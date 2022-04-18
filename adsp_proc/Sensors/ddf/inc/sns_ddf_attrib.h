/** 
 * @file sns_ddf_attrib.h 
 * @brief Device driver attributes 
 *  
 * This file lists various attributes supported by various drivers. The Sensors 
 * Manager uses these to query certain characteristics and status of the driver, 
 * as well as to set dynamic configuration parameters (e.g. resolution, 
 * calibration, etc.). 
 *  
 * @see sns_ddf_driver_if_s.set_attrib()
 * @see sns_ddf_driver_if_s.get_attrib()
 * 
 * Copyright (c) 2010-2015 Qualcomm Technologies, Inc. 
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*==============================================================================
  Edit History

  This section contains comments describing changes made to the module. Notice
  that changes are listed in reverse chronological order. Please use ISO format
  for dates.

  $Header: //components/rel/ssc.slpi/2.2/ddf/inc/sns_ddf_attrib.h#1 $
  $DateTime: 2017/04/17 22:20:39 $

  when       who  what, where, why 
  ---------- ---  -----------------------------------------------------------
  2016-03-02 jtl  Added "get" operation for S4S_CONFIG
  2015-10-12 jtl  Added S4S attributes.
  2015-05-28 pn   Added SNS_DDF_ATTRIB_FILTER_DELAY to SNS_DDF_DRIVER_VTBL_REVISION 0x2
  2014-05-12 tc   Added ODR and FIX (Q16) conversion macros
  2014-02-14 MW   Made sns_ddf_registry_group_s size uint16_t
  2013-06-21 pn   Added SNS_DDF_ATTRIB_SUPPORTED_ODR_LIST
  2013-05-05 sd   Added SNS_DDF_ATTRIB_FIFO and SNS_DDF_ATTRIB_ODR_TOLERANCE
  2013-05-01 lka  Added SNS_DDF_ATTRIB_IO_REGISTER and related data types.
  2012-03-23 pn   Added SNS_DDF_ATTRIB_REGISTRY_GROUP
  2011-12-29 yk   Added SNS_DDF_ATTRIB_ODR and cleaned up comments.
  2011-08-16 yk   Added SNS_DDF_ATTRIB_BIAS.
  2011-08-11 br   Changed type definition of sns_ddf_lowpass_freq_t to q16_t.
  2011-05-10 yk   Added more specific definition of LOWPASS attribute.
  2011-01-11 yk   Added new attribute SNS_DDF_ATTRIB_RESOLUTION_ADC.
                  Redefined SNS_DDF_ATTRIB_RESOLUTION.
  2010-10-26 ag   Added attributes for ALSPRX.
  2010-10-22 yk   Added use of boolean. Added "_enable" to motion detect type.
  2010-09-24 yk   Major revision including new and changed definitions.
  2010-08-14 yk   Renamed identifiers to conform to DSPS naming convention.
  2010-07-30 yk   Initial revision.
==============================================================================*/

#ifndef SNS_DDF_DRIVER_ATTRIB_H
#define SNS_DDF_DRIVER_ATTRIB_H

#include <stdbool.h>
#include <stdint.h>
#include "fixed_point.h"
#include "sns_ddf_common.h"

/**
 * Driver and device attributes. 
 */
