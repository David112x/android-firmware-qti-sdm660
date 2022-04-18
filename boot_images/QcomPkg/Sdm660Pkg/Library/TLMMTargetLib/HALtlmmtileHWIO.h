#ifndef __HALTLMMTILEHWIO_H__
#define __HALTLMMTILEHWIO_H__
/*
===========================================================================
*/
/**
  @file HALtlmmtileHWIO.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SDM660 (Starlord) [starlord_v1.0_p2q1r41]
 
  This file contains HWIO register definitions for the following modules:
    TLMM_CENTER
    TLMM_NORTH
    TLMM_SOUTH

  'Include' filters applied: 
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

  $Header: //components/rel/boot.xf/1.4/QcomPkg/Sdm660Pkg/Library/TLMMTargetLib/HALtlmmtileHWIO.h#3 $
  $DateTime: 2016/07/21 23:26:45 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "msmhwiobase.h"
/*----------------------------------------------------------------------------
 * MODULE: TLMM_CENTER
 *--------------------------------------------------------------------------*/

#define TLMM_CENTER_REG_BASE                                               (TLMM_BASE      + 0x00500000)
#define TLMM_CENTER_REG_BASE_OFFS                                          0x00500000

#define HWIO_TLMM_GPIO_CFG16_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00010000)
#define HWIO_TLMM_GPIO_CFG16_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00010000)
#define HWIO_TLMM_GPIO_CFG16_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG16_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG16_ADDR, HWIO_TLMM_GPIO_CFG16_RMSK)
#define HWIO_TLMM_GPIO_CFG16_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG16_ADDR, m)
#define HWIO_TLMM_GPIO_CFG16_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG16_ADDR,v)
#define HWIO_TLMM_GPIO_CFG16_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG16_ADDR,m,v,HWIO_TLMM_GPIO_CFG16_IN)
#define HWIO_TLMM_GPIO_CFG16_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG16_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG16_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG16_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG16_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG16_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG16_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG16_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG16_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG16_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT16_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00010004)
#define HWIO_TLMM_GPIO_IN_OUT16_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00010004)
#define HWIO_TLMM_GPIO_IN_OUT16_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT16_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT16_ADDR, HWIO_TLMM_GPIO_IN_OUT16_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT16_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT16_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT16_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT16_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT16_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT16_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT16_IN)
#define HWIO_TLMM_GPIO_IN_OUT16_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT16_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT16_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT16_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG16_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00010008)
#define HWIO_TLMM_GPIO_INTR_CFG16_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00010008)
#define HWIO_TLMM_GPIO_INTR_CFG16_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG16_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG16_ADDR, HWIO_TLMM_GPIO_INTR_CFG16_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG16_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG16_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG16_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG16_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG16_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG16_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG16_IN)
#define HWIO_TLMM_GPIO_INTR_CFG16_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG16_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG16_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG16_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG16_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS16_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001000c)
#define HWIO_TLMM_GPIO_INTR_STATUS16_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001000c)
#define HWIO_TLMM_GPIO_INTR_STATUS16_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS16_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS16_ADDR, HWIO_TLMM_GPIO_INTR_STATUS16_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS16_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS16_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS16_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS16_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS16_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS16_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS16_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS16_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS16_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS16_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00010010)
#define HWIO_TLMM_GPIO_ID_STATUS16_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00010010)
#define HWIO_TLMM_GPIO_ID_STATUS16_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS16_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS16_ADDR, HWIO_TLMM_GPIO_ID_STATUS16_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS16_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS16_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS16_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS16_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG17_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00011000)
#define HWIO_TLMM_GPIO_CFG17_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00011000)
#define HWIO_TLMM_GPIO_CFG17_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG17_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG17_ADDR, HWIO_TLMM_GPIO_CFG17_RMSK)
#define HWIO_TLMM_GPIO_CFG17_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG17_ADDR, m)
#define HWIO_TLMM_GPIO_CFG17_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG17_ADDR,v)
#define HWIO_TLMM_GPIO_CFG17_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG17_ADDR,m,v,HWIO_TLMM_GPIO_CFG17_IN)
#define HWIO_TLMM_GPIO_CFG17_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG17_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG17_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG17_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG17_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG17_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG17_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG17_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG17_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG17_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT17_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00011004)
#define HWIO_TLMM_GPIO_IN_OUT17_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00011004)
#define HWIO_TLMM_GPIO_IN_OUT17_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT17_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT17_ADDR, HWIO_TLMM_GPIO_IN_OUT17_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT17_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT17_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT17_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT17_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT17_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT17_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT17_IN)
#define HWIO_TLMM_GPIO_IN_OUT17_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT17_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT17_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT17_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG17_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00011008)
#define HWIO_TLMM_GPIO_INTR_CFG17_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00011008)
#define HWIO_TLMM_GPIO_INTR_CFG17_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG17_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG17_ADDR, HWIO_TLMM_GPIO_INTR_CFG17_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG17_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG17_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG17_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG17_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG17_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG17_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG17_IN)
#define HWIO_TLMM_GPIO_INTR_CFG17_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG17_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG17_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG17_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG17_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS17_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001100c)
#define HWIO_TLMM_GPIO_INTR_STATUS17_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001100c)
#define HWIO_TLMM_GPIO_INTR_STATUS17_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS17_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS17_ADDR, HWIO_TLMM_GPIO_INTR_STATUS17_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS17_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS17_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS17_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS17_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS17_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS17_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS17_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS17_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS17_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS17_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00011010)
#define HWIO_TLMM_GPIO_ID_STATUS17_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00011010)
#define HWIO_TLMM_GPIO_ID_STATUS17_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS17_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS17_ADDR, HWIO_TLMM_GPIO_ID_STATUS17_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS17_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS17_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS17_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS17_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG18_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00012000)
#define HWIO_TLMM_GPIO_CFG18_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00012000)
#define HWIO_TLMM_GPIO_CFG18_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG18_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG18_ADDR, HWIO_TLMM_GPIO_CFG18_RMSK)
#define HWIO_TLMM_GPIO_CFG18_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG18_ADDR, m)
#define HWIO_TLMM_GPIO_CFG18_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG18_ADDR,v)
#define HWIO_TLMM_GPIO_CFG18_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG18_ADDR,m,v,HWIO_TLMM_GPIO_CFG18_IN)
#define HWIO_TLMM_GPIO_CFG18_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG18_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG18_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG18_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG18_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG18_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG18_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG18_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG18_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG18_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT18_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00012004)
#define HWIO_TLMM_GPIO_IN_OUT18_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00012004)
#define HWIO_TLMM_GPIO_IN_OUT18_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT18_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT18_ADDR, HWIO_TLMM_GPIO_IN_OUT18_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT18_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT18_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT18_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT18_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT18_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT18_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT18_IN)
#define HWIO_TLMM_GPIO_IN_OUT18_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT18_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT18_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT18_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG18_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00012008)
#define HWIO_TLMM_GPIO_INTR_CFG18_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00012008)
#define HWIO_TLMM_GPIO_INTR_CFG18_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG18_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG18_ADDR, HWIO_TLMM_GPIO_INTR_CFG18_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG18_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG18_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG18_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG18_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG18_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG18_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG18_IN)
#define HWIO_TLMM_GPIO_INTR_CFG18_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG18_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG18_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG18_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG18_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS18_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001200c)
#define HWIO_TLMM_GPIO_INTR_STATUS18_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001200c)
#define HWIO_TLMM_GPIO_INTR_STATUS18_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS18_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS18_ADDR, HWIO_TLMM_GPIO_INTR_STATUS18_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS18_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS18_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS18_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS18_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS18_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS18_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS18_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS18_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS18_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS18_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00012010)
#define HWIO_TLMM_GPIO_ID_STATUS18_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00012010)
#define HWIO_TLMM_GPIO_ID_STATUS18_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS18_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS18_ADDR, HWIO_TLMM_GPIO_ID_STATUS18_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS18_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS18_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS18_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS18_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG19_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00013000)
#define HWIO_TLMM_GPIO_CFG19_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00013000)
#define HWIO_TLMM_GPIO_CFG19_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG19_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG19_ADDR, HWIO_TLMM_GPIO_CFG19_RMSK)
#define HWIO_TLMM_GPIO_CFG19_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG19_ADDR, m)
#define HWIO_TLMM_GPIO_CFG19_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG19_ADDR,v)
#define HWIO_TLMM_GPIO_CFG19_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG19_ADDR,m,v,HWIO_TLMM_GPIO_CFG19_IN)
#define HWIO_TLMM_GPIO_CFG19_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG19_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG19_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG19_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG19_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG19_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG19_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG19_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG19_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG19_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT19_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00013004)
#define HWIO_TLMM_GPIO_IN_OUT19_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00013004)
#define HWIO_TLMM_GPIO_IN_OUT19_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT19_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT19_ADDR, HWIO_TLMM_GPIO_IN_OUT19_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT19_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT19_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT19_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT19_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT19_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT19_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT19_IN)
#define HWIO_TLMM_GPIO_IN_OUT19_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT19_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT19_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT19_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG19_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00013008)
#define HWIO_TLMM_GPIO_INTR_CFG19_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00013008)
#define HWIO_TLMM_GPIO_INTR_CFG19_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG19_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG19_ADDR, HWIO_TLMM_GPIO_INTR_CFG19_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG19_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG19_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG19_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG19_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG19_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG19_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG19_IN)
#define HWIO_TLMM_GPIO_INTR_CFG19_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG19_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG19_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG19_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG19_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS19_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001300c)
#define HWIO_TLMM_GPIO_INTR_STATUS19_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001300c)
#define HWIO_TLMM_GPIO_INTR_STATUS19_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS19_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS19_ADDR, HWIO_TLMM_GPIO_INTR_STATUS19_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS19_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS19_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS19_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS19_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS19_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS19_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS19_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS19_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS19_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS19_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00013010)
#define HWIO_TLMM_GPIO_ID_STATUS19_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00013010)
#define HWIO_TLMM_GPIO_ID_STATUS19_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS19_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS19_ADDR, HWIO_TLMM_GPIO_ID_STATUS19_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS19_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS19_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS19_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS19_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG22_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00016000)
#define HWIO_TLMM_GPIO_CFG22_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00016000)
#define HWIO_TLMM_GPIO_CFG22_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG22_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG22_ADDR, HWIO_TLMM_GPIO_CFG22_RMSK)
#define HWIO_TLMM_GPIO_CFG22_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG22_ADDR, m)
#define HWIO_TLMM_GPIO_CFG22_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG22_ADDR,v)
#define HWIO_TLMM_GPIO_CFG22_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG22_ADDR,m,v,HWIO_TLMM_GPIO_CFG22_IN)
#define HWIO_TLMM_GPIO_CFG22_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG22_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG22_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG22_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG22_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG22_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG22_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG22_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG22_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG22_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT22_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00016004)
#define HWIO_TLMM_GPIO_IN_OUT22_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00016004)
#define HWIO_TLMM_GPIO_IN_OUT22_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT22_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT22_ADDR, HWIO_TLMM_GPIO_IN_OUT22_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT22_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT22_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT22_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT22_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT22_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT22_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT22_IN)
#define HWIO_TLMM_GPIO_IN_OUT22_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT22_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT22_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT22_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG22_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00016008)
#define HWIO_TLMM_GPIO_INTR_CFG22_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00016008)
#define HWIO_TLMM_GPIO_INTR_CFG22_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG22_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG22_ADDR, HWIO_TLMM_GPIO_INTR_CFG22_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG22_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG22_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG22_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG22_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG22_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG22_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG22_IN)
#define HWIO_TLMM_GPIO_INTR_CFG22_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG22_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG22_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG22_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG22_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS22_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001600c)
#define HWIO_TLMM_GPIO_INTR_STATUS22_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001600c)
#define HWIO_TLMM_GPIO_INTR_STATUS22_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS22_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS22_ADDR, HWIO_TLMM_GPIO_INTR_STATUS22_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS22_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS22_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS22_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS22_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS22_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS22_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS22_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS22_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS22_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS22_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00016010)
#define HWIO_TLMM_GPIO_ID_STATUS22_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00016010)
#define HWIO_TLMM_GPIO_ID_STATUS22_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS22_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS22_ADDR, HWIO_TLMM_GPIO_ID_STATUS22_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS22_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS22_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS22_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS22_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG23_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00017000)
#define HWIO_TLMM_GPIO_CFG23_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00017000)
#define HWIO_TLMM_GPIO_CFG23_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG23_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG23_ADDR, HWIO_TLMM_GPIO_CFG23_RMSK)
#define HWIO_TLMM_GPIO_CFG23_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG23_ADDR, m)
#define HWIO_TLMM_GPIO_CFG23_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG23_ADDR,v)
#define HWIO_TLMM_GPIO_CFG23_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG23_ADDR,m,v,HWIO_TLMM_GPIO_CFG23_IN)
#define HWIO_TLMM_GPIO_CFG23_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG23_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG23_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG23_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG23_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG23_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG23_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG23_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG23_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG23_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT23_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00017004)
#define HWIO_TLMM_GPIO_IN_OUT23_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00017004)
#define HWIO_TLMM_GPIO_IN_OUT23_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT23_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT23_ADDR, HWIO_TLMM_GPIO_IN_OUT23_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT23_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT23_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT23_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT23_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT23_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT23_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT23_IN)
#define HWIO_TLMM_GPIO_IN_OUT23_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT23_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT23_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT23_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG23_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00017008)
#define HWIO_TLMM_GPIO_INTR_CFG23_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00017008)
#define HWIO_TLMM_GPIO_INTR_CFG23_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG23_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG23_ADDR, HWIO_TLMM_GPIO_INTR_CFG23_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG23_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG23_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG23_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG23_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG23_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG23_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG23_IN)
#define HWIO_TLMM_GPIO_INTR_CFG23_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG23_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG23_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG23_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG23_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS23_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001700c)
#define HWIO_TLMM_GPIO_INTR_STATUS23_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001700c)
#define HWIO_TLMM_GPIO_INTR_STATUS23_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS23_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS23_ADDR, HWIO_TLMM_GPIO_INTR_STATUS23_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS23_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS23_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS23_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS23_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS23_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS23_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS23_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS23_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS23_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS23_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00017010)
#define HWIO_TLMM_GPIO_ID_STATUS23_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00017010)
#define HWIO_TLMM_GPIO_ID_STATUS23_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS23_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS23_ADDR, HWIO_TLMM_GPIO_ID_STATUS23_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS23_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS23_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS23_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS23_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG28_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x0001c000)
#define HWIO_TLMM_GPIO_CFG28_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x0001c000)
#define HWIO_TLMM_GPIO_CFG28_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG28_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG28_ADDR, HWIO_TLMM_GPIO_CFG28_RMSK)
#define HWIO_TLMM_GPIO_CFG28_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG28_ADDR, m)
#define HWIO_TLMM_GPIO_CFG28_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG28_ADDR,v)
#define HWIO_TLMM_GPIO_CFG28_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG28_ADDR,m,v,HWIO_TLMM_GPIO_CFG28_IN)
#define HWIO_TLMM_GPIO_CFG28_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG28_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG28_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG28_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG28_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG28_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG28_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG28_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG28_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG28_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT28_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x0001c004)
#define HWIO_TLMM_GPIO_IN_OUT28_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x0001c004)
#define HWIO_TLMM_GPIO_IN_OUT28_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT28_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT28_ADDR, HWIO_TLMM_GPIO_IN_OUT28_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT28_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT28_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT28_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT28_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT28_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT28_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT28_IN)
#define HWIO_TLMM_GPIO_IN_OUT28_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT28_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT28_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT28_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG28_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x0001c008)
#define HWIO_TLMM_GPIO_INTR_CFG28_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x0001c008)
#define HWIO_TLMM_GPIO_INTR_CFG28_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG28_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG28_ADDR, HWIO_TLMM_GPIO_INTR_CFG28_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG28_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG28_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG28_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG28_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG28_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG28_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG28_IN)
#define HWIO_TLMM_GPIO_INTR_CFG28_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG28_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG28_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG28_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG28_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS28_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS28_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS28_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS28_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS28_ADDR, HWIO_TLMM_GPIO_INTR_STATUS28_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS28_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS28_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS28_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS28_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS28_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS28_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS28_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS28_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS28_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS28_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x0001c010)
#define HWIO_TLMM_GPIO_ID_STATUS28_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x0001c010)
#define HWIO_TLMM_GPIO_ID_STATUS28_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS28_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS28_ADDR, HWIO_TLMM_GPIO_ID_STATUS28_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS28_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS28_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS28_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS28_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG29_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x0001d000)
#define HWIO_TLMM_GPIO_CFG29_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x0001d000)
#define HWIO_TLMM_GPIO_CFG29_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG29_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG29_ADDR, HWIO_TLMM_GPIO_CFG29_RMSK)
#define HWIO_TLMM_GPIO_CFG29_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG29_ADDR, m)
#define HWIO_TLMM_GPIO_CFG29_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG29_ADDR,v)
#define HWIO_TLMM_GPIO_CFG29_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG29_ADDR,m,v,HWIO_TLMM_GPIO_CFG29_IN)
#define HWIO_TLMM_GPIO_CFG29_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG29_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG29_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG29_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG29_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG29_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG29_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG29_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG29_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG29_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT29_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x0001d004)
#define HWIO_TLMM_GPIO_IN_OUT29_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x0001d004)
#define HWIO_TLMM_GPIO_IN_OUT29_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT29_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT29_ADDR, HWIO_TLMM_GPIO_IN_OUT29_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT29_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT29_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT29_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT29_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT29_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT29_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT29_IN)
#define HWIO_TLMM_GPIO_IN_OUT29_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT29_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT29_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT29_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG29_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x0001d008)
#define HWIO_TLMM_GPIO_INTR_CFG29_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x0001d008)
#define HWIO_TLMM_GPIO_INTR_CFG29_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG29_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG29_ADDR, HWIO_TLMM_GPIO_INTR_CFG29_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG29_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG29_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG29_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG29_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG29_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG29_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG29_IN)
#define HWIO_TLMM_GPIO_INTR_CFG29_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG29_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG29_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG29_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG29_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS29_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS29_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS29_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS29_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS29_ADDR, HWIO_TLMM_GPIO_INTR_STATUS29_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS29_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS29_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS29_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS29_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS29_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS29_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS29_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS29_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS29_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS29_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x0001d010)
#define HWIO_TLMM_GPIO_ID_STATUS29_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x0001d010)
#define HWIO_TLMM_GPIO_ID_STATUS29_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS29_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS29_ADDR, HWIO_TLMM_GPIO_ID_STATUS29_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS29_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS29_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS29_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS29_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG30_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x0001e000)
#define HWIO_TLMM_GPIO_CFG30_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x0001e000)
#define HWIO_TLMM_GPIO_CFG30_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG30_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG30_ADDR, HWIO_TLMM_GPIO_CFG30_RMSK)
#define HWIO_TLMM_GPIO_CFG30_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG30_ADDR, m)
#define HWIO_TLMM_GPIO_CFG30_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG30_ADDR,v)
#define HWIO_TLMM_GPIO_CFG30_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG30_ADDR,m,v,HWIO_TLMM_GPIO_CFG30_IN)
#define HWIO_TLMM_GPIO_CFG30_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG30_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG30_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG30_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG30_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG30_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG30_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG30_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG30_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG30_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT30_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x0001e004)
#define HWIO_TLMM_GPIO_IN_OUT30_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x0001e004)
#define HWIO_TLMM_GPIO_IN_OUT30_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT30_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT30_ADDR, HWIO_TLMM_GPIO_IN_OUT30_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT30_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT30_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT30_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT30_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT30_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT30_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT30_IN)
#define HWIO_TLMM_GPIO_IN_OUT30_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT30_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT30_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT30_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG30_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x0001e008)
#define HWIO_TLMM_GPIO_INTR_CFG30_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x0001e008)
#define HWIO_TLMM_GPIO_INTR_CFG30_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG30_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG30_ADDR, HWIO_TLMM_GPIO_INTR_CFG30_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG30_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG30_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG30_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG30_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG30_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG30_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG30_IN)
#define HWIO_TLMM_GPIO_INTR_CFG30_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG30_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG30_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG30_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG30_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS30_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS30_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS30_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS30_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS30_ADDR, HWIO_TLMM_GPIO_INTR_STATUS30_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS30_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS30_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS30_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS30_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS30_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS30_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS30_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS30_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS30_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS30_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x0001e010)
#define HWIO_TLMM_GPIO_ID_STATUS30_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x0001e010)
#define HWIO_TLMM_GPIO_ID_STATUS30_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS30_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS30_ADDR, HWIO_TLMM_GPIO_ID_STATUS30_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS30_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS30_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS30_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS30_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG31_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x0001f000)
#define HWIO_TLMM_GPIO_CFG31_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x0001f000)
#define HWIO_TLMM_GPIO_CFG31_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG31_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG31_ADDR, HWIO_TLMM_GPIO_CFG31_RMSK)
#define HWIO_TLMM_GPIO_CFG31_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG31_ADDR, m)
#define HWIO_TLMM_GPIO_CFG31_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG31_ADDR,v)
#define HWIO_TLMM_GPIO_CFG31_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG31_ADDR,m,v,HWIO_TLMM_GPIO_CFG31_IN)
#define HWIO_TLMM_GPIO_CFG31_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG31_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG31_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG31_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG31_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG31_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG31_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG31_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG31_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG31_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT31_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x0001f004)
#define HWIO_TLMM_GPIO_IN_OUT31_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x0001f004)
#define HWIO_TLMM_GPIO_IN_OUT31_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT31_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT31_ADDR, HWIO_TLMM_GPIO_IN_OUT31_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT31_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT31_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT31_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT31_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT31_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT31_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT31_IN)
#define HWIO_TLMM_GPIO_IN_OUT31_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT31_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT31_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT31_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG31_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x0001f008)
#define HWIO_TLMM_GPIO_INTR_CFG31_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x0001f008)
#define HWIO_TLMM_GPIO_INTR_CFG31_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG31_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG31_ADDR, HWIO_TLMM_GPIO_INTR_CFG31_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG31_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG31_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG31_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG31_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG31_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG31_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG31_IN)
#define HWIO_TLMM_GPIO_INTR_CFG31_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG31_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG31_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG31_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG31_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS31_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0001f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS31_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0001f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS31_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS31_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS31_ADDR, HWIO_TLMM_GPIO_INTR_STATUS31_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS31_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS31_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS31_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS31_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS31_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS31_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS31_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS31_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS31_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS31_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x0001f010)
#define HWIO_TLMM_GPIO_ID_STATUS31_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x0001f010)
#define HWIO_TLMM_GPIO_ID_STATUS31_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS31_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS31_ADDR, HWIO_TLMM_GPIO_ID_STATUS31_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS31_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS31_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS31_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS31_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG81_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00051000)
#define HWIO_TLMM_GPIO_CFG81_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00051000)
#define HWIO_TLMM_GPIO_CFG81_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG81_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG81_ADDR, HWIO_TLMM_GPIO_CFG81_RMSK)
#define HWIO_TLMM_GPIO_CFG81_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG81_ADDR, m)
#define HWIO_TLMM_GPIO_CFG81_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG81_ADDR,v)
#define HWIO_TLMM_GPIO_CFG81_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG81_ADDR,m,v,HWIO_TLMM_GPIO_CFG81_IN)
#define HWIO_TLMM_GPIO_CFG81_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG81_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG81_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG81_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG81_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG81_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG81_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG81_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG81_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG81_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT81_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00051004)
#define HWIO_TLMM_GPIO_IN_OUT81_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00051004)
#define HWIO_TLMM_GPIO_IN_OUT81_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT81_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT81_ADDR, HWIO_TLMM_GPIO_IN_OUT81_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT81_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT81_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT81_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT81_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT81_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT81_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT81_IN)
#define HWIO_TLMM_GPIO_IN_OUT81_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT81_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT81_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT81_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG81_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00051008)
#define HWIO_TLMM_GPIO_INTR_CFG81_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00051008)
#define HWIO_TLMM_GPIO_INTR_CFG81_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG81_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG81_ADDR, HWIO_TLMM_GPIO_INTR_CFG81_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG81_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG81_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG81_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG81_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG81_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG81_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG81_IN)
#define HWIO_TLMM_GPIO_INTR_CFG81_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG81_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG81_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG81_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG81_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS81_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0005100c)
#define HWIO_TLMM_GPIO_INTR_STATUS81_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0005100c)
#define HWIO_TLMM_GPIO_INTR_STATUS81_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS81_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS81_ADDR, HWIO_TLMM_GPIO_INTR_STATUS81_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS81_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS81_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS81_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS81_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS81_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS81_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS81_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS81_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS81_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS81_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00051010)
#define HWIO_TLMM_GPIO_ID_STATUS81_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00051010)
#define HWIO_TLMM_GPIO_ID_STATUS81_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS81_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS81_ADDR, HWIO_TLMM_GPIO_ID_STATUS81_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS81_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS81_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS81_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS81_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG82_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x00052000)
#define HWIO_TLMM_GPIO_CFG82_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x00052000)
#define HWIO_TLMM_GPIO_CFG82_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG82_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG82_ADDR, HWIO_TLMM_GPIO_CFG82_RMSK)
#define HWIO_TLMM_GPIO_CFG82_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG82_ADDR, m)
#define HWIO_TLMM_GPIO_CFG82_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG82_ADDR,v)
#define HWIO_TLMM_GPIO_CFG82_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG82_ADDR,m,v,HWIO_TLMM_GPIO_CFG82_IN)
#define HWIO_TLMM_GPIO_CFG82_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG82_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG82_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG82_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG82_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG82_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG82_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG82_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG82_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG82_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT82_ADDR                                       (TLMM_CENTER_REG_BASE      + 0x00052004)
#define HWIO_TLMM_GPIO_IN_OUT82_OFFS                                       (TLMM_CENTER_REG_BASE_OFFS + 0x00052004)
#define HWIO_TLMM_GPIO_IN_OUT82_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT82_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT82_ADDR, HWIO_TLMM_GPIO_IN_OUT82_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT82_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT82_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT82_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT82_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT82_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT82_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT82_IN)
#define HWIO_TLMM_GPIO_IN_OUT82_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT82_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT82_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT82_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG82_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00052008)
#define HWIO_TLMM_GPIO_INTR_CFG82_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00052008)
#define HWIO_TLMM_GPIO_INTR_CFG82_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG82_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG82_ADDR, HWIO_TLMM_GPIO_INTR_CFG82_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG82_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG82_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG82_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG82_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG82_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG82_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG82_IN)
#define HWIO_TLMM_GPIO_INTR_CFG82_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG82_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG82_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG82_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG82_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS82_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x0005200c)
#define HWIO_TLMM_GPIO_INTR_STATUS82_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x0005200c)
#define HWIO_TLMM_GPIO_INTR_STATUS82_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS82_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS82_ADDR, HWIO_TLMM_GPIO_INTR_STATUS82_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS82_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS82_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS82_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS82_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS82_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS82_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS82_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS82_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS82_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS82_ADDR                                    (TLMM_CENTER_REG_BASE      + 0x00052010)
#define HWIO_TLMM_GPIO_ID_STATUS82_OFFS                                    (TLMM_CENTER_REG_BASE_OFFS + 0x00052010)
#define HWIO_TLMM_GPIO_ID_STATUS82_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS82_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS82_ADDR, HWIO_TLMM_GPIO_ID_STATUS82_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS82_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS82_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS82_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS82_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_ADDR                          (TLMM_CENTER_REG_BASE      + 0x00096000)
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_OFFS                          (TLMM_CENTER_REG_BASE_OFFS + 0x00096000)
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_RMSK                                0x7f
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_IN          \
        in_dword_masked(HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_ADDR, HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_RMSK)
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_INM(m)      \
        in_dword_masked(HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_ADDR, m)
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_OUT(v)      \
        out_dword(HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_ADDR,v)
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_ADDR,m,v,HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_IN)
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_82_BMSK                        0x40
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_82_SHFT                         0x6
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_31_BMSK                        0x20
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_31_SHFT                         0x5
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_30_BMSK                        0x10
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_30_SHFT                         0x4
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_29_BMSK                         0x8
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_29_SHFT                         0x3
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_28_BMSK                         0x4
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_28_SHFT                         0x2
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_22_BMSK                         0x2
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_22_SHFT                         0x1
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_17_BMSK                         0x1
#define HWIO_TLMM_CENTER_MPM_WAKEUP_INT_EN_0_GPIO_17_SHFT                         0x0

#define HWIO_TLMM_CENTER_CLK_GATE_EN_ADDR                                  (TLMM_CENTER_REG_BASE      + 0x00097000)
#define HWIO_TLMM_CENTER_CLK_GATE_EN_OFFS                                  (TLMM_CENTER_REG_BASE_OFFS + 0x00097000)
#define HWIO_TLMM_CENTER_CLK_GATE_EN_RMSK                                         0x7
#define HWIO_TLMM_CENTER_CLK_GATE_EN_IN          \
        in_dword_masked(HWIO_TLMM_CENTER_CLK_GATE_EN_ADDR, HWIO_TLMM_CENTER_CLK_GATE_EN_RMSK)
#define HWIO_TLMM_CENTER_CLK_GATE_EN_INM(m)      \
        in_dword_masked(HWIO_TLMM_CENTER_CLK_GATE_EN_ADDR, m)
#define HWIO_TLMM_CENTER_CLK_GATE_EN_OUT(v)      \
        out_dword(HWIO_TLMM_CENTER_CLK_GATE_EN_ADDR,v)
#define HWIO_TLMM_CENTER_CLK_GATE_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_CLK_GATE_EN_ADDR,m,v,HWIO_TLMM_CENTER_CLK_GATE_EN_IN)
#define HWIO_TLMM_CENTER_CLK_GATE_EN_AHB_HCLK_EN_BMSK                             0x4
#define HWIO_TLMM_CENTER_CLK_GATE_EN_AHB_HCLK_EN_SHFT                             0x2
#define HWIO_TLMM_CENTER_CLK_GATE_EN_SUMMARY_INTR_EN_BMSK                         0x2
#define HWIO_TLMM_CENTER_CLK_GATE_EN_SUMMARY_INTR_EN_SHFT                         0x1
#define HWIO_TLMM_CENTER_CLK_GATE_EN_CRIF_READ_EN_BMSK                            0x1
#define HWIO_TLMM_CENTER_CLK_GATE_EN_CRIF_READ_EN_SHFT                            0x0

#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_ADDR                              (TLMM_CENTER_REG_BASE      + 0x00097004)
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_OFFS                              (TLMM_CENTER_REG_BASE_OFFS + 0x00097004)
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_RMSK                                     0x1
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_IN          \
        in_dword_masked(HWIO_TLMM_CENTER_IE_CTRL_DISABLE_ADDR, HWIO_TLMM_CENTER_IE_CTRL_DISABLE_RMSK)
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_INM(m)      \
        in_dword_masked(HWIO_TLMM_CENTER_IE_CTRL_DISABLE_ADDR, m)
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_OUT(v)      \
        out_dword(HWIO_TLMM_CENTER_IE_CTRL_DISABLE_ADDR,v)
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_IE_CTRL_DISABLE_ADDR,m,v,HWIO_TLMM_CENTER_IE_CTRL_DISABLE_IN)
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_IE_CTRL_DISABLE_BMSK                     0x1
#define HWIO_TLMM_CENTER_IE_CTRL_DISABLE_IE_CTRL_DISABLE_SHFT                     0x0

#define HWIO_TLMM_DBG_BUS_OUT_ADDR                                         (TLMM_CENTER_REG_BASE      + 0x00098018)
#define HWIO_TLMM_DBG_BUS_OUT_OFFS                                         (TLMM_CENTER_REG_BASE_OFFS + 0x00098018)
#define HWIO_TLMM_DBG_BUS_OUT_RMSK                                         0xffffffff
#define HWIO_TLMM_DBG_BUS_OUT_IN          \
        in_dword_masked(HWIO_TLMM_DBG_BUS_OUT_ADDR, HWIO_TLMM_DBG_BUS_OUT_RMSK)
#define HWIO_TLMM_DBG_BUS_OUT_INM(m)      \
        in_dword_masked(HWIO_TLMM_DBG_BUS_OUT_ADDR, m)
#define HWIO_TLMM_DBG_BUS_OUT_OUT(v)      \
        out_dword(HWIO_TLMM_DBG_BUS_OUT_ADDR,v)
#define HWIO_TLMM_DBG_BUS_OUT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_DBG_BUS_OUT_ADDR,m,v,HWIO_TLMM_DBG_BUS_OUT_IN)
#define HWIO_TLMM_DBG_BUS_OUT_DBG_BUS_OUT_BMSK                             0xffffffff
#define HWIO_TLMM_DBG_BUS_OUT_DBG_BUS_OUT_SHFT                                    0x0

#define HWIO_TLMM_DBG_BUS_EN_ADDR                                          (TLMM_CENTER_REG_BASE      + 0x0009801c)
#define HWIO_TLMM_DBG_BUS_EN_OFFS                                          (TLMM_CENTER_REG_BASE_OFFS + 0x0009801c)
#define HWIO_TLMM_DBG_BUS_EN_RMSK                                                 0x1
#define HWIO_TLMM_DBG_BUS_EN_IN          \
        in_dword_masked(HWIO_TLMM_DBG_BUS_EN_ADDR, HWIO_TLMM_DBG_BUS_EN_RMSK)
#define HWIO_TLMM_DBG_BUS_EN_INM(m)      \
        in_dword_masked(HWIO_TLMM_DBG_BUS_EN_ADDR, m)
#define HWIO_TLMM_DBG_BUS_EN_OUT(v)      \
        out_dword(HWIO_TLMM_DBG_BUS_EN_ADDR,v)
#define HWIO_TLMM_DBG_BUS_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_DBG_BUS_EN_ADDR,m,v,HWIO_TLMM_DBG_BUS_EN_IN)
#define HWIO_TLMM_DBG_BUS_EN_DBG_BUS_ENABLE_BMSK                                  0x1
#define HWIO_TLMM_DBG_BUS_EN_DBG_BUS_ENABLE_SHFT                                  0x0

#define HWIO_TLMM_DBG_BUS_READ_ADDR                                        (TLMM_CENTER_REG_BASE      + 0x00098020)
#define HWIO_TLMM_DBG_BUS_READ_OFFS                                        (TLMM_CENTER_REG_BASE_OFFS + 0x00098020)
#define HWIO_TLMM_DBG_BUS_READ_RMSK                                        0xffffffff
#define HWIO_TLMM_DBG_BUS_READ_IN          \
        in_dword_masked(HWIO_TLMM_DBG_BUS_READ_ADDR, HWIO_TLMM_DBG_BUS_READ_RMSK)
#define HWIO_TLMM_DBG_BUS_READ_INM(m)      \
        in_dword_masked(HWIO_TLMM_DBG_BUS_READ_ADDR, m)
#define HWIO_TLMM_DBG_BUS_READ_DBG_BUS_READ_BMSK                           0xffffffff
#define HWIO_TLMM_DBG_BUS_READ_DBG_BUS_READ_SHFT                                  0x0

#define HWIO_TLMM_PHASE_FLAG_STATUS_ADDR                                   (TLMM_CENTER_REG_BASE      + 0x00098024)
#define HWIO_TLMM_PHASE_FLAG_STATUS_OFFS                                   (TLMM_CENTER_REG_BASE_OFFS + 0x00098024)
#define HWIO_TLMM_PHASE_FLAG_STATUS_RMSK                                   0xffffffff
#define HWIO_TLMM_PHASE_FLAG_STATUS_IN          \
        in_dword_masked(HWIO_TLMM_PHASE_FLAG_STATUS_ADDR, HWIO_TLMM_PHASE_FLAG_STATUS_RMSK)
#define HWIO_TLMM_PHASE_FLAG_STATUS_INM(m)      \
        in_dword_masked(HWIO_TLMM_PHASE_FLAG_STATUS_ADDR, m)
#define HWIO_TLMM_PHASE_FLAG_STATUS_OUT(v)      \
        out_dword(HWIO_TLMM_PHASE_FLAG_STATUS_ADDR,v)
#define HWIO_TLMM_PHASE_FLAG_STATUS_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_PHASE_FLAG_STATUS_ADDR,m,v,HWIO_TLMM_PHASE_FLAG_STATUS_IN)
#define HWIO_TLMM_PHASE_FLAG_STATUS_PHASE_FLAG_STATUS_BMSK                 0xffffffff
#define HWIO_TLMM_PHASE_FLAG_STATUS_PHASE_FLAG_STATUS_SHFT                        0x0

#define HWIO_TLMM_GPIO_GS_I2C_CTL_ADDR                                     (TLMM_CENTER_REG_BASE      + 0x00099000)
#define HWIO_TLMM_GPIO_GS_I2C_CTL_OFFS                                     (TLMM_CENTER_REG_BASE_OFFS + 0x00099000)
#define HWIO_TLMM_GPIO_GS_I2C_CTL_RMSK                                            0x3
#define HWIO_TLMM_GPIO_GS_I2C_CTL_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_GS_I2C_CTL_ADDR, HWIO_TLMM_GPIO_GS_I2C_CTL_RMSK)
#define HWIO_TLMM_GPIO_GS_I2C_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_GS_I2C_CTL_ADDR, m)
#define HWIO_TLMM_GPIO_GS_I2C_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_GS_I2C_CTL_ADDR,v)
#define HWIO_TLMM_GPIO_GS_I2C_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_GS_I2C_CTL_ADDR,m,v,HWIO_TLMM_GPIO_GS_I2C_CTL_IN)
#define HWIO_TLMM_GPIO_GS_I2C_CTL_MODE_BMSK                                       0x3
#define HWIO_TLMM_GPIO_GS_I2C_CTL_MODE_SHFT                                       0x0

#define HWIO_TLMM_CENTER_SPARE_ADDR                                        (TLMM_CENTER_REG_BASE      + 0x0009a000)
#define HWIO_TLMM_CENTER_SPARE_OFFS                                        (TLMM_CENTER_REG_BASE_OFFS + 0x0009a000)
#define HWIO_TLMM_CENTER_SPARE_RMSK                                        0xffffffff
#define HWIO_TLMM_CENTER_SPARE_IN          \
        in_dword_masked(HWIO_TLMM_CENTER_SPARE_ADDR, HWIO_TLMM_CENTER_SPARE_RMSK)
#define HWIO_TLMM_CENTER_SPARE_INM(m)      \
        in_dword_masked(HWIO_TLMM_CENTER_SPARE_ADDR, m)
#define HWIO_TLMM_CENTER_SPARE_OUT(v)      \
        out_dword(HWIO_TLMM_CENTER_SPARE_ADDR,v)
#define HWIO_TLMM_CENTER_SPARE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_SPARE_ADDR,m,v,HWIO_TLMM_CENTER_SPARE_IN)
#define HWIO_TLMM_CENTER_SPARE_SPARE_BMSK                                  0xffffff00
#define HWIO_TLMM_CENTER_SPARE_SPARE_SHFT                                         0x8
#define HWIO_TLMM_CENTER_SPARE_MISC_BMSK                                         0xff
#define HWIO_TLMM_CENTER_SPARE_MISC_SHFT                                          0x0

#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n)                (TLMM_CENTER_REG_BASE      + 0x0009b000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_OFFS(n)                (TLMM_CENTER_REG_BASE_OFFS + 0x0009b000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_RMSK                        0x1ff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_MAXn                            1
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_INI(n)        \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n), HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_RMSK)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n), mask)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n),val)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n),mask,val,HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_INI(n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_POLARITY_BMSK               0x100
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_POLARITY_SHFT                 0x8
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_GPIO_SEL_BMSK                0xff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_SENSORS_GPIO_SEL_SHFT                 0x0

#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n)                (TLMM_CENTER_REG_BASE      + 0x0009c000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_OFFS(n)                (TLMM_CENTER_REG_BASE_OFFS + 0x0009c000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_RMSK                        0x1ff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_MAXn                            5
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_INI(n)        \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n), HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_RMSK)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n), mask)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_OUTI(n,val)    \
        out_dword(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n),val)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n),mask,val,HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_INI(n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_POLARITY_BMSK               0x100
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_POLARITY_SHFT                 0x8
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_GPIO_SEL_BMSK                0xff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_LPA_DSP_GPIO_SEL_SHFT                 0x0

#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_ADDR(n)                    (TLMM_CENTER_REG_BASE      + 0x0009d000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_OFFS(n)                    (TLMM_CENTER_REG_BASE_OFFS + 0x0009d000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_RMSK                            0x1ff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_MAXn                                0
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_INI(n)        \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_ADDR(n), HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_RMSK)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_ADDR(n), mask)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_OUTI(n,val)    \
        out_dword(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_ADDR(n),val)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_ADDR(n),mask,val,HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_INI(n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_POLARITY_BMSK                   0x100
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_POLARITY_SHFT                     0x8
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_GPIO_SEL_BMSK                    0xff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_RPM_GPIO_SEL_SHFT                     0x0

#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_ADDR(n)                   (TLMM_CENTER_REG_BASE      + 0x0009e000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_OFFS(n)                   (TLMM_CENTER_REG_BASE_OFFS + 0x0009e000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_RMSK                           0x1ff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_MAXn                               7
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_INI(n)        \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_ADDR(n), HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_RMSK)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_ADDR(n), mask)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_ADDR(n),val)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_ADDR(n),mask,val,HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_INI(n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_POLARITY_BMSK                  0x100
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_POLARITY_SHFT                    0x8
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_GPIO_SEL_BMSK                   0xff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_HMSS_GPIO_SEL_SHFT                    0x0

#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_ADDR(n)                    (TLMM_CENTER_REG_BASE      + 0x0009f000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_OFFS(n)                    (TLMM_CENTER_REG_BASE_OFFS + 0x0009f000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_RMSK                            0x1ff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_MAXn                                1
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_INI(n)        \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_ADDR(n), HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_RMSK)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_ADDR(n), mask)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_ADDR(n),val)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_ADDR(n),mask,val,HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_INI(n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_POLARITY_BMSK                   0x100
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_POLARITY_SHFT                     0x8
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_GPIO_SEL_BMSK                    0xff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_GSS_GPIO_SEL_SHFT                     0x0

#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_ADDR(n)                   (TLMM_CENTER_REG_BASE      + 0x000a0000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_OFFS(n)                   (TLMM_CENTER_REG_BASE_OFFS + 0x000a0000 + 0x4 * (n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_RMSK                           0x1ff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_MAXn                               1
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_INI(n)        \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_ADDR(n), HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_RMSK)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_ADDR(n), mask)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_OUTI(n,val)    \
        out_dword(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_ADDR(n),val)
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_ADDR(n),mask,val,HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_INI(n))
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_POLARITY_BMSK                  0x100
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_POLARITY_SHFT                    0x8
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_GPIO_SEL_BMSK                   0xff
#define HWIO_TLMM_CENTER_DIR_CONN_INTRn_CFG_CDSP_GPIO_SEL_SHFT                    0x0

/*----------------------------------------------------------------------------
 * MODULE: TLMM_NORTH
 *--------------------------------------------------------------------------*/

#define TLMM_NORTH_REG_BASE                                                (TLMM_BASE      + 0x00900000)
#define TLMM_NORTH_REG_BASE_OFFS                                           0x00900000

#define HWIO_TLMM_GPIO_CFG4_ADDR                                           (TLMM_NORTH_REG_BASE      + 0x00004000)
#define HWIO_TLMM_GPIO_CFG4_OFFS                                           (TLMM_NORTH_REG_BASE_OFFS + 0x00004000)
#define HWIO_TLMM_GPIO_CFG4_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG4_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG4_ADDR, HWIO_TLMM_GPIO_CFG4_RMSK)
#define HWIO_TLMM_GPIO_CFG4_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG4_ADDR, m)
#define HWIO_TLMM_GPIO_CFG4_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG4_ADDR,v)
#define HWIO_TLMM_GPIO_CFG4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG4_ADDR,m,v,HWIO_TLMM_GPIO_CFG4_IN)
#define HWIO_TLMM_GPIO_CFG4_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG4_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG4_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG4_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG4_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG4_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG4_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG4_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG4_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG4_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT4_ADDR                                        (TLMM_NORTH_REG_BASE      + 0x00004004)
#define HWIO_TLMM_GPIO_IN_OUT4_OFFS                                        (TLMM_NORTH_REG_BASE_OFFS + 0x00004004)
#define HWIO_TLMM_GPIO_IN_OUT4_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT4_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT4_ADDR, HWIO_TLMM_GPIO_IN_OUT4_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT4_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT4_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT4_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT4_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT4_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT4_IN)
#define HWIO_TLMM_GPIO_IN_OUT4_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT4_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT4_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT4_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG4_ADDR                                      (TLMM_NORTH_REG_BASE      + 0x00004008)
#define HWIO_TLMM_GPIO_INTR_CFG4_OFFS                                      (TLMM_NORTH_REG_BASE_OFFS + 0x00004008)
#define HWIO_TLMM_GPIO_INTR_CFG4_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG4_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG4_ADDR, HWIO_TLMM_GPIO_INTR_CFG4_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG4_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG4_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG4_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG4_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG4_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG4_IN)
#define HWIO_TLMM_GPIO_INTR_CFG4_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG4_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG4_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG4_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG4_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS4_ADDR                                   (TLMM_NORTH_REG_BASE      + 0x0000400c)
#define HWIO_TLMM_GPIO_INTR_STATUS4_OFFS                                   (TLMM_NORTH_REG_BASE_OFFS + 0x0000400c)
#define HWIO_TLMM_GPIO_INTR_STATUS4_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS4_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS4_ADDR, HWIO_TLMM_GPIO_INTR_STATUS4_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS4_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS4_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS4_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS4_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS4_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS4_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS4_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS4_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS4_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS4_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00004010)
#define HWIO_TLMM_GPIO_ID_STATUS4_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00004010)
#define HWIO_TLMM_GPIO_ID_STATUS4_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS4_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS4_ADDR, HWIO_TLMM_GPIO_ID_STATUS4_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS4_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS4_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS4_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS4_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG8_ADDR                                           (TLMM_NORTH_REG_BASE      + 0x00008000)
#define HWIO_TLMM_GPIO_CFG8_OFFS                                           (TLMM_NORTH_REG_BASE_OFFS + 0x00008000)
#define HWIO_TLMM_GPIO_CFG8_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG8_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG8_ADDR, HWIO_TLMM_GPIO_CFG8_RMSK)
#define HWIO_TLMM_GPIO_CFG8_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG8_ADDR, m)
#define HWIO_TLMM_GPIO_CFG8_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG8_ADDR,v)
#define HWIO_TLMM_GPIO_CFG8_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG8_ADDR,m,v,HWIO_TLMM_GPIO_CFG8_IN)
#define HWIO_TLMM_GPIO_CFG8_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG8_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG8_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG8_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG8_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG8_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG8_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG8_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG8_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG8_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT8_ADDR                                        (TLMM_NORTH_REG_BASE      + 0x00008004)
#define HWIO_TLMM_GPIO_IN_OUT8_OFFS                                        (TLMM_NORTH_REG_BASE_OFFS + 0x00008004)
#define HWIO_TLMM_GPIO_IN_OUT8_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT8_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT8_ADDR, HWIO_TLMM_GPIO_IN_OUT8_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT8_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT8_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT8_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT8_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT8_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT8_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT8_IN)
#define HWIO_TLMM_GPIO_IN_OUT8_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT8_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT8_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT8_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG8_ADDR                                      (TLMM_NORTH_REG_BASE      + 0x00008008)
#define HWIO_TLMM_GPIO_INTR_CFG8_OFFS                                      (TLMM_NORTH_REG_BASE_OFFS + 0x00008008)
#define HWIO_TLMM_GPIO_INTR_CFG8_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG8_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG8_ADDR, HWIO_TLMM_GPIO_INTR_CFG8_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG8_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG8_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG8_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG8_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG8_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG8_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG8_IN)
#define HWIO_TLMM_GPIO_INTR_CFG8_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG8_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG8_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG8_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG8_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS8_ADDR                                   (TLMM_NORTH_REG_BASE      + 0x0000800c)
#define HWIO_TLMM_GPIO_INTR_STATUS8_OFFS                                   (TLMM_NORTH_REG_BASE_OFFS + 0x0000800c)
#define HWIO_TLMM_GPIO_INTR_STATUS8_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS8_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS8_ADDR, HWIO_TLMM_GPIO_INTR_STATUS8_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS8_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS8_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS8_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS8_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS8_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS8_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS8_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS8_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS8_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS8_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00008010)
#define HWIO_TLMM_GPIO_ID_STATUS8_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00008010)
#define HWIO_TLMM_GPIO_ID_STATUS8_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS8_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS8_ADDR, HWIO_TLMM_GPIO_ID_STATUS8_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS8_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS8_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS8_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS8_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG9_ADDR                                           (TLMM_NORTH_REG_BASE      + 0x00009000)
#define HWIO_TLMM_GPIO_CFG9_OFFS                                           (TLMM_NORTH_REG_BASE_OFFS + 0x00009000)
#define HWIO_TLMM_GPIO_CFG9_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG9_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG9_ADDR, HWIO_TLMM_GPIO_CFG9_RMSK)
#define HWIO_TLMM_GPIO_CFG9_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG9_ADDR, m)
#define HWIO_TLMM_GPIO_CFG9_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG9_ADDR,v)
#define HWIO_TLMM_GPIO_CFG9_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG9_ADDR,m,v,HWIO_TLMM_GPIO_CFG9_IN)
#define HWIO_TLMM_GPIO_CFG9_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG9_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG9_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG9_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG9_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG9_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG9_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG9_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG9_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG9_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT9_ADDR                                        (TLMM_NORTH_REG_BASE      + 0x00009004)
#define HWIO_TLMM_GPIO_IN_OUT9_OFFS                                        (TLMM_NORTH_REG_BASE_OFFS + 0x00009004)
#define HWIO_TLMM_GPIO_IN_OUT9_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT9_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT9_ADDR, HWIO_TLMM_GPIO_IN_OUT9_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT9_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT9_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT9_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT9_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT9_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT9_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT9_IN)
#define HWIO_TLMM_GPIO_IN_OUT9_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT9_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT9_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT9_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG9_ADDR                                      (TLMM_NORTH_REG_BASE      + 0x00009008)
#define HWIO_TLMM_GPIO_INTR_CFG9_OFFS                                      (TLMM_NORTH_REG_BASE_OFFS + 0x00009008)
#define HWIO_TLMM_GPIO_INTR_CFG9_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG9_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG9_ADDR, HWIO_TLMM_GPIO_INTR_CFG9_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG9_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG9_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG9_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG9_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG9_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG9_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG9_IN)
#define HWIO_TLMM_GPIO_INTR_CFG9_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG9_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG9_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG9_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG9_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS9_ADDR                                   (TLMM_NORTH_REG_BASE      + 0x0000900c)
#define HWIO_TLMM_GPIO_INTR_STATUS9_OFFS                                   (TLMM_NORTH_REG_BASE_OFFS + 0x0000900c)
#define HWIO_TLMM_GPIO_INTR_STATUS9_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS9_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS9_ADDR, HWIO_TLMM_GPIO_INTR_STATUS9_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS9_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS9_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS9_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS9_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS9_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS9_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS9_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS9_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS9_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS9_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00009010)
#define HWIO_TLMM_GPIO_ID_STATUS9_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00009010)
#define HWIO_TLMM_GPIO_ID_STATUS9_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS9_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS9_ADDR, HWIO_TLMM_GPIO_ID_STATUS9_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS9_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS9_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS9_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS9_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG10_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0000a000)
#define HWIO_TLMM_GPIO_CFG10_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0000a000)
#define HWIO_TLMM_GPIO_CFG10_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG10_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG10_ADDR, HWIO_TLMM_GPIO_CFG10_RMSK)
#define HWIO_TLMM_GPIO_CFG10_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG10_ADDR, m)
#define HWIO_TLMM_GPIO_CFG10_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG10_ADDR,v)
#define HWIO_TLMM_GPIO_CFG10_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG10_ADDR,m,v,HWIO_TLMM_GPIO_CFG10_IN)
#define HWIO_TLMM_GPIO_CFG10_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG10_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG10_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG10_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG10_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG10_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG10_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG10_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG10_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG10_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT10_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0000a004)
#define HWIO_TLMM_GPIO_IN_OUT10_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0000a004)
#define HWIO_TLMM_GPIO_IN_OUT10_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT10_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT10_ADDR, HWIO_TLMM_GPIO_IN_OUT10_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT10_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT10_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT10_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT10_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT10_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT10_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT10_IN)
#define HWIO_TLMM_GPIO_IN_OUT10_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT10_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT10_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT10_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG10_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0000a008)
#define HWIO_TLMM_GPIO_INTR_CFG10_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0000a008)
#define HWIO_TLMM_GPIO_INTR_CFG10_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG10_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG10_ADDR, HWIO_TLMM_GPIO_INTR_CFG10_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG10_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG10_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG10_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG10_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG10_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG10_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG10_IN)
#define HWIO_TLMM_GPIO_INTR_CFG10_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG10_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG10_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG10_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG10_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS10_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0000a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS10_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0000a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS10_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS10_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS10_ADDR, HWIO_TLMM_GPIO_INTR_STATUS10_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS10_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS10_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS10_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS10_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS10_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS10_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS10_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS10_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS10_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS10_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0000a010)
#define HWIO_TLMM_GPIO_ID_STATUS10_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0000a010)
#define HWIO_TLMM_GPIO_ID_STATUS10_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS10_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS10_ADDR, HWIO_TLMM_GPIO_ID_STATUS10_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS10_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS10_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS10_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS10_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG11_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0000b000)
#define HWIO_TLMM_GPIO_CFG11_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0000b000)
#define HWIO_TLMM_GPIO_CFG11_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG11_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG11_ADDR, HWIO_TLMM_GPIO_CFG11_RMSK)
#define HWIO_TLMM_GPIO_CFG11_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG11_ADDR, m)
#define HWIO_TLMM_GPIO_CFG11_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG11_ADDR,v)
#define HWIO_TLMM_GPIO_CFG11_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG11_ADDR,m,v,HWIO_TLMM_GPIO_CFG11_IN)
#define HWIO_TLMM_GPIO_CFG11_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG11_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG11_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG11_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG11_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG11_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG11_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG11_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG11_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG11_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT11_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0000b004)
#define HWIO_TLMM_GPIO_IN_OUT11_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0000b004)
#define HWIO_TLMM_GPIO_IN_OUT11_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT11_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT11_ADDR, HWIO_TLMM_GPIO_IN_OUT11_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT11_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT11_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT11_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT11_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT11_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT11_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT11_IN)
#define HWIO_TLMM_GPIO_IN_OUT11_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT11_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT11_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT11_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG11_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0000b008)
#define HWIO_TLMM_GPIO_INTR_CFG11_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0000b008)
#define HWIO_TLMM_GPIO_INTR_CFG11_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG11_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG11_ADDR, HWIO_TLMM_GPIO_INTR_CFG11_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG11_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG11_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG11_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG11_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG11_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG11_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG11_IN)
#define HWIO_TLMM_GPIO_INTR_CFG11_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG11_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG11_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG11_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG11_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS11_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0000b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS11_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0000b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS11_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS11_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS11_ADDR, HWIO_TLMM_GPIO_INTR_STATUS11_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS11_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS11_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS11_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS11_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS11_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS11_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS11_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS11_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS11_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS11_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0000b010)
#define HWIO_TLMM_GPIO_ID_STATUS11_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0000b010)
#define HWIO_TLMM_GPIO_ID_STATUS11_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS11_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS11_ADDR, HWIO_TLMM_GPIO_ID_STATUS11_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS11_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS11_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS11_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS11_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG12_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0000c000)
#define HWIO_TLMM_GPIO_CFG12_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0000c000)
#define HWIO_TLMM_GPIO_CFG12_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG12_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG12_ADDR, HWIO_TLMM_GPIO_CFG12_RMSK)
#define HWIO_TLMM_GPIO_CFG12_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG12_ADDR, m)
#define HWIO_TLMM_GPIO_CFG12_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG12_ADDR,v)
#define HWIO_TLMM_GPIO_CFG12_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG12_ADDR,m,v,HWIO_TLMM_GPIO_CFG12_IN)
#define HWIO_TLMM_GPIO_CFG12_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG12_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG12_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG12_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG12_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG12_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG12_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG12_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG12_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG12_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT12_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0000c004)
#define HWIO_TLMM_GPIO_IN_OUT12_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0000c004)
#define HWIO_TLMM_GPIO_IN_OUT12_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT12_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT12_ADDR, HWIO_TLMM_GPIO_IN_OUT12_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT12_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT12_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT12_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT12_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT12_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT12_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT12_IN)
#define HWIO_TLMM_GPIO_IN_OUT12_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT12_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT12_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT12_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG12_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0000c008)
#define HWIO_TLMM_GPIO_INTR_CFG12_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0000c008)
#define HWIO_TLMM_GPIO_INTR_CFG12_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG12_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG12_ADDR, HWIO_TLMM_GPIO_INTR_CFG12_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG12_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG12_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG12_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG12_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG12_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG12_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG12_IN)
#define HWIO_TLMM_GPIO_INTR_CFG12_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG12_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG12_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG12_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG12_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS12_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0000c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS12_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0000c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS12_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS12_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS12_ADDR, HWIO_TLMM_GPIO_INTR_STATUS12_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS12_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS12_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS12_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS12_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS12_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS12_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS12_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS12_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS12_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS12_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0000c010)
#define HWIO_TLMM_GPIO_ID_STATUS12_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0000c010)
#define HWIO_TLMM_GPIO_ID_STATUS12_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS12_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS12_ADDR, HWIO_TLMM_GPIO_ID_STATUS12_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS12_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS12_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS12_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS12_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG13_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0000d000)
#define HWIO_TLMM_GPIO_CFG13_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0000d000)
#define HWIO_TLMM_GPIO_CFG13_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG13_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG13_ADDR, HWIO_TLMM_GPIO_CFG13_RMSK)
#define HWIO_TLMM_GPIO_CFG13_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG13_ADDR, m)
#define HWIO_TLMM_GPIO_CFG13_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG13_ADDR,v)
#define HWIO_TLMM_GPIO_CFG13_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG13_ADDR,m,v,HWIO_TLMM_GPIO_CFG13_IN)
#define HWIO_TLMM_GPIO_CFG13_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG13_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG13_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG13_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG13_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG13_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG13_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG13_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG13_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG13_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT13_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0000d004)
#define HWIO_TLMM_GPIO_IN_OUT13_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0000d004)
#define HWIO_TLMM_GPIO_IN_OUT13_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT13_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT13_ADDR, HWIO_TLMM_GPIO_IN_OUT13_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT13_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT13_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT13_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT13_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT13_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT13_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT13_IN)
#define HWIO_TLMM_GPIO_IN_OUT13_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT13_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT13_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT13_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG13_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0000d008)
#define HWIO_TLMM_GPIO_INTR_CFG13_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0000d008)
#define HWIO_TLMM_GPIO_INTR_CFG13_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG13_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG13_ADDR, HWIO_TLMM_GPIO_INTR_CFG13_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG13_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG13_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG13_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG13_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG13_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG13_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG13_IN)
#define HWIO_TLMM_GPIO_INTR_CFG13_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG13_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG13_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG13_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG13_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS13_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0000d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS13_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0000d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS13_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS13_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS13_ADDR, HWIO_TLMM_GPIO_INTR_STATUS13_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS13_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS13_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS13_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS13_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS13_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS13_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS13_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS13_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS13_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS13_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0000d010)
#define HWIO_TLMM_GPIO_ID_STATUS13_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0000d010)
#define HWIO_TLMM_GPIO_ID_STATUS13_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS13_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS13_ADDR, HWIO_TLMM_GPIO_ID_STATUS13_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS13_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS13_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS13_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS13_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG14_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0000e000)
#define HWIO_TLMM_GPIO_CFG14_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0000e000)
#define HWIO_TLMM_GPIO_CFG14_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG14_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG14_ADDR, HWIO_TLMM_GPIO_CFG14_RMSK)
#define HWIO_TLMM_GPIO_CFG14_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG14_ADDR, m)
#define HWIO_TLMM_GPIO_CFG14_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG14_ADDR,v)
#define HWIO_TLMM_GPIO_CFG14_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG14_ADDR,m,v,HWIO_TLMM_GPIO_CFG14_IN)
#define HWIO_TLMM_GPIO_CFG14_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG14_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG14_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG14_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG14_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG14_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG14_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG14_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG14_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG14_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT14_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0000e004)
#define HWIO_TLMM_GPIO_IN_OUT14_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0000e004)
#define HWIO_TLMM_GPIO_IN_OUT14_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT14_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT14_ADDR, HWIO_TLMM_GPIO_IN_OUT14_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT14_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT14_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT14_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT14_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT14_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT14_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT14_IN)
#define HWIO_TLMM_GPIO_IN_OUT14_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT14_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT14_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT14_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG14_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0000e008)
#define HWIO_TLMM_GPIO_INTR_CFG14_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0000e008)
#define HWIO_TLMM_GPIO_INTR_CFG14_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG14_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG14_ADDR, HWIO_TLMM_GPIO_INTR_CFG14_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG14_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG14_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG14_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG14_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG14_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG14_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG14_IN)
#define HWIO_TLMM_GPIO_INTR_CFG14_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG14_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG14_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG14_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG14_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS14_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0000e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS14_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0000e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS14_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS14_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS14_ADDR, HWIO_TLMM_GPIO_INTR_STATUS14_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS14_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS14_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS14_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS14_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS14_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS14_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS14_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS14_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS14_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS14_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0000e010)
#define HWIO_TLMM_GPIO_ID_STATUS14_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0000e010)
#define HWIO_TLMM_GPIO_ID_STATUS14_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS14_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS14_ADDR, HWIO_TLMM_GPIO_ID_STATUS14_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS14_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS14_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS14_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS14_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG15_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0000f000)
#define HWIO_TLMM_GPIO_CFG15_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0000f000)
#define HWIO_TLMM_GPIO_CFG15_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG15_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG15_ADDR, HWIO_TLMM_GPIO_CFG15_RMSK)
#define HWIO_TLMM_GPIO_CFG15_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG15_ADDR, m)
#define HWIO_TLMM_GPIO_CFG15_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG15_ADDR,v)
#define HWIO_TLMM_GPIO_CFG15_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG15_ADDR,m,v,HWIO_TLMM_GPIO_CFG15_IN)
#define HWIO_TLMM_GPIO_CFG15_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG15_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG15_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG15_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG15_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG15_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG15_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG15_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG15_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG15_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT15_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0000f004)
#define HWIO_TLMM_GPIO_IN_OUT15_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0000f004)
#define HWIO_TLMM_GPIO_IN_OUT15_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT15_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT15_ADDR, HWIO_TLMM_GPIO_IN_OUT15_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT15_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT15_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT15_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT15_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT15_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT15_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT15_IN)
#define HWIO_TLMM_GPIO_IN_OUT15_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT15_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT15_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT15_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG15_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0000f008)
#define HWIO_TLMM_GPIO_INTR_CFG15_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0000f008)
#define HWIO_TLMM_GPIO_INTR_CFG15_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG15_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG15_ADDR, HWIO_TLMM_GPIO_INTR_CFG15_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG15_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG15_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG15_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG15_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG15_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG15_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG15_IN)
#define HWIO_TLMM_GPIO_INTR_CFG15_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG15_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG15_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG15_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG15_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS15_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0000f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS15_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0000f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS15_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS15_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS15_ADDR, HWIO_TLMM_GPIO_INTR_STATUS15_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS15_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS15_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS15_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS15_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS15_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS15_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS15_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS15_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS15_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS15_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0000f010)
#define HWIO_TLMM_GPIO_ID_STATUS15_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0000f010)
#define HWIO_TLMM_GPIO_ID_STATUS15_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS15_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS15_ADDR, HWIO_TLMM_GPIO_ID_STATUS15_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS15_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS15_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS15_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS15_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG24_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00018000)
#define HWIO_TLMM_GPIO_CFG24_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00018000)
#define HWIO_TLMM_GPIO_CFG24_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG24_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG24_ADDR, HWIO_TLMM_GPIO_CFG24_RMSK)
#define HWIO_TLMM_GPIO_CFG24_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG24_ADDR, m)
#define HWIO_TLMM_GPIO_CFG24_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG24_ADDR,v)
#define HWIO_TLMM_GPIO_CFG24_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG24_ADDR,m,v,HWIO_TLMM_GPIO_CFG24_IN)
#define HWIO_TLMM_GPIO_CFG24_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG24_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG24_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG24_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG24_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG24_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG24_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG24_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG24_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG24_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT24_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00018004)
#define HWIO_TLMM_GPIO_IN_OUT24_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00018004)
#define HWIO_TLMM_GPIO_IN_OUT24_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT24_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT24_ADDR, HWIO_TLMM_GPIO_IN_OUT24_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT24_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT24_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT24_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT24_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT24_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT24_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT24_IN)
#define HWIO_TLMM_GPIO_IN_OUT24_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT24_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT24_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT24_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG24_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00018008)
#define HWIO_TLMM_GPIO_INTR_CFG24_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00018008)
#define HWIO_TLMM_GPIO_INTR_CFG24_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG24_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG24_ADDR, HWIO_TLMM_GPIO_INTR_CFG24_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG24_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG24_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG24_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG24_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG24_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG24_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG24_IN)
#define HWIO_TLMM_GPIO_INTR_CFG24_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG24_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG24_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG24_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG24_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS24_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0001800c)
#define HWIO_TLMM_GPIO_INTR_STATUS24_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0001800c)
#define HWIO_TLMM_GPIO_INTR_STATUS24_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS24_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS24_ADDR, HWIO_TLMM_GPIO_INTR_STATUS24_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS24_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS24_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS24_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS24_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS24_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS24_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS24_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS24_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS24_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS24_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00018010)
#define HWIO_TLMM_GPIO_ID_STATUS24_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00018010)
#define HWIO_TLMM_GPIO_ID_STATUS24_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS24_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS24_ADDR, HWIO_TLMM_GPIO_ID_STATUS24_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS24_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS24_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS24_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS24_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG25_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00019000)
#define HWIO_TLMM_GPIO_CFG25_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00019000)
#define HWIO_TLMM_GPIO_CFG25_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG25_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG25_ADDR, HWIO_TLMM_GPIO_CFG25_RMSK)
#define HWIO_TLMM_GPIO_CFG25_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG25_ADDR, m)
#define HWIO_TLMM_GPIO_CFG25_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG25_ADDR,v)
#define HWIO_TLMM_GPIO_CFG25_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG25_ADDR,m,v,HWIO_TLMM_GPIO_CFG25_IN)
#define HWIO_TLMM_GPIO_CFG25_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG25_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG25_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG25_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG25_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG25_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG25_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG25_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG25_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG25_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT25_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00019004)
#define HWIO_TLMM_GPIO_IN_OUT25_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00019004)
#define HWIO_TLMM_GPIO_IN_OUT25_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT25_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT25_ADDR, HWIO_TLMM_GPIO_IN_OUT25_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT25_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT25_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT25_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT25_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT25_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT25_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT25_IN)
#define HWIO_TLMM_GPIO_IN_OUT25_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT25_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT25_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT25_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG25_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00019008)
#define HWIO_TLMM_GPIO_INTR_CFG25_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00019008)
#define HWIO_TLMM_GPIO_INTR_CFG25_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG25_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG25_ADDR, HWIO_TLMM_GPIO_INTR_CFG25_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG25_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG25_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG25_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG25_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG25_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG25_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG25_IN)
#define HWIO_TLMM_GPIO_INTR_CFG25_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG25_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG25_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG25_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG25_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS25_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0001900c)
#define HWIO_TLMM_GPIO_INTR_STATUS25_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0001900c)
#define HWIO_TLMM_GPIO_INTR_STATUS25_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS25_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS25_ADDR, HWIO_TLMM_GPIO_INTR_STATUS25_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS25_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS25_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS25_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS25_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS25_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS25_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS25_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS25_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS25_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS25_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00019010)
#define HWIO_TLMM_GPIO_ID_STATUS25_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00019010)
#define HWIO_TLMM_GPIO_ID_STATUS25_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS25_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS25_ADDR, HWIO_TLMM_GPIO_ID_STATUS25_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS25_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS25_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS25_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS25_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG26_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0001a000)
#define HWIO_TLMM_GPIO_CFG26_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0001a000)
#define HWIO_TLMM_GPIO_CFG26_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG26_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG26_ADDR, HWIO_TLMM_GPIO_CFG26_RMSK)
#define HWIO_TLMM_GPIO_CFG26_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG26_ADDR, m)
#define HWIO_TLMM_GPIO_CFG26_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG26_ADDR,v)
#define HWIO_TLMM_GPIO_CFG26_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG26_ADDR,m,v,HWIO_TLMM_GPIO_CFG26_IN)
#define HWIO_TLMM_GPIO_CFG26_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG26_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG26_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG26_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG26_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG26_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG26_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG26_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG26_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG26_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT26_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0001a004)
#define HWIO_TLMM_GPIO_IN_OUT26_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0001a004)
#define HWIO_TLMM_GPIO_IN_OUT26_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT26_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT26_ADDR, HWIO_TLMM_GPIO_IN_OUT26_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT26_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT26_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT26_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT26_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT26_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT26_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT26_IN)
#define HWIO_TLMM_GPIO_IN_OUT26_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT26_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT26_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT26_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG26_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0001a008)
#define HWIO_TLMM_GPIO_INTR_CFG26_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0001a008)
#define HWIO_TLMM_GPIO_INTR_CFG26_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG26_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG26_ADDR, HWIO_TLMM_GPIO_INTR_CFG26_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG26_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG26_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG26_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG26_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG26_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG26_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG26_IN)
#define HWIO_TLMM_GPIO_INTR_CFG26_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG26_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG26_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG26_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG26_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS26_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0001a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS26_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0001a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS26_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS26_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS26_ADDR, HWIO_TLMM_GPIO_INTR_STATUS26_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS26_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS26_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS26_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS26_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS26_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS26_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS26_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS26_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS26_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS26_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0001a010)
#define HWIO_TLMM_GPIO_ID_STATUS26_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0001a010)
#define HWIO_TLMM_GPIO_ID_STATUS26_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS26_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS26_ADDR, HWIO_TLMM_GPIO_ID_STATUS26_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS26_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS26_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS26_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS26_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG27_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0001b000)
#define HWIO_TLMM_GPIO_CFG27_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0001b000)
#define HWIO_TLMM_GPIO_CFG27_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG27_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG27_ADDR, HWIO_TLMM_GPIO_CFG27_RMSK)
#define HWIO_TLMM_GPIO_CFG27_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG27_ADDR, m)
#define HWIO_TLMM_GPIO_CFG27_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG27_ADDR,v)
#define HWIO_TLMM_GPIO_CFG27_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG27_ADDR,m,v,HWIO_TLMM_GPIO_CFG27_IN)
#define HWIO_TLMM_GPIO_CFG27_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG27_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG27_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG27_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG27_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG27_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG27_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG27_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG27_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG27_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT27_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0001b004)
#define HWIO_TLMM_GPIO_IN_OUT27_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0001b004)
#define HWIO_TLMM_GPIO_IN_OUT27_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT27_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT27_ADDR, HWIO_TLMM_GPIO_IN_OUT27_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT27_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT27_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT27_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT27_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT27_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT27_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT27_IN)
#define HWIO_TLMM_GPIO_IN_OUT27_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT27_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT27_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT27_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG27_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0001b008)
#define HWIO_TLMM_GPIO_INTR_CFG27_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0001b008)
#define HWIO_TLMM_GPIO_INTR_CFG27_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG27_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG27_ADDR, HWIO_TLMM_GPIO_INTR_CFG27_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG27_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG27_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG27_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG27_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG27_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG27_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG27_IN)
#define HWIO_TLMM_GPIO_INTR_CFG27_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG27_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG27_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG27_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG27_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS27_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0001b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS27_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0001b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS27_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS27_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS27_ADDR, HWIO_TLMM_GPIO_INTR_STATUS27_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS27_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS27_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS27_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS27_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS27_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS27_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS27_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS27_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS27_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS27_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0001b010)
#define HWIO_TLMM_GPIO_ID_STATUS27_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0001b010)
#define HWIO_TLMM_GPIO_ID_STATUS27_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS27_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS27_ADDR, HWIO_TLMM_GPIO_ID_STATUS27_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS27_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS27_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS27_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS27_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG53_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00035000)
#define HWIO_TLMM_GPIO_CFG53_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00035000)
#define HWIO_TLMM_GPIO_CFG53_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG53_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG53_ADDR, HWIO_TLMM_GPIO_CFG53_RMSK)
#define HWIO_TLMM_GPIO_CFG53_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG53_ADDR, m)
#define HWIO_TLMM_GPIO_CFG53_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG53_ADDR,v)
#define HWIO_TLMM_GPIO_CFG53_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG53_ADDR,m,v,HWIO_TLMM_GPIO_CFG53_IN)
#define HWIO_TLMM_GPIO_CFG53_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG53_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG53_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG53_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG53_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG53_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG53_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG53_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG53_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG53_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT53_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00035004)
#define HWIO_TLMM_GPIO_IN_OUT53_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00035004)
#define HWIO_TLMM_GPIO_IN_OUT53_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT53_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT53_ADDR, HWIO_TLMM_GPIO_IN_OUT53_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT53_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT53_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT53_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT53_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT53_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT53_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT53_IN)
#define HWIO_TLMM_GPIO_IN_OUT53_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT53_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT53_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT53_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG53_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00035008)
#define HWIO_TLMM_GPIO_INTR_CFG53_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00035008)
#define HWIO_TLMM_GPIO_INTR_CFG53_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG53_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG53_ADDR, HWIO_TLMM_GPIO_INTR_CFG53_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG53_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG53_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG53_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG53_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG53_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG53_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG53_IN)
#define HWIO_TLMM_GPIO_INTR_CFG53_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG53_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG53_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG53_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG53_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS53_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003500c)
#define HWIO_TLMM_GPIO_INTR_STATUS53_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003500c)
#define HWIO_TLMM_GPIO_INTR_STATUS53_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS53_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS53_ADDR, HWIO_TLMM_GPIO_INTR_STATUS53_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS53_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS53_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS53_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS53_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS53_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS53_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS53_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS53_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS53_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS53_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00035010)
#define HWIO_TLMM_GPIO_ID_STATUS53_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00035010)
#define HWIO_TLMM_GPIO_ID_STATUS53_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS53_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS53_ADDR, HWIO_TLMM_GPIO_ID_STATUS53_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS53_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS53_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS53_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS53_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG54_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00036000)
#define HWIO_TLMM_GPIO_CFG54_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00036000)
#define HWIO_TLMM_GPIO_CFG54_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG54_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG54_ADDR, HWIO_TLMM_GPIO_CFG54_RMSK)
#define HWIO_TLMM_GPIO_CFG54_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG54_ADDR, m)
#define HWIO_TLMM_GPIO_CFG54_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG54_ADDR,v)
#define HWIO_TLMM_GPIO_CFG54_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG54_ADDR,m,v,HWIO_TLMM_GPIO_CFG54_IN)
#define HWIO_TLMM_GPIO_CFG54_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG54_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG54_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG54_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG54_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG54_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG54_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG54_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG54_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG54_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT54_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00036004)
#define HWIO_TLMM_GPIO_IN_OUT54_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00036004)
#define HWIO_TLMM_GPIO_IN_OUT54_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT54_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT54_ADDR, HWIO_TLMM_GPIO_IN_OUT54_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT54_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT54_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT54_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT54_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT54_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT54_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT54_IN)
#define HWIO_TLMM_GPIO_IN_OUT54_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT54_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT54_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT54_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG54_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00036008)
#define HWIO_TLMM_GPIO_INTR_CFG54_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00036008)
#define HWIO_TLMM_GPIO_INTR_CFG54_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG54_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG54_ADDR, HWIO_TLMM_GPIO_INTR_CFG54_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG54_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG54_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG54_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG54_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG54_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG54_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG54_IN)
#define HWIO_TLMM_GPIO_INTR_CFG54_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG54_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG54_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG54_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG54_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS54_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003600c)
#define HWIO_TLMM_GPIO_INTR_STATUS54_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003600c)
#define HWIO_TLMM_GPIO_INTR_STATUS54_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS54_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS54_ADDR, HWIO_TLMM_GPIO_INTR_STATUS54_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS54_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS54_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS54_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS54_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS54_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS54_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS54_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS54_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS54_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS54_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00036010)
#define HWIO_TLMM_GPIO_ID_STATUS54_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00036010)
#define HWIO_TLMM_GPIO_ID_STATUS54_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS54_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS54_ADDR, HWIO_TLMM_GPIO_ID_STATUS54_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS54_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS54_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS54_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS54_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG59_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0003b000)
#define HWIO_TLMM_GPIO_CFG59_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0003b000)
#define HWIO_TLMM_GPIO_CFG59_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG59_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG59_ADDR, HWIO_TLMM_GPIO_CFG59_RMSK)
#define HWIO_TLMM_GPIO_CFG59_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG59_ADDR, m)
#define HWIO_TLMM_GPIO_CFG59_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG59_ADDR,v)
#define HWIO_TLMM_GPIO_CFG59_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG59_ADDR,m,v,HWIO_TLMM_GPIO_CFG59_IN)
#define HWIO_TLMM_GPIO_CFG59_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG59_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG59_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG59_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG59_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG59_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG59_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG59_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG59_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG59_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT59_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0003b004)
#define HWIO_TLMM_GPIO_IN_OUT59_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0003b004)
#define HWIO_TLMM_GPIO_IN_OUT59_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT59_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT59_ADDR, HWIO_TLMM_GPIO_IN_OUT59_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT59_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT59_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT59_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT59_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT59_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT59_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT59_IN)
#define HWIO_TLMM_GPIO_IN_OUT59_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT59_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT59_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT59_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG59_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0003b008)
#define HWIO_TLMM_GPIO_INTR_CFG59_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0003b008)
#define HWIO_TLMM_GPIO_INTR_CFG59_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG59_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG59_ADDR, HWIO_TLMM_GPIO_INTR_CFG59_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG59_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG59_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG59_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG59_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG59_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG59_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG59_IN)
#define HWIO_TLMM_GPIO_INTR_CFG59_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG59_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG59_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG59_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG59_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS59_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS59_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS59_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS59_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS59_ADDR, HWIO_TLMM_GPIO_INTR_STATUS59_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS59_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS59_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS59_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS59_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS59_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS59_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS59_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS59_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS59_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS59_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0003b010)
#define HWIO_TLMM_GPIO_ID_STATUS59_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0003b010)
#define HWIO_TLMM_GPIO_ID_STATUS59_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS59_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS59_ADDR, HWIO_TLMM_GPIO_ID_STATUS59_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS59_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS59_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS59_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS59_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG60_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0003c000)
#define HWIO_TLMM_GPIO_CFG60_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0003c000)
#define HWIO_TLMM_GPIO_CFG60_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG60_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG60_ADDR, HWIO_TLMM_GPIO_CFG60_RMSK)
#define HWIO_TLMM_GPIO_CFG60_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG60_ADDR, m)
#define HWIO_TLMM_GPIO_CFG60_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG60_ADDR,v)
#define HWIO_TLMM_GPIO_CFG60_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG60_ADDR,m,v,HWIO_TLMM_GPIO_CFG60_IN)
#define HWIO_TLMM_GPIO_CFG60_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG60_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG60_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG60_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG60_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG60_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG60_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG60_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG60_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG60_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT60_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0003c004)
#define HWIO_TLMM_GPIO_IN_OUT60_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0003c004)
#define HWIO_TLMM_GPIO_IN_OUT60_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT60_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT60_ADDR, HWIO_TLMM_GPIO_IN_OUT60_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT60_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT60_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT60_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT60_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT60_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT60_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT60_IN)
#define HWIO_TLMM_GPIO_IN_OUT60_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT60_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT60_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT60_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG60_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0003c008)
#define HWIO_TLMM_GPIO_INTR_CFG60_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0003c008)
#define HWIO_TLMM_GPIO_INTR_CFG60_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG60_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG60_ADDR, HWIO_TLMM_GPIO_INTR_CFG60_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG60_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG60_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG60_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG60_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG60_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG60_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG60_IN)
#define HWIO_TLMM_GPIO_INTR_CFG60_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG60_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG60_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG60_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG60_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS60_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS60_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS60_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS60_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS60_ADDR, HWIO_TLMM_GPIO_INTR_STATUS60_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS60_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS60_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS60_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS60_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS60_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS60_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS60_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS60_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS60_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS60_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0003c010)
#define HWIO_TLMM_GPIO_ID_STATUS60_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0003c010)
#define HWIO_TLMM_GPIO_ID_STATUS60_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS60_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS60_ADDR, HWIO_TLMM_GPIO_ID_STATUS60_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS60_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS60_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS60_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS60_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG61_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0003d000)
#define HWIO_TLMM_GPIO_CFG61_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0003d000)
#define HWIO_TLMM_GPIO_CFG61_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG61_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG61_ADDR, HWIO_TLMM_GPIO_CFG61_RMSK)
#define HWIO_TLMM_GPIO_CFG61_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG61_ADDR, m)
#define HWIO_TLMM_GPIO_CFG61_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG61_ADDR,v)
#define HWIO_TLMM_GPIO_CFG61_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG61_ADDR,m,v,HWIO_TLMM_GPIO_CFG61_IN)
#define HWIO_TLMM_GPIO_CFG61_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG61_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG61_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG61_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG61_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG61_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG61_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG61_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG61_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG61_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT61_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0003d004)
#define HWIO_TLMM_GPIO_IN_OUT61_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0003d004)
#define HWIO_TLMM_GPIO_IN_OUT61_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT61_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT61_ADDR, HWIO_TLMM_GPIO_IN_OUT61_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT61_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT61_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT61_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT61_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT61_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT61_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT61_IN)
#define HWIO_TLMM_GPIO_IN_OUT61_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT61_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT61_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT61_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG61_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0003d008)
#define HWIO_TLMM_GPIO_INTR_CFG61_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0003d008)
#define HWIO_TLMM_GPIO_INTR_CFG61_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG61_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG61_ADDR, HWIO_TLMM_GPIO_INTR_CFG61_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG61_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG61_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG61_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG61_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG61_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG61_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG61_IN)
#define HWIO_TLMM_GPIO_INTR_CFG61_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG61_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG61_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG61_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG61_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS61_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS61_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS61_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS61_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS61_ADDR, HWIO_TLMM_GPIO_INTR_STATUS61_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS61_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS61_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS61_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS61_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS61_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS61_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS61_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS61_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS61_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS61_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0003d010)
#define HWIO_TLMM_GPIO_ID_STATUS61_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0003d010)
#define HWIO_TLMM_GPIO_ID_STATUS61_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS61_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS61_ADDR, HWIO_TLMM_GPIO_ID_STATUS61_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS61_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS61_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS61_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS61_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG62_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0003e000)
#define HWIO_TLMM_GPIO_CFG62_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0003e000)
#define HWIO_TLMM_GPIO_CFG62_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG62_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG62_ADDR, HWIO_TLMM_GPIO_CFG62_RMSK)
#define HWIO_TLMM_GPIO_CFG62_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG62_ADDR, m)
#define HWIO_TLMM_GPIO_CFG62_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG62_ADDR,v)
#define HWIO_TLMM_GPIO_CFG62_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG62_ADDR,m,v,HWIO_TLMM_GPIO_CFG62_IN)
#define HWIO_TLMM_GPIO_CFG62_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG62_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG62_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG62_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG62_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG62_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG62_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG62_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG62_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG62_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT62_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0003e004)
#define HWIO_TLMM_GPIO_IN_OUT62_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0003e004)
#define HWIO_TLMM_GPIO_IN_OUT62_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT62_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT62_ADDR, HWIO_TLMM_GPIO_IN_OUT62_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT62_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT62_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT62_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT62_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT62_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT62_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT62_IN)
#define HWIO_TLMM_GPIO_IN_OUT62_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT62_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT62_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT62_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG62_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0003e008)
#define HWIO_TLMM_GPIO_INTR_CFG62_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0003e008)
#define HWIO_TLMM_GPIO_INTR_CFG62_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG62_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG62_ADDR, HWIO_TLMM_GPIO_INTR_CFG62_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG62_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG62_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG62_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG62_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG62_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG62_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG62_IN)
#define HWIO_TLMM_GPIO_INTR_CFG62_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG62_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG62_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG62_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG62_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS62_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS62_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS62_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS62_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS62_ADDR, HWIO_TLMM_GPIO_INTR_STATUS62_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS62_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS62_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS62_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS62_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS62_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS62_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS62_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS62_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS62_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS62_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0003e010)
#define HWIO_TLMM_GPIO_ID_STATUS62_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0003e010)
#define HWIO_TLMM_GPIO_ID_STATUS62_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS62_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS62_ADDR, HWIO_TLMM_GPIO_ID_STATUS62_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS62_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS62_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS62_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS62_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG63_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0003f000)
#define HWIO_TLMM_GPIO_CFG63_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0003f000)
#define HWIO_TLMM_GPIO_CFG63_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG63_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG63_ADDR, HWIO_TLMM_GPIO_CFG63_RMSK)
#define HWIO_TLMM_GPIO_CFG63_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG63_ADDR, m)
#define HWIO_TLMM_GPIO_CFG63_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG63_ADDR,v)
#define HWIO_TLMM_GPIO_CFG63_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG63_ADDR,m,v,HWIO_TLMM_GPIO_CFG63_IN)
#define HWIO_TLMM_GPIO_CFG63_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG63_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG63_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG63_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG63_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG63_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG63_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG63_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG63_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG63_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT63_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0003f004)
#define HWIO_TLMM_GPIO_IN_OUT63_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0003f004)
#define HWIO_TLMM_GPIO_IN_OUT63_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT63_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT63_ADDR, HWIO_TLMM_GPIO_IN_OUT63_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT63_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT63_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT63_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT63_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT63_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT63_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT63_IN)
#define HWIO_TLMM_GPIO_IN_OUT63_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT63_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT63_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT63_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG63_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0003f008)
#define HWIO_TLMM_GPIO_INTR_CFG63_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0003f008)
#define HWIO_TLMM_GPIO_INTR_CFG63_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG63_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG63_ADDR, HWIO_TLMM_GPIO_INTR_CFG63_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG63_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG63_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG63_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG63_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG63_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG63_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG63_IN)
#define HWIO_TLMM_GPIO_INTR_CFG63_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG63_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG63_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG63_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG63_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS63_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0003f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS63_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0003f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS63_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS63_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS63_ADDR, HWIO_TLMM_GPIO_INTR_STATUS63_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS63_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS63_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS63_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS63_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS63_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS63_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS63_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS63_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS63_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS63_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0003f010)
#define HWIO_TLMM_GPIO_ID_STATUS63_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0003f010)
#define HWIO_TLMM_GPIO_ID_STATUS63_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS63_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS63_ADDR, HWIO_TLMM_GPIO_ID_STATUS63_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS63_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS63_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS63_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS63_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG66_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00042000)
#define HWIO_TLMM_GPIO_CFG66_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00042000)
#define HWIO_TLMM_GPIO_CFG66_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG66_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG66_ADDR, HWIO_TLMM_GPIO_CFG66_RMSK)
#define HWIO_TLMM_GPIO_CFG66_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG66_ADDR, m)
#define HWIO_TLMM_GPIO_CFG66_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG66_ADDR,v)
#define HWIO_TLMM_GPIO_CFG66_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG66_ADDR,m,v,HWIO_TLMM_GPIO_CFG66_IN)
#define HWIO_TLMM_GPIO_CFG66_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG66_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG66_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG66_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG66_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG66_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG66_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG66_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG66_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG66_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT66_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00042004)
#define HWIO_TLMM_GPIO_IN_OUT66_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00042004)
#define HWIO_TLMM_GPIO_IN_OUT66_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT66_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT66_ADDR, HWIO_TLMM_GPIO_IN_OUT66_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT66_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT66_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT66_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT66_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT66_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT66_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT66_IN)
#define HWIO_TLMM_GPIO_IN_OUT66_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT66_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT66_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT66_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG66_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00042008)
#define HWIO_TLMM_GPIO_INTR_CFG66_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00042008)
#define HWIO_TLMM_GPIO_INTR_CFG66_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG66_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG66_ADDR, HWIO_TLMM_GPIO_INTR_CFG66_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG66_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG66_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG66_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG66_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG66_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG66_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG66_IN)
#define HWIO_TLMM_GPIO_INTR_CFG66_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG66_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG66_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG66_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG66_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS66_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004200c)
#define HWIO_TLMM_GPIO_INTR_STATUS66_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004200c)
#define HWIO_TLMM_GPIO_INTR_STATUS66_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS66_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS66_ADDR, HWIO_TLMM_GPIO_INTR_STATUS66_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS66_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS66_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS66_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS66_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS66_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS66_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS66_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS66_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS66_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS66_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00042010)
#define HWIO_TLMM_GPIO_ID_STATUS66_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00042010)
#define HWIO_TLMM_GPIO_ID_STATUS66_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS66_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS66_ADDR, HWIO_TLMM_GPIO_ID_STATUS66_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS66_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS66_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS66_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS66_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG67_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00043000)
#define HWIO_TLMM_GPIO_CFG67_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00043000)
#define HWIO_TLMM_GPIO_CFG67_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG67_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG67_ADDR, HWIO_TLMM_GPIO_CFG67_RMSK)
#define HWIO_TLMM_GPIO_CFG67_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG67_ADDR, m)
#define HWIO_TLMM_GPIO_CFG67_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG67_ADDR,v)
#define HWIO_TLMM_GPIO_CFG67_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG67_ADDR,m,v,HWIO_TLMM_GPIO_CFG67_IN)
#define HWIO_TLMM_GPIO_CFG67_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG67_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG67_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG67_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG67_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG67_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG67_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG67_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG67_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG67_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT67_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00043004)
#define HWIO_TLMM_GPIO_IN_OUT67_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00043004)
#define HWIO_TLMM_GPIO_IN_OUT67_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT67_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT67_ADDR, HWIO_TLMM_GPIO_IN_OUT67_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT67_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT67_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT67_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT67_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT67_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT67_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT67_IN)
#define HWIO_TLMM_GPIO_IN_OUT67_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT67_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT67_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT67_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG67_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00043008)
#define HWIO_TLMM_GPIO_INTR_CFG67_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00043008)
#define HWIO_TLMM_GPIO_INTR_CFG67_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG67_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG67_ADDR, HWIO_TLMM_GPIO_INTR_CFG67_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG67_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG67_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG67_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG67_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG67_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG67_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG67_IN)
#define HWIO_TLMM_GPIO_INTR_CFG67_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG67_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG67_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG67_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG67_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS67_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004300c)
#define HWIO_TLMM_GPIO_INTR_STATUS67_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004300c)
#define HWIO_TLMM_GPIO_INTR_STATUS67_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS67_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS67_ADDR, HWIO_TLMM_GPIO_INTR_STATUS67_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS67_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS67_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS67_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS67_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS67_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS67_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS67_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS67_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS67_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS67_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00043010)
#define HWIO_TLMM_GPIO_ID_STATUS67_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00043010)
#define HWIO_TLMM_GPIO_ID_STATUS67_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS67_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS67_ADDR, HWIO_TLMM_GPIO_ID_STATUS67_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS67_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS67_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS67_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS67_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG68_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00044000)
#define HWIO_TLMM_GPIO_CFG68_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00044000)
#define HWIO_TLMM_GPIO_CFG68_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG68_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG68_ADDR, HWIO_TLMM_GPIO_CFG68_RMSK)
#define HWIO_TLMM_GPIO_CFG68_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG68_ADDR, m)
#define HWIO_TLMM_GPIO_CFG68_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG68_ADDR,v)
#define HWIO_TLMM_GPIO_CFG68_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG68_ADDR,m,v,HWIO_TLMM_GPIO_CFG68_IN)
#define HWIO_TLMM_GPIO_CFG68_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG68_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG68_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG68_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG68_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG68_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG68_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG68_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG68_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG68_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT68_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00044004)
#define HWIO_TLMM_GPIO_IN_OUT68_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00044004)
#define HWIO_TLMM_GPIO_IN_OUT68_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT68_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT68_ADDR, HWIO_TLMM_GPIO_IN_OUT68_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT68_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT68_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT68_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT68_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT68_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT68_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT68_IN)
#define HWIO_TLMM_GPIO_IN_OUT68_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT68_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT68_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT68_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG68_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00044008)
#define HWIO_TLMM_GPIO_INTR_CFG68_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00044008)
#define HWIO_TLMM_GPIO_INTR_CFG68_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG68_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG68_ADDR, HWIO_TLMM_GPIO_INTR_CFG68_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG68_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG68_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG68_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG68_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG68_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG68_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG68_IN)
#define HWIO_TLMM_GPIO_INTR_CFG68_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG68_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG68_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG68_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG68_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS68_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004400c)
#define HWIO_TLMM_GPIO_INTR_STATUS68_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004400c)
#define HWIO_TLMM_GPIO_INTR_STATUS68_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS68_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS68_ADDR, HWIO_TLMM_GPIO_INTR_STATUS68_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS68_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS68_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS68_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS68_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS68_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS68_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS68_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS68_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS68_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS68_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00044010)
#define HWIO_TLMM_GPIO_ID_STATUS68_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00044010)
#define HWIO_TLMM_GPIO_ID_STATUS68_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS68_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS68_ADDR, HWIO_TLMM_GPIO_ID_STATUS68_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS68_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS68_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS68_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS68_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG69_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00045000)
#define HWIO_TLMM_GPIO_CFG69_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00045000)
#define HWIO_TLMM_GPIO_CFG69_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG69_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG69_ADDR, HWIO_TLMM_GPIO_CFG69_RMSK)
#define HWIO_TLMM_GPIO_CFG69_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG69_ADDR, m)
#define HWIO_TLMM_GPIO_CFG69_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG69_ADDR,v)
#define HWIO_TLMM_GPIO_CFG69_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG69_ADDR,m,v,HWIO_TLMM_GPIO_CFG69_IN)
#define HWIO_TLMM_GPIO_CFG69_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG69_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG69_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG69_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG69_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG69_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG69_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG69_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG69_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG69_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT69_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00045004)
#define HWIO_TLMM_GPIO_IN_OUT69_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00045004)
#define HWIO_TLMM_GPIO_IN_OUT69_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT69_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT69_ADDR, HWIO_TLMM_GPIO_IN_OUT69_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT69_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT69_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT69_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT69_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT69_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT69_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT69_IN)
#define HWIO_TLMM_GPIO_IN_OUT69_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT69_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT69_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT69_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG69_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00045008)
#define HWIO_TLMM_GPIO_INTR_CFG69_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00045008)
#define HWIO_TLMM_GPIO_INTR_CFG69_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG69_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG69_ADDR, HWIO_TLMM_GPIO_INTR_CFG69_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG69_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG69_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG69_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG69_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG69_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG69_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG69_IN)
#define HWIO_TLMM_GPIO_INTR_CFG69_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG69_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG69_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG69_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG69_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS69_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004500c)
#define HWIO_TLMM_GPIO_INTR_STATUS69_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004500c)
#define HWIO_TLMM_GPIO_INTR_STATUS69_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS69_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS69_ADDR, HWIO_TLMM_GPIO_INTR_STATUS69_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS69_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS69_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS69_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS69_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS69_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS69_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS69_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS69_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS69_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS69_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00045010)
#define HWIO_TLMM_GPIO_ID_STATUS69_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00045010)
#define HWIO_TLMM_GPIO_ID_STATUS69_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS69_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS69_ADDR, HWIO_TLMM_GPIO_ID_STATUS69_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS69_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS69_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS69_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS69_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG70_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00046000)
#define HWIO_TLMM_GPIO_CFG70_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00046000)
#define HWIO_TLMM_GPIO_CFG70_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG70_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG70_ADDR, HWIO_TLMM_GPIO_CFG70_RMSK)
#define HWIO_TLMM_GPIO_CFG70_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG70_ADDR, m)
#define HWIO_TLMM_GPIO_CFG70_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG70_ADDR,v)
#define HWIO_TLMM_GPIO_CFG70_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG70_ADDR,m,v,HWIO_TLMM_GPIO_CFG70_IN)
#define HWIO_TLMM_GPIO_CFG70_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG70_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG70_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG70_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG70_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG70_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG70_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG70_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG70_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG70_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT70_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00046004)
#define HWIO_TLMM_GPIO_IN_OUT70_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00046004)
#define HWIO_TLMM_GPIO_IN_OUT70_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT70_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT70_ADDR, HWIO_TLMM_GPIO_IN_OUT70_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT70_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT70_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT70_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT70_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT70_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT70_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT70_IN)
#define HWIO_TLMM_GPIO_IN_OUT70_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT70_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT70_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT70_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG70_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00046008)
#define HWIO_TLMM_GPIO_INTR_CFG70_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00046008)
#define HWIO_TLMM_GPIO_INTR_CFG70_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG70_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG70_ADDR, HWIO_TLMM_GPIO_INTR_CFG70_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG70_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG70_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG70_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG70_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG70_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG70_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG70_IN)
#define HWIO_TLMM_GPIO_INTR_CFG70_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG70_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG70_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG70_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG70_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS70_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004600c)
#define HWIO_TLMM_GPIO_INTR_STATUS70_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004600c)
#define HWIO_TLMM_GPIO_INTR_STATUS70_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS70_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS70_ADDR, HWIO_TLMM_GPIO_INTR_STATUS70_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS70_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS70_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS70_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS70_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS70_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS70_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS70_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS70_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS70_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS70_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00046010)
#define HWIO_TLMM_GPIO_ID_STATUS70_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00046010)
#define HWIO_TLMM_GPIO_ID_STATUS70_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS70_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS70_ADDR, HWIO_TLMM_GPIO_ID_STATUS70_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS70_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS70_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS70_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS70_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG71_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00047000)
#define HWIO_TLMM_GPIO_CFG71_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00047000)
#define HWIO_TLMM_GPIO_CFG71_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG71_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG71_ADDR, HWIO_TLMM_GPIO_CFG71_RMSK)
#define HWIO_TLMM_GPIO_CFG71_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG71_ADDR, m)
#define HWIO_TLMM_GPIO_CFG71_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG71_ADDR,v)
#define HWIO_TLMM_GPIO_CFG71_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG71_ADDR,m,v,HWIO_TLMM_GPIO_CFG71_IN)
#define HWIO_TLMM_GPIO_CFG71_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG71_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG71_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG71_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG71_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG71_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG71_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG71_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG71_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG71_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT71_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00047004)
#define HWIO_TLMM_GPIO_IN_OUT71_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00047004)
#define HWIO_TLMM_GPIO_IN_OUT71_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT71_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT71_ADDR, HWIO_TLMM_GPIO_IN_OUT71_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT71_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT71_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT71_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT71_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT71_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT71_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT71_IN)
#define HWIO_TLMM_GPIO_IN_OUT71_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT71_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT71_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT71_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG71_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00047008)
#define HWIO_TLMM_GPIO_INTR_CFG71_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00047008)
#define HWIO_TLMM_GPIO_INTR_CFG71_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG71_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG71_ADDR, HWIO_TLMM_GPIO_INTR_CFG71_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG71_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG71_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG71_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG71_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG71_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG71_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG71_IN)
#define HWIO_TLMM_GPIO_INTR_CFG71_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG71_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG71_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG71_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG71_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS71_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004700c)
#define HWIO_TLMM_GPIO_INTR_STATUS71_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004700c)
#define HWIO_TLMM_GPIO_INTR_STATUS71_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS71_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS71_ADDR, HWIO_TLMM_GPIO_INTR_STATUS71_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS71_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS71_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS71_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS71_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS71_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS71_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS71_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS71_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS71_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS71_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00047010)
#define HWIO_TLMM_GPIO_ID_STATUS71_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00047010)
#define HWIO_TLMM_GPIO_ID_STATUS71_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS71_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS71_ADDR, HWIO_TLMM_GPIO_ID_STATUS71_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS71_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS71_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS71_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS71_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG72_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00048000)
#define HWIO_TLMM_GPIO_CFG72_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00048000)
#define HWIO_TLMM_GPIO_CFG72_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG72_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG72_ADDR, HWIO_TLMM_GPIO_CFG72_RMSK)
#define HWIO_TLMM_GPIO_CFG72_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG72_ADDR, m)
#define HWIO_TLMM_GPIO_CFG72_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG72_ADDR,v)
#define HWIO_TLMM_GPIO_CFG72_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG72_ADDR,m,v,HWIO_TLMM_GPIO_CFG72_IN)
#define HWIO_TLMM_GPIO_CFG72_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG72_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG72_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG72_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG72_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG72_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG72_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG72_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG72_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG72_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT72_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00048004)
#define HWIO_TLMM_GPIO_IN_OUT72_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00048004)
#define HWIO_TLMM_GPIO_IN_OUT72_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT72_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT72_ADDR, HWIO_TLMM_GPIO_IN_OUT72_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT72_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT72_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT72_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT72_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT72_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT72_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT72_IN)
#define HWIO_TLMM_GPIO_IN_OUT72_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT72_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT72_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT72_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG72_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00048008)
#define HWIO_TLMM_GPIO_INTR_CFG72_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00048008)
#define HWIO_TLMM_GPIO_INTR_CFG72_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG72_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG72_ADDR, HWIO_TLMM_GPIO_INTR_CFG72_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG72_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG72_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG72_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG72_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG72_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG72_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG72_IN)
#define HWIO_TLMM_GPIO_INTR_CFG72_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG72_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG72_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG72_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG72_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS72_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004800c)
#define HWIO_TLMM_GPIO_INTR_STATUS72_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004800c)
#define HWIO_TLMM_GPIO_INTR_STATUS72_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS72_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS72_ADDR, HWIO_TLMM_GPIO_INTR_STATUS72_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS72_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS72_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS72_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS72_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS72_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS72_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS72_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS72_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS72_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS72_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00048010)
#define HWIO_TLMM_GPIO_ID_STATUS72_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00048010)
#define HWIO_TLMM_GPIO_ID_STATUS72_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS72_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS72_ADDR, HWIO_TLMM_GPIO_ID_STATUS72_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS72_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS72_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS72_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS72_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG73_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x00049000)
#define HWIO_TLMM_GPIO_CFG73_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x00049000)
#define HWIO_TLMM_GPIO_CFG73_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG73_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG73_ADDR, HWIO_TLMM_GPIO_CFG73_RMSK)
#define HWIO_TLMM_GPIO_CFG73_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG73_ADDR, m)
#define HWIO_TLMM_GPIO_CFG73_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG73_ADDR,v)
#define HWIO_TLMM_GPIO_CFG73_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG73_ADDR,m,v,HWIO_TLMM_GPIO_CFG73_IN)
#define HWIO_TLMM_GPIO_CFG73_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG73_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG73_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG73_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG73_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG73_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG73_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG73_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG73_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG73_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT73_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00049004)
#define HWIO_TLMM_GPIO_IN_OUT73_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00049004)
#define HWIO_TLMM_GPIO_IN_OUT73_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT73_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT73_ADDR, HWIO_TLMM_GPIO_IN_OUT73_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT73_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT73_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT73_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT73_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT73_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT73_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT73_IN)
#define HWIO_TLMM_GPIO_IN_OUT73_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT73_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT73_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT73_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG73_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x00049008)
#define HWIO_TLMM_GPIO_INTR_CFG73_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x00049008)
#define HWIO_TLMM_GPIO_INTR_CFG73_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG73_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG73_ADDR, HWIO_TLMM_GPIO_INTR_CFG73_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG73_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG73_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG73_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG73_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG73_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG73_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG73_IN)
#define HWIO_TLMM_GPIO_INTR_CFG73_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG73_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG73_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG73_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG73_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS73_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004900c)
#define HWIO_TLMM_GPIO_INTR_STATUS73_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004900c)
#define HWIO_TLMM_GPIO_INTR_STATUS73_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS73_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS73_ADDR, HWIO_TLMM_GPIO_INTR_STATUS73_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS73_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS73_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS73_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS73_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS73_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS73_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS73_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS73_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS73_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS73_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x00049010)
#define HWIO_TLMM_GPIO_ID_STATUS73_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x00049010)
#define HWIO_TLMM_GPIO_ID_STATUS73_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS73_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS73_ADDR, HWIO_TLMM_GPIO_ID_STATUS73_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS73_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS73_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS73_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS73_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG74_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0004a000)
#define HWIO_TLMM_GPIO_CFG74_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0004a000)
#define HWIO_TLMM_GPIO_CFG74_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG74_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG74_ADDR, HWIO_TLMM_GPIO_CFG74_RMSK)
#define HWIO_TLMM_GPIO_CFG74_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG74_ADDR, m)
#define HWIO_TLMM_GPIO_CFG74_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG74_ADDR,v)
#define HWIO_TLMM_GPIO_CFG74_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG74_ADDR,m,v,HWIO_TLMM_GPIO_CFG74_IN)
#define HWIO_TLMM_GPIO_CFG74_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG74_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG74_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG74_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG74_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG74_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG74_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG74_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG74_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG74_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT74_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0004a004)
#define HWIO_TLMM_GPIO_IN_OUT74_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0004a004)
#define HWIO_TLMM_GPIO_IN_OUT74_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT74_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT74_ADDR, HWIO_TLMM_GPIO_IN_OUT74_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT74_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT74_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT74_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT74_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT74_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT74_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT74_IN)
#define HWIO_TLMM_GPIO_IN_OUT74_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT74_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT74_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT74_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG74_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0004a008)
#define HWIO_TLMM_GPIO_INTR_CFG74_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0004a008)
#define HWIO_TLMM_GPIO_INTR_CFG74_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG74_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG74_ADDR, HWIO_TLMM_GPIO_INTR_CFG74_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG74_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG74_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG74_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG74_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG74_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG74_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG74_IN)
#define HWIO_TLMM_GPIO_INTR_CFG74_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG74_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG74_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG74_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG74_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS74_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS74_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS74_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS74_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS74_ADDR, HWIO_TLMM_GPIO_INTR_STATUS74_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS74_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS74_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS74_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS74_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS74_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS74_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS74_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS74_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS74_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS74_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0004a010)
#define HWIO_TLMM_GPIO_ID_STATUS74_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0004a010)
#define HWIO_TLMM_GPIO_ID_STATUS74_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS74_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS74_ADDR, HWIO_TLMM_GPIO_ID_STATUS74_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS74_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS74_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS74_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS74_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG75_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0004b000)
#define HWIO_TLMM_GPIO_CFG75_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0004b000)
#define HWIO_TLMM_GPIO_CFG75_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG75_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG75_ADDR, HWIO_TLMM_GPIO_CFG75_RMSK)
#define HWIO_TLMM_GPIO_CFG75_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG75_ADDR, m)
#define HWIO_TLMM_GPIO_CFG75_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG75_ADDR,v)
#define HWIO_TLMM_GPIO_CFG75_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG75_ADDR,m,v,HWIO_TLMM_GPIO_CFG75_IN)
#define HWIO_TLMM_GPIO_CFG75_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG75_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG75_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG75_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG75_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG75_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG75_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG75_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG75_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG75_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT75_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0004b004)
#define HWIO_TLMM_GPIO_IN_OUT75_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0004b004)
#define HWIO_TLMM_GPIO_IN_OUT75_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT75_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT75_ADDR, HWIO_TLMM_GPIO_IN_OUT75_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT75_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT75_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT75_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT75_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT75_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT75_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT75_IN)
#define HWIO_TLMM_GPIO_IN_OUT75_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT75_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT75_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT75_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG75_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0004b008)
#define HWIO_TLMM_GPIO_INTR_CFG75_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0004b008)
#define HWIO_TLMM_GPIO_INTR_CFG75_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG75_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG75_ADDR, HWIO_TLMM_GPIO_INTR_CFG75_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG75_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG75_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG75_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG75_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG75_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG75_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG75_IN)
#define HWIO_TLMM_GPIO_INTR_CFG75_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG75_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG75_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG75_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG75_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS75_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS75_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS75_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS75_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS75_ADDR, HWIO_TLMM_GPIO_INTR_STATUS75_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS75_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS75_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS75_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS75_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS75_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS75_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS75_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS75_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS75_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS75_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0004b010)
#define HWIO_TLMM_GPIO_ID_STATUS75_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0004b010)
#define HWIO_TLMM_GPIO_ID_STATUS75_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS75_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS75_ADDR, HWIO_TLMM_GPIO_ID_STATUS75_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS75_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS75_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS75_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS75_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG76_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0004c000)
#define HWIO_TLMM_GPIO_CFG76_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0004c000)
#define HWIO_TLMM_GPIO_CFG76_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG76_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG76_ADDR, HWIO_TLMM_GPIO_CFG76_RMSK)
#define HWIO_TLMM_GPIO_CFG76_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG76_ADDR, m)
#define HWIO_TLMM_GPIO_CFG76_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG76_ADDR,v)
#define HWIO_TLMM_GPIO_CFG76_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG76_ADDR,m,v,HWIO_TLMM_GPIO_CFG76_IN)
#define HWIO_TLMM_GPIO_CFG76_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG76_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG76_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG76_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG76_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG76_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG76_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG76_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG76_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG76_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT76_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0004c004)
#define HWIO_TLMM_GPIO_IN_OUT76_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0004c004)
#define HWIO_TLMM_GPIO_IN_OUT76_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT76_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT76_ADDR, HWIO_TLMM_GPIO_IN_OUT76_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT76_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT76_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT76_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT76_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT76_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT76_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT76_IN)
#define HWIO_TLMM_GPIO_IN_OUT76_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT76_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT76_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT76_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG76_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0004c008)
#define HWIO_TLMM_GPIO_INTR_CFG76_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0004c008)
#define HWIO_TLMM_GPIO_INTR_CFG76_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG76_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG76_ADDR, HWIO_TLMM_GPIO_INTR_CFG76_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG76_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG76_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG76_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG76_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG76_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG76_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG76_IN)
#define HWIO_TLMM_GPIO_INTR_CFG76_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG76_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG76_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG76_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG76_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS76_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS76_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS76_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS76_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS76_ADDR, HWIO_TLMM_GPIO_INTR_STATUS76_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS76_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS76_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS76_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS76_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS76_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS76_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS76_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS76_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS76_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS76_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0004c010)
#define HWIO_TLMM_GPIO_ID_STATUS76_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0004c010)
#define HWIO_TLMM_GPIO_ID_STATUS76_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS76_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS76_ADDR, HWIO_TLMM_GPIO_ID_STATUS76_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS76_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS76_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS76_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS76_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG77_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0004d000)
#define HWIO_TLMM_GPIO_CFG77_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0004d000)
#define HWIO_TLMM_GPIO_CFG77_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG77_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG77_ADDR, HWIO_TLMM_GPIO_CFG77_RMSK)
#define HWIO_TLMM_GPIO_CFG77_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG77_ADDR, m)
#define HWIO_TLMM_GPIO_CFG77_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG77_ADDR,v)
#define HWIO_TLMM_GPIO_CFG77_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG77_ADDR,m,v,HWIO_TLMM_GPIO_CFG77_IN)
#define HWIO_TLMM_GPIO_CFG77_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG77_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG77_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG77_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG77_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG77_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG77_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG77_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG77_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG77_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT77_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0004d004)
#define HWIO_TLMM_GPIO_IN_OUT77_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0004d004)
#define HWIO_TLMM_GPIO_IN_OUT77_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT77_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT77_ADDR, HWIO_TLMM_GPIO_IN_OUT77_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT77_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT77_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT77_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT77_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT77_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT77_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT77_IN)
#define HWIO_TLMM_GPIO_IN_OUT77_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT77_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT77_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT77_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG77_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0004d008)
#define HWIO_TLMM_GPIO_INTR_CFG77_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0004d008)
#define HWIO_TLMM_GPIO_INTR_CFG77_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG77_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG77_ADDR, HWIO_TLMM_GPIO_INTR_CFG77_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG77_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG77_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG77_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG77_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG77_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG77_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG77_IN)
#define HWIO_TLMM_GPIO_INTR_CFG77_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG77_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG77_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG77_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG77_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS77_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS77_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS77_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS77_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS77_ADDR, HWIO_TLMM_GPIO_INTR_STATUS77_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS77_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS77_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS77_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS77_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS77_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS77_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS77_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS77_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS77_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS77_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0004d010)
#define HWIO_TLMM_GPIO_ID_STATUS77_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0004d010)
#define HWIO_TLMM_GPIO_ID_STATUS77_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS77_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS77_ADDR, HWIO_TLMM_GPIO_ID_STATUS77_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS77_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS77_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS77_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS77_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG78_ADDR                                          (TLMM_NORTH_REG_BASE      + 0x0004e000)
#define HWIO_TLMM_GPIO_CFG78_OFFS                                          (TLMM_NORTH_REG_BASE_OFFS + 0x0004e000)
#define HWIO_TLMM_GPIO_CFG78_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG78_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG78_ADDR, HWIO_TLMM_GPIO_CFG78_RMSK)
#define HWIO_TLMM_GPIO_CFG78_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG78_ADDR, m)
#define HWIO_TLMM_GPIO_CFG78_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG78_ADDR,v)
#define HWIO_TLMM_GPIO_CFG78_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG78_ADDR,m,v,HWIO_TLMM_GPIO_CFG78_IN)
#define HWIO_TLMM_GPIO_CFG78_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG78_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG78_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG78_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG78_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG78_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG78_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG78_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG78_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG78_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT78_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0004e004)
#define HWIO_TLMM_GPIO_IN_OUT78_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0004e004)
#define HWIO_TLMM_GPIO_IN_OUT78_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT78_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT78_ADDR, HWIO_TLMM_GPIO_IN_OUT78_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT78_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT78_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT78_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT78_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT78_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT78_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT78_IN)
#define HWIO_TLMM_GPIO_IN_OUT78_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT78_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT78_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT78_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG78_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0004e008)
#define HWIO_TLMM_GPIO_INTR_CFG78_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0004e008)
#define HWIO_TLMM_GPIO_INTR_CFG78_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG78_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG78_ADDR, HWIO_TLMM_GPIO_INTR_CFG78_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG78_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG78_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG78_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG78_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG78_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG78_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG78_IN)
#define HWIO_TLMM_GPIO_INTR_CFG78_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG78_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG78_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG78_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG78_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS78_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0004e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS78_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0004e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS78_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS78_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS78_ADDR, HWIO_TLMM_GPIO_INTR_STATUS78_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS78_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS78_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS78_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS78_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS78_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS78_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS78_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS78_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS78_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS78_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x0004e010)
#define HWIO_TLMM_GPIO_ID_STATUS78_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x0004e010)
#define HWIO_TLMM_GPIO_ID_STATUS78_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS78_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS78_ADDR, HWIO_TLMM_GPIO_ID_STATUS78_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS78_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS78_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS78_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS78_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_ADDR                           (TLMM_NORTH_REG_BASE      + 0x00096000)
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_OFFS                           (TLMM_NORTH_REG_BASE_OFFS + 0x00096000)
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_RMSK                            0x1ffffff
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_IN          \
        in_dword_masked(HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_ADDR, HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_RMSK)
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_INM(m)      \
        in_dword_masked(HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_ADDR, m)
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_OUT(v)      \
        out_dword(HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_ADDR,v)
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_ADDR,m,v,HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_IN)
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_78_BMSK                    0x1000000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_78_SHFT                         0x18
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_77_BMSK                     0x800000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_77_SHFT                         0x17
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_76_BMSK                     0x400000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_76_SHFT                         0x16
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_75_BMSK                     0x200000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_75_SHFT                         0x15
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_74_BMSK                     0x100000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_74_SHFT                         0x14
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_73_BMSK                      0x80000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_73_SHFT                         0x13
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_72_BMSK                      0x40000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_72_SHFT                         0x12
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_71_BMSK                      0x20000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_71_SHFT                         0x11
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_70_BMSK                      0x10000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_70_SHFT                         0x10
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_69_BMSK                       0x8000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_69_SHFT                          0xf
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_68_BMSK                       0x4000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_68_SHFT                          0xe
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_67_BMSK                       0x2000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_67_SHFT                          0xd
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_66_BMSK                       0x1000
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_66_SHFT                          0xc
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_60_BMSK                        0x800
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_60_SHFT                          0xb
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_54_BMSK                        0x400
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_54_SHFT                          0xa
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_25_BMSK                        0x200
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_25_SHFT                          0x9
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_13_BMSK                        0x100
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_13_SHFT                          0x8
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_10_BMSK                         0x80
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_10_SHFT                          0x7
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_9_BMSK                          0x40
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_GPIO_9_SHFT                           0x6
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SRST_N_BMSK                          0x20
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SRST_N_SHFT                           0x5
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC2_CMD_BMSK                        0x10
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC2_CMD_SHFT                         0x4
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC2_DATA_3_BMSK                      0x8
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC2_DATA_3_SHFT                      0x3
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC2_DATA_1_BMSK                      0x4
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC2_DATA_1_SHFT                      0x2
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC1_DATA_3_BMSK                      0x2
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC1_DATA_3_SHFT                      0x1
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC1_DATA_1_BMSK                      0x1
#define HWIO_TLMM_NORTH_MPM_WAKEUP_INT_EN_0_SDC1_DATA_1_SHFT                      0x0

#define HWIO_TLMM_NORTH_CLK_GATE_EN_ADDR                                   (TLMM_NORTH_REG_BASE      + 0x00097000)
#define HWIO_TLMM_NORTH_CLK_GATE_EN_OFFS                                   (TLMM_NORTH_REG_BASE_OFFS + 0x00097000)
#define HWIO_TLMM_NORTH_CLK_GATE_EN_RMSK                                          0x7
#define HWIO_TLMM_NORTH_CLK_GATE_EN_IN          \
        in_dword_masked(HWIO_TLMM_NORTH_CLK_GATE_EN_ADDR, HWIO_TLMM_NORTH_CLK_GATE_EN_RMSK)
#define HWIO_TLMM_NORTH_CLK_GATE_EN_INM(m)      \
        in_dword_masked(HWIO_TLMM_NORTH_CLK_GATE_EN_ADDR, m)
#define HWIO_TLMM_NORTH_CLK_GATE_EN_OUT(v)      \
        out_dword(HWIO_TLMM_NORTH_CLK_GATE_EN_ADDR,v)
#define HWIO_TLMM_NORTH_CLK_GATE_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_CLK_GATE_EN_ADDR,m,v,HWIO_TLMM_NORTH_CLK_GATE_EN_IN)
#define HWIO_TLMM_NORTH_CLK_GATE_EN_AHB_HCLK_EN_BMSK                              0x4
#define HWIO_TLMM_NORTH_CLK_GATE_EN_AHB_HCLK_EN_SHFT                              0x2
#define HWIO_TLMM_NORTH_CLK_GATE_EN_SUMMARY_INTR_EN_BMSK                          0x2
#define HWIO_TLMM_NORTH_CLK_GATE_EN_SUMMARY_INTR_EN_SHFT                          0x1
#define HWIO_TLMM_NORTH_CLK_GATE_EN_CRIF_READ_EN_BMSK                             0x1
#define HWIO_TLMM_NORTH_CLK_GATE_EN_CRIF_READ_EN_SHFT                             0x0

#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_ADDR                               (TLMM_NORTH_REG_BASE      + 0x00097004)
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_OFFS                               (TLMM_NORTH_REG_BASE_OFFS + 0x00097004)
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_RMSK                                      0x1
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_IN          \
        in_dword_masked(HWIO_TLMM_NORTH_IE_CTRL_DISABLE_ADDR, HWIO_TLMM_NORTH_IE_CTRL_DISABLE_RMSK)
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_INM(m)      \
        in_dword_masked(HWIO_TLMM_NORTH_IE_CTRL_DISABLE_ADDR, m)
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_OUT(v)      \
        out_dword(HWIO_TLMM_NORTH_IE_CTRL_DISABLE_ADDR,v)
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_IE_CTRL_DISABLE_ADDR,m,v,HWIO_TLMM_NORTH_IE_CTRL_DISABLE_IN)
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_IE_CTRL_DISABLE_BMSK                      0x1
#define HWIO_TLMM_NORTH_IE_CTRL_DISABLE_IE_CTRL_DISABLE_SHFT                      0x0

#define HWIO_TLMM_INT_JTAG_CTL_ADDR                                        (TLMM_NORTH_REG_BASE      + 0x00098000)
#define HWIO_TLMM_INT_JTAG_CTL_OFFS                                        (TLMM_NORTH_REG_BASE_OFFS + 0x00098000)
#define HWIO_TLMM_INT_JTAG_CTL_RMSK                                               0x1
#define HWIO_TLMM_INT_JTAG_CTL_IN          \
        in_dword_masked(HWIO_TLMM_INT_JTAG_CTL_ADDR, HWIO_TLMM_INT_JTAG_CTL_RMSK)
#define HWIO_TLMM_INT_JTAG_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_INT_JTAG_CTL_ADDR, m)
#define HWIO_TLMM_INT_JTAG_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_INT_JTAG_CTL_ADDR,v)
#define HWIO_TLMM_INT_JTAG_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_INT_JTAG_CTL_ADDR,m,v,HWIO_TLMM_INT_JTAG_CTL_IN)
#define HWIO_TLMM_INT_JTAG_CTL_TAP_SEL_BMSK                                       0x1
#define HWIO_TLMM_INT_JTAG_CTL_TAP_SEL_SHFT                                       0x0

#define HWIO_TLMM_ETM_MODE_ADDR                                            (TLMM_NORTH_REG_BASE      + 0x00098004)
#define HWIO_TLMM_ETM_MODE_OFFS                                            (TLMM_NORTH_REG_BASE_OFFS + 0x00098004)
#define HWIO_TLMM_ETM_MODE_RMSK                                                   0x3
#define HWIO_TLMM_ETM_MODE_IN          \
        in_dword_masked(HWIO_TLMM_ETM_MODE_ADDR, HWIO_TLMM_ETM_MODE_RMSK)
#define HWIO_TLMM_ETM_MODE_INM(m)      \
        in_dword_masked(HWIO_TLMM_ETM_MODE_ADDR, m)
#define HWIO_TLMM_ETM_MODE_OUT(v)      \
        out_dword(HWIO_TLMM_ETM_MODE_ADDR,v)
#define HWIO_TLMM_ETM_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_ETM_MODE_ADDR,m,v,HWIO_TLMM_ETM_MODE_IN)
#define HWIO_TLMM_ETM_MODE_TRACE_OVER_SDC2_BMSK                                   0x3
#define HWIO_TLMM_ETM_MODE_TRACE_OVER_SDC2_SHFT                                   0x0

#define HWIO_TLMM_MODE_PULL_CTL_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x00099000)
#define HWIO_TLMM_MODE_PULL_CTL_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x00099000)
#define HWIO_TLMM_MODE_PULL_CTL_RMSK                                              0xf
#define HWIO_TLMM_MODE_PULL_CTL_IN          \
        in_dword_masked(HWIO_TLMM_MODE_PULL_CTL_ADDR, HWIO_TLMM_MODE_PULL_CTL_RMSK)
#define HWIO_TLMM_MODE_PULL_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_MODE_PULL_CTL_ADDR, m)
#define HWIO_TLMM_MODE_PULL_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_MODE_PULL_CTL_ADDR,v)
#define HWIO_TLMM_MODE_PULL_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_MODE_PULL_CTL_ADDR,m,v,HWIO_TLMM_MODE_PULL_CTL_IN)
#define HWIO_TLMM_MODE_PULL_CTL_MODE_1_PULL_BMSK                                  0xc
#define HWIO_TLMM_MODE_PULL_CTL_MODE_1_PULL_SHFT                                  0x2
#define HWIO_TLMM_MODE_PULL_CTL_MODE_0_PULL_BMSK                                  0x3
#define HWIO_TLMM_MODE_PULL_CTL_MODE_0_PULL_SHFT                                  0x0

#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0009a000)
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0009a000)
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_RMSK                                     0x1ffff
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_IN          \
        in_dword_masked(HWIO_TLMM_SDC1_HDRV_PULL_CTL_ADDR, HWIO_TLMM_SDC1_HDRV_PULL_CTL_RMSK)
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_SDC1_HDRV_PULL_CTL_ADDR, m)
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_SDC1_HDRV_PULL_CTL_ADDR,v)
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SDC1_HDRV_PULL_CTL_ADDR,m,v,HWIO_TLMM_SDC1_HDRV_PULL_CTL_IN)
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_RCLK_PULL_BMSK                      0x18000
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_RCLK_PULL_SHFT                          0xf
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CLK_PULL_BMSK                        0x6000
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CLK_PULL_SHFT                           0xd
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CMD_PULL_BMSK                        0x1800
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CMD_PULL_SHFT                           0xb
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_DATA_PULL_BMSK                        0x600
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_DATA_PULL_SHFT                          0x9
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CLK_HDRV_BMSK                         0x1c0
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CLK_HDRV_SHFT                           0x6
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CMD_HDRV_BMSK                          0x38
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_CMD_HDRV_SHFT                           0x3
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_DATA_HDRV_BMSK                          0x7
#define HWIO_TLMM_SDC1_HDRV_PULL_CTL_SDC1_DATA_HDRV_SHFT                          0x0

#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_ADDR                                  (TLMM_NORTH_REG_BASE      + 0x0009b000)
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_OFFS                                  (TLMM_NORTH_REG_BASE_OFFS + 0x0009b000)
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_RMSK                                      0xffff
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_IN          \
        in_dword_masked(HWIO_TLMM_SDC2_HDRV_PULL_CTL_ADDR, HWIO_TLMM_SDC2_HDRV_PULL_CTL_RMSK)
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_SDC2_HDRV_PULL_CTL_ADDR, m)
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_SDC2_HDRV_PULL_CTL_ADDR,v)
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SDC2_HDRV_PULL_CTL_ADDR,m,v,HWIO_TLMM_SDC2_HDRV_PULL_CTL_IN)
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CLK_PULL_BMSK                        0xc000
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CLK_PULL_SHFT                           0xe
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_HYS_CTL_BMSK                         0x2000
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_HYS_CTL_SHFT                            0xd
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CMD_PULL_BMSK                        0x1800
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CMD_PULL_SHFT                           0xb
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_DATA_PULL_BMSK                        0x600
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_DATA_PULL_SHFT                          0x9
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CLK_HDRV_BMSK                         0x1c0
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CLK_HDRV_SHFT                           0x6
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CMD_HDRV_BMSK                          0x38
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_CMD_HDRV_SHFT                           0x3
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_DATA_HDRV_BMSK                          0x7
#define HWIO_TLMM_SDC2_HDRV_PULL_CTL_SDC2_DATA_HDRV_SHFT                          0x0

#define HWIO_TLMM_JTAG_HDRV_CTL_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x0009d000)
#define HWIO_TLMM_JTAG_HDRV_CTL_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x0009d000)
#define HWIO_TLMM_JTAG_HDRV_CTL_RMSK                                            0x3ff
#define HWIO_TLMM_JTAG_HDRV_CTL_IN          \
        in_dword_masked(HWIO_TLMM_JTAG_HDRV_CTL_ADDR, HWIO_TLMM_JTAG_HDRV_CTL_RMSK)
#define HWIO_TLMM_JTAG_HDRV_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_JTAG_HDRV_CTL_ADDR, m)
#define HWIO_TLMM_JTAG_HDRV_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_JTAG_HDRV_CTL_ADDR,v)
#define HWIO_TLMM_JTAG_HDRV_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_JTAG_HDRV_CTL_ADDR,m,v,HWIO_TLMM_JTAG_HDRV_CTL_IN)
#define HWIO_TLMM_JTAG_HDRV_CTL_TDI_PULL_BMSK                                   0x300
#define HWIO_TLMM_JTAG_HDRV_CTL_TDI_PULL_SHFT                                     0x8
#define HWIO_TLMM_JTAG_HDRV_CTL_TMS_PULL_BMSK                                    0xc0
#define HWIO_TLMM_JTAG_HDRV_CTL_TMS_PULL_SHFT                                     0x6
#define HWIO_TLMM_JTAG_HDRV_CTL_TMS_HDRV_BMSK                                    0x38
#define HWIO_TLMM_JTAG_HDRV_CTL_TMS_HDRV_SHFT                                     0x3
#define HWIO_TLMM_JTAG_HDRV_CTL_TDO_HDRV_BMSK                                     0x7
#define HWIO_TLMM_JTAG_HDRV_CTL_TDO_HDRV_SHFT                                     0x0

#define HWIO_TLMM_RESOUT_HDRV_CTL_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x0009e000)
#define HWIO_TLMM_RESOUT_HDRV_CTL_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x0009e000)
#define HWIO_TLMM_RESOUT_HDRV_CTL_RMSK                                            0x7
#define HWIO_TLMM_RESOUT_HDRV_CTL_IN          \
        in_dword_masked(HWIO_TLMM_RESOUT_HDRV_CTL_ADDR, HWIO_TLMM_RESOUT_HDRV_CTL_RMSK)
#define HWIO_TLMM_RESOUT_HDRV_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_RESOUT_HDRV_CTL_ADDR, m)
#define HWIO_TLMM_RESOUT_HDRV_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_RESOUT_HDRV_CTL_ADDR,v)
#define HWIO_TLMM_RESOUT_HDRV_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_RESOUT_HDRV_CTL_ADDR,m,v,HWIO_TLMM_RESOUT_HDRV_CTL_IN)
#define HWIO_TLMM_RESOUT_HDRV_CTL_RESOUT_N_HDRV_BMSK                              0x7
#define HWIO_TLMM_RESOUT_HDRV_CTL_RESOUT_N_HDRV_SHFT                              0x0

#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_ADDR                                 (TLMM_NORTH_REG_BASE      + 0x0009f000)
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_OFFS                                 (TLMM_NORTH_REG_BASE_OFFS + 0x0009f000)
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_RMSK                                        0xf
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_IN          \
        in_dword_masked(HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_ADDR, HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_RMSK)
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_ADDR, m)
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_ADDR,v)
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_ADDR,m,v,HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_IN)
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_SNDWIRE_DATA_SR_CTL_EN_BMSK                 0xc
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_SNDWIRE_DATA_SR_CTL_EN_SHFT                 0x2
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_SNDWIRE_CLK_SR_CTL_EN_BMSK                  0x3
#define HWIO_TLMM_SNDWIRE_SLIMBUS_CTL_SNDWIRE_CLK_SR_CTL_EN_SHFT                  0x0

#define HWIO_TLMM_BTFM_SLIMBUS_CTL_ADDR                                    (TLMM_NORTH_REG_BASE      + 0x000a0000)
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_OFFS                                    (TLMM_NORTH_REG_BASE_OFFS + 0x000a0000)
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_RMSK                                           0x3
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_IN          \
        in_dword_masked(HWIO_TLMM_BTFM_SLIMBUS_CTL_ADDR, HWIO_TLMM_BTFM_SLIMBUS_CTL_RMSK)
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_BTFM_SLIMBUS_CTL_ADDR, m)
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_BTFM_SLIMBUS_CTL_ADDR,v)
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_BTFM_SLIMBUS_CTL_ADDR,m,v,HWIO_TLMM_BTFM_SLIMBUS_CTL_IN)
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_SR_CTL_EN_BMSK                                 0x3
#define HWIO_TLMM_BTFM_SLIMBUS_CTL_SR_CTL_EN_SHFT                                 0x0

#define HWIO_TLMM_UFS_REF_CLK_CTL_ADDR                                     (TLMM_NORTH_REG_BASE      + 0x000a1000)
#define HWIO_TLMM_UFS_REF_CLK_CTL_OFFS                                     (TLMM_NORTH_REG_BASE_OFFS + 0x000a1000)
#define HWIO_TLMM_UFS_REF_CLK_CTL_RMSK                                           0x1f
#define HWIO_TLMM_UFS_REF_CLK_CTL_IN          \
        in_dword_masked(HWIO_TLMM_UFS_REF_CLK_CTL_ADDR, HWIO_TLMM_UFS_REF_CLK_CTL_RMSK)
#define HWIO_TLMM_UFS_REF_CLK_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_UFS_REF_CLK_CTL_ADDR, m)
#define HWIO_TLMM_UFS_REF_CLK_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_UFS_REF_CLK_CTL_ADDR,v)
#define HWIO_TLMM_UFS_REF_CLK_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_UFS_REF_CLK_CTL_ADDR,m,v,HWIO_TLMM_UFS_REF_CLK_CTL_IN)
#define HWIO_TLMM_UFS_REF_CLK_CTL_UFS_REF_CLK_PULL_BMSK                          0x18
#define HWIO_TLMM_UFS_REF_CLK_CTL_UFS_REF_CLK_PULL_SHFT                           0x3
#define HWIO_TLMM_UFS_REF_CLK_CTL_UFS_REF_CLK_HDRV_BMSK                           0x7
#define HWIO_TLMM_UFS_REF_CLK_CTL_UFS_REF_CLK_HDRV_SHFT                           0x0

#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_ADDR                           (TLMM_NORTH_REG_BASE      + 0x000a2000)
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_OFFS                           (TLMM_NORTH_REG_BASE_OFFS + 0x000a2000)
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_RMSK                                  0x7
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_IN          \
        in_dword_masked(HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_ADDR, HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_RMSK)
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_ADDR, m)
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_ADDR,v)
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_ADDR,m,v,HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_IN)
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_DDR_RESET_N_HDRV_BMSK                 0x7
#define HWIO_TLMM_DDR_RESET_N_HDRV_PULL_CTL_DDR_RESET_N_HDRV_SHFT                 0x0

#define HWIO_TLMM_UFS_RESET_CTL_ADDR                                       (TLMM_NORTH_REG_BASE      + 0x000a3000)
#define HWIO_TLMM_UFS_RESET_CTL_OFFS                                       (TLMM_NORTH_REG_BASE_OFFS + 0x000a3000)
#define HWIO_TLMM_UFS_RESET_CTL_RMSK                                             0x1f
#define HWIO_TLMM_UFS_RESET_CTL_IN          \
        in_dword_masked(HWIO_TLMM_UFS_RESET_CTL_ADDR, HWIO_TLMM_UFS_RESET_CTL_RMSK)
#define HWIO_TLMM_UFS_RESET_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_UFS_RESET_CTL_ADDR, m)
#define HWIO_TLMM_UFS_RESET_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_UFS_RESET_CTL_ADDR,v)
#define HWIO_TLMM_UFS_RESET_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_UFS_RESET_CTL_ADDR,m,v,HWIO_TLMM_UFS_RESET_CTL_IN)
#define HWIO_TLMM_UFS_RESET_CTL_UFS_RESET_PULL_BMSK                              0x18
#define HWIO_TLMM_UFS_RESET_CTL_UFS_RESET_PULL_SHFT                               0x3
#define HWIO_TLMM_UFS_RESET_CTL_UFS_RESET_HDRV_BMSK                               0x7
#define HWIO_TLMM_UFS_RESET_CTL_UFS_RESET_HDRV_SHFT                               0x0

#define HWIO_TLMM_UFS_RESET_ADDR                                           (TLMM_NORTH_REG_BASE      + 0x000a3004)
#define HWIO_TLMM_UFS_RESET_OFFS                                           (TLMM_NORTH_REG_BASE_OFFS + 0x000a3004)
#define HWIO_TLMM_UFS_RESET_RMSK                                                  0x1
#define HWIO_TLMM_UFS_RESET_IN          \
        in_dword_masked(HWIO_TLMM_UFS_RESET_ADDR, HWIO_TLMM_UFS_RESET_RMSK)
#define HWIO_TLMM_UFS_RESET_INM(m)      \
        in_dword_masked(HWIO_TLMM_UFS_RESET_ADDR, m)
#define HWIO_TLMM_UFS_RESET_OUT(v)      \
        out_dword(HWIO_TLMM_UFS_RESET_ADDR,v)
#define HWIO_TLMM_UFS_RESET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_UFS_RESET_ADDR,m,v,HWIO_TLMM_UFS_RESET_IN)
#define HWIO_TLMM_UFS_RESET_UFS_RESET_BMSK                                        0x1
#define HWIO_TLMM_UFS_RESET_UFS_RESET_SHFT                                        0x0

#define HWIO_TLMM_NORTH_SPARE_ADDR                                         (TLMM_NORTH_REG_BASE      + 0x000a4000)
#define HWIO_TLMM_NORTH_SPARE_OFFS                                         (TLMM_NORTH_REG_BASE_OFFS + 0x000a4000)
#define HWIO_TLMM_NORTH_SPARE_RMSK                                         0xffffffff
#define HWIO_TLMM_NORTH_SPARE_IN          \
        in_dword_masked(HWIO_TLMM_NORTH_SPARE_ADDR, HWIO_TLMM_NORTH_SPARE_RMSK)
#define HWIO_TLMM_NORTH_SPARE_INM(m)      \
        in_dword_masked(HWIO_TLMM_NORTH_SPARE_ADDR, m)
#define HWIO_TLMM_NORTH_SPARE_OUT(v)      \
        out_dword(HWIO_TLMM_NORTH_SPARE_ADDR,v)
#define HWIO_TLMM_NORTH_SPARE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_SPARE_ADDR,m,v,HWIO_TLMM_NORTH_SPARE_IN)
#define HWIO_TLMM_NORTH_SPARE_SPARE_BMSK                                   0xffffff00
#define HWIO_TLMM_NORTH_SPARE_SPARE_SHFT                                          0x8
#define HWIO_TLMM_NORTH_SPARE_MISC_BMSK                                          0xff
#define HWIO_TLMM_NORTH_SPARE_MISC_SHFT                                           0x0

#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n)                 (TLMM_NORTH_REG_BASE      + 0x000a5000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_OFFS(n)                 (TLMM_NORTH_REG_BASE_OFFS + 0x000a5000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_RMSK                         0x1ff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_MAXn                             1
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_INI(n)        \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n), HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_RMSK)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n), mask)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n),val)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n),mask,val,HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_INI(n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_POLARITY_BMSK                0x100
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_POLARITY_SHFT                  0x8
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_GPIO_SEL_BMSK                 0xff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_SENSORS_GPIO_SEL_SHFT                  0x0

#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n)                 (TLMM_NORTH_REG_BASE      + 0x000a6000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_OFFS(n)                 (TLMM_NORTH_REG_BASE_OFFS + 0x000a6000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_RMSK                         0x1ff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_MAXn                             5
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_INI(n)        \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n), HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_RMSK)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n), mask)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_OUTI(n,val)    \
        out_dword(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n),val)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n),mask,val,HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_INI(n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_POLARITY_BMSK                0x100
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_POLARITY_SHFT                  0x8
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_GPIO_SEL_BMSK                 0xff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_LPA_DSP_GPIO_SEL_SHFT                  0x0

#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n)                     (TLMM_NORTH_REG_BASE      + 0x000a7000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_OFFS(n)                     (TLMM_NORTH_REG_BASE_OFFS + 0x000a7000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_RMSK                             0x1ff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_MAXn                                 0
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_INI(n)        \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n), HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_RMSK)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n), mask)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_OUTI(n,val)    \
        out_dword(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n),val)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n),mask,val,HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_INI(n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_POLARITY_BMSK                    0x100
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_POLARITY_SHFT                      0x8
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_GPIO_SEL_BMSK                     0xff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_RPM_GPIO_SEL_SHFT                      0x0

#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n)                    (TLMM_NORTH_REG_BASE      + 0x000a8000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_OFFS(n)                    (TLMM_NORTH_REG_BASE_OFFS + 0x000a8000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_RMSK                            0x1ff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_MAXn                                7
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_INI(n)        \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n), HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_RMSK)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n), mask)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n),val)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n),mask,val,HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_INI(n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_POLARITY_BMSK                   0x100
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_POLARITY_SHFT                     0x8
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_GPIO_SEL_BMSK                    0xff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_HMSS_GPIO_SEL_SHFT                     0x0

#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n)                     (TLMM_NORTH_REG_BASE      + 0x000a9000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_OFFS(n)                     (TLMM_NORTH_REG_BASE_OFFS + 0x000a9000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_RMSK                             0x1ff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_MAXn                                 1
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_INI(n)        \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n), HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_RMSK)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n), mask)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n),val)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n),mask,val,HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_INI(n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_POLARITY_BMSK                    0x100
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_POLARITY_SHFT                      0x8
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_GPIO_SEL_BMSK                     0xff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_GSS_GPIO_SEL_SHFT                      0x0

#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n)                    (TLMM_NORTH_REG_BASE      + 0x000aa000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_OFFS(n)                    (TLMM_NORTH_REG_BASE_OFFS + 0x000aa000 + 0x4 * (n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_RMSK                            0x1ff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_MAXn                                1
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_INI(n)        \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n), HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_RMSK)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n), mask)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_OUTI(n,val)    \
        out_dword(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n),val)
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n),mask,val,HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_INI(n))
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_POLARITY_BMSK                   0x100
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_POLARITY_SHFT                     0x8
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_GPIO_SEL_BMSK                    0xff
#define HWIO_TLMM_NORTH_DIR_CONN_INTRn_CFG_CDSP_GPIO_SEL_SHFT                     0x0

/*----------------------------------------------------------------------------
 * MODULE: TLMM_SOUTH
 *--------------------------------------------------------------------------*/

#define TLMM_SOUTH_REG_BASE                                                (TLMM_BASE      + 0x00100000)
#define TLMM_SOUTH_REG_BASE_OFFS                                           0x00100000

#define HWIO_TLMM_GPIO_CFG0_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00000000)
#define HWIO_TLMM_GPIO_CFG0_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00000000)
#define HWIO_TLMM_GPIO_CFG0_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG0_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG0_ADDR, HWIO_TLMM_GPIO_CFG0_RMSK)
#define HWIO_TLMM_GPIO_CFG0_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG0_ADDR, m)
#define HWIO_TLMM_GPIO_CFG0_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG0_ADDR,v)
#define HWIO_TLMM_GPIO_CFG0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG0_ADDR,m,v,HWIO_TLMM_GPIO_CFG0_IN)
#define HWIO_TLMM_GPIO_CFG0_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG0_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG0_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG0_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG0_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG0_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG0_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG0_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG0_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG0_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT0_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00000004)
#define HWIO_TLMM_GPIO_IN_OUT0_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00000004)
#define HWIO_TLMM_GPIO_IN_OUT0_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT0_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT0_ADDR, HWIO_TLMM_GPIO_IN_OUT0_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT0_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT0_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT0_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT0_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT0_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT0_IN)
#define HWIO_TLMM_GPIO_IN_OUT0_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT0_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT0_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT0_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG0_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00000008)
#define HWIO_TLMM_GPIO_INTR_CFG0_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00000008)
#define HWIO_TLMM_GPIO_INTR_CFG0_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG0_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG0_ADDR, HWIO_TLMM_GPIO_INTR_CFG0_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG0_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG0_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG0_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG0_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG0_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG0_IN)
#define HWIO_TLMM_GPIO_INTR_CFG0_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG0_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG0_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG0_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG0_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS0_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000000c)
#define HWIO_TLMM_GPIO_INTR_STATUS0_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000000c)
#define HWIO_TLMM_GPIO_INTR_STATUS0_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS0_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS0_ADDR, HWIO_TLMM_GPIO_INTR_STATUS0_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS0_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS0_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS0_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS0_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS0_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS0_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS0_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS0_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS0_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00000010)
#define HWIO_TLMM_GPIO_ID_STATUS0_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00000010)
#define HWIO_TLMM_GPIO_ID_STATUS0_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS0_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS0_ADDR, HWIO_TLMM_GPIO_ID_STATUS0_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS0_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS0_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS0_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS0_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG1_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00001000)
#define HWIO_TLMM_GPIO_CFG1_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00001000)
#define HWIO_TLMM_GPIO_CFG1_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG1_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG1_ADDR, HWIO_TLMM_GPIO_CFG1_RMSK)
#define HWIO_TLMM_GPIO_CFG1_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG1_ADDR, m)
#define HWIO_TLMM_GPIO_CFG1_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG1_ADDR,v)
#define HWIO_TLMM_GPIO_CFG1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG1_ADDR,m,v,HWIO_TLMM_GPIO_CFG1_IN)
#define HWIO_TLMM_GPIO_CFG1_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG1_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG1_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG1_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG1_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG1_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG1_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG1_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG1_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG1_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT1_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00001004)
#define HWIO_TLMM_GPIO_IN_OUT1_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00001004)
#define HWIO_TLMM_GPIO_IN_OUT1_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT1_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT1_ADDR, HWIO_TLMM_GPIO_IN_OUT1_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT1_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT1_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT1_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT1_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT1_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT1_IN)
#define HWIO_TLMM_GPIO_IN_OUT1_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT1_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT1_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT1_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG1_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00001008)
#define HWIO_TLMM_GPIO_INTR_CFG1_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00001008)
#define HWIO_TLMM_GPIO_INTR_CFG1_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG1_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG1_ADDR, HWIO_TLMM_GPIO_INTR_CFG1_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG1_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG1_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG1_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG1_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG1_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG1_IN)
#define HWIO_TLMM_GPIO_INTR_CFG1_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG1_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG1_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG1_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG1_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS1_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000100c)
#define HWIO_TLMM_GPIO_INTR_STATUS1_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000100c)
#define HWIO_TLMM_GPIO_INTR_STATUS1_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS1_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS1_ADDR, HWIO_TLMM_GPIO_INTR_STATUS1_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS1_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS1_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS1_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS1_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS1_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS1_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS1_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS1_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS1_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00001010)
#define HWIO_TLMM_GPIO_ID_STATUS1_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00001010)
#define HWIO_TLMM_GPIO_ID_STATUS1_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS1_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS1_ADDR, HWIO_TLMM_GPIO_ID_STATUS1_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS1_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS1_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS1_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS1_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG2_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00002000)
#define HWIO_TLMM_GPIO_CFG2_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00002000)
#define HWIO_TLMM_GPIO_CFG2_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG2_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG2_ADDR, HWIO_TLMM_GPIO_CFG2_RMSK)
#define HWIO_TLMM_GPIO_CFG2_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG2_ADDR, m)
#define HWIO_TLMM_GPIO_CFG2_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG2_ADDR,v)
#define HWIO_TLMM_GPIO_CFG2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG2_ADDR,m,v,HWIO_TLMM_GPIO_CFG2_IN)
#define HWIO_TLMM_GPIO_CFG2_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG2_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG2_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG2_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG2_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG2_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG2_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG2_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG2_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG2_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT2_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00002004)
#define HWIO_TLMM_GPIO_IN_OUT2_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00002004)
#define HWIO_TLMM_GPIO_IN_OUT2_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT2_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT2_ADDR, HWIO_TLMM_GPIO_IN_OUT2_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT2_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT2_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT2_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT2_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT2_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT2_IN)
#define HWIO_TLMM_GPIO_IN_OUT2_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT2_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT2_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT2_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG2_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00002008)
#define HWIO_TLMM_GPIO_INTR_CFG2_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00002008)
#define HWIO_TLMM_GPIO_INTR_CFG2_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG2_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG2_ADDR, HWIO_TLMM_GPIO_INTR_CFG2_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG2_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG2_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG2_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG2_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG2_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG2_IN)
#define HWIO_TLMM_GPIO_INTR_CFG2_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG2_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG2_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG2_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG2_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS2_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000200c)
#define HWIO_TLMM_GPIO_INTR_STATUS2_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000200c)
#define HWIO_TLMM_GPIO_INTR_STATUS2_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS2_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS2_ADDR, HWIO_TLMM_GPIO_INTR_STATUS2_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS2_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS2_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS2_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS2_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS2_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS2_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS2_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS2_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS2_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00002010)
#define HWIO_TLMM_GPIO_ID_STATUS2_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00002010)
#define HWIO_TLMM_GPIO_ID_STATUS2_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS2_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS2_ADDR, HWIO_TLMM_GPIO_ID_STATUS2_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS2_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS2_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS2_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS2_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG3_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00003000)
#define HWIO_TLMM_GPIO_CFG3_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00003000)
#define HWIO_TLMM_GPIO_CFG3_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG3_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG3_ADDR, HWIO_TLMM_GPIO_CFG3_RMSK)
#define HWIO_TLMM_GPIO_CFG3_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG3_ADDR, m)
#define HWIO_TLMM_GPIO_CFG3_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG3_ADDR,v)
#define HWIO_TLMM_GPIO_CFG3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG3_ADDR,m,v,HWIO_TLMM_GPIO_CFG3_IN)
#define HWIO_TLMM_GPIO_CFG3_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG3_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG3_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG3_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG3_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG3_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG3_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG3_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG3_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG3_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT3_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00003004)
#define HWIO_TLMM_GPIO_IN_OUT3_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00003004)
#define HWIO_TLMM_GPIO_IN_OUT3_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT3_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT3_ADDR, HWIO_TLMM_GPIO_IN_OUT3_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT3_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT3_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT3_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT3_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT3_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT3_IN)
#define HWIO_TLMM_GPIO_IN_OUT3_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT3_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT3_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT3_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG3_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00003008)
#define HWIO_TLMM_GPIO_INTR_CFG3_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00003008)
#define HWIO_TLMM_GPIO_INTR_CFG3_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG3_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG3_ADDR, HWIO_TLMM_GPIO_INTR_CFG3_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG3_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG3_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG3_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG3_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG3_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG3_IN)
#define HWIO_TLMM_GPIO_INTR_CFG3_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG3_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG3_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG3_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG3_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS3_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000300c)
#define HWIO_TLMM_GPIO_INTR_STATUS3_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000300c)
#define HWIO_TLMM_GPIO_INTR_STATUS3_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS3_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS3_ADDR, HWIO_TLMM_GPIO_INTR_STATUS3_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS3_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS3_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS3_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS3_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS3_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS3_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS3_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS3_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS3_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS3_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00003010)
#define HWIO_TLMM_GPIO_ID_STATUS3_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00003010)
#define HWIO_TLMM_GPIO_ID_STATUS3_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS3_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS3_ADDR, HWIO_TLMM_GPIO_ID_STATUS3_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS3_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS3_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS3_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS3_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG5_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00005000)
#define HWIO_TLMM_GPIO_CFG5_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00005000)
#define HWIO_TLMM_GPIO_CFG5_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG5_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG5_ADDR, HWIO_TLMM_GPIO_CFG5_RMSK)
#define HWIO_TLMM_GPIO_CFG5_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG5_ADDR, m)
#define HWIO_TLMM_GPIO_CFG5_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG5_ADDR,v)
#define HWIO_TLMM_GPIO_CFG5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG5_ADDR,m,v,HWIO_TLMM_GPIO_CFG5_IN)
#define HWIO_TLMM_GPIO_CFG5_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG5_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG5_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG5_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG5_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG5_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG5_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG5_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG5_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG5_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT5_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00005004)
#define HWIO_TLMM_GPIO_IN_OUT5_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00005004)
#define HWIO_TLMM_GPIO_IN_OUT5_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT5_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT5_ADDR, HWIO_TLMM_GPIO_IN_OUT5_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT5_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT5_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT5_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT5_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT5_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT5_IN)
#define HWIO_TLMM_GPIO_IN_OUT5_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT5_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT5_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT5_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG5_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00005008)
#define HWIO_TLMM_GPIO_INTR_CFG5_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00005008)
#define HWIO_TLMM_GPIO_INTR_CFG5_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG5_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG5_ADDR, HWIO_TLMM_GPIO_INTR_CFG5_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG5_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG5_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG5_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG5_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG5_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG5_IN)
#define HWIO_TLMM_GPIO_INTR_CFG5_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG5_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG5_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG5_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG5_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS5_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000500c)
#define HWIO_TLMM_GPIO_INTR_STATUS5_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000500c)
#define HWIO_TLMM_GPIO_INTR_STATUS5_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS5_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS5_ADDR, HWIO_TLMM_GPIO_INTR_STATUS5_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS5_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS5_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS5_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS5_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS5_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS5_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS5_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS5_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS5_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS5_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00005010)
#define HWIO_TLMM_GPIO_ID_STATUS5_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00005010)
#define HWIO_TLMM_GPIO_ID_STATUS5_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS5_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS5_ADDR, HWIO_TLMM_GPIO_ID_STATUS5_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS5_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS5_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS5_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS5_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG6_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00006000)
#define HWIO_TLMM_GPIO_CFG6_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00006000)
#define HWIO_TLMM_GPIO_CFG6_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG6_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG6_ADDR, HWIO_TLMM_GPIO_CFG6_RMSK)
#define HWIO_TLMM_GPIO_CFG6_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG6_ADDR, m)
#define HWIO_TLMM_GPIO_CFG6_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG6_ADDR,v)
#define HWIO_TLMM_GPIO_CFG6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG6_ADDR,m,v,HWIO_TLMM_GPIO_CFG6_IN)
#define HWIO_TLMM_GPIO_CFG6_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG6_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG6_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG6_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG6_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG6_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG6_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG6_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG6_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG6_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT6_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00006004)
#define HWIO_TLMM_GPIO_IN_OUT6_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00006004)
#define HWIO_TLMM_GPIO_IN_OUT6_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT6_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT6_ADDR, HWIO_TLMM_GPIO_IN_OUT6_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT6_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT6_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT6_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT6_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT6_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT6_IN)
#define HWIO_TLMM_GPIO_IN_OUT6_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT6_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT6_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT6_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG6_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00006008)
#define HWIO_TLMM_GPIO_INTR_CFG6_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00006008)
#define HWIO_TLMM_GPIO_INTR_CFG6_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG6_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG6_ADDR, HWIO_TLMM_GPIO_INTR_CFG6_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG6_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG6_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG6_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG6_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG6_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG6_IN)
#define HWIO_TLMM_GPIO_INTR_CFG6_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG6_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG6_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG6_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG6_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS6_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000600c)
#define HWIO_TLMM_GPIO_INTR_STATUS6_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000600c)
#define HWIO_TLMM_GPIO_INTR_STATUS6_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS6_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS6_ADDR, HWIO_TLMM_GPIO_INTR_STATUS6_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS6_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS6_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS6_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS6_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS6_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS6_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS6_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS6_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS6_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS6_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00006010)
#define HWIO_TLMM_GPIO_ID_STATUS6_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00006010)
#define HWIO_TLMM_GPIO_ID_STATUS6_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS6_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS6_ADDR, HWIO_TLMM_GPIO_ID_STATUS6_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS6_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS6_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS6_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS6_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG7_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x00007000)
#define HWIO_TLMM_GPIO_CFG7_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00007000)
#define HWIO_TLMM_GPIO_CFG7_RMSK                                                0x7ff
#define HWIO_TLMM_GPIO_CFG7_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG7_ADDR, HWIO_TLMM_GPIO_CFG7_RMSK)
#define HWIO_TLMM_GPIO_CFG7_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG7_ADDR, m)
#define HWIO_TLMM_GPIO_CFG7_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG7_ADDR,v)
#define HWIO_TLMM_GPIO_CFG7_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG7_ADDR,m,v,HWIO_TLMM_GPIO_CFG7_IN)
#define HWIO_TLMM_GPIO_CFG7_GPIO_HIHYS_EN_BMSK                                  0x400
#define HWIO_TLMM_GPIO_CFG7_GPIO_HIHYS_EN_SHFT                                    0xa
#define HWIO_TLMM_GPIO_CFG7_GPIO_OE_BMSK                                        0x200
#define HWIO_TLMM_GPIO_CFG7_GPIO_OE_SHFT                                          0x9
#define HWIO_TLMM_GPIO_CFG7_DRV_STRENGTH_BMSK                                   0x1c0
#define HWIO_TLMM_GPIO_CFG7_DRV_STRENGTH_SHFT                                     0x6
#define HWIO_TLMM_GPIO_CFG7_FUNC_SEL_BMSK                                        0x3c
#define HWIO_TLMM_GPIO_CFG7_FUNC_SEL_SHFT                                         0x2
#define HWIO_TLMM_GPIO_CFG7_GPIO_PULL_BMSK                                        0x3
#define HWIO_TLMM_GPIO_CFG7_GPIO_PULL_SHFT                                        0x0

#define HWIO_TLMM_GPIO_IN_OUT7_ADDR                                        (TLMM_SOUTH_REG_BASE      + 0x00007004)
#define HWIO_TLMM_GPIO_IN_OUT7_OFFS                                        (TLMM_SOUTH_REG_BASE_OFFS + 0x00007004)
#define HWIO_TLMM_GPIO_IN_OUT7_RMSK                                               0x3
#define HWIO_TLMM_GPIO_IN_OUT7_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT7_ADDR, HWIO_TLMM_GPIO_IN_OUT7_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT7_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT7_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT7_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT7_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT7_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT7_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT7_IN)
#define HWIO_TLMM_GPIO_IN_OUT7_GPIO_OUT_BMSK                                      0x2
#define HWIO_TLMM_GPIO_IN_OUT7_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT7_GPIO_IN_BMSK                                       0x1
#define HWIO_TLMM_GPIO_IN_OUT7_GPIO_IN_SHFT                                       0x0

#define HWIO_TLMM_GPIO_INTR_CFG7_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00007008)
#define HWIO_TLMM_GPIO_INTR_CFG7_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00007008)
#define HWIO_TLMM_GPIO_INTR_CFG7_RMSK                                           0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG7_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG7_ADDR, HWIO_TLMM_GPIO_INTR_CFG7_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG7_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG7_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG7_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG7_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG7_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG7_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG7_IN)
#define HWIO_TLMM_GPIO_INTR_CFG7_DIR_CONN_EN_BMSK                               0x100
#define HWIO_TLMM_GPIO_INTR_CFG7_DIR_CONN_EN_SHFT                                 0x8
#define HWIO_TLMM_GPIO_INTR_CFG7_TARGET_PROC_BMSK                                0xe0
#define HWIO_TLMM_GPIO_INTR_CFG7_TARGET_PROC_SHFT                                 0x5
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_RAW_STATUS_EN_BMSK                         0x10
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_RAW_STATUS_EN_SHFT                          0x4
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_DECT_CTL_BMSK                               0xc
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_DECT_CTL_SHFT                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_POL_CTL_BMSK                                0x2
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_POL_CTL_SHFT                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_ENABLE_BMSK                                 0x1
#define HWIO_TLMM_GPIO_INTR_CFG7_INTR_ENABLE_SHFT                                 0x0

#define HWIO_TLMM_GPIO_INTR_STATUS7_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0000700c)
#define HWIO_TLMM_GPIO_INTR_STATUS7_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0000700c)
#define HWIO_TLMM_GPIO_INTR_STATUS7_RMSK                                          0x1
#define HWIO_TLMM_GPIO_INTR_STATUS7_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS7_ADDR, HWIO_TLMM_GPIO_INTR_STATUS7_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS7_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS7_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS7_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS7_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS7_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS7_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS7_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS7_INTR_STATUS_BMSK                              0x1
#define HWIO_TLMM_GPIO_INTR_STATUS7_INTR_STATUS_SHFT                              0x0

#define HWIO_TLMM_GPIO_ID_STATUS7_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00007010)
#define HWIO_TLMM_GPIO_ID_STATUS7_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00007010)
#define HWIO_TLMM_GPIO_ID_STATUS7_RMSK                                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS7_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS7_ADDR, HWIO_TLMM_GPIO_ID_STATUS7_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS7_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS7_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS7_GPIO_ID_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_ID_STATUS7_GPIO_ID_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_CFG20_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00014000)
#define HWIO_TLMM_GPIO_CFG20_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00014000)
#define HWIO_TLMM_GPIO_CFG20_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG20_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG20_ADDR, HWIO_TLMM_GPIO_CFG20_RMSK)
#define HWIO_TLMM_GPIO_CFG20_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG20_ADDR, m)
#define HWIO_TLMM_GPIO_CFG20_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG20_ADDR,v)
#define HWIO_TLMM_GPIO_CFG20_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG20_ADDR,m,v,HWIO_TLMM_GPIO_CFG20_IN)
#define HWIO_TLMM_GPIO_CFG20_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG20_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG20_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG20_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG20_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG20_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG20_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG20_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG20_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG20_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT20_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00014004)
#define HWIO_TLMM_GPIO_IN_OUT20_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00014004)
#define HWIO_TLMM_GPIO_IN_OUT20_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT20_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT20_ADDR, HWIO_TLMM_GPIO_IN_OUT20_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT20_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT20_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT20_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT20_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT20_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT20_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT20_IN)
#define HWIO_TLMM_GPIO_IN_OUT20_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT20_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT20_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT20_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG20_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00014008)
#define HWIO_TLMM_GPIO_INTR_CFG20_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00014008)
#define HWIO_TLMM_GPIO_INTR_CFG20_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG20_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG20_ADDR, HWIO_TLMM_GPIO_INTR_CFG20_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG20_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG20_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG20_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG20_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG20_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG20_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG20_IN)
#define HWIO_TLMM_GPIO_INTR_CFG20_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG20_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG20_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG20_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG20_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS20_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0001400c)
#define HWIO_TLMM_GPIO_INTR_STATUS20_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0001400c)
#define HWIO_TLMM_GPIO_INTR_STATUS20_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS20_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS20_ADDR, HWIO_TLMM_GPIO_INTR_STATUS20_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS20_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS20_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS20_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS20_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS20_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS20_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS20_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS20_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS20_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS20_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00014010)
#define HWIO_TLMM_GPIO_ID_STATUS20_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00014010)
#define HWIO_TLMM_GPIO_ID_STATUS20_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS20_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS20_ADDR, HWIO_TLMM_GPIO_ID_STATUS20_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS20_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS20_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS20_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS20_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG21_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00015000)
#define HWIO_TLMM_GPIO_CFG21_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00015000)
#define HWIO_TLMM_GPIO_CFG21_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG21_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG21_ADDR, HWIO_TLMM_GPIO_CFG21_RMSK)
#define HWIO_TLMM_GPIO_CFG21_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG21_ADDR, m)
#define HWIO_TLMM_GPIO_CFG21_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG21_ADDR,v)
#define HWIO_TLMM_GPIO_CFG21_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG21_ADDR,m,v,HWIO_TLMM_GPIO_CFG21_IN)
#define HWIO_TLMM_GPIO_CFG21_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG21_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG21_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG21_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG21_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG21_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG21_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG21_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG21_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG21_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT21_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00015004)
#define HWIO_TLMM_GPIO_IN_OUT21_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00015004)
#define HWIO_TLMM_GPIO_IN_OUT21_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT21_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT21_ADDR, HWIO_TLMM_GPIO_IN_OUT21_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT21_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT21_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT21_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT21_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT21_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT21_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT21_IN)
#define HWIO_TLMM_GPIO_IN_OUT21_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT21_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT21_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT21_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG21_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00015008)
#define HWIO_TLMM_GPIO_INTR_CFG21_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00015008)
#define HWIO_TLMM_GPIO_INTR_CFG21_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG21_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG21_ADDR, HWIO_TLMM_GPIO_INTR_CFG21_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG21_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG21_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG21_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG21_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG21_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG21_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG21_IN)
#define HWIO_TLMM_GPIO_INTR_CFG21_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG21_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG21_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG21_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG21_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS21_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0001500c)
#define HWIO_TLMM_GPIO_INTR_STATUS21_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0001500c)
#define HWIO_TLMM_GPIO_INTR_STATUS21_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS21_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS21_ADDR, HWIO_TLMM_GPIO_INTR_STATUS21_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS21_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS21_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS21_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS21_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS21_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS21_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS21_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS21_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS21_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS21_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00015010)
#define HWIO_TLMM_GPIO_ID_STATUS21_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00015010)
#define HWIO_TLMM_GPIO_ID_STATUS21_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS21_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS21_ADDR, HWIO_TLMM_GPIO_ID_STATUS21_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS21_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS21_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS21_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS21_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG32_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00020000)
#define HWIO_TLMM_GPIO_CFG32_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00020000)
#define HWIO_TLMM_GPIO_CFG32_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG32_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG32_ADDR, HWIO_TLMM_GPIO_CFG32_RMSK)
#define HWIO_TLMM_GPIO_CFG32_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG32_ADDR, m)
#define HWIO_TLMM_GPIO_CFG32_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG32_ADDR,v)
#define HWIO_TLMM_GPIO_CFG32_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG32_ADDR,m,v,HWIO_TLMM_GPIO_CFG32_IN)
#define HWIO_TLMM_GPIO_CFG32_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG32_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG32_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG32_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG32_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG32_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG32_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG32_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG32_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG32_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT32_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00020004)
#define HWIO_TLMM_GPIO_IN_OUT32_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00020004)
#define HWIO_TLMM_GPIO_IN_OUT32_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT32_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT32_ADDR, HWIO_TLMM_GPIO_IN_OUT32_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT32_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT32_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT32_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT32_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT32_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT32_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT32_IN)
#define HWIO_TLMM_GPIO_IN_OUT32_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT32_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT32_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT32_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG32_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00020008)
#define HWIO_TLMM_GPIO_INTR_CFG32_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00020008)
#define HWIO_TLMM_GPIO_INTR_CFG32_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG32_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG32_ADDR, HWIO_TLMM_GPIO_INTR_CFG32_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG32_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG32_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG32_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG32_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG32_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG32_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG32_IN)
#define HWIO_TLMM_GPIO_INTR_CFG32_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG32_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG32_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG32_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG32_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS32_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002000c)
#define HWIO_TLMM_GPIO_INTR_STATUS32_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002000c)
#define HWIO_TLMM_GPIO_INTR_STATUS32_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS32_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS32_ADDR, HWIO_TLMM_GPIO_INTR_STATUS32_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS32_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS32_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS32_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS32_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS32_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS32_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS32_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS32_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS32_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS32_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00020010)
#define HWIO_TLMM_GPIO_ID_STATUS32_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00020010)
#define HWIO_TLMM_GPIO_ID_STATUS32_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS32_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS32_ADDR, HWIO_TLMM_GPIO_ID_STATUS32_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS32_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS32_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS32_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS32_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG33_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00021000)
#define HWIO_TLMM_GPIO_CFG33_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00021000)
#define HWIO_TLMM_GPIO_CFG33_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG33_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG33_ADDR, HWIO_TLMM_GPIO_CFG33_RMSK)
#define HWIO_TLMM_GPIO_CFG33_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG33_ADDR, m)
#define HWIO_TLMM_GPIO_CFG33_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG33_ADDR,v)
#define HWIO_TLMM_GPIO_CFG33_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG33_ADDR,m,v,HWIO_TLMM_GPIO_CFG33_IN)
#define HWIO_TLMM_GPIO_CFG33_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG33_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG33_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG33_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG33_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG33_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG33_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG33_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG33_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG33_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT33_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00021004)
#define HWIO_TLMM_GPIO_IN_OUT33_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00021004)
#define HWIO_TLMM_GPIO_IN_OUT33_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT33_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT33_ADDR, HWIO_TLMM_GPIO_IN_OUT33_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT33_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT33_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT33_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT33_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT33_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT33_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT33_IN)
#define HWIO_TLMM_GPIO_IN_OUT33_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT33_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT33_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT33_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG33_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00021008)
#define HWIO_TLMM_GPIO_INTR_CFG33_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00021008)
#define HWIO_TLMM_GPIO_INTR_CFG33_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG33_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG33_ADDR, HWIO_TLMM_GPIO_INTR_CFG33_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG33_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG33_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG33_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG33_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG33_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG33_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG33_IN)
#define HWIO_TLMM_GPIO_INTR_CFG33_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG33_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG33_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG33_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG33_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS33_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002100c)
#define HWIO_TLMM_GPIO_INTR_STATUS33_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002100c)
#define HWIO_TLMM_GPIO_INTR_STATUS33_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS33_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS33_ADDR, HWIO_TLMM_GPIO_INTR_STATUS33_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS33_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS33_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS33_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS33_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS33_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS33_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS33_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS33_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS33_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS33_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00021010)
#define HWIO_TLMM_GPIO_ID_STATUS33_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00021010)
#define HWIO_TLMM_GPIO_ID_STATUS33_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS33_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS33_ADDR, HWIO_TLMM_GPIO_ID_STATUS33_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS33_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS33_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS33_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS33_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG34_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00022000)
#define HWIO_TLMM_GPIO_CFG34_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00022000)
#define HWIO_TLMM_GPIO_CFG34_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG34_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG34_ADDR, HWIO_TLMM_GPIO_CFG34_RMSK)
#define HWIO_TLMM_GPIO_CFG34_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG34_ADDR, m)
#define HWIO_TLMM_GPIO_CFG34_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG34_ADDR,v)
#define HWIO_TLMM_GPIO_CFG34_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG34_ADDR,m,v,HWIO_TLMM_GPIO_CFG34_IN)
#define HWIO_TLMM_GPIO_CFG34_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG34_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG34_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG34_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG34_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG34_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG34_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG34_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG34_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG34_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT34_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00022004)
#define HWIO_TLMM_GPIO_IN_OUT34_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00022004)
#define HWIO_TLMM_GPIO_IN_OUT34_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT34_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT34_ADDR, HWIO_TLMM_GPIO_IN_OUT34_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT34_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT34_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT34_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT34_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT34_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT34_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT34_IN)
#define HWIO_TLMM_GPIO_IN_OUT34_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT34_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT34_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT34_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG34_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00022008)
#define HWIO_TLMM_GPIO_INTR_CFG34_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00022008)
#define HWIO_TLMM_GPIO_INTR_CFG34_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG34_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG34_ADDR, HWIO_TLMM_GPIO_INTR_CFG34_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG34_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG34_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG34_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG34_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG34_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG34_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG34_IN)
#define HWIO_TLMM_GPIO_INTR_CFG34_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG34_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG34_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG34_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG34_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS34_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002200c)
#define HWIO_TLMM_GPIO_INTR_STATUS34_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002200c)
#define HWIO_TLMM_GPIO_INTR_STATUS34_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS34_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS34_ADDR, HWIO_TLMM_GPIO_INTR_STATUS34_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS34_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS34_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS34_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS34_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS34_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS34_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS34_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS34_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS34_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS34_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00022010)
#define HWIO_TLMM_GPIO_ID_STATUS34_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00022010)
#define HWIO_TLMM_GPIO_ID_STATUS34_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS34_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS34_ADDR, HWIO_TLMM_GPIO_ID_STATUS34_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS34_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS34_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS34_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS34_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG35_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00023000)
#define HWIO_TLMM_GPIO_CFG35_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00023000)
#define HWIO_TLMM_GPIO_CFG35_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG35_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG35_ADDR, HWIO_TLMM_GPIO_CFG35_RMSK)
#define HWIO_TLMM_GPIO_CFG35_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG35_ADDR, m)
#define HWIO_TLMM_GPIO_CFG35_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG35_ADDR,v)
#define HWIO_TLMM_GPIO_CFG35_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG35_ADDR,m,v,HWIO_TLMM_GPIO_CFG35_IN)
#define HWIO_TLMM_GPIO_CFG35_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG35_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG35_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG35_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG35_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG35_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG35_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG35_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG35_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG35_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT35_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00023004)
#define HWIO_TLMM_GPIO_IN_OUT35_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00023004)
#define HWIO_TLMM_GPIO_IN_OUT35_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT35_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT35_ADDR, HWIO_TLMM_GPIO_IN_OUT35_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT35_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT35_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT35_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT35_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT35_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT35_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT35_IN)
#define HWIO_TLMM_GPIO_IN_OUT35_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT35_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT35_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT35_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG35_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00023008)
#define HWIO_TLMM_GPIO_INTR_CFG35_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00023008)
#define HWIO_TLMM_GPIO_INTR_CFG35_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG35_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG35_ADDR, HWIO_TLMM_GPIO_INTR_CFG35_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG35_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG35_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG35_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG35_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG35_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG35_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG35_IN)
#define HWIO_TLMM_GPIO_INTR_CFG35_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG35_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG35_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG35_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG35_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS35_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002300c)
#define HWIO_TLMM_GPIO_INTR_STATUS35_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002300c)
#define HWIO_TLMM_GPIO_INTR_STATUS35_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS35_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS35_ADDR, HWIO_TLMM_GPIO_INTR_STATUS35_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS35_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS35_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS35_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS35_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS35_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS35_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS35_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS35_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS35_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS35_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00023010)
#define HWIO_TLMM_GPIO_ID_STATUS35_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00023010)
#define HWIO_TLMM_GPIO_ID_STATUS35_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS35_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS35_ADDR, HWIO_TLMM_GPIO_ID_STATUS35_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS35_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS35_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS35_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS35_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG36_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00024000)
#define HWIO_TLMM_GPIO_CFG36_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00024000)
#define HWIO_TLMM_GPIO_CFG36_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG36_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG36_ADDR, HWIO_TLMM_GPIO_CFG36_RMSK)
#define HWIO_TLMM_GPIO_CFG36_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG36_ADDR, m)
#define HWIO_TLMM_GPIO_CFG36_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG36_ADDR,v)
#define HWIO_TLMM_GPIO_CFG36_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG36_ADDR,m,v,HWIO_TLMM_GPIO_CFG36_IN)
#define HWIO_TLMM_GPIO_CFG36_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG36_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG36_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG36_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG36_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG36_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG36_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG36_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG36_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG36_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT36_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00024004)
#define HWIO_TLMM_GPIO_IN_OUT36_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00024004)
#define HWIO_TLMM_GPIO_IN_OUT36_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT36_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT36_ADDR, HWIO_TLMM_GPIO_IN_OUT36_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT36_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT36_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT36_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT36_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT36_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT36_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT36_IN)
#define HWIO_TLMM_GPIO_IN_OUT36_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT36_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT36_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT36_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG36_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00024008)
#define HWIO_TLMM_GPIO_INTR_CFG36_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00024008)
#define HWIO_TLMM_GPIO_INTR_CFG36_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG36_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG36_ADDR, HWIO_TLMM_GPIO_INTR_CFG36_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG36_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG36_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG36_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG36_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG36_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG36_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG36_IN)
#define HWIO_TLMM_GPIO_INTR_CFG36_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG36_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG36_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG36_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG36_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS36_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002400c)
#define HWIO_TLMM_GPIO_INTR_STATUS36_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002400c)
#define HWIO_TLMM_GPIO_INTR_STATUS36_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS36_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS36_ADDR, HWIO_TLMM_GPIO_INTR_STATUS36_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS36_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS36_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS36_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS36_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS36_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS36_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS36_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS36_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS36_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS36_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00024010)
#define HWIO_TLMM_GPIO_ID_STATUS36_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00024010)
#define HWIO_TLMM_GPIO_ID_STATUS36_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS36_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS36_ADDR, HWIO_TLMM_GPIO_ID_STATUS36_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS36_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS36_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS36_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS36_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG37_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00025000)
#define HWIO_TLMM_GPIO_CFG37_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00025000)
#define HWIO_TLMM_GPIO_CFG37_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG37_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG37_ADDR, HWIO_TLMM_GPIO_CFG37_RMSK)
#define HWIO_TLMM_GPIO_CFG37_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG37_ADDR, m)
#define HWIO_TLMM_GPIO_CFG37_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG37_ADDR,v)
#define HWIO_TLMM_GPIO_CFG37_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG37_ADDR,m,v,HWIO_TLMM_GPIO_CFG37_IN)
#define HWIO_TLMM_GPIO_CFG37_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG37_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG37_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG37_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG37_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG37_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG37_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG37_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG37_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG37_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT37_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00025004)
#define HWIO_TLMM_GPIO_IN_OUT37_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00025004)
#define HWIO_TLMM_GPIO_IN_OUT37_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT37_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT37_ADDR, HWIO_TLMM_GPIO_IN_OUT37_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT37_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT37_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT37_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT37_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT37_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT37_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT37_IN)
#define HWIO_TLMM_GPIO_IN_OUT37_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT37_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT37_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT37_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG37_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00025008)
#define HWIO_TLMM_GPIO_INTR_CFG37_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00025008)
#define HWIO_TLMM_GPIO_INTR_CFG37_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG37_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG37_ADDR, HWIO_TLMM_GPIO_INTR_CFG37_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG37_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG37_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG37_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG37_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG37_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG37_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG37_IN)
#define HWIO_TLMM_GPIO_INTR_CFG37_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG37_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG37_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG37_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG37_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS37_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002500c)
#define HWIO_TLMM_GPIO_INTR_STATUS37_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002500c)
#define HWIO_TLMM_GPIO_INTR_STATUS37_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS37_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS37_ADDR, HWIO_TLMM_GPIO_INTR_STATUS37_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS37_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS37_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS37_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS37_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS37_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS37_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS37_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS37_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS37_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS37_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00025010)
#define HWIO_TLMM_GPIO_ID_STATUS37_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00025010)
#define HWIO_TLMM_GPIO_ID_STATUS37_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS37_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS37_ADDR, HWIO_TLMM_GPIO_ID_STATUS37_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS37_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS37_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS37_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS37_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG38_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00026000)
#define HWIO_TLMM_GPIO_CFG38_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00026000)
#define HWIO_TLMM_GPIO_CFG38_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG38_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG38_ADDR, HWIO_TLMM_GPIO_CFG38_RMSK)
#define HWIO_TLMM_GPIO_CFG38_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG38_ADDR, m)
#define HWIO_TLMM_GPIO_CFG38_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG38_ADDR,v)
#define HWIO_TLMM_GPIO_CFG38_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG38_ADDR,m,v,HWIO_TLMM_GPIO_CFG38_IN)
#define HWIO_TLMM_GPIO_CFG38_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG38_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG38_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG38_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG38_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG38_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG38_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG38_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG38_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG38_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT38_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00026004)
#define HWIO_TLMM_GPIO_IN_OUT38_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00026004)
#define HWIO_TLMM_GPIO_IN_OUT38_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT38_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT38_ADDR, HWIO_TLMM_GPIO_IN_OUT38_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT38_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT38_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT38_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT38_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT38_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT38_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT38_IN)
#define HWIO_TLMM_GPIO_IN_OUT38_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT38_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT38_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT38_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG38_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00026008)
#define HWIO_TLMM_GPIO_INTR_CFG38_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00026008)
#define HWIO_TLMM_GPIO_INTR_CFG38_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG38_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG38_ADDR, HWIO_TLMM_GPIO_INTR_CFG38_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG38_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG38_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG38_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG38_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG38_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG38_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG38_IN)
#define HWIO_TLMM_GPIO_INTR_CFG38_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG38_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG38_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG38_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG38_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS38_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002600c)
#define HWIO_TLMM_GPIO_INTR_STATUS38_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002600c)
#define HWIO_TLMM_GPIO_INTR_STATUS38_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS38_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS38_ADDR, HWIO_TLMM_GPIO_INTR_STATUS38_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS38_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS38_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS38_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS38_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS38_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS38_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS38_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS38_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS38_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS38_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00026010)
#define HWIO_TLMM_GPIO_ID_STATUS38_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00026010)
#define HWIO_TLMM_GPIO_ID_STATUS38_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS38_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS38_ADDR, HWIO_TLMM_GPIO_ID_STATUS38_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS38_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS38_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS38_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS38_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG39_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00027000)
#define HWIO_TLMM_GPIO_CFG39_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00027000)
#define HWIO_TLMM_GPIO_CFG39_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG39_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG39_ADDR, HWIO_TLMM_GPIO_CFG39_RMSK)
#define HWIO_TLMM_GPIO_CFG39_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG39_ADDR, m)
#define HWIO_TLMM_GPIO_CFG39_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG39_ADDR,v)
#define HWIO_TLMM_GPIO_CFG39_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG39_ADDR,m,v,HWIO_TLMM_GPIO_CFG39_IN)
#define HWIO_TLMM_GPIO_CFG39_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG39_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG39_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG39_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG39_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG39_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG39_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG39_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG39_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG39_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT39_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00027004)
#define HWIO_TLMM_GPIO_IN_OUT39_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00027004)
#define HWIO_TLMM_GPIO_IN_OUT39_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT39_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT39_ADDR, HWIO_TLMM_GPIO_IN_OUT39_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT39_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT39_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT39_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT39_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT39_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT39_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT39_IN)
#define HWIO_TLMM_GPIO_IN_OUT39_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT39_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT39_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT39_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG39_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00027008)
#define HWIO_TLMM_GPIO_INTR_CFG39_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00027008)
#define HWIO_TLMM_GPIO_INTR_CFG39_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG39_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG39_ADDR, HWIO_TLMM_GPIO_INTR_CFG39_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG39_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG39_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG39_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG39_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG39_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG39_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG39_IN)
#define HWIO_TLMM_GPIO_INTR_CFG39_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG39_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG39_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG39_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG39_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS39_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002700c)
#define HWIO_TLMM_GPIO_INTR_STATUS39_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002700c)
#define HWIO_TLMM_GPIO_INTR_STATUS39_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS39_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS39_ADDR, HWIO_TLMM_GPIO_INTR_STATUS39_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS39_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS39_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS39_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS39_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS39_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS39_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS39_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS39_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS39_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS39_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00027010)
#define HWIO_TLMM_GPIO_ID_STATUS39_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00027010)
#define HWIO_TLMM_GPIO_ID_STATUS39_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS39_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS39_ADDR, HWIO_TLMM_GPIO_ID_STATUS39_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS39_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS39_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS39_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS39_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG40_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00028000)
#define HWIO_TLMM_GPIO_CFG40_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00028000)
#define HWIO_TLMM_GPIO_CFG40_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG40_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG40_ADDR, HWIO_TLMM_GPIO_CFG40_RMSK)
#define HWIO_TLMM_GPIO_CFG40_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG40_ADDR, m)
#define HWIO_TLMM_GPIO_CFG40_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG40_ADDR,v)
#define HWIO_TLMM_GPIO_CFG40_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG40_ADDR,m,v,HWIO_TLMM_GPIO_CFG40_IN)
#define HWIO_TLMM_GPIO_CFG40_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG40_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG40_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG40_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG40_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG40_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG40_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG40_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG40_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG40_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT40_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00028004)
#define HWIO_TLMM_GPIO_IN_OUT40_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00028004)
#define HWIO_TLMM_GPIO_IN_OUT40_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT40_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT40_ADDR, HWIO_TLMM_GPIO_IN_OUT40_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT40_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT40_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT40_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT40_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT40_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT40_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT40_IN)
#define HWIO_TLMM_GPIO_IN_OUT40_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT40_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT40_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT40_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG40_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00028008)
#define HWIO_TLMM_GPIO_INTR_CFG40_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00028008)
#define HWIO_TLMM_GPIO_INTR_CFG40_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG40_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG40_ADDR, HWIO_TLMM_GPIO_INTR_CFG40_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG40_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG40_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG40_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG40_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG40_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG40_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG40_IN)
#define HWIO_TLMM_GPIO_INTR_CFG40_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG40_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG40_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG40_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG40_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS40_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002800c)
#define HWIO_TLMM_GPIO_INTR_STATUS40_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002800c)
#define HWIO_TLMM_GPIO_INTR_STATUS40_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS40_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS40_ADDR, HWIO_TLMM_GPIO_INTR_STATUS40_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS40_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS40_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS40_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS40_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS40_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS40_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS40_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS40_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS40_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS40_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00028010)
#define HWIO_TLMM_GPIO_ID_STATUS40_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00028010)
#define HWIO_TLMM_GPIO_ID_STATUS40_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS40_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS40_ADDR, HWIO_TLMM_GPIO_ID_STATUS40_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS40_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS40_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS40_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS40_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG41_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00029000)
#define HWIO_TLMM_GPIO_CFG41_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00029000)
#define HWIO_TLMM_GPIO_CFG41_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG41_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG41_ADDR, HWIO_TLMM_GPIO_CFG41_RMSK)
#define HWIO_TLMM_GPIO_CFG41_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG41_ADDR, m)
#define HWIO_TLMM_GPIO_CFG41_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG41_ADDR,v)
#define HWIO_TLMM_GPIO_CFG41_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG41_ADDR,m,v,HWIO_TLMM_GPIO_CFG41_IN)
#define HWIO_TLMM_GPIO_CFG41_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG41_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG41_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG41_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG41_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG41_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG41_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG41_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG41_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG41_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT41_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00029004)
#define HWIO_TLMM_GPIO_IN_OUT41_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00029004)
#define HWIO_TLMM_GPIO_IN_OUT41_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT41_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT41_ADDR, HWIO_TLMM_GPIO_IN_OUT41_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT41_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT41_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT41_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT41_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT41_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT41_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT41_IN)
#define HWIO_TLMM_GPIO_IN_OUT41_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT41_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT41_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT41_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG41_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00029008)
#define HWIO_TLMM_GPIO_INTR_CFG41_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00029008)
#define HWIO_TLMM_GPIO_INTR_CFG41_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG41_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG41_ADDR, HWIO_TLMM_GPIO_INTR_CFG41_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG41_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG41_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG41_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG41_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG41_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG41_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG41_IN)
#define HWIO_TLMM_GPIO_INTR_CFG41_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG41_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG41_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG41_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG41_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS41_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002900c)
#define HWIO_TLMM_GPIO_INTR_STATUS41_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002900c)
#define HWIO_TLMM_GPIO_INTR_STATUS41_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS41_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS41_ADDR, HWIO_TLMM_GPIO_INTR_STATUS41_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS41_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS41_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS41_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS41_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS41_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS41_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS41_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS41_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS41_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS41_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00029010)
#define HWIO_TLMM_GPIO_ID_STATUS41_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00029010)
#define HWIO_TLMM_GPIO_ID_STATUS41_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS41_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS41_ADDR, HWIO_TLMM_GPIO_ID_STATUS41_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS41_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS41_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS41_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS41_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG42_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0002a000)
#define HWIO_TLMM_GPIO_CFG42_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0002a000)
#define HWIO_TLMM_GPIO_CFG42_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG42_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG42_ADDR, HWIO_TLMM_GPIO_CFG42_RMSK)
#define HWIO_TLMM_GPIO_CFG42_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG42_ADDR, m)
#define HWIO_TLMM_GPIO_CFG42_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG42_ADDR,v)
#define HWIO_TLMM_GPIO_CFG42_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG42_ADDR,m,v,HWIO_TLMM_GPIO_CFG42_IN)
#define HWIO_TLMM_GPIO_CFG42_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG42_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG42_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG42_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG42_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG42_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG42_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG42_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG42_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG42_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT42_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0002a004)
#define HWIO_TLMM_GPIO_IN_OUT42_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0002a004)
#define HWIO_TLMM_GPIO_IN_OUT42_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT42_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT42_ADDR, HWIO_TLMM_GPIO_IN_OUT42_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT42_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT42_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT42_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT42_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT42_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT42_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT42_IN)
#define HWIO_TLMM_GPIO_IN_OUT42_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT42_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT42_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT42_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG42_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0002a008)
#define HWIO_TLMM_GPIO_INTR_CFG42_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0002a008)
#define HWIO_TLMM_GPIO_INTR_CFG42_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG42_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG42_ADDR, HWIO_TLMM_GPIO_INTR_CFG42_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG42_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG42_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG42_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG42_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG42_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG42_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG42_IN)
#define HWIO_TLMM_GPIO_INTR_CFG42_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG42_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG42_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG42_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG42_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS42_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS42_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS42_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS42_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS42_ADDR, HWIO_TLMM_GPIO_INTR_STATUS42_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS42_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS42_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS42_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS42_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS42_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS42_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS42_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS42_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS42_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS42_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0002a010)
#define HWIO_TLMM_GPIO_ID_STATUS42_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0002a010)
#define HWIO_TLMM_GPIO_ID_STATUS42_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS42_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS42_ADDR, HWIO_TLMM_GPIO_ID_STATUS42_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS42_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS42_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS42_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS42_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG43_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0002b000)
#define HWIO_TLMM_GPIO_CFG43_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0002b000)
#define HWIO_TLMM_GPIO_CFG43_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG43_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG43_ADDR, HWIO_TLMM_GPIO_CFG43_RMSK)
#define HWIO_TLMM_GPIO_CFG43_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG43_ADDR, m)
#define HWIO_TLMM_GPIO_CFG43_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG43_ADDR,v)
#define HWIO_TLMM_GPIO_CFG43_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG43_ADDR,m,v,HWIO_TLMM_GPIO_CFG43_IN)
#define HWIO_TLMM_GPIO_CFG43_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG43_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG43_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG43_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG43_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG43_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG43_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG43_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG43_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG43_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT43_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0002b004)
#define HWIO_TLMM_GPIO_IN_OUT43_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0002b004)
#define HWIO_TLMM_GPIO_IN_OUT43_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT43_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT43_ADDR, HWIO_TLMM_GPIO_IN_OUT43_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT43_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT43_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT43_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT43_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT43_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT43_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT43_IN)
#define HWIO_TLMM_GPIO_IN_OUT43_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT43_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT43_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT43_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG43_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0002b008)
#define HWIO_TLMM_GPIO_INTR_CFG43_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0002b008)
#define HWIO_TLMM_GPIO_INTR_CFG43_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG43_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG43_ADDR, HWIO_TLMM_GPIO_INTR_CFG43_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG43_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG43_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG43_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG43_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG43_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG43_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG43_IN)
#define HWIO_TLMM_GPIO_INTR_CFG43_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG43_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG43_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG43_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG43_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS43_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS43_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS43_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS43_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS43_ADDR, HWIO_TLMM_GPIO_INTR_STATUS43_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS43_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS43_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS43_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS43_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS43_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS43_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS43_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS43_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS43_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS43_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0002b010)
#define HWIO_TLMM_GPIO_ID_STATUS43_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0002b010)
#define HWIO_TLMM_GPIO_ID_STATUS43_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS43_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS43_ADDR, HWIO_TLMM_GPIO_ID_STATUS43_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS43_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS43_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS43_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS43_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG44_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0002c000)
#define HWIO_TLMM_GPIO_CFG44_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0002c000)
#define HWIO_TLMM_GPIO_CFG44_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG44_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG44_ADDR, HWIO_TLMM_GPIO_CFG44_RMSK)
#define HWIO_TLMM_GPIO_CFG44_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG44_ADDR, m)
#define HWIO_TLMM_GPIO_CFG44_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG44_ADDR,v)
#define HWIO_TLMM_GPIO_CFG44_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG44_ADDR,m,v,HWIO_TLMM_GPIO_CFG44_IN)
#define HWIO_TLMM_GPIO_CFG44_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG44_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG44_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG44_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG44_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG44_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG44_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG44_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG44_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG44_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT44_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0002c004)
#define HWIO_TLMM_GPIO_IN_OUT44_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0002c004)
#define HWIO_TLMM_GPIO_IN_OUT44_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT44_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT44_ADDR, HWIO_TLMM_GPIO_IN_OUT44_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT44_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT44_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT44_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT44_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT44_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT44_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT44_IN)
#define HWIO_TLMM_GPIO_IN_OUT44_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT44_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT44_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT44_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG44_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0002c008)
#define HWIO_TLMM_GPIO_INTR_CFG44_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0002c008)
#define HWIO_TLMM_GPIO_INTR_CFG44_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG44_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG44_ADDR, HWIO_TLMM_GPIO_INTR_CFG44_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG44_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG44_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG44_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG44_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG44_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG44_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG44_IN)
#define HWIO_TLMM_GPIO_INTR_CFG44_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG44_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG44_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG44_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG44_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS44_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS44_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS44_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS44_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS44_ADDR, HWIO_TLMM_GPIO_INTR_STATUS44_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS44_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS44_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS44_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS44_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS44_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS44_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS44_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS44_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS44_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS44_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0002c010)
#define HWIO_TLMM_GPIO_ID_STATUS44_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0002c010)
#define HWIO_TLMM_GPIO_ID_STATUS44_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS44_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS44_ADDR, HWIO_TLMM_GPIO_ID_STATUS44_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS44_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS44_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS44_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS44_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG45_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0002d000)
#define HWIO_TLMM_GPIO_CFG45_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0002d000)
#define HWIO_TLMM_GPIO_CFG45_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG45_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG45_ADDR, HWIO_TLMM_GPIO_CFG45_RMSK)
#define HWIO_TLMM_GPIO_CFG45_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG45_ADDR, m)
#define HWIO_TLMM_GPIO_CFG45_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG45_ADDR,v)
#define HWIO_TLMM_GPIO_CFG45_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG45_ADDR,m,v,HWIO_TLMM_GPIO_CFG45_IN)
#define HWIO_TLMM_GPIO_CFG45_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG45_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG45_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG45_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG45_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG45_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG45_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG45_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG45_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG45_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT45_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0002d004)
#define HWIO_TLMM_GPIO_IN_OUT45_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0002d004)
#define HWIO_TLMM_GPIO_IN_OUT45_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT45_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT45_ADDR, HWIO_TLMM_GPIO_IN_OUT45_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT45_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT45_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT45_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT45_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT45_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT45_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT45_IN)
#define HWIO_TLMM_GPIO_IN_OUT45_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT45_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT45_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT45_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG45_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0002d008)
#define HWIO_TLMM_GPIO_INTR_CFG45_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0002d008)
#define HWIO_TLMM_GPIO_INTR_CFG45_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG45_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG45_ADDR, HWIO_TLMM_GPIO_INTR_CFG45_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG45_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG45_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG45_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG45_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG45_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG45_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG45_IN)
#define HWIO_TLMM_GPIO_INTR_CFG45_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG45_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG45_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG45_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG45_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS45_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS45_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS45_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS45_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS45_ADDR, HWIO_TLMM_GPIO_INTR_STATUS45_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS45_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS45_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS45_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS45_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS45_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS45_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS45_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS45_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS45_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS45_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0002d010)
#define HWIO_TLMM_GPIO_ID_STATUS45_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0002d010)
#define HWIO_TLMM_GPIO_ID_STATUS45_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS45_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS45_ADDR, HWIO_TLMM_GPIO_ID_STATUS45_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS45_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS45_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS45_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS45_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG46_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0002e000)
#define HWIO_TLMM_GPIO_CFG46_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0002e000)
#define HWIO_TLMM_GPIO_CFG46_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG46_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG46_ADDR, HWIO_TLMM_GPIO_CFG46_RMSK)
#define HWIO_TLMM_GPIO_CFG46_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG46_ADDR, m)
#define HWIO_TLMM_GPIO_CFG46_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG46_ADDR,v)
#define HWIO_TLMM_GPIO_CFG46_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG46_ADDR,m,v,HWIO_TLMM_GPIO_CFG46_IN)
#define HWIO_TLMM_GPIO_CFG46_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG46_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG46_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG46_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG46_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG46_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG46_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG46_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG46_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG46_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT46_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0002e004)
#define HWIO_TLMM_GPIO_IN_OUT46_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0002e004)
#define HWIO_TLMM_GPIO_IN_OUT46_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT46_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT46_ADDR, HWIO_TLMM_GPIO_IN_OUT46_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT46_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT46_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT46_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT46_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT46_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT46_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT46_IN)
#define HWIO_TLMM_GPIO_IN_OUT46_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT46_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT46_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT46_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG46_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0002e008)
#define HWIO_TLMM_GPIO_INTR_CFG46_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0002e008)
#define HWIO_TLMM_GPIO_INTR_CFG46_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG46_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG46_ADDR, HWIO_TLMM_GPIO_INTR_CFG46_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG46_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG46_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG46_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG46_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG46_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG46_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG46_IN)
#define HWIO_TLMM_GPIO_INTR_CFG46_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG46_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG46_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG46_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG46_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS46_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS46_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS46_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS46_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS46_ADDR, HWIO_TLMM_GPIO_INTR_STATUS46_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS46_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS46_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS46_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS46_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS46_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS46_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS46_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS46_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS46_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS46_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0002e010)
#define HWIO_TLMM_GPIO_ID_STATUS46_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0002e010)
#define HWIO_TLMM_GPIO_ID_STATUS46_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS46_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS46_ADDR, HWIO_TLMM_GPIO_ID_STATUS46_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS46_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS46_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS46_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS46_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG47_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0002f000)
#define HWIO_TLMM_GPIO_CFG47_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0002f000)
#define HWIO_TLMM_GPIO_CFG47_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG47_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG47_ADDR, HWIO_TLMM_GPIO_CFG47_RMSK)
#define HWIO_TLMM_GPIO_CFG47_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG47_ADDR, m)
#define HWIO_TLMM_GPIO_CFG47_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG47_ADDR,v)
#define HWIO_TLMM_GPIO_CFG47_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG47_ADDR,m,v,HWIO_TLMM_GPIO_CFG47_IN)
#define HWIO_TLMM_GPIO_CFG47_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG47_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG47_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG47_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG47_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG47_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG47_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG47_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG47_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG47_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT47_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0002f004)
#define HWIO_TLMM_GPIO_IN_OUT47_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0002f004)
#define HWIO_TLMM_GPIO_IN_OUT47_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT47_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT47_ADDR, HWIO_TLMM_GPIO_IN_OUT47_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT47_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT47_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT47_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT47_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT47_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT47_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT47_IN)
#define HWIO_TLMM_GPIO_IN_OUT47_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT47_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT47_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT47_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG47_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0002f008)
#define HWIO_TLMM_GPIO_INTR_CFG47_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0002f008)
#define HWIO_TLMM_GPIO_INTR_CFG47_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG47_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG47_ADDR, HWIO_TLMM_GPIO_INTR_CFG47_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG47_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG47_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG47_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG47_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG47_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG47_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG47_IN)
#define HWIO_TLMM_GPIO_INTR_CFG47_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG47_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG47_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG47_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG47_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS47_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0002f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS47_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0002f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS47_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS47_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS47_ADDR, HWIO_TLMM_GPIO_INTR_STATUS47_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS47_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS47_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS47_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS47_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS47_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS47_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS47_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS47_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS47_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS47_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0002f010)
#define HWIO_TLMM_GPIO_ID_STATUS47_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0002f010)
#define HWIO_TLMM_GPIO_ID_STATUS47_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS47_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS47_ADDR, HWIO_TLMM_GPIO_ID_STATUS47_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS47_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS47_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS47_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS47_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG48_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00030000)
#define HWIO_TLMM_GPIO_CFG48_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00030000)
#define HWIO_TLMM_GPIO_CFG48_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG48_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG48_ADDR, HWIO_TLMM_GPIO_CFG48_RMSK)
#define HWIO_TLMM_GPIO_CFG48_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG48_ADDR, m)
#define HWIO_TLMM_GPIO_CFG48_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG48_ADDR,v)
#define HWIO_TLMM_GPIO_CFG48_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG48_ADDR,m,v,HWIO_TLMM_GPIO_CFG48_IN)
#define HWIO_TLMM_GPIO_CFG48_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG48_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG48_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG48_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG48_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG48_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG48_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG48_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG48_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG48_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT48_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00030004)
#define HWIO_TLMM_GPIO_IN_OUT48_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00030004)
#define HWIO_TLMM_GPIO_IN_OUT48_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT48_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT48_ADDR, HWIO_TLMM_GPIO_IN_OUT48_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT48_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT48_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT48_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT48_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT48_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT48_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT48_IN)
#define HWIO_TLMM_GPIO_IN_OUT48_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT48_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT48_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT48_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG48_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00030008)
#define HWIO_TLMM_GPIO_INTR_CFG48_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00030008)
#define HWIO_TLMM_GPIO_INTR_CFG48_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG48_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG48_ADDR, HWIO_TLMM_GPIO_INTR_CFG48_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG48_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG48_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG48_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG48_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG48_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG48_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG48_IN)
#define HWIO_TLMM_GPIO_INTR_CFG48_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG48_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG48_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG48_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG48_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS48_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003000c)
#define HWIO_TLMM_GPIO_INTR_STATUS48_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003000c)
#define HWIO_TLMM_GPIO_INTR_STATUS48_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS48_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS48_ADDR, HWIO_TLMM_GPIO_INTR_STATUS48_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS48_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS48_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS48_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS48_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS48_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS48_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS48_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS48_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS48_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS48_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00030010)
#define HWIO_TLMM_GPIO_ID_STATUS48_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00030010)
#define HWIO_TLMM_GPIO_ID_STATUS48_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS48_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS48_ADDR, HWIO_TLMM_GPIO_ID_STATUS48_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS48_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS48_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS48_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS48_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG49_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00031000)
#define HWIO_TLMM_GPIO_CFG49_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00031000)
#define HWIO_TLMM_GPIO_CFG49_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG49_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG49_ADDR, HWIO_TLMM_GPIO_CFG49_RMSK)
#define HWIO_TLMM_GPIO_CFG49_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG49_ADDR, m)
#define HWIO_TLMM_GPIO_CFG49_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG49_ADDR,v)
#define HWIO_TLMM_GPIO_CFG49_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG49_ADDR,m,v,HWIO_TLMM_GPIO_CFG49_IN)
#define HWIO_TLMM_GPIO_CFG49_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG49_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG49_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG49_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG49_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG49_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG49_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG49_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG49_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG49_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT49_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00031004)
#define HWIO_TLMM_GPIO_IN_OUT49_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00031004)
#define HWIO_TLMM_GPIO_IN_OUT49_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT49_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT49_ADDR, HWIO_TLMM_GPIO_IN_OUT49_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT49_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT49_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT49_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT49_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT49_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT49_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT49_IN)
#define HWIO_TLMM_GPIO_IN_OUT49_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT49_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT49_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT49_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG49_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00031008)
#define HWIO_TLMM_GPIO_INTR_CFG49_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00031008)
#define HWIO_TLMM_GPIO_INTR_CFG49_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG49_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG49_ADDR, HWIO_TLMM_GPIO_INTR_CFG49_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG49_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG49_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG49_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG49_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG49_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG49_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG49_IN)
#define HWIO_TLMM_GPIO_INTR_CFG49_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG49_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG49_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG49_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG49_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS49_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003100c)
#define HWIO_TLMM_GPIO_INTR_STATUS49_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003100c)
#define HWIO_TLMM_GPIO_INTR_STATUS49_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS49_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS49_ADDR, HWIO_TLMM_GPIO_INTR_STATUS49_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS49_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS49_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS49_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS49_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS49_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS49_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS49_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS49_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS49_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS49_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00031010)
#define HWIO_TLMM_GPIO_ID_STATUS49_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00031010)
#define HWIO_TLMM_GPIO_ID_STATUS49_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS49_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS49_ADDR, HWIO_TLMM_GPIO_ID_STATUS49_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS49_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS49_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS49_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS49_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG50_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00032000)
#define HWIO_TLMM_GPIO_CFG50_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00032000)
#define HWIO_TLMM_GPIO_CFG50_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG50_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG50_ADDR, HWIO_TLMM_GPIO_CFG50_RMSK)
#define HWIO_TLMM_GPIO_CFG50_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG50_ADDR, m)
#define HWIO_TLMM_GPIO_CFG50_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG50_ADDR,v)
#define HWIO_TLMM_GPIO_CFG50_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG50_ADDR,m,v,HWIO_TLMM_GPIO_CFG50_IN)
#define HWIO_TLMM_GPIO_CFG50_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG50_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG50_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG50_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG50_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG50_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG50_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG50_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG50_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG50_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT50_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00032004)
#define HWIO_TLMM_GPIO_IN_OUT50_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00032004)
#define HWIO_TLMM_GPIO_IN_OUT50_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT50_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT50_ADDR, HWIO_TLMM_GPIO_IN_OUT50_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT50_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT50_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT50_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT50_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT50_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT50_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT50_IN)
#define HWIO_TLMM_GPIO_IN_OUT50_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT50_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT50_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT50_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG50_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00032008)
#define HWIO_TLMM_GPIO_INTR_CFG50_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00032008)
#define HWIO_TLMM_GPIO_INTR_CFG50_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG50_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG50_ADDR, HWIO_TLMM_GPIO_INTR_CFG50_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG50_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG50_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG50_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG50_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG50_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG50_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG50_IN)
#define HWIO_TLMM_GPIO_INTR_CFG50_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG50_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG50_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG50_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG50_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS50_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003200c)
#define HWIO_TLMM_GPIO_INTR_STATUS50_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003200c)
#define HWIO_TLMM_GPIO_INTR_STATUS50_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS50_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS50_ADDR, HWIO_TLMM_GPIO_INTR_STATUS50_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS50_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS50_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS50_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS50_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS50_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS50_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS50_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS50_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS50_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS50_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00032010)
#define HWIO_TLMM_GPIO_ID_STATUS50_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00032010)
#define HWIO_TLMM_GPIO_ID_STATUS50_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS50_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS50_ADDR, HWIO_TLMM_GPIO_ID_STATUS50_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS50_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS50_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS50_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS50_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG51_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00033000)
#define HWIO_TLMM_GPIO_CFG51_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00033000)
#define HWIO_TLMM_GPIO_CFG51_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG51_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG51_ADDR, HWIO_TLMM_GPIO_CFG51_RMSK)
#define HWIO_TLMM_GPIO_CFG51_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG51_ADDR, m)
#define HWIO_TLMM_GPIO_CFG51_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG51_ADDR,v)
#define HWIO_TLMM_GPIO_CFG51_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG51_ADDR,m,v,HWIO_TLMM_GPIO_CFG51_IN)
#define HWIO_TLMM_GPIO_CFG51_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG51_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG51_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG51_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG51_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG51_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG51_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG51_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG51_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG51_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT51_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00033004)
#define HWIO_TLMM_GPIO_IN_OUT51_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00033004)
#define HWIO_TLMM_GPIO_IN_OUT51_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT51_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT51_ADDR, HWIO_TLMM_GPIO_IN_OUT51_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT51_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT51_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT51_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT51_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT51_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT51_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT51_IN)
#define HWIO_TLMM_GPIO_IN_OUT51_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT51_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT51_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT51_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG51_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00033008)
#define HWIO_TLMM_GPIO_INTR_CFG51_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00033008)
#define HWIO_TLMM_GPIO_INTR_CFG51_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG51_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG51_ADDR, HWIO_TLMM_GPIO_INTR_CFG51_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG51_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG51_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG51_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG51_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG51_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG51_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG51_IN)
#define HWIO_TLMM_GPIO_INTR_CFG51_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG51_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG51_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG51_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG51_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS51_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003300c)
#define HWIO_TLMM_GPIO_INTR_STATUS51_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003300c)
#define HWIO_TLMM_GPIO_INTR_STATUS51_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS51_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS51_ADDR, HWIO_TLMM_GPIO_INTR_STATUS51_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS51_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS51_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS51_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS51_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS51_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS51_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS51_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS51_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS51_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS51_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00033010)
#define HWIO_TLMM_GPIO_ID_STATUS51_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00033010)
#define HWIO_TLMM_GPIO_ID_STATUS51_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS51_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS51_ADDR, HWIO_TLMM_GPIO_ID_STATUS51_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS51_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS51_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS51_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS51_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG52_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00034000)
#define HWIO_TLMM_GPIO_CFG52_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00034000)
#define HWIO_TLMM_GPIO_CFG52_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG52_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG52_ADDR, HWIO_TLMM_GPIO_CFG52_RMSK)
#define HWIO_TLMM_GPIO_CFG52_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG52_ADDR, m)
#define HWIO_TLMM_GPIO_CFG52_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG52_ADDR,v)
#define HWIO_TLMM_GPIO_CFG52_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG52_ADDR,m,v,HWIO_TLMM_GPIO_CFG52_IN)
#define HWIO_TLMM_GPIO_CFG52_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG52_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG52_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG52_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG52_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG52_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG52_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG52_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG52_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG52_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT52_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00034004)
#define HWIO_TLMM_GPIO_IN_OUT52_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00034004)
#define HWIO_TLMM_GPIO_IN_OUT52_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT52_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT52_ADDR, HWIO_TLMM_GPIO_IN_OUT52_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT52_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT52_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT52_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT52_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT52_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT52_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT52_IN)
#define HWIO_TLMM_GPIO_IN_OUT52_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT52_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT52_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT52_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG52_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00034008)
#define HWIO_TLMM_GPIO_INTR_CFG52_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00034008)
#define HWIO_TLMM_GPIO_INTR_CFG52_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG52_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG52_ADDR, HWIO_TLMM_GPIO_INTR_CFG52_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG52_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG52_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG52_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG52_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG52_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG52_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG52_IN)
#define HWIO_TLMM_GPIO_INTR_CFG52_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG52_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG52_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG52_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG52_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS52_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003400c)
#define HWIO_TLMM_GPIO_INTR_STATUS52_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003400c)
#define HWIO_TLMM_GPIO_INTR_STATUS52_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS52_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS52_ADDR, HWIO_TLMM_GPIO_INTR_STATUS52_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS52_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS52_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS52_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS52_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS52_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS52_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS52_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS52_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS52_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS52_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00034010)
#define HWIO_TLMM_GPIO_ID_STATUS52_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00034010)
#define HWIO_TLMM_GPIO_ID_STATUS52_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS52_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS52_ADDR, HWIO_TLMM_GPIO_ID_STATUS52_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS52_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS52_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS52_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS52_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG55_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00037000)
#define HWIO_TLMM_GPIO_CFG55_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00037000)
#define HWIO_TLMM_GPIO_CFG55_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG55_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG55_ADDR, HWIO_TLMM_GPIO_CFG55_RMSK)
#define HWIO_TLMM_GPIO_CFG55_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG55_ADDR, m)
#define HWIO_TLMM_GPIO_CFG55_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG55_ADDR,v)
#define HWIO_TLMM_GPIO_CFG55_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG55_ADDR,m,v,HWIO_TLMM_GPIO_CFG55_IN)
#define HWIO_TLMM_GPIO_CFG55_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG55_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG55_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG55_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG55_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG55_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG55_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG55_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG55_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG55_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT55_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00037004)
#define HWIO_TLMM_GPIO_IN_OUT55_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00037004)
#define HWIO_TLMM_GPIO_IN_OUT55_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT55_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT55_ADDR, HWIO_TLMM_GPIO_IN_OUT55_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT55_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT55_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT55_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT55_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT55_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT55_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT55_IN)
#define HWIO_TLMM_GPIO_IN_OUT55_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT55_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT55_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT55_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG55_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00037008)
#define HWIO_TLMM_GPIO_INTR_CFG55_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00037008)
#define HWIO_TLMM_GPIO_INTR_CFG55_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG55_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG55_ADDR, HWIO_TLMM_GPIO_INTR_CFG55_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG55_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG55_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG55_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG55_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG55_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG55_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG55_IN)
#define HWIO_TLMM_GPIO_INTR_CFG55_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG55_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG55_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG55_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG55_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS55_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003700c)
#define HWIO_TLMM_GPIO_INTR_STATUS55_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003700c)
#define HWIO_TLMM_GPIO_INTR_STATUS55_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS55_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS55_ADDR, HWIO_TLMM_GPIO_INTR_STATUS55_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS55_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS55_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS55_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS55_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS55_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS55_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS55_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS55_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS55_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS55_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00037010)
#define HWIO_TLMM_GPIO_ID_STATUS55_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00037010)
#define HWIO_TLMM_GPIO_ID_STATUS55_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS55_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS55_ADDR, HWIO_TLMM_GPIO_ID_STATUS55_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS55_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS55_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS55_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS55_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG56_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00038000)
#define HWIO_TLMM_GPIO_CFG56_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00038000)
#define HWIO_TLMM_GPIO_CFG56_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG56_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG56_ADDR, HWIO_TLMM_GPIO_CFG56_RMSK)
#define HWIO_TLMM_GPIO_CFG56_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG56_ADDR, m)
#define HWIO_TLMM_GPIO_CFG56_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG56_ADDR,v)
#define HWIO_TLMM_GPIO_CFG56_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG56_ADDR,m,v,HWIO_TLMM_GPIO_CFG56_IN)
#define HWIO_TLMM_GPIO_CFG56_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG56_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG56_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG56_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG56_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG56_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG56_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG56_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG56_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG56_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT56_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00038004)
#define HWIO_TLMM_GPIO_IN_OUT56_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00038004)
#define HWIO_TLMM_GPIO_IN_OUT56_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT56_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT56_ADDR, HWIO_TLMM_GPIO_IN_OUT56_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT56_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT56_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT56_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT56_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT56_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT56_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT56_IN)
#define HWIO_TLMM_GPIO_IN_OUT56_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT56_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT56_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT56_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG56_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00038008)
#define HWIO_TLMM_GPIO_INTR_CFG56_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00038008)
#define HWIO_TLMM_GPIO_INTR_CFG56_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG56_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG56_ADDR, HWIO_TLMM_GPIO_INTR_CFG56_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG56_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG56_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG56_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG56_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG56_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG56_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG56_IN)
#define HWIO_TLMM_GPIO_INTR_CFG56_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG56_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG56_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG56_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG56_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS56_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003800c)
#define HWIO_TLMM_GPIO_INTR_STATUS56_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003800c)
#define HWIO_TLMM_GPIO_INTR_STATUS56_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS56_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS56_ADDR, HWIO_TLMM_GPIO_INTR_STATUS56_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS56_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS56_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS56_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS56_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS56_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS56_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS56_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS56_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS56_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS56_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00038010)
#define HWIO_TLMM_GPIO_ID_STATUS56_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00038010)
#define HWIO_TLMM_GPIO_ID_STATUS56_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS56_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS56_ADDR, HWIO_TLMM_GPIO_ID_STATUS56_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS56_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS56_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS56_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS56_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG57_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00039000)
#define HWIO_TLMM_GPIO_CFG57_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00039000)
#define HWIO_TLMM_GPIO_CFG57_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG57_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG57_ADDR, HWIO_TLMM_GPIO_CFG57_RMSK)
#define HWIO_TLMM_GPIO_CFG57_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG57_ADDR, m)
#define HWIO_TLMM_GPIO_CFG57_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG57_ADDR,v)
#define HWIO_TLMM_GPIO_CFG57_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG57_ADDR,m,v,HWIO_TLMM_GPIO_CFG57_IN)
#define HWIO_TLMM_GPIO_CFG57_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG57_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG57_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG57_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG57_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG57_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG57_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG57_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG57_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG57_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT57_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00039004)
#define HWIO_TLMM_GPIO_IN_OUT57_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00039004)
#define HWIO_TLMM_GPIO_IN_OUT57_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT57_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT57_ADDR, HWIO_TLMM_GPIO_IN_OUT57_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT57_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT57_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT57_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT57_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT57_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT57_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT57_IN)
#define HWIO_TLMM_GPIO_IN_OUT57_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT57_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT57_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT57_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG57_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00039008)
#define HWIO_TLMM_GPIO_INTR_CFG57_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00039008)
#define HWIO_TLMM_GPIO_INTR_CFG57_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG57_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG57_ADDR, HWIO_TLMM_GPIO_INTR_CFG57_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG57_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG57_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG57_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG57_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG57_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG57_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG57_IN)
#define HWIO_TLMM_GPIO_INTR_CFG57_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG57_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG57_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG57_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG57_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS57_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003900c)
#define HWIO_TLMM_GPIO_INTR_STATUS57_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003900c)
#define HWIO_TLMM_GPIO_INTR_STATUS57_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS57_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS57_ADDR, HWIO_TLMM_GPIO_INTR_STATUS57_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS57_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS57_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS57_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS57_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS57_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS57_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS57_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS57_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS57_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS57_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00039010)
#define HWIO_TLMM_GPIO_ID_STATUS57_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00039010)
#define HWIO_TLMM_GPIO_ID_STATUS57_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS57_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS57_ADDR, HWIO_TLMM_GPIO_ID_STATUS57_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS57_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS57_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS57_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS57_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG58_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0003a000)
#define HWIO_TLMM_GPIO_CFG58_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0003a000)
#define HWIO_TLMM_GPIO_CFG58_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG58_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG58_ADDR, HWIO_TLMM_GPIO_CFG58_RMSK)
#define HWIO_TLMM_GPIO_CFG58_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG58_ADDR, m)
#define HWIO_TLMM_GPIO_CFG58_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG58_ADDR,v)
#define HWIO_TLMM_GPIO_CFG58_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG58_ADDR,m,v,HWIO_TLMM_GPIO_CFG58_IN)
#define HWIO_TLMM_GPIO_CFG58_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG58_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG58_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG58_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG58_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG58_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG58_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG58_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG58_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG58_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT58_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0003a004)
#define HWIO_TLMM_GPIO_IN_OUT58_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0003a004)
#define HWIO_TLMM_GPIO_IN_OUT58_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT58_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT58_ADDR, HWIO_TLMM_GPIO_IN_OUT58_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT58_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT58_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT58_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT58_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT58_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT58_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT58_IN)
#define HWIO_TLMM_GPIO_IN_OUT58_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT58_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT58_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT58_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG58_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0003a008)
#define HWIO_TLMM_GPIO_INTR_CFG58_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0003a008)
#define HWIO_TLMM_GPIO_INTR_CFG58_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG58_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG58_ADDR, HWIO_TLMM_GPIO_INTR_CFG58_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG58_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG58_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG58_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG58_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG58_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG58_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG58_IN)
#define HWIO_TLMM_GPIO_INTR_CFG58_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG58_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG58_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG58_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG58_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS58_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0003a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS58_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0003a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS58_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS58_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS58_ADDR, HWIO_TLMM_GPIO_INTR_STATUS58_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS58_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS58_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS58_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS58_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS58_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS58_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS58_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS58_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS58_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS58_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0003a010)
#define HWIO_TLMM_GPIO_ID_STATUS58_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0003a010)
#define HWIO_TLMM_GPIO_ID_STATUS58_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS58_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS58_ADDR, HWIO_TLMM_GPIO_ID_STATUS58_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS58_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS58_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS58_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS58_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG64_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00040000)
#define HWIO_TLMM_GPIO_CFG64_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00040000)
#define HWIO_TLMM_GPIO_CFG64_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG64_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG64_ADDR, HWIO_TLMM_GPIO_CFG64_RMSK)
#define HWIO_TLMM_GPIO_CFG64_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG64_ADDR, m)
#define HWIO_TLMM_GPIO_CFG64_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG64_ADDR,v)
#define HWIO_TLMM_GPIO_CFG64_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG64_ADDR,m,v,HWIO_TLMM_GPIO_CFG64_IN)
#define HWIO_TLMM_GPIO_CFG64_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG64_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG64_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG64_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG64_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG64_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG64_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG64_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG64_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG64_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT64_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00040004)
#define HWIO_TLMM_GPIO_IN_OUT64_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00040004)
#define HWIO_TLMM_GPIO_IN_OUT64_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT64_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT64_ADDR, HWIO_TLMM_GPIO_IN_OUT64_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT64_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT64_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT64_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT64_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT64_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT64_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT64_IN)
#define HWIO_TLMM_GPIO_IN_OUT64_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT64_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT64_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT64_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG64_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00040008)
#define HWIO_TLMM_GPIO_INTR_CFG64_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00040008)
#define HWIO_TLMM_GPIO_INTR_CFG64_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG64_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG64_ADDR, HWIO_TLMM_GPIO_INTR_CFG64_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG64_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG64_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG64_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG64_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG64_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG64_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG64_IN)
#define HWIO_TLMM_GPIO_INTR_CFG64_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG64_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG64_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG64_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG64_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS64_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0004000c)
#define HWIO_TLMM_GPIO_INTR_STATUS64_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0004000c)
#define HWIO_TLMM_GPIO_INTR_STATUS64_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS64_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS64_ADDR, HWIO_TLMM_GPIO_INTR_STATUS64_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS64_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS64_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS64_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS64_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS64_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS64_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS64_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS64_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS64_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS64_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00040010)
#define HWIO_TLMM_GPIO_ID_STATUS64_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00040010)
#define HWIO_TLMM_GPIO_ID_STATUS64_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS64_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS64_ADDR, HWIO_TLMM_GPIO_ID_STATUS64_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS64_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS64_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS64_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS64_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG65_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00041000)
#define HWIO_TLMM_GPIO_CFG65_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00041000)
#define HWIO_TLMM_GPIO_CFG65_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG65_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG65_ADDR, HWIO_TLMM_GPIO_CFG65_RMSK)
#define HWIO_TLMM_GPIO_CFG65_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG65_ADDR, m)
#define HWIO_TLMM_GPIO_CFG65_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG65_ADDR,v)
#define HWIO_TLMM_GPIO_CFG65_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG65_ADDR,m,v,HWIO_TLMM_GPIO_CFG65_IN)
#define HWIO_TLMM_GPIO_CFG65_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG65_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG65_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG65_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG65_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG65_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG65_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG65_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG65_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG65_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT65_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00041004)
#define HWIO_TLMM_GPIO_IN_OUT65_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00041004)
#define HWIO_TLMM_GPIO_IN_OUT65_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT65_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT65_ADDR, HWIO_TLMM_GPIO_IN_OUT65_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT65_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT65_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT65_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT65_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT65_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT65_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT65_IN)
#define HWIO_TLMM_GPIO_IN_OUT65_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT65_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT65_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT65_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG65_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00041008)
#define HWIO_TLMM_GPIO_INTR_CFG65_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00041008)
#define HWIO_TLMM_GPIO_INTR_CFG65_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG65_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG65_ADDR, HWIO_TLMM_GPIO_INTR_CFG65_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG65_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG65_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG65_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG65_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG65_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG65_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG65_IN)
#define HWIO_TLMM_GPIO_INTR_CFG65_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG65_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG65_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG65_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG65_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS65_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0004100c)
#define HWIO_TLMM_GPIO_INTR_STATUS65_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0004100c)
#define HWIO_TLMM_GPIO_INTR_STATUS65_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS65_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS65_ADDR, HWIO_TLMM_GPIO_INTR_STATUS65_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS65_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS65_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS65_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS65_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS65_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS65_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS65_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS65_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS65_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS65_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00041010)
#define HWIO_TLMM_GPIO_ID_STATUS65_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00041010)
#define HWIO_TLMM_GPIO_ID_STATUS65_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS65_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS65_ADDR, HWIO_TLMM_GPIO_ID_STATUS65_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS65_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS65_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS65_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS65_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG79_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0004f000)
#define HWIO_TLMM_GPIO_CFG79_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0004f000)
#define HWIO_TLMM_GPIO_CFG79_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG79_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG79_ADDR, HWIO_TLMM_GPIO_CFG79_RMSK)
#define HWIO_TLMM_GPIO_CFG79_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG79_ADDR, m)
#define HWIO_TLMM_GPIO_CFG79_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG79_ADDR,v)
#define HWIO_TLMM_GPIO_CFG79_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG79_ADDR,m,v,HWIO_TLMM_GPIO_CFG79_IN)
#define HWIO_TLMM_GPIO_CFG79_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG79_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG79_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG79_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG79_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG79_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG79_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG79_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG79_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG79_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT79_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0004f004)
#define HWIO_TLMM_GPIO_IN_OUT79_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0004f004)
#define HWIO_TLMM_GPIO_IN_OUT79_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT79_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT79_ADDR, HWIO_TLMM_GPIO_IN_OUT79_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT79_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT79_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT79_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT79_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT79_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT79_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT79_IN)
#define HWIO_TLMM_GPIO_IN_OUT79_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT79_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT79_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT79_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG79_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0004f008)
#define HWIO_TLMM_GPIO_INTR_CFG79_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0004f008)
#define HWIO_TLMM_GPIO_INTR_CFG79_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG79_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG79_ADDR, HWIO_TLMM_GPIO_INTR_CFG79_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG79_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG79_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG79_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG79_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG79_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG79_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG79_IN)
#define HWIO_TLMM_GPIO_INTR_CFG79_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG79_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG79_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG79_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG79_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS79_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0004f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS79_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0004f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS79_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS79_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS79_ADDR, HWIO_TLMM_GPIO_INTR_STATUS79_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS79_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS79_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS79_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS79_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS79_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS79_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS79_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS79_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS79_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS79_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0004f010)
#define HWIO_TLMM_GPIO_ID_STATUS79_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0004f010)
#define HWIO_TLMM_GPIO_ID_STATUS79_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS79_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS79_ADDR, HWIO_TLMM_GPIO_ID_STATUS79_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS79_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS79_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS79_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS79_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG80_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00050000)
#define HWIO_TLMM_GPIO_CFG80_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00050000)
#define HWIO_TLMM_GPIO_CFG80_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG80_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG80_ADDR, HWIO_TLMM_GPIO_CFG80_RMSK)
#define HWIO_TLMM_GPIO_CFG80_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG80_ADDR, m)
#define HWIO_TLMM_GPIO_CFG80_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG80_ADDR,v)
#define HWIO_TLMM_GPIO_CFG80_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG80_ADDR,m,v,HWIO_TLMM_GPIO_CFG80_IN)
#define HWIO_TLMM_GPIO_CFG80_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG80_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG80_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG80_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG80_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG80_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG80_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG80_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG80_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG80_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT80_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00050004)
#define HWIO_TLMM_GPIO_IN_OUT80_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00050004)
#define HWIO_TLMM_GPIO_IN_OUT80_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT80_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT80_ADDR, HWIO_TLMM_GPIO_IN_OUT80_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT80_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT80_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT80_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT80_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT80_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT80_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT80_IN)
#define HWIO_TLMM_GPIO_IN_OUT80_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT80_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT80_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT80_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG80_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00050008)
#define HWIO_TLMM_GPIO_INTR_CFG80_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00050008)
#define HWIO_TLMM_GPIO_INTR_CFG80_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG80_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG80_ADDR, HWIO_TLMM_GPIO_INTR_CFG80_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG80_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG80_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG80_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG80_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG80_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG80_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG80_IN)
#define HWIO_TLMM_GPIO_INTR_CFG80_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG80_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG80_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG80_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG80_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS80_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005000c)
#define HWIO_TLMM_GPIO_INTR_STATUS80_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005000c)
#define HWIO_TLMM_GPIO_INTR_STATUS80_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS80_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS80_ADDR, HWIO_TLMM_GPIO_INTR_STATUS80_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS80_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS80_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS80_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS80_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS80_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS80_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS80_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS80_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS80_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS80_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00050010)
#define HWIO_TLMM_GPIO_ID_STATUS80_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00050010)
#define HWIO_TLMM_GPIO_ID_STATUS80_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS80_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS80_ADDR, HWIO_TLMM_GPIO_ID_STATUS80_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS80_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS80_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS80_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS80_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG83_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00053000)
#define HWIO_TLMM_GPIO_CFG83_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00053000)
#define HWIO_TLMM_GPIO_CFG83_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG83_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG83_ADDR, HWIO_TLMM_GPIO_CFG83_RMSK)
#define HWIO_TLMM_GPIO_CFG83_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG83_ADDR, m)
#define HWIO_TLMM_GPIO_CFG83_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG83_ADDR,v)
#define HWIO_TLMM_GPIO_CFG83_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG83_ADDR,m,v,HWIO_TLMM_GPIO_CFG83_IN)
#define HWIO_TLMM_GPIO_CFG83_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG83_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG83_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG83_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG83_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG83_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG83_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG83_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG83_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG83_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT83_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00053004)
#define HWIO_TLMM_GPIO_IN_OUT83_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00053004)
#define HWIO_TLMM_GPIO_IN_OUT83_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT83_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT83_ADDR, HWIO_TLMM_GPIO_IN_OUT83_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT83_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT83_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT83_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT83_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT83_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT83_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT83_IN)
#define HWIO_TLMM_GPIO_IN_OUT83_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT83_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT83_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT83_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG83_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00053008)
#define HWIO_TLMM_GPIO_INTR_CFG83_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00053008)
#define HWIO_TLMM_GPIO_INTR_CFG83_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG83_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG83_ADDR, HWIO_TLMM_GPIO_INTR_CFG83_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG83_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG83_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG83_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG83_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG83_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG83_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG83_IN)
#define HWIO_TLMM_GPIO_INTR_CFG83_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG83_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG83_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG83_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG83_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS83_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005300c)
#define HWIO_TLMM_GPIO_INTR_STATUS83_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005300c)
#define HWIO_TLMM_GPIO_INTR_STATUS83_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS83_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS83_ADDR, HWIO_TLMM_GPIO_INTR_STATUS83_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS83_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS83_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS83_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS83_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS83_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS83_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS83_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS83_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS83_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS83_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00053010)
#define HWIO_TLMM_GPIO_ID_STATUS83_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00053010)
#define HWIO_TLMM_GPIO_ID_STATUS83_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS83_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS83_ADDR, HWIO_TLMM_GPIO_ID_STATUS83_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS83_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS83_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS83_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS83_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG84_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00054000)
#define HWIO_TLMM_GPIO_CFG84_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00054000)
#define HWIO_TLMM_GPIO_CFG84_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG84_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG84_ADDR, HWIO_TLMM_GPIO_CFG84_RMSK)
#define HWIO_TLMM_GPIO_CFG84_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG84_ADDR, m)
#define HWIO_TLMM_GPIO_CFG84_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG84_ADDR,v)
#define HWIO_TLMM_GPIO_CFG84_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG84_ADDR,m,v,HWIO_TLMM_GPIO_CFG84_IN)
#define HWIO_TLMM_GPIO_CFG84_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG84_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG84_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG84_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG84_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG84_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG84_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG84_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG84_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG84_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT84_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00054004)
#define HWIO_TLMM_GPIO_IN_OUT84_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00054004)
#define HWIO_TLMM_GPIO_IN_OUT84_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT84_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT84_ADDR, HWIO_TLMM_GPIO_IN_OUT84_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT84_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT84_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT84_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT84_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT84_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT84_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT84_IN)
#define HWIO_TLMM_GPIO_IN_OUT84_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT84_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT84_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT84_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG84_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00054008)
#define HWIO_TLMM_GPIO_INTR_CFG84_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00054008)
#define HWIO_TLMM_GPIO_INTR_CFG84_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG84_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG84_ADDR, HWIO_TLMM_GPIO_INTR_CFG84_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG84_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG84_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG84_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG84_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG84_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG84_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG84_IN)
#define HWIO_TLMM_GPIO_INTR_CFG84_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG84_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG84_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG84_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG84_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS84_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005400c)
#define HWIO_TLMM_GPIO_INTR_STATUS84_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005400c)
#define HWIO_TLMM_GPIO_INTR_STATUS84_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS84_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS84_ADDR, HWIO_TLMM_GPIO_INTR_STATUS84_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS84_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS84_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS84_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS84_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS84_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS84_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS84_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS84_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS84_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS84_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00054010)
#define HWIO_TLMM_GPIO_ID_STATUS84_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00054010)
#define HWIO_TLMM_GPIO_ID_STATUS84_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS84_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS84_ADDR, HWIO_TLMM_GPIO_ID_STATUS84_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS84_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS84_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS84_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS84_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG85_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00055000)
#define HWIO_TLMM_GPIO_CFG85_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00055000)
#define HWIO_TLMM_GPIO_CFG85_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG85_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG85_ADDR, HWIO_TLMM_GPIO_CFG85_RMSK)
#define HWIO_TLMM_GPIO_CFG85_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG85_ADDR, m)
#define HWIO_TLMM_GPIO_CFG85_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG85_ADDR,v)
#define HWIO_TLMM_GPIO_CFG85_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG85_ADDR,m,v,HWIO_TLMM_GPIO_CFG85_IN)
#define HWIO_TLMM_GPIO_CFG85_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG85_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG85_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG85_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG85_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG85_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG85_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG85_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG85_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG85_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT85_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00055004)
#define HWIO_TLMM_GPIO_IN_OUT85_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00055004)
#define HWIO_TLMM_GPIO_IN_OUT85_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT85_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT85_ADDR, HWIO_TLMM_GPIO_IN_OUT85_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT85_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT85_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT85_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT85_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT85_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT85_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT85_IN)
#define HWIO_TLMM_GPIO_IN_OUT85_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT85_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT85_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT85_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG85_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00055008)
#define HWIO_TLMM_GPIO_INTR_CFG85_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00055008)
#define HWIO_TLMM_GPIO_INTR_CFG85_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG85_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG85_ADDR, HWIO_TLMM_GPIO_INTR_CFG85_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG85_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG85_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG85_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG85_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG85_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG85_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG85_IN)
#define HWIO_TLMM_GPIO_INTR_CFG85_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG85_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG85_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG85_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG85_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS85_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005500c)
#define HWIO_TLMM_GPIO_INTR_STATUS85_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005500c)
#define HWIO_TLMM_GPIO_INTR_STATUS85_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS85_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS85_ADDR, HWIO_TLMM_GPIO_INTR_STATUS85_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS85_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS85_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS85_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS85_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS85_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS85_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS85_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS85_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS85_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS85_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00055010)
#define HWIO_TLMM_GPIO_ID_STATUS85_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00055010)
#define HWIO_TLMM_GPIO_ID_STATUS85_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS85_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS85_ADDR, HWIO_TLMM_GPIO_ID_STATUS85_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS85_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS85_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS85_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS85_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG86_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00056000)
#define HWIO_TLMM_GPIO_CFG86_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00056000)
#define HWIO_TLMM_GPIO_CFG86_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG86_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG86_ADDR, HWIO_TLMM_GPIO_CFG86_RMSK)
#define HWIO_TLMM_GPIO_CFG86_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG86_ADDR, m)
#define HWIO_TLMM_GPIO_CFG86_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG86_ADDR,v)
#define HWIO_TLMM_GPIO_CFG86_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG86_ADDR,m,v,HWIO_TLMM_GPIO_CFG86_IN)
#define HWIO_TLMM_GPIO_CFG86_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG86_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG86_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG86_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG86_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG86_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG86_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG86_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG86_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG86_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT86_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00056004)
#define HWIO_TLMM_GPIO_IN_OUT86_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00056004)
#define HWIO_TLMM_GPIO_IN_OUT86_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT86_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT86_ADDR, HWIO_TLMM_GPIO_IN_OUT86_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT86_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT86_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT86_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT86_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT86_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT86_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT86_IN)
#define HWIO_TLMM_GPIO_IN_OUT86_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT86_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT86_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT86_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG86_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00056008)
#define HWIO_TLMM_GPIO_INTR_CFG86_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00056008)
#define HWIO_TLMM_GPIO_INTR_CFG86_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG86_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG86_ADDR, HWIO_TLMM_GPIO_INTR_CFG86_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG86_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG86_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG86_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG86_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG86_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG86_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG86_IN)
#define HWIO_TLMM_GPIO_INTR_CFG86_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG86_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG86_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG86_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG86_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS86_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005600c)
#define HWIO_TLMM_GPIO_INTR_STATUS86_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005600c)
#define HWIO_TLMM_GPIO_INTR_STATUS86_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS86_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS86_ADDR, HWIO_TLMM_GPIO_INTR_STATUS86_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS86_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS86_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS86_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS86_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS86_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS86_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS86_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS86_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS86_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS86_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00056010)
#define HWIO_TLMM_GPIO_ID_STATUS86_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00056010)
#define HWIO_TLMM_GPIO_ID_STATUS86_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS86_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS86_ADDR, HWIO_TLMM_GPIO_ID_STATUS86_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS86_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS86_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS86_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS86_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG87_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00057000)
#define HWIO_TLMM_GPIO_CFG87_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00057000)
#define HWIO_TLMM_GPIO_CFG87_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG87_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG87_ADDR, HWIO_TLMM_GPIO_CFG87_RMSK)
#define HWIO_TLMM_GPIO_CFG87_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG87_ADDR, m)
#define HWIO_TLMM_GPIO_CFG87_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG87_ADDR,v)
#define HWIO_TLMM_GPIO_CFG87_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG87_ADDR,m,v,HWIO_TLMM_GPIO_CFG87_IN)
#define HWIO_TLMM_GPIO_CFG87_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG87_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG87_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG87_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG87_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG87_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG87_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG87_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG87_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG87_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT87_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00057004)
#define HWIO_TLMM_GPIO_IN_OUT87_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00057004)
#define HWIO_TLMM_GPIO_IN_OUT87_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT87_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT87_ADDR, HWIO_TLMM_GPIO_IN_OUT87_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT87_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT87_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT87_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT87_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT87_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT87_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT87_IN)
#define HWIO_TLMM_GPIO_IN_OUT87_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT87_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT87_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT87_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG87_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00057008)
#define HWIO_TLMM_GPIO_INTR_CFG87_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00057008)
#define HWIO_TLMM_GPIO_INTR_CFG87_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG87_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG87_ADDR, HWIO_TLMM_GPIO_INTR_CFG87_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG87_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG87_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG87_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG87_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG87_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG87_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG87_IN)
#define HWIO_TLMM_GPIO_INTR_CFG87_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG87_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG87_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG87_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG87_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS87_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005700c)
#define HWIO_TLMM_GPIO_INTR_STATUS87_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005700c)
#define HWIO_TLMM_GPIO_INTR_STATUS87_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS87_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS87_ADDR, HWIO_TLMM_GPIO_INTR_STATUS87_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS87_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS87_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS87_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS87_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS87_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS87_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS87_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS87_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS87_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS87_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00057010)
#define HWIO_TLMM_GPIO_ID_STATUS87_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00057010)
#define HWIO_TLMM_GPIO_ID_STATUS87_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS87_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS87_ADDR, HWIO_TLMM_GPIO_ID_STATUS87_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS87_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS87_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS87_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS87_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG88_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00058000)
#define HWIO_TLMM_GPIO_CFG88_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00058000)
#define HWIO_TLMM_GPIO_CFG88_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG88_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG88_ADDR, HWIO_TLMM_GPIO_CFG88_RMSK)
#define HWIO_TLMM_GPIO_CFG88_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG88_ADDR, m)
#define HWIO_TLMM_GPIO_CFG88_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG88_ADDR,v)
#define HWIO_TLMM_GPIO_CFG88_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG88_ADDR,m,v,HWIO_TLMM_GPIO_CFG88_IN)
#define HWIO_TLMM_GPIO_CFG88_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG88_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG88_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG88_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG88_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG88_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG88_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG88_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG88_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG88_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT88_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00058004)
#define HWIO_TLMM_GPIO_IN_OUT88_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00058004)
#define HWIO_TLMM_GPIO_IN_OUT88_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT88_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT88_ADDR, HWIO_TLMM_GPIO_IN_OUT88_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT88_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT88_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT88_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT88_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT88_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT88_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT88_IN)
#define HWIO_TLMM_GPIO_IN_OUT88_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT88_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT88_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT88_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG88_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00058008)
#define HWIO_TLMM_GPIO_INTR_CFG88_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00058008)
#define HWIO_TLMM_GPIO_INTR_CFG88_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG88_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG88_ADDR, HWIO_TLMM_GPIO_INTR_CFG88_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG88_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG88_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG88_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG88_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG88_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG88_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG88_IN)
#define HWIO_TLMM_GPIO_INTR_CFG88_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG88_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG88_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG88_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG88_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS88_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005800c)
#define HWIO_TLMM_GPIO_INTR_STATUS88_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005800c)
#define HWIO_TLMM_GPIO_INTR_STATUS88_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS88_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS88_ADDR, HWIO_TLMM_GPIO_INTR_STATUS88_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS88_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS88_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS88_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS88_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS88_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS88_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS88_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS88_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS88_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS88_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00058010)
#define HWIO_TLMM_GPIO_ID_STATUS88_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00058010)
#define HWIO_TLMM_GPIO_ID_STATUS88_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS88_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS88_ADDR, HWIO_TLMM_GPIO_ID_STATUS88_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS88_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS88_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS88_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS88_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG89_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00059000)
#define HWIO_TLMM_GPIO_CFG89_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00059000)
#define HWIO_TLMM_GPIO_CFG89_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG89_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG89_ADDR, HWIO_TLMM_GPIO_CFG89_RMSK)
#define HWIO_TLMM_GPIO_CFG89_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG89_ADDR, m)
#define HWIO_TLMM_GPIO_CFG89_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG89_ADDR,v)
#define HWIO_TLMM_GPIO_CFG89_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG89_ADDR,m,v,HWIO_TLMM_GPIO_CFG89_IN)
#define HWIO_TLMM_GPIO_CFG89_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG89_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG89_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG89_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG89_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG89_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG89_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG89_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG89_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG89_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT89_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00059004)
#define HWIO_TLMM_GPIO_IN_OUT89_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00059004)
#define HWIO_TLMM_GPIO_IN_OUT89_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT89_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT89_ADDR, HWIO_TLMM_GPIO_IN_OUT89_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT89_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT89_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT89_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT89_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT89_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT89_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT89_IN)
#define HWIO_TLMM_GPIO_IN_OUT89_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT89_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT89_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT89_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG89_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00059008)
#define HWIO_TLMM_GPIO_INTR_CFG89_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00059008)
#define HWIO_TLMM_GPIO_INTR_CFG89_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG89_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG89_ADDR, HWIO_TLMM_GPIO_INTR_CFG89_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG89_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG89_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG89_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG89_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG89_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG89_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG89_IN)
#define HWIO_TLMM_GPIO_INTR_CFG89_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG89_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG89_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG89_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG89_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS89_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005900c)
#define HWIO_TLMM_GPIO_INTR_STATUS89_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005900c)
#define HWIO_TLMM_GPIO_INTR_STATUS89_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS89_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS89_ADDR, HWIO_TLMM_GPIO_INTR_STATUS89_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS89_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS89_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS89_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS89_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS89_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS89_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS89_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS89_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS89_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS89_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00059010)
#define HWIO_TLMM_GPIO_ID_STATUS89_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00059010)
#define HWIO_TLMM_GPIO_ID_STATUS89_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS89_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS89_ADDR, HWIO_TLMM_GPIO_ID_STATUS89_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS89_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS89_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS89_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS89_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG90_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0005a000)
#define HWIO_TLMM_GPIO_CFG90_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0005a000)
#define HWIO_TLMM_GPIO_CFG90_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG90_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG90_ADDR, HWIO_TLMM_GPIO_CFG90_RMSK)
#define HWIO_TLMM_GPIO_CFG90_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG90_ADDR, m)
#define HWIO_TLMM_GPIO_CFG90_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG90_ADDR,v)
#define HWIO_TLMM_GPIO_CFG90_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG90_ADDR,m,v,HWIO_TLMM_GPIO_CFG90_IN)
#define HWIO_TLMM_GPIO_CFG90_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG90_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG90_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG90_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG90_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG90_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG90_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG90_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG90_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG90_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT90_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0005a004)
#define HWIO_TLMM_GPIO_IN_OUT90_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0005a004)
#define HWIO_TLMM_GPIO_IN_OUT90_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT90_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT90_ADDR, HWIO_TLMM_GPIO_IN_OUT90_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT90_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT90_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT90_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT90_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT90_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT90_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT90_IN)
#define HWIO_TLMM_GPIO_IN_OUT90_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT90_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT90_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT90_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG90_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0005a008)
#define HWIO_TLMM_GPIO_INTR_CFG90_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0005a008)
#define HWIO_TLMM_GPIO_INTR_CFG90_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG90_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG90_ADDR, HWIO_TLMM_GPIO_INTR_CFG90_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG90_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG90_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG90_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG90_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG90_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG90_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG90_IN)
#define HWIO_TLMM_GPIO_INTR_CFG90_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG90_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG90_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG90_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG90_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS90_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS90_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS90_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS90_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS90_ADDR, HWIO_TLMM_GPIO_INTR_STATUS90_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS90_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS90_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS90_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS90_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS90_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS90_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS90_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS90_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS90_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS90_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0005a010)
#define HWIO_TLMM_GPIO_ID_STATUS90_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0005a010)
#define HWIO_TLMM_GPIO_ID_STATUS90_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS90_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS90_ADDR, HWIO_TLMM_GPIO_ID_STATUS90_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS90_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS90_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS90_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS90_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG91_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0005b000)
#define HWIO_TLMM_GPIO_CFG91_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0005b000)
#define HWIO_TLMM_GPIO_CFG91_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG91_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG91_ADDR, HWIO_TLMM_GPIO_CFG91_RMSK)
#define HWIO_TLMM_GPIO_CFG91_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG91_ADDR, m)
#define HWIO_TLMM_GPIO_CFG91_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG91_ADDR,v)
#define HWIO_TLMM_GPIO_CFG91_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG91_ADDR,m,v,HWIO_TLMM_GPIO_CFG91_IN)
#define HWIO_TLMM_GPIO_CFG91_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG91_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG91_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG91_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG91_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG91_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG91_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG91_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG91_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG91_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT91_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0005b004)
#define HWIO_TLMM_GPIO_IN_OUT91_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0005b004)
#define HWIO_TLMM_GPIO_IN_OUT91_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT91_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT91_ADDR, HWIO_TLMM_GPIO_IN_OUT91_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT91_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT91_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT91_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT91_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT91_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT91_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT91_IN)
#define HWIO_TLMM_GPIO_IN_OUT91_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT91_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT91_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT91_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG91_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0005b008)
#define HWIO_TLMM_GPIO_INTR_CFG91_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0005b008)
#define HWIO_TLMM_GPIO_INTR_CFG91_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG91_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG91_ADDR, HWIO_TLMM_GPIO_INTR_CFG91_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG91_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG91_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG91_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG91_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG91_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG91_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG91_IN)
#define HWIO_TLMM_GPIO_INTR_CFG91_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG91_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG91_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG91_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG91_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS91_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS91_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS91_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS91_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS91_ADDR, HWIO_TLMM_GPIO_INTR_STATUS91_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS91_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS91_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS91_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS91_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS91_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS91_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS91_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS91_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS91_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS91_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0005b010)
#define HWIO_TLMM_GPIO_ID_STATUS91_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0005b010)
#define HWIO_TLMM_GPIO_ID_STATUS91_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS91_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS91_ADDR, HWIO_TLMM_GPIO_ID_STATUS91_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS91_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS91_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS91_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS91_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG92_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0005c000)
#define HWIO_TLMM_GPIO_CFG92_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0005c000)
#define HWIO_TLMM_GPIO_CFG92_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG92_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG92_ADDR, HWIO_TLMM_GPIO_CFG92_RMSK)
#define HWIO_TLMM_GPIO_CFG92_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG92_ADDR, m)
#define HWIO_TLMM_GPIO_CFG92_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG92_ADDR,v)
#define HWIO_TLMM_GPIO_CFG92_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG92_ADDR,m,v,HWIO_TLMM_GPIO_CFG92_IN)
#define HWIO_TLMM_GPIO_CFG92_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG92_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG92_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG92_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG92_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG92_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG92_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG92_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG92_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG92_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT92_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0005c004)
#define HWIO_TLMM_GPIO_IN_OUT92_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0005c004)
#define HWIO_TLMM_GPIO_IN_OUT92_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT92_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT92_ADDR, HWIO_TLMM_GPIO_IN_OUT92_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT92_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT92_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT92_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT92_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT92_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT92_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT92_IN)
#define HWIO_TLMM_GPIO_IN_OUT92_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT92_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT92_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT92_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG92_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0005c008)
#define HWIO_TLMM_GPIO_INTR_CFG92_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0005c008)
#define HWIO_TLMM_GPIO_INTR_CFG92_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG92_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG92_ADDR, HWIO_TLMM_GPIO_INTR_CFG92_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG92_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG92_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG92_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG92_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG92_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG92_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG92_IN)
#define HWIO_TLMM_GPIO_INTR_CFG92_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG92_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG92_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG92_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG92_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS92_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS92_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS92_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS92_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS92_ADDR, HWIO_TLMM_GPIO_INTR_STATUS92_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS92_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS92_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS92_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS92_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS92_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS92_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS92_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS92_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS92_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS92_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0005c010)
#define HWIO_TLMM_GPIO_ID_STATUS92_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0005c010)
#define HWIO_TLMM_GPIO_ID_STATUS92_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS92_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS92_ADDR, HWIO_TLMM_GPIO_ID_STATUS92_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS92_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS92_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS92_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS92_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG93_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0005d000)
#define HWIO_TLMM_GPIO_CFG93_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0005d000)
#define HWIO_TLMM_GPIO_CFG93_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG93_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG93_ADDR, HWIO_TLMM_GPIO_CFG93_RMSK)
#define HWIO_TLMM_GPIO_CFG93_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG93_ADDR, m)
#define HWIO_TLMM_GPIO_CFG93_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG93_ADDR,v)
#define HWIO_TLMM_GPIO_CFG93_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG93_ADDR,m,v,HWIO_TLMM_GPIO_CFG93_IN)
#define HWIO_TLMM_GPIO_CFG93_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG93_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG93_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG93_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG93_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG93_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG93_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG93_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG93_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG93_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT93_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0005d004)
#define HWIO_TLMM_GPIO_IN_OUT93_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0005d004)
#define HWIO_TLMM_GPIO_IN_OUT93_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT93_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT93_ADDR, HWIO_TLMM_GPIO_IN_OUT93_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT93_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT93_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT93_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT93_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT93_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT93_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT93_IN)
#define HWIO_TLMM_GPIO_IN_OUT93_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT93_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT93_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT93_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG93_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0005d008)
#define HWIO_TLMM_GPIO_INTR_CFG93_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0005d008)
#define HWIO_TLMM_GPIO_INTR_CFG93_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG93_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG93_ADDR, HWIO_TLMM_GPIO_INTR_CFG93_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG93_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG93_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG93_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG93_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG93_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG93_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG93_IN)
#define HWIO_TLMM_GPIO_INTR_CFG93_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG93_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG93_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG93_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG93_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS93_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS93_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS93_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS93_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS93_ADDR, HWIO_TLMM_GPIO_INTR_STATUS93_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS93_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS93_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS93_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS93_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS93_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS93_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS93_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS93_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS93_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS93_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0005d010)
#define HWIO_TLMM_GPIO_ID_STATUS93_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0005d010)
#define HWIO_TLMM_GPIO_ID_STATUS93_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS93_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS93_ADDR, HWIO_TLMM_GPIO_ID_STATUS93_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS93_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS93_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS93_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS93_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG94_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0005e000)
#define HWIO_TLMM_GPIO_CFG94_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0005e000)
#define HWIO_TLMM_GPIO_CFG94_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG94_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG94_ADDR, HWIO_TLMM_GPIO_CFG94_RMSK)
#define HWIO_TLMM_GPIO_CFG94_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG94_ADDR, m)
#define HWIO_TLMM_GPIO_CFG94_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG94_ADDR,v)
#define HWIO_TLMM_GPIO_CFG94_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG94_ADDR,m,v,HWIO_TLMM_GPIO_CFG94_IN)
#define HWIO_TLMM_GPIO_CFG94_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG94_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG94_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG94_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG94_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG94_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG94_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG94_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG94_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG94_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT94_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0005e004)
#define HWIO_TLMM_GPIO_IN_OUT94_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0005e004)
#define HWIO_TLMM_GPIO_IN_OUT94_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT94_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT94_ADDR, HWIO_TLMM_GPIO_IN_OUT94_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT94_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT94_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT94_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT94_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT94_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT94_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT94_IN)
#define HWIO_TLMM_GPIO_IN_OUT94_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT94_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT94_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT94_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG94_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0005e008)
#define HWIO_TLMM_GPIO_INTR_CFG94_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0005e008)
#define HWIO_TLMM_GPIO_INTR_CFG94_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG94_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG94_ADDR, HWIO_TLMM_GPIO_INTR_CFG94_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG94_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG94_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG94_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG94_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG94_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG94_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG94_IN)
#define HWIO_TLMM_GPIO_INTR_CFG94_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG94_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG94_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG94_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG94_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS94_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS94_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS94_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS94_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS94_ADDR, HWIO_TLMM_GPIO_INTR_STATUS94_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS94_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS94_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS94_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS94_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS94_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS94_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS94_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS94_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS94_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS94_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0005e010)
#define HWIO_TLMM_GPIO_ID_STATUS94_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0005e010)
#define HWIO_TLMM_GPIO_ID_STATUS94_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS94_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS94_ADDR, HWIO_TLMM_GPIO_ID_STATUS94_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS94_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS94_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS94_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS94_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG95_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x0005f000)
#define HWIO_TLMM_GPIO_CFG95_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x0005f000)
#define HWIO_TLMM_GPIO_CFG95_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG95_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG95_ADDR, HWIO_TLMM_GPIO_CFG95_RMSK)
#define HWIO_TLMM_GPIO_CFG95_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG95_ADDR, m)
#define HWIO_TLMM_GPIO_CFG95_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG95_ADDR,v)
#define HWIO_TLMM_GPIO_CFG95_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG95_ADDR,m,v,HWIO_TLMM_GPIO_CFG95_IN)
#define HWIO_TLMM_GPIO_CFG95_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG95_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG95_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG95_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG95_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG95_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG95_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG95_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG95_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG95_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT95_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x0005f004)
#define HWIO_TLMM_GPIO_IN_OUT95_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x0005f004)
#define HWIO_TLMM_GPIO_IN_OUT95_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT95_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT95_ADDR, HWIO_TLMM_GPIO_IN_OUT95_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT95_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT95_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT95_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT95_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT95_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT95_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT95_IN)
#define HWIO_TLMM_GPIO_IN_OUT95_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT95_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT95_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT95_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG95_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x0005f008)
#define HWIO_TLMM_GPIO_INTR_CFG95_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x0005f008)
#define HWIO_TLMM_GPIO_INTR_CFG95_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG95_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG95_ADDR, HWIO_TLMM_GPIO_INTR_CFG95_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG95_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG95_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG95_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG95_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG95_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG95_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG95_IN)
#define HWIO_TLMM_GPIO_INTR_CFG95_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG95_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG95_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG95_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG95_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS95_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0005f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS95_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0005f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS95_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS95_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS95_ADDR, HWIO_TLMM_GPIO_INTR_STATUS95_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS95_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS95_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS95_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS95_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS95_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS95_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS95_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS95_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS95_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS95_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0005f010)
#define HWIO_TLMM_GPIO_ID_STATUS95_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0005f010)
#define HWIO_TLMM_GPIO_ID_STATUS95_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS95_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS95_ADDR, HWIO_TLMM_GPIO_ID_STATUS95_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS95_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS95_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS95_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS95_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG96_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00060000)
#define HWIO_TLMM_GPIO_CFG96_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00060000)
#define HWIO_TLMM_GPIO_CFG96_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG96_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG96_ADDR, HWIO_TLMM_GPIO_CFG96_RMSK)
#define HWIO_TLMM_GPIO_CFG96_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG96_ADDR, m)
#define HWIO_TLMM_GPIO_CFG96_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG96_ADDR,v)
#define HWIO_TLMM_GPIO_CFG96_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG96_ADDR,m,v,HWIO_TLMM_GPIO_CFG96_IN)
#define HWIO_TLMM_GPIO_CFG96_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG96_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG96_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG96_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG96_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG96_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG96_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG96_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG96_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG96_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT96_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00060004)
#define HWIO_TLMM_GPIO_IN_OUT96_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00060004)
#define HWIO_TLMM_GPIO_IN_OUT96_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT96_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT96_ADDR, HWIO_TLMM_GPIO_IN_OUT96_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT96_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT96_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT96_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT96_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT96_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT96_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT96_IN)
#define HWIO_TLMM_GPIO_IN_OUT96_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT96_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT96_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT96_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG96_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00060008)
#define HWIO_TLMM_GPIO_INTR_CFG96_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00060008)
#define HWIO_TLMM_GPIO_INTR_CFG96_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG96_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG96_ADDR, HWIO_TLMM_GPIO_INTR_CFG96_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG96_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG96_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG96_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG96_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG96_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG96_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG96_IN)
#define HWIO_TLMM_GPIO_INTR_CFG96_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG96_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG96_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG96_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG96_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS96_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0006000c)
#define HWIO_TLMM_GPIO_INTR_STATUS96_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0006000c)
#define HWIO_TLMM_GPIO_INTR_STATUS96_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS96_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS96_ADDR, HWIO_TLMM_GPIO_INTR_STATUS96_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS96_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS96_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS96_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS96_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS96_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS96_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS96_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS96_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS96_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS96_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00060010)
#define HWIO_TLMM_GPIO_ID_STATUS96_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00060010)
#define HWIO_TLMM_GPIO_ID_STATUS96_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS96_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS96_ADDR, HWIO_TLMM_GPIO_ID_STATUS96_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS96_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS96_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS96_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS96_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG97_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00061000)
#define HWIO_TLMM_GPIO_CFG97_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00061000)
#define HWIO_TLMM_GPIO_CFG97_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG97_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG97_ADDR, HWIO_TLMM_GPIO_CFG97_RMSK)
#define HWIO_TLMM_GPIO_CFG97_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG97_ADDR, m)
#define HWIO_TLMM_GPIO_CFG97_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG97_ADDR,v)
#define HWIO_TLMM_GPIO_CFG97_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG97_ADDR,m,v,HWIO_TLMM_GPIO_CFG97_IN)
#define HWIO_TLMM_GPIO_CFG97_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG97_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG97_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG97_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG97_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG97_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG97_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG97_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG97_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG97_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT97_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00061004)
#define HWIO_TLMM_GPIO_IN_OUT97_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00061004)
#define HWIO_TLMM_GPIO_IN_OUT97_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT97_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT97_ADDR, HWIO_TLMM_GPIO_IN_OUT97_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT97_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT97_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT97_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT97_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT97_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT97_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT97_IN)
#define HWIO_TLMM_GPIO_IN_OUT97_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT97_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT97_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT97_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG97_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00061008)
#define HWIO_TLMM_GPIO_INTR_CFG97_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00061008)
#define HWIO_TLMM_GPIO_INTR_CFG97_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG97_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG97_ADDR, HWIO_TLMM_GPIO_INTR_CFG97_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG97_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG97_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG97_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG97_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG97_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG97_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG97_IN)
#define HWIO_TLMM_GPIO_INTR_CFG97_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG97_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG97_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG97_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG97_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS97_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0006100c)
#define HWIO_TLMM_GPIO_INTR_STATUS97_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0006100c)
#define HWIO_TLMM_GPIO_INTR_STATUS97_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS97_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS97_ADDR, HWIO_TLMM_GPIO_INTR_STATUS97_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS97_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS97_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS97_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS97_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS97_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS97_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS97_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS97_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS97_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS97_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00061010)
#define HWIO_TLMM_GPIO_ID_STATUS97_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00061010)
#define HWIO_TLMM_GPIO_ID_STATUS97_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS97_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS97_ADDR, HWIO_TLMM_GPIO_ID_STATUS97_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS97_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS97_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS97_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS97_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG98_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00062000)
#define HWIO_TLMM_GPIO_CFG98_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00062000)
#define HWIO_TLMM_GPIO_CFG98_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG98_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG98_ADDR, HWIO_TLMM_GPIO_CFG98_RMSK)
#define HWIO_TLMM_GPIO_CFG98_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG98_ADDR, m)
#define HWIO_TLMM_GPIO_CFG98_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG98_ADDR,v)
#define HWIO_TLMM_GPIO_CFG98_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG98_ADDR,m,v,HWIO_TLMM_GPIO_CFG98_IN)
#define HWIO_TLMM_GPIO_CFG98_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG98_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG98_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG98_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG98_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG98_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG98_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG98_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG98_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG98_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT98_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00062004)
#define HWIO_TLMM_GPIO_IN_OUT98_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00062004)
#define HWIO_TLMM_GPIO_IN_OUT98_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT98_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT98_ADDR, HWIO_TLMM_GPIO_IN_OUT98_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT98_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT98_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT98_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT98_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT98_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT98_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT98_IN)
#define HWIO_TLMM_GPIO_IN_OUT98_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT98_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT98_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT98_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG98_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00062008)
#define HWIO_TLMM_GPIO_INTR_CFG98_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00062008)
#define HWIO_TLMM_GPIO_INTR_CFG98_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG98_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG98_ADDR, HWIO_TLMM_GPIO_INTR_CFG98_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG98_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG98_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG98_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG98_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG98_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG98_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG98_IN)
#define HWIO_TLMM_GPIO_INTR_CFG98_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG98_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG98_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG98_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG98_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS98_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0006200c)
#define HWIO_TLMM_GPIO_INTR_STATUS98_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0006200c)
#define HWIO_TLMM_GPIO_INTR_STATUS98_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS98_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS98_ADDR, HWIO_TLMM_GPIO_INTR_STATUS98_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS98_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS98_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS98_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS98_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS98_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS98_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS98_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS98_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS98_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS98_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00062010)
#define HWIO_TLMM_GPIO_ID_STATUS98_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00062010)
#define HWIO_TLMM_GPIO_ID_STATUS98_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS98_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS98_ADDR, HWIO_TLMM_GPIO_ID_STATUS98_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS98_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS98_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS98_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS98_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG99_ADDR                                          (TLMM_SOUTH_REG_BASE      + 0x00063000)
#define HWIO_TLMM_GPIO_CFG99_OFFS                                          (TLMM_SOUTH_REG_BASE_OFFS + 0x00063000)
#define HWIO_TLMM_GPIO_CFG99_RMSK                                               0x7ff
#define HWIO_TLMM_GPIO_CFG99_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG99_ADDR, HWIO_TLMM_GPIO_CFG99_RMSK)
#define HWIO_TLMM_GPIO_CFG99_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG99_ADDR, m)
#define HWIO_TLMM_GPIO_CFG99_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG99_ADDR,v)
#define HWIO_TLMM_GPIO_CFG99_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG99_ADDR,m,v,HWIO_TLMM_GPIO_CFG99_IN)
#define HWIO_TLMM_GPIO_CFG99_GPIO_HIHYS_EN_BMSK                                 0x400
#define HWIO_TLMM_GPIO_CFG99_GPIO_HIHYS_EN_SHFT                                   0xa
#define HWIO_TLMM_GPIO_CFG99_GPIO_OE_BMSK                                       0x200
#define HWIO_TLMM_GPIO_CFG99_GPIO_OE_SHFT                                         0x9
#define HWIO_TLMM_GPIO_CFG99_DRV_STRENGTH_BMSK                                  0x1c0
#define HWIO_TLMM_GPIO_CFG99_DRV_STRENGTH_SHFT                                    0x6
#define HWIO_TLMM_GPIO_CFG99_FUNC_SEL_BMSK                                       0x3c
#define HWIO_TLMM_GPIO_CFG99_FUNC_SEL_SHFT                                        0x2
#define HWIO_TLMM_GPIO_CFG99_GPIO_PULL_BMSK                                       0x3
#define HWIO_TLMM_GPIO_CFG99_GPIO_PULL_SHFT                                       0x0

#define HWIO_TLMM_GPIO_IN_OUT99_ADDR                                       (TLMM_SOUTH_REG_BASE      + 0x00063004)
#define HWIO_TLMM_GPIO_IN_OUT99_OFFS                                       (TLMM_SOUTH_REG_BASE_OFFS + 0x00063004)
#define HWIO_TLMM_GPIO_IN_OUT99_RMSK                                              0x3
#define HWIO_TLMM_GPIO_IN_OUT99_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT99_ADDR, HWIO_TLMM_GPIO_IN_OUT99_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT99_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT99_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT99_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT99_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT99_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT99_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT99_IN)
#define HWIO_TLMM_GPIO_IN_OUT99_GPIO_OUT_BMSK                                     0x2
#define HWIO_TLMM_GPIO_IN_OUT99_GPIO_OUT_SHFT                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT99_GPIO_IN_BMSK                                      0x1
#define HWIO_TLMM_GPIO_IN_OUT99_GPIO_IN_SHFT                                      0x0

#define HWIO_TLMM_GPIO_INTR_CFG99_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00063008)
#define HWIO_TLMM_GPIO_INTR_CFG99_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00063008)
#define HWIO_TLMM_GPIO_INTR_CFG99_RMSK                                          0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG99_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG99_ADDR, HWIO_TLMM_GPIO_INTR_CFG99_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG99_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG99_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG99_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG99_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG99_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG99_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG99_IN)
#define HWIO_TLMM_GPIO_INTR_CFG99_DIR_CONN_EN_BMSK                              0x100
#define HWIO_TLMM_GPIO_INTR_CFG99_DIR_CONN_EN_SHFT                                0x8
#define HWIO_TLMM_GPIO_INTR_CFG99_TARGET_PROC_BMSK                               0xe0
#define HWIO_TLMM_GPIO_INTR_CFG99_TARGET_PROC_SHFT                                0x5
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_RAW_STATUS_EN_BMSK                        0x10
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_RAW_STATUS_EN_SHFT                         0x4
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_DECT_CTL_BMSK                              0xc
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_DECT_CTL_SHFT                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_POL_CTL_BMSK                               0x2
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_POL_CTL_SHFT                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_ENABLE_BMSK                                0x1
#define HWIO_TLMM_GPIO_INTR_CFG99_INTR_ENABLE_SHFT                                0x0

#define HWIO_TLMM_GPIO_INTR_STATUS99_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0006300c)
#define HWIO_TLMM_GPIO_INTR_STATUS99_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0006300c)
#define HWIO_TLMM_GPIO_INTR_STATUS99_RMSK                                         0x1
#define HWIO_TLMM_GPIO_INTR_STATUS99_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS99_ADDR, HWIO_TLMM_GPIO_INTR_STATUS99_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS99_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS99_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS99_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS99_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS99_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS99_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS99_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS99_INTR_STATUS_BMSK                             0x1
#define HWIO_TLMM_GPIO_INTR_STATUS99_INTR_STATUS_SHFT                             0x0

#define HWIO_TLMM_GPIO_ID_STATUS99_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00063010)
#define HWIO_TLMM_GPIO_ID_STATUS99_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00063010)
#define HWIO_TLMM_GPIO_ID_STATUS99_RMSK                                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS99_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS99_ADDR, HWIO_TLMM_GPIO_ID_STATUS99_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS99_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS99_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS99_GPIO_ID_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_ID_STATUS99_GPIO_ID_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_CFG100_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00064000)
#define HWIO_TLMM_GPIO_CFG100_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00064000)
#define HWIO_TLMM_GPIO_CFG100_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG100_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG100_ADDR, HWIO_TLMM_GPIO_CFG100_RMSK)
#define HWIO_TLMM_GPIO_CFG100_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG100_ADDR, m)
#define HWIO_TLMM_GPIO_CFG100_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG100_ADDR,v)
#define HWIO_TLMM_GPIO_CFG100_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG100_ADDR,m,v,HWIO_TLMM_GPIO_CFG100_IN)
#define HWIO_TLMM_GPIO_CFG100_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG100_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG100_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG100_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG100_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG100_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG100_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG100_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG100_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG100_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT100_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00064004)
#define HWIO_TLMM_GPIO_IN_OUT100_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00064004)
#define HWIO_TLMM_GPIO_IN_OUT100_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT100_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT100_ADDR, HWIO_TLMM_GPIO_IN_OUT100_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT100_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT100_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT100_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT100_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT100_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT100_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT100_IN)
#define HWIO_TLMM_GPIO_IN_OUT100_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT100_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT100_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT100_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG100_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00064008)
#define HWIO_TLMM_GPIO_INTR_CFG100_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00064008)
#define HWIO_TLMM_GPIO_INTR_CFG100_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG100_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG100_ADDR, HWIO_TLMM_GPIO_INTR_CFG100_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG100_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG100_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG100_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG100_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG100_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG100_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG100_IN)
#define HWIO_TLMM_GPIO_INTR_CFG100_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG100_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG100_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG100_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG100_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS100_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006400c)
#define HWIO_TLMM_GPIO_INTR_STATUS100_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006400c)
#define HWIO_TLMM_GPIO_INTR_STATUS100_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS100_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS100_ADDR, HWIO_TLMM_GPIO_INTR_STATUS100_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS100_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS100_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS100_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS100_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS100_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS100_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS100_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS100_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS100_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS100_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00064010)
#define HWIO_TLMM_GPIO_ID_STATUS100_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00064010)
#define HWIO_TLMM_GPIO_ID_STATUS100_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS100_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS100_ADDR, HWIO_TLMM_GPIO_ID_STATUS100_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS100_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS100_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS100_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS100_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG101_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00065000)
#define HWIO_TLMM_GPIO_CFG101_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00065000)
#define HWIO_TLMM_GPIO_CFG101_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG101_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG101_ADDR, HWIO_TLMM_GPIO_CFG101_RMSK)
#define HWIO_TLMM_GPIO_CFG101_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG101_ADDR, m)
#define HWIO_TLMM_GPIO_CFG101_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG101_ADDR,v)
#define HWIO_TLMM_GPIO_CFG101_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG101_ADDR,m,v,HWIO_TLMM_GPIO_CFG101_IN)
#define HWIO_TLMM_GPIO_CFG101_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG101_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG101_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG101_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG101_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG101_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG101_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG101_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG101_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG101_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT101_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00065004)
#define HWIO_TLMM_GPIO_IN_OUT101_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00065004)
#define HWIO_TLMM_GPIO_IN_OUT101_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT101_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT101_ADDR, HWIO_TLMM_GPIO_IN_OUT101_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT101_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT101_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT101_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT101_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT101_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT101_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT101_IN)
#define HWIO_TLMM_GPIO_IN_OUT101_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT101_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT101_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT101_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG101_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00065008)
#define HWIO_TLMM_GPIO_INTR_CFG101_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00065008)
#define HWIO_TLMM_GPIO_INTR_CFG101_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG101_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG101_ADDR, HWIO_TLMM_GPIO_INTR_CFG101_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG101_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG101_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG101_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG101_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG101_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG101_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG101_IN)
#define HWIO_TLMM_GPIO_INTR_CFG101_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG101_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG101_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG101_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG101_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS101_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006500c)
#define HWIO_TLMM_GPIO_INTR_STATUS101_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006500c)
#define HWIO_TLMM_GPIO_INTR_STATUS101_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS101_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS101_ADDR, HWIO_TLMM_GPIO_INTR_STATUS101_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS101_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS101_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS101_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS101_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS101_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS101_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS101_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS101_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS101_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS101_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00065010)
#define HWIO_TLMM_GPIO_ID_STATUS101_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00065010)
#define HWIO_TLMM_GPIO_ID_STATUS101_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS101_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS101_ADDR, HWIO_TLMM_GPIO_ID_STATUS101_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS101_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS101_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS101_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS101_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG102_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00066000)
#define HWIO_TLMM_GPIO_CFG102_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00066000)
#define HWIO_TLMM_GPIO_CFG102_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG102_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG102_ADDR, HWIO_TLMM_GPIO_CFG102_RMSK)
#define HWIO_TLMM_GPIO_CFG102_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG102_ADDR, m)
#define HWIO_TLMM_GPIO_CFG102_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG102_ADDR,v)
#define HWIO_TLMM_GPIO_CFG102_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG102_ADDR,m,v,HWIO_TLMM_GPIO_CFG102_IN)
#define HWIO_TLMM_GPIO_CFG102_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG102_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG102_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG102_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG102_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG102_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG102_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG102_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG102_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG102_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT102_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00066004)
#define HWIO_TLMM_GPIO_IN_OUT102_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00066004)
#define HWIO_TLMM_GPIO_IN_OUT102_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT102_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT102_ADDR, HWIO_TLMM_GPIO_IN_OUT102_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT102_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT102_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT102_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT102_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT102_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT102_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT102_IN)
#define HWIO_TLMM_GPIO_IN_OUT102_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT102_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT102_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT102_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG102_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00066008)
#define HWIO_TLMM_GPIO_INTR_CFG102_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00066008)
#define HWIO_TLMM_GPIO_INTR_CFG102_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG102_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG102_ADDR, HWIO_TLMM_GPIO_INTR_CFG102_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG102_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG102_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG102_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG102_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG102_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG102_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG102_IN)
#define HWIO_TLMM_GPIO_INTR_CFG102_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG102_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG102_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG102_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG102_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS102_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006600c)
#define HWIO_TLMM_GPIO_INTR_STATUS102_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006600c)
#define HWIO_TLMM_GPIO_INTR_STATUS102_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS102_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS102_ADDR, HWIO_TLMM_GPIO_INTR_STATUS102_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS102_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS102_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS102_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS102_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS102_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS102_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS102_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS102_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS102_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS102_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00066010)
#define HWIO_TLMM_GPIO_ID_STATUS102_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00066010)
#define HWIO_TLMM_GPIO_ID_STATUS102_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS102_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS102_ADDR, HWIO_TLMM_GPIO_ID_STATUS102_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS102_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS102_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS102_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS102_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG103_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00067000)
#define HWIO_TLMM_GPIO_CFG103_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00067000)
#define HWIO_TLMM_GPIO_CFG103_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG103_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG103_ADDR, HWIO_TLMM_GPIO_CFG103_RMSK)
#define HWIO_TLMM_GPIO_CFG103_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG103_ADDR, m)
#define HWIO_TLMM_GPIO_CFG103_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG103_ADDR,v)
#define HWIO_TLMM_GPIO_CFG103_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG103_ADDR,m,v,HWIO_TLMM_GPIO_CFG103_IN)
#define HWIO_TLMM_GPIO_CFG103_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG103_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG103_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG103_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG103_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG103_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG103_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG103_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG103_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG103_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT103_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00067004)
#define HWIO_TLMM_GPIO_IN_OUT103_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00067004)
#define HWIO_TLMM_GPIO_IN_OUT103_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT103_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT103_ADDR, HWIO_TLMM_GPIO_IN_OUT103_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT103_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT103_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT103_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT103_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT103_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT103_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT103_IN)
#define HWIO_TLMM_GPIO_IN_OUT103_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT103_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT103_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT103_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG103_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00067008)
#define HWIO_TLMM_GPIO_INTR_CFG103_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00067008)
#define HWIO_TLMM_GPIO_INTR_CFG103_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG103_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG103_ADDR, HWIO_TLMM_GPIO_INTR_CFG103_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG103_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG103_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG103_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG103_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG103_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG103_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG103_IN)
#define HWIO_TLMM_GPIO_INTR_CFG103_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG103_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG103_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG103_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG103_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS103_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006700c)
#define HWIO_TLMM_GPIO_INTR_STATUS103_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006700c)
#define HWIO_TLMM_GPIO_INTR_STATUS103_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS103_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS103_ADDR, HWIO_TLMM_GPIO_INTR_STATUS103_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS103_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS103_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS103_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS103_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS103_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS103_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS103_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS103_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS103_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS103_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00067010)
#define HWIO_TLMM_GPIO_ID_STATUS103_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00067010)
#define HWIO_TLMM_GPIO_ID_STATUS103_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS103_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS103_ADDR, HWIO_TLMM_GPIO_ID_STATUS103_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS103_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS103_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS103_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS103_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG104_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00068000)
#define HWIO_TLMM_GPIO_CFG104_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00068000)
#define HWIO_TLMM_GPIO_CFG104_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG104_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG104_ADDR, HWIO_TLMM_GPIO_CFG104_RMSK)
#define HWIO_TLMM_GPIO_CFG104_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG104_ADDR, m)
#define HWIO_TLMM_GPIO_CFG104_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG104_ADDR,v)
#define HWIO_TLMM_GPIO_CFG104_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG104_ADDR,m,v,HWIO_TLMM_GPIO_CFG104_IN)
#define HWIO_TLMM_GPIO_CFG104_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG104_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG104_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG104_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG104_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG104_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG104_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG104_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG104_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG104_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT104_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00068004)
#define HWIO_TLMM_GPIO_IN_OUT104_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00068004)
#define HWIO_TLMM_GPIO_IN_OUT104_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT104_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT104_ADDR, HWIO_TLMM_GPIO_IN_OUT104_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT104_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT104_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT104_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT104_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT104_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT104_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT104_IN)
#define HWIO_TLMM_GPIO_IN_OUT104_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT104_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT104_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT104_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG104_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00068008)
#define HWIO_TLMM_GPIO_INTR_CFG104_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00068008)
#define HWIO_TLMM_GPIO_INTR_CFG104_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG104_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG104_ADDR, HWIO_TLMM_GPIO_INTR_CFG104_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG104_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG104_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG104_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG104_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG104_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG104_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG104_IN)
#define HWIO_TLMM_GPIO_INTR_CFG104_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG104_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG104_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG104_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG104_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS104_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006800c)
#define HWIO_TLMM_GPIO_INTR_STATUS104_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006800c)
#define HWIO_TLMM_GPIO_INTR_STATUS104_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS104_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS104_ADDR, HWIO_TLMM_GPIO_INTR_STATUS104_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS104_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS104_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS104_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS104_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS104_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS104_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS104_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS104_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS104_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS104_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00068010)
#define HWIO_TLMM_GPIO_ID_STATUS104_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00068010)
#define HWIO_TLMM_GPIO_ID_STATUS104_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS104_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS104_ADDR, HWIO_TLMM_GPIO_ID_STATUS104_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS104_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS104_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS104_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS104_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG105_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00069000)
#define HWIO_TLMM_GPIO_CFG105_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00069000)
#define HWIO_TLMM_GPIO_CFG105_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG105_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG105_ADDR, HWIO_TLMM_GPIO_CFG105_RMSK)
#define HWIO_TLMM_GPIO_CFG105_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG105_ADDR, m)
#define HWIO_TLMM_GPIO_CFG105_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG105_ADDR,v)
#define HWIO_TLMM_GPIO_CFG105_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG105_ADDR,m,v,HWIO_TLMM_GPIO_CFG105_IN)
#define HWIO_TLMM_GPIO_CFG105_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG105_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG105_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG105_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG105_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG105_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG105_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG105_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG105_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG105_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT105_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00069004)
#define HWIO_TLMM_GPIO_IN_OUT105_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00069004)
#define HWIO_TLMM_GPIO_IN_OUT105_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT105_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT105_ADDR, HWIO_TLMM_GPIO_IN_OUT105_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT105_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT105_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT105_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT105_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT105_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT105_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT105_IN)
#define HWIO_TLMM_GPIO_IN_OUT105_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT105_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT105_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT105_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG105_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00069008)
#define HWIO_TLMM_GPIO_INTR_CFG105_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00069008)
#define HWIO_TLMM_GPIO_INTR_CFG105_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG105_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG105_ADDR, HWIO_TLMM_GPIO_INTR_CFG105_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG105_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG105_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG105_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG105_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG105_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG105_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG105_IN)
#define HWIO_TLMM_GPIO_INTR_CFG105_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG105_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG105_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG105_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG105_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS105_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006900c)
#define HWIO_TLMM_GPIO_INTR_STATUS105_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006900c)
#define HWIO_TLMM_GPIO_INTR_STATUS105_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS105_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS105_ADDR, HWIO_TLMM_GPIO_INTR_STATUS105_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS105_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS105_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS105_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS105_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS105_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS105_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS105_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS105_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS105_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS105_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00069010)
#define HWIO_TLMM_GPIO_ID_STATUS105_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00069010)
#define HWIO_TLMM_GPIO_ID_STATUS105_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS105_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS105_ADDR, HWIO_TLMM_GPIO_ID_STATUS105_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS105_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS105_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS105_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS105_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG106_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0006a000)
#define HWIO_TLMM_GPIO_CFG106_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0006a000)
#define HWIO_TLMM_GPIO_CFG106_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG106_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG106_ADDR, HWIO_TLMM_GPIO_CFG106_RMSK)
#define HWIO_TLMM_GPIO_CFG106_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG106_ADDR, m)
#define HWIO_TLMM_GPIO_CFG106_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG106_ADDR,v)
#define HWIO_TLMM_GPIO_CFG106_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG106_ADDR,m,v,HWIO_TLMM_GPIO_CFG106_IN)
#define HWIO_TLMM_GPIO_CFG106_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG106_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG106_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG106_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG106_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG106_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG106_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG106_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG106_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG106_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT106_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0006a004)
#define HWIO_TLMM_GPIO_IN_OUT106_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0006a004)
#define HWIO_TLMM_GPIO_IN_OUT106_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT106_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT106_ADDR, HWIO_TLMM_GPIO_IN_OUT106_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT106_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT106_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT106_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT106_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT106_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT106_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT106_IN)
#define HWIO_TLMM_GPIO_IN_OUT106_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT106_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT106_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT106_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG106_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0006a008)
#define HWIO_TLMM_GPIO_INTR_CFG106_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0006a008)
#define HWIO_TLMM_GPIO_INTR_CFG106_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG106_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG106_ADDR, HWIO_TLMM_GPIO_INTR_CFG106_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG106_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG106_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG106_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG106_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG106_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG106_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG106_IN)
#define HWIO_TLMM_GPIO_INTR_CFG106_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG106_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG106_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG106_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG106_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS106_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS106_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006a00c)
#define HWIO_TLMM_GPIO_INTR_STATUS106_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS106_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS106_ADDR, HWIO_TLMM_GPIO_INTR_STATUS106_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS106_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS106_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS106_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS106_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS106_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS106_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS106_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS106_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS106_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS106_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0006a010)
#define HWIO_TLMM_GPIO_ID_STATUS106_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0006a010)
#define HWIO_TLMM_GPIO_ID_STATUS106_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS106_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS106_ADDR, HWIO_TLMM_GPIO_ID_STATUS106_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS106_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS106_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS106_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS106_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG107_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0006b000)
#define HWIO_TLMM_GPIO_CFG107_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0006b000)
#define HWIO_TLMM_GPIO_CFG107_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG107_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG107_ADDR, HWIO_TLMM_GPIO_CFG107_RMSK)
#define HWIO_TLMM_GPIO_CFG107_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG107_ADDR, m)
#define HWIO_TLMM_GPIO_CFG107_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG107_ADDR,v)
#define HWIO_TLMM_GPIO_CFG107_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG107_ADDR,m,v,HWIO_TLMM_GPIO_CFG107_IN)
#define HWIO_TLMM_GPIO_CFG107_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG107_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG107_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG107_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG107_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG107_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG107_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG107_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG107_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG107_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT107_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0006b004)
#define HWIO_TLMM_GPIO_IN_OUT107_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0006b004)
#define HWIO_TLMM_GPIO_IN_OUT107_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT107_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT107_ADDR, HWIO_TLMM_GPIO_IN_OUT107_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT107_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT107_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT107_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT107_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT107_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT107_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT107_IN)
#define HWIO_TLMM_GPIO_IN_OUT107_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT107_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT107_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT107_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG107_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0006b008)
#define HWIO_TLMM_GPIO_INTR_CFG107_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0006b008)
#define HWIO_TLMM_GPIO_INTR_CFG107_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG107_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG107_ADDR, HWIO_TLMM_GPIO_INTR_CFG107_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG107_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG107_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG107_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG107_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG107_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG107_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG107_IN)
#define HWIO_TLMM_GPIO_INTR_CFG107_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG107_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG107_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG107_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG107_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS107_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS107_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006b00c)
#define HWIO_TLMM_GPIO_INTR_STATUS107_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS107_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS107_ADDR, HWIO_TLMM_GPIO_INTR_STATUS107_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS107_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS107_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS107_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS107_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS107_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS107_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS107_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS107_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS107_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS107_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0006b010)
#define HWIO_TLMM_GPIO_ID_STATUS107_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0006b010)
#define HWIO_TLMM_GPIO_ID_STATUS107_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS107_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS107_ADDR, HWIO_TLMM_GPIO_ID_STATUS107_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS107_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS107_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS107_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS107_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG108_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0006c000)
#define HWIO_TLMM_GPIO_CFG108_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0006c000)
#define HWIO_TLMM_GPIO_CFG108_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG108_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG108_ADDR, HWIO_TLMM_GPIO_CFG108_RMSK)
#define HWIO_TLMM_GPIO_CFG108_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG108_ADDR, m)
#define HWIO_TLMM_GPIO_CFG108_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG108_ADDR,v)
#define HWIO_TLMM_GPIO_CFG108_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG108_ADDR,m,v,HWIO_TLMM_GPIO_CFG108_IN)
#define HWIO_TLMM_GPIO_CFG108_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG108_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG108_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG108_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG108_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG108_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG108_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG108_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG108_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG108_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT108_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0006c004)
#define HWIO_TLMM_GPIO_IN_OUT108_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0006c004)
#define HWIO_TLMM_GPIO_IN_OUT108_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT108_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT108_ADDR, HWIO_TLMM_GPIO_IN_OUT108_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT108_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT108_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT108_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT108_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT108_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT108_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT108_IN)
#define HWIO_TLMM_GPIO_IN_OUT108_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT108_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT108_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT108_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG108_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0006c008)
#define HWIO_TLMM_GPIO_INTR_CFG108_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0006c008)
#define HWIO_TLMM_GPIO_INTR_CFG108_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG108_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG108_ADDR, HWIO_TLMM_GPIO_INTR_CFG108_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG108_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG108_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG108_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG108_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG108_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG108_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG108_IN)
#define HWIO_TLMM_GPIO_INTR_CFG108_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG108_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG108_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG108_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG108_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS108_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS108_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006c00c)
#define HWIO_TLMM_GPIO_INTR_STATUS108_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS108_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS108_ADDR, HWIO_TLMM_GPIO_INTR_STATUS108_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS108_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS108_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS108_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS108_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS108_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS108_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS108_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS108_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS108_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS108_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0006c010)
#define HWIO_TLMM_GPIO_ID_STATUS108_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0006c010)
#define HWIO_TLMM_GPIO_ID_STATUS108_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS108_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS108_ADDR, HWIO_TLMM_GPIO_ID_STATUS108_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS108_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS108_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS108_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS108_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG109_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0006d000)
#define HWIO_TLMM_GPIO_CFG109_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0006d000)
#define HWIO_TLMM_GPIO_CFG109_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG109_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG109_ADDR, HWIO_TLMM_GPIO_CFG109_RMSK)
#define HWIO_TLMM_GPIO_CFG109_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG109_ADDR, m)
#define HWIO_TLMM_GPIO_CFG109_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG109_ADDR,v)
#define HWIO_TLMM_GPIO_CFG109_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG109_ADDR,m,v,HWIO_TLMM_GPIO_CFG109_IN)
#define HWIO_TLMM_GPIO_CFG109_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG109_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG109_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG109_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG109_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG109_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG109_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG109_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG109_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG109_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT109_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0006d004)
#define HWIO_TLMM_GPIO_IN_OUT109_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0006d004)
#define HWIO_TLMM_GPIO_IN_OUT109_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT109_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT109_ADDR, HWIO_TLMM_GPIO_IN_OUT109_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT109_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT109_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT109_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT109_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT109_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT109_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT109_IN)
#define HWIO_TLMM_GPIO_IN_OUT109_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT109_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT109_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT109_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG109_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0006d008)
#define HWIO_TLMM_GPIO_INTR_CFG109_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0006d008)
#define HWIO_TLMM_GPIO_INTR_CFG109_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG109_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG109_ADDR, HWIO_TLMM_GPIO_INTR_CFG109_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG109_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG109_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG109_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG109_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG109_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG109_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG109_IN)
#define HWIO_TLMM_GPIO_INTR_CFG109_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG109_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG109_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG109_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG109_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS109_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS109_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006d00c)
#define HWIO_TLMM_GPIO_INTR_STATUS109_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS109_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS109_ADDR, HWIO_TLMM_GPIO_INTR_STATUS109_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS109_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS109_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS109_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS109_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS109_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS109_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS109_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS109_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS109_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS109_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0006d010)
#define HWIO_TLMM_GPIO_ID_STATUS109_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0006d010)
#define HWIO_TLMM_GPIO_ID_STATUS109_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS109_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS109_ADDR, HWIO_TLMM_GPIO_ID_STATUS109_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS109_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS109_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS109_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS109_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG110_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0006e000)
#define HWIO_TLMM_GPIO_CFG110_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0006e000)
#define HWIO_TLMM_GPIO_CFG110_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG110_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG110_ADDR, HWIO_TLMM_GPIO_CFG110_RMSK)
#define HWIO_TLMM_GPIO_CFG110_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG110_ADDR, m)
#define HWIO_TLMM_GPIO_CFG110_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG110_ADDR,v)
#define HWIO_TLMM_GPIO_CFG110_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG110_ADDR,m,v,HWIO_TLMM_GPIO_CFG110_IN)
#define HWIO_TLMM_GPIO_CFG110_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG110_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG110_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG110_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG110_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG110_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG110_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG110_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG110_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG110_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT110_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0006e004)
#define HWIO_TLMM_GPIO_IN_OUT110_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0006e004)
#define HWIO_TLMM_GPIO_IN_OUT110_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT110_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT110_ADDR, HWIO_TLMM_GPIO_IN_OUT110_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT110_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT110_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT110_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT110_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT110_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT110_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT110_IN)
#define HWIO_TLMM_GPIO_IN_OUT110_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT110_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT110_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT110_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG110_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0006e008)
#define HWIO_TLMM_GPIO_INTR_CFG110_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0006e008)
#define HWIO_TLMM_GPIO_INTR_CFG110_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG110_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG110_ADDR, HWIO_TLMM_GPIO_INTR_CFG110_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG110_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG110_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG110_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG110_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG110_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG110_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG110_IN)
#define HWIO_TLMM_GPIO_INTR_CFG110_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG110_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG110_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG110_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG110_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS110_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS110_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006e00c)
#define HWIO_TLMM_GPIO_INTR_STATUS110_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS110_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS110_ADDR, HWIO_TLMM_GPIO_INTR_STATUS110_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS110_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS110_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS110_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS110_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS110_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS110_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS110_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS110_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS110_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS110_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0006e010)
#define HWIO_TLMM_GPIO_ID_STATUS110_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0006e010)
#define HWIO_TLMM_GPIO_ID_STATUS110_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS110_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS110_ADDR, HWIO_TLMM_GPIO_ID_STATUS110_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS110_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS110_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS110_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS110_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG111_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0006f000)
#define HWIO_TLMM_GPIO_CFG111_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0006f000)
#define HWIO_TLMM_GPIO_CFG111_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG111_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG111_ADDR, HWIO_TLMM_GPIO_CFG111_RMSK)
#define HWIO_TLMM_GPIO_CFG111_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG111_ADDR, m)
#define HWIO_TLMM_GPIO_CFG111_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG111_ADDR,v)
#define HWIO_TLMM_GPIO_CFG111_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG111_ADDR,m,v,HWIO_TLMM_GPIO_CFG111_IN)
#define HWIO_TLMM_GPIO_CFG111_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG111_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG111_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG111_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG111_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG111_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG111_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG111_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG111_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG111_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT111_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0006f004)
#define HWIO_TLMM_GPIO_IN_OUT111_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0006f004)
#define HWIO_TLMM_GPIO_IN_OUT111_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT111_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT111_ADDR, HWIO_TLMM_GPIO_IN_OUT111_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT111_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT111_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT111_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT111_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT111_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT111_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT111_IN)
#define HWIO_TLMM_GPIO_IN_OUT111_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT111_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT111_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT111_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG111_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x0006f008)
#define HWIO_TLMM_GPIO_INTR_CFG111_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x0006f008)
#define HWIO_TLMM_GPIO_INTR_CFG111_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG111_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG111_ADDR, HWIO_TLMM_GPIO_INTR_CFG111_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG111_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG111_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG111_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG111_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG111_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG111_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG111_IN)
#define HWIO_TLMM_GPIO_INTR_CFG111_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG111_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG111_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG111_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG111_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS111_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0006f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS111_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0006f00c)
#define HWIO_TLMM_GPIO_INTR_STATUS111_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS111_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS111_ADDR, HWIO_TLMM_GPIO_INTR_STATUS111_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS111_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS111_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS111_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS111_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS111_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS111_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS111_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS111_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS111_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS111_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0006f010)
#define HWIO_TLMM_GPIO_ID_STATUS111_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0006f010)
#define HWIO_TLMM_GPIO_ID_STATUS111_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS111_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS111_ADDR, HWIO_TLMM_GPIO_ID_STATUS111_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS111_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS111_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS111_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS111_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG112_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00070000)
#define HWIO_TLMM_GPIO_CFG112_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00070000)
#define HWIO_TLMM_GPIO_CFG112_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG112_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG112_ADDR, HWIO_TLMM_GPIO_CFG112_RMSK)
#define HWIO_TLMM_GPIO_CFG112_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG112_ADDR, m)
#define HWIO_TLMM_GPIO_CFG112_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG112_ADDR,v)
#define HWIO_TLMM_GPIO_CFG112_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG112_ADDR,m,v,HWIO_TLMM_GPIO_CFG112_IN)
#define HWIO_TLMM_GPIO_CFG112_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG112_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG112_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG112_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG112_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG112_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG112_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG112_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG112_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG112_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT112_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00070004)
#define HWIO_TLMM_GPIO_IN_OUT112_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00070004)
#define HWIO_TLMM_GPIO_IN_OUT112_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT112_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT112_ADDR, HWIO_TLMM_GPIO_IN_OUT112_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT112_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT112_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT112_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT112_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT112_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT112_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT112_IN)
#define HWIO_TLMM_GPIO_IN_OUT112_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT112_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT112_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT112_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG112_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00070008)
#define HWIO_TLMM_GPIO_INTR_CFG112_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00070008)
#define HWIO_TLMM_GPIO_INTR_CFG112_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG112_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG112_ADDR, HWIO_TLMM_GPIO_INTR_CFG112_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG112_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG112_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG112_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG112_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG112_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG112_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG112_IN)
#define HWIO_TLMM_GPIO_INTR_CFG112_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG112_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG112_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG112_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG112_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS112_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0007000c)
#define HWIO_TLMM_GPIO_INTR_STATUS112_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0007000c)
#define HWIO_TLMM_GPIO_INTR_STATUS112_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS112_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS112_ADDR, HWIO_TLMM_GPIO_INTR_STATUS112_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS112_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS112_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS112_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS112_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS112_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS112_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS112_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS112_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS112_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS112_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00070010)
#define HWIO_TLMM_GPIO_ID_STATUS112_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00070010)
#define HWIO_TLMM_GPIO_ID_STATUS112_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS112_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS112_ADDR, HWIO_TLMM_GPIO_ID_STATUS112_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS112_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS112_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS112_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS112_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_GPIO_CFG113_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x00071000)
#define HWIO_TLMM_GPIO_CFG113_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x00071000)
#define HWIO_TLMM_GPIO_CFG113_RMSK                                              0x7ff
#define HWIO_TLMM_GPIO_CFG113_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_CFG113_ADDR, HWIO_TLMM_GPIO_CFG113_RMSK)
#define HWIO_TLMM_GPIO_CFG113_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_CFG113_ADDR, m)
#define HWIO_TLMM_GPIO_CFG113_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_CFG113_ADDR,v)
#define HWIO_TLMM_GPIO_CFG113_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_CFG113_ADDR,m,v,HWIO_TLMM_GPIO_CFG113_IN)
#define HWIO_TLMM_GPIO_CFG113_GPIO_HIHYS_EN_BMSK                                0x400
#define HWIO_TLMM_GPIO_CFG113_GPIO_HIHYS_EN_SHFT                                  0xa
#define HWIO_TLMM_GPIO_CFG113_GPIO_OE_BMSK                                      0x200
#define HWIO_TLMM_GPIO_CFG113_GPIO_OE_SHFT                                        0x9
#define HWIO_TLMM_GPIO_CFG113_DRV_STRENGTH_BMSK                                 0x1c0
#define HWIO_TLMM_GPIO_CFG113_DRV_STRENGTH_SHFT                                   0x6
#define HWIO_TLMM_GPIO_CFG113_FUNC_SEL_BMSK                                      0x3c
#define HWIO_TLMM_GPIO_CFG113_FUNC_SEL_SHFT                                       0x2
#define HWIO_TLMM_GPIO_CFG113_GPIO_PULL_BMSK                                      0x3
#define HWIO_TLMM_GPIO_CFG113_GPIO_PULL_SHFT                                      0x0

#define HWIO_TLMM_GPIO_IN_OUT113_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x00071004)
#define HWIO_TLMM_GPIO_IN_OUT113_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x00071004)
#define HWIO_TLMM_GPIO_IN_OUT113_RMSK                                             0x3
#define HWIO_TLMM_GPIO_IN_OUT113_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT113_ADDR, HWIO_TLMM_GPIO_IN_OUT113_RMSK)
#define HWIO_TLMM_GPIO_IN_OUT113_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_IN_OUT113_ADDR, m)
#define HWIO_TLMM_GPIO_IN_OUT113_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_IN_OUT113_ADDR,v)
#define HWIO_TLMM_GPIO_IN_OUT113_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_IN_OUT113_ADDR,m,v,HWIO_TLMM_GPIO_IN_OUT113_IN)
#define HWIO_TLMM_GPIO_IN_OUT113_GPIO_OUT_BMSK                                    0x2
#define HWIO_TLMM_GPIO_IN_OUT113_GPIO_OUT_SHFT                                    0x1
#define HWIO_TLMM_GPIO_IN_OUT113_GPIO_IN_BMSK                                     0x1
#define HWIO_TLMM_GPIO_IN_OUT113_GPIO_IN_SHFT                                     0x0

#define HWIO_TLMM_GPIO_INTR_CFG113_ADDR                                    (TLMM_SOUTH_REG_BASE      + 0x00071008)
#define HWIO_TLMM_GPIO_INTR_CFG113_OFFS                                    (TLMM_SOUTH_REG_BASE_OFFS + 0x00071008)
#define HWIO_TLMM_GPIO_INTR_CFG113_RMSK                                         0x1ff
#define HWIO_TLMM_GPIO_INTR_CFG113_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG113_ADDR, HWIO_TLMM_GPIO_INTR_CFG113_RMSK)
#define HWIO_TLMM_GPIO_INTR_CFG113_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_CFG113_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_CFG113_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_CFG113_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_CFG113_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_CFG113_ADDR,m,v,HWIO_TLMM_GPIO_INTR_CFG113_IN)
#define HWIO_TLMM_GPIO_INTR_CFG113_DIR_CONN_EN_BMSK                             0x100
#define HWIO_TLMM_GPIO_INTR_CFG113_DIR_CONN_EN_SHFT                               0x8
#define HWIO_TLMM_GPIO_INTR_CFG113_TARGET_PROC_BMSK                              0xe0
#define HWIO_TLMM_GPIO_INTR_CFG113_TARGET_PROC_SHFT                               0x5
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_RAW_STATUS_EN_BMSK                       0x10
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_RAW_STATUS_EN_SHFT                        0x4
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_DECT_CTL_BMSK                             0xc
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_DECT_CTL_SHFT                             0x2
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_POL_CTL_BMSK                              0x2
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_POL_CTL_SHFT                              0x1
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_ENABLE_BMSK                               0x1
#define HWIO_TLMM_GPIO_INTR_CFG113_INTR_ENABLE_SHFT                               0x0

#define HWIO_TLMM_GPIO_INTR_STATUS113_ADDR                                 (TLMM_SOUTH_REG_BASE      + 0x0007100c)
#define HWIO_TLMM_GPIO_INTR_STATUS113_OFFS                                 (TLMM_SOUTH_REG_BASE_OFFS + 0x0007100c)
#define HWIO_TLMM_GPIO_INTR_STATUS113_RMSK                                        0x1
#define HWIO_TLMM_GPIO_INTR_STATUS113_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS113_ADDR, HWIO_TLMM_GPIO_INTR_STATUS113_RMSK)
#define HWIO_TLMM_GPIO_INTR_STATUS113_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_INTR_STATUS113_ADDR, m)
#define HWIO_TLMM_GPIO_INTR_STATUS113_OUT(v)      \
        out_dword(HWIO_TLMM_GPIO_INTR_STATUS113_ADDR,v)
#define HWIO_TLMM_GPIO_INTR_STATUS113_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_GPIO_INTR_STATUS113_ADDR,m,v,HWIO_TLMM_GPIO_INTR_STATUS113_IN)
#define HWIO_TLMM_GPIO_INTR_STATUS113_INTR_STATUS_BMSK                            0x1
#define HWIO_TLMM_GPIO_INTR_STATUS113_INTR_STATUS_SHFT                            0x0

#define HWIO_TLMM_GPIO_ID_STATUS113_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00071010)
#define HWIO_TLMM_GPIO_ID_STATUS113_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00071010)
#define HWIO_TLMM_GPIO_ID_STATUS113_RMSK                                          0x1
#define HWIO_TLMM_GPIO_ID_STATUS113_IN          \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS113_ADDR, HWIO_TLMM_GPIO_ID_STATUS113_RMSK)
#define HWIO_TLMM_GPIO_ID_STATUS113_INM(m)      \
        in_dword_masked(HWIO_TLMM_GPIO_ID_STATUS113_ADDR, m)
#define HWIO_TLMM_GPIO_ID_STATUS113_GPIO_ID_STATUS_BMSK                           0x1
#define HWIO_TLMM_GPIO_ID_STATUS113_GPIO_ID_STATUS_SHFT                           0x0

#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_ADDR                           (TLMM_SOUTH_REG_BASE      + 0x00096000)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_OFFS                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00096000)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_RMSK                           0xffffffff
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_IN          \
        in_dword_masked(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_ADDR, HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_RMSK)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_INM(m)      \
        in_dword_masked(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_ADDR, m)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_OUT(v)      \
        out_dword(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_ADDR,v)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_ADDR,m,v,HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_IN)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_90_BMSK                   0x80000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_90_SHFT                         0x1f
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_87_BMSK                   0x40000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_87_SHFT                         0x1e
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_86_BMSK                   0x20000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_86_SHFT                         0x1d
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_85_BMSK                   0x10000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_85_SHFT                         0x1c
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_84_BMSK                    0x8000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_84_SHFT                         0x1b
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_83_BMSK                    0x4000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_83_SHFT                         0x1a
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_65_BMSK                    0x2000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_65_SHFT                         0x19
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_64_BMSK                    0x1000000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_64_SHFT                         0x18
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_58_BMSK                     0x800000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_58_SHFT                         0x17
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_56_BMSK                     0x400000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_56_SHFT                         0x16
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_55_BMSK                     0x200000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_55_SHFT                         0x15
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_52_BMSK                     0x100000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_52_SHFT                         0x14
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_51_BMSK                      0x80000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_51_SHFT                         0x13
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_50_BMSK                      0x40000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_50_SHFT                         0x12
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_49_BMSK                      0x20000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_49_SHFT                         0x11
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_48_BMSK                      0x10000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_48_SHFT                         0x10
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_47_BMSK                       0x8000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_47_SHFT                          0xf
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_46_BMSK                       0x4000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_46_SHFT                          0xe
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_45_BMSK                       0x2000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_45_SHFT                          0xd
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_44_BMSK                       0x1000
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_44_SHFT                          0xc
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_43_BMSK                        0x800
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_43_SHFT                          0xb
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_42_BMSK                        0x400
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_42_SHFT                          0xa
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_41_BMSK                        0x200
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_41_SHFT                          0x9
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_40_BMSK                        0x100
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_40_SHFT                          0x8
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_21_BMSK                         0x80
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_21_SHFT                          0x7
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_6_BMSK                          0x40
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_6_SHFT                           0x6
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_5_BMSK                          0x20
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_5_SHFT                           0x5
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_2_BMSK                          0x10
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_2_SHFT                           0x4
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_1_BMSK                           0x8
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_GPIO_1_SHFT                           0x3
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_SSC_31_BMSK                           0x4
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_SSC_31_SHFT                           0x2
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_SSC_22_BMSK                           0x2
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_SSC_22_SHFT                           0x1
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_SSC_20_BMSK                           0x1
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_0_SSC_20_SHFT                           0x0

#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_ADDR                           (TLMM_SOUTH_REG_BASE      + 0x00096004)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_OFFS                           (TLMM_SOUTH_REG_BASE_OFFS + 0x00096004)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_RMSK                                0x1ff
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_IN          \
        in_dword_masked(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_ADDR, HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_RMSK)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_INM(m)      \
        in_dword_masked(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_ADDR, m)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_OUT(v)      \
        out_dword(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_ADDR,v)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_ADDR,m,v,HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_IN)
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_113_BMSK                       0x100
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_113_SHFT                         0x8
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_111_BMSK                        0x80
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_111_SHFT                         0x7
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_109_BMSK                        0x40
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_109_SHFT                         0x6
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_107_BMSK                        0x20
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_107_SHFT                         0x5
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_105_BMSK                        0x10
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_105_SHFT                         0x4
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_103_BMSK                         0x8
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_103_SHFT                         0x3
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_101_BMSK                         0x4
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_101_SHFT                         0x2
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_98_BMSK                          0x2
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_98_SHFT                          0x1
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_91_BMSK                          0x1
#define HWIO_TLMM_SOUTH_MPM_WAKEUP_INT_EN_1_GPIO_91_SHFT                          0x0

#define HWIO_TLMM_SOUTH_CLK_GATE_EN_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x00097000)
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x00097000)
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_RMSK                                          0x7
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_IN          \
        in_dword_masked(HWIO_TLMM_SOUTH_CLK_GATE_EN_ADDR, HWIO_TLMM_SOUTH_CLK_GATE_EN_RMSK)
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_INM(m)      \
        in_dword_masked(HWIO_TLMM_SOUTH_CLK_GATE_EN_ADDR, m)
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_OUT(v)      \
        out_dword(HWIO_TLMM_SOUTH_CLK_GATE_EN_ADDR,v)
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_CLK_GATE_EN_ADDR,m,v,HWIO_TLMM_SOUTH_CLK_GATE_EN_IN)
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_AHB_HCLK_EN_BMSK                              0x4
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_AHB_HCLK_EN_SHFT                              0x2
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_SUMMARY_INTR_EN_BMSK                          0x2
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_SUMMARY_INTR_EN_SHFT                          0x1
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_CRIF_READ_EN_BMSK                             0x1
#define HWIO_TLMM_SOUTH_CLK_GATE_EN_CRIF_READ_EN_SHFT                             0x0

#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_ADDR                               (TLMM_SOUTH_REG_BASE      + 0x00097004)
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_OFFS                               (TLMM_SOUTH_REG_BASE_OFFS + 0x00097004)
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_RMSK                                      0x1
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_IN          \
        in_dword_masked(HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_ADDR, HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_RMSK)
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_INM(m)      \
        in_dword_masked(HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_ADDR, m)
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_OUT(v)      \
        out_dword(HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_ADDR,v)
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_ADDR,m,v,HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_IN)
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_IE_CTRL_DISABLE_BMSK                      0x1
#define HWIO_TLMM_SOUTH_IE_CTRL_DISABLE_IE_CTRL_DISABLE_SHFT                      0x0

#define HWIO_TLMM_DBG_BUS_OUT_SEL_ADDR                                     (TLMM_SOUTH_REG_BASE      + 0x00098008)
#define HWIO_TLMM_DBG_BUS_OUT_SEL_OFFS                                     (TLMM_SOUTH_REG_BASE_OFFS + 0x00098008)
#define HWIO_TLMM_DBG_BUS_OUT_SEL_RMSK                                            0x3
#define HWIO_TLMM_DBG_BUS_OUT_SEL_IN          \
        in_dword_masked(HWIO_TLMM_DBG_BUS_OUT_SEL_ADDR, HWIO_TLMM_DBG_BUS_OUT_SEL_RMSK)
#define HWIO_TLMM_DBG_BUS_OUT_SEL_INM(m)      \
        in_dword_masked(HWIO_TLMM_DBG_BUS_OUT_SEL_ADDR, m)
#define HWIO_TLMM_DBG_BUS_OUT_SEL_OUT(v)      \
        out_dword(HWIO_TLMM_DBG_BUS_OUT_SEL_ADDR,v)
#define HWIO_TLMM_DBG_BUS_OUT_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_DBG_BUS_OUT_SEL_ADDR,m,v,HWIO_TLMM_DBG_BUS_OUT_SEL_IN)
#define HWIO_TLMM_DBG_BUS_OUT_SEL_COPY_SEL_BMSK                                   0x3
#define HWIO_TLMM_DBG_BUS_OUT_SEL_COPY_SEL_SHFT                                   0x0

#define HWIO_TLMM_CHIP_MODE_ADDR                                           (TLMM_SOUTH_REG_BASE      + 0x0009800c)
#define HWIO_TLMM_CHIP_MODE_OFFS                                           (TLMM_SOUTH_REG_BASE_OFFS + 0x0009800c)
#define HWIO_TLMM_CHIP_MODE_RMSK                                                  0x3
#define HWIO_TLMM_CHIP_MODE_IN          \
        in_dword_masked(HWIO_TLMM_CHIP_MODE_ADDR, HWIO_TLMM_CHIP_MODE_RMSK)
#define HWIO_TLMM_CHIP_MODE_INM(m)      \
        in_dword_masked(HWIO_TLMM_CHIP_MODE_ADDR, m)
#define HWIO_TLMM_CHIP_MODE_MODE1_PIN_BMSK                                        0x2
#define HWIO_TLMM_CHIP_MODE_MODE1_PIN_SHFT                                        0x1
#define HWIO_TLMM_CHIP_MODE_MODE0_PIN_BMSK                                        0x1
#define HWIO_TLMM_CHIP_MODE_MODE0_PIN_SHFT                                        0x0

#define HWIO_TLMM_HW_REVISION_NUMBER_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x00098010)
#define HWIO_TLMM_HW_REVISION_NUMBER_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x00098010)
#define HWIO_TLMM_HW_REVISION_NUMBER_RMSK                                  0xffffffff
#define HWIO_TLMM_HW_REVISION_NUMBER_IN          \
        in_dword_masked(HWIO_TLMM_HW_REVISION_NUMBER_ADDR, HWIO_TLMM_HW_REVISION_NUMBER_RMSK)
#define HWIO_TLMM_HW_REVISION_NUMBER_INM(m)      \
        in_dword_masked(HWIO_TLMM_HW_REVISION_NUMBER_ADDR, m)
#define HWIO_TLMM_HW_REVISION_NUMBER_VERSION_ID_BMSK                       0xf0000000
#define HWIO_TLMM_HW_REVISION_NUMBER_VERSION_ID_SHFT                             0x1c
#define HWIO_TLMM_HW_REVISION_NUMBER_PRODUCT_DEVICE_ID_BMSK                 0xffff000
#define HWIO_TLMM_HW_REVISION_NUMBER_PRODUCT_DEVICE_ID_SHFT                       0xc
#define HWIO_TLMM_HW_REVISION_NUMBER_QUALCOMM_MFG_ID_BMSK                       0xffe
#define HWIO_TLMM_HW_REVISION_NUMBER_QUALCOMM_MFG_ID_SHFT                         0x1
#define HWIO_TLMM_HW_REVISION_NUMBER_START_BIT_BMSK                               0x1
#define HWIO_TLMM_HW_REVISION_NUMBER_START_BIT_SHFT                               0x0

#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_ADDR                               (TLMM_SOUTH_REG_BASE      + 0x00098014)
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_OFFS                               (TLMM_SOUTH_REG_BASE_OFFS + 0x00098014)
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_RMSK                                      0x1
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_IN          \
        in_dword_masked(HWIO_TLMM_PERIPH_CHAR_TEST_MODE_ADDR, HWIO_TLMM_PERIPH_CHAR_TEST_MODE_RMSK)
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_INM(m)      \
        in_dword_masked(HWIO_TLMM_PERIPH_CHAR_TEST_MODE_ADDR, m)
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_OUT(v)      \
        out_dword(HWIO_TLMM_PERIPH_CHAR_TEST_MODE_ADDR,v)
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_PERIPH_CHAR_TEST_MODE_ADDR,m,v,HWIO_TLMM_PERIPH_CHAR_TEST_MODE_IN)
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_CHAR_TEST_MODE_BMSK                       0x1
#define HWIO_TLMM_PERIPH_CHAR_TEST_MODE_CHAR_TEST_MODE_SHFT                       0x0

#define HWIO_TLMM_RFFE_CTL_ADDR                                            (TLMM_SOUTH_REG_BASE      + 0x00099000)
#define HWIO_TLMM_RFFE_CTL_OFFS                                            (TLMM_SOUTH_REG_BASE_OFFS + 0x00099000)
#define HWIO_TLMM_RFFE_CTL_RMSK                                                0x1dff
#define HWIO_TLMM_RFFE_CTL_IN          \
        in_dword_masked(HWIO_TLMM_RFFE_CTL_ADDR, HWIO_TLMM_RFFE_CTL_RMSK)
#define HWIO_TLMM_RFFE_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_RFFE_CTL_ADDR, m)
#define HWIO_TLMM_RFFE_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_RFFE_CTL_ADDR,v)
#define HWIO_TLMM_RFFE_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_RFFE_CTL_ADDR,m,v,HWIO_TLMM_RFFE_CTL_IN)
#define HWIO_TLMM_RFFE_CTL_RFFE6_DATA_SR_CTL_EN_BMSK                           0x1000
#define HWIO_TLMM_RFFE_CTL_RFFE6_DATA_SR_CTL_EN_SHFT                              0xc
#define HWIO_TLMM_RFFE_CTL_RFFE6_CLK_SR_CTL_EN_BMSK                             0x800
#define HWIO_TLMM_RFFE_CTL_RFFE6_CLK_SR_CTL_EN_SHFT                               0xb
#define HWIO_TLMM_RFFE_CTL_RFFE5_DATA_SR_CTL_EN_BMSK                            0x400
#define HWIO_TLMM_RFFE_CTL_RFFE5_DATA_SR_CTL_EN_SHFT                              0xa
#define HWIO_TLMM_RFFE_CTL_RFFE5_CLK_SR_CTL_EN_BMSK                             0x100
#define HWIO_TLMM_RFFE_CTL_RFFE5_CLK_SR_CTL_EN_SHFT                               0x8
#define HWIO_TLMM_RFFE_CTL_RFFE4_DATA_SR_CTL_EN_BMSK                             0x80
#define HWIO_TLMM_RFFE_CTL_RFFE4_DATA_SR_CTL_EN_SHFT                              0x7
#define HWIO_TLMM_RFFE_CTL_RFFE4_CLK_SR_CTL_EN_BMSK                              0x40
#define HWIO_TLMM_RFFE_CTL_RFFE4_CLK_SR_CTL_EN_SHFT                               0x6
#define HWIO_TLMM_RFFE_CTL_RFFE3_DATA_SR_CTL_EN_BMSK                             0x20
#define HWIO_TLMM_RFFE_CTL_RFFE3_DATA_SR_CTL_EN_SHFT                              0x5
#define HWIO_TLMM_RFFE_CTL_RFFE3_CLK_SR_CTL_EN_BMSK                              0x10
#define HWIO_TLMM_RFFE_CTL_RFFE3_CLK_SR_CTL_EN_SHFT                               0x4
#define HWIO_TLMM_RFFE_CTL_RFFE2_DATA_SR_CTL_EN_BMSK                              0x8
#define HWIO_TLMM_RFFE_CTL_RFFE2_DATA_SR_CTL_EN_SHFT                              0x3
#define HWIO_TLMM_RFFE_CTL_RFFE2_CLK_SR_CTL_EN_BMSK                               0x4
#define HWIO_TLMM_RFFE_CTL_RFFE2_CLK_SR_CTL_EN_SHFT                               0x2
#define HWIO_TLMM_RFFE_CTL_RFFE1_DATA_SR_CTL_EN_BMSK                              0x2
#define HWIO_TLMM_RFFE_CTL_RFFE1_DATA_SR_CTL_EN_SHFT                              0x1
#define HWIO_TLMM_RFFE_CTL_RFFE1_CLK_SR_CTL_EN_BMSK                               0x1
#define HWIO_TLMM_RFFE_CTL_RFFE1_CLK_SR_CTL_EN_SHFT                               0x0

#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR                                  (TLMM_SOUTH_REG_BASE      + 0x0009a000)
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_OFFS                                  (TLMM_SOUTH_REG_BASE_OFFS + 0x0009a000)
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_RMSK                                    0xffffff
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_IN          \
        in_dword_masked(HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR, HWIO_TLMM_PMIC_HDRV_PULL_CTL_RMSK)
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR, m)
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR,v)
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR,m,v,HWIO_TLMM_PMIC_HDRV_PULL_CTL_IN)
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_HIHYS_EN_DATA_BMSK            0x800000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_HIHYS_EN_DATA_SHFT                0x17
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_HIHYS_EN_CLK_BMSK             0x400000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_HIHYS_EN_CLK_SHFT                 0x16
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_DATA_SR_CTL_BMSK              0x300000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_DATA_SR_CTL_SHFT                  0x14
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_CLK_SR_CTL_BMSK                0xc0000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_CLK_SR_CTL_SHFT                   0x12
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_DATA_PULL_BMSK                  0xc000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_DATA_PULL_SHFT                     0xe
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_CLK_PULL_BMSK                   0x3000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_CLK_PULL_SHFT                      0xc
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PSHOLD_HDRV_BMSK                           0xe00
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PSHOLD_HDRV_SHFT                             0x9
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_CXO_EN_HDRV_BMSK                           0x1c0
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_CXO_EN_HDRV_SHFT                             0x6
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_DATA_HDRV_BMSK                    0x38
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_DATA_HDRV_SHFT                     0x3
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_CLK_HDRV_BMSK                      0x7
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_PMIC_SPMI_CLK_HDRV_SHFT                      0x0

#define HWIO_TLMM_CCI_GS_I2C_CTL_ADDR                                      (TLMM_SOUTH_REG_BASE      + 0x0009b000)
#define HWIO_TLMM_CCI_GS_I2C_CTL_OFFS                                      (TLMM_SOUTH_REG_BASE_OFFS + 0x0009b000)
#define HWIO_TLMM_CCI_GS_I2C_CTL_RMSK                                             0xf
#define HWIO_TLMM_CCI_GS_I2C_CTL_IN          \
        in_dword_masked(HWIO_TLMM_CCI_GS_I2C_CTL_ADDR, HWIO_TLMM_CCI_GS_I2C_CTL_RMSK)
#define HWIO_TLMM_CCI_GS_I2C_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_CCI_GS_I2C_CTL_ADDR, m)
#define HWIO_TLMM_CCI_GS_I2C_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_CCI_GS_I2C_CTL_ADDR,v)
#define HWIO_TLMM_CCI_GS_I2C_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_CCI_GS_I2C_CTL_ADDR,m,v,HWIO_TLMM_CCI_GS_I2C_CTL_IN)
#define HWIO_TLMM_CCI_GS_I2C_CTL_CCI1_MODE_BMSK                                   0xc
#define HWIO_TLMM_CCI_GS_I2C_CTL_CCI1_MODE_SHFT                                   0x2
#define HWIO_TLMM_CCI_GS_I2C_CTL_CCI0_MODE_BMSK                                   0x3
#define HWIO_TLMM_CCI_GS_I2C_CTL_CCI0_MODE_SHFT                                   0x0

#define HWIO_TLMM_SOUTH_SPARE_ADDR                                         (TLMM_SOUTH_REG_BASE      + 0x0009c000)
#define HWIO_TLMM_SOUTH_SPARE_OFFS                                         (TLMM_SOUTH_REG_BASE_OFFS + 0x0009c000)
#define HWIO_TLMM_SOUTH_SPARE_RMSK                                         0xffffffff
#define HWIO_TLMM_SOUTH_SPARE_IN          \
        in_dword_masked(HWIO_TLMM_SOUTH_SPARE_ADDR, HWIO_TLMM_SOUTH_SPARE_RMSK)
#define HWIO_TLMM_SOUTH_SPARE_INM(m)      \
        in_dword_masked(HWIO_TLMM_SOUTH_SPARE_ADDR, m)
#define HWIO_TLMM_SOUTH_SPARE_OUT(v)      \
        out_dword(HWIO_TLMM_SOUTH_SPARE_ADDR,v)
#define HWIO_TLMM_SOUTH_SPARE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_SPARE_ADDR,m,v,HWIO_TLMM_SOUTH_SPARE_IN)
#define HWIO_TLMM_SOUTH_SPARE_SPARE_BMSK                                   0xffffff00
#define HWIO_TLMM_SOUTH_SPARE_SPARE_SHFT                                          0x8
#define HWIO_TLMM_SOUTH_SPARE_MISC_BMSK                                          0xff
#define HWIO_TLMM_SOUTH_SPARE_MISC_SHFT                                           0x0

#define HWIO_TLMM_RESIN_N_HIHYS_CTL_ADDR                                   (TLMM_SOUTH_REG_BASE      + 0x0009d000)
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_OFFS                                   (TLMM_SOUTH_REG_BASE_OFFS + 0x0009d000)
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_RMSK                                          0x1
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_IN          \
        in_dword_masked(HWIO_TLMM_RESIN_N_HIHYS_CTL_ADDR, HWIO_TLMM_RESIN_N_HIHYS_CTL_RMSK)
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_INM(m)      \
        in_dword_masked(HWIO_TLMM_RESIN_N_HIHYS_CTL_ADDR, m)
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_OUT(v)      \
        out_dword(HWIO_TLMM_RESIN_N_HIHYS_CTL_ADDR,v)
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TLMM_RESIN_N_HIHYS_CTL_ADDR,m,v,HWIO_TLMM_RESIN_N_HIHYS_CTL_IN)
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_RESIN_N_HIHYS_CTL_BMSK                        0x1
#define HWIO_TLMM_RESIN_N_HIHYS_CTL_RESIN_N_HIHYS_CTL_SHFT                        0x0

#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n)                 (TLMM_SOUTH_REG_BASE      + 0x000a0000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_OFFS(n)                 (TLMM_SOUTH_REG_BASE_OFFS + 0x000a0000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_RMSK                         0x1ff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_MAXn                             1
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_INI(n)        \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n), HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_RMSK)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n), mask)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n),val)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_ADDR(n),mask,val,HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_INI(n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_POLARITY_BMSK                0x100
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_POLARITY_SHFT                  0x8
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_GPIO_SEL_BMSK                 0xff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_SENSORS_GPIO_SEL_SHFT                  0x0

#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n)                 (TLMM_SOUTH_REG_BASE      + 0x000a1000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_OFFS(n)                 (TLMM_SOUTH_REG_BASE_OFFS + 0x000a1000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_RMSK                         0x1ff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_MAXn                             5
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_INI(n)        \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n), HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_RMSK)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n), mask)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_OUTI(n,val)    \
        out_dword(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n),val)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_ADDR(n),mask,val,HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_INI(n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_POLARITY_BMSK                0x100
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_POLARITY_SHFT                  0x8
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_GPIO_SEL_BMSK                 0xff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_LPA_DSP_GPIO_SEL_SHFT                  0x0

#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n)                     (TLMM_SOUTH_REG_BASE      + 0x000a2000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_OFFS(n)                     (TLMM_SOUTH_REG_BASE_OFFS + 0x000a2000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_RMSK                             0x1ff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_MAXn                                 0
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_INI(n)        \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n), HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_RMSK)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n), mask)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_OUTI(n,val)    \
        out_dword(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n),val)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_ADDR(n),mask,val,HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_INI(n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_POLARITY_BMSK                    0x100
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_POLARITY_SHFT                      0x8
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_GPIO_SEL_BMSK                     0xff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_RPM_GPIO_SEL_SHFT                      0x0

#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n)                    (TLMM_SOUTH_REG_BASE      + 0x000a3000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_OFFS(n)                    (TLMM_SOUTH_REG_BASE_OFFS + 0x000a3000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_RMSK                            0x1ff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_MAXn                                7
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_INI(n)        \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n), HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_RMSK)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n), mask)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n),val)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_ADDR(n),mask,val,HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_INI(n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_POLARITY_BMSK                   0x100
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_POLARITY_SHFT                     0x8
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_GPIO_SEL_BMSK                    0xff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_HMSS_GPIO_SEL_SHFT                     0x0

#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n)                     (TLMM_SOUTH_REG_BASE      + 0x000a4000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_OFFS(n)                     (TLMM_SOUTH_REG_BASE_OFFS + 0x000a4000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_RMSK                             0x1ff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_MAXn                                 1
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_INI(n)        \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n), HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_RMSK)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n), mask)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_OUTI(n,val)    \
        out_dword(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n),val)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_ADDR(n),mask,val,HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_INI(n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_POLARITY_BMSK                    0x100
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_POLARITY_SHFT                      0x8
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_GPIO_SEL_BMSK                     0xff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_GSS_GPIO_SEL_SHFT                      0x0

#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n)                    (TLMM_SOUTH_REG_BASE      + 0x000a5000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_OFFS(n)                    (TLMM_SOUTH_REG_BASE_OFFS + 0x000a5000 + 0x4 * (n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_RMSK                            0x1ff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_MAXn                                1
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_INI(n)        \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n), HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_RMSK)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_INMI(n,mask)    \
        in_dword_masked(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n), mask)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_OUTI(n,val)    \
        out_dword(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n),val)
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_ADDR(n),mask,val,HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_INI(n))
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_POLARITY_BMSK                   0x100
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_POLARITY_SHFT                     0x8
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_GPIO_SEL_BMSK                    0xff
#define HWIO_TLMM_SOUTH_DIR_CONN_INTRn_CFG_CDSP_GPIO_SEL_SHFT                     0x0


#endif /* __HALTLMMTILEHWIO_H__ */
