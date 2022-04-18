#ifndef DDR_DRIVERS_H
#define DDR_DRIVERS_H

#define DDR_DRIVERS_H_MAJOR  01
#define DDR_DRIVERS_H_MINOR  06

/**
  @file ddr_drivers.h
  @brief
  Function headers of DDR drivers on all targets.
*/
/*=============================================================================
NOTE: The @brief description and any detailed descriptions above do not appear
      in the PDF.

      The ddr_mainpage.dox file contains all file/group descriptions that
      are in the output PDF generated using Doxygen and Latex. To edit or
      update any of the file/group text in the PDF, edit the
      ddr_mainpage.dox file or contact Tech Pubs.

	  The above description for this file is part of the xxx group
      description in the ddr_mainpage.dox file. 
=============================================================================*/
/*=============================================================================
  Copyright (c) 2009-2015 Qualcomm Technology Incorporated.
  All rights reserved.
  Qualcomm Confidential and Proprietary.
=============================================================================*/
/*=============================================================================
                                EDIT HISTORY

$Header: //components/rel/rpm.bf/1.8/core/api/boot/ddr_drivers.h#1 $ 
$DateTime: 2016/11/03 00:13:13 $
$Author: pwbldsvc $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
01/10/13   tw      Removed vddcx and mx api from public header
12/07/12   tw      Exposed API for checking whether training is required or not.
08/08/12   sl      Added ddr_enter/exit_power_collapse()
05/06/11   tw      Added API to determine ddr training is required or not
05/06/11   tw      Added API to support extended ram partition table.
03/02/11   sd      (Tech Pubs) Edited/added Doxygen markup and comments.
11/17/10   dxiang  Doxygen grouping changes for API auto-generation
10/27/10   tw      Added API to turn on and off hw based self refresh
06/23/10   sl      Moved ddr_device_detection() to ddr_devices.h
06/11/10   sl      Doxygenated comments
05/05/10   tw      Added API for retriving ddr type
04/23/10   sl      Added pre/post XO shutdown
04/19/10   tw      Updated to support lpddr2 ram size detection
03/01/10   tw      Updated to perform ficdc calibration for all interfaces when
                   performing voltage switch
02/25/10   tw      Added API for voltage switch sequence
02/19/10   tw      Added api to convert from desired bandwidth to frequency
02/08/10   tw      updated ddr drivers to use dalsys instead of deprecated api
12/11/09   tw      update self refresh routine to pass in clock speed
06/27/09   tw      Initial revision.
=============================================================================*/

#include "ddr_common.h"

/** @addtogroup ddr_apis
@{ */



/* ============================================================================
**  Function : ddr_get_extended_cdt_params
** ============================================================================
*/
/**
*   @brief
*   Get DDR device parameters.
*
*   @param[in]  interface_name  Interface to get DDR device parameters for
*
*   @return
*   DDR device parameters
*
*   @dependencies
*   None
*
*   @sa
*   None
*
*   @sa
*   None
*/
void *ddr_get_extended_cdt_params(void);

/*=============================================================================
    Function : ddr_init
=============================================================================*/

/**
  Initializes the DDR HAL with the correct DDR parameters. 

  @return
  None.

  @dependencies
  This function must be called before any DDR driver functions are called.
*/
void ddr_init( void );

/*=============================================================================
    Function : ddr_initialize_device
=============================================================================*/

/**
  Sets up the DDR parameters in the HAL and initializes the DDR device.

  This function passes the currently used DDR parameters to the HAL and
  then initializes the DDR device per the specified clock speed.

  @param[in] clk_speed    Clock speed.

  @return
  None.

  @dependencies
  None.
*/
void ddr_initialize_device
(
  uint32  clk_speed
);

/*=============================================================================
    Function : ddr_pre_clock_switch
=============================================================================*/

/**
  Stalls a DDR device and loads new timing parameters into shadow registers 
  to prevent data loss during clock switching. Depending on whether the clock 
  speed is increased or decreased, this function loads the shadow registers to 
  actual registers before or after clock switching. 

  This function is called before the clock is switched.

  @param[in] curr_clk        Current clock speed.
  @param[in] new_clk         New speed to which the clock is switched.
  @param[in] interface_name  Interface for which the clock is switched.

  @return
  None.
  
  @dependencies
  The HAL_SDRAM_Pre_Clock_Switch() function must be called after this function 
  is called.

  @sa
  ddr_clock_switch
*/
void ddr_pre_clock_switch
(
  uint32           curr_clk,
  uint32           new_clk,
  SDRAM_INTERFACE  interface_name
);

