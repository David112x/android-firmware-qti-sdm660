/** vi: tw=128 ts=3 sw=3 et
@file pd_mon_internal.c
@brief This file contains the API details for the Protection Domain Monitor, API 2.0
*/
/*=============================================================================
NOTE: The @brief description above does not appear in the PDF.
The tms_mainpage.dox file contains the group/module descriptions that
are displayed in the output PDF generated using Doxygen and LaTeX. To
edit or update any of the group/module text in the PDF, edit the
tms_mainpage.dox file or contact Tech Pubs.
===============================================================================*/
/*=============================================================================
Copyright (c) 2014 - 2016 by Qualcomm Technologies, Inc.  All Rights Reserved.
Qualcomm Confidential and Proprietary
===============================================================================*/
/*=============================================================================
Edit History
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/pd_mon/src/pd_mon_internal.c#1 $
$DateTime: 2020/02/10 01:57:30 $
$Change: 22511909 $
$Author: pwbldsvc $
===============================================================================*/

#include "pd_mon_qurt.h"
#include "pd_mon_internal.h"
#include "servreg_common.h"

/////////////////////////////////////////////////////////////////////
// Localized Type Declarations
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// Localized Storage
/////////////////////////////////////////////////////////////////////

pd_mon_internal_t pd_mon_internal;

/**
  return asid from pd_mon_internal from the specified index passed in 
   the function 
@return
None
*/
int pd_mon_internal_get_asid(int index)
{
  return pd_mon_internal.status[index].asid;
}

/**
  return servreg_h from pd_mon_internal from the specified index passed in 
   the function 
@return
None
*/
SERVREG_MON_HANDLE pd_mon_internal_get_servreg_h(int index)
{
    return pd_mon_internal.status[index].servreg_h;
}


