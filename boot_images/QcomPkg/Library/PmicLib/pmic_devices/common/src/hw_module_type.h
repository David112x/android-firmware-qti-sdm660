#ifndef HW_MODULE_TYPE_H
#define HW_MODULE_TYPE_H

/*! \ file hw_module_type.h
*
 * \brief   <Brief Comment Block/>
 * \details <Detailed Comment Block/>
 * \n &copy; Copyright 2012 - 2016 QUALCOMM Technologies Incorporated, All Rights Reserved
 */

/*===========================================================================

						EDIT HISTORY FOR MODULE
						
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when        who     what, where, why
--------    ----    ---------------------------------------------------------
11/15/16    mr      Added support for OLEDB and LCDB
01/09/16    ps      Added support for PM660 and PM660L PMICs (CR-1074489)
07/18/16    llioe   Updated FG modules
11/03/15    al      Updated for rails
06/30/15    al      Adding Haptics support
07/24/15    al      Added HP
===========================================================================*/

/*===========================================================================

                        TYPES DEFINITIONS

===========================================================================*/
typedef enum
{
    PM_HW_MODULE_Reserved = 0,
    PM_HW_MODULE_PON = 1,
    PM_HW_MODULE_CHARGER = 2,
    PM_HW_MODULE_HF_BUCK = 3,
    PM_HW_MODULE_LDO = 4,
    PM_HW_MODULE_VS = 5,
    PM_HW_MODULE_CLOCK = 6,
    PM_HW_MODULE_RTC = 7,
    PM_HW_MODULE_ADC = 8,
    PM_HW_MODULE_ALARM = 9,
    PM_HW_MODULE_INTERRUPT = 10,
    PM_HW_MODULE_INTERFACE = 11,
    PM_HW_MODULE_TRIM = 12,
    PM_HW_MODULE_FG = 13,
    PM_HW_MODULE_MBG = 14,
    PM_HW_MODULE_LED_DRIVER = 15,
    PM_HW_MODULE_GPIO = 16,
    PM_HW_MODULE_MPP = 17,
    PM_HW_MODULE_KEYPAD = 18,
    PM_HW_MODULE_LPG = 19,
    PM_HW_MODULE_MISC = 20,
    PM_HW_MODULE_HAPTICS = 21,
    PM_HW_MODULE_PBS = 22,
    PM_HW_MODULE_WLED = 23,
    PM_HW_MODULE_FLASH = 24,
    PM_HW_MODULE_RGB = 25,
    PM_HW_MODULE_KEYPAD_BL = 26,
    PM_HW_MODULE_BOOST = 27,
    PM_HW_MODULE_FTS = 28,
    PM_HW_MODULE_BUCK_CMN = 29,
    PM_HW_MODULE_PWM = 30,
    PM_HW_MODULE_BOOST_BYP = 31,
    PM_HW_MODULE_IBB = 32,
    PM_HW_MODULE_ULT_LDO = 33,
    PM_HW_MODULE_ULT_BUCK = 34,
    PM_HW_MODULE_LAB = 36,
    PM_HW_MODULE_HP_BUCK = 38,
    PM_HW_MODULE_BOB = 41,
    PM_HW_MODULE_OLEDB = 44,
    PM_HW_MODULE_LCDB = 45,
    PM_HW_MODULE_INVALID
}pm_hw_module_type;

typedef enum
{
    PM_HW_MODULE_WLED_Reserved = 0,
    PM_HW_MODULE_WLED_MAIN = 1,
    PM_HW_MODULE_WLED_SINK = 8,
    PM_HW_MODULE_WLED_INVALID
}pm_hw_module_wled_subtype;

typedef enum
{
    PM_HW_MODULE_PON_Reserved = 0,
    PM_HW_MODULE_PON_LV_PON = 1,
    PM_HW_MODULE_PON_LV_PON_GEN2_PRIMARY = 4,
    PM_HW_MODULE_PON_LV_PON_GEN2_SECONDARY = 5,
    PM_HW_MODULE_PON_INVALID
}pm_hw_module_pon_subtype;

