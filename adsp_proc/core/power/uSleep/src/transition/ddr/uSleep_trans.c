/*==============================================================================
  FILE:         uSleep_trans.c

  OVERVIEW:     This file provides uSleep transition functions that are located
                in DDR memory space

  DEPENDENCIES: None
  
                Copyright (c) 2014-2017 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.qdsp6/1.0.c2/power/uSleep/src/transition/ddr/uSleep_trans.c#1 $
$DateTime: 2020/02/10 01:57:30 $
==============================================================================*/
#include <stdlib.h>
#include "comdef.h"
#include "CoreVerify.h"
#include "CoreTime.h"
#include "uSleepi.h"
#include "uSleep_util.h"
#include "uSleep_ddr_log.h"
#include "uSleep_timer.h"
#include "uSleep_node.h"
#include "uSleep_os.h"
#include "sleep_os.h"
#include "sleep_pmi.h"
#include "rpmclient.h"
#include "qurt.h"
#include "uSleep_target.h"
#include "sleep_synth.h"
#include "sleepActive.h"
#include "island_mgr.h"

/*==============================================================================
                            EXTERNAL VARIABLES
 =============================================================================*/
extern uSleep_callback_data g_uSleepCallbacks;
extern qurt_mutex_t         g_uSleepStateMutex;
extern uSleep_global_data   g_uSleepData;
extern qurt_signal_t        g_uSleepExitSignal;
extern qurt_signal_t        g_uSleepEnterSignal;

/*==============================================================================
                            FORWARD DECLARATIONS
 =============================================================================*/
void uSleep_transitionInitialize(void);

/*==============================================================================
                       INTERNAL FUNCTION DEFINITIONS
 =============================================================================*/
/** 
 * uSleepTrans_updateLPILatency
 * 
 * @brief Updates the LPI latency data in the main sleep solver
 *  
 * @param enterAdjust:  Amount to adjust the enter latency of the LPI 
 * @param exitAdjust:   Amount to adjust the exit latency of the LPI 
 */
static void uSleepTrans_updateLPILatency(int32 enterAdjust, int32 exitAdjust)
{
  synthLPI_updateLatency(enterAdjust, exitAdjust);
  return;
}

/**
 * uSleepTrans_resetTimes
 * 
 * @brief Resets transition statistic values
 * 
 * @param transPtr: Pointer to transition data 
 */
static void uSleepTrans_resetTimes(uSleep_transition_profiling *transPtr) 
{
  memset(&transPtr->entry_stats, 0, sizeof(sleepStats_generic));
  memset(&transPtr->exit_stats, 0, sizeof(sleepStats_generic));
  
  transPtr->entry_stats.min  = UINT64_MAX;
  transPtr->exit_stats.min   = UINT64_MAX;

  return;
}

/**
 * uSleepTrans_programDDRWakeupTimeInternal
 * 
 * @brief Creates a uTimer based on the previously set value.  The timer is used to exit 
 *        island mode in order to service the normal mode timer.  
 */
static void uSleepTrans_programDDRWakeupTimeInternal(void)
{
  uint64 wakeup = uSleep_getDDRWakeupTimeInternal();

  uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, (1 * 2)+1,
                      "Set DDR exit timer (Value: 0x%llx), island exit latency (Value: 0x%x )",
                      ULOG64_DATA(wakeup), g_uSleepData.transition_data.exit_latency);
  
  uSleepTimer_setValue(wakeup);
  return;
}

/**
 * uSleepTrans_initTransitionSignals 
 *  
 * @brief Initializes the transition signals. This should be performed once 
 *        at system init time.  
 */
static void uSleepTrans_initTransitionSignals(void)
{
  /* Init internal signals */
  qurt_signal_init(&g_uSleepExitSignal);
  qurt_signal_init(&g_uSleepEnterSignal);

  return;
}

/*==============================================================================
                       EXTERNAL FUNCTION DEFINITIONS
 =============================================================================*/
/*
 * uSleepTrans_setDDRWakeupTimeInternal
 */
void uSleepTrans_setDDRWakeupTimeInternal(uint64 wakeupTimer)
{
  /* Backoff the normal operational deadline by the time it takes to exit
   * uSleep */
  g_uSleepData.ddr_wakeup_timer = 
    wakeupTimer - g_uSleepData.transition_data.exit_latency;

  /* Create a uTimer based on the normal mode timer to trigger exit */
  uSleepTrans_programDDRWakeupTimeInternal();

  return;
}

