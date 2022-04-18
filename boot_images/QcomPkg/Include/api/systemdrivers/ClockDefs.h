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

  Copyright (c) 2011-2016 QUALCOMM Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================


  when       who     what, where, why
  --------   ---     ---------------------------------------------------------- 
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
 * Public logging flags for individual clocks
 *
 *  LOG_STATE_CHANGE - Enable logging of enable/disable calls
 *    to a particular node.
 *  LOG_FREQ_CHANGE - Enable logging of frequency changes to
 *    a particular node.
 *  LOG_CONFIG_CHANGE - Enable logging of configuration changes
 *    to a particular node.
 *  LOG_RESET - Enable logging of resets to a particular node.
 *  LOG_SLEEP_CHANGE - Enable logging of sleep state changes.
 */
#define PUBLIC_CLOCK_FLAG_LOG_STATE_CHANGE           0x00000001
#define PUBLIC_CLOCK_FLAG_LOG_FREQ_CHANGE            0x00000002
#define PUBLIC_CLOCK_FLAG_LOG_CONFIG_CHANGE          0x00000004
#define PUBLIC_CLOCK_FLAG_LOG_RESET                  0x00000008
#define PUBLIC_CLOCK_FLAG_LOG_SLEEP_CHANGE           0x00000010
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000020        0x00000020
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000040        0x00000040
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000080        0x00000080
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000100        0x00000100
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000200        0x00000200
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000400        0x00000400
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00000800        0x00000800
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00001000        0x00001000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00002000        0x00002000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00004000        0x00004000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00008000        0x00008000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00010000        0x00010000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00020000        0x00020000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00040000        0x00040000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00080000        0x00080000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00100000        0x00100000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00200000        0x00200000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00400000        0x00400000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x00800000        0x00800000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x01000000        0x01000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x02000000        0x02000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x04000000        0x04000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x08000000        0x08000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x10000000        0x10000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x20000000        0x20000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x40000000        0x40000000
#define PUBLIC_CLOCK_FLAG_RESERVED_0x80000000        0x80000000

/**
 * Public global logging flags
 *
 *  LOG_x_STATE_CHANGE - Enable logging of enable/disable
 *    calls to all clocks, sources, or power domains as
 *    specified by x.
 *  LOG_CLOCK_FREQ_CHANGE - Enable logging of frequency changes
 *    to all clocks.
 *  LOG_CLOCK_CONFIG_CHANGE - Enable logging of configuration
 *    changes to all clocks.
 *  LOG_CLOCK_RESET - Enable logging of resets to all clocks.
 *  LOG_VOLTAGE_CHANGE - Enable logging of vdd requirement changes.
 *  LOG_CLOCK_SLEEP_CHANGE - Enable logging of sleep state changes.
 *  BIST_IN_PROGRESS - Indicates that a Built-In Self Test is running.
 *  LOG_MISC_STATUS - Enable logging of miscellaneous status info.
 */
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_CLOCK_STATE_CHANGE          0x00000001
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_CLOCK_FREQ_CHANGE           0x00000002
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_CLOCK_CONFIG_CHANGE         0x00000004
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_CLOCK_RESET                 0x00000008
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_SOURCE_STATE_CHANGE         0x00000010
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_POWER_DOMAIN_STATE_CHANGE   0x00000020
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_VOLTAGE_CHANGE              0x00000040
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_SOURCE_FREQ_CHANGE          0x00000080
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00000100             0x00000100
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00000200             0x00000200
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00000400             0x00000400
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00000800             0x00000800
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_CLOCK_SLEEP_CHANGE          0x00001000
#define PUBLIC_CLOCK_GLOBAL_FLAG_BIST_IN_PROGRESS                0x00002000
#define PUBLIC_CLOCK_GLOBAL_FLAG_CPU_TEST_IN_PROGRESS            0x00004000
#define PUBLIC_CLOCK_GLOBAL_FLAG_LOG_MISC_STATUS                 0x00008000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00010000             0x00010000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00020000             0x00020000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00040000             0x00040000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00080000             0x00080000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00100000             0x00100000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00200000             0x00200000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00400000             0x00400000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x00800000             0x00800000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x01000000             0x01000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x02000000             0x02000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x04000000             0x04000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x08000000             0x08000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x10000000             0x10000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x20000000             0x20000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x40000000             0x40000000
#define PUBLIC_CLOCK_GLOBAL_FLAG_RESERVED_0x80000000             0x80000000