typedef enum
{
    PM_HW_MODULE_CHARGER_Reserved = 0,
    PM_HW_MODULE_CHARGER_SMBCHG_CHGR = 1,
    PM_HW_MODULE_CHARGER_SMBCHG_BAT_IF = 3,
    PM_HW_MODULE_CHARGER_SMBCHG_USB_CHGPTH = 4,
    PM_HW_MODULE_CHARGER_SMBCHG_DC_CHGPTH = 5,
    PM_HW_MODULE_CHARGER_SMBCHG_MISC = 7,
    PM_HW_MODULE_CHARGER_SMBCHG_OTG = 8,
    PM_HW_MODULE_CHARGER_LIN_CHGR = 21,
    PM_HW_MODULE_CHARGER_LIN_BAT_IF = 22 ,
    PM_HW_MODULE_CHARGER_LIN_USB = 23,
    PM_HW_MODULE_CHARGER_LIN_MISC = 24,
    PM_HW_MODULE_CHARGER_COINCELL = 32,
    PM_HW_MODULE_CHARGER_INVALID

}pm_hw_module_charger_subtype;

typedef enum
{
    PM_HW_MODULE_FG_Reserved = 0,
    PM_HW_MODULE_FG_LMH = 11,
    PM_HW_MODULE_FG_MEM_IF = 13,
    PM_HW_MODULE_FG_BATT_SOC = 16,
    PM_HW_MODULE_FG_BATT_INFO = 17,
    PM_HW_MODULE_FG_BCL = 18,
    PM_HW_MODULE_FG_ADC_RR = 19,
    PM_HW_MODULE_FG_FT_HDR = 20,
    PM_HW_MODULE_FG_INVALID
}pm_hw_module_fg_subtype;

typedef enum
{
    PM_HW_MODULE_HF_BUCK_Reserved = 0,
    PM_HW_MODULE_HF_BUCK_PS1X = 1,
    PM_HW_MODULE_HF_BUCK_PS2X = 2,
    PM_HW_MODULE_HF_BUCK_PS3X = 3,
    PM_HW_MODULE_HF_BUCK_PS6X = 6,
    PM_HW_MODULE_HF_BUCK_GP_CTL = 8,
    PM_HW_MODULE_HF_BUCK_RF_CTL = 9,
    PM_HW_MODULE_HF_BUCK_VPWM_CTL = 10,
    PM_HW_MODULE_HF_BUCK_PSLV_0p5A = 16,
    PM_HW_MODULE_HF_BUCK_PSLV_1A = 17,
    PM_HW_MODULE_HF_BUCK_PSLV_1p5A = 18,
    PM_HW_MODULE_HF_BUCK_PSLV_2A = 19,
    PM_HW_MODULE_HF_BUCK_PSLV_2p5A = 20,
    PM_HW_MODULE_HF_BUCK_PSLV_3A = 21,
    PM_HW_MODULE_HF_BUCK_PSLV_3p5A = 22,
    PM_HW_MODULE_HF_BUCK_PSLV_4A = 23,
    PM_HW_MODULE_HF_BUCK_PSHV_0p5A = 32,
    PM_HW_MODULE_HF_BUCK_PSHV_1A = 33,
    PM_HW_MODULE_HF_BUCK_PSHV_1p5A = 34,
    PM_HW_MODULE_HF_BUCK_PSHV_2A = 35,
    PM_HW_MODULE_HF_BUCK_PSHV_2p5A = 36,
    PM_HW_MODULE_HF_BUCK_PSHV_3A = 37,
    PM_HW_MODULE_HF_BUCK_INVALID
}pm_hw_module_hf_buck_subtype;

