/*
==============================================================================

FILE:         HALclkAgeraPLL.c

DESCRIPTION:
  This file contains the clock HAL code for the Agera PLL control.
  These PLLs are of the Agera PLL variety.

==============================================================================

                             Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/clk/hw/v1/HALclkAgeraPLL.c#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
06/07/14   sr      Created

==============================================================================
    Copyright (c) 2016 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/

#include "HALhwio.h"
#include "HALclkGenericPLL.h"
#include "HALclkAgeraPLL.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/


/*
 * HAL_CLK_PLL_MODE_*
 *
 * Definitions for configuring the PLLn_MODE register.
 */
#define HAL_CLK_PLL_MODE_ACTIVE  \
  (HWIO_FMSK(PLL_MODE, OUTCTRL)  | \
   HWIO_FMSK(PLL_MODE, BYPASSNL) | \
   HWIO_FMSK(PLL_MODE, RESET_N))

/*
 * Definitions for configuring the PLL in FSM Mode
 */
#define HAL_CLK_PLL_BIAS_COUNT_VAL   (0x6 << HWIO_SHFT(PLL_MODE, BIAS_COUNT))
#define HAL_CLK_PLL_LOCK_COUNT_VAL   (0x0 << HWIO_SHFT(PLL_MODE, LOCK_COUNT))

/*
 * HAL_CLK_PLL_INIT_TIME_US
 *
 * Init time in microseconds after de-asserting PLL reset (normal mode).
 */
#define HAL_CLK_PLL_INIT_TIME_US 5

/*
 * HAL_CLK_PLL_WARMUP_TIME_US
 *
 * Warm-up time in microseconds after turning on the PLL.
 */
#define HAL_CLK_PLL_WARMUP_TIME_US 50

/*
 * HAL_CLK_LOCK_TIMEOUT_US
 *
 * Timeout in usec for PLL_LOCK_DET to get set.
 * For Agera, this is 50us worst-case lock time.
 */
#define HAL_CLK_LOCK_TIMEOUT_US 50


/* ============================================================================
**    Data Declarations
** ==========================================================================*/

/*
 * HAL_clk_AgeraPLLControl
 *
 * Control function array for the Agera PLLs.
 */
HAL_clk_SourceControlType HAL_clk_AgeraPLLControl =
{
  /* .Enable          = */ HAL_clk_AgeraPLLEnable,
  /* .Disable         = */ HAL_clk_AgeraPLLDisable,
  /* .IsEnabled       = */ HAL_clk_AgeraPLLIsEnabled,
  /* .Config          = */ HAL_clk_AgeraPLLConfig,
  /* .ConfigPLL       = */ HAL_clk_AgeraPLLConfigPLL,
  /* .DetectPLLConfig = */ HAL_clk_AgeraPLLDetectPLLConfig,
  /* .EnableVote      = */ HAL_clk_AgeraPLLEnableVote,
  /* .DisableVote     = */ HAL_clk_AgeraPLLDisableVote,
  /* .IsVoteEnabled   = */ HAL_clk_AgeraPLLIsVoteEnabled,
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

/* ===========================================================================
**  HAL_clk_AgeraPLLEnableVote
**
** ======================================================================== */

static boolean HAL_clk_AgeraPLLEnableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  HAL_clk_PLLContextType *pCtxt;
  uint32                  nVal;
  boolean                 bResult;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Set the appropriate bit.
   */
  nVal = inpdw(pCtxt->VoterRegister.nAddr) | pCtxt->VoterRegister.nMask;
  outpdw(pCtxt->VoterRegister.nAddr, nVal);

  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pCtxt),
      HWIO_FMSK(PLL_MODE, PLL_ACTIVE_FLAG),
      HAL_CLK_LOCK_TIMEOUT_US);

  return bResult;

} /* END HAL_clk_AgeraPLLEnableVote */


/* ===========================================================================
**  HAL_clk_AgeraPLLDisableVote
**
** ======================================================================== */

static void HAL_clk_AgeraPLLDisableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  HAL_clk_PLLContextType *pCtxt;
  uint32 nVal;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Clear the appropriate bit.
   */
  nVal = inpdw(pCtxt->VoterRegister.nAddr) & ~pCtxt->VoterRegister.nMask;
  outpdw(pCtxt->VoterRegister.nAddr, nVal);

} /* END HAL_clk_AgeraPLLDisableVote */


/* ===========================================================================
**  HAL_clk_AgeraPLLIsVoteEnabled
**
** ======================================================================== */

static boolean HAL_clk_AgeraPLLIsVoteEnabled
(
  HAL_clk_SourceDescType *pSource
)
{
  HAL_clk_PLLContextType *pCtxt;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Check the appropriate bit.
   */
  if (inpdw(pCtxt->VoterRegister.nAddr) & pCtxt->VoterRegister.nMask)
  {
    return TRUE;
  }

  return FALSE;

} /* END HAL_clk_AgeraPLLIsVoteEnabled */