typedef enum
{
    SNS_DDF_ATTRIB_POWER_INFO,
    SNS_DDF_ATTRIB_POWER_STATE,
    SNS_DDF_ATTRIB_DELAYS,
    SNS_DDF_ATTRIB_RANGE,
    SNS_DDF_ATTRIB_RESOLUTION_ADC,
    SNS_DDF_ATTRIB_RESOLUTION,
    SNS_DDF_ATTRIB_LOWPASS,
    SNS_DDF_ATTRIB_MOTION_DETECT,
    SNS_DDF_ATTRIB_DRIVER_INFO,
    SNS_DDF_ATTRIB_DEVICE_INFO,
    SNS_DDF_ATTRIB_THRESHOLD,
    SNS_DDF_ATTRIB_ACCURACY,
    SNS_DDF_ATTRIB_BIAS,
    SNS_DDF_ATTRIB_ODR,
    SNS_DDF_ATTRIB_SUPPORTED_ODR_LIST,
    SNS_DDF_ATTRIB_REGISTRY_GROUP,
    SNS_DDF_ATTRIB_IO_REGISTER,
    SNS_DDF_ATTRIB_FIFO,
    SNS_DDF_ATTRIB_ODR_TOLERANCE,
    SNS_DDF_ATTRIB_FILTER_DELAY,
    SNS_DDF_ATTRIB_S4S_CONFIG,
    SNS_DDF_ATTRIB_S4S_ST,
    SNS_DDF_ATTRIB_S4S_DT,
    SNS_DDF_ATTRIB_S4S_MAX_CLOCK_DRIFT,

} sns_ddf_attribute_e;


/** 
 * SNS_DDF_ATTRIB_POWER_STATE 
 *  
 * Power modes supported by a device. 
 *  
 * Get: Driver returns its current power state.
 * Set: SMGR selects power state with a value from this enum.
 */
typedef enum
{
    SNS_DDF_POWERSTATE_ACTIVE,
    SNS_DDF_POWERSTATE_LOWPOWER

} sns_ddf_powerstate_e;


/**
 * SNS_DDF_ATTRIB_POWER_INFO 
 *  
 * Information regarding the power states supported by this device. 
 *  
 * Get: Driver populates this structure. 
 * Set: n/a 
 */
typedef struct
{
    uint32_t  active_current;    /**< Avg current in uA consumed in ACTIVE. */
    uint32_t  lowpower_current;  /**< Avg current in uA consumed in LOWPOWER. */

} sns_ddf_power_info_s;


/**
 * SNS_DDF_ATTRIB_DELAYS 
 *  
 * Various delays associated with data retrieval for the driver. Note that the 
 * driver is only expected to provide values associated with its devices. Values 
 * concerning bus delays are outside of this scope. 
 *  
 * Get: Driver populates this structure. 
 * Set: n/a 
 */
typedef struct
{
    uint32_t  time_to_active;  /**< Interval in microsec from the time a wakeup
                                    instruction is received until the time the
                                    sensor is ready to be commanded. */
    uint32_t  time_to_data;    /**< Worst case interval between time the data
                                    retrieval instruction is received and the
                                    time data is available for reading. This
                                    does not include bus delay. */
} sns_ddf_delays_s;


/**
 * SNS_DDF_ATTRIB_MOTION_DETECT 
 *  
 * Enables/disables motion detection.
 * 
 * Get: n/a
 * Set: "True" to enable motion detection or "false" to disable it.
 */
typedef bool sns_ddf_motion_detect_enable_t;


/**
 * SNS_DDF_ATTRIB_RANGE 
 *  
 * A range representing the set of values a sensor can report, in the sensor's 
 * units. 
 *  
 * Get: Driver returns an ordered set of ranges. 
 * Set: SMGR selects a range via an index into the ordered set. 
 */
typedef struct
{
    q16_t  min;  /**< Minimum value in this range. */
    q16_t  max;  /**< Maximum value in this range. */

} sns_ddf_range_s;


/**
 * SNS_DDF_ATTRIB_RESOLUTION 
 *  
 * The smallest unit the sensor device can measure. This refers to the absolute 
 * maximum resolution the device can measure. 
 *  
 * Get: Driver returns a value in its standard measurement units. 
 * Set: n/a 
 */
typedef q16_t sns_ddf_resolution_t;


/**
 * SNS_DDF_ATTRIB_RESOLUTION_ADC 
 *  
 * Supported ADC bit length of the device. 
 *  
 * Get: Driver returns an ordered set of supported bit lengths. 
 * Set: SMGR select a bit length via an index into the ordered set.  
 */
