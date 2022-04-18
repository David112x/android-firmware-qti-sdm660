#ifndef RCESN_QURT_H
#define RCESN_QURT_H
/** vi: tw=128 ts=3 sw=3 et :
@file rcesn_qurt.h
@brief This file contains the API for the Run Control Framework, API 2.1
*/
/*=============================================================================
NOTE: The @brief description above does not appear in the PDF.
The tms_mainpage.dox file contains the group/module descriptions that
are displayed in the output PDF generated using Doxygen and LaTeX. To
edit or update any of the group/module text in the PDF, edit the
tms_mainpage.dox file or contact Tech Pubs.
===============================================================================*/
/*=============================================================================
Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
===============================================================================*/
/*=============================================================================
Edit History
$Header: //components/rel/core.qdsp6/1.0.c2/api/debugtools/rcesn_qurt.h#1 $
$DateTime: 2020/02/10 01:57:30 $
$Change: 22511909 $
$Author: pwbldsvc $
===============================================================================*/

#include "tms_dll_api.h"                                                         /**< MUST PRECEDE CLIENT DEFINITION OF DLL_API_EXPORT */

#if defined(DLL_API_BUILD_RCINIT)                                                /**< REQUIRED TO BE DECLARED IN TECH AREA SOURCE MODULES (SU/VU VISIBLE) */
#undef  DLL_API_EXPORT_RCINIT                                                    /**< REDEFINITION FOR THIS SPECIFIC MODULE */
#define DLL_API_EXPORT_RCINIT DLL_API_EXPORT_HELPER                              /**< CONTROL OVER DLL SYMBOL VISIBILITY BY EXPORT */
#else
#undef  DLL_API_EXPORT_RCINIT                                                    /**< REDEFINITION FOR THIS SPECIFIC MODULE */
#define DLL_API_EXPORT_RCINIT DLL_API_IMPORT_HELPER                              /**< CONTROL OVER DLL SYMBOL VISIBILITY BY EXPORT */
#endif

#include "qurt.h"
#include "rcesn.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/** @addtogroup rcinit_api @{ */

////////////////////////////////////////
// REGISTER
////////////////////////////////////////

// qurt_anysignal_t client_qurt_signal;
//
// qurt_anysignal_init(&client_qurt_signal);
//
// if (RCESN_NULL == rcesn_register_name_qurt(CLIENT_EVENTNAME, compare, &client_qurt_signal, CLIENT_QURT_SIGNAL_MASK))
// {
// MSG("error"); // handle error
// }

////////////////////////////////////////
// BLOCKING WAIT
////////////////////////////////////////

// unsigned int recv = qurt_anysignal_wait(&qurt_signal, CLIENT_QURT_SIGNAL_MASK);
//
// if (0 != (recv & RCESN_QURT_SIGNAL_MASK))
// {
// MSG("event handler");
// }

////////////////////////////////////////
// UNREGISTER
////////////////////////////////////////

// if (RCESN_NULL == rcesn_unregister_name_qurt(CLIENT_EVENTNAME, compare, &client_qurt_signal, CLIENT_QURT_SIGNAL_MASK))
// {
// MSG("error"); // handle error
// }
//
// qurt_anysignal_destroy(&qurt_signal);

////////////////////////////////////////
// SIGNAL FROM OTHER CONTEXT
////////////////////////////////////////

// if (RCESN_NULL == rcesn_create_name(CLIENT_EVENTNAME)) // Prior to Use
// {
// MSG("error"); // handle error
// }

// if (RCESN_NULL == rcesn_signal_name(CLIENT_EVENTNAME))
// {
// MSG("error"); // handle error
// }

/**
API, NHLOS Specific Structure
*/
typedef struct
{
   qurt_anysignal_t* signal;

   unsigned int mask;

   RCESN_FNSIG_COMPARE compare;

} RCESN_SIGEX_SIGQURT;

