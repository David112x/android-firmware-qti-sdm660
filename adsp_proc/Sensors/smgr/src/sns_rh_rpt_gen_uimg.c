/*=============================================================================
  @file sns_rh_rpt_gen_uimg.c

  Implementation of Report Generation functions that execute in microImage

******************************************************************************
* Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
******************************************************************************/

/* $Header: //components/rel/ssc.slpi/2.2/smgr/src/sns_rh_rpt_gen_uimg.c#1 $ */
/* $DateTime: 2017/04/17 22:20:39 $ */
/* $Author: pwbldsvc $ */

/*============================================================================
  EDIT HISTORY FOR FILE

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2017-03-13  sd   Let num of samples in one indication be multiple of num of items in a report if possible
  2017-02-09  sd   Allow multiple items in one indication for event sensor
  2016-10-05  bd   Corrected number of indications for subHz requests
  2016-06-28  pn   - Fixed interpolation init bug causing initial samples to be discarded
                   - Fixed occasional data gap when chosen ODR is lower than requested rate
                   - Fixed missing indication for reports with streaming and event sensors
  2016-06-21  pn   Fixed forever loop while generating Periodic-like indications				   
  2016-06-08  jtl  Fill out SamplingRate field in periodic indications.
  2016-06-03  jtl  Save item_ptr->quality during while loops in case SMGR changes it
                   Initialize interpolator based on S4S schedule
  2016-05-18  pn   Periodic-like Buffering report are treated the same as Batching reports
  2016-04-20  pn   Fixed uneven distribution of samples on indication train
  2016-04-01  pn   Fixed unintentional delay of first indication of streaming reports
  2016-01-14  pn   Considers possibility of sample accumulation in Periodic-like reports
  2015-12-29  pn   Ignores sample status when processing it for report generation
  2015-10-28  bd   Use number of samples instead of end_timestamp to limit sample cnt
  2015-10-19  pn   Report timer is used only for event-sensor batching
  2015-09-29  pn   Put back the check to prevent indication message overflow
  2015-09-24  pn   Code cleanup
  2015-09-18  pn   Updated debug loggings
  2015-09-11  pn   Uses correct indication type after QMI connection resumes
  2015-09-10  pn   Uses first valid sample as first interpolated sample
  2015-09-03  bd   Separate batchbuff for uimg and bimg  
  2015-08-24  bd   Code cleanup  
  2015-08-24  bd   Depot size reduction  
  2015-08-21  bd   Code cleanup
  2015-08-13  bd   Fixed uimage switching when batching big image sensors
  2015-07-30  bd   Added batching feature
  2015-07-09  ps   fix klocwork errors
  2015-06-19  pn   Takes into account filter delay when preparing for next report
  2015-06-15  pn   Updated sns_rh_rpt_gen_save_indication() signature
  2015-05-27  bd   Indication flow control in SMGR
  2015-05-08  pn   Updates report state for reports with only event sensors
  2015-04-25  pn   Fixed sample delivery latency 
  2015-04-09  pn   Added support for 56-bit timestamp
  2015-03-20  pn   Allows first sample to be interpolated from a single sample
  2015-02-24  pn   Updated QDSS events
  2015-02-17  pn   Uses latest samples for Periodic/periodic-like reports
  2015-01-22  BD   Changed the way of putting functions in uImage to use sections
  2014-12-18  pn   - Fixed wrong indication type
                   - Fixed bigImage depot access when generating Periodic indications
  2014-12-08  pn   Fixed sample count estimates for Bufferring reports
  2014-11-24  pn   Corrected ts_last_rpt_sent for multi-sensor reports
  2014-11-06  pn   Updates report state when scheduling next Buffering indications
  2014-10-28  jms  Rpt sending with effective_rate_hz=0 fix
  2014-10-28  pn   Immediately requeues Periodic report until all samples are sent
  2014-10-28  jc   Skip the first sample in report if invalid
  2014-10-22  pn   Added debug messages for Buffering reports
  2014-10-10  pn   Only locks depot if it's going to be accessed
  2014-10-09  pn   Correctly updates report schedule
  2014-10-06  jc   Grab mutex before accessing depot
  2014-10-02  pn   Stays in big-image until report generation is done if 
                   using big-image depots
  2014-09-30  MW   Fixed end_ts for event sensors in 
                   sns_rh_rpt_gen_send_buffering_indications()
  2014-09-25  pn   - Uses depot selected for report item
                   - copies samples from uImage depot when generating indications
  2014-09-23  pn   Added QDSS logging
  2014-09-04  pn   Changed how the next indication is scheduled
  2014-08-21  tc   Allowed the reassignment of the FIRST_IND indType to adjust
                   for unsent first indications.
  2014-08-18  pn   Removed KW error
  2014-08-15  tc   Fixed overflow condition for CurrentRate in periodic ind
  2014-07-31  pn   Obsoleted FEATURE_TEST_DRI
  2014-07-21  pn   Added support for event_gated_buffering
  2014-06-16  pn   Replaced FLAGS_SAMPLES_SENT_B with boolean samples_sent
  2014-06-16  pn   Removed references to unused circular buffer
  2014-05-12  tc   Forced the separation of buffered subHz-sampled data into
                   back-to-back indications with each indication carrying only
                   one sample.
  2014-04-29  pn   Initial version

============================================================================*/

