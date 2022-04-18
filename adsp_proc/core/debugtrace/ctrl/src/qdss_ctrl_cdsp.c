/*=============================================================================

FILE:         qdss_ctrl.c

DESCRIPTION:  Implements handlers for diag comamnds to configure qdss on
              a particular core
=============================================================================*/
/*=============================================================================
  Copyright (c) 2012-2015 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
/*===========================================================================
  $Header: //components/rel/core.qdsp6/1.0.c2/debugtrace/ctrl/src/qdss_ctrl_cdsp.c#1 $
===========================================================================*/

#include "qdss_ctrl_diag.h"
#include "qdss_ctrl_etm.h"
#include "qdss_ctrl_utils.h"
#include "qdss_ctrl_priv.h"
#include "qdss_control.h"



extern struct qdss_ctrl_s qdss_ctrl_ctxt;


/*-------------------------------------------------------------------------*/
int qdss_control_set_etm(uint8 state)
{
   int nErr = DAL_ERROR;

   if (0 == qdss_ctrl_ctxt.hSync)
   {
      nErr = DAL_SYNC_ENTER_FAILED;
      return nErr;
   }

   DALSYS_SyncEnter(qdss_ctrl_ctxt.hSync);

   if (state)
   {
      if (!qdss_ctrl_ctxt.etm_port_enabled)
      {
         qdss_ctrl_ctxt.etm_port_enabled = TRUE;
      }
      /* State: D0 bit serves the enable or disable ETM,
         D1 - D7 bits serves ETM configuration mode */

      if (1 < state)    // Request from Diag.
      {  // State right shifted 1 time to get the mode value.
         qdss_ctrl_etm_set_param(QDSS_CTRL_ETM_PARAM_ID_DSP_MODE,
                                 (unsigned int)state >> 1);
      }  // else simple request from QMI/Debug Agent or Diag with default mode
      TRY(nErr,qdss_ctrl_etm_enable());

   }
   else
   {
      if (qdss_ctrl_ctxt.etm_port_enabled)
      {
         TRY(nErr,qdss_ctrl_etm_disable());
         qdss_ctrl_ctxt.etm_port_enabled = FALSE;
      }
      else
      {
         nErr = DAL_SUCCESS;
      }
   }

   CATCH(nErr) {}

   if (DAL_SUCCESS == nErr)
   {
      qdss_ctrl_ctxt.etm_state = state;
   }
   DALSYS_SyncLeave(qdss_ctrl_ctxt.hSync);

   return nErr;
}

/*-------------------------------------------------------------------------*/

int qdss_control_set_etm_rpm(uint8 state)
{
   return 1;
}
