/**
 * @file:  SpmiBlock.c
 * 
 * Copyright (c) 2013-2016 by Qualcomm Technologies 
 * Incorporated. All Rights Reserved. 
 * 
 * $DateTime: 2016/05/23 02:27:48 $
 * $Header: //components/rel/boot.xf/1.4/QcomPkg/Library/SPMILib/src/platform/config/bear/Sdm660/SpmiBlock.c#1 $
 * $Change: 10528659 $ 
 * 
 *                              Edit History
 * Date     Description
 * -------  -------------------------------------------------------------------
 * 10/1/13  Initial Version
 */

#include "SpmiInfo.h"
#include "SpmiTypes.h"
#include "SpmiHal.h"
#include "SpmiGenericConsts.h"
#include "SpmiUtils.h"
#include "SpmiOsTarget.h"

#define SPMI_PMIC_ARB_PHYS_ADDRESS 0x08000000
#define SPMI_BARE_OWNER_NUMBER     0

#define SPMI_MAX_CHANNELS_SUPPORTED   (HWIO_PMIC_ARB_REG_CHNLn_MAXn + 1)
#define SPMI_MAX_BUSES_SUPPORTED      (1)

static int16 periphMap[SPMI_MAX_PERIPH_ID + 1];
static ChannelMapEntry channelMap[SPMI_MAX_CHANNELS_SUPPORTED];
static SpmiDeviceGenerics generics = INIT_SPMI_DEV_GENERICS;

static SpmiTargetConfig spmiTgt =
{
    .hwioAddrStr    = "PMIC_ARB",
    .interruptVec   = 358,
};

SpmiDevInfo spmiDevices[] = {
   {
      .baseAddrs          = (uint8*)SPMI_PMIC_ARB_PHYS_ADDRESS,
      .uDevIdx            = 0,
      .reservedChan       = SPMI_MAX_CHANNELS_SUPPORTED - 1,
      .nextChanIdx        = 0,
      .reservedChanEn     = TRUE,   
      .dynamicChannelMode = FALSE,   
      .periphMap          = periphMap,
      .channelMap         = channelMap,
      .pGenerics          = &generics,
      .target             = (void*) &spmiTgt,    
   },
};

SpmiInfo spmiInfo = {
  .owner              = SPMI_BARE_OWNER_NUMBER,
  .uNumDevices        = SPMI_MAX_BUSES_SUPPORTED,
  .devices            = spmiDevices,
};

SpmiInfo * pSpmiBlockInfo = &spmiInfo;