#define __SNS_MODULE__ SNS_RH

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "sns_osa.h"
#include "sns_memmgr.h"

#include "sns_smgr_main.h"
#include "sns_smgr.h"
#include "sns_smgr_util.h"
#include "sns_rh_batchbuff.h"
#include "sns_rh_main_uimg.h"
#include "sns_rh_mr.h"
#include "sns_rh_rpt_gen.h"
#include "sns_rh_sample_proc_uimg.h"
#include "sns_rh_sol.h"
#include "sns_rh_util.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
//#define SNS_SMGR_B2B_IND_DEBUG
#ifdef SNS_SMGR_B2B_IND_DEBUG
#define SNS_SMGR_B2B_IND_DBG1 SNS_SMGR_PRINTF1
#define SNS_SMGR_B2B_IND_DBG2 SNS_SMGR_PRINTF2
#define SNS_SMGR_B2B_IND_DBG3 SNS_SMGR_PRINTF3
#define SNS_SMGR_B2B_IND_DBG4 SNS_SMGR_PRINTF4
#else
#define SNS_SMGR_B2B_IND_DBG1(level,msg,p1)
#define SNS_SMGR_B2B_IND_DBG2(level,msg,p1,p2)
#define SNS_SMGR_B2B_IND_DBG3(level,msg,p1,p2,p3)
#define SNS_SMGR_B2B_IND_DBG4(level,msg,p1,p2,p3,p4)
#endif

//#define SNS_SMGR_REPORT_DEBUG
#ifdef SNS_SMGR_REPORT_DEBUG
#define SNS_SMGR_REPORT_DBG1 SNS_SMGR_PRINTF1
#define SNS_SMGR_REPORT_DBG2 SNS_SMGR_PRINTF2
#define SNS_SMGR_REPORT_DBG3 SNS_SMGR_PRINTF3
#define SNS_SMGR_REPORT_DBG4 SNS_SMGR_PRINTF4
#else
#define SNS_SMGR_REPORT_DBG1(level,msg,p1)
#define SNS_SMGR_REPORT_DBG2(level,msg,p1,p2)
#define SNS_SMGR_REPORT_DBG3(level,msg,p1,p2,p3)
#define SNS_SMGR_REPORT_DBG4(level,msg,p1,p2,p3,p4)
#endif

//#define SNS_SMGR_INIT_ITER_DEBUG
#ifdef SNS_SMGR_INIT_ITER_DEBUG
#define SNS_SMGR_INIT_ITER_DBG1 SNS_SMGR_PRINTF1
#define SNS_SMGR_INIT_ITER_DBG2 SNS_SMGR_PRINTF2
#define SNS_SMGR_INIT_ITER_DBG3 SNS_SMGR_PRINTF3
#define SNS_SMGR_INIT_ITER_DBG4 SNS_SMGR_PRINTF4
#else
#define SNS_SMGR_INIT_ITER_DBG1(level,msg,p1)
#define SNS_SMGR_INIT_ITER_DBG2(level,msg,p1,p2)
#define SNS_SMGR_INIT_ITER_DBG3(level,msg,p1,p2,p3)
#define SNS_SMGR_INIT_ITER_DBG4(level,msg,p1,p2,p3,p4)
#endif

#define SNS_RH_1000MS_IN_TICK   TIMETICK_SCLK_FROM_MS(1000)
#define SNS_RH_100MS_IN_TICK    TIMETICK_SCLK_FROM_MS(100)

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 *  Variables
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/

/*===========================================================================

  FUNCTION:   sns_rh_sol_init_interp_time

===========================================================================*/

/*===========================================================================

  FUNCTION:   sns_rh_rpt_gen_init_item_depot_iter

===========================================================================*/
/*!
  @brief Initializes given item's depot_iter object.

  @detail Also returned are timestamp of current sample in iterator.

  @param[i]  item_ptr - the report item whose depot_iter to initialize

  @return   None
 */
