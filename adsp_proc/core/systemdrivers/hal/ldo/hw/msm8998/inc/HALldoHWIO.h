#ifndef __HALLDOHWIO_H__
#define __HALLDOHWIO_H__
/*
===========================================================================
*/
/**
  @file HALldoHWIO.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    MSM8998 (Nazgul) [nazgul_v1.0_p3q3r32]
 
  This file contains HWIO register definitions for the following modules:
    LPASS_QDSP6V60SS_PUB

  'Include' filters applied: 
  'Exclude' filters applied: RESERVED DUMMY RESERVED[LPASS_QDSP6V60SS_PUB] 
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

  $Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/ldo/hw/msm8998/inc/HALldoHWIO.h#1 $
  $DateTime: 2020/02/10 01:57:30 $
  $Author: pwbldsvc $

  ===========================================================================
*/

/*
 * HWIO base definitions
 */
extern uint32                  HAL_ldo_nHWIOBaseLPASS;
#define LPASS_BASE             HAL_ldo_nHWIOBaseLPASS
#define LPASS_BASE_PHYS        0x17000000
#define LPASS_BASE_SIZE        0x00400000

/*----------------------------------------------------------------------------
 * MODULE: LPASS_QDSP6V60SS_PUB
 *--------------------------------------------------------------------------*/

#define LPASS_QDSP6V60SS_PUB_REG_BASE                                                 (LPASS_BASE      + 0x00300000)
#define LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS                                            0x00300000

#define HWIO_LPASS_QDSP6SS_VERSION_ADDR                                               (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000000)
#define HWIO_LPASS_QDSP6SS_VERSION_OFFS                                               (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000000)
#define HWIO_LPASS_QDSP6SS_VERSION_RMSK                                               0xffffffff
#define HWIO_LPASS_QDSP6SS_VERSION_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_VERSION_ADDR, HWIO_LPASS_QDSP6SS_VERSION_RMSK)
#define HWIO_LPASS_QDSP6SS_VERSION_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_VERSION_ADDR, m)
#define HWIO_LPASS_QDSP6SS_VERSION_MAJOR_BMSK                                         0xf0000000
#define HWIO_LPASS_QDSP6SS_VERSION_MAJOR_SHFT                                               0x1c
#define HWIO_LPASS_QDSP6SS_VERSION_MINOR_BMSK                                          0xfff0000
#define HWIO_LPASS_QDSP6SS_VERSION_MINOR_SHFT                                               0x10
#define HWIO_LPASS_QDSP6SS_VERSION_STEP_BMSK                                              0xffff
#define HWIO_LPASS_QDSP6SS_VERSION_STEP_SHFT                                                 0x0

#define HWIO_LPASS_QDSP6SS_CONFIG_ID_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000004)
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000004)
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_RMSK                                             0xfff1ffff
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CONFIG_ID_ADDR, HWIO_LPASS_QDSP6SS_CONFIG_ID_RMSK)
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CONFIG_ID_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_NUM_L2VIC_SRC_BMSK                               0xfff00000
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_NUM_L2VIC_SRC_SHFT                                     0x14
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_ZMEAS_PRESENT_BMSK                                  0x10000
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_ZMEAS_PRESENT_SHFT                                     0x10
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_PMIC_IF_PRESENT_BMSK                                 0x8000
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_PMIC_IF_PRESENT_SHFT                                    0xf
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_IN_SUBSYSTEM_BMSK                                    0x7000
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_IN_SUBSYSTEM_SHFT                                       0xc
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_LDO_PRESENT_BMSK                                      0x800
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_LDO_PRESENT_SHFT                                        0xb
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_BHS_PRESENT_BMSK                                      0x400
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_BHS_PRESENT_SHFT                                        0xa
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_PLL_VOTE_BMSK                                         0x200
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_PLL_VOTE_SHFT                                           0x9
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_PLL_PRESENT_BMSK                                      0x100
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_PLL_PRESENT_SHFT                                        0x8
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_CORE_TYPE_BMSK                                         0xf0
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_CORE_TYPE_SHFT                                          0x4
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_L2_SIZE_BMSK                                            0xf
#define HWIO_LPASS_QDSP6SS_CONFIG_ID_L2_SIZE_SHFT                                            0x0

#define HWIO_LPASS_QDSP6SS_RST_EVB_ADDR                                               (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000010)
#define HWIO_LPASS_QDSP6SS_RST_EVB_OFFS                                               (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000010)
#define HWIO_LPASS_QDSP6SS_RST_EVB_RMSK                                                0xffffff0
#define HWIO_LPASS_QDSP6SS_RST_EVB_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_RST_EVB_ADDR, HWIO_LPASS_QDSP6SS_RST_EVB_RMSK)
#define HWIO_LPASS_QDSP6SS_RST_EVB_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_RST_EVB_ADDR, m)
#define HWIO_LPASS_QDSP6SS_RST_EVB_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_RST_EVB_ADDR,v)
#define HWIO_LPASS_QDSP6SS_RST_EVB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_RST_EVB_ADDR,m,v,HWIO_LPASS_QDSP6SS_RST_EVB_IN)
#define HWIO_LPASS_QDSP6SS_RST_EVB_EVB_BMSK                                            0xffffff0
#define HWIO_LPASS_QDSP6SS_RST_EVB_EVB_SHFT                                                  0x4

#define HWIO_LPASS_QDSP6SS_RESET_ADDR                                                 (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000014)
#define HWIO_LPASS_QDSP6SS_RESET_OFFS                                                 (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000014)
#define HWIO_LPASS_QDSP6SS_RESET_RMSK                                                     0x7ff7
#define HWIO_LPASS_QDSP6SS_RESET_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_RESET_ADDR, HWIO_LPASS_QDSP6SS_RESET_RMSK)
#define HWIO_LPASS_QDSP6SS_RESET_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_RESET_ADDR, m)
#define HWIO_LPASS_QDSP6SS_RESET_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_RESET_ADDR,v)
#define HWIO_LPASS_QDSP6SS_RESET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_RESET_ADDR,m,v,HWIO_LPASS_QDSP6SS_RESET_IN)
#define HWIO_LPASS_QDSP6SS_RESET_CSI1_ARES_BMSK                                           0x4000
#define HWIO_LPASS_QDSP6SS_RESET_CSI1_ARES_SHFT                                              0xe
#define HWIO_LPASS_QDSP6SS_RESET_CSI0_ARES_BMSK                                           0x2000
#define HWIO_LPASS_QDSP6SS_RESET_CSI0_ARES_SHFT                                              0xd
#define HWIO_LPASS_QDSP6SS_RESET_CORE_ARCH_ARES_BMSK                                      0x1000
#define HWIO_LPASS_QDSP6SS_RESET_CORE_ARCH_ARES_SHFT                                         0xc
#define HWIO_LPASS_QDSP6SS_RESET_CORE_NONRET_ARES_BMSK                                     0x800
#define HWIO_LPASS_QDSP6SS_RESET_CORE_NONRET_ARES_SHFT                                       0xb
#define HWIO_LPASS_QDSP6SS_RESET_CORE_RET_ARES_BMSK                                        0x400
#define HWIO_LPASS_QDSP6SS_RESET_CORE_RET_ARES_SHFT                                          0xa
#define HWIO_LPASS_QDSP6SS_RESET_AXIM2_ARES_BMSK                                           0x200
#define HWIO_LPASS_QDSP6SS_RESET_AXIM2_ARES_SHFT                                             0x9
#define HWIO_LPASS_QDSP6SS_RESET_AXIS_ARES_BMSK                                            0x100
#define HWIO_LPASS_QDSP6SS_RESET_AXIS_ARES_SHFT                                              0x8
#define HWIO_LPASS_QDSP6SS_RESET_ATBM_ARES_BMSK                                             0x80
#define HWIO_LPASS_QDSP6SS_RESET_ATBM_ARES_SHFT                                              0x7
#define HWIO_LPASS_QDSP6SS_RESET_AHBM_ARES_BMSK                                             0x40
#define HWIO_LPASS_QDSP6SS_RESET_AHBM_ARES_SHFT                                              0x6
#define HWIO_LPASS_QDSP6SS_RESET_AXIM_ARES_BMSK                                             0x20
#define HWIO_LPASS_QDSP6SS_RESET_AXIM_ARES_SHFT                                              0x5
#define HWIO_LPASS_QDSP6SS_RESET_ETM_ISDB_ARES_BMSK                                         0x10
#define HWIO_LPASS_QDSP6SS_RESET_ETM_ISDB_ARES_SHFT                                          0x4
#define HWIO_LPASS_QDSP6SS_RESET_BUS_ARES_ENA_BMSK                                           0x4
#define HWIO_LPASS_QDSP6SS_RESET_BUS_ARES_ENA_SHFT                                           0x2
#define HWIO_LPASS_QDSP6SS_RESET_CORE_ARES_BMSK                                              0x2
#define HWIO_LPASS_QDSP6SS_RESET_CORE_ARES_SHFT                                              0x1
#define HWIO_LPASS_QDSP6SS_RESET_STOP_CORE_BMSK                                              0x1
#define HWIO_LPASS_QDSP6SS_RESET_STOP_CORE_SHFT                                              0x0

