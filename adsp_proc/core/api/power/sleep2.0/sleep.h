#ifndef SLEEP_H
#define SLEEP_H
/*==============================================================================
  FILE:         sleep.h

  OVERVIEW:     This file contains public APIs related to Sleep task.

  DEPENDENCIES: None

                Copyright (c) 2012-2014,2016 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.qdsp6/1.0.c2/api/power/sleep2.0/sleep.h#1 $
$DateTime: 2020/02/10 01:57:30 $
==============================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

#include "comdef.h"

/*==============================================================================
                            GLOBAL FUNCTION DECLARATIONS
 =============================================================================*/ 
/**
 * sleepOS_isProcessorInSTM
 *
 * @brief Checks if the processor is in Single threaded mode (also known
 *        as INTLOCK'd or Sleep context) when this function is called.
 *
 * For multicore (HLOS) targets, it should gives the status of core 
 * on which this function was called.
 *
 * @NOTE 
 * This function is more like a query function which returns the value 
 * at any given point. It may have changed immediately after calling it.
 *
 * @return Non-zero if processor in sleep context otherwise zero.
 */
uint32 sleepOS_isProcessorInSTM(void);

#ifdef __cplusplus
}
#endif

#endif /* SLEEP_H */