/*=========================================================================*/
SNS_RH_UIMAGE_CODE 
const sns_smgr_sample_s* sns_rh_rpt_gen_init_item_depot_iter(
  sns_rh_rpt_item_s* item_ptr)
{
  const sns_smgr_sample_s* sample_ptr;
  sns_rh_interpolator_obj_s* iobj_ptr = &item_ptr->interpolator_obj;
  sns_ddf_time_t ts = item_ptr->last_processed_sample_timestamp + 1;
  /* -------------------------------------------------------------------- */

  if ( item_ptr->last_processed_sample_timestamp == 0 )
  {
    ts = item_ptr->ts_last_sent;
  }
  else if ( item_ptr->interpolator_obj.sample2_ptr != NULL &&
            item_ptr->interpolator_obj.desired_timestamp <=
            SMGR_SAMPLE_TIMESTAMP(item_ptr->interpolator_obj.sample2_ptr) )
  {
    ts = item_ptr->last_processed_sample_timestamp;
  }

  sample_ptr = sns_smgr_depot_init_iter(item_ptr->depot_ptr, ts, &item_ptr->depot_iter);

  if ( !item_ptr->samples_sent )
  {
    sns_rh_rpt_spec_s* rpt_ptr = item_ptr->parent_report_ptr;
    sns_ddf_time_t     sample_ts = 0;
    sns_ddf_status_e   sample_status = SNS_DDF_EINVALID_DATA;

#ifdef SNS_SMGR_INIT_ITER_DEBUG
    sns_rh_leave_island();
#endif

    /* Discards initial invalid samples */
    while ( sample_ptr != NULL && SMGR_SAMPLE_STATUS(sample_ptr) != SNS_DDF_SUCCESS )
    {
      SNS_SMGR_INIT_ITER_DBG4(
        MED, "init_iter - rpt %u/0x%x not using %u from sensor %u", 
        rpt_ptr->rpt_id, rpt_ptr->msg_header.connection_handle, 
        SMGR_SAMPLE_TIMESTAMP(sample_ptr), 
        SMGR_SENSOR_ID(item_ptr->ddf_sensor_ptr->sensor_ptr));
      item_ptr->last_processed_sample_timestamp = SMGR_SAMPLE_TIMESTAMP(sample_ptr) + 1;
      item_ptr->ts_last_sent = item_ptr->last_processed_sample_timestamp;
      sample_ptr = sns_smgr_depot_get_sample(&item_ptr->depot_iter, 1);
    }

    if ( sample_ptr != NULL )
    {
      sample_ts     = SMGR_SAMPLE_TIMESTAMP(sample_ptr);
      sample_status = SMGR_SAMPLE_STATUS(sample_ptr);
      SNS_SMGR_INIT_ITER_DBG4(
        HIGH, "init_iter - rpt_id=%u/0x%x last_sent=%u last_proc=%u",
        rpt_ptr->rpt_id, rpt_ptr->msg_header.connection_handle,
        item_ptr->ts_last_sent, item_ptr->last_processed_sample_timestamp);
    }

    if ( sample_ptr != NULL && item_ptr->last_processed_sample_timestamp != sample_ts )
    {
      /* first unprocessed valid sample found */
      if ( SNS_RH_REPORT_IS_STREAMING(rpt_ptr) && item_ptr->cic_obj.factor > 1 )
      {
        sns_ddf_time_t lastest_sample_ts = sns_rh_get_latest_sample_timestamp(item_ptr);
        int32_t delta_time = lastest_sample_ts - item_ptr->ts_last_sent;
        SNS_SMGR_INIT_ITER_DBG4(
          HIGH, "init_iter - latest=%u delta=%d invtl=%u current=%u",
          lastest_sample_ts, delta_time, item_ptr->sampling_interval, sample_ts);
        if ( delta_time < item_ptr->sampling_interval )
        {
          /* filtering requires samples covering at least one
             sampling interval from last_sent; since even the latest sample 
             is not at least one sampling interval from last_sent, no point 
             in trying to use current sample */
          sample_ptr    = NULL;
          sample_ts     = 0;
          sample_status = SNS_DDF_EINVALID_DATA;
        }
      }

      if ( sample_ptr != NULL && iobj_ptr->interval_ticks != 0 )
      {
        if ( !SMGR_SENSOR_IS_S4S(item_ptr->ddf_sensor_ptr->sensor_ptr) )
        {
          iobj_ptr->desired_timestamp = sample_ts;
        }
        else if ( iobj_ptr->desired_timestamp == 0 )
        {
          /* For S4S, set the interpolator to interpolate timestamps based on the S4S
           * schedule. Use "sample_ts-1" since s4s_get_next_sample is guaranteed
           * to return a timestamp greater than the input */
          iobj_ptr->desired_timestamp =
            sns_smgr_s4s_get_next_sample_ts( item_ptr->ddf_sensor_ptr, sample_ts-1 );
        }
        item_ptr->ts_last_sent = iobj_ptr->desired_timestamp - 1;

        SNS_SMGR_INIT_ITER_DBG3(
          MED, "init_iter - ts1=%u ts=%u ts2=%u",
          iobj_ptr->sample1_ptr ? SMGR_SAMPLE_TIMESTAMP(iobj_ptr->sample1_ptr) : 0,
          iobj_ptr->desired_timestamp,
          iobj_ptr->sample2_ptr ? SMGR_SAMPLE_TIMESTAMP(iobj_ptr->sample2_ptr) : 0);
      }
    }
    SNS_SMGR_INIT_ITER_DBG4(
      MED, "init_iter - rpt_id=%u/0x%x sample=%u status=%u",
      rpt_ptr->rpt_id, rpt_ptr->msg_header.connection_handle, sample_ts, sample_status);
  }
  return sample_ptr;
}

/*===========================================================================

  FUNCTION:   sns_rh_rpt_gen_schedule_next_report

===========================================================================*/
/*!
  @brief Schedules next report 
  @param [i]  rpt_ptr  - the report to schedule
  @return   none
 */
