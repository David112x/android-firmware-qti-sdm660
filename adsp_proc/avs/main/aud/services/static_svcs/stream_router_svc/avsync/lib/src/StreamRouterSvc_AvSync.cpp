/**
@file StreamRouterSvc_AvSync.cpp
@brief This file defines stream router AV-Sync utilities.

Copyright (c) 2015-2017 Qualcomm Technologies, Inc.  All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
 *//*====================================================================== */

/*========================================================================
Edit History

$Header: //components/rel/avs.adsp/2.8/aud/services/static_svcs/stream_router_svc/avsync/lib/src/StreamRouterSvc_AvSync.cpp#9 $

when               who     what, where, why
--------               ---         -------------------------------------------------------
07/14/2015   KR       Created file
12/15/2015   YW       DSD related changes
========================================================================== */
/* =======================================================================
INCLUDE FILES FOR MODULE
========================================================================== */
#include "qurt_elite.h"
#include "Elite.h"
#include "EliteMsg_Custom.h"
#include "AudioStreamMgr_AprIf.h"
#include "StreamRouterSvc.h"
#include "adsp_asm_api.h"
#include "adsp_media_fmt.h"
#include "adsp_asm_session_commands.h"
#include "AudioStreamMgr_GetSetBits.h"
#include "AudioStreamMgr.h"
#include "adsp_mtmx_strtr_api.h"
#include "StreamRouterSvcStructs.h"
#include "AudioStreamMgr_PrivateDefs.h"
#include "EliteLoggingUtils_i.h"
#include "AudDevMgr_AprIf.h"
#include "avsync_lib.h"
#include "avsync_stats_lib.h"
#include "IEC61937.h"
#include <audio_basic_op_ext.h>

//#define DBG_STRTR_AVSYNC

ADSPResult stream_router_svc_set_avsync_params(stream_router_svc_t* pMe, uint32_t param_id, void *param_val_ptr, uint16_t param_size, uint32_t port_id)
{

   if(NULL == param_val_ptr)
   {
      return ADSP_EFAILED;
   }

   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];

   switch(param_id)
   {
   case ASM_SESSION_MTMX_STRTR_PARAM_RENDER_DECISION:
   {
      //Make sure that the Run Command has not been issued yet. If port is already in run state, reject this Set Param. Default mode will be used.
      if( RUN == in_port_ptr->stream_state)
      {
         MSG_2(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Streamrouter: i/p port %lu is in %d state and cannot accept this SetParam",
               port_id, in_port_ptr->stream_state);

         return ADSP_EUNEXPECTED;
      }
      break;
   }
   case ASM_SESSION_MTMX_PARAM_ADJUST_SESSION_TIME_FINE_CTL:
   {
       MSG_2(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Streamrouter: i/p port %lu received unsupported SetParam ID %x",
             port_id, param_id);

       return ADSP_EBADPARAM;
   }


   default:
   {
      //Do nothing, let avsync lib handle.
   }
   }

   return  avsync_lib_set_param(in_port_ptr->avsync_params,param_id,param_val_ptr,param_size);
}

ADSPResult stream_router_svc_query_avsync_stats(stream_router_svc_t* pMe, asm_session_param_data_v2_t *param_data_ptr, uint32_t payload_size, uint32_t struct_size, uint32_t port_id)
{
   ADSPResult result = ADSP_EOK;
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];
   if(payload_size < struct_size)
   {
      MSG_2(MSG_SSID_QDSP6, DBG_ERROR_PRIO, " Param Id %lu: payload size %lu too small",
            param_data_ptr->param_id, payload_size);
      return ADSP_ENEEDMORE;
   }
   result = avsync_lib_query_stat(in_port_ptr->avsync_params, param_data_ptr->param_id, param_data_ptr + 1);

   if(ADSP_EOK != result)
   {
      MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, " Get Session Stats received before setting stats window start and end");
      return result;
   }
   param_data_ptr->param_size = struct_size;

   return result;
}

