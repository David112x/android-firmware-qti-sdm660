#ifndef __QFPROM_PTE_LPASS_HWIO_H__
#define __QFPROM_PTE_LPASS_HWIO_H__
/*
===========================================================================
*/
/**
  @file qfprom_pte_lpass_hwio.h
  @brief Auto-generated HWIO interface include file.

  This file contains HWIO register definitions for the following modules:
    SECURITY_CONTROL_CORE
    LPASS_QDSP6SS_CSR

  'Include' filters applied: <none>
  'Exclude' filters applied: RESERVED DUMMY 
*/
/*
  ===========================================================================

  Copyright (c) 2016 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.

  ===========================================================================

  $Header: //components/rel/rpm.bf/1.8/core/power/sleep/src/660/qfprom_pte_lpass_hwio.h#2 $
  $DateTime: 2016/11/07 22:46:44 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "msmhwiobase.h"



/*----------------------------------------------------------------------------
 * MODULE: SECURITY_CONTROL_CORE
 *--------------------------------------------------------------------------*/

#define SECURITY_CONTROL_CORE_REG_BASE                                                           (SECURITY_CONTROL_BASE      + 0x00000000)

#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_ADDR(n)                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000000 + 0x4 * (n))
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_MAXn                                                             71
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_ADDR(n), HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_RMSK)
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_ADDR(n), mask)
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_BMSK                                      0xffffffff
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_SHFT                                             0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_ADDR(n)                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000120 + 0x4 * (n))
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_MAXn                                                             3
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REGIONn_ADDR(n), HWIO_QFPROM_RAW_QC_SPARE_REGIONn_RMSK)
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REGIONn_ADDR(n), mask)
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REGIONn_ADDR(n),val)
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REGIONn_ADDR(n),mask,val,HWIO_QFPROM_RAW_QC_SPARE_REGIONn_INI(n))
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_QC_SPARE_BMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REGIONn_QC_SPARE_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000130)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_PTE_DATA0_BMSK                                              0xe0000000
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_PTE_DATA0_SHFT                                                    0x1d
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_MACCHIATO_EN_BMSK                                           0x10000000
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_MACCHIATO_EN_SHFT                                                 0x1c
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_FEATURE_ID_BMSK                                              0xff00000
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_FEATURE_ID_SHFT                                                   0x14
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_JTAG_ID_BMSK                                                   0xfffff
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_JTAG_ID_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000134)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_PTE_DATA1_BMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_PTE_DATA1_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000138)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_SERIAL_NUM_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_SERIAL_NUM_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000013c)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_PTE_DATA1_BMSK                                              0xffff0000
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_PTE_DATA1_SHFT                                                    0x10
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_CHIP_ID_BMSK                                                    0xffff
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_CHIP_ID_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000140)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_PTE_DATA0_BMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_PTE_DATA0_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000144)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_PTE_DATA1_BMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_PTE_DATA1_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000148)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW3_LSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW3_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_PTE_DATA0_BMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_PTE_DATA0_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000014c)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR, HWIO_QFPROM_RAW_PTE_ROW3_MSB_RMSK)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW3_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_PTE_DATA1_BMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_PTE_DATA1_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000150)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR, HWIO_QFPROM_RAW_RD_PERM_LSB_RMSK)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR,m,v,HWIO_QFPROM_RAW_RD_PERM_LSB_IN)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RSVD0_BMSK                                                   0x80000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RSVD0_SHFT                                                         0x1f
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG30_BMSK                                         0x40000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG30_SHFT                                               0x1e
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG29_BMSK                                         0x20000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG29_SHFT                                               0x1d
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG28_BMSK                                         0x10000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG28_SHFT                                               0x1c
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG27_BMSK                                          0x8000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG27_SHFT                                               0x1b
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG26_BMSK                                          0x4000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG26_SHFT                                               0x1a
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH1_BMSK                                                 0x2000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH1_SHFT                                                      0x19
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                          0x1000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                               0x18
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_ROM_PATCH_BMSK                                            0x800000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_ROM_PATCH_SHFT                                                0x17
#define HWIO_QFPROM_RAW_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                    0x400000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                        0x16
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                    0x200000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                        0x15
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SEC_BOOT_BMSK                                              0x100000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SEC_BOOT_SHFT                                                  0x14
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                         0x80000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                            0x13
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG18_BMSK                                             0x40000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG18_SHFT                                                0x12
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG17_BMSK                                             0x20000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG17_SHFT                                                0x11
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG16_BMSK                                             0x10000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG16_SHFT                                                0x10
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CM_FEAT_CONFIG_BMSK                                              0x8000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CM_FEAT_CONFIG_SHFT                                                 0xf
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MEM_CONFIG_BMSK                                                  0x4000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MEM_CONFIG_SHFT                                                     0xe
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CALIB_BMSK                                                       0x2000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CALIB_SHFT                                                          0xd
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH0_BMSK                                                    0x1000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH0_SHFT                                                       0xc
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEAT_CONFIG_BMSK                                                  0x800
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEAT_CONFIG_SHFT                                                    0xb
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_CONFIG_BMSK                                                   0x400
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_CONFIG_SHFT                                                     0xa
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                              0x200
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                                0x9
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                              0x100
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                                0x8
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                               0x80
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                                0x7
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                               0x40
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                                0x6
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEC_EN_BMSK                                                        0x20
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEC_EN_SHFT                                                         0x5
#define HWIO_QFPROM_RAW_RD_PERM_LSB_WR_PERM_BMSK                                                       0x10
#define HWIO_QFPROM_RAW_RD_PERM_LSB_WR_PERM_SHFT                                                        0x4
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RD_PERM_BMSK                                                        0x8
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RD_PERM_SHFT                                                        0x3
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PTE_BMSK                                                            0x4
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PTE_SHFT                                                            0x2
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REGION_BMSK                                                0x2
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REGION_SHFT                                                0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CRI_CM_PRIVATE_BMSK                                                 0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CRI_CM_PRIVATE_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000154)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_RAW_RD_PERM_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR, HWIO_QFPROM_RAW_RD_PERM_MSB_RMSK)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR,m,v,HWIO_QFPROM_RAW_RD_PERM_MSB_IN)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_RSVD0_BMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_RD_PERM_MSB_RSVD0_SHFT                                                          0x0

#define HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000158)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR, HWIO_QFPROM_RAW_WR_PERM_LSB_RMSK)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR,m,v,HWIO_QFPROM_RAW_WR_PERM_LSB_IN)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RSVD0_BMSK                                                   0x80000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RSVD0_SHFT                                                         0x1f
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG30_BMSK                                         0x40000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG30_SHFT                                               0x1e
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG29_BMSK                                         0x20000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG29_SHFT                                               0x1d
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG28_BMSK                                         0x10000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG28_SHFT                                               0x1c
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG27_BMSK                                          0x8000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG27_SHFT                                               0x1b
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG26_BMSK                                          0x4000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG26_SHFT                                               0x1a
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH1_BMSK                                                 0x2000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH1_SHFT                                                      0x19
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                          0x1000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                               0x18
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_ROM_PATCH_BMSK                                            0x800000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_ROM_PATCH_SHFT                                                0x17
#define HWIO_QFPROM_RAW_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                    0x400000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                        0x16
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                    0x200000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                        0x15
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SEC_BOOT_BMSK                                              0x100000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SEC_BOOT_SHFT                                                  0x14
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                         0x80000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                            0x13
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG18_BMSK                                             0x40000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG18_SHFT                                                0x12
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG17_BMSK                                             0x20000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG17_SHFT                                                0x11
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG16_BMSK                                             0x10000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG16_SHFT                                                0x10
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CM_FEAT_CONFIG_BMSK                                              0x8000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CM_FEAT_CONFIG_SHFT                                                 0xf
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MEM_CONFIG_BMSK                                                  0x4000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MEM_CONFIG_SHFT                                                     0xe
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CALIB_BMSK                                                       0x2000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CALIB_SHFT                                                          0xd
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH0_BMSK                                                    0x1000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH0_SHFT                                                       0xc
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEAT_CONFIG_BMSK                                                  0x800
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEAT_CONFIG_SHFT                                                    0xb
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_CONFIG_BMSK                                                   0x400
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_CONFIG_SHFT                                                     0xa
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                              0x200
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                                0x9
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                              0x100
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                                0x8
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                               0x80
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                                0x7
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                               0x40
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                                0x6
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEC_EN_BMSK                                                        0x20
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEC_EN_SHFT                                                         0x5
#define HWIO_QFPROM_RAW_WR_PERM_LSB_WR_PERM_BMSK                                                       0x10
#define HWIO_QFPROM_RAW_WR_PERM_LSB_WR_PERM_SHFT                                                        0x4
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RD_PERM_BMSK                                                        0x8
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RD_PERM_SHFT                                                        0x3
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PTE_BMSK                                                            0x4
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PTE_SHFT                                                            0x2
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REGION_BMSK                                                0x2
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REGION_SHFT                                                0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CRI_CM_PRIVATE_BMSK                                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CRI_CM_PRIVATE_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000015c)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_RAW_WR_PERM_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR, HWIO_QFPROM_RAW_WR_PERM_MSB_RMSK)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR,m,v,HWIO_QFPROM_RAW_WR_PERM_MSB_IN)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_RSVD0_BMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_WR_PERM_MSB_RSVD0_SHFT                                                          0x0

#define HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000160)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_RMSK                                                          0xffffffff
#define HWIO_QFPROM_RAW_FEC_EN_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR, HWIO_QFPROM_RAW_FEC_EN_LSB_RMSK)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEC_EN_LSB_IN)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_RSVD0_BMSK                                                    0x80000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_RSVD0_SHFT                                                          0x1f
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_EN_BMSK                                          0x40000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_EN_SHFT                                                0x1e
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_EN_BMSK                                          0x20000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_EN_SHFT                                                0x1d
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION28_FEC_EN_BMSK                                          0x10000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION28_FEC_EN_SHFT                                                0x1c
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION27_FEC_EN_BMSK                                           0x8000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION27_FEC_EN_SHFT                                                0x1b
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION26_FEC_EN_BMSK                                           0x4000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION26_FEC_EN_SHFT                                                0x1a
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION25_FEC_EN_BMSK                                           0x2000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION25_FEC_EN_SHFT                                                0x19
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION24_FEC_EN_BMSK                                           0x1000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION24_FEC_EN_SHFT                                                0x18
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION23_FEC_EN_BMSK                                            0x800000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION23_FEC_EN_SHFT                                                0x17
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION22_FEC_EN_BMSK                                            0x400000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION22_FEC_EN_SHFT                                                0x16
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION21_FEC_EN_BMSK                                            0x200000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION21_FEC_EN_SHFT                                                0x15
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION20_FEC_EN_BMSK                                            0x100000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION20_FEC_EN_SHFT                                                0x14
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION19_FEC_EN_BMSK                                             0x80000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION19_FEC_EN_SHFT                                                0x13
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION18_FEC_EN_BMSK                                             0x40000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION18_FEC_EN_SHFT                                                0x12
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION17_FEC_EN_BMSK                                             0x20000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION17_FEC_EN_SHFT                                                0x11
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION16_FEC_EN_BMSK                                             0x10000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION16_FEC_EN_SHFT                                                0x10
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION15_FEC_EN_BMSK                                              0x8000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION15_FEC_EN_SHFT                                                 0xf
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION14_FEC_EN_BMSK                                              0x4000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION14_FEC_EN_SHFT                                                 0xe
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION13_FEC_EN_BMSK                                              0x2000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION13_FEC_EN_SHFT                                                 0xd
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION12_FEC_EN_BMSK                                              0x1000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION12_FEC_EN_SHFT                                                 0xc
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION11_FEC_EN_BMSK                                               0x800
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION11_FEC_EN_SHFT                                                 0xb
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION10_FEC_EN_BMSK                                               0x400
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION10_FEC_EN_SHFT                                                 0xa
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION9_FEC_EN_BMSK                                                0x200
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION9_FEC_EN_SHFT                                                  0x9
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION8_FEC_EN_BMSK                                                0x100
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION8_FEC_EN_SHFT                                                  0x8
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION7_FEC_EN_BMSK                                                 0x80
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION7_FEC_EN_SHFT                                                  0x7
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION6_FEC_EN_BMSK                                                 0x40
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION6_FEC_EN_SHFT                                                  0x6
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION5_FEC_EN_BMSK                                                 0x20
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION5_FEC_EN_SHFT                                                  0x5
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION4_FEC_EN_BMSK                                                 0x10
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION4_FEC_EN_SHFT                                                  0x4
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION3_FEC_EN_BMSK                                                  0x8
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION3_FEC_EN_SHFT                                                  0x3
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION2_FEC_EN_BMSK                                                  0x4
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION2_FEC_EN_SHFT                                                  0x2
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION1_FEC_EN_BMSK                                                  0x2
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION1_FEC_EN_SHFT                                                  0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION0_FEC_EN_BMSK                                                  0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION0_FEC_EN_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000164)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_RMSK                                                          0xffffffff
#define HWIO_QFPROM_RAW_FEC_EN_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR, HWIO_QFPROM_RAW_FEC_EN_MSB_RMSK)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEC_EN_MSB_IN)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_RSVD0_BMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_FEC_EN_MSB_RSVD0_SHFT                                                           0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000168)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_XBL0_BMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_XBL0_SHFT                                                   0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000016c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_XBL1_BMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_XBL1_SHFT                                                   0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000170)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_BMSK                              0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_SHFT                                     0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000174)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_XBL_SEC_BMSK                                         0xfe000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_XBL_SEC_SHFT                                               0x19
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_RPM_BMSK                                              0x1fe0000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_RPM_SHFT                                                   0x11
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_TZ_BMSK                                                 0x1ffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_TZ_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000178)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RSVD1_BMSK                                           0xc0000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RSVD1_SHFT                                                 0x1e
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_BMSK                                 0x3e000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_SHFT                                       0x19
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_BMSK                             0x1000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_SHFT                                  0x18
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_BMSK                               0xffff00
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_SHFT                                    0x8
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_SAFESWITCH_BMSK                                            0xff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_SAFESWITCH_SHFT                                             0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000017c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_RSVD1_BMSK                                           0xf0000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_RSVD1_SHFT                                                 0x1c
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_BMSK                                       0xffe0000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_SHFT                                            0x11
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_BMSK                                       0x1f000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_SHFT                                           0xc
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_HYPERVISOR_BMSK                                           0xfff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_HYPERVISOR_SHFT                                             0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000180)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MSS_BMSK                                             0xffff0000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MSS_SHFT                                                   0x10
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MBA_BMSK                                                 0xffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MBA_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000184)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR, HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RMSK)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RSVD0_BMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RSVD0_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000188)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR, HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DCC_DEBUG_DISABLE_BMSK                               0x80000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DCC_DEBUG_DISABLE_SHFT                                     0x1f
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_APB_DFD_DISABLE_BMSK                            0x40000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_APB_DFD_DISABLE_SHFT                                  0x1e
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_BMSK                               0x20000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_SHFT                                     0x1d
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_BMSK                            0x10000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_SHFT                                  0x1c
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RSVD2_BMSK                                            0xe000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RSVD2_SHFT                                                 0x19
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                 0x1000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                      0x18
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                 0x800000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                     0x17
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_BMSK                                    0x400000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_SHFT                                        0x16
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_BMSK                             0x200000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_SHFT                                 0x15
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_BMSK                              0x100000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_SHFT                                  0x14
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_BMSK                            0x80000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_SHFT                               0x13
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RSVD1_BMSK                                              0x60000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RSVD1_SHFT                                                 0x11
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_BMSK                             0x10000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_SHFT                                0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_BMSK                                     0x8000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_SHFT                                        0xf
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_WDOG_EN_BMSK                                             0x4000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_WDOG_EN_SHFT                                                0xe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SPDM_SECURE_MODE_BMSK                                    0x2000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SPDM_SECURE_MODE_SHFT                                       0xd
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_BMSK                                0x1000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_SHFT                                   0xc
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RSVD0_BMSK                                                0xc00
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RSVD0_SHFT                                                  0xa
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_BMSK                                            0x3e0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SHFT                                              0x5
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_BMSK                                   0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_SHFT                                    0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_BMSK                                 0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_SHFT                                 0x3
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_BMSK                                    0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_SHFT                                    0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_BMSK                                           0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_SHFT                                           0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_BMSK                                        0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_SHFT                                        0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000018c)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR, HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_SPIDEN_DISABLE_BMSK                            0x80000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_SPIDEN_DISABLE_SHFT                                  0x1f
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_SPIDEN_DISABLE_BMSK                             0x40000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_SPIDEN_DISABLE_SHFT                                   0x1e
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_SPIDEN_DISABLE_BMSK                              0x20000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_SPIDEN_DISABLE_SHFT                                    0x1d
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_SPIDEN_DISABLE_BMSK                             0x10000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_SPIDEN_DISABLE_SHFT                                   0x1c
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_SPNIDEN_DISABLE_BMSK                            0x8000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_SPNIDEN_DISABLE_SHFT                                 0x1b
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_SPNIDEN_DISABLE_BMSK                            0x4000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_SPNIDEN_DISABLE_SHFT                                 0x1a
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_SPNIDEN_DISABLE_BMSK                             0x2000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_SPNIDEN_DISABLE_SHFT                                  0x19
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_SPNIDEN_DISABLE_BMSK                              0x1000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_SPNIDEN_DISABLE_SHFT                                   0x18
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_SPNIDEN_DISABLE_BMSK                              0x800000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_SPNIDEN_DISABLE_SHFT                                  0x17
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_MSS_NIDEN_DISABLE_BMSK                                 0x400000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_MSS_NIDEN_DISABLE_SHFT                                     0x16
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_NIDEN_DISABLE_BMSK                        0x200000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_NIDEN_DISABLE_SHFT                            0x15
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_NIDEN_DISABLE_BMSK                               0x100000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_NIDEN_DISABLE_SHFT                                   0x14
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RPM_NIDEN_DISABLE_BMSK                                  0x80000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RPM_NIDEN_DISABLE_SHFT                                     0x13
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_NIDEN_DISABLE_BMSK                                 0x40000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_NIDEN_DISABLE_SHFT                                    0x12
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_NIDEN_DISABLE_BMSK                                0x20000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_NIDEN_DISABLE_SHFT                                   0x11
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_NIDEN_DISABLE_BMSK                                  0x10000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_NIDEN_DISABLE_SHFT                                     0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_BMSK                                  0x8000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_SHFT                                     0xf
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_MSS_DBGEN_DISABLE_BMSK                                   0x4000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_MSS_DBGEN_DISABLE_SHFT                                      0xe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_A5X_ISDB_DBGEN_DISABLE_BMSK                              0x2000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_A5X_ISDB_DBGEN_DISABLE_SHFT                                 0xd
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_VENUS_0_DBGEN_DISABLE_BMSK                               0x1000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_VENUS_0_DBGEN_DISABLE_SHFT                                  0xc
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RSVD1_BMSK                                                0x800
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RSVD1_SHFT                                                  0xb
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_DBGEN_DISABLE_BMSK                           0x400
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_DBGEN_DISABLE_SHFT                             0xa
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_DBGEN_DISABLE_BMSK                                  0x200
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PIMEM_DBGEN_DISABLE_SHFT                                    0x9
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RPM_DBGEN_DISABLE_BMSK                                    0x100
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RPM_DBGEN_DISABLE_SHFT                                      0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_DBGEN_DISABLE_BMSK                                    0x80
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_WCSS_DBGEN_DISABLE_SHFT                                     0x7
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_Q6_DBGEN_DISABLE_BMSK                                0x40
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_LPASS_Q6_DBGEN_DISABLE_SHFT                                 0x6
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_DBGEN_DISABLE_BMSK                                     0x20
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_DBGEN_DISABLE_SHFT                                      0x5
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_BMSK                                    0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_SHFT                                     0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_DEVICEEN_DISABLE_BMSK                                   0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DAP_DEVICEEN_DISABLE_SHFT                                   0x3
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RPM_DAPEN_DISABLE_BMSK                                      0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RPM_DAPEN_DISABLE_SHFT                                      0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RSVD0_BMSK                                                  0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RSVD0_SHFT                                                  0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DEBUG_BUS_DISABLE_BMSK                                      0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_DEBUG_BUS_DISABLE_SHFT                                      0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000190)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR, HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD1_BMSK                                           0xffff8000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD1_SHFT                                                  0xf
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG30_SECURE_BMSK                              0x4000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG30_SECURE_SHFT                                 0xe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG29_SECURE_BMSK                              0x2000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG29_SECURE_SHFT                                 0xd
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG28_SECURE_BMSK                              0x1000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG28_SECURE_SHFT                                 0xc
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG27_SECURE_BMSK                               0x800
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG27_SECURE_SHFT                                 0xb
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG26_SECURE_BMSK                               0x400
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG26_SECURE_SHFT                                 0xa
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD0_BMSK                                                0x3fe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD0_SHFT                                                  0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_LPASS_SPIDEN_DISABLE_BMSK                                   0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_LPASS_SPIDEN_DISABLE_SHFT                                   0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000194)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR, HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_BMSK                                  0xffff0000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_SHFT                                        0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_BMSK                                           0xffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_SHFT                                              0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000198)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_VID_BMSK                                      0xffff0000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_VID_SHFT                                            0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_PID_BMSK                                          0xffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_PID_SHFT                                             0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000019c)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RSVD0_BMSK                                           0xffffff00
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RSVD0_SHFT                                                  0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_BMSK                              0xff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_SHFT                               0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001a0)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_BMSK                         0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_SHFT                               0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_BMSK                                   0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_SHFT                                         0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_BMSK                         0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_SHFT                               0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                           0x1fe00000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                                 0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                            0x180000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                                0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_BMSK                         0x40000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_SHFT                            0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_BMSK                         0x20000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_SHFT                            0x11
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_BMSK                                  0x10000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_SHFT                                     0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_BMSK                                0x8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_SHFT                                   0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_BMSK                                0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_SHFT                                   0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_BMSK                                    0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_SHFT                                       0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                       0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                          0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                              0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                                0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                      0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                        0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                       0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                         0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_BMSK                                        0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_SHFT                                          0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                           0x80
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                            0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                                 0x40
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                                  0x6
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_BMSK                                        0x20
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_SHFT                                         0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_BMSK                                       0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_SHFT                                        0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_BMSK                                        0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_SHFT                                        0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                                0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                                0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001a4)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                              0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                    0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                    0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                          0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_BMSK                                   0x10000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_SHFT                                         0x1c
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_BMSK                               0x8000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_SHFT                                    0x1b
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_BMSK                            0x4000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_SHFT                                 0x1a
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_BMSK                0x2000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                     0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_BMSK                    0x1000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_SHFT                         0x18
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_BMSK                 0x800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_SHFT                     0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                                0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                    0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_BMSK                                      0x200000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_SHFT                                          0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_BMSK                                 0x100000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_SHFT                                     0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_BMSK                          0x80000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_SHFT                             0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                                 0x7c000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                     0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                              0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                                 0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_BMSK                                       0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_SHFT                                          0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                          0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                            0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_BMSK                                       0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_SHFT                                         0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                        0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                          0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                         0x1e0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                           0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                               0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                                0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_BMSK                                  0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_SHFT                                  0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_BMSK                                   0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_SHFT                                   0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_BMSK                                     0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_SHFT                                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_BMSK                                    0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_SHFT                                    0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001a8)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_BMSK                                0xfff00000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_SHFT                                      0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_BMSK                              0x80000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_SHFT                                 0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_BMSK                                       0x40000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_SHFT                                          0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_BMSK                                   0x20000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_SHFT                                      0x11
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_BMSK                                  0x18000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_SHFT                                      0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                        0x7fe0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                           0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_BMSK                          0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_SHFT                           0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001ac)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_BMSK                         0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_SHFT                               0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                         0x60000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                               0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                        0x1fe00000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                              0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_BMSK                                 0x100000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_SHFT                                     0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_RSVD1_BMSK                                             0xf0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_RSVD1_SHFT                                                0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_BMSK                                   0xffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_SHFT                                      0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001b0)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_BMSK                        0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_SHFT                              0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_BMSK                           0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_SHFT                                 0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_BMSK                  0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_SHFT                        0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_BMSK                         0x10000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_SHFT                               0x1c
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_BMSK                            0x8000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_SHFT                                 0x1b
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_BMSK                           0x4000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_SHFT                                0x1a
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_BMSK                          0x2000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_SHFT                               0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_BMSK                            0x1000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_SHFT                                 0x18
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                            0x800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                                0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_BMSK                             0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_SHFT                                 0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_BMSK                        0x200000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_SHFT                            0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_BMSK                         0x100000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_SHFT                             0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_BMSK                 0x80000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_SHFT                    0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_BMSK                     0x40000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_SHFT                        0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_BMSK                            0x20000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_SHFT                               0x11
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_BMSK                              0x10000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_SHFT                                 0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_BMSK                              0x8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_SHFT                                 0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_BMSK                          0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_SHFT                             0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_BMSK                               0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_SHFT                                  0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                              0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                                 0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_BMSK                             0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_SHFT                               0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_BMSK                                0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_SHFT                                  0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_DSI_0_DISABLE_BMSK                                       0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_DSI_0_DISABLE_SHFT                                         0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_BMSK                                0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_SHFT                                  0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_BMSK                                 0x80
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_SHFT                                  0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_BMSK                              0x40
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_SHFT                               0x6
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_BMSK                                0x20
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_SHFT                                 0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_BMSK                                0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_SHFT                                 0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_BMSK                                 0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_SHFT                                 0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_BMSK                                      0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_SHFT                                      0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                       0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                           0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                           0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001b4)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_BMSK                                 0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_SHFT                                       0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_BMSK                           0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_SHFT                                 0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_BMSK                                  0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_SHFT                                        0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SILVER_PLL_MAX_FREQ_LVAL_BMSK                       0x1fe00000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SILVER_PLL_MAX_FREQ_LVAL_SHFT                             0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                               0x1c0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                                   0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_GOLD_PLL_MAX_FREQ_LVAL_BMSK                            0x3fc00
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_GOLD_PLL_MAX_FREQ_LVAL_SHFT                                0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_BMSK                    0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_SHFT                      0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_BMSK                             0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_SHFT                               0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_BMSK                              0x80
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_SHFT                               0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_BMSK                               0x40
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_SHFT                                0x6
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_BMSK                                0x20
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_SHFT                                 0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_BMSK                               0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_SHFT                                0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_BMSK                              0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_SHFT                              0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_BMSK                              0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_SHFT                              0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_BMSK                               0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_SHFT                               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_BMSK                                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_SHFT                                0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001b8)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_BMSK               0xfffc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_SHFT                     0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_TAP_INSTR_DISABLE_BMSK                                 0x3ffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_TAP_INSTR_DISABLE_SHFT                                     0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001bc)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_SEC_TAP_ACCESS_DISABLE_BMSK                         0xfffc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_SEC_TAP_ACCESS_DISABLE_SHFT                               0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_BMSK                 0x3ffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_SHFT                     0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001c0)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_PATCH_VERSION_BMSK                        0xfe000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_PATCH_VERSION_SHFT                              0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_APPS_PBL_PATCH_VERSION_BMSK                          0x1fc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_APPS_PBL_PATCH_VERSION_SHFT                               0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_APPS_PBL_BOOT_SPEED_BMSK                               0x30000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_APPS_PBL_BOOT_SPEED_SHFT                                  0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_BOOT_BMSK                                     0x8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_BOOT_SHFT                                        0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RSVD1_BMSK                                              0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RSVD1_SHFT                                                 0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_APPS_BOOT_FROM_ROM_BMSK                                 0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_APPS_BOOT_FROM_ROM_SHFT                                    0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RSVD0_BMSK                                              0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RSVD0_SHFT                                                 0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MODEM_BOOT_FROM_ROM_BMSK                                 0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MODEM_BOOT_FROM_ROM_SHFT                                   0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MSA_ENA_BMSK                                             0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_MSA_ENA_SHFT                                               0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_FORCE_MSA_AUTH_EN_BMSK                                   0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_FORCE_MSA_AUTH_EN_SHFT                                     0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ARM_CE_DISABLE_USAGE_BMSK                                0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ARM_CE_DISABLE_USAGE_SHFT                                  0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_BOOT_ROM_CFG_BMSK                                         0xff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_BOOT_ROM_CFG_SHFT                                          0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001c4)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR, HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RMSK)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_APPS_BOOT_TRIGGER_DISABLE_BMSK                      0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_APPS_BOOT_TRIGGER_DISABLE_SHFT                            0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_BMSK                     0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_SHFT                           0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_XBL_SEC_AUTH_DISABLE_BMSK                           0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_XBL_SEC_AUTH_DISABLE_SHFT                                 0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_MSM_PKG_TYPE_BMSK                                   0x10000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_MSM_PKG_TYPE_SHFT                                         0x1c
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RSVD3_BMSK                                           0xffc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RSVD3_SHFT                                                0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_FOUNDRY_ID_BMSK                                        0x3c000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_FOUNDRY_ID_SHFT                                            0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_PLL_CFG_BMSK                                            0x3ff0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_PLL_CFG_SHFT                                               0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_APPS_PBL_PLL_CTRL_BMSK                                     0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_APPS_PBL_PLL_CTRL_SHFT                                     0x0

#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001c8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_MAXn                                                            3
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_HASH_DATA0_BMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_HASH_DATA0_SHFT                                               0x0

#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001cc + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_MAXn                                                            3
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_HASH_DATA1_BMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_HASH_DATA1_SHFT                                               0x0

#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001e8)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_LMH_CS_FUSES_SLOPE_16_0_BMSK                              0xffff8000
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_LMH_CS_FUSES_SLOPE_16_0_SHFT                                     0xf
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_VREF_TRIM_BMSK                                 0x7f80
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_VREF_TRIM_SHFT                                    0x7
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_ENABLE_BMSK                                      0x40
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_ENABLE_SHFT                                       0x6
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_VREF_TRIM_BMSK                                    0x3e
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_VREF_TRIM_SHFT                                     0x1
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_ENABLE_BMSK                                        0x1
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_ENABLE_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001ec)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_LMH_CS_FUSES_INTERCEPT_8_0_BMSK                           0xff800000
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_LMH_CS_FUSES_INTERCEPT_8_0_SHFT                                 0x17
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_LMH_CS_FUSES_SLOPE_39_17_BMSK                               0x7fffff
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_LMH_CS_FUSES_SLOPE_39_17_SHFT                                    0x0