/* ===========================================================================
**  HAL_clk_AgeraPLLPostDivToHW
**
** ======================================================================== */

static uint32 HAL_clk_AgeraPLLPostDivToHW (uint32 nDivider)
{
  switch (nDivider)
  {
    case 0:
    case 1:   return 0; /* Divide-by-1 */
    case 2:   return 1; /* Divide-by-2 */
    case 4:   return 3; /* Divide-by-4 */
    case 8:   return 2; /* Divide-by-8 */
    default:
      return 0;
  }

} /* END HAL_clk_AgeraPLLPostDivToHW */


/* ===========================================================================
**  HAL_clk_AgeraPLLPostDivFromHW
**
** ======================================================================== */

static uint32 HAL_clk_AgeraPLLPostDivFromHW (uint32 nDivider)
{
  switch (nDivider)
  {
    case 0:   return 1; /* Divide-by-1 */
    case 1:   return 2; /* Divide-by-2 */
    case 2:   return 8; /* Divide-by-8 */
    case 3:   return 4; /* Divide-by-4 */
    default:
      return 1;
  }

} /* END HAL_clk_AgeraPLLPostDivFromHW */



/* ===========================================================================
**  HAL_clk_AgeraPLLEnable
**
** ======================================================================== */

static boolean HAL_clk_AgeraPLLEnable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32                  nModeVal;
  HAL_clk_PLLContextType *pCtxt;
  boolean                 bResult;

  /*
   * Check if PLL is already enabled and return
   */
  if (HAL_clk_AgeraPLLIsEnabled(pSource))
  {
    return TRUE;
  }

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pCtxt);

  /*
   * De-assert PLL bypass.
   * This latches L and Alpha values.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, BYPASSNL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

  /*
   * Wait for PLL init time
   */
  HAL_clk_BusyWait(HAL_CLK_PLL_INIT_TIME_US);

  /*
   * De-assert PLL reset.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, RESET_N);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

  /*
   * Wait for the PLL warm-up time.
   */
  HAL_clk_BusyWait(HAL_CLK_PLL_WARMUP_TIME_US);

  /*
   * Wait for the PLL to lock within the timeout period.
   */
  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pCtxt),
      HWIO_FMSK(PLL_MODE, LOCK_DET),
      HAL_CLK_LOCK_TIMEOUT_US);

  /*
   * Return immediately if the lock detect failed.
   */
  if (!bResult)
  {
    return FALSE;
  }

  /*
   * Put the PLL in active mode
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, OUTCTRL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

  return TRUE;

} /* END HAL_clk_AgeraPLLEnable */


/* ===========================================================================
**  HAL_clk_AgeraPLLDisable
**
** ======================================================================== */

static void HAL_clk_AgeraPLLDisable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32                  nModeVal;
  HAL_clk_PLLContextType *pCtxt;

  /*
   * The Agera PLL's only support full enable/disable mode.
   */
  if (eMode != HAL_CLK_SOURCE_DISABLE_MODE_NORMAL)
  {
    return;
  }

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pCtxt);

  /*
   * First clear the output enable bit
   */
  nModeVal &= ~(HWIO_FMSK(PLL_MODE, OUTCTRL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

  /*
   * Put the PLL in off state
   */
  nModeVal &= ~(HWIO_FMSK(PLL_MODE, RESET_N) |
                HWIO_FMSK(PLL_MODE, BYPASSNL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

} /* END HAL_clk_AgeraPLLDisable */


/* ===========================================================================
**  HAL_clk_AgeraPLLIsEnabled
**
** ======================================================================== */

static boolean HAL_clk_AgeraPLLIsEnabled
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32                  nModeVal;
  HAL_clk_PLLContextType *pCtxt;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pCtxt);

  /*
   * Check whether the PLL is enabled.
   */
  return ((nModeVal & HAL_CLK_PLL_MODE_ACTIVE) == HAL_CLK_PLL_MODE_ACTIVE);

} /* END HAL_clk_AgeraPLLIsEnabled */


/* ===========================================================================
**  HAL_clk_AgeraPLLConfig
**
** ======================================================================== */

static void HAL_clk_AgeraPLLConfig
(
  HAL_clk_SourceDescType   *pSource,
  HAL_clk_SourceConfigType  eConfig
)
{
  HAL_clk_PLLContextType *pCtxt;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Take action.
   */
  switch (eConfig)
  {
    case HAL_CLK_CONFIG_PLL_FSM_MODE_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pCtxt, FSM_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_FSM_MODE_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pCtxt, FSM_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX2_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, PLLOUT_LV_AUX2_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX2_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, PLLOUT_LV_AUX2_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_AUX_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, PLLOUT_LV_AUX_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, PLLOUT_LV_AUX_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, PLLOUT_LV_TEST_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, PLLOUT_LV_TEST_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EARLY_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, LVEARLY_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EARLY_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, LVEARLY_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, LVMAIN_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pCtxt, LVMAIN_EN, 0);
      break;

    default:
      break;
  }

} /* END HAL_clk_AgeraPLLConfig */


