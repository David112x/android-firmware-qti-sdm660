#ifndef __HAL_CLK_TEST_H__
#define __HAL_CLK_TEST_H__


/*
==============================================================================

FILE:         HALclkTest.h

DESCRIPTION:
  This file contains the ids for configuring the debug clock circuitry
  for the clock HAL.


==============================================================================

                             Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/clk/hw/msm8998/slpi/inc/HALclkTest.h#1 $

when         who     what, where, why
----------   ---     ----------------------------------------------------------- 
06/16/2014           Auto-generated.


==============================================================================
            Copyright (c) 2014 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Defines
** ==========================================================================*/

/*
 * Masks used during test clock frequency calculation setup.
 */
#define HAL_CLK_TEST_TYPE_MASK    (0xF0000)
#define HAL_CLK_TEST_SEL_MASK     (0x07FFF)


/*
 * GCC debug clocks
 */
#define HAL_CLK_GCC_TEST                                              (1  << 0x10)

#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_AXI_CLK                        (HAL_CLK_GCC_TEST | 0x000)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_WEST_AXI_CLK                   (HAL_CLK_GCC_TEST | 0x001)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_EAST_AXI_CLK                   (HAL_CLK_GCC_TEST | 0x002)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_QDSS_STM_AXI_CLK               (HAL_CLK_GCC_TEST | 0x003)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_HMSS_AHB_CLK                   (HAL_CLK_GCC_TEST | 0x004)
#define HAL_CLK_GCC_TEST_GCC_SNOC_CNOC_AHB_CLK                      (HAL_CLK_GCC_TEST | 0x005)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_AT_CLK                         (HAL_CLK_GCC_TEST | 0x006)
#define HAL_CLK_GCC_TEST_GCC_SNOC_QOSGEN_EXTREF                     (HAL_CLK_GCC_TEST | 0x007)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_PIMEM_AXI_CLK                  (HAL_CLK_GCC_TEST | 0x008)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_HS_AXI_CLK                     (HAL_CLK_GCC_TEST | 0x009)
#define HAL_CLK_GCC_TEST_GCC_BIMC_NIUS_HS_AXI_CLK                   (HAL_CLK_GCC_TEST | 0x00A)
#define HAL_CLK_GCC_TEST_GCC_BIMC_NIUS_AXI_CLK                      (HAL_CLK_GCC_TEST | 0x00B)
#define HAL_CLK_GCC_TEST_GCC_BIMC_NIUS_CFG_AHB_CLK                  (HAL_CLK_GCC_TEST | 0x00C)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_DCD_XO_CLK                     (HAL_CLK_GCC_TEST | 0x00D)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x00E)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_WEST_AHB_CLK                   (HAL_CLK_GCC_TEST | 0x00F)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_NORTH_AHB_CLK                  (HAL_CLK_GCC_TEST | 0x010)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_EAST_AHB_CLK                   (HAL_CLK_GCC_TEST | 0x011)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_DDR_CFG_CLK                    (HAL_CLK_GCC_TEST | 0x012)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_TIC_CLK                        (HAL_CLK_GCC_TEST | 0x013)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_USB3_AXI_CLK                   (HAL_CLK_GCC_TEST | 0x014)
#define HAL_CLK_GCC_TEST_GCC_CNOC_PERIPH_WEST_AHB_CLK               (HAL_CLK_GCC_TEST | 0x015)
#define HAL_CLK_GCC_TEST_GCC_CNOC_PERIPH_EAST_AHB_CLK               (HAL_CLK_GCC_TEST | 0x016)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_DCD_XO_CLK                     (HAL_CLK_GCC_TEST | 0x017)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_WEST_DCD_XO_CLK                (HAL_CLK_GCC_TEST | 0x018)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_EAST_DCD_XO_CLK                (HAL_CLK_GCC_TEST | 0x019)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_NORTH_DCD_XO_CLK               (HAL_CLK_GCC_TEST | 0x01A)
#define HAL_CLK_GCC_TEST_GCC_CFG_NOC_AH2PHY_XO_CLK                  (HAL_CLK_GCC_TEST | 0x01B)
#define HAL_CLK_GCC_TEST_GCC_TIC_CFG_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x01C)
#define HAL_CLK_GCC_TEST_GCC_IMEM_AXI_CLK                           (HAL_CLK_GCC_TEST | 0x01D)
#define HAL_CLK_GCC_TEST_GCC_IMEM_CFG_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x01E)
#define HAL_CLK_GCC_TEST_GCC_MMSS_SYS_NOC_AXI_CLK                   (HAL_CLK_GCC_TEST | 0x01F)
#define HAL_CLK_GCC_TEST_GCC_MMSS_NOC_CFG_AHB_CLK                   (HAL_CLK_GCC_TEST | 0x020)
#define HAL_CLK_GCC_TEST_GCC_MMSS_AT_CLK                            (HAL_CLK_GCC_TEST | 0x021)
#define HAL_CLK_GCC_TEST_MMSS_GCC_DBG_CLK                           (HAL_CLK_GCC_TEST | 0x022)
#define HAL_CLK_GCC_TEST_GCC_MMSS_QM_CORE_CLK                       (HAL_CLK_GCC_TEST | 0x023)
#define HAL_CLK_GCC_TEST_GCC_MMSS_TRIG_CLK                          (HAL_CLK_GCC_TEST | 0x024)
#define HAL_CLK_GCC_TEST_GCC_MMSS_QM_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x025)
#define HAL_CLK_GCC_TEST_GCC_MMSS_NOC_AT_CLK                        (HAL_CLK_GCC_TEST | 0x026)
#define HAL_CLK_GCC_TEST_GCC_PIMEM_AXI_CLK                          (HAL_CLK_GCC_TEST | 0x027)
#define HAL_CLK_GCC_TEST_GCC_PIMEM_AHB_CLK                          (HAL_CLK_GCC_TEST | 0x028)
#define HAL_CLK_GCC_TEST_GCC_QDSS_DAP_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x029)
#define HAL_CLK_GCC_TEST_GCC_QDSS_CFG_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x02A)
#define HAL_CLK_GCC_TEST_GCC_QDSS_CENTER_AT_CLK                     (HAL_CLK_GCC_TEST | 0x02B)
#define HAL_CLK_GCC_TEST_GCC_WEST_AT_CLK                            (HAL_CLK_GCC_TEST | 0x02C)
#define HAL_CLK_GCC_TEST_GCC_EAST_AT_CLK                            (HAL_CLK_GCC_TEST | 0x02D)
#define HAL_CLK_GCC_TEST_GCC_NORTH_AT_CLK                           (HAL_CLK_GCC_TEST | 0x02E)
#define HAL_CLK_GCC_TEST_GCC_QDSS_ETR_USB_CLK                       (HAL_CLK_GCC_TEST | 0x02F)
#define HAL_CLK_GCC_TEST_GCC_QDSS_STM_CLK                           (HAL_CLK_GCC_TEST | 0x030)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TRACECLKIN_CLK                    (HAL_CLK_GCC_TEST | 0x031)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TSCTR_DIV2_CLK                    (HAL_CLK_GCC_TEST | 0x032)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TSCTR_DIV3_CLK                    (HAL_CLK_GCC_TEST | 0x033)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TSCTR_DIV4_CLK                    (HAL_CLK_GCC_TEST | 0x034)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TSCTR_DIV8_CLK                    (HAL_CLK_GCC_TEST | 0x035)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TSCTR_DIV16_CLK                   (HAL_CLK_GCC_TEST | 0x036)
#define HAL_CLK_GCC_TEST_GCC_QDSS_TRIG_CLK                          (HAL_CLK_GCC_TEST | 0x037)
#define HAL_CLK_GCC_TEST_GCC_QDSS_DAP_CLK                           (HAL_CLK_GCC_TEST | 0x038)
#define HAL_CLK_GCC_TEST_GCC_EAST_APB_CLK                           (HAL_CLK_GCC_TEST | 0x039)
#define HAL_CLK_GCC_TEST_GCC_WEST_APB_CLK                           (HAL_CLK_GCC_TEST | 0x03A)
#define HAL_CLK_GCC_TEST_GCC_NORTH_APB_CLK                          (HAL_CLK_GCC_TEST | 0x03B)
#define HAL_CLK_GCC_TEST_GCC_CENTER_APB_CLK                         (HAL_CLK_GCC_TEST | 0x03C)
#define HAL_CLK_GCC_TEST_GCC_QDSS_XO_CLK                            (HAL_CLK_GCC_TEST | 0x03D)
#define HAL_CLK_GCC_TEST_GCC_USB30_MASTER_CLK                       (HAL_CLK_GCC_TEST | 0x03E)
#define HAL_CLK_GCC_TEST_GCC_USB30_SLEEP_CLK                        (HAL_CLK_GCC_TEST | 0x03F)
#define HAL_CLK_GCC_TEST_GCC_USB30_MOCK_UTMI_CLK                    (HAL_CLK_GCC_TEST | 0x040)
#define HAL_CLK_GCC_TEST_GCC_USB3_PHY_AUX_CLK                       (HAL_CLK_GCC_TEST | 0x041)
#define HAL_CLK_GCC_TEST_GCC_USB3_PHY_PIPE_CLK                      (HAL_CLK_GCC_TEST | 0x042)
#define HAL_CLK_GCC_TEST_USB3_PHY_WRAPPER_GCC_USB3_PIPE_CLK         (HAL_CLK_GCC_TEST | 0x043)
#define HAL_CLK_GCC_TEST_QUSB2PHY_PRIM_GCC_USB30_UTMI_CLK           (HAL_CLK_GCC_TEST | 0x044)
#define HAL_CLK_GCC_TEST_GCC_USB_PHY_CFG_AHB2PHY_CLK                (HAL_CLK_GCC_TEST | 0x045)
#define HAL_CLK_GCC_TEST_GCC_SDCC2_APPS_CLK                         (HAL_CLK_GCC_TEST | 0x046)
#define HAL_CLK_GCC_TEST_GCC_SDCC2_AHB_CLK                          (HAL_CLK_GCC_TEST | 0x047)
#define HAL_CLK_GCC_TEST_GCC_SDCC4_APPS_CLK                         (HAL_CLK_GCC_TEST | 0x048)
#define HAL_CLK_GCC_TEST_GCC_SDCC4_AHB_CLK                          (HAL_CLK_GCC_TEST | 0x049)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_AHB_CLK                          (HAL_CLK_GCC_TEST | 0x04A)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_SLEEP_CLK                        (HAL_CLK_GCC_TEST | 0x04B)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP1_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x04C)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP1_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x04D)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_UART1_APPS_CLK                   (HAL_CLK_GCC_TEST | 0x04E)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_UART1_SIM_CLK                    (HAL_CLK_GCC_TEST | 0x04F)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP2_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x050)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP2_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x051)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_UART2_APPS_CLK                   (HAL_CLK_GCC_TEST | 0x052)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_UART2_SIM_CLK                    (HAL_CLK_GCC_TEST | 0x053)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP3_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x054)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP3_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x055)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_UART3_APPS_CLK                   (HAL_CLK_GCC_TEST | 0x056)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_UART3_SIM_CLK                    (HAL_CLK_GCC_TEST | 0x057)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP4_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x058)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP4_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x059)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP5_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x05A)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP5_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x05B)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP6_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x05C)
#define HAL_CLK_GCC_TEST_GCC_BLSP1_QUP6_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x05D)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_AHB_CLK                          (HAL_CLK_GCC_TEST | 0x05E)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_SLEEP_CLK                        (HAL_CLK_GCC_TEST | 0x05F)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP1_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x060)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP1_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x061)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_UART1_APPS_CLK                   (HAL_CLK_GCC_TEST | 0x062)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_UART1_SIM_CLK                    (HAL_CLK_GCC_TEST | 0x063)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP2_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x064)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP2_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x065)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_UART2_APPS_CLK                   (HAL_CLK_GCC_TEST | 0x066)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_UART2_SIM_CLK                    (HAL_CLK_GCC_TEST | 0x067)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP3_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x068)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP3_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x069)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_UART3_APPS_CLK                   (HAL_CLK_GCC_TEST | 0x06A)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_UART3_SIM_CLK                    (HAL_CLK_GCC_TEST | 0x06B)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP4_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x06C)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP4_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x06D)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP5_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x06E)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP5_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x06F)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP6_SPI_APPS_CLK                (HAL_CLK_GCC_TEST | 0x070)
#define HAL_CLK_GCC_TEST_GCC_BLSP2_QUP6_I2C_APPS_CLK                (HAL_CLK_GCC_TEST | 0x071)
#define HAL_CLK_GCC_TEST_GCC_PDM_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x072)
#define HAL_CLK_GCC_TEST_GCC_PDM_XO4_CLK                            (HAL_CLK_GCC_TEST | 0x073)
#define HAL_CLK_GCC_TEST_GCC_PDM2_CLK                               (HAL_CLK_GCC_TEST | 0x074)
#define HAL_CLK_GCC_TEST_GCC_PRNG_AHB_CLK                           (HAL_CLK_GCC_TEST | 0x075)
#define HAL_CLK_GCC_TEST_GCC_TSIF_AHB_CLK                           (HAL_CLK_GCC_TEST | 0x076)
#define HAL_CLK_GCC_TEST_GCC_TSIF_REF_CLK                           (HAL_CLK_GCC_TEST | 0x077)
#define HAL_CLK_GCC_TEST_GCC_TSIF_INACTIVITY_TIMERS_CLK             (HAL_CLK_GCC_TEST | 0x078)
#define HAL_CLK_GCC_TEST_GCC_TCSR_AHB_CLK                           (HAL_CLK_GCC_TEST | 0x079)
#define HAL_CLK_GCC_TEST_GCC_BOOT_ROM_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x07A)
#define HAL_CLK_GCC_TEST_GCC_MSG_RAM_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x07B)
#define HAL_CLK_GCC_TEST_GCC_TLMM_NORTH_AHB_CLK                     (HAL_CLK_GCC_TEST | 0x07C)
#define HAL_CLK_GCC_TEST_GCC_TLMM_WEST_AHB_CLK                      (HAL_CLK_GCC_TEST | 0x07D)
#define HAL_CLK_GCC_TEST_GCC_TLMM_EAST_AHB_CLK                      (HAL_CLK_GCC_TEST | 0x07E)
#define HAL_CLK_GCC_TEST_GCC_TLMM_CLK                               (HAL_CLK_GCC_TEST | 0x07F)
#define HAL_CLK_GCC_TEST_GCC_MPM_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x080)
#define HAL_CLK_GCC_TEST_GCC_RPM_PROC_FCLK                          (HAL_CLK_GCC_TEST | 0x081)
#define HAL_CLK_GCC_TEST_GCC_RPM_PROC_HCLK                          (HAL_CLK_GCC_TEST | 0x082)
#define HAL_CLK_GCC_TEST_GCC_RPM_BUS_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x083)
#define HAL_CLK_GCC_TEST_GCC_RPM_SLEEP_CLK                          (HAL_CLK_GCC_TEST | 0x084)
#define HAL_CLK_GCC_TEST_GCC_RPM_TIMER_CLK                          (HAL_CLK_GCC_TEST | 0x085)
#define HAL_CLK_GCC_TEST_GCC_RPM_MST_M2_CNOC_AHB_CLK                (HAL_CLK_GCC_TEST | 0x086)
#define HAL_CLK_GCC_TEST_GCC_CNOC_MST_RPM_AHB_CLK                   (HAL_CLK_GCC_TEST | 0x087)
#define HAL_CLK_GCC_TEST_GCC_SEC_CTRL_ACC_CLK                       (HAL_CLK_GCC_TEST | 0x088)
#define HAL_CLK_GCC_TEST_GCC_SEC_CTRL_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x089)
#define HAL_CLK_GCC_TEST_GCC_SEC_CTRL_CLK                           (HAL_CLK_GCC_TEST | 0x08A)
#define HAL_CLK_GCC_TEST_GCC_SEC_CTRL_SENSE_CLK                     (HAL_CLK_GCC_TEST | 0x08B)
#define HAL_CLK_GCC_TEST_GCC_SEC_CTRL_BOOT_ROM_PATCH_CLK            (HAL_CLK_GCC_TEST | 0x08C)
#define HAL_CLK_GCC_TEST_GCC_SPMI_SER_CLK                           (HAL_CLK_GCC_TEST | 0x08D)
#define HAL_CLK_GCC_TEST_GCC_SPMI_CNOC_AHB_CLK                      (HAL_CLK_GCC_TEST | 0x08E)
#define HAL_CLK_GCC_TEST_GCC_SPMI_AHB_CLK                           (HAL_CLK_GCC_TEST | 0x08F)
#define HAL_CLK_GCC_TEST_GCC_SPDM_CFG_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x090)
#define HAL_CLK_GCC_TEST_GCC_SPDM_MSTR_AHB_CLK                      (HAL_CLK_GCC_TEST | 0x091)
#define HAL_CLK_GCC_TEST_GCC_SPDM_FF_CLK                            (HAL_CLK_GCC_TEST | 0x092)
#define HAL_CLK_GCC_TEST_GCC_SPDM_BIMC_CY_CLK                       (HAL_CLK_GCC_TEST | 0x093)
#define HAL_CLK_GCC_TEST_GCC_SPDM_SNOC_CY_CLK                       (HAL_CLK_GCC_TEST | 0x094)
#define HAL_CLK_GCC_TEST_GCC_SPDM_PNOC_CY_CLK                       (HAL_CLK_GCC_TEST | 0x095)
#define HAL_CLK_GCC_TEST_GCC_SPDM_RPM_CY_CLK                        (HAL_CLK_GCC_TEST | 0x096)
#define HAL_CLK_GCC_TEST_GCC_CE1_CLK                                (HAL_CLK_GCC_TEST | 0x097)
#define HAL_CLK_GCC_TEST_GCC_CE1_AXI_CLK                            (HAL_CLK_GCC_TEST | 0x098)
#define HAL_CLK_GCC_TEST_GCC_CE1_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x099)
#define HAL_CLK_GCC_TEST_GCC_AHB_CLK                                (HAL_CLK_GCC_TEST | 0x09A)
#define HAL_CLK_GCC_TEST_GCC_XO_CLK                                 (HAL_CLK_GCC_TEST | 0x09B)
#define HAL_CLK_GCC_TEST_GCC_XO_DIV4_CLK                            (HAL_CLK_GCC_TEST | 0x09C)
#define HAL_CLK_GCC_TEST_GCC_IM_SLEEP_CLK                           (HAL_CLK_GCC_TEST | 0x09D)
#define HAL_CLK_GCC_TEST_GCC_BIMC_XO_CLK                            (HAL_CLK_GCC_TEST | 0x09E)
#define HAL_CLK_GCC_TEST_GCC_BIMC_CFG_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x09F)
#define HAL_CLK_GCC_TEST_GCC_BIMC_SLEEP_CLK                         (HAL_CLK_GCC_TEST | 0x0A0)
#define HAL_CLK_GCC_TEST_GCC_BIMC_SYSNOC_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x0A1)
#define HAL_CLK_GCC_TEST_GCC_BIMC_CLK                               (HAL_CLK_GCC_TEST | 0x0A2)
#define HAL_CLK_GCC_TEST_GCC_BIMC_MSS_Q6_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x0A3)
#define HAL_CLK_GCC_TEST_GCC_BIMC_AT_CLK                            (HAL_CLK_GCC_TEST | 0x0A4)
#define HAL_CLK_GCC_TEST_GCC_BIMC_SYSNOC_HS_AXI_CLK                 (HAL_CLK_GCC_TEST | 0x0A5)
#define HAL_CLK_GCC_TEST_GCC_BIMC_PIMEM_AXI_CLK                     (HAL_CLK_GCC_TEST | 0x0A6)
#define HAL_CLK_GCC_TEST_GCC_BIMC_DTTS_XO_CLK                       (HAL_CLK_GCC_TEST | 0x0A7)
#define HAL_CLK_GCC_TEST_GCC_DDR_DIM_CFG_CLK                        (HAL_CLK_GCC_TEST | 0x0A8)
#define HAL_CLK_GCC_TEST_GCC_BIMC_DDR_CPLL0_CLK                     (HAL_CLK_GCC_TEST | 0x0A9)
#define HAL_CLK_GCC_TEST_GCC_BIMC_DDR_CPLL1_CLK                     (HAL_CLK_GCC_TEST | 0x0AA)
#define HAL_CLK_GCC_TEST_GCC_DDR_DIM_SLEEP_CLK                      (HAL_CLK_GCC_TEST | 0x0AB)
#define HAL_CLK_GCC_TEST_GCC_BIMC_GFX_CLK                           (HAL_CLK_GCC_TEST | 0x0AC)
#define HAL_CLK_GCC_TEST_GCC_MCCC_CFG_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x0AD)
#define HAL_CLK_GCC_TEST_GCC_LPASS_Q6_AXI_CLK                       (HAL_CLK_GCC_TEST | 0x0AE)
#define HAL_CLK_GCC_TEST_GCC_LPASS_Q6_SMMU_AXI_SRC_CLK              (HAL_CLK_GCC_TEST | 0x0AF)
#define HAL_CLK_GCC_TEST_GCC_LPASS_Q6_SMMU_AXI_CLK                  (HAL_CLK_GCC_TEST | 0x0B0)
#define HAL_CLK_GCC_TEST_GCC_LPASS_SWAY_CLK                         (HAL_CLK_GCC_TEST | 0x0B1)
#define HAL_CLK_GCC_TEST_GCC_LPASS_Q6_SMMU_AHB_CLK                  (HAL_CLK_GCC_TEST | 0x0B2)
#define HAL_CLK_GCC_TEST_GCC_LPASS_CORE_SMMU_AHB_CLK                (HAL_CLK_GCC_TEST | 0x0B3)
#define HAL_CLK_GCC_TEST_GCC_LPASS_SMMU_AON_AHB_CLK                 (HAL_CLK_GCC_TEST | 0x0B4)
#define HAL_CLK_GCC_TEST_GCC_LPASS_TRIG_CLK                         (HAL_CLK_GCC_TEST | 0x0B5)
#define HAL_CLK_GCC_TEST_GCC_LPASS_AT_CLK                           (HAL_CLK_GCC_TEST | 0x0B6)
#define HAL_CLK_GCC_TEST_GCC_LPASS_CORE_SMMU_CLIENT_SRC_CLK         (HAL_CLK_GCC_TEST | 0x0B7)
#define HAL_CLK_GCC_TEST_GCC_LPASS_CORE_SMMU_CLIENT_CLK             (HAL_CLK_GCC_TEST | 0x0B8)
#define HAL_CLK_GCC_TEST_LPASS_GCC_DBG_CLK                          (HAL_CLK_GCC_TEST | 0x0B9)
#define HAL_CLK_GCC_TEST_GCC_HMSS_AHB_CLK                           (HAL_CLK_GCC_TEST | 0x0BA)
#define HAL_CLK_GCC_TEST_GCC_BIMC_HMSS_AXI_CLK                      (HAL_CLK_GCC_TEST | 0x0BB)
#define HAL_CLK_GCC_TEST_GCC_HMSS_RBCPR_CLK                         (HAL_CLK_GCC_TEST | 0x0BC)
#define HAL_CLK_GCC_TEST_GCC_HMSS_TRIG_CLK                          (HAL_CLK_GCC_TEST | 0x0BD)
#define HAL_CLK_GCC_TEST_GCC_HMSS_AT_CLK                            (HAL_CLK_GCC_TEST | 0x0BE)
#define HAL_CLK_GCC_TEST_GCC_HMSS_DVM_BUS_CLK                       (HAL_CLK_GCC_TEST | 0x0BF)
#define HAL_CLK_GCC_TEST_HMSS_GCC_DBG_CLK                           (HAL_CLK_GCC_TEST | 0x0C0)
#define HAL_CLK_GCC_TEST_GCC_SNOC_BUS_TIMEOUT0_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0C1)
#define HAL_CLK_GCC_TEST_GCC_SNOC_BUS_TIMEOUT1_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0C2)
#define HAL_CLK_GCC_TEST_GCC_SNOC_BUS_TIMEOUT3_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0C3)
#define HAL_CLK_GCC_TEST_GCC_SNOC_BUS_TIMEOUT_EXTREF                (HAL_CLK_GCC_TEST | 0x0C4)
#define HAL_CLK_GCC_TEST_GCC_CNOC_PERIPH_BUS_TIMEOUT1_AHB_CLK       (HAL_CLK_GCC_TEST | 0x0C5)
#define HAL_CLK_GCC_TEST_GCC_CNOC_PERIPH_BUS_TIMEOUT2_AHB_CLK       (HAL_CLK_GCC_TEST | 0x0C6)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT0_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0C7)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT1_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0C8)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT2_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0C9)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT3_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0CA)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT4_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0CB)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT5_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0CC)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT6_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0CD)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT7_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0CE)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT8_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0CF)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT9_AHB_CLK              (HAL_CLK_GCC_TEST | 0x0D0)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT10_AHB_CLK             (HAL_CLK_GCC_TEST | 0x0D1)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT11_AHB_CLK             (HAL_CLK_GCC_TEST | 0x0D2)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT12_AHB_CLK             (HAL_CLK_GCC_TEST | 0x0D3)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT13_AHB_CLK             (HAL_CLK_GCC_TEST | 0x0D4)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT14_AHB_CLK             (HAL_CLK_GCC_TEST | 0x0D5)
#define HAL_CLK_GCC_TEST_GCC_CNOC_BUS_TIMEOUT_EXTREF                (HAL_CLK_GCC_TEST | 0x0D6)
#define HAL_CLK_GCC_TEST_GCC_QDSS_APB2JTAG_CLK                      (HAL_CLK_GCC_TEST | 0x0D7)
#define HAL_CLK_GCC_TEST_GCC_RBCPR_CX_CLK                           (HAL_CLK_GCC_TEST | 0x0D8)
#define HAL_CLK_GCC_TEST_GCC_RBCPR_CX_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x0D9)
#define HAL_CLK_GCC_TEST_GCC_RBCPR_MX_CLK                           (HAL_CLK_GCC_TEST | 0x0DA)
#define HAL_CLK_GCC_TEST_GCC_RBCPR_MX_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x0DB)
#define HAL_CLK_GCC_TEST_QUSB2PHY_GCC_CLK_TEST_PRIM                 (HAL_CLK_GCC_TEST | 0x0DC)
#define HAL_CLK_GCC_TEST_MPM_GCC_TEMP0_SENSOR_RINGOSC_CLK           (HAL_CLK_GCC_TEST | 0x0DD)
#define HAL_CLK_GCC_TEST_MPM_GCC_TEMP1_SENSOR_RINGOSC_CLK           (HAL_CLK_GCC_TEST | 0x0DE)
#define HAL_CLK_GCC_TEST_GCC_GP1_CLK                                (HAL_CLK_GCC_TEST | 0x0DF)
#define HAL_CLK_GCC_TEST_GCC_GP2_CLK                                (HAL_CLK_GCC_TEST | 0x0E0)
#define HAL_CLK_GCC_TEST_GCC_GP3_CLK                                (HAL_CLK_GCC_TEST | 0x0E1)
#define HAL_CLK_GCC_TEST_GCC_PCIE_0_SLV_AXI_CLK                     (HAL_CLK_GCC_TEST | 0x0E2)
#define HAL_CLK_GCC_TEST_GCC_PCIE_0_MSTR_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x0E3)
#define HAL_CLK_GCC_TEST_GCC_PCIE_0_CFG_AHB_CLK                     (HAL_CLK_GCC_TEST | 0x0E4)
#define HAL_CLK_GCC_TEST_GCC_PCIE_0_AUX_CLK                         (HAL_CLK_GCC_TEST | 0x0E5)
#define HAL_CLK_GCC_TEST_GCC_PCIE_0_PIPE_CLK                        (HAL_CLK_GCC_TEST | 0x0E6)
#define HAL_CLK_GCC_TEST_GCC_PCIE_PHY_AUX_CLK                       (HAL_CLK_GCC_TEST | 0x0E8)
#define HAL_CLK_GCC_TEST_GCC_OBT_ODT_CLK                            (HAL_CLK_GCC_TEST | 0x0E9)
#define HAL_CLK_GCC_TEST_GCC_UFS_AXI_CLK                            (HAL_CLK_GCC_TEST | 0x0EA)
#define HAL_CLK_GCC_TEST_GCC_UFS_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x0EB)
#define HAL_CLK_GCC_TEST_GCC_UFS_TX_SYMBOL_0_CLK                    (HAL_CLK_GCC_TEST | 0x0EC)
#define HAL_CLK_GCC_TEST_GCC_UFS_RX_SYMBOL_0_CLK                    (HAL_CLK_GCC_TEST | 0x0ED)
#define HAL_CLK_GCC_TEST_UFS_TX_SYMBOL_0_CLK                        (HAL_CLK_GCC_TEST | 0x0EE)
#define HAL_CLK_GCC_TEST_UFS_RX_SYMBOL_0_CLK                        (HAL_CLK_GCC_TEST | 0x0EF)
#define HAL_CLK_GCC_TEST_GCC_UFS_UNIPRO_CORE_CLK                    (HAL_CLK_GCC_TEST | 0x0F0)
#define HAL_CLK_GCC_TEST_GCC_UFS_ICE_CORE_CLK                       (HAL_CLK_GCC_TEST | 0x0F1)
#define HAL_CLK_GCC_TEST_GCC_UFS_PHY_AUX_CLK                        (HAL_CLK_GCC_TEST | 0x0F2)
#define HAL_CLK_GCC_TEST_GCC_SSC_SNOC_AHBM_CLK                      (HAL_CLK_GCC_TEST | 0x0F3)
#define HAL_CLK_GCC_TEST_GCC_SYS_NOC_SSC_Q6_AXI_CLK                 (HAL_CLK_GCC_TEST | 0x0F4)
#define HAL_CLK_GCC_TEST_GCC_SSC_CNOC_AHBS_CLK                      (HAL_CLK_GCC_TEST | 0x0F5)
#define HAL_CLK_GCC_TEST_GCC_SSC_CNOC_MPU_CLK                       (HAL_CLK_GCC_TEST | 0x0F6)
#define HAL_CLK_GCC_TEST_GCC_SSC_AT_CLK                             (HAL_CLK_GCC_TEST | 0x0F7)
#define HAL_CLK_GCC_TEST_GCC_SSC_XO_CLK                             (HAL_CLK_GCC_TEST | 0x0F8)
#define HAL_CLK_GCC_TEST_GCC_SSC_APB_CLK                            (HAL_CLK_GCC_TEST | 0x0F9)
#define HAL_CLK_GCC_TEST_SSC_GCC_DBG_CLK                            (HAL_CLK_GCC_TEST | 0x0FA)
#define HAL_CLK_GCC_TEST_GCC_VDDCX_VS_CLK                           (HAL_CLK_GCC_TEST | 0x0FB)
#define HAL_CLK_GCC_TEST_GCC_VDDMX_VS_CLK                           (HAL_CLK_GCC_TEST | 0x0FC)
#define HAL_CLK_GCC_TEST_GCC_VDDA_VS_CLK                            (HAL_CLK_GCC_TEST | 0x0FD)
#define HAL_CLK_GCC_TEST_GCC_VS_CTRL_CLK                            (HAL_CLK_GCC_TEST | 0x0FE)
#define HAL_CLK_GCC_TEST_GCC_MSS_VS_CLK                             (HAL_CLK_GCC_TEST | 0x0FF)
#define HAL_CLK_GCC_TEST_GCC_GPU_VS_CLK                             (HAL_CLK_GCC_TEST | 0x100)
#define HAL_CLK_GCC_TEST_GCC_APC0_VS_CLK                            (HAL_CLK_GCC_TEST | 0x101)
#define HAL_CLK_GCC_TEST_GCC_APC1_VS_CLK                            (HAL_CLK_GCC_TEST | 0x102)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_SNOC_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x103)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_CNOC_AHB_CLK                    (HAL_CLK_GCC_TEST | 0x104)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_NOC_AT_CLK                      (HAL_CLK_GCC_TEST | 0x105)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_CNOC_PERIPH_AHB_CLK             (HAL_CLK_GCC_TEST | 0x106)
#define HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE1_AXI_SRC_CLK                (HAL_CLK_GCC_TEST | 0x107)
#define HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE1_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x108)
#define HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE1_AHB_CLK                    (HAL_CLK_GCC_TEST | 0x109)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_USB3_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x10A)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_UFS_AXI_CLK                     (HAL_CLK_GCC_TEST | 0x10B)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_NOC_XO_CLK                      (HAL_CLK_GCC_TEST | 0x10C)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_NOC_QOSGEN_EXTREF               (HAL_CLK_GCC_TEST | 0x10D)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x10E)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_EAST_AXI_CLK               (HAL_CLK_GCC_TEST | 0x10F)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_NORTH_AXI_CLK              (HAL_CLK_GCC_TEST | 0x110)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_CNOC_AHB_CLK                    (HAL_CLK_GCC_TEST | 0x111)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_NOC_AT_CLK                      (HAL_CLK_GCC_TEST | 0x112)
#define HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE2_AXI_SRC_CLK                (HAL_CLK_GCC_TEST | 0x113)
#define HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE2_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x114)
#define HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE2_AHB_CLK                    (HAL_CLK_GCC_TEST | 0x115)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_NOC_QOSGEN_EXTREF               (HAL_CLK_GCC_TEST | 0x116)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_NOC_IPA_CLK                     (HAL_CLK_GCC_TEST | 0x117)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_CNOC_PERIPH_AHB_CLK             (HAL_CLK_GCC_TEST | 0x118)
#define HAL_CLK_GCC_TEST_GCC_DCC_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x119)
#define HAL_CLK_GCC_TEST_GCC_IPA_2X_CLK                             (HAL_CLK_GCC_TEST | 0x11A)
#define HAL_CLK_GCC_TEST_GCC_IPA_CLK                                (HAL_CLK_GCC_TEST | 0x11B)
#define HAL_CLK_GCC_TEST_GCC_IPA_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x11C)
#define HAL_CLK_GCC_TEST_GCC_IPA_SLEEP_CLK                          (HAL_CLK_GCC_TEST | 0x11D)
#define HAL_CLK_GCC_TEST_GCC_MSS_CFG_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x11F)
#define HAL_CLK_GCC_TEST_GCC_MSS_MNOC_BIMC_AXI_CLK                  (HAL_CLK_GCC_TEST | 0x120)
#define HAL_CLK_GCC_TEST_GCC_MSS_TRIG_CLK                           (HAL_CLK_GCC_TEST | 0x121)
#define HAL_CLK_GCC_TEST_GCC_MSS_AT_CLK                             (HAL_CLK_GCC_TEST | 0x122)
#define HAL_CLK_GCC_TEST_GCC_MSS_SNOC_AXI_CLK                       (HAL_CLK_GCC_TEST | 0x123)
#define HAL_CLK_GCC_TEST_GCC_MSS_Q6_BIMC_AXI_CLK                    (HAL_CLK_GCC_TEST | 0x124)
#define HAL_CLK_GCC_TEST_MSS_GCC_DBG_CLK                            (HAL_CLK_GCC_TEST | 0x125)
#define HAL_CLK_GCC_TEST_GCC_GLM_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x126)
#define HAL_CLK_GCC_TEST_GCC_GLM_CLK                                (HAL_CLK_GCC_TEST | 0x127)
#define HAL_CLK_GCC_TEST_GCC_GLM_XO_CLK                             (HAL_CLK_GCC_TEST | 0x128)
#define HAL_CLK_GCC_TEST_GCC_SKL_AHB_CLK                            (HAL_CLK_GCC_TEST | 0x129)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_NOC_MSMPU_CFG_AHB_CLK           (HAL_CLK_GCC_TEST | 0x12A)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_NOC_MSMPU_CFG_AHB_CLK           (HAL_CLK_GCC_TEST | 0x12B)
#define HAL_CLK_GCC_TEST_GCC_MSS_Q6_MSMPU_CFG_AHB_CLK               (HAL_CLK_GCC_TEST | 0x12C)
#define HAL_CLK_GCC_TEST_GCC_MSS_MSMPU_CFG_AHB_CLK                  (HAL_CLK_GCC_TEST | 0x12D)
#define HAL_CLK_GCC_TEST_GCC_AGGRE1_SNOC_MSMPU_CLIENT_AXI_CLK       (HAL_CLK_GCC_TEST | 0x12E)
#define HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_MSMPU_CLIENT_AXI_CLK       (HAL_CLK_GCC_TEST | 0x12F)
#define HAL_CLK_GCC_TEST_GCC_MSS_Q6_MSMPU_CLIENT_AXI_CLK            (HAL_CLK_GCC_TEST | 0x130)
#define HAL_CLK_GCC_TEST_GCC_MSS_MSMPU_CLIENT_AXI_CLK               (HAL_CLK_GCC_TEST | 0x131)
#define HAL_CLK_GCC_TEST_GCC_QREFS_VBG_CAL_CLK                      (HAL_CLK_GCC_TEST | 0x132)
#define HAL_CLK_GCC_TEST_GCC_WCSS_AHB_S0_CLK                        (HAL_CLK_GCC_TEST | 0x133)
#define HAL_CLK_GCC_TEST_GCC_WCSS_AXI_M_CLK                         (HAL_CLK_GCC_TEST | 0x134)
#define HAL_CLK_GCC_TEST_GCC_WCSS_ECAHB_CLK                         (HAL_CLK_GCC_TEST | 0x135)
#define HAL_CLK_GCC_TEST_GCC_WCSS_SHDREG_AHB_CLK                    (HAL_CLK_GCC_TEST | 0x136)
#define HAL_CLK_GCC_TEST_GCC_WCSS_AT_CLK                            (HAL_CLK_GCC_TEST | 0x137)
#define HAL_CLK_GCC_TEST_GCC_WCSS_TSCTR_DIV2_CLK                    (HAL_CLK_GCC_TEST | 0x138)
#define HAL_CLK_GCC_TEST_GCC_WCSS_APB_CLK                           (HAL_CLK_GCC_TEST | 0x139)
#define HAL_CLK_GCC_TEST_WCSS_GCC_DBG_CLK                           (HAL_CLK_GCC_TEST | 0x13A)
#define HAL_CLK_GCC_TEST_GCC_GPU_CFG_AHB_CLK                        (HAL_CLK_GCC_TEST | 0x13B)
#define HAL_CLK_GCC_TEST_GCC_GPU_AT_CLK                             (HAL_CLK_GCC_TEST | 0x13C)
#define HAL_CLK_GCC_TEST_GPU_GCC_DBG_CLK                            (HAL_CLK_GCC_TEST | 0x13D)
#define HAL_CLK_GCC_TEST_GCC_GPU_BIMC_GFX_SRC_CLK                   (HAL_CLK_GCC_TEST | 0x13E)
#define HAL_CLK_GCC_TEST_GCC_GPU_BIMC_GFX_CLK                       (HAL_CLK_GCC_TEST | 0x13F)
#define HAL_CLK_GCC_TEST_GCC_GPU_TRIG_CLK                           (HAL_CLK_GCC_TEST | 0x140)
#define HAL_CLK_GCC_TEST_GCC_GPU_SNOC_DVM_GFX_CLK                   (HAL_CLK_GCC_TEST | 0x141)
#define HAL_CLK_GCC_TEST_GCC_SPSS_SNOC_EMM_CLK                      (HAL_CLK_GCC_TEST | 0x142)
#define HAL_CLK_GCC_TEST_GCC_SPSS_CFG_AHB_CLK                       (HAL_CLK_GCC_TEST | 0x143)
#define HAL_CLK_GCC_TEST_GCC_SPSS_SCSR_CLK                          (HAL_CLK_GCC_TEST | 0x144)
#define HAL_CLK_GCC_TEST_GCC_SPSS_SEC_CTRL_CLK                      (HAL_CLK_GCC_TEST | 0x145)
#define HAL_CLK_GCC_TEST_GCC_SPSS_XO_CLK                            (HAL_CLK_GCC_TEST | 0x146)
#define HAL_CLK_GCC_TEST_GCC_SPSS_TRIG_CLK                          (HAL_CLK_GCC_TEST | 0x147)
#define HAL_CLK_GCC_TEST_SPSS_GCC_DBG_CLK                           (HAL_CLK_GCC_TEST | 0x148)
#define HAL_CLK_GCC_TEST_NAV_GCC_DBG_CLK                            (HAL_CLK_GCC_TEST | 0x149)
#define HAL_CLK_GCC_TEST_GCC_AHB2PHY_EAST_CLK                       (HAL_CLK_GCC_TEST | 0x14A)
#define HAL_CLK_GCC_TEST_GCC_CM_PHY_REFGEN1_CLK                     (HAL_CLK_GCC_TEST | 0x14B)
#define HAL_CLK_GCC_TEST_GCC_CM_PHY_REFGEN2_CLK                     (HAL_CLK_GCC_TEST | 0x14C)
#define HAL_CLK_GCC_TEST_GCC_SRAM_SENSOR_XO_CLK                     (HAL_CLK_GCC_TEST | 0x14D)
#define HAL_CLK_GCC_TEST_PCIE_0_PIPE_CLK                            (HAL_CLK_GCC_TEST | 0x15F)


