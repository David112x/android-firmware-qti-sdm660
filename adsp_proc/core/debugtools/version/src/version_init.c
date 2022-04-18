/** vi: tw=128 ts=3 sw=3 et
@file version_init.c
@brief This file contains the API for the IMAGE VERSION, API 1.0.1
*/
/*=============================================================================
NOTE: The @brief description above does not appear in the PDF.
The tms_mainpage.dox file contains the group/module descriptions that
are displayed in the output PDF generated using Doxygen and LaTeX. To
edit or update any of the group/module text in the PDF, edit the
tms_mainpage.dox file or contact Tech Pubs.
===============================================================================*/
/*=============================================================================
Copyright (c) 2014-16 Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Confidential and Proprietary
=============================================================================*/
/*=============================================================================
Edit History
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/version/src/version_init.c#1 $
$DateTime: 2020/02/10 01:57:30 $
$Change: 22511909 $
$Author: pwbldsvc $
===============================================================================*/

#include "version.h"

#include "comdef.h"
#include "image_version.h"

void version_init(void)
{
   // IMAGE_INDEX is defined in version.scons
   if (0 != image_version_populate_version(IMAGE_INDEX))
   {
      //ERR("unable to populate version", 0, 0, 0);
   }
}
