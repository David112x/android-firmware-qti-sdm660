#ifndef CLOCKDEFS_H
#define CLOCKDEFS_H
/*
===========================================================================
*/
/**
  @file ClockDefs.h
  @brief Public definitions include file for accessing the clock device driver.
*/
/*===========================================================================
NOTE: The @brief description and any detailed descriptions above do not appear
      in the PDF.

      The Clock_Driver_API_mainpage.dox file contains all file/group
      descriptions that are in the output PDF generated using Doxygen and
      LaTeX. To edit or update any of the file/group text in the PDF, edit the
      Clock_Driver_mainpage.dox file or contact Tech Pubs.

===========================================================================*/
/*
  ===========================================================================

  Copyright (c) 2016 Qualcomm  Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================

  $Header: //components/rel/core.qdsp6/1.0.c2/api/systemdrivers/ClockDefs.h#1 $
  $DateTime: 2020/02/10 01:57:30 $
  $Author: pwbldsvc $

  when       who     what, where, why
  --------   ---     ---------------------------------------------------------- 
  10/11/16   shm     First version for core.qdsp6.1.0
  05/17/11   llg     (Tech Pubs) Edited/added Doxygen comments and markup.

  ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "com_dtypes.h" /* for "uint32" */


/*=========================================================================
      Type Definitions
==========================================================================*/


/** @addtogroup clock_functions
@{ */

/**
  Clock handle.
 */
typedef uint32 ClockIdType;

/**
  Source handle.
 */
typedef uint32 SourceIdType;


/**
  Used to search for a matching frequency input. This type describes how 
  frequency matching is done for the clock frequency selection function. It 
  also indicates units in Hz, kHz, or MHz.
 */
typedef enum
{
  CLOCK_FREQUENCY_HZ_AT_LEAST  = 0,  /**< Frequency is the minimum allowed in Hz. */
  CLOCK_FREQUENCY_HZ_AT_MOST   = 1,  /**< Frequency is the maximum allowed in Hz. */
  CLOCK_FREQUENCY_HZ_CLOSEST   = 2,  /**< Closest match in Hz. */
  CLOCK_FREQUENCY_HZ_EXACT     = 3,  /**< Exact match only in Hz. */

  CLOCK_FREQUENCY_KHZ_AT_LEAST = 0x10,  /**< Frequency is the minimum allowed in kHz. */
  CLOCK_FREQUENCY_KHZ_AT_MOST  = 0x11,  /**< Frequency is the maximum allowed in kHz. */
  CLOCK_FREQUENCY_KHZ_CLOSEST  = 0x12,  /**< Closest match in kHz. */
  CLOCK_FREQUENCY_KHZ_EXACT    = 0x13,  /**< Exact match only in kHz. */

  CLOCK_FREQUENCY_MHZ_AT_LEAST = 0x20,  /**< Frequency is the minimum allowed in MHz. */
  CLOCK_FREQUENCY_MHZ_AT_MOST  = 0x21,  /**< Frequency is the maximum allowed in MHz. */
  CLOCK_FREQUENCY_MHZ_CLOSEST  = 0x22, /**< Closest match in MHz. */
  CLOCK_FREQUENCY_MHZ_EXACT    = 0x23, /**< Exact match only in MHz. */
} ClockFrequencyType;


/**
  Type of clock reset. This defines how the reset to the clock domain 
  is to be handled.
 */
typedef enum
{
  CLOCK_RESET_DEASSERT = 0,  /**< Deassert the reset signal. */
  CLOCK_RESET_ASSERT   = 1,  /**< Assert and hold the reset signal. */
  CLOCK_RESET_PULSE    = 2   /**< Assert and immediately deassert. */
} ClockResetType;


/**
 * Clock QDSS levels
 */
typedef enum
{
  CLOCK_QDSS_LEVEL_OFF,      /* clock set to CXO, and off */
  CLOCK_QDSS_LEVEL_DEBUG,    /* clock rate follows VDD_CX */
  CLOCK_QDSS_LEVEL_HSDEBUG,  /* clock set to high speed */
} ClockQDSSLevelType;


/**
  Type of clock configuration.  This type describes how a clock is 
  configured.
 */
