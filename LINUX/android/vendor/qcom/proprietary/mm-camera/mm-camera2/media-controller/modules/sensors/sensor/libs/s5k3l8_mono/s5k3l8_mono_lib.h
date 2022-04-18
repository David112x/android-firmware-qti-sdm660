/* s5k3l8_mono_lib.h
 *
 *Copyright (c) 2015 Qualcomm Technologies, Inc.
 *All Rights Reserved.
 *Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef __S5K3L8_MONO_LIB_H__
#define __S5K3L8_MONO_LIB_H__

#include "sensor_lib.h"
#define SENSOR_MODEL "s5k3l8_mono"
/* s5k3l8 Regs */
#define S5K3L8_DIG_GAIN_GR_ADDR       0x020E /* 0x4000020E */
#define S5K3L8_DIG_GAIN_R_ADDR        0x0210 /* 0x40000210 */
#define S5K3L8_DIG_GAIN_B_ADDR        0x0212 /* 0x40000212 */
#define S5K3L8_DIG_GAIN_GB_ADDR       0x0214 /* 0x40000214 */

#define S5K3L8_DATA_PEDESTAL            0x40 /* 10bit */

#define S5K3L8_MIN_AGAIN_REG_VAL        0 /* 1.0x */
#define S5K3L8_MAX_AGAIN_REG_VAL        512 /* 16.0x */
#define S5K3L8_MIN_DGAIN_REG_VAL        256 /* 1.0x */
#define S5K3L8_MAX_DGAIN_REG_VAL        256 /* 1.0x */

/* s5k3l8 FORMULAS */
#define S5K3L8_MIN_AGAIN    (1.0)
#define S5K3L8_MAX_AGAIN    (S5K3L8_MAX_AGAIN_REG_VAL / 32)
#define S5K3L8_MIN_DGAIN    (S5K3L8_MIN_DGAIN_REG_VAL / 256)
#define S5K3L8_MAX_DGAIN    (S5K3L8_MAX_DGAIN_REG_VAL / 256)

int s5k3l8_calculate_exposure(float real_gain,
  unsigned int line_count, sensor_exposure_info_t *exp_info, float s_real_gain);


int s5k3l8_fill_exposure_array(unsigned int gain,
  __attribute__((unused)) unsigned int digital_gain, unsigned int line,
  unsigned int fl_lines,  __attribute__((unused)) int luma_avg,
  __attribute__((unused)) unsigned int hdr_param,
  struct camera_i2c_reg_setting* reg_setting,
  __attribute__((unused)) unsigned int s_gain,
  __attribute__((unused)) int s_linecount,
  __attribute__((unused)) int is_hdr_enabled);

#define START_REG_ARRAY \
{ \
  {0x6028, 0x4000, 0x00}, \
  {0x0100, 0x0100, 0x00}, \
}

#define STOP_REG_ARRAY \
{ \
  {0x0100, 0x0000, 0x00}, \
}

#define GROUPON_REG_ARRAY \
{ \
  {0x0104, 0x01, 0x00}, \
}

#define GROUPOFF_REG_ARRAY \
{ \
  {0x0104, 0x00, 0x00}, \
}

