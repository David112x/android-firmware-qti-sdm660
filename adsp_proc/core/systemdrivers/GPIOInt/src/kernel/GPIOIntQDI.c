/*==============================================================================

  G P I O   I N T E R R U P T   C O N T R O L L E R  Q D I   W R A P P E R  

DESCRIPTION
  This modules contains the Qurt Driver Invocation (QDI) layer that interfaces
  with the driver in the kernel on behalf of the user clients in the user domain.

REFERENCES

       Copyright (c) 2012 - 2015 QUALCOMM Technologies Incorporated.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
 
==============================================================================*/
/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/GPIOInt/src/kernel/GPIOIntQDI.c#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
1/1/2010   aratin  First draft created. 
===========================================================================*/
#include "DalDevice.h"
#include "DALDeviceId.h"
#include "DALStdErr.h"
#include "DALGlbCtxt.h"
#include "GPIOIntQDI.h"
#include "DDIGPIOInt.h"
#include "DDIGPIOMgr.h"
#include "qurt_qdi.h"
#include "qurt_qdi_driver.h"
#include "qurt.h"
#include "qurt_futex.h"
#include "qurt_atomic_ops.h"
#include "stdlib.h"
#include "err.h"
#include "HALgpioint.h"

/*------------------------------------------------------------------------------
 GPIOInt Data Type Declarations.
------------------------------------------------------------------------------*/ 

/* 
 * Any Driver that opens a QDI driver has this structure. 
 */ 
typedef struct{
  qurt_qdi_obj_t       qdiobj;
}GPIOIntQdiOpenerType;

/* 
 * Any Driver that opens a QDI driver has this structure. 
 */ 
typedef struct  
{
  qurt_qdi_obj_t qdiobj;
}GPIOIntQdiDrvType;

/* 
 * The QDI driver sets signals on the User threads using this object.
 */ 
typedef struct
{
  qurt_anysignal_t*    pISTSignal;
  qurt_qdi_obj_t*      pQDIObj;
}GPIOIntQdiStateType;

/* 
 * The QDI driver sets signals on the User threads using this object.
 */ 
typedef struct
{
  qurt_anysignal_t      summarySig;
  qurt_anysignal_t      ackSig;
}GPIOIntQdiSummaryType;

/* 
 * The QDI driver has one common structure for all user PD clients.
 */ 
typedef struct
{
 GPIOIntQdiStateType   *pState;
 uint32                nGpioNumber;
 DalDeviceHandle *     pGPIOIntHdl;
 uint8                 is_initialized;
 GPIOIntQdiSummaryType pSummaryQDI[GPIOINT_NUM_PDS];
 qurt_qdi_obj_t*       pQDIObjList[GPIOINT_NUM_PDS];

}GPIOIntQdiDataType;


static DalDeviceHandle *  pGPIOInt_Hdl = NULL;
static DalDeviceHandle *  phGPIOMgr = NULL;
static qurt_mutex_t GPIOIntQDILock = {{0}};
static GPIOIntQdiDataType *pGPIOIntQdiData = NULL;

/*------------------------------------------------------------------------------
 GPIOInt Constants.
------------------------------------------------------------------------------*/ 

/*
 * This is the maximum number of GPIOs allowed to be used in the system.
 */
#define GPIO_TOTAL_NUMBER 200

/*
 * This macro does a limit check on the GPIO number passed in.
 */
#define GPIOINTQDI_VALID_GPIO(x) ((x) < (pGPIOIntQdiData->nGpioNumber) )

/*------------------------------------------------------------------------------
 GPIOInt Function Declarations.
------------------------------------------------------------------------------*/ 
static int GPIOIntQDI_Invoke(int hClientHandle,qurt_qdi_obj_t *pobj,
                          int method,qurt_qdi_arg_t a1,
                          qurt_qdi_arg_t a2,qurt_qdi_arg_t a3,
                          qurt_qdi_arg_t a4,qurt_qdi_arg_t a5,
                          qurt_qdi_arg_t a6,qurt_qdi_arg_t a7,
                          qurt_qdi_arg_t a8,qurt_qdi_arg_t a9);

void GPIOIntQDI_Release(qurt_qdi_obj_t *qdiobj);

/*------------------------------------------------------------------------------
 GPIOInt Data Declarations.
------------------------------------------------------------------------------*/ 

/*
 * The QDI functionality is implemented in a opener object.
 */
const GPIOIntQdiOpenerType GPIOIntQdiOpener = {
  { 
    GPIOIntQDI_Invoke,
    QDI_REFCNT_PERM,
    GPIOIntQDI_Release
  }
};




