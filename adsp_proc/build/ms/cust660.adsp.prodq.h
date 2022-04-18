#ifndef CUST660_ADSP_PRODQ_H
#define CUST660_ADSP_PRODQ_H
/* ========================================================================
FILE: CUST660.ADSP.PRODQ

Copyright (c) 2020 by Qualcomm Technologies, Inc.  All Rights Reserved.
Qualcomm Technologies Proprietary and Confidential.        
=========================================================================== */

#ifndef TARG660_ADSP_PRODQ_H
   #include "targ660.adsp.prodq.h"
#endif

#define FEATURE_Q_NO_SELF_QPTR
#define FEATURE_QUEUE_USES_MUTEX
#define FEATURE_MEMHEAP_MT
#define DSMI_DS_SMALL_ITEM_CNT 10
#define COREMAIN_EXCLUDE_POSIX_TIMER
#define FEATURE_QURT
#define FEATURE_DAL
#define FEATURE_QUBE
#define DEVCFG_DATA_SEG_SIZE 0x1F000
#define DEVCFG_PLATFORM_DATA_SEG_SIZE 0x4000
#define FEATURE_SMEM
#define FEATURE_SMSM
#define FEATURE_SMEM_LOG
#define FEATURE_SMDL_LOOPBACK_TEST
#define SCL_APPS_BOOT_BASE 0x00000000
#define FEATURE_SAVE_L1DCACHE 1
#define SCL_APPS_BOOT_SIZE 0x0100000




#endif /* CUST660_ADSP_PRODQ_H */
