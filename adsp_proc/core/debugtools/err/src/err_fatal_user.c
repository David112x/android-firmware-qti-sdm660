/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

         E R R O R     R E P O R T I N G    S E R V I C E S

GENERAL DESCRIPTION
  This module provides ERR_FATAL and its dependecies. This file must be island 
  mode safe.

Copyright (c) 2015 - 2017 by Qualcomm Technologies, Inc.  All Rights Reserved.

*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/*===========================================================================

                        Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/err/src/err_fatal_user.c#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
08/27/15   din     Adapted from err.c

===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "qurt.h"
#include "erri.h"
#include "tms_utils.h"
#include "err_qdi_client.h"

/*===========================================================================

                      Prototypes for internal functions

===========================================================================*/
void err_emergency_error_recovery(void) ERR_NORETURN_ATTRIBUTE;
void err_raise_to_kernel(void) ERR_NORETURN_ATTRIBUTE;
void err_fatal_lock_init_check(void);
void err_pd_exit(void);

/*===========================================================================

                      Prototypes for external functions

===========================================================================*/
/* from err_jettison_core.s */
extern void err_halt_execution( void ) ERR_NORETURN_ATTRIBUTE; 

/*===========================================================================

                 Defines and variable declarations for module

===========================================================================*/

  
extern err_fatal_params_type err_fatal_params;

/*===========================================================================

                              Function definitions

===========================================================================*/

/*===========================================================================

FUNCTION ERR_FATAL_LOCK_INIT_CHECK

DESCRIPTION
  Called by err_fatal_lock
============================================================================*/
void err_fatal_lock_init_check(void)
{
  if ( !err_qdi_client_is_initialized() )
  {
    ERR_FATAL_ENTER_SINGLE_THREADED_MODE();
    ERR_FATAL_FLUSH_CACHE_NO_RETURN();
  }

} /* err_fatal_lock_init_check */


/*=========================================================================

FUNCTION err_emergency_error_recovery

DESCRIPTION
  Action to be taken when more than one error has occurred, or if an
  error occurs before err_init has completed.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  No return from this function

===========================================================================*/
void err_emergency_error_recovery( void )
{
  /* Define action to be taken when multiple crashes occur */
  if ( qurt_island_get_status() == FALSE ) 
    ERR_CRUMB_TRAIL_BMSK(ERR_CRUMB_TRAIL_BMSK_EMERGENCY_RECOVERY_PRE);
  else
    ERR_CRUMB_TRAIL_BMSK_ISLAND(ERR_CRUMB_TRAIL_BMSK_EMERGENCY_RECOVERY_PRE);

  /* flush cache, etc - does not return*/
  err_raise_to_kernel();

} /* err_emergency_error_recovery */

/*=========================================================================

FUNCTION err_raise_to_kernel

DESCRIPTION
  Function which will terminate user space/PD handling and raise to kernel

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None

===========================================================================*/
void err_raise_to_kernel(void)
{
  if ( qurt_island_get_status() == FALSE )
  { 
    ERR_CRUMB_TRAIL_BMSK(ERR_CRUMB_TRAIL_BMSK_RAISE_TO_KERNEL_PRE);
    tms_get_timetick(&(coredump.err.err_handler_end_time));
  }
  else
    ERR_CRUMB_TRAIL_BMSK_ISLAND(ERR_CRUMB_TRAIL_BMSK_EMERGENCY_RECOVERY_PRE);

  if ( qurt_island_get_status() == FALSE )
  {
    if (ERR_QDI_SUCCESS == err_qdi_invoke_err_handling_done())
    {
      ERR_CRUMB_TRAIL_BMSK(ERR_CRUMB_TRAIL_BMSK_PD_EXIT);
      /* Exit User PD */
      err_pd_exit();
    }
    else
    {
      /* Since QDI misbehaved , cannot get the status of PDR enablement,
         so assuming PDR is disable and crashing the root PD */
      ERR_CRUMB_TRAIL_BMSK(ERR_CRUMB_TRAIL_BMSK_NOT_PD_EXIT);
      #ifdef ERR_FATAL_FLUSH_CACHE_NO_RETURN
        ERR_FATAL_FLUSH_CACHE_NO_RETURN();
      #else
        #warning ERR_FATAL_FLUSH_CACHE_NO_RETURN not defined
      #endif
    }
  }
  else
  {
    #ifdef ERR_FATAL_FLUSH_CACHE_NO_RETURN
      ERR_FATAL_FLUSH_CACHE_NO_RETURN();
    #else
      #warning ERR_FATAL_FLUSH_CACHE_NO_RETURN not defined
    #endif
  }

  /* Stop active thread - will not reach here*/
  err_halt_execution();

} /* err_raise_to_kernel */ 


/*===========================================================================

FUNCTION ERR_PD_EXIT

DESCRIPTION
  Initiates PD exit 

DEPENDENCIES

RETURN VALUE
  No return.

SIDE EFFECTS
  **************************************************************
  ************ THERE IS NO RETURN FROM THIS FUNCTION ***********
  **************************************************************

===========================================================================*/

void err_pd_exit(void)
{
  qurt_qdi_handle_invoke(QDI_HANDLE_GENERIC, QDI_OS_PROCESS_EXIT, 0);

} /* err_pd_exit */
void dog_force_kick(void)
{
}

void dog_force_bite(void)
{
}

void dog_disable_bark_nmi(void)
{
}