#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001f0)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_LMH_FUSES_AMP_COMP_0_BMSK                                 0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_LMH_FUSES_AMP_COMP_0_SHFT                                       0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_LMH_CS_FUSES_INTERCEPT_39_9_BMSK                          0x7fffffff
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_LMH_CS_FUSES_INTERCEPT_39_9_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001f4)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_SPARE0_BMSK                                               0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_SPARE0_SHFT                                                     0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_WEST_BGV_TRIM_BMSK                                 0x7f800000
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_WEST_BGV_TRIM_SHFT                                       0x17
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_EAST_BGV_TRIM_BMSK                                   0x7f8000
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_EAST_BGV_TRIM_SHFT                                        0xf
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_BANDGAP_TRIM_BMSK                                             0x7f00
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_BANDGAP_TRIM_SHFT                                                0x8
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_GPU_LDOVREFTRIM_BMSK                                            0xf8
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_GPU_LDOVREFTRIM_SHFT                                             0x3
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_LMH_FUSES_AMP_COMP_3_1_BMSK                                      0x7
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_LMH_FUSES_AMP_COMP_3_1_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001f8)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_1_0_BMSK                    0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_1_0_SHFT                          0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_SPTP_BMSK                          0x3ff00000
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_SPTP_SHFT                                0x14
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_RAC_BMSK                              0xffc00
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_RAC_SHFT                                  0xa
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_HM_BMSK                                 0x3ff
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_HM_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001fc)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_AMP_COMP_BMSK                            0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_AMP_COMP_SHFT                                  0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_SPTP_BMSK                       0xffc0000
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_SPTP_SHFT                            0x12
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_RAC_BMSK                          0x3ff00
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_RAC_SHFT                              0x8
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_9_2_BMSK                          0xff
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_9_2_SHFT                           0x0

#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000200)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW3_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW3_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_SVS_3_0_BMSK                        0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_SVS_3_0_SHFT                              0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_NOM_BMSK                             0xf000000
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_NOM_SHFT                                  0x18
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_TUR_BMSK                              0xf00000
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_TUR_SHFT                                  0x14
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS2_BMSK                                     0xf8000
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS2_SHFT                                         0xf
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS_BMSK                                       0x7c00
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS_SHFT                                          0xa
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_NOM_BMSK                                        0x3e0
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_NOM_SHFT                                          0x5
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_TUR_BMSK                                         0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_CPR0_TARG_VOLT_TUR_SHFT                                          0x0

#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000204)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW3_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW3_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS2_BMSK                                  0xf8000000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS2_SHFT                                        0x1b
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS_BMSK                                    0x7c00000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS_SHFT                                         0x16
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_NOM_BMSK                                     0x3e0000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_NOM_SHFT                                         0x11
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_TUR_BMSK                                      0x1f000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR1_TARG_VOLT_TUR_SHFT                                          0xc
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR0_AGING_BMSK                                                0xff0
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR0_AGING_SHFT                                                  0x4
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_BMSK                                  0xf
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_SHFT                                  0x0

#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000208)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW4_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR2_TARG_VOLT_NOM_2_0_BMSK                               0xe0000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR2_TARG_VOLT_NOM_2_0_SHFT                                     0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR2_TARG_VOLT_TUR_BMSK                                   0x1f000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR2_TARG_VOLT_TUR_SHFT                                         0x18
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_AGING_BMSK                                             0xff0000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_AGING_SHFT                                                 0x10
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS2_BMSK                               0xf000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS2_SHFT                                  0xc
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS_BMSK                                 0xf00
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS_SHFT                                   0x8
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_NOM_BMSK                                  0xf0
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_NOM_SHFT                                   0x4
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_TUR_BMSK                                   0xf
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_TUR_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000020c)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW4_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_AGING_3_0_BMSK                                       0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_AGING_3_0_SHFT                                             0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS2_BMSK                            0xf000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS2_SHFT                                 0x18
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS_BMSK                              0xf00000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS_SHFT                                  0x14
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_NOM_BMSK                               0xf0000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_NOM_SHFT                                  0x10
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_TUR_BMSK                                0xf000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_TUR_SHFT                                   0xc
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS2_BMSK                                       0xf80
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS2_SHFT                                         0x7
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS_BMSK                                         0x7c
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS_SHFT                                          0x2
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_NOM_4_3_BMSK                                      0x3
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_CPR2_TARG_VOLT_NOM_4_3_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000210)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_RMSK                                                      0xff07ffff
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW5_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW5_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR4_TARG_VOLT_NOM_2_0_BMSK                               0xe0000000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR4_TARG_VOLT_NOM_2_0_SHFT                                     0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR4_TARG_VOLT_TUR_BMSK                                   0x1f000000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR4_TARG_VOLT_TUR_SHFT                                         0x18
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR3_TARG_VOLT_SVS_BMSK                                      0x7c000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR3_TARG_VOLT_SVS_SHFT                                          0xe
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR3_TARG_VOLT_TUR_BMSK                                       0x3e00
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR3_TARG_VOLT_TUR_SHFT                                          0x9
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR3_TARG_VOLT_NOM_BMSK                                        0x1f0
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR3_TARG_VOLT_NOM_SHFT                                          0x4
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR2_AGING_7_4_BMSK                                              0xf
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_CPR2_AGING_7_4_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000214)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_RMSK                                                       0x7ffffff
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW5_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW5_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR6_TARG_VOLT_SVS_BMSK                                    0x7c00000
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR6_TARG_VOLT_SVS_SHFT                                         0x16
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR6_TARG_VOLT_NOM_BMSK                                     0x3e0000
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR6_TARG_VOLT_NOM_SHFT                                         0x11
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR6_TARG_VOLT_TUR_BMSK                                      0x1f000
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR6_TARG_VOLT_TUR_SHFT                                          0xc
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR5_TARG_VOLT_TUR_BMSK                                        0xf80
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR5_TARG_VOLT_TUR_SHFT                                          0x7
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR5_TARG_VOLT_NOM_BMSK                                         0x7c
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR5_TARG_VOLT_NOM_SHFT                                          0x2
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR4_TARG_VOLT_NOM_4_3_BMSK                                      0x3
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_CPR4_TARG_VOLT_NOM_4_3_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000218)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW6_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW6_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TARG_VOLT_SVS_3_0_BMSK                               0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TARG_VOLT_SVS_3_0_SHFT                                     0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TARG_VOLT_NOM_BMSK                                    0xfc00000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TARG_VOLT_NOM_SHFT                                         0x16
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TARG_VOLT_TUR_BMSK                                     0x3f0000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TARG_VOLT_TUR_SHFT                                         0x10
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_SVS2_ROSEL_BMSK                                          0xf000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_SVS2_ROSEL_SHFT                                             0xc
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_SVS_ROSEL_BMSK                                            0xf00
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_SVS_ROSEL_SHFT                                              0x8
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_NOMINAL_ROSEL_BMSK                                         0xf0
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_NOMINAL_ROSEL_SHFT                                          0x4
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TURBO_ROSEL_BMSK                                            0xf
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_CPR8_TURBO_ROSEL_SHFT                                            0x0

#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000021c)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_RMSK                                                      0xffffc0ff
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW6_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW6_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_NOMINAL_QUOT_VMIN_5_0_BMSK                           0xfc000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_NOMINAL_QUOT_VMIN_5_0_SHFT                                 0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_TURBO_QUOT_VMIN_BMSK                                  0x3ffc000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_TURBO_QUOT_VMIN_SHFT                                        0xe
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS2_BMSK                                        0xfc
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS2_SHFT                                         0x2
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS_5_4_BMSK                                      0x3
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS_5_4_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000220)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_RMSK                                                      0x3fffffff
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW7_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW7_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_CPR8_SVS2_QUOT_VMIN_BMSK                                  0x3ffc0000
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_CPR8_SVS2_QUOT_VMIN_SHFT                                        0x12
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_CPR8_SVS_QUOT_VMIN_BMSK                                      0x3ffc0
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_CPR8_SVS_QUOT_VMIN_SHFT                                          0x6
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_CPR8_NOMINAL_QUOT_VMIN_11_6_BMSK                                0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_CPR8_NOMINAL_QUOT_VMIN_11_6_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000224)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_RMSK                                                      0xfffffc00
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW7_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW7_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS2_0_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS2_0_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS_6_0_BMSK                             0x7f000000
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS_6_0_SHFT                                   0x18
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_NOM_BMSK                                   0xfe0000
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_NOM_SHFT                                       0x11
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_TUR_BMSK                                    0x1fc00
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_TUR_SHFT                                        0xa

#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000228)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW8_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW8_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_TARG_VOLT_TUR_1_0_BMSK                               0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_TARG_VOLT_TUR_1_0_SHFT                                     0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_SVS2_ROSEL_BMSK                                      0x3c000000
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_SVS2_ROSEL_SHFT                                            0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_SVS_ROSEL_BMSK                                        0x3c00000
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_SVS_ROSEL_SHFT                                             0x16
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_NOMINAL_ROSEL_BMSK                                     0x3c0000
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_NOMINAL_ROSEL_SHFT                                         0x12
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_TURBO_ROSEL_BMSK                                        0x3c000
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR9_TURBO_ROSEL_SHFT                                            0xe
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR8_AGING_BMSK                                               0x3fc0
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR8_AGING_SHFT                                                  0x6
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR8_QUOT_OFFSET_SVS2_6_1_BMSK                                  0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_CPR8_QUOT_OFFSET_SVS2_6_1_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000022c)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_RMSK                                                      0xf03fffff
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW8_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW8_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TURBO_QUOT_VMIN_3_0_BMSK                             0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TURBO_QUOT_VMIN_3_0_SHFT                                   0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS2_BMSK                                    0x3f0000
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS2_SHFT                                        0x10
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS_BMSK                                       0xfc00
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS_SHFT                                          0xa
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_NOM_BMSK                                        0x3f0
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_NOM_SHFT                                          0x4
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_TUR_5_2_BMSK                                      0xf
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_CPR9_TARG_VOLT_TUR_5_2_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000230)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW9_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW9_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_CPR9_SVS_QUOT_VMIN_BMSK                                   0xfff00000
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_CPR9_SVS_QUOT_VMIN_SHFT                                         0x14
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_CPR9_NOMINAL_QUOT_VMIN_BMSK                                  0xfff00
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_CPR9_NOMINAL_QUOT_VMIN_SHFT                                      0x8
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_CPR9_TURBO_QUOT_VMIN_11_4_BMSK                                  0xff
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_CPR9_TURBO_QUOT_VMIN_11_4_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000234)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_RMSK                                                      0xff000fff
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW9_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW9_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_NOM_0_BMSK                               0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_NOM_0_SHFT                                     0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_TUR_BMSK                                 0x7f000000
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_TUR_SHFT                                       0x18
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_CPR9_SVS2_QUOT_VMIN_BMSK                                       0xfff
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_CPR9_SVS2_QUOT_VMIN_SHFT                                         0x0

#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000238)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_RMSK                                                        0xfffff
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW10_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW10_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS2_BMSK                                  0xfe000
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS2_SHFT                                      0xd
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS_BMSK                                    0x1fc0
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS_SHFT                                       0x6
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_NOM_6_1_BMSK                                  0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_NOM_6_1_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000023c)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_RMSK                                                     0xffffffc0
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW10_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW10_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SPARE_71_63_BMSK                                         0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SPARE_71_63_SHFT                                               0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SPARE_71_62_BMSK                                         0x40000000
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SPARE_71_62_SHFT                                               0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SPARE_71_61_BMSK                                         0x20000000
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SPARE_71_61_SHFT                                               0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SW_CAL_REDUN_SEL_BMSK                                    0x1c000000
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_SW_CAL_REDUN_SEL_SHFT                                          0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS2_BMSK                             0x3e00000
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS2_SHFT                                  0x15
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS_BMSK                               0x1f0000
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS_SHFT                                   0x10
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_NOM_BMSK                                 0xf800
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_NOM_SHFT                                    0xb
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_TUR_BMSK                                  0x7c0
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_TUR_SHFT                                    0x6

#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000240)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW11_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW11_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SPARE_72_31_BMSK                                         0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SPARE_72_31_SHFT                                               0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SPARE_72_30_BMSK                                         0x40000000
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SPARE_72_30_SHFT                                               0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_QUSB_REFCLK_SEL_BMSK                                     0x20000000
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_QUSB_REFCLK_SEL_SHFT                                           0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_QUSB_PORT0_HSTX_TRIM_LSB_BMSK                            0x1e000000
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_QUSB_PORT0_HSTX_TRIM_LSB_SHFT                                  0x19
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_1_BMSK                                  0x1fe0000
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_1_SHFT                                       0x11
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_0_BMSK                                    0x1fe00
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_0_SHFT                                        0x9
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_GNSS_ADC_RSB_BMSK                                             0x1c0
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_GNSS_ADC_RSB_SHFT                                               0x6
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_GNSS_ADC_LDO_BMSK                                              0x38
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_GNSS_ADC_LDO_SHFT                                               0x3
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_GNSS_ADC_VREF_BMSK                                              0x7
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_GNSS_ADC_VREF_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000244)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW11_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW11_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS1_BASE0_8_0_BMSK                                    0xff800000
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS1_BASE0_8_0_SHFT                                          0x17
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS0_BASE1_BMSK                                          0x7fe000
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS0_BASE1_SHFT                                               0xd
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS0_BASE0_BMSK                                            0x1ff8
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS0_BASE0_SHFT                                               0x3
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS_CAL_SEL_BMSK                                              0x7
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_TSENS_CAL_SEL_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000248)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW12_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW12_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS5_OFFSET_0_BMSK                                     0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS5_OFFSET_0_SHFT                                           0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS4_OFFSET_BMSK                                       0x78000000
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS4_OFFSET_SHFT                                             0x1b
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS3_OFFSET_BMSK                                        0x7800000
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS3_OFFSET_SHFT                                             0x17
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS2_OFFSET_BMSK                                         0x780000
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS2_OFFSET_SHFT                                             0x13
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS1_OFFSET_BMSK                                          0x78000
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS1_OFFSET_SHFT                                              0xf
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS0_OFFSET_BMSK                                           0x7800
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS0_OFFSET_SHFT                                              0xb
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS1_BASE1_BMSK                                             0x7fe
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS1_BASE1_SHFT                                               0x1
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS1_BASE0_9_BMSK                                             0x1
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_TSENS1_BASE0_9_SHFT                                             0x0

#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000024c)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW12_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW12_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS13_OFFSET_0_BMSK                                    0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS13_OFFSET_0_SHFT                                          0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS12_OFFSET_BMSK                                      0x78000000
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS12_OFFSET_SHFT                                            0x1b
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS11_OFFSET_BMSK                                       0x7800000
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS11_OFFSET_SHFT                                            0x17
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS10_OFFSET_BMSK                                        0x780000
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS10_OFFSET_SHFT                                            0x13
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS9_OFFSET_BMSK                                          0x78000
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS9_OFFSET_SHFT                                              0xf
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS8_OFFSET_BMSK                                           0x7800
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS8_OFFSET_SHFT                                              0xb
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS7_OFFSET_BMSK                                            0x780
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS7_OFFSET_SHFT                                              0x7
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS6_OFFSET_BMSK                                             0x78
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS6_OFFSET_SHFT                                              0x3
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS5_OFFSET_3_1_BMSK                                          0x7
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_TSENS5_OFFSET_3_1_SHFT                                          0x0

#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000250)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_RMSK                                                            0x7
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW13_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW13_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_TSENS13_OFFSET_3_1_BMSK                                         0x7
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_TSENS13_OFFSET_3_1_SHFT                                         0x0

#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000254)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_RMSK                                                     0xfffff800
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW13_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW13_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR6_LPI_MX_RC_BMSK                                      0xe0000000
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR6_LPI_MX_RC_SHFT                                            0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR5_LPI_CX_RC_BMSK                                      0x1c000000
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR5_LPI_CX_RC_SHFT                                            0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR4_MX_RC_BMSK                                           0x3800000
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR4_MX_RC_SHFT                                                0x17
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR3_DDR_RC_BMSK                                           0x700000
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR3_DDR_RC_SHFT                                               0x14
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR2_GFX_RC_BMSK                                            0xe0000
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR2_GFX_RC_SHFT                                               0x11
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR1_MSS_RC_BMSK                                            0x1c000
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR1_MSS_RC_SHFT                                                0xe
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR0_CX_RC_BMSK                                              0x3800
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR0_CX_RC_SHFT                                                 0xb

#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000258)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW14_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW14_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_VSENSE_CALIB_25_0_BMSK                                   0xffffffc0
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_VSENSE_CALIB_25_0_SHFT                                          0x6
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR_LOCAL_RC_BMSK                                              0x38
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR_LOCAL_RC_SHFT                                               0x3
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR7_WLAN_RC_BMSK                                               0x7
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR7_WLAN_RC_SHFT                                               0x0

#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000025c)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW14_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW14_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_VSENSE_CALIB_57_26_BMSK                                  0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_VSENSE_CALIB_57_26_SHFT                                         0x0

#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000260)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW15_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW15_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_SW_CAL_REDUNDANCY_30_0_BMSK                              0xfffffffe
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_SW_CAL_REDUNDANCY_30_0_SHFT                                     0x1
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_VSENSE_CALIB_58_BMSK                                            0x1
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_VSENSE_CALIB_58_SHFT                                            0x0

#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000264)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW15_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW15_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_SW_CAL_REDUNDANCY_62_31_BMSK                             0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_SW_CAL_REDUNDANCY_62_31_SHFT                                    0x0

#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000268)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW16_LSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW16_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_SW_CAL_REDUNDANCY_94_63_BMSK                             0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_SW_CAL_REDUNDANCY_94_63_SHFT                                    0x0

#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000026c)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR, HWIO_QFPROM_RAW_CALIB_ROW16_MSB_RMSK)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW16_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_SW_CAL_REDUNDANCY_126_95_BMSK                            0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_SW_CAL_REDUNDANCY_126_95_SHFT                                   0x0

#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000270 + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_MAXn                                                         18
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_REDUN_DATA_BMSK                                      0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_REDUN_DATA_SHFT                                             0x0

#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000274 + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_MAXn                                                         18
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_REDUN_DATA_BMSK                                      0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_REDUN_DATA_SHFT                                             0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000308)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ADDR, HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_BMSK                      0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_SHFT                            0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_BMSK                                0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_SHFT                                      0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_BMSK                      0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_SHFT                            0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                        0x1fe00000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                              0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                         0x180000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                             0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_BMSK                      0x40000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_SHFT                         0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_BMSK                      0x20000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_SHFT                         0x11
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_BMSK                               0x10000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_SHFT                                  0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_BMSK                             0x8000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_SHFT                                0xf
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_BMSK                             0x4000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_SHFT                                0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_BMSK                                 0x2000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_SHFT                                    0xd
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                    0x1000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                       0xc
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                           0x800
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                             0xb
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                   0x400
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                     0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                    0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                      0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_BMSK                                     0x100
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_SHFT                                       0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                        0x80
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                         0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                              0x40
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                               0x6
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_BMSK                                     0x20
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_SHFT                                      0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_BMSK                                    0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_SHFT                                     0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_BMSK                                     0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_SHFT                                     0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                             0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                             0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000030c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ADDR, HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                           0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                 0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                           0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                 0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                 0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                       0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_BMSK                                0x10000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_SHFT                                      0x1c
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_BMSK                            0x8000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_SHFT                                 0x1b
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_BMSK                         0x4000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_SHFT                              0x1a
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_BMSK             0x2000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                  0x19
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_BMSK                 0x1000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_SHFT                      0x18
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_BMSK              0x800000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_SHFT                  0x17
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                             0x400000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                 0x16
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_BMSK                                   0x200000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_SHFT                                       0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_BMSK                              0x100000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_SHFT                                  0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_BMSK                       0x80000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_SHFT                          0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                              0x7c000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                  0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                           0x2000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                              0xd
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_BMSK                                    0x1000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_SHFT                                       0xc
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                       0x800
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                         0xb
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_BMSK                                    0x400
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_SHFT                                      0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                     0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                       0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                      0x1e0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                        0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                            0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                             0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_BMSK                               0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_SHFT                               0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_BMSK                                0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_SHFT                                0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_BMSK                                  0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_SHFT                                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_BMSK                                 0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000310)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_ADDR, HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_BMSK                             0xfff00000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_SHFT                                   0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_BMSK                           0x80000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_SHFT                              0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_BMSK                                    0x40000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_SHFT                                       0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_BMSK                                0x20000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_SHFT                                   0x11
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_BMSK                               0x18000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_SHFT                                   0xf
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                     0x7fe0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                        0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_BMSK                       0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_SHFT                        0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000314)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_ADDR, HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_BMSK                      0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_SHFT                            0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                      0x60000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                            0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                     0x1fe00000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                           0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_BMSK                              0x100000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_SHFT                                  0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_RSVD1_BMSK                                          0xf0000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_RSVD1_SHFT                                             0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_BMSK                                0xffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000318)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_BMSK                     0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_SHFT                           0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_BMSK                        0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_SHFT                              0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_BMSK               0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_SHFT                     0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_BMSK                      0x10000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_SHFT                            0x1c
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_BMSK                         0x8000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_SHFT                              0x1b
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_BMSK                        0x4000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_SHFT                             0x1a
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_BMSK                       0x2000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_SHFT                            0x19
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_BMSK                         0x1000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_SHFT                              0x18
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                         0x800000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                             0x17
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_BMSK                          0x400000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_SHFT                              0x16
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_BMSK                     0x200000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_SHFT                         0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_BMSK                      0x100000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_SHFT                          0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_BMSK              0x80000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_SHFT                 0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_BMSK                  0x40000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_SHFT                     0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_BMSK                         0x20000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_SHFT                            0x11
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_BMSK                           0x10000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_SHFT                              0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_BMSK                           0x8000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_SHFT                              0xf
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_BMSK                       0x4000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_SHFT                          0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_BMSK                            0x2000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_SHFT                               0xd
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                           0x1000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                              0xc
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_BMSK                          0x800
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_SHFT                            0xb
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_BMSK                             0x400
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_SHFT                               0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_DSI_0_DISABLE_BMSK                                    0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_DSI_0_DISABLE_SHFT                                      0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_BMSK                             0x100
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_SHFT                               0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_BMSK                              0x80
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_SHFT                               0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_BMSK                           0x40
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_SHFT                            0x6
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_BMSK                             0x20
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_SHFT                              0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_BMSK                             0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_SHFT                              0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_BMSK                              0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_SHFT                              0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_BMSK                                   0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_SHFT                                   0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                    0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                        0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000031c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_BMSK                        0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_SHFT                              0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_BMSK                               0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_SHFT                                     0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_PLL_MAX_BOOST_LVAL_BMSK                          0x1fe00000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_PLL_MAX_BOOST_LVAL_SHFT                                0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                            0x1c0000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                                0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_PLL_MAX_FREQ_LVAL_BMSK                              0x3fc00
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_PLL_MAX_FREQ_LVAL_SHFT                                  0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_BMSK                 0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_SHFT                   0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_BMSK                          0x100
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_SHFT                            0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_BMSK                           0x80
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_SHFT                            0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_BMSK                            0x40
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_SHFT                             0x6
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_BMSK                             0x20
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_SHFT                              0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_BMSK                            0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_SHFT                             0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_BMSK                           0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_SHFT                           0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_BMSK                           0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_SHFT                           0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_BMSK                            0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_SHFT                            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_BMSK                             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_SHFT                             0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000310 + 0x8 * (n))
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_MAXn                                                           18
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_ADDR(n), HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_RMSK)
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_INI(n))
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_QC_SPARE_BMSK                                          0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_LSB_QC_SPARE_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000314 + 0x8 * (n))
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_MAXn                                                           18
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_ADDR(n), HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_RMSK)
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_INI(n))
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_RSVD0_BMSK                                             0x80000000
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_RSVD0_SHFT                                                   0x1f
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_FEC_VALUE_BMSK                                         0x7f000000
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_FEC_VALUE_SHFT                                               0x18
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_QC_SPARE_BMSK                                            0xffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REGn_MSB_QC_SPARE_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n)                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000338 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK                                         0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_MAXn                                                  1
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_BMSK                               0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_SHFT                                      0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n)                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000033c + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK                                         0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_MAXn                                                  1
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RSVD1_BMSK                                   0x80000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RSVD1_SHFT                                         0x1f
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_FEC_VALUE_BMSK                               0x7f000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_FEC_VALUE_SHFT                                     0x18
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_BMSK                                 0xffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_SHFT                                      0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000348)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RMSK                                         0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_BMSK                                   0xffff0000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_SHFT                                         0x10
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_BMSK                                   0xffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_SHFT                                      0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000034c)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RMSK                                         0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD1_BMSK                                   0x80000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD1_SHFT                                         0x1f
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_FEC_VALUE_BMSK                               0x7f000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_FEC_VALUE_SHFT                                     0x18
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_BMSK                                     0xffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_SHFT                                          0x0

#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n)                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000350 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_MAXn                                                        1
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_BMSK                                     0xff000000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_SHFT                                           0x18
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_BMSK                                       0xff0000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_SHFT                                           0x10
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_BMSK                                         0xff00
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_SHFT                                            0x8
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_BMSK                                           0xff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_SHFT                                            0x0

#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n)                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000354 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_MAXn                                                        1
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RSVD1_BMSK                                         0x80000000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RSVD1_SHFT                                               0x1f
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_FEC_VALUE_BMSK                                     0x7f000000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_FEC_VALUE_SHFT                                           0x18
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_BMSK                                       0xff0000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_SHFT                                           0x10
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_BMSK                                         0xff00
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_SHFT                                            0x8
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_BMSK                                           0xff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_SHFT                                            0x0

#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000360 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                              3
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                           0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                  0x0

#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000364 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                              3
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_BMSK                               0x80000000
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_SHFT                                     0x1f
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_BMSK                           0x7f000000
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_SHFT                                 0x18
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                             0xffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                  0x0

#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000380)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_RMSK)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_BMSK                           0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_SHFT                                  0x0

#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000384)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RMSK)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RSVD1_BMSK                               0x80000000
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RSVD1_SHFT                                     0x1f
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_FEC_VALUE_BMSK                           0x7f000000
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_FEC_VALUE_SHFT                                 0x18
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_BMSK                                 0xffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_SHFT                                      0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000388 + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                              3
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                           0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                  0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000038c + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                              3
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_BMSK                               0x80000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_SHFT                                     0x1f
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_BMSK                           0x7f000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_SHFT                                 0x18
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                             0xffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                  0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000003a8)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_RMSK)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_BMSK                           0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_SHFT                                  0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000003ac)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RMSK)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD1_BMSK                               0x80000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD1_SHFT                                     0x1f
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_FEC_VALUE_BMSK                           0x7f000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_FEC_VALUE_SHFT                                 0x18
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_BMSK                                 0xffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_SHFT                                      0x0

#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000003b0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_MAXn                                                          55
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_PATCH_DATA_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_PATCH_DATA_SHFT                                              0x0

#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000003b4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_MAXn                                                          55
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD1_BMSK                                            0x80000000
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD1_SHFT                                                  0x1f
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_FEC_VALUE_BMSK                                        0x7f000000
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_FEC_VALUE_SHFT                                              0x18
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD0_BMSK                                              0xfe0000
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD0_SHFT                                                  0x11
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_ADDR_BMSK                                          0x1fffe
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_ADDR_SHFT                                              0x1
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_EN_BMSK                                                0x1
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_EN_SHFT                                                0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000570 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_MAXn                                                     1
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_BMSK                                  0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_SHFT                                         0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000574 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_MAXn                                                     1
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RSVD1_BMSK                                      0x80000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RSVD1_SHFT                                            0x1f
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_FEC_VALUE_BMSK                                  0x7f000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_FEC_VALUE_SHFT                                        0x18
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_BMSK                                    0xffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_SHFT                                         0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000580)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR, HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RMSK)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_BMSK                                      0xffff0000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_SHFT                                            0x10
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_BMSK                                      0xffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_SHFT                                         0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000584)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR, HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RMSK)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD1_BMSK                                      0x80000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD1_SHFT                                            0x1f
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_FEC_VALUE_BMSK                                  0x7f000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_FEC_VALUE_SHFT                                        0x18
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_BMSK                                        0xffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_SHFT                                             0x0

#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000588 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_MAXn                                                            3
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_HASH_DATA0_BMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_HASH_DATA0_SHFT                                               0x0

#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000058c + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_MAXn                                                            3
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_RSVD1_BMSK                                             0x80000000
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_RSVD1_SHFT                                                   0x1f
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_FEC_VALUE_BMSK                                         0x7f000000
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_FEC_VALUE_SHFT                                               0x18
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_HASH_DATA1_BMSK                                          0xffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROWn_MSB_HASH_DATA1_SHFT                                               0x0

#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005a8)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_ADDR, HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_HASH_DATA0_BMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_LSB_HASH_DATA0_SHFT                                               0x0

#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005ac)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_ADDR, HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_RSVD1_BMSK                                             0x80000000
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_RSVD1_SHFT                                                   0x1f
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_FEC_VALUE_BMSK                                         0x7f000000
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_FEC_VALUE_SHFT                                               0x18
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_RSVD0_BMSK                                               0xfffffc
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_RSVD0_SHFT                                                    0x2
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_MODEM_BMSK                                     0x2
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_MODEM_SHFT                                     0x1
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_APPS_BMSK                                      0x1
#define HWIO_QFPROM_RAW_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_APPS_SHFT                                      0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000596 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_MAXn                                                     30
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_BMSK                                   0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_SHFT                                          0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000059a + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_MAXn                                                     30
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_BMSK                                   0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_SHFT                                          0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000059e + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_MAXn                                                     30
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_BMSK                                   0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_SHFT                                          0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005a2 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_MAXn                                                     30
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_BMSK                                   0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_SHFT                                          0x0

#define HWIO_QFPROM_BLOW_TIMER_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000203c)
#define HWIO_QFPROM_BLOW_TIMER_RMSK                                                                   0xfff
#define HWIO_QFPROM_BLOW_TIMER_IN          \
        in_dword_masked(HWIO_QFPROM_BLOW_TIMER_ADDR, HWIO_QFPROM_BLOW_TIMER_RMSK)
#define HWIO_QFPROM_BLOW_TIMER_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BLOW_TIMER_ADDR, m)
#define HWIO_QFPROM_BLOW_TIMER_OUT(v)      \
        out_dword(HWIO_QFPROM_BLOW_TIMER_ADDR,v)