/**
API, Register notification to event, with handle
@param[in] Opaque handle of the event
@param[in] Function pointer to Comparision Function
@param[in] Notification NHLOS specific notification information
@param[in] Notification NHLOS specific notification information
@return
RCESN_NULL -- Error
RCESN_HANDLE -- Opaque handle to existing event
*/
DLL_API_WARN_UNUSED_RESULT 
DLL_API_STATIC_INLINE RCESN_HANDLE rcesn_register_handle_qurt(RCESN_HANDLE const handle, RCESN_FNSIG_COMPARE const compare, qurt_anysignal_t* const signal, unsigned int mask)
{
   RCESN_HANDLE rc = RCESN_NULL;

   if (RCESN_NULL != handle && RCESN_NULL != compare && RCESN_NULL != signal)
   {
      RCESN_SIGEX_SIGQURT sigex;
      sigex.signal = signal;
      sigex.mask = mask;
      sigex.compare = compare;
      rc = rcesn_register_sigex_handle(handle, RCESN_SIGEX_TYPE_SIGQURT, &sigex);
   }

   return rc;
}

/**
API, Register notification to event, with name
@param[in] NULL terminated string, name of the event
@param[in] Function pointer to Comparision Function
@param[in] Notification NHLOS specific notification information
@param[in] Notification NHLOS specific notification information
@return
RCESN_NULL -- Error
RCESN_HANDLE -- Opaque handle to existing event
*/
DLL_API_WARN_UNUSED_RESULT
DLL_API_STATIC_INLINE RCESN_HANDLE rcesn_register_name_qurt(RCESN_NAME const name, RCESN_FNSIG_COMPARE compare, qurt_anysignal_t* signal, unsigned int mask)
{
   RCESN_HANDLE rc = RCESN_NULL;

   if (RCESN_NULL != name && RCESN_NULL != compare && RCESN_NULL != signal)
   {
      RCESN_SIGEX_SIGQURT sigex;
      sigex.signal = signal;
      sigex.mask = mask;
      sigex.compare = compare;
      rc = rcesn_register_sigex_name(name, RCESN_SIGEX_TYPE_SIGQURT, &sigex);
   }

   return rc;
}

/**
API, Unegister notification to event, with handle
@param[in] Opaque handle of the event
@param[in] Function pointer to Comparision Function
@param[in] Notification NHLOS specific notification information
@param[in] Notification NHLOS specific notification information
@return
RCESN_NULL -- Error
RCESN_HANDLE -- Opaque handle to existing event
*/
DLL_API_WARN_UNUSED_RESULT 
DLL_API_STATIC_INLINE RCESN_HANDLE rcesn_unregister_handle_qurt(RCESN_HANDLE const handle, RCESN_FNSIG_COMPARE compare, qurt_anysignal_t* signal, unsigned int mask)
{
   RCESN_HANDLE rc = RCESN_NULL;

   if (RCESN_NULL != handle && RCESN_NULL != compare && RCESN_NULL != signal)
   {
      RCESN_SIGEX_SIGQURT sigex;
      sigex.signal = signal;
      sigex.mask = mask;
      sigex.compare = compare;
      rc = rcesn_unregister_sigex_handle(handle, RCESN_SIGEX_TYPE_SIGQURT, &sigex);
   }

   return rc;
}

/**
API, Unegister notification to event, with name
@param[in] NULL terminated string, name of the event
@param[in] Function pointer to Comparision Function
@param[in] Notification NHLOS specific notification information
@param[in] Notification NHLOS specific notification information
@return
RCESN_NULL -- Error
RCESN_HANDLE -- Opaque handle to existing event
*/
DLL_API_WARN_UNUSED_RESULT 
DLL_API_STATIC_INLINE RCESN_HANDLE rcesn_unregister_name_qurt(RCESN_NAME const name, RCESN_FNSIG_COMPARE compare, qurt_anysignal_t* signal, unsigned int mask)
{
   RCESN_HANDLE rc = RCESN_NULL;

   if (RCESN_NULL != name && RCESN_NULL != compare && RCESN_NULL != signal)
   {
      RCESN_SIGEX_SIGQURT sigex;
      sigex.signal = signal;
      sigex.mask = mask;
      sigex.compare = compare;
      rc = rcesn_unregister_sigex_name(name, RCESN_SIGEX_TYPE_SIGQURT, &sigex);
   }

   return rc;
}

/** @} end_addtogroup rcinit_api */

#if defined(__cplusplus)
}
#endif

#endif
