/*============================================================================

  @file sns_pm_uimg.c

  @brief
  This file contains the implementation of the Sensors Power Manager
  operational in micro image

  Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

============================================================================*/

/*============================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

when         who     what, where, why
----------   ---     --------------------------------------------------------- 
03-27-2017   sd      Include uSleep_mode_trans.h for 8998
11-03-2016   rt      Added exponential backoff to AP resume hysteresis timer
02-11-2016   jtl     notify clients when AP enters sleep, even if done already
09-16-2015   rt      Added back uImage entry hysteresis timer
09-10-2015   hw      Add uimg exit callback function mechanism 
09-04-2015   rt      Remove/Restore MaxDuration on Island Entry/Exit
08-18-2015   rt      Removed uImage entry hysteresis timer
05-04-2015   hw      Remove SMSM
03-19-2015   hw      Replace SMSM with SMP2P
01-28-2015   agk     Release MIPS and BW vote if NO_CLIENT
11-11-2014   jhh     Restore DDR AB upon exiting uImage
11-03-2014    sc     Assert on uSleep_exit() failure
10-10-2014   agk     Release/restore DDR BW when entering/exiting uImage
10-06-2014   jhh     Add QDSS events for img mode change and spare
09-10-2014   jhh     Add MACRO for excluding power feature
08-26-2014   jhh     Added hysteresis timer for entering micro image
08-22-2014   jhh     Split functions for micro image

============================================================================*/

/*=====================================================================
                               INCLUDES
=======================================================================*/
#include <stdbool.h>
#include "sns_memmgr.h"
#include "sns_init.h"
#include "sns_common.h"
#include "sns_pm.h"
#include "sns_pm_priv.h"
#include "sns_debug_str.h"

#include "npa.h"

#include "uSleep.h"
#if defined(SLEEP_HEADER_8998)
#include "uSleep_mode_trans.h"
#endif
#include "sns_em.h"
#include "sns_profiling.h"

/*======================================================================
                     INTERNAL DEFINITIONS AND TYPES
========================================================================*/

/* Below are used to set clint_vote_status for micro image log packet */
#define  NUM_PM_DECISION_BITS 4
#define  NUM_STATUS_BITS_PER_CLIENT 4
#define  BIT_TO_CLEAR_CLIENT_STATUS 15

#ifdef SNS_USES_ISLAND
uint8_t sns_pm_uimg_enabled = 1; // Disable uimage entry/exit, 1-enable.
#else
uint8_t sns_pm_uimg_enabled = 0;
#endif /* SNS_USES_ISLAND */

sns_pm_internal_s sns_pm;
uSleep_notification_cb_handle uSleep_handle;

bool sns_pm_initialized = false;
bool sns_pm_uimg_enter_hysteresis_started = false;
sns_em_timer_obj_t uimg_enter_tmr_obj;


/*======================================================================
                            GLOBAL VARIABLES
========================================================================*/
/* SPARE variables */
/* Resume time hysteresis to prevent rapid suspend/resume due to high frequency data. */
//#define  RESUME_HYSTERESIS_TICKS   (uint32_t)(200000/30.51)  /* 200 mill sec resume delay */

bool linux_kernel_suspend = false;
volatile bool timer_valid = false;
uint32_t current_resume_hysteresis_ticks = 0; 
/*======================================================================
                               FUNCTIONS
========================================================================*/

#ifndef SNS_PM_EXCLUDE_POWER
/*===========================================================================

FUNCTION sns_pm_set_latency

DESCRIPTION
  This function sets latency restriction provided by clients to sleep
  driver's latency node. Clients must use this function to provide their
  latency requirements. This function should be thread safe.
  pm_latency_mutex_ptr shall be used to protect critical sections in
  this function.

===========================================================================*/
sns_pm_err_code_e sns_pm_set_latency( sns_pm_handle_t client_handle,
                                      uint32 latency_us )
{

  int i;
  uint8_t os_err;
  sns_os_mutex_pend(sns_pm.pm_mutex_ptr, 0, &os_err);

  sns_pm_client_info_s *client_info = (sns_pm_client_info_s *)client_handle;
  client_info->max_tolerable_delay = latency_us;

  /* re-calculate the max_tolerable_delay from all clients */
  sns_pm.status.max_tolerable_delay = MAX_TOLERABLE_LATENCY;
  for(i = 0; i < sns_pm.status.num_clients; i++)
  {
    if(sns_pm.status.client_handle[i] != NULL)
    {
      uint32 max_delay = sns_pm.status.client_handle[i]->max_tolerable_delay;
      if(sns_pm.status.max_tolerable_delay > max_delay)
      {
        sns_pm.status.max_tolerable_delay = max_delay;
      }
    }
  }

  //PM_MSG_2(LOW, "Set Latency : voted latency[%d], total latency[%d]", latency_us, sns_pm.status.max_tolerable_delay);
  /* Latency requirement of 0 is to remove the latency requirement */
  if ( sns_pm.status.max_tolerable_delay == 0 )
  {
    npa_complete_request(sns_pm.core_handle.req_sync_latency_client);
  }
  else
  {
    npa_issue_required_request(sns_pm.core_handle.req_sync_latency_client, sns_pm.status.max_tolerable_delay);
  }

  sns_os_mutex_post(sns_pm.pm_mutex_ptr);

  return SNS_PM_SUCCESS;
}
/*===========================================================================

FUNCTION sns_pm_vote_img_mode

DESCRIPTION
  Updates the vote status information

===========================================================================*/
void sns_pm_update_vote_status(sns_pm_img_mode_e mode)
{
  if(mode != SNS_IMG_MODE_MICRO && mode != SNS_IMG_MODE_BIG)
  {
    return;
  }

  sns_pm.status.current_vote         = mode;
  sns_pm.status.state_vote_timestamp = sns_em_get_timestamp();
  sns_pm.status.client_vote_status &= ~BIT_TO_CLEAR_CLIENT_STATUS;
  sns_pm.status.client_vote_status |= 1 << (mode -1);
}

