/*===========================================================================

                   IPC ROUTER DEVICE CONFIGURATION

        This file provides the device configuration for IPC Router

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
  ---------------------------------------------------------------------------
===========================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

$Header:

when       who     what, where, why
--------   ---     ----------------------------------------------------------
===========================================================================*/

/*===========================================================================
                          INCLUDE FILES
===========================================================================*/
#include "DALStdDef.h"
#include "ipc_router_types.h"
#include "ipc_router_xal_glink.h"

/*===========================================================================
                    CONSTANT / MACRO DECLARATIONS
===========================================================================*/
#define IPC_ROUTER_XAL_GLINK_PRIO 150
#define IPC_ROUTER_XAL_GLINK_STACK_SIZE (1024 * 3)

/*===========================================================================
                      LOCAL DATA DEFINATION
===========================================================================*/
/* GLINK Transports */
static ipc_router_xal_glink_param_type ipc_router_devcfg_glink_xals[] =
{
 /* Link to Apps */
  {
    "SMEM", "apss", "IPCRTR", 0, 
    IPC_ROUTER_XAL_GLINK_PRIO,
    IPC_ROUTER_XAL_GLINK_STACK_SIZE,
    {{128,16}, {512, 8}, {1024+128, 5}, {8192+128, 1}},
  },

  /* Link to Modem */
  {
    "SMEM", "mpss", "IPCRTR", 0,
    IPC_ROUTER_XAL_GLINK_PRIO,
    IPC_ROUTER_XAL_GLINK_STACK_SIZE,
    {{128,16}, {512, 8}, {1024+128, 5}, {8192+128, 1}},
  },
  
  {
    NULL, NULL, NULL, 0, 0, 0, {{0, 0}}
  }
};

/*===========================================================================
                      GLOBAL DATA DEFINATION
===========================================================================*/
/* Processor information */
const ipc_router_proc_info_type ipc_router_devcfg_proc =
{
  "adsp",
  5
};

/* Transports supported */
const ipc_router_xal_info_type ipc_router_devcfg_xals[] =
{
  {"GLINK", (const void*)ipc_router_devcfg_glink_xals},
  {NULL, NULL}
};

