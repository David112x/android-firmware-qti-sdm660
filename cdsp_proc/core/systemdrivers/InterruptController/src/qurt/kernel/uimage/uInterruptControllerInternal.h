#ifndef __UIntInternal_H
#define __UIntInternal_H
/*===========================================================================

  M I C R O   I N T E R R U P T   C O N T R O L L E R    

DESCRIPTION
  This modules contains enumeration definitions to support the Dal 
  interrupt controller. The definitions in this module are used internally 
  in the Micro interrupt controller and are not to be exposed to the clients.

REFERENCES

       Copyright (c) 2016 Qualcomm Technologies Incorporated.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
===========================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/InterruptController/src/qurt/kernel/uimage/uInterruptControllerInternal.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
11/03/16   shm     Updated max interrupts to 230 and interrupts supported in
                   uImage to 16 for SDM660.
1/1/2010   aratin  First draft created.
===========================================================================*/

#include "qurt.h"
#include "uInterruptController.h"
/*------------------------------------------------------------------------------
Declaring uInterrupt Driver data
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 Micro interrupt controller constant declarations.
------------------------------------------------------------------------------*/

#define UIST_TASKNAME_SIZE 16

/*
 * As an upper limit we keep the maximum number of interrupts as 230.
 * This number needs to be updated if the interrupt number exceeds 230.
 * Also the number of interrupts supported in uImage (16) is a direct 1 to 1
 * relation to the number of direct connects currently available in LPASS.
 */
#define MAX_NUMBER_OF_UINTS         16
#define MAX_NUMBER_OF_INTS          230
#define UINTF_MPMINT                0x0002
#define UINTF_WAKEUP                0x0004
#define UINTF_REGISTERED            0x0008
#define UINT_IST_STACK_SIZE         1792

/*
 * These are signals to the TASK
 * Esstentially the task can wait on interrupt signals from the kernel and
 * signals from the registration thread.
 */
#define UINT_TASK_START      0x00000800
#define UINT_TASK_STOP       0x00001000 
#define UINT_TASK_INT0       0x00002000 /* Direct connect 0 registration signal to the IST. */
#define UINT_TASK_INT1       0x00004000 /* Direct connect 1 registration signal to the IST. */
#define UINT_TASK_INT2       0x00008000 /* Direct connect 2 registration signal to the IST. */
#define UINT_TASK_INT3       0x00010000 /* Direct connect 3 registration signal to the IST. */
#define UINT_TASK_INT4       0x00020000 /* Direct connect 4 registration signal to the IST. */
#define UINT_TASK_INT5       0x00040000 /* Direct connect 5 registration signal to the IST. */
#define UINT_TASK_INT6       0x00080000 /* Direct connect 6 registration signal to the IST. */
#define UINT_TASK_INT7       0x00100000 /* Direct connect 7 registration signal to the IST. */
#define UINT_TASK_INT8       0x00200000 /* Direct connect 8 registration signal to the IST. */
#define UINT_TASK_INT9       0x00400000 /* Direct connect 9 registration signal to the IST. */
#define UINT_TASK_INT10      0x00800000 /* Direct connect 10 registration signal to the IST. */
#define UINT_TASK_INT11      0x01000000 /* Direct connect 11 registration signal to the IST. */
#define UINT_TASK_INT12      0x02000000 /* Direct connect 12 registration signal to the IST. */
#define UINT_TASK_INT13      0x04000000 /* Direct connect 13 registration signal to the IST. */
#define UINT_TASK_INT14      0x08000000 /* Direct connect 14 registration signal to the IST. */
#define UINT_TASK_INT15      0x10000000 /* Direct connect 15 registration signal to the IST. */


#define UINT_TASK_INTMASK    0xFFFE0000

/** Default interrupt trigger value.
*/
#define UINT_NOAONID         0xFF 


/*=========================================================================

                           DATA TYPE DEFINITIONS

===========================================================================*/