#define HWIO_LPASS_QDSP6SS_DBG_CFG_ADDR                                               (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000018)
#define HWIO_LPASS_QDSP6SS_DBG_CFG_OFFS                                               (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000018)
#define HWIO_LPASS_QDSP6SS_DBG_CFG_RMSK                                               0xffff0003
#define HWIO_LPASS_QDSP6SS_DBG_CFG_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DBG_CFG_ADDR, HWIO_LPASS_QDSP6SS_DBG_CFG_RMSK)
#define HWIO_LPASS_QDSP6SS_DBG_CFG_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DBG_CFG_ADDR, m)
#define HWIO_LPASS_QDSP6SS_DBG_CFG_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_DBG_CFG_ADDR,v)
#define HWIO_LPASS_QDSP6SS_DBG_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_DBG_CFG_ADDR,m,v,HWIO_LPASS_QDSP6SS_DBG_CFG_IN)
#define HWIO_LPASS_QDSP6SS_DBG_CFG_DBG_SW_REG_BMSK                                    0xff000000
#define HWIO_LPASS_QDSP6SS_DBG_CFG_DBG_SW_REG_SHFT                                          0x18
#define HWIO_LPASS_QDSP6SS_DBG_CFG_DBG_SPARE_BMSK                                       0xff0000
#define HWIO_LPASS_QDSP6SS_DBG_CFG_DBG_SPARE_SHFT                                           0x10
#define HWIO_LPASS_QDSP6SS_DBG_CFG_CTI_TIHS_ENA_BMSK                                         0x2
#define HWIO_LPASS_QDSP6SS_DBG_CFG_CTI_TIHS_ENA_SHFT                                         0x1
#define HWIO_LPASS_QDSP6SS_DBG_CFG_DBG_ARES_ENA_BMSK                                         0x1
#define HWIO_LPASS_QDSP6SS_DBG_CFG_DBG_ARES_ENA_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_RET_CFG_ADDR                                               (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000001c)
#define HWIO_LPASS_QDSP6SS_RET_CFG_OFFS                                               (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000001c)
#define HWIO_LPASS_QDSP6SS_RET_CFG_RMSK                                                      0x3
#define HWIO_LPASS_QDSP6SS_RET_CFG_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_RET_CFG_ADDR, HWIO_LPASS_QDSP6SS_RET_CFG_RMSK)
#define HWIO_LPASS_QDSP6SS_RET_CFG_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_RET_CFG_ADDR, m)
#define HWIO_LPASS_QDSP6SS_RET_CFG_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_RET_CFG_ADDR,v)
#define HWIO_LPASS_QDSP6SS_RET_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_RET_CFG_ADDR,m,v,HWIO_LPASS_QDSP6SS_RET_CFG_IN)
#define HWIO_LPASS_QDSP6SS_RET_CFG_ARCH_ARES_ENA_BMSK                                        0x2
#define HWIO_LPASS_QDSP6SS_RET_CFG_ARCH_ARES_ENA_SHFT                                        0x1
#define HWIO_LPASS_QDSP6SS_RET_CFG_RET_ARES_ENA_BMSK                                         0x1
#define HWIO_LPASS_QDSP6SS_RET_CFG_RET_ARES_ENA_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000020)
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000020)
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_RMSK                                                  0x30f
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_GFMUX_CTL_ADDR, HWIO_LPASS_QDSP6SS_GFMUX_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_GFMUX_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_GFMUX_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_GFMUX_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_GFMUX_CTL_IN)
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_IDLE_CORE_CLK_EN_BMSK                                 0x200
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_IDLE_CORE_CLK_EN_SHFT                                   0x9
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_SRC_SWITCH_CLK_OVR_BMSK                               0x100
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_SRC_SWITCH_CLK_OVR_SHFT                                 0x8
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_CLK_SRC_SEL_BMSK                                        0xc
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_CLK_SRC_SEL_SHFT                                        0x2
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_CLK_ENA_BMSK                                            0x2
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_CLK_ENA_SHFT                                            0x1
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_CLK_ARES_BMSK                                           0x1
#define HWIO_LPASS_QDSP6SS_GFMUX_CTL_CLK_ARES_SHFT                                           0x0

#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000024)
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000024)
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_RMSK                                                0x1f
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_GFMUX_STATUS_ADDR, HWIO_LPASS_QDSP6SS_GFMUX_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_GFMUX_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_SEL_STATUS_BMSK                                     0x1e
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_SEL_STATUS_SHFT                                      0x1
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_SWITCH_STATUS_BMSK                                   0x1
#define HWIO_LPASS_QDSP6SS_GFMUX_STATUS_SWITCH_STATUS_SHFT                                   0x0

#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000028)
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000028)
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_RMSK                                         0x80000013
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ADDR, HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_RMSK)
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ADDR,m,v,HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_IN)
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ROOT_OFF_BMSK                                0x80000000
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ROOT_OFF_SHFT                                      0x1f
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                0x10
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                 0x4
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ROOT_EN_BMSK                                        0x2
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_ROOT_EN_SHFT                                        0x1
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_UPDATE_BMSK                                         0x1
#define HWIO_LPASS_QDSP6SS_CORE_CMD_RCGR_UPDATE_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000002c)
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000002c)
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_RMSK                                            0x1071f
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_ADDR, HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_RMSK)
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_ADDR,m,v,HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_IN)
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_RCGLITE_DISABLE_BMSK                            0x10000
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_RCGLITE_DISABLE_SHFT                               0x10
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_SRC_SEL_BMSK                                      0x700
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_SRC_SEL_SHFT                                        0x8
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_SRC_DIV_BMSK                                       0x1f
#define HWIO_LPASS_QDSP6SS_CORE_CFG_RCGR_SRC_DIV_SHFT                                        0x0

#define HWIO_LPASS_QDSP6SS_PWR_CTL_ADDR                                               (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000030)
#define HWIO_LPASS_QDSP6SS_PWR_CTL_OFFS                                               (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000030)
#define HWIO_LPASS_QDSP6SS_PWR_CTL_RMSK                                                0xf7c0000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PWR_CTL_ADDR, HWIO_LPASS_QDSP6SS_PWR_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PWR_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PWR_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PWR_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PWR_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PWR_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PWR_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PWR_CTL_IN)
#define HWIO_LPASS_QDSP6SS_PWR_CTL_LDO_PWR_UP_BG_BMSK                                  0x8000000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_LDO_PWR_UP_BG_SHFT                                       0x1b
#define HWIO_LPASS_QDSP6SS_PWR_CTL_LDO_PWR_UP_BMSK                                     0x4000000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_LDO_PWR_UP_SHFT                                          0x1a
#define HWIO_LPASS_QDSP6SS_PWR_CTL_LDO_BYP_BMSK                                        0x2000000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_LDO_BYP_SHFT                                             0x19
#define HWIO_LPASS_QDSP6SS_PWR_CTL_BHS_ON_BMSK                                         0x1000000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_BHS_ON_SHFT                                              0x18
#define HWIO_LPASS_QDSP6SS_PWR_CTL_CLAMP_QMC_MEM_BMSK                                   0x400000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_CLAMP_QMC_MEM_SHFT                                       0x16
#define HWIO_LPASS_QDSP6SS_PWR_CTL_CLAMP_WL_BMSK                                        0x200000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_CLAMP_WL_SHFT                                            0x15
#define HWIO_LPASS_QDSP6SS_PWR_CTL_CLAMP_IO_BMSK                                        0x100000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_CLAMP_IO_SHFT                                            0x14
#define HWIO_LPASS_QDSP6SS_PWR_CTL_SLP_RET_N_BMSK                                        0x80000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_SLP_RET_N_SHFT                                           0x13
#define HWIO_LPASS_QDSP6SS_PWR_CTL_ARR_STBY_N_BMSK                                       0x40000
#define HWIO_LPASS_QDSP6SS_PWR_CTL_ARR_STBY_N_SHFT                                          0x12