#define INIT0_REG_ARRAY \
{ \
  /* Page pointer HW */ \
  {0x6028, 0x4000, 0x00}, \
  {0x6214, 0xFFFF, 0x00}, \
  /* Clock on */ \
  {0x6216, 0xFFFF, 0x00}, \
  {0x6218, 0x0000, 0x00}, \
  {0x621A, 0x0000, 0x00}, \
  /* TnP for dual sync, SWregister setting */ \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x2450, 0x00}, \
  {0x6F12, 0x0448, 0x00}, \
  {0x6F12, 0x0349, 0x00}, \
  {0x6F12, 0x0160, 0x00}, \
  {0x6F12, 0xC26A, 0x00}, \
  {0x6F12, 0x511A, 0x00}, \
  {0x6F12, 0x8180, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x83B8, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x262C, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x16C0, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x10B5, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0xA9F8, 0x00}, \
  {0x6F12, 0x4948, 0x00}, \
  {0x6F12, 0x4078, 0x00}, \
  {0x6F12, 0x0028, 0x00}, \
  {0x6F12, 0x0AD0, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0xA8F8, 0x00}, \
  {0x6F12, 0x4749, 0x00}, \
  {0x6F12, 0xB1F8, 0x00}, \
  {0x6F12, 0x1403, 0x00}, \
  {0x6F12, 0x4200, 0x00}, \
  {0x6F12, 0x4648, 0x00}, \
  {0x6F12, 0x4282, 0x00}, \
  {0x6F12, 0x91F8, 0x00}, \
  {0x6F12, 0x9610, 0x00}, \
  {0x6F12, 0x4187, 0x00}, \
  {0x6F12, 0x10BD, 0x00}, \
  {0x6F12, 0x70B5, 0x00}, \
  {0x6F12, 0x0446, 0x00}, \
  {0x6F12, 0x4348, 0x00}, \
  {0x6F12, 0x0022, 0x00}, \
  {0x6F12, 0x4068, 0x00}, \
  {0x6F12, 0x86B2, 0x00}, \
  {0x6F12, 0x050C, 0x00}, \
  {0x6F12, 0x3146, 0x00}, \
  {0x6F12, 0x2846, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x98F8, 0x00}, \
  {0x6F12, 0x2046, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x9AF8, 0x00}, \
  {0x6F12, 0x14F8, 0x00}, \
  {0x6F12, 0x680F, 0x00}, \
  {0x6F12, 0x6178, 0x00}, \
  {0x6F12, 0x40EA, 0x00}, \
  {0x6F12, 0x4100, 0x00}, \
  {0x6F12, 0x3949, 0x00}, \
  {0x6F12, 0xC886, 0x00}, \
  {0x6F12, 0x3A48, 0x00}, \
  {0x6F12, 0x2278, 0x00}, \
  {0x6F12, 0x007C, 0x00}, \
  {0x6F12, 0x4240, 0x00}, \
  {0x6F12, 0x3548, 0x00}, \
  {0x6F12, 0xA230, 0x00}, \
  {0x6F12, 0x8378, 0x00}, \
  {0x6F12, 0x43EA, 0x00}, \
  {0x6F12, 0xC202, 0x00}, \
  {0x6F12, 0x0378, 0x00}, \
  {0x6F12, 0x4078, 0x00}, \
  {0x6F12, 0x9B00, 0x00}, \
  {0x6F12, 0x43EA, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
  {0x6F12, 0x0243, 0x00}, \
  {0x6F12, 0xD0B2, 0x00}, \
  {0x6F12, 0x0882, 0x00}, \
  {0x6F12, 0x3146, 0x00}, \
  {0x6F12, 0x2846, 0x00}, \
  {0x6F12, 0xBDE8, 0x00}, \
  {0x6F12, 0x7040, 0x00}, \
  {0x6F12, 0x0122, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x76B8, 0x00}, \
  {0x6F12, 0x2DE9, 0x00}, \
  {0x6F12, 0xF041, 0x00}, \
  {0x6F12, 0x0546, 0x00}, \
  {0x6F12, 0x2C48, 0x00}, \
  {0x6F12, 0x0E46, 0x00}, \
  {0x6F12, 0x8268, 0x00}, \
  {0x6F12, 0x140C, 0x00}, \
  {0x6F12, 0x97B2, 0x00}, \
  {0x6F12, 0x0022, 0x00}, \
  {0x6F12, 0x3946, 0x00}, \
  {0x6F12, 0x2046, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x69F8, 0x00}, \
  {0x6F12, 0x3146, 0x00}, \
  {0x6F12, 0x2846, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x6FF8, 0x00}, \
  {0x6F12, 0x8046, 0x00}, \
  {0x6F12, 0x0122, 0x00}, \
  {0x6F12, 0x3946, 0x00}, \
  {0x6F12, 0x2046, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x5FF8, 0x00}, \
  {0x6F12, 0x244A, 0x00}, \
  {0x6F12, 0xB2F8, 0x00}, \
  {0x6F12, 0xD802, 0x00}, \
  {0x6F12, 0x0128, 0x00}, \
  {0x6F12, 0x03D1, 0x00}, \
  {0x6F12, 0x2248, 0x00}, \
  {0x6F12, 0xB0F8, 0x00}, \
  {0x6F12, 0xE210, 0x00}, \
  {0x6F12, 0x11B1, 0x00}, \
  {0x6F12, 0x0020, 0x00}, \
  {0x6F12, 0xBDE8, 0x00}, \
  {0x6F12, 0xF081, 0x00}, \
  {0x6F12, 0xD0F8, 0x00}, \
  {0x6F12, 0xEC00, 0x00}, \
  {0x6F12, 0x1F4B, 0x00}, \
  {0x6F12, 0x05FB, 0x00}, \
  {0x6F12, 0x0601, 0x00}, \
  {0x6F12, 0xD2F8, 0x00}, \
  {0x6F12, 0xEC02, 0x00}, \
  {0x6F12, 0xB3F9, 0x00}, \
  {0x6F12, 0x0220, 0x00}, \
  {0x6F12, 0x8C1A, 0x00}, \
  {0x6F12, 0xA042, 0x00}, \
  {0x6F12, 0x01DD, 0x00}, \
  {0x6F12, 0x8842, 0x00}, \
  {0x6F12, 0x03DD, 0x00}, \
  {0x6F12, 0x0028, 0x00}, \
  {0x6F12, 0x03DB, 0x00}, \
  {0x6F12, 0x9042, 0x00}, \
  {0x6F12, 0x01DA, 0x00}, \
  {0x6F12, 0x0120, 0x00}, \
  {0x6F12, 0x00E0, 0x00}, \
  {0x6F12, 0x0020, 0x00}, \
  {0x6F12, 0x1880, 0x00}, \
  {0x6F12, 0x4046, 0x00}, \
  {0x6F12, 0xE5E7, 0x00}, \
  {0x6F12, 0x10B5, 0x00}, \
  {0x6F12, 0x0022, 0x00}, \
  {0x6F12, 0xAFF2, 0x00}, \
  {0x6F12, 0xFB01, 0x00}, \
  {0x6F12, 0x1348, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x43F8, 0x00}, \
  {0x6F12, 0x0C4C, 0x00}, \
  {0x6F12, 0x0022, 0x00}, \
  {0x6F12, 0xAFF2, 0x00}, \
  {0x6F12, 0xE501, 0x00}, \
  {0x6F12, 0x2060, 0x00}, \
  {0x6F12, 0x1048, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x3BF8, 0x00}, \
  {0x6F12, 0x0122, 0x00}, \
  {0x6F12, 0xAFF2, 0x00}, \
  {0x6F12, 0x9701, 0x00}, \
  {0x6F12, 0x6060, 0x00}, \
  {0x6F12, 0x0D48, 0x00}, \
  {0x6F12, 0x00F0, 0x00}, \
  {0x6F12, 0x34F8, 0x00}, \
  {0x6F12, 0x0949, 0x00}, \
  {0x6F12, 0xA060, 0x00}, \
  {0x6F12, 0x0020, 0x00}, \
  {0x6F12, 0x0880, 0x00}, \
  {0x6F12, 0x10BD, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x0550, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x0C60, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
  {0x6F12, 0xD000, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x2620, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x16F0, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x1B70, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x0B50, 0x00}, \
  {0x6F12, 0x2000, 0x00}, \
  {0x6F12, 0x4900, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x2221, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x2249, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x4073, 0x00}, \
  {0x6F12, 0x42F2, 0x00}, \
  {0x6F12, 0x351C, 0x00}, \
  {0x6F12, 0xC0F2, 0x00}, \
  {0x6F12, 0x000C, 0x00}, \
  {0x6F12, 0x6047, 0x00}, \
  {0x6F12, 0x42F2, 0x00}, \
  {0x6F12, 0xE11C, 0x00}, \
  {0x6F12, 0xC0F2, 0x00}, \
  {0x6F12, 0x000C, 0x00}, \
  {0x6F12, 0x6047, 0x00}, \
  {0x6F12, 0x40F2, 0x00}, \
  {0x6F12, 0x077C, 0x00}, \
  {0x6F12, 0xC0F2, 0x00}, \
  {0x6F12, 0x000C, 0x00}, \
  {0x6F12, 0x6047, 0x00}, \
  {0x6F12, 0x42F2, 0x00}, \
  {0x6F12, 0x492C, 0x00}, \
  {0x6F12, 0xC0F2, 0x00}, \
  {0x6F12, 0x000C, 0x00}, \
  {0x6F12, 0x6047, 0x00}, \
  {0x6F12, 0x44F2, 0x00}, \
  {0x6F12, 0x730C, 0x00}, \
  {0x6F12, 0xC0F2, 0x00}, \
  {0x6F12, 0x000C, 0x00}, \
  {0x6F12, 0x6047, 0x00}, \
  {0x6F12, 0x4BF2, 0x00}, \
  {0x6F12, 0x453C, 0x00}, \
  {0x6F12, 0xC0F2, 0x00}, \
  {0x6F12, 0x000C, 0x00}, \
  {0x6F12, 0x6047, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x30C8, 0x00}, \
  {0x6F12, 0x0163, 0x00}, \
  {0x6F12, 0x0000, 0x00}, \
  {0x6F12, 0x000B, 0x00}, \
  /* Global, Analog setting */ \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x1082, 0x00}, \
  {0x6F12, 0x8010, 0x00}, \
  {0x6028, 0x4000, 0x00}, \
  {0x31CE, 0x0001, 0x00}, \
  {0x0200, 0x00C6, 0x00}, \
  {0x3734, 0x0010, 0x00}, \
  {0x3736, 0x0001, 0x00}, \
  {0x3738, 0x0001, 0x00}, \
  {0x37CC, 0x0000, 0x00}, \
  {0x3744, 0x0100, 0x00}, \
  {0x3762, 0x0105, 0x00}, \
  {0x3764, 0x0105, 0x00}, \
  {0x376A, 0x00F0, 0x00}, \
  {0x344A, 0x000F, 0x00}, \
  {0x344C, 0x003D, 0x00}, \
  {0xF460, 0x0030, 0x00}, \
  {0xF414, 0x24C2, 0x00}, \
  {0xF416, 0x0183, 0x00}, \
  {0xF468, 0x0405, 0x00}, \
  {0x3424, 0x0A07, 0x00}, \
  {0x3426, 0x0F07, 0x00}, \
  {0x3428, 0x0F07, 0x00}, \
  {0x341E, 0x0804, 0x00}, \
  {0x3420, 0x0C0C, 0x00}, \
  {0x3422, 0x2D2D, 0x00}, \
  {0xF462, 0x003A, 0x00}, \
  {0x3450, 0x0010, 0x00}, \
  {0x3452, 0x0010, 0x00}, \
  {0xF446, 0x0020, 0x00}, \
  {0xF44E, 0x000C, 0x00}, \
  {0x31FA, 0x0007, 0x00}, \
  {0x31FC, 0x0161, 0x00}, \
  {0x31FE, 0x0009, 0x00}, \
  {0x3200, 0x000C, 0x00}, \
  {0x3202, 0x007F, 0x00}, \
  {0x3204, 0x00A2, 0x00}, \
  {0x3206, 0x007D, 0x00}, \
  {0x3208, 0x00A4, 0x00}, \
  {0x3334, 0x00A7, 0x00}, \
  {0x3336, 0x00A5, 0x00}, \
  {0x3338, 0x0033, 0x00}, \
  {0x333A, 0x0006, 0x00}, \
  {0x333C, 0x009F, 0x00}, \
  {0x333E, 0x008C, 0x00}, \
  {0x3340, 0x002D, 0x00}, \
  {0x3342, 0x000A, 0x00}, \
  {0x3344, 0x002F, 0x00}, \
  {0x3346, 0x0008, 0x00}, \
  {0x3348, 0x009F, 0x00}, \
  {0x334A, 0x008C, 0x00}, \
  {0x334C, 0x002D, 0x00}, \
  {0x334E, 0x000A, 0x00}, \
  {0x3350, 0x000A, 0x00}, \
  {0x320A, 0x007B, 0x00}, \
  {0x320C, 0x0161, 0x00}, \
  {0x320E, 0x007F, 0x00}, \
  {0x3210, 0x015F, 0x00}, \
  {0x3212, 0x007B, 0x00}, \
  {0x3214, 0x00B0, 0x00}, \
  {0x3216, 0x0009, 0x00}, \
  {0x3218, 0x0038, 0x00}, \
  {0x321A, 0x0009, 0x00}, \
  {0x321C, 0x0031, 0x00}, \
  {0x321E, 0x0009, 0x00}, \
  {0x3220, 0x0038, 0x00}, \
  {0x3222, 0x0009, 0x00}, \
  {0x3224, 0x007B, 0x00}, \
  {0x3226, 0x0001, 0x00}, \
  {0x3228, 0x0010, 0x00}, \
  {0x322A, 0x00A2, 0x00}, \
  {0x322C, 0x00B1, 0x00}, \
  {0x322E, 0x0002, 0x00}, \
  {0x3230, 0x015D, 0x00}, \
  {0x3232, 0x0001, 0x00}, \
  {0x3234, 0x015D, 0x00}, \
  {0x3236, 0x0001, 0x00}, \
  {0x3238, 0x000B, 0x00}, \
  {0x323A, 0x0016, 0x00}, \
  {0x323C, 0x000D, 0x00}, \
  {0x323E, 0x001C, 0x00}, \
  {0x3240, 0x000D, 0x00}, \
  {0x3242, 0x0054, 0x00}, \
  {0x3244, 0x007B, 0x00}, \
  {0x3246, 0x00CC, 0x00}, \
  {0x3248, 0x015D, 0x00}, \
  {0x324A, 0x007E, 0x00}, \
  {0x324C, 0x0095, 0x00}, \
  {0x324E, 0x0085, 0x00}, \
  {0x3250, 0x009D, 0x00}, \
  {0x3252, 0x008D, 0x00}, \
  {0x3254, 0x009D, 0x00}, \
  {0x3256, 0x007E, 0x00}, \
  {0x3258, 0x0080, 0x00}, \
  {0x325A, 0x0001, 0x00}, \
  {0x325C, 0x0005, 0x00}, \
  {0x325E, 0x0085, 0x00}, \
  {0x3260, 0x009D, 0x00}, \
  {0x3262, 0x0001, 0x00}, \
  {0x3264, 0x0005, 0x00}, \
  {0x3266, 0x007E, 0x00}, \
  {0x3268, 0x0080, 0x00}, \
  {0x326A, 0x0053, 0x00}, \
  {0x326C, 0x007D, 0x00}, \
  {0x326E, 0x00CB, 0x00}, \
  {0x3270, 0x015E, 0x00}, \
  {0x3272, 0x0001, 0x00}, \
  {0x3274, 0x0005, 0x00}, \
  {0x3276, 0x0009, 0x00}, \
  {0x3278, 0x000C, 0x00}, \
  {0x327A, 0x007E, 0x00}, \
  {0x327C, 0x0098, 0x00}, \
  {0x327E, 0x0009, 0x00}, \
  {0x3280, 0x000C, 0x00}, \
  {0x3282, 0x007E, 0x00}, \
  {0x3284, 0x0080, 0x00}, \
  {0x3286, 0x0044, 0x00}, \
  {0x3288, 0x0163, 0x00}, \
  {0x328A, 0x0045, 0x00}, \
  {0x328C, 0x0047, 0x00}, \
  {0x328E, 0x007D, 0x00}, \
  {0x3290, 0x0080, 0x00}, \
  {0x3292, 0x015F, 0x00}, \
  {0x3294, 0x0162, 0x00}, \
  {0x3296, 0x007D, 0x00}, \
  {0x3298, 0x0000, 0x00}, \
  {0x329A, 0x0000, 0x00}, \
  {0x329C, 0x0000, 0x00}, \
  {0x329E, 0x0000, 0x00}, \
  {0x32A0, 0x0008, 0x00}, \
  {0x32A2, 0x0010, 0x00}, \
  {0x32A4, 0x0018, 0x00}, \
  {0x32A6, 0x0020, 0x00}, \
  {0x32A8, 0x0000, 0x00}, \
  {0x32AA, 0x0008, 0x00}, \
  {0x32AC, 0x0010, 0x00}, \
  {0x32AE, 0x0018, 0x00}, \
  {0x32B0, 0x0020, 0x00}, \
  {0x32B2, 0x0020, 0x00}, \
  {0x32B4, 0x0020, 0x00}, \
  {0x32B6, 0x0020, 0x00}, \
  {0x32B8, 0x0000, 0x00}, \
  {0x32BA, 0x0000, 0x00}, \
  {0x32BC, 0x0000, 0x00}, \
  {0x32BE, 0x0000, 0x00}, \
  {0x32C0, 0x0000, 0x00}, \
  {0x32C2, 0x0000, 0x00}, \
  {0x32C4, 0x0000, 0x00}, \
  {0x32C6, 0x0000, 0x00}, \
  {0x32C8, 0x0000, 0x00}, \
  {0x32CA, 0x0000, 0x00}, \
  {0x32CC, 0x0000, 0x00}, \
  {0x32CE, 0x0000, 0x00}, \
  {0x32D0, 0x0000, 0x00}, \
  {0x32D2, 0x0000, 0x00}, \
  {0x32D4, 0x0000, 0x00}, \
  {0x32D6, 0x0000, 0x00}, \
  {0x32D8, 0x0000, 0x00}, \
  {0x32DA, 0x0000, 0x00}, \
  {0x32DC, 0x0000, 0x00}, \
  {0x32DE, 0x0000, 0x00}, \
  {0x32E0, 0x0000, 0x00}, \
  {0x32E2, 0x0000, 0x00}, \
  {0x32E4, 0x0000, 0x00}, \
  {0x32E6, 0x0000, 0x00}, \
  {0x32E8, 0x0000, 0x00}, \
  {0x32EA, 0x0000, 0x00}, \
  {0x32EC, 0x0000, 0x00}, \
  {0x32EE, 0x0000, 0x00}, \
  {0x32F0, 0x0000, 0x00}, \
  {0x32F2, 0x0000, 0x00}, \
  {0x32F4, 0x000A, 0x00}, \
  {0x32F6, 0x0002, 0x00}, \
  {0x32F8, 0x0008, 0x00}, \
  {0x32FA, 0x0010, 0x00}, \
  {0x32FC, 0x0020, 0x00}, \
  {0x32FE, 0x0028, 0x00}, \
  {0x3300, 0x0038, 0x00}, \
  {0x3302, 0x0040, 0x00}, \
  {0x3304, 0x0050, 0x00}, \
  {0x3306, 0x0058, 0x00}, \
  {0x3308, 0x0068, 0x00}, \
  {0x330A, 0x0070, 0x00}, \
  {0x330C, 0x0080, 0x00}, \
  {0x330E, 0x0088, 0x00}, \
  {0x3310, 0x0098, 0x00}, \
  {0x3312, 0x00A0, 0x00}, \
  {0x3314, 0x00B0, 0x00}, \
  {0x3316, 0x00B8, 0x00}, \
  {0x3318, 0x00C8, 0x00}, \
  {0x331A, 0x00D0, 0x00}, \
  {0x331C, 0x00E0, 0x00}, \
  {0x331E, 0x00E8, 0x00}, \
  {0x3320, 0x0017, 0x00}, \
  {0x3322, 0x002F, 0x00}, \
  {0x3324, 0x0047, 0x00}, \
  {0x3326, 0x005F, 0x00}, \
  {0x3328, 0x0077, 0x00}, \
  {0x332A, 0x008F, 0x00}, \
  {0x332C, 0x00A7, 0x00}, \
  {0x332E, 0x00BF, 0x00}, \
  {0x3330, 0x00D7, 0x00}, \
  {0x3332, 0x00EF, 0x00}, \
  {0x3352, 0x00A5, 0x00}, \
  {0x3354, 0x00AF, 0x00}, \
  {0x3356, 0x0187, 0x00}, \
  {0x3358, 0x0000, 0x00}, \
  {0x335A, 0x009E, 0x00}, \
  {0x335C, 0x016B, 0x00}, \
  {0x335E, 0x0015, 0x00}, \
  {0x3360, 0x00A5, 0x00}, \
  {0x3362, 0x00AF, 0x00}, \
  {0x3364, 0x01FB, 0x00}, \
  {0x3366, 0x0000, 0x00}, \
  {0x3368, 0x009E, 0x00}, \
  {0x336A, 0x016B, 0x00}, \
  {0x336C, 0x0015, 0x00}, \
  {0x336E, 0x00A5, 0x00}, \
  {0x3370, 0x00A6, 0x00}, \
  {0x3372, 0x0187, 0x00}, \
  {0x3374, 0x0000, 0x00}, \
  {0x3376, 0x009E, 0x00}, \
  {0x3378, 0x016B, 0x00}, \
  {0x337A, 0x0015, 0x00}, \
  {0x337C, 0x00A5, 0x00}, \
  {0x337E, 0x00A6, 0x00}, \
  {0x3380, 0x01FB, 0x00}, \
  {0x3382, 0x0000, 0x00}, \
  {0x3384, 0x009E, 0x00}, \
  {0x3386, 0x016B, 0x00}, \
  {0x3388, 0x0015, 0x00}, \
  {0x319A, 0x0005, 0x00}, \
  {0x1006, 0x0005, 0x00}, \
  {0x3416, 0x0001, 0x00}, \
  {0x308C, 0x0008, 0x00}, \
  {0x307C, 0x0240, 0x00}, \
  {0x375E, 0x0050, 0x00}, \
  {0x31CE, 0x0101, 0x00}, \
  {0x374E, 0x0007, 0x00}, \
  {0x3460, 0x0001, 0x00}, \
  {0x3052, 0x0002, 0x00}, \
  {0x3058, 0x0100, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x108A, 0x00}, \
  {0x6F12, 0x0359, 0x00}, \
  {0x6F12, 0x0100, 0x00}, \
}