typedef enum
{
    PM_HW_MODULE_HP_BUCK_Reserved = 0,
    PM_HW_MODULE_HP_BUCK_GP_CTL = 8,
    PM_HW_MODULE_HP_BUCK_INVALID
}pm_hw_module_hp_buck_subtype;

typedef enum
{
    PM_HW_MODULE_ULT_BUCK_Reserved = 0,
    PM_HW_MODULE_ULT_BUCK_CTL_LV = 13,
    PM_HW_MODULE_ULT_BUCK_CTL2 = 14,
    PM_HW_MODULE_ULT_BUCK_CTL3 = 15,
    PM_HW_MODULE_ULT_BUCK_CTL_MV = 16,
    PM_HW_MODULE_ULT_BUCK_INVALID
}pm_hw_module_ult_buck_subtype;

typedef enum
{
    PM_HW_MODULE_LDO_Reserved = 0,
    PM_HW_MODULE_LDO_N50 = 1,
    PM_HW_MODULE_LDO_N150 = 2,
    PM_HW_MODULE_LDO_N300 = 3,
    PM_HW_MODULE_LDO_N600 = 4,
    PM_HW_MODULE_LDO_N1200 = 5,
    PM_HW_MODULE_LDO_N600_STEPPER = 6,
    PM_HW_MODULE_LDO_N1200_STEPPER = 7,
    PM_HW_MODULE_LDO_P50 = 8,
    PM_HW_MODULE_LDO_P150 = 9,
    PM_HW_MODULE_LDO_P300 = 10,
    PM_HW_MODULE_LDO_P600 = 11,
    PM_HW_MODULE_LDO_P1200 = 12,
    PM_HW_MODULE_LDO_LN_LDO = 16,
    PM_HW_MODULE_LDO_N900_STEPPER = 20,
    PM_HW_MODULE_LDO_N300_STEPPER = 21,
    PM_HW_MODULE_LDO_USB_LDO = 24,
    PM_HW_MODULE_LDO_LV_P50 = 40,
    PM_HW_MODULE_LDO_LV_P150 = 41,
    PM_HW_MODULE_LDO_LV_P300 = 42,
    PM_HW_MODULE_LDO_LV_P600 = 43,
    PM_HW_MODULE_LDO_LV_P1200 = 44,
    PM_HW_MODULE_LDO_P450 = 45,
    PM_HW_MODULE_LDO_HT_N300_STEPPER = 48,
    PM_HW_MODULE_LDO_HT_N600_STEPPER = 49,
    PM_HW_MODULE_LDO_HT_N1200_STEPPER = 50,
    PM_HW_MODULE_LDO_HT_P50 = 52,
    PM_HW_MODULE_LDO_HT_P150 = 53,
    PM_HW_MODULE_LDO_HT_P300 = 54,
    PM_HW_MODULE_LDO_HT_P600 = 55,
    PM_HW_MODULE_LDO_HT_P1200 = 56,
    PM_HW_MODULE_LDO_HT_LV_P50 = 58,
    PM_HW_MODULE_LDO_HT_LV_P150 = 59,
    PM_HW_MODULE_LDO_HT_LV_P300 = 60,
    PM_HW_MODULE_LDO_HT_LV_P600 = 61,
    PM_HW_MODULE_LDO_HT_LV_P1200 = 62,
    PM_HW_MODULE_LDO_HT_P50_SP = 64,

    PM_HW_MODULE_LDO_440_N300_STEPPER = 66,
    PM_HW_MODULE_LDO_440_N600_STEPPER = 67,
    PM_HW_MODULE_LDO_440_N1200_STEPPER = 68,

    PM_HW_MODULE_LDO_440_P50 = 70,
    PM_HW_MODULE_LDO_440_P150 = 71,
    PM_HW_MODULE_LDO_440_P300 = 72,
    PM_HW_MODULE_LDO_440_P600 = 73,
    PM_HW_MODULE_LDO_440_P1200 = 74,

    PM_HW_MODULE_LDO_440_LV_P50 = 76,
    PM_HW_MODULE_LDO_440_LV_P150 = 77,
    PM_HW_MODULE_LDO_440_LV_P300 = 78,
    PM_HW_MODULE_LDO_440_LV_P600 = 79,
    PM_HW_MODULE_LDO_440_LV_P1200 = 80,

    PM_HW_MODULE_LDO_INVALID,
}pm_hw_module_ldo_subtype;