#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ADDR                                           (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000034)
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_OFFS                                           (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000034)
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_RMSK                                           0x1fffffff
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ADDR, HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_IN)
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_JU_SLP_NRET_N_BMSK                             0x1c000000
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_JU_SLP_NRET_N_SHFT                                   0x1a
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ETB_SLP_NRET_N_BMSK                             0x2000000
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_ETB_SLP_NRET_N_SHFT                                  0x19
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L1IU_SLP_NRET_N_BMSK                            0x1800000
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L1IU_SLP_NRET_N_SHFT                                 0x17
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L1DU_SLP_NRET_N_BMSK                             0x600000
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L1DU_SLP_NRET_N_SHFT                                 0x15
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L2PLRU_SLP_NRET_N_BMSK                           0x100000
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L2PLRU_SLP_NRET_N_SHFT                               0x14
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L2TAG_SLP_NRET_N_BMSK                             0xf0000
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L2TAG_SLP_NRET_N_SHFT                                0x10
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L2DATA_SLP_NRET_N_BMSK                             0xffff
#define HWIO_LPASS_QDSP6SS_MEM_PWR_CTL_L2DATA_SLP_NRET_N_SHFT                                0x0

#define HWIO_LPASS_QDSP6SS_XO_CBCR_ADDR                                               (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000038)
#define HWIO_LPASS_QDSP6SS_XO_CBCR_OFFS                                               (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000038)
#define HWIO_LPASS_QDSP6SS_XO_CBCR_RMSK                                               0x80000001
#define HWIO_LPASS_QDSP6SS_XO_CBCR_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_XO_CBCR_ADDR, HWIO_LPASS_QDSP6SS_XO_CBCR_RMSK)
#define HWIO_LPASS_QDSP6SS_XO_CBCR_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_XO_CBCR_ADDR, m)
#define HWIO_LPASS_QDSP6SS_XO_CBCR_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_XO_CBCR_ADDR,v)
#define HWIO_LPASS_QDSP6SS_XO_CBCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_XO_CBCR_ADDR,m,v,HWIO_LPASS_QDSP6SS_XO_CBCR_IN)
#define HWIO_LPASS_QDSP6SS_XO_CBCR_CLKOFF_BMSK                                        0x80000000
#define HWIO_LPASS_QDSP6SS_XO_CBCR_CLKOFF_SHFT                                              0x1f
#define HWIO_LPASS_QDSP6SS_XO_CBCR_CLKEN_BMSK                                                0x1
#define HWIO_LPASS_QDSP6SS_XO_CBCR_CLKEN_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000003c)
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000003c)
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_RMSK                                            0x80000001
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_SLEEP_CBCR_ADDR, HWIO_LPASS_QDSP6SS_SLEEP_CBCR_RMSK)
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_SLEEP_CBCR_ADDR, m)
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_SLEEP_CBCR_ADDR,v)
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_SLEEP_CBCR_ADDR,m,v,HWIO_LPASS_QDSP6SS_SLEEP_CBCR_IN)
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_CLKOFF_BMSK                                     0x80000000
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_CLKOFF_SHFT                                           0x1f
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_CLKEN_BMSK                                             0x1
#define HWIO_LPASS_QDSP6SS_SLEEP_CBCR_CLKEN_SHFT                                             0x0

#define HWIO_LPASS_QDSP6SS_NMI_ADDR                                                   (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000040)
#define HWIO_LPASS_QDSP6SS_NMI_OFFS                                                   (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000040)
#define HWIO_LPASS_QDSP6SS_NMI_RMSK                                                          0x3
#define HWIO_LPASS_QDSP6SS_NMI_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_NMI_ADDR,v)
#define HWIO_LPASS_QDSP6SS_NMI_CLEAR_STATUS_BMSK                                             0x2
#define HWIO_LPASS_QDSP6SS_NMI_CLEAR_STATUS_SHFT                                             0x1
#define HWIO_LPASS_QDSP6SS_NMI_SET_NMI_BMSK                                                  0x1
#define HWIO_LPASS_QDSP6SS_NMI_SET_NMI_SHFT                                                  0x0

#define HWIO_LPASS_QDSP6SS_NMI_STATUS_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000044)
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000044)
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_RMSK                                                   0x7
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_NMI_STATUS_ADDR, HWIO_LPASS_QDSP6SS_NMI_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_NMI_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_EXT_DBG_TRIG_BMSK                                      0x4
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_EXT_DBG_TRIG_SHFT                                      0x2
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_WDOG_TRIG_BMSK                                         0x2
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_WDOG_TRIG_SHFT                                         0x1
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_PUBCSR_TRIG_BMSK                                       0x1
#define HWIO_LPASS_QDSP6SS_NMI_STATUS_PUBCSR_TRIG_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000048)
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000048)
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_RMSK                                               0x1
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_ADDR, HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_RMSK)
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_ADDR,m,v,HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_IN)
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_Q6_MON_CLKEN_BMSK                                  0x1
#define HWIO_LPASS_QDSP6SS_CLOCK_SPDM_MON_Q6_MON_CLKEN_SHFT                                  0x0

#define HWIO_LPASS_QDSP6SS_STATERET_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000004c)
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000004c)
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_RMSK                                                 0xf
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STATERET_CTL_ADDR, HWIO_LPASS_QDSP6SS_STATERET_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STATERET_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STATERET_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STATERET_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_STATERET_CTL_IN)
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_WAKEUP_IN_BMSK                                       0x8
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_WAKEUP_IN_SHFT                                       0x3
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_WAKE_IRQ_BMSK                                        0x4
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_WAKE_IRQ_SHFT                                        0x2
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_RESTORE_BMSK                                         0x2
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_RESTORE_SHFT                                         0x1
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_SAVE_BMSK                                            0x1
#define HWIO_LPASS_QDSP6SS_STATERET_CTL_SAVE_SHFT                                            0x0

#define HWIO_LPASS_QDSP6SS_LDO_USER_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000050)
#define HWIO_LPASS_QDSP6SS_LDO_USER_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000050)
#define HWIO_LPASS_QDSP6SS_LDO_USER_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_USER_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_USER_ADDR, HWIO_LPASS_QDSP6SS_LDO_USER_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_USER_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_USER_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_USER_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_USER_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_USER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_USER_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_USER_IN)
#define HWIO_LPASS_QDSP6SS_LDO_USER_DATA_BMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_USER_DATA_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_LDO_CFG0_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000054)
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000054)
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_CFG0_ADDR, HWIO_LPASS_QDSP6SS_LDO_CFG0_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_CFG0_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_CFG0_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_CFG0_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_CFG0_IN)
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_DATA_BMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_CFG0_DATA_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_LDO_CFG1_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000058)
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000058)
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_CFG1_ADDR, HWIO_LPASS_QDSP6SS_LDO_CFG1_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_CFG1_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_CFG1_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_CFG1_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_CFG1_IN)
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_DATA_BMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_CFG1_DATA_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_LDO_CFG2_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000005c)
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000005c)
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_CFG2_ADDR, HWIO_LPASS_QDSP6SS_LDO_CFG2_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_CFG2_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_CFG2_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_CFG2_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_CFG2_IN)
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_DATA_BMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_CFG2_DATA_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000060)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000060)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_RMSK                                             0x1007f
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_VREF_SET_ADDR, HWIO_LPASS_QDSP6SS_LDO_VREF_SET_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_VREF_SET_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_VREF_SET_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_VREF_SET_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_VREF_SET_IN)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_LDO_VREF_SEL_RST_BMSK                            0x10000
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_LDO_VREF_SEL_RST_SHFT                               0x10
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_VREF_LDO_BMSK                                       0x7f
#define HWIO_LPASS_QDSP6SS_LDO_VREF_SET_VREF_LDO_SHFT                                        0x0

#define HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000064)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000064)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_RMSK                                                 0x1
#define HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_LDO_VREF_SEL_UPDATE_BMSK                             0x1
#define HWIO_LPASS_QDSP6SS_LDO_VREF_CMD_LDO_VREF_SEL_UPDATE_SHFT                             0x0

