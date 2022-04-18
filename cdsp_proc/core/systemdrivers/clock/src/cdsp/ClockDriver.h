#ifndef __CLOCKDRIVER_H__
#define __CLOCKDRIVER_H__
/*
===========================================================================
*/
/**
  @file ClockDriver.h

  Internal header file for the clock device driver.
*/
/*
  ====================================================================

  Copyright (c) 2016 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================

  $Header: //components/rel/core.qdsp6/1.0.c2/systemdrivers/clock/src/cdsp/ClockDriver.h#1 $
  $DateTime: 2020/02/10 01:57:30 $
  $Author: pwbldsvc $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "com_dtypes.h"
#include "comdef.h"
#include "DALSys.h"
#ifdef CLOCK_ULOG_STUB
#include "ClockULogStub.h"
#else
  #include "ULogFront.h"
#endif
#include "ClockDefs.h"
#include "ClockBSP.h"
#ifdef CLOCK_NPA_STUB
#include "ClockNPAStub.h"
#else
  #include "npa.h"
#endif
#include "DDIClock.h"


/*=========================================================================
      Macro Definitions
==========================================================================*/

/**
 * Define __weak for non-rvct compilers.
 */
#ifdef __GNUC__
  #define __weak __attribute__((weak))
#elif !defined(__ARMCC_VERSION)
  #define __weak
#endif

/*
 * Macro defining the total number of supported client contexts.
 * The value of this macro has a direct impact on the clock data 
 * structures size.
 */
#define CLOCK_CTXT_TOTAL             3

/**
 * Macro lock the driver mutex.
 */
#define DALCLOCK_LOCK(drvCtxt) DALSYS_SyncEnter(drvCtxt->hLock)


/**
 * Macro try-lock the driver mutex.
 */
#define DALCLOCK_TRYLOCK(drvCtxt) DALSYS_SyncTryEnter(drvCtxt->hLock)


/**
 * Macro to free the driver mutex.
 */
#define DALCLOCK_FREE(drvCtxt) DALSYS_SyncLeave(drvCtxt->hLock)


/**
 * Convert an NPA state to a frequency in Hz.
 */
#define NPA_TO_HZ(state) \
  (uint32)((state) == NPA_MAX_STATE ? (state) : (state) * 1000)


/*
 * Macros for checking, setting and clearing the unified flag bits in the
 * driver nodes.  Note these work on any structure containing an "nFlags"
 * field.
 */
#define CLOCK_FLAG_IS_SET(ptr, flag) (((ptr)->nFlags & CLOCK_FLAG_##flag) ? TRUE : FALSE)
#define CLOCK_FLAG_SET(ptr, flag)    ((ptr)->nFlags |= CLOCK_FLAG_##flag)
#define CLOCK_FLAG_CLEAR(ptr, flag)  ((ptr)->nFlags &= ~CLOCK_FLAG_##flag)


/*
 * Macros for checking, setting and clearing the global flag bits in the
 * driver context.  Note these work only on the "nGlobalFlags" field
 * within the driver context structure.
 */
#define CLOCK_GLOBAL_FLAG_IS_SET(flag) ((pDrvCtxt->nGlobalFlags & CLOCK_GLOBAL_FLAG_##flag) ? TRUE : FALSE)
#define CLOCK_GLOBAL_FLAG_SET(flag)    (pDrvCtxt->nGlobalFlags |= CLOCK_GLOBAL_FLAG_##flag)
#define CLOCK_GLOBAL_FLAG_CLEAR(flag)  (pDrvCtxt->nGlobalFlags &= ~CLOCK_GLOBAL_FLAG_##flag)


/*
 * Values used for making NPA requests on clock sources.
 *  0: XO is not required at all.
 *  1: XO is always required.
 */
#define CLOCK_SOURCE_NOT_REQUIRED     0
#define CLOCK_SOURCE_REQUIRED         1


/*
 * Default size of the BIST ULOG log buffer.
 *
 * NOTE: The log size should be specified in powers of 2.
 */
#define CLOCK_BIST_DEFAULT_LOG_SIZE   65536


/*
 * Macro to force an enumeration to be a full 32 bits wide.
 */
#define CLOCK_ENUM_32BITS(name) CLOCK_##name##_32BITS = 0x7FFFFFFF


