/*
Copyright (c) 2019 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

Copyright (c) 2015, The Linux Foundation. All rights reserved.

*/

#ifndef __RADIO_CHEROKEE_COMMANDS_H
#define __RADIO_CHEROKEE_COMMANDS_H

enum helium_cmd_t {
    HCI_FM_HELIUM_SRCHMODE = 0x8000000 + 1,
    HCI_FM_HELIUM_SCANDWELL,
    HCI_FM_HELIUM_SRCHON,
    HCI_FM_HELIUM_STATE,
    HCI_FM_HELIUM_TRANSMIT_MODE,
    HCI_FM_HELIUM_RDSGROUP_MASK,
    HCI_FM_HELIUM_REGION,
    HCI_FM_HELIUM_SIGNAL_TH,
    HCI_FM_HELIUM_SRCH_PTY,
    HCI_FM_HELIUM_SRCH_PI,
    HCI_FM_HELIUM_SRCH_CNT,
    HCI_FM_HELIUM_EMPHASIS,
    HCI_FM_HELIUM_RDS_STD,
    HCI_FM_HELIUM_SPACING,
    HCI_FM_HELIUM_RDSON,
    HCI_FM_HELIUM_RDSGROUP_PROC,
    HCI_FM_HELIUM_LP_MODE,
    HCI_FM_HELIUM_ANTENNA,
    HCI_FM_HELIUM_RDSD_BUF,
    HCI_FM_HELIUM_PSALL,

    /*v4l2 Tx controls*/
    HCI_FM_HELIUM_IOVERC = 0x8000000 + 24,
    HCI_FM_HELIUM_INTDET,
    HCI_FM_HELIUM_MPX_DCC,
    HCI_FM_HELIUM_AF_JUMP,
    HCI_FM_HELIUM_RSSI_DELTA,
    HCI_FM_HELIUM_HLSI,

    /*Diagnostic commands*/
    HCI_FM_HELIUM_SOFT_MUTE,
    HCI_FM_HELIUM_RIVA_ACCS_ADDR,
    HCI_FM_HELIUM_RIVA_ACCS_LEN,
    HCI_FM_HELIUM_RIVA_PEEK,
    HCI_FM_HELIUM_RIVA_POKE,
    HCI_FM_HELIUM_SSBI_ACCS_ADDR,
    HCI_FM_HELIUM_SSBI_PEEK,
    HCI_FM_HELIUM_SSBI_POKE,
    HCI_FM_HELIUM_TX_TONE,
    HCI_FM_HELIUM_RDS_GRP_COUNTERS,
    HCI_FM_HELIUM_SET_NOTCH_FILTER, /* 0x8000028 */
    HCI_FM_HELIUM_SET_AUDIO_PATH,
    HCI_FM_HELIUM_DO_CALIBRATION,
    HCI_FM_HELIUM_SRCH_ALGORITHM,
    HCI_FM_HELIUM_GET_SINR,
    HCI_FM_HELIUM_INTF_LOW_THRESHOLD,
    HCI_FM_HELIUM_INTF_HIGH_THRESHOLD,
    HCI_FM_HELIUM_SINR_THRESHOLD,
    HCI_FM_HELIUM_SINR_SAMPLES,
    HCI_FM_HELIUM_SPUR_FREQ,
    HCI_FM_HELIUM_SPUR_FREQ_RMSSI,
    HCI_FM_HELIUM_SPUR_SELECTION,
    HCI_FM_HELIUM_UPDATE_SPUR_TABLE,
    HCI_FM_HELIUM_VALID_CHANNEL,
    HCI_FM_HELIUM_AF_RMSSI_TH,
    HCI_FM_HELIUM_AF_RMSSI_SAMPLES,
    HCI_FM_HELIUM_GOOD_CH_RMSSI_TH,
    HCI_FM_HELIUM_SRCHALGOTYPE,
    HCI_FM_HELIUM_CF0TH12,
    HCI_FM_HELIUM_SINRFIRSTSTAGE,
    HCI_FM_HELIUM_RMSSIFIRSTSTAGE,
    HCI_FM_HELIUM_RXREPEATCOUNT,
    HCI_FM_HELIUM_RSSI_TH,
    HCI_FM_HELIUM_AF_JUMP_RSSI_TH,
    HCI_FM_HELIUM_BLEND_SINRHI,
    HCI_FM_HELIUM_BLEND_RMSSIHI,
    HCI_FM_HELIUM_RDS_GRP_COUNTERS_EXT,
    HCI_FM_HELIUM_AGC_UCCTRL = 0x8000043, /* 0x8000043 */
    HCI_FM_HELIUM_AGC_GAIN_STATE,
    HCI_FM_HELIUM_ENABLE_LPF,

    /*using private CIDs under userclass*/
    HCI_FM_HELIUM_AUDIO_MUTE = 0x980909,
    HCI_FM_HELIUM_READ_DEFAULT = 0x00980928,
    HCI_FM_HELIUM_WRITE_DEFAULT,
    HCI_FM_HELIUM_SET_CALIBRATION,
    HCI_FM_HELIUM_SET_SPURTABLE = 0x0098092D,
    HCI_FM_HELIUM_GET_SPUR_TBL  = 0x0098092E,
    HCI_FM_HELIUM_FREQ,
    HCI_FM_HELIUM_SEEK,
    HCI_FM_HELIUM_UPPER_BAND,
    HCI_FM_HELIUM_LOWER_BAND,
    HCI_FM_HELIUM_AUDIO_MODE,
    HCI_FM_HELIUM_RMSSI,
    HCI_FM_HELIUM_AF_ALGO,
    HCI_FM_HELIUM_AF_SINR_GD_CH_TH,
    HCI_FM_HELIUM_AF_SINR_TH,

    /*FM VSC command to enable/disable slimbus data port*/
    HCI_FM_HELIUM_AUDIO = 0x00980940,
};
#endif /* __RADIO_CHEROKEE_COMMANDS_H */