/*=========================================================================*/
SNS_RH_UIMAGE_CODE SMGR_STATIC void sns_rh_rpt_gen_schedule_next_report(
  sns_rh_rpt_spec_s* rpt_ptr,
  bool               samples_sent)
{
  if ( rpt_ptr->rpt_tick == 0 )
  {
    rpt_ptr->state = RH_RPT_STATE_ACTIVE;
  }
  else if ( rpt_ptr->event_sensors_only )
  {
    if ( samples_sent )
    {
      /* one report interval from now */
      rpt_ptr->rpt_tick = rpt_ptr->ts_last_rpt_sent + rpt_ptr->rpt_interval;
    }
    rpt_ptr->state = RH_RPT_STATE_ACTIVE;
  }
  else if ( samples_sent || rpt_ptr->ind_count == 0 )
  {
    rpt_ptr->rpt_tick = rpt_ptr->ts_last_rpt_sent + rpt_ptr->rpt_interval;
    rpt_ptr->state = RH_RPT_STATE_ACTIVE;
  }
  else if ( rpt_ptr->state == RH_RPT_STATE_FLUSHING )
  {
    rpt_ptr->state = RH_RPT_STATE_ACTIVE;
  }
}

/*===========================================================================

  FUNCTION:   sns_rh_requeue_periodic_report

===========================================================================*/
/*!
  @brief Puts Periodic report back to ready queue if there are more
         samples to process.

  @param [io]  rpt_ptr  report pointer
 
  @return      none
 */
/*=========================================================================*/
SNS_RH_UIMAGE_CODE 
SMGR_STATIC void sns_rh_requeue_periodic_report(sns_rh_rpt_spec_s* rpt_ptr)
{
  uint8_t i;
  RH_FOR_EACH_REPORT_ITEM( rpt_ptr, i )
  {
    sns_rh_rpt_item_s* item_ptr = rpt_ptr->item_list[i];
    sns_ddf_time_t latest_sample_timestamp =
      item_ptr->ddf_sensor_ptr->latest_sample_ts;
    if ( latest_sample_timestamp != item_ptr->last_processed_sample_timestamp )
    {
      SNS_SMGR_REPORT_DBG3(
         LOW, "requeue_periodic_rpt - last_sent=%u last_proc=%u latest=%u",
         item_ptr->ts_last_sent, item_ptr->last_processed_sample_timestamp, 
         latest_sample_timestamp);
      break;
    }
    else if ( item_ptr->interpolator_obj.sample2_ptr != NULL &&
              item_ptr->interpolator_obj.desired_timestamp <=
              SMGR_SAMPLE_TIMESTAMP(item_ptr->interpolator_obj.sample2_ptr) )
    {
      SNS_SMGR_REPORT_DBG4(
         MED, "requeue_periodic_rpt - sensor=%u last_sent=%u last_proc=%u desired=%u",
         SMGR_SENSOR_ID(item_ptr->ddf_sensor_ptr->sensor_ptr),
         item_ptr->ts_last_sent, item_ptr->last_processed_sample_timestamp, 
         item_ptr->interpolator_obj.desired_timestamp);
      break;
    }
  }
  if ( i >= rpt_ptr->num_items )
  {
    rpt_ptr->state = RH_RPT_STATE_ACTIVE;
  }
  else
  {
    /* add it back to end of ready report list */
    sns_rh_add_to_ready_list(rpt_ptr);
  }
}

/*===========================================================================

  FUNCTION:   sns_rh_rpt_gen_generate_periodic_report

===========================================================================*/
/*!
  @brief This function generates periodic report indication message.

  @detail

  @param[i]  rpt_spec_ptr  report pointer
  @return   TRUE if report was generated
 */
