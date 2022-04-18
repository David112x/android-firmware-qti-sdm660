#ifndef UART_LOG_H
#define UART_LOG_H
/*==================================================================================================

FILE: Uart_log.h

DESCRIPTION: Defines the logging feature APIs for the UART driver.

Copyright (c) 2013-2016 Qualcomm Technologies, Inc.
        All Rights Reserved.
Qualcomm Technologies, Inc. Confidential and Proprietary.

==================================================================================================*/

/*==================================================================================================
Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/buses/uart_lite/inc/Uart_log.h#1 $

when       who     what, where, why
--------   ---     --------------------------------------------------------
07/10/13   VV      Initial revision.

==================================================================================================*/

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/

#include "Uart_defs.h"


void   uart_log( uint8 file_id, uint16 line, uint8 num_args, uint32 a1, uint32 a2, uint32 a3 );

#ifdef UART_LOG_ALL
   #define UART_MSG_INFO( format, num_args, a1, a2, a3 ) \
                 uart_log((uint8) UART_LOGGING_FILE_ID, (uint16) __LINE__,num_args, a1, a2, a3)
#else
   #define UART_MSG_INFO( format, num_args, a1, a2, a3 )
#endif

#if ( defined(UART_LOG_ALL) || defined(UART_LOG_ERROR))
   #define UART_MSG_ERROR( format, num_args, a1, a2, a3 ) \
                 uart_log((uint8) UART_LOGGING_FILE_ID, (uint16) __LINE__,num_args, a1, a2, a3)
#else
   #define UART_MSG_ERROR( format, num_args, a1, a2, a3 )
#endif


#define UART_LOG( level, format )                  UART_LOG_0( level, format )
#define UART_LOG_0( level, format )                UART_MSG_##level( format, 0,  0,  0,  0 )
#define UART_LOG_1( level, format, a1 )            UART_MSG_##level( format, 1, a1,  0,  0 )
#define UART_LOG_2( level, format, a1, a2 )        UART_MSG_##level( format, 2, a1, a2,  0 )
#define UART_LOG_3( level, format, a1, a2, a3 )    UART_MSG_##level( format, 3, a1, a2, a3 )

#ifdef UART_QDSS_ENABLE
#include "UARTLiteSWEventId.h"
#include "tracer_micro.h"

#define UART_QDSS_LOG_0( log )     UTRACER_EVENT( log ) 
#define UART_QDSS_LOG_1( log, a1 ) UTRACER_EVENT( log, a1 ) 

#else 
#define UART_QDSS_LOG_0( log )  
#define UART_QDSS_LOG_1( log, a1 ) 

#endif

#endif