/* ===========================================================================
**  HAL_clk_AgeraPLLConfigPLLNormal
**
** ======================================================================== */

static boolean HAL_clk_AgeraPLLConfigPLLNormal
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  uint32  nModeVal;
  uint32  nUserVal;
  boolean bPLLEnabled = FALSE;
  HAL_clk_PLLContextType *pCtxt;
  uint32  nPLLInFSMMode = 0;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Check PLL FSM mode.
   */
  nPLLInFSMMode = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pCtxt) &
    HWIO_FMSK(PLL_MODE, FSM_EN);

  /*
   * Check PLL mode.
   */
  bPLLEnabled = HAL_clk_AgeraPLLIsEnabled(pSource);

  /*
   * Disable the PLL.
   */
  if (bPLLEnabled)
  {
    HAL_clk_AgeraPLLDisable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pCtxt);

  /*
   * Disable FSM Mode
   */
  if (nPLLInFSMMode != 0)
  {
    nModeVal &= ~HWIO_FMSK(PLL_MODE, FSM_EN);
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);
  }

  /*
   * Program L/Alpha values.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_L_VAL, pCtxt, pConfig->nL);
  HAL_CLK_PLL_HWIO_OUT(PLL_ALPHA_VAL, pCtxt, pConfig->nAlpha);

  /*
   * Get the CONFIG value and clear out fields we will configure.
   */
  nUserVal  =  HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pCtxt);
  nUserVal &= ~(HWIO_FMSK(PLL_USER_CTL, ALPHA_MODE) |
                HWIO_FMSK(PLL_USER_CTL, MN_ACC) |
                HWIO_FMSK(PLL_USER_CTL, CLK_REF_PRE_DIV) |
                HWIO_FMSK(PLL_USER_CTL, CLK_POST_DIV));

  /*
   * Program the pre-div value (div-1 to div-2).
   */
  if (pConfig->nPreDiv <= 2 && pConfig->nPreDiv > 0)
  {
    nUserVal |= HWIO_FVAL(PLL_USER_CTL, CLK_REF_PRE_DIV, (pConfig->nPreDiv - 1));
  }

  /*
   * Program the post-div value.
   */
  nUserVal |= HWIO_FVAL(PLL_USER_CTL, CLK_POST_DIV,
    HAL_clk_AgeraPLLPostDivToHW(pConfig->nPostDiv));

  /*
   *  Check fractional output or integer output.
   */
  if ( pConfig->nAlpha != 0 )
  {
    /*
     * Alpha Mode
     */
    nUserVal |= HWIO_FMSK(PLL_USER_CTL, MN_ACC);
  }
  else if ( pConfig->nM != 0 || pConfig->nN != 0 )
  {
    /*
     * M/N Mode
     */
    nUserVal |= HWIO_FMSK(PLL_USER_CTL, MN_ACC);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL, ALPHA_MODE);
  }

  /*
   * Enable MAIN_OUT_ENA bit.
   */
  nUserVal |= HWIO_FMSK(PLL_USER_CTL, LVMAIN_EN);

  /*
   * Finally program the USER_CTL register.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL, pCtxt, nUserVal);

  /*
   * If there is an address for a voting register, then the PLL is in
   * FSM voteable mode. In this case, the enable sequence is handled in
   * hardware, guided by the BIAS and LOCK counts.
   */
  if (nPLLInFSMMode)
  {
    /*
     * Put the FSM in reset.
     */
    nModeVal |= HWIO_FMSK(PLL_MODE, FSM_RES);
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

    /*
     * Program the FSM portion of the mode register.
     */
    nModeVal &= ~HWIO_FMSK(PLL_MODE, BIAS_COUNT);
    nModeVal &= ~HWIO_FMSK(PLL_MODE, LOCK_COUNT);

    nModeVal |= HAL_CLK_PLL_BIAS_COUNT_VAL;
    nModeVal |= HAL_CLK_PLL_LOCK_COUNT_VAL;

    nModeVal |= HWIO_FMSK(PLL_MODE, FSM_EN);
    /*
     * Finally program the Mode register.
     */
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);

    /*
     * Take the FSM out of reset.
     */
    nModeVal &= ~HWIO_FMSK(PLL_MODE, FSM_RES);
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pCtxt, nModeVal);
  }

  /*
   * Enable the PLL if it was on before.
   */
  if (bPLLEnabled && nPLLInFSMMode == 0)
  {
    HAL_clk_AgeraPLLEnable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  return TRUE;

} /* END HAL_clk_AgeraPLLConfigPLLNormal */


