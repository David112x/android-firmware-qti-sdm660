#ifndef DIAG_LSMI_H
#define DIAG_LSMI_H

/*===========================================================================

                   Diag Mapping Layer DLL , internal declarations

DESCRIPTION
  Internal declarations for Diag Service Mapping Layer.
  

Copyright (c) 2008-2009, 2012, 2014-2018 Qualcomm Technologies Incorporated. 
All Rights Reserved.
Qualcomm Confidential and Proprietary

===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/core.qdsp6/1.0.c2/services/diag/LSM/qurt/src/Diag_LSMi.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
03/21/18   gn      Tagging the data with dynamic diag IDs
02/21/17   ph      Tag DIAG ID header to all the diag packets sent out.
11/18/15   gn      Added loopback command in user PD. 
05/12/16   sa      Circular Mode for UserPD buffer
07/10/15   rh      Added delayed response command in UserPD
06/18/15   sa      Added support for time sync feature.
11/14/14   vk      Added healthcommand in UserPD
10/09/14   sr      Added stress test in UserPD
07/05/12   sg      Changes to bring up Diag MultiPD
01/15/09   mad     Moved Synch. Event name prefixes to diag_shared_i.h
09/10/08   mad     Changes for stream driver model. Added WinDiag driver HANDLE 
                   and Synchronization event declarations. Removed Component 
                   Services references.
02/04/08   mad     Created File
===========================================================================*/

#include "diagdiag_v.h"
#include "qw.h"    /* for qword */

/* this process's global file descriptor for diag resource manager */
extern int diag_qdi_handle;

/* This process's pid */
extern int diag_pid;
/* Magic number for lowest value that diag_qdi_handle could have */
#define DIAG_FD_MIN_VALUE 0

#define DIAG_ERR_ULOG_SIZE (1024*4)

boolean diag_time_init_LSM(void);

boolean diag_set_time_api_LSM(void);

typedef PACK(struct){
  uint16 reserved;					 /* To make it byte aligned */
  int num_tasks;                     /* Number of tasks, to be started */
  diag_per_task_test_info test[1];   /* Place holder for per task info */
}diagdiag_LSM_stress_test_info;

typedef enum{
  DIAGDIAG_STRESS_TEST_OPCODE = 0,
  DIAGDIAG_HEALTH_CMD_OPCODE = 1,
  DIAGDIAG_LOOPBACK_CMD_OPCODE = 2,
  DIAGDIAG_PD_BUF_MODE_OPCODE=3,
}Diag_LSM_cmd_type;

typedef PACK(struct) {
  uint32 num_tasks;
  diag_per_task_test_info test[1];
}diag_LSM_stress_test_type;

typedef PACK(struct) {
  uint16 cmd_code;
  uint32 drop_count;
}diag_LSM_health_cmd_type; 

typedef PACK(struct) {
  diagpkt_subsys_header_type header; /* Sub System header */
  uint16 opcode;                     /*Specifies the type of cmd*/
  union{
  diag_LSM_stress_test_type stress_test_info;
  uint16 diag_LSM_health_command;
  uint8 pd_buf_mode;
  }cmd_type;
} diag_LSM_test_cmd_req_type;

typedef struct {
  byte cmd_code;
  byte subsys_id;
  uint16 subsys_cmd_code;
  uint32 status;
  uint16 delayed_rsp_id;
  uint16 response_cnt;
}diagdiag_lsm_delayed_rsp_test_rsp_type;

typedef PACK(struct) {
  diagpkt_subsys_header_type header; /* Sub System header */
  uint16 opcode;                     /*Specifies the type of cmd*/
  union{
  diagdiag_LSM_stress_test_info stress_test_info;
  diag_LSM_health_cmd_type health_cmd; 
  uint8 pd_buf_mode;
  }rsp_cmd_type;
} diag_LSM_test_cmd_rsp_type;

/*===========================================================================

FUNCTION DIAG_LSM_STRESSTEST_CLEANUP_CB

DESCRIPTION
  This procedure is a cleanup function. It goes through the
  diag_stress_test_task_q, checks if any data block is ready to cleaned.
  If yes it removes the entry from the Q and frees the memory.

============================================================================*/
void  diag_LSM_stresstest_cleanup_cb (void);

#endif /* DIAG_LSMI_H */

