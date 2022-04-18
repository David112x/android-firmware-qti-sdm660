/*
==============================================================================

FILE:         HALclkSYSTEMNOC.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   SYSTEMNOC clocks.

   List of clock domains:
     - HAL_clk_mGCCSYSNOCHSAXIClkDomain
     - HAL_clk_mGCCSYSTEMNOCClkDomain


   List of power domains:



==============================================================================

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/clk/hw/msm8998/slpi/src/gcc/HALclkSYSTEMNOC.c#1 $

==============================================================================
            Copyright (c) 2015 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


#include <HALhwio.h>

#include "HALclkInternal.h"
#include "HALclkTest.h"
#include "HALclkGeneric.h"
#include "HALclkHWIO.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Prototypes
** ==========================================================================*/


/* ============================================================================
**    Externs
** ==========================================================================*/

extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControl_2;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControlRO_2;


/* ============================================================================
**    Data
** ==========================================================================*/


/*                           
 *  HAL_clk_mSYSNOCHSAXIClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mSYSNOCHSAXIClkDomainClks[] =
{
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_bimc_nius_hs_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BIMC_NIUS_HS_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BIMC_NIUS_HS_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_bimc_sysnoc_hs_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BIMC_SYSNOC_HS_AXI_CBCR), HWIO_OFFS(GCC_BIMC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BIMC_SYSNOC_HS_AXI_CLK
  },
#endif

  {
    /* .szClockName      = */ "gcc_lpass_q6_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_LPASS_Q6_AXI_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_LPASS_Q6_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_lpass_q6_smmu_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_LPASS_Q6_SMMU_AXI_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_LPASS_Q6_SMMU_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_lpass_q6_smmu_axi_src_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_LPASS_Q6_SMMU_AXI_SRC_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_LPASS_Q6_SMMU_AXI_SRC_CLK
  },
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_mss_mnoc_bimc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MSS_MNOC_BIMC_AXI_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MSS_MNOC_BIMC_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_mss_msmpu_client_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MSS_MSMPU_CLIENT_AXI_CBCR), HWIO_OFFS(GCC_MSMPU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MSS_MSMPU_CLIENT_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_sys_noc_hs_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_HS_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_HS_AXI_CLK
  },
#endif

};


/*
 * HAL_clk_mGCCSYSNOCHSAXIClkDomain
 *
 * SYSNOCHSAXI clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCSYSNOCHSAXIClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_SYS_NOC_HS_AXI_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mSYSNOCHSAXIClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mSYSNOCHSAXIClkDomainClks)/sizeof(HAL_clk_mSYSNOCHSAXIClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControlRO_2,
  /* .pmNextClockDomain    = */ NULL
};


/*                           
 *  HAL_clk_mSYSTEMNOCClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mSYSTEMNOCClkDomainClks[] =
{
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_aggre1_snoc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_AGGRE1_SNOC_AXI_CBCR), HWIO_OFFS(GCC_AGGRE1_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_AGGRE1_SNOC_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_aggre1_snoc_msmpu_client_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_AGGRE1_SNOC_MSMPU_CLIENT_AXI_CBCR), HWIO_OFFS(GCC_MSMPU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_AGGRE1_SNOC_MSMPU_CLIENT_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_aggre2_snoc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_AGGRE2_SNOC_AXI_CBCR), HWIO_OFFS(GCC_AGGRE2_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_aggre2_snoc_east_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_AGGRE2_SNOC_EAST_AXI_CBCR), HWIO_OFFS(GCC_AGGRE2_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_EAST_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_aggre2_snoc_msmpu_client_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_AGGRE2_SNOC_MSMPU_CLIENT_AXI_CBCR), HWIO_OFFS(GCC_MSMPU_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_MSMPU_CLIENT_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_aggre2_snoc_north_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_AGGRE2_SNOC_NORTH_AXI_CBCR), HWIO_OFFS(GCC_AGGRE2_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_AGGRE2_SNOC_NORTH_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_bimc_nius_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BIMC_NIUS_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BIMC_NIUS_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_bimc_sysnoc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BIMC_SYSNOC_AXI_CBCR), HWIO_OFFS(GCC_BIMC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BIMC_SYSNOC_AXI_CLK
  },
#endif

  {
    /* .szClockName      = */ "gcc_ce1_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_CE1_AXI_CBCR), HWIO_OFFS(GCC_CE1_BCR), HAL_CLK_FMSK(PROC_CLK_BRANCH_ENA_VOTE, CE1_AXI_CLK_ENA) },
    /* .pmControl        = */ &HAL_clk_mGenericClockControlRO,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_CE1_AXI_CLK
  },
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_hmss_dvm_bus_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_HMSS_DVM_BUS_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_HMSS_DVM_BUS_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_imem_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_IMEM_AXI_CBCR), HWIO_OFFS(GCC_IMEM_BCR), HAL_CLK_FMSK(PROC_CLK_BRANCH_ENA_VOTE, IMEM_AXI_CLK_ENA) },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_IMEM_AXI_CLK
  },