/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * Clock Reference Type for client contexts to keep track of the total number
 * of reference counts for each type of trackable resource.
 */
typedef struct
{
  uint32 nClockRefs;
  uint32 nPowerDomainRefs;
  uint32 nSourceRefs;

}ClockCtxtReferenceType;

/**
 *  ID structure to keep track of allocated client contexts.
 */
typedef struct
{
  uint32                 nPDID;               /**< The ID from the DAL framework associated with a particular PD */
  uint32                 nIdx;                /**< ClockClientCxts[] index associated with this client information */
  boolean                bInUse;              /**< Flag specifying if a client context is currently in use */
  ClockCtxtReferenceType TotalCtxtReferences; /**< The total resource reference count for this context */

}ClockCtxtInfoType;


/*
 * Driver, device and client contexts
 */
typedef struct ClockDALDrvCtxt    ClockDALDrvCtxt;
typedef struct ClockDALDevCtxt    ClockDALDevCtxt;
typedef struct ClockDALClientCtxt ClockDALClientCtxt;


/**
 * Private "Clock" Vtable
 */
typedef struct ClockDALVtbl ClockDALVtbl;
struct ClockDALVtbl
{
  DALResult (*Clock_DriverInit)(ClockDALDrvCtxt *);
  DALResult (*Clock_DriverDeInit)(ClockDALDrvCtxt *);
};


/**
 * Clock client context.
 */
struct ClockDALClientCtxt
{
  /*
   * Base members - do not modify!
   */
  uint32                  dwRefs;
  uint32                  dwAccessMode;
  void                   *pPortCtxt;
  struct ClockDALDevCtxt *pClockDevCtxt;
  DalClockHandle          DalClockHandle;
  ClockCtxtInfoType       CtxtInfo;
};


/**
 * Clock voltage regular configuration type.
 */
typedef struct ClockVRegConfigType
{
  uint32            nClientCount[VCS_CORNER_NUM_OF_CORNERS];  /**< Number of active clients */
  VCSCornerType     eMinLevel;                            /**< Minimum vreg level */
  npa_client_handle              NPAHandle;                            /**< NPA client handle */
} ClockVRegConfigType;


/**
 * Clock voltage request type.
 */
typedef struct ClockVRegRequestType
{
  VCSCornerType eVRegLevel;
  boolean            bSuppressible;
} ClockVRegRequestType;


/**
 * Clock source type.
 */
typedef struct ClockSourceNodeType ClockSourceNodeType;
struct ClockSourceNodeType
{
  HAL_clk_SourceType             eSource;                      /**< Source enum value. */
  const char                    *szName;                       /**< Source name string */
  ClockSourceConfigType         *pBSPConfig;                   /**< Pointer to BSP data */
  npa_client_handle              NPAHandle;                    /**< NPA client handle */
  ClockSourceFreqConfigType     *pActiveFreqConfig;            /**< Pointer to active config */
  ClockSourceFreqConfigType     *pCalibrationFreqConfig;       /**< Pointer to calibration config */
  uint32                         nReferenceCount;              /**< Number of active non-CPU domains */
  uint32                         nReferenceCountSuppressible;  /**< Number of active suppressible domains */
  uint32                         nReferenceCountExternalTotal;              /**< Total external reference count for this clock */
  uint32                         nReferenceCountExternal[CLOCK_CTXT_TOTAL]; /**< Number of active external enable requests */
  ClockVRegRequestType           VRegRequest;                  /**< Voltage request */
  uint32                         nFlags;                       /**< Flags for the source */
  uint32                         nCalibration;                 /**< Source calibration data */
  ClockSourceNodeType           *pSource;                      /**< Pointer to source's source node */
};


/**
 * Clock domain type.
 */
typedef struct
{
  ClockMuxConfigType            *pBSPConfig;                   /**< Pointer to BSP data */
  HAL_clk_ClockDomainHandleType  HALHandle;                    /**< Handle to HAL data */
  ClockMuxConfigType            *pActiveMuxConfig;             /**< Pointer to active config */
  uint32                         nReferenceCount;              /**< Number of active clocks */
  uint32                         nReferenceCountSuppressible;  /**< Number of active suppressible domains */
  ClockVRegRequestType           VRegRequest;                  /**< Voltage request */
  uint32                         nFlags;                       /**< Flags for the domain */
  ClockSourceNodeType           *pSource;                      /**< Pointer to source node */
} ClockDomainNodeType;