typedef struct
{
    uint16_t bit_len;  /**< ADC bit length. */
    uint16_t max_freq; /**< Maximum frequency that the driver (not device) can
                            reasonably support at this bit length. Note that
                            this may be slower than the actual HW spec. */
} sns_ddf_resolution_adc_s;


/**
 * SNS_DDF_ATTRIB_BIAS 
 *  
 * Bias value for a specific axis of a sensor. 
 *  
 * Get: Driver returns an array of biases for each of the sensor's axes. 
 * Set: n/a 
 */
typedef q16_t sns_ddf_bias_t;


/**
 * SNS_DDF_ATTRIB_LOWPASS 
 *  
 * Low pass filter (LPF) frequencies supported by this device. 
 *  
 * Get: Array of low-pass frequencies, specified in Hz, in ascending order.
 * Set: SMGR selects a frequency via an index into the ordered set.
 */
typedef q16_t sns_ddf_lowpass_freq_t;


/**
 * SNS_DDF_ATTRIB_ODR 
 *  
 * Output data rate for devices that support self-scheduled periodic sampling. 
 *  
 * Get: Returns the currently set ODR.
 * Set: Configures the device to an ODR setting above 90% of the requested value.
 */
typedef uint32_t sns_ddf_odr_t;

// Converts a value from sns_ddf_odr_t to q16_t
#define DDF_ODRTOFIX_Q16(x)       FX_FLTTOFIX_Q16((uint32_t) x)

// Converts a value from q16_t to sns_ddf_odr_t using the floor operation
// Note: this operation assumes that x is a POSITIVE value, because it does not make sense to have a negative frequency
#define DDF_FIXTOODR_FLOOR_Q16(x) (sns_ddf_odr_t) FX_FIXTOFLT_Q16(FX_FLOOR_Q16(x))

// Converts a value from q16_t to sns_ddf_odr_t using the ceiling operation
// Note: this operation assumes that x is a POSITIVE value, because it does not make sense to have a negative frequency
// if there are fractional bits, take the floor and add 1
#define DDF_FIXTOODR_CEIL_Q16(x)  (x & 0x0000FFFF)?(DDF_FIXTOODR_FLOOR_Q16(x)+1):DDF_FIXTOODR_FLOOR_Q16(x)

/**
 * SNS_DDF_ATTRIB_DRIVER_INFO 
 *  
 * Identifying information regarding a driver, in human readable format. All 
 * strings must be null terminated.
 *  
 * Get: Driver returns this structure. 
 * Set: n/a 
 */
typedef struct
{
    char*    name;      /**< A string representing the name of this driver. */
    int32_t  version;   /**< The driver's version number. */

} sns_ddf_driver_info_s;


/**
 * SNS_DDF_ATTRIB_DEVICE_INFO 
 *  
 * Identifying information regarding a device, in human readable format. All 
 * strings must be null terminated.
 *  
 * Get: Driver returns this structure. 
 * Set: n/a 
 */
typedef struct
{
    char*    name;      /**< Device name. */
    char*    vendor;    /**< Vendor name. */
    char*    model;     /**< The device model name. */
    int32_t  version;   /**< The device version number. */

} sns_ddf_device_info_s;


typedef struct
{
    uint8_t* group_data; /* pointer to byte array of registry data */      
    uint16_t  size; /* size of registry data; must be <=256 */

} sns_ddf_registry_group_s;

/** data width. */
typedef enum
{
   SNS_DDF_IO_DATA_WIDTH_UINT8,
   SNS_DDF_IO_DATA_WIDTH_UINT16,
   SNS_DDF_IO_DATA_WIDTH_UINT32

} sns_ddf_io_data_width_e;

/**
 * SNS_DDF_ATTRIB_IO_REGISTER
 *
 * Read or write device specific register values from/to specified address.
 *
 * Get: SMGR gives instruction to a driver using this structure, and the driver
 *      returns result using the structure.
 * Set: SMGR gives instruction to a driver using this structure, and the driver returns
 *      the result using the structure
 */
