#ifndef DIAG_PARAM_H
/*==========================================================================

                     Diagnostic parameters Header File

Description
  Configuration parameters for a peripheral or PD.

Copyright (c) 2016-2017 by QUALCOMM Technologies, Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary

===========================================================================*/


/*===========================================================================

                         Edit History

      $Header: //components/rel/core.qdsp6/1.0.c2/services/diag/platform/cfg/adsp_core/diag_param.h#1 $

when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
05/25/17   ph      Separate macro to configure sensor PD buffer size.
02/21/17   ph      Tag DIAG ID header to all the diag packets sent out.
10/03/16   gn      Changes to support common PW for ADSP, CDSP and SLPI
===========================================================================*/
#include "diag_v.h"

#define DIAGDIAG_GET_CMD_REG_TBL DIAGDIAG_GET_CMD_REG_TBL_Q6

#define DIAGDIAG_START_STRESS_TEST_F DIAGDIAG_START_STRESS_TEST_QDSP_F
#define DIAGDIAG_STRESS_TEST_SUBSYS_LOOPBACK DIAGDIAG_STRESS_TEST_SUBSYS_LOOPBACK_Q6

#define DIAGDIAG_GET_ALLOC_COUNT_LOG DIAGDIAG_GET_ALLOC_COUNT_LOG_Q6
#define DIAGDIAG_GET_ALLOC_COUNT_F3 DIAGDIAG_GET_ALLOC_COUNT_F3_Q6
#define DIAGDIAG_GET_ALLOC_COUNT_EVENT DIAGDIAG_GET_ALLOC_COUNT_EVENT_Q6
#define DIAGDIAG_GET_ALLOC_COUNT_DELAY DIAGDIAG_GET_ALLOC_COUNT_DELAY_Q6

#define DIAGDIAG_GET_DROP_COUNT_LOG DIAGDIAG_GET_DROP_COUNT_LOG_Q6
#define DIAGDIAG_GET_DROP_COUNT_F3 DIAGDIAG_GET_DROP_COUNT_F3_Q6
#define DIAGDIAG_GET_DROP_COUNT_EVENT DIAGDIAG_GET_DROP_COUNT_EVENT_Q6
#define DIAGDIAG_GET_DROP_COUNT_DELAY DIAGDIAG_GET_DROP_COUNT_DELAY_Q6

#define DIAGDIAG_RESET_DROP_COUNT_LOG DIAGDIAG_RESET_DROP_COUNT_LOG_Q6
#define DIAGDIAG_RESET_DROP_COUNT_F3 DIAGDIAG_RESET_DROP_COUNT_F3_Q6
#define DIAGDIAG_RESET_DROP_COUNT_EVENT DIAGDIAG_RESET_DROP_COUNT_EVENT_Q6
#define DIAGDIAG_RESET_DROP_COUNT_DELAY DIAGDIAG_RESET_DROP_COUNT_DELAY_Q6

#define DIAGDIAG_LOG_MASK_RETRIEVAL DIAGDIAG_LOG_MASK_RETRIEVAL_Q6
#define DIAGDIAG_MSG_MASK_RETRIEVAL DIAGDIAG_MSG_MASK_RETRIEVAL_Q6
#define DIAGDIAG_EVENT_MASK_RETRIEVAL DIAGDIAG_EVENT_MASK_RETRIEVAL_Q6
#define DIAGDIAG_RETRIEVE_SSID_RANGE DIAGDIAG_RETRIEVE_SSID_RANGE_Q6
#define DIAGDIAG_RETRIEVE_EQUIP_ID_RANGE DIAGDIAG_RETRIEVE_EQUIP_ID_RANGE_Q6

#define DIAGDIAG_GET_FLOW_CTRL_COUNT DIAGDIAG_GET_FLOW_CTRL_COUNT_Q6
#define DIAGDIAG_RESET_FLOW_CTRL_COUNT DIAGDIAG_RESET_FLOW_CTRL_COUNT_Q6
#define DIAGDIAG_GET_TIME_API DIAGDIAG_GET_TIME_API_Q6

#define DIAG_MY_PROC_ID DIAG_QDSP6_PROC
#define DIAG_CTRL_MY_PROC_ID DIAG_CTRL_ADSP_PROC
#define DIAGDIAG_STRESS_TEST_DELAYED_RSP DIAGDIAG_STRESS_TEST_DELAYED_RSP_Q6
#define DIAGDIAG_TX_MODE_CONFIG DIAGDIAG_TX_MODE_CONFIG_Q6

#define DIAG_F3_TRACE_SET_CONFIG DIAG_F3_TRACE_SET_CONFIG_Q6

/* Priority change when using the QURT API (253 - old priority) */
#define DIAG_PRI 238 

/* Time (ms) for event stale timer */
#define EVENT_TIMER_LEN 1000 

/* Timer to drain data from DIAGBUF*/
#define DIAG_DRAIN_TIMER_LEN 200   

/* NRT mode parameters*/
#define DIAG_DRAIN_TIMER_LEN_NRT       0
#define EVENT_STALE_TIMER_LEN_NRT      0

/*Time (ms) to wait before notifying registered users about diag mask change*/
#define DIAG_MASK_NOTIFY_TIMER_LEN 60

#define DIAG_MULTIPD_DRAIN_TIMER_MIN 0
#define DIAG_MULTIPD_DRAIN_TIMER_MAX 1000
#define DIAG_MULTIPD_DRAIN_TIMER_DEFAULT 200

/* The max payload data item length */
#define EVENT_MAX_PAYLOAD_LEN 80 

/* Approximate event report packet size - to be used as a threshold - actual
   packet will be slightly larger. */