/**
 * Clock type.
 */
typedef struct
{
  const char                    *szName;              /**< Clock name string */
  HAL_clk_ClockHandleType        HALHandle;           /**< Handle to HAL data */
  uint32                         nReferenceCountTotal;              /**< Total number of reference counts for this clock */
  uint32                         nReferenceCount[CLOCK_CTXT_TOTAL]; /**< Number of active client requests */
  uint32                         nFlags;              /**< Flags for the clock */
  ClockDomainNodeType           *pDomain;             /**< Pointer to domain node */
} ClockNodeType;


/**
 * Power domain type.
 */
typedef struct
{
  const char                    *szName;              /**< Power domain name string */
  HAL_clk_PowerDomainHandleType  HALHandle;           /**< Handle to HAL data */
  uint32                         nReferenceCountTotal;              /**< Total number of reference counts */
  uint32                         nReferenceCount[CLOCK_CTXT_TOTAL]; /**< Number of active client requests */
  boolean                        bEnabled;            /**< Enabled flag */
  uint32                         nFlags;              /**< Flags for the power domain */
} ClockPowerDomainNodeType;


/**
 * Clock driver context.
 */
typedef struct
{
  DALSYSSyncObj                  LockObj;             /**< Sync object storage */
  DALSYSSyncHandle               hLock;               /**< Handle to our mutex */

  ULogHandle                     hClockLog;           /**< Handle to our ULOG log */
  uint32                         nGlobalFlags;        /**< Global flags for the driver */

  ULogHandle                     hClockBISTLog;       /**< Handle to our BIST ULOG log */
  boolean                        bBISTEnabled;        /**< Flag used to enable the BIST */
  uint32                         nBISTLogSize;        /**< Size of the BIST ULOG log */

  boolean                        bDCVSEnabled;        /**< DCVS state */
  void                          *pImageCtxt;          /**< Image context */

  uint8                          anSourceIndex[HAL_CLK_NUM_OF_SOURCES]; /**< Array of source indices */
  uint32                         nNumSources;         /**< Number of supported sources */
  ClockSourceNodeType           *aSources;            /**< Array of supported sources */
  uint32                         nNumClockDomains;    /**< Number of supported clock domains */
  ClockDomainNodeType           *aClockDomains;       /**< Array of supported clock domains */
  uint32                         nNumClocks;          /**< Number of supported clocks */
  ClockNodeType                 *aClocks;             /**< Array of supported clocks */
  uint32                         nNumPowerDomains;    /**< Number of supported power domains */
  ClockPowerDomainNodeType      *aPowerDomains;       /**< Array of supported power domains */
  ClockVRegConfigType            VRegConfig;          /**< Voltage configuration */
  ClockVRegConfigType            VRegConfigSuppressible; /**< Suppressible voltage configuration */
  boolean                        bSuspendVoltageRequest; /**< Voltage suspension state */

  uint32                         nInitVotesRemaining; /**< Number initial votes remaining */
} ClockDrvCtxt;


/**
 * Clock callback context type.
 */
typedef struct ClockCallbackCtxtType
{
  void          (*pCallback)(void *);  /**< callback function for the resource */
  void          *pCallbackContext;     /**< context passed to the callback */
  ClockDrvCtxt  *pDriverContext;       /**< clock driver context used for locking */
} ClockCallbackCtxtType;


/**
 * Clock device context.
 */
struct ClockDALDevCtxt
{
  /*
   * Base Members - do not modify!
   */
  uint32           dwRefs;
  DALDEVICEID      DevId;
  uint32           dwDevCtxtRefIdx;
  ClockDALDrvCtxt *pClockDrvCtxt;
  DALSYS_PROPERTY_HANDLE_DECLARE(hProp);
  uint32           Reserved[16];
};


/**
 * Clock driver context.
 */
struct ClockDALDrvCtxt
{
  /*
   * Base members - do not modify!
   */
  ClockDALVtbl              ClockDALVtbl;
  uint32                    dwNumDev;
  uint32                    dwSizeDevCtxt;
  uint32                    bInit;
  uint32                    dwRefs;
  ClockDALDevCtxt           ClockDevCtxt[1];