typedef struct
{
    uint32_t* address_ptr;    /* The starting register address */
    uint32_t  length;         /* The access count in bytes */
    bool      addr_fixed;     /* When TRUE, no incremental address method is used.
                                 The value is only valid for input to the functions */
    sns_ddf_io_data_width_e data_width;   /* defines if data width is one, two, or four bytes */
    uint8_t   data[1];        /* The data values to be written or have been read.
                                 The actual array size is determined by the length field */
} sns_ddf_io_register_s;

/**
* SNS_DDF_ATTRIB_FIFO
*
* For getting FIFO related attributes from driver or setting FIFO related
  attribute to driver. This is called after all DD is initialized.
*
* Get: Driver returns the attribute using structure sns_ddf_fifo_attrib_get_s
* Set: SMGR deliver the parameter using structure sns_ddf_fifo_attrib_set_s
*      SMGR set FIFO watermark, enable FIFO if watermark is > 0, disable FIFO   
	if watermark is 0. ( do not enable/disable FIFO watermark interrupt )  
*/

typedef struct
{
    sns_ddf_sensor_e  sensor;    // The sensor types which shares the FIFO*/
    sns_ddf_handle_t  dd_handle;  // The driver handle which associated with
   				 // the above sensor type dd_handle is the
				 // handle returned from the init() call*/
} sns_ddf_fifo_share_sensor_s;

typedef struct
{
    bool		is_supported;		// Is FIFO supported by device?
    bool		is_sw_watermark;	// Is FIFO watermark simulated by 
				  	// timer? Note that some device
				   	// doesn't support FIFO HW watermark
    uint16_t     max_watermark;    	// The maximum number of samples of this sensor type
                                    // can be stored in the FIFO assuming no other sensor
                                    // data is stored in the FIFO if shared.
    uint16_t     share_sensor_cnt; 	// The count of sensor types which 
					// shares the FIFO 
    sns_ddf_fifo_share_sensor_s   *share_sensors[1]; // The pointer to the
					// information of sensor types that 
					// share the FIFO. The actual array 
					// size is determined by
                                      // the share_sensor_cnt field
} sns_ddf_fifo_attrib_get_s;

/**
 * SNS_DDF_ATTRIB_FIFO
 *
 * Information regarding a sensor device FIFO.
 *
 * Get: n/a
 * Set: SMGR sends this structure ptr to the driver.
 * 
 */
typedef struct
{
 uint16_t watermark;     /**< FIFO watermark level that should be set*/

}sns_ddf_fifo_set_s;


/**
 * SNS_DDF_ATTRIB_ODR_TOLERANCE
 *
 * Information regarding the ODR tolerance. Indicates the percent error value.
 *
 *
 * Get: Driver returns this information
 * Set: n/a
 */
typedef q16_t sns_ddf_odr_tolerance_t;


/**
 * SNS_DDF_ATTRIB_FILTER_DELAY
 *
 * The current filter delay DD applies to sample timestamps
 * Available in SNS_DDF_DRIVER_VTBL_REVISION 0x2 and later
 *
 * Get: Driver returns filter delay in ticks
 * Set: n/a
 */
typedef uint32_t sns_ddf_filter_delay_t;

