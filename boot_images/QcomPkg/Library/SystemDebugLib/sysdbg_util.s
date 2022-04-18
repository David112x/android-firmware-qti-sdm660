/*============================================================================

             SYSDBG ASSEMBLY ROUTINES

 Copyright 2014 - 2015 by Qualcomm Technologies Incorporated.  All Rights Reserved
============================================================================

============================================================================

                       EDIT HISTORY FOR MODULE

 $Header: //components/rel/boot.xf/1.4/QcomPkg/Library/SystemDebugLib/sysdbg_util.s#2 $
 $DateTime: 2016/08/19 05:58:45 $
 $Author: c_mvanim $

 This section contains comments describing changes made to the module.
 Notice that changes are listed in reverse chronological order.


 when      who     what, where, why
 --------  ---     ---------------------------------------------------------
 07/29/15  AJC     Issue with exclusive monitors with IMC / Hydra
 04/12/15  AJC     Initial Version
============================================================================

============================================================================

                        MODULE MACROS AND FUNCTIONS

============================================================================
    .section .code.SYSDB_UTIL_ASM, "ax", %progbits
    .p2align 3
=============================================================================*/

/* @Name: set_global_lock(global_lock_type* lock, uint64 value)
 Set the lock variable to a particular value atomically
 Arg0 : global lock address, value to set the lock
*/
.global set_global_lock
.type set_global_lock,%function
set_global_lock:
    sub sp, sp, 0x10
    stp x2, x3, [SP]
    ldr x3, [x0]
51:
    str x1, [x0]
    //cbnz w2, 51b
    mov x0, xzr
    mov w0, w2
    ldp x2, x3, [SP]
    add sp, sp, 0x10
    ret


/* @Name: get_global_lock(global_lock_type* lock)
 Get the lock value atomically
 Arg0 : global lock address, 
 Return Val : Lock value
*/

.global get_global_lock
.type get_global_lock,%function
get_global_lock:
    sub sp, sp, 0x10
    stp x2, x3, [SP]
    ldr x3, [x0]
52:
    str x3, [x0]
    //cbnz w2, 52b
    mov x0, x3
    ldp x2, x3, [SP]
    add sp, sp, 0x10
    ret