  /*
   * Private driver context.
   */
  DalDeviceHandle          *phHWIO;
  ClockDrvCtxt              DrvCtxt;
};


/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : Clock_DriverInit
** =========================================================================*/
/**
  Initialize the clock driver.

  This function initializes the clock driver, it is the main init entry
  point.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_DriverInit
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : ClockStub_DriverInit
** =========================================================================*/
/**
  Initialize the clock driver stub.

  This function initializes the clock driver, it is the main init entry
  point.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult ClockStub_DriverInit
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_DriverDeInit
** =========================================================================*/
/**
  De-initialize the clock driver.

  This function shuts-down the clock driver.  It is not expected to ever
  be called.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_DriverDeInit
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : ClockStub_DriverDeInit
** =========================================================================*/
/**
  De-initialize the clock driver stub.

  This function shuts-down the clock driver.  It is not expected to ever
  be called.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult ClockStub_DriverDeInit
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_InitCore
** =========================================================================*/
/**
  Initialize the core portion of the clock driver.

  This function initializes the common portion of the clock driver that is
  shared with all images.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_InitCore
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_InitImage
** =========================================================================*/
/**
  Initialize the image specific portion of the clock driver.

  This function initializes the portion of the clock driver that is specific
  to the image we are running on.  This generally corresponds to a particular
  processor on a particular chipset, but also includes the various boot
  images.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_InitImage
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : ClockStub_InitImage
** =========================================================================*/
/**
  Initialize the image specific portion of the clock driver stub.

  This function initializes the portion of the clock driver that is specific
  to the image we are running on.  This generally corresponds to a particular
  processor on a particular chipset, but also includes the various boot
  images.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult ClockStub_InitImage
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_InitDCVS
** =========================================================================*/
/**
  Initialize the NPA DCVS nodes for this image in the clock driver.

  This function initializes the DCVS module for the current image.  This
  will define and create the required NPA nodes.  Nodes will be be
  active until DalClock_EnableDCVS has been called.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Init was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_InitDCVS
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_TestClock
** =========================================================================*/
/**
  Perform a non-destructive built-in self test on the specified clock node
  in the driver.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param ClockId [in] -- Clock ID of the clock to be tested.

  @return
  DAL_SUCCESS -- BIST was successful.
  DAL_ERROR -- BIST failed.

  @dependencies
  Core and image initialization must be complete prior to running the test.
*/

DALResult Clock_TestClock
(
  ClockDrvCtxt *pDrvCtxt,
  ClockIdType   ClockId
);


/* =========================================================================
**  Function : Clock_BIST
** =========================================================================*/
/**
  Perform a non-destructive built-in self test on all clock nodes in the
  driver.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- BIST was successful.
  DAL_ERROR -- BIST failed.

  @dependencies
  Core and image initialization must be complete prior to running the BIST.
*/

DALResult Clock_BIST
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_ImageBIST
** =========================================================================*/
/**
  Perform a non-destructive built-in self test on the image specific portion
  of the clock driver.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param *bBISTPassed [in/out] -- Pointer to the main BIST passed boolean.
  @param *nFailedTests [in/out] -- Pointer to the main BIST value which stores
                                   number of failed tests.

  @return
  DAL_SUCCESS -- Image BIST was successful.
  DAL_ERROR -- Image BIST failed.

  @dependencies
  Core and image initialization must be complete prior to running the Image BIST.
*/

DALResult __weak Clock_ImageBIST
(
  ClockDrvCtxt  *pDrvCtxt,
  boolean       *bBISTPassed,
  uint32        *nFailedTests
);


/* =========================================================================
**  Function : Clock_SetClockConfig
** =========================================================================*/
/**
  Sets a clock configuration.

  This function configures a clock domain to a particular configuration.
  It is used internally only.

  @param *pDrvCtxt [in] -- Driver context.
  @param *pClockDomain [in] -- Clock domain to configure.
  @param *pNewConfig [in] -- New configuration to use.

  @return
  DAL_SUCCESS -- The domain was successfully configured.
  DAL_ERROR -- The domain configuration failed.

  @dependencies
  The clock mutex must be locked.
*/

DALResult Clock_SetClockConfig
(
  ClockDrvCtxt        *pDrvCtxt,
  ClockDomainNodeType *pDomain,
  ClockMuxConfigType  *pNewConfig
);