/*
 * LPASS debug clocks
 */
#define HAL_CLK_LPASS_TEST                                              (3  << 0x10)

#define HAL_CLK_LPASS_TEST_SLEEP_CLK_SRC                            (HAL_CLK_LPASS_TEST | 0x00A)
#define HAL_CLK_LPASS_TEST_LPAIF_SPKR_CLK_SRC                       (HAL_CLK_LPASS_TEST | 0x00B)
#define HAL_CLK_LPASS_TEST_LPAIF_PRI_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x00C)
#define HAL_CLK_LPASS_TEST_LPAIF_SEC_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x00D)
#define HAL_CLK_LPASS_TEST_LPAIF_TER_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x00E)
#define HAL_CLK_LPASS_TEST_LPAIF_QUAD_CLK_SRC                       (HAL_CLK_LPASS_TEST | 0x00F)
#define HAL_CLK_LPASS_TEST_LPAIF_PCMOE_CLK_SRC                      (HAL_CLK_LPASS_TEST | 0x010)
#define HAL_CLK_LPASS_TEST_ATIME_CLK_SRC                            (HAL_CLK_LPASS_TEST | 0x011)
#define HAL_CLK_LPASS_TEST_RESAMPLER_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x012)
#define HAL_CLK_LPASS_TEST_AUD_SLIMBUS_CLK_SRC                      (HAL_CLK_LPASS_TEST | 0x013)
#define HAL_CLK_LPASS_TEST_QCA_SLIMBUS_CLK_SRC                      (HAL_CLK_LPASS_TEST | 0x014)
#define HAL_CLK_LPASS_TEST_CORE_CLK_SRC                             (HAL_CLK_LPASS_TEST | 0x015)
#define HAL_CLK_LPASS_TEST_AON_CLK_SRC                              (HAL_CLK_LPASS_TEST | 0x016)
#define HAL_CLK_LPASS_TEST_EXT_MCLK0_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x018)
#define HAL_CLK_LPASS_TEST_EXT_MCLK1_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x019)
#define HAL_CLK_LPASS_TEST_EXT_MCLK2_CLK_SRC                        (HAL_CLK_LPASS_TEST | 0x01A)
#define HAL_CLK_LPASS_TEST_XO_CLK_SRC                               (HAL_CLK_LPASS_TEST | 0x01D)
#define HAL_CLK_LPASS_TEST_QOS_FIXED_LAT_COUNTER_CLK_SRC            (HAL_CLK_LPASS_TEST | 0x022)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_GDSC_XO_CLK             (HAL_CLK_LPASS_TEST | 0x023)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_CODEC_SPKR_OSR_CLK     (HAL_CLK_LPASS_TEST | 0x024)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_CODEC_SPKR_IBIT_CLK     (HAL_CLK_LPASS_TEST | 0x025)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_PRI_IBIT_CLK      (HAL_CLK_LPASS_TEST | 0x027)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_SEC_IBIT_CLK      (HAL_CLK_LPASS_TEST | 0x029)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_TER_IBIT_CLK      (HAL_CLK_LPASS_TEST | 0x02B)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_QUAD_IBIT_CLK     (HAL_CLK_LPASS_TEST | 0x02D)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPAIF_PCM_DATA_OE_CLK     (HAL_CLK_LPASS_TEST | 0x02E)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_AVSYNC_ATIME_CLK        (HAL_CLK_LPASS_TEST | 0x02F)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_AVSYNC_STC_CLK          (HAL_CLK_LPASS_TEST | 0x030)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_RESAMPLER_CLK           (HAL_CLK_LPASS_TEST | 0x031)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_AUD_SLIMBUS_CLK         (HAL_CLK_LPASS_TEST | 0x032)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_QCA_SLIMBUS_CLK         (HAL_CLK_LPASS_TEST | 0x033)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_CORE_CLK                (HAL_CLK_LPASS_TEST | 0x034)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_SYSNOC_MPORT_CORE_CLK     (HAL_CLK_LPASS_TEST | 0x035)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_AUD_SLIMBUS_CORE_CLK     (HAL_CLK_LPASS_TEST | 0x036)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_QCA_SLIMBUS_CORE_CLK     (HAL_CLK_LPASS_TEST | 0x037)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPM_MEM0_CORE_CLK       (HAL_CLK_LPASS_TEST | 0x038)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPM_MEM1_CORE_CLK       (HAL_CLK_LPASS_TEST | 0x039)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPM_MEM2_CORE_CLK       (HAL_CLK_LPASS_TEST | 0x03A)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPM_MEM3_CORE_CLK       (HAL_CLK_LPASS_TEST | 0x03B)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_QDSP_SWAY_AON_CLK       (HAL_CLK_LPASS_TEST | 0x03D)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_PERIPHERAL_SMMU_CFG_CNOC_CLK     (HAL_CLK_LPASS_TEST | 0x03E)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_SYSNOC_SWAY_SNOC_CLK     (HAL_CLK_LPASS_TEST | 0x03F)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_BCR_SLP_CLK             (HAL_CLK_LPASS_TEST | 0x040)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_SYSNOC_SWAY_SNOC_CLK     (HAL_CLK_LPASS_TEST | 0x043)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_AON_CLK              (HAL_CLK_LPASS_TEST | 0x044)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_QOS_AHBS_AON_CLK     (HAL_CLK_LPASS_TEST | 0x045)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_EXT_MCLK0_CLK        (HAL_CLK_LPASS_TEST | 0x046)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_EXT_MCLK1_CLK        (HAL_CLK_LPASS_TEST | 0x047)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_EXT_MCLK2_CLK        (HAL_CLK_LPASS_TEST | 0x048)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_SYSNOC_SWAY_AON_CLK     (HAL_CLK_LPASS_TEST | 0x049)
#define HAL_CLK_LPASS_TEST_LPASS_Q6SS_AHBM_AON_CLK                  (HAL_CLK_LPASS_TEST | 0x04A)
#define HAL_CLK_LPASS_TEST_LPASS_Q6SS_BCR_SLP_CLK                   (HAL_CLK_LPASS_TEST | 0x04B)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_Q6_SMMU_GDSC_XO_CLK     (HAL_CLK_LPASS_TEST | 0x04C)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_MPU_CFG_AON_CLK      (HAL_CLK_LPASS_TEST | 0x04E)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_Q6_AHBM_MPU_AON_CLK     (HAL_CLK_LPASS_TEST | 0x04F)
#define HAL_CLK_LPASS_TEST_LPASS_Q6SS_AHBS_AON_CLK                  (HAL_CLK_LPASS_TEST | 0x050)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_QOS_XO_LAT_COUNTER_CLK     (HAL_CLK_LPASS_TEST | 0x051)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_QOS_DMONITOR_FIXED_LAT_COUNTER_CLK     (HAL_CLK_LPASS_TEST | 0x052)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_QOS_DANGER_FIXED_LAT_COUNTER_CLK     (HAL_CLK_LPASS_TEST | 0x053)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_QOS_DMONITOR_FIXED_LAT_COUNTER_CLK     (HAL_CLK_LPASS_TEST | 0x055)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_BUS_TIMEOUT_CORE_CLK     (HAL_CLK_LPASS_TEST | 0x056)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_WRAPPER_BUS_TIMEOUT_AON_CLK     (HAL_CLK_LPASS_TEST | 0x056)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_LPM_CORE_CLK            (HAL_CLK_LPASS_TEST | 0x057)
#define HAL_CLK_LPASS_TEST_LPASS_AUDIO_CORE_AUD_SLIMBUS_NPL_CLK     (HAL_CLK_LPASS_TEST | 0x058)


#endif // __HAL_CLK_TEST_H__