#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000068)
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000068)
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_RMSK                                                0xffff
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_LD_CTL_ADDR, HWIO_LPASS_QDSP6SS_LDO_LD_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_LD_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_LD_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_LD_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_LD_CTL_IN)
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_DATA_BMSK                                           0xffff
#define HWIO_LPASS_QDSP6SS_LDO_LD_CTL_DATA_SHFT                                              0x0

#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000006c)
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000006c)
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_RMSK                                                0xff
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_ADDR, HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_IN)
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_DATA_BMSK                                           0xff
#define HWIO_LPASS_QDSP6SS_LDO_TRIM_CTL_DATA_SHFT                                            0x0

#define HWIO_LPASS_QDSP6SS_LDO_STATUS_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000070)
#define HWIO_LPASS_QDSP6SS_LDO_STATUS_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000070)
#define HWIO_LPASS_QDSP6SS_LDO_STATUS_RMSK                                            0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_STATUS_ADDR, HWIO_LPASS_QDSP6SS_LDO_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_STATUS_STATUS_BMSK                                     0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_STATUS_STATUS_SHFT                                            0x0

#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_ADDR                                      (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000074)
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_OFFS                                      (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000074)
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_RMSK                                            0x3f
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_ADDR, HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_LDO_VREF_TRIM_BMSK                              0x3e
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_LDO_VREF_TRIM_SHFT                               0x1
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_LDO_EN_BMSK                                      0x1
#define HWIO_LPASS_QDSP6SS_LDO_EFUSE_STATUS_LDO_EN_SHFT                                      0x0

#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000078)
#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000078)
#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_RMSK                                               0x1
#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_ADDR, HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_LDO_READY_BMSK                                     0x1
#define HWIO_LPASS_QDSP6SS_LDO_PWR_STATUS_LDO_READY_SHFT                                     0x0

#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000007c)
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000007c)
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_RMSK                                                0x3
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_ADDR, HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_IN)
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_CORE_PREON_EN_BMSK                                  0x2
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_CORE_PREON_EN_SHFT                                  0x1
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_CP_PREON_EN_BMSK                                    0x1
#define HWIO_LPASS_QDSP6SS_LDO_PREON_CTL_CP_PREON_EN_SHFT                                    0x0

#define HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_ADDR                                           (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000080)
#define HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_OFFS                                           (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000080)
#define HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_RMSK                                                  0xf
#define HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_ADDR,v)
#define HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_CMD_BMSK                                              0xf
#define HWIO_LPASS_QDSP6SS_SPM_SW_TRIG_CMD_SHFT                                              0x0

#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_ADDR                                       (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000084)
#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_OFFS                                       (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000084)
#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_RMSK                                              0xf
#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_ADDR, HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_BUSY_BMSK                                         0xf
#define HWIO_LPASS_QDSP6SS_SPM_TRIG_STATUS_BUSY_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000088)
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000088)
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_RMSK                                                 0x7
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ADDR, HWIO_LPASS_QDSP6SS_INTF_HALTREQ_RMSK)
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ADDR, m)
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ADDR,v)
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ADDR,m,v,HWIO_LPASS_QDSP6SS_INTF_HALTREQ_IN)
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_AXIM2_BMSK                                           0x4
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_AXIM2_SHFT                                           0x2
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_AXIM_BMSK                                            0x2
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_AXIM_SHFT                                            0x1
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ALL_BMSK                                             0x1
#define HWIO_LPASS_QDSP6SS_INTF_HALTREQ_ALL_SHFT                                             0x0

#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000008c)
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000008c)
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_RMSK                                                 0x7
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTF_HALTACK_ADDR, HWIO_LPASS_QDSP6SS_INTF_HALTACK_RMSK)
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTF_HALTACK_ADDR, m)
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_AXIM2_BMSK                                           0x4
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_AXIM2_SHFT                                           0x2
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_AXIM_BMSK                                            0x2
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_AXIM_SHFT                                            0x1
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_ALL_BMSK                                             0x1
#define HWIO_LPASS_QDSP6SS_INTF_HALTACK_ALL_SHFT                                             0x0

#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000090)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000090)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_RMSK                                                0xf
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_ADDR,v)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM2_CLAMP_E_BMSK                                  0x8
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM2_CLAMP_E_SHFT                                  0x3
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM2_CLAMP_L_BMSK                                  0x4
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM2_CLAMP_L_SHFT                                  0x2
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM_CLAMP_E_BMSK                                   0x2
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM_CLAMP_E_SHFT                                   0x1
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM_CLAMP_L_BMSK                                   0x1
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_SET_AXIM_CLAMP_L_SHFT                                   0x0

#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_ADDR                                       (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000094)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_OFFS                                       (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000094)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_RMSK                                              0xf
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_ADDR,v)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM2_CLAMP_E_BMSK                                0x8
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM2_CLAMP_E_SHFT                                0x3
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM2_CLAMP_L_BMSK                                0x4
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM2_CLAMP_L_SHFT                                0x2
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM_CLAMP_E_BMSK                                 0x2
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM_CLAMP_E_SHFT                                 0x1
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM_CLAMP_L_BMSK                                 0x1
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_CLEAR_AXIM_CLAMP_L_SHFT                                 0x0

#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_ADDR                                      (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000098)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_OFFS                                      (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000098)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_RMSK                                             0xf
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_ADDR, HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM2_CLAMP_E_BMSK                               0x8
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM2_CLAMP_E_SHFT                               0x3
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM2_CLAMP_L_BMSK                               0x4
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM2_CLAMP_L_SHFT                               0x2
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM_CLAMP_E_BMSK                                0x2
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM_CLAMP_E_SHFT                                0x1
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM_CLAMP_L_BMSK                                0x1
#define HWIO_LPASS_QDSP6SS_INTFCLAMP_STATUS_AXIM_CLAMP_L_SHFT                                0x0

#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_ADDR                                       (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000009c)
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_OFFS                                       (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000009c)
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_RMSK                                              0x3
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_ADDR, HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_RMSK)
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_ADDR, m)
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_ADDR,v)
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_ADDR,m,v,HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_IN)
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_AXIM2_BMSK                                        0x2
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_AXIM2_SHFT                                        0x1
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_AXIM_BMSK                                         0x1
#define HWIO_LPASS_QDSP6SS_INTF_FIFO_RESET_AXIM_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000ac)
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000ac)
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_RMSK                                                   0xf
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_BHS_CTL_ADDR, HWIO_LPASS_QDSP6SS_CP_BHS_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_BHS_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CP_BHS_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CP_BHS_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_CP_BHS_CTL_IN)
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_DRIVE_SEL_BMSK                                         0xf
#define HWIO_LPASS_QDSP6SS_CP_BHS_CTL_DRIVE_SEL_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000b0)
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000b0)
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_RMSK                                              0xaf7f
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_ADDR, HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_RMSK)
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_ADDR,m,v,HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_IN)
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CP0_CLK_EN_BMSK                                   0x8000
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CP0_CLK_EN_SHFT                                      0xf
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_AXIS_CLK_EN_BMSK                                  0x2000
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_AXIS_CLK_EN_SHFT                                     0xd
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_AHBM_CLK_EN_BMSK                                   0x800
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_AHBM_CLK_EN_SHFT                                     0xb
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_AHBS_CLK_EN_BMSK                                   0x400
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_AHBS_CLK_EN_SHFT                                     0xa
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_PRIV_AHBS_CLK_EN_BMSK                              0x300
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_PRIV_AHBS_CLK_EN_SHFT                                0x8
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_L2VIC_AHBS_CLK_EN_BMSK                              0x60
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_L2VIC_AHBS_CLK_EN_SHFT                               0x5
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_TEST_AHBS_CLK_EN_BMSK                               0x10
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_TEST_AHBS_CLK_EN_SHFT                                0x4
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_PUB_AHBS_CLK_EN_BMSK                                 0x8
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_PUB_AHBS_CLK_EN_SHFT                                 0x3
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CORE_BUS_EN_BMSK                                     0x4
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CORE_BUS_EN_SHFT                                     0x2
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CORE_RCLK_EN_BMSK                                    0x2
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CORE_RCLK_EN_SHFT                                    0x1
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CORE_CLK_EN_BMSK                                     0x1
#define HWIO_LPASS_QDSP6SS_CGC_OVERRIDE_CORE_CLK_EN_SHFT                                     0x0