ADSPResult stream_router_svc_get_avsync_params(stream_router_svc_t* pMe)
{
   ADSPResult result = ADSP_EOK;
   EliteMsg_CustomStreamRouterGetSetParam *param_msg_ptr =
         (EliteMsg_CustomStreamRouterGetSetParam *)pMe->cmd_msg.pPayload;
   asm_session_param_data_v2_t * param_data_ptr = (asm_session_param_data_v2_t *)param_msg_ptr->pnParamData;
   uint32_t payload_size = param_msg_ptr->unSize - sizeof(asm_session_param_data_v2_t);
   uint32_t port_id = param_msg_ptr->unPortID;
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];

   //get the port structure of the primary output port this input port is connected to
   stream_router_output_port_t *out_port_ptr = &pMe->out_port[in_port_ptr->primary_output_port];

   MSG_1(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " AVSync GetParam Id: 0x%lx", param_data_ptr->param_id);

   switch(param_data_ptr->param_id)
   {
   case ASM_SESSION_MTMX_STRTR_PARAM_SESSION_TIME_V3:
   {
      if(payload_size < sizeof(asm_session_mtmx_strtr_param_session_time_v3_t))
      {
         MSG_2(MSG_SSID_QDSP6, DBG_ERROR_PRIO, " Param Id %lx: payload size %lu too small",
               param_data_ptr->param_id, payload_size);
         return ADSP_ENEEDMORE;
      }
      uint64_t current_session_clock = 0;
      uint64_t current_absolute_time = 0;
      avsync_lib_get_internal_param(in_port_ptr->avsync_params,SESSION_CLOCK,&(current_session_clock));
      avsync_lib_get_internal_param(in_port_ptr->avsync_params,ABSOLUTE_TS,&(current_absolute_time));
      asm_session_mtmx_strtr_param_session_time_v3_t *session_time_ptr = (asm_session_mtmx_strtr_param_session_time_v3_t *)(param_data_ptr + 1);
      session_time_ptr->session_time_msw = (uint32_t)(current_session_clock >> 32);
      session_time_ptr->session_time_lsw = (uint32_t)current_session_clock;
      session_time_ptr->absolute_time_msw = (uint32_t)(current_absolute_time >> 32);
      session_time_ptr->absolute_time_lsw = (uint32_t)(current_absolute_time);
      session_time_ptr->time_stamp_msw = (uint32_t)(out_port_ptr->ts_state.output_buffer_ts >> 32);
      session_time_ptr->time_stamp_lsw = (uint32_t)(out_port_ptr->ts_state.output_buffer_ts);

      if (in_port_ptr->is_first_buffer_received)
      {
         session_time_ptr->flags = out_port_ptr->ts_state.ts_valid?ASM_SESSION_MTMX_STRTR_PARAM_SESSION_TIME_TIMESTAMP_VALID_FLAG_BIT_MASK:0;
      }
      else
      {
         session_time_ptr->flags = 0;
      }

      MSG_7(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " get session time: flag = 0x%lx session,abs,ts: (msw,lsw) = (%lu,%lu), (%lu,%lu) (%lu,%lu).",
            session_time_ptr->flags, session_time_ptr->session_time_msw, session_time_ptr->session_time_lsw,
            session_time_ptr->absolute_time_msw, session_time_ptr->absolute_time_lsw,
            session_time_ptr->time_stamp_msw, session_time_ptr->time_stamp_lsw);

      param_data_ptr->param_size = sizeof(asm_session_mtmx_strtr_param_session_time_v3_t);
      break;
   }
   case ASM_SESSION_MTMX_STRTR_PARAM_SESSION_INST_STATISTICS_V2:
   {
      result = stream_router_svc_query_avsync_stats(pMe, param_data_ptr, payload_size, sizeof(asm_session_mtmx_strtr_session_inst_statistics_v2_t), port_id);
      break;
   }
   case ASM_SESSION_MTMX_STRTR_PARAM_SESSION_CUMU_STATISTICS_V2:
   {
      result = stream_router_svc_query_avsync_stats(pMe, param_data_ptr, payload_size, sizeof(asm_session_mtmx_strtr_session_cumu_statistics_v2_t), port_id);
      break;
   }
   default:
      MSG_1(MSG_SSID_QDSP6, DBG_ERROR_PRIO, " Invalid param Id %lx for AVSync GetParam", param_data_ptr->param_id);
      return ADSP_EBADPARAM;
   }

   return result;
}

ADSPResult stream_router_init_input_avsync(stream_router_svc_t *pMe, uint32_t port_id)
{
   pMe->in_port[port_id].avsync_params = qurt_elite_memory_malloc(avsync_lib_getsize(),QURT_ELITE_HEAP_DEFAULT);
   if(NULL == pMe->in_port[port_id].avsync_params)
   {
      MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failed to alloc memory for avsync lib !! \n");
      return ADSP_EFAILED;
   }
   memset(pMe->in_port[port_id].avsync_params,0,avsync_lib_getsize());
   char inst_name[32];
   snprintf(inst_name,32,"SRIp %lu",port_id);
   avsync_lib_init(pMe->in_port[port_id].avsync_params,inst_name);
   return ADSP_EOK;
}

ADSPResult stream_router_deinit_input_avsync(stream_router_svc_t *pMe, uint32_t port_id)
{
   if(pMe->in_port[port_id].avsync_params)
   {
      (void)avsync_lib_deinit_s2d_drift(pMe->in_port[port_id].avsync_params);
      avsync_lib_deinit(pMe->in_port[port_id].avsync_params);
      qurt_elite_memory_free(pMe->in_port[port_id].avsync_params);
      pMe->in_port[port_id].avsync_params = NULL;
   }
   return ADSP_EOK;
}

ADSPResult stream_router_svc_init_s2d_drift(stream_router_svc_t *pMe, uint32_t port_id)
{
   ADSPResult result = ADSP_EOK;
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];
   result = avsync_lib_init_s2d_drift(in_port_ptr->avsync_params);
   if(ADSP_EOK != result)
   {
      MSG_2(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Stream router: i/p port %lu Init of pAVSyncS2DDriftUtilsLib failed. Res=%d",
            port_id, result);
   }

   return result;
}

ADSPResult stream_router_svc_update_s2d_drift(stream_router_svc_t *pMe, uint32_t port_id, int32_t input_data_length, uint64_t time_stamp)
{
   ADSPResult result = ADSP_EOK;
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];
   result = avsync_lib_update_s2d_drift(in_port_ptr->avsync_params, input_data_length, time_stamp);
   return result;
}

