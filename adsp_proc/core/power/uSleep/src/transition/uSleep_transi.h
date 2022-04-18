#ifndef USLEEP_TRANSI_H
#define USLEEP_TRANSI_H
/*==============================================================================
  FILE:         uSleep_transi.h

  OVERVIEW:     Internal types & prototypes for transition uSleep functions

  DEPENDENCIES: None
  
                Copyright (c) 2014-2016 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.qdsp6/1.0.c2/power/uSleep/src/transition/uSleep_transi.h#1 $
$DateTime: 2020/02/10 01:57:30 $
==============================================================================*/
#include "comdef.h"
#include "uSleep_mode_trans.h"
#include "sleep_stats_global.h"
#include "qurt.h"
#include "npa.h"

/*==============================================================================
                            DEFINITIONS & TYPES
 =============================================================================*/
/* NPA client type that prevents uSleep entry based on latency and other
 * internal restrictions */
#define USLEEP_CLIENT_NODE_CORE_DRIVERS   NPA_CLIENT_CUSTOM1  /* For internal core driver client node */

/* Enum to indicate which RPM data set(s) to send and how to wait for the response */
typedef enum uSleep_transition_mode_s
{
  UIMAGE_ENTER  = 0,  /* Performs island entry steps */
  UIMAGE_EXIT,        /* Performs island exit steps */ 
  UIMAGE_EXIT_FAST    /* Performs island exit steps required in fatal error cases */
}uSleep_transition_mode;

/* Signal controls for the transition wait stages */
typedef enum uSleep_trans_signal_control_s
{
  USLEEP_TRANS_SIGNAL_CLEAR = 0,  /* Clears the signal */
  USLEEP_TRANS_SIGNAL_SET,        /* Sets the signal */
  USLEEP_TRANS_SIGNAL_WAIT        /* Waits for signal to set */
}uSleep_trans_signal_control;

/** 
 * uSleep_transition_profiling
 * 
 * @brief Data structure for tracking the mode transition times
 */
typedef struct uSleep_transition_profiling_s
{
  /* Timestamp of last uSleep entry point */
  uint64 entry_start_time;

  /* Timestamp of last uSleep exit point */
  uint64 exit_start_time;

  /* Current value of the time to enter uSleep */
  uint32 entry_latency;

  /* Current value of the time to exit uSleep */
  uint32 exit_latency;

  /* Statistics for transition times */
  sleepStats_generic  entry_stats;
  sleepStats_generic  exit_stats;

  /* Total entries into island mode */
  uint32 total_entries;

  /* Adjustement match value */
  uint32 adjust_count;
}uSleep_transition_profiling;

/*==============================================================================
                        NORMAL MODE FUNCTION DECLARATIONS
 =============================================================================*/
/**
 * uSleepTrans_completeTransitionToNormalMode
 * 
 * @brief Completes the island mode exit process.
 */
void uSleepTrans_completeTransitionToNormalMode(void);

/**
 * uSleepTrans_initialize
 *
 * @brief Intializes some of the internal objects which are used to interact
 *        with surrounding systems especially Sleep.
 *  
 * @Note This assumes that the CXO vote has been setup via normal sleep code 
 *       initilization and will never be removed from the active/sleep sets. 
 */
void uSleepTrans_initialize(void);

/*==============================================================================
                        ISLAND FUNCTION DECLARATIONS
 =============================================================================*/
/**
 * uSleepTrans_islandControl
 * 
 * @brief Enters or exits island mode
 * 
 * @param mode: Enum to perform entry or exit transition actions
 */
void uSleepTrans_islandControl(uSleep_transition_mode mode);

/** 
 * uSleepTrans_performIslandModeTransition
 * 
 * @brief Main uSleep function that enters any low power modes while 
 *        waiting for the island entry transition to complete 
 */
uint32 uSleepTrans_performIslandModeTransition(void);

/** 
 * uSleepTrans_updateTimes 
 *  
 * @brief If necessary, will update the transition latency values to enter and 
 *        exit uSleep.
 *  
 * @note This must be called in normal operational mode. 
 */ 
void uSleepTrans_updateTimes(void);

/** 
 * uSleepTrans_transitionNotify
 * 
 * @brief Notifies registered clients of a normal operational <-> island 
 *        transition.
 *  
 * @param state:  Enum of entry or exit transition 
 */
void uSleepTrans_transitionNotify(uSleep_state_notification state);

/**
 * uSleepTrans_adjustLatency
 * 
 * @brief Sets the island entry & exit transition latency 
 *  
 * @param entryAdjust: Latency adjustment in ticks to make to the entry transition
 * @param exitAdjust:  Latency adjustment in ticks to make to the exit transition
 */
void uSleepTrans_adjustLatency(int32 entryAdjust, int32 exitAdjust);

/**
 * uSleepTrans_initLatency
 * 
 * @brief Initilizes the initial latency values for the LPI
 */
void uSleepTrans_initLatency(void);

/**
 * uSleepTrans_exitSignalControl
 * 
 * @brief Performs a clear/set/wait action on the uSleep exit signal to 
 *        coordinate internal tasks during the exit process.
 *  
 * @param control: Action to perform 
 */
void uSleepTrans_exitSignalControl(uSleep_trans_signal_control control);

/**
 * uSleepTrans_enterSignalControl
 * 
 * @brief Performs a clear/set/wait action on the uSleep enter signal to 
 *        coordinate internal tasks during the entry process.
 *  
 * @param control: Action to perform 
 */
void uSleepTrans_enterSignalControl(uSleep_trans_signal_control control);

#endif /* USLEEP_TRANSI_H */

