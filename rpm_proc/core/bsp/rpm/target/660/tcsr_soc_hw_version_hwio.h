#ifndef __TCSR_SOC_HW_VERSION_HWIO_H__
#define __TCSR_SOC_HW_VERSION_HWIO_H__
/*
===========================================================================
*/
/**
  @file tcsr_soc_hw_version_hwio.h
  @brief Auto-generated HWIO interface include file.

  This file contains HWIO register definitions for the following modules:
    TCSR_TCSR_REGS

  'Include' filters applied: HW_VERSION[TCSR_TCSR_REGS] 
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

  $Header: //components/rel/rpm.bf/1.8/core/bsp/rpm/target/660/tcsr_soc_hw_version_hwio.h#2 $
  $DateTime: 2016/11/07 22:46:44 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: TCSR_TCSR_REGS
 *--------------------------------------------------------------------------*/

#define TCSR_TCSR_REGS_REG_BASE                                                                                    (CORE_TOP_CSR_BASE      + 0x000c0000)

#define HWIO_TCSR_SOC_HW_VERSION_ADDR                                                                              (TCSR_TCSR_REGS_REG_BASE      + 0x00008000)
#define HWIO_TCSR_SOC_HW_VERSION_RMSK                                                                              0xffffffff
#define HWIO_TCSR_SOC_HW_VERSION_IN          \
        in_dword_masked(HWIO_TCSR_SOC_HW_VERSION_ADDR, HWIO_TCSR_SOC_HW_VERSION_RMSK)
#define HWIO_TCSR_SOC_HW_VERSION_INM(m)      \
        in_dword_masked(HWIO_TCSR_SOC_HW_VERSION_ADDR, m)
#define HWIO_TCSR_SOC_HW_VERSION_FAMILY_NUMBER_BMSK                                                                0xf0000000
#define HWIO_TCSR_SOC_HW_VERSION_FAMILY_NUMBER_SHFT                                                                      0x1c
#define HWIO_TCSR_SOC_HW_VERSION_DEVICE_NUMBER_BMSK                                                                 0xfff0000
#define HWIO_TCSR_SOC_HW_VERSION_DEVICE_NUMBER_SHFT                                                                      0x10
#define HWIO_TCSR_SOC_HW_VERSION_MAJOR_VERSION_BMSK                                                                    0xff00
#define HWIO_TCSR_SOC_HW_VERSION_MAJOR_VERSION_SHFT                                                                       0x8
#define HWIO_TCSR_SOC_HW_VERSION_MINOR_VERSION_BMSK                                                                      0xff
#define HWIO_TCSR_SOC_HW_VERSION_MINOR_VERSION_SHFT                                                                       0x0


#endif /* __TCSR_SOC_HW_VERSION_HWIO_H__ */