#define EVENT_RPT_PKT_SIZE 128
#define EVENT_RPT_PKT_SIZE_NRT (128)           /* NRT mode */

#define EVENT_SEND_MAX 50
#define EVENT_SEND_MAX_NRT 1024
#define EVENT_RPT_PKT_LEN_SIZE 		0x200
#define EVENT_RPT_PKT_LEN_SIZE_NRT 	0x1000

#ifndef DIAG_F3_TRACE_BUFFER_SIZE
#define DIAG_F3_TRACE_BUFFER_SIZE      131072
#endif

#define DIAG_SEND_BUF_SIZE_DATA 0x8000 /* Data Buffer size*/
#define DIAG_SEND_BUF_SIZE_DATA_SENSOR 0x8000
#define DIAG_SEND_BUF_SIZE_DATA_AUDIO  0x8000
#define DIAG_SEND_BUF_SIZE_CMD 0x8000 /* Cmd Buffer size*/
#define DIAG_MAX_SEND_DATA_SIZE 1024*8

#define DIAGBUF_SIZE (1024*32)   /* main DIAG buffer size */

#ifndef DIAG_MULTIPD_BUF_SIZE
#define DIAG_MULTIPD_BUF_SIZE 32768
#endif

#define DIAG_CTRL_BUF_SIZE (8*1024)   
#define DIAG_CTRL_RESEND_BUF_SIZE (16*1024)
#define DIAG_CTRL_SEND_BUF_SIZE  0x1000 //4k
#define DIAG_CTRL_READ_BUF_SIZE		      0x2000 //8k
#define DIAG_CMD_READ_BUF_SIZE		      0x4000 //16k
#define DIAG_MAX_SOCKETS_DATA_BLOCK_SIZE 0x4000 /* size of block that can be sent on the sockets channel */
#define DIAG_MAX_SMDL_DATA_BLOCK_SIZE 0x2000    /* size of block that can be sent on the SMDL channel */

#define DIAGBUF_COMMIT_THRESHOLD (1024*2)	               /* # of bytes committed to Diag buffer before draining. */
#define DIAG_CORE_PD_DRAIN_THRESHOLD 0x1000 //The number of bytes to drain from a buffer before moving onto the next one.
#define DIAGBUF_COMMIT_THRESHOLD_NRT (1024*16) /* non real time value that are used when diag is in power savings mode*/

#define DIAG_MULTIPD_BUF_COMMIT_THRESHOLD_PER_MIN 0
#define DIAG_MULTIPD_BUF_COMMIT_THRESHOLD_PER_MAX 100
#define DIAG_MULTIPD_BUF_COMMIT_THRESHOLD_PER_DEFAULT 13

#define DIAG_MULTIPD_BUF_DRAIN_THRESHOLD_PER_MIN 0
#define DIAG_MULTIPD_BUF_DRAIN_THRESHOLD_PER_MAX 100
#define DIAG_MULTIPD_BUF_DRAIN_THRESHOLD_PER_DEFAULT 13

#define DIAG_SEND_BUF_PAD_LEN 0x500
#define DIAG_SEND_BUF_PAD_LEN_NRT 0x1000

/*Pad length if HDLC encoding is enabled on peripheral */
#define DIAG_HDLC_PAD_LEN (150) 

#define DIAG_INST_ID_BASE 64  //ADSP sockets will range from 64-127

#define DIAG_SOCKET_INST_ID_CTRL (DIAG_INST_ID_BASE)
#define DIAG_SOCKET_INST_ID_CMD (DIAG_INST_ID_BASE+1)
#define DIAG_SOCKET_INST_ID_DATA (DIAG_INST_ID_BASE+2)
#define DIAG_SOCKET_INST_ID_DCI_CMD (DIAG_INST_ID_BASE+3)
#define DIAG_SOCKET_INST_ID_DCI_DATA (DIAG_INST_ID_BASE+4)

#define DIAG_MAX_NUM_SOCKETS 6

/*
Send buffer count is based on DIAG ID instances.
Each diagID need not be associated with a unique send buffer.
*/
#define DIAG_SEND_BUF_CNT 3

/* Index 0 is already reserved for local DIAG ID instance */
#define DIAG_DIAGID_AUDIO_USER_IDX    0x1
#define DIAG_DIAGID_SENSOR_USER_IDX   0x2

/* The size of the DIAG heap.  Currently, it is only used for events, response 
   packets and allocating tasks for stress testing.  DIAGBUF_SIZE only 
   impacts MSG and LOG packets. */
#ifndef DIAG_HEAP_SIZE   
#define DIAG_HEAP_SIZE (1024 * 8)
#endif

#define DIAG_EVENT_HEAP_SIZE (1024 * 2)
#define DIAG_EVENT_SEC_HEAP_SIZE (1024 * 2)
#define DIAG_MPD_EVENT_HEAP_SIZE (1024*2)

#define DIAG_MAX_ACTIVE_LISTENERS ( 18 ) /*Arbitrary limit on active listeners to avoid exhaustion of system heap */

#define DIAG_BUFFERED_MANY_DRAIN_PER_MARK      (75) /* % of buffer full when we start to drain or wrap */
#define DIAG_BUFFERED_FEW_DRAIN_PER_MARK       (20) /* % of buffer full when we stop draining */

#ifndef DIAG_TX_SLEEP_THRESHOLD_DEFAULT
#define DIAG_TX_SLEEP_THRESHOLD_DEFAULT (1024*4)
#endif

#ifndef DIAG_TX_SLEEP_TIME_DEFAULT
#define DIAG_TX_SLEEP_TIME_DEFAULT 5
#endif


#define DIAG_TX_SLEEP_THRESHOLD_NRT  (1024*8)

#define DIAG_TX_SLEEP_TIME_NRT       5 

#endif

