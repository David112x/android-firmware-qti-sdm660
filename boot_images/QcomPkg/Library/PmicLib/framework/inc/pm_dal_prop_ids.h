#ifndef PM_DAL_PROP_IDS_H
#define PM_DAL_PROP_IDS_H
/*! \file
 *
 *  \brief  pm_dal_prop_id.h ----This file contains all the available PMIC DAL device config property values.
 *  \details This file contains all the available PMIC DAL device config property values.
 *
 *  &copy; Copyright 2013-2017 Qualcomm Technologies Incorporated, All Rights Reserved
 */

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This document is created by a code generator, therefore this section will
  not contain comments describing changes made to the module.


when        who     what, where, why
--------    ----    ---------------------------------------------------------
05/23/17    sv      Added Dal support for AFP temparature config.
02/10/17    mr      Added DAL Prop for RGB-LPG Channel mapping
11/15/16    mr      Added support for OLEDB and LCDB
05/27/16    pxm     Add PM_PROP_SBL_CHG_WIPOWER_SPECIFIC_DATA
04/29/16    aab     Adding PM_PROP_SBL_PON_SPECIFIC_DATA
03/24/16    al      Add keypress support
11/03/15    al      Updated for rails
07/10/15    al      Adding support for HP type
06/25/15    al      Porting changes
03/05/14    aab     Updated to the latest PMIC driver architecture
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES

===========================================================================*/

