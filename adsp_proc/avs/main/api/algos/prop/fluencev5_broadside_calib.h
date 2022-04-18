#ifndef FLUENCEV5_BROADSIDE_CALIB_H
#define FLUENCEV5_BROADSIDE_CALIB_H
/*==============================================================================
  @file fluencev5_broadside_calib.h
  @brief This file contains FLUENCEV5_BROADSIDE
==============================================================================*/
/*=======================================================================
* Copyright (c) 2017 Qualcomm Technologies, Inc.  All Rights Reserved.
* Confidential and Proprietary – Qualcomm Technologies, Inc.
=========================================================================*/
/*========================================================================
 Edit History

 when       who     what, where, why
 --------   ---     -------------------------------------------------------
 04/11/17   shrani  Added h2xml comments.
 ========================================================================== */
#include "mmdefs.h"
#include "voice_param_mod_enable_calib.h"
#include "ecns_common_param_calib.h"
#include "audio_rtm_logging_param_calib.h"


/** @h2xml_title1           {VOICE_MODULE_FLUENCEV5_BROADSIDE}
    @h2xml_title_agile_rev  {VOICE_MODULE_FLUENCEV5_BROADSIDE}
    @h2xml_title_date       {April 11, 2017} */


#define VOICE_MODULE_FLUENCEV5_BROADSIDE  0x00010F18
/**
    @h2xmlm_module       {"VOICE_MODULE_FLUENCEV5_BROADSIDE",
                          VOICE_MODULE_FLUENCEV5_BROADSIDE}
    @h2xmlm_displayName  {"TX VOICE DM FV5 BROADSIDE"}
	@h2xmlm_description {Dual-mic Fluence version 5 broadside ECNS in the voice processor on the Tx path.\n
This module supports the following parameter IDs\n
VOICE_PARAM_MOD_ENABLE\n
VOICE_PARAM_AF_COEFFS\n
VOICE_PARAM_ECHO_PATH_DELAY\n
VOICE_PARAM_FLUENCE_EC\n
VOICE_PARAM_FLUENCE_NS_SPK\n
VOICE_PARAM_FP_STATE\n
VOICE_PARAM_FLUENCE_NS_SPK_STATE\n
VOICE_PARAM_MUTE_DET\n
VOICE_PARAM_FLUENCE_FLEC\n
VOICE_PARAM_FLUENCE_FLEC_STATE\n
VOICE_PARAM_MUTE_DET_STATE\n
RTM_LOGGING_PARAM_ENABLE \n
RTM_PCM_LOGGING_PARAM  \n\n}

    @h2xmlm_ToolPolicy 				{Calibration; RTC}
    @{                   <-- Start of the Module -->

@h2xml_Select					{voice_param_mod_enable_t}
   @h2xmlm_InsertParameter
   @h2xml_Select       {voice_param_mod_enable_t::Enable}
    @h2xmle_default     {1}



@h2xml_Select					{voice_param_echo_path_delay_t}
   @h2xmlm_InsertParameter

@h2xml_Select					{voice_param_fluence_ec_t}
   @h2xmlm_InsertParameter

   @h2xml_Select					{voice_param_fluence_ns_spk_t}
   @h2xmlm_InsertParameter

   @h2xml_Select					{voice_param_fp_state_t}
   @h2xmlm_InsertParameter

  @h2xml_Select					{voice_param_fluence_ns_spk_state_t}
   @h2xmlm_InsertParameter

   @h2xml_Select					{voice_param_mute_det_t}
   @h2xmlm_InsertParameter

     @h2xml_Select					{mic_low_det_struct}
   @h2xmlm_InsertParameter

   @h2xml_Select					{voice_param_mute_det_state_t}
   @h2xmlm_InsertParameter


    @h2xml_Select					{voice_param_fluence_flec_t}
    @h2xmlm_InsertParameter

    @h2xml_Select					{voice_param_fluence_flec_state_t}
   @h2xmlm_InsertParameter

   @h2xml_Select					{voice_param_af_coeffs_t}
   @h2xmlm_InsertParameter

   @h2xml_Select					{voice_param_aec_path_struct_t}
   @h2xmlm_InsertParameter

    @h2xml_Select					{audproc_rtm_logging_enable_payload_t}
    @h2xmlm_InsertParameter

    @h2xml_Select					{audproc_rtm_pcm_logging_payload_t}
    @h2xmlm_InsertParameter



   @}                   <-- End of the Module -->*/
#endif
