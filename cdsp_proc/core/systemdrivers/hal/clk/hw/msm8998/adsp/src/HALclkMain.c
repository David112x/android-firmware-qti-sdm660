/*
==============================================================================

FILE:         HALclkMain.c

DESCRIPTION:
  This file contains the main platform initialization code for the clock
  HAL on the modem subsystem (LPASS) processor on MSM8974.

==============================================================================

                             Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/clk/hw/msm8998/adsp/src/HALclkMain.c#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
12/10/11   dcf     Created.

==============================================================================
            Copyright (c) 2014 Qualcomm Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


#include "HALclkInternal.h"
#include "HALclkGeneric.h"
#include "HALclkGenericPLL.h"
#include "HALhwio.h"
#include "HALclkHWIO.h"


/* ============================================================================
**    Prototypes
** ==========================================================================*/

void HAL_clk_PlatformInitSources(void);


/* ============================================================================
**    Externs
** ==========================================================================*/

extern void HAL_clk_PlatformInitGCCMain(void);
extern void HAL_clk_PlatformInitLPASSMain(void);


/* ============================================================================
**    Data
** ==========================================================================*/


/*
 * HAL_clk_aInitFuncs
 *
 * Declare array of module initialization functions.
 */
static HAL_clk_InitFuncType HAL_clk_afInitFuncs[] =
{
  /*
   * Sources
   */
  HAL_clk_PlatformInitSources,
  
  /*
   *
   */
  HAL_clk_PlatformInitGCCMain,
  HAL_clk_PlatformInitLPASSMain,

  NULL
};


/*
 * Declare the base pointers for HWIO access.
 */
uint32 HAL_clk_nHWIOBaseTop;
uint32 HAL_clk_nHWIOBaseLPASS;
uint32 HAL_clk_nHWIOBaseTCSR;


/*
 * HAL_clk_aHWIOBases
 *
 * Declare array of HWIO bases in use on this platform.
 */
static HAL_clk_HWIOBaseType HAL_clk_aHWIOBases[] =
{
  { CLK_CTL_BASE_PHYS,      CLK_CTL_BASE_SIZE,      &HAL_clk_nHWIOBaseTop },
  { LPASS_BASE_PHYS,        LPASS_BASE_SIZE,        &HAL_clk_nHWIOBaseLPASS },
  { CORE_TOP_CSR_BASE_PHYS, CORE_TOP_CSR_BASE_SIZE, &HAL_clk_nHWIOBaseTCSR },
  { 0, 0, NULL }
};


/*
 * HAL_clk_Platform;
 * Platform data.
 */
HAL_clk_PlatformType HAL_clk_Platform =
{
  HAL_clk_afInitFuncs,
  HAL_clk_aHWIOBases
};


/*
 * GPLL contexts
 */
static HAL_clk_PLLContextType HAL_clk_aPLLContextGCCPLL[] =
{
  {
    HWIO_OFFS(GCC_GPLL0_MODE),
    HAL_CLK_FMSK(GCC_LPASS_DSP_GPLL_ENA_VOTE, GPLL0),
    HAL_CLK_PLL_FABIA
  },
};


/*
 * LPASS PLL contexts - voting is support.
 */

static HAL_clk_PLLContextType HAL_clk_aPLLContextLPASSPLL[] =
{
  {
    HWIO_OFFS(LPASS_LPAAUDIO_PLL_MODE),
    HAL_CLK_FMSK(LPASS_LPA_PLL_VOTE_LPASS_HW, LPAAUDIO_PLL),
    HAL_CLK_PLL_AGERA
  },

  {
    HWIO_OFFS(LPASS_LPAAUDIO_DIG_PLL_MODE),
    HAL_CLK_FMSK(LPASS_LPA_PLL_VOTE_LPASSQ6, LPAAUDIO_DIG_PLL),
    HAL_CLK_PLL_FABIA
  },

  {
    HWIO_OFFS(LPASS_QDSP6SS_PLL_MODE),
    HAL_CLK_FMSK(LPASS_LPA_PLL_VOTE_LPASS_HW, QDSP6SS_PLL),
    HAL_CLK_PLL_FABIA
  },
};


/* ============================================================================
**    Functions
** ==========================================================================*/


/* ===========================================================================
**  HAL_clk_PlatformInitSources
**
** ======================================================================== */

void HAL_clk_PlatformInitSources (void)
{
  /*
   * Install PLL handlers.
   */

  HAL_clk_InstallPLL(
      HAL_CLK_SOURCE_GPLL0, &HAL_clk_aPLLContextGCCPLL[0], CLK_CTL_BASE);

  HAL_clk_InstallPLL(
      HAL_CLK_SOURCE_LPAPLL0, &HAL_clk_aPLLContextLPASSPLL[0], LPASS_BASE);

  HAL_clk_InstallPLL(
      HAL_CLK_SOURCE_LPAPLL2, &HAL_clk_aPLLContextLPASSPLL[1], LPASS_BASE);

  HAL_clk_InstallPLL(
      HAL_CLK_SOURCE_LPAPLL1, &HAL_clk_aPLLContextLPASSPLL[2], LPASS_BASE);

} /* END HAL_clk_PlatformInitSources */


/* ===========================================================================
**  HAL_clk_Save
**
** ======================================================================== */

void HAL_clk_Save (void)
{
  /*
   * Nothing to save.
   */

} /* END HAL_clk_Save */


/* ===========================================================================
**  HAL_clk_Restore
**
** ======================================================================== */

void HAL_clk_Restore (void)
{
  /*
   * Nothing to restore.
   */
  
} /* END HAL_clk_Restore */

