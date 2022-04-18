/* ov2685_lib.h
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __OV2685_LIB_H__
#define __OV2685_LIB_H__

#include "sensor_lib.h"
#define SENSOR_MODEL "ov2685"

#define MIN_GAIN 1
#define MAX_ANALOG_GAIN (15.5)
#define MAX_DIGITAL_GAIN (1)
#define MAX_GAIN (MAX_ANALOG_GAIN * MAX_DIGITAL_GAIN)

/* 0x3: manual exp and gain; 0x0: auto exp and gain*/
#define MANUAL_EXP_ENABLE 0x3503

#define OV2685_MAX_DGAIN_DECIMATOR  2048

#define START_REG_ARRAY \
{ \
  {0x0100, 0x01, 0x00}, \
}

#define STOP_REG_ARRAY \
{ \
  {0x0100, 0x00, 0x00}, \
}

#define GROUPON_REG_ARRAY \
{ \
  {0x3208, 0x00, 0x00}, \
}

#define GROUPOFF_REG_ARRAY \
{ \
  {0x3208, 0x10, 0x00}, \
  {0x3208, 0xa0, 0x00}, \
}

#define RES0_REG_ARRAY \
{ \
  {0x0103, 0x01, 0x00}, \
  {0x3002, 0x00, 0x00}, \
  {0x3016, 0x1C, 0x00}, \
  {0x3018, 0x84, 0x00}, \
  {0x301D, 0xF0, 0x00}, \
  {0x3020, 0x00, 0x00}, \
  {0x3082, 0x2C, 0x00}, \
  {0x3083, 0x03, 0x00}, \
  {0x3084, 0x07, 0x00}, \
  {0x3085, 0x03, 0x00}, \
  {0x3086, 0x00, 0x00}, \
  {0x3087, 0x00, 0x00}, \
  {0x3501, 0x4E, 0x00}, \
  {0x3502, 0xE0, 0x00}, \
  {0x3503, 0x03, 0x00}, \
  {0x350B, 0x36, 0x00}, \
  {0x3600, 0xB4, 0x00}, \
  {0x3603, 0x35, 0x00}, \
  {0x3604, 0x24, 0x00}, \
  {0x3605, 0x00, 0x00}, \
  {0x3620, 0x24, 0x00}, \
  {0x3621, 0x34, 0x00}, \
  {0x3622, 0x03, 0x00}, \
  {0x3628, 0x10, 0x00}, \
  {0x3705, 0x3C, 0x00}, \
  {0x370A, 0x21, 0x00}, \
  {0x370C, 0x50, 0x00}, \
  {0x370D, 0xC0, 0x00}, \
  {0x3717, 0x58, 0x00}, \
  {0x3718, 0x80, 0x00}, \
  {0x3720, 0x00, 0x00}, \
  {0x3721, 0x09, 0x00}, \
  {0x3722, 0x06, 0x00}, \
  {0x3723, 0x59, 0x00}, \
  {0x3738, 0x99, 0x00}, \
  {0x3781, 0x80, 0x00}, \
  {0x3784, 0x0C, 0x00}, \
  {0x3789, 0x60, 0x00}, \
  {0x3800, 0x00, 0x00}, \
  {0x3801, 0x00, 0x00}, \
  {0x3802, 0x00, 0x00}, \
  {0x3803, 0x00, 0x00}, \
  {0x3804, 0x06, 0x00}, \
  {0x3805, 0x4F, 0x00}, \
  {0x3806, 0x04, 0x00}, \
  {0x3807, 0xBF, 0x00}, \
  {0x3808, 0x06, 0x00}, \
  {0x3809, 0x40, 0x00}, \
  {0x380A, 0x04, 0x00}, \
  {0x380B, 0xB0, 0x00}, \
  {0x380C, 0x06, 0x00}, \
  {0x380D, 0xA4, 0x00}, \
  {0x380E, 0x05, 0x00}, \
  {0x380F, 0x0E, 0x00}, \
  {0x3810, 0x00, 0x00}, \
  {0x3811, 0x08, 0x00}, \
  {0x3812, 0x00, 0x00}, \
  {0x3813, 0x08, 0x00}, \
  {0x3814, 0x11, 0x00}, \
  {0x3815, 0x11, 0x00}, \
  {0x3819, 0x04, 0x00}, \
  {0x3820, 0xC0, 0x00}, \
  {0x3821, 0x00, 0x00}, \
  {0x3A06, 0x01, 0x00}, \
  {0x3A07, 0x84, 0x00}, \
  {0x3A08, 0x01, 0x00}, \
  {0x3A09, 0x43, 0x00}, \
  {0x3A0A, 0x24, 0x00}, \
  {0x3A0B, 0x60, 0x00}, \
  {0x3A0C, 0x28, 0x00}, \
  {0x3A0D, 0x60, 0x00}, \
  {0x3A0E, 0x04, 0x00}, \
  {0x3A0F, 0x8C, 0x00}, \
  {0x3A10, 0x05, 0x00}, \
  {0x3A11, 0x0C, 0x00}, \
  {0x4000, 0x81, 0x00}, \
  {0x4001, 0x40, 0x00}, \
  {0x4008, 0x02, 0x00}, \
  {0x4009, 0x09, 0x00}, \
  {0x4300, 0x30, 0x00}, \
  {0x430E, 0x00, 0x00}, \
  {0x4602, 0x02, 0x00}, \
  {0x481B, 0x40, 0x00}, \
  {0x481F, 0x40, 0x00}, \
  {0x4837, 0x1E, 0x00}, \
  {0x5000, 0xFF, 0x00}, \
  {0x5001, 0x05, 0x00}, \
  {0x5002, 0x32, 0x00}, \
  {0x5003, 0x04, 0x00}, \
  {0x5004, 0xFF, 0x00}, \
  {0x5005, 0x12, 0x00}, \
  {0x0100, 0x00, 0x00}, \
  {0x5180, 0xF4, 0x00}, \
  {0x5181, 0x11, 0x00}, \
  {0x5182, 0x41, 0x00}, \
  {0x5183, 0x42, 0x00}, \
  {0x5184, 0x78, 0x00}, \
  {0x5185, 0x58, 0x00}, \
  {0x5186, 0xB5, 0x00}, \
  {0x5187, 0xB2, 0x00}, \
  {0x5188, 0x08, 0x00}, \
  {0x5189, 0x0E, 0x00}, \
  {0x518A, 0x0C, 0x00}, \
  {0x518B, 0x4C, 0x00}, \
  {0x518C, 0x38, 0x00}, \
  {0x518D, 0xF8, 0x00}, \
  {0x518E, 0x04, 0x00}, \
  {0x518F, 0x7F, 0x00}, \
  {0x5190, 0x40, 0x00}, \
  {0x5191, 0x5F, 0x00}, \
  {0x5192, 0x40, 0x00}, \
  {0x5193, 0xFF, 0x00}, \
  {0x5194, 0x40, 0x00}, \
  {0x5195, 0x07, 0x00}, \
  {0x5196, 0x04, 0x00}, \
  {0x5197, 0x04, 0x00}, \
  {0x5198, 0x00, 0x00}, \
  {0x5199, 0x05, 0x00}, \
  {0x519A, 0xD2, 0x00}, \
  {0x519B, 0x04, 0x00}, \
  {0x5200, 0x09, 0x00}, \
  {0x5201, 0x00, 0x00}, \
  {0x5202, 0x06, 0x00}, \
  {0x5203, 0x20, 0x00}, \
  {0x5204, 0x41, 0x00}, \
  {0x5205, 0x16, 0x00}, \
  {0x5206, 0x00, 0x00}, \
  {0x5207, 0x05, 0x00}, \
  {0x520B, 0x30, 0x00}, \
  {0x520C, 0x75, 0x00}, \
  {0x520D, 0x00, 0x00}, \
  {0x520E, 0x30, 0x00}, \
  {0x520F, 0x75, 0x00}, \
  {0x5210, 0x00, 0x00}, \
  {0x5280, 0x14, 0x00}, \
  {0x5281, 0x02, 0x00}, \
  {0x5282, 0x02, 0x00}, \
  {0x5283, 0x04, 0x00}, \
  {0x5284, 0x06, 0x00}, \
  {0x5285, 0x08, 0x00}, \
  {0x5286, 0x0C, 0x00}, \
  {0x5287, 0x10, 0x00}, \
  {0x5300, 0xC5, 0x00}, \
  {0x5301, 0xA0, 0x00}, \
  {0x5302, 0x06, 0x00}, \
  {0x5303, 0x0A, 0x00}, \
  {0x5304, 0x30, 0x00}, \
  {0x5305, 0x60, 0x00}, \
  {0x5306, 0x90, 0x00}, \
  {0x5307, 0xC0, 0x00}, \
  {0x5308, 0x82, 0x00}, \
  {0x5309, 0x00, 0x00}, \
  {0x530A, 0x26, 0x00}, \
  {0x530B, 0x02, 0x00}, \
  {0x530C, 0x02, 0x00}, \
  {0x530D, 0x00, 0x00}, \
  {0x530E, 0x0C, 0x00}, \
  {0x530F, 0x14, 0x00}, \
  {0x5310, 0x1A, 0x00}, \
  {0x5311, 0x20, 0x00}, \
  {0x5312, 0x80, 0x00}, \
  {0x5313, 0x4B, 0x00}, \
  {0x5380, 0x01, 0x00}, \
  {0x5381, 0x52, 0x00}, \
  {0x5382, 0x00, 0x00}, \
  {0x5383, 0x4A, 0x00}, \
  {0x5384, 0x00, 0x00}, \
  {0x5385, 0xB6, 0x00}, \
  {0x5386, 0x00, 0x00}, \
  {0x5387, 0x8D, 0x00}, \
  {0x5388, 0x00, 0x00}, \
  {0x5389, 0x3A, 0x00}, \
  {0x538A, 0x00, 0x00}, \
  {0x538B, 0xA6, 0x00}, \
  {0x538C, 0x00, 0x00}, \
  {0x5400, 0x0D, 0x00}, \
  {0x5401, 0x18, 0x00}, \
  {0x5402, 0x31, 0x00}, \
  {0x5403, 0x5A, 0x00}, \
  {0x5404, 0x65, 0x00}, \
  {0x5405, 0x6F, 0x00}, \
  {0x5406, 0x77, 0x00}, \
  {0x5407, 0x80, 0x00}, \
  {0x5408, 0x87, 0x00}, \
  {0x5409, 0x8F, 0x00}, \
  {0x540A, 0xA2, 0x00}, \
  {0x540B, 0xB2, 0x00}, \
  {0x540C, 0xCC, 0x00}, \
  {0x540D, 0xE4, 0x00}, \
  {0x540E, 0xF0, 0x00}, \
  {0x540F, 0xA0, 0x00}, \
  {0x5410, 0x6E, 0x00}, \
  {0x5411, 0x06, 0x00}, \
  {0x5480, 0x19, 0x00}, \
  {0x5481, 0x00, 0x00}, \
  {0x5482, 0x09, 0x00}, \
  {0x5483, 0x12, 0x00}, \
  {0x5484, 0x04, 0x00}, \
  {0x5485, 0x06, 0x00}, \
  {0x5486, 0x08, 0x00}, \
  {0x5487, 0x0C, 0x00}, \
  {0x5488, 0x10, 0x00}, \
  {0x5489, 0x18, 0x00}, \
  {0x5500, 0x02, 0x00}, \
  {0x5501, 0x03, 0x00}, \
  {0x5502, 0x04, 0x00}, \
  {0x5503, 0x05, 0x00}, \
  {0x5504, 0x06, 0x00}, \
  {0x5505, 0x08, 0x00}, \
  {0x5506, 0x00, 0x00}, \
  {0x5600, 0x02, 0x00}, \
  {0x5603, 0x40, 0x00}, \
  {0x5604, 0x28, 0x00}, \
  {0x5609, 0x20, 0x00}, \
  {0x560A, 0x60, 0x00}, \
  {0x5780, 0x3E, 0x00}, \
  {0x5781, 0x0F, 0x00}, \
  {0x5782, 0x04, 0x00}, \
  {0x5783, 0x02, 0x00}, \
  {0x5784, 0x01, 0x00}, \
  {0x5785, 0x01, 0x00}, \
  {0x5786, 0x00, 0x00}, \
  {0x5787, 0x04, 0x00}, \
  {0x5788, 0x02, 0x00}, \
  {0x5789, 0x00, 0x00}, \
  {0x578A, 0x01, 0x00}, \
  {0x578B, 0x02, 0x00}, \
  {0x578C, 0x03, 0x00}, \
  {0x578D, 0x03, 0x00}, \
  {0x578E, 0x08, 0x00}, \
  {0x578F, 0x0C, 0x00}, \
  {0x5790, 0x08, 0x00}, \
  {0x5791, 0x04, 0x00}, \
  {0x5792, 0x00, 0x00}, \
  {0x5793, 0x00, 0x00}, \
  {0x5794, 0x03, 0x00}, \
  {0x5800, 0x03, 0x00}, \
  {0x5801, 0x24, 0x00}, \
  {0x5802, 0x02, 0x00}, \
  {0x5803, 0x40, 0x00}, \
  {0x5804, 0x34, 0x00}, \
  {0x5805, 0x05, 0x00}, \
  {0x5806, 0x12, 0x00}, \
  {0x5807, 0x05, 0x00}, \
  {0x5808, 0x03, 0x00}, \
  {0x5809, 0x3C, 0x00}, \
  {0x580A, 0x02, 0x00}, \
  {0x580B, 0x40, 0x00}, \
  {0x580C, 0x26, 0x00}, \
  {0x580D, 0x05, 0x00}, \
  {0x580E, 0x52, 0x00}, \
  {0x580F, 0x06, 0x00}, \
  {0x5810, 0x03, 0x00}, \
  {0x5811, 0x28, 0x00}, \
  {0x5812, 0x02, 0x00}, \
  {0x5813, 0x40, 0x00}, \
  {0x5814, 0x24, 0x00}, \
  {0x5815, 0x05, 0x00}, \
  {0x5816, 0x42, 0x00}, \
  {0x5817, 0x06, 0x00}, \
  {0x5818, 0x0D, 0x00}, \
  {0x5819, 0x40, 0x00}, \
  {0x581A, 0x04, 0x00}, \
  {0x581B, 0x0C, 0x00}, \
  {0x3A03, 0x4C, 0x00}, \
  {0x3A04, 0x40, 0x00}, \
  {0x3080, 0x02, 0x00}, \
  {0x3082, 0x48, 0x00}, \
  {0x3018, 0x44, 0x00}, \
  {0x3084, 0x0F, 0x00}, \
  {0x3085, 0x06, 0x00}, \
  {0x380d, 0xc8, 0x00}, \
  {0x380f, 0x10, 0x00}, \
  {0x4837, 0x12, 0x00}, \
  {0x3002, 0x00, 0x00}, \
  {0x3823, 0x30, 0x00}, \
  {0x3824, 0x00, 0x00}, \
  {0x3825, 0x10, 0x00}, \
  {0x3826, 0x00, 0x00}, \
  {0x3827, 0x08, 0x00}, \
}

