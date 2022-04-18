/*==============================================================================
 Copyright (c) 2014, AKM
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
     3. Neither the name of the AKM nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
==============================================================================*/

/*==============================================================================

 Copyright (c) 2014-2016 Qualcomm Technologies, Inc. All Rights Reserved.
 Qualcomm Technologies Proprietary and Confidential.

==============================================================================*/

/*==============================================================================
  File Name         : sns_dd_mag_fifo_akm099xx_uimg.c
  Authors (, Name)  : Masahiko Fukasawa, Rikita YAMADA
  Version           : 2.2.6
  Date (MM/DD/YYYY) : 01/24/2017
==============================================================================*/

/*==============================================================================

                       EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

when         who     what, where, why
----------   ---     -----------------------------------------------------------
01/24/17     AKM     Add DC lib support.
12/14/16     BZ       Fix heartattack caused by incorrect timestamp
11/04/16     AKM     improved jitter time in DRI mode. increased AKM_INVALID_DATA_NUM
11/03/16     AKM     improved jitter time in FIFO-DRI mode (add AKM_INVALID_DATA_NUM)
10/14/16     AKM     improved jitter time in Polling/DRI mode
10/13/16     AKM     Add AKM_ENABLE_S4S flag, improved jitter time
09/21/16     AKM     improved jitter time
08/18/16     SD      improved jitter time
08/02/16     SD      updated end timestamp check
03/03/16     AKM     Fix RR calculation.
02/12/16     AKM     Add S4S support.
02/12/16     AKM     Add AK09915D/AK09916D support.
11/14/15     MW      Polling jitter failure fix
10/27/15     PN      Fixed negative timestamp before sample period can be averaged
10/09/15     PN      use avg sample period for timestamping
10/01/15     MW      Consider total_samples-1 during timestamping (FIFO mode)
07/09/15     AKM     Add AK09913/AK09916.
06/08/15     AR      On receiving more sample than WM setting, use ODR for sample interval
03/31/15     AKM     Updated copyright message
03/10/15     MW      Eliminated KW error
11/19/14     AKM     Fixed SPI operation, switched multiple write to single write
11/13/14     MW      Fixed timestamps in trigger_fifo_data
11/12/14     MW      Fixed timestamps
09/12/14     AKM     Initial Edition, created for uImage support
==============================================================================*/

/*============================================================================
INCLUDE FILES
============================================================================*/

#include "sns_dd_mag_fifo_akm099xx_priv.h"

/*============================================================================
STATIC VARIABLE DEFINITIONS
============================================================================*/
/* WEIGHT value must be from 0.0 to 1.0 (floating value) */
#define AKM_SAMPLING_INTERVAL_WEIGHT   (0.5f)
#define AKM_DELAY_SET_WM_TICK_TIME     0
#define AKM_MAX_SAMPLING_RATE_HZ       (100)
#define TICKS_PER_SEC                  (32768uL)
#define AKM_SAMPLING_INTERVAL_TH       (TICKS_PER_SEC / AKM_MAX_SAMPLING_RATE_HZ / 2)
#define AKM_SMPLING_INTERVAL_TH_FACTOR (0.9f)

/*============================================================================
STATIC FUNCTION PROTOTYPES
============================================================================*/
static void sns_mgt_akm_notify_smgr_err(
  sns_dd_mag_akm099xx_state_s *state,
  sns_ddf_status_e            status
);

static void sns_mgt_akm_averaging(
    sns_dd_mag_akm099xx_state_s *state,
    q16_t                       data[]
);

static sns_ddf_status_e sns_mgt_akm_read_sensor(
  sns_dd_mag_akm099xx_state_s *state,
  sns_ddf_sensor_data_s       **sensor_data,
  sns_ddf_sensor_sample_s     **sensor_sample,
  uint32_t                    samples,
  sns_ddf_time_t              *ts_now
);

static void sns_mgt_akm_sample_sensor(
  sns_dd_mag_akm099xx_state_s *state,
  sns_ddf_time_t              timestamp,
  bool                        in_timer_handler
);

static void sns_mgt_akm_log_sensor_data(
  sns_ddf_sensor_data_s *sensor_data,
  bool                  fifo_mode
);

static sns_ddf_status_e sns_mgt_akm_is_fifo_overflow(
  sns_dd_mag_akm099xx_state_s *state,
  bool                        *result
);

static void sns_akm_validate_timestamps(
  sns_ddf_time_t cur_time,
  sns_ddf_time_t last_timestamp,
  int32_t        num_samples,
  float         est_interval,
  sns_ddf_time_t *restrict start_time,
  sns_ddf_time_t *restrict end_time,
  sns_ddf_time_t delay
);


/*==============================================================================
  STATIC FUNCTION:   sns_mgt_akm_notify_smgr_err
==============================================================================*/
/*!
  @brief Called SMGR needs to be notified of error

  @note This will routine will be called from
  sns_mgt_akm_sample_sensor_* routine when an error is seen in memory
  allocation for sample data or problem in reading the data from the
  Mag. The top level sensor data structure with filled with appropriate
  error type before calling the sns_dd_mag099xx_notify_smgr routine

  @param[in] *state               ptr to the driver state structure
  @param[in] status               error code for the problem

  @return
   None

============================================================================*/
static void sns_mgt_akm_notify_smgr_err(
    sns_dd_mag_akm099xx_state_s *state,
    sns_ddf_status_e            status)
{
  sns_ddf_sensor_data_s *sensor_data;

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_1(LOW, "notify_smgr_err: status=%d", status);
#endif

  if (sns_ddf_malloc_ex(
        (void **)&sensor_data,
        sizeof(sns_ddf_sensor_data_s),
        state->smgr_handle) != SNS_DDF_SUCCESS) {
    MAG_AKM_DEBUG_MSG_1(HIGH, "Malloc error for sensor_data (%d).", status);
  } else {
    /* set error status */
    sensor_data->sensor    = SNS_DDF_SENSOR_MAG;
    sensor_data->status    = status;
    sensor_data->timestamp = sns_ddf_get_timestamp();
    /* send */
    sns_ddf_smgr_notify_data(state->smgr_handle, sensor_data, 1);
    /* finalize */
    sns_ddf_mfree_ex(sensor_data, state->smgr_handle);
  }
}

/*==============================================================================
  STATIC FUNCTION:   sns_mgt_akm_averaging
==============================================================================*/
/*!
  @brief

  @note

  @param[in]     *state  ptr to the driver state structure
  @param[in/out] data    ptr to data. The size must be AKM_MAG099XX_NUM_DATATYPES.
                         A new data as input, averaged data as output.
  @return

  ============================================================================*/
static void sns_mgt_akm_averaging(
    sns_dd_mag_akm099xx_state_s *state,
    q16_t                       data[])
{
  uint16_t total_num = AKM_MAG099XX_NUM_DATATYPES * AKM_MAG099XX_AVERAGING;
  int      i;
  q16_t    sumX, sumY, sumZ;

  /* input sanity check */
  if (state == NULL || data == NULL) {
    return;
  }

  /* put data into buffer */
  for (i = total_num - 1; i >= AKM_MAG099XX_NUM_DATATYPES; i--) {
    state->data_cache[i] = state->data_cache[i - AKM_MAG099XX_NUM_DATATYPES];
  }
  for (i = AKM_MAG099XX_NUM_DATATYPES - 1; i >= 0; i--) {
    state->data_cache[i] = data[i];
  }
  if (state->num_cached < AKM_MAG099XX_AVERAGING) {
    state->num_cached++;
  }

  /* overwrite total_num with the number of available data */
  total_num = AKM_MAG099XX_NUM_DATATYPES * state->num_cached;

  /* calculate average */
  sumX = sumY = sumZ = 0;
  for (i = 0; i < total_num; i += 3) {
    sumX += state->data_cache[i];
    sumY += state->data_cache[i + 1];
    sumZ += state->data_cache[i + 2];
  }

  data[0] = sumX / state->num_cached;
  data[1] = sumY / state->num_cached;
  data[2] = sumZ / state->num_cached;
}

