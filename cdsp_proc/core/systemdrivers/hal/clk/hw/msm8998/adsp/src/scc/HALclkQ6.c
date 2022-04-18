/*
==============================================================================

FILE:         HALclkQ6.c

DESCRIPTION:
   This file contains the clock HAL code for the QDSP6 core clock.


==============================================================================

                             Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/clk/hw/msm8998/adsp/src/scc/HALclkQ6.c#1 $

when          who     what, where, why
--------      ---     ----------------------------------------------------------- 
07/10/2014    dcf     Created

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

static uint32  HAL_clk_Q6SourceMapToHW       ( const HAL_clk_ClockMuxConfigType *pmConfig );
static void    HAL_clk_Q6CoreClkEnable       ( HAL_clk_ClockDescType  *pmClockDesc );
static void    HAL_clk_Q6CoreClkDisable      ( HAL_clk_ClockDescType  *pmClockDesc );
static boolean HAL_clk_Q6CoreClkIsEnabled    ( HAL_clk_ClockDescType  *pmClockDesc );
static boolean HAL_clk_Q6CoreClkIsOn         ( HAL_clk_ClockDescType  *pmClockDesc );
static void    HAL_clk_Q6CoreClkConfig       ( HAL_clk_ClockDescType  *pmClockDesc, HAL_clk_ClockConfigType eConfig );
static void    HAL_clk_Q6CoreConfigMux       ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, const HAL_clk_ClockMuxConfigType *pmConfig );
static void    HAL_clk_Q6CoreDetectMuxConfig ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig );
static void    HAL_clk_Q6CoreConfigDivider   ( HAL_clk_ClockDescType *pmClockDesc, uint32 nDivider );

/* ============================================================================
**    Externs
** ==========================================================================*/



/* ============================================================================
**    Data
** ==========================================================================*/

/*
 * HAL_clk_mQ6ClockDomainControl
 *
 * Functions for controlling Q6 clock domains
 */
HAL_clk_ClockDomainControlType HAL_clk_mQ6ClockDomainControl =
{
   /* .ConfigMux          = */ HAL_clk_Q6CoreConfigMux,
   /* .DetectMuxConfig    = */ HAL_clk_Q6CoreDetectMuxConfig,
   /* .IsOn               = */ HAL_clk_GenericDomainIsOn,
   /* .pmSourceMapping    = */ NULL
};
                                 
   
/*
 * HAL_clk_mQ6ClockControl
 *
 * Functions for controlling Q6 clock functions.
 */
HAL_clk_ClockControlType HAL_clk_mQ6ClockControl =
{
  /* .Enable           = */ HAL_clk_Q6CoreClkEnable,
  /* .Disable          = */ HAL_clk_Q6CoreClkDisable,
  /* .IsEnabled        = */ HAL_clk_Q6CoreClkIsEnabled,
  /* .IsOn             = */ HAL_clk_Q6CoreClkIsOn,
  /* .Reset            = */ NULL,
  /* .IsReset          = */ NULL,
  /* .Config           = */ HAL_clk_Q6CoreClkConfig,
  /* .DetectConfig     = */ NULL,
  /* .ConfigDivider    = */ HAL_clk_Q6CoreConfigDivider,
  /* .DetectDivider    = */ NULL,
  /* .ConfigFootswitch = */ NULL,
};   
   
                                    
/*
 *  HAL_clk_mSDCC1APPSClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mQ6CoreClkDomainClks[] =
{
  {
    /* .szClockName      = */ "ssc_q6core",
    /* .mRegisters       = */ { 0, 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mQ6ClockControl,
    /* .nTestClock       = */ HAL_CLK_SSC_TEST_Q6SS_DBG_CLK
  },
};


/*
 * HAL_clk_mQ6ClkDomain
 *
 * Q6 clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mQ6ClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(SSC_QDSP6SS_CORE_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mQ6CoreClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mQ6CoreClkDomainClks)/sizeof(HAL_clk_mQ6CoreClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mQ6ClockDomainControl,
  /* .pmNextClockDomain    = */ NULL
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