#define HWIO_QFPROM_BLOW_TIMER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_BLOW_TIMER_ADDR,m,v,HWIO_QFPROM_BLOW_TIMER_IN)
#define HWIO_QFPROM_BLOW_TIMER_BLOW_TIMER_BMSK                                                        0xfff
#define HWIO_QFPROM_BLOW_TIMER_BLOW_TIMER_SHFT                                                          0x0

#define HWIO_QFPROM_TEST_CTRL_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002040)
#define HWIO_QFPROM_TEST_CTRL_RMSK                                                                      0xf
#define HWIO_QFPROM_TEST_CTRL_IN          \
        in_dword_masked(HWIO_QFPROM_TEST_CTRL_ADDR, HWIO_QFPROM_TEST_CTRL_RMSK)
#define HWIO_QFPROM_TEST_CTRL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_TEST_CTRL_ADDR, m)
#define HWIO_QFPROM_TEST_CTRL_OUT(v)      \
        out_dword(HWIO_QFPROM_TEST_CTRL_ADDR,v)
#define HWIO_QFPROM_TEST_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_TEST_CTRL_ADDR,m,v,HWIO_QFPROM_TEST_CTRL_IN)
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_ROM_BMSK                                                          0x8
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_ROM_SHFT                                                          0x3
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_WL_BMSK                                                           0x4
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_WL_SHFT                                                           0x2
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_BL_BMSK                                                           0x2
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_BL_SHFT                                                           0x1
#define HWIO_QFPROM_TEST_CTRL_EN_FUSE_RES_MEAS_BMSK                                                     0x1
#define HWIO_QFPROM_TEST_CTRL_EN_FUSE_RES_MEAS_SHFT                                                     0x0

#define HWIO_QFPROM_ACCEL_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002044)
#define HWIO_QFPROM_ACCEL_RMSK                                                                        0xfff
#define HWIO_QFPROM_ACCEL_IN          \
        in_dword_masked(HWIO_QFPROM_ACCEL_ADDR, HWIO_QFPROM_ACCEL_RMSK)
#define HWIO_QFPROM_ACCEL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_ACCEL_ADDR, m)
#define HWIO_QFPROM_ACCEL_OUT(v)      \
        out_dword(HWIO_QFPROM_ACCEL_ADDR,v)
#define HWIO_QFPROM_ACCEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_ACCEL_ADDR,m,v,HWIO_QFPROM_ACCEL_IN)
#define HWIO_QFPROM_ACCEL_QFPROM_GATELAST_BMSK                                                        0x800
#define HWIO_QFPROM_ACCEL_QFPROM_GATELAST_SHFT                                                          0xb
#define HWIO_QFPROM_ACCEL_QFPROM_TRIPPT_SEL_BMSK                                                      0x700
#define HWIO_QFPROM_ACCEL_QFPROM_TRIPPT_SEL_SHFT                                                        0x8
#define HWIO_QFPROM_ACCEL_QFPROM_ACCEL_BMSK                                                            0xff
#define HWIO_QFPROM_ACCEL_QFPROM_ACCEL_SHFT                                                             0x0

#define HWIO_QFPROM_BLOW_STATUS_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002048)
#define HWIO_QFPROM_BLOW_STATUS_RMSK                                                                    0x3
#define HWIO_QFPROM_BLOW_STATUS_IN          \
        in_dword_masked(HWIO_QFPROM_BLOW_STATUS_ADDR, HWIO_QFPROM_BLOW_STATUS_RMSK)
#define HWIO_QFPROM_BLOW_STATUS_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BLOW_STATUS_ADDR, m)
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_WR_ERR_BMSK                                                      0x2
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_WR_ERR_SHFT                                                      0x1
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_BUSY_BMSK                                                        0x1
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_BUSY_SHFT                                                        0x0

#define HWIO_QFPROM_ROM_ERROR_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000204c)
#define HWIO_QFPROM_ROM_ERROR_RMSK                                                                      0x1
#define HWIO_QFPROM_ROM_ERROR_IN          \
        in_dword_masked(HWIO_QFPROM_ROM_ERROR_ADDR, HWIO_QFPROM_ROM_ERROR_RMSK)
#define HWIO_QFPROM_ROM_ERROR_INM(m)      \
        in_dword_masked(HWIO_QFPROM_ROM_ERROR_ADDR, m)
#define HWIO_QFPROM_ROM_ERROR_ERROR_BMSK                                                                0x1
#define HWIO_QFPROM_ROM_ERROR_ERROR_SHFT                                                                0x0

#define HWIO_QFPROM0_MATCH_STATUS_ADDR                                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002050)
#define HWIO_QFPROM0_MATCH_STATUS_RMSK                                                           0xffffffff
#define HWIO_QFPROM0_MATCH_STATUS_IN          \
        in_dword_masked(HWIO_QFPROM0_MATCH_STATUS_ADDR, HWIO_QFPROM0_MATCH_STATUS_RMSK)
#define HWIO_QFPROM0_MATCH_STATUS_INM(m)      \
        in_dword_masked(HWIO_QFPROM0_MATCH_STATUS_ADDR, m)
#define HWIO_QFPROM0_MATCH_STATUS_FLAG_BMSK                                                      0xffffffff
#define HWIO_QFPROM0_MATCH_STATUS_FLAG_SHFT                                                             0x0

#define HWIO_QFPROM1_MATCH_STATUS_ADDR                                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002054)
#define HWIO_QFPROM1_MATCH_STATUS_RMSK                                                           0xffffffff
#define HWIO_QFPROM1_MATCH_STATUS_IN          \
        in_dword_masked(HWIO_QFPROM1_MATCH_STATUS_ADDR, HWIO_QFPROM1_MATCH_STATUS_RMSK)
#define HWIO_QFPROM1_MATCH_STATUS_INM(m)      \
        in_dword_masked(HWIO_QFPROM1_MATCH_STATUS_ADDR, m)
#define HWIO_QFPROM1_MATCH_STATUS_FLAG_BMSK                                                      0xffffffff
#define HWIO_QFPROM1_MATCH_STATUS_FLAG_SHFT                                                             0x0

#define HWIO_FEC_ESR_ADDR                                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002058)
#define HWIO_FEC_ESR_RMSK                                                                            0x2fdf
#define HWIO_FEC_ESR_IN          \
        in_dword_masked(HWIO_FEC_ESR_ADDR, HWIO_FEC_ESR_RMSK)
#define HWIO_FEC_ESR_INM(m)      \
        in_dword_masked(HWIO_FEC_ESR_ADDR, m)
#define HWIO_FEC_ESR_OUT(v)      \
        out_dword(HWIO_FEC_ESR_ADDR,v)
#define HWIO_FEC_ESR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_FEC_ESR_ADDR,m,v,HWIO_FEC_ESR_IN)
#define HWIO_FEC_ESR_CORR_SW_ACC_BMSK                                                                0x2000
#define HWIO_FEC_ESR_CORR_SW_ACC_SHFT                                                                   0xd
#define HWIO_FEC_ESR_CORR_SECURE_CHANNEL_BMSK                                                         0x800
#define HWIO_FEC_ESR_CORR_SECURE_CHANNEL_SHFT                                                           0xb
#define HWIO_FEC_ESR_CORR_BOOT_ROM_BMSK                                                               0x400
#define HWIO_FEC_ESR_CORR_BOOT_ROM_SHFT                                                                 0xa
#define HWIO_FEC_ESR_CORR_FUSE_SENSE_BMSK                                                             0x200
#define HWIO_FEC_ESR_CORR_FUSE_SENSE_SHFT                                                               0x9
#define HWIO_FEC_ESR_CORR_MULT_BMSK                                                                   0x100
#define HWIO_FEC_ESR_CORR_MULT_SHFT                                                                     0x8
#define HWIO_FEC_ESR_CORR_SEEN_BMSK                                                                    0x80
#define HWIO_FEC_ESR_CORR_SEEN_SHFT                                                                     0x7
#define HWIO_FEC_ESR_ERR_SW_ACC_BMSK                                                                   0x40
#define HWIO_FEC_ESR_ERR_SW_ACC_SHFT                                                                    0x6
#define HWIO_FEC_ESR_ERR_SECURE_CHANNEL_BMSK                                                           0x10
#define HWIO_FEC_ESR_ERR_SECURE_CHANNEL_SHFT                                                            0x4
#define HWIO_FEC_ESR_ERR_BOOT_ROM_BMSK                                                                  0x8
#define HWIO_FEC_ESR_ERR_BOOT_ROM_SHFT                                                                  0x3
#define HWIO_FEC_ESR_ERR_FUSE_SENSE_BMSK                                                                0x4
#define HWIO_FEC_ESR_ERR_FUSE_SENSE_SHFT                                                                0x2
#define HWIO_FEC_ESR_ERR_MULT_BMSK                                                                      0x2
#define HWIO_FEC_ESR_ERR_MULT_SHFT                                                                      0x1
#define HWIO_FEC_ESR_ERR_SEEN_BMSK                                                                      0x1
#define HWIO_FEC_ESR_ERR_SEEN_SHFT                                                                      0x0

#define HWIO_FEC_EAR_ADDR                                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000205c)
#define HWIO_FEC_EAR_RMSK                                                                        0xffffffff
#define HWIO_FEC_EAR_IN          \
        in_dword_masked(HWIO_FEC_EAR_ADDR, HWIO_FEC_EAR_RMSK)
#define HWIO_FEC_EAR_INM(m)      \
        in_dword_masked(HWIO_FEC_EAR_ADDR, m)
#define HWIO_FEC_EAR_CORR_ADDR_BMSK                                                              0xffff0000
#define HWIO_FEC_EAR_CORR_ADDR_SHFT                                                                    0x10
#define HWIO_FEC_EAR_ERR_ADDR_BMSK                                                                   0xffff
#define HWIO_FEC_EAR_ERR_ADDR_SHFT                                                                      0x0

#define HWIO_QFPROM_BIST_CTRL_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002060)
#define HWIO_QFPROM_BIST_CTRL_RMSK                                                                     0xff
#define HWIO_QFPROM_BIST_CTRL_IN          \
        in_dword_masked(HWIO_QFPROM_BIST_CTRL_ADDR, HWIO_QFPROM_BIST_CTRL_RMSK)
#define HWIO_QFPROM_BIST_CTRL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BIST_CTRL_ADDR, m)
#define HWIO_QFPROM_BIST_CTRL_OUT(v)      \
        out_dword(HWIO_QFPROM_BIST_CTRL_ADDR,v)
#define HWIO_QFPROM_BIST_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_BIST_CTRL_ADDR,m,v,HWIO_QFPROM_BIST_CTRL_IN)
#define HWIO_QFPROM_BIST_CTRL_AUTH_REGION_BMSK                                                         0xfc
#define HWIO_QFPROM_BIST_CTRL_AUTH_REGION_SHFT                                                          0x2
#define HWIO_QFPROM_BIST_CTRL_SHA_ENABLE_BMSK                                                           0x2
#define HWIO_QFPROM_BIST_CTRL_SHA_ENABLE_SHFT                                                           0x1
#define HWIO_QFPROM_BIST_CTRL_START_BMSK                                                                0x1
#define HWIO_QFPROM_BIST_CTRL_START_SHFT                                                                0x0

#define HWIO_QFPROM_BIST_ERROR0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002064)
#define HWIO_QFPROM_BIST_ERROR0_RMSK                                                             0xffffffff
#define HWIO_QFPROM_BIST_ERROR0_IN          \
        in_dword_masked(HWIO_QFPROM_BIST_ERROR0_ADDR, HWIO_QFPROM_BIST_ERROR0_RMSK)
#define HWIO_QFPROM_BIST_ERROR0_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BIST_ERROR0_ADDR, m)
#define HWIO_QFPROM_BIST_ERROR0_ERROR_BMSK                                                       0xffffffff
#define HWIO_QFPROM_BIST_ERROR0_ERROR_SHFT                                                              0x0

#define HWIO_QFPROM_BIST_ERROR1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002068)
#define HWIO_QFPROM_BIST_ERROR1_RMSK                                                             0xffffffff
#define HWIO_QFPROM_BIST_ERROR1_IN          \
        in_dword_masked(HWIO_QFPROM_BIST_ERROR1_ADDR, HWIO_QFPROM_BIST_ERROR1_RMSK)
#define HWIO_QFPROM_BIST_ERROR1_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BIST_ERROR1_ADDR, m)
#define HWIO_QFPROM_BIST_ERROR1_ERROR_BMSK                                                       0xffffffff
#define HWIO_QFPROM_BIST_ERROR1_ERROR_SHFT                                                              0x0

#define HWIO_QFPROM_HASH_SIGNATUREn_ADDR(n)                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000206c + 0x4 * (n))
#define HWIO_QFPROM_HASH_SIGNATUREn_RMSK                                                         0xffffffff
#define HWIO_QFPROM_HASH_SIGNATUREn_MAXn                                                                  7
#define HWIO_QFPROM_HASH_SIGNATUREn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_HASH_SIGNATUREn_ADDR(n), HWIO_QFPROM_HASH_SIGNATUREn_RMSK)
#define HWIO_QFPROM_HASH_SIGNATUREn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_HASH_SIGNATUREn_ADDR(n), mask)
#define HWIO_QFPROM_HASH_SIGNATUREn_HASH_VALUE_BMSK                                              0xffffffff
#define HWIO_QFPROM_HASH_SIGNATUREn_HASH_VALUE_SHFT                                                     0x0

#define HWIO_HW_KEY_STATUS_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000208c)
#define HWIO_HW_KEY_STATUS_RMSK                                                                       0x7ff
#define HWIO_HW_KEY_STATUS_IN          \
        in_dword_masked(HWIO_HW_KEY_STATUS_ADDR, HWIO_HW_KEY_STATUS_RMSK)
#define HWIO_HW_KEY_STATUS_INM(m)      \
        in_dword_masked(HWIO_HW_KEY_STATUS_ADDR, m)
#define HWIO_HW_KEY_STATUS_MSA_SECURE_BMSK                                                            0x400
#define HWIO_HW_KEY_STATUS_MSA_SECURE_SHFT                                                              0xa
#define HWIO_HW_KEY_STATUS_APPS_SECURE_BMSK                                                           0x200
#define HWIO_HW_KEY_STATUS_APPS_SECURE_SHFT                                                             0x9
#define HWIO_HW_KEY_STATUS_KDF_AND_HW_KEY_SHIFT_DONE_BMSK                                             0x100
#define HWIO_HW_KEY_STATUS_KDF_AND_HW_KEY_SHIFT_DONE_SHFT                                               0x8
#define HWIO_HW_KEY_STATUS_HW_KEY_SHIFT_DONE_BMSK                                                      0x80
#define HWIO_HW_KEY_STATUS_HW_KEY_SHIFT_DONE_SHFT                                                       0x7
#define HWIO_HW_KEY_STATUS_FUSE_SENSE_DONE_BMSK                                                        0x40
#define HWIO_HW_KEY_STATUS_FUSE_SENSE_DONE_SHFT                                                         0x6
#define HWIO_HW_KEY_STATUS_CRI_CM_BOOT_DONE_BMSK                                                       0x20
#define HWIO_HW_KEY_STATUS_CRI_CM_BOOT_DONE_SHFT                                                        0x5
#define HWIO_HW_KEY_STATUS_KDF_DONE_BMSK                                                               0x10
#define HWIO_HW_KEY_STATUS_KDF_DONE_SHFT                                                                0x4
#define HWIO_HW_KEY_STATUS_MSA_KEYS_BLOCKED_BMSK                                                        0x8
#define HWIO_HW_KEY_STATUS_MSA_KEYS_BLOCKED_SHFT                                                        0x3
#define HWIO_HW_KEY_STATUS_APPS_KEYS_BLOCKED_BMSK                                                       0x4
#define HWIO_HW_KEY_STATUS_APPS_KEYS_BLOCKED_SHFT                                                       0x2
#define HWIO_HW_KEY_STATUS_SEC_KEY_DERIVATION_KEY_BLOWN_BMSK                                            0x2
#define HWIO_HW_KEY_STATUS_SEC_KEY_DERIVATION_KEY_BLOWN_SHFT                                            0x1
#define HWIO_HW_KEY_STATUS_PRI_KEY_DERIVATION_KEY_BLOWN_BMSK                                            0x1
#define HWIO_HW_KEY_STATUS_PRI_KEY_DERIVATION_KEY_BLOWN_SHFT                                            0x0

#define HWIO_RESET_JDR_STATUS_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002090)
#define HWIO_RESET_JDR_STATUS_RMSK                                                                      0x3
#define HWIO_RESET_JDR_STATUS_IN          \
        in_dword_masked(HWIO_RESET_JDR_STATUS_ADDR, HWIO_RESET_JDR_STATUS_RMSK)
#define HWIO_RESET_JDR_STATUS_INM(m)      \
        in_dword_masked(HWIO_RESET_JDR_STATUS_ADDR, m)
#define HWIO_RESET_JDR_STATUS_FORCE_RESET_BMSK                                                          0x2
#define HWIO_RESET_JDR_STATUS_FORCE_RESET_SHFT                                                          0x1
#define HWIO_RESET_JDR_STATUS_DISABLE_SYSTEM_RESET_BMSK                                                 0x1
#define HWIO_RESET_JDR_STATUS_DISABLE_SYSTEM_RESET_SHFT                                                 0x0

#define HWIO_ATPG_JDR_STATUS_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002094)
#define HWIO_ATPG_JDR_STATUS_RMSK                                                                       0x1
#define HWIO_ATPG_JDR_STATUS_IN          \
        in_dword_masked(HWIO_ATPG_JDR_STATUS_ADDR, HWIO_ATPG_JDR_STATUS_RMSK)
#define HWIO_ATPG_JDR_STATUS_INM(m)      \
        in_dword_masked(HWIO_ATPG_JDR_STATUS_ADDR, m)
#define HWIO_ATPG_JDR_STATUS_FUSE_SENSE_ATPG_CTL_BMSK                                                   0x1
#define HWIO_ATPG_JDR_STATUS_FUSE_SENSE_ATPG_CTL_SHFT                                                   0x0

#define HWIO_FEAT_PROV_OUTn_ADDR(n)                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002098 + 0x4 * (n))
#define HWIO_FEAT_PROV_OUTn_RMSK                                                                 0xffffffff
#define HWIO_FEAT_PROV_OUTn_MAXn                                                                          3
#define HWIO_FEAT_PROV_OUTn_INI(n)        \
        in_dword_masked(HWIO_FEAT_PROV_OUTn_ADDR(n), HWIO_FEAT_PROV_OUTn_RMSK)
#define HWIO_FEAT_PROV_OUTn_INMI(n,mask)    \
        in_dword_masked(HWIO_FEAT_PROV_OUTn_ADDR(n), mask)
#define HWIO_FEAT_PROV_OUTn_FEAT_PROV_OUT_VALUE_BMSK                                             0xffffffff
#define HWIO_FEAT_PROV_OUTn_FEAT_PROV_OUT_VALUE_SHFT                                                    0x0

#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000020a8 + 0x4 * (n))
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_RMSK                                                   0xffffffff
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_MAXn                                                            3
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_INI(n)        \
        in_dword_masked(HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_ADDR(n), HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_RMSK)
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_INMI(n,mask)    \
        in_dword_masked(HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_ADDR(n), mask)
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_SEC_CTRL_MISC_CONFIG_STATUS_VALUE_BMSK                 0xffffffff
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_SEC_CTRL_MISC_CONFIG_STATUS_VALUE_SHFT                        0x0

#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_ADDR(n)                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004000 + 0x4 * (n))
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_MAXn                                                            71
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_ADDR(n), HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_RMSK)
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_ADDR(n), mask)
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_SHFT                                            0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004120 + 0x4 * (n))
#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_MAXn                                                            3
#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REGIONn_ADDR(n), HWIO_QFPROM_CORR_QC_SPARE_REGIONn_RMSK)
#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REGIONn_ADDR(n), mask)
#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_QC_SPARE_BMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REGIONn_QC_SPARE_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004130)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW0_LSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_PTE_DATA0_BMSK                                             0xe0000000
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_PTE_DATA0_SHFT                                                   0x1d
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_MACCHIATO_EN_BMSK                                          0x10000000
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_MACCHIATO_EN_SHFT                                                0x1c
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_FEATURE_ID_BMSK                                             0xff00000
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_FEATURE_ID_SHFT                                                  0x14
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_JTAG_ID_BMSK                                                  0xfffff
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_JTAG_ID_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004134)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW0_MSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004138)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW1_LSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_SERIAL_NUM_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_SERIAL_NUM_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000413c)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW1_MSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_PTE_DATA1_BMSK                                             0xffff0000
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_PTE_DATA1_SHFT                                                   0x10
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_CHIP_ID_BMSK                                                   0xffff
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_CHIP_ID_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004140)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004144)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004148)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW3_LSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW3_LSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000414c)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW3_MSB_ADDR, HWIO_QFPROM_CORR_PTE_ROW3_MSB_RMSK)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_RD_PERM_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004150)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_RD_PERM_LSB_ADDR, HWIO_QFPROM_CORR_RD_PERM_LSB_RMSK)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_RD_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RSVD0_BMSK                                                  0x80000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RSVD0_SHFT                                                        0x1f
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG30_BMSK                                        0x40000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG30_SHFT                                              0x1e
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG29_BMSK                                        0x20000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG29_SHFT                                              0x1d
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG28_BMSK                                        0x10000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG28_SHFT                                              0x1c
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG27_BMSK                                         0x8000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG27_SHFT                                              0x1b
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG26_BMSK                                         0x4000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG26_SHFT                                              0x1a
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH1_BMSK                                                0x2000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH1_SHFT                                                     0x19
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                         0x1000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                              0x18
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_ROM_PATCH_BMSK                                           0x800000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_ROM_PATCH_SHFT                                               0x17
#define HWIO_QFPROM_CORR_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                   0x400000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                       0x16
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                   0x200000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                       0x15
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SEC_BOOT_BMSK                                             0x100000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SEC_BOOT_SHFT                                                 0x14
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                        0x80000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                           0x13
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG18_BMSK                                            0x40000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG18_SHFT                                               0x12
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG17_BMSK                                            0x20000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG17_SHFT                                               0x11
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG16_BMSK                                            0x10000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG16_SHFT                                               0x10
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CM_FEAT_CONFIG_BMSK                                             0x8000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CM_FEAT_CONFIG_SHFT                                                0xf
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MEM_CONFIG_BMSK                                                 0x4000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MEM_CONFIG_SHFT                                                    0xe
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CALIB_BMSK                                                      0x2000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CALIB_SHFT                                                         0xd
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH0_BMSK                                                   0x1000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH0_SHFT                                                      0xc
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEAT_CONFIG_BMSK                                                 0x800
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEAT_CONFIG_SHFT                                                   0xb
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_CONFIG_BMSK                                                  0x400
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_CONFIG_SHFT                                                    0xa
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                             0x200
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                               0x9
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                             0x100
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                               0x8
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                              0x80
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                               0x7
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                              0x40
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                               0x6
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEC_EN_BMSK                                                       0x20
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEC_EN_SHFT                                                        0x5
#define HWIO_QFPROM_CORR_RD_PERM_LSB_WR_PERM_BMSK                                                      0x10
#define HWIO_QFPROM_CORR_RD_PERM_LSB_WR_PERM_SHFT                                                       0x4
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RD_PERM_BMSK                                                       0x8
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RD_PERM_SHFT                                                       0x3
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PTE_BMSK                                                           0x4
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PTE_SHFT                                                           0x2
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REGION_BMSK                                               0x2
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REGION_SHFT                                               0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CRI_CM_PRIVATE_BMSK                                                0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CRI_CM_PRIVATE_SHFT                                                0x0

#define HWIO_QFPROM_CORR_RD_PERM_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004154)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_CORR_RD_PERM_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_RD_PERM_MSB_ADDR, HWIO_QFPROM_CORR_RD_PERM_MSB_RMSK)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_RD_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_RSVD0_BMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_RD_PERM_MSB_RSVD0_SHFT                                                         0x0

#define HWIO_QFPROM_CORR_WR_PERM_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004158)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_WR_PERM_LSB_ADDR, HWIO_QFPROM_CORR_WR_PERM_LSB_RMSK)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_WR_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RSVD0_BMSK                                                  0x80000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RSVD0_SHFT                                                        0x1f
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG30_BMSK                                        0x40000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG30_SHFT                                              0x1e
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG29_BMSK                                        0x20000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG29_SHFT                                              0x1d
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG28_BMSK                                        0x10000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG28_SHFT                                              0x1c
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG27_BMSK                                         0x8000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG27_SHFT                                              0x1b
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG26_BMSK                                         0x4000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG26_SHFT                                              0x1a
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH1_BMSK                                                0x2000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH1_SHFT                                                     0x19
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                         0x1000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                              0x18
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_ROM_PATCH_BMSK                                           0x800000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_ROM_PATCH_SHFT                                               0x17
#define HWIO_QFPROM_CORR_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                   0x400000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                       0x16
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                   0x200000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                       0x15
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SEC_BOOT_BMSK                                             0x100000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SEC_BOOT_SHFT                                                 0x14
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                        0x80000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                           0x13
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG18_BMSK                                            0x40000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG18_SHFT                                               0x12
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG17_BMSK                                            0x20000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG17_SHFT                                               0x11
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG16_BMSK                                            0x10000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG16_SHFT                                               0x10
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CM_FEAT_CONFIG_BMSK                                             0x8000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CM_FEAT_CONFIG_SHFT                                                0xf
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MEM_CONFIG_BMSK                                                 0x4000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MEM_CONFIG_SHFT                                                    0xe
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CALIB_BMSK                                                      0x2000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CALIB_SHFT                                                         0xd
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH0_BMSK                                                   0x1000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH0_SHFT                                                      0xc
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEAT_CONFIG_BMSK                                                 0x800
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEAT_CONFIG_SHFT                                                   0xb
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_CONFIG_BMSK                                                  0x400
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_CONFIG_SHFT                                                    0xa
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                             0x200
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                               0x9
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                             0x100
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                               0x8
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                              0x80
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                               0x7
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                              0x40
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                               0x6
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEC_EN_BMSK                                                       0x20
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEC_EN_SHFT                                                        0x5
#define HWIO_QFPROM_CORR_WR_PERM_LSB_WR_PERM_BMSK                                                      0x10
#define HWIO_QFPROM_CORR_WR_PERM_LSB_WR_PERM_SHFT                                                       0x4
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RD_PERM_BMSK                                                       0x8
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RD_PERM_SHFT                                                       0x3
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PTE_BMSK                                                           0x4
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PTE_SHFT                                                           0x2
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REGION_BMSK                                               0x2
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REGION_SHFT                                               0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CRI_CM_PRIVATE_BMSK                                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CRI_CM_PRIVATE_SHFT                                                0x0

#define HWIO_QFPROM_CORR_WR_PERM_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000415c)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_CORR_WR_PERM_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_WR_PERM_MSB_ADDR, HWIO_QFPROM_CORR_WR_PERM_MSB_RMSK)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_WR_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_RSVD0_BMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_WR_PERM_MSB_RSVD0_SHFT                                                         0x0