/* =========================================================================
**  Function : Clock_InitSources
** =========================================================================*/
/**
  Initialize clock sources.

  This function allocates memory for the clock source nodes and initializes
  them based on the BSP/XML data.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Initialization was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_InitSources
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_EnableSourceInternal
** =========================================================================*/
/**
  Requests to enable a source.

  This function enables a source, generally as a result of a call to
  Clock_EnableClockDomain().  CPU based source requests are tracked
  independently of non-CPU based as the former will be automatically
  released when the CPU goes to sleep.
  A reference count is maintained so callers must ensure that all Enables
  and Disables are matched.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param *pSource [in] -- Pointer to a source node.
  @param bSuppressibleRequest [in] -- TRUE if this is a source request is for a suppressible clock.

  @return
  DAL_SUCCESS -- The source was successfully enabled.
  DAL_ERROR -- The source was not enabled.

  @dependencies
  The clock mutex must be locked prior to calling this function.
*/

DALResult Clock_EnableSourceInternal
(
  ClockDrvCtxt        *pDrvCtxt,
  ClockSourceNodeType *pSource,
  boolean              bSuppressibleRequest
);


/* =========================================================================
**  Function : Clock_DisableSourceInternal
** =========================================================================*/
/**
  Disables a source.

  This function disables a source, generally as a result of a call to
  Clock_DisableClockDomain().
  A reference count is maintained so callers must ensure that all Enables
  and Disables are matched.

  @param *pDrvCtxt [in]             -- Handle to the DAL driver context.
  @param *pSource [in]              -- Pointer to a source node.
  @param  bSuppressibleRequest [in] -- TRUE if this is a source request is for a suppressible clock.
  @param  bDoNotDisable [in]        -- TRUE if this is a source request that should not disable the source.

  @return
  DAL_SUCCESS -- The source was successfully disabled.
  DAL_ERROR -- The source was not disabled.

  @dependencies
  The clock mutex must be locked prior to calling this function.
*/

DALResult Clock_DisableSourceInternal
(
  ClockDrvCtxt        *pDrvCtxt,
  ClockSourceNodeType *pSource,
  boolean              bSuppressibleRequest,
  boolean              bDoNotDisable
);


/* =========================================================================
**  Function : Clock_FindSourceConfig
** =========================================================================*/
/**
  Finds a particular source configuration in the BSP.

  This function finds a particular source configuration in the BSP based on
  the specified frequency and match criteria.

  @param *pBSPConfig [in] -- Pointer to a list of configurations
  @param nFreqHz [in] -- Frequency in Hz
  @param eMatch [in] -- Match criteria
  @param **pMatchingConfig [out] -- Matching configuration

  @return
  DAL_SUCCESS -- A matching configuration was found.
  DAL_ERROR -- A matching configuration was not found.

  @dependencies
  None.
*/
DALResult Clock_FindSourceConfig
(
  ClockSourceFreqConfigType   *pBSPConfig,
  uint32                       nFreqHz,
  ClockFrequencyType           eMatch,
  ClockSourceFreqConfigType  **pMatchingConfig
);


/* =========================================================================
**  Function : Clock_ConfigSource
** =========================================================================*/
/**
  Configures a source.

  This function configures a source, generally a PLL.  This can only be
  done if there are no users of the source and we own the PLL.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param *pSource [in] -- Pointer to a source node.
  @param *pConfig [in] -- New configuration.

  @return
  DAL_SUCCESS -- The source was successfully configures.
  DAL_ERROR -- The source was not configured, either due to invalid
               parameter or (more likely) the source was in use.

  @dependencies
  The clock mutex must be locked prior to calling this function.
*/

DALResult Clock_ConfigSource
(
  ClockDrvCtxt               *pDrvCtxt,
  ClockSourceNodeType        *pSource,
  ClockSourceFreqConfigType  *pConfig
);


/* =========================================================================
**  Function : Clock_InitSource
** =========================================================================*/
/**
  Configures a source.

  This function initializes a source, generally a PLL, from the current BSP
  data.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param  eSource  [in] -- Which source to initialize.
  @param  nFreqHz  [in] -- Optional frequency to init this source to.
                           The first source frequency config is used if
                           this argument is 0.

  @return
  DAL_SUCCESS -- The source was successfully initialized.
  DAL_ERROR -- The source was not initialized, generally because the source
               has no valid BSP data.

  @dependencies
  The clock mutex should be locked prior to calling this function or
  we should be a single execution thread environment (like boot).
*/

