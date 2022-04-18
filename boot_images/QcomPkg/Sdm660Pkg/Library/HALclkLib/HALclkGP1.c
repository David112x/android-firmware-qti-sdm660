/*
==============================================================================

FILE:         HALclkGP1.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   GP1 clocks.

   List of clock domains:
     - HAL_clk_mGCCGP1ClkDomain


   List of power domains:



==============================================================================

$Header: //components/rel/boot.xf/1.4/QcomPkg/Sdm660Pkg/Library/HALclkLib/HALclkGP1.c#2 $

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


/* ============================================================================
**    Data
** ==========================================================================*/


/*                           
 *  HAL_clk_mGP1ClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mGP1ClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_gp1_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_GP1_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_GP1_CLK
  },
};


/*
 * HAL_clk_mGCCGP1ClkDomain
 *
 * GP1 clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCGP1ClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_GP1_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mGP1ClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mGP1ClkDomainClks)/sizeof(HAL_clk_mGP1ClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl,
  /* .pmNextClockDomain    = */ NULL
};

