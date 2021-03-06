#ifndef AUDIO_FTM_AFE_LOOPBACK_H
#define AUDIO_FTM_AFE_LOOPBACK_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

/**
  @file audio_ftm_afe_loopback.h
  @brief  Audio FTM AFE Loopback Driver API
====================================================================================================
Copyright (c) 2011, 2017 Qualcomm Technologies, Inc.  All Rights Reserved.
Qualcomm Technologies Proprietary and Confidential.

$Header: //source/qcom/qct/multimedia2/Audio/drivers/ftm/8x60/linux/rel/1.0/inc/audio_ftm_afe_loopback.h#1 $
$DateTime: 2011/04/05 20:05:46 $
$Author: zhongl $

Revision History:
                            Modification     Tracking
Author (core ID)                Date         CR Number   Description of Changes
-------------------------   ------------    ----------   -------------------------------------------
ZhongL                      05/30/2010                    File creation.



====================================================================================================
                                         INCLUDE FILES
==================================================================================================*/

#include "DALSYS_common.h"
#include "audio_ftm_driver_fwk.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/



/*==================================================================================================
                                            MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATION
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

AUDIO_FTM_STS_T
audio_ftm_afe_lp_attach
(
    void *,                             /* Input: parameters  */
    AUDIO_FTM_DRIVER_HANDLE_T *       /* Output: driver handle */
);

AUDIO_FTM_STS_T
audio_ftm_afe_lp_open
(
    AUDIO_FTM_DRIVER_HANDLE_T,         /* Input: driver handle */
    AUD_FTM_ACCESS_MODE_T AccessMode,  /* Input: Access mode */
    AUD_FTM_SHARE_MODE_T  ShareMode,   /* Input: Share mode */
    AUDIO_FTM_CLIENT_HANDLE_T *        /* Output: client handle */
);

AUDIO_FTM_STS_T
audio_ftm_afe_lp_close
(
    AUDIO_FTM_CLIENT_HANDLE_T         /* Input: client handle */
);

AUDIO_FTM_STS_T
audio_ftm_afe_lp_read
(
);

AUDIO_FTM_STS_T
audio_ftm_afe_lp_write
(
);

AUDIO_FTM_STS_T
audio_ftm_afe_lp_iocontrol
(
    AUDIO_FTM_CLIENT_HANDLE_T,        /* Input: client handle */
    uint32 dwIOCode,                  /* Input: IOControl command */
    uint8 * pBufIn                    /* Input: buffer pointer for input parameters */
);

AUDIO_FTM_STS_T
audio_ftm_afe_lp_detach
(
    AUDIO_FTM_DRIVER_HANDLE_T
);

/*=================================================================================================*/
#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* AUDIO_FTM_AFE_LOOPBACK_H */


