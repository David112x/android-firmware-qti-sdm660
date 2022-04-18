#ifndef SNS_SMGR_REG_H
#define SNS_SMGR_REG_H

/*============================================================================

  @file sns_smgr_reg.h

  @brief
  This file contains registry related definitions for Sensor Manager
 
*******************************************************************************
*   Copyright (c) 2014 Qualcomm Technologies, Inc.  All Rights Reserved.
*   Qualcomm Technologies Proprietary and Confidential.
*
******************************************************************************* 
 
============================================================================*/
/* $Header: //components/rel/ssc.slpi/2.2/smgr/src/sns_smgr_reg.h#1 $ */
/* $DateTime: 2017/04/17 22:20:39 $ */
/* $Author: pwbldsvc $ */

/*============================================================================
  EDIT HISTORY FOR FILE

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2014-04-23  pn    Initial version
============================================================================*/
#include "sns_smgr_mr.h"
#include "sns_rh.h"

/*===========================================================================

                   SMGR MACRO

===========================================================================*/


/*===========================================================================

                   EXTERNAL DEFINITIONS AND TYPES

===========================================================================*/


/*===========================================================================

                   STRUCTURE DEFINITIONS

===========================================================================*/

/*===========================================================================

                          FUNCTIONS

===========================================================================*/
extern bool sns_smgr_ssi_is_last_cfg(uint16_t id);

extern int sns_smgr_ssi_get_cfg_idx(uint16_t id);

extern int32_t sns_smgr_ssi_get_cfg_id(uint8_t idx);

extern void sns_smgr_process_reg_resp_msg(
  sns_smgr_mr_msg_s* item_ptr);

extern sns_err_code_e sns_smgr_req_reg_data( 
  const uint16_t     item_id, 
  const uint8_t      item_type);

extern sns_err_code_e sns_smgr_update_reg_data( 
  const uint16_t     item_id, 
  const uint8_t      item_type,
  uint32_t           item_len, 
  uint8_t*           data_ptr);

extern void smgr_send_reg_message_for_fac_cal(void);
extern void sns_smgr_save_last_rcvd_reg_group_id(uint16_t group_id);
sns_reg_mag_cal_params_data_group_s mag_fac_cal_reg_data; //SI
sns_reg_mag_cal_params_data_group_s mag_dyn_cal_reg_data; //HI

#endif /* SNS_SMGR_REG_H */

