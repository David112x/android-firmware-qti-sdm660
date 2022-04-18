/** vi: tw=128 ts=3 sw=3 et
@file tms_utils_chr_append.c
@brief This file contains the API for the TMS Utilities, API 0.1.0
*/
/*=============================================================================
NOTE: The @brief description above does not appear in the PDF.
The tms_mainpage.dox file contains the group/module descriptions that
are displayed in the output PDF generated using Doxygen and LaTeX. To
edit or update any of the group/module text in the PDF, edit the
tms_mainpage.dox file or contact Tech Pubs.
===============================================================================*/
/*=============================================================================
Copyright (c) 2014-16 QUALCOMM Technologies Incorporated.
All rights reserved.
QUALCOMM Confidential and Proprietary.
=============================================================================*/
/*=============================================================================
Edit History
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/utils/src/tms_utils_chr_append.c#1 $
$DateTime: 2020/02/10 01:57:30 $
$Change: 22511909 $
$Author: pwbldsvc $
===============================================================================*/

#if !defined(TMS_UTILS_EXCLUDE_MSG_SWEVT)
#include "tms_utils_msg.h"
#endif

#if !defined(TMS_UTILS_EXCLUDE_TRACER_SWEVT)
#include "tracer.h"
#include "tms_utils_tracer_swe.h"
#endif

// Function must remain reentrant and not utilize NHLOS or external library calls which
// are not reentrant or potentially cause any type of NHLOS blocking to occur.

#include "stdint.h"
#include "tms_utils.h"

size_t tms_utils_chr_append(tms_chr* out_buf_p, size_t out_buf_sz, tms_chr const* in_buf_p, size_t in_buf_sz)
{
   tms_chr* out_p = out_buf_p;
   tms_chr const* in_p = in_buf_p;

   while (out_buf_sz && out_p && *out_p)
   {
      out_buf_sz--, out_p++;
   }

   while (out_buf_sz && out_p && in_buf_sz && in_p && *in_p)
   {
      *out_p = *in_p;

      out_buf_sz--, out_p++;

      in_buf_sz--, in_p++;
   }

   if (out_buf_sz && out_p)
   {
      *out_p = '\0';

      return out_p - out_buf_p;
   }

   if (out_p && out_p - out_buf_p)
   {
      *(out_p - 1) = '\0';

      return out_p - out_buf_p;
   }

   return 0;
}