//PMIC HW peripheral specific dal properties -- starting from 1
#define PM_PROP_CLK_REG                            1   //"PM_PROP_CLK_REG"
#define PM_PROP_SMPS_REG                           2   //"PM_PROP_SMPS_REG"
#define PM_PROP_LDO_REG                            3   //"PM_PROP_LDO_REG"
#define PM_PROP_VS_REG                             4   //"PM_PROP_VS_REG"
#define PM_PROP_BOOST_REG                          5   //"PM_PROP_BOOST_REG"
#define PM_PROP_FTS_VOLT                           6   //"PM_PROP_FTS_VOLT"
#define PM_PROP_HFS_VOLT                           7   //"PM_PROP_HFS_VOLT"
#define PM_PROP_BOOST_VOLT                         8   //"PM_PROP_BOOST_VOLT"
#define PM_PROP_NMOS_VOLT                          9   //"PM_PROP_NMOS_VOLT"
#define PM_PROP_N600_VOLT                         10   //"PM_PROP_N600_VOLT"
#define PM_PROP_N1200_VOLT                        11   //"PM_PROP_N1200_VOLT"
#define PM_PROP_PMOS_VOLT                         12   //"PM_PROP_PMOS_VOLT"
#define PM_PROP_LN_VOLT                           13   //"PM_PROP_LN_VOLT"
#define PM_PROP_FTS_RANGE                         14   //"PM_PROP_FTS_RANGE"
#define PM_PROP_HFS_RANGE                         15   //"PM_PROP_HFS_RANGE"
#define PM_PROP_BOOST_RANGE                       16   //"PM_PROP_BOOST_RANGE"
#define PM_PROP_NMOS_RANGE                        17   //"PM_PROP_NMOS_RANGE"
#define PM_PROP_N600_RANGE                        18   //"PM_PROP_N600_RANGE"
#define PM_PROP_N1200_RANGE                       19   //"PM_PROP_N1200_RANGE"
#define PM_PROP_PMOS_RANGE                        20   //"PM_PROP_PMOS_RANGE"
#define PM_PROP_LN_RANGE                          21   //"PM_PROP_LN_RANGE"
#define PM_PROP_CLK_SLEEP_REG                     22   //"PM_PROP_CLK_SLEEP_REG"
#define PM_PROP_CLK_XO_REG                        23   //"PM_PROP_CLK_XO_REG"
#define PM_PROP_CLK_COMMON                        24   //"PM_PROP_CLK_COMMON"
#define PM_PROP_GPIO_REG                          25   //"PM_PROP_GPIO_REG"
#define PM_PROP_MPP_REG                           26   //"PM_PROP_MPP_REG"
#define PM_PROP_RGB_REG                           27   //"PM_PROP_RGB_REG"
#define PM_PROP_LPG_REG                           28   //"PM_PROP_LPG_REG"
#define PM_PROP_LPG_SPECIFIC_DATA                 29   //"PM_PROP_LPG_SPECIFIC_DATA"
#define PM_PROP_VIB_REG                           30   //"PM_PROP_VIB_REG"
#define PM_PROP_WLED_REG                          31   //"PM_PROP_WLED_REG"
#define PM_PROP_PBS_CLIENT_REG                    32   //"PM_PROP_PBS_CLIENT_REG"
#define PM_PROP_VIB_DATA                          33   //"PM_PROP_VIB_DATA"
#define PM_PROP_WLED_DATA                         34   //"PM_PROP_WLED_DATA"
#define PM_PROP_SMPSA_PHASE_LUT                   35   //"PM_PROP_SMPSA_PHASE_LUT"
#define PM_PROP_MPP_SPECIFIC_DATA                 36   //"PM_PROP_MPP_SPECIFIC_DATA"
#define PM_PROP_SBL_REG_CONFIG_LUT                37   //"PM_PROP_SBL_REG_CONFIG_LUT"
#define PM_PROP_PBS_RAM_CONFIG_LUT                38   //"PM_PROP_PBS_RAM_CONFIG_LUT"
#define PM_PROP_SMPS_ILIMIT_LUT                   39   //"PM_PROP_SMPS_ILIMIT_LUT"
#define PM_PROP_FTS2p5_VOLT                       40   //"PM_PROP_FTS2p5_VOLT"
#define PM_PROP_FTS2p5_RANGE                      41   //"PM_PROP_FTS2p5_RANGE"
#define PM_PROP_CHARGER_REG                       42   //"PM_PROP_CHARGER_REG"
#define PM_PROP_CHARGER_DATA                      43   //"PM_PROP_CHARGER_DATA"
#define PM_PROP_IBB_REG                           44   //"PM_PROP_IBB_REG"
#define PM_PROP_LAB_REG                           45   //"PM_PROP_LAB_REG"
#define PM_PROP_RTC_REG                           46   //"PM_PROP_RTC_REG"
#define PM_PROP_PWM_REG                           47   //"PM_PROP_PWM_REG"
#define PM_PROP_FG_REG                            48   //"PM_PROP_FG_REG"
#define PM_PROP_CHARGER_SPECIFIC_DATA             49   //"PM_PROP_CHARGER_SPECIFIC_DATA"
#define PM_PROP_FG_SPECIFIC_DATA                  50   //"PM_PROP_FG_SPECIFIC_DATA"
#define PM_PROP_PBS_CUSTOM_SEQ_DATA               51
#define PM_PROP_PBS_INFO                          52
#define PM_PROP_SETTINGS_TEST_FLAG_REG            53
#define PM_PROP_SBL_CHG_SPECIFIC_DATA             54
#define PM_PROP_HAPTICS_REG                       55   //"PM_PROP_HAPTICS_REG"
#define PM_PROP_HP_VOLT                           56   //"PM_PROP_HP_VOLT"
#define PM_PROP_HP_RANGE                          57   //"PM_PROP_HP_RANGE"
#define PM_PROP_COINCELL_REG                      58
#define PM_PROP_ULT_BUCK_RANGE_1                  59
#define PM_PROP_ULT_BUCK_VOLT_1                   60
#define PM_PROP_ULT_BUCK_RANGE_2                  61
#define PM_PROP_ULT_BUCK_VOLT_2                   62
#define PM_PROP_ULT_PMOS_RANGE                    63
#define PM_PROP_ULT_PMOS_VOLT                     64
#define PM_PROP_ULT_NMOS_RANGE                    65
#define PM_PROP_ULT_NMOS_VOLT                     66
#define PM_PROP_SBL_CHG_JETTA_CONFIG_DATA         67
#define PM_PROP_SBL_CHG_BATT_THERM_CONFIG_DATA    68
#define PM_PROP_SBL_PON_SPECIFIC_DATA             69
#define PM_PROP_SBL_CHG_WIPOWER_SPECIFIC_DATA     70
#define PM_PROP_SBL_SPECIFIC_DATA                 71
#define PM_PROP_OLEDB_REG                         72
#define PM_PROP_LCDB_REG                          73
#define PM_PROP_APP_CHG_TEMP_MONITOR_CONFIG_DATA  74
#define PM_PROP_APP_CHG_TEMP_LIMIT_CONFIG_DATA    75


