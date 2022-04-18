/*
* Copyright (c) 2015 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Qualcomm Technologies, Inc. Confidential and Proprietary.
*/

/*
@file: mipsmgr.c
@brief: Implementation of ADSPPM MIPS/MPPS Manager.

$Header: //components/rel/core.qdsp6/1.0.c2/power/qdsp_pm/src/driver/qdsp_pm_mgr/resource_mgr/mipsmgr.c#1 $
*/

#include "adsppm.h"
#include "adsppm_utils.h"
#include "requestmgr.h"
#include "asic.h"
#include "mipsmgr.h"
#include "ahbmgr.h"
#include "core_internal.h"
#include "hal_clkrgm.h"
#include "hal_busdrv.h"
#include "clientmgr.h"
#include "adspclkmgr.h"
#include "usleepmgr.h"


typedef struct
{
    uint32 mppsTotal;           //!< Total MPPS value
    uint32 numDominantThreads;  //!< Thread Loading Info
    uint32 mipsTotal;           //!< Total MIPS value calculated from MPPS
    uint32 adspFloorClock;      //!< ADSP Floor clock value in MHz
    uint32 maxMppsVote;         //!< Current Max MPPS vote
    uint32 secondMaxMppsVote;   //!< Current Second Max MPPS vote
    uint32 mppsPerClientClass[ADSPPM_NUM_OF_CLIENT_CLASSES];
} mipsMgrMppsDataType;

typedef struct
{
    AdsppmMIPSToClockAggregateType mipsToClockData;
    AdsppmMIPSToBWAggregateType mipsToBWAggregateDataDdr;
    AdsppmMIPSToBWAggregateType mipsToBWAggregateDataOcmem;
} mipsMgrAggregateDataType;

typedef struct
{
    DALSYSSyncHandle         lock;
    uint32                   numOfClients;
    uint32                   numOfPeriodicClients;
    AdsppmMipsDataType       mipsAggregateData;
    mipsMgrMppsDataType      mppsAggregateData;
    mipsMgrAggregateDataType previousAggregateData;
    mipsMgrAggregateDataType currentAggregateData;
    npa_client_handle        uSleepHandle;
} mipsMgrCtxType;

static mipsMgrCtxType mipsMgrCtx;

///////////////////////////////////////////////////////////////////////////////
// Static functions
///////////////////////////////////////////////////////////////////////////////

// Aggregate MIPS values, both total and per thread
static void mipsMgr_AggregateMips(
    AdsppmMipsDataType *pMipsData,
    AdsppmMipsRequestType *pMipsReqData)
{
    pMipsData->mipsTotal += pMipsReqData->mipsTotal;
    pMipsData->mipsPerThread = MAX(
        pMipsData->mipsPerThread, pMipsReqData->mipsPerThread);
}

// Assume lock is obtained
static void mipsMgr_ProcessMipsRequest(
    mipsMgrCtxType *self,
    AdsppmMipsRequestType *pMipsReqData)
{
    AdsppmMIPSToBWAggregateType *pMipsToBWAggregateDataDdr =
        &self->currentAggregateData.mipsToBWAggregateDataDdr;
    AdsppmMIPSToBWAggregateType *pMipsToBWAggregateDataOcmem =
        &self->currentAggregateData.mipsToBWAggregateDataOcmem;

    mipsMgr_AggregateMips(
        &self->mipsAggregateData, pMipsReqData);

    if(MipsRequestOperation_BWandMIPS == pMipsReqData->reqOperation)
    {
        if(AdsppmBusPort_Ddr_Slave == pMipsReqData->codeLocation)
        {
            mipsMgr_AggregateMips(
                &pMipsToBWAggregateDataDdr->mipsData, pMipsReqData);
        }
        else if(AdsppmBusPort_Ocmem_Slave == pMipsReqData->codeLocation)
        {
            mipsMgr_AggregateMips(
                &pMipsToBWAggregateDataOcmem->mipsData, pMipsReqData);
        }
    }
}

