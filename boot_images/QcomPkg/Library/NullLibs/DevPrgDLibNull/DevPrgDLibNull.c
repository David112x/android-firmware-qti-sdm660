/** @file DeviceProgrammerDdrLibNull.c
  
  Stub functions for DeviceProgrammer DDR.

  Copyright (c) 2014, Qualcomm Technologies, Inc. All rights reserved.
**/

/*=============================================================================
                              EDIT HISTORY

  $Header: //components/rel/boot.xf/1.4/QcomPkg/Library/NullLibs/DevPrgDLibNull/DevPrgDLibNull.c#2 $
  $DateTime: 2016/08/19 05:58:45 $
  $Author: c_mvanim $

when       who       what, where, why
--------   ---       -----------------------------------------------------------
12/02/14   wkimberl  Initial revision.

=============================================================================*/

#include "boot_sbl_if.h"

/*!
 * Stub for boot_hand_control_to_deviceprogrammer_ddr_main()
 *
 * @param bl_shared_data
 *    The shared bootloader information.
 *
*****************************************************************************/
void
boot_hand_control_to_deviceprogrammer_ddr_main (bl_shared_data_type *bl_shared_data)
{
  (void)bl_shared_data;
}