DALResult Clock_InitSource
(
  ClockDrvCtxt       *pDrvCtxt,
  HAL_clk_SourceType  eSource,
  uint32              nFreqHz
);


/* =========================================================================
**  Function : Clock_GetPropertyValue
** =========================================================================*/
/**
  Retrieve a clock driver property from the environment store.

  This function retrieves the given clock property from the relevant
  storage location (may be DAL properties DB or another source).

  @param *szName [in] -- Name of the property to look up
  @param *pValue [out] -- Location to store the result

  @return
  DAL_SUCCESS if property was found and retrieved, DAL_ERROR otherwise.

  @dependencies
  None.
*/

DALResult Clock_GetPropertyValue
(
  const char              *szName,
  ClockPropertyValueType  *pValue
);


/* =========================================================================
**  Function : Clock_MapHWIORegion
** =========================================================================*/
/**
  Map a HWIO region into memory for the clock driver.

  This function maps a physical HWIO region into memory for the clock driver
  using environment appropriate APIs.  If the mapping is not available
  the virtual address will be set to the provided physical address.

  @param nPhysAddr [in] -- Physical address.
  @param nSizeBytes [in] -- Size of the region in bytes.
  @param *pnVirtAddr [out] -- Location to store the mapped address.

  @return
  DAL_SUCCESS if mapping was ok, otherwise error code based on failure.

  @dependencies
  None.
*/

DALResult Clock_MapHWIORegion
(
  uint32  nPhysAddr,
  uint32  nSizeBytes,
  uint32 *pnVirtAddr
);


/* =========================================================================
**  Function : Clock_InitVoltage
** =========================================================================*/
/**
  Initialize voltage tracking subsystem.

  This function prepares the voltage tracking module for managing voltage
  requests.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Initialization was successful.
  DAL_ERROR -- Initialization failed.

  @dependencies
  None.
*/

DALResult Clock_InitVoltage
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_VoltageRequest
** =========================================================================*/
/**
  Make a voltage regulator request.

  This function is used internally for a clock domain to make a voltage
  regulator level request.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param *pCurrentRequest [in/out] -- Pointer to currently requested voltage config.
                                      Updated to pNewRequest.
  @param *pNewRequest [in] -- New voltage requirement.

  @return
  DAL_SUCCESS -- Request was successful.
  DAL_ERROR -- Request failed.

  @dependencies
  The clock mutex must be locked.
*/

DALResult Clock_VoltageRequest
(
  ClockDrvCtxt          *pDrvCtxt,
  ClockVRegRequestType  *pCurrentRequest,
  ClockVRegRequestType  *pNewRequest
);


/* =========================================================================
**  Function : Clock_VoltageSuspend
** =========================================================================*/
/**
  Make a request to suspend voltage requests.

  This function is used internally to suspend voltage requests.

  @param *pDrvCtxt [in]       -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- Request was successful.
  DAL_ERROR   -- Request failed.

  @dependencies
  The clock mutex must be locked.
*/

