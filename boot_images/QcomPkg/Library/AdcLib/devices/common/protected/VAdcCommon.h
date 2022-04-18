#ifndef __VADC_COMMON_H__
#define __VADC_COMMON_H__
/*============================================================================
  @file VAdcCommon.h

  Common scaling functions and helper functions for VADC.

                Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Proprietary and Confidential.
============================================================================*/
/* $Header: //components/rel/boot.xf/1.4/QcomPkg/Library/AdcLib/devices/common/protected/VAdcCommon.h#2 $ */

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "DDIAdcDevice.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/
typedef struct
{
   uint32 uNumerator;
   uint32 uDenominator;
} VAdcChannelScalingFactor;

/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/
void
VAdcProcessConversionResult(
   const VAdcChannelScalingFactor *pScaling,
   VAdcScalingMethodType eScalingMethod,
   const AdcIntTableType *pIntTable,
   uint32 uPullUp,
   uint32 uFullScale_code,
   uint32 uFullScale_uV,
   uint32 uCode,
   AdcDeviceResultType *pResult
   );

void
VAdcProcessConversionResultInverse(
   const VAdcChannelScalingFactor *pScaling,
   VAdcScalingMethodType eScalingMethod,
   const AdcIntTableType *pIntTable,
   uint32 uPullUp,
   uint32 uFullScale_code,
   uint32 uFullScale_uV,
   int32 nPhysical,
   AdcDeviceResultType *pResult
   );

#endif /* #ifndef __VADC_COMMON_H__ */