static uint32 mipsMgr_calcNumDominantThreads(
    uint32 mppsTotal, uint32 maxMpps, uint32 secondMaxMpps)
{
    // Default return 1 Dominant Thread
    uint32 dominantThreads = 1;
    // Sum MPPS other than max
    uint32 sumOfRestClients = mppsTotal - maxMpps;

    if(maxMpps == 0)
    {
        // No Active MPPS Request In System
        dominantThreads = 0;
    }
    else if(maxMpps != 0)
    {
        if(((sumOfRestClients) * 100) / maxMpps > 30)
        {
            if(((sumOfRestClients * 100) / maxMpps > 65))
            {
                dominantThreads = 3;
            }
            else
            {
                dominantThreads = 2;
            }
        }
    }

    ADSPPM_LOG_PRINTF_4(ADSPPM_LOG_LEVEL_INFO,
        "MPPS total=%u, Max MPPS=%u, SecondMax MPPS=%u, Dominant Threads=%u",
        mppsTotal, maxMpps, secondMaxMpps, dominantThreads);

    return dominantThreads;
}

static void mipsMgr_AggregateMpps(
    mipsMgrMppsDataType *pMppsData,
    AdsppmMppsRequestType *pMppsReqData)
{
    pMppsData->mppsTotal += pMppsReqData->mppsTotal;
    pMppsData->adspFloorClock = MAX(
        pMppsData->adspFloorClock, pMppsReqData->adspFloorClock);
}

static void mipsMgr_ProcessMppsRequest(
    mipsMgrCtxType *self,
    AdsppmMppsRequestType *pMppsReqData)
{
    mipsMgr_AggregateMpps(&self->mppsAggregateData, pMppsReqData);

    if(pMppsReqData->mppsTotal >= self->mppsAggregateData.maxMppsVote)
    {
        self->mppsAggregateData.secondMaxMppsVote = self->mppsAggregateData.maxMppsVote;
        self->mppsAggregateData.maxMppsVote = pMppsReqData->mppsTotal;
    }
    if((pMppsReqData->mppsTotal < self->mppsAggregateData.maxMppsVote) &&
        (pMppsReqData->mppsTotal > self->mppsAggregateData.secondMaxMppsVote))
    {
        self->mppsAggregateData.secondMaxMppsVote = pMppsReqData->mppsTotal;
    }
}

