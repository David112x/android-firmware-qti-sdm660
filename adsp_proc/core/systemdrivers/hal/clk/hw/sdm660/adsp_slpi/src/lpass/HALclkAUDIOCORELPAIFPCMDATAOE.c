/*
==============================================================================

FILE:         HALclkAUDIOCORELPAIFPCMDATAOE.c

DESCRIPTION:
   This auto-generated file contains the clock HAL code for the 
   AUDIOCORELPAIFPCMDATAOE clocks.

   List of clock domains:
     - HAL_clk_mLPASSLPAIFPCMOEClkDomain


   List of power domains:



==============================================================================

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/hal/clk/hw/sdm660/adsp_slpi/src/lpass/HALclkAUDIOCORELPAIFPCMDATAOE.c#1 $

==============================================================================
            Copyright (c) 2016 Qualcomm Technologies Incorporated.
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

extern HAL_clk_ClockDomainControlType  HAL_clk_mLPASSClockDomainControl;
extern HAL_clk_ClockDomainControlType  HAL_clk_mLPASSClockDomainControlRO;


/* ============================================================================
**    Data
** ==========================================================================*/


/*                           
 *  HAL_clk_mLPAIFPCMOEClkDomainClks
 *                  
 *  List of clocks supported by this domain.
 */
static HAL_clk_ClockDescType HAL_clk_mLPAIFPCMOEClkDomainClks[] =
{
  {
    /* .szClockName      = */ "audio_core_lpaif_pcm_data_oe_clk",
    /* .mRegisters       = */ { HWIO_OFFS(LPASS_AUDIO_CORE_LPAIF_PCM_DATA_OE_CBCR), 0, {0, 0} },
    /* .pmControl        = */ &HAL_clk_mGenericClockControl,
    /* .nTestClock       = */ HAL_CLK_LPASS_TEST_AUDIO_CORE_LPAIF_PCM_DATA_OE_CLK
  },
};


/*
 * HAL_clk_mLPASSLPAIFPCMOEClkDomain
 *
 * LPAIFPCMOE clock domain.
 */
HAL_clk_ClockDomainDescType HAL_clk_mLPASSLPAIFPCMOEClkDomain =
{
  /* .nCGRAddr             = */ HWIO_OFFS(LPASS_LPAIF_PCMOE_CMD_RCGR),
  /* .pmClocks             = */ HAL_clk_mLPAIFPCMOEClkDomainClks,
  /* .nClockCount          = */ sizeof(HAL_clk_mLPAIFPCMOEClkDomainClks)/sizeof(HAL_clk_mLPAIFPCMOEClkDomainClks[0]),
  /* .pmControl            = */ &HAL_clk_mLPASSClockDomainControl,
  /* .pmNextClockDomain    = */ NULL
};