#define HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004160)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_CORR_FEC_EN_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR, HWIO_QFPROM_CORR_FEC_EN_LSB_RMSK)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_RSVD0_BMSK                                                   0x80000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_RSVD0_SHFT                                                         0x1f
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION30_FEC_EN_BMSK                                         0x40000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION30_FEC_EN_SHFT                                               0x1e
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION29_FEC_EN_BMSK                                         0x20000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION29_FEC_EN_SHFT                                               0x1d
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION28_FEC_EN_BMSK                                         0x10000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION28_FEC_EN_SHFT                                               0x1c
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION27_FEC_EN_BMSK                                          0x8000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION27_FEC_EN_SHFT                                               0x1b
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION26_FEC_EN_BMSK                                          0x4000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION26_FEC_EN_SHFT                                               0x1a
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION25_FEC_EN_BMSK                                          0x2000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION25_FEC_EN_SHFT                                               0x19
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION24_FEC_EN_BMSK                                          0x1000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION24_FEC_EN_SHFT                                               0x18
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION23_FEC_EN_BMSK                                           0x800000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION23_FEC_EN_SHFT                                               0x17
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION22_FEC_EN_BMSK                                           0x400000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION22_FEC_EN_SHFT                                               0x16
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION21_FEC_EN_BMSK                                           0x200000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION21_FEC_EN_SHFT                                               0x15
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION20_FEC_EN_BMSK                                           0x100000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION20_FEC_EN_SHFT                                               0x14
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION19_FEC_EN_BMSK                                            0x80000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION19_FEC_EN_SHFT                                               0x13
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION18_FEC_EN_BMSK                                            0x40000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION18_FEC_EN_SHFT                                               0x12
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION17_FEC_EN_BMSK                                            0x20000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION17_FEC_EN_SHFT                                               0x11
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION16_FEC_EN_BMSK                                            0x10000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION16_FEC_EN_SHFT                                               0x10
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION15_FEC_EN_BMSK                                             0x8000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION15_FEC_EN_SHFT                                                0xf
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION14_FEC_EN_BMSK                                             0x4000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION14_FEC_EN_SHFT                                                0xe
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION13_FEC_EN_BMSK                                             0x2000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION13_FEC_EN_SHFT                                                0xd
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION12_FEC_EN_BMSK                                             0x1000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION12_FEC_EN_SHFT                                                0xc
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION11_FEC_EN_BMSK                                              0x800
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION11_FEC_EN_SHFT                                                0xb
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION10_FEC_EN_BMSK                                              0x400
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION10_FEC_EN_SHFT                                                0xa
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION9_FEC_EN_BMSK                                               0x200
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION9_FEC_EN_SHFT                                                 0x9
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION8_FEC_EN_BMSK                                               0x100
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION8_FEC_EN_SHFT                                                 0x8
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION7_FEC_EN_BMSK                                                0x80
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION7_FEC_EN_SHFT                                                 0x7
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION6_FEC_EN_BMSK                                                0x40
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION6_FEC_EN_SHFT                                                 0x6
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION5_FEC_EN_BMSK                                                0x20
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION5_FEC_EN_SHFT                                                 0x5
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION4_FEC_EN_BMSK                                                0x10
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION4_FEC_EN_SHFT                                                 0x4
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION3_FEC_EN_BMSK                                                 0x8
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION3_FEC_EN_SHFT                                                 0x3
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION2_FEC_EN_BMSK                                                 0x4
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION2_FEC_EN_SHFT                                                 0x2
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION1_FEC_EN_BMSK                                                 0x2
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION1_FEC_EN_SHFT                                                 0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION0_FEC_EN_BMSK                                                 0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION0_FEC_EN_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004164)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_CORR_FEC_EN_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR, HWIO_QFPROM_CORR_FEC_EN_MSB_RMSK)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_RSVD0_BMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_FEC_EN_MSB_RSVD0_SHFT                                                          0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004168)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_XBL0_BMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_XBL0_SHFT                                                  0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000416c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_XBL1_BMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_XBL1_SHFT                                                  0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004170)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_BMSK                             0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_SHFT                                    0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004174)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_XBL_SEC_BMSK                                        0xfe000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_XBL_SEC_SHFT                                              0x19
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_RPM_BMSK                                             0x1fe0000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_RPM_SHFT                                                  0x11
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_TZ_BMSK                                                0x1ffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_TZ_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004178)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RSVD1_BMSK                                          0xc0000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RSVD1_SHFT                                                0x1e
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_BMSK                                0x3e000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_SHFT                                      0x19
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_BMSK                            0x1000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_SHFT                                 0x18
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_BMSK                              0xffff00
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_SHFT                                   0x8
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_SAFESWITCH_BMSK                                           0xff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_SAFESWITCH_SHFT                                            0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000417c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_RSVD1_BMSK                                          0xf0000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_RSVD1_SHFT                                                0x1c
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_BMSK                                      0xffe0000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_SHFT                                           0x11
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_BMSK                                      0x1f000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_SHFT                                          0xc
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_HYPERVISOR_BMSK                                          0xfff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_HYPERVISOR_SHFT                                            0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004180)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MSS_BMSK                                            0xffff0000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MSS_SHFT                                                  0x10
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MBA_BMSK                                                0xffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MBA_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004184)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ADDR, HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RMSK)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RSVD0_BMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RSVD0_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004188)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR, HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DCC_DEBUG_DISABLE_BMSK                              0x80000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DCC_DEBUG_DISABLE_SHFT                                    0x1f
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_APB_DFD_DISABLE_BMSK                           0x40000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_APB_DFD_DISABLE_SHFT                                 0x1e
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_BMSK                              0x20000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_SHFT                                    0x1d
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_BMSK                           0x10000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_SHFT                                 0x1c
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RSVD2_BMSK                                           0xe000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RSVD2_SHFT                                                0x19
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                0x1000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                     0x18
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                0x800000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                    0x17
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_BMSK                                   0x400000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_SHFT                                       0x16
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_BMSK                            0x200000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_SHFT                                0x15
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_BMSK                             0x100000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_SHFT                                 0x14
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_BMSK                           0x80000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_SHFT                              0x13
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RSVD1_BMSK                                             0x60000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RSVD1_SHFT                                                0x11
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_BMSK                            0x10000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_SHFT                               0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_BMSK                                    0x8000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_SHFT                                       0xf
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_WDOG_EN_BMSK                                            0x4000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_WDOG_EN_SHFT                                               0xe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SPDM_SECURE_MODE_BMSK                                   0x2000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SPDM_SECURE_MODE_SHFT                                      0xd
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_BMSK                               0x1000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_SHFT                                  0xc
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RSVD0_BMSK                                               0xc00
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RSVD0_SHFT                                                 0xa
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_BMSK                                           0x3e0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SHFT                                             0x5
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_BMSK                                  0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_SHFT                                   0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_BMSK                                0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_SHFT                                0x3
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_BMSK                                   0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_SHFT                                   0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_BMSK                                          0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_SHFT                                          0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_BMSK                                       0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_SHFT                                       0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000418c)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_ADDR, HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_SPIDEN_DISABLE_BMSK                           0x80000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_SPIDEN_DISABLE_SHFT                                 0x1f
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_SPIDEN_DISABLE_BMSK                            0x40000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_SPIDEN_DISABLE_SHFT                                  0x1e
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_SPIDEN_DISABLE_BMSK                             0x20000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_SPIDEN_DISABLE_SHFT                                   0x1d
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_SPIDEN_DISABLE_BMSK                            0x10000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_SPIDEN_DISABLE_SHFT                                  0x1c
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_SPNIDEN_DISABLE_BMSK                           0x8000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_SPNIDEN_DISABLE_SHFT                                0x1b
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_SPNIDEN_DISABLE_BMSK                           0x4000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_SPNIDEN_DISABLE_SHFT                                0x1a
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_SPNIDEN_DISABLE_BMSK                            0x2000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_SPNIDEN_DISABLE_SHFT                                 0x19
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_SPNIDEN_DISABLE_BMSK                             0x1000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_SPNIDEN_DISABLE_SHFT                                  0x18
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_SPNIDEN_DISABLE_BMSK                             0x800000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_SPNIDEN_DISABLE_SHFT                                 0x17
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_MSS_NIDEN_DISABLE_BMSK                                0x400000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_MSS_NIDEN_DISABLE_SHFT                                    0x16
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_NIDEN_DISABLE_BMSK                       0x200000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_NIDEN_DISABLE_SHFT                           0x15
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_NIDEN_DISABLE_BMSK                              0x100000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_NIDEN_DISABLE_SHFT                                  0x14
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RPM_NIDEN_DISABLE_BMSK                                 0x80000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RPM_NIDEN_DISABLE_SHFT                                    0x13
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_NIDEN_DISABLE_BMSK                                0x40000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_NIDEN_DISABLE_SHFT                                   0x12
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_NIDEN_DISABLE_BMSK                               0x20000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_NIDEN_DISABLE_SHFT                                  0x11
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_NIDEN_DISABLE_BMSK                                 0x10000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_NIDEN_DISABLE_SHFT                                    0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_BMSK                                 0x8000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_SHFT                                    0xf
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_MSS_DBGEN_DISABLE_BMSK                                  0x4000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_MSS_DBGEN_DISABLE_SHFT                                     0xe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_A5X_ISDB_DBGEN_DISABLE_BMSK                             0x2000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_A5X_ISDB_DBGEN_DISABLE_SHFT                                0xd
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_VENUS_0_DBGEN_DISABLE_BMSK                              0x1000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_VENUS_0_DBGEN_DISABLE_SHFT                                 0xc
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RSVD1_BMSK                                               0x800
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RSVD1_SHFT                                                 0xb
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_DBGEN_DISABLE_BMSK                          0x400
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_SENSOR_DBGEN_DISABLE_SHFT                            0xa
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_DBGEN_DISABLE_BMSK                                 0x200
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PIMEM_DBGEN_DISABLE_SHFT                                   0x9
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RPM_DBGEN_DISABLE_BMSK                                   0x100
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RPM_DBGEN_DISABLE_SHFT                                     0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_DBGEN_DISABLE_BMSK                                   0x80
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_WCSS_DBGEN_DISABLE_SHFT                                    0x7
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_Q6_DBGEN_DISABLE_BMSK                               0x40
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_LPASS_Q6_DBGEN_DISABLE_SHFT                                0x6
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_DBGEN_DISABLE_BMSK                                    0x20
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_DBGEN_DISABLE_SHFT                                     0x5
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_BMSK                                   0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_SHFT                                    0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_DEVICEEN_DISABLE_BMSK                                  0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DAP_DEVICEEN_DISABLE_SHFT                                  0x3
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RPM_DAPEN_DISABLE_BMSK                                     0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RPM_DAPEN_DISABLE_SHFT                                     0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RSVD0_BMSK                                                 0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RSVD0_SHFT                                                 0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DEBUG_BUS_DISABLE_BMSK                                     0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_DEBUG_BUS_DISABLE_SHFT                                     0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004190)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR, HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD1_BMSK                                          0xffff8000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD1_SHFT                                                 0xf
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG30_SECURE_BMSK                             0x4000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG30_SECURE_SHFT                                0xe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG29_SECURE_BMSK                             0x2000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG29_SECURE_SHFT                                0xd
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG28_SECURE_BMSK                             0x1000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG28_SECURE_SHFT                                0xc
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG27_SECURE_BMSK                              0x800
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG27_SECURE_SHFT                                0xb
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG26_SECURE_BMSK                              0x400
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OEM_SPARE_REG26_SECURE_SHFT                                0xa
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD0_BMSK                                               0x3fe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD0_SHFT                                                 0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_LPASS_SPIDEN_DISABLE_BMSK                                  0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_LPASS_SPIDEN_DISABLE_SHFT                                  0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004194)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_ADDR, HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_BMSK                                 0xffff0000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_SHFT                                       0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_BMSK                                          0xffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_SHFT                                             0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004198)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_VID_BMSK                                     0xffff0000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_VID_SHFT                                           0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_PID_BMSK                                         0xffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_PID_SHFT                                            0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000419c)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RSVD0_BMSK                                          0xffffff00
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RSVD0_SHFT                                                 0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_BMSK                             0xff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_SHFT                              0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041a0)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_BMSK                        0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_SHFT                              0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_BMSK                                  0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_SHFT                                        0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_BMSK                        0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_SHFT                              0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                          0x1fe00000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                                0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                           0x180000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                               0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_BMSK                        0x40000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_SHFT                           0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_BMSK                        0x20000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_SHFT                           0x11
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_BMSK                                 0x10000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_SHFT                                    0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_BMSK                               0x8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_SHFT                                  0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_BMSK                               0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_SHFT                                  0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_BMSK                                   0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_SHFT                                      0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                      0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                         0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                             0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                               0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                     0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                       0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                      0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                        0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_BMSK                                       0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_SHFT                                         0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                          0x80
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                           0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                                0x40
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                                 0x6
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_BMSK                                       0x20
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_SHFT                                        0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_BMSK                                      0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_SHFT                                       0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_BMSK                                       0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_SHFT                                       0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                               0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                               0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041a4)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                             0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                   0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                             0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                   0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                   0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                         0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_BMSK                                  0x10000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_SHFT                                        0x1c
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_BMSK                              0x8000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_SHFT                                   0x1b
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_BMSK                           0x4000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_SHFT                                0x1a
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_BMSK               0x2000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                    0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_BMSK                   0x1000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_SHFT                        0x18
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_BMSK                0x800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_SHFT                    0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                               0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                   0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_BMSK                                     0x200000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_SHFT                                         0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_BMSK                                0x100000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_SHFT                                    0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_BMSK                         0x80000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_SHFT                            0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                                0x7c000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                    0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                             0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                                0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_BMSK                                      0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_SHFT                                         0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                         0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                           0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_BMSK                                      0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_SHFT                                        0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                       0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                         0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                        0x1e0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                          0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                              0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                               0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_BMSK                                 0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_SHFT                                 0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_BMSK                                  0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_SHFT                                  0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_BMSK                                    0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_SHFT                                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_BMSK                                   0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_SHFT                                   0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041a8)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_BMSK                               0xfff00000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_SHFT                                     0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_BMSK                             0x80000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_SHFT                                0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_BMSK                                      0x40000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_SHFT                                         0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_BMSK                                  0x20000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_SHFT                                     0x11
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_BMSK                                 0x18000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_SHFT                                     0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                       0x7fe0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                          0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_BMSK                         0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_SHFT                          0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041ac)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_BMSK                        0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_SHFT                              0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                        0x60000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                              0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                       0x1fe00000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                             0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_BMSK                                0x100000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_SHFT                                    0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_RSVD1_BMSK                                            0xf0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_RSVD1_SHFT                                               0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_BMSK                                  0xffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_SHFT                                     0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041b0)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_BMSK                       0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_SHFT                             0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_BMSK                          0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_SHFT                                0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_BMSK                 0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_SHFT                       0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_BMSK                        0x10000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_SHFT                              0x1c
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_BMSK                           0x8000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_SHFT                                0x1b
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_BMSK                          0x4000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_SHFT                               0x1a
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_BMSK                         0x2000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_SHFT                              0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_BMSK                           0x1000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_SHFT                                0x18
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                           0x800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                               0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_BMSK                            0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_SHFT                                0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_BMSK                       0x200000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_SHFT                           0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_BMSK                        0x100000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_SHFT                            0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_BMSK                0x80000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_SHFT                   0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_BMSK                    0x40000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_SHFT                       0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_BMSK                           0x20000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_SHFT                              0x11
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_BMSK                             0x10000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_SHFT                                0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_BMSK                             0x8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_SHFT                                0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_BMSK                         0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_SHFT                            0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_BMSK                              0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_SHFT                                 0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                             0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                                0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_BMSK                            0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_SHFT                              0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_BMSK                               0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_SHFT                                 0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_DSI_0_DISABLE_BMSK                                      0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_DSI_0_DISABLE_SHFT                                        0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_BMSK                               0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_SHFT                                 0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_BMSK                                0x80
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_SHFT                                 0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_BMSK                             0x40
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_SHFT                              0x6
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_BMSK                               0x20
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_SHFT                                0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_BMSK                               0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_SHFT                                0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_BMSK                                0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_SHFT                                0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_BMSK                                     0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_SHFT                                     0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                      0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                          0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                          0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041b4)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_BMSK                                0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_SHFT                                      0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_BMSK                          0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_SHFT                                0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_BMSK                                 0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_SHFT                                       0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SILVER_PLL_MAX_FREQ_LVAL_BMSK                      0x1fe00000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SILVER_PLL_MAX_FREQ_LVAL_SHFT                            0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                              0x1c0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                                  0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_GOLD_PLL_MAX_FREQ_LVAL_BMSK                           0x3fc00
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_GOLD_PLL_MAX_FREQ_LVAL_SHFT                               0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_BMSK                   0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_SHFT                     0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_BMSK                            0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_SHFT                              0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_BMSK                             0x80
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_SHFT                              0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_BMSK                              0x40
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_SHFT                               0x6
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_BMSK                               0x20
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_SHFT                                0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_BMSK                              0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_SHFT                               0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_BMSK                             0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_SHFT                             0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_BMSK                             0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_SHFT                             0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_BMSK                              0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_SHFT                              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_BMSK                               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_SHFT                               0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041b8)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_BMSK              0xfffc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_SHFT                    0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_TAP_INSTR_DISABLE_BMSK                                0x3ffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_TAP_INSTR_DISABLE_SHFT                                    0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041bc)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_SEC_TAP_ACCESS_DISABLE_BMSK                        0xfffc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_SEC_TAP_ACCESS_DISABLE_SHFT                              0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_BMSK                0x3ffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_SHFT                    0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041c0)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_PATCH_VERSION_BMSK                       0xfe000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_PATCH_VERSION_SHFT                             0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_APPS_PBL_PATCH_VERSION_BMSK                         0x1fc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_APPS_PBL_PATCH_VERSION_SHFT                              0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_APPS_PBL_BOOT_SPEED_BMSK                              0x30000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_APPS_PBL_BOOT_SPEED_SHFT                                 0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_BOOT_BMSK                                    0x8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MODEM_PBL_BOOT_SHFT                                       0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RSVD1_BMSK                                             0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RSVD1_SHFT                                                0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_APPS_BOOT_FROM_ROM_BMSK                                0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_APPS_BOOT_FROM_ROM_SHFT                                   0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RSVD0_BMSK                                             0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RSVD0_SHFT                                                0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MODEM_BOOT_FROM_ROM_BMSK                                0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MODEM_BOOT_FROM_ROM_SHFT                                  0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MSA_ENA_BMSK                                            0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_MSA_ENA_SHFT                                              0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_FORCE_MSA_AUTH_EN_BMSK                                  0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_FORCE_MSA_AUTH_EN_SHFT                                    0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ARM_CE_DISABLE_USAGE_BMSK                               0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ARM_CE_DISABLE_USAGE_SHFT                                 0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_BOOT_ROM_CFG_BMSK                                        0xff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_BOOT_ROM_CFG_SHFT                                         0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041c4)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_ADDR, HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RMSK)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_APPS_BOOT_TRIGGER_DISABLE_BMSK                     0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_APPS_BOOT_TRIGGER_DISABLE_SHFT                           0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_BMSK                    0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_SHFT                          0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_XBL_SEC_AUTH_DISABLE_BMSK                          0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_XBL_SEC_AUTH_DISABLE_SHFT                                0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_MSM_PKG_TYPE_BMSK                                  0x10000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_MSM_PKG_TYPE_SHFT                                        0x1c
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RSVD3_BMSK                                          0xffc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RSVD3_SHFT                                               0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_FOUNDRY_ID_BMSK                                       0x3c000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_FOUNDRY_ID_SHFT                                           0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_PLL_CFG_BMSK                                           0x3ff0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_PLL_CFG_SHFT                                              0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_APPS_PBL_PLL_CTRL_BMSK                                    0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_APPS_PBL_PLL_CTRL_SHFT                                    0x0

#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041c8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_MAXn                                                           3
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_HASH_DATA0_BMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_HASH_DATA0_SHFT                                              0x0

#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041cc + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_MAXn                                                           3
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_HASH_DATA1_BMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_HASH_DATA1_SHFT                                              0x0

#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041e8)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_LMH_CS_FUSES_SLOPE_16_0_BMSK                             0xffff8000
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_LMH_CS_FUSES_SLOPE_16_0_SHFT                                    0xf
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_VREF_TRIM_BMSK                                0x7f80
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_VREF_TRIM_SHFT                                   0x7
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_ENABLE_BMSK                                     0x40
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_CDSP_Q6SS1_LDO_ENABLE_SHFT                                      0x6
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_VREF_TRIM_BMSK                                   0x3e
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_VREF_TRIM_SHFT                                    0x1
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_ENABLE_BMSK                                       0x1
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_MSS_Q6SS0_LDO_ENABLE_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041ec)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_LMH_CS_FUSES_INTERCEPT_8_0_BMSK                          0xff800000
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_LMH_CS_FUSES_INTERCEPT_8_0_SHFT                                0x17
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_LMH_CS_FUSES_SLOPE_39_17_BMSK                              0x7fffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_LMH_CS_FUSES_SLOPE_39_17_SHFT                                   0x0

#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041f0)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_LMH_FUSES_AMP_COMP_0_BMSK                                0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_LMH_FUSES_AMP_COMP_0_SHFT                                      0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_LMH_CS_FUSES_INTERCEPT_39_9_BMSK                         0x7fffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_LMH_CS_FUSES_INTERCEPT_39_9_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041f4)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_SPARE0_BMSK                                              0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_SPARE0_SHFT                                                    0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_WEST_BGV_TRIM_BMSK                                0x7f800000
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_WEST_BGV_TRIM_SHFT                                      0x17
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_EAST_BGV_TRIM_BMSK                                  0x7f8000
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_EAST_BGV_TRIM_SHFT                                       0xf
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_BANDGAP_TRIM_BMSK                                            0x7f00
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_BANDGAP_TRIM_SHFT                                               0x8
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_GPU_LDOVREFTRIM_BMSK                                           0xf8
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_GPU_LDOVREFTRIM_SHFT                                            0x3
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_LMH_FUSES_AMP_COMP_3_1_BMSK                                     0x7
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_LMH_FUSES_AMP_COMP_3_1_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041f8)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_1_0_BMSK                   0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_1_0_SHFT                         0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_SPTP_BMSK                         0x3ff00000
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_SPTP_SHFT                               0x14
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_RAC_BMSK                             0xffc00
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_RAC_SHFT                                 0xa
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_HM_BMSK                                0x3ff
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_GPU_LMH_CS_FUSES_SLOPE_HM_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041fc)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_AMP_COMP_BMSK                           0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_AMP_COMP_SHFT                                 0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_SPTP_BMSK                      0xffc0000
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_SPTP_SHFT                           0x12
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_RAC_BMSK                         0x3ff00
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_RAC_SHFT                             0x8
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_9_2_BMSK                         0xff
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_GPU_LMH_CS_FUSES_INTERCEPT_HM_9_2_SHFT                          0x0

#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004200)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW3_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW3_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_SVS_3_0_BMSK                       0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_SVS_3_0_SHFT                             0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_NOM_BMSK                            0xf000000
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_NOM_SHFT                                 0x18
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_TUR_BMSK                             0xf00000
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_OFFSET_TUR_SHFT                                 0x14
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS2_BMSK                                    0xf8000
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS2_SHFT                                        0xf
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS_BMSK                                      0x7c00
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_SVS_SHFT                                         0xa
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_NOM_BMSK                                       0x3e0
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_NOM_SHFT                                         0x5
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_TUR_BMSK                                        0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_CPR0_TARG_VOLT_TUR_SHFT                                         0x0

#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004204)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW3_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW3_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS2_BMSK                                 0xf8000000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS2_SHFT                                       0x1b
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS_BMSK                                   0x7c00000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_SVS_SHFT                                        0x16
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_NOM_BMSK                                    0x3e0000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_NOM_SHFT                                        0x11
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_TUR_BMSK                                     0x1f000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR1_TARG_VOLT_TUR_SHFT                                         0xc
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR0_AGING_BMSK                                               0xff0
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR0_AGING_SHFT                                                 0x4
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_BMSK                                 0xf
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_SHFT                                 0x0

#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004208)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW4_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW4_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR2_TARG_VOLT_NOM_2_0_BMSK                              0xe0000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR2_TARG_VOLT_NOM_2_0_SHFT                                    0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR2_TARG_VOLT_TUR_BMSK                                  0x1f000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR2_TARG_VOLT_TUR_SHFT                                        0x18
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_AGING_BMSK                                            0xff0000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_AGING_SHFT                                                0x10
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS2_BMSK                              0xf000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS2_SHFT                                 0xc
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS_BMSK                                0xf00
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_SVS_SHFT                                  0x8
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_NOM_BMSK                                 0xf0
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_NOM_SHFT                                  0x4
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_TUR_BMSK                                  0xf
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_CPR1_TARG_VOLT_OFFSET_TUR_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000420c)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW4_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW4_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_AGING_3_0_BMSK                                      0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_AGING_3_0_SHFT                                            0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS2_BMSK                           0xf000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS2_SHFT                                0x18
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS_BMSK                             0xf00000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_SVS_SHFT                                 0x14
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_NOM_BMSK                              0xf0000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_NOM_SHFT                                 0x10
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_TUR_BMSK                               0xf000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_OFFSET_TUR_SHFT                                  0xc
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS2_BMSK                                      0xf80
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS2_SHFT                                        0x7
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS_BMSK                                        0x7c
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_SVS_SHFT                                         0x2
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_NOM_4_3_BMSK                                     0x3
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_CPR2_TARG_VOLT_NOM_4_3_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004210)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_RMSK                                                     0xff07ffff
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW5_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW5_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR4_TARG_VOLT_NOM_2_0_BMSK                              0xe0000000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR4_TARG_VOLT_NOM_2_0_SHFT                                    0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR4_TARG_VOLT_TUR_BMSK                                  0x1f000000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR4_TARG_VOLT_TUR_SHFT                                        0x18
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR3_TARG_VOLT_SVS_BMSK                                     0x7c000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR3_TARG_VOLT_SVS_SHFT                                         0xe
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR3_TARG_VOLT_TUR_BMSK                                      0x3e00
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR3_TARG_VOLT_TUR_SHFT                                         0x9
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR3_TARG_VOLT_NOM_BMSK                                       0x1f0
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR3_TARG_VOLT_NOM_SHFT                                         0x4
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR2_AGING_7_4_BMSK                                             0xf
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_CPR2_AGING_7_4_SHFT                                             0x0

#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004214)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_RMSK                                                      0x7ffffff
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW5_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW5_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR6_TARG_VOLT_SVS_BMSK                                   0x7c00000
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR6_TARG_VOLT_SVS_SHFT                                        0x16
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR6_TARG_VOLT_NOM_BMSK                                    0x3e0000
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR6_TARG_VOLT_NOM_SHFT                                        0x11
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR6_TARG_VOLT_TUR_BMSK                                     0x1f000
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR6_TARG_VOLT_TUR_SHFT                                         0xc
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR5_TARG_VOLT_TUR_BMSK                                       0xf80
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR5_TARG_VOLT_TUR_SHFT                                         0x7
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR5_TARG_VOLT_NOM_BMSK                                        0x7c
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR5_TARG_VOLT_NOM_SHFT                                         0x2
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR4_TARG_VOLT_NOM_4_3_BMSK                                     0x3
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_CPR4_TARG_VOLT_NOM_4_3_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004218)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW6_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW6_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW6_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TARG_VOLT_SVS_3_0_BMSK                              0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TARG_VOLT_SVS_3_0_SHFT                                    0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TARG_VOLT_NOM_BMSK                                   0xfc00000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TARG_VOLT_NOM_SHFT                                        0x16
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TARG_VOLT_TUR_BMSK                                    0x3f0000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TARG_VOLT_TUR_SHFT                                        0x10
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_SVS2_ROSEL_BMSK                                         0xf000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_SVS2_ROSEL_SHFT                                            0xc
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_SVS_ROSEL_BMSK                                           0xf00
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_SVS_ROSEL_SHFT                                             0x8
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_NOMINAL_ROSEL_BMSK                                        0xf0
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_NOMINAL_ROSEL_SHFT                                         0x4
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TURBO_ROSEL_BMSK                                           0xf
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_CPR8_TURBO_ROSEL_SHFT                                           0x0

#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000421c)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_RMSK                                                     0xffffc0ff
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW6_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW6_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW6_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_NOMINAL_QUOT_VMIN_5_0_BMSK                          0xfc000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_NOMINAL_QUOT_VMIN_5_0_SHFT                                0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_TURBO_QUOT_VMIN_BMSK                                 0x3ffc000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_TURBO_QUOT_VMIN_SHFT                                       0xe
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS2_BMSK                                       0xfc
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS2_SHFT                                        0x2
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS_5_4_BMSK                                     0x3
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_CPR8_TARG_VOLT_SVS_5_4_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004220)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_RMSK                                                     0x3fffffff
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW7_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_CPR8_SVS2_QUOT_VMIN_BMSK                                 0x3ffc0000
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_CPR8_SVS2_QUOT_VMIN_SHFT                                       0x12
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_CPR8_SVS_QUOT_VMIN_BMSK                                     0x3ffc0
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_CPR8_SVS_QUOT_VMIN_SHFT                                         0x6
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_CPR8_NOMINAL_QUOT_VMIN_11_6_BMSK                               0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_CPR8_NOMINAL_QUOT_VMIN_11_6_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004224)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RMSK                                                     0xfffffc00
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS2_0_BMSK                             0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS2_0_SHFT                                   0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS_6_0_BMSK                            0x7f000000
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_SVS_6_0_SHFT                                  0x18
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_NOM_BMSK                                  0xfe0000
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_NOM_SHFT                                      0x11
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_TUR_BMSK                                   0x1fc00
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_CPR8_QUOT_OFFSET_TUR_SHFT                                       0xa

#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004228)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_TARG_VOLT_TUR_1_0_BMSK                              0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_TARG_VOLT_TUR_1_0_SHFT                                    0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_SVS2_ROSEL_BMSK                                     0x3c000000
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_SVS2_ROSEL_SHFT                                           0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_SVS_ROSEL_BMSK                                       0x3c00000
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_SVS_ROSEL_SHFT                                            0x16
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_NOMINAL_ROSEL_BMSK                                    0x3c0000
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_NOMINAL_ROSEL_SHFT                                        0x12
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_TURBO_ROSEL_BMSK                                       0x3c000
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR9_TURBO_ROSEL_SHFT                                           0xe
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR8_AGING_BMSK                                              0x3fc0
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR8_AGING_SHFT                                                 0x6
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR8_QUOT_OFFSET_SVS2_6_1_BMSK                                 0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_CPR8_QUOT_OFFSET_SVS2_6_1_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000422c)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RMSK                                                     0xf03fffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TURBO_QUOT_VMIN_3_0_BMSK                            0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TURBO_QUOT_VMIN_3_0_SHFT                                  0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS2_BMSK                                   0x3f0000
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS2_SHFT                                       0x10
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS_BMSK                                      0xfc00
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_SVS_SHFT                                         0xa
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_NOM_BMSK                                       0x3f0
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_NOM_SHFT                                         0x4
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_TUR_5_2_BMSK                                     0xf
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_CPR9_TARG_VOLT_TUR_5_2_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004230)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_CPR9_SVS_QUOT_VMIN_BMSK                                  0xfff00000
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_CPR9_SVS_QUOT_VMIN_SHFT                                        0x14
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_CPR9_NOMINAL_QUOT_VMIN_BMSK                                 0xfff00
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_CPR9_NOMINAL_QUOT_VMIN_SHFT                                     0x8
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_CPR9_TURBO_QUOT_VMIN_11_4_BMSK                                 0xff
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_CPR9_TURBO_QUOT_VMIN_11_4_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004234)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RMSK                                                     0xff000fff
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_NOM_0_BMSK                              0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_NOM_0_SHFT                                    0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_TUR_BMSK                                0x7f000000
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_CPR9_QUOT_OFFSET_TUR_SHFT                                      0x18
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_CPR9_SVS2_QUOT_VMIN_BMSK                                      0xfff
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_CPR9_SVS2_QUOT_VMIN_SHFT                                        0x0

#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004238)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RMSK                                                       0xfffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS2_BMSK                                 0xfe000
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS2_SHFT                                     0xd
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS_BMSK                                   0x1fc0
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_SVS_SHFT                                      0x6
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_NOM_6_1_BMSK                                 0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_CPR9_QUOT_OFFSET_NOM_6_1_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000423c)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RMSK                                                    0xffffffc0
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SPARE_71_63_BMSK                                        0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SPARE_71_63_SHFT                                              0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SPARE_71_62_BMSK                                        0x40000000
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SPARE_71_62_SHFT                                              0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SPARE_71_61_BMSK                                        0x20000000
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SPARE_71_61_SHFT                                              0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SW_CAL_REDUN_SEL_BMSK                                   0x1c000000
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_SW_CAL_REDUN_SEL_SHFT                                         0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS2_BMSK                            0x3e00000
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS2_SHFT                                 0x15
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS_BMSK                              0x1f0000
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_SVS_SHFT                                  0x10
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_NOM_BMSK                                0xf800
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_NOM_SHFT                                   0xb
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_TUR_BMSK                                 0x7c0
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_CPR7_WLAN_TARG_VOLT_TUR_SHFT                                   0x6