//Target/power grid specific dal properties -- starting from 101
#define PM_PROP_PMIC_NUM                         101    //"PM_PROP_PMIC_NUM"
#define PM_PROP_SMPS_NUM                         102    //"PM_PROP_SMPS_NUM"
#define PM_PROP_CLK_NUM                          103    //"PM_PROP_CLK_NUM"
#define PM_PROP_LDO_NUM                          104    //"PM_PROP_LDO_NUM"
#define PM_PROP_VS_NUM                           105    //"PM_PROP_VS_NUM"
#define PM_PROP_BOOST_NUM                        106    //"PM_PROP_BOOST_NUM"
#define PM_PROP_GPIO_NUM                         107    //"PM_PROP_GPIO_NUM"
#define PM_PROP_MPP_NUM                          108    //"PM_PROP_MPP_NUM"
#define PM_PROP_LPG_NUM                          109    //"PM_PROP_LPG_NUM"
#define PM_PROP_RGB_NUM                          110    //"PM_PROP_RGB_NUM"
#define PM_PROP_VIB_NUM                          111    //"PM_PROP_VIB_NUM"
#define PM_PROP_WLED_NUM                         112    //"PM_PROP_WLED_NUM"
#define PM_PROP_CHARGER_NUM                      113    //"PM_PROP_SMBCHG_NUM"
#define PM_PROP_IBB_NUM                          114    //"PM_PROP_IBB_NUM"
#define PM_PROP_LAB_NUM                          115    //"PM_PROP_LAB_NUM"
#define PM_PROP_RTC_NUM                          116    //"PM_PROP_RTC_NUM"
#define PM_PROP_MX                               117    //"PM_PROP_MX"
#define PM_PROP_CX                               118    //"PM_PROP_CX"
#define PM_PROP_MSS                              119    //"PM_PROP_MSS"
#define PM_PROP_PAM_NODE_RSRCS                   120    //"PM_PROP_PAM_NODE_RSRCS"
#define PM_PROP_PAM_NODE_NUM                     121    //"PM_PROP_PAM_NODE_NUM"
#define PM_PROP_REMOTE_LDO                       122    //"PM_PROP_REMOTE_LDO"
#define PM_PROP_REMOTE_CLK                       123    //"PM_PROP_REMOTE_CLK"
#define PM_PROP_REMOTE_SMPS                      124    //"PM_PROP_REMOTE_SMPS"
#define PM_PROP_REMOTE_VS                        125    //"PM_PROP_REMOTE_VS"

#define PM_PROP_FG_NUM                           126  //"PM_PROP_FG_NUM"
#define PM_PROP_PBS_CLIENT_NUM                   127  //"PM_PROP_PBS_CLIENT_NUM"
#define PM_PROP_FGB_NUM                          128  //"PM_PROP_FGB_NUM"

#define PM_PROP_NUMBER_PERIPHERAL                129
#define PM_PROP_SPMI_PERIPH_CFG                  130

#define PM_PROP_PERIPH_BITMAP                    131

#define PM_PROP_HAPTICS_NUM                      132    //"PM_PROP_HAPTICS_NUM"
#define PM_PROP_COINCELL_NUM                     133
#define PM_PROP_LONG_PWRKEY_HOLD_BOOT_TIME       134    //"PM_PROP_LONG_PWRKEY_HOLD_BOOT_TIME"
#define PM_PROP_RGB_LPG_CHAN_MAP                 135


#endif // PM_DAL_PROP_IDS_H
