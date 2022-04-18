#ifndef __PM_UEFI_VREGS_H__
#define __PM_UEFI_VREGS_H__
/*===========================================================================


            PM UEFI VREG HEADER FILE

DESCRIPTION
    This file contains functions prototypes and variable/type/constant 
  declarations to support the different voltage regulators inside the 
  Qualcomm Power Manager ICs.
  
Copyright (c) 2003-2012  by Qualcomm Technologies, Inc.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE
                                                                         
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
9/14/12	   al	   Added api pm_dev_pwr_mode
07/27/12   al	   Added pulldown
07/27/12   al	   Renamed all Enums,added device index and resource index
09/14/11   sm      Added SET_LEVEL and GET_LEVEL functionality
05/23/11   dy      Port to UEFI
===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include "com_dtypes.h"
#include "pm_uefi_lib_err.h"
#include "Protocol/EFIPmicVreg.h"
#include "pm_uefi.h"

/* Which VREG needs to be configured */
/*===========================================================================
                        TYPE DEFINITIONS 
===========================================================================*/
// VREG identifier used to call VREG APIs


/**
 * Typedef for VREG level in millivolts
 */

typedef uint64 pm_vreg_mask_type;
typedef uint64 pm_vreg_masked_type;

//typedef enum
//{
/*LDO resources */
//	PM_LDO_1 ,
//	PM_LDO_2 ,
//	PM_LDO_3 ,
//	PM_LDO_4 ,
//	PM_LDO_5 ,
//	PM_LDO_6 ,
//	PM_LDO_7 ,
//	PM_LDO_8 ,
//	PM_LDO_9 ,
//	PM_LDO_10 ,
//	PM_LDO_11 ,
//	PM_LDO_12 ,
//	PM_LDO_13 ,
//	PM_LDO_14 ,
//	PM_LDO_15 ,
//	PM_LDO_16 ,
//	PM_LDO_17 ,
//	PM_LDO_18 ,
//	PM_LDO_19 ,
//	PM_LDO_20 ,
//	PM_LDO_21 ,
//	PM_LDO_22 ,
//	PM_LDO_23 ,
//	PM_LDO_24 ,
//	PM_LDO_25 ,
//	PM_LDO_26 ,
//	PM_LDO_27 ,
//	PM_LDO_28 ,
//	PM_LDO_29 ,
//	PM_LDO_30 ,
//	PM_LDO_31 ,
//	PM_LDO_32 ,
//	PM_LDO_33 ,
/* SMPS Resources */
//	PM_SMPS_1 ,
//	PM_SMPS_2 ,
//	PM_SMPS_3 ,
//	PM_SMPS_4 ,
//	PM_SMPS_5 ,
//	PM_SMPS_6 ,
//	PM_SMPS_7 ,
//	PM_SMPS_8 ,
//	PM_SMPS_9 ,
//	PM_SMPS_10 ,
/* Voltage Switcher Resources */
//	PM_VS_LVS_1 ,
//	PM_VS_LVS_2 ,
//	PM_VS_LVS_3 ,
//	PM_VS_LVS_4 ,
//	PM_VS_LVS_5 ,
//	PM_VS_LVS_6 ,
//	PM_VS_LVS_7 ,
//	PM_VS_LVS_8 ,
//	PM_VS_LVS_9 ,
//	PM_VS_LVS_10 ,
//	PM_VS_LVS_11 ,
//	PM_VS_LVS_12 ,
//	PM_VS_MVS_1 ,
//	PM_VS_OTG_1 ,
//	PM_VS_HDMI_1 ,
//	PM_VREG_INVALID 
//} pm_vreg_id_type;
typedef EFI_PM_VREG_ID_TYPE pm_vreg_id_type;

typedef uint32 pm_vreg_level_type_microvolts;
typedef uint32 pm_vreg_level_type_millivolts;
typedef uint32 pm_vreg_level_type;

/*****************************************************************************/
/* Enumerations used when calling PMIC VREG APIs */
/*****************************************************************************/
typedef enum 
{
    PM_PWR_SW_MODE_PFM = 0,	// Low power mode	
    PM_PWR_SW_MODE_BYPASS = 1,	// Bypass mode bit 5
    PM_PWR_SW_MODE_AUTO = 2,   // auto mode bit 6
    PM_PWR_SW_MODE_NPM = 4,	// Normal mode bit 7	
    PM_PWR_SW_MODE_INVALID
}pm_pwr_sw_mode_type;

/* BUCK VREGs Maximum compensation values. */
#define PM_VREG_BUCK_MAX_SAWTOOTH_I_COMP  0x07
#define PM_VREG_BUCK_MAX_GM_COMP          0x0f
#define PM_VREG_BUCK_MAX_RES_COMP         0x0f

