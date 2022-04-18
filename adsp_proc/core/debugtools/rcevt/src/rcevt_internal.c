/** vi: tw=128 ts=3 sw=3 et :
@file rcevt_internal.c
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
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/rcevt/src/rcevt_internal.c#1 $
$DateTime: 2020/02/10 01:57:30 $
$Change: 22511909 $
$Author: pwbldsvc $
===============================================================================*/

#define DLL_API_BUILD_RCINIT

#include "rcevt.h"
#include "tms_rcevt.h"

/////////////////////////////////////////////////////////////////////
// Localized Storage
/////////////////////////////////////////////////////////////////////

struct rce_internal_s rce_internal;
rce_nfy_pool_t rce_nfy_pool_static;                                              // first pool static storage
rce_nde_pool_t rce_nde_pool_static;                                              // first pool static storage
rce_nde_p rce_hashtab[RCEVT_HASHTABLE_BUCKETS];                                  // hashtable lookup buckets