DALResult Clock_VoltageSuspend
(
  ClockDrvCtxt        *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_VoltageResume
** =========================================================================*/
/**
  Make a request to resume voltage requests.

  This function is used internally to resume voltage requests.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param bUpdate [in] -- Flag to update voltage request immediately upon resume.

  @return
  DAL_SUCCESS -- Request was successful.
  DAL_ERROR   -- Request failed.

  @dependencies
  The clock mutex must be locked.
*/

DALResult Clock_VoltageResume
(
  ClockDrvCtxt  *pDrvCtxt,
  boolean        bUpdate
);


/*=========================================================================
**  Function : Clock_InitFlags
** =========================================================================*/
/**
  Initialize the flag attributes of clock(s)/domain(s).

  This function initializes the flag attributes of particular clock(s)
  and domain(s) as specified in the BSP data.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param eType     [in] -- Node type to process.

  @return
  DAL_SUCCESS -- Flag init was successful.
  DAL_ERROR -- Flag init failed.

  @dependencies
  None.
*/

DALResult Clock_InitFlags
(
  ClockDrvCtxt      *pDrvCtxt,
  ClockFlagNodeType  eType
);


/*=========================================================================
**  Function : Clock_RegisterResourceCallback
** =========================================================================*/
/**
  Wrapper function to register a resource callback and increment the number
  of remaining initial votes in the driver context. This is used in
  conjunction with Clock_CommonNPACallback which decrements the remaining
  votes after the actual resource callback executes.

  An example use case is we register CX, MX, and PLL_SR2 callbacks with this
  API, thereby incrementing the number of remaining initial votes three times.
  When each resource becomes available, Clock_CommonNPACallback is invoked
  which in turn invokes the actual resource callback based on the context
  information passed in, and decrements the number of remaining votes. When
  the number of remaining votes reaches zero, we know all the resource
  callbacks registered via this API have been invoked. At that point we
  signal the resource master we have completed our initial votes.

  @param  *pDrvCtxt         [in] -- Handle to the DAL driver context.
  @param  *szResourceName   [in] -- Name of resource for which the callback
                                    is to be invoked.
  @param  (*pCallback)      [in] --  Pointer to the callback function.
  @param  *pCallbackContext [in] -- Context to be passed into the callback

  @return
  DAL_SUCCESS -- Successfully registered the NPA callback.
  DAL_ERROR -- Error allocating memory for the NPA callback context.

  @dependencies
  None.
*/

DALResult Clock_RegisterResourceCallback
(
  ClockDrvCtxt *pDrvCtxt,
  const char   *szResourceName,
  void         (*pCallback)(void *),
  void         *pCallbackContext
);


/*=========================================================================
**  Function : Clock_IsBSPSupported
** =========================================================================*/
/**

  This function validates the specified BSP config is supported on the
  executing target chip and version.

  @param pHWVersion [in] - HW Version

  @return
  TRUE - HW version is supported.
  FALSE - HW version is not supported.

  @dependencies
  None.
*/

boolean Clock_IsBSPSupported
(
  ClockHWVersionType *pHWVersion
);


/*=========================================================================
**  Function : Clock_GetDrvCtxt
** =========================================================================*/
/**
  Returns driver context.

  This function is used to get the driver context when called from the lite
  API call path.  The mutex shared with the lite API is taken.


  @return
  Pointer to clock driver context.

  @dependencies
  None.
*/

ClockDrvCtxt *Clock_GetDrvCtxt
(
  void
);


/*=========================================================================
**  Function : Clock_ReleaseDrvCtxt
** =========================================================================*/
/**
  This function is used to release the driver context when called from the lite
  API call path.  The mutex shared with the lite API is released.

  @return
  None.

  @dependencies
  None.
*/

void Clock_ReleaseDrvCtxt
(
  void
);


/*=========================================================================
**  Function : Clock_TransferReferenceCount
** =========================================================================*/
/**
  This function is used to transfer the reference count of lite API enable
  requests to the DAL driver.

  @return
  DAL_SUCCESS -- Successfully transferred reference count.
  DAL_ERROR_INTERNAL -- Failed to successfully enable clocks via DAL API.

  @dependencies
  None.
*/

DALResult Clock_TransferReferenceCount
(
  void
);


/*=========================================================================
**  Function : Clock_FindClockConfig
** =========================================================================*/
/**

  Exposed Clock_FindClockConfig for chipset/subystem-specific invocation.
  See ClockDriver.c.

  @dependencies
  None.
*/

DALResult Clock_FindClockConfig
(
  ClockMuxConfigType  *pBSPConfig,
  uint32               nFreqHz,
  ClockFrequencyType   eMatch,
  ClockMuxConfigType **pMatchingConfig
);


/*=========================================================================
**  Function : Clock_GetDrvCtxtNoLock
** =========================================================================*/
/**

  API to retrieve the static driver context without causing a mutex lock
  in the process.

  @dependencies
  None.
*/

ClockDrvCtxt *Clock_GetDrvCtxtNoLock
(
  void
);


/*=========================================================================
**  Function : Clock_GetInitialClientCtxt
** =========================================================================*/
/**

  Internal clock API to retrieve the first (root) client context for use
  in APIs that need a client context but have only a driver context.

  @dependencies
  None.
*/

ClockDALClientCtxt *Clock_GetInitialClientCtxt
(
  void
);


/*=========================================================================
      Function Definitions From DDIClock.h
==========================================================================*/

DALResult Clock_GetClockId(ClockDrvCtxt *pDrvCtxt, const char *szClock,  ClockIdType *pnId);
DALResult Clock_EnableClock(ClockDALClientCtxt *pClientCtxt, ClockIdType nClock);
DALResult Clock_DisableClock(ClockDALClientCtxt *pClientCtxt, ClockIdType nClock);
DALResult Clock_SetClockFrequency(ClockDrvCtxt *pDrvCtxt,  ClockIdType nClock, uint32 nFreq, ClockFrequencyType eMatch, uint32 *pnResultFreq);
DALResult Clock_SetClockDivider(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, uint32 nDivider);
DALResult Clock_InvertClock(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, boolean  bInvert);
DALResult Clock_ResetClock(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, ClockResetType eReset);
DALResult Clock_ResetClock_STM( ClockDrvCtxt *pDrvCtxt,  ClockIdType  nClock,  ClockResetType  eReset);
DALResult Clock_ConfigClock(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, ClockConfigType eConfig);
DALResult Clock_IsClockEnabled(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, boolean *pbIsOn);
DALResult Clock_IsClockOn(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, boolean *pbIsOn);
DALResult Clock_GetClockFrequency(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, uint32 *pnFrequencyHz);
DALResult Clock_SelectExternalSource(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, uint32 nFreqHz, uint32 nSource, uint32 nDiv2x, uint32 nM, uint32 nN, uint32 n2D);
DALResult Clock_CalcClockFrequency(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, uint32 *pnFrequencyHz);
DALResult Clock_SetUARTBaudClock(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, ClockIdType nRefClock, uint32 nDI, uint32 nFI, uint32 *pnResultFreq);
DALResult Clock_LogState(ClockDrvCtxt *pDrvCtxt, ULogHandle hULog, uint32 nFlags);

DALResult Clock_GetSourceId(ClockDrvCtxt *pDrvCtxt, const char *szSource, SourceIdType *pnId);
DALResult Clock_EnableSource(ClockDALClientCtxt *pClientCtxt, SourceIdType nSource);
DALResult Clock_DisableSource(ClockDALClientCtxt *pClientCtxt, SourceIdType nSource);
DALResult Clock_SetSourceFrequency(ClockDrvCtxt *pDrvCtxt, SourceIdType nSource, uint32 nFreq, ClockFrequencyType eMatch, uint32 *pnResultFreq);
DALResult Clock_GetSourceFrequency(ClockDrvCtxt *pDrvCtxt, SourceIdType nSource, uint32 *pnFrequencyHz);

DALResult Clock_GetPowerDomainId(ClockDrvCtxt *pDrvCtxt, const char *szPowerDomain, ClockPowerDomainIdType *pnPowerDomainId);
DALResult Clock_EnablePowerDomain(ClockDALClientCtxt *pClientCtxt, ClockPowerDomainIdType nPowerDomainId);
DALResult Clock_DisablePowerDomain(ClockDALClientCtxt *pClientCtxt, ClockPowerDomainIdType nPowerDomainId);

DALResult Clock_EnableDCVS(ClockDrvCtxt *pDrvCtxt);
DALResult Clock_LoadNV(ClockDrvCtxt *pDrvCtxt);
DALResult Clock_SetCPUMaxFrequencyAtCurrentVoltage( ClockDrvCtxt *pDrvCtxt, boolean bRequired, uint32 *pnResultFreqHz);
DALResult Clock_ProcessorSleep(ClockDrvCtxt *pDrvCtxt, ClockSleepModeType eMode, uint32 nFlags);
DALResult Clock_ProcessorRestore(ClockDrvCtxt *pDrvCtxt, ClockSleepModeType eMode, uint32 nFlags);
DALResult Clock_AdjustSourceFrequency(ClockDrvCtxt *pDrvCtxt, ClockSourceType eSource, int32 nDeltaLAlpha);
DALResult Clock_SelectClockSource(ClockDrvCtxt *pDrvCtxt, ClockIdType nClock, ClockSourceType eSource);

#endif /* !__CLOCK_DRIVER_H__ */