void ddrsns_pre_clock_switch
(
  uint32           curr_clk,
  uint32           new_clk
);

/*=============================================================================
    Function : ddr_clock_switch
=============================================================================*/

/**
  Stalls a DDR device and loads new timing parameters into shadow registers 
  to prevent data loss during clock switching. Depending on whether the clock 
  speed is increased or decreased, this function loads the shadow registers to 
  actual registers before or after clock switching. 

  This function is called for clock switching.

  @param[in] curr_clk        Current clock speed.
  @param[in] new_clk         New speed to which the clock is switched.
  @param[in] interface_name  Interface for which the clock is switched.

  @return
  None.
  
  @dependencies
  The HAL_DDR_Clock_Switch() function must be called after this function 
  is called.

  @sa
  ddr_post_clock_switch
*/
void ddr_clock_switch
(
  uint32           curr_clk,
  uint32           new_clk,
  SDRAM_INTERFACE  interface_name
);

/*=============================================================================
    Function : ddr_post_clock_switch
=============================================================================*/

/**
  Reactivates (unstalls) a DDR device. Depending on whether the clock 
  speed is increased or decreased, this function loads the shadow registers to 
  actual registers before or after clock switching.

  This function is called right after the clock is switched.

  @param[in] curr_clk        Current clock speed.
  @param[in] new_clk         New speed to which the clock is switched.
  @param[in] interface_name  Interface for which the clock is switched.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Post_Clock_Switch() function must be called before this 
  function is called.

  @sa
  ddr_pre_clock_switch
*/
void ddr_post_clock_switch
(
  uint32           curr_clk,
  uint32           new_clk,
  SDRAM_INTERFACE  interface_name
);

void ddrsns_post_clock_switch
(
  uint32           curr_clk,
  uint32           new_clk
);

/*=============================================================================
    Function : ddr_pre_xo_shutdown
=============================================================================*/

/**
  Puts a DDR device into Self Refresh mode and disables the CDC and I/O 
  calibration.

  This function is called right before XO shutdown. 

  @param[in] clk_speed    Clock speed.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Pre_XO_Shutdown() function must be called after this function 
  is called.

  @sa
  ddr_post_xo_shutdown
*/
void ddr_pre_xo_shutdown
(
  uint32  clk_speed
);

/*=============================================================================
    Function : ddr_post_xo_shutdown
=============================================================================*/

/**
  Takes a DDR device out of Self Refresh mode and enables the CDC and I/O 
  calibration.

  This function is called right after XO wakeup. 

  @param[in] clk_speed    Clock speed.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Post_XO_Shutdown() function must be called before this function 
  is called.

  @sa
  ddr_pre_xo_shutdown
*/
void ddr_post_xo_shutdown
(
  uint32  clk_speed
);

/*=============================================================================
    Function : ddr_pre_voltage_switch
=============================================================================*/

/**
  Stalls a DDR device to prevent data loss during voltage switching. 

  This function is called right before voltage switching.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Pre_Voltage_Switch() function must be called after this 
  function is called.

  @sa
  ddr_post_voltage_switch
*/
void ddr_pre_voltage_switch( void );

/*=============================================================================
    Function : ddr_post_voltage_switch
=============================================================================*/

/**
  Reactivates (unstalls) a DDR device to prevent data loss after voltage 
  switching. 

  This function is called right after voltage switching.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Post_Voltage_Switch() function must be called before this 
  function is called.

  @sa
  ddr_pre_voltage_switch
*/
void ddr_post_voltage_switch( void );

/*=============================================================================
    Function : ddr_enter_self_refresh_all
=============================================================================*/

/**
  Puts one or more DDR devices into Self Refresh mode.

  When there is more than one DDR device, this function first
  reads the device status to make sure the device is in Active mode before
  putting it into Self Refresh mode.

  @param[in] clk_speed    Clock speed.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Enter_Self_Refresh_All() function must be called after this 
  function is called.

  @sa
  ddr_exit_self_refresh_all
*/
void ddr_enter_self_refresh_all
(
  uint32  clk_speed
);

/*=============================================================================
   Function : ddr_exit_self_refresh_all
=============================================================================*/

