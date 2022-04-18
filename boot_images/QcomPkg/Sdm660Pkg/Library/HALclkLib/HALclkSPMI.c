/*
==============================================================================

FILE:         HALclkSPMI.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   SPMI clocks.

   List of clock domains:
     - HAL_clk_mGCCSPMIAHBClkDomain
     - HAL_clk_mGCCSPMISERClkDomain


   List of power domains:



==============================================================================

$Header: //components/rel/boot.xf/1.4/QcomPkg/Sdm660Pkg/Library/HALclkLib/HALclkSPMI.c#3 $

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

extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControl;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControlRO;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControl_1;
extern HAL_clk_ClockDomainControlType  HAL_clk_mGCCClockDomainControlRO_1;


/* ============================================================================
**    Data
** ==========================================================================*/


/*                           
 *  HAL_clk_mSPMIAHBClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mSPMIAHBClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_spmi_ahb_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SPMI_AHB_CBCR), HWIO_OFFS(GCC_SPMI_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControlRO,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SPMI_AHB_CLK
  },
};


/*
 * HAL_clk_mGCCSPMIAHBClkDomain
 *
 * SPMIAHB clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCSPMIAHBClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_SPMI_AHB_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mSPMIAHBClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mSPMIAHBClkDomainClks)/sizeof(HAL_clk_mSPMIAHBClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControlRO_1,
  /* .pmNextClockDomain    = */ NULL
};


/*                           
 *  HAL_clk_mSPMISERClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mSPMISERClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_spmi_ser_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_SPMI_SER_CBCR), HWIO_OFFS(GCC_SPMI_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControlRO,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_SPMI_SER_CLK
  },
};


/*
 * HAL_clk_mGCCSPMISERClkDomain
 *
 * SPMISER clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCSPMISERClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_SPMI_SER_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mSPMISERClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mSPMISERClkDomainClks)/sizeof(HAL_clk_mSPMISERClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControlRO,
  /* .pmNextClockDomain    = */ NULL
};