ADSPResult stream_router_svc_update_session_clock(stream_router_svc_t *pMe, uint32_t input_port_id, bool_t is_pausing)
{
   ADSPResult result=ADSP_EOK;
   if(input_port_id >= STRTR_MAX_PORTS)
   {
      MSG_1(MSG_SSID_QDSP6, DBG_HIGH_PRIO, "Stream router: invalid session ID %lu",input_port_id);
      return ADSP_EFAILED;
   }
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[input_port_id];
   stream_router_output_port_t *out_port_ptr = &pMe->out_port[in_port_ptr->primary_output_port];
   uint64_t current_session_clock = 0;
   uint64_t current_start_time;
   uint32_t current_rendering_decision_type;
   uint64_t total_remainder_duration = 0;
   //increment the session clock
   if(!is_pausing)//If in run state, count valid data bursts being rendered
   {
      in_port_ptr->ts_state.duration_rendered += in_port_ptr->data_burst_duration;
      in_port_ptr->input_buffer_remainder_total += in_port_ptr->input_buffer_remainder_unit;
      //In addition to the data burst duration, we also calculate if the accumulated remainder
      // is large enough to be considered;
      total_remainder_duration = stream_router_svc_remainder_to_duration(in_port_ptr,
            (in_port_ptr->input_buffer_remainder_total),
            out_port_ptr->sampling_rate, out_port_ptr->num_channels,out_port_ptr->bits_per_sample);
      if (0 < total_remainder_duration)
      {
         //add remainder duration to total duration rendered;
         in_port_ptr->ts_state.duration_rendered += total_remainder_duration;
         // update the total remainder size accordingly;
         in_port_ptr->input_buffer_remainder_total -= (stream_router_svc_duration_to_remainder_size(in_port_ptr,
               total_remainder_duration, out_port_ptr->sampling_rate,
               out_port_ptr->num_channels,out_port_ptr->bits_per_sample));
      }

   }
   else //If need to pause, count pause bursts being rendered.
   {
      in_port_ptr->ts_state.duration_rendered += out_port_ptr->pause_buffer_duration;
   }
   uint64_t session_clock_total_increment = in_port_ptr->ts_state.duration_rendered;
   uint64_t proposed_incremental_session_clock = in_port_ptr->ts_state.initial_session_clock + session_clock_total_increment;
   result = avsync_lib_update_stc_clock(in_port_ptr->avsync_params);
   if(result != ADSP_EOK)
   {
      return result;
   }
   result = avsync_lib_update_session_clock(in_port_ptr->avsync_params,
         proposed_incremental_session_clock);
   //Update expected session clock
   avsync_lib_get_internal_param(in_port_ptr->avsync_params,SESSION_CLOCK,&current_session_clock);
   avsync_lib_get_internal_param(in_port_ptr->avsync_params,RENDERING_DECISION_TYPE,&current_rendering_decision_type);
   if(ASM_SESSION_MTMX_STRTR_PARAM_RENDER_DECISION_DEFAULT != current_rendering_decision_type)
   {
      avsync_lib_get_internal_param(in_port_ptr->avsync_params,START_TIME,&current_start_time);
      current_session_clock += current_start_time;
   }
   result = avsync_lib_set_internal_param(in_port_ptr->avsync_params,EXPECTED_SESSION_CLOCK,&current_session_clock,
         sizeof(current_session_clock));

   //Returning result for updating of session clock.
   return result;
}

/*======================================================================
FUNCTION      stream_router_svc_custom_run_rx_mode

DESCRIPTION   changes the stream router state to RUN. Starts processing
input data buffers
Two types of run
1) Run Immediate - Here the sream router starts outputting data as soon
as it is available at the input port
2) Run at absolute time/Run with delay - In this case stream router
compares the start time (+ incoming buffer TS) with the AV timer and
starts outputting valid data only when the two are equal

DEPENDENCIES  none

RETURN VALUE  error code

SIDE EFFECTS  none
======================================================================*/
ADSPResult stream_router_svc_custom_run_rx_mode(stream_router_svc_t *pMe)
{
   EliteMsg_CustomStreamRouterRun *run_msg_ptr = (EliteMsg_CustomStreamRouterRun *)pMe->cmd_msg.pPayload;

   uint32_t port_id = run_msg_ptr->port_id;
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];

   if(DISCONNECTED == in_port_ptr->stream_state)
   {
      MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, " received RUN before connection complete\n");
      //cannot issue run till graph is established
      elite_msg_finish_msg(&pMe->cmd_msg, ADSP_ENOTREADY);
      return ADSP_ENOTREADY;
   }

   //start listening for data on the particular input port
   pMe->current_bitfield |= stream_router_svc_input_port_to_signal_mask(port_id);

   //also start listening to each of the connected output ports
   uint32_t temp_bitfield = stream_router_svc_get_connected_active_out_ports(pMe, in_port_ptr);
   uint32_t output_port_id = 0;
   while(temp_bitfield != 0)
   {
      if(temp_bitfield & 1)
      {
         pMe->current_bitfield |= stream_router_svc_output_port_to_signal_mask(output_port_id);
      }
      temp_bitfield >>= 1;
      output_port_id++;
   }

   //The downstream delay is automatically considered from the output port context.
   avsync_lib_process_run(in_port_ptr->avsync_params,run_msg_ptr->unStartFlag, 0);

   //For different RUN modes, set the stream state and start times
   switch(run_msg_ptr->unStartFlag)
   {
   case ASM_SESSION_CMD_RUN_START_TIME_RUN_IMMEDIATE:
      in_port_ptr->stream_state = RUN;
      MSG(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " Run Immediate");
      break;

   case ASM_SESSION_CMD_RUN_START_TIME_RUN_AT_ABSOLUTE_TIME:
   case ASM_SESSION_CMD_RUN_START_TIME_RUN_WITH_DELAY:
   case ASM_SESSION_CMD_RUN_START_TIME_RUN_AT_RELATIVE_TIME:
      in_port_ptr->stream_state = WAITING;
      avsync_lib_set_internal_param(in_port_ptr->avsync_params,START_TIME,&run_msg_ptr->llStartTime,
            sizeof(run_msg_ptr->llStartTime));
      MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO, "Stream Router Svc: Run at absolute time = MSW:%lu, LSW=%lu",
            (uint32_t)(run_msg_ptr->llStartTime >> 32), (uint32_t)run_msg_ptr->llStartTime);
      break;

   default:
      MSG_1(MSG_SSID_QDSP6, DBG_ERROR_PRIO, " Does not support this RUN mode %lu", run_msg_ptr->unStartFlag);
      elite_msg_finish_msg(&pMe->cmd_msg, ADSP_EUNSUPPORTED);
      return ADSP_EUNSUPPORTED;
   }

   MSG(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " Processed RUN");

   //in synchronous mode need to sync to the next buffer timestamp
   if(!in_port_ptr->ts_state.is_asynchronous_mode)
   {
      in_port_ptr->ts_state.sync_to_next_ts = TRUE;
   }

   in_port_ptr->kpps_vote = default_kpps;
   in_port_ptr->bw_vote = in_port_ptr->sampling_rate * in_port_ptr->num_channels * (in_port_ptr->bits_per_sample / BITS_PER_BYTE);
   if (0 == in_port_ptr->bw_vote)
   {
      in_port_ptr->bw_vote = default_bw;
   }
   stream_router_svc_process_kpps_bw(pMe, FALSE, FALSE);

   //ACK run command
   elite_msg_finish_msg(&pMe->cmd_msg, ADSP_EOK);

   return ADSP_EOK;
}