/* BUCK VREGS Compensation settings. */
typedef struct
{
   uint8 sawtooth_set;
   uint8 gm_set;
   uint8 resistor_set;
}pm_vreg_buck_cfg_cp_type;


/**
 * Typedef for selecting SMPS stepper delay 
 */
typedef float pm_vreg_smps_stepper_delay_type;
/**
 * Typedef for selecting SMPS step size
 */
typedef float pm_vreg_smps_step_size_type;
/*=============================================================================
                        FUNCTION PROTOTYPE
=============================================================================*/
/**
 * FUNCTION  pm_vreg_init()
 *
 * @brief    Initialize VREG driver
 *
 * @param    None
 *
 * @retval   PM_ERR_FLAG__VREG_ID_OUT_OF_RANGE  = VREG ID is out of range
 *           PM_ERR_FLAG__SUCCESS               = SUCCESS.
 *
 */
pm_err_flag_type pm_vreg_init
(
  unsigned Pmic_Device_Index
);


/**
 * @brief Enable/Disable VREG
 *
 * @param vreg_id The VREG that is to be configured
 * @param enable  TRUE - enable VREG
 *                FALSE - disable VREG
 * 
 * @return PM_ERR_FLAG__SUCCESS if successful
 */
pm_err_flag_type pm_vreg_control
(
 unsigned Pmic_Device_Index,
  pm_vreg_id_type    vreg_id, 
  boolean            enable
);

pm_err_flag_type  pm_dev_pwr_control
( 
 unsigned pmic_device_index,
 pm_vreg_id_type  vreg_id, 
 boolean  enable
 );
/**
 * @brief Set desired voltage for the vreg
 *
 * @param[in] vreg_id of the VREG that is to be configured
 * @param[in] voltage to be set
 *
 * @retval     PM_ERR_FLAG__SUCCESS if successful
 *///pm_vreg_set_level
pm_err_flag_type pm_dev_pwr_volt_level
( 
  unsigned Pmic_Device_Index,
  pm_vreg_id_type     vreg_id, 
  pm_vreg_level_type  voltage
);

/**
 * @brief      Determines the voltage of a vregs
 *
 * @param[in]  vreg_id of the VREG that is to be configured
 * @param[out] voltage
 *
 * @retval      PM_ERR_FLAG__SUCCESS if successful
 *///pm_vreg_get_level
pm_err_flag_type pm_dev_pwr_volt_level_status
( 
 unsigned Pmic_Device_Index,
 pm_vreg_id_type      vreg_id, 
  pm_vreg_level_type  *voltage
);


/**
 * 
 * @param vreg_cmd
 * @param vreg
 * 
 * @return pm_err_flag_type
 */
//pm_err_flag_type pm_dev_pwr_pull_down
//(
//    unsigned            pmic_device_index,
//	uint8 				externalResourceIndex, 
//	pm_switch_cmd_type 	enableDisableCmd 
//    );
//#pragma message("Do not use pm_pwr_pull_down(), which is deprecated. Use pm_dev_pwr_pull_down() instead.")
//pm_err_flag_type pm_pwr_pull_down
//(
// uint8 				externalResourceIndex, 
// pm_switch_cmd_type 	enableDisableCmd 
// );

/**
 * 
 * @param clk_sel
 *     Select RC or TCXO as the SMPS clock source
 * 
 * @return pm_err_flag_type
 */
//pm_err_flag_type pm_dev_pwr_buck_clk_source
//( 
//    unsigned                        pmic_device_index,
//	uint8 							externalResourceIndex, 
//	pm_pwr_buck_clk_source_type 	clkSource 
//);
//#pragma message("Do not use pm_pwr_buck_clk_source(), which is deprecated. Use pm_dev_pwr_buck_clk_source() instead.")
//pm_err_flag_type pm_pwr_buck_clk_source
//( 
//    uint8 							externalResourceIndex, 
//    pm_pwr_buck_clk_source_type 	clkSource 
//);


/**
 * @brief Sets sw mode for vregs
 *
 * @param[in] pmic_device_index  Primary :0 , Secondary:1 
 * @param[in] vreg_id of the VREG that is to be configured 
 * @param[in] mode, refer pm_pwr_sw_mode_type for more info
 *                          
 * @param enable  TRUE - enable VREG FALSE - disable VREG 
 * 
 * @return PM_ERR_FLAG__SUCCESS if successful
 */
pm_err_flag_type pm_dev_pwr_mode
(
   unsigned pmic_device_index, 
   pm_vreg_id_type     vreg_id, 
   pm_pwr_sw_mode_type mode
); 

#endif /* __PM_UEFI_VREGS_H__ */

