#ifndef _GDDEJAVUSANSMONOOBLIQUE_H_
#define _GDDEJAVUSANSMONOOBLIQUE_H_

/*===========================================================================
   Copyright (c) 2013 Qualcomm Technologies, Inc.       
   All Rights Reserved.
   Qualcomm Technologies Proprietary and Confidential.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

  $Header: //components/rel/core.tz/1.0.7.1/securemsm/sse/qsee/SecureDisplay/libgd/include/gd_dejavu_sans_mono_oblique.h#1 $
  $DateTime: 2020/01/14 12:35:09 $
  $Author: pwbldsvc $

when       who      what, where, why
--------   ---      ------------------------------------
07/02/13   ts       Initial version.

===========================================================================*/

/*
	This is a header file for gd font, generated using
	bdftogd version 0.60 by Jan Pazdziora, adelton@fi.muni.cz
	from bdf font
	-FreeType-DejaVu Sans Mono-Medium-I-Normal--17-120-100-100-M-86-ISO8859-1
	at Mon Jul  1 17:04:03 2013.
	The original bdf was holding following copyright:
	"Copyright (c) 2003 by Bitstream, Inc. All Rights Reserved.  DejaVu changes are in public domain  "
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gd.h"

extern BGD_EXPORT_DATA_PROT gdFontPtr gdfontOblique;
BGD_DECLARE(gdFontPtr) gdFontGetOblique(void);

#endif