#endif

  {
    /* .szClockName      = */ "gcc_lpass_core_smmu_client_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_LPASS_CORE_SMMU_CLIENT_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_LPASS_CORE_SMMU_CLIENT_CLK
  },
  {
    /* .szClockName      = */ "gcc_lpass_core_smmu_client_src_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_LPASS_CORE_SMMU_CLIENT_SRC_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_LPASS_CORE_SMMU_CLIENT_SRC_CLK
  },
  {
    /* .szClockName      = */ "gcc_lpass_sway_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_LPASS_SWAY_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_LPASS_SWAY_CLK
  },
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_mmss_sys_noc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MMSS_SYS_NOC_AXI_CBCR), HWIO_OFFS(GCC_MMSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MMSS_SYS_NOC_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_mss_snoc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_MSS_SNOC_AXI_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_MSS_SNOC_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_pcie_0_mstr_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_PCIE_0_MSTR_AXI_CBCR), HWIO_OFFS(GCC_PCIE_0_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_PCIE_0_MSTR_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_pcie_0_slv_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_PCIE_0_SLV_AXI_CBCR), HWIO_OFFS(GCC_PCIE_0_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_PCIE_0_SLV_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_qdss_etr_usb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_QDSS_ETR_USB_CBCR), HWIO_OFFS(GCC_QDSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_QDSS_ETR_USB_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_smmu_aggre1_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SMMU_AGGRE1_AXI_CBCR), HWIO_OFFS(GCC_AGGRE1_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE1_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_smmu_aggre1_axi_src_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SMMU_AGGRE1_AXI_SRC_CBCR), HWIO_OFFS(GCC_AGGRE1_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE1_AXI_SRC_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_smmu_aggre2_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SMMU_AGGRE2_AXI_CBCR), HWIO_OFFS(GCC_AGGRE2_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE2_AXI_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_smmu_aggre2_axi_src_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SMMU_AGGRE2_AXI_SRC_CBCR), HWIO_OFFS(GCC_AGGRE2_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SMMU_AGGRE2_AXI_SRC_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_snoc_bus_timeout1_ahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SNOC_BUS_TIMEOUT1_AHB_CBCR), HWIO_OFFS(GCC_SNOC_BUS_TIMEOUT1_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SNOC_BUS_TIMEOUT1_AHB_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_snoc_bus_timeout3_ahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SNOC_BUS_TIMEOUT3_AHB_CBCR), HWIO_OFFS(GCC_SNOC_BUS_TIMEOUT3_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SNOC_BUS_TIMEOUT3_AHB_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_spdm_snoc_cy_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SPDM_SNOC_CY_CBCR), HWIO_OFFS(GCC_SPDM_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SPDM_SNOC_CY_CLK
  },
#endif

  {
    /* .szClockName      = */ "gcc_spss_snoc_emm_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SPSS_SNOC_EMM_CBCR), HWIO_OFFS(GCC_SPSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SPSS_SNOC_EMM_CLK
  },
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_ssc_snoc_ahbm_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SSC_SNOC_AHBM_CBCR), HWIO_OFFS(GCC_SSC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SSC_SNOC_AHBM_CLK
  },
#endif

  {
    /* .szClockName      = */ "gcc_sys_noc_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControlRO,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_AXI_CLK
  },
  {
    /* .szClockName      = */ "gcc_sys_noc_east_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_EAST_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControlRO,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_EAST_AXI_CLK
  },
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_sys_noc_ssc_q6_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_SSC_Q6_AXI_CBCR), HWIO_OFFS(GCC_SSC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_SSC_Q6_AXI_CLK
  },
#endif

  {
    /* .szClockName      = */ "gcc_sys_noc_west_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_WEST_AXI_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControlRO,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_WEST_AXI_CLK
  },
#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_wcss_ahb_s0_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_WCSS_AHB_S0_CBCR), HWIO_OFFS(GCC_WCSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_WCSS_AHB_S0_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_wcss_axi_m_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_WCSS_AXI_M_CBCR), HWIO_OFFS(GCC_WCSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_WCSS_AXI_M_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_wcss_ecahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_WCSS_ECAHB_CBCR), HWIO_OFFS(GCC_WCSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_WCSS_ECAHB_CLK
  },
#endif

#if 0 /* not present on lpass */

  {
    /* .szClockName      = */ "gcc_wcss_shdreg_ahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_WCSS_SHDREG_AHB_CBCR), HWIO_OFFS(GCC_WCSS_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_WCSS_SHDREG_AHB_CLK
  },
#endif

};


/*
 * HAL_clk_mGCCSYSTEMNOCClkDomain
 *
 * SYSTEMNOC clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCSYSTEMNOCClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_SYSTEM_NOC_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mSYSTEMNOCClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mSYSTEMNOCClkDomainClks)/sizeof(HAL_clk_mSYSTEMNOCClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControlRO_2,
  /* .pmNextClockDomain    = */ NULL
};