ADSPResult stream_router_svc_reset_session_clock(stream_router_svc_t *pMe, uint32_t port_id)
{
   avsync_lib_set_internal_param(pMe->in_port[port_id].avsync_params, SESSION_CLOCK, &(AVSYNC_LIB_ZERO_SESSION_CLOCK),
         sizeof(AVSYNC_LIB_ZERO_SESSION_CLOCK));
   return ADSP_EOK;
}

ADSPResult stream_router_svc_update_session_clock_2(stream_router_svc_t *pMe, uint32_t port_id, uint64_t time_stamp)
{
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];
   avsync_lib_set_internal_param(in_port_ptr->avsync_params, SESSION_CLOCK, &(time_stamp), sizeof(time_stamp));
   return ADSP_EOK;
}

ADSPResult stream_router_svc_update_expected_session_clk(stream_router_svc_t *pMe, uint32_t port_id, uint64_t proposed_val)
{
    stream_router_input_port_t *in_port_ptr = &pMe->in_port[port_id];
    avsync_lib_set_internal_param(in_port_ptr->avsync_params, EXPECTED_SESSION_CLOCK, &(proposed_val), sizeof(proposed_val));
    return ADSP_EOK;
}

ADSPResult stream_router_svc_set_in_out_drift_ptr(stream_router_svc_t *pMe, uint32_t in_port_id, uint32_t out_port_id)
{
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[in_port_id];
   stream_router_output_port_t *out_port_ptr = &pMe->out_port[out_port_id];

   if(NULL == out_port_ptr->afe_drift_ptr)
   {
      MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO,"Stream router: i/p port %u, Top prio o/p port %lu AFE Drift Ptr is NULL",
            in_port_id, out_port_id);
   }
   else
   {
      MSG_3(MSG_SSID_QDSP6, DBG_HIGH_PRIO,"Stream router: i/p port %u, Top prio o/p port %lu AFE Drift Ptr %p",
            in_port_id, out_port_id, out_port_ptr->afe_drift_ptr);
      avsync_lib_set_device_drift_pointer(in_port_ptr->avsync_params, &(out_port_ptr->afe_drift_ptr->avt_drift_info));
   }

   return ADSP_EOK;
}