/*==============================================================================
  STATIC FUNCTION:   sns_mgt_akm_read_sensor
==============================================================================*/
/*!
  @brief

  @note
    This function allocate new memory area to the pointer which is specified
    by the arguments, sensor_data and sensor_sample.
    When memory is allocated successfully, put measurement data to sensor_sample.
    When this function fails, allocated memory are freed internally.
    This function sets required parameters in struct except timestamp.
    Because timestamp method is different if FIFO is used or not.

  @param[in]  *state          ptr to the driver state structure
  @param[out] **sensor_data   ptr to sensor_data_s struct.
                              This pointer is valid only when the fucntion succeeds.
  @param[out] **sensor_sample ptr to sensor_sample_s struct.
                              This pointer is valid only when the fucntion succeeds.
  @param[in]  samples         The number of data set to be read.
                              In case of AKM magnetometer, when this value is 1,
                              then you can get X,Y and Z data because the device
                              has 3 axes. It means we count 3 axes data for 1.
  @return

  ============================================================================*/
static sns_ddf_status_e sns_mgt_akm_read_sensor(
    sns_dd_mag_akm099xx_state_s *state,
    sns_ddf_sensor_data_s       **sensor_data,
    sns_ddf_sensor_sample_s     **sensor_sample,
    uint32_t                    samples,
    sns_ddf_time_t              *ts_now )
{
  sns_ddf_status_e status;
  uint8_t          akm_read_data[AKM_MAG099XX_NUM_DATA_BYTES];
  uint8_t          out;
  uint16_t         i, j;
  sns_ddf_time_t   txn_start;

  /* input sanity check */
  if (state == NULL || sensor_data == NULL || sensor_sample == NULL) {
    return SNS_DDF_EINVALID_PARAM;
  }

  if (samples == 0) {
    return SNS_DDF_EINVALID_PARAM;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_1(LOW, "read_sensor: samples to read=%u", samples);
#endif

  /* allocate required memory to store the samples in FIFO */
  if ((status = sns_ddf_malloc_ex(
           (void **)sensor_data,
           sizeof(sns_ddf_sensor_data_s),
           state->smgr_handle)) != SNS_DDF_SUCCESS) {
    MAG_AKM_DEBUG_MSG_1(HIGH, "Malloc error for sensor_data (%d).", status);
    goto READ_SENSOR_ERR1;
  }

  /* allocate required memory to store the samples in FIFO */
  if ((status = sns_ddf_malloc_ex(
           (void **)sensor_sample,
           AKM_MAG099XX_NUM_DATATYPES * sizeof(sns_ddf_sensor_sample_s) * samples,
           state->smgr_handle)) != SNS_DDF_SUCCESS) {
    MAG_AKM_DEBUG_MSG_1(HIGH, "Malloc error for sensor_sample (%d).", status);
    goto READ_SENSOR_ERR2;
  }

  /* create a report */
  (*sensor_data)->sensor      = SNS_DDF_SENSOR_MAG;
  (*sensor_data)->status      = SNS_DDF_SUCCESS;
  (*sensor_data)->samples     = *sensor_sample;
  (*sensor_data)->num_samples = 0;

  for (i = 0; i < samples; i++) {
    uint8_t          reg_st2;
    int16_t          temp_i16;
    float            temp_flt[AKM_MAG099XX_NUM_DATATYPES];
    q16_t            data[AKM_MAG099XX_NUM_DATATYPES];
    sns_ddf_status_e data_status = SNS_DDF_SUCCESS;

    txn_start = sns_ddf_get_timestamp();
    /* Note that reading starts from HXL, not ST1 */
    if ((status = sns_ddf_read_port(
             state->port_handle,
             AKM_MAG_REG_ADDR_HXL_099XX,
             akm_read_data,
             AKM_MAG099XX_NUM_DATA_BYTES - 1,
             &out)) != SNS_DDF_SUCCESS) {
      MAG_AKM_DEBUG_MSG_1(HIGH, "read_port() error (%d).", status);
      goto READ_SENSOR_ERR3;
    }
    if( ts_now ) {
      *ts_now = txn_start;
    }

    /* Since read from HXL, the index of ST2 is as follows. */
    reg_st2 = akm_read_data[AKM_MAG099XX_NUM_DATA_BYTES - 2];

    /* Check if there's valid data in FIFO */
    /* This operation is only when the device has FIFO */
    if ((reg_st2 & AKM_MAG_INV_BIT_MASK) && (state->device_fifo_size != 0)){
      break;
    }

    /* Check overflow.
     * According to 4.3.1 of reference manual, status has to be
     * set to SNS_DDF_EDATA_BOUND. */
    if (reg_st2 & AKM_MAG_HOFL_BIT_MASK) {
      data_status = SNS_DDF_EDATA_BOUND;
    }

    for (j = 0; j < AKM_MAG099XX_NUM_DATATYPES; j++) {
      /* Storing raw data in 16 bits */
      temp_i16 = (int16_t)(((uint16_t)akm_read_data[(j * 2) + 0]) |
                           ((uint16_t)akm_read_data[(j * 2) + 1] << 8));
      /* Adjust sensitivity values to the measurement data read out from the
       * measurement data register. As a result, 'temp_flt' is unit of Gauss. */
      temp_flt[j] = temp_i16 * state->sens_adj_flt[j] * state->mag_scale_flt;
    }

#ifdef AKM_MAG_ENABLE_PDC
    MAG_AKM_DEBUG_MSG_3(HIGH,
        "akm,Q16,X,Y,Z before DC: %d %d %d",
        FX_FLTTOFIX_Q16(temp_flt[0]),
        FX_FLTTOFIX_Q16(temp_flt[1]),
        FX_FLTTOFIX_Q16(temp_flt[2]));
    /* Apply DC algorithm
     * If DC algorithm is failed, input vector will not overwritten. */
    if ((status = AKSC_DistCompen(state->pdc_parameter, temp_flt)) != SNS_DDF_SUCCESS) {
        MAG_AKM_DEBUG_MSG_1(HIGH, "DC error (%d).", status);
    }
    MAG_AKM_DEBUG_MSG_3(HIGH,
        "akm,Q16,X,Y,Z after  DC: %d %d %d",
        FX_FLTTOFIX_Q16(temp_flt[0]),
        FX_FLTTOFIX_Q16(temp_flt[1]),
        FX_FLTTOFIX_Q16(temp_flt[2]));
#endif

    /* convert float to Q16 format */
    for (j = 0; j < AKM_MAG099XX_NUM_DATATYPES; j++) {
      data[j] = FX_FLTTOFIX_Q16(temp_flt[j]);
    }

    /* Convert sensor data to the phone's coordinate system. */
    sns_ddf_map_axes(&state->axes_map, data);

    /* Take an average */
    sns_mgt_akm_averaging(state, data);

    /* Put the data into the packet. */
    for (j = 0; j < AKM_MAG099XX_NUM_DATATYPES; j++) {
      (*sensor_data)->samples[AKM_MAG099XX_NUM_DATATYPES * i + j].sample = data[j];
      if (state->num_cached < AKM_MAG099XX_AVERAGING){
        (*sensor_data)->samples[AKM_MAG099XX_NUM_DATATYPES * i + j].status = SNS_DDF_EINVALID_DATA;
        }
      else{
        (*sensor_data)->samples[AKM_MAG099XX_NUM_DATATYPES * i + j].status = data_status;
        }
      }

    if (state->num_cached < AKM_MAG099XX_AVERAGING)
    {
      (*sensor_data)->status = SNS_DDF_EINVALID_DATA;
    }

    (*sensor_data)->num_samples += AKM_MAG099XX_NUM_DATATYPES;
  }

  /* TODO: how about i=0, i.e. no data is available?
   * If FIFO_FLUSH operation is called right after the watermark interrupt,
   * INV_BIT will be set.
   * In this case, this operation is success or fail?
   * (current implementation is 'success')
   */

  return SNS_DDF_SUCCESS;

/* Error handling */
READ_SENSOR_ERR3:
  sns_mgt_akm_notify_smgr_err(state, status);
  sns_ddf_mfree_ex(*sensor_sample, state->smgr_handle);
READ_SENSOR_ERR2:
  sns_ddf_mfree_ex(*sensor_data, state->smgr_handle);
READ_SENSOR_ERR1:

  return status;
}

/*==============================================================================
  STATIC FUNCTION:   sns_mgt_akm_sample_sensor
==============================================================================*/
/*!
  @brief Called when the timer set by this driver has expired.

  @note This routine will read the data status & read the data and copy
  it at a malloced location. The address of the data location is passed
  as parameter in the notify_data routine.

  Condition must be:
    retry: 0 or larger number.

  @param[in] *state  ptr to the driver state structure
  @param[in] ts_now  Time at which this function is called.

  @return
   None

  ============================================================================*/
static void sns_mgt_akm_sample_sensor(
  sns_dd_mag_akm099xx_state_s *state,
  sns_ddf_time_t              ts_now,
  bool                        in_timer_handler)
{
  sns_ddf_status_e        status;
  sns_ddf_sensor_data_s   *sensor_data;
  sns_ddf_sensor_sample_s *sensor_sample;
  sns_ddf_time_t          sampleInterval;

  /* Input sanity check */
  if (state == NULL) {
    return;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_1(
      LOW,
      "sample_sensor: in_timer=%d",
      (in_timer_handler ? 1 : 0));
#endif

  /* initialize local variables */
  sensor_data = NULL;
  sensor_sample = NULL;

  /* In case of Android, no data update is worth issue than report incorrect data.
   * So, report current data even if the obtained data is not updated yet.
   */
#if 0
  /* Read ST1 first. Then check ST1 whether measurement is done or not */
  if ((status = sns_ddf_read_port(
           state->port_handle,
           AKM_MAG_REG_ADDR_STATUS1_099XX,
           &reg_st1,
           DDF_READ_ONE_BYTE,
           &out)) != SNS_DDF_SUCCESS) {
    /* Handling the err cond when reading operation is failed. */
    sns_mgt_akm_notify_smgr_err(state, status);
    MAG_AKM_DEBUG_MSG_1(HIGH, "Reading ST1 failed. Status = %d.", status);
    goto FINALIZE_SAMPLE_SENSOR;
  }

  /* Check ST1 bit */
  if ((reg_st1 & AKM_MAG_DRDY_BIT_MASK) == 0) {
    /* Measurement is not done yet. */
    if (NUM_MEASUREMENT_RETRY <= ++(state->retry)) {
      /* When retry number exceeds the limit, send error message. */
      sns_mgt_akm_notify_smgr_err(state, SNS_DDF_EDEVICE);
      MAG_AKM_DEBUG_MSG_1(HIGH, "Number of Retry = %d exceeded the limit.", state->retry);
      goto FINALIZE_SAMPLE_SENSOR;
    }

    /* start timer again */
    if ((status = sns_ddf_timer_start(
             state->sns_dd_tmr_obj,
             USEC_TIME_FOR_RETRY)) != SNS_DDF_SUCCESS) {
      /* timer cannot be started, exit with error */
      sns_mgt_akm_notify_smgr_err(state, status);
      MAG_AKM_DEBUG_MSG_1(HIGH, "Timer couldn't be started. Status = %d.", status);
      goto FINALIZE_SAMPLE_SENSOR;
    }

    /* just exit this function */
    MAG_AKM_DEBUG_MSG_1(MED, "Number of Retry = %d.", state->retry);
    goto EXIT_SAMPLE_SENSOR;
  }
#endif

  /* ST1 register is OK now. Then read sensor data.
   * After read_sensor succeeds, sensor_data and sensor_sample
   * must be free when exit this function.
   * If read_sensor function fails, the pointer is already freed.
   */
  if ((status = sns_mgt_akm_read_sensor(
          state,
          &sensor_data,
          &sensor_sample,
          1,
          NULL)) != SNS_DDF_SUCCESS) {
    /* error message reporting is already done in the function.
     * So, just exit this function.
     */
    goto FINALIZE_SAMPLE_SENSOR;
  }

  /* averaging is disabled. So delay is determined by hardware delay only.
   * i.e. not dependent to sampling interval any more.
   */
  /* set hardware measurement delay */
  if (state->extended_odr) {
    state->sample_delay = sns_ddf_convert_usec_to_tick(USEC_TIME_FOR_DEVICE_DELAY_EXT);
  } else {
    state->sample_delay = sns_ddf_convert_usec_to_tick(USEC_TIME_FOR_DEVICE_DELAY);
  }

  /* Polling mode */
  if(in_timer_handler){
    sensor_data->timestamp = ts_now;
    sensor_data->end_timestamp = ts_now;
  }
  /* DRI mode */
  else {
    /* set to invalid data at the first few samples */
    if (state->invalid_samples_cnt > 0) {
      sensor_data->status = SNS_DDF_EINVALID_DATA;
      state->invalid_samples_cnt--;
      MAG_AKM_DEBUG_MSG_1(HIGH,"Set to SNS_DDF_EINVALID_DATA Count=%d",state->invalid_samples_cnt);
    }

    if (state->this_is_first_data) {
      MAG_AKM_DEBUG_MSG_0(HIGH,"This is the first data.");
    }

    /* Use ts_now for timestamping if:
     * 1. this is first polling cycle
     * 2. Somehow prev_ts > ts_now (this should not really happen in polling mode)
     * Note: prev_ts is set to 0 when powerstate attrib is set.
     */
    if(state->time_prev_int == 0 || (state->time_prev_int > ts_now)) {
      sensor_data->timestamp = ts_now;
      sensor_data->end_timestamp = ts_now;
    }
    /* After first polling cycle, use average sampling interval to determine
     * sample timestamps.  This is done to address jitter in polling.
     */
    else
    {
      sampleInterval = ts_now - state->time_prev_int;

      if ( sampleInterval < AKM099xx_LROUNDF(state->avg_sampling_intvl * AKM_SMPLING_INTERVAL_TH_FACTOR) ) {
        sensor_data->timestamp = (sns_ddf_time_t)(state->time_prev_int + AKM099xx_LROUNDF(state->avg_sampling_intvl));
        sensor_data->end_timestamp = sensor_data->timestamp;

      } else {
        sensor_data->timestamp = ts_now;
        sensor_data->end_timestamp = ts_now;
      }
      state->avg_sampling_intvl =
        (state->avg_sampling_intvl * (1.0 - AKM_SAMPLING_INTERVAL_WEIGHT))
        + (sampleInterval * AKM_SAMPLING_INTERVAL_WEIGHT);
    }
  }

  if (state->this_is_first_data) {
    state->this_is_first_data = false;
  }

  /* adjust timestamp */
  if (ts_now < sensor_data->timestamp - state->sample_delay) {
    sensor_data->timestamp = ts_now;
    sensor_data->end_timestamp = ts_now;
  }

  MAG_AKM_DEBUG_MSG_4(
      HIGH,
      "ts_now= %u, timestamp= %u, sampleInterval= %u, average_interval= %d",
      ts_now,
      sensor_data->timestamp,
      sampleInterval,
      AKM099xx_LROUNDF(state->avg_sampling_intvl));

  /* for next event */
  state->time_prev_int = sensor_data->end_timestamp;

  /* Applies the filter delay. */
  sensor_data->timestamp -= state->sample_delay;
  sensor_data->end_timestamp -= state->sample_delay;

  /* send data */
  sns_ddf_smgr_notify_data(state->smgr_handle, sensor_data, 1);

  /* Logging and debug */
  if (sensor_data->status == SNS_DDF_SUCCESS)
  {
     sns_mgt_akm_log_sensor_data(sensor_data, false);
  }

  /* Free memory */
  sns_ddf_mfree_ex(sensor_sample, state->smgr_handle);
  sns_ddf_mfree_ex(sensor_data, state->smgr_handle);

FINALIZE_SAMPLE_SENSOR:
  /* Reset state regardless success */
  if (state->curr_mode == AKM_MAG_SINGLE_MEAS_MODE_099XX) {
    state->curr_mode = AKM_MAG_PWR_DOWN_MODE_099XX;
    state->curr_powerstate = SNS_DDF_POWERSTATE_LOWPOWER;
  }
  state->retry = 0;

#if 0
EXIT_SAMPLE_SENSOR:
  return;
#endif
}

/*==============================================================================
  STATIC FUNCTION:   sns_mgt_akm_log_sensor_data
==============================================================================*/
/*!
  @brief Commit log packet

  @param[in] sensor_data ptr to the sensor_data struct.
  @param[in] fifo_mode   If true, commit a FIFO type log packet.
                         see section 9.1 of ddf driver reference manual.

  @return
   None

  ============================================================================*/
static void sns_mgt_akm_log_sensor_data(
    sns_ddf_sensor_data_s *sensor_data,
    bool                  fifo_mode)
{
  sns_log_sensor_data_pkt_s *log_struct_ptr;
  sns_err_code_e            err_code;
  size_t                    log_size;
  uint16_t                  i;

  if (fifo_mode) {
    log_size = sizeof(sns_log_sensor_data_pkt_s) + (sensor_data->num_samples - 1) * sizeof(int32_t);
  } else {
    log_size = sizeof(sns_log_sensor_data_pkt_s);
  }

  /* Allocate log packet */
  err_code = sns_logpkt_malloc(AKM099xx_LOG_PACKET, log_size, (void**)&log_struct_ptr);

  if ((err_code != SNS_SUCCESS) || (log_struct_ptr == NULL)) {
    /* Do nothing */
    return;
  }

  log_struct_ptr->version   = SNS_LOG_SENSOR_DATA_PKT_VERSION;
  log_struct_ptr->sensor_id = SNS_DDF_SENSOR_MAG;
  log_struct_ptr->vendor_id = SNS_DDF_VENDOR_AKM;

  log_struct_ptr->timestamp      = sensor_data->timestamp;
  log_struct_ptr->end_timestamp  = sensor_data->end_timestamp;
  log_struct_ptr->num_data_types = AKM_MAG099XX_NUM_DATATYPES;

  log_struct_ptr->data[0] = sensor_data->samples[0].sample;
  log_struct_ptr->data[1] = sensor_data->samples[1].sample;
  log_struct_ptr->data[2] = sensor_data->samples[2].sample;

  if (fifo_mode) {
    /* these attributes are needed only for FIFO report */
    /* AKM_MAG099XX_NUM_DATATYPES is never 0, so this division is OK. */
    log_struct_ptr->num_samples   = sensor_data->num_samples / AKM_MAG099XX_NUM_DATATYPES;

    /* Pick up sample values from sns_ddf_sensor_sample_s */
    for (i = 0; i < sensor_data->num_samples; i++) {
      log_struct_ptr->samples[i] = sensor_data->samples[i].sample;
    }
  }

  /* Commit log (also frees up the log packet memory) */
  err_code = sns_logpkt_commit(AKM099xx_LOG_PACKET, log_struct_ptr);
  if (err_code != SNS_SUCCESS)
  {
    MAG_AKM_DEBUG_MSG_1(ERROR, "sns_logpkt_commit error = 0x%X.", err_code);
  }
}

/*==============================================================================
  STATIC FUNCTION:   sns_mgt_akm_is_fifo_overflow
==============================================================================*/
/*!
  @brief Called to check if the FIFO overflows or not.

  @param[in] *state   ptr to the driver state structure
  @param[in] *result   pointer to store the result of this function

  @return
   SNS_DDF_SUCCESS when succeeded. Otherwise an appropriate error code.

  ============================================================================*/
static sns_ddf_status_e sns_mgt_akm_is_fifo_overflow(
  sns_dd_mag_akm099xx_state_s *state,
  bool                        *result)
{
  sns_ddf_status_e status;
  uint8_t          reg_st1;
  uint8_t          out;

  /* Input sanity check */
  if (state == NULL || result == NULL) {
    return SNS_DDF_EINVALID_PARAM;
  }

  /* Read ST1 first and check if the FIFO buffer overflows. */
  if ((status = sns_ddf_read_port(
           state->port_handle,
           AKM_MAG_REG_ADDR_STATUS1_099XX,
           &reg_st1,
           DDF_READ_ONE_BYTE,
           &out)) != SNS_DDF_SUCCESS) {
    MAG_AKM_DEBUG_MSG_1(HIGH, "Reading a port failed. status = %d.", status);
    return status;
  }

  if ((reg_st1 & AKM_MAG_DOR_BIT_MASK) != 0) {
    *result = true;
  } else {
    *result = false;
  }

  return status;
}

/*==============================================================================
  STATIC FUNCTION:   sns_akm_validate_timestamps
==============================================================================*/
/**
* @brief Validate timestamps, then adjust timestamp.
*
* @detail
* - Description 1
* - Description 2
*
* @param[in]  cur_time       -
* @param[in]  last_timestamp -
* @param[in]  num_samples    -
* @param[in]  est_interval   -
* @param[in/out] start_time  -
* @param[in/out] end_time    -
*
* @return
*  None.
*
*/
/*============================================================================*/
static void sns_akm_validate_timestamps(
    sns_ddf_time_t cur_time,
    sns_ddf_time_t last_timestamp,
    int32_t        num_samples,
    float         est_interval,
    sns_ddf_time_t *restrict start_time,
    sns_ddf_time_t *restrict end_time,
    sns_ddf_time_t delay)
{
  sns_ddf_time_t orig_start_time = *start_time;
  sns_ddf_time_t orig_end_time = *end_time;
  sns_ddf_time_t diff_endtime;

/*
  if(last_timestamp != 0) {
    if( (sns_ddf_time_t)(last_timestamp + est_interval*3/2) < *start_time ) {
      *start_time = (sns_ddf_time_t)(last_timestamp + est_interval*3/2);
    }
    if( (sns_ddf_time_t)(last_timestamp + est_interval*3/4) > *start_time ) {
      *start_time = (sns_ddf_time_t)(last_timestamp + est_interval*3/4);
    }
  }
*/

  /* check if the end_timestamp is bigger than the cur_time */
  if ( (*end_time-delay)>cur_time  ) {
    diff_endtime = (*end_time - delay) - cur_time;

    /* update end_time */
    *end_time = MIN(*end_time, cur_time);

    /* update start_time */
    if( diff_endtime < AKM099xx_LROUNDF(est_interval / 2) ) {
      *start_time -= diff_endtime;
    } else {
      *start_time -= AKM099xx_LROUNDF(est_interval / 2);
    }
    MAG_AKM_DEBUG_MSG_1(ERROR, "akm Validate timestamp:adjusting end time to current time by :%u", (*end_time-delay)-cur_time);
  }

  if( *end_time < (sns_ddf_time_t)(cur_time - AKM099xx_LROUNDF(est_interval * 2) ) ) {
    *end_time = cur_time;
    MAG_AKM_DEBUG_MSG_1(ERROR, "akm Validate timestamp:adjusting end time bigger :%u", *end_time-orig_end_time);
  }

  if( *start_time >= *end_time ) {
    *start_time = *end_time;
  }

  if( *start_time == *end_time && num_samples > 1 ) {
    MAG_AKM_DEBUG_MSG_0(ERROR, "Validate timestamp error");
  } else if (num_samples == 1) {
    *start_time = *end_time;
  }
  if( *start_time != orig_start_time ||
      *end_time != orig_end_time ) {
    MAG_AKM_DEBUG_MSG_4(HIGH, "Adjusted timestamps start %u-->%u end %u-->%u",
                        orig_start_time, *start_time,
                        orig_end_time, *end_time );
  }
}


/*==============================================================================

  COMMON FUNCTION:   sns_mgt_akm_set_operation_mode_099xx

==============================================================================*/
/**
* @brief Program the measurement mode on AKM099XX
*
* @detail
* - Prog the CNTL1 and CNTL2 register for measurement mode.
* - curr_mode is set internally, but pwr_state is not set.
* - AK0991X does not permit to set to measurement mode from other than
*   power-down mode.
*
* @param[in] *state - ptr to the driver state
* @param[in] mode   - next mode
*
* @return
*  The error code definition within the DDF
*  SNS_DDF_SUCCESS on success;
*  Otherwise SNS_DDF_EDEVICE, SNS_DDF_EBUS, SNS_DDF_EINVALID_PARAM, or
*  SNS_DDF_EFAIL to indicate an error has occurred.
*/
/*============================================================================*/
sns_ddf_status_e sns_mgt_akm_set_operation_mode_099xx(
  sns_dd_mag_akm099xx_state_s *state,
  mag099xx_operation_mode_e   mode)
{
  uint8_t write_buffer[2];
  uint8_t out;
  sns_ddf_status_e status = SNS_DDF_SUCCESS;

  const uint8_t CNTL1_IDX = 0;
  const uint8_t CNTL2_IDX = 1;

  /* Input sanity check */
  if (state == NULL) {
    return SNS_DDF_EINVALID_PARAM;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_1(LOW, "set_operation start. mode=%d", mode);
#endif

  /* Ignore if same mode is set */
  if (state->curr_mode == mode) {
    MAG_AKM_DEBUG_MSG_1(MED, "Skip because same mode(%d) is specified.", mode);
    return SNS_DDF_SUCCESS;
  }

  /* default setting */
  write_buffer[CNTL1_IDX] = AKM_MAG099XX_NSF_BIT_MASK;
  write_buffer[CNTL2_IDX] = mode;

  /* additional setting */
  switch (mode) {
    case AKM_MAG_CONT_MEAS_MODE_1_099XX:
    case AKM_MAG_CONT_MEAS_MODE_2_099XX:
    case AKM_MAG_CONT_MEAS_MODE_3_099XX:
    case AKM_MAG_CONT_MEAS_MODE_4_099XX:
    case AKM_MAG_CONT_MEAS_MODE_5_099XX:
    case AKM_MAG_CONT_MEAS_MODE_6_099XX:
      if (state->water_mark > 0) {
        /* Watermark bits definition: 0x00 -> 1 step, 0x01 -> 2 step, ... */
        write_buffer[CNTL1_IDX] |= (state->water_mark - 1);
        write_buffer[CNTL2_IDX] |= AKM_MAG099XX_FIFO_BIT_MASK;
      }
      break;

    case AKM_MAG_PWR_DOWN_MODE_099XX:
    case AKM_MAG_SINGLE_MEAS_MODE_099XX:
    case AKM_MAG_SELF_TEST_MODE_099XX:
    case AKM_MAG_FUSE_ROM_ACCESS_MODE_099XX:
      break;

    default:
      return SNS_DDF_EINVALID_PARAM;
  }

  /*========================================================
   * Do not use multiple byte write. It doesn't work on SPI.
   */

  if (state->has_nsf || (state->device_fifo_size > 0)) {
    if ((status = sns_ddf_write_port(
            state->port_handle,
            AKM_MAG_REG_ADDR_CNTL1_099XX,
            &write_buffer[CNTL1_IDX],
            DDF_WRITE_ONE_BYTE,
            &out)) != SNS_DDF_SUCCESS) {
      MAG_AKM_DEBUG_MSG_1(HIGH, "Writing CNTL1 failed. status=%d.", status);
      return status;
    }
  }

  if ((status = sns_ddf_write_port(
           state->port_handle,
           AKM_MAG_REG_ADDR_CNTL2_099XX,
           &write_buffer[CNTL2_IDX],
           DDF_WRITE_ONE_BYTE,
           &out)) != SNS_DDF_SUCCESS) {
    MAG_AKM_DEBUG_MSG_1(HIGH, "Writing CNTL2 failed. status=%d.", status);
    return status;
  }

  /* set current time to previous int. */
  if (mode != AKM_MAG_PWR_DOWN_MODE_099XX) {
    if(state->invalid_samples_cnt > 0) {
      state->time_prev_int = sns_ddf_get_timestamp();
      state->time_last_report_sample = state->time_prev_int;
    }
    state->this_is_first_data = true;
    MAG_AKM_DEBUG_MSG_1(HIGH, "after power_down mode change, time_prev_int=%d.", state->time_prev_int);
  }

  state->curr_mode = mode;

  /* 100 usec delay is needed after set operation mode */
  sns_ddf_delay(USEC_TIME_TO_ACTIVE);

  return SNS_DDF_SUCCESS;
}

/*==============================================================================

  COMMON FUNCTION:   sns_mgt_akm_sample_fifo_099xx

==============================================================================*/
/*!
  @brief Called when the FIFO WM interrupt heppens or trigger_fifo_data()
  is called.

  @note

  @param[in] *state       ptr to the driver state structure
  @param[in] num_samples  the number of samples that should be read from the FIFO
  @param[in] ts_now       Time at which this function is called.
  @param[in] in_interrupt_handler  True if this function is called from
                                   interrupt handler.

  @return
   SNS_DDF_SUCCESS when succeeded. Otherwise an appropriate error code.

  ============================================================================*/
sns_ddf_status_e sns_mgt_akm_sample_fifo_099xx(
  sns_dd_mag_akm099xx_state_s *state,
  uint16_t                    num_samples,
  sns_ddf_time_t              ts_now,
  bool                        in_interrupt_handler)
{
  sns_ddf_status_e        status;
  sns_ddf_sensor_data_s   *sensor_data;
  sns_ddf_sensor_data_s   *sensor_data_ex = NULL;
  sns_ddf_sensor_sample_s *sensor_sample;
  uint16_t                samples = 0;
  uint32_t                total_samples;
  uint32_t                sampleInterval = 0;
  float                   prev_average_interval = 0.0f;

  /* Input sanity check */
  if (state == NULL) {
    return SNS_DDF_EINVALID_PARAM;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_2(
      LOW,
      "sample_fifo: num_sample=%u, in_irq=%u",
      num_samples, (in_interrupt_handler ? 1 : 0));
#endif

  if (state->device_fifo_size == 0) {
    /* current device does not have fifo. */
    return SNS_DDF_EDEVICE;
  }

  /* Number of the sample should be read is not specified.
   * In this case, the DD reads valid samples as many as possible. */
  if (num_samples == FLUSH_FIFO) {
    samples = state->device_fifo_size;
  } else {
    samples = num_samples;
  }

  /* after read_sensor succeeds,
   * sensor_data and sensor_sample must be free when exit this function.
   */
  if ((status = sns_mgt_akm_read_sensor(
          state,
          &sensor_data,
          &sensor_sample,
          samples,
          NULL)) != SNS_DDF_SUCCESS) {
    /* error message reporting is already done in the function.
     * So, just exit this function.
     */
    goto FINALIZE_SAMPLE_FIFO;
  }

  /* calculate the number of total samples
   * (total samples means a set of X,Y,Z data)
   * AKM_MAG099XX_NUM_DATATYPES is never 0, so this division is OK.
   */
  total_samples = sensor_data->num_samples / AKM_MAG099XX_NUM_DATATYPES;


  /* num_samples=0 may happen, because this function is called when
   * flushing FIFO data. The operation is usually asynchronously.
   * In this case (incomplete data), discard the data.
   */
  if (total_samples == 0) {
    goto FREE_SAMPLE_FIFO;
  }

  /* update total number of samples, since last interrupt */
  if ( state->this_is_first_data && (!in_interrupt_handler) ) {
    /* still no interrupt */
    state->num_samples_since_prev_int = total_samples;
  }
  else{
    state->num_samples_since_prev_int += total_samples;
  }

  /* Calculate time stamp. The unit of timestamp is 'tick'
   * The implementation is described in section 4.3.1.1 of 80-N4080-1_U.
   *
   * On receiving more sample than WM setting, use ODR  to calculate sample interval
   * FIFO mode does not work with single measurement mode, so sample_delay value must
   * be set when ODR is set by calling set_attrib function.
   *
   * WM interrupt happens when samples in FIFO is greater than set WM. So we need to
   * check for (total_samples-1) to use current ts for timestamping samples.
   */
  if (in_interrupt_handler) {      // In FIFO + WM Interrupt
    /* When handling interrupts, this driver use watermark interrupt timestamp
     * to determine interval. Here, ts_now is the time latest interrupt fired.
     */
    /* avg_sampling_intvl is used when asynchronous data acquisition.
     * Ex. trigger_fifo_data is called for some reason. also to smooth jitter
     */

    /* set to invalid data at the first few samples */
    if (state->invalid_samples_cnt > 0) {
        sensor_data->status = SNS_DDF_EINVALID_DATA;
        state->invalid_samples_cnt--;
        MAG_AKM_DEBUG_MSG_1(HIGH,"Set to SNS_DDF_EINVALID_DATA Count=%d",state->invalid_samples_cnt);
    }

    if (state->this_is_first_data) {
        MAG_AKM_DEBUG_MSG_0(HIGH,"This is the first data.");
    }

    /* Update time_prev_int and time_last_report_sample time for delay of the wm is changed. */
    if(total_samples > 1 && state->this_is_first_data && sensor_data->status != SNS_DDF_EINVALID_DATA) {
        state->time_prev_int += AKM_DELAY_SET_WM_TICK_TIME;
        state->time_last_report_sample += AKM_DELAY_SET_WM_TICK_TIME;
        MAG_AKM_DEBUG_MSG_0(HIGH,"Update time_prev_int and time_last_report_sample time for delay of the wm is changed.");
    }

    if ( ts_now > state->time_prev_int) {
      sampleInterval = (uint32_t)((ts_now - state->time_prev_int) / state->num_samples_since_prev_int);
    } else {
      sampleInterval = AKM_SAMPLING_INTERVAL_TH;
    }
    if (sampleInterval < AKM_SAMPLING_INTERVAL_TH) {
      sampleInterval = AKM_SAMPLING_INTERVAL_TH;
    }

    prev_average_interval = state->avg_sampling_intvl;

    state->avg_sampling_intvl = (state->avg_sampling_intvl * (1.0 - AKM_SAMPLING_INTERVAL_WEIGHT))
      + (sampleInterval * AKM_SAMPLING_INTERVAL_WEIGHT);

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_4(
      MED,
      "ts_now= %u, last_report_sample= %u, sampleInterval= %u avg_sampling_intvl= %d",
      ts_now,
      state->time_last_report_sample,
      sampleInterval,
      AKM099xx_LROUNDF(state->avg_sampling_intvl));
#endif

    if (sensor_data->status != SNS_DDF_EINVALID_DATA &&
      sampleInterval < AKM099xx_LROUNDF(prev_average_interval * AKM_SMPLING_INTERVAL_TH_FACTOR)) {
      sensor_data->timestamp = (sns_ddf_time_t)(state->time_prev_int +
          AKM099xx_LROUNDF(prev_average_interval) * (1 + state->num_samples_since_prev_int - total_samples));
      if (total_samples > 1) {
        sensor_data->end_timestamp = (sns_ddf_time_t)(state->time_prev_int +
            AKM099xx_LROUNDF(prev_average_interval) * state->num_samples_since_prev_int);
      } else {
        sensor_data->end_timestamp = sensor_data->timestamp;
      }
#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
      MAG_AKM_DEBUG_MSG_4(HIGH,
                          "ts_now is incorrect, ts_now= %u, time_prev_in= %u, prev_average_interval= %d, avg_sampling_intvl= %d",
                          ts_now,
                          state->time_prev_int,
                          AKM099xx_LROUNDF(prev_average_interval),
                          AKM099xx_LROUNDF(state->avg_sampling_intvl));
#endif
    } else {
      if(total_samples>1) {
        sensor_data->timestamp = (sns_ddf_time_t)(state->time_last_report_sample + AKM099xx_LROUNDF(state->avg_sampling_intvl));
      } else {
        sensor_data->timestamp = ts_now;
      }
      sensor_data->end_timestamp = ts_now;
    }

    /* for next event */
    if (state->this_is_first_data) {
      state->this_is_first_data = false;
      state->time_prev_int = ts_now;
    }
    else{
        state->time_prev_int = sensor_data->end_timestamp;
    }
    //    state->time_prev_int = ts_now;
    state->num_samples_since_prev_int = 0;
    /* for later validation */
    sampleInterval = AKM099xx_LROUNDF(state->avg_sampling_intvl);
  } else {
    sampleInterval = AKM099xx_LROUNDF(state->avg_sampling_intvl);
    /* Update ts_now, since it may have taken a while to read the FIFO */
    ts_now = sns_ddf_get_timestamp();
    /* At the first time right after measurement started, time_prev_int is the time
     * set_attrib SNS_DDF_ATTRIB_FIFO is called, and avg_sampling_intvl is calculated
     * from set ODR.
     */
    sensor_data->timestamp = state->time_last_report_sample + sampleInterval;
    sensor_data->end_timestamp = state->time_last_report_sample + (sampleInterval * total_samples);

    MAG_AKM_DEBUG_MSG_0(MED, "FIFO data is get asynchronously.");
  }

  sns_akm_validate_timestamps( sns_ddf_get_timestamp(),
                               state->time_last_report_sample,
                               total_samples,
                               sampleInterval,
                               &sensor_data->timestamp,
                               &sensor_data->end_timestamp,
                               state->sample_delay);

  MAG_AKM_DEBUG_MSG_4(
      MED,
      "After Validate: timestamp= %u, end_timestamp= %u, total_samples= %d, time_last_report_sample= %u",
      sensor_data->timestamp,
      sensor_data->end_timestamp,
      total_samples,
      state->time_last_report_sample);


  /* For next time */
  state->time_last_report_sample = sensor_data->end_timestamp;

  /* Reports and logs if sensor_data_ex has items. */
  if (sensor_data_ex != NULL) {
    /* Applies the filter delay. */
    sensor_data_ex->timestamp -= state->sample_delay;
    sensor_data_ex->end_timestamp -= state->sample_delay;
    /* Sends data to SMGR. */
    sns_ddf_smgr_notify_data(state->smgr_handle, sensor_data_ex, 1);
   /* Logs packets. */
    if (sensor_data_ex->status == SNS_DDF_SUCCESS) {
      sns_mgt_akm_log_sensor_data(sensor_data_ex, true);
    }

  }

  /* Applies the filter delay. */
  sensor_data->timestamp -= state->sample_delay;
  sensor_data->end_timestamp -= state->sample_delay;

  if(sensor_data->status != SNS_DDF_EINVALID_DATA){
    MAG_AKM_DEBUG_MSG_4(
        MED,
        "After apply filter delay sent to SMGR: timestamp= %u, end_timestamp= %u ts_now= %u now= %u",
        sensor_data->timestamp,
        sensor_data->end_timestamp,
        ts_now,
        sns_ddf_get_timestamp()
        );
  }

  /* Sends data to SMGR */
  sns_ddf_smgr_notify_data(state->smgr_handle, sensor_data, 1);
  /* logs packet */
  if (sensor_data->status == SNS_DDF_SUCCESS) {
    sns_mgt_akm_log_sensor_data(sensor_data, true);
  } else {
    MAG_AKM_DEBUG_MSG_0(ERROR, "Sensor status incorrect! no 0x14c1");
  }

  /* Free memory if it is allocated. */
  if (sensor_data_ex != NULL) {
    sns_ddf_mfree_ex( sensor_data_ex, state->smgr_handle);
  }

FREE_SAMPLE_FIFO:
  /* Free memory */
  sns_ddf_mfree_ex(sensor_sample, state->smgr_handle);
  sns_ddf_mfree_ex(sensor_data, state->smgr_handle);

FINALIZE_SAMPLE_FIFO:
  return status;
}

/*===========================================================================

FUNCTION:   sns_dd_akm099xx_handle_irq

===========================================================================*/
/**
* @brief Called in response to an interrupt for this driver.
*
* @note This function will be called within the context of the SMGR task,
*       *not* the ISR.
*
* @param[in] dd_handle  Handle to a driver instance.
* @param[in] gpio_num   GPIO number that triggered this interrupt.
* @param[in] timestamp  Time at which interrupt happened.
*/
/*=========================================================================*/
void sns_dd_akm099xx_handle_irq(
    sns_ddf_handle_t  dd_handle,
    uint32_t          gpio_num,
    sns_ddf_time_t    timestamp)
{
  /* Read status, handle interrupt, read data and return data to SMGR */
  sns_dd_mag_akm099xx_state_s *state = (sns_dd_mag_akm099xx_state_s *)dd_handle;
  sns_ddf_status_e            status;

  if (state == NULL) {
    return;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_1(LOW, "handle_irq: gpio_num=%d", gpio_num);
#endif

  if (gpio_num == state->gpio1) {
    /* In case the DRI is a FIFO WM event. */
    if (state->water_mark > 0) {
      bool isFifoOverflow;

      /* FIFO is enabled and the interrupt means number of data in FIFO exceeded the WM */
      if ((status = sns_ddf_smgr_notify_event(
              state->smgr_handle,
              SNS_DDF_SENSOR_MAG,
              SNS_DDF_EVENT_FIFO_WM_INT)) != SNS_DDF_SUCCESS) {
        MAG_AKM_DEBUG_MSG_1(HIGH, "FIFO WM event notify failed. Status = %d.", status);
      }

      /* Check FIFO overflow */
      if ((status = sns_mgt_akm_is_fifo_overflow(state, &isFifoOverflow)) != SNS_DDF_SUCCESS) {
        MAG_AKM_DEBUG_MSG_1(HIGH, "FIFO overflow check failed. Status = %d.", status);
      } else {
        if (isFifoOverflow) {
          if ((status = sns_ddf_smgr_notify_event(
                  state->smgr_handle,
                  SNS_DDF_SENSOR_MAG,
                  SNS_DDF_EVENT_FIFO_OVERFLOW)) != SNS_DDF_SUCCESS) {
            MAG_AKM_DEBUG_MSG_1(HIGH, "FIFO overflow event notify failed. Status = %d.", status);
          }
        }
      }

      /* Read out sensor data from FIFO and notify to SMGR */
      if(state->water_mark < 2){
        sns_mgt_akm_sample_fifo_099xx(state, FLUSH_FIFO, timestamp, true);
      }else{
        sns_mgt_akm_sample_fifo_099xx(state, state->water_mark, timestamp, true);
      }
    } else {
      sns_mgt_akm_sample_sensor(state, timestamp, false);
    }
  }
}

/*===========================================================================

FUNCTION:   sns_dd_akm099xx_handle_timer

===========================================================================*/
/**
* @brief Called when the timer set by this driver has expired. This must be
*        the callback function submitted when initializing a timer.
*
* @note This will be called within the context of the Sensors Manager task.
*
* @param[in] dd_handle  Handle to a driver instance.
* @param[in] arg        The argument submitted when the timer was set.
*
*/
/*=========================================================================*/
void sns_dd_akm099xx_handle_timer(
    sns_ddf_handle_t dd_handle,
    void* arg)
{
  sns_dd_mag_akm099xx_state_s *state = (sns_dd_mag_akm099xx_state_s *)dd_handle;

  if (state == NULL) {
    return;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_0(LOW, "handle_timer");
#endif

  /* In 80-N4080-1_T, section 6.4.3
   * the driver should handle the case where this function is called
   * erroneously after stopping.
   */

  if (state->curr_powerstate == SNS_DDF_POWERSTATE_ACTIVE) {
    /* ACTIVE status means that the device is still in measurement */
    sns_mgt_akm_sample_sensor(state, sns_ddf_get_timestamp(), true);
  }
}

/*===========================================================================

FUNCTION:   sns_dd_akm099xx_get_data

===========================================================================*/
/**
* @brief Retrieves a single set of sensor data.
*
* @param[in]  dd_handle    Handle to a driver instance.
* @param[in]  sensors      List of sensors for which data is requested.
* @param[in]  num_sensors  Number of elements in @a sensors.
* @param[in]  memhandler   Memory handler used to dynamically allocate
*                          output parameters, if applicable.
* @param[out] data         Sampled sensor data. The number of elements must
*                          match @a num_sensors.
*                          This parameter is ignored by this async driver.
*
* @return SNS_DDF_SUCCESS if data was populated successfully. If any of the
*         sensors queried are to be read asynchronously SNS_DDF_PENDING is
*         returned and data is via @a sns_ddf_smgr_data_notify() when
*         available. Otherwise a specific error code is returned.
*/
/*=========================================================================*/
sns_ddf_status_e sns_dd_akm099xx_get_data(
    sns_ddf_handle_t        dd_handle,
    sns_ddf_sensor_e        sensors[],
    uint32_t                num_sensors,
    sns_ddf_memhandler_s*   memhandler,
    sns_ddf_sensor_data_s*  data[])
{
  sns_dd_mag_akm099xx_state_s *state = (sns_dd_mag_akm099xx_state_s *)dd_handle;
  sns_ddf_status_e            status = SNS_DDF_SUCCESS;

  if (state == NULL) {
    return SNS_DDF_EINVALID_PARAM;
  }
#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_2(
      LOW,
      "get_data: powerstate=%d, mode=%d",
      state->curr_powerstate,
      state->curr_mode);
#endif

  if (state->curr_powerstate == SNS_DDF_POWERSTATE_LOWPOWER) {
    /* sensor starts measuring, i.e. powerstate must be ACTIVE */
    state->curr_powerstate = SNS_DDF_POWERSTATE_ACTIVE;
    if ((status = sns_mgt_akm_set_operation_mode_099xx(
             state,
             AKM_MAG_SINGLE_MEAS_MODE_099XX)) != SNS_DDF_SUCCESS) {
      /* set_operation_mode failed */
      state->curr_powerstate = SNS_DDF_POWERSTATE_LOWPOWER;
      return status;
    }

    /* Reset retry number first */
    state->retry = 0;

    if ((status = sns_ddf_timer_start(
             state->sns_dd_tmr_obj,
             state->time_for_measurement)) != SNS_DDF_SUCCESS) {
      MAG_AKM_DEBUG_MSG_1(HIGH, "Setting timer failed. Status = %d.", status);
      /* timer start failed */
      state->curr_powerstate = SNS_DDF_POWERSTATE_LOWPOWER;
      return status;
    }
    /* Mag returns data asynchronously. Hence set PENDING status to return
     * to Sensor Manager
     */
    status = SNS_DDF_PENDING;
  } else if (state->curr_powerstate == SNS_DDF_POWERSTATE_ACTIVE) {
    switch (state->curr_mode) {
      case AKM_MAG_SINGLE_MEAS_MODE_099XX:
        /* This is added for completeness and making SMGR aware that it first
         * needs to change the HW device state to active and then get data which
         * in case of mag doesn't actually make a difference
         */
        status = SNS_DDF_PENDING;
        break;

      case AKM_MAG_CONT_MEAS_MODE_1_099XX:
      case AKM_MAG_CONT_MEAS_MODE_2_099XX:
      case AKM_MAG_CONT_MEAS_MODE_3_099XX:
      case AKM_MAG_CONT_MEAS_MODE_4_099XX:
      case AKM_MAG_CONT_MEAS_MODE_5_099XX:
      case AKM_MAG_CONT_MEAS_MODE_6_099XX:
        /* Reset retry number first */
        state->retry = 0;
        /* Sensor is already working so a measurement data can be read out
         * directory now. But to reduce source code, use timer to retrieve a data.
         */
        if ((status = sns_ddf_timer_start(
                state->sns_dd_tmr_obj,
                USEC_TIME_FOR_TRIGGER_TIMER_HANDLER)) != SNS_DDF_SUCCESS) {
          MAG_AKM_DEBUG_MSG_1(HIGH, "Setting timer failed. Status = %d.", status);
          return status;
        }
        status = SNS_DDF_PENDING;
        break;

      case AKM_MAG_SELF_TEST_MODE_099XX:
      case AKM_MAG_FUSE_ROM_ACCESS_MODE_099XX:
        /* cannot get data */
        status = SNS_DDF_EDEVICE_BUSY;
        break;

      case AKM_MAG_PWR_DOWN_MODE_099XX:
        /* When power_state is ACTIVE, curr_mode must not be power_down. */
        status = SNS_DDF_EINVALID_PARAM;
        break;
    }
  } else {
      MAG_AKM_DEBUG_MSG_1(HIGH, "Unknown Power Status = %d.", state->curr_powerstate);
      return SNS_DDF_EFAIL;
  }

  return status;
}

/*===========================================================================

FUNCTION:   sns_dd_akm099xx_trigger_fifo_data

===========================================================================*/
/**
* @brief Retrieves a set of sensor data. Asynchronous API
*
* @note If a sensor has failed or
*       isn't available, @a sns_ddf_sensor_data_s.status must be used to
*       reflect this status.
*
* @param[in]  dd_handle     Handle to a driver instance.
* @param[in]  sensor        sensor for which data is requested.
*
* @param[in]  num_samples   number of samples to retrieve as available. Drain the FIFO if value is set to Zero.
* @param[in]  trigger now   trigger notify fifo data now or
*       later when trigger_now is set to true.
*
*
* @return SNS_DDF_SUCCESS   if data was populated successfully.
*         via sns_ddf_smgr_data_notify() or if trigger_now is
*         set to false; Otherwise a specific error code is
*         returned.
*
*/
/*=========================================================================*/
sns_ddf_status_e sns_dd_akm099xx_trigger_fifo_data(
    sns_ddf_handle_t         dd_handle,
    sns_ddf_sensor_e         sensor,
    uint16_t                 num_samples,
    bool                     trigger_now)
{
  sns_ddf_status_e status = SNS_DDF_SUCCESS;
  sns_dd_mag_akm099xx_state_s *state = (sns_dd_mag_akm099xx_state_s *)dd_handle;

  /* Input sanity check */
  if (state == NULL) {
    return SNS_DDF_EINVALID_PARAM;
  }

  if (sensor != SNS_DDF_SENSOR_MAG) {
    return SNS_DDF_EINVALID_PARAM;
  }

#ifdef SNSD_MAG_AKM099XX_DEBUG_FUNC_UIMG
  MAG_AKM_DEBUG_MSG_2(
      LOW, "trigger_fifo_data: trigger_now = %u num_samples = %u",
      trigger_now, num_samples);
#endif

  /* "curr_odr > 0" means that the device is in continuous measurement mode
   * This condition is essential because, if device is in powerdown mode,
   * INV bit may not work as expected.
   */
  if (trigger_now && (state->curr_odr > 0)) {
    if ((status = sns_mgt_akm_sample_fifo_099xx(
            state,
            num_samples,
            sns_ddf_get_timestamp(),
            false)) != SNS_DDF_SUCCESS) {
      MAG_AKM_DEBUG_MSG_1(HIGH, "Reading FIFO data failed. Status = %d.", status);
      return status;
    }
  }

  return status;
}


/*==============================================================================

  Callbacks setting

==============================================================================*/
sns_ddf_driver_if_s AKM099xx_FIFO_DD_IF =
{
    .init              = &sns_dd_akm099xx_init,
    .get_data          = &sns_dd_akm099xx_get_data,
    .set_attrib        = &sns_dd_akm099xx_set_attrib,
    .get_attrib        = &sns_dd_akm099xx_get_attrib,
    .handle_timer      = &sns_dd_akm099xx_handle_timer,
    .handle_irq        = &sns_dd_akm099xx_handle_irq,
    .reset             = &sns_dd_akm099xx_reset,
    .run_test          = &sns_dd_akm099xx_run_test,
    .enable_sched_data = &sns_dd_akm099xx_enable_sched_data,
    .probe             = &sns_dd_akm099xx_probe,
    .trigger_fifo_data = &sns_dd_akm099xx_trigger_fifo_data
};