/*
 * uSleepTrans_completeTransitionToNormalMode
 */
void uSleepTrans_completeTransitionToNormalMode(void)
{
  uSleep_transition_profiling *transProfileData = uSleep_getProfilingDataPtr();

  /* Set sleep function pointer to main uSleep perform function so we may  
   * re-enter island mode */
  uSleepOS_setIdleFunctionPtr(uSleepOS_mainEntry);

  /* Set PMI handler back to main image handler */
  sleepPMI_setHandlerFunctionPTR(sleepOS_PMIPerformer);
  
  /* Call notification CB's when DDR is accessable, but still have global interrupts
   * disabled to ensure all callbacks complete before processing any normal mode interrupt */
  uSleepTrans_transitionNotify(USLEEP_STATE_EXIT);

  /* Perform any final cleanup of the exit which must be done while we are still in
   * interrupt lock context, sleep thread will sill be at highest priority until
   * kernel exit is completed below */
  uSleepOS_cleanupIslandExit();

  /* Indicate we have fully exited uSleep and are back in normal operational mode */
  uSleep_setStateInternal(uSLEEP_INTERNAL_STATE_IN_DDR);
  
  /* Check new hard deadlines on island exit since an island timer could have expired */
  sleepActive_SetSignal(SLEEP_SIGNAL_ISLAND_HARD_DURATION);  
  
  /* Someone requested an exit, unblock their exit call now that exit is complete */
  uSleepTrans_exitSignalControl(USLEEP_TRANS_SIGNAL_SET);
  
  uSleepDDRLog_QDSSPrintf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 
                          USLEEP_EXIT_NUM_ARGS,
                          USLEEP_EXIT_STR,
                          USLEEP_EXIT);

  /* Record the exit transition time */
  sleepStats_updateValue(&transProfileData->exit_stats,
                         CoreTimetick_Get64() - transProfileData->exit_start_time); 

  /* Complete island exit which will reset the sleep thread priority and unlock
   * interrupts (which was already done above, but has no effect to do it again) */
  CORE_LOG_VERIFY(QURT_EOK == island_mgr_island_exit(QURT_ISLAND_EXIT_STAGE2),
                  uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 0,
                                      "Kernel stage 2 exit failure"));

  uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 0, "Kernel stage 2 exit completed");

  /* Reseet CLK_ENABLE bit of Q6 Axi clock */
  uSleepOS_Set_Q6AxiClockConfiguration( CLK_DISABLE );

  return;
}

/*
 * uSleepTrans_transitionNotify
 */
void uSleepTrans_transitionNotify(uSleep_state_notification state)
{
  uSleep_callback_list      *guestFunction;
  uSleep_user_callback_list *userFunction;

  /* Notify registered client callback functions of uImage transition */
  guestFunction = g_uSleepCallbacks.callback_list;
  userFunction  = g_uSleepCallbacks.user_callback_list;

  uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 1,
                      "Transition notification (State: %s)",
                      USLEEP_STATE_ENTER == state ? "Entry" : "Exit");

  /* Call guest OS notification functions */
  while(NULL != guestFunction)
  {
    uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 1,
                       " Calling (FCN ptr: 0x%x)",
                       (uint32)guestFunction->callback);

    guestFunction->callback(state);
    guestFunction = guestFunction->next;
  }

  /* Call user OS notification functions. This will actually signal
   * a thread to run in user space and wait for it to finish calling all user
   * CB's for that particular PD */
  while(NULL != userFunction)
  {
    uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 0, " Calling User CB's");

    userFunction->callback(state, userFunction->signals);
    userFunction = userFunction->next;
  }

  uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 0,
                      "Notification complete");

  return;
}

/* 
 * uSleepTrans_updateTimes
 */ 