typedef enum
{
    PM_HW_MODULE_ULT_LDO_Reserved = 0,
    PM_HW_MODULE_ULT_LDO_N50 = 1,
    PM_HW_MODULE_ULT_LDO_N150 = 2,
    PM_HW_MODULE_ULT_LDO_N300 = 3,
    PM_HW_MODULE_ULT_LDO_N600 = 4,
    PM_HW_MODULE_ULT_LDO_N1200 = 5,
    PM_HW_MODULE_ULT_LDO_N600_STEPPER = 6,
    PM_HW_MODULE_ULT_LDO_N1200_STEPPER = 7,
    PM_HW_MODULE_ULT_LDO_P50 = 8,
    PM_HW_MODULE_ULT_LDO_P150 = 9,
    PM_HW_MODULE_ULT_LDO_P300 = 10,
    PM_HW_MODULE_ULT_LDO_P600 = 11,
    PM_HW_MODULE_ULT_LDO_P1200 = 12,
    PM_HW_MODULE_ULT_LDO_N900 = 19,
    PM_HW_MODULE_ULT_LDO_N900_STEPPER = 20,
    PM_HW_MODULE_ULT_LDO_N300_STEPPER = 21,
    PM_HW_MODULE_ULT_LDO_LV_P50 = 40,
    PM_HW_MODULE_ULT_LDO_LV_P150 = 41,
    PM_HW_MODULE_ULT_LDO_LV_P300 = 42,
    PM_HW_MODULE_ULT_LDO_LV_P600 = 43,
    PM_HW_MODULE_ULT_LDO_LV_P1200 = 44,
    PM_HW_MODULE_ULT_LDO_P450 = 45,
    PM_HW_MODULE_ULT_LDO_INVALID,
}pm_hw_module_ult_ldo_subtype;

typedef enum
{
    PM_HW_MODULE_VS_Reserved = 0,
    PM_HW_MODULE_VS_LV100 = 1,
    PM_HW_MODULE_VS_LV300 = 2,
    PM_HW_MODULE_VS_MV300 = 8,
    PM_HW_MODULE_VS_MV500 = 9,
    PM_HW_MODULE_VS_HDMI = 16,
    PM_HW_MODULE_VS_OTG = 17,
    PM_HW_MODULE_VS_INVALID,
}pm_hw_module_vs_subtype;

typedef enum
{
    PM_HW_MODULE_CLOCK_Reserved = 0,
    PM_HW_MODULE_CLOCK_XO_CORE = 1,
    PM_HW_MODULE_CLOCK_CLK_DIST = 2,
    PM_HW_MODULE_CLOCK_XO_CORE_38P4MHZ = 3,
    PM_HW_MODULE_CLOCK_BB_CLK = 8,
    PM_HW_MODULE_CLOCK_RF_CLK = 9,
    PM_HW_MODULE_CLOCK_DIFF_CLK = 10,
    PM_HW_MODULE_CLOCK_DIV_CLK = 11,
    PM_HW_MODULE_CLOCK_SLP_CLK = 12,
    PM_HW_MODULE_CLOCK_CALRC2 = 14,
    PM_HW_MODULE_CLOCK_INVALID,
}pm_hw_module_clk_subtype;

typedef enum
{
    PM_HW_MODULE_RTC_Reserved = 0,
    PM_HW_MODULE_RTC_RTC_RW = 1,
    PM_HW_MODULE_RTC_RTC_RO = 2,
    PM_HW_MODULE_RTC_RTC_ALARM = 3,
    PM_HW_MODULE_RTC_TIMER = 8,
    PM_HW_MODULE_RTC_INVALID,
}pm_hw_module_rtc_subtype;