#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004240)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SPARE_72_31_BMSK                                        0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SPARE_72_31_SHFT                                              0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SPARE_72_30_BMSK                                        0x40000000
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SPARE_72_30_SHFT                                              0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_QUSB_REFCLK_SEL_BMSK                                    0x20000000
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_QUSB_REFCLK_SEL_SHFT                                          0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_QUSB_PORT0_HSTX_TRIM_LSB_BMSK                           0x1e000000
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_QUSB_PORT0_HSTX_TRIM_LSB_SHFT                                 0x19
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_1_BMSK                                 0x1fe0000
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_1_SHFT                                      0x11
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_0_BMSK                                   0x1fe00
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_SRAM_AGING_SENSOR_0_SHFT                                       0x9
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_GNSS_ADC_RSB_BMSK                                            0x1c0
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_GNSS_ADC_RSB_SHFT                                              0x6
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_GNSS_ADC_LDO_BMSK                                             0x38
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_GNSS_ADC_LDO_SHFT                                              0x3
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_GNSS_ADC_VREF_BMSK                                             0x7
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_GNSS_ADC_VREF_SHFT                                             0x0

#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004244)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS1_BASE0_8_0_BMSK                                   0xff800000
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS1_BASE0_8_0_SHFT                                         0x17
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS0_BASE1_BMSK                                         0x7fe000
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS0_BASE1_SHFT                                              0xd
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS0_BASE0_BMSK                                           0x1ff8
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS0_BASE0_SHFT                                              0x3
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS_CAL_SEL_BMSK                                             0x7
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_TSENS_CAL_SEL_SHFT                                             0x0

#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004248)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS5_OFFSET_0_BMSK                                    0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS5_OFFSET_0_SHFT                                          0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS4_OFFSET_BMSK                                      0x78000000
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS4_OFFSET_SHFT                                            0x1b
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS3_OFFSET_BMSK                                       0x7800000
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS3_OFFSET_SHFT                                            0x17
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS2_OFFSET_BMSK                                        0x780000
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS2_OFFSET_SHFT                                            0x13
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS1_OFFSET_BMSK                                         0x78000
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS1_OFFSET_SHFT                                             0xf
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS0_OFFSET_BMSK                                          0x7800
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS0_OFFSET_SHFT                                             0xb
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS1_BASE1_BMSK                                            0x7fe
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS1_BASE1_SHFT                                              0x1
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS1_BASE0_9_BMSK                                            0x1
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_TSENS1_BASE0_9_SHFT                                            0x0

#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000424c)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS13_OFFSET_0_BMSK                                   0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS13_OFFSET_0_SHFT                                         0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS12_OFFSET_BMSK                                     0x78000000
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS12_OFFSET_SHFT                                           0x1b
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS11_OFFSET_BMSK                                      0x7800000
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS11_OFFSET_SHFT                                           0x17
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS10_OFFSET_BMSK                                       0x780000
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS10_OFFSET_SHFT                                           0x13
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS9_OFFSET_BMSK                                         0x78000
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS9_OFFSET_SHFT                                             0xf
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS8_OFFSET_BMSK                                          0x7800
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS8_OFFSET_SHFT                                             0xb
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS7_OFFSET_BMSK                                           0x780
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS7_OFFSET_SHFT                                             0x7
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS6_OFFSET_BMSK                                            0x78
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS6_OFFSET_SHFT                                             0x3
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS5_OFFSET_3_1_BMSK                                         0x7
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_TSENS5_OFFSET_3_1_SHFT                                         0x0

#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004250)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_RMSK                                                           0x7
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW13_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_TSENS13_OFFSET_3_1_BMSK                                        0x7
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_TSENS13_OFFSET_3_1_SHFT                                        0x0

#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004254)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_RMSK                                                    0xfffff800
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW13_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW13_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW13_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR6_LPI_MX_RC_BMSK                                     0xe0000000
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR6_LPI_MX_RC_SHFT                                           0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR5_LPI_CX_RC_BMSK                                     0x1c000000
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR5_LPI_CX_RC_SHFT                                           0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR4_MX_RC_BMSK                                          0x3800000
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR4_MX_RC_SHFT                                               0x17
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR3_DDR_RC_BMSK                                          0x700000
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR3_DDR_RC_SHFT                                              0x14
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR2_GFX_RC_BMSK                                           0xe0000
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR2_GFX_RC_SHFT                                              0x11
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR1_MSS_RC_BMSK                                           0x1c000
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR1_MSS_RC_SHFT                                               0xe
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR0_CX_RC_BMSK                                             0x3800
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR0_CX_RC_SHFT                                                0xb

#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004258)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW14_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW14_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW14_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_VSENSE_CALIB_25_0_BMSK                                  0xffffffc0
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_VSENSE_CALIB_25_0_SHFT                                         0x6
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR_LOCAL_RC_BMSK                                             0x38
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR_LOCAL_RC_SHFT                                              0x3
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR7_WLAN_RC_BMSK                                              0x7
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR7_WLAN_RC_SHFT                                              0x0

#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000425c)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW14_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW14_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW14_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_VSENSE_CALIB_57_26_BMSK                                 0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_VSENSE_CALIB_57_26_SHFT                                        0x0

#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004260)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW15_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW15_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW15_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_SW_CAL_REDUNDANCY_30_0_BMSK                             0xfffffffe
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_SW_CAL_REDUNDANCY_30_0_SHFT                                    0x1
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_VSENSE_CALIB_58_BMSK                                           0x1
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_VSENSE_CALIB_58_SHFT                                           0x0

#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004264)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW15_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW15_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW15_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_SW_CAL_REDUNDANCY_62_31_BMSK                            0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_SW_CAL_REDUNDANCY_62_31_SHFT                                   0x0

#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004268)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW16_LSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW16_LSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW16_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_SW_CAL_REDUNDANCY_94_63_BMSK                            0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_SW_CAL_REDUNDANCY_94_63_SHFT                                   0x0

#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000426c)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW16_MSB_ADDR, HWIO_QFPROM_CORR_CALIB_ROW16_MSB_RMSK)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW16_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_SW_CAL_REDUNDANCY_126_95_BMSK                           0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_SW_CAL_REDUNDANCY_126_95_SHFT                                  0x0

#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_ADDR(n)                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004270 + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_MAXn                                                        18
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_REDUN_DATA_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_REDUN_DATA_SHFT                                            0x0

#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_ADDR(n)                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004274 + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_MAXn                                                        18
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_REDUN_DATA_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_REDUN_DATA_SHFT                                            0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004308)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ADDR, HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_BMSK                     0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_UFS_SW_CONTROL_DISABLE_SHFT                           0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_BMSK                               0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_SATA_DISABLE_SHFT                                     0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_BMSK                     0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_SECURE_CHANNEL_DISABLE_SHFT                           0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                       0x1fe00000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                             0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                        0x180000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                            0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_BMSK                     0x40000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_ENCODE_DISABLE_SHFT                        0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_BMSK                     0x20000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VENUS_HEVC_DECODE_DISABLE_SHFT                        0x11
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_BMSK                              0x10000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VENUS_4K_DISABLE_SHFT                                 0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_BMSK                            0x8000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VP8_DECODER_DISABLE_SHFT                               0xf
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_BMSK                            0x4000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_VP8_ENCODER_DISABLE_SHFT                               0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_BMSK                                0x2000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDMI_DP_DISABLE_SHFT                                   0xd
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                   0x1000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                      0xc
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                          0x800
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                            0xb
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                  0x400
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                    0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                   0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                     0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_BMSK                                    0x100
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_USB2_DISABLE_SHFT                                      0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                       0x80
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                        0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                             0x40
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                              0x6
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_BMSK                                    0x20
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ISP_1_DISABLE_SHFT                                     0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_BMSK                                   0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_3_DISABLE_SHFT                                    0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_BMSK                                    0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_2_DISABLE_SHFT                                    0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                            0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                            0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000430c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ADDR, HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                          0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                          0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                      0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_BMSK                               0x10000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_RICA_DISABLE_SHFT                                     0x1c
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_BMSK                           0x8000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SPI_SLAVE_DISABLE_SHFT                                0x1b
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_BMSK                        0x4000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SENSOR_DISABLE_SHFT                             0x1a
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_BMSK            0x2000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                 0x19
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_BMSK                0x1000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SW_ISLAND_MODE_DISABLE_SHFT                     0x18
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_BMSK             0x800000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_EFUSE_TESTBUS_READ_DISABLE_SHFT                 0x17
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                            0x400000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                0x16
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_BMSK                                  0x200000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_HVX_DISABLE_SHFT                                      0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_BMSK                             0x100000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_APB2JTAG_DISABLE_SHFT                                 0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_BMSK                      0x80000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_WDOG_BOOT_CLUSTER_SELECT_SHFT                         0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                             0x7c000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                 0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                          0x2000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                             0xd
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_BMSK                                   0x1000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CDSP_DISABLE_SHFT                                      0xc
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                      0x800
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                        0xb
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_BMSK                                   0x400
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_NIDNT_DISABLE_SHFT                                     0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                    0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                      0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                     0x1e0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                       0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                           0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                            0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_BMSK                              0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VFE_RESOLUTION_LIMIT_SHFT                              0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_BMSK                               0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VP9_DECODER_DISABLE_SHFT                               0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_BMSK                                 0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_LPASS_SVA_DISABLE_SHFT                                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_BMSK                                0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_BOOT_CUSTER_SELECT_SHFT                                0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004310)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_ADDR, HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_BMSK                            0xfff00000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MDSP_FW_DISABLE_SHFT                                  0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_BMSK                          0x80000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_GLOBAL_DISABLE_SHFT                             0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_BMSK                                   0x40000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_NAV_DISABLE_SHFT                                      0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_BMSK                               0x20000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_SYS_APCCCFGNMFI_SHFT                                  0x11
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_BMSK                              0x18000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_BOOT_CORE_SELECT_SHFT                                  0xf
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                    0x7fe0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                       0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_BMSK                      0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SLICE_SHFT                       0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004314)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_ADDR, HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_BMSK                     0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCX_SYSBARDISABLE_SHFT                           0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                     0x60000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                           0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                    0x1fe00000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                          0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_BMSK                             0x100000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_APPS_ACG_DISABLE_SHFT                                 0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_RSVD1_BMSK                                         0xf0000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_RSVD1_SHFT                                            0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_BMSK                               0xffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_VU_DISABLE_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004318)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_BMSK                    0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_SPNIDEN_DISABLE_SHFT                          0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_BMSK                       0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_NIDEN_DISABLE_SHFT                             0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_BMSK              0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_NIDEN_DISABLE_SHFT                    0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_BMSK                     0x10000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_NIDEN_DISABLE_SHFT                           0x1c
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_BMSK                        0x8000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_NIDEN_DISABLE_SHFT                             0x1b
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_BMSK                       0x4000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_NIDEN_DISABLE_SHFT                            0x1a
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_BMSK                      0x2000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_NIDEN_DISABLE_SHFT                           0x19
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_BMSK                        0x1000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_NIDEN_DISABLE_SHFT                             0x18
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                        0x800000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                            0x17
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_BMSK                         0x400000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_MSS_DBGEN_DISABLE_SHFT                             0x16
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_BMSK                    0x200000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_A5X_ISDB_DBGEN_DISABLE_SHFT                        0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_BMSK                     0x100000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_VENUS_0_DBGEN_DISABLE_SHFT                         0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_BMSK             0x80000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TURING_EFUSE_TESTBUS_READ_DISABLE_SHFT                0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_BMSK                 0x40000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_SENSOR_DBGEN_DISABLE_SHFT                    0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_BMSK                        0x20000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_PIMEM_DBGEN_DISABLE_SHFT                           0x11
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_BMSK                          0x10000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DBGEN_DISABLE_SHFT                             0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_BMSK                          0x8000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_WCSS_DBGEN_DISABLE_SHFT                             0xf
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_BMSK                      0x4000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_LPASS_Q6_DBGEN_DISABLE_SHFT                         0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_BMSK                           0x2000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DBGEN_DISABLE_SHFT                              0xd
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                          0x1000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                             0xc
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_BMSK                         0x800
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DAP_DEVICEEN_DISABLE_SHFT                           0xb
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_BMSK                            0x400
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_RPM_DAPEN_DISABLE_SHFT                              0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_RSVD0_BMSK                                           0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_RSVD0_SHFT                                             0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_BMSK                            0x100
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DEBUG_BUS_DISABLE_SHFT                              0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_BMSK                             0x80
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_DCC_DEBUG_DISABLE_SHFT                              0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_BMSK                          0x40
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_APB_DFD_DISABLE_SHFT                           0x6
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_BMSK                            0x20
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_NIDEN_DISABLE_SHFT                             0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_BMSK                            0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DBGEN_DISABLE_SHFT                             0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_BMSK                             0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_GPMU_DAPEN_DISABLE_SHFT                             0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_BMSK                                  0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QDI_SPMI_DISABLE_SHFT                                  0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                   0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                       0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000431c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_BMSK                             0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGEND_SHFT                                   0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_BMSK                       0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCP15SDISABLE_SHFT                             0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_BMSK                              0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGTE_SHFT                                    0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SILVER_PLL_MAX_FREQ_LVAL_BMSK                   0x1fe00000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SILVER_PLL_MAX_FREQ_LVAL_SHFT                         0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                           0x1c0000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                               0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_GOLD_PLL_MAX_FREQ_LVAL_BMSK                        0x3fc00
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_GOLD_PLL_MAX_FREQ_LVAL_SHFT                            0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_BMSK                0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_SHFT                  0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_BMSK                         0x100
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPIDEN_DISABLE_SHFT                           0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_BMSK                          0x80
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPIDEN_DISABLE_SHFT                           0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_BMSK                           0x40
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPIDEN_DISABLE_SHFT                            0x6
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_BMSK                            0x20
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPIDEN_DISABLE_SHFT                             0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_BMSK                           0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_APPS_SPIDEN_DISABLE_SHFT                            0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_BMSK                          0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_LPASS_SPNIDEN_DISABLE_SHFT                          0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_BMSK                          0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_PIMEM_SPNIDEN_DISABLE_SHFT                          0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_BMSK                           0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_WCSS_SPNIDEN_DISABLE_SHFT                           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_BMSK                            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_QC_DAP_SPNIDEN_DISABLE_SHFT                            0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004310 + 0x8 * (n))
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_MAXn                                                          18
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_ADDR(n), HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_RMSK)
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_QC_SPARE_BMSK                                         0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_LSB_QC_SPARE_SHFT                                                0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004314 + 0x8 * (n))
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_RMSK                                                    0xffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_MAXn                                                          18
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_ADDR(n), HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_RMSK)
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_QC_SPARE_BMSK                                           0xffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REGn_MSB_QC_SPARE_SHFT                                                0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n)                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004338 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK                                        0xffffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_MAXn                                                 1
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_BMSK                              0xffffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_SHFT                                     0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n)                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000433c + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK                                          0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_MAXn                                                 1
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_BMSK                                0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_SHFT                                     0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004348)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RMSK                                        0xffffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_BMSK                                  0xffff0000
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_SHFT                                        0x10
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_BMSK                                  0xffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_SHFT                                     0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000434c)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RMSK                                          0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_BMSK                                    0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_SHFT                                         0x0

#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(n)                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004350 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_MAXn                                                       1
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_BMSK                                    0xff000000
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_SHFT                                          0x18
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_BMSK                                      0xff0000
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_SHFT                                          0x10
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_BMSK                                        0xff00
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_SHFT                                           0x8
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_BMSK                                          0xff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_SHFT                                           0x0

#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_ADDR(n)                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004354 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_RMSK                                                0xffffff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_MAXn                                                       1
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_BMSK                                      0xff0000
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_SHFT                                          0x10
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_BMSK                                        0xff00
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_SHFT                                           0x8
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_BMSK                                          0xff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_SHFT                                           0x0

#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004360 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                             3
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004364 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                      0xffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                             3
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                            0xffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                 0x0

#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004380)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_RMSK)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004384)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RMSK                                      0xffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RMSK)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_BMSK                                0xffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_SHFT                                     0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004388 + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                             3
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000438c + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                      0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                             3
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                            0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                 0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000043a8)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_RMSK)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000043ac)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RMSK                                      0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RMSK)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_BMSK                                0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_SHFT                                     0x0

#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000043b0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_MAXn                                                         55
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_PATCH_DATA_BMSK                                      0xffffffff
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_PATCH_DATA_SHFT                                             0x0

#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000043b4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RMSK                                                   0xffffff
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_MAXn                                                         55
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RSVD0_BMSK                                             0xfe0000
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RSVD0_SHFT                                                 0x11
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_ADDR_BMSK                                         0x1fffe
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_ADDR_SHFT                                             0x1
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_EN_BMSK                                               0x1
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_EN_SHFT                                               0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004570 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_MAXn                                                    1
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_BMSK                                 0xffffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_SHFT                                        0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004574 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK                                             0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_MAXn                                                    1
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_BMSK                                   0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_SHFT                                        0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004580)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR, HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RMSK)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_BMSK                                     0xffff0000
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_SHFT                                           0x10
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_BMSK                                     0xffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_SHFT                                        0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004584)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RMSK                                             0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR, HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RMSK)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_BMSK                                       0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_SHFT                                            0x0

#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004588 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_MAXn                                                           3
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_HASH_DATA0_BMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_LSB_HASH_DATA0_SHFT                                              0x0

#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000458c + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_RMSK                                                    0xffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_MAXn                                                           3
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_HASH_DATA1_BMSK                                         0xffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROWn_MSB_HASH_DATA1_SHFT                                              0x0

#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_ADDR                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045a8)
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_ADDR, HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_HASH_DATA0_BMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_LSB_HASH_DATA0_SHFT                                              0x0

#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_ADDR                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045ac)
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_RMSK                                                    0xffffff
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_IN          \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_ADDR, HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_RSVD0_BMSK                                              0xfffffc
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_RSVD0_SHFT                                                   0x2
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_MODEM_BMSK                                    0x2
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_MODEM_SHFT                                    0x1
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_APPS_BMSK                                     0x1
#define HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_APPS_SHFT                                     0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004596 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_MAXn                                                    30
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000459a + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_MAXn                                                    30
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000459e + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_MAXn                                                    30
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045a2 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_MAXn                                                    30
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_SEC_CTRL_HW_VERSION_ADDR                                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006000)
#define HWIO_SEC_CTRL_HW_VERSION_RMSK                                                            0xffffffff
#define HWIO_SEC_CTRL_HW_VERSION_IN          \
        in_dword_masked(HWIO_SEC_CTRL_HW_VERSION_ADDR, HWIO_SEC_CTRL_HW_VERSION_RMSK)
#define HWIO_SEC_CTRL_HW_VERSION_INM(m)      \
        in_dword_masked(HWIO_SEC_CTRL_HW_VERSION_ADDR, m)
#define HWIO_SEC_CTRL_HW_VERSION_MAJOR_BMSK                                                      0xf0000000
#define HWIO_SEC_CTRL_HW_VERSION_MAJOR_SHFT                                                            0x1c
#define HWIO_SEC_CTRL_HW_VERSION_MINOR_BMSK                                                       0xfff0000
#define HWIO_SEC_CTRL_HW_VERSION_MINOR_SHFT                                                            0x10
#define HWIO_SEC_CTRL_HW_VERSION_STEP_BMSK                                                           0xffff
#define HWIO_SEC_CTRL_HW_VERSION_STEP_SHFT                                                              0x0

#define HWIO_FEATURE_CONFIG0_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006004)
#define HWIO_FEATURE_CONFIG0_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG0_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG0_ADDR, HWIO_FEATURE_CONFIG0_RMSK)
#define HWIO_FEATURE_CONFIG0_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG0_ADDR, m)
#define HWIO_FEATURE_CONFIG0_UFS_SW_CONTROL_DISABLE_BMSK                                         0x80000000
#define HWIO_FEATURE_CONFIG0_UFS_SW_CONTROL_DISABLE_SHFT                                               0x1f
#define HWIO_FEATURE_CONFIG0_SATA_DISABLE_BMSK                                                   0x40000000
#define HWIO_FEATURE_CONFIG0_SATA_DISABLE_SHFT                                                         0x1e
#define HWIO_FEATURE_CONFIG0_SECURE_CHANNEL_DISABLE_BMSK                                         0x20000000
#define HWIO_FEATURE_CONFIG0_SECURE_CHANNEL_DISABLE_SHFT                                               0x1d
#define HWIO_FEATURE_CONFIG0_GFX3D_FREQ_LIMIT_VAL_BMSK                                           0x1fe00000
#define HWIO_FEATURE_CONFIG0_GFX3D_FREQ_LIMIT_VAL_SHFT                                                 0x15
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_BMSK                                            0x180000
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_SHFT                                                0x13
#define HWIO_FEATURE_CONFIG0_VENUS_HEVC_ENCODE_DISABLE_BMSK                                         0x40000
#define HWIO_FEATURE_CONFIG0_VENUS_HEVC_ENCODE_DISABLE_SHFT                                            0x12
#define HWIO_FEATURE_CONFIG0_VENUS_HEVC_DECODE_DISABLE_BMSK                                         0x20000
#define HWIO_FEATURE_CONFIG0_VENUS_HEVC_DECODE_DISABLE_SHFT                                            0x11
#define HWIO_FEATURE_CONFIG0_VENUS_4K_DISABLE_BMSK                                                  0x10000
#define HWIO_FEATURE_CONFIG0_VENUS_4K_DISABLE_SHFT                                                     0x10
#define HWIO_FEATURE_CONFIG0_VP8_DECODER_DISABLE_BMSK                                                0x8000
#define HWIO_FEATURE_CONFIG0_VP8_DECODER_DISABLE_SHFT                                                   0xf
#define HWIO_FEATURE_CONFIG0_VP8_ENCODER_DISABLE_BMSK                                                0x4000
#define HWIO_FEATURE_CONFIG0_VP8_ENCODER_DISABLE_SHFT                                                   0xe
#define HWIO_FEATURE_CONFIG0_HDMI_DP_DISABLE_BMSK                                                    0x2000
#define HWIO_FEATURE_CONFIG0_HDMI_DP_DISABLE_SHFT                                                       0xd
#define HWIO_FEATURE_CONFIG0_HDCP_DISABLE_BMSK                                                       0x1000
#define HWIO_FEATURE_CONFIG0_HDCP_DISABLE_SHFT                                                          0xc
#define HWIO_FEATURE_CONFIG0_MDP_APICAL_LTC_DISABLE_BMSK                                              0x800
#define HWIO_FEATURE_CONFIG0_MDP_APICAL_LTC_DISABLE_SHFT                                                0xb
#define HWIO_FEATURE_CONFIG0_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                                      0x400
#define HWIO_FEATURE_CONFIG0_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                                        0xa
#define HWIO_FEATURE_CONFIG0_DSI_1_DISABLE_BMSK                                                       0x200
#define HWIO_FEATURE_CONFIG0_DSI_1_DISABLE_SHFT                                                         0x9
#define HWIO_FEATURE_CONFIG0_USB2_DISABLE_BMSK                                                        0x100
#define HWIO_FEATURE_CONFIG0_USB2_DISABLE_SHFT                                                          0x8
#define HWIO_FEATURE_CONFIG0_FD_DISABLE_BMSK                                                           0x80
#define HWIO_FEATURE_CONFIG0_FD_DISABLE_SHFT                                                            0x7
#define HWIO_FEATURE_CONFIG0_CSID_DPCM_14_DISABLE_BMSK                                                 0x40
#define HWIO_FEATURE_CONFIG0_CSID_DPCM_14_DISABLE_SHFT                                                  0x6
#define HWIO_FEATURE_CONFIG0_ISP_1_DISABLE_BMSK                                                        0x20
#define HWIO_FEATURE_CONFIG0_ISP_1_DISABLE_SHFT                                                         0x5
#define HWIO_FEATURE_CONFIG0_CSID_3_DISABLE_BMSK                                                       0x10
#define HWIO_FEATURE_CONFIG0_CSID_3_DISABLE_SHFT                                                        0x4
#define HWIO_FEATURE_CONFIG0_CSID_2_DISABLE_BMSK                                                        0x8
#define HWIO_FEATURE_CONFIG0_CSID_2_DISABLE_SHFT                                                        0x3
#define HWIO_FEATURE_CONFIG0_BOOT_ROM_PATCH_DISABLE_BMSK                                                0x7
#define HWIO_FEATURE_CONFIG0_BOOT_ROM_PATCH_DISABLE_SHFT                                                0x0

#define HWIO_FEATURE_CONFIG1_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006008)
#define HWIO_FEATURE_CONFIG1_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG1_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG1_ADDR, HWIO_FEATURE_CONFIG1_RMSK)
#define HWIO_FEATURE_CONFIG1_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG1_ADDR, m)
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY1_BMSK                                              0x80000000
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY1_SHFT                                                    0x1f
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY0_BMSK                                              0x40000000
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY0_SHFT                                                    0x1e
#define HWIO_FEATURE_CONFIG1_ICE_DISABLE_BMSK                                                    0x20000000
#define HWIO_FEATURE_CONFIG1_ICE_DISABLE_SHFT                                                          0x1d
#define HWIO_FEATURE_CONFIG1_RICA_DISABLE_BMSK                                                   0x10000000
#define HWIO_FEATURE_CONFIG1_RICA_DISABLE_SHFT                                                         0x1c
#define HWIO_FEATURE_CONFIG1_SPI_SLAVE_DISABLE_BMSK                                               0x8000000
#define HWIO_FEATURE_CONFIG1_SPI_SLAVE_DISABLE_SHFT                                                    0x1b
#define HWIO_FEATURE_CONFIG1_LPASS_SENSOR_DISABLE_BMSK                                            0x4000000
#define HWIO_FEATURE_CONFIG1_LPASS_SENSOR_DISABLE_SHFT                                                 0x1a
#define HWIO_FEATURE_CONFIG1_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_BMSK                                0x2000000
#define HWIO_FEATURE_CONFIG1_LPASS_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                                     0x19
#define HWIO_FEATURE_CONFIG1_LPASS_SW_ISLAND_MODE_DISABLE_BMSK                                    0x1000000
#define HWIO_FEATURE_CONFIG1_LPASS_SW_ISLAND_MODE_DISABLE_SHFT                                         0x18
#define HWIO_FEATURE_CONFIG1_LPASS_EFUSE_TESTBUS_READ_DISABLE_BMSK                                 0x800000
#define HWIO_FEATURE_CONFIG1_LPASS_EFUSE_TESTBUS_READ_DISABLE_SHFT                                     0x17
#define HWIO_FEATURE_CONFIG1_APS_RESET_DISABLE_BMSK                                                0x400000
#define HWIO_FEATURE_CONFIG1_APS_RESET_DISABLE_SHFT                                                    0x16
#define HWIO_FEATURE_CONFIG1_HVX_DISABLE_BMSK                                                      0x200000
#define HWIO_FEATURE_CONFIG1_HVX_DISABLE_SHFT                                                          0x15
#define HWIO_FEATURE_CONFIG1_APB2JTAG_DISABLE_BMSK                                                 0x100000
#define HWIO_FEATURE_CONFIG1_APB2JTAG_DISABLE_SHFT                                                     0x14
#define HWIO_FEATURE_CONFIG1_WDOG_BOOT_CLUSTER_SELECT_BMSK                                          0x80000
#define HWIO_FEATURE_CONFIG1_WDOG_BOOT_CLUSTER_SELECT_SHFT                                             0x13
#define HWIO_FEATURE_CONFIG1_STACKED_MEMORY_ID_BMSK                                                 0x7c000
#define HWIO_FEATURE_CONFIG1_STACKED_MEMORY_ID_SHFT                                                     0xe
#define HWIO_FEATURE_CONFIG1_PRNG_TESTMODE_DISABLE_BMSK                                              0x2000
#define HWIO_FEATURE_CONFIG1_PRNG_TESTMODE_DISABLE_SHFT                                                 0xd
#define HWIO_FEATURE_CONFIG1_CDSP_DISABLE_BMSK                                                       0x1000
#define HWIO_FEATURE_CONFIG1_CDSP_DISABLE_SHFT                                                          0xc
#define HWIO_FEATURE_CONFIG1_MOCHA_PART_BMSK                                                          0x800
#define HWIO_FEATURE_CONFIG1_MOCHA_PART_SHFT                                                            0xb
#define HWIO_FEATURE_CONFIG1_NIDNT_DISABLE_BMSK                                                       0x400
#define HWIO_FEATURE_CONFIG1_NIDNT_DISABLE_SHFT                                                         0xa
#define HWIO_FEATURE_CONFIG1_SMMU_DISABLE_BMSK                                                        0x200
#define HWIO_FEATURE_CONFIG1_SMMU_DISABLE_SHFT                                                          0x9
#define HWIO_FEATURE_CONFIG1_VENDOR_LOCK_BMSK                                                         0x1e0
#define HWIO_FEATURE_CONFIG1_VENDOR_LOCK_SHFT                                                           0x5
#define HWIO_FEATURE_CONFIG1_CM_FEAT_CONFIG_DISABLE_BMSK                                               0x10
#define HWIO_FEATURE_CONFIG1_CM_FEAT_CONFIG_DISABLE_SHFT                                                0x4
#define HWIO_FEATURE_CONFIG1_VFE_RESOLUTION_LIMIT_BMSK                                                  0x8
#define HWIO_FEATURE_CONFIG1_VFE_RESOLUTION_LIMIT_SHFT                                                  0x3
#define HWIO_FEATURE_CONFIG1_VP9_DECODER_DISABLE_BMSK                                                   0x4
#define HWIO_FEATURE_CONFIG1_VP9_DECODER_DISABLE_SHFT                                                   0x2
#define HWIO_FEATURE_CONFIG1_LPASS_SVA_DISABLE_BMSK                                                     0x2
#define HWIO_FEATURE_CONFIG1_LPASS_SVA_DISABLE_SHFT                                                     0x1
#define HWIO_FEATURE_CONFIG1_BOOT_CUSTER_SELECT_BMSK                                                    0x1
#define HWIO_FEATURE_CONFIG1_BOOT_CUSTER_SELECT_SHFT                                                    0x0

