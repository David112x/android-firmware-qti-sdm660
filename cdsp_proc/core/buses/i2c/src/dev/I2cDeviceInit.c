/*=============================================================================

FILE:      I2cDevice.c

OVERVIEW:  This file contains the implementation of the API for the QUPI2CDeviceQup
           I2CDEV_Init must be called before any other api call.

           Copyright (c) 2011-2016 Qualcomm Technologies Incorporated.
                             All Rights Reserved.
           Qualcomm Technologies Confidential and Proprietary

=============================================================================*/

/*=============================================================================
  EDIT HISTORY FOR MODULE
  

$Header: //components/rel/core.qdsp6/1.0.c2/buses/i2c/src/dev/I2cDeviceInit.c#1 $
$DateTime: 2020/02/10 01:57:30 $$Author: pwbldsvc $ 
 
When     Who    What, where, why
-------- ---    -----------------------------------------------------------
10/17/16 VG     Updated Copy Rights
09/26/11 LK     Created


=============================================================================*/

/*-------------------------------------------------------------------------
* Include Files
* ----------------------------------------------------------------------*/

#include "I2cDevice.h"
#include "QupRegs.h"


/** @brief Initializes the device.
 
 This Function Initializes the device and creates the
 necessary data structures to support other calls into the
 device. This needs to be done outside uImage.
 
 @param[in] pDev    Pointer to device struct.
 @param[in] pProp   Pointer to properties struct.
 
 @return          int32 .
 */
int32
I2cDev_Init
(
 I2cDev_Device          *pDev,
 I2cDev_PropertyType    *pProp
)
{
   //int32                               res = I2C_RES_SUCCESS;

   //res = I2cSys_Memset(pDev, 0, sizeof(I2cDev_Device));
   //if ( I2C_RES_SUCCESS != res )  {
   //   return res;
   //}

   pDev->devInitState = I2cDev_InitState_Uninitialized;
   pDev->seqInfo.pDev                 = pDev;
   pDev->seqInfo.outSeqInfo.pSeq      = &pDev->seqInfo;
   pDev->seqInfo.inSeqInfo.pSeq       = &pDev->seqInfo;
   pDev->clntCfg.uBusFreqKhz = I2CDEV_DEFAULT_BUS_FREQ_KHZ;
   pDev->clntCfg.uByteTransferTimeoutUs =
         I2CDEV_DEFAULT_BYTE_TRANSFER_TIMEOUT_US;
   pDev->devInitState |= I2cDev_InitState_DeviceInit_Done;

   pDev->qupInfo.pQupRegs = (QupRegsType *) (pProp->virtBlockAddr);
   pDev->props = *pProp;

   return I2C_RES_SUCCESS;
}

/** @brief Deinitializes the device.

    This Function Deinitializes the device and releases
    resources acquired during init.

    @param[in] pDev    Pointer to device struct.

    @return          int32 .
  */
int32
I2cDev_DeInit
(
   I2cDev_Device          *pDev
)
{
   pDev->devInitState = I2cDev_InitState_Uninitialized;
   return I2C_RES_SUCCESS;
}

