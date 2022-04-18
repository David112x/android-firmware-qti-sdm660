#ifndef _USLEEP_HWIO_H_
#define _USLEEP_HWIO_H_
/*==============================================================================
  FILE:         uSleep_hwio.h

  OVERVIEW:     This file contains the generic HWIO wrapper macros for sleep.

  DEPENDENCIES: None
                
                Copyright (c) 2016 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary
================================================================================
$Header: //components/rel/core.qdsp6/1.0.c2/power/uSleep/src/hwio/uSleep_hwio.h#1 $
$DateTime: 2020/02/10 01:57:30 $
================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

#include "HALhwio.h"

/* Ensure prefix is defined at build level */
#ifndef USLEEP_HWIO_PREFIX
#error "USLEEP_HWIO_PREFIX is undefined"
#endif

/*==========================================================================
 *                                MACROS
 *=========================================================================*/
/* These macros are used to defer register name - build script can provide
 * the necessary parameters to construct actual register name.
 *
 * @Note
 * This list does not cover all HWIO macros. Only those macros used by 
 * SLEEP layer are defined here. If required, new wrapper macros can
 * be added here. */
#define _USLEEP_HWIO_CONCAT_NAME(prefix, name)  prefix##_##name
#define USLEEP_HWIO_CONCAT_NAME(prefix, name)   _USLEEP_HWIO_CONCAT_NAME(prefix, name)
#define USLEEP_HWIO_EXPAND_NAME(name)           USLEEP_HWIO_CONCAT_NAME(USLEEP_HWIO_PREFIX, name)

#define USLEEP_HWIO_VAL(name, field, val)       HWIO_VAL(USLEEP_HWIO_EXPAND_NAME(name), field, val)
#define USLEEP_HWIO_FVAL(name, field, val)      HWIO_FVAL(USLEEP_HWIO_EXPAND_NAME(name), field, val)

#define USLEEP_HWIO_IN(name)                    HWIO_IN(USLEEP_HWIO_EXPAND_NAME(name))
#define USLEEP_HWIO_INF(name, field)            HWIO_INF(USLEEP_HWIO_EXPAND_NAME(name), field)
#define USLEEP_HWIO_INM(name, mask)             HWIO_INM(USLEEP_HWIO_EXPAND_NAME(name), mask)

#define USLEEP_HWIO_OUT(name, val)              HWIO_OUT(USLEEP_HWIO_EXPAND_NAME(name), val)
#define USLEEP_HWIO_OUTF(name, field, val)      HWIO_OUTF(USLEEP_HWIO_EXPAND_NAME(name), field, val)

#define USLEEP_HWIO_FMSK(name, hwio_fldsym)     HWIO_FMSK(USLEEP_HWIO_EXPAND_NAME(name), hwio_fldsym)

#ifdef __cplusplus
}
#endif

#endif /* _USLEEP_HWIO_H_ */