#define RES0_REG_ARRAY \
{ \
  {0x6028, 0x4000, 0x00}, \
  {0x0100, 0x0000, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x0F74, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6028, 0x4000, 0x00}, \
  {0x0344, 0x0008, 0x00}, \
  {0x0346, 0x0008, 0x00}, \
  {0x0348, 0x1077, 0x00}, \
  {0x034A, 0x0C37, 0x00}, \
  {0x034C, 0x1070, 0x00}, \
  {0x034E, 0x0C30, 0x00}, \
  {0x0900, 0x0011, 0x00}, \
  {0x0380, 0x0001, 0x00}, \
  {0x0382, 0x0001, 0x00}, \
  {0x0384, 0x0001, 0x00}, \
  {0x0386, 0x0001, 0x00}, \
  {0x0400, 0x0000, 0x00}, \
  {0x0404, 0x0010, 0x00}, \
  {0x0114, 0x0300, 0x00}, \
  {0x0110, 0x0002, 0x00}, \
  {0x0136, 0x1800, 0x00}, \
  {0x0304, 0x0006, 0x00}, \
  {0x0306, 0x00B1, 0x00}, \
  {0x0302, 0x0001, 0x00}, \
  {0x0300, 0x0005, 0x00}, \
  {0x030C, 0x0006, 0x00}, \
  {0x030E, 0x0119, 0x00}, \
  {0x030A, 0x0001, 0x00}, \
  {0x0308, 0x0008, 0x00}, \
  {0x0342, 0x16B0, 0x00}, \
  {0x0340, 0x0CB2, 0x00}, \
  {0x0202, 0x0200, 0x00}, \
  {0x0200, 0x00C6, 0x00}, \
  {0x0B04, 0x0101, 0x00}, \
  {0x0B08, 0x0000, 0x00}, \
  {0x0B00, 0x0007, 0x00}, \
  {0x316A, 0x00A0, 0x00}, \
  /* Slave */ \
  {0x6028, 0x4000, 0x00}, \
  {0x3814, 0x0001, 0x00}, \
  {0x30C0, 0x0300, 0x00}, \
  {0x30BE, 0x0004, 0x00}, \
  {0x30C2, 0x0101, 0x00}, \
  {0x30C4, 0x0100, 0x00}, \
  {0x3812, 0x0002, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x4902, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
}

#define RES1_REG_ARRAY \
{ \
  {0x6028, 0x4000, 0x00}, \
  {0x0100, 0x0000, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x0F74, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6028, 0x4000, 0x00}, \
  {0x0344, 0x0008, 0x00}, \
  {0x0346, 0x0008, 0x00}, \
  {0x0348, 0x1077, 0x00}, \
  {0x034A, 0x0C37, 0x00}, \
  {0x034C, 0x0838, 0x00}, \
  {0x034E, 0x0618, 0x00}, \
  {0x0900, 0x0112, 0x00}, \
  {0x0380, 0x0001, 0x00}, \
  {0x0382, 0x0001, 0x00}, \
  {0x0384, 0x0001, 0x00}, \
  {0x0386, 0x0003, 0x00}, \
  {0x0400, 0x0001, 0x00}, \
  {0x0404, 0x0020, 0x00}, \
  {0x0114, 0x0300, 0x00}, \
  {0x0110, 0x0002, 0x00}, \
  {0x0136, 0x1800, 0x00}, \
  {0x0304, 0x0006, 0x00}, \
  {0x0306, 0x00B1, 0x00}, \
  {0x0302, 0x0001, 0x00}, \
  {0x0300, 0x0005, 0x00}, \
  {0x030C, 0x0006, 0x00}, \
  {0x030E, 0x0119, 0x00}, \
  {0x030A, 0x0001, 0x00}, \
  {0x0308, 0x0008, 0x00}, \
  {0x0342, 0x16B0, 0x00}, \
  {0x0340, 0x0CB2, 0x00}, \
  {0x0202, 0x0200, 0x00}, \
  {0x0200, 0x00C6, 0x00}, \
  {0x0B04, 0x0101, 0x00}, \
  {0x0B08, 0x0000, 0x00}, \
  {0x0B00, 0x0007, 0x00}, \
  {0x316A, 0x00A0, 0x00}, \
  /* Slave */ \
  {0x6028, 0x4000, 0x00}, \
  {0x3814, 0x0001, 0x00}, \
  {0x30C0, 0x0300, 0x00}, \
  {0x30BE, 0x0004, 0x00}, \
  {0x30C2, 0x0101, 0x00}, \
  {0x30C4, 0x0100, 0x00}, \
  {0x3812, 0x0002, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x4902, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
}

#define RES2_REG_ARRAY \
{ \
  {0x6028, 0x4000, 0x00}, \
  {0x0100, 0x0000, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x0F74, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6028, 0x4000, 0x00}, \
  {0x0344, 0x00C0, 0x00}, \
  {0x0346, 0x01E8, 0x00}, \
  {0x0348, 0x0FBF, 0x00}, \
  {0x034A, 0x0A57, 0x00}, \
  {0x034C, 0x0780, 0x00}, \
  {0x034E, 0x0438, 0x00}, \
  {0x0900, 0x0112, 0x00}, \
  {0x0380, 0x0001, 0x00}, \
  {0x0382, 0x0001, 0x00}, \
  {0x0384, 0x0001, 0x00}, \
  {0x0386, 0x0003, 0x00}, \
  {0x0400, 0x0001, 0x00}, \
  {0x0404, 0x0020, 0x00}, \
  {0x0114, 0x0300, 0x00}, \
  {0x0110, 0x0002, 0x00}, \
  {0x0136, 0x1800, 0x00}, \
  {0x0304, 0x0006, 0x00}, \
  {0x0306, 0x00B1, 0x00}, \
  {0x0302, 0x0001, 0x00}, \
  {0x0300, 0x0005, 0x00}, \
  {0x030C, 0x0006, 0x00}, \
  {0x030E, 0x0119, 0x00}, \
  {0x030A, 0x0001, 0x00}, \
  {0x0308, 0x0008, 0x00}, \
  {0x0342, 0x16B0, 0x00}, \
  {0x0340, 0x0659, 0x00}, \
  {0x0202, 0x0200, 0x00}, \
  {0x0200, 0x00C6, 0x00}, \
  {0x0B04, 0x0101, 0x00}, \
  {0x0B08, 0x0000, 0x00}, \
  {0x0B00, 0x0007, 0x00}, \
  {0x316A, 0x00A0, 0x00}, \
  /* Slave */ \
  {0x6028, 0x4000, 0x00}, \
  {0x3814, 0x0001, 0x00}, \
  {0x30C0, 0x0300, 0x00}, \
  {0x30BE, 0x0004, 0x00}, \
  {0x30C2, 0x0101, 0x00}, \
  {0x30C4, 0x0100, 0x00}, \
  {0x3812, 0x0002, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x4902, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
}

#define RES3_REG_ARRAY \
{ \
  {0x6028, 0x4000, 0x00}, \
  {0x0100, 0x0000, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x0F74, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6028, 0x4000, 0x00}, \
  {0x0344, 0x00C0, 0x00}, \
  {0x0346, 0x01E8, 0x00}, \
  {0x0348, 0x0FBF, 0x00}, \
  {0x034A, 0x0A57, 0x00}, \
  {0x034C, 0x0500, 0x00}, \
  {0x034E, 0x02D0, 0x00}, \
  {0x0900, 0x0113, 0x00}, \
  {0x0380, 0x0001, 0x00}, \
  {0x0382, 0x0001, 0x00}, \
  {0x0384, 0x0001, 0x00}, \
  {0x0386, 0x0005, 0x00}, \
  {0x0400, 0x0001, 0x00}, \
  {0x0404, 0x0030, 0x00}, \
  {0x0114, 0x0300, 0x00}, \
  {0x0110, 0x0002, 0x00}, \
  {0x0136, 0x1800, 0x00}, \
  {0x0304, 0x0006, 0x00}, \
  {0x0306, 0x00B1, 0x00}, \
  {0x0302, 0x0001, 0x00}, \
  {0x0300, 0x0005, 0x00}, \
  {0x030C, 0x0006, 0x00}, \
  {0x030E, 0x0119, 0x00}, \
  {0x030A, 0x0001, 0x00}, \
  {0x0308, 0x0008, 0x00}, \
  {0x0342, 0x16B0, 0x00}, \
  {0x0340, 0x043B, 0x00}, \
  {0x0202, 0x0200, 0x00}, \
  {0x0200, 0x00C6, 0x00}, \
  {0x0B04, 0x0101, 0x00}, \
  {0x0B08, 0x0000, 0x00}, \
  {0x0B00, 0x0007, 0x00}, \
  {0x316A, 0x00A0, 0x00}, \
  /* Slave */ \
  {0x6028, 0x4000, 0x00}, \
  {0x3814, 0x0001, 0x00}, \
  {0x30C0, 0x0300, 0x00}, \
  {0x30BE, 0x0004, 0x00}, \
  {0x30C2, 0x0101, 0x00}, \
  {0x30C4, 0x0100, 0x00}, \
  {0x3812, 0x0002, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x4902, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
}

#define RES4_REG_ARRAY \
{ \
  {0x6028, 0x4000, 0x00}, \
  {0x0100, 0x0000, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x0F74, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6F12, 0x0040, 0x00}, \
  {0x6028, 0x4000, 0x00}, \
  {0x0344, 0x00C0, 0x00}, \
  {0x0346, 0x01E8, 0x00}, \
  {0x0348, 0x0FBF, 0x00}, \
  {0x034A, 0x0A57, 0x00}, \
  {0x034C, 0x0500, 0x00}, \
  {0x034E, 0x02D0, 0x00}, \
  {0x0900, 0x0113, 0x00}, \
  {0x0380, 0x0001, 0x00}, \
  {0x0382, 0x0001, 0x00}, \
  {0x0384, 0x0001, 0x00}, \
  {0x0386, 0x0005, 0x00}, \
  {0x0400, 0x0001, 0x00}, \
  {0x0404, 0x0030, 0x00}, \
  {0x0114, 0x0300, 0x00}, \
  {0x0110, 0x0002, 0x00}, \
  {0x0136, 0x1800, 0x00}, \
  {0x0304, 0x0006, 0x00}, \
  {0x0306, 0x00B1, 0x00}, \
  {0x0302, 0x0001, 0x00}, \
  {0x0300, 0x0005, 0x00}, \
  {0x030C, 0x0006, 0x00}, \
  {0x030E, 0x0119, 0x00}, \
  {0x030A, 0x0001, 0x00}, \
  {0x0308, 0x0008, 0x00}, \
  {0x0342, 0x16B0, 0x00}, \
  {0x0340, 0x032C, 0x00}, \
  {0x0202, 0x0200, 0x00}, \
  {0x0200, 0x00C6, 0x00}, \
  {0x0B04, 0x0101, 0x00}, \
  {0x0B08, 0x0000, 0x00}, \
  {0x0B00, 0x0007, 0x00}, \
  {0x316A, 0x00A0, 0x00}, \
  /* Slave */ \
  {0x6028, 0x4000, 0x00}, \
  {0x3814, 0x0001, 0x00}, \
  {0x30C0, 0x0300, 0x00}, \
  {0x30BE, 0x0004, 0x00}, \
  {0x30C2, 0x0101, 0x00}, \
  {0x30C4, 0x0100, 0x00}, \
  {0x3812, 0x0002, 0x00}, \
  {0x6028, 0x2000, 0x00}, \
  {0x602A, 0x4902, 0x00}, \
  {0x6F12, 0x4000, 0x00}, \
}

/* Sensor Handler */
static sensor_lib_t sensor_lib_ptr =
{
  .sensor_slave_info =
  {
    .sensor_name = SENSOR_MODEL,
    .slave_addr = 0x5A,
    .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .sensor_id_info =
    {
      .sensor_id_reg_addr = 0x0000,
      .sensor_id = 0x30c8,
    },
    .power_setting_array =
    {
      .power_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
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
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 24000000,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
      },
      .size = 8,
      .power_down_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 0,
          .delay = 1,
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
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
      },
      .size_down = 6,
    },
  },
  .sensor_output =
  {
    .output_format = SENSOR_BAYER,
    .connection_mode = SENSOR_MIPI_CSI,
    .raw_output = SENSOR_10_BIT_DIRECT,
    .filter_arrangement = SENSOR_Y,
  },
  .output_reg_addr =
  {
    .x_output = 0x034C,
    .y_output = 0x034E,
    .line_length_pclk = 0x0342,
    .frame_length_lines = 0x0340,
  },
  .exp_gain_info =
  {
    .coarse_int_time_addr = 0x0202,
    .global_gain_addr = 0x0204,
    .vert_offset = 5,
  },
  .aec_info =
  {
    .min_gain = 1,
    .max_gain = 16.0,
    .max_analog_gain = 16.0,
    .max_linecount = 65535 - 4,
  },
  .sensor_num_frame_skip = 1,
  .sensor_num_HDR_frame_skip = 2,
  .sensor_max_pipeline_frame_delay = 2,
  .sensor_property =
  {
    .pix_size = 1.12,
    .sensing_method = SENSOR_SMETHOD_ONE_CHIP_COLOR_AREA_SENSOR,
  },
  .pixel_array_size_info =
  {
    .active_array_size =
    {
      .width = 4208,
      .height = 3120,
    },
    .left_dummy = 8,
    .right_dummy = 8,
    .top_dummy = 8,
    .bottom_dummy = 8,
  },
  .color_level_info =
  {
    .white_level = 1023,
    .r_pedestal = S5K3L8_DATA_PEDESTAL,
    .gr_pedestal = S5K3L8_DATA_PEDESTAL,
    .gb_pedestal = S5K3L8_DATA_PEDESTAL,
    .b_pedestal = S5K3L8_DATA_PEDESTAL,
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
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_BAYER,
        },
      },
    },
    .size = 1,
  },
  .start_settings =
  {
    .reg_setting_a = START_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_WORD_DATA,
    .delay = 0,
  },
  .stop_settings =
  {
    .reg_setting_a = STOP_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_WORD_DATA,
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
  .test_pattern_info =
  {
    .test_pattern_settings =
    {
      {
        .mode = SENSOR_TEST_PATTERN_OFF,
        .settings =
        {
          .reg_setting_a =
          {
            {0x6028, 0x4000, 0x00},
            {0x602A, 0x0600, 0x00},
            {0x6F12, 0x0000, 0x00},
          },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        }
      },
      {
        .mode = SENSOR_TEST_PATTERN_SOLID_COLOR,
        .settings =
        {
          .reg_setting_a =
          {
            {0x6028, 0x4000, 0x0000},
            {0x602A, 0x0600, 0x0000},
            {0x6F12, 0x0001, 0x0000},
          },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_COLOR_BARS,
        .settings =
        {
          .reg_setting_a =
          {
            {0x6028, 0x4000, 0x0000},
            {0x602A, 0x0600, 0x0000},
            {0x6F12, 0x0002, 0x0000},
          },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_COLOR_BARS_FADE_TO_GRAY,
        .settings =
        {
          .reg_setting_a =
          {
            {0x6028, 0x4000, 0x0000},
            {0x602A, 0x0600, 0x0000},
            {0x6F12, 0x0003, 0x0000},
          },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_PN9,
        .settings =
        {
          .reg_setting_a =
          {
            {0x6028, 0x4000, 0x0000},
            {0x602A, 0x0600, 0x0000},
            {0x6F12, 0x0004, 0x0000},
          },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_CUSTOM1, /* Macbeth */
        .settings =
        {
          .reg_setting_a =
          {
            {0x6028, 0x4000, 0x0000},
            {0x602A, 0x0600, 0x0000},
            {0x6F12, 0x0100, 0x0000},
          },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
    },
    .size = 6,
    .solid_mode_addr =
    {
      .r_addr = 0x0602,
      .gr_addr = 0x0604,
      .gb_addr = 0x0606,
      .b_addr = 0x0608,
    },
  },
  .init_settings_array =
  {
    .reg_settings =
    {
      {
        .reg_setting_a = INIT0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_WORD_DATA,
        .delay = 0,
      },
    },
    .size = 1,
  },
  .res_settings_array =
  {
    .reg_settings =
    {
      /* Res 0 */
      {
        .reg_setting_a = RES0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_WORD_DATA,
        .delay = 0,
      },
      /* Res 1 */
      {
        .reg_setting_a = RES1_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_WORD_DATA,
        .delay = 0,
      },
      /* Res 2 */
      {
        .reg_setting_a = RES2_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_WORD_DATA,
        .delay = 0,
      },
      /* Res 3 */
      {
        .reg_setting_a = RES3_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_WORD_DATA,
        .delay = 0,
      },
      /* Res 4 */
      {
        .reg_setting_a = RES4_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_WORD_DATA,
        .delay = 0,
      },
    },
    .size = 5,
  },
  .out_info_array =
  {
    .out_info =
    {
      /* Res 0 */
      {
        .x_output = 4208,
        .y_output = 3120,
        .line_length_pclk = 5808,
        .frame_length_lines = 3250,
        .op_pixel_clk = 449600000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 30.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 1 */
      {
        .x_output = 2104,
        .y_output = 1560,
        .line_length_pclk = 5808,
        .frame_length_lines = 3250,
        .op_pixel_clk = 449600000,
        .binning_factor = 2,
        .min_fps = 7.5,
        .max_fps = 30.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 2 */
      {
        .x_output = 1920,
        .y_output = 1080,
        .line_length_pclk = 5808,
        .frame_length_lines = 1625,
        .op_pixel_clk = 449600000,
        .binning_factor = 2,
        .min_fps = 7.5,
        .max_fps = 60.0,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 3 */
      {
        .x_output = 1280,
        .y_output = 720,
        .line_length_pclk = 5808,
        .frame_length_lines = 1083,
        .op_pixel_clk = 449600000,
        .binning_factor = 3,
        .min_fps = 7.5,
        .max_fps = 90.0,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 4 */
      {
        .x_output = 1280,
        .y_output = 720,
        .line_length_pclk = 5808,
        .frame_length_lines = 812,
        .op_pixel_clk = 449600000,
        .binning_factor = 3,
        .min_fps = 7.500,
        .max_fps = 120.0,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
    },
    .size = 5,
  },
  .csi_params =
  {
    .lane_cnt = 4,
    .settle_cnt = 0x14,
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
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 1 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 2 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 3 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 4 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
    },
    .size = 5,
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
      /* Res 1 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 2 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 3 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 4 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
    },
    .size = 5,
  },
  .exposure_func_table =
  {
    .sensor_calculate_exposure = s5k3l8_calculate_exposure,
    .sensor_fill_exposure_array = s5k3l8_fill_exposure_array,
  },
  .meta_data_out_info_array =
  {
    .meta_data_out_info =
    {
      {
        .width = 0,
        .height = 0,
        .stats_type = 0,
      },
    },
    .size = 0,
  },
  .sensor_capability = 0,
  .awb_func_table =
  {
    .sensor_fill_awb_array = 0,
    .awb_table_size = 0,
  },
  .rolloff_config =
  {
    .enable = FALSE,
    .full_size_info =
    {
      .full_size_width = 0,
      .full_size_height = 0,
      .full_size_left_crop = 0,
      .full_size_top_crop = 0,
    },
  },
  .adc_readout_time = 0,
  .sensor_num_fast_aec_frame_skip = 0,
  .noise_coeff = {
    .gradient_S = 3.738032e-06,
    .offset_S = 3.651935e-04,
    .gradient_O = 4.499952e-07,
    .offset_O = -2.968624e-04,
  },
};

#endif /* __s5k3l8_MONO_LIB_H__ */
