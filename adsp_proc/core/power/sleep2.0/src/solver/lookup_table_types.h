#ifndef LOOKUP_TABLE_TYPES_H
#define LOOKUP_TABLE_TYPES_H
/*==============================================================================
  FILE:         lookup_table_types.h
  
  OVERVIEW:     Data structures for lookup table solver

  DEPENDENCIES: None

                Copyright (c) 2013,2016 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.qdsp6/1.0.c2/power/sleep2.0/src/solver/lookup_table_types.h#1 $
$DateTime: 2020/02/10 01:57:30 $
==============================================================================*/
#include "DALStdDef.h"
#include "sleep_stats.h"
#include "sleep_stats_global.h"
#include "synthTypes.h"
#include "SleepLPR_synth_modes.h"
#include "SleepLPI_synth_modes.h"

/*==============================================================================
                              COMMON TYPE DECLARATIONS
 =============================================================================*/
typedef union
{
  int               mode_idx;
  sleep_synth_lprm  *mode_ptr;
} LUT_mode_elem_u;

/*==============================================================================
                              LPR TYPE DECLARATIONS
 =============================================================================*/
typedef struct sleep_mLUT_elem_s
{
  /* The minimum duration during which this mode should be chosen for entry. */
  uint64 duration_thresh;

  /* The mode to enter, if the sleep duration is within the given range,
   * provided that the latency and duration restrictions are still met.
   * For a given duration, the solver will traverse this list of modes,
   * and find the first one that meets the constraints. */
  LUT_mode_elem_u mode[SLEEP_LPR_NUM_SYNTHESIZED_MODES];

  /* Statistics for duration hit counts */
  sleepStats_generic element_stats;
} sleep_mLUT_elem;

typedef struct sleep_mLUT_s
{
  /* The number of table element entries in this table */
  uint32 num_elements;

  /* The mode to enter, if the sleep duration is within the given range,
   * provided that the latency and duration restrictions are still met.
   * For a given duration, the solver will traverse this list of modes,
   * and find the first one that meets the constraints. */
  sleep_mLUT_elem *element;
} sleep_mLUT;

/*==============================================================================
                              LPI TYPE DECLARATIONS
 =============================================================================*/
/* The structures below are [currently] identical the LPR structures above, with
 * the only difference being the array size. */
typedef struct sleep_lpiLut_elem_s
{
  uint64              duration_thresh;
  LUT_mode_elem_u     mode[SLEEP_LPI_NUM_SYNTHESIZED_MODES];
  sleepStats_generic  element_stats;

} sleep_lpiLut_elem;

typedef struct sleep_lpiLut_s
{
  uint32              num_elements;
  sleep_lpiLut_elem  *element;

} sleep_lpiLut;

#endif /* LOOKUP_TABLE_TYPES_H */

