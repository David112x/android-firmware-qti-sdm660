#ifndef DELAY_CALIB_H
#define DELAY_CALIB_H
/*==============================================================================
  @file delay_calib.h
  @brief This file contains DELAY API
==============================================================================*/

/*=======================================================================
* Copyright (c) 2017 Qualcomm Technologies, Inc.  All Rights Reserved.
* Confidential and Proprietary – Qualcomm Technologies, Inc.
=========================================================================*/
/*========================================================================
 Edit History

 when       who     what, where, why
 --------   ---     -------------------------------------------------------
 03/21/17   pag     Added h2xml comments.
 ========================================================================== */

/** @h2xml_title1           {Audio Delay/Latency}
    @h2xml_title_agile_rev  {Audio Delay/Latency}
    @h2xml_title_date       {February 9, 2017} */

#include  "mmdefs.h"

/*------------------------------------------------------------------------------
   Module
------------------------------------------------------------------------------*/
/*==============================================================================
   Constants
==============================================================================*/

/* Global unique Module ID definition
   Module library is independent of this number, it defined here for static
   loading purpose only */
#define AUDPROC_MODULE_ID_DELAY                    0x00010772
/**
    @h2xmlm_module       {"AUDPROC_MODULE_ID_DELAY",
                          AUDPROC_MODULE_ID_DELAY}
    @h2xmlm_displayName  {"AUDIO DELAY"}

    @h2xmlm_description  { ID of the Delay/Latency module on the LPCM data path.\n
    This module introduces the specified amount of delay in the audio path.\n
    If the delay is increased, silence is inserted. If the delay is decreased,
    data is dropped.\n

    There are no smooth transitions.The resolution of the delay applied is
    limited by the period of a single sample. Qualcomm recommends muting the
    device path when the delay is changed (to avoid glitches).\n

    This module supports the AUDPROC_PARAM_ID_DELAY parameter ID.\n }

     @h2xmlm_toolPolicy              {Calibration; RTC}

    @{                   <-- Start of the Module -->
*/
/* ID of the Delay parameter used by AUDPROC_MODULE_ID_DELAY. */
#define AUDPROC_PARAM_ID_DELAY                     0x00010773

/* Structure for delay parameter in LPCM data paths. */
typedef struct audproc_delay_param_t audproc_delay_param_t;
/** @h2xmlp_parameter   {"AUDPROC_PARAM_ID_DELAY", AUDPROC_PARAM_ID_DELAY}
    @h2xmlp_description {Delay in microseconds.}
    @h2xmlp_toolPolicy  {NO_SUPPORT}  */

#include "adsp_begin_pack.h"

/* Payload of the AUDPROC_PARAM_ID_DELAY parameter used by
 AUDPROC_MODULE_ID_DELAY.
 */
struct audproc_delay_param_t
{
   uint32_t delay_us;
   /**< @h2xmle_description  {Delay in microseconds.\n
   The amount of delay must be greater than 0.\n  If the value is zero, this module is disabled.\n
   The actual resolution of the delay is limited by the period of a single audio sample.\n}
   @h2xmle_range   {0..100000}
   @h2xmle_default {100000} */

}
#include "adsp_end_pack.h"
;
#define AUDPROC_PARAM_ID_MCHAN_DELAY                     0x00010941

/* Structure for delay parameter in LPCM data paths. */
typedef struct audproc_delay_param_per_config_t audproc_delay_param_per_config_t;


struct audproc_delay_param_per_config_t
{
   uint32_t channel_mask_lsb;
   /**< @h2xmle_description  { Lower 32 bits of the mask that indicates the corresponding channel
                               whose delay is to be set.
                               - Set the bits corresponding to 1 to 31 channels of standard channel
                                 mapping (channels are mapped per standard channel mapping)
                               - Position of the bit to set 1 (left shift) (channel_map)                   } */

   uint32_t channel_mask_msb;
   /**< @h2xmle_description  { Upper 32 bits of the mask that indicates the corresponding channel
                               whose delay is to be set.
                               - Set the bits corresponding to 32 to 63 channels of standard channel
                                 mapping (channels are mapped per standard channel mapping)
                               - Position of the bit to set  1 (left shift) (channel_map - 32)              } */


   uint32_t delay_us;
    /**< @h2xmle_description  {Delay in microseconds.\n
   The amount of delay must be greater than 0.\n  If the value is zero, this module is disabled.\n
   The actual resolution of the delay is limited by the period of a single audio sample.\n}
   @h2xmle_range   {0..100000}
   @h2xmle_default {100000} */
  };


typedef struct audproc_mchan_delay_param_t audproc_mchan_delay_param_t;
/** @h2xmlp_parameter   {"AUDPROC_PARAM_ID_MCHAN_DELAY", AUDPROC_PARAM_ID_MCHAN_DELAY}
    @h2xmlp_description {Delay in microseconds.}
    @h2xmlp_toolPolicy  {NO_SUPPORT}  */


#include "adsp_begin_pack.h"

struct audproc_mchan_delay_param_t
{
   uint32_t num_config;
   /**< @h2xmle_description  {Specifies the different delay configurations.}
        @h2xmle_range        {1..63}
        @h2xmle_default      {1}                        */

   audproc_delay_param_per_config_t mchan_delay[0];
   /**< @h2xmle_description {Specifies the different delay configurations.}}
        @h2xmle_variableArraySize {num_config}
        @h2xmle_default      {0} */

}
#include "adsp_end_pack.h"
;
/** @}                   <-- End of the Module -->*/
#endif


