#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_ADDR                                           (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000b4)
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_OFFS                                           (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000b4)
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_RMSK                                                 0xff
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_ADDR, HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_IN)
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_SLP_NRET_N_BMSK                                      0xff
#define HWIO_LPASS_QDSP6SS_L1S_PWR_CTL_SLP_NRET_N_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000c0)
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000c0)
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_RMSK                                                 0xf
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_ADDR, HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_IN)
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_DRIVE_SEL_BMSK                                       0xf
#define HWIO_LPASS_QDSP6SS_CORE_BHS_CTL_DRIVE_SEL_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_BHS_STATUS_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000c4)
#define HWIO_LPASS_QDSP6SS_BHS_STATUS_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000c4)
#define HWIO_LPASS_QDSP6SS_BHS_STATUS_RMSK                                                   0x1
#define HWIO_LPASS_QDSP6SS_BHS_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_BHS_STATUS_ADDR, HWIO_LPASS_QDSP6SS_BHS_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_BHS_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_BHS_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_BHS_STATUS_BHS_EN_REST_ACK_BMSK                                   0x1
#define HWIO_LPASS_QDSP6SS_BHS_STATUS_BHS_EN_REST_ACK_SHFT                                   0x0

#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_ADDR                                           (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000c8)
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_OFFS                                           (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000c8)
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_RMSK                                                  0x3
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_ADDR, HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_IN)
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_QMC_MEM_SVS_SEL_BMSK                                  0x2
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_QMC_MEM_SVS_SEL_SHFT                                  0x1
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_QMC_MEM_SVS_BMSK                                      0x1
#define HWIO_LPASS_QDSP6SS_QMC_SVS_CTL_QMC_MEM_SVS_SHFT                                      0x0

#define HWIO_LPASS_QDSP6SS_BHS_TEST_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000cc)
#define HWIO_LPASS_QDSP6SS_BHS_TEST_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000cc)
#define HWIO_LPASS_QDSP6SS_BHS_TEST_RMSK                                                     0x1
#define HWIO_LPASS_QDSP6SS_BHS_TEST_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_BHS_TEST_ADDR, HWIO_LPASS_QDSP6SS_BHS_TEST_RMSK)
#define HWIO_LPASS_QDSP6SS_BHS_TEST_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_BHS_TEST_ADDR, m)
#define HWIO_LPASS_QDSP6SS_BHS_TEST_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_BHS_TEST_ADDR,v)
#define HWIO_LPASS_QDSP6SS_BHS_TEST_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_BHS_TEST_ADDR,m,v,HWIO_LPASS_QDSP6SS_BHS_TEST_IN)
#define HWIO_LPASS_QDSP6SS_BHS_TEST_INSTANT_ON_BMSK                                          0x1
#define HWIO_LPASS_QDSP6SS_BHS_TEST_INSTANT_ON_SHFT                                          0x0

#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000f0)
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000f0)
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_RMSK                                                   0xf
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_PWR_CTL_ADDR, HWIO_LPASS_QDSP6SS_CP_PWR_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_PWR_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CP_PWR_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CP_PWR_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_CP_PWR_CTL_IN)
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_LDO_2PASS_ON_BMSK                                      0x8
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_LDO_2PASS_ON_SHFT                                      0x3
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_SHUNT_BHS_ON_BMSK                                      0x4
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_SHUNT_BHS_ON_SHFT                                      0x2
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_BHS_ON_BMSK                                            0x2
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_BHS_ON_SHFT                                            0x1
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_CLAMP_IO_BMSK                                          0x1
#define HWIO_LPASS_QDSP6SS_CP_PWR_CTL_CLAMP_IO_SHFT                                          0x0

#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000f4)
#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000f4)
#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_RMSK                                                0x1
#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_ADDR, HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_ENR_ACK_BMSK                                        0x1
#define HWIO_LPASS_QDSP6SS_CP_PWR_STATUS_ENR_ACK_SHFT                                        0x0

#define HWIO_LPASS_QDSP6SS_CP_RESET_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000f8)
#define HWIO_LPASS_QDSP6SS_CP_RESET_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000f8)
#define HWIO_LPASS_QDSP6SS_CP_RESET_RMSK                                                     0x1
#define HWIO_LPASS_QDSP6SS_CP_RESET_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_RESET_ADDR, HWIO_LPASS_QDSP6SS_CP_RESET_RMSK)
#define HWIO_LPASS_QDSP6SS_CP_RESET_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_RESET_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CP_RESET_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CP_RESET_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CP_RESET_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CP_RESET_ADDR,m,v,HWIO_LPASS_QDSP6SS_CP_RESET_IN)
#define HWIO_LPASS_QDSP6SS_CP_RESET_ARES_BMSK                                                0x1
#define HWIO_LPASS_QDSP6SS_CP_RESET_ARES_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x000000fc)
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x000000fc)
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_RMSK                                                   0x1
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_CLK_CTL_ADDR, HWIO_LPASS_QDSP6SS_CP_CLK_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CP_CLK_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_CP_CLK_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_CP_CLK_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_CP_CLK_CTL_IN)
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_CLK_ENA_BMSK                                           0x1
#define HWIO_LPASS_QDSP6SS_CP_CLK_CTL_CLK_ENA_SHFT                                           0x0

#define HWIO_LPASS_QDSP6SS_STRAP_TCM_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000100)
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000100)
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_RMSK                                             0xfffc0000
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_TCM_ADDR, HWIO_LPASS_QDSP6SS_STRAP_TCM_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_TCM_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_TCM_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_TCM_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_TCM_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_BASE_ADDR_BMSK                                   0xfffc0000
#define HWIO_LPASS_QDSP6SS_STRAP_TCM_BASE_ADDR_SHFT                                         0x12

#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000104)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000104)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_RMSK                                        0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_ADDR, HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_UPPER_ADDR_BMSK                             0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AHBUPPER_UPPER_ADDR_SHFT                                    0xe

#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000108)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000108)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_RMSK                                        0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_ADDR, HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_LOWER_ADDR_BMSK                             0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AHBLOWER_LOWER_ADDR_SHFT                                    0xe

#define HWIO_LPASS_QDSP6SS_STRAP_ACC_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000110)
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000110)
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_RMSK                                             0xffffffff
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_ACC_ADDR, HWIO_LPASS_QDSP6SS_STRAP_ACC_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_ACC_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_ACC_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_ACC_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_ACC_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_DATA_BMSK                                        0xffffffff
#define HWIO_LPASS_QDSP6SS_STRAP_ACC_DATA_SHFT                                               0x0

#define HWIO_LPASS_QDSP6SS_DCC_CTRL_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000118)
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000118)
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DCC_CTRL_ADDR, HWIO_LPASS_QDSP6SS_DCC_CTRL_RMSK)
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DCC_CTRL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_DCC_CTRL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_DCC_CTRL_ADDR,m,v,HWIO_LPASS_QDSP6SS_DCC_CTRL_IN)
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_CTRL_BMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_DCC_CTRL_CTRL_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_ADDR                                      (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000011c)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_OFFS                                      (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000011c)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_RMSK                                      0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_ADDR, HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_UPPER_ADDR_BMSK                           0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2UPPER_UPPER_ADDR_SHFT                                  0xe

#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_ADDR                                      (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000120)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_OFFS                                      (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000120)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_RMSK                                      0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_ADDR, HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_LOWER_ADDR_BMSK                           0xffffc000
#define HWIO_LPASS_QDSP6SS_STRAP_AXIM2LOWER_LOWER_ADDR_SHFT                                  0xe

#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_ADDR                                     (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000124)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_OFFS                                     (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000124)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_RMSK                                            0x1
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_ADDR, HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_STRAP_QMC_ACC_SEL_BMSK                          0x1
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_SEL_STRAP_QMC_ACC_SEL_SHFT                          0x0

#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000128)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000128)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_RMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_ADDR, HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_STRAP_QMC_ACC_BMSK                           0xffffffff
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_STRAP_QMC_ACC_SHFT                                  0x0

#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_ADDR                                       (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000012c)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_OFFS                                       (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000012c)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_RMSK                                       0xffffffff
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_ADDR, HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_RMSK)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_ADDR, m)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_ADDR,v)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_ADDR,m,v,HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_IN)
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_STRAP_QMC_ACC_U_BMSK                       0xffffffff
#define HWIO_LPASS_QDSP6SS_STRAP_QMC_ACC_U_STRAP_QMC_ACC_U_SHFT                              0x0

