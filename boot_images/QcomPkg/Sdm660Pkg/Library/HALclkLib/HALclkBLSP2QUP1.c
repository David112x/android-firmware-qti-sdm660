/*
==============================================================================

FILE:         HALclkBLSP2QUP1.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   BLSP2QUP1 clocks.

   List of clock domains:
     - HAL_clk_mGCCBLSP2QUP1I2CAPPSClkDomain
     - HAL_clk_mGCCBLSP2QUP1SPIAPPSClkDomain


   List of power domains:



==============================================================================

$Header: //components/rel/boot.xf/1.4/QcomPkg/Sdm660Pkg/Library/HALclkLib/HALclkBLSP2QUP1.c#2 $

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
 *  HAL_clk_mBLSP2QUP1I2CAPPSClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mBLSP2QUP1I2CAPPSClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_blsp2_qup1_i2c_apps_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BLSP2_QUP1_I2C_APPS_CBCR), HWIO_OFFS(GCC_BLSP2_QUP1_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BLSP2_QUP1_I2C_APPS_CLK
  },
};


/*
 * HAL_clk_mGCCBLSP2QUP1I2CAPPSClkDomain
 *
 * BLSP2QUP1I2CAPPS clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCBLSP2QUP1I2CAPPSClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_BLSP2_QUP1_I2C_APPS_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mBLSP2QUP1I2CAPPSClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mBLSP2QUP1I2CAPPSClkDomainClks)/sizeof(HAL_clk_mBLSP2QUP1I2CAPPSClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl_1,
  /* .pmNextClockDomain    = */ NULL
};


/*                           
 *  HAL_clk_mBLSP2QUP1SPIAPPSClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mBLSP2QUP1SPIAPPSClkDomainClks[] =
{
  {
    /* .szClockName      = */ "gcc_blsp2_qup1_spi_apps_clk",
    /* .mRegisters       = */ { HWIO_OFFS(GCC_BLSP2_QUP1_SPI_APPS_CBCR), HWIO_OFFS(GCC_BLSP2_QUP1_BCR), {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_GCC_TEST_GCC_BLSP2_QUP1_SPI_APPS_CLK
  },
};


/*
 * HAL_clk_mGCCBLSP2QUP1SPIAPPSClkDomain
 *
 * BLSP2QUP1SPIAPPS clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mGCCBLSP2QUP1SPIAPPSClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(GCC_BLSP2_QUP1_SPI_APPS_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mBLSP2QUP1SPIAPPSClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mBLSP2QUP1SPIAPPSClkDomainClks)/sizeof(HAL_clk_mBLSP2QUP1SPIAPPSClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mGCCClockDomainControl,
  /* .pmNextClockDomain    = */ NULL
};

