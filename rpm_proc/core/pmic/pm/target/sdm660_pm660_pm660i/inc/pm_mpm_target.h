#ifndef __PM_MPM_TARGET_H__
#define __PM_MPM_TARGET_H__

/*! \file pm_mpm_target.h
*  \n
*  \brief Header file for target specific PMIC MPM declarations.
*  \n
*  \n &copy; Copyright 2014-2016 Qualcomm Technologies Incorporated, All Rights Reserved
*
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/rpm.bf/1.8/core/pmic/pm/target/sdm660_pm660_pm660i/inc/pm_mpm_target.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
11/20/14   kt     Created.
========================================================================== */

/*=========================================================================
      Include Files
==========================================================================*/

#include "pm_mpm_internal.h"

/*=========================================================================
      Type Definitions
==========================================================================*/

// step rate of 8mV/1.67uS = 4790uV/1uS
#define PM_RAIL_STEPPER_RATE_UVOLT_USEC  4800

/*===========================================================================
Data Declarations
===========================================================================*/

/*This enum is in strict order. If you need to
add /delete any entry from the sleep_cfg array
this enum should be updated as well*/
typedef enum 
{
  PM_MPM_SLEEP_CMD_CX_VSET_LB,
  PM_MPM_SLEEP_CMD_CX_VSET_UB,
  //PM_MPM_SLEEP_CMD_EBI_DIS,
  PM_MPM_SLEEP_CMD_MX_VSET_LB,
  PM_MPM_SLEEP_CMD_MX_VSET_UB,
  PM_MPM_SLEEP_CMD_PBS_TRIG_ARG,
  PM_MPM_SLEEP_CMD_PBS_TRIG, 
  PM_MPM_SLEEP_CMD_END,
}pm_mpm_sleep;

/*This enum is in strict order. If you need to
add /delete any entry from the active_cfg array
this enum should be updated as well*/
typedef enum 
{
  PM_MPM_ACTIVE_CMD_PBS_TRIG_ARG,
  PM_MPM_ACTIVE_CMD_PBS_TRIG, 
  PM_MPM_ACTIVE_CMD_MX_MODE,
  PM_MPM_ACTIVE_CMD_CX_MODE,
  PM_MPM_ACTIVE_CMD_MX_VSET_LB,
  PM_MPM_ACTIVE_CMD_MX_VSET_UB,
  //PM_MPM_ACTIVE_CMD_EBI_EN,
  PM_MPM_ACTIVE_CMD_CX_VSET_LB,
  PM_MPM_ACTIVE_CMD_CX_VSET_UB,
  PM_MPM_ACTIVE_CMD_END,
}pm_mpm_active;

/**
  * Enum to store the array index of the different rail types in
  * pm_mpm_cmd_index_type[] in target based config.
  */
typedef enum
{
   PM_MPM_CX_INDEX,
   PM_MPM_MX_INDEX,
   PM_MPM_NUM_INDICES,
} pm_mpm_target_cmd_arr_index;

/*----------------------------------------------------------------------------
 * Function : pm_mpm_target_cmd_config
 * -------------------------------------------------------------------------*/
/*!
    Description: Return a pointer to a config data buffer for target based
                 MPM voltage rail command.
    @param
      mpm_cfg_ptr: pointer to the data structure that pointer to
                   the buffer which contains target based config data
                   for retention and active voltage.
    @return
    PM_ERR_FLAG__SUCCESS success otherwise PMIC error.

    @dependencies
    railway_get_corner_voltage()
    pm_rpm_calculate_vset()


    @sa None
*/
pm_err_flag_type pm_mpm_target_cmd_config
(
  pm_mpm_cmd_cfg_type *mpm_cmd_ptr,
  pm_mpm_cfg_type *sleep_cfg_ptr, 
  pm_mpm_cfg_type *active_cfg_ptr, 
  pm_mpm_rails_info_type *mpm_rails_ptr, 
  pm_mpm_cmd_index_type *cmd_index_ptr,
  uint32 *mpm_max_delay_ptr
);

#endif /* __PM_MPM_TARGET_H__ */