static boolean mipsMgr_DoesRequestCountTowardsDcvsFloor(RMHandleType *pRMHandle)
{
    if(ACM_GetFeatureStatus(AsicFeatureId_DcvsControl) ==
        AsicFeatureState_Enabled)
    {
        // Aggregate DCVS Floor vote depending on client's
        // participation in DCVS
        // Two type of clients counts towards DCVS Floor vote:
        // 1. Clients that voted for DCVS disabled
        // 2. Clients that voted for DCVS enabled and
        //    chose MMPM_DCVS_ADJUST_ONLY_UP as enable option
        if((!pRMHandle->pClient->dcvsParticipation.enable) ||
            (pRMHandle->pClient->dcvsParticipation.enable &&
                (pRMHandle->pClient->dcvsParticipation.enableOpt ==
                    MMPM_DCVS_ADJUST_ONLY_UP)))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// Update MMPS per client class
static void mipsMgr_UpdateMppsPerClientClass(
    mipsMgrCtxType *self,
    uint32 clientClass,
    uint32 mppsValue)
{
    uint32 index = 0;

    // Get client class index
    for(index = 0; index < ADSPPM_NUM_OF_CLIENT_CLASSES; index++)
    {
        // 1 << index will give the different client class enums
        // Except MMPM_UNKNOWN_CLIENT_CLASS which is not needed
        if(clientClass & (1 << index))
        {
            self->mppsAggregateData.mppsPerClientClass[index] += mppsValue;
            break;
        }
    }
}

static Adsppm_Status mipsMgrUpdateUSleepMgr(void)
{
    Adsppm_Status sts = Adsppm_Status_Success;
    AdsppmMIPSToBWAggregateType *pMipsToBWAggregateDataDdr = 
        &mipsMgrCtx.currentAggregateData.mipsToBWAggregateDataDdr;

	if (mipsMgrCtx.uSleepHandle)
	{
		boolean uSleep_vote;

   		/* Allow sleep only then aggr DDR bw = 0 */
    	uSleep_vote = pMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ab ? QDSPPM_USLEEP_DISALLOW : QDSPPM_USLEEP_ALLOW;
        ADSPPM_LOG_PRINTF_1(ADSPPM_LOG_LEVEL_INFO_EXT,
                               "NPA request to %s usleep", (uSleep_vote ? "Allow" : "DisAllow"));

           npa_issue_required_request(mipsMgrCtx.uSleepHandle, uSleep_vote);
	}

    return sts;    
}

Adsppm_Status mipsmgr_GetMppsPerClientClass( MmpmClientClassType clientClass, uint32 *mppsValue)
{
    uint32 index = 0;
    mipsMgrCtxType *self = &mipsMgrCtx;

    if(!clientClass || !VALID_CLIENT_CLASS(clientClass) || !mppsValue)
        return Adsppm_Status_Failed;


    adsppm_lock(self->lock);

    // Get client class index
    for(index = 0; index < ADSPPM_NUM_OF_CLIENT_CLASSES; index++)
    {
        // 1 << index will give the different client class enums
        // Except MMPM_UNKNOWN_CLIENT_CLASS which is not needed
        if(clientClass & (1 << index))
        {
            *mppsValue = self->mppsAggregateData.mppsPerClientClass[index]; 
        }
    }

    adsppm_unlock(self->lock);	

    return Adsppm_Status_Success;
}

/**
 * MIPS_USleepNode_RegisterCB
 * 
 * @brief Registers dspPm uSleep node
 * 
 * @param see npa_callback defintion for function parameters
 */
static void MIPS_USleepNode_RegisterCB(
			void         *context,
            unsigned int  eventType,
            void         *data,
            unsigned int  dataSize)
{
    mipsMgrCtx.uSleepHandle = npa_create_sync_client(
								QDSPPM_USLEEP_NODE_NAME, 
                                "qdsppm_mipsmgr",
								NPA_CLIENT_REQUIRED);
    return;
}

///////////////////////////////////////////////////////////////////////////////
// Public functions
///////////////////////////////////////////////////////////////////////////////

/**
 * @fn MIPS_Init - Initialize MIPS management related data structure and mutex
 * @return Adsppm_Status_Failed
 * @return Adsppm_Status_Success
 */
Adsppm_Status MIPS_Init(void)
{
    mipsMgrCtxType *self = &mipsMgrCtx;

    memset(self, 0, sizeof(mipsMgrCtxType));

    if(DAL_SUCCESS != DALSYS_SyncCreate(
        DALSYS_SYNC_ATTR_RESOURCE,
        &self->lock, NULL))
    {
        return Adsppm_Status_Failed;
    }

    /* Register a callback for dspPm uSleep node
     * create a client for MipsMgr to vote on dspPm uSleep node.
	 */
    npa_resource_available_cb(QDSPPM_USLEEP_NODE_NAME,
                              MIPS_USleepNode_RegisterCB, NULL);

    return Adsppm_Status_Success;
}

/**
 * @fn MIPS_ProcessRequest - Process clients MIPS request
 * @param input RMHandleType *pMipsReqQ - MIPS request data from clients
 * @return Adsppm_Status
 */
Adsppm_Status MIPS_ProcessRequest(coreUtils_Q_Type *pMipsReqQ)
{
    mipsMgrCtxType *self = &mipsMgrCtx;
    Adsppm_Status sts = Adsppm_Status_Success;

    // Client activity update information
    uint32 newRequestClientId = 0;
    uint32 releasedRequestClientId = 0;

    // DCVS and set ADSP clock information
    AdsppmMIPSToClockAggregateType mipsDataForDcvsFloorVote;
    mipsMgrMppsDataType mppsDataForDcvsFloorVote;
    AdsppmMIPSToClockAggregateType dcvsFloorVote;
    uint32 currentAdspClock = 0;
    uint32 previousAdspClock = 0;
    uint32 dcvsFloorAdspClock = 0;

    if(pMipsReqQ == NULL)
    {
        return Adsppm_Status_BadParm;
    }

    if(self->lock == NULL)
    {
        return Adsppm_Status_NotInitialized;
    }

    memset(&mipsDataForDcvsFloorVote, 0, sizeof(AdsppmMIPSToClockAggregateType));
    memset(&mppsDataForDcvsFloorVote, 0, sizeof(mipsMgrMppsDataType));
    memset(&dcvsFloorVote, 0, sizeof(AdsppmMIPSToClockAggregateType));

    adsppm_lock(self->lock);

    AdsppmMIPSToClockAggregateType *pMipsToClockData =
        &self->currentAggregateData.mipsToClockData;
    AdsppmMIPSToBWAggregateType *pMipsToBWAggregateDataDdr =
        &self->currentAggregateData.mipsToBWAggregateDataDdr;
    AdsppmMIPSToBWAggregateType *pMipsToBWAggregateDataOcmem =
        &self->currentAggregateData.mipsToBWAggregateDataOcmem;

    AdsppmMIPSToClockAggregateType *pPreMipsToClockData =
        &self->previousAggregateData.mipsToClockData;
    AdsppmMIPSToBWAggregateType *pPreMipsToBWAggregateDataDdr =
        &self->previousAggregateData.mipsToBWAggregateDataDdr;
    AdsppmMIPSToBWAggregateType *pPreMipsToBWAggregateDataOcmem =
        &self->previousAggregateData.mipsToBWAggregateDataOcmem;

    memset(&self->currentAggregateData, 0, sizeof(mipsMgrAggregateDataType));
    memset(&self->mppsAggregateData, 0, sizeof(mipsMgrMppsDataType));
    self->mipsAggregateData.mipsTotal = 0;
    self->mipsAggregateData.mipsPerThread = 0;
    self->numOfClients = 0;
    self->numOfPeriodicClients = 0;
    pMipsToBWAggregateDataDdr->mipsToBW.busRoute.masterPort = AdsppmBusPort_Adsp_Master;
    pMipsToBWAggregateDataDdr->mipsToBW.busRoute.slavePort = AdsppmBusPort_Ddr_Slave;
    pMipsToBWAggregateDataOcmem->mipsToBW.busRoute.masterPort = AdsppmBusPort_Adsp_Master;
    pMipsToBWAggregateDataOcmem->mipsToBW.busRoute.slavePort = AdsppmBusPort_Ocmem_Slave;

    RMHandleType *pRMHandle = NULL;
    AdsppmQ6ClockRequestInfoType *pQ6ReqData = NULL;
    AdsppmMipsRequestType *pMipsReqData = NULL;
    AdsppmMppsRequestType *pMppsReqData = NULL;
    AdsppmClientPeriodicityType periodicity = Adsppm_ClientType_Normal;
    boolean nonZeroRequest = FALSE;
    uint32 index = 0;

    ADSPPM_LOCK_RESOURCE(Adsppm_Rsc_Id_Mips);

    // Go through all client request
    pRMHandle = (RMHandleType *) coreUtils_Q_Check(pMipsReqQ);
    for(index = 0; (index < pMipsReqQ->nCnt) && (NULL != pRMHandle); index++)
    {
        nonZeroRequest = FALSE;
        if(RM_Valid == pRMHandle->validFlag)
        {
            if((NULL == (AdsppmQ6ClockRequestInfoType *) (pRMHandle->pRequestData)) ||
                (NULL == pRMHandle->pClient))
            {
                sts = Adsppm_Status_BadParm;
                ADSPPM_LOG_PRINTF_2(ADSPPM_LOG_LEVEL_ERROR,
                    "pRequestData(%u) or pClient(%u) is NULL",
                    (AdsppmQ6ClockRequestInfoType *) (pRMHandle->pRequestData),
                    pRMHandle->pClient);
                break;
            }
            else
            {
                periodicity = pRMHandle->pClient->periodicityType;
                pQ6ReqData = (AdsppmQ6ClockRequestInfoType *) (pRMHandle->pRequestData);

                if(pQ6ReqData->usageType == Adsppm_Q6ClockRequestUsageType_Mips)
                {
                    pMipsReqData = &(pQ6ReqData->AdsppmQ6ClockRequestType.mipsRequestData);

                    if((pMipsReqData->mipsTotal > 0) || (pMipsReqData->mipsPerThread > 0))
                    {
                        nonZeroRequest = TRUE;
                        self->numOfClients++;
                        if(periodicity == Adsppm_ClientType_Periodic)
                        {
                            self->numOfPeriodicClients++;
                        }

                        // Aggregate vote to DCVS Floor value
                        if(mipsMgr_DoesRequestCountTowardsDcvsFloor(pRMHandle))
                        {
                            mipsMgr_AggregateMips(
                                &mipsDataForDcvsFloorVote.mipsData, pMipsReqData);
                        }

                        // Process MIPS clients requests
                        mipsMgr_ProcessMipsRequest(self, pMipsReqData);
                    }
                }
                else if(pQ6ReqData->usageType == Adsppm_Q6ClockRequestUsageType_Mpps)
                {
                    pMppsReqData = &(pQ6ReqData->AdsppmQ6ClockRequestType.mppsRequestData);

                    if((pMppsReqData->mppsTotal > 0) || (pMppsReqData->adspFloorClock > 0))
                    {
                        nonZeroRequest = TRUE;
                        self->numOfClients++;
                        if(periodicity == Adsppm_ClientType_Periodic)
                        {
                            self->numOfPeriodicClients++;
                        }

                        // Aggregate vote to DCVS Floor value
                        if(mipsMgr_DoesRequestCountTowardsDcvsFloor(pRMHandle))
                        {
                            mipsMgr_AggregateMpps(
                                &mppsDataForDcvsFloorVote, pMppsReqData);
                        }

                        // Process MPPS clients requests
                        mipsMgr_ProcessMppsRequest(self, pMppsReqData);

                        // Update MMPS per client class
                        mipsMgr_UpdateMppsPerClientClass(
                            self,
                            (uint32) pRMHandle->pClient->clientClass,
                            pMppsReqData->mppsTotal);
                    }
                }
            }
        }

        // Keep track of new and released requests;
        // Assuming there is no more than one of each for each
        // time this function is called
        if(pRMHandle->lifecycleState == NEW_REQUEST)
        {
            if(nonZeroRequest)
            {
                // This is a normal new/modified request with non-zero MIPS/MPPS
                if(newRequestClientId)
                {
                    ADSPPM_LOG_PRINTF_0(ADSPPM_LOG_LEVEL_WARNING,
                        "more than one new request received");
                }
                newRequestClientId = pRMHandle->clientId;
            }
            else
            {
                // This is a new/modified request with zero MIPS, which
                // we treat similar to a release request
                if(releasedRequestClientId)
                {
                    ADSPPM_LOG_PRINTF_0(ADSPPM_LOG_LEVEL_WARNING,
                        "more than one request released");
                }
                releasedRequestClientId = pRMHandle->clientId;
            }
        }
        else if(pRMHandle->lifecycleState == RELEASED_REQUEST)
        {
            if(releasedRequestClientId)
            {
                ADSPPM_LOG_PRINTF_0(ADSPPM_LOG_LEVEL_WARNING,
                    "more than one request released");
            }
            releasedRequestClientId = pRMHandle->clientId;
        }

        pRMHandle = (RMHandleType *) coreUtils_Q_Next(pMipsReqQ, &pRMHandle->link);
    }

    ADSPPM_UNLOCK_RESOURCE(Adsppm_Rsc_Id_Mips);

    if(sts == Adsppm_Status_Success)
    {
        // Calculate number of dominant threads
        self->mppsAggregateData.numDominantThreads = mipsMgr_calcNumDominantThreads(
            self->mppsAggregateData.mppsTotal,
            self->mppsAggregateData.maxMppsVote,
            self->mppsAggregateData.secondMaxMppsVote);

        // Calculate MIPS from MPPS
        self->mppsAggregateData.mipsTotal = ACM_GetMipsFromMpps(
            self->mppsAggregateData.mppsTotal,
            self->mppsAggregateData.numDominantThreads);

        // Aggregate MIPS from aggregated MPPS and MIPS
        pMipsToClockData->mipsData.mipsTotal =
            self->mipsAggregateData.mipsTotal +
            self->mppsAggregateData.mipsTotal;
        pMipsToClockData->mipsData.mipsPerThread = MAX(
            self->mipsAggregateData.mipsPerThread,
            self->mppsAggregateData.adspFloorClock / ACM_GetHwThreadNumber());

        // Aggregate for DCVS floor value
        if(ACM_GetFeatureStatus(AsicFeatureId_DcvsControl) ==
            AsicFeatureState_Enabled)
        {
            // Calculate MIPS from MPPS
            mppsDataForDcvsFloorVote.mipsTotal = ACM_GetMipsFromMpps(
                mppsDataForDcvsFloorVote.mppsTotal,
                self->mppsAggregateData.numDominantThreads);

            // Aggregate MIPS from aggregated MPPS and MIPS
            // Also, as part of floor vote, aggregate with
            // total floor vote regardless of DCVS participation
            dcvsFloorVote.mipsData.mipsTotal =
                mipsDataForDcvsFloorVote.mipsData.mipsTotal +
                mppsDataForDcvsFloorVote.mipsTotal;
            dcvsFloorVote.mipsData.mipsPerThread =
                pMipsToClockData->mipsData.mipsPerThread;
        }
    }

    // Specify whether only periodic clients are running
    // This has to be done before calling ACM and AHBM functions
    if(sts == Adsppm_Status_Success)
    {
        if((self->numOfPeriodicClients == self->numOfClients) &&
            (self->numOfPeriodicClients > 0))
        {
            SetPeriodicUseCase(1);
        }
        else
        {
            SetPeriodicUseCase(0);
        }
    }

    // Calculate Final Static Q6 Clock
    if(sts == Adsppm_Status_Success)
    {
        sts = ACM_GetClockFromMips(pMipsToClockData);
        ADSPPM_LOG_PRINTF_3(ADSPPM_LOG_LEVEL_INFO_EXT,
            "MIPS total=%u, MIPS min=%u, Clock=%u",
            pMipsToClockData->mipsData.mipsTotal,
            pMipsToClockData->mipsData.mipsPerThread,
            pMipsToClockData->qDSP6Clock);

        currentAdspClock = pMipsToClockData->qDSP6Clock;
        previousAdspClock = pPreMipsToClockData->qDSP6Clock;
    }

    if(ACM_GetFeatureStatus(AsicFeatureId_DcvsControl) ==
        AsicFeatureState_Enabled)
    {
        // Calculate Floor Q6 Clock
        if(sts == Adsppm_Status_Success)
        {
            sts = ACM_GetClockFromMips(&dcvsFloorVote);
            dcvsFloorAdspClock = dcvsFloorVote.qDSP6Clock;
        }
    }

    // Calculate DDR BW for MIPS
    if(sts == Adsppm_Status_Success)
    {
        sts = ACM_GetBWFromMips(pMipsToBWAggregateDataDdr);
        ADSPPM_LOG_PRINTF_2(ADSPPM_LOG_LEVEL_INFO_EXT,
            "DDR BW Ab=%u, Ib=%u",
            (uint32) pMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ab,
            (uint32) pMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ib);
    }
    // Calculate OCMEM BW for MIPS
    if(sts == Adsppm_Status_Success)
    {
        sts = ACM_GetBWFromMips(pMipsToBWAggregateDataOcmem);
        ADSPPM_LOG_PRINTF_2(ADSPPM_LOG_LEVEL_INFO_EXT,
            "OCMEM BW Ab=%u, Ib=%u",
            (uint32) pMipsToBWAggregateDataOcmem->mipsToBW.bwValue.busBwAbIb.Ab,
            (uint32) pMipsToBWAggregateDataOcmem->mipsToBW.bwValue.busBwAbIb.Ib);
    }

    // Issue BW request for MIPS
    if((sts == Adsppm_Status_Success) &&
        ((pPreMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ab !=
            pMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ab) ||
        (pPreMipsToBWAggregateDataOcmem->mipsToBW.bwValue.busBwAbIb.Ab !=
            pMipsToBWAggregateDataOcmem->mipsToBW.bwValue.busBwAbIb.Ab) ||
        (pPreMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ib !=
            pMipsToBWAggregateDataDdr->mipsToBW.bwValue.busBwAbIb.Ib) ||
        (pPreMipsToBWAggregateDataOcmem->mipsToBW.bwValue.busBwAbIb.Ib !=
            pMipsToBWAggregateDataOcmem->mipsToBW.bwValue.busBwAbIb.Ib)))
    {
        AdsppmBusBWRequestValueType busBw[BUS_NUMBER_MIPS_ROUTES];
        busBw[0].bwValue = pMipsToBWAggregateDataOcmem->mipsToBW.bwValue;
        busBw[0].busRoute.masterPort = pMipsToBWAggregateDataOcmem->mipsToBW.busRoute.masterPort;
        busBw[0].busRoute.slavePort = pMipsToBWAggregateDataOcmem->mipsToBW.busRoute.slavePort;
        busBw[1].bwValue = pMipsToBWAggregateDataDdr->mipsToBW.bwValue;
        busBw[1].busRoute.masterPort = pMipsToBWAggregateDataDdr->mipsToBW.busRoute.masterPort;
        busBw[1].busRoute.slavePort = pMipsToBWAggregateDataDdr->mipsToBW.busRoute.slavePort;
        sts = Bus_IssueBWRequest_MIPS(&busBw[0]);
    }

    // Adjust AHB clock for periodic use-cases if required
    if(sts == Adsppm_Status_Success)
    {
        sts = AHBM_AdjustAndSetAHBClock();
    }

    // Update uSleep manager
    if(Adsppm_Status_Success == sts)
    {
        sts = mipsMgrUpdateUSleepMgr();
    }
    
    // Copy current to previous state
    if(sts == Adsppm_Status_Success)
    {
        memscpy(
            &self->previousAggregateData,
            sizeof(mipsMgrAggregateDataType),
            &self->currentAggregateData,
            sizeof(mipsMgrAggregateDataType));
    }

    adsppm_unlock(self->lock);

    // Update client properties
    if(newRequestClientId)
    {
        // MIPS request is now active for client making the new request
        CM_SetProperty(newRequestClientId,
            CM_MIPS_REQ_ACTIVE_PROPERTY, TRUE);
    }
    if(releasedRequestClientId)
    {
        // MIPS request is no longer active for client making the released
        // request clientId should still be valid for released requests
        CM_SetProperty(releasedRequestClientId,
            CM_MIPS_REQ_ACTIVE_PROPERTY, FALSE);
    }

    // Issue ADSP clock request to ADSP clock Manager
    if(sts == Adsppm_Status_Success)
    {
        sts = AdspClkMgr_IssueAdspClkRequest(
            currentAdspClock, dcvsFloorAdspClock);
    }

    return sts;
}

uint32 MIPS_GetMppsAggregationInfo(uint32 clientClasses)
{
    mipsMgrCtxType *self = &mipsMgrCtx;
    uint32 index = 0;
    uint32 totalMpps = 0;

    if(clientClasses == 0)
        return 0;

    adsppm_lock(self->lock);

    for(index = 0; index < ADSPPM_NUM_OF_CLIENT_CLASSES; index++)
        // 1 << index will give the different client class enums
        // Except MMPM_UNKNOWN_CLIENT_CLASS which is not needed
        if(clientClasses & (1 << index))
            totalMpps += self->mppsAggregateData.mppsPerClientClass[index];

    adsppm_unlock(self->lock);

    return totalMpps;
}