static uint32 HAL_clk_Q6SourceMapToHW 
( 
  const HAL_clk_ClockMuxConfigType *pmConfig 
)
{
  return 1;
}


/* ===========================================================================
**  HAL_clk_Q6CoreClkEnable
**
** ======================================================================== */

static void HAL_clk_Q6CoreClkEnable 
( 
  HAL_clk_ClockDescType  *pmClockDesc 
)
{
  //HWIO_OUTF(SSC_Q6CORE_CMD_RCGR, ROOT_EN, 1);

}  /* END HAL_clk_Q6CoreClkEnable */


/* ===========================================================================
**  HAL_clk_Q6CoreClkDisable
**
** ======================================================================== */

static void HAL_clk_Q6CoreClkDisable 
( 
  HAL_clk_ClockDescType  *pmClockDesc
)
{
  //HWIO_OUTF(SSC_Q6CORE_CMD_RCGR, ROOT_EN, 0);

}  /* END HAL_clk_Q6CoreClkDisable */


/* ===========================================================================
**  HAL_clk_Q6CoreClkIsEnabled
**
** ======================================================================== */

static boolean HAL_clk_Q6CoreClkIsEnabled 
( 
  HAL_clk_ClockDescType  *pmClockDesc 
)
{
  return TRUE;

}  /* END HAL_clk_Q6CoreClkIsEnabled */


/* ===========================================================================
**  HAL_clk_Q6CoreClkIsOn
**
** ======================================================================== */

static boolean HAL_clk_Q6CoreClkIsOn
( 
  HAL_clk_ClockDescType  *pmClockDesc
)
{
  return TRUE;

}  /* END HAL_clk_Q6CoreClkIsOn */


/* ===========================================================================
**  HAL_clk_Q6CoreClkConfig
**
** ======================================================================== */

static void HAL_clk_Q6CoreClkConfig
( 
  HAL_clk_ClockDescType   *pmClockDesc, 
  HAL_clk_ClockConfigType eConfig 
)
{
  uint32 nSrcSel;
  
  switch (eConfig)
  {
    case HAL_CLK_CONFIG_Q6SS_CORE_CLOCK_MUX_SRCA:
      nSrcSel = 0x0;
      break;

    case HAL_CLK_CONFIG_Q6SS_CORE_CLOCK_MUX_SRCB:
      nSrcSel = 0x1;
      break;

    case HAL_CLK_CONFIG_Q6SS_CORE_CLOCK_MUX_SRCC:
      nSrcSel = 0x2;
      break;

    case HAL_CLK_CONFIG_Q6SS_CORE_CLOCK_MUX_SRCD:
      nSrcSel = 0x3;
      break;

    default:
      return;
  }

  HWIO_OUTF(SSC_QDSP6SS_GFMUX_CTL, CLK_SRC_SEL, nSrcSel);

}  /* END HAL_clk_Q6CoreClkConfig */


/* ===========================================================================
**  HAL_clk_Q6CoreConfigMux
**
** ======================================================================== */

