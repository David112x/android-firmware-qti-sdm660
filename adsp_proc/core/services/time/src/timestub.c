/*=============================================================================

                   T I M E   S E R V I C E   S U B S Y S T E M

GENERAL DESCRIPTION
  Implements time-keeping functions using various sources.


EXTERNALIZED FUNCTIONS
  time_get( )
    Retrieves time according to CDMA, HDR, GSM, or slow-clock Time-of-Day

REGIONAL FUNCTIONS
  
INITIALIZATION AND SEQUENCING REQUIREMENTS


Copyright (c) 2003 - 2017 by QUALCOMM Technologies Incorporated.  All Rights Reserved.

=============================================================================*/


/*=============================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/core.qdsp6/1.0.c2/services/time/src/timestub.c#1 $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
11/05/13   abh     File created.

=============================================================================*/



/*=============================================================================

                           INCLUDE FILES

=============================================================================*/

#include "time_svc.h"
#include "qurt.h"
#include "timetick_sclk64.h"

/*=============================================================================

                           MACROS

=============================================================================*/

#define TIME_MODEM_PROC_ID              0
#define TIME_LPASS_PROC_ID              1
#define TIME_CNSS_PROC_ID               2
#define TIME_SENSOR_PROC_ID             3
#define TIME_LAST_PROC_ID               TIME_SENSOR_PROC_ID
#define TIME_APPS_PROC_ID               (TIME_LAST_PROC_ID + 1)


/*=============================================================================

                           DATA DEFINITIONS

=============================================================================*/


/*-----------------------------------------------------------------------------

                      SYSTEM TIMESTAMP FORMAT


   |<------------ 48 bits --------------->|<----- 16 bits ------->|
   +--------------------------------------+-----------------------+
   |      1.25 ms counter                 |   1/32 chip counter   |
   +--------------------------------------+-----------------------+
         (11K years of dynamic range)          (1.25 ms dynamic
                                                range. Rolls over
                                                at count 49152)

-----------------------------------------------------------------------------*/


/*=============================================================================

                           FUNCTION DEFINITIONS

=============================================================================*/


/*=============================================================================

FUNCTION TIME_GET

DESCRIPTION
  Returns the current time

DEPENDENCIES
  A valid CDMA time, HDR time, GSM time, or a Time-of-Day, etc.

RETURN VALUE
  Time-stamp returned to ts_val parameter.
  Time source used to determine time is returned

SIDE EFFECTS
  None

=============================================================================*/

time_source_enum_type time_get
(
  /* OUT: The current time */
  time_type                       ts_val
)
{
	unsigned long long time_in_ms = 0;
	unsigned long long ticks = 0;
	
	/* Non Blocking Api to get the ticks */
	ticks = qurt_sysclock_get_hw_ticks();
    /*Get time in micro sec*/
	time_in_ms = qurt_sysclock_timetick_to_us(ticks);
    /* Divided by 1000 to convert to milli sec*/
	time_in_ms = ((time_in_ms*1073742)>>30);
	time_in_ms = time_in_ms *4;
	time_in_ms = time_in_ms/5;
	time_in_ms = time_in_ms<<16;
    qw_set(ts_val, (uint32)(time_in_ms>>32), time_in_ms);

    return TIME_SOURCE_32KHZ;

} /* time_get */


/*=============================================================================

FUNCTION TIME_GET_UPTIME

DESCRIPTION
  Returns the uptime in timestamp format

DEPENDENCIES
  
RETURN VALUE
  Source of the time

SIDE EFFECTS
  None

=============================================================================*/
time_source_enum_type time_get_uptime
(
  /* OUT: The current time */
  time_type                       ts_val
)
{
  qw_set( ts_val, 0, 0 );
  
  /* Get uptime from sclk_time */
  time_sclk_get( ts_val, (uint64)-1);

  return (time_source_enum_type)(TIME_LPASS_PROC_ID<<4 | TIME_SOURCE_32KHZ);
} /* time_get_uptime */


/*=============================================================================

FUNCTION TIME_INIT

DESCRIPTION
  Initializes time dependencies

=============================================================================*/
void time_init( void )
{
   timetick_sclk64_init();
}