/*===========================================================================
FUNCTION GPIOIntQDI_Init
 
DESCRIPTION 
  This function is called in RCInit . Its dependent on GPIOInt DAL in Guest OS.
  Only when the Guest OS GPIOInt_Init is called then can this function be called.
  It registers the GPIOInt QDI wrapper with QDI Framework.
===========================================================================*/
void GPIOIntQDI_Init(void)
{

  DALResult nResult;

  nResult = DAL_SUCCESS;
  if (pGPIOIntQdiData == NULL) 
  {
    qurt_mutex_init(&GPIOIntQDILock);
    pGPIOIntQdiData = malloc(sizeof(*pGPIOIntQdiData));
    if (pGPIOIntQdiData != NULL)
    {
    
      pGPIOIntQdiData->pState = malloc((sizeof(GPIOIntQdiStateType)*GPIO_TOTAL_NUMBER));
      if (pGPIOIntQdiData->pState == NULL)
      {
        ERR_FATAL("GPIOIntQDI_Init failed to initialize properly", 0, 0, 0);
      }

      /*
       * Allways initialize malloced data to 0.
       */
      memset(pGPIOIntQdiData->pState, 0, (sizeof(GPIOIntQdiStateType)*GPIO_TOTAL_NUMBER));
    }
    else
    {
      ERR_FATAL("GPIOIntQDI_Init failed to initialize properly", 0, 0, 0);
    }
  
    nResult = DAL_DeviceAttach(DALDEVICEID_GPIOINT, &pGPIOInt_Hdl);
    if(nResult == DAL_SUCCESS)
    {
      pGPIOIntQdiData->pGPIOIntHdl = pGPIOInt_Hdl ;
      if(qurt_qdi_register_devname(GPIOIntQdiName, &GPIOIntQdiOpener) < 0)
      {
        nResult = DAL_ERROR;
      }
    }
    if (nResult == DAL_ERROR) 
    {
      ERR_FATAL("GPIOIntQDI_Init failed to initialize properly", 0, 0, 0);
    }
 
    /* 
     * Acquire GPIO Manager
     */
    if( DalGPIOMgr_Attach( &phGPIOMgr ) != DAL_SUCCESS )
    {
      return;
    }

    /*
     * For the initialization the Max GPIO limit is set at the threshold.
     * It will be changed according to platform usage shortly thereafter.
     */
    pGPIOIntQdiData->nGpioNumber = GPIO_TOTAL_NUMBER;
    pGPIOIntQdiData->is_initialized = 1;
  }
  return;

}


/*===========================================================================
FUNCTION GPIOIntQDI_release

DESCRIPTION
  GPIOIntQDI_release
  This releases the qdi object when the user pd driver closes the handle
  to the qdi driver.
===========================================================================*/
void GPIOIntQDI_Release(qurt_qdi_obj_t *qdiobj)
{
  uint32 nIdx, nGpio, nPd = 0, nInt = 0;

  /* 
   * Typically this driver is active during the entire duration that the
   * target is on. So we may not want to release anything more than the client handle,
   * but if the Protection domain itself is resetting we want to go and reset all the invalid
   * signal pointers belonging to that particualr domain.
   */
  for (nIdx = 0;nIdx< GPIO_TOTAL_NUMBER; nIdx++ ) 
  {
    if (pGPIOIntQdiData->pState[nIdx].pQDIObj == qdiobj) 
    {
       pGPIOIntQdiData->pState[nIdx].pISTSignal = NULL;
    }
  }

  for ( nIdx = 1; nIdx < GPIOINT_NUM_PDS; nIdx++ )
  {
    if ( pGPIOIntQdiData->pQDIObjList[nIdx] == qdiobj )
    {
      for ( nGpio = 0; nGpio < pGPIOIntQdiData->nGpioNumber; nGpio++ )
      {
        /* Call into GPIOMgr to see if the GPIO is allocated to the PD */
        if( ( DAL_SUCCESS == DalGPIOMgr_GetGPIOCurrentPD( phGPIOMgr, nGpio, &nPd ) ) &&
            ( nPd == nIdx ) )
        {

          /* Clean up the GPIO data from the GPIO_INTR_CFG register */
          HAL_gpioint_DisableDirConnIntr( nGpio );

          /* Release direct connect if it is one */
          DalGPIOMgr_ReleaseGPIO( phGPIOMgr, nGpio );

          /*  */
          if ( DAL_SUCCESS == DalGPIOMgr_GetDirectConnectInterruptID( phGPIOMgr, nGpio, &nInt ) )
          {
            DalGPIOMgr_ReleaseDirectConnectGPIO(phGPIOMgr, nGpio, nInt);
          }
        }
      }
      /* Destroy signal objects for the PD and clear out reference to the QDI obj */
      qurt_anysignal_destroy( &pGPIOIntQdiData->pSummaryQDI[nIdx].summarySig );
      qurt_anysignal_destroy( &pGPIOIntQdiData->pSummaryQDI[nIdx].ackSig );
      memset( &pGPIOIntQdiData->pSummaryQDI[nIdx].summarySig, 0, sizeof( qurt_anysignal_t ) );
      memset( &pGPIOIntQdiData->pSummaryQDI[nIdx].ackSig, 0, sizeof( qurt_anysignal_t ) );
      pGPIOIntQdiData->pQDIObjList[nIdx] = NULL;
    }
  }

  free(qdiobj);

} /* End GPIOIntQDI_Release */