/**
  Takes one or more DDR devicess out of Self Refresh mode.

  When there is more than one DDR device, this function first reads
  the device status to make sure the device is in Self Refresh mode before
  taking it out of Self Refresh mode.

  @param[in] clk_speed    Clock speed.

  @return
  None.

  @dependencies
  The HAL_SDRAM_Exit_Self_Refresh_All() function must be called before this 
  function is called.

  @sa
  ddr_enter_self_refresh_all
*/
void ddr_exit_self_refresh_all
(
  uint32 clk_speed
);

/*=============================================================================
    Function : ddr_enter_self_refresh
=============================================================================*/

/**
  Puts into Self Refresh mode a DDR device that is currently in Active mode.

  This function first checks to see if the DDR device specified by the caller
  is available and active, and then puts it into Self Refresh mode. If the
  device is not active or not available, this function does nothing.

  @param[in] interface_name  Interface for which the DDR device is put in
                             Self Refresh mode.
  @param[in] chip_select     Chip select for which the DDR device is put in
                             Self Refresh mode.
  @param[in] clk_speed       Clock speed.

  @return
  None.

  @dependencies
  None.

  @sa
  ddr_exit_self_refresh
*/
void ddr_enter_self_refresh
(
  SDRAM_INTERFACE   interface_name,
  SDRAM_CHIPSELECT  chip_select,
  uint32            clk_speed
);

void ddrsns_enter_self_refresh
(
  DDR_CHANNEL   interface_name,
  DDR_CHIPSELECT  chip_select,
  uint32            clk_speed
);

/*=============================================================================
    Function : ddr_exit_self_refresh
=============================================================================*/

/**
  Takes a DDR device out of Self Refresh mode.

  @param[in] interface_name  Interface for which the DDR device is taken out of
                             Self Refresh mode.
  @param[in] chip_select     Chip select for which the DDR device is taken out
                             of Self Refresh mode.
  @param[in] clk_speed       Clock speed.

  @return
  None.

  @dependencies
  None.

  @sa
  ddr_enter_self_refresh
*/
void ddr_exit_self_refresh
(
  SDRAM_INTERFACE   interface_name,
  SDRAM_CHIPSELECT  chip_select,
  uint32            clk_speed
);

void ddrsns_exit_self_refresh
(
  DDR_CHANNEL   interface_name,
  DDR_CHIPSELECT  chip_select,
  uint32            clk_speed
);

/*=============================================================================
    Function : ddr_stall
=============================================================================*/

/**
  Stalls DDR devices on a specified DDR interface.
   
  Only the DDR devices in Active status are stalled. Devices with any other 
  status, such as Self Refresh, Deep Power Down or Unavailable, are ignored.
  
  @param[in] interface_name    Interface for which the DDR devices are stalled.

  @return
  None.
   
  @dependencies
  None.
   
  @sideeffects
  The DDR devices are unavailable after they have been stalled.
   
  @sa
  ddr_unstall
*/
void ddr_stall
(
  SDRAM_INTERFACE  interface_name
);

/*=============================================================================
    Function : ddr_unstall
=============================================================================*/

/**
  Reactivates (unstalls) all stalled DDR devices.

  DDR devices with a Stalled status are reactivated (unstalled). Devices with 
  any other status are ignored.

  @return
  None.

  @dependencies
  None.

  @sa
  ddr_stall
*/
void ddr_unstall( void );

/*=============================================================================
    Function : ddr_enter_deep_power_down
=============================================================================*/

/**
  Puts a DDR device in Deep Power Down mode.

  @param[in] interface_name  Interface for which the DDR device is put in DPD
                             mode.
  @param[in] chip_select     Chip select for which the DDR device is put in DPD
                             mode.

  @return
  None.

  @dependencies
  None.

  @sideeffects
  After a device has entered DPD mode, it is unavaiable for use. When bring a
  device out of DPD mode, a full hardware intialization must be executed.

  @sa
  ddr_exit_deep_power_down
*/
void ddr_enter_deep_power_down
(
  SDRAM_INTERFACE   interface_name,
  SDRAM_CHIPSELECT  chip_select
);

void ddrsns_enter_deep_power_down
(
  DDR_CHANNEL   interface_name,
  DDR_CHIPSELECT  chip_select
);

/*=============================================================================
    Function : ddr_exit_deep_power_down
=============================================================================*/