#define HWIO_LPASS_QDSP6SS_PLL_MODE_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000200)
#define HWIO_LPASS_QDSP6SS_PLL_MODE_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000200)
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_MODE_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_MODE_ADDR, HWIO_LPASS_QDSP6SS_PLL_MODE_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_MODE_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_MODE_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_MODE_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_MODE_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_MODE_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_MODE_IN)
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_LOCK_DET_BMSK                                 0x80000000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_LOCK_DET_SHFT                                       0x1f
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_ACTIVE_FLAG_BMSK                              0x40000000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_ACTIVE_FLAG_SHFT                                    0x1e
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_ACK_LATCH_BMSK                                0x20000000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_ACK_LATCH_SHFT                                      0x1d
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_LOCK_DET_FINE_BMSK                            0x10000000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_LOCK_DET_FINE_SHFT                                  0x1c
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RESERVE_BITS27_24_BMSK                             0xf000000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RESERVE_BITS27_24_SHFT                                  0x18
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_HW_UPDATE_LOGIC_BYPASS_BMSK                     0x800000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_HW_UPDATE_LOGIC_BYPASS_SHFT                         0x17
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_UPDATE_BMSK                                     0x400000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_UPDATE_SHFT                                         0x16
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_VOTE_FSM_RESET_BMSK                             0x200000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_VOTE_FSM_RESET_SHFT                                 0x15
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_VOTE_FSM_ENA_BMSK                               0x100000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_VOTE_FSM_ENA_SHFT                                   0x14
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_BIAS_COUNT_BMSK                                  0xfc000
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_BIAS_COUNT_SHFT                                      0xe
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_LOCK_COUNT_BMSK                                   0x3f00
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_LOCK_COUNT_SHFT                                      0x8
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RESERVE_BITS7_3_BMSK                                    0xf8
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RESERVE_BITS7_3_SHFT                                     0x3
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_RESET_N_BMSK                                         0x4
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_RESET_N_SHFT                                         0x2
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RESERVE_BIT1_BMSK                                        0x2
#define HWIO_LPASS_QDSP6SS_PLL_MODE_RESERVE_BIT1_SHFT                                        0x1
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_OUTCTRL_BMSK                                         0x1
#define HWIO_LPASS_QDSP6SS_PLL_MODE_PLL_OUTCTRL_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000204)
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000204)
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_RMSK                                                 0xffff
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_L_VAL_ADDR, HWIO_LPASS_QDSP6SS_PLL_L_VAL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_L_VAL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_L_VAL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_L_VAL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_L_VAL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_PLL_L_BMSK                                           0xffff
#define HWIO_LPASS_QDSP6SS_PLL_L_VAL_PLL_L_SHFT                                              0x0

#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_ADDR                                         (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000208)
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_OFFS                                         (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000208)
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_RMSK                                             0xffff
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_ADDR, HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_PLL_CAL_L_BMSK                                   0xffff
#define HWIO_LPASS_QDSP6SS_PLL_CAL_L_VAL_PLL_CAL_L_SHFT                                      0x0

#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000020c)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000020c)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RMSK                                          0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_ADDR, HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_USER_CTL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RESERVE_BITS31_19_BMSK                        0xfff80000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RESERVE_BITS31_19_SHFT                              0x13
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PRE_DIV_RATIO_BMSK                               0x70000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PRE_DIV_RATIO_SHFT                                  0x10
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_POST_DIV_RATIO_ODD_BMSK                           0xf000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_POST_DIV_RATIO_ODD_SHFT                              0xc
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_POST_DIV_RATIO_EVEN_BMSK                           0xf00
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_POST_DIV_RATIO_EVEN_SHFT                             0x8
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_OUT_CLK_POLARITY_BMSK                               0x80
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_OUT_CLK_POLARITY_SHFT                                0x7
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RESERVE_BITS6_5_BMSK                                0x60
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RESERVE_BITS6_5_SHFT                                 0x5
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_TEST_BMSK                                    0x10
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_TEST_SHFT                                     0x4
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RESERVE_BIT3_BMSK                                    0x8
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_RESERVE_BIT3_SHFT                                    0x3
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_ODD_BMSK                                      0x4
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_ODD_SHFT                                      0x2
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_EVEN_BMSK                                     0x2
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_EVEN_SHFT                                     0x1
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_MAIN_BMSK                                     0x1
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_PLLOUT_MAIN_SHFT                                     0x0

#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000210)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000210)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_RMSK                                        0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_ADDR, HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_IN)
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_RESERVE_BITS31_19_BMSK                      0xfff80000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_RESERVE_BITS31_19_SHFT                            0x13
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_USE_PREDIV_WHEN_CAL_BMSK                       0x40000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_USE_PREDIV_WHEN_CAL_SHFT                          0x12
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_USE_EXT_SAVERESTORE_BMSK                       0x20000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_USE_EXT_SAVERESTORE_SHFT                          0x11
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_LOW_JITTER_MODE_EN_BMSK                        0x10000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_LOW_JITTER_MODE_EN_SHFT                           0x10
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_FRAC_FORMAT_SEL_BMSK                            0x8000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_FRAC_FORMAT_SEL_SHFT                               0xf
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_BIAS_ON_IN_STANDBY_BMSK                         0x4000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_BIAS_ON_IN_STANDBY_SHFT                            0xe
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_REF_CLK_AT_OUT_BMSK                             0x2000
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_REF_CLK_AT_OUT_SHFT                                0xd
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_BMSK                      0x1800
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_SHFT                         0xb
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_LATCH_INTERFACE_BYPASS_BMSK                      0x400
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_LATCH_INTERFACE_BYPASS_SHFT                        0xa
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_STATUS_REGISTER_BMSK                             0x3e0
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_STATUS_REGISTER_SHFT                               0x5
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_WRITE_STATE_EN_BMSK                               0x10
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_WRITE_STATE_EN_SHFT                                0x4
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_CALIB_CTRL_BMSK                                    0xe
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_CALIB_CTRL_SHFT                                    0x1
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_BMSK                        0x1
#define HWIO_LPASS_QDSP6SS_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_SHFT                        0x0

#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000214)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000214)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_RMSK                                        0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_ADDR, HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FINE_LDC_THRESHOLD_BMSK                     0xfc000000
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FINE_LDC_THRESHOLD_SHFT                           0x1a
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_COARSE_LDC_THRESHOLD_BMSK                    0x3c00000
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_COARSE_LDC_THRESHOLD_SHFT                         0x16
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_COARSE_LOCK_DET_NEG_THRESHOLD_BMSK            0x3c0000
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_COARSE_LOCK_DET_NEG_THRESHOLD_SHFT                0x12
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_COARSE_LOCK_DET_POS_THRESHOLD_BMSK             0x3c000
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_COARSE_LOCK_DET_POS_THRESHOLD_SHFT                 0xe
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FINE_LOCK_DET_THRESHOLD_BMSK                    0x3800
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FINE_LOCK_DET_THRESHOLD_SHFT                       0xb
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FINE_LOCK_DET_SAMPLE_SIZE_BMSK                   0x700
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FINE_LOCK_DET_SAMPLE_SIZE_SHFT                     0x8
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FWD_GAIN_SLEWING_KFN_BMSK                         0xf0
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FWD_GAIN_SLEWING_KFN_SHFT                          0x4
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FWD_GAIN_KFN_BMSK                                  0xf
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_FWD_GAIN_KFN_SHFT                                  0x0

#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_ADDR                                      (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000218)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_OFFS                                      (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000218)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_RMSK                                      0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_ADDR, HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_IN)
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_BIST_CFG_BMSK                             0xfff00000
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_BIST_CFG_SHFT                                   0x14
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_RESERVE_BITS19_12_BMSK                       0xff000
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_RESERVE_BITS19_12_SHFT                           0xc
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_BMSK                       0xc00
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_SHFT                         0xa
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_PREDIV_WHEN_CAL_BMSK                           0x380
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_PREDIV_WHEN_CAL_SHFT                             0x7
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_INC_MIN_GLITCH_THRESHOLD_4X_BMSK                0x40
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_INC_MIN_GLITCH_THRESHOLD_4X_SHFT                 0x6
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_BMSK                       0x30
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_SHFT                        0x4
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_USE_BOTH_REF_CLK_EDGE_BMSK                       0x8
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_USE_BOTH_REF_CLK_EDGE_SHFT                       0x3
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_BIAS_WARMUP_TIME_BMSK                            0x6
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_BIAS_WARMUP_TIME_SHFT                            0x1
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_DIV_LOCK_DET_THRESHOLDS_BMSK                     0x1
#define HWIO_LPASS_QDSP6SS_PLL_CONFIG_CTL_U_DIV_LOCK_DET_THRESHOLDS_SHFT                     0x0