/* ===========================================================================
**  HAL_clk_AgeraPLLConfigPLLSlew
**
**  Returns:
**    boolean - TRUE if successfully configured.
**              FALSE if unable to detect that the PLL successfully locked.
** ======================================================================== */

static boolean HAL_clk_AgeraPLLConfigPLLSlew
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  HAL_clk_PLLContextType *pCtxt;
  boolean                 bResult;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Program L value.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_L_VAL, pCtxt, pConfig->nL);

  /*
   * Wait for 11 or more PLL clk_ref ticks for PLL_LOCK_DET to transition to 0.
   * When using a reference clock of XO, the wait requirement is 570 ns.
   */
  HAL_clk_BusyWait(1);

  /*
   * Wait for the PLL to lock during the 15 us timeout period.
   */
  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pCtxt),
      HWIO_FMSK(PLL_MODE, LOCK_DET),
      HAL_CLK_LOCK_TIMEOUT_US);

  return bResult;

} /* END HAL_clk_AgeraPLLConfigPLLSlew */


/* ===========================================================================
**  HAL_clk_AgeraPLLConfigPLL
**
** ======================================================================== */

static boolean HAL_clk_AgeraPLLConfigPLL
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig,
  HAL_clk_SourceConfigMode     eMode
)
{
  boolean bResult = FALSE;

  switch (eMode)
  {
    case HAL_CLK_SOURCE_CONFIG_MODE_NORMAL:
      bResult = HAL_clk_AgeraPLLConfigPLLNormal(pSource, pConfig);
      break;
    case HAL_CLK_SOURCE_CONFIG_MODE_SLEW:
      bResult = HAL_clk_AgeraPLLConfigPLLSlew(pSource, pConfig);
      break;
    default:
      bResult = FALSE;
      break;
  }

  return bResult;

} /* END HAL_clk_AgeraPLLConfigPLL */


/* ===========================================================================
**  HAL_clk_AgeraPLLDetectPLLConfig
**
** ======================================================================== */

static void HAL_clk_AgeraPLLDetectPLLConfig
(
  HAL_clk_SourceDescType *pSource,
  HAL_clk_PLLConfigType  *pConfig
)
{
  uint32                  nConfigVal;
  uint32                  nMode;
  HAL_clk_PLLContextType *pCtxt;

  /*
   * Get the PLL context.
   */
  pCtxt = (HAL_clk_PLLContextType *)pSource->pContext;

  /*
   * Clear all config values not modified in this function.
   */
  pConfig->eVCO = HAL_CLK_PLL_VCO1;
  pConfig->nM = 0;
  pConfig->nN = 0;
  pConfig->nVCOMultiplier = 0;
  pConfig->nAlphaU = 0;

  /*
   * Read current L and Alpha values.
   */
  nMode = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pCtxt);

  /*
   * Check to see if fractional value is enabled
   */
  if ( nMode & HWIO_FMSK(PLL_USER_CTL, MN_ACC) )
  {
    if ( nMode & HWIO_FMSK(PLL_USER_CTL, ALPHA_MODE) )
    {
      /*
       * In M/N mode
       */
      pConfig->nM = HAL_CLK_PLL_HWIO_IN(PLL_ALPHA_VAL, pCtxt);
      pConfig->nN = HAL_CLK_PLL_HWIO_IN(PLL_ALPHA_VAL, pCtxt);
    }
    else
    {
      /*
       * In Alpha mode
       */
      pConfig->nAlpha = HAL_CLK_PLL_HWIO_IN(PLL_ALPHA_VAL, pCtxt);
    }
  }

  /*
   * Read current L-Val
   */
  pConfig->nL = HAL_CLK_PLL_HWIO_IN(PLL_L_VAL, pCtxt);

  /*
   * Determine the oscillator source.
   */
  pConfig->eSource = HAL_CLK_SOURCE_XO;

  /*
   * Get the pre and post dividers.
   */
  nConfigVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pCtxt);
  pConfig->nPreDiv = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL, CLK_REF_PRE_DIV))
                      >> (HWIO_SHFT(PLL_USER_CTL, CLK_REF_PRE_DIV))) + 1;
  pConfig->nPostDiv = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL, CLK_POST_DIV))
                       >> HWIO_SHFT(PLL_USER_CTL, CLK_POST_DIV));
  pConfig->nPostDiv = HAL_clk_AgeraPLLPostDivFromHW(pConfig->nPostDiv);

} /* END HAL_clk_AgeraPLLDetectPLLConfig */