/*===========================================================================

FUNCTION sns_pm_clear_state_stats

DESCRIPTION
  Clears statistics for state

===========================================================================*/
void sns_pm_clear_state_stats(void)
{
  sns_pm.status.num_exits_from_uimg = 0;
  sns_pm.status.time_spent_in_uimg = 0;
  sns_pm.status.last_uimg_entry_ts = 0;
  sns_pm.status.first_uimg_entry_ts = 0;
  sns_pm.status.bigImage_entry_ts = 0;
}

/*===========================================================================

FUNCTION sns_pm_uimg_exit_alert

DESCRIPTION
  Alerts registered clients that system has exited uImage mode

===========================================================================*/
static void sns_pm_uimg_exit_alert(void)
{
  uint8_t i;
  for (i= 0; i<ARR_SIZE(sns_pm.status.client_handle); i++)
  {
    if ( sns_pm.status.client_handle[i] != NULL &&
         sns_pm.status.client_handle[i]->uimg_exit_cb != NULL )
    {
      sns_pm.status.client_handle[i]->uimg_exit_cb();
}
  }
}

/*===========================================================================

FUNCTION sns_pm_vote_img_mode

DESCRIPTION
  This function votes for image modes (uImage or Big image) based on
  client input. Vote to uImage will be done through NPA node (/core/usleep).
  Vote to big image will be done through a function call to uSleep.The
  function is asymmetric. It is synchronous when entering big image mode
  whereas it is asynchronous when entering uImage mode. If the request is
  to enter uImage mode, there shall be a callback later on when system
  really enters uImage mode.
  Clients are not expected to wait for the callback when entering uImage
  mode. Clients are expected to continue to operate in uImage mode when
  this function returns.

===========================================================================*/
sns_pm_err_code_e sns_pm_vote_img_mode( sns_pm_handle_t client_handle,
                                       sns_pm_img_mode_e mode )
{

  uint8_t os_err;
  int client_index;

  sns_os_mutex_pend(sns_pm.pm_mutex_ptr, 0, &os_err);

  sns_pm_client_info_s *client_info;
  client_info = (sns_pm_client_info_s *)client_handle;

  /* If client voted for the same mode, ignore */
  if(client_info->current_vote == mode)
  {
    sns_os_mutex_post(sns_pm.pm_mutex_ptr);
    return SNS_PM_SUCCESS;
  }

  sns_profiling_log_qdss(SNS_PM_CLIENT_VOTE, 2, client_info->client_id, mode);
  //PM_MSG_3(LOW, "uImage vote :: Client %d ==> mode %d, current: %x", client_info->client_id,
  //  mode, sns_pm.status.client_vote_status);

  /* Update clinet info */
  client_info->current_vote = mode;

  /* Find client index */
  client_index = sns_pm_find_client_index(client_handle);
  if(client_index == -1)
  {
    sns_os_mutex_post(sns_pm.pm_mutex_ptr);
    return SNS_PM_ERR_FAILED;

  }

  if(mode != SNS_IMG_MODE_UNKNOWN)
  {
    int temp = 0;
    /* Update the client_vote_status
       Each client is given NUM_STATUS_BITS_PER_CLIENT bits to represent vote status,
       Last NUM_PM_DECISION_BITS is reserved for sns_pm overall decision,
       thus shift by NUM_STATUS_BITS_PER_CLIENT * index + NUM_PM_DECISION_BITS */
    sns_pm.status.client_vote_status &= ~(BIT_TO_CLEAR_CLIENT_STATUS << (NUM_STATUS_BITS_PER_CLIENT * client_index + NUM_PM_DECISION_BITS));
    temp = 1 << (mode-1);
    sns_pm.status.client_vote_status |= (temp << (NUM_STATUS_BITS_PER_CLIENT * client_index + NUM_PM_DECISION_BITS));
  }

  if(mode == SNS_IMG_MODE_MICRO)
  {
    int i;
    /* Search if any of the clients voted for Big Image Mode */
    for(i = 0; i < sns_pm.status.num_clients; i++)
    {
      if(sns_pm.status.client_handle[i] != NULL
         && sns_pm.status.client_handle[i]->current_vote == SNS_IMG_MODE_BIG)
      {
        break;
      }
    }

    /* All votes are SNS_IMG_MODE_MICRO. Switch to Micro Image Mode */
    if(i == sns_pm.status.num_clients && sns_pm.status.current_mode != SNS_IMG_MODE_MICRO)
    {
      //PM_MSG_0(MED, "Vote Image Mode : switch to Micro Image");
      if(sns_pm_uimg_enabled && sns_pm_uimg_enter_hysteresis_started == false &&
         sns_pm.status.current_vote != SNS_IMG_MODE_MICRO)
      {
        sns_pm_update_vote_status(SNS_IMG_MODE_MICRO);
        sns_pm.status.last_uimg_vote_ts = sns_pm.status.state_vote_timestamp;
        if(sns_pm.status.current_mode != SNS_IMG_MODE_MICRO)
      {
        sns_pm_log_uimg_mode();
        }
        sns_pm_clear_state_stats();
        sns_em_register_timer(uimg_enter_tmr_obj, UIMG_ENTER_HYSTERESIS_TICKS);
        sns_pm_uimg_enter_hysteresis_started = true;
      }
    }
  }
  else if(mode == SNS_IMG_MODE_NOCLIENT)
  {
    int i;
    int client_exist = 0;
    int big_image_client_exist = 0;

    /* Search if all of the client voted for No Client Mode */
    for(i = 0; i < sns_pm.status.num_clients; i++)
    {
      if(sns_pm.status.client_handle[i] != NULL
         && sns_pm.status.client_handle[i]->current_vote != SNS_IMG_MODE_NOCLIENT
         && sns_pm.status.client_handle[i]->current_vote != SNS_IMG_MODE_UNKNOWN)
      {
        client_exist = 1;
        if(sns_pm.status.client_handle[i]->current_vote == SNS_IMG_MODE_BIG)
        {
          big_image_client_exist = 1;
        }
      }
    }

    if(!big_image_client_exist)
    {
      /* no big image client, but there's micro image client. vote for micro image */
      if(client_exist && sns_pm.status.current_vote != SNS_IMG_MODE_MICRO)
      {
        if(sns_pm_uimg_enabled && sns_pm_uimg_enter_hysteresis_started == false
           && sns_pm.status.current_mode != SNS_IMG_MODE_MICRO)
        {
          sns_pm_update_vote_status(SNS_IMG_MODE_MICRO);
          sns_pm.status.last_uimg_vote_ts = sns_pm.status.state_vote_timestamp;
          if(sns_pm.status.current_mode != SNS_IMG_MODE_MICRO)
          {
            sns_pm_log_uimg_mode();
          }
          sns_pm_clear_state_stats();
          sns_em_register_timer(uimg_enter_tmr_obj, UIMG_ENTER_HYSTERESIS_TICKS);
          sns_pm_uimg_enter_hysteresis_started = true;
        }
      }
      /* no big image client and no other client exist, vote for big image */
      else
      {
          if (sns_pm_uimg_enabled && sns_pm.status.current_vote != SNS_IMG_MODE_BIG)
          {
              SNS_ASSERT(uSleep_exit() == USLEEP_SUCCESS);
              sns_pm_update_vote_status(SNS_IMG_MODE_BIG);
              sns_pm.status.bigImage_entry_ts = sns_em_get_timestamp();
              sns_em_cancel_timer(uimg_enter_tmr_obj);
              sns_pm_uimg_enter_hysteresis_started = false;
              npa_issue_required_request(sns_pm.core_handle.req_usleep_client, 0);

              sns_pm_log_uimg_mode();
              sns_pm_clear_state_stats();
              sns_profiling_log_qdss(SNS_PM_VOTE_IMG_MODE, 1, SNS_IMG_MODE_BIG);
              sns_pm_uimg_exit_alert();
          }

          /* Release MIPS vote */
          /* Not setting sns_pm.status.total_mcps to 0 as it reflects client votes
             and may cause discrepancy since clients have not really voted for 0 */
          sns_pm_internal_vote_mcps(0);
          /* Restore DDR BW to minimum */
          sns_pm_internal_vote_ddr_bw(0, 100);
          
        sns_pm.status.current_mode = SNS_IMG_MODE_NOCLIENT;
        /* Remove Max duration requirement when no client exists */
        sns_pm_set_wakeup_interval(client_handle, 0);
      }
    }
    client_info->max_tolerable_delay = MAX_TOLERABLE_LATENCY;
  }
  else if(mode == SNS_IMG_MODE_BIG)
  {
    /* Immediately switch to Big Image Mode */
    if(sns_pm_uimg_enabled && sns_pm.status.current_vote != SNS_IMG_MODE_BIG)
    {
      SNS_ASSERT( uSleep_exit() == USLEEP_SUCCESS );
      sns_pm_update_vote_status(SNS_IMG_MODE_BIG);
      sns_pm.status.bigImage_entry_ts = sns_em_get_timestamp();
      sns_em_cancel_timer(uimg_enter_tmr_obj);
      sns_pm_uimg_enter_hysteresis_started = false;
      npa_issue_required_request(sns_pm.core_handle.req_usleep_client, 0);

      /* Restore DDR BW */
      sns_pm_internal_vote_ddr_bw(sns_pm.status.total_bw, 100);

      sns_pm_log_uimg_mode();
      sns_pm_clear_state_stats();
      sns_profiling_log_qdss(SNS_PM_VOTE_IMG_MODE, 1, SNS_IMG_MODE_BIG);
      sns_pm_uimg_exit_alert();
    }

    sns_pm.status.current_mode = SNS_IMG_MODE_BIG;
    /* Restore Max Sleep duration on island exit */
    sns_pm_set_wakeup_interval(client_handle, sns_pm.status.wakeup_interval);
  }
  else
  {
    sns_os_mutex_post(sns_pm.pm_mutex_ptr);
    return SNS_PM_ERR_NOT_SUPPORTED;
  }

  sns_os_mutex_post(sns_pm.pm_mutex_ptr);

  return SNS_PM_SUCCESS;
}