#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000021c)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000021c)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_RMSK                                          0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADDR, HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADD_REF_CYC_CALIB_STEPS_BMSK                  0xc0000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ADD_REF_CYC_CALIB_STEPS_SHFT                        0x1e
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_GLITCH_DETECTOR_COUNT_LIMIT_BMSK              0x30000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_GLITCH_DETECTOR_COUNT_LIMIT_SHFT                    0x1c
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_GLITCH_PREVENTION_DIS_BMSK                     0x8000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_GLITCH_PREVENTION_DIS_SHFT                          0x1b
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_FINE_FCW_BMSK                                  0x7e00000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_FINE_FCW_SHFT                                       0x15
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OVERRIDE_FINE_FCW_BMSK                          0x100000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OVERRIDE_FINE_FCW_SHFT                              0x14
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_COARSE_FCW_BMSK                                  0xff000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_COARSE_FCW_SHFT                                      0xc
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OVERRIDE_COARSE_FCW_BMSK                           0x800
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OVERRIDE_COARSE_FCW_SHFT                             0xb
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_PROCESS_CALIB_WORD_BMSK                            0x700
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_PROCESS_CALIB_WORD_SHFT                              0x8
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OVERRIDE_CALIB_WORD_BMSK                            0x80
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_OVERRIDE_CALIB_WORD_SHFT                             0x7
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_DISABLE_LFSR_BMSK                                   0x40
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_DISABLE_LFSR_SHFT                                    0x6
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST1_SEL_BMSK                                     0x30
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST1_SEL_SHFT                                      0x4
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST0_SEL_BMSK                                      0xc
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST0_SEL_SHFT                                      0x2
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST1_EN_BMSK                                       0x2
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST1_EN_SHFT                                       0x1
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST0_EN_BMSK                                       0x1
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_ATEST0_EN_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000220)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000220)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_RMSK                                        0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ADDR, HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_IN)
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ENABLE_TRAINING_SEQ_BMSK                    0x80000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_ENABLE_TRAINING_SEQ_SHFT                          0x1f
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_LOGIC_DEP_BMSK                       0x40000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_LOGIC_DEP_SHFT                             0x1e
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_BIAS_DET_BMSK                        0x20000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_BIAS_DET_SHFT                              0x1d
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_MSB_CLOCK_SELECT_BMSK                       0x10000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_MSB_CLOCK_SELECT_SHFT                             0x1c
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_FIRST_ORDER_DSM_BMSK                  0x8000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_FIRST_ORDER_DSM_SHFT                       0x1b
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DCO_OFFSET_CURRENT_ADJUST_BMSK               0x6000000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DCO_OFFSET_CURRENT_ADJUST_SHFT                    0x19
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_MIRROR_DEVICE_ADJUST_BMSK                    0x1c00000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_MIRROR_DEVICE_ADJUST_SHFT                         0x16
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BIAS_STARTUP_CIR_DIS_BMSK                     0x200000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BIAS_STARTUP_CIR_DIS_SHFT                         0x15
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DISABLE_CLAMP_BMSK                            0x100000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DISABLE_CLAMP_SHFT                                0x14
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_MODE_OF_BIAS_BMSK                       0x80000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_MODE_OF_BIAS_SHFT                          0x13
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_MODE_FOR_BIAS_EN_BMSK                   0x40000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BYPASS_MODE_FOR_BIAS_EN_SHFT                      0x12
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BIAS_ADJUST_BMSK                               0x30000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_BIAS_ADJUST_SHFT                                  0x10
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DIV2_NMO_EN_BMSK                                0x8000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DIV2_NMO_EN_SHFT                                   0xf
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DIS_LEAK_CMP_BMSK                               0x4000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DIS_LEAK_CMP_SHFT                                  0xe
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_SINGLE_DMET_EN_BMSK                             0x2000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_SINGLE_DMET_EN_SHFT                                0xd
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DEMET_WINDOW_DIS_BMSK                           0x1000
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_DEMET_WINDOW_DIS_SHFT                              0xc
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_NMO_OSC_SEL_BMSK                                 0xc00
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_NMO_OSC_SEL_SHFT                                   0xa
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_NOISE_MAG_BMSK                                   0x380
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_NOISE_MAG_SHFT                                     0x7
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_NOISE_GEN_EN_BMSK                                 0x40
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_NOISE_GEN_EN_SHFT                                  0x6
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_OSC_BIAS_GND_BMSK                                 0x20
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_OSC_BIAS_GND_SHFT                                  0x5
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_PLL_TEST_OUT_SEL_BMSK                             0x18
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_PLL_TEST_OUT_SEL_SHFT                              0x3
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_STATUS_REG_EN_BMSK                                 0x4
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_STATUS_REG_EN_SHFT                                 0x2
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_SKIP_FINE_TUNE_BMSK                                0x2
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_SKIP_FINE_TUNE_SHFT                                0x1
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_SKIP_FAST_LOCK_BMSK                                0x1
#define HWIO_LPASS_QDSP6SS_PLL_TEST_CTL_U_SKIP_FAST_LOCK_SHFT                                0x0

#define HWIO_LPASS_QDSP6SS_PLL_STATUS_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000224)
#define HWIO_LPASS_QDSP6SS_PLL_STATUS_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000224)
#define HWIO_LPASS_QDSP6SS_PLL_STATUS_RMSK                                            0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_STATUS_ADDR, HWIO_LPASS_QDSP6SS_PLL_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_STATUS_STATUS_31_0_BMSK                                0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_STATUS_STATUS_31_0_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000228)
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000228)
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_RMSK                                          0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_ADDR, HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_FREQUENCY_CTL_WORD_BMSK                       0xffffffff
#define HWIO_LPASS_QDSP6SS_PLL_FREQ_CTL_FREQUENCY_CTL_WORD_SHFT                              0x0

#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000022c)
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000022c)
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_RMSK                                                   0x7
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_OPMODE_ADDR, HWIO_LPASS_QDSP6SS_PLL_OPMODE_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_OPMODE_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_OPMODE_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_OPMODE_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_OPMODE_IN)
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_PLL_OPMODE_BMSK                                        0x7
#define HWIO_LPASS_QDSP6SS_PLL_OPMODE_PLL_OPMODE_SHFT                                        0x0

#define HWIO_LPASS_QDSP6SS_PLL_STATE_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000230)
#define HWIO_LPASS_QDSP6SS_PLL_STATE_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000230)
#define HWIO_LPASS_QDSP6SS_PLL_STATE_RMSK                                                    0x7
#define HWIO_LPASS_QDSP6SS_PLL_STATE_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_STATE_ADDR, HWIO_LPASS_QDSP6SS_PLL_STATE_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_STATE_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_STATE_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_STATE_PLL_STATE_BMSK                                          0x7
#define HWIO_LPASS_QDSP6SS_PLL_STATE_PLL_STATE_SHFT                                          0x0

#define HWIO_LPASS_QDSP6SS_PLL_DROOP_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000234)
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000234)
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_RMSK                                                   0xff
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_DROOP_ADDR, HWIO_LPASS_QDSP6SS_PLL_DROOP_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_DROOP_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_DROOP_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_DROOP_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_DROOP_IN)
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_DROOP_CODE_BMSK                                        0xfe
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_DROOP_CODE_SHFT                                         0x1
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_DROOP_EN_BMSK                                           0x1
#define HWIO_LPASS_QDSP6SS_PLL_DROOP_DROOP_EN_SHFT                                           0x0

#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000238)
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000238)
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_RMSK                                              0xffff
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_ADDR, HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_PLL_FRAC_VAL_BMSK                                 0xffff
#define HWIO_LPASS_QDSP6SS_PLL_FRAC_VAL_PLL_FRAC_VAL_SHFT                                    0x0

#define HWIO_LPASS_QDSP6SS_PLL_SPARE_ADDR                                             (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000023c)
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_OFFS                                             (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000023c)
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_RMSK                                                   0xff
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_SPARE_ADDR, HWIO_LPASS_QDSP6SS_PLL_SPARE_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_SPARE_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_SPARE_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_SPARE_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_SPARE_IN)
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_SPARE_OUTPUTS_BMSK                                     0xf0
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_SPARE_OUTPUTS_SHFT                                      0x4
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_SPARE_INPUTS_BMSK                                       0xf
#define HWIO_LPASS_QDSP6SS_PLL_SPARE_SPARE_INPUTS_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_ADDR                                 (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000240)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_OFFS                                 (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000240)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_RMSK                                        0x3
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_ADDR, HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_RCG2PLL_UPD_STATUS_BMSK                     0x2
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_RCG2PLL_UPD_STATUS_SHFT                     0x1
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_PLL2RCG_UPD_STATUS_BMSK                     0x1
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_STATUS_PLL2RCG_UPD_STATUS_SHFT                     0x0