/*=========================================================================*/
SNS_RH_UIMAGE_CODE bool sns_rh_rpt_gen_generate_periodic_report(
  sns_rh_rpt_spec_s* rpt_ptr)
{
  bool                                  sent = false;
  sns_smgr_periodic_report_ind_msg_v01* ind_ptr = NULL;
  sns_smgr_data_item_s_v01*             item_ptr;
  uint8_t                               i;
  /* -------------------------------------------------------------------- */

  SNS_SMGR_REPORT_DBG3(
    MED, "periodic_rpt - id=%u/%u #items=%u",
    rpt_ptr->msg_header.src_module, rpt_ptr->rpt_id, rpt_ptr->num_items);

  ind_ptr = sns_rh_get_periodic_ind_buf();
  SNS_OS_MEMZERO(ind_ptr, sizeof(sns_smgr_periodic_report_ind_msg_v01));
  ind_ptr->ReportId = rpt_ptr->rpt_id;
  ind_ptr->status   = SNS_SMGR_REPORT_OK_V01;

  /* gather all items */
  item_ptr = ind_ptr->Item;
  RH_FOR_EACH_REPORT_ITEM( rpt_ptr, i )
  {
    sns_rh_rpt_item_s* item_spec_ptr = rpt_ptr->item_list[i];
    uint8_t            item_quality  = item_spec_ptr->quality;
    sns_smgr_ddf_sensor_s* ddf_sensor_ptr = item_spec_ptr->ddf_sensor_ptr;
    const sns_smgr_sample_s* sample_ptr;
    sns_ddf_time_t timestamp;
    sns_ddf_status_e status;

    item_spec_ptr->state = RH_RPT_ITEM_STATE_IDLE;
    SNS_SMGR_REPORT_DBG2(
      HIGH, "resulting_sample status=%d ts=%u",
      SMGR_SAMPLE_STATUS(&item_spec_ptr->resulting_sample),
      SMGR_SAMPLE_TIMESTAMP(&item_spec_ptr->resulting_sample));

    if ( item_spec_ptr->ddf_sensor_ptr->bimg_depot_ptr == item_spec_ptr->depot_ptr )
    {
      sns_rh_leave_island();
    }

    if ( !sns_smgr_ddf_sensor_is_event_sensor(ddf_sensor_ptr) )
    {
      sample_ptr = sns_rh_rpt_gen_init_item_depot_iter(item_spec_ptr);
      while ( (item_spec_ptr->state != RH_RPT_ITEM_STATE_DONE) && (sample_ptr != NULL) )
      {
        sns_ddf_status_e status =
          sns_rh_process_sample(item_spec_ptr, item_quality, sample_ptr,
                                &timestamp,
                                item_spec_ptr->resulting_sample.data);
        SMGR_SAMPLE_TIMESTAMP_SET(&item_spec_ptr->resulting_sample, timestamp);
        SMGR_SAMPLE_STATUS_SET(&item_spec_ptr->resulting_sample, status);
        sample_ptr = sns_smgr_depot_get_sample(&item_spec_ptr->depot_iter, 1);
        SNS_SMGR_REPORT_DBG3(
          MED, "resulting_sample status=%d ts=%u sample_ts=%u",
          SMGR_SAMPLE_STATUS(&item_spec_ptr->resulting_sample),
          SMGR_SAMPLE_TIMESTAMP(&item_spec_ptr->resulting_sample),
          sample_ptr ? SMGR_SAMPLE_TIMESTAMP(sample_ptr) : 0);
      }
    }
    else
    {
      sample_ptr = sns_smgr_depot_get_latest_sample(item_spec_ptr->depot_ptr);
      if ( sample_ptr != NULL )
      {
        status = sns_rh_process_sample(item_spec_ptr, item_quality, sample_ptr, &timestamp,
                                       item_spec_ptr->resulting_sample.data);
        SMGR_SAMPLE_TIMESTAMP_SET(&item_spec_ptr->resulting_sample, timestamp);
        SMGR_SAMPLE_STATUS_SET(&item_spec_ptr->resulting_sample, status);
      }
    }

    if ( (item_spec_ptr->state == RH_RPT_ITEM_STATE_DONE) &&
         ((SMGR_SAMPLE_STATUS(&item_spec_ptr->resulting_sample) == SNS_DDF_SUCCESS) ||
          /* invalid samples only OK to be sent midstream */
          ((SMGR_SAMPLE_STATUS(&item_spec_ptr->resulting_sample) == 
            SNS_DDF_EINVALID_DATA) &&
           item_spec_ptr->samples_sent)) )
    {
      ind_ptr->SamplingRate_valid = true;
      ind_ptr->SamplingRate[ind_ptr->SamplingRate_len++] = item_spec_ptr->effective_rate_hz;
      /* Calculate current reporting rate: Only for the first item */
      if ( 0 == ind_ptr->Item_len++ )
      {
        /* If the effective rate is less than 1 Hz, output the current rate as
           the period in milliseconds. */
        if ( item_spec_ptr->effective_rate_hz < FX_ONE_Q16 )
        {
          // If effective_rate_hz is 0x3E8 or less, this will overflow the 16-bit integer
          uint32_t period_ms = FX_FLTTOFIX_Q16(1000) / item_spec_ptr->effective_rate_hz;

          // If an overflow of the 16-bit CurrentRate happens, use UINT16_MAX instead
          ind_ptr->CurrentRate = (UINT16_MAX < period_ms) ?
              UINT16_MAX : period_ms;
        }
        else
        {
          ind_ptr->CurrentRate = 
            (uint16_t) FX_FIXTOFLT_Q16_SP(item_spec_ptr->effective_rate_hz);
        }
      }
      SNS_OS_MEMCOPY(item_ptr->ItemData,
                     item_spec_ptr->resulting_sample.data,
                     sizeof(item_ptr->ItemData));
      if ( SMGR_SAMPLE_STATUS(&item_spec_ptr->resulting_sample) != SNS_DDF_SUCCESS )
      {
        item_ptr->ItemFlags   = SNS_SMGR_ITEM_FLAG_INVALID_V01;
        item_ptr->ItemQuality = SNS_SMGR_ITEM_QUALITY_INVALID_NOT_READY_V01;
        SNS_SMGR_REPORT_DBG1(
          ERROR, "periodic_rpt - ts=%u", 
          SMGR_SAMPLE_TIMESTAMP(&item_spec_ptr->resulting_sample));
      }
      else
      {
        item_ptr->ItemQuality = item_spec_ptr->quality;
        item_ptr->ItemFlags  |=
          sns_rh_apply_calibration(item_ptr->ItemData,
                                 item_spec_ptr->ddf_sensor_ptr,
                                 item_spec_ptr->cal_sel);
      }
      item_spec_ptr->samples_sent = true;
      RH_UPDATE_INTERP_TIMESTAMP(&item_spec_ptr->interpolator_obj);

      item_ptr->SensorId = SMGR_SENSOR_ID(ddf_sensor_ptr->sensor_ptr);
      item_ptr->DataType = ddf_sensor_ptr->data_type;
      item_ptr->ItemSensitivity = item_spec_ptr->sensitivity;
      item_ptr->TimeStamp   = SMGR_SAMPLE_TIMESTAMP(&item_spec_ptr->resulting_sample);

      SNS_SMGR_REPORT_DBG2(
        LOW, "periodic_rpt - sensor=%d ts=%u",
        item_ptr->SensorId, item_ptr->TimeStamp);

      item_spec_ptr->ts_last_sent = SMGR_SAMPLE_TIMESTAMP(&item_spec_ptr->resulting_sample);
      item_ptr++;       /* next item */

      if ( sns_smgr_ddf_sensor_is_event_sensor(ddf_sensor_ptr) ||
           item_spec_ptr->quality == SNS_SMGR_ITEM_QUALITY_CURRENT_SAMPLE_V01 )
      {
        item_spec_ptr->state = RH_RPT_ITEM_STATE_IDLE;
      }
    }

    if ( item_spec_ptr->ddf_sensor_ptr->bimg_depot_ptr == item_spec_ptr->depot_ptr )
    {
      sns_rh_enter_island();
    }
  }/* for each item in report */

  sns_profiling_log_qdss(SNS_RH_RPT_IND_START, 4, rpt_ptr->rpt_id, 
                         rpt_ptr->msg_header.connection_handle, 
                         SNS_SMGR_REPORT_IND_V01, rpt_ptr->num_items);

  if ( ind_ptr->Item_len > 0 )
  {
    sent = sns_rh_rpt_gen_send_report_indication(
      rpt_ptr,
      ind_ptr,
      SNS_SMGR_REPORT_IND_V01,
      sizeof(sns_smgr_periodic_report_ind_msg_v01),
      false);
  }

  sns_profiling_log_qdss(SNS_RH_RPT_IND_END, 3, rpt_ptr->rpt_id, 
                         ind_ptr->Item_len, sent);
  
  if ( sent || sns_rh_mr_conn_busy(rpt_ptr->msg_header.connection_handle) )
  {
    rpt_ptr->ind_count++;
    rpt_ptr->ts_last_rpt_sent = sns_ddf_get_timestamp();
    if ( rpt_ptr->ind_count == 1 || rpt_ptr->proc_type != SNS_PROC_APPS_V01 || !sent ||
         rpt_ptr->q16_rpt_rate <= FX_ONE_Q16 )
    {
      SNS_SMGR_PRINTF4(
        HIGH, "send_per_ind - id=%u/0x%x #items=%u ts[0]=%u",
        ind_ptr->ReportId, rpt_ptr->msg_header.connection_handle, 
        ind_ptr->Item_len, ind_ptr->Item[0].TimeStamp);
    }
    sns_rh_requeue_periodic_report(rpt_ptr);
  }
  else if ( ind_ptr->Item_len != 0 )
  {
    SNS_SMGR_PRINTF3(
      ERROR, "send_per_ind - id=%u/0x%x last_sent[0]=%u",
      ind_ptr->ReportId, rpt_ptr->msg_header.connection_handle, 
      rpt_ptr->item_list[0]->ts_last_sent);
  }
  else
  {
    SNS_SMGR_REPORT_DBG3(
      LOW, "periodic_rpt - no ready items for rpt %u/0x%x last_proc[0]=%u",
      rpt_ptr->rpt_id, rpt_ptr->msg_header.connection_handle, 
      rpt_ptr->item_list[0]->last_processed_sample_timestamp);
  }
  return sent;
}