int sns_pm_find_client_index( sns_pm_handle_t client_handle )
{
  int i;
  for(i = 0; i < sns_pm.status.num_clients; i++)
  {
    if(sns_pm.status.client_handle[i] == client_handle)
    {
      return i;
    }
  }

  return -1;
}

/*===========================================================================

FUNCTION sns_pm_notify_smp2p_client

DESCRIPTION
  Broadcast the linux_kernel_suspend to any clients willing to get notified
  when there's change.

===========================================================================*/
void sns_pm_notify_smp2p_client(bool suspend)
{
  int i;
  sns_profiling_log_qdss(SNS_PM_SPARE_BROADCAST, 1, suspend);
  for(i = 0; i < sns_pm.status.num_clients; i++)
  {
    if(sns_pm.status.client_handle[i] != NULL &&
       sns_pm.status.client_handle[i]->callback != NULL)
    {
      (sns_pm.status.client_handle[i]->callback)(suspend);
    }
  }
}

/*===========================================================================

FUNCTION sns_pm_resume_timer_cb

DESCRIPTION
  Callback that gets called after resume time hysteresis

===========================================================================*/
void sns_pm_resume_timer_cb(void *arg)
{
  if(timer_valid)
  {
    sns_pm_ap_wakeup_broadcast();
  }
  else
  {
    /* If the timer is invalid, the AP will remain in suspend,
       hence reset the hysteresis to the default value */
    current_resume_hysteresis_ticks = DEFAULT_RESUME_HYSTERESIS_TICKS;
  }
}

/*===========================================================================

FUNCTION sns_pm_apps_wakeup_broadcast

DESCRIPTION
  function gets called to broadcast apps suspend->wakeup transition to all
  clients

===========================================================================*/
void sns_pm_ap_wakeup_broadcast(void)
{
  uint8_t os_err;
  sns_os_mutex_pend(sns_pm.pm_suspend_resume_mutex_ptr, 0, &os_err );
  SNS_ASSERT ( os_err == OS_ERR_NONE );

  if(linux_kernel_suspend)
  {
    linux_kernel_suspend = false;
    sns_pm_notify_smp2p_client(linux_kernel_suspend);
  }
  
  os_err = sns_os_mutex_post(sns_pm.pm_suspend_resume_mutex_ptr );
  SNS_ASSERT ( os_err == OS_ERR_NONE );
}

#else
sns_pm_err_code_e sns_pm_set_latency( sns_pm_handle_t client_handle,
                                      uint32 latency_us )
{
  return SNS_PM_SUCCESS;
}

sns_pm_err_code_e sns_pm_vote_img_mode( sns_pm_handle_t client_handle,
                                        sns_pm_img_mode_e mode)
{
  return SNS_PM_SUCCESS;
}
#endif /* SNS_PM_EXCLUDE_POWER */