/**
  Takes a DDR device out of Deep Power Down mode.
   
  @param[in] interface_name  Interface for which the DDR device is taken out of
                             DPD mode.
  @param[in] chip_select     Chip select for which the DDR device is taken out
                             of DPD mode.
  @param[in] clk_speed       Clock speed to reinitialize the DDR device.

  @return
  None.

  @dependencies
  The DDR clock must be returned to an applicable initialization frequency:\n
  - LPDDR1 -- No restrictions.\n
  - LPDDR2 -- < 50 MHz.

  @sa
  ddr_enter_deep_power_down
*/
void ddr_exit_deep_power_down
(
  SDRAM_INTERFACE interface_name,
  SDRAM_CHIPSELECT chip_select,
  uint32 clk_speed
);

void ddrsns_exit_deep_power_down
(
  DDR_CHANNEL interface_name,
  DDR_CHIPSELECT chip_select,
  uint32 clk_speed
);


/*=============================================================================
    Function : ddr_enable_hw_based_self_refresh
=============================================================================*/

/**
  Enables the hardware-triggered Self Refresh feature.

  @param[in] interface_name   Interface to turn on the hardware-triggered self
                              refresh.

  @return
  None.

  @dependencies
  None.
*/
void ddr_enable_hw_based_self_refresh(SDRAM_INTERFACE interface_name);

/*=============================================================================
    Function : ddr_disable_hw_based_self_refresh
=============================================================================*/

/**
  Disables the hardware-triggered Self Refresh feature.

  @param[in] interface_name    Interface to turn off the hardware-triggered
                               self refresh.

  @return
  None.

  @dependencies
  None.
*/
void ddr_disable_hw_based_self_refresh(SDRAM_INTERFACE interface_name);

/*=============================================================================
    Function : ddr_set_hw_based_self_refresh_timer
=============================================================================*/

/**
  Updates the hardware-triggered self refresh timer.

  @param [in] interface_name      Interface to turn off the hardware-triggered
                                  self refresh.
  @param [in] self_refresh_timer  New timer value for the hardware-triggered
                                  self refresh.

  @return
  None.

  @dependencies
  None.
*/
void ddr_set_hw_based_self_refresh_timer(SDRAM_INTERFACE interface_name, uint16 self_refresh_timer);

/*=============================================================================
    Function : ddr_get_status
=============================================================================*/

/**
  Gets the status of a DDR device. This function returns the ddr_status 
  internal structure so the caller of this function can see the devices that 
  are available and the states the devices are in.

  @return
  Status of the devices on all available interfaces and chip selects.

  @dependencies
  None.
*/
ddr_interface_state ddr_get_status( void );

/*=============================================================================
    Function : ddr_set_status
=============================================================================*/

/**
  Sets the status of a DDR device. 
  
  @dependencies
  None.
*/
void ddr_set_status(SDRAM_STATUS status);

/* ============================================================================
**  Function : ddr_update_info
** ============================================================================
*/
/*!
*   @brief
*   update the internal ddr info variable with the latest detected settings
*
*   @details
*   update the internal ddr info variable with the latest detected settings
*
*   @param  None.
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*
*   @retval
*   None
*
*   @sa None
*/

void ddr_update_info(void);

/* ============================================================================
**  Function : ddr_get_info
** ============================================================================
*/
/*!
*   @brief
*   Returns the physical configuration of ddr on target
*
*   @details
*   This function will return the physical configuration of the ddr on target
*
*   @param  None.
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*
*   @retval ddr_size_infor contains the ddr size and base address
*
*   @sa None
*/

ddr_info ddr_get_info(void);

/* ============================================================================
**  Function : ddr_update_size
** ============================================================================
*/
/*!
*   @brief
*   Returns the ddr size and base address
*   
*   @details
*
*   
*  @param  None
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval ddr_size_infor contains the ddr size and base address
*   
*   @sa None
*/

void ddr_update_size(void);

/* ============================================================================
**  Function : ddr_get_size
** ============================================================================
*/
/*!
*   @brief
*   Returns the ddr size and base address
*
*   @details
*
*
*  @param  None
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*
*   @retval ddr_size_infor contains the ddr size and base address
*
*   @sa None
*/

ddr_size_info ddr_get_size(void);

/* ============================================================================
**  Function : ddr_get_partition
** ============================================================================
*/
/*!
*   @brief
*   Returns the ddr partitions and base address
*   
*   @details
*
*   
*  @param  None
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval ddr_size_partitioning contains the ddr partitions and base address
*   
*   @sa None
*/