/*===========================================================================
FUNCTION GPIOIntQDI_open

DESCRIPTION
  Open the specified driver for subsequent operations.
===========================================================================*/
int GPIOIntQDI_Open
(
  int hClientHandle,
  qurt_qdi_obj_t *objptr,
  const char *devname,
  int mode
)
{
  GPIOIntQdiDrvType *pGPIOIntQdiDrv;
  int nResult;
  pGPIOIntQdiDrv = malloc(sizeof(*pGPIOIntQdiDrv));
  if (pGPIOIntQdiDrv == NULL)
  {
    return -1;
  }
  pGPIOIntQdiDrv->qdiobj.invoke = GPIOIntQDI_Invoke;
  pGPIOIntQdiDrv->qdiobj.refcnt = QDI_REFCNT_INIT;
  pGPIOIntQdiDrv->qdiobj.release = GPIOIntQDI_Release;

  pGPIOIntQdiData->pQDIObjList[qurt_process_get_id()] = objptr;

  nResult = qurt_qdi_handle_create_from_obj_t(hClientHandle,&pGPIOIntQdiDrv->qdiobj);

  if (nResult < 0)
  {
    free(pGPIOIntQdiDrv);
  }

  return nResult;

} /* End GPIOIntQDI_Open */


/*===========================================================================

FUNCTION    GPIOIntQDI_RegisterSummarySignal

DESCRIPTION
 This api registers the signal objects required for routing the summary signal.

DEPENDENCIES
  None.

RETURN VALUE
  This returns the following signal Value :
  GPIOINT_QDI_SUCCESS if signal was set successfully.
  GPIOINT_QDI_ERROR if signal could not be set.
 
SIDE EFFECTS
  None

===========================================================================*/
int GPIOIntQDI_RegisterSummarySignal
(
  int               hClientHandle,
  int               nPD
)
{
  if ( nPD >= GPIOINT_NUM_PDS ) 
  {
    return GPIOINT_QDI_ERROR;
  }

  qurt_anysignal_init(&pGPIOIntQdiData->pSummaryQDI[nPD].summarySig);
  qurt_anysignal_init(&pGPIOIntQdiData->pSummaryQDI[nPD].ackSig);

  return GPIOINT_QDI_SUCCESS;
}

/*===========================================================================

FUNCTION    GPIOIntQDI_ReceiveSummarySignal

DESCRIPTION
 This api is called to wait for a summary interrupt.

DEPENDENCIES
  None.

RETURN VALUE
  This returns the following signal Value :
  GPIOINT_QDI_SUCCESS if signal was set successfully.
  GPIOINT_QDI_ERROR if signal could not be set.
 
SIDE EFFECTS
  None

===========================================================================*/
int GPIOIntQDI_ReceiveSummarySignal
(
  int               hClientHandle,
  int               nPD,
  void*             pGPIO
)
{
  uint32 nSigs, nErr;

  if ( nPD >= GPIOINT_NUM_PDS || pGPIO == NULL ) 
  {
    return GPIOINT_QDI_ERROR;
  }

  nErr = qurt_signal_wait_cancellable(&pGPIOIntQdiData->pSummaryQDI[nPD].summarySig, 
                               SIG_INT_ABORT                | 
                               GPIOINT_QDI_INTERRUPT_SIGNAL,
							   QURT_SIGNAL_ATTR_WAIT_ANY, (unsigned int *)&nSigs);

  if ( nErr == QURT_ECANCEL )
  {
    return GPIOINT_QDI_ERROR;
  }

  if ( nSigs & GPIOINT_QDI_INTERRUPT_SIGNAL )
  {
    qurt_anysignal_clear( &pGPIOIntQdiData->pSummaryQDI[nPD].summarySig, 
                          GPIOINT_QDI_SUMMARY_CLR_BMSK );

    *( ( uint32 * ) pGPIO ) = GPIOINTQDI_GET_SUMMARY_SIG(nSigs);

    return GPIOINT_QDI_SUCCESS;
  }
  else
  {
    return GPIOINT_QDI_ERROR;
  }

}

