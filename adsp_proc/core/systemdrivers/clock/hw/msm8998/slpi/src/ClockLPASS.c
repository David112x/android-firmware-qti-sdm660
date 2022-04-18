/*
===========================================================================
*/
/**
  @file ClockLPASS.c 
  
  Main entry point for the MSM8996 LPASS clock driver.
*/
/*  
  ====================================================================

  Copyright (c) 2014 - 2015 QUALCOMM Technologies Incorporated.
  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential. 

  ==================================================================== 
  $Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/clock/hw/msm8998/slpi/src/ClockLPASS.c#1 $
  $DateTime: 2020/02/10 01:57:30 $
  $Author: pwbldsvc $
 
  when       who     what, where, why
  --------   ---     -------------------------------------------------
  09/07/11   dcf     Created.
 
  ====================================================================
*/ 


/*=========================================================================
      Include Files
==========================================================================*/

#include "DALDeviceId.h"
#include "ClockDriver.h"
#include "ClockLPASS.h"
#include "busywait.h"
#include "ClockSWEVT.h"
#include "ClockLPASSHWIO.h"
#include "DDIChipInfo.h"

/*=========================================================================
      Macros
==========================================================================*/


/*=========================================================================
      Type Definitions
==========================================================================*/

uint32 Clock_nHWIOBaseLPASS;

/*=========================================================================
      Data
==========================================================================*/

static ClockImageCtxtType Clock_ImageCtxt;

/* =========================================================================
      Functions
==========================================================================*/


/* =========================================================================
**  Function : Clock_DetectBSPVersion
** =========================================================================*/
/**
  Detects which BSP configuration to use for the current HW.

  @param *pDrvCtxt [in] -- Pointer to driver context.

  @return
  DAL_ERROR if a valid configuration was not found, other DAL_SUCCESS.

  @dependencies
  None.
*/

static DALResult Clock_DetectBSPVersion
(
  ClockDrvCtxt *pDrvCtxt
)
{
  ClockImageCtxtType     *pImageCtxt;
  ClockCPUPerfConfigType *pCPUPerfConfig;
  uint32                  i;

  pImageCtxt = (ClockImageCtxtType *)pDrvCtxt->pImageCtxt;

  /*-----------------------------------------------------------------------*/
  /* Detect which CPU BSP data to use for this HW version.                 */
  /*-----------------------------------------------------------------------*/

  pCPUPerfConfig = pImageCtxt->pBSPConfig->pCPUPerfConfig;
  for (i = 0; i < pImageCtxt->pBSPConfig->nNumCPUPerfLevelConfigs; i++)
  {
    if (Clock_IsBSPSupported(&pCPUPerfConfig[i].HWVersion) == TRUE)
    {
      pImageCtxt->CPUCtxt.PerfConfig.HWVersion = pCPUPerfConfig[i].HWVersion;
      pImageCtxt->CPUCtxt.PerfConfig.anPerfLevel = pCPUPerfConfig[i].anPerfLevel;
      pImageCtxt->CPUCtxt.PerfConfig.nMaxPerfLevel = pCPUPerfConfig[i].nMaxPerfLevel;
      pImageCtxt->CPUCtxt.PerfConfig.nMinPerfLevel = pCPUPerfConfig[i].nMinPerfLevel;
      pImageCtxt->CPUCtxt.PerfConfig.nNumPerfLevels = pCPUPerfConfig[i].nNumPerfLevels;

      break;
    }
  }

  if (i == pImageCtxt->pBSPConfig->nNumCPUPerfLevelConfigs)
  {
    return DAL_ERROR;
  }

  return DAL_SUCCESS;

} /* END of Clock_DetectBSPVersion */