/*======================================================================
FUNCTION      stream_router_svc_process_output_data_q_rx_mode

DESCRIPTION   pops a buffer from the the output data queue.
Takes one of the following actions:
1)If no input buffer available fill output buffer with pause
data bursts
2)If input buffer available and timestamp matches with session
clock or asynchrounous mode, copy input content to output
buffer.
3)If synchrounous mode and input buffer TS in past, drop it
4)If future TS, add pause burst for the correct duration

DEPENDENCIES  none

RETURN VALUE  error code

SIDE EFFECTS  none
======================================================================*/
ADSPResult stream_router_svc_process_output_data_q_rx_mode(stream_router_svc_t *pMe, uint32_t output_port_id)
{
   ADSPResult nResult = ADSP_EOK;
   qurt_elite_bufmgr_node_t output_buffer_node;
   elite_msg_any_t *msg_to_peer_ptr;
   elite_msg_data_buffer_t *out_buf_ptr;
   uint32_t pause_duration;
   int64_t delta;
   uint32_t input_port_id;
   stream_router_input_port_t *in_port_ptr;
   uint32_t old_buf_size=0;
   uint64_t downstream_delay=0,downstream_buf_delay=0;
   avsync_rendering_decision_t rendering_decision = RENDER;

   stream_router_output_port_t *out_port_ptr = &pMe->out_port[output_port_id];
   if(NULL == out_port_ptr->downstream_svc_handle)
   {
      //if downstream service has not been connected then don't do anything
      return ADSP_ENOTREADY;
   }

   // Take next msg off the q
   nResult = qurt_elite_queue_pop_front(out_port_ptr->service_handle.gpQ, (uint64_t*)&output_buffer_node);

   if(ADSP_EOK != nResult)
   {
      MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failure in popping output buffer ");
      goto _EoS_process;
   }

   out_buf_ptr = (elite_msg_data_buffer_t *)output_buffer_node.pBuffer;

   old_buf_size = out_buf_ptr->nActualSize;

   /** check if buffer max size matches. If not, free this buffer and create one. Once all buffers are returned &
    * if input is disconnected, then stop listening to output queue ultimately when all buffers are returned. */
   nResult = stream_router_svc_check_recreate_out_buf(pMe, output_port_id, &out_buf_ptr);

   output_buffer_node.pBuffer = out_buf_ptr;

   if (NULL == out_buf_ptr)
   {
      MSG(MSG_SSID_QDSP6, DBG_HIGH_PRIO, "returning since out buf is null ");
      goto _EoS_process;
   }
   if(ADSP_EOK != nResult)
   {
      MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failure in recreating output buffer ");
      goto _EoS_process;
   }

   //find out the input port this output port is connected to
   input_port_id = out_port_ptr->connected_input_port;
   if (STRTR_INVALID_PORT_ID == input_port_id)
   {
      (void) elite_msg_push_payload_to_returnq(out_port_ptr->service_handle.gpQ, (elite_msg_any_payload_t*)(output_buffer_node.pBuffer));
      goto _EoS_process;
   }

   in_port_ptr = &pMe->in_port[input_port_id];

   if(WAITING == in_port_ptr->stream_state)
   {
      nResult = stream_router_svc_process_output_data_q_wait_state(pMe, output_port_id, &output_buffer_node, old_buf_size);
      goto _EoS_process;
   }

   //subtract from the accumulated buffer duration, duration for the returned buffer (do this with size before buf is recreated)
   //be careful about stream_router_svc_process_output_data_q_wait_state as it also uses downstream_buffer_duration
   downstream_buf_delay = stream_router_svc_buffer_size_to_duration(in_port_ptr,
         old_buf_size, out_port_ptr->sampling_rate, out_port_ptr->num_channels,out_port_ptr->bits_per_sample);
   out_port_ptr->downstream_buffer_duration -= downstream_buf_delay;

   //downstream delay (1 stream router buffer + AFE delay + compressed COPP delay) needs to be accounted for
   downstream_delay = (*out_port_ptr->copp_buf_delay_ptr) + (*out_port_ptr->copp_alg_delay_ptr) + (*out_port_ptr->afe_delay_ptr) + out_port_ptr->downstream_buffer_duration;
#ifdef DBG_STRTR_AVSYNC
   MSG_5(MSG_SSID_QDSP6, DBG_HIGH_PRIO,"Streamrouter: Downstream Delay %lu, where COPP Buf Delay %lu, COPP Alg Delay %lu, AFE Delay %lu, Downstream Buffer Duration %lu",
         (uint32_t)downstream_delay,
         (uint32_t)*out_port_ptr->copp_buf_delay_ptr,
         (uint32_t)*out_port_ptr->copp_alg_delay_ptr,
         (uint32_t)*out_port_ptr->afe_delay_ptr,
         (uint32_t)out_port_ptr->downstream_buffer_duration);
#endif

   pause_duration = 0;
   //If any input data arrived after the last output buffer was sent out
   if(out_port_ptr->intermediate_buff.is_updated)
   {
      if(is_top_prio_output_port(pMe, output_port_id))
      {
         delta = 0;
         //Get current time used for
         if(!in_port_ptr->ts_state.is_asynchronous_mode)
         {
            avsync_lib_update_stc_clock(in_port_ptr->avsync_params);
            nResult =  avsync_lib_make_rendering_decision(in_port_ptr->avsync_params,
                  in_port_ptr->ts_state.input_buffer_ts,
                  downstream_delay,
                  TRUE,
                  &delta,
                  &rendering_decision);
            if(ADSP_EOK != nResult)
            {
               MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failure in making rendering decision");
               goto _EoS_process;
            }
#ifdef DBG_STRTR_AVSYNC
            uint64_t session_clock = 0;
            uint64_t start_time = 0;
            avsync_lib_get_internal_param(in_port_ptr->avsync_params,SESSION_CLOCK,&session_clock);
            avsync_lib_get_internal_param(in_port_ptr->avsync_params,START_TIME,&start_time);
            //Debug message
            MSG_1(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "rendering decision %d",(int)rendering_decision);
#endif
            uint32_t one_pause_burst_dur = stream_router_svc_get_pause_duration(in_port_ptr, out_port_ptr);

            if(!in_port_ptr->ts_state.skip_update)
            {
               avsync_lib_update_stat(in_port_ptr->avsync_params, delta, in_port_ptr->data_burst_duration);
            }
            in_port_ptr->ts_state.skip_update = FALSE;

            delta = (delta/1000)*1000; //ignore micro-sec (consider only ms), note how this is done after stat update.

            if(DROP == rendering_decision)
            {
               //Buffer is in past
               MSG_1(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " Past TS detected. Dropping data burst (Mismatch duration = %ld us)", (int32_t)delta);

               //sync input TS to output even for drop
               out_port_ptr->ts_state.output_buffer_ts = in_port_ptr->ts_state.input_buffer_ts;
               out_port_ptr->ts_state.ts_valid = TRUE;

               //drop this buffer
               out_port_ptr->intermediate_buff.is_updated = FALSE;
               qurt_elite_queue_push_back(out_port_ptr->service_handle.gpQ, (uint64_t *)&output_buffer_node);
               out_port_ptr->downstream_buffer_duration += stream_router_svc_buffer_size_to_duration(
                     in_port_ptr, out_buf_ptr->nActualSize, out_port_ptr->sampling_rate, out_port_ptr->num_channels,out_port_ptr->bits_per_sample);

               //start listening to input port
               if (RUN == in_port_ptr->stream_state)
               {
                  pMe->current_bitfield |= stream_router_svc_input_port_to_signal_mask(input_port_id);
               }

               nResult = ADSP_EOK;
               goto _EoS_process;
            }//if delta is less than render window by more than one pause burst duration, then insert pause burst
            else if (HOLD == rendering_decision)
            {
               //Buffer is in future
               uint64_t abs_delta = (delta < 0) ? (-delta) : delta;
               MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO,
                     " Future TS detected. Inserting pause bursts if |(Mismatch duration = %ld us)| >= pause burst dur %lu us",
                     (int32_t)abs_delta, one_pause_burst_dur);

               if ( (uint32_t)abs_delta >= one_pause_burst_dur )
               {
                  //limit the pause samples to data burst samples (max output buffer size)
                  pause_duration = (abs_delta > in_port_ptr->data_burst_duration)? in_port_ptr->data_burst_duration : abs_delta;
                  in_port_ptr->ts_state.skip_update = TRUE;
               }
               else
               {
                  //session clock need not be corrected by this amount: session clock and TS will be off by this amount.
                  //render
                  //sync input TS to output for render. note that this out buffer ts will be out of sync with session clock by 1 frame under linear time-stamp cases.
                  out_port_ptr->ts_state.output_buffer_ts = in_port_ptr->ts_state.input_buffer_ts;
                  out_port_ptr->ts_state.ts_valid = TRUE;
               }
            }
            else
            {
               //sync input TS to output for render. note that this out buffer ts will be out of sync with session clock by 1 frame under linear time-stamp cases.
               out_port_ptr->ts_state.output_buffer_ts = in_port_ptr->ts_state.input_buffer_ts;
               out_port_ptr->ts_state.ts_valid = TRUE;
            }
         }
         else
         {
            //reset for invalid TS.
            out_port_ptr->ts_state.output_buffer_ts = 0;
            out_port_ptr->ts_state.ts_valid = FALSE;
         }
      }

      //One of three cases
      //i)  asynchronous mode
      //ii) no timestamp mismatch
      //iii)non top priority output port
      if(0 == pause_duration)
      {
         memscpy(&out_buf_ptr->nDataBuf, out_buf_ptr->nMaxSize, out_port_ptr->intermediate_buff.address_ptr, out_port_ptr->intermediate_buff.actual_size);
         out_buf_ptr->nActualSize = (out_port_ptr->intermediate_buff.actual_size > (uint32_t)out_buf_ptr->nMaxSize) ? out_buf_ptr->nMaxSize : out_port_ptr->intermediate_buff.actual_size;
         out_port_ptr->intermediate_buff.is_updated = FALSE;


         //update the av sync parameters only for top priority output port
         if(is_top_prio_output_port(pMe, output_port_id))
         {  //Update session clock with valid data burst
            stream_router_svc_update_session_clock(pMe,input_port_id, FALSE);
            if(!in_port_ptr->ts_state.is_asynchronous_mode)
            {
               avsync_lib_commit_stat(in_port_ptr->avsync_params);
            }
            if (RUN == in_port_ptr->stream_state)
            {
               //start listening to input port
               pMe->current_bitfield |= stream_router_svc_input_port_to_signal_mask(input_port_id);
            }
         }
         //Add the duration of this buffer to the accumulated duration
         out_port_ptr->downstream_buffer_duration += stream_router_svc_buffer_size_to_duration(
               in_port_ptr, out_buf_ptr->nActualSize, out_port_ptr->sampling_rate, out_port_ptr->num_channels,out_port_ptr->bits_per_sample);
         //query the av-timer
         avsync_lib_update_absolute_time(in_port_ptr->avsync_params,out_port_ptr->downstream_buffer_duration,(is_top_prio_output_port(pMe, output_port_id) && (!in_port_ptr->ts_state.is_asynchronous_mode)));
      }
   }
   else
   {
      //in case of data starvation send 10 ms of pause data burst (at least as big as worst case DMA transfer size)
      MSG_1(MSG_SSID_QDSP6, DBG_HIGH_PRIO,"Rx Stream router out port %lu underrun", output_port_id);
      pause_duration = PAUSE_BURST_DURATION_IN_US;
   }

   //if pause bursts have to be inserted
   if(pause_duration > 0)
   {
      MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO,"Rx Stream router out port %lu introducing pause bursts of %lu microseconds", output_port_id, pause_duration);
      //fill pause burst. pause samples have to be a multiple of the pause burst repetition period
      stream_router_svc_fill_pause_burst(pMe, out_buf_ptr, pause_duration, input_port_id, output_port_id);
      out_port_ptr->pause_buffer_duration = pause_duration;
      //Add the duration of this buffer to the accumulated duration
      out_port_ptr->downstream_buffer_duration += stream_router_svc_buffer_size_to_duration(
            in_port_ptr, out_buf_ptr->nActualSize, out_port_ptr->sampling_rate, out_port_ptr->num_channels, out_port_ptr->bits_per_sample);
      //increment session clock only if in run state and synchronous mode
      //Also do not increment session clock for pause bursts (before 1st data buffer)
      if((RUN == in_port_ptr->stream_state) && (!in_port_ptr->ts_state.is_asynchronous_mode) && (!in_port_ptr->ts_state.sync_to_next_ts))
      {
         //query the av-timer
         avsync_lib_update_absolute_time(in_port_ptr->avsync_params,out_port_ptr->downstream_buffer_duration,(is_top_prio_output_port(pMe, output_port_id)));

         //update the AV-sync related parameters only for top priority output port
         if(is_top_prio_output_port(pMe, output_port_id))
         {
            //Update session clock using pause buffer frames.
            stream_router_svc_update_session_clock(pMe,input_port_id,TRUE);
            avsync_lib_commit_stat(in_port_ptr->avsync_params);
         }
      }
   }
   
   //update the Rx stream router delay as this is equals to total buffering delay
   if( NULL != out_port_ptr->str_rtr_delay_ptr)
   {
      *out_port_ptr->str_rtr_delay_ptr = (uint32_t)out_port_ptr->downstream_buffer_duration;
   }

   //convert buffer node to elite msg
   msg_to_peer_ptr = elite_msg_convt_buf_node_to_msg(
         &output_buffer_node,
         ELITE_DATA_BUFFER,
         NULL, /* do not need response */
         pMe->service_handle.unSvcId,/* token */
         0);  /* do not care response result*/