ddr_size_partition ddr_get_partition(void);

/* ============================================================================
**  Function : ddr_get_frequency
** ============================================================================
*/
/**
*   @brief
*   Returns the corresponding frequency to the bandwidth desired.
*
*   This function takes the given bandwidth and converts it to the appropriate
*   frequency in terms of KHz 

  @param[in] bandwidth    Bandwidth desired in megabits.

  @return
  Corresponding frequency in kHz.

  @dependencies
  None.
*/
uint32 ddr_get_frequency
(
  uint32 bandwidth
);

/*=============================================================================
    Function : ddr_get_ddr_type
=============================================================================*/

/**
  Gets the DDR device type. This function reads the MSM&reg;&nbsp; hardware ID 
  to determine the type of DDR device.

  @return
  Type of DDR device.

  @dependencies
  None.
*/
DDR_TYPE ddr_get_ddr_type( void );

/*=============================================================================
    Function : ddr_get_temperature_status
=============================================================================*/

/**
  Gets the temperature status.
   
  This function reads the MR4 register or SRR register depending on the DDR
  type and returns the temperature status.

  @return 
  Temperature status, as specified in JEDEC.

  @dependencies
  None.
*/
uint8 ddr_get_temperature_status(void);

/* =============================================================================
**  Function : ddr_configure_lpae
** =============================================================================
*/
/**
*   @brief
*   configures ddr for LPAE by statically splitting the memory in half.
*
*   @param high_mem_enabled     -  [IN] partition guid for high mem is enabled
*
*   @retval  void
*
*   @dependencies
*   ddr initialization has already finished
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void ddr_configure_lpae(boolean high_mem_enabled);

/* ============================================================================
**  Function : ddr_training_required
** ============================================================================
*/
/*!
*   @brief
*   This function will parse the magic cookie and clock plan to determine
*   if the runtime configuration has changed since the last time we trained
*   and if it has return TRUE for training required.
*   Otherwise return FALSE for no training required.
*
*   @details
*   This function will parse the magic cookie and clock plan to determine
*   if the runtime configuration has changed since the last time we trained
*   and if it has return TRUE for training required.
*   Otherwise return FALSE for no training required.
*
*   @param
*   None
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval  boolean - Training required/Not required
*
*   @sa None
*/
boolean ddr_training_required(void);

/* =============================================================================
**  Function : ddr_enter_power_collapse
** =============================================================================
*/
/**
*   @brief
*   Function called before DDR controller goes into power collapse.
*
*   @param[in]  clk_speed  Current clock speed (in KHz)
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void ddr_enter_power_collapse(uint32 clk_speed);

/* =============================================================================
**  Function : ddr_exit_power_collapse
** =============================================================================
*/
/**
*   @brief
*   Function called after DDR controller comes out of power collapse.
*
*   @param[in]  clk_speed  Current clock speed (in KHz)
*
*   @retval  None
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void ddr_exit_power_collapse(uint32 clk_speed);

/* ===========================================================================
**  Function : ddr_save_status_regs
** ===========================================================================
*/
/*!
*   @brief
*   This function is called before and after pre/post clock/voltage switch to store the
*   status information of the important DDR PHY/BIMC registers .
*
*   @details
*   This function save the status register values, BIMC/PHY status registers ( for pre_clock , pre_voltage switch ) in 0th index , 
*   BIMC/PHY status registers ( for post_clock , post_voltage switch) in 1st index of ddr_status_reg field of DDR_STRUCT 
*
*   @param
*   None
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval  None
*
*   @sa None
*/

void ddr_save_status_regs(reg_status_log pre_post);

/* ============================================================================
**  Function : ddr_training_is_required
** ============================================================================
*/
/*!
*   @brief
*   This function will parse the magic cookie and clock plan to determine
*   if the runtime configuration has changed since the last time we trained
*   and if it has return TRUE for training required.
*   Otherwise return FALSE for no training required.
*
*   @details
*   This function will parse the magic cookie and clock plan to determine
*   if the runtime configuration has changed since the last time we trained
*   and if it has return TRUE for training required.
*   Otherwise return FALSE for no training required.
*
*   @param
*   None
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval  boolean - Training required/Not required
*
*   @sa None
*/
boolean ddr_training_is_required(void);
/** @} */ /* end_addtogroup ddr_apis */

#endif /* DDR_DRIVERS_H */