#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_ADDR                                    (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000244)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_OFFS                                    (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000244)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_RMSK                                           0x3
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_ADDR, HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_IN)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_RCG2PLL_UPD_EN_BMSK                            0x2
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_RCG2PLL_UPD_EN_SHFT                            0x1
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_PLL2RCG_UPD_EN_BMSK                            0x1
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CFG_PLL2RCG_UPD_EN_SHFT                            0x0

#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_ADDR                                 (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000248)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_OFFS                                 (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000248)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_RMSK                                       0x1f
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_ADDR, HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_IN)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_MATCH_VALUE_BMSK                           0x1f
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_DLYCTL_MATCH_VALUE_SHFT                            0x0

#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_ADDR                                    (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000024c)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_OFFS                                    (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000024c)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_RMSK                                           0x1
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_CMD_BMSK                                       0x1
#define HWIO_LPASS_QDSP6SS_PLL_RCG_UPDATE_CMD_CMD_SHFT                                       0x0

#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_ADDR                                           (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000300)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_OFFS                                           (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000300)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_RMSK                                                  0x7
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_ADDR, HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_RMSK)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_ADDR, m)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_ADDR,v)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_ADDR,m,v,HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_IN)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_DBG_NMI_EN_IN_PWR_COLLAPSE_BMSK                       0x4
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_DBG_NMI_EN_IN_PWR_COLLAPSE_SHFT                       0x2
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_DBG_NMI_DISABLE_BMSK                                  0x2
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_DBG_NMI_DISABLE_SHFT                                  0x1
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_DBG_NMI_WAKEUP_DISABLE_BMSK                           0x1
#define HWIO_LPASS_QDSP6SS_DBG_NMI_CFG_DBG_NMI_WAKEUP_DISABLE_SHFT                           0x0

#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_ADDR                                    (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00000304)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_OFFS                                    (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00000304)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_RMSK                                           0x3
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_ADDR, HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_QDSP6_PWR_COLLAPSE_BMSK                        0x2
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_QDSP6_PWR_COLLAPSE_SHFT                        0x1
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_QDSP6_IN_SLEEP_BMSK                            0x1
#define HWIO_LPASS_QDSP6SS_DBG_NMI_PWR_STATUS_QDSP6_IN_SLEEP_SHFT                            0x0

#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00002000)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00002000)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_RMSK                                          0xffffffff
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_ADDR, HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_IN)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_SPARE_CFG_BMSK                                0xff000000
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_SPARE_CFG_SHFT                                      0x18
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_HWE_INV_BMSK                                    0x800000
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_HWE_INV_SHFT                                        0x17
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_HWE_SEL_BMSK                                    0x7c0000
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_HWE_SEL_SHFT                                        0x12
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_TESTBUS_EN_BMSK                                  0x20000
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_TESTBUS_EN_SHFT                                     0x11
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_Q6_SEL_BMSK                                      0x10000
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_Q6_SEL_SHFT                                         0x10
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_SEL_BMSK                                          0xffff
#define HWIO_LPASS_QDSP6SS_TEST_BUS_CTL_SEL_SHFT                                             0x0

#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00002004)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00002004)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_RMSK                                        0xffffffff
#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_ADDR, HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_RMSK)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_ADDR, m)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_VALUE_BMSK                                  0xffffffff
#define HWIO_LPASS_QDSP6SS_TEST_BUS_VALUE_VALUE_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_ADDR                                        (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00002008)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_OFFS                                        (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00002008)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_RMSK                                        0xffffffff
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_ADDR, HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_RMSK)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_ADDR, m)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_ADDR,v)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_ADDR,m,v,HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_IN)
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_VALUE_BMSK                                  0xffffffff
#define HWIO_LPASS_QDSP6SS_TEST_BUS_WDATA_VALUE_SHFT                                         0x0

#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ADDR                                            (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000200c)
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_OFFS                                            (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000200c)
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_RMSK                                                   0x1
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ADDR, HWIO_LPASS_QDSP6SS_PWRDBG_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_PWRDBG_CTL_IN)
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ENA_BMSK                                               0x1
#define HWIO_LPASS_QDSP6SS_PWRDBG_CTL_ENA_SHFT                                               0x0

#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00002010)
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00002010)
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_RMSK                                                0x7f
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_ADDR, HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_RMSK)
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_ADDR, m)
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_ADDR,v)
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_ADDR,m,v,HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_IN)
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_Q6_DBG_CLK_EN_BMSK                                  0x40
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_Q6_DBG_CLK_EN_SHFT                                   0x6
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_Q6_DBG_CLK_INV_BMSK                                 0x20
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_Q6_DBG_CLK_INV_SHFT                                  0x5
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_DBG_CLK_SEL_BMSK                                    0x1f
#define HWIO_LPASS_QDSP6SS_TEST_CLK_CTL_DBG_CLK_SEL_SHFT                                     0x0

#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ADDR                                          (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00002018)
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_OFFS                                          (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00002018)
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_RMSK                                            0xffffff
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ADDR, HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_RMSK)
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ADDR, m)
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ADDR,v)
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ADDR,m,v,HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_IN)
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_COUNT_BMSK                                0xffffe0
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_COUNT_SHFT                                     0x5
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_MUX_SEL_BMSK                                        0x10
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_MUX_SEL_SHFT                                         0x4
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_CLK_R_ENA_BMSK                                 0x8
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_CLK_R_ENA_SHFT                                 0x3
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_CGC_EN_BMSK                                    0x4
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_CGC_EN_SHFT                                    0x2
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_BYPASS_BMSK                                    0x2
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_BYPASS_SHFT                                    0x1
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_SW_RESET_BMSK                                  0x1
#define HWIO_LPASS_QDSP6SS_ZMEAS_CONFIG_ZMEAS_SW_RESET_SHFT                                  0x0

#define HWIO_LPASS_QDSP6SS_LDO_TEST_ADDR                                              (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x0000201c)
#define HWIO_LPASS_QDSP6SS_LDO_TEST_OFFS                                              (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x0000201c)
#define HWIO_LPASS_QDSP6SS_LDO_TEST_RMSK                                              0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_TEST_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_TEST_ADDR, HWIO_LPASS_QDSP6SS_LDO_TEST_RMSK)
#define HWIO_LPASS_QDSP6SS_LDO_TEST_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_LDO_TEST_ADDR, m)
#define HWIO_LPASS_QDSP6SS_LDO_TEST_OUT(v)      \
        out_dword(HWIO_LPASS_QDSP6SS_LDO_TEST_ADDR,v)
#define HWIO_LPASS_QDSP6SS_LDO_TEST_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LPASS_QDSP6SS_LDO_TEST_ADDR,m,v,HWIO_LPASS_QDSP6SS_LDO_TEST_IN)
#define HWIO_LPASS_QDSP6SS_LDO_TEST_DATA_BMSK                                         0xffffffff
#define HWIO_LPASS_QDSP6SS_LDO_TEST_DATA_SHFT                                                0x0

#define HWIO_LPASS_QDSP6SS_CORE_STATUS_ADDR                                           (LPASS_QDSP6V60SS_PUB_REG_BASE      + 0x00002028)
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_OFFS                                           (LPASS_QDSP6V60SS_PUB_REG_BASE_OFFS + 0x00002028)
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_RMSK                                                  0x7
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_IN          \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_STATUS_ADDR, HWIO_LPASS_QDSP6SS_CORE_STATUS_RMSK)
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_INM(m)      \
        in_dword_masked(HWIO_LPASS_QDSP6SS_CORE_STATUS_ADDR, m)
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_CP0_IDLE_BMSK                                         0x4
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_CP0_IDLE_SHFT                                         0x2
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_CORE_IN_SLEEP_BMSK                                    0x2
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_CORE_IN_SLEEP_SHFT                                    0x1
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_CORE_STATE_BMSK                                       0x1
#define HWIO_LPASS_QDSP6SS_CORE_STATUS_CORE_STATE_SHFT                                       0x0


#endif /* __HALLDOHWIO_H__ */