static sensor_lib_t sensor_lib_ptr =
{
  .sensor_slave_info =
  {
    .sensor_name = SENSOR_MODEL,
    .slave_addr = 0x78,
    .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .sensor_id_info =
    {
      .sensor_id_reg_addr = 0x300A,
      .sensor_id = 0x2685,
    },
    .power_setting_array =
    {
      .power_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 5,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_HIGH,
          .delay = 10,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 5,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_HIGH,
          .delay = 10,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 24000000,
          .delay = 10,
        },
      },
      .size = 8,
      .power_down_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
      },
      .size_down = 6,
    },
  },
  .sensor_output =
  {
    .output_format = SENSOR_YCBCR,
    .connection_mode = SENSOR_MIPI_CSI,
    .raw_output = SENSOR_8_BIT_DIRECT,
    .filter_arrangement = SENSOR_YUYV,
  },
  .output_reg_addr =
  {
    .x_output = 0x3808,
    .y_output = 0x380A,
    .line_length_pclk = 0x380C,
    .frame_length_lines = 0x380E,
  },
  .exp_gain_info =
  {
    .coarse_int_time_addr = 0x3501,
    .global_gain_addr = 0x350A,
    .vert_offset = 4,
  },
  .aec_info =
  {
    .min_gain = 1.0,
    .max_gain = 15.5,
    .max_analog_gain = 15.5,
    .max_linecount = 0xFFFF,
  },
  .sensor_num_frame_skip = 3,
  .sensor_num_HDR_frame_skip = 3,
  .sensor_max_pipeline_frame_delay = 2,
  .sensor_property =
  {
    .pix_size = 1.75,
    .sensing_method = SENSOR_SMETHOD_NOT_DEFINED,
    .crop_factor = 1.0,
  },
  .pixel_array_size_info =
  {
    .active_array_size =
    {
      .width = 1600,
      .height = 1200,
    },
    .left_dummy = 8,
    .right_dummy = 8,
    .top_dummy = 8,
    .bottom_dummy = 8,
  },
  .sensor_stream_info_array =
  {
    .sensor_stream_info =
    {
      {
        .vc_cfg_size = 1,
        .vc_cfg =
        {
          {
            .cid = 0,
            .dt = CSI_YUV422_8,
            .decode_format = CSI_DECODE_8BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_YCBCR,
        },
      },
    },
    .size = 1,
  },
  .start_settings =
  {
    .reg_setting_a = START_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .stop_settings =
  {
    .reg_setting_a = STOP_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .groupon_settings =
  {
    .reg_setting_a = GROUPON_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .groupoff_settings =
  {
    .reg_setting_a = GROUPOFF_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .res_settings_array =
  {
    .reg_settings =
    {
      /* Res 0 */
      {
        .reg_setting_a = RES0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
    },
    .size = 1,
  },
  .out_info_array =
  {
    .out_info =
    {
      /* Res 0 */
      /* size=1600x1200, HTS=1736, VTS=1296 */
      {
        .x_output = 1600 * 2,
        .y_output = 1200,
        .line_length_pclk = 1736 * 2,
        .frame_length_lines = 1296,
        .op_pixel_clk = 132000000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 24.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 1.000,
      },
    },
    .size = 1,
  },
  .csi_params =
  {
    .lane_cnt = 1,
    .settle_cnt = 0x16,
    .is_csi_3phase = 0,
  },
  .csid_lut_params_array =
  {
    .lut_params =
    {
      /* Res 0 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_YUV422_8,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
    },
    .size = 1,
  },
  .crop_params_array =
  {
    .crop_params =
    {
      /* Res 0 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
    },
    .size = 1,
  },
  .exposure_func_table =
  {
    .sensor_calculate_exposure = sensor_calculate_exposure,
    .sensor_fill_exposure_array = sensor_fill_exposure_array,
  },
};

#endif
