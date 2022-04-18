//*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
//
//                 BOOT AARCH64 FASTCALL TZ ASM FUNCTIONS
//
// Copyright (c) 2013 - 2016 by Qualcomm Technologies, Incorporated. 
//                          All Rights Reserved.
//*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

//*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
//
//                           EDIT HISTORY FOR FILE
//
// This section contains comments describing changes made to the module.
// Notice that changes are listed in reverse chronological order.
//
//
// $Header: //components/rel/boot.xf/1.4/QcomPkg/XBLLoader/boot_Aarch64_fastcall_tz.s#3 $
// when       who     what, where, why
// --------   ---     --------------------------------------------------------
// 04/06/16   kpa     rename boot_fastcall_scm_2arg to boot_fastcall_scm
// 03/15/16   kpa     Added boot_fastcall_scm_2arg
// 12/04/15   plc     Update for new toolchain for XBL
// 07/30/14   plc     Update to new ARMv8 SMC standard
// 06/12/14   plc     Update to remove unnecessary 4-arg SMC call routine
// 01/30/14   plc     Call 2-arg SCM for 2 and 3 args, 4-arg for 4 only
// 01/20/13   plc     Update with SCM call support
// 11/01/13   plc     Initial revision for 64-bit MSM8994
//*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

//=======================================================================
//                             MODULE IMPORTS
//=======================================================================

  .extern mmu_invalidate_data_cache
  
//=======================================================================
//                             MODULE EXPORTS
//=======================================================================

  .global boot_scm

//=======================================================================
//
//                             MODULE DATA AREA
//
//=======================================================================

  //PRESERVE8
  //AREA    BOOT_UTIL_ASM, CODE, READONLY
  //CODE
  .section BOOT_UTIL_ASM, "ax", %progbits
  .p2align 8

  .macro    PushTwo x0, x1
  stp     \x1, \x0, [sp, #-0x10]!
  .endm

  .macro    PopTwo x0, x1
  ldp     \x0, \x1, [sp], #0x10
  .endm

  .macro PushSMC
  PushTwo x30, x29
  PushTwo x28, x27
  PushTwo x26, x25
  PushTwo x24, x23
  PushTwo x22, x21
  PushTwo x20, x19
  PushTwo x18, x17
  PushTwo x16, x15
  .endm

  .macro PopSMC
  PopTwo x15, x16
  PopTwo x17, x18
  PopTwo x19, x20
  PopTwo x21, x22
  PopTwo x23, x24
  PopTwo x25, x26
  PopTwo x27, x28
  PopTwo x29, x30
  .endm

  .macro SMCCALL
redo:
  smc     0x0
smc_ret:
  cmp     x0, #1    //Check smc return value
  beq     redo      //Redo smc if value is 1
   //bl      mmu_invalidate_data_cache
  .endm
  

//===========================================================================
//
// FUNCTION boot_fastcall_scm
// int boot_fastcall_scm(uintnt id, uintnt token, uintnt r0, uintnt r1, boot_tz_result_regs_t* resp_buff_ptr);
//
// ARGS
// x0  - SMC ID
// x1  - Parameter ID
// x2  - First argument to TZ syscall
// x3  - Second argument to TZ syscall
// x4  - Third argument to TZ syscall
// x5  - Fourth argument to TZ syscall or ptr to more args
// x6  - Trusted OS Session ID
// x7  - Local buffer that will be populated with SMC result registers
//
// RETURN
//  reg X0: error code is what returned by Tz from smc call         
//
// DESCRIPTION
//   Make a secure monitor call to TZ to perform read write in secure mode
//============================================================================
.type boot_scm @function
boot_scm:
  PushTwo x8, x7
  PushSMC
  SMCCALL
  PopSMC
  PopTwo  x7, x8
  cmp     x7, #0
  beq     scm_exit
  str     x1, [x7, #0x0]
  str     x2, [x7, #0x8]
  str     x3, [x7, #0x10]
scm_exit: 
  ret

//============================================================================
  .end

