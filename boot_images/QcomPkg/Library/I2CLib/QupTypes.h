#ifndef _QUPTYPES_H_
#define _QUPTYPES_H_
/*
===========================================================================

FILE:   QupTypes.h

DESCRIPTION:
    This file contains the Standard Types.

===========================================================================

        Edit History


When     Who    What, where, why
-------- ---    -----------------------------------------------------------
02/01/17 VG     Copyright updated 
06/13/12 LK     Created

===========================================================================
    Copyright (c) 2012-2017 Qualcomm Technologies, Incorporated.
                        All rights reserved.
    Qualcomm Technologies, Confidential and Proprieta
===========================================================================
*/


/* The following definitions are the same accross platforms.  This first
** group are the sanctioned types.
*/


#ifndef _ARM_ASM_
#ifndef _BOOLEAN_DEFINED
typedef  unsigned char      boolean;     /* Boolean value type. */
#define _BOOLEAN_DEFINED
#endif


#if defined(DALSTDDEF_H) /* guards against a known re-definer */
#define _BOOLEAN_DEFINED
#define _UINT32_DEFINED
#define _UINT16_DEFINED
#define _UINT8_DEFINED
#define _INT32_DEFINED
#define _INT16_DEFINED
#define _INT8_DEFINED
#define _UINT64_DEFINED
#define _INT64_DEFINED
#define _BYTE_DEFINED
#endif /* #if !defined(DALSTDDEF_H) */


#ifndef _UINT32_DEFINED
typedef  unsigned int       uint32;      /* Unsigned 32 bit value */
#define _UINT32_DEFINED
#endif

#ifndef _UINT16_DEFINED
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
#define _UINT16_DEFINED
#endif

#ifndef _UINT8_DEFINED
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
#define _UINT8_DEFINED
#endif

#ifndef _INT32_DEFINED
typedef  signed int         int32;       /* Signed 32 bit value */
#define _INT32_DEFINED
#endif

#ifndef _INT16_DEFINED
typedef  signed short       int16;       /* Signed 16 bit value */
#define _INT16_DEFINED
#endif

#ifndef _INT8_DEFINED
typedef  signed char        int8;        /* Signed 8  bit value */
#define _INT8_DEFINED
#endif

#ifndef _BYTE_DEFINED
typedef  unsigned char      byte;        /* byte type */
#define  _BYTE_DEFINED
#endif


#ifndef TRUE
#define TRUE   1   /* Boolean true value. */
#endif

#ifndef FALSE
#define FALSE  0   /* Boolean false value. */
#endif

#ifndef NULL
#define NULL  0
#endif

#endif /* _ARM_ASM_ */
#endif /* _QUPTYPES_H */