/* =========================================================================
**  Function : ClockStub_InitImage
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult ClockStub_InitImage
(
  ClockDrvCtxt *pDrvCtxt
)
{
  /*-----------------------------------------------------------------------*/
  /* Initialize the SW Events for Clocks.                                  */
  /*-----------------------------------------------------------------------*/

  Clock_SWEvent(CLOCK_EVENT_INIT, 0);

  /*-----------------------------------------------------------------------*/
  /* Good to go.                                                           */
  /*-----------------------------------------------------------------------*/

  return DAL_SUCCESS;

} /* END Clock_InitImage */

/* =========================================================================
**  Function : Clock_InitCPUConfig
** =========================================================================*/
/**
  Initializes current configuration of CPU clock
 
  This function is invoked at driver initialization to initialize the current
  CPU configuration.
 
  @param *pDrvCtxt [in] -- Pointer to driver context.

  @return
  DAL_ERROR if configuration was not valid, other DAL_SUCCESS.

  @dependencies
  None.
*/ 

static DALResult Clock_InitCPUConfig
(
  ClockDrvCtxt *pDrvCtxt
)
{
  DALResult eResult;

  /*-----------------------------------------------------------------------*/
  /* Initialize the DCVS module.                                           */
  /*-----------------------------------------------------------------------*/

  eResult = Clock_InitDCVS(pDrvCtxt);

  return eResult;

} /* END Clock_InitCPUConfig */


/* =========================================================================
**  Function : Clock_InitImage
** =========================================================================*/
/*
  See ClockDriver.h
*/ 

