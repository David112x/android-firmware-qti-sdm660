/*============================================================================
  FILE:         DalFgAdcInfo.c

  OVERVIEW:     FGADC DAL info file.

  DEPENDENCIES: None

                Copyright (c) 2016 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Proprietary and Confidential.
============================================================================*/
/*============================================================================
  EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.  Please
  use ISO format for dates.

  $Header: //components/rel/boot.xf/1.4/QcomPkg/Library/AdcLib/devices/fgadc/src/DalFgAdcInfo.c#2 $$DateTime: 2016/08/19 05:58:45 $$Author: c_mvanim $

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2016-04-22  jjo  Initial revision.

============================================================================*/
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "DALReg.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Static Function Declarations
 * -------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

DALResult
FgAdc_DalAdcDevice_Attach(const char *, DALDEVICEID, DalDeviceHandle **);

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

/*----------------------------------------------------------------------------
 * Global Data Definitions
 * -------------------------------------------------------------------------*/
const DALREG_DriverInfo DALFgAdc_DriverInfo =
{
   FgAdc_DalAdcDevice_Attach,
   0,
   NULL
};

/*----------------------------------------------------------------------------
 * Static Variable Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Static Function Declarations and Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Externalized Function Definitions
 * -------------------------------------------------------------------------*/

