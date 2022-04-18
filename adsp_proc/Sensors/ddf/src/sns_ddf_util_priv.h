/** 
 * @file sns_ddf_util_priv.h 
 * @brief private header for DDF util.
 *  
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */

/*==============================================================================
  Edit History

  This section contains comments describing changes made to the module. Notice
  that changes are listed in reverse chronological order. Please use ISO format
  for dates.

  $Header: //components/rel/ssc.slpi/2.2/ddf/src/sns_ddf_util_priv.h#1 $
  $DateTime: 2017/04/17 22:20:39 $

  when       who  what, where, why 
  ---------- ---  -----------------------------------------------------------
  2015-11-03 pn   Added declaration for get_bit_position()
  2014-01-12 MW   Initial revision
==============================================================================*/

#ifndef SNS_DDF_UTIL_PRIV_H
#define SNS_DDF_UTIL_PRIV_H

#include "sns_ddf_util.h"

SNS_DDF_UIMAGE_CODE uint32_t get_bit_position (uint32_t flags);

#endif //SNS_DDF_UTIL_PRIV_H