#define HWIO_FEATURE_CONFIG2_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000600c)
#define HWIO_FEATURE_CONFIG2_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG2_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG2_ADDR, HWIO_FEATURE_CONFIG2_RMSK)
#define HWIO_FEATURE_CONFIG2_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG2_ADDR, m)
#define HWIO_FEATURE_CONFIG2_MDSP_FW_DISABLE_BMSK                                                0xfff00000
#define HWIO_FEATURE_CONFIG2_MDSP_FW_DISABLE_SHFT                                                      0x14
#define HWIO_FEATURE_CONFIG2_MODEM_GLOBAL_DISABLE_BMSK                                              0x80000
#define HWIO_FEATURE_CONFIG2_MODEM_GLOBAL_DISABLE_SHFT                                                 0x13
#define HWIO_FEATURE_CONFIG2_NAV_DISABLE_BMSK                                                       0x40000
#define HWIO_FEATURE_CONFIG2_NAV_DISABLE_SHFT                                                          0x12
#define HWIO_FEATURE_CONFIG2_SYS_APCCCFGNMFI_BMSK                                                   0x20000
#define HWIO_FEATURE_CONFIG2_SYS_APCCCFGNMFI_SHFT                                                      0x11
#define HWIO_FEATURE_CONFIG2_BOOT_CORE_SELECT_BMSK                                                  0x18000
#define HWIO_FEATURE_CONFIG2_BOOT_CORE_SELECT_SHFT                                                      0xf
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SPARE_BMSK                                        0x7fe0
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SPARE_SHFT                                           0x5
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SLICE_BMSK                                          0x1f
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SLICE_SHFT                                           0x0

#define HWIO_FEATURE_CONFIG3_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006010)
#define HWIO_FEATURE_CONFIG3_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG3_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG3_ADDR, HWIO_FEATURE_CONFIG3_RMSK)
#define HWIO_FEATURE_CONFIG3_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG3_ADDR, m)
#define HWIO_FEATURE_CONFIG3_SYS_APCX_SYSBARDISABLE_BMSK                                         0x80000000
#define HWIO_FEATURE_CONFIG3_SYS_APCX_SYSBARDISABLE_SHFT                                               0x1f
#define HWIO_FEATURE_CONFIG3_SYS_APCSCFGAPMBOOTONMX_BMSK                                         0x60000000
#define HWIO_FEATURE_CONFIG3_SYS_APCSCFGAPMBOOTONMX_SHFT                                               0x1d
#define HWIO_FEATURE_CONFIG3_SYS_APCCCFGCPUPRESENT_N_BMSK                                        0x1fe00000
#define HWIO_FEATURE_CONFIG3_SYS_APCCCFGCPUPRESENT_N_SHFT                                              0x15
#define HWIO_FEATURE_CONFIG3_APPS_ACG_DISABLE_BMSK                                                 0x100000
#define HWIO_FEATURE_CONFIG3_APPS_ACG_DISABLE_SHFT                                                     0x14
#define HWIO_FEATURE_CONFIG3_RSVD1_BMSK                                                             0xf0000
#define HWIO_FEATURE_CONFIG3_RSVD1_SHFT                                                                0x10
#define HWIO_FEATURE_CONFIG3_MODEM_VU_DISABLE_BMSK                                                   0xffff
#define HWIO_FEATURE_CONFIG3_MODEM_VU_DISABLE_SHFT                                                      0x0

#define HWIO_FEATURE_CONFIG4_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006014)
#define HWIO_FEATURE_CONFIG4_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG4_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG4_ADDR, HWIO_FEATURE_CONFIG4_RMSK)
#define HWIO_FEATURE_CONFIG4_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG4_ADDR, m)
#define HWIO_FEATURE_CONFIG4_QC_APPS_SPNIDEN_DISABLE_BMSK                                        0x80000000
#define HWIO_FEATURE_CONFIG4_QC_APPS_SPNIDEN_DISABLE_SHFT                                              0x1f
#define HWIO_FEATURE_CONFIG4_QC_MSS_NIDEN_DISABLE_BMSK                                           0x40000000
#define HWIO_FEATURE_CONFIG4_QC_MSS_NIDEN_DISABLE_SHFT                                                 0x1e
#define HWIO_FEATURE_CONFIG4_QC_LPASS_SENSOR_NIDEN_DISABLE_BMSK                                  0x20000000
#define HWIO_FEATURE_CONFIG4_QC_LPASS_SENSOR_NIDEN_DISABLE_SHFT                                        0x1d
#define HWIO_FEATURE_CONFIG4_QC_PIMEM_NIDEN_DISABLE_BMSK                                         0x10000000
#define HWIO_FEATURE_CONFIG4_QC_PIMEM_NIDEN_DISABLE_SHFT                                               0x1c
#define HWIO_FEATURE_CONFIG4_QC_RPM_NIDEN_DISABLE_BMSK                                            0x8000000
#define HWIO_FEATURE_CONFIG4_QC_RPM_NIDEN_DISABLE_SHFT                                                 0x1b
#define HWIO_FEATURE_CONFIG4_QC_WCSS_NIDEN_DISABLE_BMSK                                           0x4000000
#define HWIO_FEATURE_CONFIG4_QC_WCSS_NIDEN_DISABLE_SHFT                                                0x1a
#define HWIO_FEATURE_CONFIG4_QC_LPASS_NIDEN_DISABLE_BMSK                                          0x2000000
#define HWIO_FEATURE_CONFIG4_QC_LPASS_NIDEN_DISABLE_SHFT                                               0x19
#define HWIO_FEATURE_CONFIG4_QC_DAP_NIDEN_DISABLE_BMSK                                            0x1000000
#define HWIO_FEATURE_CONFIG4_QC_DAP_NIDEN_DISABLE_SHFT                                                 0x18
#define HWIO_FEATURE_CONFIG4_QC_APPS_NIDEN_DISABLE_BMSK                                            0x800000
#define HWIO_FEATURE_CONFIG4_QC_APPS_NIDEN_DISABLE_SHFT                                                0x17
#define HWIO_FEATURE_CONFIG4_QC_MSS_DBGEN_DISABLE_BMSK                                             0x400000
#define HWIO_FEATURE_CONFIG4_QC_MSS_DBGEN_DISABLE_SHFT                                                 0x16
#define HWIO_FEATURE_CONFIG4_QC_A5X_ISDB_DBGEN_DISABLE_BMSK                                        0x200000
#define HWIO_FEATURE_CONFIG4_QC_A5X_ISDB_DBGEN_DISABLE_SHFT                                            0x15
#define HWIO_FEATURE_CONFIG4_QC_VENUS_0_DBGEN_DISABLE_BMSK                                         0x100000
#define HWIO_FEATURE_CONFIG4_QC_VENUS_0_DBGEN_DISABLE_SHFT                                             0x14
#define HWIO_FEATURE_CONFIG4_TURING_EFUSE_TESTBUS_READ_DISABLE_BMSK                                 0x80000
#define HWIO_FEATURE_CONFIG4_TURING_EFUSE_TESTBUS_READ_DISABLE_SHFT                                    0x13
#define HWIO_FEATURE_CONFIG4_QC_LPASS_SENSOR_DBGEN_DISABLE_BMSK                                     0x40000
#define HWIO_FEATURE_CONFIG4_QC_LPASS_SENSOR_DBGEN_DISABLE_SHFT                                        0x12
#define HWIO_FEATURE_CONFIG4_QC_PIMEM_DBGEN_DISABLE_BMSK                                            0x20000
#define HWIO_FEATURE_CONFIG4_QC_PIMEM_DBGEN_DISABLE_SHFT                                               0x11
#define HWIO_FEATURE_CONFIG4_QC_RPM_DBGEN_DISABLE_BMSK                                              0x10000
#define HWIO_FEATURE_CONFIG4_QC_RPM_DBGEN_DISABLE_SHFT                                                 0x10
#define HWIO_FEATURE_CONFIG4_QC_WCSS_DBGEN_DISABLE_BMSK                                              0x8000
#define HWIO_FEATURE_CONFIG4_QC_WCSS_DBGEN_DISABLE_SHFT                                                 0xf
#define HWIO_FEATURE_CONFIG4_QC_LPASS_Q6_DBGEN_DISABLE_BMSK                                          0x4000
#define HWIO_FEATURE_CONFIG4_QC_LPASS_Q6_DBGEN_DISABLE_SHFT                                             0xe
#define HWIO_FEATURE_CONFIG4_QC_DAP_DBGEN_DISABLE_BMSK                                               0x2000
#define HWIO_FEATURE_CONFIG4_QC_DAP_DBGEN_DISABLE_SHFT                                                  0xd
#define HWIO_FEATURE_CONFIG4_QC_APPS_DBGEN_DISABLE_BMSK                                              0x1000
#define HWIO_FEATURE_CONFIG4_QC_APPS_DBGEN_DISABLE_SHFT                                                 0xc
#define HWIO_FEATURE_CONFIG4_QC_DAP_DEVICEEN_DISABLE_BMSK                                             0x800
#define HWIO_FEATURE_CONFIG4_QC_DAP_DEVICEEN_DISABLE_SHFT                                               0xb
#define HWIO_FEATURE_CONFIG4_QC_RPM_DAPEN_DISABLE_BMSK                                                0x400
#define HWIO_FEATURE_CONFIG4_QC_RPM_DAPEN_DISABLE_SHFT                                                  0xa
#define HWIO_FEATURE_CONFIG4_RSVD0_BMSK                                                               0x200
#define HWIO_FEATURE_CONFIG4_RSVD0_SHFT                                                                 0x9
#define HWIO_FEATURE_CONFIG4_QC_DEBUG_BUS_DISABLE_BMSK                                                0x100
#define HWIO_FEATURE_CONFIG4_QC_DEBUG_BUS_DISABLE_SHFT                                                  0x8
#define HWIO_FEATURE_CONFIG4_QC_DCC_DEBUG_DISABLE_BMSK                                                 0x80
#define HWIO_FEATURE_CONFIG4_QC_DCC_DEBUG_DISABLE_SHFT                                                  0x7
#define HWIO_FEATURE_CONFIG4_QC_APPS_APB_DFD_DISABLE_BMSK                                              0x40
#define HWIO_FEATURE_CONFIG4_QC_APPS_APB_DFD_DISABLE_SHFT                                               0x6
#define HWIO_FEATURE_CONFIG4_QC_GPMU_NIDEN_DISABLE_BMSK                                                0x20
#define HWIO_FEATURE_CONFIG4_QC_GPMU_NIDEN_DISABLE_SHFT                                                 0x5
#define HWIO_FEATURE_CONFIG4_QC_GPMU_DBGEN_DISABLE_BMSK                                                0x10
#define HWIO_FEATURE_CONFIG4_QC_GPMU_DBGEN_DISABLE_SHFT                                                 0x4
#define HWIO_FEATURE_CONFIG4_QC_GPMU_DAPEN_DISABLE_BMSK                                                 0x8
#define HWIO_FEATURE_CONFIG4_QC_GPMU_DAPEN_DISABLE_SHFT                                                 0x3
#define HWIO_FEATURE_CONFIG4_QDI_SPMI_DISABLE_BMSK                                                      0x4
#define HWIO_FEATURE_CONFIG4_QDI_SPMI_DISABLE_SHFT                                                      0x2
#define HWIO_FEATURE_CONFIG4_SM_BIST_DISABLE_BMSK                                                       0x2
#define HWIO_FEATURE_CONFIG4_SM_BIST_DISABLE_SHFT                                                       0x1
#define HWIO_FEATURE_CONFIG4_TIC_DISABLE_BMSK                                                           0x1
#define HWIO_FEATURE_CONFIG4_TIC_DISABLE_SHFT                                                           0x0

#define HWIO_FEATURE_CONFIG5_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006018)
#define HWIO_FEATURE_CONFIG5_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG5_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG5_ADDR, HWIO_FEATURE_CONFIG5_RMSK)
#define HWIO_FEATURE_CONFIG5_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG5_ADDR, m)
#define HWIO_FEATURE_CONFIG5_SYS_APCCCFGEND_BMSK                                                 0x80000000
#define HWIO_FEATURE_CONFIG5_SYS_APCCCFGEND_SHFT                                                       0x1f
#define HWIO_FEATURE_CONFIG5_SYS_APCCCP15SDISABLE_BMSK                                           0x40000000
#define HWIO_FEATURE_CONFIG5_SYS_APCCCP15SDISABLE_SHFT                                                 0x1e
#define HWIO_FEATURE_CONFIG5_SYS_APCCCFGTE_BMSK                                                  0x20000000
#define HWIO_FEATURE_CONFIG5_SYS_APCCCFGTE_SHFT                                                        0x1d
#define HWIO_FEATURE_CONFIG5_SILVER_PLL_MAX_FREQ_LVAL_BMSK                                       0x1fe00000
#define HWIO_FEATURE_CONFIG5_SILVER_PLL_MAX_FREQ_LVAL_SHFT                                             0x15
#define HWIO_FEATURE_CONFIG5_APPS_BOOT_FSM_FUSE_BMSK                                               0x1c0000
#define HWIO_FEATURE_CONFIG5_APPS_BOOT_FSM_FUSE_SHFT                                                   0x12
#define HWIO_FEATURE_CONFIG5_GOLD_PLL_MAX_FREQ_LVAL_BMSK                                            0x3fc00
#define HWIO_FEATURE_CONFIG5_GOLD_PLL_MAX_FREQ_LVAL_SHFT                                                0xa
#define HWIO_FEATURE_CONFIG5_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_BMSK                                    0x200
#define HWIO_FEATURE_CONFIG5_QC_A5X_ISDB_SECURE_DBGEN_DISABLE_SHFT                                      0x9
#define HWIO_FEATURE_CONFIG5_QC_LPASS_SPIDEN_DISABLE_BMSK                                             0x100
#define HWIO_FEATURE_CONFIG5_QC_LPASS_SPIDEN_DISABLE_SHFT                                               0x8
#define HWIO_FEATURE_CONFIG5_QC_PIMEM_SPIDEN_DISABLE_BMSK                                              0x80
#define HWIO_FEATURE_CONFIG5_QC_PIMEM_SPIDEN_DISABLE_SHFT                                               0x7
#define HWIO_FEATURE_CONFIG5_QC_WCSS_SPIDEN_DISABLE_BMSK                                               0x40
#define HWIO_FEATURE_CONFIG5_QC_WCSS_SPIDEN_DISABLE_SHFT                                                0x6
#define HWIO_FEATURE_CONFIG5_QC_DAP_SPIDEN_DISABLE_BMSK                                                0x20
#define HWIO_FEATURE_CONFIG5_QC_DAP_SPIDEN_DISABLE_SHFT                                                 0x5
#define HWIO_FEATURE_CONFIG5_QC_APPS_SPIDEN_DISABLE_BMSK                                               0x10
#define HWIO_FEATURE_CONFIG5_QC_APPS_SPIDEN_DISABLE_SHFT                                                0x4
#define HWIO_FEATURE_CONFIG5_QC_LPASS_SPNIDEN_DISABLE_BMSK                                              0x8
#define HWIO_FEATURE_CONFIG5_QC_LPASS_SPNIDEN_DISABLE_SHFT                                              0x3
#define HWIO_FEATURE_CONFIG5_QC_PIMEM_SPNIDEN_DISABLE_BMSK                                              0x4
#define HWIO_FEATURE_CONFIG5_QC_PIMEM_SPNIDEN_DISABLE_SHFT                                              0x2
#define HWIO_FEATURE_CONFIG5_QC_WCSS_SPNIDEN_DISABLE_BMSK                                               0x2
#define HWIO_FEATURE_CONFIG5_QC_WCSS_SPNIDEN_DISABLE_SHFT                                               0x1
#define HWIO_FEATURE_CONFIG5_QC_DAP_SPNIDEN_DISABLE_BMSK                                                0x1
#define HWIO_FEATURE_CONFIG5_QC_DAP_SPNIDEN_DISABLE_SHFT                                                0x0

#define HWIO_FEATURE_CONFIG6_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000601c)
#define HWIO_FEATURE_CONFIG6_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG6_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG6_ADDR, HWIO_FEATURE_CONFIG6_RMSK)
#define HWIO_FEATURE_CONFIG6_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG6_ADDR, m)
#define HWIO_FEATURE_CONFIG6_TAP_GEN_SPARE_INSTR_DISABLE_13_0_BMSK                               0xfffc0000
#define HWIO_FEATURE_CONFIG6_TAP_GEN_SPARE_INSTR_DISABLE_13_0_SHFT                                     0x12
#define HWIO_FEATURE_CONFIG6_TAP_INSTR_DISABLE_BMSK                                                 0x3ffff
#define HWIO_FEATURE_CONFIG6_TAP_INSTR_DISABLE_SHFT                                                     0x0

#define HWIO_FEATURE_CONFIG7_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006020)
#define HWIO_FEATURE_CONFIG7_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG7_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG7_ADDR, HWIO_FEATURE_CONFIG7_RMSK)
#define HWIO_FEATURE_CONFIG7_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG7_ADDR, m)
#define HWIO_FEATURE_CONFIG7_SEC_TAP_ACCESS_DISABLE_BMSK                                         0xfffc0000
#define HWIO_FEATURE_CONFIG7_SEC_TAP_ACCESS_DISABLE_SHFT                                               0x12
#define HWIO_FEATURE_CONFIG7_TAP_GEN_SPARE_INSTR_DISABLE_31_14_BMSK                                 0x3ffff
#define HWIO_FEATURE_CONFIG7_TAP_GEN_SPARE_INSTR_DISABLE_31_14_SHFT                                     0x0

#define HWIO_FEATURE_CONFIG8_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006024)
#define HWIO_FEATURE_CONFIG8_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG8_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG8_ADDR, HWIO_FEATURE_CONFIG8_RMSK)
#define HWIO_FEATURE_CONFIG8_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG8_ADDR, m)
#define HWIO_FEATURE_CONFIG8_MODEM_PBL_PATCH_VERSION_BMSK                                        0xfe000000
#define HWIO_FEATURE_CONFIG8_MODEM_PBL_PATCH_VERSION_SHFT                                              0x19
#define HWIO_FEATURE_CONFIG8_APPS_PBL_PATCH_VERSION_BMSK                                          0x1fc0000
#define HWIO_FEATURE_CONFIG8_APPS_PBL_PATCH_VERSION_SHFT                                               0x12
#define HWIO_FEATURE_CONFIG8_APPS_PBL_BOOT_SPEED_BMSK                                               0x30000
#define HWIO_FEATURE_CONFIG8_APPS_PBL_BOOT_SPEED_SHFT                                                  0x10
#define HWIO_FEATURE_CONFIG8_MODEM_PBL_BOOT_BMSK                                                     0x8000
#define HWIO_FEATURE_CONFIG8_MODEM_PBL_BOOT_SHFT                                                        0xf
#define HWIO_FEATURE_CONFIG8_RSVD1_BMSK                                                              0x4000
#define HWIO_FEATURE_CONFIG8_RSVD1_SHFT                                                                 0xe
#define HWIO_FEATURE_CONFIG8_APPS_BOOT_FROM_ROM_BMSK                                                 0x2000
#define HWIO_FEATURE_CONFIG8_APPS_BOOT_FROM_ROM_SHFT                                                    0xd
#define HWIO_FEATURE_CONFIG8_RSVD0_BMSK                                                              0x1000
#define HWIO_FEATURE_CONFIG8_RSVD0_SHFT                                                                 0xc
#define HWIO_FEATURE_CONFIG8_MODEM_BOOT_FROM_ROM_BMSK                                                 0x800
#define HWIO_FEATURE_CONFIG8_MODEM_BOOT_FROM_ROM_SHFT                                                   0xb
#define HWIO_FEATURE_CONFIG8_MSA_ENA_BMSK                                                             0x400
#define HWIO_FEATURE_CONFIG8_MSA_ENA_SHFT                                                               0xa
#define HWIO_FEATURE_CONFIG8_FORCE_MSA_AUTH_EN_BMSK                                                   0x200
#define HWIO_FEATURE_CONFIG8_FORCE_MSA_AUTH_EN_SHFT                                                     0x9
#define HWIO_FEATURE_CONFIG8_ARM_CE_DISABLE_USAGE_BMSK                                                0x100
#define HWIO_FEATURE_CONFIG8_ARM_CE_DISABLE_USAGE_SHFT                                                  0x8
#define HWIO_FEATURE_CONFIG8_BOOT_ROM_CFG_BMSK                                                         0xff
#define HWIO_FEATURE_CONFIG8_BOOT_ROM_CFG_SHFT                                                          0x0

#define HWIO_FEATURE_CONFIG9_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006028)
#define HWIO_FEATURE_CONFIG9_RMSK                                                                0xffffffff
#define HWIO_FEATURE_CONFIG9_IN          \
        in_dword_masked(HWIO_FEATURE_CONFIG9_ADDR, HWIO_FEATURE_CONFIG9_RMSK)
#define HWIO_FEATURE_CONFIG9_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG9_ADDR, m)
#define HWIO_FEATURE_CONFIG9_APPS_BOOT_TRIGGER_DISABLE_BMSK                                      0x80000000
#define HWIO_FEATURE_CONFIG9_APPS_BOOT_TRIGGER_DISABLE_SHFT                                            0x1f
#define HWIO_FEATURE_CONFIG9_PBL_QSEE_BOOT_FLOW_DISABLE_BMSK                                     0x40000000
#define HWIO_FEATURE_CONFIG9_PBL_QSEE_BOOT_FLOW_DISABLE_SHFT                                           0x1e
#define HWIO_FEATURE_CONFIG9_XBL_SEC_AUTH_DISABLE_BMSK                                           0x20000000
#define HWIO_FEATURE_CONFIG9_XBL_SEC_AUTH_DISABLE_SHFT                                                 0x1d
#define HWIO_FEATURE_CONFIG9_MSM_PKG_TYPE_BMSK                                                   0x10000000
#define HWIO_FEATURE_CONFIG9_MSM_PKG_TYPE_SHFT                                                         0x1c
#define HWIO_FEATURE_CONFIG9_RSVD3_BMSK                                                           0xffc0000
#define HWIO_FEATURE_CONFIG9_RSVD3_SHFT                                                                0x12
#define HWIO_FEATURE_CONFIG9_FOUNDRY_ID_BMSK                                                        0x3c000
#define HWIO_FEATURE_CONFIG9_FOUNDRY_ID_SHFT                                                            0xe
#define HWIO_FEATURE_CONFIG9_PLL_CFG_BMSK                                                            0x3ff0
#define HWIO_FEATURE_CONFIG9_PLL_CFG_SHFT                                                               0x4
#define HWIO_FEATURE_CONFIG9_APPS_PBL_PLL_CTRL_BMSK                                                     0xf
#define HWIO_FEATURE_CONFIG9_APPS_PBL_PLL_CTRL_SHFT                                                     0x0

#define HWIO_OEM_CONFIG0_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006040)
#define HWIO_OEM_CONFIG0_RMSK                                                                    0xffffffff
#define HWIO_OEM_CONFIG0_IN          \
        in_dword_masked(HWIO_OEM_CONFIG0_ADDR, HWIO_OEM_CONFIG0_RMSK)
#define HWIO_OEM_CONFIG0_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG0_ADDR, m)
#define HWIO_OEM_CONFIG0_DCC_DEBUG_DISABLE_BMSK                                                  0x80000000
#define HWIO_OEM_CONFIG0_DCC_DEBUG_DISABLE_SHFT                                                        0x1f
#define HWIO_OEM_CONFIG0_APPS_APB_DFD_DISABLE_BMSK                                               0x40000000
#define HWIO_OEM_CONFIG0_APPS_APB_DFD_DISABLE_SHFT                                                     0x1e
#define HWIO_OEM_CONFIG0_ALL_DEBUG_DISABLE_BMSK                                                  0x20000000
#define HWIO_OEM_CONFIG0_ALL_DEBUG_DISABLE_SHFT                                                        0x1d
#define HWIO_OEM_CONFIG0_DEBUG_POLICY_DISABLE_BMSK                                               0x10000000
#define HWIO_OEM_CONFIG0_DEBUG_POLICY_DISABLE_SHFT                                                     0x1c
#define HWIO_OEM_CONFIG0_RSVD2_BMSK                                                               0xe000000
#define HWIO_OEM_CONFIG0_RSVD2_SHFT                                                                    0x19
#define HWIO_OEM_CONFIG0_MSS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                                    0x1000000
#define HWIO_OEM_CONFIG0_MSS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                                         0x18
#define HWIO_OEM_CONFIG0_APPS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                                    0x800000
#define HWIO_OEM_CONFIG0_APPS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                                        0x17
#define HWIO_OEM_CONFIG0_USB_SS_DISABLE_BMSK                                                       0x400000
#define HWIO_OEM_CONFIG0_USB_SS_DISABLE_SHFT                                                           0x16
#define HWIO_OEM_CONFIG0_SW_ROT_USE_SERIAL_NUM_BMSK                                                0x200000
#define HWIO_OEM_CONFIG0_SW_ROT_USE_SERIAL_NUM_SHFT                                                    0x15
#define HWIO_OEM_CONFIG0_DISABLE_ROT_TRANSFER_BMSK                                                 0x100000
#define HWIO_OEM_CONFIG0_DISABLE_ROT_TRANSFER_SHFT                                                     0x14
#define HWIO_OEM_CONFIG0_IMAGE_ENCRYPTION_ENABLE_BMSK                                               0x80000
#define HWIO_OEM_CONFIG0_IMAGE_ENCRYPTION_ENABLE_SHFT                                                  0x13
#define HWIO_OEM_CONFIG0_RSVD1_BMSK                                                                 0x60000
#define HWIO_OEM_CONFIG0_RSVD1_SHFT                                                                    0x11
#define HWIO_OEM_CONFIG0_PBL_USB_TYPE_C_DISABLE_BMSK                                                0x10000
#define HWIO_OEM_CONFIG0_PBL_USB_TYPE_C_DISABLE_SHFT                                                   0x10
#define HWIO_OEM_CONFIG0_PBL_LOG_DISABLE_BMSK                                                        0x8000
#define HWIO_OEM_CONFIG0_PBL_LOG_DISABLE_SHFT                                                           0xf
#define HWIO_OEM_CONFIG0_WDOG_EN_BMSK                                                                0x4000
#define HWIO_OEM_CONFIG0_WDOG_EN_SHFT                                                                   0xe
#define HWIO_OEM_CONFIG0_SPDM_SECURE_MODE_BMSK                                                       0x2000
#define HWIO_OEM_CONFIG0_SPDM_SECURE_MODE_SHFT                                                          0xd
#define HWIO_OEM_CONFIG0_SW_FUSE_PROG_DISABLE_BMSK                                                   0x1000
#define HWIO_OEM_CONFIG0_SW_FUSE_PROG_DISABLE_SHFT                                                      0xc
#define HWIO_OEM_CONFIG0_RSVD0_BMSK                                                                   0xc00
#define HWIO_OEM_CONFIG0_RSVD0_SHFT                                                                     0xa
#define HWIO_OEM_CONFIG0_FAST_BOOT_BMSK                                                               0x3e0
#define HWIO_OEM_CONFIG0_FAST_BOOT_SHFT                                                                 0x5
#define HWIO_OEM_CONFIG0_SDCC_MCLK_BOOT_FREQ_BMSK                                                      0x10
#define HWIO_OEM_CONFIG0_SDCC_MCLK_BOOT_FREQ_SHFT                                                       0x4
#define HWIO_OEM_CONFIG0_FORCE_USB_BOOT_DISABLE_BMSK                                                    0x8
#define HWIO_OEM_CONFIG0_FORCE_USB_BOOT_DISABLE_SHFT                                                    0x3
#define HWIO_OEM_CONFIG0_FORCE_DLOAD_DISABLE_BMSK                                                       0x4
#define HWIO_OEM_CONFIG0_FORCE_DLOAD_DISABLE_SHFT                                                       0x2
#define HWIO_OEM_CONFIG0_ENUM_TIMEOUT_BMSK                                                              0x2
#define HWIO_OEM_CONFIG0_ENUM_TIMEOUT_SHFT                                                              0x1
#define HWIO_OEM_CONFIG0_E_DLOAD_DISABLE_BMSK                                                           0x1
#define HWIO_OEM_CONFIG0_E_DLOAD_DISABLE_SHFT                                                           0x0

#define HWIO_OEM_CONFIG1_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006044)
#define HWIO_OEM_CONFIG1_RMSK                                                                    0xffffffff
#define HWIO_OEM_CONFIG1_IN          \
        in_dword_masked(HWIO_OEM_CONFIG1_ADDR, HWIO_OEM_CONFIG1_RMSK)
