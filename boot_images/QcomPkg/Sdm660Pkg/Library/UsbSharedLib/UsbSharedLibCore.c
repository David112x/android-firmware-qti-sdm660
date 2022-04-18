/*=======================================================================*//**
 * @file        UsbSharedCore.c
 * @author:     gothekar
 * @date        15-Sept-2016
 *
 * @brief       USB common & shared USB core init implementation.
 *
 * @details     This file contains API's the Init sequence for HS and SS core implementation.
 *
 * @note        
 *              Copyright 2016 QUALCOMM Technologies Incorporated.
 *              All Rights Reserved.
 *              Qualcomm Confidential and Proprietary
 * 
*//*========================================================================*/

// ===========================================================================
// 
//                            EDIT HISTORY FOR FILE
//   This section contains comments describing changes made to the module.
//   Notice that changes are listed in reverse chronological order.
// 
// 
// when          who     what, where, why
// ----------   -----    ----------------------------------------------------------
// 09/15/16     arung 	 Initial revision
// 
// ===========================================================================

//----------------------------------------------------------------------------
// Include Files
//----------------------------------------------------------------------------
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include "UsbSharedLib.h"

void usb_shared_delay_us(uint32 usecs) {
    gBS->Stall (MICRO_STALL_UNITS(usecs));
}

void usb_shared_loop_here(void) { 
    static volatile uint32 loop_here = 0x1; 
	
    while(loop_here);
}

void usb_shared_uart_log_info(char *message) { 
    DebugPrint(EFI_D_ERROR,"%a\n", message);
}

void usb_shared_uart_log_error(char *message, uint32 value) { 
    DebugPrint(EFI_D_ERROR, "%a: %d\n", message, value);
}

void usb_shared_error_log(uint32 id_0, uint8 offset, uint32 param) {
    return;
}