void uSleepTrans_updateTimes(void)
{
  uSleep_transition_profiling *transPtr = uSleep_getProfilingDataPtr();

  if(transPtr->adjust_count < 8)
  {
    /* Initialize data values */
    uSleepTrans_resetTimes(transPtr);

    /* Set initial adjustment match value */
    transPtr->adjust_count = 8;
  }
  else if(transPtr->entry_stats.count >= transPtr->adjust_count)
  {
    int64 enterAvg;
    int64 exitAvg;
    uint64 enterTotal = transPtr->entry_stats.total;
    uint64 exitTotal  = transPtr->exit_stats.total;

    /* Remove the best and worst cases */
    enterTotal -= (transPtr->entry_stats.min + transPtr->entry_stats.max);
    exitTotal  -= (transPtr->exit_stats.min + transPtr->exit_stats.max);
    
    /* Compute average transition enter and exit latency */
    enterAvg  = (int64)(enterTotal / (transPtr->entry_stats.count - 2));
    exitAvg   = (int64)(exitTotal / (transPtr->exit_stats.count - 2));

    /* Update transition times */
    uSleepTrans_adjustLatency((int32)(enterAvg - transPtr->entry_latency), 
                              (int32)(exitAvg - transPtr->exit_latency));

    /* Reset the data for the next adjustment, but keep current min/max */
    transPtr->entry_stats.count = 0;
    transPtr->entry_stats.total = 0;
    transPtr->exit_stats.count = 0;
    transPtr->exit_stats.total = 0;

    /* Set next adjustment */
    if(transPtr->adjust_count < 0x000000400)
    {
      transPtr->adjust_count = transPtr->adjust_count << 2;
    }
  }

  return;
}

/*
 * uSleepTrans_initLatency
 */
void uSleepTrans_initLatency(void)
{
  uint32                      enterLat;
  uint32                      exitLat;
  uSleep_transition_profiling *dataPtr = uSleep_getProfilingDataPtr();

  synthLPI_getCurrentLatency(&enterLat, &exitLat, 0);

  /* Set initial internal latency ticks */
  dataPtr->entry_latency  = enterLat;
  dataPtr->exit_latency   = exitLat;

  return;
}

/*
 * uSleepTrans_adjustLatency
 */
void uSleepTrans_adjustLatency(int32 entryAdjust, int32 exitAdjust)
{
  int64 entryLat;
  int64 exitLat;

  uSleep_transition_profiling *dataPtr = uSleep_getProfilingDataPtr();
  
  uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 4,
                      "Transition latency update request "
                      "(Current enter: %u) "
                      "(enter adjust: %d) "
                      "(Current exit: %u) "
                      "(exit adjust: %d)",
                      dataPtr->entry_latency,
                      entryAdjust,
                      dataPtr->exit_latency,
                      exitAdjust);
  
  if(entryAdjust || exitAdjust)
  {
    if(exitAdjust < 0)
    {
      /* If reducing latency, adjust by smaller amount because we always need to assume 
       * worst case but still want to move it down eventually if that is really where 
       * it is observed to be */ 
      exitAdjust /= 64;

      uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 1,
                          " Large exit adjustment - reducing (new: %d)",
                          exitAdjust);

      /* Reset adjustment counter to something reasonable if the count is high */
      if(dataPtr->adjust_count > (8 << 4))
      {
        dataPtr->adjust_count = (8 << 4);
      }
    }

    if(entryAdjust < 0)
    {
      entryAdjust /= 64;

      uSleepDDRLog_printf(USLEEP_DDR_LOG_LEVEL_TRANSITION, 1,
                          " Large entry adjustment - reducing (new: %d)",
                          entryAdjust);

      if(dataPtr->adjust_count > (8 << 4))
      {
        dataPtr->adjust_count = (8 << 4);
      }
    }

    /* Adjust the LUT entry which expects a difference */
    uSleepTrans_updateLPILatency(entryAdjust, exitAdjust);

    /* Set new internal latency ticks */
    entryLat  = dataPtr->entry_latency + entryAdjust;
    exitLat   = dataPtr->exit_latency + exitAdjust;

    CORE_VERIFY((entryLat > 0) && (entryLat < UINT32_MAX));
    CORE_VERIFY((exitLat > 0) && (exitLat < UINT32_MAX));

    dataPtr->entry_latency  = (uint32)entryLat;
    dataPtr->exit_latency   = (uint32)exitLat;
  }

  return;
}

/*
 * uSleepTrans_initialize
 */
void uSleepTrans_initialize(void)
{
  /* Initializing the mutex for uSleep resource request */
  qurt_mutex_init(&g_uSleepStateMutex);

  /* Init the signals to coordinate the transition */
  uSleepTrans_initTransitionSignals();

  /* Initialize target specific transition */
  uSleep_transitionInitialize();

  return;
}