typedef enum
{
  CLOCK_CONFIG_MMSS_SOURCE_CSI0             = 1,  /**< Select CSI0 source. */ 
  CLOCK_CONFIG_MMSS_SOURCE_CSI1             = 2,  /**< Select CSI1 source. */ 
  CLOCK_CONFIG_MMSS_SOURCE_CSI2             = 3,  /**< Select CSI2 source. */ 
  CLOCK_CONFIG_LPASS_CORE_MEM_ON            = 4,  /**< Config mem retention. */
  CLOCK_CONFIG_LPASS_CORE_MEM_OFF           = 5,
  CLOCK_CONFIG_LPASS_PERIPH_MEM_ON          = 6,  /**< Config periph mem retention. */
  CLOCK_CONFIG_LPASS_PERIPH_MEM_OFF         = 7,
  CLOCK_CONFIG_LPASS__HW_CTL_ON             = 8,  /**< HW Controlled clock gating. */
  CLOCK_CONFIG_LPASS__HW_CTL_OFF            = 9,
  CLOCK_CONFIG_AUTOGATE_ENABLE              = 10,  /**< Enable autogating. */
  CLOCK_CONFIG_AUTOGATE_DISABLE             = 11,  /**< Disable autogating. */
  CLOCK_CONFIG_DIG_CODEC_SRC_SEL_DIG_CODEC  = 12,
  CLOCK_CONFIG_DIG_CODEC_SRC_SEL_PRI_MI2S   = 13,
  CLOCK_CONFIG_DIG_CODEC_SRC_SEL_SEC_MI2S   = 14,
  /** @cond 
  */
  CLOCK_CONFIG_TOTAL = 15
  /** @endcond */
} ClockConfigType;


/**
  Types of clock source that can be used to select runtime 
  frequency adjustements where supported. Primary refers to the
  main source.
 */
typedef enum
{
  CLOCK_SOURCE_NONE,
  CLOCK_SOURCE_PRIMARY,
  CLOCK_SOURCE_SECONDARY,
  CLOCK_SOURCE_TERNERY,

  CLOCK_SOURCE_TOTAL

}ClockSourceType;


/**
  Options for the DalClock_LogState API.
 */
typedef enum
{
  CLOCK_LOG_STATE_CLOCK_FREQUENCY = (1 << 0),
} ClockLogStateFlags;

/** @} */ /* end_addtogroup clock_functions */

/** @addtogroup power_domain_functions
@{ */


/**
  Power domain handle.
 */
typedef uint32 ClockPowerDomainIdType;


/** @} */ /* end_addtogroup power_domain_functions */

/** @addtogroup misc_functions
@{ */


/**
  Processor Sleep mode. This type defines the different kinds of sleep modes 
  that can be entered.
 */
typedef enum
{
  CLOCK_SLEEP_MODE_HALT,            /**< Processor halt only. */
  CLOCK_SLEEP_MODE_POWER_COLLAPSE   /**< Processor power collapse. */
} ClockSleepModeType;


/**
  Processor Sleep mode flag masks. RAMP_DOWN_CPU triggers frequency switching 
  to a lower performance level before SWFI.  L2CACHE_FLUSH flushes the contents
  of L2 cache when entering power collapse. In some cases, the L2 cache frequency
  needs to be lowered with the CPU frequency. In other cases, the L2 cache
  frequency needs to remain untouched. This is when the RAMP_DOWN_L2CACHE flag
  becomes useful.
 */
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_CPU          0x00000001
#define CLOCK_SLEEP_FLAG_L2CACHE_FLUSH          0x00000002
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_L2CACHE      0x00000004
#define CLOCK_SLEEP_FLAG_RAMP_UP_CPU            0x00000008


/**
 * CPU Identifiers.
 *
 * These are used to place voltage votes to VCS for satisfying CPU voltage
 * requirements.
 */
typedef enum
{
  CLOCK_CPU_MSS_Q6,
  CLOCK_CPU_LPASS_Q6,
  CLOCK_CPU_SLPI_Q6,
  CLOCK_CPU_TURING_Q6,
  CLOCK_CPU_APPS_C0,
  CLOCK_CPU_APPS_C1,
  CLOCK_CPU_APPS_C2,
  CLOCK_CPU_APPS_C3,

  CLOCK_CPU_NUM_OF_CPUS
} ClockCPUType;


