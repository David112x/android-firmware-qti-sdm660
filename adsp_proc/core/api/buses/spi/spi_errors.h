#ifndef _SPI_ERRORS_H_
#define _SPI_ERRORS_H_
/*
===========================================================================

FILE:   spi_errors.h

DESCRIPTION:
    This file contains the result definitions 

===========================================================================

        Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/api/buses/spi/spi_errors.h#1 $

When     Who    What, where, why
-------- ---    -----------------------------------------------------------
09/26/11 AG     Created

===========================================================================
        Copyright c 2011-2014 Qualcomm Technologies Incorporated.
            All Rights Reserved.
            Qualcomm Proprietary/GTDR

===========================================================================
*/

typedef enum
{
   SPI_SUCCESS =0,
   SPI_ERROR_CLS_DEVICE     = 0x01000000,
   SPI_ERROR_CLS_DRIVER     = 0x04000000,
   SPI_ERROR_CLS_PLATFORM   = 0x0E000000,
   SPI_ERROR_CLS_OS         = 0x0F000000,
} SPI_RESULT;

#endif /* _SPI_ERRORS_H_*/