static void  HAL_clk_Q6CoreConfigMux
( 
  HAL_clk_ClockDomainDescType      *pmClockDomainDesc, 
  const HAL_clk_ClockMuxConfigType *pmConfig 
)
{
  uint32 nCmdCGRAddr, nCmdCGRVal, nCfgCGRAddr, nCfgCGRVal;
  uint32 nSource;

  /*
   * Sanity check.  No RCG config for SCCPLL0
   */
  if((pmClockDomainDesc           == NULL) || 
     (pmClockDomainDesc->nCGRAddr == 0   ) ||
     (pmConfig->eSource == HAL_CLK_SOURCE_SCCPLL0_ODD) ||
     (pmConfig->eSource == HAL_CLK_SOURCE_SCCPLL0_EVEN) ||
     (pmConfig->eSource == HAL_CLK_SOURCE_SCCPLL0))
  {
    return;
  }


  /*
   * Get current CMD and CFG register values
   */
  nCmdCGRAddr = pmClockDomainDesc->nCGRAddr;
  nCmdCGRVal  = inpdw(nCmdCGRAddr);
  nCfgCGRAddr = pmClockDomainDesc->nCGRAddr + HAL_CLK_CFG_REG_OFFSET;
  nCfgCGRVal  = inpdw(nCfgCGRAddr);

  /*
   * Clear the fields
   */
  nCfgCGRVal &= ~(HAL_CLK_CFG_CGR_SRC_SEL_FMSK |
                  HAL_CLK_CFG_CGR_SRC_DIV_FMSK);

  /*
   * Program the source and divider values.
   */
  nSource = HAL_clk_Q6SourceMapToHW(pmConfig);

  nCfgCGRVal |= ((nSource << HAL_CLK_CFG_CGR_SRC_SEL_SHFT) 
                   & HAL_CLK_CFG_CGR_SRC_SEL_FMSK);

  /*
   * Set the divider
   */
  nCfgCGRVal |= ((HALF_DIVIDER(pmConfig) << HAL_CLK_CFG_CGR_SRC_DIV_SHFT) 
                & HAL_CLK_CFG_CGR_SRC_DIV_FMSK);

  /*
   * Write the final CFG register value
   */
  outpdw(nCfgCGRAddr, nCfgCGRVal);

  /*
   * Trigger the update
   */
  nCmdCGRVal |= HAL_CLK_CMD_CFG_UPDATE_FMSK;
  outpdw(nCmdCGRAddr, nCmdCGRVal);

  /*
   * Wait until update finishes
   */
  while(inpdw(nCmdCGRAddr) & HAL_CLK_CMD_CFG_UPDATE_FMSK);

}  /* END HAL_clk_Q6CoreConfigMux */


/* ===========================================================================
**  HAL_clk_Q6CoreDetectMuxConfig
**
** ======================================================================== */

static void  HAL_clk_Q6CoreDetectMuxConfig 
( 
  HAL_clk_ClockDomainDescType *pmClockDomainDesc, 
  HAL_clk_ClockMuxConfigType  *pmConfig 
)
{
  uint32 nCfgCGRAddr, nCfgCGRVal, nSource;

  pmConfig->eSource = HAL_CLK_SOURCE_NULL;
  pmConfig->nDiv2x  = 0;
  pmConfig->n2D     = 0;
  pmConfig->nM      = 0;
  pmConfig->nN      = 0;

  /*
   * Sanity check
   */
  if((pmClockDomainDesc           == NULL) || 
     (pmClockDomainDesc->nCGRAddr == 0   ))
  {
    return;
  }

  /*
   * Get current CFG register value
   */
  nCfgCGRAddr = pmClockDomainDesc->nCGRAddr + HAL_CLK_CFG_REG_OFFSET;
  nCfgCGRVal  = inpdw(nCfgCGRAddr);

  /*
   * Get the source and divider values
   */
  pmConfig->nDiv2x = 
    ((nCfgCGRVal & HAL_CLK_CFG_CGR_SRC_DIV_FMSK) >> HAL_CLK_CFG_CGR_SRC_DIV_SHFT) + 1;

  nSource = (nCfgCGRVal & HAL_CLK_CFG_CGR_SRC_SEL_FMSK) >> HAL_CLK_CFG_CGR_SRC_SEL_SHFT;

  /*
   * The SSC QDSP6 PLL will always be chosen as the RCG source when sourced by anything but
   * XO.  Additional sources are configured through the GFMUX.
   */

  if( nSource == 0 )
  {
    pmConfig->eSource = HAL_CLK_SOURCE_XO;
  }
  else
  {
    pmConfig->eSource = HAL_CLK_SOURCE_SCCPLL1;
  }
}  /* END HAL_clk_Q6CoreDetectMuxConfig */


/* ===========================================================================
**  HAL_clk_Q6CoreConfigDivider
**
** ======================================================================== */

static void HAL_clk_Q6CoreConfigDivider
(
  HAL_clk_ClockDescType *pmClockDesc,
  uint32                 nDivider
)
{
  HWIO_OUTF(SSC_SCC_SCC_PLL_OUT_MAIN_CLK_DIV_REG, CLK_DIV, nDivider);

} /* HAL_clk_Q6CoreConfigDivider */