#ifdef DBG_STRTR_AVSYNC
   MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO, "deliver buffer of size %ld max size %lu",
         out_buf_ptr->nActualSize, out_buf_ptr->nMaxSize);
#endif
   //now push this into downstream service input data queue
   nResult= qurt_elite_queue_push_back(out_port_ptr->downstream_svc_handle->dataQ, (uint64_t*)msg_to_peer_ptr);
   if(ADSP_FAILED(nResult))
   {
      MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failed to deliver buffer dowstream");
      (void) elite_msg_push_payload_to_returnq(out_port_ptr->service_handle.gpQ, (elite_msg_any_payload_t*)(output_buffer_node.pBuffer));
   }

   _EoS_process:
   //if there are any pending EOS's on this port send them down
   nResult |= stream_router_svc_push_eos_downstream(pMe, output_port_id);

   if (ADSP_FAILED(nResult))
   {
      nResult = ADSP_EFAILED;
   }
   return nResult;
}

/*======================================================================
FUNCTION      stream_router_svc_process_output_data_q_wait_state

DESCRIPTION   pops a buffer from the the output data queue while in the
WAIT state
State is set to WAIT when the start time in the run command has not
yet elapsed.

DEPENDENCIES  none

RETURN VALUE  error code

SIDE EFFECTS  none
======================================================================*/
ADSPResult stream_router_svc_process_output_data_q_wait_state(stream_router_svc_t *pMe, uint32_t output_port_id, qurt_elite_bufmgr_node_t *output_buffer_node, uint32_t old_buf_size)
{
   ADSPResult nResult = ADSP_EOK;

   stream_router_output_port_t *out_port_ptr = &pMe->out_port[output_port_id];

   //find out the input port this output port is connected to
   uint32_t input_port_id = out_port_ptr->connected_input_port;
   stream_router_input_port_t *in_port_ptr = &pMe->in_port[input_port_id];

   bool_t out_buf_filled = TRUE;

   elite_msg_data_buffer_t *out_buf_ptr = (elite_msg_data_buffer_t *)output_buffer_node->pBuffer;

   uint32_t buf_size = old_buf_size;
   //subtract from the accumulated buffer duration, duration for the returned buffer
   out_port_ptr->downstream_buffer_duration -= stream_router_svc_buffer_size_to_duration(
         in_port_ptr, buf_size, out_port_ptr->sampling_rate, out_port_ptr->num_channels, out_port_ptr->bits_per_sample);

   //Case 1: An input buffer has not yet been received, or this is not the top priority output port
   if(!in_port_ptr->is_first_buffer_received || !is_top_prio_output_port(pMe, output_port_id))
   {
      //Keep sending pause bursts without checking if the start time is current
      stream_router_svc_fill_pause_burst(pMe, out_buf_ptr, out_port_ptr->pause_buffer_duration, input_port_id, output_port_id);
      buf_size = out_buf_ptr->nActualSize;
   }
   else
   {
      //If TS is not valid, then start rendering now if the start time is in the past. This is done to be compatible with Matrix.
      //If TS is not valid and start time is in the future, then treat the same as though the TS is valid.

      //When TS is invalid, & start time is in the past, there's no way but to start rendering immediately. If we keep dropping we will drop all data
      //& never catch-up with incoming data.
      //with invalid TS, problem occurs when given time is in the past, we will never be able to catch up, unless we count whats dropped.

      nResult = avsync_lib_update_stc_clock(in_port_ptr->avsync_params);
      if(ADSP_EOK != nResult)
      {
         return ADSP_EFAILED;
      }


      //downstream delay (1 stream router buffer + AFE delay + compressed COPP delay) needs to be accounted for
      uint64_t downstream_delay = (*out_port_ptr->copp_buf_delay_ptr) + (*out_port_ptr->copp_alg_delay_ptr) + (*out_port_ptr->afe_delay_ptr) + out_port_ptr->downstream_buffer_duration;

      int64_t delta = 0;
      avsync_rendering_decision_t rendering_decision = RENDER;

      uint64_t input_ts = in_port_ptr->ts_state.input_buffer_ts;

      if (in_port_ptr->ts_state.is_asynchronous_mode)
      {
         input_ts = 0;
      }

      nResult =  avsync_lib_make_rendering_decision(in_port_ptr->avsync_params,
            input_ts,
            downstream_delay,
            FALSE,
            &delta,
            &rendering_decision);


      if(ADSP_EOK != nResult)
      {
         MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failure in making rendering decision");
         return ADSP_EFAILED;
      }

      //Case 2. Current time has not yet reached start time
      if(delta <= 0)
      {
         uint64_t pause_buffer_duration = out_port_ptr->pause_buffer_duration;
         int64_t abs_delta = -delta;

         if(abs_delta >= (int64_t)pause_buffer_duration)
         {
            MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " holding data as effective start time is in the future. Delta = %ld Pause duration=%lu", (uint32_t)delta,(uint32_t)pause_buffer_duration);
            stream_router_svc_fill_pause_burst(pMe, out_buf_ptr, out_port_ptr->pause_buffer_duration, input_port_id, output_port_id);
            buf_size = out_buf_ptr->nActualSize;
         }
         else
         {
            //delta is less than one pause buffer, so send a smaller pause buffer and start running
            //normally from the next call
            //#ifdef DBG_STRTR_AVSYNC
            MSG_2(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " Run Start. Delta = %ld downstream_delay =%lu",(uint32_t)delta,(uint32_t)downstream_delay);
            //#endif
            uint32_t pause_duration = (uint32_t)abs_delta;
            stream_router_svc_fill_pause_burst(pMe, out_buf_ptr, pause_duration, input_port_id, output_port_id);
            buf_size = out_buf_ptr->nActualSize;
            //set the state to RUN since the required time would have elapsed
            in_port_ptr->stream_state = RUN;
            //sync to the incoming timestamp
            if(!in_port_ptr->ts_state.is_asynchronous_mode)
            {
               //session clock syncs to the incoming timestamp. So does the initial session clock.
               //initial session clock and frames rendered are used to avoid any finite word length effects in incrementing session clock
               nResult = avsync_lib_update_session_clock(in_port_ptr->avsync_params,
                     in_port_ptr->ts_state.input_buffer_ts);
               nResult |= avsync_lib_set_internal_param(in_port_ptr->avsync_params,
                     EXPECTED_SESSION_CLOCK,
                     &(in_port_ptr->ts_state.input_buffer_ts),
                     sizeof(in_port_ptr->ts_state.input_buffer_ts));
               in_port_ptr->ts_state.duration_rendered = 0;
            }
            avsync_lib_get_internal_param(in_port_ptr->avsync_params,SESSION_CLOCK,
                  &(in_port_ptr->ts_state.initial_session_clock));
            in_port_ptr->ts_state.sync_to_next_ts = FALSE;

            //sync input TS to output
            out_port_ptr->ts_state.output_buffer_ts = in_port_ptr->ts_state.input_buffer_ts;
            out_port_ptr->ts_state.ts_valid = in_port_ptr->ts_state.is_asynchronous_mode?FALSE:TRUE;
         }
      }
      //Case 3: Start time was in the past
      else
      {
         //sync input TS to output even for drop
         out_port_ptr->ts_state.output_buffer_ts = in_port_ptr->ts_state.input_buffer_ts;
         out_port_ptr->ts_state.ts_valid = in_port_ptr->ts_state.is_asynchronous_mode?FALSE:TRUE;

         //start time was effectively in the past, drop required frames(equivalent to marking the intermediate buffer as consumed)
         //this may happen a few more times before, finally moving to delta = 0 state.
         //however, with invalid TS we will never reach delta = 0. therefore move to run immediately.
         out_port_ptr->intermediate_buff.is_updated = FALSE;

         if (in_port_ptr->ts_state.is_asynchronous_mode)
         {
            in_port_ptr->stream_state = RUN;
         }

         MSG_1(MSG_SSID_QDSP6, DBG_HIGH_PRIO, " dropping data as effective start time was in the past.Downstream delay=%lu",(uint32_t)downstream_delay);

         //check if we have data in input buffer. If we have then go process input data & then come to fill output buf.
         //If again, delta is nonzero, then we will drop that data.
         //this process can be done for invalid TS as well.
         if(ADSP_FAILED(nResult = qurt_elite_channel_poll(
               qurt_elite_queue_get_channel(in_port_ptr->service_handle.dataQ),
               stream_router_svc_input_port_to_signal_mask(input_port_id))))
         {
            //if not,introduce pause burst

            in_port_ptr->is_first_buffer_received = FALSE;

            stream_router_svc_fill_pause_burst(pMe, out_buf_ptr, out_port_ptr->pause_buffer_duration, input_port_id, output_port_id);
            buf_size = out_buf_ptr->nActualSize;
         }
         else
         {
            out_buf_filled = FALSE;
         }

         //listen for an input buffer
         pMe->current_bitfield |= stream_router_svc_input_port_to_signal_mask(input_port_id);

      }
   }

   if (out_buf_filled)
   {
      //convert buffer node to elite msg
      elite_msg_any_t *msg_to_peer_ptr = elite_msg_convt_buf_node_to_msg(
            output_buffer_node,
            ELITE_DATA_BUFFER,
            NULL, /* do not need response */
            pMe->service_handle.unSvcId,/* token */
            0);  /* do not care response result*/

      //now push this into downstream service input data queue
      nResult= qurt_elite_queue_push_back(out_port_ptr->downstream_svc_handle->dataQ, (uint64_t*)msg_to_peer_ptr);
      if(ADSP_FAILED(nResult))
      {
         MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failed to deliver buffer dowstream");
         (void) elite_msg_push_payload_to_returnq(out_port_ptr->service_handle.gpQ, (elite_msg_any_payload_t*)(output_buffer_node->pBuffer));
      }
   }
   else
   {
      nResult= qurt_elite_queue_push_back(out_port_ptr->service_handle.gpQ, (uint64_t*)output_buffer_node);
      if(ADSP_FAILED(nResult))
      {
         MSG(MSG_SSID_QDSP6, DBG_ERROR_PRIO, "Failed to push back to the queue.");
         (void) elite_msg_push_payload_to_returnq(out_port_ptr->service_handle.gpQ, (elite_msg_any_payload_t*)(output_buffer_node->pBuffer));
      }
   }

   //Add the duration of this buffer to the accumulated duration
   out_port_ptr->downstream_buffer_duration += stream_router_svc_buffer_size_to_duration(
         in_port_ptr, buf_size, out_port_ptr->sampling_rate, out_port_ptr->num_channels,out_port_ptr->bits_per_sample);

   return ADSP_EOK;
}