typedef enum
{
    PM_HW_MODULE_ADC_Reserved = 0,
    PM_HW_MODULE_ADC_VADC1 = 1,
    PM_HW_MODULE_ADC_VADC2 = 2,
    PM_HW_MODULE_ADC_CCADC = 3,
    PM_HW_MODULE_ADC_INVALID,
}pm_hw_module_adc_subtype;

typedef enum
{
    PM_HW_MODULE_ALARM_Reserved = 0,
    PM_HW_MODULE_ALARM_BATT_ALARM = 1,
    PM_HW_MODULE_ALARM_TEMP_ALARM = 8,
    PM_HW_MODULE_ALARM_INVALID,
}pm_hw_module_alarm_subtype;

typedef enum
{
    PM_HW_MODULE_GPIO_Reserved = 0,
    PM_HW_MODULE_GPIO_GPIO = 1,
    PM_HW_MODULE_GPIO_GPIOC = 2,
    PM_HW_MODULE_GPIO_GPIOLV = 16,
    PM_HW_MODULE_GPIO_GPIOMV = 17,
    PM_HW_MODULE_GPIO_INVALID,
}pm_hw_module_gpio_subtype;

typedef enum
{
    PM_HW_MODULE_MISC_Reserved = 0,
    PM_HW_MODULE_MISC_MISC8941 = 1,
    PM_HW_MODULE_MISC_MISC8841 = 2,
    PM_HW_MODULE_MISC_INVALID,
}pm_hw_module_misc_subtype;

typedef enum
{
    PM_HW_MODULE_FTS__Reserved = 0,
    PM_HW_MODULE_FTS__PS1X = 1,
    PM_HW_MODULE_FTS__PS0p5X = 2,
    PM_HW_MODULE_FTS__FTS2p5_PS = 3,
    PM_HW_MODULE_FTS__FTS426_PS = 6,
    PM_HW_MODULE_FTS__FTS_CTL = 8,
    PM_HW_MODULE_FTS__FTS2p5_CTL = 9,
    PM_HW_MODULE_FTS__FTS426_CTL = 10,
    PM_HW_MODULE_FTS__INVALID,
}pm_hw_module_fts_subtype;

typedef enum
{
    PM_HW_MODULE_BUCK_CMN_Reserved = 0,
    PM_HW_MODULE_BUCK_CMN_BUCK_CMN1 = 1,
    PM_HW_MODULE_BUCK_CMN_BUCK_CMN2 = 2,
    PM_HW_MODULE_BUCK_CMN_INVALID,
}pm_hw_module_buck_cmn_subtype;

typedef enum
{
    PM_HW_MODULE_PBS_Reserved = 0,
    PM_HW_MODULE_PBS_CORE = 1,
    PM_HW_MODULE_PBS_CLIENT = 8,
    PM_HW_MODULE_PBS_CLIENT_1TRIG = 9,
    PM_HW_MODULE_PBS_CLIENT_4TRIG = 10,
    PM_HW_MODULE_PBS_INVALID,
}pm_hw_module_pbs_subtype;

typedef enum
{
    PM_HW_MODULE_LPG_Reserved = 0,
    PM_HW_MODULE_LPG_LUT  = 1,
    PM_HW_MODULE_LPG_CHAN = 2,
    PM_HW_MODULE_LPG_PWM = 11,
    PM_HW_MODULE_LPG_INVALID,
}pm_hw_module_lpg_subtype;

typedef enum
{
    PM_HW_MODULE_HAPTICS_Reserved = 0,
    PM_HW_MODULE_HAPTICS_VIB      = 0x1,
    PM_HW_MODULE_HAPTICS_HAPTICS  = 0x9,
}pm_hw_module_haptics_subtype;

#endif //HW_MODULE_TYPE_H