#define HWIO_OEM_CONFIG1_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG1_ADDR, m)
#define HWIO_OEM_CONFIG1_PIMEM_SPIDEN_DISABLE_BMSK                                               0x80000000
#define HWIO_OEM_CONFIG1_PIMEM_SPIDEN_DISABLE_SHFT                                                     0x1f
#define HWIO_OEM_CONFIG1_WCSS_SPIDEN_DISABLE_BMSK                                                0x40000000
#define HWIO_OEM_CONFIG1_WCSS_SPIDEN_DISABLE_SHFT                                                      0x1e
#define HWIO_OEM_CONFIG1_DAP_SPIDEN_DISABLE_BMSK                                                 0x20000000
#define HWIO_OEM_CONFIG1_DAP_SPIDEN_DISABLE_SHFT                                                       0x1d
#define HWIO_OEM_CONFIG1_APPS_SPIDEN_DISABLE_BMSK                                                0x10000000
#define HWIO_OEM_CONFIG1_APPS_SPIDEN_DISABLE_SHFT                                                      0x1c
#define HWIO_OEM_CONFIG1_LPASS_SPNIDEN_DISABLE_BMSK                                               0x8000000
#define HWIO_OEM_CONFIG1_LPASS_SPNIDEN_DISABLE_SHFT                                                    0x1b
#define HWIO_OEM_CONFIG1_PIMEM_SPNIDEN_DISABLE_BMSK                                               0x4000000
#define HWIO_OEM_CONFIG1_PIMEM_SPNIDEN_DISABLE_SHFT                                                    0x1a
#define HWIO_OEM_CONFIG1_WCSS_SPNIDEN_DISABLE_BMSK                                                0x2000000
#define HWIO_OEM_CONFIG1_WCSS_SPNIDEN_DISABLE_SHFT                                                     0x19
#define HWIO_OEM_CONFIG1_DAP_SPNIDEN_DISABLE_BMSK                                                 0x1000000
#define HWIO_OEM_CONFIG1_DAP_SPNIDEN_DISABLE_SHFT                                                      0x18
#define HWIO_OEM_CONFIG1_APPS_SPNIDEN_DISABLE_BMSK                                                 0x800000
#define HWIO_OEM_CONFIG1_APPS_SPNIDEN_DISABLE_SHFT                                                     0x17
#define HWIO_OEM_CONFIG1_MSS_NIDEN_DISABLE_BMSK                                                    0x400000
#define HWIO_OEM_CONFIG1_MSS_NIDEN_DISABLE_SHFT                                                        0x16
#define HWIO_OEM_CONFIG1_LPASS_SENSOR_NIDEN_DISABLE_BMSK                                           0x200000
#define HWIO_OEM_CONFIG1_LPASS_SENSOR_NIDEN_DISABLE_SHFT                                               0x15
#define HWIO_OEM_CONFIG1_PIMEM_NIDEN_DISABLE_BMSK                                                  0x100000
#define HWIO_OEM_CONFIG1_PIMEM_NIDEN_DISABLE_SHFT                                                      0x14
#define HWIO_OEM_CONFIG1_RPM_NIDEN_DISABLE_BMSK                                                     0x80000
#define HWIO_OEM_CONFIG1_RPM_NIDEN_DISABLE_SHFT                                                        0x13
#define HWIO_OEM_CONFIG1_WCSS_NIDEN_DISABLE_BMSK                                                    0x40000
#define HWIO_OEM_CONFIG1_WCSS_NIDEN_DISABLE_SHFT                                                       0x12
#define HWIO_OEM_CONFIG1_LPASS_NIDEN_DISABLE_BMSK                                                   0x20000
#define HWIO_OEM_CONFIG1_LPASS_NIDEN_DISABLE_SHFT                                                      0x11
#define HWIO_OEM_CONFIG1_DAP_NIDEN_DISABLE_BMSK                                                     0x10000
#define HWIO_OEM_CONFIG1_DAP_NIDEN_DISABLE_SHFT                                                        0x10
#define HWIO_OEM_CONFIG1_APPS_NIDEN_DISABLE_BMSK                                                     0x8000
#define HWIO_OEM_CONFIG1_APPS_NIDEN_DISABLE_SHFT                                                        0xf
#define HWIO_OEM_CONFIG1_MSS_DBGEN_DISABLE_BMSK                                                      0x4000
#define HWIO_OEM_CONFIG1_MSS_DBGEN_DISABLE_SHFT                                                         0xe
#define HWIO_OEM_CONFIG1_A5X_ISDB_DBGEN_DISABLE_BMSK                                                 0x2000
#define HWIO_OEM_CONFIG1_A5X_ISDB_DBGEN_DISABLE_SHFT                                                    0xd
#define HWIO_OEM_CONFIG1_VENUS_0_DBGEN_DISABLE_BMSK                                                  0x1000
#define HWIO_OEM_CONFIG1_VENUS_0_DBGEN_DISABLE_SHFT                                                     0xc
#define HWIO_OEM_CONFIG1_RSVD1_BMSK                                                                   0x800
#define HWIO_OEM_CONFIG1_RSVD1_SHFT                                                                     0xb
#define HWIO_OEM_CONFIG1_LPASS_SENSOR_DBGEN_DISABLE_BMSK                                              0x400
#define HWIO_OEM_CONFIG1_LPASS_SENSOR_DBGEN_DISABLE_SHFT                                                0xa
#define HWIO_OEM_CONFIG1_PIMEM_DBGEN_DISABLE_BMSK                                                     0x200
#define HWIO_OEM_CONFIG1_PIMEM_DBGEN_DISABLE_SHFT                                                       0x9
#define HWIO_OEM_CONFIG1_RPM_DBGEN_DISABLE_BMSK                                                       0x100
#define HWIO_OEM_CONFIG1_RPM_DBGEN_DISABLE_SHFT                                                         0x8
#define HWIO_OEM_CONFIG1_WCSS_DBGEN_DISABLE_BMSK                                                       0x80
#define HWIO_OEM_CONFIG1_WCSS_DBGEN_DISABLE_SHFT                                                        0x7
#define HWIO_OEM_CONFIG1_LPASS_Q6_DBGEN_DISABLE_BMSK                                                   0x40
#define HWIO_OEM_CONFIG1_LPASS_Q6_DBGEN_DISABLE_SHFT                                                    0x6
#define HWIO_OEM_CONFIG1_DAP_DBGEN_DISABLE_BMSK                                                        0x20
#define HWIO_OEM_CONFIG1_DAP_DBGEN_DISABLE_SHFT                                                         0x5
#define HWIO_OEM_CONFIG1_APPS_DBGEN_DISABLE_BMSK                                                       0x10
#define HWIO_OEM_CONFIG1_APPS_DBGEN_DISABLE_SHFT                                                        0x4
#define HWIO_OEM_CONFIG1_DAP_DEVICEEN_DISABLE_BMSK                                                      0x8
#define HWIO_OEM_CONFIG1_DAP_DEVICEEN_DISABLE_SHFT                                                      0x3
#define HWIO_OEM_CONFIG1_RPM_DAPEN_DISABLE_BMSK                                                         0x4
#define HWIO_OEM_CONFIG1_RPM_DAPEN_DISABLE_SHFT                                                         0x2
#define HWIO_OEM_CONFIG1_RSVD0_BMSK                                                                     0x2
#define HWIO_OEM_CONFIG1_RSVD0_SHFT                                                                     0x1
#define HWIO_OEM_CONFIG1_DEBUG_BUS_DISABLE_BMSK                                                         0x1
#define HWIO_OEM_CONFIG1_DEBUG_BUS_DISABLE_SHFT                                                         0x0

#define HWIO_OEM_CONFIG2_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006048)
#define HWIO_OEM_CONFIG2_RMSK                                                                    0xffffffff
#define HWIO_OEM_CONFIG2_IN          \
        in_dword_masked(HWIO_OEM_CONFIG2_ADDR, HWIO_OEM_CONFIG2_RMSK)
#define HWIO_OEM_CONFIG2_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG2_ADDR, m)
#define HWIO_OEM_CONFIG2_RSVD1_BMSK                                                              0xffff8000
#define HWIO_OEM_CONFIG2_RSVD1_SHFT                                                                     0xf
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG30_SECURE_BMSK                                                 0x4000
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG30_SECURE_SHFT                                                    0xe
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG29_SECURE_BMSK                                                 0x2000
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG29_SECURE_SHFT                                                    0xd
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG28_SECURE_BMSK                                                 0x1000
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG28_SECURE_SHFT                                                    0xc
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG27_SECURE_BMSK                                                  0x800
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG27_SECURE_SHFT                                                    0xb
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG26_SECURE_BMSK                                                  0x400
#define HWIO_OEM_CONFIG2_OEM_SPARE_REG26_SECURE_SHFT                                                    0xa
#define HWIO_OEM_CONFIG2_RSVD0_BMSK                                                                   0x3fe
#define HWIO_OEM_CONFIG2_RSVD0_SHFT                                                                     0x1
#define HWIO_OEM_CONFIG2_LPASS_SPIDEN_DISABLE_BMSK                                                      0x1
#define HWIO_OEM_CONFIG2_LPASS_SPIDEN_DISABLE_SHFT                                                      0x0

#define HWIO_OEM_CONFIG3_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000604c)
#define HWIO_OEM_CONFIG3_RMSK                                                                    0xffffffff
#define HWIO_OEM_CONFIG3_IN          \
        in_dword_masked(HWIO_OEM_CONFIG3_ADDR, HWIO_OEM_CONFIG3_RMSK)
#define HWIO_OEM_CONFIG3_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG3_ADDR, m)
#define HWIO_OEM_CONFIG3_OEM_PRODUCT_ID_BMSK                                                     0xffff0000
#define HWIO_OEM_CONFIG3_OEM_PRODUCT_ID_SHFT                                                           0x10
#define HWIO_OEM_CONFIG3_OEM_HW_ID_BMSK                                                              0xffff
#define HWIO_OEM_CONFIG3_OEM_HW_ID_SHFT                                                                 0x0

#define HWIO_OEM_CONFIG4_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006050)
#define HWIO_OEM_CONFIG4_RMSK                                                                    0xffffffff
#define HWIO_OEM_CONFIG4_IN          \
        in_dword_masked(HWIO_OEM_CONFIG4_ADDR, HWIO_OEM_CONFIG4_RMSK)
#define HWIO_OEM_CONFIG4_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG4_ADDR, m)
#define HWIO_OEM_CONFIG4_PERIPH_VID_BMSK                                                         0xffff0000
#define HWIO_OEM_CONFIG4_PERIPH_VID_SHFT                                                               0x10
#define HWIO_OEM_CONFIG4_PERIPH_PID_BMSK                                                             0xffff
#define HWIO_OEM_CONFIG4_PERIPH_PID_SHFT                                                                0x0

#define HWIO_OEM_CONFIG5_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006054)
#define HWIO_OEM_CONFIG5_RMSK                                                                    0xffffffff
#define HWIO_OEM_CONFIG5_IN          \
        in_dword_masked(HWIO_OEM_CONFIG5_ADDR, HWIO_OEM_CONFIG5_RMSK)
#define HWIO_OEM_CONFIG5_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG5_ADDR, m)
#define HWIO_OEM_CONFIG5_RSVD0_BMSK                                                              0xffffff00
#define HWIO_OEM_CONFIG5_RSVD0_SHFT                                                                     0x8
#define HWIO_OEM_CONFIG5_ANTI_ROLLBACK_FEATURE_EN_BMSK                                                 0xff
#define HWIO_OEM_CONFIG5_ANTI_ROLLBACK_FEATURE_EN_SHFT                                                  0x0

#define HWIO_BOOT_CONFIG_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006070)
#define HWIO_BOOT_CONFIG_RMSK                                                                         0x7ff
#define HWIO_BOOT_CONFIG_IN          \
        in_dword_masked(HWIO_BOOT_CONFIG_ADDR, HWIO_BOOT_CONFIG_RMSK)
#define HWIO_BOOT_CONFIG_INM(m)      \
        in_dword_masked(HWIO_BOOT_CONFIG_ADDR, m)
#define HWIO_BOOT_CONFIG_FORCE_MSA_AUTH_EN_BMSK                                                       0x400
#define HWIO_BOOT_CONFIG_FORCE_MSA_AUTH_EN_SHFT                                                         0xa
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_BMSK                                                     0x300
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_SHFT                                                       0x8
#define HWIO_BOOT_CONFIG_MODEM_BOOT_FROM_ROM_BMSK                                                      0x80
#define HWIO_BOOT_CONFIG_MODEM_BOOT_FROM_ROM_SHFT                                                       0x7
#define HWIO_BOOT_CONFIG_APPS_BOOT_FROM_ROM_BMSK                                                       0x40
#define HWIO_BOOT_CONFIG_APPS_BOOT_FROM_ROM_SHFT                                                        0x6
#define HWIO_BOOT_CONFIG_FAST_BOOT_BMSK                                                                0x3e
#define HWIO_BOOT_CONFIG_FAST_BOOT_SHFT                                                                 0x1
#define HWIO_BOOT_CONFIG_WDOG_EN_BMSK                                                                   0x1
#define HWIO_BOOT_CONFIG_WDOG_EN_SHFT                                                                   0x0

#define HWIO_SECURE_BOOTn_ADDR(n)                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006078 + 0x4 * (n))
#define HWIO_SECURE_BOOTn_RMSK                                                                        0x1ff
#define HWIO_SECURE_BOOTn_MAXn                                                                           14
#define HWIO_SECURE_BOOTn_INI(n)        \
        in_dword_masked(HWIO_SECURE_BOOTn_ADDR(n), HWIO_SECURE_BOOTn_RMSK)
#define HWIO_SECURE_BOOTn_INMI(n,mask)    \
        in_dword_masked(HWIO_SECURE_BOOTn_ADDR(n), mask)
#define HWIO_SECURE_BOOTn_FUSE_SRC_BMSK                                                               0x100
#define HWIO_SECURE_BOOTn_FUSE_SRC_SHFT                                                                 0x8
#define HWIO_SECURE_BOOTn_RSVD_7_BMSK                                                                  0x80
#define HWIO_SECURE_BOOTn_RSVD_7_SHFT                                                                   0x7
#define HWIO_SECURE_BOOTn_USE_SERIAL_NUM_BMSK                                                          0x40
#define HWIO_SECURE_BOOTn_USE_SERIAL_NUM_SHFT                                                           0x6
#define HWIO_SECURE_BOOTn_AUTH_EN_BMSK                                                                 0x20
#define HWIO_SECURE_BOOTn_AUTH_EN_SHFT                                                                  0x5
#define HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_BMSK                                                         0x10
#define HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_SHFT                                                          0x4
#define HWIO_SECURE_BOOTn_ROM_PK_HASH_INDEX_BMSK                                                        0xf
#define HWIO_SECURE_BOOTn_ROM_PK_HASH_INDEX_SHFT                                                        0x0

#define HWIO_OVERRIDE_0_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060c0)
#define HWIO_OVERRIDE_0_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_0_IN          \
        in_dword_masked(HWIO_OVERRIDE_0_ADDR, HWIO_OVERRIDE_0_RMSK)
#define HWIO_OVERRIDE_0_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_0_ADDR, m)
#define HWIO_OVERRIDE_0_OUT(v)      \
        out_dword(HWIO_OVERRIDE_0_ADDR,v)
#define HWIO_OVERRIDE_0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_0_ADDR,m,v,HWIO_OVERRIDE_0_IN)
#define HWIO_OVERRIDE_0_RSVD_31_3_BMSK                                                           0xfffffff8
#define HWIO_OVERRIDE_0_RSVD_31_3_SHFT                                                                  0x3
#define HWIO_OVERRIDE_0_TX_DISABLE_BMSK                                                                 0x4
#define HWIO_OVERRIDE_0_TX_DISABLE_SHFT                                                                 0x2
#define HWIO_OVERRIDE_0_RSVD_1_0_BMSK                                                                   0x3
#define HWIO_OVERRIDE_0_RSVD_1_0_SHFT                                                                   0x0

#define HWIO_OVERRIDE_1_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060c4)
#define HWIO_OVERRIDE_1_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_1_IN          \
        in_dword_masked(HWIO_OVERRIDE_1_ADDR, HWIO_OVERRIDE_1_RMSK)
#define HWIO_OVERRIDE_1_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_1_ADDR, m)
#define HWIO_OVERRIDE_1_OUT(v)      \
        out_dword(HWIO_OVERRIDE_1_ADDR,v)
#define HWIO_OVERRIDE_1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_1_ADDR,m,v,HWIO_OVERRIDE_1_IN)
#define HWIO_OVERRIDE_1_RSVD_31_7_BMSK                                                           0xffffff80
#define HWIO_OVERRIDE_1_RSVD_31_7_SHFT                                                                  0x7
#define HWIO_OVERRIDE_1_OVRID_VSENSE_DEBUG_DISABLE_BMSK                                                0x40
#define HWIO_OVERRIDE_1_OVRID_VSENSE_DEBUG_DISABLE_SHFT                                                 0x6
#define HWIO_OVERRIDE_1_OVRID_DAP_DEVICEEN_DISABLE_BMSK                                                0x20
#define HWIO_OVERRIDE_1_OVRID_DAP_DEVICEEN_DISABLE_SHFT                                                 0x5
#define HWIO_OVERRIDE_1_OVRID_RPM_DAPEN_DISABLE_BMSK                                                   0x10
#define HWIO_OVERRIDE_1_OVRID_RPM_DAPEN_DISABLE_SHFT                                                    0x4
#define HWIO_OVERRIDE_1_RSVD0_BMSK                                                                      0x8
#define HWIO_OVERRIDE_1_RSVD0_SHFT                                                                      0x3
#define HWIO_OVERRIDE_1_OVRID_DEBUG_BUS_DISABLE_BMSK                                                    0x4
#define HWIO_OVERRIDE_1_OVRID_DEBUG_BUS_DISABLE_SHFT                                                    0x2
#define HWIO_OVERRIDE_1_OVRID_DCC_DEBUG_DISABLE_BMSK                                                    0x2
#define HWIO_OVERRIDE_1_OVRID_DCC_DEBUG_DISABLE_SHFT                                                    0x1
#define HWIO_OVERRIDE_1_OVRID_APPS_APB_DFD_DISABLE_BMSK                                                 0x1
#define HWIO_OVERRIDE_1_OVRID_APPS_APB_DFD_DISABLE_SHFT                                                 0x0

#define HWIO_OVERRIDE_2_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060c8)
#define HWIO_OVERRIDE_2_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_2_IN          \
        in_dword_masked(HWIO_OVERRIDE_2_ADDR, HWIO_OVERRIDE_2_RMSK)
#define HWIO_OVERRIDE_2_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_2_ADDR, m)
#define HWIO_OVERRIDE_2_OUT(v)      \
        out_dword(HWIO_OVERRIDE_2_ADDR,v)
#define HWIO_OVERRIDE_2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_2_ADDR,m,v,HWIO_OVERRIDE_2_IN)
#define HWIO_OVERRIDE_2_RSVD_31_17_BMSK                                                          0xfffe0000
#define HWIO_OVERRIDE_2_RSVD_31_17_SHFT                                                                0x11
#define HWIO_OVERRIDE_2_OVRID_LPASS_SENSOR_NIDEN_DISABLE_BMSK                                       0x10000
#define HWIO_OVERRIDE_2_OVRID_LPASS_SENSOR_NIDEN_DISABLE_SHFT                                          0x10
#define HWIO_OVERRIDE_2_OVRID_PIMEM_NIDEN_DISABLE_BMSK                                               0x8000
#define HWIO_OVERRIDE_2_OVRID_PIMEM_NIDEN_DISABLE_SHFT                                                  0xf
#define HWIO_OVERRIDE_2_OVRID_RPM_NIDEN_DISABLE_BMSK                                                 0x4000
#define HWIO_OVERRIDE_2_OVRID_RPM_NIDEN_DISABLE_SHFT                                                    0xe
#define HWIO_OVERRIDE_2_OVRID_WCSS_NIDEN_DISABLE_BMSK                                                0x2000
#define HWIO_OVERRIDE_2_OVRID_WCSS_NIDEN_DISABLE_SHFT                                                   0xd
#define HWIO_OVERRIDE_2_OVRID_LPASS_NIDEN_DISABLE_BMSK                                               0x1000
#define HWIO_OVERRIDE_2_OVRID_LPASS_NIDEN_DISABLE_SHFT                                                  0xc
#define HWIO_OVERRIDE_2_OVRID_DAP_NIDEN_DISABLE_BMSK                                                  0x800
#define HWIO_OVERRIDE_2_OVRID_DAP_NIDEN_DISABLE_SHFT                                                    0xb
#define HWIO_OVERRIDE_2_OVRID_APPS_NIDEN_DISABLE_BMSK                                                 0x400
#define HWIO_OVERRIDE_2_OVRID_APPS_NIDEN_DISABLE_SHFT                                                   0xa
#define HWIO_OVERRIDE_2_OVRID_A5X_ISDB_DBGEN_DISABLE_BMSK                                             0x200
#define HWIO_OVERRIDE_2_OVRID_A5X_ISDB_DBGEN_DISABLE_SHFT                                               0x9
#define HWIO_OVERRIDE_2_OVRID_VENUS_0_DBGEN_DISABLE_BMSK                                              0x100
#define HWIO_OVERRIDE_2_OVRID_VENUS_0_DBGEN_DISABLE_SHFT                                                0x8
#define HWIO_OVERRIDE_2_RSVD1_BMSK                                                                     0x80
#define HWIO_OVERRIDE_2_RSVD1_SHFT                                                                      0x7
#define HWIO_OVERRIDE_2_OVRID_LPASS_SENSOR_DBGEN_DISABLE_BMSK                                          0x40
#define HWIO_OVERRIDE_2_OVRID_LPASS_SENSOR_DBGEN_DISABLE_SHFT                                           0x6
#define HWIO_OVERRIDE_2_OVRID_PIMEM_DBGEN_DISABLE_BMSK                                                 0x20
#define HWIO_OVERRIDE_2_OVRID_PIMEM_DBGEN_DISABLE_SHFT                                                  0x5
#define HWIO_OVERRIDE_2_OVRID_RPM_DBGEN_DISABLE_BMSK                                                   0x10
#define HWIO_OVERRIDE_2_OVRID_RPM_DBGEN_DISABLE_SHFT                                                    0x4
#define HWIO_OVERRIDE_2_OVRID_WCSS_DBGEN_DISABLE_BMSK                                                   0x8
#define HWIO_OVERRIDE_2_OVRID_WCSS_DBGEN_DISABLE_SHFT                                                   0x3
#define HWIO_OVERRIDE_2_OVRID_LPASS_Q6_DBGEN_DISABLE_BMSK                                               0x4
#define HWIO_OVERRIDE_2_OVRID_LPASS_Q6_DBGEN_DISABLE_SHFT                                               0x2
#define HWIO_OVERRIDE_2_OVRID_DAP_DBGEN_DISABLE_BMSK                                                    0x2
#define HWIO_OVERRIDE_2_OVRID_DAP_DBGEN_DISABLE_SHFT                                                    0x1
#define HWIO_OVERRIDE_2_OVRID_APPS_DBGEN_DISABLE_BMSK                                                   0x1
#define HWIO_OVERRIDE_2_OVRID_APPS_DBGEN_DISABLE_SHFT                                                   0x0

#define HWIO_OVERRIDE_3_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060cc)
#define HWIO_OVERRIDE_3_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_3_IN          \
        in_dword_masked(HWIO_OVERRIDE_3_ADDR, HWIO_OVERRIDE_3_RMSK)
#define HWIO_OVERRIDE_3_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_3_ADDR, m)
#define HWIO_OVERRIDE_3_OUT(v)      \
        out_dword(HWIO_OVERRIDE_3_ADDR,v)
#define HWIO_OVERRIDE_3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_3_ADDR,m,v,HWIO_OVERRIDE_3_IN)
#define HWIO_OVERRIDE_3_RSVD_31_11_BMSK                                                          0xfffff800
#define HWIO_OVERRIDE_3_RSVD_31_11_SHFT                                                                 0xb
#define HWIO_OVERRIDE_3_OVRID_SPDM_SECURE_MODE_BMSK                                                   0x400
#define HWIO_OVERRIDE_3_OVRID_SPDM_SECURE_MODE_SHFT                                                     0xa
#define HWIO_OVERRIDE_3_OVRID_LPASS_SPIDEN_DISABLE_BMSK                                               0x200
#define HWIO_OVERRIDE_3_OVRID_LPASS_SPIDEN_DISABLE_SHFT                                                 0x9
#define HWIO_OVERRIDE_3_OVRID_PIMEM_SPIDEN_DISABLE_BMSK                                               0x100
#define HWIO_OVERRIDE_3_OVRID_PIMEM_SPIDEN_DISABLE_SHFT                                                 0x8
#define HWIO_OVERRIDE_3_OVRID_WCSS_SPIDEN_DISABLE_BMSK                                                 0x80
#define HWIO_OVERRIDE_3_OVRID_WCSS_SPIDEN_DISABLE_SHFT                                                  0x7
#define HWIO_OVERRIDE_3_OVRID_DAP_SPIDEN_DISABLE_BMSK                                                  0x40
#define HWIO_OVERRIDE_3_OVRID_DAP_SPIDEN_DISABLE_SHFT                                                   0x6
#define HWIO_OVERRIDE_3_OVRID_APPS_SPIDEN_DISABLE_BMSK                                                 0x20
#define HWIO_OVERRIDE_3_OVRID_APPS_SPIDEN_DISABLE_SHFT                                                  0x5
#define HWIO_OVERRIDE_3_OVRID_LPASS_SPNIDEN_DISABLE_BMSK                                               0x10
#define HWIO_OVERRIDE_3_OVRID_LPASS_SPNIDEN_DISABLE_SHFT                                                0x4
#define HWIO_OVERRIDE_3_OVRID_PIMEM_SPNIDEN_DISABLE_BMSK                                                0x8
#define HWIO_OVERRIDE_3_OVRID_PIMEM_SPNIDEN_DISABLE_SHFT                                                0x3
#define HWIO_OVERRIDE_3_OVRID_WCSS_SPNIDEN_DISABLE_BMSK                                                 0x4
#define HWIO_OVERRIDE_3_OVRID_WCSS_SPNIDEN_DISABLE_SHFT                                                 0x2
#define HWIO_OVERRIDE_3_OVRID_DAP_SPNIDEN_DISABLE_BMSK                                                  0x2
#define HWIO_OVERRIDE_3_OVRID_DAP_SPNIDEN_DISABLE_SHFT                                                  0x1
#define HWIO_OVERRIDE_3_OVRID_APPS_SPNIDEN_DISABLE_BMSK                                                 0x1
#define HWIO_OVERRIDE_3_OVRID_APPS_SPNIDEN_DISABLE_SHFT                                                 0x0

#define HWIO_OVERRIDE_4_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060d0)
#define HWIO_OVERRIDE_4_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_4_IN          \
        in_dword_masked(HWIO_OVERRIDE_4_ADDR, HWIO_OVERRIDE_4_RMSK)
#define HWIO_OVERRIDE_4_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_4_ADDR, m)
#define HWIO_OVERRIDE_4_OUT(v)      \
        out_dword(HWIO_OVERRIDE_4_ADDR,v)
#define HWIO_OVERRIDE_4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_4_ADDR,m,v,HWIO_OVERRIDE_4_IN)
#define HWIO_OVERRIDE_4_RSVD_31_2_BMSK                                                           0xfffffffc
#define HWIO_OVERRIDE_4_RSVD_31_2_SHFT                                                                  0x2
#define HWIO_OVERRIDE_4_OVRID_MSS_NIDEN_DISABLE_BMSK                                                    0x2
#define HWIO_OVERRIDE_4_OVRID_MSS_NIDEN_DISABLE_SHFT                                                    0x1
#define HWIO_OVERRIDE_4_OVRID_MSS_DBGEN_DISABLE_BMSK                                                    0x1
#define HWIO_OVERRIDE_4_OVRID_MSS_DBGEN_DISABLE_SHFT                                                    0x0

#define HWIO_OVERRIDE_5_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060d4)
#define HWIO_OVERRIDE_5_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_5_IN          \
        in_dword_masked(HWIO_OVERRIDE_5_ADDR, HWIO_OVERRIDE_5_RMSK)
#define HWIO_OVERRIDE_5_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_5_ADDR, m)
#define HWIO_OVERRIDE_5_OUT(v)      \
        out_dword(HWIO_OVERRIDE_5_ADDR,v)
#define HWIO_OVERRIDE_5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_5_ADDR,m,v,HWIO_OVERRIDE_5_IN)
#define HWIO_OVERRIDE_5_RSVD_31_0_BMSK                                                           0xffffffff
#define HWIO_OVERRIDE_5_RSVD_31_0_SHFT                                                                  0x0

#define HWIO_OVERRIDE_6_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060d8)
#define HWIO_OVERRIDE_6_RMSK                                                                     0xffffffff
#define HWIO_OVERRIDE_6_IN          \
        in_dword_masked(HWIO_OVERRIDE_6_ADDR, HWIO_OVERRIDE_6_RMSK)
#define HWIO_OVERRIDE_6_INM(m)      \
        in_dword_masked(HWIO_OVERRIDE_6_ADDR, m)
#define HWIO_OVERRIDE_6_OUT(v)      \
        out_dword(HWIO_OVERRIDE_6_ADDR,v)
#define HWIO_OVERRIDE_6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_OVERRIDE_6_ADDR,m,v,HWIO_OVERRIDE_6_IN)
#define HWIO_OVERRIDE_6_RSVD_31_0_BMSK                                                           0xffffffff
#define HWIO_OVERRIDE_6_RSVD_31_0_SHFT                                                                  0x0

#define HWIO_CAPT_SEC_GPIO_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006100)
#define HWIO_CAPT_SEC_GPIO_RMSK                                                                     0x1ffff
#define HWIO_CAPT_SEC_GPIO_IN          \
        in_dword_masked(HWIO_CAPT_SEC_GPIO_ADDR, HWIO_CAPT_SEC_GPIO_RMSK)
#define HWIO_CAPT_SEC_GPIO_INM(m)      \
        in_dword_masked(HWIO_CAPT_SEC_GPIO_ADDR, m)
#define HWIO_CAPT_SEC_GPIO_OUT(v)      \
        out_dword(HWIO_CAPT_SEC_GPIO_ADDR,v)
#define HWIO_CAPT_SEC_GPIO_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CAPT_SEC_GPIO_ADDR,m,v,HWIO_CAPT_SEC_GPIO_IN)
#define HWIO_CAPT_SEC_GPIO_FORCE_USB_BOOT_GPIO_BMSK                                                 0x10000
#define HWIO_CAPT_SEC_GPIO_FORCE_USB_BOOT_GPIO_SHFT                                                    0x10
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FORCE_MSA_AUTH_EN_BMSK                                   0x8000
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FORCE_MSA_AUTH_EN_SHFT                                      0xf
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_AUTH_EN_BMSK                                          0x4000
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_AUTH_EN_SHFT                                             0xe
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_PK_HASH_IN_FUSE_BMSK                                  0x2000
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_PK_HASH_IN_FUSE_SHFT                                     0xd
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_MSA_AUTH_EN_BMSK                                         0x1000
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_MSA_AUTH_EN_SHFT                                            0xc
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_MSA_PK_HASH_IN_FUSE_BMSK                                  0x800
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_MSA_PK_HASH_IN_FUSE_SHFT                                    0xb
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_ALL_USE_SERIAL_NUM_BMSK                                   0x400
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_ALL_USE_SERIAL_NUM_SHFT                                     0xa
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_PK_HASH_INDEX_SRC_BMSK                                    0x200
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_PK_HASH_INDEX_SRC_SHFT                                      0x9
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_PBL_BOOT_SPEED_BMSK                                  0x180
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_PBL_BOOT_SPEED_SHFT                                    0x7
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_MODEM_BOOT_FROM_ROM_BMSK                                   0x40
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_MODEM_BOOT_FROM_ROM_SHFT                                    0x6
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_BOOT_FROM_ROM_BMSK                                    0x20
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_BOOT_FROM_ROM_SHFT                                     0x5
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FAST_BOOT_BMSK                                             0x1e
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FAST_BOOT_SHFT                                              0x1
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_WDOG_DISABLE_BMSK                                           0x1
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_WDOG_DISABLE_SHFT                                           0x0

#define HWIO_APP_PROC_CFG_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006110)
#define HWIO_APP_PROC_CFG_RMSK                                                                        0xfff
#define HWIO_APP_PROC_CFG_IN          \
        in_dword_masked(HWIO_APP_PROC_CFG_ADDR, HWIO_APP_PROC_CFG_RMSK)