/*===========================================================================

FUNCTION    GPIOIntQDI_AckSummarySignal

DESCRIPTION
 This api acks the server to tell it that it has successfully handled
 the signal that it received.

DEPENDENCIES
  None.

RETURN VALUE
  This returns the following signal Value :
  GPIOINT_QDI_SUCCESS if signal was set successfully.
  GPIOINT_QDI_ERROR if signal could not be set.
 
SIDE EFFECTS
  None

===========================================================================*/
int GPIOIntQDI_AckSummarySignal
(
  int               hClientHandle,
  int               nPD
)
{
  if ( nPD >= GPIOINT_NUM_PDS ) 
  {
    return GPIOINT_QDI_ERROR;
  }

  qurt_anysignal_set( &pGPIOIntQdiData->pSummaryQDI[nPD].ackSig, GPIOINT_QDI_ACK_SIGNAL );
  return GPIOINT_QDI_SUCCESS;
}

/*===========================================================================

FUNCTION    GPIOIntQDI_SetSummarySignal

DESCRIPTION
 This api sets the signal to tell PD that it has a summary interrupt in which
 it needs handled on the respective PD.

DEPENDENCIES
  None.

RETURN VALUE
  This returns the following signal Value :
  GPIOINT_QDI_SUCCESS if signal was set successfully.
  GPIOINT_QDI_ERROR if signal could not be set.
 
SIDE EFFECTS
  None

===========================================================================*/
int GPIOIntQDI_SetSummarySignal
(
  uint32            nPD,
  uint32            nGPIO
)
{
  if ( nPD >= GPIOINT_NUM_PDS ) 
  {
    return GPIOINT_QDI_ERROR;
  }

  qurt_anysignal_set( &pGPIOIntQdiData->pSummaryQDI[nPD].summarySig, 
                      GPIOINTQDI_SET_SUMMARY_SIG( nGPIO ) );

  return GPIOINT_QDI_SUCCESS;
}

/*===========================================================================

FUNCTION    GPIOIntQDI_WaitOnAckSummarySignal

DESCRIPTION
 This api acks the server to tell it that it has successfully handled
 the signal that it received.

DEPENDENCIES
  None.

RETURN VALUE
  This returns the following signal Value :
  GPIOINT_QDI_SUCCESS if signal was set successfully.
  GPIOINT_QDI_ERROR if signal could not be set.
 
SIDE EFFECTS
  None

===========================================================================*/
int GPIOIntQDI_WaitOnAckSummarySignal
(
  uint32            nPD
)
{
  uint32 nSigs = 0;

  if ( nPD >= GPIOINT_NUM_PDS ) 
  {
    return GPIOINT_QDI_ERROR;
  }

  qurt_signal_wait_cancellable(&pGPIOIntQdiData->pSummaryQDI[nPD].ackSig, GPIOINT_QDI_ACK_SIGNAL,
							   QURT_SIGNAL_ATTR_WAIT_ANY, (unsigned int *)&nSigs);
  qurt_anysignal_clear( &pGPIOIntQdiData->pSummaryQDI[nPD].ackSig, GPIOINT_QDI_ACK_SIGNAL );

  return GPIOINT_QDI_SUCCESS;
}

/*===========================================================================
FUNCTION GPIOIntQDI_Invoke

DESCRIPTION : 
  This is the main handler for the QDI driver layer in the kernel. All user
  specified methods are routed by this handler to the specific functionality.
 
===========================================================================*/
static int GPIOIntQDI_Invoke(int hClientHandle,
						  qurt_qdi_obj_t *pobj,
                          int method,
                          qurt_qdi_arg_t a1,
                          qurt_qdi_arg_t a2,
                          qurt_qdi_arg_t a3,
                          qurt_qdi_arg_t a4,
                          qurt_qdi_arg_t a5,
                          qurt_qdi_arg_t a6,
                          qurt_qdi_arg_t a7,
                          qurt_qdi_arg_t a8,
                          qurt_qdi_arg_t a9)
{
  switch (method) 
  {
    case QDI_OPEN:
      return GPIOIntQDI_Open(hClientHandle, (void *)pobj, a1.ptr, a2.num);

    case GPIOINT_QDI_REGISTER_SUMMARY_TASK:
      return GPIOIntQDI_RegisterSummarySignal(hClientHandle,a1.num);

    case GPIOINT_QDI_RECEIVE_SUMMARY_SIGNAL:
      return GPIOIntQDI_ReceiveSummarySignal(hClientHandle,a1.num,a2.ptr);

    case GPIOINT_QDI_ACK_SUMMARY_SIGNAL:
      return GPIOIntQDI_AckSummarySignal(hClientHandle,a1.num);

    default:
      return qurt_qdi_method_default(hClientHandle, pobj, method,
                                     a1, a2, a3, a4, a5, a6, a7, a8, a9);	
  }
   return -1;
} /* End GPIOIntQDI_Invoke */