/**
 * SNS_DDF_ATTRIB_S4S_CONFIG
 *
 * Configure S4S parameters. This command can be set at any time. Typically it will be
 * sent at least once during any FIFO or ODR reconfiguration. It may also be sent
 * in the middle of sensor streaming operations to modify the ideal_sync_interval.
 * Available in SNS_DDF_DRIVER_VTBL_REVISION 0x3 and later
 *
 * The t_ph and ideal_sync_interval values can be used to calculate the actual
 * ODR which will be forced by the S4S procedure.
 * If fifo_int_en is false, this shall override any current or future call to enable_sched_data
 *
 * After the S4S parameters are set, SMGR will get the parameters back to discover if the
 * driver has modified the S4S parameters. SMGR will also read the S4S parameters after every
 * ODR change event from the driver.
 * 
 * For getting S4S parameters from the driver, the driver may:
 *   - Modify TPH to indicate that a different number of samples are available during each
 *     interval. This may be 0 if the driver has disabled S4S.
 *   - Modify the RR.
 *   - Modify the ideal_sync_interval to indicate that the driver wants to receive the
 *     ST/DT commands at a different interval. This is not recommended. The driver should
 *     try to use the interval initially provided by SMGR. SMGR will honor the new interval,
 *     but this may result in this driver not being synced to another driver's schedule
 *     (resulting in extra wakeups and more power).
 *
 * Note: SMGR will not send an additional S4S config, nor change the S4S timing, if the
 *       driver changes the requested ODR. If the driver changes the ODR and sends the
 *       ODR_CHANGED event, it will be up to the driver to calculate a new t_ph value,
 *       if necessary.
 *
 * Get: Current S4S configuration used by the hardware & driver
 * Set: Driver sends S4S config to hardware
 */

typedef struct
{
  uint16_t t_ph; /**< Number of samples in one synchronization period */
  uint8_t  rr;   /**< 0-3, indicating the LSB resolution of the DT message.
                  * rr=0 --> 2^-11 of the ideal sync interval.
                  * rr=1 --> 2^-12 of the ideal sync interval.
                  * rr=2 --> 2^-13 of the ideal sync interval.
                  * rr=3 --> 2^-14 of the ideal sync interval.
                  */
  uint32_t ideal_sync_interval; /**< Number of ticks in one sync interval. */
  bool     fifo_int_en; /**< false: disable FIFO interrupt, or set watermark to maximum
                             true: enable FIFO interrupt as normal -- only used for debugging */
}sns_ddf_s4s_config_s;

/**
 * SNS_DDF_ATTRIB_S4S_ST
 *
 * S4S ST timing. May be set in uImage mode.
 * Available in SNS_DDF_DRIVER_VTBL_REVISION 0x3 and later
 *
 *
 * Get: n/a
 * Set: Instructs driver to send ST command to hardware
 *      Contains the time of the ideal ST sync, which should be in the past.
 */
typedef sns_ddf_time_t sns_ddf_st_t; /**< Clock tick of the ideal ST time */

/**
 * SNS_DDF_ATTRIB_S4S_DT
 *
 * S4S DT timing. May be set in uImage mode.
 * Available in SNS_DDF_DRIVER_VTBL_REVISION 0x3 and later
 *
 * Set: Instructs driver to send DT command to hardware.
 *      If the value is 0/false, an abort DT should be sent.
 *      If the value is not 0/true, the correct DT should be sent with the offset (in
 *      "RR" units) between the actual ST time and the ideal ST time.
 *
 * Return values:
 *   SNS_DDF_SUCCESS: DT was successfully sent to the hardware
 *   SNS_DDF_EDT_NOT_SENT: DT was not sent to the hardware
 *   SNS_DDF_EDT_ABORT: DT abort was sent to the hardware
 */
typedef bool sns_ddf_dt_t; /**< true: send DT with timing. false: send abort DT */

/**
 * SNS_DDF_ATTRIB_S4S_MAX_CLOCK_DRIFT
 *
 * Reads worst-case clock drift given the current S4S configuration,
 * assuming accurate ST/DT intervals and synchronized clocks.
 * Available in SNS_DDF_DRIVER_VTBL_REVISION 0x3 and later
 *
 *
 * Get: The worst-case clock drift possible in one S4S ST/DT window in ticks
 * Set: n/a
 */
typedef sns_ddf_time_t sns_ddf_max_clock_drift_t; /**< max clock drift in ticks */


#endif