/*===========================================================================

  FUNCTION:   sns_rh_rpt_gen_send_buffering_indications

===========================================================================*/
/*!
  @brief Determines number of indications required to send all available samples
         for the given report, generates and sends them.

  @param[i]  rpt_spec_ptr  - the report spec
  @param[i]  last_ind_type - type of the most recent indication sent for this report

  @return   TRUE if one or more indications were sent
 */
/*=========================================================================*/
SNS_RH_UIMAGE_CODE bool sns_rh_rpt_gen_send_buffering_indications(
  sns_rh_rpt_spec_s* rpt_spec_ptr,
  uint8_t            last_ind_type)
{
  uint16_t inds_sent = 0;
  uint32_t num_samples_sent = 0;
  uint32_t total_num_samples_sent = 0;
  bool     samples_sent = false;
  sns_ddf_time_t time_now = sns_ddf_get_timestamp();

  /* -------------------------------------------------------------------- */

  sns_profiling_log_qdss(SNS_RH_BUF_TRAIN_START, 3, rpt_spec_ptr->rpt_id, 
                         rpt_spec_ptr->msg_header.connection_handle, 
                         rpt_spec_ptr->num_items);

  SNS_SMGR_B2B_IND_DBG4(
    HIGH, "buff_rpt_prep - rpt_id=%u/0x%x #inds=%u #samples=%u",
    rpt_spec_ptr->rpt_id, rpt_spec_ptr->msg_header.connection_handle, 
    rpt_spec_ptr->ind_count, rpt_spec_ptr->num_saved_samples);

  if ( rpt_spec_ptr->num_saved_samples > 0 )
  {
    uint32_t i;
    uint32_t num_samples_in_ind;
    uint32_t old_ind_count = rpt_spec_ptr->ind_count;
    uint16_t subHz_item_cnt = 0;
    uint32_t max_subHz_sample_cnt = 0;
    uint16_t num_inds = 0;

    if ( rpt_spec_ptr->event_sensors_only  )
    {
       RH_FOR_EACH_REPORT_ITEM( rpt_spec_ptr, i )
       {
         sns_rh_rpt_item_s* item_ptr = rpt_spec_ptr->item_list[i];
         num_inds = MAX(num_inds, item_ptr->num_saved_samples);
       }
    }
    else
    {
       uint16_t sns_smgr_buffering_report_max_samples_v2 = SNS_SMGR_BUFFERING_REPORT_MAX_SAMPLES_V01;
       if ( rpt_spec_ptr->num_items )
       {
         sns_smgr_buffering_report_max_samples_v2 =
         SNS_SMGR_BUFFERING_REPORT_MAX_SAMPLES_V01/rpt_spec_ptr->num_items *rpt_spec_ptr->num_items;
         if (sns_smgr_buffering_report_max_samples_v2 == 0 )
         {
             sns_smgr_buffering_report_max_samples_v2 = SNS_SMGR_BUFFERING_REPORT_MAX_SAMPLES_V01;
         }
       }
       num_inds = 
      (rpt_spec_ptr->num_saved_samples + sns_smgr_buffering_report_max_samples_v2 - 1) / 
         sns_smgr_buffering_report_max_samples_v2;
      /* If any items in the report have a sampling rate less than 1 Hz, set the
         number of indications to the number of samples. This will cause the SMGR
         to send all the samples as back-to-back (b2b) indications with each
         indication carrying just 1 sample. This ensures that the TimeStampOffset
         field in the indication message does not overflow (overflow happens
         when the sampling rate is 0.5 Hz or less).
         TODO: Send only back-to-back indications for the samples that will cause
         an overflow in the TimeStampOffset field. All other samples can be
         grouped in batches of 100 samples and sent together. */
      RH_FOR_EACH_REPORT_ITEM( rpt_spec_ptr, i )
      {
        sns_rh_rpt_item_s* item_ptr = rpt_spec_ptr->item_list[i];

        if ( (item_ptr->effective_rate_hz > 0 && item_ptr->effective_rate_hz < FX_ONE_Q16) )
        {
          max_subHz_sample_cnt = MAX(max_subHz_sample_cnt, item_ptr->num_saved_samples);
          if ( item_ptr->num_saved_samples > 0 )
          {
            subHz_item_cnt++;
          }
        }
      }
      num_inds = MAX(num_inds, max_subHz_sample_cnt);
    }

    num_samples_in_ind = (rpt_spec_ptr->num_saved_samples + num_inds - 1)/ num_inds;
    if (rpt_spec_ptr->num_items && (num_samples_in_ind >=rpt_spec_ptr->num_items) )
    {
      num_samples_in_ind = (num_samples_in_ind+rpt_spec_ptr->num_items-1)/rpt_spec_ptr->num_items 
                            *rpt_spec_ptr->num_items;
    }
    SNS_SMGR_B2B_IND_DBG3(
         MED, "buff_rpt_prep - #items=%u #ind=%u #samples/ind=%u", 
         rpt_spec_ptr->num_items, num_inds, num_samples_in_ind);
    

    for ( i = 0, inds_sent = 0; i < num_inds; i++ )
    {
      uint8_t ind_type;

      if ( i == num_inds-1 ) /* the end of the train */
      {
        if ( total_num_samples_sent > 0 ) /* train has multiple indications */
        {
          ind_type = SNS_BATCH_LAST_IND_V01;
        }
        else if ( last_ind_type != SNS_BATCH_ONLY_IND_V01 &&
                  last_ind_type != SNS_BATCH_LAST_IND_V01 )
        {
          /* the only indication on this train is really the last indication 
             of the previous train that was interrupted by QMI connection busy */
          ind_type = SNS_BATCH_LAST_IND_V01;
        }
        else
        {
          ind_type = SNS_BATCH_ONLY_IND_V01;
        }
        num_samples_in_ind = rpt_spec_ptr->num_saved_samples;
      }
      else /* not the caboose */
      {
        if ( total_num_samples_sent > 0 ) /* not head of the train */
        {
          ind_type = SNS_BATCH_INTERMEDIATE_IND_V01;
        }
        else if ( last_ind_type == SNS_BATCH_INTERMEDIATE_IND_V01 ||
                  last_ind_type == SNS_BATCH_FIRST_IND_V01 )
        {
          /* the first indication on this train is really an intermediate indication
             of the previous train that was interrupted by QMI connection busy */
          ind_type = SNS_BATCH_INTERMEDIATE_IND_V01;
        }
        else
        {
          ind_type = SNS_BATCH_FIRST_IND_V01;
        }
      }
      if ( i >= max_subHz_sample_cnt )
      {
        subHz_item_cnt = 0;
      }
      num_samples_sent = sns_rh_batchbuff_generate_buffering_report(rpt_spec_ptr, 
                                                                    num_samples_in_ind, 
                                                                    ind_type,
                                                                    subHz_item_cnt);
      if ( num_samples_sent >0 )
      {
        inds_sent++;
        total_num_samples_sent += num_samples_sent;
      }
      else if ( ind_type != SNS_BATCH_LAST_IND_V01 &&
                !sns_rh_mr_conn_busy(rpt_spec_ptr->msg_header.connection_handle))
      {
        SNS_SMGR_PRINTF0(
          ERROR, "buff_inds - possible framing error");
      }

      SNS_SMGR_B2B_IND_DBG2(
        LOW, "buff_inds - #sent=%u ind_type=%u", num_samples_sent, ind_type);

      if ( num_samples_sent == 0 &&
           sns_rh_mr_conn_busy(rpt_spec_ptr->msg_header.connection_handle) )
      {
        break;
      }

      if ( (inds_sent & 0xF) == 0xF ) /* checks every 16 indications */
      {
        if ( sns_rh_new_samples_available() )
        {
          sns_rh_process_ready_sample_sig(rpt_spec_ptr);
        }
      }
    }

    SNS_SMGR_B2B_IND_DBG2(
      MED, "buff_inds - #samples=%u #inds=%u", total_num_samples_sent, inds_sent);

    samples_sent = (total_num_samples_sent > 0);

    if ( !rpt_spec_ptr->periodic_like )
    {
      rpt_spec_ptr->ts_last_rpt_sent = time_now;
      sns_rh_rpt_gen_schedule_next_report(rpt_spec_ptr, samples_sent);
    }

    /* debug logging */
    if ( samples_sent && !rpt_spec_ptr->periodic_like &&
         (old_ind_count == 0 || rpt_spec_ptr->event_sensors_only ||
          (rpt_spec_ptr->q16_rpt_rate < FX_ONE_Q16 && 
           rpt_spec_ptr->proc_type != SNS_PROC_SSC_V01)) )
    {
      SNS_SMGR_PRINTF4(
        HIGH, "buff_train - rpt_id=%u/0x%x #samples=%u #ind=%u",
        rpt_spec_ptr->rpt_id, rpt_spec_ptr->msg_header.connection_handle, 
        total_num_samples_sent, inds_sent);
      SNS_SMGR_PRINTF3(
        HIGH, "buff_train - last_sent[0]=%u rpt(last/next)=%u/%u",
        rpt_spec_ptr->item_list[0]->ts_last_sent, rpt_spec_ptr->ts_last_rpt_sent,
        rpt_spec_ptr->rpt_tick);
    }
  }

  sns_profiling_log_qdss(SNS_RH_BUF_TRAIN_END, 3, inds_sent, total_num_samples_sent,
                         rpt_spec_ptr->rpt_tick);
  return samples_sent;
}