/*
 * uIntDataType
 * Structure storing the details for a SUMMARY group interrupt
 */
typedef struct
{
  uIRQ                           isr;
  uIRQCtx                        isr_param;
  qurt_anysignal_t *             pISTSignal;
  uint32                         nInterruptMask;
  uint32                         nIntRegMask;
  uint8                          nAonID;
  uint8                          intr_trigger;
  uint8                          intr_flags;
  uint8                          qurt_intr_id;

} uIntDataType;
 
/*
 * uIntCntrlType
 *
 * Container for all local data.
 *
 */
typedef struct
{

  uint8                          uInt_Init;
  uIntDataType                   state[MAX_NUMBER_OF_UINTS];
  uint16                         auIntLUT[MAX_NUMBER_OF_INTS];
  qurt_thread_t                  nThreadID;
  uint8                          aISTStack[UINT_IST_STACK_SIZE];
  char                           aISTName[UIST_TASKNAME_SIZE];
  qurt_anysignal_t               ISTSignal;
  qurt_thread_attr_t             ThreadAttr;
  uint32                         nPriority;
  uint32                         nIntMask;
  uint32                         nIntRegistrationMask;
  uint32                         nISTStackSize;
  qurt_mutex_t                   uIntLock;
        
} uIntCntrlType;

/* =========================================================================
**  Function : uInterruptController_RegisterInterrupt
** =========================================================================*/
/*
  Registers a client callback notification for a interrupt.

  This function registers the client callback isr routine to a given 
  interrupt.Whenever an interrupt is fired the isr routine registered by the 
  user is called. \n
  
  @param[in] nInterruptID      The Interrupt vector number.
  @param[in] trigger   The interrupt trigger condition for which the client callback is being registered.
  @param[in] isr       The client ISR callback.
  @param[in] param     The Client specified parameter to be given to the client callback when the interrupt fires.
  @param[in] nFlags    The Client specified flags to be given to the interrupt controller so that internally it
                       can decide whether the interrupt is to be used in Uimage or big image. 
  
  DEPENDENCIES  None.
  @return
  UINTERRUPT_SUCCESS -- Is returned if the ISR registration was a success. \n
  UINTERRUPT_ERROR -- An Error if the uInterrupt driver was not able to register the interrupt
  service routine (ISR). \n
  @dependencies
  None.
*/

int32
uInterruptController_RegisterInterrupt( uint32 nInterruptID,uint32 trigger,
uIRQ isr,uIRQCtx param, uint32 nFlags, uint16 nAonID);


/*=============================================================================
  FUNCTION      uInterruptController_DeregisterIsr
=============================================================================*/
 /*
  Deregisters the client callback routine to a given interrupt.

  This function deregisters the client callback ISR function to a given L2VIC  
  interrupt.As a result of which the interrupt is disabled. \n
  
  @param[in] nInterruptID      The Interrupt vector number.
  @param[in] isr        The client interrupt service callback.
 
  
  DEPENDENCIES  None.
  @return
  UINTERRUPT_SUCCESS -- Is returned if the ISR deregistration was a success. \n
  UINTERRUPT_ERROR -- Is returned if the uInterruptController driver was not able to deregister 
  the client interrupt service routine. \n
  @dependencies
  None.
*/

int32
uInterruptController_UnRegister( uint32 nInterruptID);


/*=============================================================================
  FUNCTION      uInterruptController_Init
=============================================================================*/

/*
  Queries the interrupt Registration state.

  This function is the main uInterruptController driver initialization function.

  DEPENDENCIES  None.
  @return
  UINTERRUPT_SUCCESS -- Is returned if the Interrupt state query was successful. \n
  UINTERRUPT_ERROR --  Is returned if the interrupt is unsupported. \n
  @dependencies
  None.
*/

int32 
uInterruptController_Init(void);


#endif /*__UIntInternal_H */
