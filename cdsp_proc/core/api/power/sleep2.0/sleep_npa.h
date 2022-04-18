#ifndef SLEEP_NPA_H
#define SLEEP_NPA_H
/*==============================================================================
  FILE:         sleep_npa.h
  
  OVERVIEW:     This file provides the public externs and definitions that
                are exported by the sleep module for accessing the various sleep 
                nodes and functions.

  DEPENDENCIES: None

                Copyright (c) 2016 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.qdsp6/1.0.c2/api/power/sleep2.0/sleep_npa.h#1 $
$DateTime: 2020/02/10 01:57:30 $
==============================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

#include "npa.h"

/*==============================================================================
                         MASTER SLEEP LPR NODE DEFINITIONS
 =============================================================================*/
/* Name of the master sleep LPR node */
#define SLEEP_LPR_NODE_NAME                 "/sleep/lpr"

/*==============================================================================
                            LATENCY NODE DEFINITIONS
 =============================================================================*/
/* Name of the normal mode sleep latency node with values in ticks.
 * Indicates how fast the system must respond to a normal mode wakeup interrupt */
#define SLEEP_NORMAL_LATENCY_NODE_NAME      "/core/cpu/latency"

/* Name of the island mode sleep latency node with values in ticks.
 * Indicates how fast the system must respond to a normal mode wakeup interrupt while
 * allowing island if the restriction is greater than the island entry latency */
#define SLEEP_ISLAND_LATENCY_NODE_NAME      "/core/cpu/island/latency"

/* Name of the corresponding sleep latency nodes with values in uS */
#define SLEEP_USEC_NORMAL_LATENCY_NODE_NAME "/core/cpu/latency/usec"
#define SLEEP_USEC_ISLAND_LATENCY_NODE_NAME "/core/cpu/island/latency/usec"

/*==============================================================================
                            WAKEUP NODE DEFINITIONS
 =============================================================================*/
/* Name of the sleep wakeup node with values in ticks.
 * Used to provide a hint as to when the next wakeup interrupt may occur */
#define SLEEP_WAKEUP_NODE_NAME            "/core/cpu/wakeup"

/* Query type to be used with the wakeup nodes above */
#define SLEEP_WAKEUP_QUERY_TYPE           (NPA_QUERY_RESERVED_END+1)

/* Query type that is the same as SLEEP_QUERY_WAKEUP_TIME, except it returns the
 * absolute wakeup time. */
#define SLEEP_WAKEUP_QUERY_TYPE_ABS       (NPA_QUERY_RESERVED_END+2)

/*==============================================================================
                        MAX DURATION NODE DEFINITION
 =============================================================================*/
/* Name of the sleep max duration node with values in ticks
 * Indicates an expected periodic interrupt time */
#define SLEEP_MAX_DURATION_NODE_NAME      "/sleep/max_duration"

/* Name of the sleep max duration node with values in uS */
#define SLEEP_USEC_MAX_DURATION_NODE_NAME "/sleep/max_duration/usec"

/* Query type to be used with either of the max duration nodes above */
#define SLEEP_MAX_DURATION_QUERY_TYPE     (NPA_QUERY_RESERVED_END+1)

/*==============================================================================
                                LPR DEFINITIONS
 =============================================================================*/
/* Global LPR node state that enables ALL component modes */
#define SLEEP_LPR_ENABLE_ALL                0

/*------------
 * CPU VDD LPR
 *------------*/
/* Name of the CPU VDD LPR node */
#define SLEEP_CPUVDD_LPR_NODE_NAME          "/core/cpu/vdd"

/* Valid LPRM state requets */
#define SLEEP_CPUVDD_LPR_ENABLE_ALL         SLEEP_LPR_ENABLE_ALL  /* All LPRM's allowed. */
#define SLEEP_CPUVDD_LPR_CLOCKGATE_ONLY     2                     /* All LPRM's disabled */
#define SLEEP_CPUVDD_LPR_DISABLE_ALL        SLEEP_CPUVDD_LPR_CLOCKGATE_ONLY

/* Maximum valid state */
#define SLEEP_CPUVDD_LPR_MAX_STATE          SLEEP_CPUVDD_LPR_DISABLE_ALL

/*------------
 * RPM LPR
 *------------*/
/* Name of the RPM LPR node */
#define SLEEP_RPM_LPR_NODE_NAME             "/core/cpu/rpm_sync"

/* Valid LPRM state requets */
#define SLEEP_RPM_LPR_ENABLE_ALL            SLEEP_LPR_ENABLE_ALL  /* All LPRM's allowed. */
#define SLEEP_RPM_LPR_DISABLE_ALL           2                     /* All LPRM's disabled */

/* Maximum valid state */
#define SLEEP_RPM_LPR_MAX_STATE             SLEEP_RPM_LPR_DISABLE_ALL

/*------------
 * L2 LPR
 *------------*/
/* Name of the L2 Cache LPR node */
#define SLEEP_L2_CACHE_LPR_NODE_NAME        "/core/cpu/l2cache"

/* Valid LPRM state requets */
#define SLEEP_L2_CACHE_LPR_ALLOW_ALL        SLEEP_LPR_ENABLE_ALL  /* All LPRM's allowed */
#define SLEEP_L2_CACHE_LPR_RETENTION_ONLY   1                     /* Allow only L2 retention modes */

/* Maximum valid state */
#define SLEEP_L2_CACHE_LPR_MAX_STATE        SLEEP_L2_CACHE_LPR_RETENTION_ONLY

#ifdef __cplusplus
}
#endif

#endif /* SLEEP_NPA_H */