/**
 Processor Sleep mode flag masks:
  RAMP_DOWN_CPU
   Triggers frequency switching to a lower performance level before SWFI.

  L2CACHE_FLUSH
   Flushes the contents of L2 cache when entering power collapse.

  RAMP_DOWN_L2CACHE
   In some cases, the L2 cache frequency needs to be lowered with the CPU
   frequency. In other cases, the L2 cache frequency needs to remain untouched.
   This is when the RAMP_DOWN_L2CACHE flag becomes useful.

  PLL_OFF
   Configures the PLL to a state where it is ready for the SPM to power it off.
   It also preloads any configuration registers necessary such that it is ready
   to be used once the SPM powers it back on.
 */
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_CPU          0x00000001
#define CLOCK_SLEEP_FLAG_L2CACHE_FLUSH          0x00000002
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_L2CACHE      0x00000004
#define CLOCK_SLEEP_FLAG_PLL_OFF                0x00000008


/** @} */ /* end_addtogroup misc_functions */

/** @addtogroup npa_functions
@{ */
/** @name NPA Query Requests
@{ */

/**
  NPA Node: /clk/cpu [ALL]
  NPA query ID for a performance level frequency. This query 
  gets the frequency in kHz for the node performance level. The actual
  performance level is to be added to this ID (i.e., to query frequency
  for performance level 2, pass DALCLOCK_NPA_QUERY_PERF_LEVEL_KHZ + 2).
  This interfaces uses 0 as the first index.
 */
#define CLOCK_NPA_QUERY_PERF_LEVEL_KHZ                                        \
  (NPA_QUERY_RESERVED_END + 1)

/**
  NPA Node: /clk/cpu [ALL]
  NPA query ID for the number of supported performance levels.
  This query returns the number of supported performance levels for
  the resource in question.
 */
#define CLOCK_NPA_QUERY_NUM_PERF_LEVELS                                       \
  (CLOCK_NPA_QUERY_PERF_LEVEL_KHZ + 0x20)

/**
  NPA Node: /clk/cpu [ALL]
  NPA query ID for the CPU's max frequency in KHz at the requested corner.
  The voltage corner (i.e. SVS, NOM, TURBO) is to be added to this query ID.

  For example, the query for the max frequency at SVS corner voltage is:

  CLOCK_NPA_QUERY_CPU_MAX_KHZ_AT_CORNER + VCS_CORNER_LOW

  This interfaces uses 0 as the first index.
  See VCSDefs.h for VCS enum of voltage corners.
 */
#define CLOCK_NPA_QUERY_CPU_MAX_KHZ_AT_CORNER                                 \
  (CLOCK_NPA_QUERY_NUM_PERF_LEVELS + 1)

/**
  NPA Node: /clk/cpu [ALL]
  NPA query for the minimum supported frequency in kHz for a resource.
  This query returns the minimum supported frequency for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_MIN_FREQ_KHZ                                          \
  (CLOCK_NPA_QUERY_CPU_MAX_KHZ_AT_CORNER + 0x20)

/**
  NPA Node: /clk/cpu [ALL]
  NPA query ID for the CPU's corner vote on its voltage rail.
  This query returns the CPU's requirement on its VREG, but it may not
  map directly to the supplied voltage. In cases where the CPU VREG isn't
  wholly owned by the CPU, then the actual VREG voltage will be at least
  this level, but may be higher.
 */
#define CLOCK_NPA_QUERY_CPU_RAIL_VOLTAGE_CORNER                               \
  (CLOCK_NPA_QUERY_MIN_FREQ_KHZ + 1)

/**
  NPA Node: /clk/cpu [ALL]
  NPA query ID for the identifier of the rail powering the CPU.
  The returned ID will be one of the enums defined in VCSDefs.h (VCS_RAIL_X).
 */
#define CLOCK_NPA_QUERY_CPU_RAIL_ID                                            \
  (CLOCK_NPA_QUERY_CPU_RAIL_VOLTAGE_CORNER + 1)

/** @} */ /* end_name_group NPA Query Requests */
/** @} */ /* end_addtogroup npa_functions */


#endif /* !CLOCKDEFS_H */
