/*
==============================================================================

FILE:         HALclkHMSS.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   HMSS clocks.

   List of clock domains:
     - HAL_clk_mGCCBIMCHMSSAXIClkDomain
     - HAL_clk_mGCCHMSSAHBClkDomain
     - HAL_clk_mGCCHMSSRBCPRClkDomain


   List of power domains:



==============================================================================

$Header: //components/rel/boot.xf/1.4/QcomPkg/Sdm660Pkg/Library/HALclkLib/HALclkHMSS.c#3 $

==============================================================================
            Copyright (c) 2016 QUALCOMM Technologies Incorporated.
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

extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControl_1;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControlRO_1;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControl_4;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControlRO_4;


/* ============================================================================
**    Data
** ==========================================================================*/


/*                           
 *  HAL_clk_mBIMCHMSSAXIClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mBIMCHMSSAXIClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_bimc_hmss_axi_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BIMC_HMSS_AXI_CBCR), 0, HAL_CLK_FMSK(PROC_CLK_BRANCH_ENA_VOTE, BIMC_HMSS_AXI_CLK_ENA) },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BIMC_HMSS_AXI_CLK
  },
};


/*
 * HAL_clk_mGCCBIMCHMSSAXIClkDomain
 *
 * BIMCHMSSAXI clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCBIMCHMSSAXIClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_BIMC_HMSS_AXI_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mBIMCHMSSAXIClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mBIMCHMSSAXIClkDomainClks)/sizeof(HAL_clk_mBIMCHMSSAXIClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControlRO_4,
  /* .pmNextClockDomain    = */ NULL
};


/*                           
 *  HAL_clk_mHMSSAHBClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mHMSSAHBClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_hmss_ahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_HMSS_AHB_CBCR), 0, HAL_CLK_FMSK(PROC_CLK_BRANCH_ENA_VOTE, HMSS_AHB_CLK_ENA) },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_HMSS_AHB_CLK
  },
#if 0 /* not present on apcs */

  {
    /* .szClockName      = */ "gcc_sys_noc_hmss_ahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SYS_NOC_HMSS_AHB_CBCR), HWIO_OFFS(GCC_SYSTEM_NOC_BCR), HAL_CLK_FMSK(PROC_CLK_BRANCH_ENA_VOTE, SYS_NOC_HMSS_AHB_CLK_ENA) },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SYS_NOC_HMSS_AHB_CLK
  },
#endif

};


/*
 * HAL_clk_mGCCHMSSAHBClkDomain
 *
 * HMSSAHB clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCHMSSAHBClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_HMSS_AHB_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mHMSSAHBClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mHMSSAHBClkDomainClks)/sizeof(HAL_clk_mHMSSAHBClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl_1,
  /* .pmNextClockDomain    = */ NULL
};


/*                           
 *  HAL_clk_mHMSSRBCPRClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mHMSSRBCPRClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_hmss_rbcpr_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_HMSS_RBCPR_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_HMSS_RBCPR_CLK
  },
};


/*
 * HAL_clk_mGCCHMSSRBCPRClkDomain
 *
 * HMSSRBCPR clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCHMSSRBCPRClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_HMSS_RBCPR_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mHMSSRBCPRClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mHMSSRBCPRClkDomainClks)/sizeof(HAL_clk_mHMSSRBCPRClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl_1,
  /* .pmNextClockDomain    = */ NULL
};