/**
  Clock handle.
 */
typedef size_t ClockIdType;


/**
  Source handle.
 */
typedef size_t SourceIdType;


/**
  Used to search for a matching frequency input. This type describes how 
  frequency matching is done for the clock frequency selection function. It 
  also indicates units in Hz, kHz, or MHz.
 */
typedef enum
{
  CLOCK_FREQUENCY_HZ_AT_LEAST  = 0,     /**< Frequency is the minimum allowed in Hz. */
  CLOCK_FREQUENCY_HZ_AT_MOST   = 1,     /**< Frequency is the maximum allowed in Hz. */
  CLOCK_FREQUENCY_HZ_CLOSEST   = 2,     /**< Closest match in Hz. */
  CLOCK_FREQUENCY_HZ_EXACT     = 3,     /**< Exact match only in Hz. */

  CLOCK_FREQUENCY_KHZ_AT_LEAST = 0x10,  /**< Frequency is the minimum allowed in kHz. */
  CLOCK_FREQUENCY_KHZ_AT_MOST  = 0x11,  /**< Frequency is the maximum allowed in kHz. */
  CLOCK_FREQUENCY_KHZ_CLOSEST  = 0x12,  /**< Closest match in kHz. */
  CLOCK_FREQUENCY_KHZ_EXACT    = 0x13,  /**< Exact match only in kHz. */

  CLOCK_FREQUENCY_MHZ_AT_LEAST = 0x20,  /**< Frequency is the minimum allowed in MHz. */
  CLOCK_FREQUENCY_MHZ_AT_MOST  = 0x21,  /**< Frequency is the maximum allowed in MHz. */
  CLOCK_FREQUENCY_MHZ_CLOSEST  = 0x22,  /**< Closest match in MHz. */
  CLOCK_FREQUENCY_MHZ_EXACT    = 0x23,  /**< Exact match only in MHz. */
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
  Clock QDSS levels
 */
typedef enum
{
  CLOCK_QDSS_LEVEL_OFF,      /**< clock set to CXO, and off */
  CLOCK_QDSS_LEVEL_DEBUG,    /**< clock rate follows VDD_CX */
  CLOCK_QDSS_LEVEL_HSDEBUG,  /**< clock set to high speed */
} ClockQDSSLevelType;


/**
  Type of clock configuration.  This type describes how a clock is 
  configured.
 */
typedef enum
{
  CLOCK_CONFIG_NULL                                   = 0,  /**< NULL configuration. */

  CLOCK_CONFIG_MMSS_SOURCE_CSI0                       = 1,  /**< Select CSI0 source. */ 
  CLOCK_CONFIG_MMSS_SOURCE_CSI1                       = 2,  /**< Select CSI1 source. */ 
  CLOCK_CONFIG_MMSS_SOURCE_CSI2                       = 3,  /**< Select CSI2 source. */ 

  CLOCK_CONFIG_AUTOGATE_ENABLE                        = 4,  /**< Enable autogating. */
  CLOCK_CONFIG_AUTOGATE_DISABLE                       = 5,  /**< Disable autogating. */

  CLOCK_CONFIG_BRANCH_ONLY_ENABLE                     = 6,  /**< Enable clock branch only. */
  CLOCK_CONFIG_BRANCH_ONLY_DISABLE                    = 7,  /**< Disable clock branch only. */

  CLOCK_CONFIG_MARK_SUPPRESSIBLE                      = 8,  /**< Mark the clock as suppressible. */
  CLOCK_CONFIG_MARK_INSUPPRESSIBLE                    = 9,  /**< Mark the clock as insuppressible. */

  CLOCK_CONFIG_SUSPEND_REF_COUNTING                   = 10, /**< Suspend reference counting for the clock. */
  CLOCK_CONFIG_RESUME_REF_COUNTING                    = 11, /**< Resume reference counting for the clock. */

  CLOCK_CONFIG_MARK_ALWAYS_ON_TRUE                    = 12, /**< Mark the clock as always on. */
  CLOCK_CONFIG_MARK_ALWAYS_ON_FALSE                   = 13, /**< Mark the clock as not always on. */

  CLOCK_CONFIG_FORCE_MEM_CORE_ENABLED                 = 14, /**< Enable override of the normal FORCE MEM CORE operation. */
  CLOCK_CONFIG_FORCE_MEM_PERIPH_ENABLED               = 15, /**< Enable override of the normal FORCE MEM PERIPH operation. */
  CLOCK_CONFIG_FORCE_MEM_CORE_AND_MEM_PERIPH_ENABLED  = 16, /**< Enable override of the normal FORCE MEM CORE & FORCE MEM PERIPH operation. */

  CLOCK_CONFIG_REPORT_CX_RAIL_UPDATES                 = 17, /**< Enable CX rail update callbacks. */

  CLOCK_CONFIG_FOOTSWITCH_CORE_FORCE_ON               = 18, /**< Force the core to remain on when the clock is disabled. This is generally the default. */
  CLOCK_CONFIG_FOOTSWITCH_CORE_ALLOW_OFF              = 19, /**< Allow the core logic to turn off when the core clock turns off. */
  CLOCK_CONFIG_FOOTSWITCH_PERIPHERAL_FORCE_ON         = 20, /**< Force the peripheral logic to remain on when the clock is disabled. */
  CLOCK_CONFIG_FOOTSWITCH_PERIPHERAL_ALLOW_OFF        = 21, /**< Allow the peripheral logic to turn off when the core clock turns off. This is generally the default. */
  CLOCK_CONFIG_FOOTSWITCH_PERIPHERAL_FORCE_OFF        = 22, /**< Force the peripheral logic to remain off even when the clock is on. */
  CLOCK_CONFIG_FOOTSWITCH_PERIPHERAL_ALLOW_ON         = 23, /**< Allow the peripheral logic to turn on when the clock is on. This is generally the default. */

  /** @cond 
  */
  CLOCK_CONFIG_TOTAL = 24
  /** @endcond */
} ClockConfigType;

/**
  Type of clock data request. This type identifies miscellaneous clock data, including
  configuration values stored in a row of BSP data for each clock frequency.
 */
typedef enum
{
  CLOCK_REQUEST_DATA_NUMBER_OF_FREQUENCY_LEVELS       = 0,  /**< Clock Request: Number of frequency levels */
  CLOCK_REQUEST_DATA_FREQUENCY_HZ                     = 1,  /**< Clock Request: Frequency in Hz */
  CLOCK_REQUEST_DATA_VOLTAGE_CORNER                   = 2,  /**< Clock Request: Voltage Corner */
  CLOCK_REQUEST_DATA_VOLTAGE_UV                       = 3,  /**< Clock Request: Voltage uV */

  /** @cond
  */
  CLOCK_REQUEST_DATA_TOTAL = 4
  /** @endcond */
} ClockRequestDataType;

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
typedef size_t ClockPowerDomainIdType;


/** @} */ /* end_addtogroup power_domain_functions */

/** @addtogroup topology_functions
@{ */

/**
 * Enumeration of clusters comprising the APSS.
 */
typedef enum
{
  CLOCK_APPS_CLUSTER_A7,
  CLOCK_APPS_CLUSTER_A53,
  CLOCK_APPS_CLUSTER_A57,
  CLOCK_APPS_CLUSTER_CCI,
  CLOCK_APPS_CLUSTER_HYDRA_0,
  CLOCK_APPS_CLUSTER_HYDRA_1,
  CLOCK_APPS_CLUSTER_CBF,
  CLOCK_APPS_CLUSTER_SILVER,
  CLOCK_APPS_CLUSTER_GOLD,
  CLOCK_APPS_CLUSTER_TOTAL
} ClockAppsClusterIdType;

/**
  Types of cores recognized in a topology.
 */
typedef enum
{
  CLOCK_CORE_PROCESSOR,
  CLOCK_CORE_L1_CACHE,
  CLOCK_CORE_L2_CACHE,
  CLOCK_CORE_L3_CACHE,
  CLOCK_CORE_CCI,
  CLOCK_CORE_CBF,
  CLOCK_CORE_TYPE_TOTAL
} ClockCoreType;

/**
  Types of clusters recognized in a topology.
 */
typedef enum
{
  CLOCK_CLUSTER_SYNCHRONOUS,
  CLOCK_CLUSTER_ASYNCHRONOUS,
  CLOCK_CLUSTER_TYPE_TOTAL
} ClockClusterType;


/** @} */ /* end_addtogroup topology_functions */

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


/*
 * Impending CPU core state.
 */
typedef enum
{
  CLOCK_CORE_WENT_OFFLINE,          /* Processor core went offline. */
  CLOCK_CORE_COMING_ONLINE,         /* Processor core coming online. */
  CLOCK_CORE_STATE_TOTAL
} ClockCoreStateType;

/*
 * CPR Client ID Type.
 */
typedef enum
{
  CLOCK_VREG_VDD_APC0_CLIENT_A53,
  CLOCK_VREG_VDD_APC0_CLIENT_CCI,
  CLOCK_VREG_VDD_APC0_CLIENT_TOTAL,
  CLOCK_VREG_VDD_APC1_CLIENT_A57 = 0,
  CLOCK_VREG_VDD_APC1_CLIENT_TOTAL,
  CLOCK_VREG_VDD_APC_CLIENT0 = 0,    /* Single rail, multiple clients configuration. */
  CLOCK_VREG_VDD_APC_CLIENT1,        /* ---------------------//--------------------- */
  CLOCK_VREG_VDD_APC_CLIENT2,        /* ---------------------//--------------------- */
  CLOCK_VREG_VDD_GFX_CLIENT0,        /* Graphics rail client                         */
  CLOCK_VREG_VDD_APC_CLIENTX_TOTAL,  /* ---------------------//--------------------- */
  CLOCK_VREG_VDD_APC0_CLIENT0 = 0,   /* Multiple rails, single client configuration. */
  CLOCK_VREG_VDD_APC1_CLIENT0,       /* ---------------------//--------------------- */
  CLOCK_VREG_VDD_APC2_CLIENT0,       /* ---------------------//--------------------- */
  CLOCK_VREG_VDD_APCX_CLIENTX_TOTAL, /* ---------------------//--------------------- */
} ClockVRegClientIdType;

/*
 * Voltage regulator ID Type.
 */
typedef enum
{
  CLOCK_VREG_VDD_CX,
  CLOCK_VREG_VDD_MSS,
  CLOCK_VREG_VDD_APC,
  CLOCK_VREG_VDD_APC0,
  CLOCK_VREG_VDD_APC1,
  CLOCK_VREG_VDD_CBF,
  CLOCK_VREG_VDD_GFX,
  CLOCK_VREG_TOTAL
} ClockVRegIdType;


/*
 * CPR Voltage Corner Type.
 */
typedef enum
{
  CPR_CORNER_LOW_SVS,
  CPR_CORNER_SVS,
  CPR_CORNER_NOMINAL,
  CPR_CORNER_TURBO,
  CPR_CORNER_TOTAL
} ClockCPRCornerType;


/*
 * CPR3 Voltage Corner Type.
 */
typedef enum
{
  CPR3_CORNER_MIN_SVS_FUSE,
  CPR3_CORNER_MIN_SVS,
  CPR3_CORNER_LOW_SVS_FUSE,
  CPR3_CORNER_LOW_SVS,
  CPR3_CORNER_SVS_FUSE,
  CPR3_CORNER_SVS,
  CPR3_CORNER_SVS_L1_FUSE,
  CPR3_CORNER_SVS_L1,
  CPR3_CORNER_NOMINAL_FUSE,
  CPR3_CORNER_NOMINAL,
  CPR3_CORNER_NOMINAL_L1_FUSE,
  CPR3_CORNER_NOMINAL_L1,
  CPR3_CORNER_TURBO_FUSE,
  CPR3_CORNER_TURBO,
  CPR3_CORNER_TOTAL
} ClockCPR3CornerType;


/*
 * CPR callback functions
 */
typedef void (*CPR_PreSwitchFuncPtr) (void *pContext, void *pClientContext);
typedef void (*CPR_GetVoltageFuncPtr)(void *pContext, void *pClientContext, uint32 nVoltageMode, uint32 *pRawVoltageUV);
typedef void (*CPR_PostSwitchFuncPtr)(void *pContext, void *pClientContext, boolean bIsLDOEnabled, uint32 nRawVoltageUV);

typedef void (*CPR_GfxLprmDisableEnterFuncPtr)(void);
typedef void (*CPR_GfxLprmDisableExitFuncPtr) (void);


/*
 * CLOCK AVS interrupt request type.  These types are used to program
 * the AVS hardware to generate various interrupts used by the AVS system when
 * implemented in SW.
 */
typedef enum
{

  CLOCK_AVS_INT_REQUEST_SW_DONE = 0,            /* HW ACK of SW write adjust Vdd */
  CLOCK_AVS_INT_REQUEST_MAX_LVL_EXCEEDED,       /* Vdd request above maximum level */
  CLOCK_AVS_INT_REQUEST_MIN_LVL_EXCEEDED,       /* Vdd request below minimum level */

} ClockAvsIntRequestType;


/*
 * Corner voltage data.
 */
typedef struct
{
  uint32              nUVMin;                   /* voltage floor (uV)                     */
  uint32              nUVMinStatic;             /* static voltage floor (uV)              */
  uint32              nUVMax;                   /* voltage ceiling (uV)                   */
  uint32              nUVMaxStatic;             /* static voltage ceiling (uV)            */
  ClockCPRCornerType  eCornerType;              /* CPR Corner Type enum                   */
  uint32              nFreqKHz;                 /* corresponding frequency (KHz)          */
  uint32              nInitialVoltageUV;        /* initial voltage (uV)                   */
  uint32              nInitialVoltageUVStatic;  /* static initial voltage (uV)            */
  uint32              nUVMinAdj;                /* Max Floor to Ceiling Range (uV)        */
  int                 nOLVAdjUV;                /* CPR Open Loop Adjustment (uV)          */
  int                 nCLVAdjUV;                /* CPR Closed Loop Adjustment (uV)        */
  int                 nOLVAdjUVStatic;          /* static CPR Open Loop Adjustment (uV)   */
  int                 nCLVAdjUVStatic;          /* static CPR Closed Loop Adjustment (uV) */
  uint32              nVC;                      /* virtual corner from the voltage plan   */
} ClockVRegCornerDataType;


/*
 * Limits Management callback functions
 */
typedef void (*LM_CpuUpdateFuncPtr)(uint32 nVoltageCorner);
typedef void (*LM_GpuUpdateFuncPtr)(uint32 nVoltageCorner);


/*
 * Clock Debug List Data Structure.
 */
typedef struct
{
  uint32      nDebugId;             /* QDSS clock debug ID */
  uint32      nIndex;               /* clock index */
} ClockDebugListDataStructureType;


/*
 * Clock Debug Data Structure.
 */
typedef struct
{
  uint32      nDebugId;             /* QDSS clock debug ID */
  const char *szClockName;          /* clock name string */
} ClockDebugDataStructureType;


/*
 * Debug filter type used to specify data of interest.
 */
typedef enum
{                                   /* Returns data for: */
  CLOCK_FILTER_NONE,                /*  all clocks */
  CLOCK_FILTER_ENABLED,             /*  all clocks in ENABLED state */
  CLOCK_FILTER_ON,                  /*  all clocks in ON state */
  CLOCK_FILTER_REF,                 /*  all clocks with non-zero reference count */
  CLOCK_FILTER_XO,                  /*  all clocks blocking XO */
  CLOCK_FILTER_TOTAL
} ClockDebugFilterType;


/*
 * Structure returning all known NPA Resource Name list.
 */
typedef struct KnownNPAResourceNamesList
{
  const char  *szName;
  boolean      bLocal;
  boolean      bBlocksXO;
} KnownNPAResourceNamesList;


/*
 * Structure returning a local NPA Resource's list of clocks.
 */
typedef struct LocalNPAResourceClocksList
{
  const char  *szName;
  const void  *pNULL;
} LocalNPAResourceClocksList;


/**
  Processor Sleep mode flag masks. RAMP_DOWN_CPU triggers frequency switching 
  to a lower performance level before SWFI.  L2CACHE_FLUSH flushes the contents
  of L2 cache when entering power collapse. In some cases, the L2 cache frequency
  needs to be lowered with the CPU frequency. In other cases, the L2 cache
  frequency needs to remain untouched. This is when the RAMP_DOWN_L2CACHE flag
  becomes useful.
 */
#define CLOCK_SLEEP_FLAG_NONE                   0x00000000
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_CPU          0x00000001
#define CLOCK_SLEEP_FLAG_L2CACHE_FLUSH          0x00000002
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_L2CACHE      0x00000004
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_L3CACHE      0x00000008
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_APSS         0x00000010
#define CLOCK_SLEEP_FLAG_RAMP_DOWN_XO           0x00000010
#define CLOCK_SLEEP_FLAG_CORE_RET               0x00000020


/*
 * Clock Driver External Configuration Parameter Type.
 */
typedef enum
{
  CLOCK_CONFIG_PARAM_APCS_VOLTAGE_STEP_SIZE,
  CLOCK_CONFIG_PARAM_APCS_VOLTAGE_OFFSET,
  CLOCK_CONFIG_PARAM_IS_EXTERNAL_BUCK_USED,
  CLOCK_CONFIG_PARAM_APCS_SHARED_CX_RAIL,
  CLOCK_CONFIG_PARAM_RETURN_SPEED_BIN,
  CLOCK_CONFIG_PARAM_RETURN_SPEED_BIN_RAW,
  CLOCK_CONFIG_PARAM_RETURN_SPEED_BIN_STATUS,
  CLOCK_CONFIG_PARAM_RETURN_PVS_BIN,
  CLOCK_CONFIG_PARAM_RETURN_PVS_BIN_SECONDARY,
  CLOCK_CONFIG_PARAM_RETURN_UPLIFT_FUSE,
  CLOCK_CONFIG_PARAM_RETURN_ACC_L1_REGISTER,
  CLOCK_CONFIG_PARAM_RETURN_METAL_REV,
  CLOCK_CONFIG_PARAM_RETURN_SPEED_BIN_SECONDARY,
  CLOCK_CONFIG_PARAM_RETURN_VOLTAGE_PLAN_VERSION,
  CLOCK_CONFIG_PARAM_INTERPOLATION_MODE,
  CLOCK_CONFIG_PARAM_DYNAMIC_CEILING_MODE,
  CLOCK_CONFIG_PARAM_DYNAMIC_FLOOR_MODE,
  CLOCK_CONFIG_PARAM_PLL_SLEWING_MODE,
  CLOCK_CONFIG_PARAM_GFX_FULL_RPM_EMULATION_MODE,
  CLOCK_CONFIG_PARAM_PLL_DROOP_DETECTION_MODE,
  CLOCK_CONFIG_PARAM_ACD_REDUCTION_MODE,
  CLOCK_CONFIG_PARAM_APM_CONTROL_MODE,
  CLOCK_CONFIG_PARAM_LDO_CONTROL_MODE,
  CLOCK_CONFIG_PARAM_LDO_MAX_VOLTAGE_UV,
  CLOCK_CONFIG_PARAM_LDO_MIN_VOLTAGE_UV,
  CLOCK_CONFIG_PARAM_LDO_MIN_HEADROOM_UV,
  CLOCK_CONFIG_PARAM_LDO_SAFETY_MARGIN_UV,
  CLOCK_CONFIG_PARAM_LDO_APC_RETENTION_UV,
  CLOCK_CONFIG_PARAM_GLOBAL_VOLTAGE_LIMIT_UV,
  CLOCK_CONFIG_PARAM_GET_GPU_MIN_FREQUENCY,
  CLOCK_CONFIG_PARAM_GET_GPU_MAX_FREQUENCY,
  CLOCK_CONFIG_PARAM_SET_GPU_MIN_FREQUENCY,
  CLOCK_CONFIG_PARAM_SET_GPU_MAX_FREQUENCY,
  CLOCK_CONFIG_PARAM_GET_DCVS_STATE,
  CLOCK_CONFIG_PARAM_GET_CPR_STATE,
  CLOCK_CONFIG_PARAM_SET_DCVS_STATE,
  CLOCK_CONFIG_PARAM_SET_CPR_STATE,
  CLOCK_CONFIG_PARAM_TOTAL,
} eConfigParamType;


/*
 * Clock Driver External Context Value Type.
 */
typedef enum
{
  CLOCK_CONTEXT_LMH_NODE_LOCK_POINTER,
  CLOCK_CONTEXT_TOTAL,
} eContextValueType;


typedef struct
{
  uint32  nVoltageOffset;             /* Number of 10mV steps to offset from the standard voltage. */
  boolean bSubtract;                  /* 1: subtract,
                                         0: add the nVoltageOffset from/to the standard voltage. */
} ClockCprEfuseType;


/**
 * PVS and Speed Bin Validation Parameter Type.
 */
typedef struct
{
  uint32            nChipId;            /* Chip ID as returned by the ChipInfo library */
  uint32            nChipVersion;       /* Chip Version in the MAJOR.minor format */
  uint32            nPVSBin;            /* PVS bin number */
  uint32            nPVSBinSecondary;   /* Secondary PVS bin number */
  uint32            nSpeedBinRaw;       /* Speed bin number */
  uint32            nSpeedBinStatus;    /* Speed bin status */
  uint32            nCPRRev;            /* CPR Revision Level */
  uint32            nAccL1Register;     /* Normalized value of the ACC_L1 Register 0xFC4B81B4[15:10] */
  uint32            nUpliftFuse;        /* Normalized value of the UPLIFT_FUSE 0xFC4B80B4[53] */
  uint32            nMetalRev;          /* Normalized value of the METAL_REV 0xFC4B8454[19:18] */
  ClockCprEfuseType C0_SVS2;            /* Normalized value of the APSS Cluster 0 SVS2 e-fuse */
  ClockCprEfuseType C0_SVS;             /* Normalized value of the APSS Cluster 0 SVS e-fuse */
  ClockCprEfuseType C0_Nominal;         /* Normalized value of the APSS Cluster 0 Nominal e-fuse */
  ClockCprEfuseType C0_Turbo;           /* Normalized value of the APSS Cluster 0 Turbo e-fuse */
  ClockCprEfuseType C1_SVS2;            /* Normalized value of the APSS Cluster 1 SVS2 e-fuse */
  ClockCprEfuseType C1_SVS;             /* Normalized value of the APSS Cluster 1 SVS e-fuse */
  ClockCprEfuseType C1_Nominal;         /* Normalized value of the APSS Cluster 1 Nominal e-fuse */
  ClockCprEfuseType C1_Turbo;           /* Normalized value of the APSS Cluster 1 Turbo e-fuse */
  uint32            nSpeedBinPrimary;   /* Primary Cluster speed bin number */
  uint32            nSpeedBinSecondary; /* Secondary Cluster speed bin number */
} ClockBinValidationType;


/** @} */ /* end_addtogroup misc_functions */

/** @addtogroup npa_functions
@{ */
/** @name NPA Query Requests
@{ */

/**
  NPA query ID for a performance level frequency. This query 
  gets the frequency in kHz for the node performance level. The actual
  performance level is to be added to this ID (i.e., to query frequency
  for performance level 2, pass DALCLOCK_NPA_QUERY_PERF_LEVEL_KHZ + 2).
 */
#define CLOCK_NPA_QUERY_PERF_LEVEL_KHZ (NPA_QUERY_RESERVED_END + 1)

/**
  NPA query ID for the number of supported performance levels.
  This query returns the number of supported performance levels for
  the resource in question.
 */
#define CLOCK_NPA_QUERY_NUM_PERF_LEVELS (CLOCK_NPA_QUERY_PERF_LEVEL_KHZ + 0x20)

/**
  NPA query for the minimum supported frequency in kHz for a resource.
  This query returns the minimum supported frequency for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_MIN_FREQ_KHZ (CLOCK_NPA_QUERY_NUM_PERF_LEVELS + 1)

/**
  NPA query ID for the corner voltage table.
  This query returns the voltage values of each corner for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE (CLOCK_NPA_QUERY_MIN_FREQ_KHZ + 1)

/**
  NPA query ID for the number of voltage corners.
  This query returns the number of voltage corners for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES (CLOCK_NPA_QUERY_VOLTAGE_TABLE + 1)

/**
  NPA query ID for the current voltage corner.
  This query returns the id (voltage table index) of for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY (CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES + 1)

/**
  NPA query ID for the corner voltage table of rail 0.
  This query returns the voltage values of each corner for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_RAIL_0 (CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_CLUSTER_0 CLOCK_NPA_QUERY_VOLTAGE_TABLE_RAIL_0

/**
  NPA query ID for the number of voltage corners of rail 0.
  This query returns the number of voltage corners for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_RAIL_0 (CLOCK_NPA_QUERY_VOLTAGE_TABLE_RAIL_0 + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_CLUSTER_0 CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_RAIL_0

/**
  NPA query ID for the current voltage corner of rail 0.
  This query returns the id (voltage table index) of for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_RAIL_0 (CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_RAIL_0 + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_CLUSTER_0 CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_RAIL_0

/**
  NPA query ID for the corner voltage table of rail 1.
  This query returns the voltage values of each corner for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_RAIL_1 (CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_RAIL_0 + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_CLUSTER_1 CLOCK_NPA_QUERY_VOLTAGE_TABLE_RAIL_1

/**
  NPA query ID for the number of voltage corners of rail 1.
  This query returns the number of voltage corners for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_RAIL_1 (CLOCK_NPA_QUERY_VOLTAGE_TABLE_RAIL_1 + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_CLUSTER_1 CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_RAIL_1

/**
  NPA query ID for the current voltage corner of rail 1.
  This query returns the id (voltage table index) of for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_RAIL_1 (CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_RAIL_1 + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_CLUSTER_1 CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_RAIL_1

/**
  NPA query ID for the corner voltage table for CCI.
  This query returns the voltage values of each corner for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_CCI (CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_RAIL_1 + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_CBF CLOCK_NPA_QUERY_VOLTAGE_TABLE_CCI

/**
  NPA query ID for the number of voltage corners for CCI.
  This query returns the number of voltage corners for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_CCI (CLOCK_NPA_QUERY_VOLTAGE_TABLE_CCI + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_CBF CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_CCI

/**
  NPA query ID for the current voltage corner for CCI.
  This query returns the id (voltage table index) of for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_CCI (CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_CCI + 1)
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_CBF CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_CCI

/**
  NPA query ID for the corner voltage table for GFX.
  This query returns the voltage values of each corner for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_TABLE_GFX (CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_CCI + 1)

/**
  NPA query ID for the number of voltage corners for GFX.
  This query returns the number of voltage corners for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_GFX (CLOCK_NPA_QUERY_VOLTAGE_TABLE_GFX + 1)

/**
  NPA query ID for the current voltage corner for GFX.
  This query returns the id (voltage table index) of for the resource
  based on the target and configured limitations.
 */
#define CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_GFX (CLOCK_NPA_QUERY_VOLTAGE_NUM_ENTRIES_GFX + 1)

/**
  NPA query for the CPU rail voltage in mV.

  NOTE: This is the clock driver's vote for the CPU VREG, but it may not map
        directly to the supplied voltage. In cases where the CPU VREG isn't
        wholly owned by the CPU, then the actual VREG voltage will be at least
        this level, but may be higher.
 */
#define CLOCK_NPA_QUERY_CPU_RAIL_VOLTAGE_MV (CLOCK_NPA_QUERY_VOLTAGE_CURRENT_ENTRY_GFX + 1)


/** @} */ /* end_name_group NPA Query Requests */
/** @} */ /* end_addtogroup npa_functions */


#endif /* !CLOCKDEFS_H */