DALResult Clock_InitImage
(
  ClockDrvCtxt *pDrvCtxt
)
{
  DALResult eRes;
  uint32 nIdx;
  ClockPropertyValueType PropVal = NULL;
  ClockSourceInitType* pInitSources = NULL;
  HAL_clk_HWIOBaseType *pHWIOBases = NULL;
  ClockPowerDomainIdType nPowerDomain;
  ClockIdType nCoreClkId, nMportClkId, nAONBusClkId;

  /*-----------------------------------------------------------------------*/
  /* Get the CPU Configurations.                                           */
  /*-----------------------------------------------------------------------*/

  if(DAL_SUCCESS != Clock_GetPropertyValue("ClockImageConfig", &PropVal))
  {
    return(DAL_ERROR);
  }

  Clock_ImageCtxt.pBSPConfig = (ClockImageBSPConfigType*)PropVal;

  pDrvCtxt->pImageCtxt = &Clock_ImageCtxt;

  /*-----------------------------------------------------------------------*/
  /* Initialize the Q6SS HWIO Base address.                                */
  /*-----------------------------------------------------------------------*/

  if(Clock_nHWIOBaseLPASS == 0)
  {
    eRes = Clock_GetPropertyValue("ClockLPASSBase", &PropVal);

    if (eRes != DAL_SUCCESS)
    {
      return(eRes);
    }

    pHWIOBases = (HAL_clk_HWIOBaseType*)PropVal;

    if (pHWIOBases != NULL)
    {
      Clock_MapHWIORegion(
        pHWIOBases->nPhysAddr, pHWIOBases->nSize, &Clock_nHWIOBaseLPASS);

      /*
       * If we are unable to map a virtual address, assume the physical one.
       */
      if(Clock_nHWIOBaseLPASS == NULL)
      {
        Clock_nHWIOBaseLPASS = pHWIOBases->nPhysAddr;
      }
    }
    else
    {
      /*
       * We were unable to get the base address.
       */
      return(DAL_ERROR);
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Detect the BSP version to use.                                        */
  /*-----------------------------------------------------------------------*/

  eRes = Clock_DetectBSPVersion(pDrvCtxt);
  if (eRes != DAL_SUCCESS)
  {
    DALSYS_LogEvent (
      DALDEVICEID_CLOCK, DALSYS_LOGEVENT_FATAL_ERROR,
      "Failed to detect the BSP version.");
    return eRes;
  }  

  /*-----------------------------------------------------------------------*/
  /* Initialize the XO module.                                             */
  /*-----------------------------------------------------------------------*/

  Clock_InitXO(pDrvCtxt);

  /*-----------------------------------------------------------------------*/
  /* Initialize CPU core clock frequency configuration.                    */
  /*-----------------------------------------------------------------------*/

  eRes = Clock_InitCPUConfig(pDrvCtxt);
  if (eRes != DAL_SUCCESS)
  {
    DALSYS_LogEvent (
      DALDEVICEID_CLOCK, DALSYS_LOGEVENT_FATAL_ERROR,
      "Unable to detect CPU core clock configuration.");
    return eRes;
  }


  /*-----------------------------------------------------------------------*/
  /* Initialize the Q6PLL if applicable to this chipset.                   */
  /*-----------------------------------------------------------------------*/

  if(DAL_SUCCESS == Clock_GetPropertyValue("ClockSourcesToInit", &PropVal))
  {
    pInitSources = (ClockSourceInitType*)PropVal;

    if (pInitSources != NULL)
    {
      nIdx = 0;
      while (pInitSources[nIdx].eSource != HAL_CLK_SOURCE_NULL)
      {
        Clock_InitSource(pDrvCtxt,
                         pInitSources[nIdx].eSource,
                         pInitSources[nIdx].nFreqHz);
        nIdx++;
      }
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Connect the active frequency configuration for the main PLL. This has */
  /* already been configured and enabled pre-main so this step ensures SW  */
  /* has correct data structures initialized.                              */
  /*-----------------------------------------------------------------------*/

  nIdx = pDrvCtxt->anSourceIndex[HAL_CLK_SOURCE_LPAPLL2];
  pDrvCtxt->aSources[nIdx].pActiveFreqConfig = 
    pDrvCtxt->aSources[nIdx].pBSPConfig->pSourceFreqConfig;


  /*----------------------------------------------------------------------*/
  /* Enable the AON bus clock and set the frequency based on what was     */
  /* programmed in the BSP in the early init.                             */
  /*----------------------------------------------------------------------*/

  if(DAL_SUCCESS == Clock_GetClockId(pDrvCtxt, "lpass_audio_wrapper_aon_clk", &nAONBusClkId))
  {
    eRes = Clock_EnableClock(Clock_GetInitialClientCtxt(), nAONBusClkId);

    if(DAL_SUCCESS != eRes)
    {
      DALSYS_LogEvent(
          DALDEVICEID_CLOCK, DALSYS_LOGEVENT_FATAL_ERROR,
          "Clock_InitImage:  Failed to enable the audio_wrapper_aon_clk clock.  Error code: %x", eRes);
      return eRes;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Now that NPA is initialized, allow Q6 scaling by the power manager.   */
  /*-----------------------------------------------------------------------*/

  eRes = Clock_EnableDCVS(pDrvCtxt);

  if(DAL_SUCCESS != eRes)
  {
    DALSYS_LogEvent(
      DALDEVICEID_CLOCK, DALSYS_LOGEVENT_FATAL_ERROR,
      "Clock_InitImage:  Failed to initialize DCVS %d", eRes);
    return eRes;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the NPA Voltage NPA node.                                  */
  /*-----------------------------------------------------------------------*/

  eRes = Clock_InitVdd(pDrvCtxt);

  if(DAL_SUCCESS != eRes)
  {
    DALSYS_LogEvent(
      DALDEVICEID_CLOCK, DALSYS_LOGEVENT_FATAL_ERROR,
      "Clock_InitImage:  Failed to initialize Vdd node %d", eRes);
    return eRes;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the HVX Coprocessor node.                                  */
  /*-----------------------------------------------------------------------*/

  eRes = Clock_InitHvx(pDrvCtxt);

  if(DAL_SUCCESS != eRes)
  {
    DALSYS_LogEvent(
      DALDEVICEID_CLOCK, DALSYS_LOGEVENT_FATAL_ERROR,
      "Clock_InitImage:  Failed to initialize HVX %d", eRes);
    return eRes;
  }

  /*
   * Put in a vote for the core bus clock and the mport CBC.  These will
   * already be on at this point.  ADSPPM will later disable them. 
   * NOTE:: This may be removed at a later point, this was a workaround for 
   * 8996 that we are carrying forward for now. 
   */
  if(DAL_SUCCESS == Clock_GetClockId(pDrvCtxt,
                                     "lpass_audio_core_core_clk",
                                     &nCoreClkId))
  {
    Clock_EnableClock(Clock_GetInitialClientCtxt(), nCoreClkId);

    if(DAL_SUCCESS == 
        Clock_GetClockId(pDrvCtxt,
                         "lpass_audio_core_sysnoc_mport_core_clk",
                         &nMportClkId))
    {
      Clock_EnableClock(Clock_GetInitialClientCtxt(), nMportClkId);

      if(DAL_SUCCESS == Clock_GetPowerDomainId(pDrvCtxt, "VDD_AUDIO_CORE", &nPowerDomain))
      {
        Clock_EnablePowerDomain(Clock_GetInitialClientCtxt(), nPowerDomain);
      }
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Set a indefinite vote for the LPAAUDIO_DIG PLL.  This PLL will remain */
  /* on until the SPM collapses it for power collapse in order to mitigate */
  /* extra delays caused by enabling the PLL via vote.                     */
  /*-----------------------------------------------------------------------*/

  HWIO_OUTF(LPASS_LPA_PLL_VOTE_LPASSQ6, LPAAUDIO_DIG_PLL, 0x1);

  /*-----------------------------------------------------------------------*/
  /* Good to go.                                                           */
  /*-----------------------------------------------------------------------*/

  return DAL_SUCCESS;

} /* END Clock_InitImage */


/* =========================================================================
**  Function : Clock_ProcessorSleep
** =========================================================================*/
/*
  See DDIClock.h
*/

DALResult Clock_ProcessorSleep
(
  ClockDrvCtxt       *pDrvCtxt,
  ClockSleepModeType  eMode,
  uint32              nFlags
)
{

  return DAL_SUCCESS;

} /* END Clock_ProcessorSleep */


/* =========================================================================
**  Function : Clock_ProcessorRestore
** =========================================================================*/
/*
  See DDIClock.h
*/

DALResult Clock_ProcessorRestore
(
  ClockDrvCtxt       *pDrvCtxt,
  ClockSleepModeType  eMode,
  uint32              nFlags
) 
{

  /*
   * Nothing to do here. HW_VOTE does SPMCTL override handling.
  */

  return DAL_SUCCESS;

} /* END Clock_ProcessorRestore */


/* =========================================================================
**  Function : Clock_AdjustSourceFrequency
** =========================================================================*/
/*
  See DDIClock.h
*/
DALResult Clock_AdjustSourceFrequency
(
   ClockDrvCtxt    *pDrvCtxt,
   ClockSourceType eSource,
   int32           nDeltaLAlpha
)
{
  return(DAL_ERROR);

} /* Clock_AdjustSourceFrequency */


DALResult Clock_SelectClockSource
(
   ClockDrvCtxt    *pDrvCtxt,
   ClockIdType     nClock,
   ClockSourceType eSource
)
{

  if(eSource == CLOCK_SOURCE_PRIMARY)
  {
    return(DAL_SUCCESS);
  }
  return(DAL_ERROR);

} /* Clock_SelectClockSource */


/* =========================================================================
**  Function : Clock_GetImageCtxt
** =========================================================================*/
/*
  See ClockLPASS.h
*/

ClockImageCtxtType* Clock_GetImageCtxt(void)
{
  return(&Clock_ImageCtxt);
}

/*
 * Unused APIs are stubbed out here.
 */

DALResult Clock_ImageBIST
(
  ClockDrvCtxt  *pDrvCtxt,
  boolean       *bBISTPassed,
  uint32        *nFailedTests
)
{
  return(DAL_ERROR);
}

DALResult Clock_LoadNV
(
  ClockDrvCtxt  *pDrvCtxt
)
{
  return(DAL_ERROR_NOT_SUPPORTED);
}