/*===========================================================================

  FUNCTION:   sns_rh_rpt_gen_send_report_indication

===========================================================================*/
/*!
  @brief This function populates message header and sends the given indication
   over the given connection. The indication will be saved if connection is busy

  @param[i]  rpt_spec_ptr - report spec
  @param[i]  ind_msg_ptr - the indication message to send
  @param[i]  msg_id      - indication ID
  @param[i]  len         - length of the indication body
  @param[i]  free_me     - whether to free the indication memory
 
  @return   true if indication was sent or will be sent
 */
/*=========================================================================*/
SNS_RH_UIMAGE_CODE bool sns_rh_rpt_gen_send_report_indication(
   sns_rh_rpt_spec_s* rpt_spec_ptr,
   void*        ind_msg_ptr,
   uint16_t     msg_id, 
   uint16_t     len,
   bool         free_me)
{
  bool sent = false;
  
  sent = sns_rh_mr_send_indication(rpt_spec_ptr->msg_header.connection_handle,
                                   ind_msg_ptr, 
                                   msg_id, 
                                   len, 
                                   free_me);
  
  if ( !sent && sns_rh_mr_conn_busy(rpt_spec_ptr->msg_header.connection_handle) )
  {
    sns_rh_leave_island();
    sns_rh_rpt_gen_save_indication(rpt_spec_ptr, ind_msg_ptr, len);
    sns_rh_enter_island();
  }
  
  return sent;
}