#define HWIO_APP_PROC_CFG_INM(m)      \
        in_dword_masked(HWIO_APP_PROC_CFG_ADDR, m)
#define HWIO_APP_PROC_CFG_OUT(v)      \
        out_dword(HWIO_APP_PROC_CFG_ADDR,v)
#define HWIO_APP_PROC_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_APP_PROC_CFG_ADDR,m,v,HWIO_APP_PROC_CFG_IN)
#define HWIO_APP_PROC_CFG_LPASS_DBG_SPNIDEN_BMSK                                                      0x800
#define HWIO_APP_PROC_CFG_LPASS_DBG_SPNIDEN_SHFT                                                        0xb
#define HWIO_APP_PROC_CFG_PIMEM_DBG_SPNIDEN_BMSK                                                      0x400
#define HWIO_APP_PROC_CFG_PIMEM_DBG_SPNIDEN_SHFT                                                        0xa
#define HWIO_APP_PROC_CFG_WCSS_DBG_SPNIDEN_BMSK                                                       0x200
#define HWIO_APP_PROC_CFG_WCSS_DBG_SPNIDEN_SHFT                                                         0x9
#define HWIO_APP_PROC_CFG_DAP_DBG_SPNIDEN_BMSK                                                        0x100
#define HWIO_APP_PROC_CFG_DAP_DBG_SPNIDEN_SHFT                                                          0x8
#define HWIO_APP_PROC_CFG_APPS_DBG_SPNIDEN_BMSK                                                        0x80
#define HWIO_APP_PROC_CFG_APPS_DBG_SPNIDEN_SHFT                                                         0x7
#define HWIO_APP_PROC_CFG_LPASS_SENSOR_DBG_NIDEN_BMSK                                                  0x40
#define HWIO_APP_PROC_CFG_LPASS_SENSOR_DBG_NIDEN_SHFT                                                   0x6
#define HWIO_APP_PROC_CFG_PIMEM_DBG_NIDEN_BMSK                                                         0x20
#define HWIO_APP_PROC_CFG_PIMEM_DBG_NIDEN_SHFT                                                          0x5
#define HWIO_APP_PROC_CFG_RPM_DBG_NIDEN_BMSK                                                           0x10
#define HWIO_APP_PROC_CFG_RPM_DBG_NIDEN_SHFT                                                            0x4
#define HWIO_APP_PROC_CFG_WCSS_DBG_NIDEN_BMSK                                                           0x8
#define HWIO_APP_PROC_CFG_WCSS_DBG_NIDEN_SHFT                                                           0x3
#define HWIO_APP_PROC_CFG_LPASS_DBG_NIDEN_BMSK                                                          0x4
#define HWIO_APP_PROC_CFG_LPASS_DBG_NIDEN_SHFT                                                          0x2
#define HWIO_APP_PROC_CFG_DAP_DBG_NIDEN_BMSK                                                            0x2
#define HWIO_APP_PROC_CFG_DAP_DBG_NIDEN_SHFT                                                            0x1
#define HWIO_APP_PROC_CFG_APPS_DBG_NIDEN_BMSK                                                           0x1
#define HWIO_APP_PROC_CFG_APPS_DBG_NIDEN_SHFT                                                           0x0

#define HWIO_MSS_PROC_CFG_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006114)
#define HWIO_MSS_PROC_CFG_RMSK                                                                          0x1
#define HWIO_MSS_PROC_CFG_IN          \
        in_dword_masked(HWIO_MSS_PROC_CFG_ADDR, HWIO_MSS_PROC_CFG_RMSK)
#define HWIO_MSS_PROC_CFG_INM(m)      \
        in_dword_masked(HWIO_MSS_PROC_CFG_ADDR, m)
#define HWIO_MSS_PROC_CFG_OUT(v)      \
        out_dword(HWIO_MSS_PROC_CFG_ADDR,v)
#define HWIO_MSS_PROC_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_MSS_PROC_CFG_ADDR,m,v,HWIO_MSS_PROC_CFG_IN)
#define HWIO_MSS_PROC_CFG_MSS_DBG_NIDEN_BMSK                                                            0x1
#define HWIO_MSS_PROC_CFG_MSS_DBG_NIDEN_SHFT                                                            0x0

#define HWIO_QFPROM_CLK_CTL_ADDR                                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006118)
#define HWIO_QFPROM_CLK_CTL_RMSK                                                                        0x1
#define HWIO_QFPROM_CLK_CTL_IN          \
        in_dword_masked(HWIO_QFPROM_CLK_CTL_ADDR, HWIO_QFPROM_CLK_CTL_RMSK)
#define HWIO_QFPROM_CLK_CTL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CLK_CTL_ADDR, m)
#define HWIO_QFPROM_CLK_CTL_OUT(v)      \
        out_dword(HWIO_QFPROM_CLK_CTL_ADDR,v)
#define HWIO_QFPROM_CLK_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_CLK_CTL_ADDR,m,v,HWIO_QFPROM_CLK_CTL_IN)
#define HWIO_QFPROM_CLK_CTL_CLK_HALT_BMSK                                                               0x1
#define HWIO_QFPROM_CLK_CTL_CLK_HALT_SHFT                                                               0x0

#define HWIO_JTAG_ID_ADDR                                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006130)
#define HWIO_JTAG_ID_RMSK                                                                        0xffffffff
#define HWIO_JTAG_ID_IN          \
        in_dword_masked(HWIO_JTAG_ID_ADDR, HWIO_JTAG_ID_RMSK)
#define HWIO_JTAG_ID_INM(m)      \
        in_dword_masked(HWIO_JTAG_ID_ADDR, m)
#define HWIO_JTAG_ID_JTAG_ID_BMSK                                                                0xffffffff
#define HWIO_JTAG_ID_JTAG_ID_SHFT                                                                       0x0

#define HWIO_SERIAL_NUM_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006134)
#define HWIO_SERIAL_NUM_RMSK                                                                     0xffffffff
#define HWIO_SERIAL_NUM_IN          \
        in_dword_masked(HWIO_SERIAL_NUM_ADDR, HWIO_SERIAL_NUM_RMSK)
#define HWIO_SERIAL_NUM_INM(m)      \
        in_dword_masked(HWIO_SERIAL_NUM_ADDR, m)
#define HWIO_SERIAL_NUM_SERIAL_NUM_BMSK                                                          0xffffffff
#define HWIO_SERIAL_NUM_SERIAL_NUM_SHFT                                                                 0x0

#define HWIO_OEM_ID_ADDR                                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006138)
#define HWIO_OEM_ID_RMSK                                                                         0xffffffff
#define HWIO_OEM_ID_IN          \
        in_dword_masked(HWIO_OEM_ID_ADDR, HWIO_OEM_ID_RMSK)
#define HWIO_OEM_ID_INM(m)      \
        in_dword_masked(HWIO_OEM_ID_ADDR, m)
#define HWIO_OEM_ID_OEM_ID_BMSK                                                                  0xffff0000
#define HWIO_OEM_ID_OEM_ID_SHFT                                                                        0x10
#define HWIO_OEM_ID_OEM_PRODUCT_ID_BMSK                                                              0xffff
#define HWIO_OEM_ID_OEM_PRODUCT_ID_SHFT                                                                 0x0

#define HWIO_TEST_BUS_SEL_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000613c)
#define HWIO_TEST_BUS_SEL_RMSK                                                                          0x7
#define HWIO_TEST_BUS_SEL_IN          \
        in_dword_masked(HWIO_TEST_BUS_SEL_ADDR, HWIO_TEST_BUS_SEL_RMSK)
#define HWIO_TEST_BUS_SEL_INM(m)      \
        in_dword_masked(HWIO_TEST_BUS_SEL_ADDR, m)
#define HWIO_TEST_BUS_SEL_OUT(v)      \
        out_dword(HWIO_TEST_BUS_SEL_ADDR,v)
#define HWIO_TEST_BUS_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TEST_BUS_SEL_ADDR,m,v,HWIO_TEST_BUS_SEL_IN)
#define HWIO_TEST_BUS_SEL_TEST_EN_BMSK                                                                  0x4
#define HWIO_TEST_BUS_SEL_TEST_EN_SHFT                                                                  0x2
#define HWIO_TEST_BUS_SEL_TEST_SELECT_BMSK                                                              0x3
#define HWIO_TEST_BUS_SEL_TEST_SELECT_SHFT                                                              0x0

#define HWIO_SPDM_DYN_SECURE_MODE_ADDR                                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006140)
#define HWIO_SPDM_DYN_SECURE_MODE_RMSK                                                                  0x1
#define HWIO_SPDM_DYN_SECURE_MODE_IN          \
        in_dword_masked(HWIO_SPDM_DYN_SECURE_MODE_ADDR, HWIO_SPDM_DYN_SECURE_MODE_RMSK)
#define HWIO_SPDM_DYN_SECURE_MODE_INM(m)      \
        in_dword_masked(HWIO_SPDM_DYN_SECURE_MODE_ADDR, m)
#define HWIO_SPDM_DYN_SECURE_MODE_OUT(v)      \
        out_dword(HWIO_SPDM_DYN_SECURE_MODE_ADDR,v)
#define HWIO_SPDM_DYN_SECURE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_DYN_SECURE_MODE_ADDR,m,v,HWIO_SPDM_DYN_SECURE_MODE_IN)
#define HWIO_SPDM_DYN_SECURE_MODE_SECURE_MODE_BMSK                                                      0x1
#define HWIO_SPDM_DYN_SECURE_MODE_SECURE_MODE_SHFT                                                      0x0

#define HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(n)                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006150 + 0x4 * (n))
#define HWIO_OEM_IMAGE_ENCR_KEYn_RMSK                                                            0xffffffff
#define HWIO_OEM_IMAGE_ENCR_KEYn_MAXn                                                                     3
#define HWIO_OEM_IMAGE_ENCR_KEYn_INI(n)        \
        in_dword_masked(HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(n), HWIO_OEM_IMAGE_ENCR_KEYn_RMSK)
#define HWIO_OEM_IMAGE_ENCR_KEYn_INMI(n,mask)    \
        in_dword_masked(HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(n), mask)
#define HWIO_OEM_IMAGE_ENCR_KEYn_KEY_DATA0_BMSK                                                  0xffffffff
#define HWIO_OEM_IMAGE_ENCR_KEYn_KEY_DATA0_SHFT                                                         0x0

#define HWIO_IMAGE_ENCR_KEY1_0_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006160)
#define HWIO_IMAGE_ENCR_KEY1_0_RMSK                                                              0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_0_IN          \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_0_ADDR, HWIO_IMAGE_ENCR_KEY1_0_RMSK)
#define HWIO_IMAGE_ENCR_KEY1_0_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_0_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_0_KEY_DATA0_BMSK                                                    0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_0_KEY_DATA0_SHFT                                                           0x0

#define HWIO_IMAGE_ENCR_KEY1_1_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006164)
#define HWIO_IMAGE_ENCR_KEY1_1_RMSK                                                              0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_1_IN          \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_1_ADDR, HWIO_IMAGE_ENCR_KEY1_1_RMSK)
#define HWIO_IMAGE_ENCR_KEY1_1_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_1_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_1_KEY_DATA0_BMSK                                                    0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_1_KEY_DATA0_SHFT                                                           0x0

#define HWIO_IMAGE_ENCR_KEY1_2_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006168)
#define HWIO_IMAGE_ENCR_KEY1_2_RMSK                                                              0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_2_IN          \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_2_ADDR, HWIO_IMAGE_ENCR_KEY1_2_RMSK)
#define HWIO_IMAGE_ENCR_KEY1_2_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_2_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_2_KEY_DATA0_BMSK                                                    0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_2_KEY_DATA0_SHFT                                                           0x0

#define HWIO_IMAGE_ENCR_KEY1_3_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000616c)
#define HWIO_IMAGE_ENCR_KEY1_3_RMSK                                                              0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_3_IN          \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_3_ADDR, HWIO_IMAGE_ENCR_KEY1_3_RMSK)
#define HWIO_IMAGE_ENCR_KEY1_3_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_3_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_3_KEY_DATA0_BMSK                                                    0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_3_KEY_DATA0_SHFT                                                           0x0

#define HWIO_PK_HASH0_0_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006190)
#define HWIO_PK_HASH0_0_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_0_IN          \
        in_dword_masked(HWIO_PK_HASH0_0_ADDR, HWIO_PK_HASH0_0_RMSK)
#define HWIO_PK_HASH0_0_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_0_ADDR, m)
#define HWIO_PK_HASH0_0_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_0_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_1_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006194)
#define HWIO_PK_HASH0_1_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_1_IN          \
        in_dword_masked(HWIO_PK_HASH0_1_ADDR, HWIO_PK_HASH0_1_RMSK)
#define HWIO_PK_HASH0_1_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_1_ADDR, m)
#define HWIO_PK_HASH0_1_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_1_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_2_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006198)
#define HWIO_PK_HASH0_2_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_2_IN          \
        in_dword_masked(HWIO_PK_HASH0_2_ADDR, HWIO_PK_HASH0_2_RMSK)
#define HWIO_PK_HASH0_2_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_2_ADDR, m)
#define HWIO_PK_HASH0_2_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_2_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_3_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000619c)
#define HWIO_PK_HASH0_3_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_3_IN          \
        in_dword_masked(HWIO_PK_HASH0_3_ADDR, HWIO_PK_HASH0_3_RMSK)
#define HWIO_PK_HASH0_3_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_3_ADDR, m)
#define HWIO_PK_HASH0_3_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_3_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_4_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061a0)
#define HWIO_PK_HASH0_4_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_4_IN          \
        in_dword_masked(HWIO_PK_HASH0_4_ADDR, HWIO_PK_HASH0_4_RMSK)
#define HWIO_PK_HASH0_4_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_4_ADDR, m)
#define HWIO_PK_HASH0_4_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_4_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_5_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061a4)
#define HWIO_PK_HASH0_5_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_5_IN          \
        in_dword_masked(HWIO_PK_HASH0_5_ADDR, HWIO_PK_HASH0_5_RMSK)
#define HWIO_PK_HASH0_5_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_5_ADDR, m)
#define HWIO_PK_HASH0_5_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_5_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_6_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061a8)
#define HWIO_PK_HASH0_6_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_6_IN          \
        in_dword_masked(HWIO_PK_HASH0_6_ADDR, HWIO_PK_HASH0_6_RMSK)
#define HWIO_PK_HASH0_6_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_6_ADDR, m)
#define HWIO_PK_HASH0_6_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_6_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH0_7_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061ac)
#define HWIO_PK_HASH0_7_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH0_7_IN          \
        in_dword_masked(HWIO_PK_HASH0_7_ADDR, HWIO_PK_HASH0_7_RMSK)
#define HWIO_PK_HASH0_7_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_7_ADDR, m)
#define HWIO_PK_HASH0_7_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH0_7_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_0_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061b0)
#define HWIO_PK_HASH1_0_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_0_IN          \
        in_dword_masked(HWIO_PK_HASH1_0_ADDR, HWIO_PK_HASH1_0_RMSK)
#define HWIO_PK_HASH1_0_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_0_ADDR, m)
#define HWIO_PK_HASH1_0_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_0_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_1_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061b4)
#define HWIO_PK_HASH1_1_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_1_IN          \
        in_dword_masked(HWIO_PK_HASH1_1_ADDR, HWIO_PK_HASH1_1_RMSK)
#define HWIO_PK_HASH1_1_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_1_ADDR, m)
#define HWIO_PK_HASH1_1_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_1_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_2_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061b8)
#define HWIO_PK_HASH1_2_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_2_IN          \
        in_dword_masked(HWIO_PK_HASH1_2_ADDR, HWIO_PK_HASH1_2_RMSK)
#define HWIO_PK_HASH1_2_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_2_ADDR, m)
#define HWIO_PK_HASH1_2_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_2_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_3_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061bc)
#define HWIO_PK_HASH1_3_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_3_IN          \
        in_dword_masked(HWIO_PK_HASH1_3_ADDR, HWIO_PK_HASH1_3_RMSK)
#define HWIO_PK_HASH1_3_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_3_ADDR, m)
#define HWIO_PK_HASH1_3_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_3_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_4_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061c0)
#define HWIO_PK_HASH1_4_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_4_IN          \
        in_dword_masked(HWIO_PK_HASH1_4_ADDR, HWIO_PK_HASH1_4_RMSK)
#define HWIO_PK_HASH1_4_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_4_ADDR, m)
#define HWIO_PK_HASH1_4_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_4_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_5_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061c4)
#define HWIO_PK_HASH1_5_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_5_IN          \
        in_dword_masked(HWIO_PK_HASH1_5_ADDR, HWIO_PK_HASH1_5_RMSK)
#define HWIO_PK_HASH1_5_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_5_ADDR, m)
#define HWIO_PK_HASH1_5_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_5_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_6_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061c8)
#define HWIO_PK_HASH1_6_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_6_IN          \
        in_dword_masked(HWIO_PK_HASH1_6_ADDR, HWIO_PK_HASH1_6_RMSK)
#define HWIO_PK_HASH1_6_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_6_ADDR, m)
#define HWIO_PK_HASH1_6_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_6_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_PK_HASH1_7_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061cc)
#define HWIO_PK_HASH1_7_RMSK                                                                     0xffffffff
#define HWIO_PK_HASH1_7_IN          \
        in_dword_masked(HWIO_PK_HASH1_7_ADDR, HWIO_PK_HASH1_7_RMSK)
#define HWIO_PK_HASH1_7_INM(m)      \
        in_dword_masked(HWIO_PK_HASH1_7_ADDR, m)
#define HWIO_PK_HASH1_7_HASH_DATA0_BMSK                                                          0xffffffff
#define HWIO_PK_HASH1_7_HASH_DATA0_SHFT                                                                 0x0

#define HWIO_SW_ROT_STICKY_BIT_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061e0)
#define HWIO_SW_ROT_STICKY_BIT_RMSK                                                                     0x1
#define HWIO_SW_ROT_STICKY_BIT_IN          \
        in_dword_masked(HWIO_SW_ROT_STICKY_BIT_ADDR, HWIO_SW_ROT_STICKY_BIT_RMSK)
#define HWIO_SW_ROT_STICKY_BIT_INM(m)      \
        in_dword_masked(HWIO_SW_ROT_STICKY_BIT_ADDR, m)
#define HWIO_SW_ROT_STICKY_BIT_OUT(v)      \
        out_dword(HWIO_SW_ROT_STICKY_BIT_ADDR,v)
#define HWIO_SW_ROT_STICKY_BIT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SW_ROT_STICKY_BIT_ADDR,m,v,HWIO_SW_ROT_STICKY_BIT_IN)
#define HWIO_SW_ROT_STICKY_BIT_SW_ROT_STICKY_BIT_0_BMSK                                                 0x1
#define HWIO_SW_ROT_STICKY_BIT_SW_ROT_STICKY_BIT_0_SHFT                                                 0x0

#define HWIO_SW_ROT_CONFIG_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061e4)
#define HWIO_SW_ROT_CONFIG_RMSK                                                                         0x3
#define HWIO_SW_ROT_CONFIG_IN          \
        in_dword_masked(HWIO_SW_ROT_CONFIG_ADDR, HWIO_SW_ROT_CONFIG_RMSK)
#define HWIO_SW_ROT_CONFIG_INM(m)      \
        in_dword_masked(HWIO_SW_ROT_CONFIG_ADDR, m)
#define HWIO_SW_ROT_CONFIG_CURRENT_SW_ROT_MODEM_BMSK                                                    0x2
#define HWIO_SW_ROT_CONFIG_CURRENT_SW_ROT_MODEM_SHFT                                                    0x1
#define HWIO_SW_ROT_CONFIG_CURRENT_SW_ROT_APPS_BMSK                                                     0x1
#define HWIO_SW_ROT_CONFIG_CURRENT_SW_ROT_APPS_SHFT                                                     0x0

#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061f0)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_RMSK                                               0xffffffff
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_IN          \
        in_dword_masked(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR, HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_RMSK)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_INM(m)      \
        in_dword_masked(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR, m)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_OUT(v)      \
        out_dword(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR,v)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR,m,v,HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_IN)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_RSVD0_BMSK                                         0x80000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_RSVD0_SHFT                                               0x1f
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION30_STICKY_BIT_BMSK                           0x40000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION30_STICKY_BIT_SHFT                                 0x1e
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION29_STICKY_BIT_BMSK                           0x20000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION29_STICKY_BIT_SHFT                                 0x1d
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION28_STICKY_BIT_BMSK                           0x10000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION28_STICKY_BIT_SHFT                                 0x1c
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION27_STICKY_BIT_BMSK                            0x8000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION27_STICKY_BIT_SHFT                                 0x1b
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION26_STICKY_BIT_BMSK                            0x4000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION26_STICKY_BIT_SHFT                                 0x1a
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION25_STICKY_BIT_BMSK                            0x2000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION25_STICKY_BIT_SHFT                                 0x19
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION24_STICKY_BIT_BMSK                            0x1000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION24_STICKY_BIT_SHFT                                 0x18
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION23_STICKY_BIT_BMSK                             0x800000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION23_STICKY_BIT_SHFT                                 0x17
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION22_STICKY_BIT_BMSK                             0x400000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION22_STICKY_BIT_SHFT                                 0x16
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION21_STICKY_BIT_BMSK                             0x200000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION21_STICKY_BIT_SHFT                                 0x15
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION20_STICKY_BIT_BMSK                             0x100000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION20_STICKY_BIT_SHFT                                 0x14
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION19_STICKY_BIT_BMSK                              0x80000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION19_STICKY_BIT_SHFT                                 0x13
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION18_STICKY_BIT_BMSK                              0x40000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION18_STICKY_BIT_SHFT                                 0x12
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION17_STICKY_BIT_BMSK                              0x20000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION17_STICKY_BIT_SHFT                                 0x11
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION16_STICKY_BIT_BMSK                              0x10000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION16_STICKY_BIT_SHFT                                 0x10
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION15_STICKY_BIT_BMSK                               0x8000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION15_STICKY_BIT_SHFT                                  0xf
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION14_STICKY_BIT_BMSK                               0x4000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION14_STICKY_BIT_SHFT                                  0xe
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION13_STICKY_BIT_BMSK                               0x2000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION13_STICKY_BIT_SHFT                                  0xd
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION12_STICKY_BIT_BMSK                               0x1000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION12_STICKY_BIT_SHFT                                  0xc
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION11_STICKY_BIT_BMSK                                0x800
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION11_STICKY_BIT_SHFT                                  0xb
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION10_STICKY_BIT_BMSK                                0x400
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION10_STICKY_BIT_SHFT                                  0xa
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION9_STICKY_BIT_BMSK                                 0x200
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION9_STICKY_BIT_SHFT                                   0x9
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION8_STICKY_BIT_BMSK                                 0x100
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION8_STICKY_BIT_SHFT                                   0x8
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION7_STICKY_BIT_BMSK                                  0x80
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION7_STICKY_BIT_SHFT                                   0x7
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION6_STICKY_BIT_BMSK                                  0x40
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION6_STICKY_BIT_SHFT                                   0x6
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION5_STICKY_BIT_BMSK                                  0x20
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION5_STICKY_BIT_SHFT                                   0x5
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION4_STICKY_BIT_BMSK                                  0x10
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION4_STICKY_BIT_SHFT                                   0x4
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION3_STICKY_BIT_BMSK                                   0x8
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION3_STICKY_BIT_SHFT                                   0x3
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION2_STICKY_BIT_BMSK                                   0x4
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION2_STICKY_BIT_SHFT                                   0x2
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_BMSK                                   0x2
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_SHFT                                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION0_STICKY_BIT_BMSK                                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION0_STICKY_BIT_SHFT                                   0x0

#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061f4)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RMSK                                               0xffffffff
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_IN          \
        in_dword_masked(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR, HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RMSK)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_INM(m)      \
        in_dword_masked(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR, m)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_OUT(v)      \
        out_dword(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR,v)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR,m,v,HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_IN)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RSVD0_BMSK                                         0xffffffff
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RSVD0_SHFT                                                0x0

#define HWIO_ANTI_ROLLBACK_1_0_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006200)
#define HWIO_ANTI_ROLLBACK_1_0_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_1_0_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_1_0_ADDR, HWIO_ANTI_ROLLBACK_1_0_RMSK)
#define HWIO_ANTI_ROLLBACK_1_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_1_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_1_0_XBL0_BMSK                                                         0xffffffff
#define HWIO_ANTI_ROLLBACK_1_0_XBL0_SHFT                                                                0x0

#define HWIO_ANTI_ROLLBACK_1_1_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006204)
#define HWIO_ANTI_ROLLBACK_1_1_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_1_1_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_1_1_ADDR, HWIO_ANTI_ROLLBACK_1_1_RMSK)
#define HWIO_ANTI_ROLLBACK_1_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_1_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_1_1_XBL1_BMSK                                                         0xffffffff
#define HWIO_ANTI_ROLLBACK_1_1_XBL1_SHFT                                                                0x0

#define HWIO_ANTI_ROLLBACK_2_0_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006208)
#define HWIO_ANTI_ROLLBACK_2_0_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_2_0_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_2_0_ADDR, HWIO_ANTI_ROLLBACK_2_0_RMSK)
#define HWIO_ANTI_ROLLBACK_2_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_2_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_2_0_PIL_SUBSYSTEM_31_0_BMSK                                           0xffffffff
#define HWIO_ANTI_ROLLBACK_2_0_PIL_SUBSYSTEM_31_0_SHFT                                                  0x0

#define HWIO_ANTI_ROLLBACK_2_1_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000620c)
#define HWIO_ANTI_ROLLBACK_2_1_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_2_1_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_2_1_ADDR, HWIO_ANTI_ROLLBACK_2_1_RMSK)
#define HWIO_ANTI_ROLLBACK_2_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_2_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_2_1_XBL_SEC_BMSK                                                      0xfe000000
#define HWIO_ANTI_ROLLBACK_2_1_XBL_SEC_SHFT                                                            0x19
#define HWIO_ANTI_ROLLBACK_2_1_RPM_BMSK                                                           0x1fe0000
#define HWIO_ANTI_ROLLBACK_2_1_RPM_SHFT                                                                0x11
#define HWIO_ANTI_ROLLBACK_2_1_TZ_BMSK                                                              0x1ffff
#define HWIO_ANTI_ROLLBACK_2_1_TZ_SHFT                                                                  0x0

#define HWIO_ANTI_ROLLBACK_3_0_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006210)
#define HWIO_ANTI_ROLLBACK_3_0_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_3_0_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_3_0_ADDR, HWIO_ANTI_ROLLBACK_3_0_RMSK)
#define HWIO_ANTI_ROLLBACK_3_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_3_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_3_0_RSVD1_BMSK                                                        0xc0000000
#define HWIO_ANTI_ROLLBACK_3_0_RSVD1_SHFT                                                              0x1e
#define HWIO_ANTI_ROLLBACK_3_0_TQS_HASH_ACTIVE_BMSK                                              0x3e000000
#define HWIO_ANTI_ROLLBACK_3_0_TQS_HASH_ACTIVE_SHFT                                                    0x19
#define HWIO_ANTI_ROLLBACK_3_0_RPMB_KEY_PROVISIONED_BMSK                                          0x1000000
#define HWIO_ANTI_ROLLBACK_3_0_RPMB_KEY_PROVISIONED_SHFT                                               0x18
#define HWIO_ANTI_ROLLBACK_3_0_PIL_SUBSYSTEM_47_32_BMSK                                            0xffff00
#define HWIO_ANTI_ROLLBACK_3_0_PIL_SUBSYSTEM_47_32_SHFT                                                 0x8
#define HWIO_ANTI_ROLLBACK_3_0_SAFESWITCH_BMSK                                                         0xff
#define HWIO_ANTI_ROLLBACK_3_0_SAFESWITCH_SHFT                                                          0x0

#define HWIO_ANTI_ROLLBACK_3_1_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006214)
#define HWIO_ANTI_ROLLBACK_3_1_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_3_1_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_3_1_ADDR, HWIO_ANTI_ROLLBACK_3_1_RMSK)
#define HWIO_ANTI_ROLLBACK_3_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_3_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_3_1_RSVD1_BMSK                                                        0xf0000000
#define HWIO_ANTI_ROLLBACK_3_1_RSVD1_SHFT                                                              0x1c
#define HWIO_ANTI_ROLLBACK_3_1_DEVICE_CFG_BMSK                                                    0xffe0000
#define HWIO_ANTI_ROLLBACK_3_1_DEVICE_CFG_SHFT                                                         0x11
#define HWIO_ANTI_ROLLBACK_3_1_DEBUG_POLICY_BMSK                                                    0x1f000
#define HWIO_ANTI_ROLLBACK_3_1_DEBUG_POLICY_SHFT                                                        0xc
#define HWIO_ANTI_ROLLBACK_3_1_HYPERVISOR_BMSK                                                        0xfff
#define HWIO_ANTI_ROLLBACK_3_1_HYPERVISOR_SHFT                                                          0x0

#define HWIO_ANTI_ROLLBACK_4_0_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006218)
#define HWIO_ANTI_ROLLBACK_4_0_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_4_0_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_4_0_ADDR, HWIO_ANTI_ROLLBACK_4_0_RMSK)
#define HWIO_ANTI_ROLLBACK_4_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_4_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_4_0_MSS_BMSK                                                          0xffff0000
#define HWIO_ANTI_ROLLBACK_4_0_MSS_SHFT                                                                0x10
#define HWIO_ANTI_ROLLBACK_4_0_MBA_BMSK                                                              0xffff
#define HWIO_ANTI_ROLLBACK_4_0_MBA_SHFT                                                                 0x0

#define HWIO_ANTI_ROLLBACK_4_1_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000621c)
#define HWIO_ANTI_ROLLBACK_4_1_RMSK                                                              0xffffffff
#define HWIO_ANTI_ROLLBACK_4_1_IN          \
        in_dword_masked(HWIO_ANTI_ROLLBACK_4_1_ADDR, HWIO_ANTI_ROLLBACK_4_1_RMSK)
#define HWIO_ANTI_ROLLBACK_4_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_4_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_4_1_RSVD0_BMSK                                                        0xffffffff
#define HWIO_ANTI_ROLLBACK_4_1_RSVD0_SHFT                                                               0x0


#endif /* __QFPROM_PTE_LPASS_HWIO_H__ */
