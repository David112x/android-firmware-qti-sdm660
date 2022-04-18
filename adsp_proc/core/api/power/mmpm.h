#ifndef MMPM_H
#define MMPM_H


/*============================================================================*/
/**
 @file mmpm.h

 @brief This file contains data types, constants that make up the
        Multi Media Power Management (MMPM) public API.

 DESCRIPTION:
     Public Function Declarations 
     This is the MMPM client API. 

 EXTERNALIZED FUNCTIONS:
     See below.
*/
/*===========================================================================
NOTE: The @brief description above does not appear in the PDF.
      The description that displays in the PDF is located in the
      ADSPPM_mainpage.dox file. Contact Tech Pubs for assistance.

NOTE: The apps_only condition is for QC internal and means:
      "The APPS side MMPM API is not published. It�s internal API for
      QC MM/CoreBSP drivers on APPS, i.e., no external drivers will call
      into it." (per Charles Kong)
===========================================================================*/
/*==============================================================================
  Copyright (c) 2009-2011, 2013-2014 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  Export of this technology or software is regulated
  by the U.S. Government, Diversion contrary to U.S. law prohibited.
==============================================================================*/

/*==============================================================================
                             Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/api/power/mmpm.h#1 $

                           EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

when         who     what, where, why
--------     ---     ---------------------------------------------------------
06/15/09    Shiju    Initial version
06/30/09    PK       Updating format to conform to QCT Coding Standard.
08/05/09    Shiju    Updated with review feedbacks and fixed compilation issues
08/19/09    CK       Added data structures for MMSS common components.
                     Updated comments for the camera components' parameters.
09/29/09    AC       Updated video parameters.
10/16/09    PK       Updated comment format for Doxygen.
10/28/09    CK       Removed API's that are not directly exposed to clients.
11/12/09    CY       Revised Audio MMPM APIs.
05/12/10    CY       Design changes to Audio MMPM API.
05/17/10    AC       Modified bandwidth request data structure.
07/15/10    CK       Added ddr clock to use case parameter structure of MipiCsi
08/20/10    Shiju    Added support for DSI clks
02/10/11    CK       Added parameter to define ISPIF interface
06/19/11    CK       Created MMPM 2.0 structures, backward compatible with 1.0
08/16/11    CK       Added comments on each clock enum ID with the expected behavior on them.
                     Merged 1.0 header file updates (till rev68) into the 2.0 header file's 1.0 part
12/12/11    YR       Extended interface for LPASS
04/12/13    llg     (Tech Pubs) Edited/added Doxygen comments/markup for 2.0.
05/08/14    sw     ( Tech Pubs) Edited/added Doxygen comments/markup for 2.4.
==============================================================================*/

/*============================================================================*/
/*
*                           INCLUDE FILES FOR MODULE
*/
/*============================================================================*/

/*======================================================================
  Enumerations
  ======================================================================*/

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/*======================================================================*/
/*
  Types/Typedefs
*/
/*======================================================================*/

#ifndef NULL
#define NULL  ((void*) 0)
#endif

#ifndef _BOOLEAN_DEFINED
typedef unsigned char       boolean;
#define _BOOLEAN_DEFINED
#endif

#ifndef _UINT32_DEFINED
typedef unsigned long int   uint32;
#define _UINT32_DEFINED
#endif

#ifndef _INT32_DEFINED
typedef signed long int     int32;
#define _INT32_DEFINED
#endif

#ifndef _UINT64_DEFINED
typedef unsigned long long  uint64;
#define _UINT64_DEFINED
#endif

#ifndef _INT64_DEFINED
typedef signed long long    int64;
#define _INT64_DEFINED
#endif

#ifndef _BYTE_DEFINED
typedef unsigned char       byte;
#define _BYTE_DEFINED
#endif

#ifndef _INT8_DEFINED
typedef signed char         int8;
#define _INT8_DEFINED
#endif

#ifndef _BOOL32_DEFINED
typedef unsigned long int   bool32;
#define _BOOL32_DEFINED
#endif

#ifndef _UINT8_DEFINED
typedef unsigned char       uint8;
#define _UINT8_DEFINED
#endif


/** @addtogroup mmpm_datatypes
@{ */
/**
  Valid MMPM status types used for the MMPM return status.
*/
typedef enum {
    MMPM_STATUS_SUCCESS,                  /**< Success. */
    MMPM_STATUS_FAILED,                   /**< General failure. */
    MMPM_STATUS_NOMEMORY,                 /**< Insufficient memory. */
    MMPM_STATUS_VERSIONNOTSUPPORT,        /**< Version is not supported. */
    MMPM_STATUS_BADCLASS,                 /**< NULL class object. */
    MMPM_STATUS_BADSTATE,                 /**< Invalid state. */
    MMPM_STATUS_BADPARM,                  /**< Invalid parameter. */
    MMPM_STATUS_INVALIDFORMAT,            /**< Invalid format. */
    MMPM_STATUS_UNSUPPORTED,              /**< API is not supported. */
    MMPM_STATUS_RESOURCENOTFOUND,         /**< Resource is not found. */
    MMPM_STATUS_BADMEMPTR,                /**< Bad memory pointer. */
    MMPM_STATUS_BADHANDLE,                /**< Invalid handle. */
    MMPM_STATUS_RESOURCEINUSE,            /**< Resource is in use. */
    MMPM_STATUS_NOBANDWIDTH,              /**< Insufficient bandwidth. */
    MMPM_STATUS_NULLPOINTER,              /**< NULL pointer. */
    MMPM_STATUS_NOTINITIALIZED,           /**< Not initialized. */
    MMPM_STATUS_RESOURCENOTREQUESTED,     /**< Resource was not requested. */
    MMPM_STATUS_CORERESOURCENOTAVAILABLE, /**< Core resource is not 
                                               available. */
    MMPM_STATUS_MAX,                      /**< Maximum count. */
    MMPM_STATUS_FORCE32BITS = 0x7FFFFFFF  /**< Forces the enumeration to 
                                               32 bits. */
} MmpmStatusType;


typedef MmpmStatusType                  MMPM_STATUS;  /**< MMPM status type. */
/** @} */ /* end_addtogroup mmpm_datatypes  */


/******************************************************************************************/
/*                                                                                        */
/*                          MMPM_Register_Ext() Data Structures                           */
/*                                                                                        */
/******************************************************************************************/

/** @ingroup mmpm_constants_macros
  MMPM revision used to check for compatibility issues.
*/
#define MMPM_REVISION                   0x00000002

/** @addtogroup mmpm_datatypes
@{ */
/**
  Valid MMPM owner ID types.

  Each MMPM core has a unique core ID. All requests to MMPM are routed to 
  the right core based its ID. The maximum number of core IDs is 1024.
*/
typedef enum {
    MMPM_CORE_ID_NONE           = 0,     /**< No ID type. */
/** @cond apps_only */
    MMPM_CORE_ID_2D_GRP         = 1,     /**< 2D graphics. */
    MMPM_CORE_ID_3D_GRP         = 2,     /**< 3D graphics. */
    MMPM_CORE_ID_MDP            = 3,     /**< MDP. */
    MMPM_CORE_ID_VCODEC         = 4,     /**< Video codec. */
    MMPM_CORE_ID_VPE            = 5,     /**< VPE. */
    MMPM_CORE_ID_VFE            = 6,     /**< VFE. */
    MMPM_CORE_ID_MIPICSI        = 7,     /**< Mobile Industry Processor Interface 
                                              (MIPI) CSI. */
    MMPM_CORE_ID_SENSOR         = 8,     /**< Camera sensor. */
    MMPM_CORE_ID_JPEGD          = 9,     /**< JPEG decoder. */
    MMPM_CORE_ID_JPEGE          = 10,    /**< JPEG encoder. */
    MMPM_CORE_ID_FABRIC         = 11,    /**< MMSS FABRIC. */
    MMPM_CORE_ID_IMEM           = 12,    /**< MMSS IMEM. */
    MMPM_CORE_ID_SMMU           = 13,    /**< MMSS system memory management units. */
    MMPM_CORE_ID_ROTATOR        = 14,    /**< Rotator. */
    MMPM_CORE_ID_TV             = 15,    /**< TV. */
    MMPM_CORE_ID_DSI            = 16,    /**< DSI. */
    MMPM_CORE_ID_AUDIOIF        = 17,    /**< Audio interface. */
    MMPM_CORE_ID_GMEM           = 18,    /**< MMSS GMEM. */
/** @endcond */
    // LPASS core ID START
	MMPM_CORE_ID_SS_CORE_START  = 100,
    MMPM_CORE_ID_LPASS_START    = MMPM_CORE_ID_SS_CORE_START,   /**< LPASS core ID start. */
	MMPM_CORE_ID_Q6_DSP         = 101,
    MMPM_CORE_ID_LPASS_ADSP     = MMPM_CORE_ID_Q6_DSP,   /**< aDSP hardware in the LPASS. */
    MMPM_CORE_ID_LPASS_CORE     = 102,   /**< Generic ID for entire LPASS core. */
    MMPM_CORE_ID_LPASS_LPM      = 103,   /**< Low power memory in the LPASS. */
    MMPM_CORE_ID_LPASS_DML      = 104,   /**< Data Mover Lite hardware in the
                                              LPASS. */
    MMPM_CORE_ID_LPASS_AIF      = 105,   /**< Audio interface hardware in the 
                                              LPASS. */
    MMPM_CORE_ID_LPASS_SLIMBUS  = 106,   /**< SLIMbus@regns hardware in the 
                                              LPASS. */
    MMPM_CORE_ID_LPASS_MIDI     = 107,   /**< MIDI hardware in the LPASS. */
    MMPM_CORE_ID_LPASS_AVSYNC   = 108,   /**< Audio-video timer/ProntoSync
                                              hardware in the LPASS. */
    MMPM_CORE_ID_LPASS_HWRSMP   = 109,   /**< Hardware Resampler hardware in 
                                              the LPASS. */
    MMPM_CORE_ID_LPASS_SRAM     = 110,   /**< Sensors RAM used by the LPASS. */
    MMPM_CORE_ID_LPASS_DCODEC   = 111,   /**< Digital codec in the LPASS. */
    MMPM_CORE_ID_LPASS_SPDIF    = 112,   /**< SPDIF in the LPASS. */
    MMPM_CORE_ID_LPASS_HDMIRX   = 113,   /**< HDMI Rx hardware in the LPASS. */
    MMPM_CORE_ID_LPASS_HDMITX   = 114,   /**< HDMI Tx hardware in the LPASS. */
    MMPM_CORE_ID_LPASS_SIF      = 115,   /**< SIF (analog audio) in the LPASS. */
    MMPM_CORE_ID_LPASS_BSTC     = 116,   /**< Broadcast System Time Clock (STC)
                                              in the LPASS. */
    MMPM_CORE_ID_LPASS_ADSP_HVX = 117,   /**< HVX (Hexagon Vector eXtensions)
                                              hardware in the LPASS. */
    MMPM_CORE_ID_LPASS_END,              /**< End of the LPASS core IDs. */
	MMPM_CORE_ID_SS_CORE_END = MMPM_CORE_ID_LPASS_END,
    //LPASS CORE ID END
    MMPM_CORE_ID_MAX,                    /**< Maximum count. */
    MMPM_CORE_ID_FORCE32BITS = 0x7FFFFFFF
                                         /**< Forces the enumeration to 32 bits. */
} MmpmCoreIdType;


/******** rscId = MMPM_RSC_ID_EVENT_CALLBACK ********/
/**
  Valid callback events.
*/
typedef enum {
    MMPM_CALLBACK_EVENT_ID_NONE,
    /**< No callback event. */
    MMPM_CALLBACK_EVENT_ID_IDLE,
    /**< Except for the Mobile Display Processor (MDP), the Multimedia Subsystem
         (MMSS) is idle. */
    MMPM_CALLBACK_EVENT_ID_BUSY,
    /**< Except for the MDP, the MMSS is busy. */
    MMPM_CALLBACK_EVENT_ID_THERMAL,
    /**< Thermal event. */
    MMPM_CALLBACK_EVENT_ID_COMPLETE,
    /**< Asynchronous request is completed. */
    MMPM_CALLBACK_EVENT_ID_MAX,
    /**< Maximum count. */
    MMPM_CALLBACK_EVENT_ID_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. @if apps_only @newpage @endif */
} MmpmCallbackEventIdType;


/**
  Parameter for an event callback.
*/
typedef struct {
    MmpmCallbackEventIdType     eventId;
    /**< Callback event ID.

         @values See #MmpmCallbackEventIdType */

    uint32                      clientId;
    /**< MMPM client ID. */

    uint32                      callbackDataSize;
    /**< Size of callbackData. */

    void*                       callbackData;
    /**< Pointer to the data structure (MmpmCompletionCallbackDataType) to be
         defined when asynchronous calls are supported. */
} MmpmCallbackParamType;


/**
  Asynchronous request callback return value.
*/
typedef struct {
    uint32 reqTag;      /**< Request tag. */
    MMPM_STATUS result; /**< Request completion result. @newpagetable */
}MmpmCompletionCallbackDataType;
/** @} */ /* end_addtogroup mmpm_datatypes */

/** @addtogroup mmpm_constants_macros
@{ */
/** @name Power control flags
@xreflabel{hdr:powerControlFlag}
@vertspace{-6} Bitmasks for the type of power control.
@{ */

/** Do not participate in any power control. */
#define PWR_CTRL_NONE               0x0000

/** Participate in static display power control. */
#define PWR_CTRL_STATIC_DISPLAY     0x0001

/** Participate in thermal power control. MMPM manages thermal for the client. */
#define PWR_CTRL_THERMAL            0x0002

/** Client is a periodic type requiring special handling for its requests.

  Periodic clients assume that their requests are only applied if 
  they run concurrently with other clients. Otherwise, a pre-defined baseline 
  state is applied to optimize the timeline.
*/
#define PWR_CTRL_PERIODIC_CLIENT    0x0100
/** @} */ /* end_name_group Power control flag */

/** @name Callback flags
@xreflabel{hdr:callbackFlag}
@vertspace{-6} Bitmasks for the type of callback.
@{ */

/** No callbacks */
#define CALLBACK_NONE               0x0000

/** Callback for static display. */
#define CALLBACK_STATIC_DISPLAY     0x0001

/** Callback for thermal. */
#define CALLBACK_THERMAL            0x0002

/** Callback for asynchronous request completion notification. */
#define CALLBACK_REQUEST_COMPLETE   0x0004

/** @} */ /* end_name_group Callback flag */
/** @} */ /* end_addtogroup mmpm_constants_macros */

/** @ingroup mmpm_datatypes
  Valid core instance IDs.
*/
typedef enum{
    MMPM_CORE_INSTANCE_NONE,  /**< No instance ID. */
    MMPM_CORE_INSTANCE_0,     /**< Core instance 0. */
    MMPM_CORE_INSTANCE_1,     /**< Core instance 1. */
    MMPM_CORE_INSTANCE_2,     /**< Core instance 2. */
    MMPM_CORE_INSTANCE_MAX,   /**< Maximum count. */
    MMPM_CORE_INSTANCE_FORCE32BITS = 0x7FFFFFFF
                             /**< Forces the enumeration to 32 bits.
                                  @if OEM_only @newpage @endif */
} MmpmCoreInstanceIdType;


/** @ingroup mmpm_constants_macros
  Maximum client name length.
*/
#define MAX_CLIENT_NAME                 32


/** @addtogroup mmpm_datatypes
@{ */
/**  Parameter for MMPM registration information.
*/
typedef struct {
    uint32                      rev;
    /**< Specifies the MMPM revision.

         @values #MMPM_REVISION */

    MmpmCoreIdType              coreId;
    /**< Specifies the ID of the hardware block for which the client is 
         registering. Typically, this is the hardware core the client wants to 
         control. */

    MmpmCoreInstanceIdType      instanceId;
    /**< Instance of the same hardware core, e.g., the first instance of the 
         two Graphics2D cores. */

    char                        *pClientName;
    /**< Client name.

         This must be unique for each combination of coreId and instanceId.
         The maximum size is 32 characters. */

    uint32                      pwrCtrlFlag;
    /**< Bitmask that indicates whether the client is participating in the 
         power control.

         @values See @xhyperref{hdr:powerControlFlag,Power control flags} */

    uint32                      callBackFlag;
    /**< Bitmask that indicates which callback the client wants to receive.

         @values See @xhyperref{hdr:powerControlFlag,Power control flags} */

    uint32                      (*MMPM_Callback)(MmpmCallbackParamType *pCbParam);
    /**< Callback function for an event notification. */

    uint32                      cbFcnStackSize;
    /**< Stack size of the callback function. */

} MmpmRegParamType;


/******************************************************************************************/
/*                                                                                        */
/*                    MMPM_Request() Data Structures                                  */
/*                                                                                        */
/******************************************************************************************/

/** Valid MMPM resource IDs.
*/
typedef enum {
    MMPM_RSC_ID_NONE            = 0,
    /**< No resource ID. */

    MMPM_RSC_ID_POWER           = 1,
    /**< GDFS for MMSS cores. */

/** @cond apps_only */
    MMPM_RSC_ID_VREG            = 2,
    /**< Power rails for panels and sensors. */
/** @endcond */

    MMPM_RSC_ID_REG_PROG        = 3,
    /**< Register programming clocks. */

    MMPM_RSC_ID_CORE_CLK        = 4,
    /**< Core clocks requested by passing in clock settings.

         Depending on the clock ID, there are three types of operations:\n
           @txtbullet Enable only \n
           @txtbullet Set the frequency and enable \n
           @txtbullet Set the clock source and enable */

    MMPM_RSC_ID_CORE_CLK_DOMAIN  = 5,
    /**< Core clocks requested by passing in clock domain settings. */

/** @cond apps_only */
    MMPM_RSC_ID_MEM_BW          = 6,
    /**< Bandwidth requested by passing in values. The AXI clock is enabled 
         with the bandwidth request. */
    MMPM_RSC_ID_AXI_EN          = 7,
    /**< Core is to enable AXI clock only. */
    MMPM_RSC_ID_MIPS            = 8,
    /**< MIPS requested by passing in values. */
/** @endcond */

    MMPM_RSC_ID_SLEEP_LATENCY   = 9,
    /**< Interrupt latency requested by passing in values. */

/** @cond apps_only */
    MMPM_RSC_ID_ACTIVE_STATE    = 10,
    /**< Core is to notify MMPM that it is in the Active state. */
    MMPM_RSC_ID_PMIC_GPIO       = 11,
    /**< PMIC GPIO resource ID. */
    MMPM_RSC_ID_RESET           = 12,
    /**< Reset of core through the clock registers. */
/** @endcond */

    MMPM_RSC_ID_MIPS_EXT        = 13,
    /**< Extended MIPS requested by passing in MIPS, request type, and 
         code location values. */

    MMPM_RSC_ID_GENERIC_BW      = 14,
    /**< Generic bandwidth defined by the endpoints. */

    MMPM_RSC_ID_THERMAL         = 15,
    /**< Thermal mitigation request. */

    MMPM_RSC_ID_MEM_POWER       = 16,
    /**< Request for the memory power state. */

    MMPM_RSC_ID_GENERIC_BW_EXT  = 17,
    /**< Generic bandwidth defined by the endpoints. Bandwidth voting through
         this resource ID is intended for audio and voice clients, and has an
         internal compensation factor automatically applied to the vote to
         ensure audio and voice usecases are provided the requested bandwidth.
         */

    MMPM_RSC_ID_MPPS            = 18,
    /**< Request for MPPS (million packets per second) requirement
        for audio/voice clients.  This will be converted internally
        to aDSP clock requirement
         */

    MMPM_RSC_ID_MAX             ,
    /**< Maximum count. */

    MMPM_RSC_ID_FORCE32BITS     = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. @if apps_only @newpage @endif */

} MmpmRscIdType;

/******** rscId = MMPM_RSC_ID_REG_PROG ********/
/**
  Valid register programming matches.
*/
typedef enum {
    MMPM_REG_PROG_NONE,  /**< No match. */
    MMPM_REG_PROG_NORM,  /**< Register programming at normal speed. */
    MMPM_REG_PROG_FAST,  /**< Register programming at fast speed. */
    MMPM_REG_PROG_MAX,   /**< Maximum count. */
    MMPM_REG_PROG_FORCE32BITS = 0x7FFFFFFF
                         /**< Forces the enumeration to 32 bits. */
} MmpmRegProgMatchType;


/******** rscId = MMPM_RSC_ID_CORE_CLK ********/
/**
  Valid clock IDs for 2D graphics.
*/
typedef enum {
    MMPM_CLK_ID_2D_GRP_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_2D_GRP,
    /**< 2D graphics clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_2D_GRP_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_2D_GRP_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkId2dGrpType;


/**
   Valid clock IDs for 3D graphics.
*/
typedef enum {
    MMPM_CLK_ID_3D_GRP_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_3D_GRP,
    /**< 3D graphics clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_3D_GRP_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_3D_GRP_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkId3dGrpType;


/**
  Valid clock IDs for the MDP.
*/
typedef enum {
    MMPM_CLK_ID_MDP_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_MDP,
    /**< MDP clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and enable. */
    MMPM_CLK_ID_MDP_VSYNC,
    /**< MDP Vertical synchronization clock; set by MMPM_RSC_ID_CORE_CLK:
         enable only. */
    MMPM_CLK_ID_MDP_LUT,
    /**< MDP look-up table clock; set by MMPM_RSC_ID_CORE_CLK: enable only. */
    MMPM_CLK_ID_MDP_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_MDP_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdMdpType;


/**
  Valid clock IDs for the video codec.
*/
typedef enum {
    MMPM_CLK_ID_VCODEC_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_VCODEC,
    /**< Video codec clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_VCODEC_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_VCODEC_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdVcodecType;


/**
  Valid clock IDs for the Video Preprocessing Engine (VPE).
*/
typedef enum {
    MMPM_CLK_ID_VPE_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_VPE,
    /**< VPE clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and enable. */
    MMPM_CLK_ID_VPE_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_VPE_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdVpeType;


/**
  Valid clock IDs for the Video Front End (VFE).
*/
typedef enum {
    MMPM_CLK_ID_VFE_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_VFE,
    /**< VFE clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and enable. */
    MMPM_CLK_ID_VFE_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_VFE_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdVfeType;


/**
  Valid clock IDs for the MIPI Camera Serial Interface (CSI).
*/
typedef enum {
    MMPM_CLK_ID_CSI_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_CSI,
    /**< CSI clock; instance ID as registered; 
         set by MMPM_RSC_ID_CORE_CLK: set frequency and enable. */
    MMPM_CLK_ID_CSI_VFE,
    /**< CSI VFE clock; instance ID as registered; 
         set by MMPM_RSC_ID_CORE_CLK: enable only. */
    MMPM_CLK_ID_CSI_PHY,
    /**< CSI PHY clock; instance ID as registered; 
         set by MMPM_RSC_ID_CORE_CLK: enable only. */
    MMPM_CLK_ID_CSI_PHY_TIMER,
    /**< CSI PHY timer clock; instance ID as registered; 
         set by MMPM_RSC_ID_CORE_CLK: set frequency and enable. */
    MMPM_CLK_ID_CSI_PIX0,
    /**< CSI pixel clock 0; sourced by CSI instance ID; 
         set by MMPM_RSC_ID_CORE_CLK: set source and enable.
         @if apps_only @newpage @endif */
    MMPM_CLK_ID_CSI_PIX1,
    /**< CSI pixel clock 1; sourced by CSI instance ID; 
         set by MMPM_RSC_ID_CORE_CLK: set source and enable. */
    MMPM_CLK_ID_CSI_RDI0,
    /**< CSI raw interface clock 0; sourced by CSI instance ID; 
         set by MMPM_RSC_ID_CORE_CLK: set source and enable. */
    MMPM_CLK_ID_CSI_RDI1,
    /**< CSI raw interface clock 1; sourced by CSI instance ID; 
         set by MMPM_RSC_ID_CORE_CLK: set source and enable. */
    MMPM_CLK_ID_CSI_RDI2,
    /**< CSI raw interface clock 2; sourced by CSI instance ID; 
         set by MMPM_RSC_ID_CORE_CLK: set source and enable. */
    MMPM_CLK_ID_CSI_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_CSI_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdCsiType;


/**
  Valid clock IDs for the sensor.
*/
typedef enum {
    MMPM_CLK_ID_SENSOR_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_SENSOR,
    /**< Sensor clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_SENSOR_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_SENSOR_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdSensorType;


/**
  Valid clock IDs for the JPEG decoder.
*/
typedef enum {
    MMPM_CLK_ID_JPEGD_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_JPEGD,
    /**< JPEG decoder clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_JPEGD_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_JPEGD_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdJpegdType;


/**
  Valid clock IDs for the JPEG encoder.
*/
typedef enum {
    MMPM_CLK_ID_JPEGE_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_JPEGE,
    /**< JPEG encoder clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_JPEGE_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_JPEGE_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. @if apps_only @newpage @endif */
} MmpmClkIdJpegeType;


/**
  Valid clock IDs for the rotator.
*/
typedef enum {
    MMPM_CLK_ID_ROTATOR_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_ROTATOR,
    /**< Rotator clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_ROTATOR_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_ROTATOR_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdRotatorType;


/**
  Valid clock IDs for TV.
*/
typedef enum {
    MMPM_CLK_ID_TV_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_TV_ENC,
    /**< ENC TV clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_TV_DAC,
    /**< Digital-to-analog converter TV clock; set by MMPM_RSC_ID_CORE_CLK:
         set frequency and enable. */
    MMPM_CLK_ID_TV_MDP,
    /**< MDP TV clock; set by either MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable, or by MMPM_RSC_ID_CORE_CLK_DOMAIN. */
    MMPM_CLK_ID_TV_HDMI_APP,
    /**< HDMI APP TV clock; set by MMPM_RSC_ID_CORE_CLK: enable only.
         @if OEM_only @newpage @endif */
    MMPM_CLK_ID_TV_HDMI,
    /**< HDMI TV clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: set frequency and 
         enable. */
    MMPM_CLK_ID_TV_RGB,
    /**< RGB TV clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: enable only. */
    MMPM_CLK_ID_TV_NPL,
    /**< NPL TV clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: enable only. */
    MMPM_CLK_ID_TV_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_TV_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdTvType;


/**
  Valid clock IDs for the Display Serial Interface (DSI).
*/
typedef enum {
    MMPM_CLK_ID_DSI_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_DSI,
    /**< DSI clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN. */
    MMPM_CLK_ID_DSI_ESC,
    /**< DSI escape clock; set by either MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable, or by MMPM_RSC_ID_CORE_CLK_DOMAIN. */
    MMPM_CLK_ID_DSI_PIX,
    /**< DSI pixel clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: set frequency 
         and enable. */
    MMPM_CLK_ID_DSI_BYTE,
    /**< DSI byte clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: set frequency 
         and enable. @if apps_only @newpage @endif */
    MMPM_CLK_ID_DSI_LVDS,
    /**< DSI LVDS clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: enable only. */
    MMPM_CLK_ID_DSI_MDP_P2,
    /**< DSI MDP P2 clock; set by MMPM_RSC_ID_CORE_CLK_DOMAIN: enable only. */
    MMPM_CLK_ID_DSI_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_DSI_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdDsiType;


/**
  Valid clock IDs for the audio interface.
*/
typedef enum {
    MMPM_CLK_ID_AUDIOIF_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_AUDIOIF_PCM,
    /**< Audio PCM clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and 
         enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_CODEC_SPKR_MCLK,
    /**< Audio I2S codec speaker master clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_CODEC_SPKR_SCLK,
    /**< Audio I2S codec speaker slave clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_SPARE_SPKR_MCLK,
    /**< Audio I2S spare speaker master clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_SPARE_SPKR_SCLK,
    /**< Audio I2S spare speaker slave clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_CODEC_MIC_MCLK,
    /**< Audio I2S codec mic master clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_CODEC_MIC_SCLK,
    /**< Audio I2S codec mic slave clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_SPARE_MIC_MCLK,
    /**< Audio I2S spare mic master clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_I2S_SPARE_MIC_SCLK,
    /**< Audio I2S spare mic slave clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_MI2S_CODEC_MCLK,
    /**< Audio MI2S codec master clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_MI2S_CODEC_SCLK,
    /**< Audio MI2S codec slave clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_MI2S_CODEC_TX_MCLK,
    /**< Audio MI2S codec Tx master clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_MI2S_CODEC_TX_SCLK,
    /**< Audio MI2S codec Tx slave clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_LPASS_SB_REF_CLK,
    /**< Audio LPASS SLIMbus reference clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_SPS_SB_REF_CLK,
    /**< Audio SPS SLIMbus reference clock; set by MMPM_RSC_ID_CORE_CLK: 
         set frequency and enable. */
    MMPM_CLK_ID_AUDIOIF_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_AUDIOIF_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdAudioIfType;


/**
  Valid clock IDs for the LPASS aDSP.

  Only core clocks are included. 
  The HCLK for each block is controlled by either register programming or 
  generic bandwidth requests.
*/
typedef enum {
    MMPM_CLK_ID_LPASS_NONE = 0,
    /**<  None. */
    MMPM_CLK_ID_LPASS_HWRSP_CORE,
    /**<  Hardware resampler core clock. */
    MMPM_CLK_ID_LPASS_MIDI_CORE,
    /**<  MIDI core clock. */
    MMPM_CLK_ID_LPASS_AVSYNC_XO,
    /**<  Audio-video timer/ProntoSync XO clock. */
    MMPM_CLK_ID_LPASS_AVSYNC_BT,
    /**<  Audio-video timer/ProntoSync BT XO clock. */
    MMPM_CLK_ID_LPASS_AVSYNC_FM,
    /**<  Audio-video timer/ProntoSync FM XO clock. */
    MMPM_CLK_ID_LPASS_SLIMBUS_CORE,
    /**<  SLIMbus core clock. */
    MMPM_CLK_ID_LPASS_AVTIMER_CORE,
    /**< Audio-video timer core clock. */
    MMPM_CLK_ID_LPASS_ATIME_CORE,
    /**< Audio timer core clock. */
    MMPM_CLK_ID_LPASS_ATIME2_CORE,
    /**< Second instance of the audio timer core clock. */
/* the following clkid only for getinfo api.*/
    MMPM_CLK_ID_LPASS_ADSP_CORE,
    /**<  aDSP core clock; only applicable for MMPM_GetInfo(). */
    MMPM_CLK_ID_LPASS_AHB_ROOT,
    /**<  AHB root clock. */
    MMPM_CLK_ID_LPASS_ENUM_MAX,
    /**<  Maximum count. */
    MMPM_CLK_ID_LPASS_FORCE32BITS = 0x7fffffff
    /**<  Forces the enumeration to 32 bits. @if OEM_only @newpage @endif */
} MmpmClkIdLpassType;

/**
  Valid clock IDs for Video Capture and Processing (VCAP).
*/
typedef enum {
    MMPM_CLK_ID_VCAP_NONE,
    /**< No clock ID. */
    MMPM_CLK_ID_VCAP,
    /**< VCAP clock; set by MMPM_RSC_ID_CORE_CLK: set frequency and enable. */
    MMPM_CLK_ID_VCAP_NPL,
    /**< VCAP_NPL clock; set by MMPM_RSC_ID_CORE_CLK: enable only. */
    MMPM_CLK_ID_VCAP_MAX,
    /**< Maximum count. */
    MMPM_CLK_ID_VCAP_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkIdVcapType;

/**
 Clock ID for the core.
*/
typedef union {
/** @cond apps_only */
    MmpmClkId2dGrpType          clkId2dGrp;   /**< 2D graphics. */
    MmpmClkId3dGrpType          clkId3dGrp;   /**< 3D graphics. */
    MmpmClkIdMdpType            clkIdMdp;     /**< Mobile Display Processor 
                                                   (MDP). */
    MmpmClkIdVcodecType         clkIdVcodec;  /**< Video codec. */
    MmpmClkIdVpeType            clkIdVpe;     /**< Video Preprocessing Engine 
                                                   (VPE). */
    MmpmClkIdVfeType            clkIdVfe;     /**< Video Front End (VFE). */
    MmpmClkIdCsiType            clkIdCsi;     /**< Camera Serial Interface 
                                                   (CSI). */
    MmpmClkIdSensorType         clkIdSensor;  /**< Sensor. */
    MmpmClkIdJpegdType          clkIdJpegd;   /**< JPEG decoder. */
    MmpmClkIdJpegeType          clkIdJpege;   /**< JPEG encoder. */
    MmpmClkIdRotatorType        clkIdRotator; /**< Rotator. */
    MmpmClkIdTvType             clkIdTv;      /**< TV. */
    MmpmClkIdDsiType            clkIdDsi;     /**< Display Serial Interface 
                                                   (DSI). */
    MmpmClkIdAudioIfType        clkIdAudioIf; /**< Audio interface. */
    MmpmClkIdVcapType           clkIdVcap;    /**< Video Capture and Processing 
                                                   (VCAP). */
/** @endcond */
    MmpmClkIdLpassType          clkIdLpass;
    /**< Low Power Audio Subsystem (LPASS).

         @values See #MmpmClkIdLpassType */

} MmpmCoreClkIdType;


/**
  Valid frequency clock matches.
*/
typedef enum {
    MMPM_FREQ_AT_LEAST,  /**< At least. */
    MMPM_FREQ_AT_MOST,   /**< At most. */
    MMPM_FREQ_CLOSEST,   /**< Closest. */
    MMPM_FREQ_EXACT,     /**< Exact. */
    MMPM_FREQ_MAX,       /**< Maximum count. */
    MMPM_FREQ_FORCE32BITS = 0x7FFFFFFF
                         /**< Forces the enumeration to 32 bits. */
} MmpmFreqMatchType;


/**
  Clock setting for one clock ID.
*/
typedef struct {
    MmpmCoreClkIdType           clkId;
    /**< Core clock ID defined by enumerations of MmpmClkIdXyzType, where 
         Xyz is the core name. */

    uint32                      clkFreqHz;
    /**< Clock frequency is in Hertz. */
    MmpmFreqMatchType           freqMatch;
    /**< Frequency match.

         @values See #MmpmFreqMatchType */
} MmpmClkValType;


/**
  Clock value array that contains clock frequencies for each corresponding 
  clock ID.
*/
typedef struct {
    uint32                      numOfClk;
    /**< Number of clock settings in the array. */
    MmpmClkValType              *pClkArray;
    /**< Pointer to an array of clock settings.
         @if OEM_only @newpagetable @endif */
} MmpmClkReqType;


/******** rscId = MMPM_RSC_ID_CORE_CLK_DOMAIN ********/
/** @cond apps_only */
/**
  Clock ID for HDMI.
*/
typedef enum {
    MMPM_CLK_DOMAIN_SRC_ID_HDMI_NONE,
    /**< No clock ID. */
    MMPM_CLK_DOMAIN_SRC_ID_HDMI0,
    /**< HDMI0 clock. */
    MMPM_CLK_DOMAIN_SRC_ID_HDMI_MAX,
    /**< Maximum count. */
    MMPM_CLK_DOMAIN_SRC_ID_HDMI_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkDomainSrcIdHdmiType;


/**
  Valid clock IDs for DSI.
*/
typedef enum {
    MMPM_CLK_DOMAIN_SRC_ID_DSI_NONE,
    /**< No clock ID. */
    MMPM_CLK_DOMAIN_SRC_ID_DSI0,
    /**< DSI0 clock. */
    MMPM_CLK_DOMAIN_SRC_ID_DSI1,
    /**< DSI1 clock. */
    MMPM_CLK_DOMAIN_SRC_ID_LVDS,
    /**< LVDS clock. */
    MMPM_CLK_DOMAIN_SRC_ID_DSI_MAX,
    /**< Maximum count. */
    MMPM_CLK_DOMAIN_SRC_ID_DSI_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkDomainSrcIdDsiType;
/** @endcond */

/**
  Valid clock domain source IDs for the LPASS.
*/
typedef enum {
    MMPM_CLK_DOMAIN_SRC_ID_LPASS_NONE,
    /**< No clock ID. */
    MMPM_CLK_DOMAIN_SRC_ID_Q6PLL,
    /**< Audio-video synchronization clock. */
    MMPM_CLK_DOMAIN_SRC_ID_AUDIOPLL,
    /**< Audio-video timer clock. */
    MMPM_CLK_DOMAIN_SRC_ID_PRIUSPLL,
    /**< Audio timer clock. */
    MMPM_CLK_DOMAIN_SRC_ID_LPASS_MAX,
    /**< Maximum count. */
    MMPM_CLK_DOMAIN_SRC_ID_LPASS_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmClkDomainSrcIdLpassType;


/**
  Clock domain source ID for all cores.
*/
typedef union {
/** @cond apps_only */
    MmpmClkDomainSrcIdHdmiType  clkDomainSrcIdHdmi;
    /**< Clock domain source IDs of HDMI. */
    MmpmClkDomainSrcIdDsiType   clkDomainSrcIdDsi;
    /**< Clock domain source IDs of DSI. */
/** @endcond */

    MmpmClkDomainSrcIdLpassType clkDomainSrcIdLpass;
    /**< Clock domain source ID of the LPASS.

         @values See #MmpmClkDomainSrcIdType @if apps_only @newpagetable @endif */
} MmpmClkDomainSrcIdType;

/**
  Clock domain setting for one clock ID.
*/
typedef struct {
    MmpmCoreClkIdType           clkId;
    /**< Core clock ID defined by MmpmClkIdXyzType, where Xyz is the
         core name. */
    uint32                      M_val;
    /**< M value. */
    uint32                      N_val;
    /**< N value. */
    uint32                      n2D_val;
    /**< 2D value. */
    uint32                      div_val;
    /**< Predivider value. */
    uint32                      clkFreqHz;
    /**< Frequency (in Hertz) of the core clock ID that is
         configured using M, N, and D. */
    MmpmClkDomainSrcIdType      clkDomainSrc;
    /**< Clock domain source ID. */
} MmpmClkDomainType;

/**
  Clock domain array that contains clock domain settings for each 
  corresponding clock ID.
*/
typedef struct {
    uint32                      numOfClk;
    /**< Number of clock settings in the array. */
    MmpmClkDomainType           *pClkDomainArray;
    /**< Pointer to an array of clock domain settings. */
} MmpmClkDomainReqType;


/******** rscId = MMPM_RSC_ID_THERMAL ********/
/**
  Valid thermal mitigation requests.
*/
typedef enum {
    MMPM_THERMAL_NONE,      /**< No mitigation. */
    MMPM_THERMAL_LOW,       /**< Low temperature condition. */
    MMPM_THERMAL_NORM,      /**< Normal temperature condition. No thermal 
                                 mitigation is needed. */
    MMPM_THERMAL_HIGH_L1,   /**< High temperature condition level 1. */
    MMPM_THERMAL_HIGH_L2,   /**< High temperature condition level 2. */
    MMPM_THERMAL_HIGH_L3,   /**< High temperature condition level 3. */
    MMPM_THERMAL_HIGH_L4,   /**< High temperature condition level 4. */
    MMPM_THERMAL_HIGH_L5,   /**< High temperature condition level 5. */
    MMPM_THERMAL_HIGH_L6,   /**< High temperature condition level 6. */
    MMPM_THERMAL_HIGH_L7,   /**< High temperature condition level 7. */
    MMPM_THERMAL_HIGH_L8,   /**< High temperature condition level 8. */
    MMPM_THERMAL_HIGH_L9,   /**< High temperature condition level 9. */
    MMPM_THERMAL_HIGH_L10,  /**< High temperature condition level 10. */
    MMPM_THERMAL_HIGH_L11,  /**< High temperature condition level 11. */
    MMPM_THERMAL_HIGH_L12,  /**< High temperature condition level 12. */
    MMPM_THERMAL_HIGH_L13,  /**< High temperature condition level 13. */
    MMPM_THERMAL_HIGH_L14,  /**< High temperature condition level 14. */
    MMPM_THERMAL_HIGH_L15,  /**< High temperature condition level 15. */
    MMPM_THERMAL_HIGH_L16,  /**< High temperature condition level 16. */
    MMPM_THERMAL_MAX,       /**< Maximum count. */
    MMPM_THERMAL_FORCE32BITS = 0x7FFFFFFF
                            /**< Forces the enumeration to 32 bits. */
} MmpmThermalType;



/******** rscId = MMPM_RSC_ID_MEM_BW, MMPM_RSC_ID_GENERIC_BW ********/
/**
  Bandwidth usage for 2D graphics.
*/
typedef enum {
    MMPM_BW_USAGE_2D_GRP_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_2D_GRP,       /**< 2D graphics bandwidth usage. */
    MMPM_BW_USAGE_2D_GRP_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_2D_GRP_FORCE32BITS = 0x7FFFFFFF
                                /**< Forces the enumeration to 32 bits. */
} MmpmBwUsage2dGrpType;


/**
  Bandwidth usage for 3D graphics.
*/
typedef enum {
    MMPM_BW_USAGE_3D_GRP_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_3D_GRP,       /**< 3D graphics bandwidth usage. */
    MMPM_BW_USAGE_3D_GRP_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_3D_GRP_FORCE32BITS = 0x7FFFFFFF
                                /**< Forces the enumeration to 32 bits. */
} MmpmBwUsage3dGrpType;


/**
  Bandwidth usage for the MDP.
*/
typedef enum {
    MMPM_BW_USAGE_MDP_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_MDP,       /**< MDP bandwidth usage. */
    MMPM_BW_USAGE_MDP_HRES,  /**< MDP bandwidth usage for high resolution. */
    MMPM_BW_USAGE_MDP_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_MDP_FORCE32BITS = 0x7FFFFFFF
                             /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageMdpType;


/**
  Bandwidth usage for the video codec.
*/
typedef enum {
    MMPM_BW_USAGE_VCODEC_NONE,
    /**< No bandwidth usage. */
    MMPM_BW_USAGE_VCODEC_ENC,
    /**< Video codec bandwidth usage when doing encoding. */
    MMPM_BW_USAGE_VCODEC_DEC,
    /**< Video codec bandwidth usage when doing decoding. */
    MMPM_BW_USAGE_VCODEC_ENC_DEC,
    /**< Video codec bandwidth usage when doing both encoding and decoding. */
    MMPM_BW_USAGE_VCODEC_MAX,
    /**< Maximum count. */
    MMPM_BW_USAGE_VCODEC_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageVcodecType;


/**
  Bandwidth usage for the VPE.
*/
typedef enum {
    MMPM_BW_USAGE_VPE_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_VPE,       /**< VPE bandwidth usage. */
    MMPM_BW_USAGE_VPE_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_VPE_FORCE32BITS = 0x7FFFFFFF
                             /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageVpeType;


/**
  Bandwidth usage for the VFE.
*/
typedef enum {
    MMPM_BW_USAGE_VFE_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_VFE,       /**< VFE bandwidth usage. */
    MMPM_BW_USAGE_VFE_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_VFE_FORCE32BITS = 0x7FFFFFFF
                             /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageVfeType;


/**
  Bandwidth usage for the JPEG decoder.
*/
typedef enum {
    MMPM_BW_USAGE_JPEGD_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_JPEGD,       /**< JPEG decoder bandwidth usage. */
    MMPM_BW_USAGE_JPEGD_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_JPEGD_FORCE32BITS = 0x7FFFFFFF
                               /**< Forces the enumeration to 32 bits.
                                    @newpage */
} MmpmBwUsageJpegdType;


/**
  Bandwidth usage for the JPEG encoder.
*/
typedef enum {
    MMPM_BW_USAGE_JPEGE_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_JPEGE,       /**< JPEG encoder bandwidth usage. */
    MMPM_BW_USAGE_JPEGE_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_JPEGE_FORCE32BITS = 0x7FFFFFFF
                               /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageJpegeType;


/**
  Bandwidth usage for the rotator.
*/
typedef enum {
    MMPM_BW_USAGE_ROTATOR_NONE,  /**< No bandwidth usage. */
    MMPM_BW_USAGE_ROTATOR,       /**< Rotator bandwidth usage. */
    MMPM_BW_USAGE_ROTATOR_MAX,   /**< Maximum count. */
    MMPM_BW_USAGE_ROTATOR_FORCE32BITS = 0x7FFFFFFF
                                 /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageRotatorType;


/**
  Bandwidth usage for the LPASS.
*/
typedef enum {
    MMPM_BW_USAGE_LPASS_NONE,      /**< No bandwidth usage. */
    MMPM_BW_USAGE_LPASS_DSP,       /**< Bandwidth usage by the aDSP. */
    MMPM_BW_USAGE_LPASS_DMA,       /**< Bandwidth usage by DMA/BAM. */
    MMPM_BW_USAGE_LPASS_EXT_CPU,   /**< Bandwidth usage by the CPU outside 
                                        of the LPASS. */
    MMPM_BW_USAGE_LPASS_ENUM_MAX,  /**< Maximum count. */
    MMPM_BW_USAGE_LPASS_FORCE32BITS = 0x7FFFFFFF
                                   /**< Forces the enumeration to 32 bits. */
} MmpmBwUsageLpassType;


/**
  Bandwidth usage for the core.
*/
typedef union {
/** @cond apps_only */
    MmpmBwUsage2dGrpType        bwUsage2dGrp;    /**< 2D graphics. */
    MmpmBwUsage3dGrpType        bwUsage3dGrp;    /**< 3D graphics. */
    MmpmBwUsageMdpType          bwUsageMdp;      /**< MDP. */
    MmpmBwUsageVcodecType       bwUsageVcodec;   /**< Video codec. */
    MmpmBwUsageVpeType          bwUsageVpe;      /**< VPE. */
    MmpmBwUsageVfeType          bwUsageVfe;      /**< VFE. */
    MmpmBwUsageJpegdType        bwUsageJpegd;    /**< CSI. */
    MmpmBwUsageJpegeType        bwUsageJpege;    /**< Sensor. */
    MmpmBwUsageRotatorType      bwUsageRotator;  /**< JPEG decoder. */
/** @endcond */

    MmpmBwUsageLpassType        bwUsageLpass;
    /**< Type of LPASS usage.

         @values See #MmpmBwUsageLpassType */
} MmpmCoreBwUsageType;

/**
  Valid generic bandwidth port IDs.
*/
typedef enum {
    MMPM_BW_PORT_ID_NONE = 0,        /**< No port ID. */
    MMPM_BW_PORT_ID_ADSP_MASTER,     /**< aDSP master. */
	MMPM_BW_PORT_ID_Q6DSP_MASTER = MMPM_BW_PORT_ID_ADSP_MASTER, /**< Compute DSP Master. */
    MMPM_BW_PORT_ID_DML_MASTER,      /**< Data Mover Lite master. */
    MMPM_BW_PORT_ID_AIF_MASTER,      /**< Audio interface master. */
    MMPM_BW_PORT_ID_SLIMBUS_MASTER,  /**< SLIMbus master. */
    MMPM_BW_PORT_ID_MIDI_MASTER,     /**< MIDI master. */
    MMPM_BW_PORT_ID_HWRSMP_MASTER,   /**< Hardware Resampler master. */
    MMPM_BW_PORT_ID_EXT_AHB_MASTER,  /**< External AHB master. This is the 
                                          SNoC port to the AHB. */
    MMPM_BW_PORT_ID_SPDIF_MASTER,    /**< SPDIF master. */
    MMPM_BW_PORT_ID_HDMIRX_MASTER,   /**< HDMI RX slave. */
    MMPM_BW_PORT_ID_HDMITX_MASTER,   /**< HDMI TX slave. */
    MMPM_BW_PORT_ID_SIF_MASTER,      /**< SIF slave. */
    MMPM_BW_PORT_ID_DML_SLAVE,       /**< Data Mover Lite slave. */
    MMPM_BW_PORT_ID_AIF_SLAVE,       /**< Audio interface slave. */
    MMPM_BW_PORT_ID_SLIMBUS_SLAVE,   /**< SLIMbus slave. */
    MMPM_BW_PORT_ID_MIDI_SLAVE,      /**< MIDI slave. */
    MMPM_BW_PORT_ID_HWRSMP_SLAVE,    /**< Hardware sesampler slave. */
    MMPM_BW_PORT_ID_AVSYNC_SLAVE,    /**< Audio-video timer/ProntoSync slave. */
    MMPM_BW_PORT_ID_LPM_SLAVE,       /**< Low-power memory slave. */
    MMPM_BW_PORT_ID_SRAM_SLAVE,      /**< Sensors RAM slave. */
    MMPM_BW_PORT_ID_EXT_AHB_SLAVE,   /**< Extended AHB slave. */
    MMPM_BW_PORT_ID_DDR_SLAVE,       /**< DDR slave. */
    MMPM_BW_PORT_ID_OCMEM_SLAVE,     /**< On-chip memory slave. */
    MMPM_BW_PORT_ID_PERIFNOC_SLAVE,  /**< Peripheral NoC slave. */
    MMPM_BW_PORT_ID_SPDIF_SLAVE,     /**< SPDIF slave. */
    MMPM_BW_PORT_ID_HDMIRX_SLAVE,    /**< HDMI RX slave. */
    MMPM_BW_PORT_ID_HDMITX_SLAVE,    /**< HDMI TX slave. */
    MMPM_BW_PORT_ID_SIF_SLAVE,       /**< SIF slave. */
    MMPM_BW_PORT_ID_BSTC_SLAVE,      /**< BSTC slave. */
    MMPM_BW_PORT_ID_DCODEC_SLAVE,    /**< Digital codec slave. */
    MMPM_BW_PORT_ID_CORE,            /**< Core for which the current client is 
                                          registered. This must be specified 
                                          in the srcPortId for core-to-memory 
                                          transfers. */
    MMPM_BW_PORT_ID_MAX,             /**< Maximum count. */
    MMPM_BW_PORT_ID_FORCE32BITS = 0x7FFFFFFF
                                    /**< Forces the enumeration to 32 bits. */
} MmpmBwPortIdType;

/** @cond apps_only */
/**
  Bandwidth value structure that includes information on source-destination, 
  bandwidth value, and bandwidth characteristics.
*/
typedef struct {
    /* master-slave */
    uint32                      memPhyAddr;
    /**< Physical memory address. */
    uint32                      axiPort;
    /**< AXI port index. */

    /* bw */
    uint32                      bwBytePerSec;
    /**< Bytes per second. */

    /* bw characteristics */
    uint32                      usagePercentage;
    /**< Percentage of bandwidth usage. */
    MmpmCoreBwUsageType         bwUsageType;
    /**< Core's bandwidth usage type defined by enumerations of 
         MmpmBwUsageXyzType, where Xyz is the core name. */
} MmpmBwValType;

/**
  Bandwidth value array that contains bandwidth settings for each 
  corresponding memory ID. All BW requests should be valid. 0 is not a valid value
*/
typedef struct {
    uint32                      numOfBw;
    /**< Number of bandwidth settings in the array; maximum: 16 per client. */
    MmpmBwValType               *pBandWidthArray;
    /**< Pointer to an array of bandwidth settings. @newpagetable */
} MmpmBwReqType;
/** @endcond */


/* general BW definition start here */
/**
  Bus route type (master/slave pair).
*/
typedef struct{
    MmpmBwPortIdType masterPort;
    /**< Type of master port.

         @values See #MmpmBwPortIdType */

    MmpmBwPortIdType slavePort;
    /**< Type of slave port.

         @values See #MmpmBwPortIdType */
} MmpmBusRouteType;

/**
  Holds the bandwidth values for Type 3 requests (Ab/Ib).
*/
typedef struct{
    uint64 Ab;  /**< Average bandwidth in bytes per second. */
    uint64 Ib;  /**< Instantaneous bandwidth in bytes per second. */
} MmpmBusBWDataIbAbType;

/**
  Holds the bandwidth value for Type 1 requests (bandwidth/usage).
*/
typedef struct{
    uint64 bwBytePerSec;
    /**< Bandwidth value in bytes per second. */
    uint32 usagePercentage;
    /**< Utilization percentage. */
    MmpmBwUsageLpassType usageType;
    /**< Bandwidth usage type.

         @values See #MmpmBwUsageLpassType */
} MmpmBusBWDataUsageType;

/** @cond apps_only */
/**
  Bandwidth request for Ab/Ib.
*/
typedef union{
    MmpmBusBWDataIbAbType busBwAbIb;
    /**< Bus bandwidth for Ab/Ib. */
    MmpmBusBWDataUsageType busBwValue;
    /**< Bus bandwidth for bandwidth/usage. @if apps_only @newpagetable @endif */
} MmpmBusBWDataType;
/** @endcond */

/**
  Bandwidth request parameters.
*/
typedef struct{
    MmpmBusRouteType busRoute;
    /**< Master/slave pair for which the bandwidth is requested. */
    MmpmBusBWDataType bwValue;
    /**< Bandwidth value. @if OEM_only @newpagetable @endif */
} MmpmGenBwValType;

/**
  Generic bandwidth value array that contains bandwidth settings for each 
  corresponding master/slave pair.All BW requests should be valid. 0 is not a valid value
*/
typedef struct {
    uint32                         numOfBw;
    /**< Number of bandwidth settings in the array.
         The maximum is 16 per client. */
    MmpmGenBwValType               *pBandWidthArray;
    /**< Pointer to an array of bandwidth settings. */
} MmpmGenBwReqType;

/******** rscId = MMPM_RSC_ID_MEM_POWER ********/
/**
  Valid memory power states.
*/
typedef enum {
    MMPM_MEM_POWER_NONE,       /**< No state. */
    MMPM_MEM_POWER_OFF,        /**< Memory is off. */
    MMPM_MEM_POWER_RETENTION,  /**< Memory is in retention. */
    MMPM_MEM_POWER_ACTIVE,     /**< Memory is in the Active state. */
    MMPM_MEM_POWER_MAX,        /**< Maximum count. */
    MMPM_MEM_POWER_FORCE32BITS = 0x7FFFFFFF
                               /**< Forces the enumeration to 32 bits. */
} MmpmMemPowerStateType;

/**
  Valid memory IDs for memory power state requests.
*/
typedef enum{
    MMPM_MEM_NONE,       /**< No memory ID. */
    MMPM_MEM_OCMEM,      /**< On-chip memory. */
    MMPM_MEM_LPASS_LPM,  /**< Low-power memory. */
    MMPM_MEM_SRAM,       /**< Sensors RAM. */
    MMPM_MEM_MAX,        /**< Maximum count. */
    MMPM_MEM_FORCE32BITS = 0x7FFFFFFF
                        /**< Forces the enumeration to 32 bits. */
} MmpmMemIdType;

/**
  Memory power state request parameter.
*/
typedef struct{
    MmpmMemIdType memory;
    /**< Memory type identifier.

         @values See #MmpmMemIdType */

    MmpmMemPowerStateType powerState;
    /**< Type of power state.

         @values See #MmpmMemPowerStateType */
}MmpmMemPowerReqParamType;

/** @cond apps_only */
/**
 PMIC GPIO parameter.
*/
typedef struct {
    uint32                      gpioId;
    /**< Which GPIO to configure. */
    boolean                     configGpio;
    /**< Whether to configure GPIO. */
    uint32                      gpioVoltageSource;
    /**< Which voltage source. */
    boolean                     gpioModeOnOff;
    /**< Enables/disables the mode selection. */
    uint32                      gpioModeSelect;
    /**< Mode select type. */
    uint32                      gpioOutBufferConfig;
    /**< Output buffer configuration. */
    boolean                     invertExtPin;
    /**< Invert external pin. */
    uint32                      gpioCurrentSourcePulls;
    /**< Current source pull configuration. */
    uint32                      gpioOutBufferDriveStrength;
    /**< Output buffer drive strength. */
    uint32                      gpioDtestBufferOnOff;
    /**< Dtest buffer configuration. */
    uint32                      gpioExtPinConfig;
    /**< OEM_only pin configuration. */
    uint32                      gpioSourceConfig;
    /**< GPIO source configuration. */
    boolean                     interrupPolarity;
    /**< Interrupt polarity. */
    uint32                      uartPath;
    /**< UART path. */
} MmpmPmicGpioParamType;
/** @endcond */

/**
 Valid types of PMIC GPIO configuration.
*/
typedef enum {
     MMPM_PMIC_CONFIG,
     /**< General configuration. */
     MMPM_PMIC_CONFIG_BIAS_VOLTAGE,
     /**< Bias voltage. */
     MMPM_PMIC_CONFIG_DIGITAL_INPUT,
     /**< Digital input. */
     MMPM_PMIC_CONFIG_DIGITAL_OUTPUT,
     /**< Digital output. */
     MMPM_PMIC_CONFIG_SET_VOLTAGE_SOURCE,
     /**< Set the voltage source. */
     MMPM_PMIC_CONFIG_MODE_SELECTION,
     /**< Mode selection. */
     MMPM_PMIC_CONFIG_SET_OUTPUT_BUFFER,
     /**< Set the output buffer configuration. */
     MMPM_PMIC_CONFIG_SET_INVERSION,
     /**< Set the inversion configuration. */
     MMPM_PMIC_CONFIG_SET_CURRENT_SOURCE_PULLS,
     /**< Set the current source pulls. */
     MMPM_PMIC_CONFIG_SET_EXT_PIN,
     /**< Set the external pin configuration. */
     MMPM_PMIC_CONFIG_SET_OUTPUT_BUF_DRIVE_STRG,
     /**< Set the output buffer drive strength. */
     MMPM_PMIC_CONFIG_SET_SOURCE,
     /**< Set the source configuration. */
     MMPM_PMIC_CONFIG_SET_INT_POLARITY,
     /**< Set the interrupt polarity. */
     MMPM_PMIC_CONFIG_SET_MUX_CTRL,
     /**< Set the MUX control. */
} MmpmPmicGpioConfigType;

/** @cond apps_only */
/**
  The PMIC GPIO value structure includes information on the configuration ID 
  and GPIO parameters. This is a passthrough from the client to the PMIC 
  driver. For each congigId, pass in the corresponding parameters in 
  MmpmPmicGpioParamType.
*/
/* Refer to PMIC GPIO API header file for details of parameters
   that need to be filled for a configId. */
typedef struct {
    MmpmPmicGpioConfigType      configId;
    /**< PMIC GPIO configuration ID. */
    MmpmPmicGpioParamType       gpioParam;
    /**< PMIC GPIO configuration parameters. */
} MmpmPmicGpioReqType;

/**
  Valid types of reset to be done through the resource ID, MMPM_RSC_ID_RESET.
*/
typedef enum {
     MMPM_RESET_NONE,      /**< Reset is ignored. */
     MMPM_RESET_DEASSERT,  /**< Reset with a deassert. */
     MMPM_RESET_ASSERT,    /**< Reset with an assert. */
     MMPM_RESET_PULSE,     /**< Reset with a pulse. */
     MMPM_RESET_ENUM_MAX,  /**< Maximum count. */
     MMPM_RESET_ENUM_FORCE32BITS = 0x7FFFFFFF
                          /**< Forces the enumeration to 32 bits. */
} MmpmResetType;
/** @endcond */

/** @cond apps_only */
/**
  Parameter for the reset.
*/
typedef struct {
    MmpmCoreClkIdType         clkId;
    /**< Clock ID corresponding to a coreId and instanceId. */
    MmpmResetType             resetType;
    /**< Reset type. */
} MmpmResetParamType;

/**
  Request for the reset.
*/
typedef struct {
    uint32                    numOfReset;
    /**< Number of reset requests. */
    MmpmResetParamType        *pResetParamArray;
    /**< Reset parameter. */
} MmpmResetReqType;
/** @endcond */

/**
  Possible operations to perform during an extended MIPS request.
*/
typedef enum {
    MMPM_MIPS_REQUEST_NONE = 0,
    /**< No operation. */
    MMPM_MIPS_REQUEST_CPU_CLOCK_ONLY,
    /**< MIPS request adjusts only the CPU clock. The bandwidth to cover 
         instruction fetches is requested separately. */
    MMPM_MIPS_REQUEST_CPU_CLOCK_AND_BW,
    /**< MIPS request adjusts CPU clock and bandwidth required to support 
         instruction fetches. The location of the code must be provided in 
         this request.*/

    MMPM_MIPS_REQUEST_ENUM_MAX,
    /**< Maximum count. */
    MMPM_MIPS_REQUEST_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. */
} MmpmMipsRequestFnType;

/**
  MIPS request structure for an extended MIPS request.
*/
typedef struct {
    uint32                 mipsTotal;
    /**< Total MIPS value. */
    uint32                 mipsPerThread;
    /**< MIPS value per hardware thread. */
    MmpmBwPortIdType       codeLocation;
    /**< Location from where the code is executed.

         @values See #MmpmBwPortIdType */ //TODO create a new enum
    MmpmMipsRequestFnType  reqOperation;
    /**< Operations the MIPS request is to include.

         @values See #MmpmMipsRequestFnType */
} MmpmMipsReqType;

/**
  MPPS request structure for MPPS request.
*/
typedef struct {
    uint32                 mppsTotal;
    /**< Total MPPS value. */
    uint32                 adspFloorClock;
    /**< aDSP Floor Clock value(Mhz) . */   
} MmpmMppsReqType;

/******************************************************************************************/
/*                                                                                        */
/*                    MMPM_Release() Data Structure                                   */
/*                                                                                        */
/******************************************************************************************/
/**
  Array of clock IDs for the same core, defined by the same enumeration of 
  MmpmClkIdXyzType, where Xyz is the core name. For example, MmpmClkId2dGrpType.
*/
typedef struct {
    uint32                      numOfClk;
    /**< Number of clocks. */
    MmpmCoreClkIdType           *pClkIdArray;
    /**< Pointer to an array of clock IDs. @if OEM_only @newpagetable @endif */
} MmpmClkIdArrayParamType;


/******************************************************************************************/
/*                                                                                        */
/*                    MMPM_Request(), MMPM_Release(),                             */
/*                    MMPM_Pause(), and MMPM_Resume() Data Structures                      */
/*                                                                                        */
/******************************************************************************************/

/*
  For MMPM_Request(): \n
     -if rscId = MMPM_RSC_ID_POWER,              NULL;        Return MMPM_SUCESS if the GDHS request was sucessfull or if the support is broken in h/w or s/w.
                                                              If it is broken no call is made to clkregime driver to enable the GDHS bit.
                                                              MMPM_UNSUPPORTED will be returned if the h/w block does not have support for GDHS; \n
     -if rscId = MMPM_RSC_ID_VREG,               vregMilliVolt; \n
     -if rscId = MMPM_RSC_ID_REG_PROG,           regProgMatch; \n
     -if rscId = MMPM_RSC_ID_PMIC_GPIO,          pPmicGpio; \n
     -if rscId = MMPM_RSC_ID_CORE_CLK,           pCoreClk; \n
     -if rscId = MMPM_RSC_ID_CORE_CLK_DOMAIN,    pCoreClkDomain; \n
     -if rscId = MMPM_RSC_ID_MEM_BW,             pBwReq; \n
     -if rscId = MMPM_RSC_ID_GENERIC_BW,         pGenBwReq; \n
     -if rscId = MMPM_RSC_ID_AXI_EN,             NULL; .\n
     -if rscId = MMPM_RSC_ID_SLEEP_LATENCY,      sleepMicroSec;   This request should be used by clients who have restrictions on the maximum interrupt 
                                                                  latency that they can endure and still function correctly.A value of 0 is rejected with 
                                                                  a return status MMPM_STATUS_BADPARM.Make sure you only make your latency request when 
                                                                  you are expecting your interrupt to fire. And cancel your request when you are no longer 
                                                                  expecting your interrupt to fire. Otherwise, you will be preventing low power modes by 
                                                                  having a latency restriction in place that is not being used.\n
     -if rscId = MMPM_RSC_ID_MIPS,               mips; \n
     -if rscId = MMPM_RSC_ID_MIPS_EXT,           pMipsExt;
     -if rscId = MMPM_RSC_ID_RESET,              pResetReq; \n \n
     -if rscId = MMPM_RSC_ID_ACTIVE_STATE,       NULL; Request: core is active; \n
     -if rscId = MMPM_RSC_ID_THERMAL,            thermalMitigation; Request for thermal mitigation for the condition described in thermalMitigation; \n
     -if rscId = MMPM_RSC_MEM_POWER,             pMemPowerState; Memory power request data\n

  For MMPM_Release(): \n
     -if rscId = MMPM_RSC_ID_POWER,              NULL;        Return MMPM_SUCESS if the GDHS request was sucessfull or if the support is broken in h/w or s/w.
                                                              If it is broken no call is made to clkregime driver to disable the GDHS bit.
                                                              MMPM_UNSUPPORTED will be returned if the h/w block does not have support for GDHS; \n
     -if rscId = MMPM_RSC_ID_VREG,               NULL; \n
     -if rscId = MMPM_RSC_ID_REG_PROG,           NULL; \n
     -if rscId = MMPM_RSC_ID_CORE_CLK,           pRelClkIdArray; \n
     -if rscId = MMPM_RSC_ID_CORE_CLK_DOMAIN,    pRelClkIdArray; \n
     -if rscId = MMPM_RSC_ID_MEM_BW,             NULL; \n
     -if rscId = MMPM_RSC_ID_GENERIC_BW,         NULL; \n
     -if rscId = MMPM_RSC_ID_AXI_EN,             NULL; \n
     -if rscId = MMPM_RSC_ID_SLEEP_LATENCY,      NULL; \n
     -if rscId = MMPM_RSC_ID_MIPS,               NULL; \n
     -if rscId = MMPM_RSC_ID_MIPS_EXT,           NULL; \n
     -if rscId = MMPM_RSC_ID_ACTIVE_STATE,       NULL; Release: core is idle; \n
     -if rscId = MMPM_RSC_ID_THERMAL,            thermalMitigation; No thermal mitigation is necessary. Equivalent to request with 
                                                                    thermalMitigation =  MMPM_THERMAL_NORM  \n
     -if rscId = MMPM_RSC_MEM_POWER,             NULL;\n


  For MMPM_Pause()/MMPM_Resume(): \n
     -if rscId = MMPM_RSC_ID_CLK,                gateClkId; \n
     -if rscId = MMPM_RSC_ID_CORE_CLK,           gateClkId; \n
     -if rscId = MMPM_RSC_ID_REG_PROG,           NULL; \n Pause/Resumes AHB clks.
     -if rscId = MMPM_RSC_ID_MEM_BW,             NULL; \n Pause/Resume AXI clks
*/
/**
  MMPM resource parameter structure definition. 

  @if OEM_only
  The parameter maps to different structures depending on the rscId 
  (in MmpmRscParamType) and whether the function is MMPM_Request_Ext() or 
  MMPM_Release_Ext().
  Below is a summary of the resource mapping, followed by the parameter
  description table.

  @inputtable{MmpmRscParamStructType_parameters_OEM.tex}
  @endif

  @if apps_only
  The parameter maps to different structures depending on the rscId 
  (in MmpmRscParamType) and whether the function is MMPM_Request(), 
  MMPM_Release(), MMPM_Pause(), or MMPM_Resume().
  Below is a summary of the resource mapping, followed by the parameter
  description table.

  @inputtable{MmpmRscParamStructType_parameters.tex}
  @endif
*/
typedef union {
    /* For MMPM_Request() */
    uint32                      vregMilliVolt;
    /**< VREG in millivolts.

         @if OEM_only For rscId = MMPM_RSC_ID_VREG in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_VREG in MMPM_Request().
         @endif */

    MmpmRegProgMatchType        regProgMatch;
    /**< Register programming clock match.

         @if OEM_only For rscId = MMPM_RSC_ID_REG_PROG in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_REG_PROG in MMPM_Request().
         @endif */

    MmpmPmicGpioReqType         *pPmicGpio;
    /**< Pointer to the MIC GPIO parameters.

         @if OEM_only For rscId = MMPM_RSC_ID_PMIC_GPIO in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_PMIC_GPIO in MMPM_Request().
         @endif */

    MmpmClkReqType              *pCoreClk;
    /**< Pointer to the core clock request parameter.

         @if OEM_only For rscId = MMPM_RSC_ID_CORE_CLK in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_CORE_CLK in MMPM_Request().
         @endif */

    MmpmClkDomainReqType        *pCoreClkDomain;
    /**< Pointer to the core clock domain parameter.

         @if OEM_only For rscId = MMPM_RSC_ID_CORE_CLK_DOMAIN in
         MMPM_Request_Ext(). @endif
         @if apps_only For rscId = MMPM_RSC_ID_CORE_CLK_DOMAIN in MMPM_Request().
         @endif */

    MmpmBwReqType               *pBwReq;
    /**< Pointer to the bandwidth request parameter.

         @if OEM_only For rscId = MMPM_RSC_ID_MEM_BW in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_MEM_BW in MMPM_Request().
         @endif */

    MmpmGenBwReqType            *pGenBwReq;
    /**< Pointer to the bandwidth request parameter.

         @if OEM_only For rscId = MMPM_RSC_ID_GENERIC_BW in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_GENERIC_BW in MMPM_Request().
         @endif */

    uint32                      sleepMicroSec;
    /**< Sleep latency in microseconds.

         @if OEM_only For rscId = MMPM_RSC_ID_SLEEP_LATENCY in
         MMPM_Request_Ext(). @endif
         @if apps_only For rscId = MMPM_RSC_ID_SLEEP_LATENCY in MMPM_Request().
         @endif */

    uint32                      mips;
    /**< MIPS.

         @if OEM_only For rscId = MMPM_RSC_ID_MIPS in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_MIPS in MMPM_Request().
         @endif

         MIPS = 0 is treated as an impulse request. No release is 
         expected for an impulse request. */

    MmpmResetReqType            *pResetReq;
    /**< Pointer to the reset parameters.

         @if OEM_only For rscId = MMPM_RSC_ID_RESET in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_RESET in MMPM_Request().
         @endif */

    MmpmMipsReqType             *pMipsExt;
    /**< Pointer to the MIPS, request type, and code location.

         @if OEM_only For rscId = MMPM_RSC_ID_MIPS_EXT in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_MIPS_EXT in MMPM_Request().
         @endif */

    MmpmMppsReqType             *pMppsReq;
    /**< Pointer to the MPPS, request type.

         @if OEM_only For rscId = MMPM_RSC_ID_MPPS in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_MPPS in MMPM_Request().
         @endif */

    MmpmThermalType             thermalMitigation;
    /**< Thermal mitigation requested.

         @if OEM_only For rscId = MMPM_RSC_ID_THERMAL in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_THERMAL in MMPM_Request().
         @endif */

    MmpmMemPowerReqParamType    *pMemPowerState;
    /**< Pointer to the memory power state request data.

         @if OEM_only For rscId = MMPM_RSC_ID_MEM_POWER in MMPM_Request_Ext().
         @endif
         @if apps_only For rscId = MMPM_RSC_ID_MEM_POWER in MMPM_Request().
         @endif */

    /* For MMPM_Release(). */
    MmpmClkIdArrayParamType     *pRelClkIdArray;
    /**< Pointer to the clock ID array.

         @if OEM_only For rscId = MMPM_RSC_ID_CORE_CLK and
         MMPM_RSC_ID_CORE_CLK_DOMAIN  in MMPM_Release_Ext(). @endif
         @if apps_only For rscId = MMPM_RSC_ID_CORE_CLK and
         MMPM_RSC_ID_CORE_CLK_DOMAIN  in MMPM_Release(). @endif */

    /* For MMPM_Pause()/MMPM_Resume(). */
    /** @cond apps_only */
    MmpmCoreClkIdType           gateClkId;
    /**< Clock ID in MMPM_Pause() or MMPM_Resume().

         This is defined by enumerations of MmpmClkId<Xyz>Type, where Xyz is 
         the core name. For example, MmpmClkId2dGrpType. */
    /** @endcond */

}MmpmRscParamStructType;


/**
  @if OEM_only Resource parameter for MMPM_Request_Ext() and MMPM_Release_Ext().
  @endif
  @if apps_only Resource parameter for MMPM_Request(), MMPM_Release(),
  MMPM_Pause(), and MMPM_Resume(). @endif
*/
typedef struct {
    MmpmRscIdType               rscId;
    /**< ID of the resource to request.

         @values See #MmpmRscIdType */

    MmpmRscParamStructType      rscParam;
    /**< Parameter data structure that matches rscId. */
} MmpmRscParamType;


/******************************************************************************************/
/*                                                                                        */
/*                    MMPM_Request_Ext()/MMPM_Release_Ext()/                              */
/*                    MMPM_Pause_Ext()/MMPM_Resume_Ext() Data Structures                  */
/*                                                                                        */
/******************************************************************************************/

/**
  Valid parameters for API calls.
*/
typedef enum{
     MMPM_API_TYPE_NONE,      /**< No parameter. */
     MMPM_API_TYPE_SYNC,      /**< Synchronous API call. */
     MMPM_API_TYPE_ASYNC,     /**< Asynchronous API call. */
     MMPM_API_TYPE_ENUM_MAX,  /**< Enumeration maximum. */
     MMPM_API_TYPE_FORCE32BITS = 0x7FFFFFFF
                             /**< Forces the enumeration to 32 bits.
                                  @if OEM_only @newpage @endif*/
} MmpmApiType;

/**
  Resource parameter for MMPM_Request_Ext() and MMPM_Release_Ext().
*/
typedef struct {
    MmpmApiType                 apiType;
    /**< Function call type.

         @values See #MmpmApiType */

    uint32                      numOfReq;
    /**< Total number of requests. The maximum is 8. */

    MmpmRscParamType            *pReqArray;
    /**< Pointer to the request array. */

    MMPM_STATUS                 *pStsArray;
    /**< Pointer to the return status array. */

    uint32                      reqTag;
    /**< Request tag for the asynchronous callback; only used for an 
         asynchronous apiType. */
    void                        *pExt;
    /**< Reserved for future expansion of the API.
         @if apps_only @newpagetable @endif */
} MmpmRscExtParamType;


/******************************************************************************************/
/*                                                                                        */
/*                          MMPM_GetInfo() Data Structures                                */
/*                                                                                        */
/******************************************************************************************/
/**
  Valid MMPM information IDs.
*/
typedef enum {
    MMPM_INFO_ID_NONE,
    /**< No ID. */

/** @cond apps_only */
    MMPM_INFO_ID_CORE_CLK,
    /**< Core clock frequency. */
/** @endcond */

    MMPM_INFO_ID_CORE_CLK_MAX,
    /**< Maximum core clock frequency for the core. */

/** @cond apps_only */
    MMPM_INFO_ID_CORE_CLK_MAX_SVS,
    /**< Maximum core clock frequency for the core's SVS mode. This is zero 
         if the core does not have SVS mode. */
    MMPM_INFO_ID_CORE_CLK_MAX_NOMINAL,
    /**< Maximum core clock frequency for the core's Nominal mode. This is 
         zero if the core does not have NOMINAL mode. */
    MMPM_INFO_ID_CORE_CLK_MAX_TURBO,
    /**< Maximum core clock frequency for the core's Turbo mode. This is zero 
         if the core does not have Turbo mode. */
/** @endcond */

    MMPM_INFO_ID_MIPS_MAX,
    /**< Maximum/minimum MIPS for the core; supported for the aDSP only. */
    MMPM_INFO_ID_BW_MAX,
    /**< Maximum/minimum bandwidth; supported for the LPASS only. */

/** @cond apps_only */
    MMPM_INFO_ID_CRASH_DUMP,
    /**< Crash dump. */
    MMPM_INFO_ID_POWER_SUPPORT,
    /**< Information on whether a block supports GDHS. */
/** @endcond */

    MMPM_INFO_ID_CLK_FREQ,
    /**< Measures a clock frequency. */

/** @cond apps_only */
    MMPM_INFO_ID_PERFMON,
    /**< Controls the performance monitor. */
    MMPM_INFO_ID_PMIC_GPIO,
    /**< Returns the PMIC GPIO status. */
    MMPM_INFO_ID_SET_DEBUG_LEVEL,
    /**< Sets the debug level for MMPM2. */
    MMPM_INFO_ID_MMSS_BUS,
    /**< MMSS FABRIC bus status. */
    MMPM_INFO_ID_LPASS_BUS,
    /**< LPASS FABRIC bus status. */
/** @endcond */

    MMPM_INFO_ID_AGGREGATE_CLIENT_CLASS,
    /**< Aggregate class of active clients. */
    MMPM_INFO_ID_MPPS,
    /**< Aggregated MPPS (millions of packets per second) request. */
    MMPM_INFO_ID_BW_EXT,
    /**< Aggregated BW requested using MMPM_RSC_ID_GENERIC_BW_EXT. */
    MMPM_INFO_ID_DCVS_STATE,
    /**< DCVS enable/disable state. */

    MMPM_INFO_ID_EXT_REQ,
    /**< Extended Info; supported for the LPASS only. */

    MMPM_INFO_ID_MAX,
    /**< Maximum count. */
    MMPM_INFO_ID_FORCE32BITS = 0x7FFFFFFF
    /**< Forces the enumeration to 32 bits. @if apps_only @newpage @endif */
} MmpmInfoIdType;

/** @cond apps_only */
/**
    Client gets the current clock frequency.
    InfoId = MMPM_INFO_ID_CORE_CLK.
*/
typedef struct {
    MmpmCoreClkIdType           clkId;
    /**< Input: core clock IDs. */ /* defined by MmpmClkIdType enums of mmpm2_platformclocks.h */
    uint32                      clkFreqHz;
    /**< Output: clock frequency in Hertz. @if OEM_only @newpagetable @endif */
} MmpmInfoClkType;
/** @endcond */
/** @} */ /* end_addtogroup mmpm_datatypes */

/** @ingroup mmpm_constants_macros
  Maximum clock name length.
*/
#define MMPM_MAX_CLOCK_NAME 64

/** @ingroup mmpm_datatypes
  Clock frequency information.
*/
typedef struct {
    uint32                      clkId;
    /**< Input field: core clock IDs. */ /* defined by MmpmClkIdType enums of mmpm2_platformclocks.h */
    uint32                      clkFreqHz;
    /**< Output field: clock frequency in Hertz. */
    uint32                      forceMeasure;
    /**< Input field: forces the clock to be measured.

         The clock frequency may be read from a cached table if this is not set
         to 1. @if OEM_only @newpagetable @endif */
} MmpmInfoClkFreqType;

typedef struct
{
    uint32                      clientClasses;
    /**< Input field: specifies the client classes to be included in the
         aggregated MPPS query, using the bitwise-OR of values from
         #MmpmClientClassType. */
    uint32                      aggregateMpps;
    /**< Output field: the aggregated MPPS value. */
    
} MmpmInfoMppsType;

typedef struct
{
    MmpmBusRouteType            busRoute;
    /**< Input field: specifies the bus route for which the BW query applies. */
    uint64                      totalBw;
    /**< Output field: the total BW requested for the specified bus route, in
         bytes per second. */
} MmpmInfoBwExtType;

/********************************************************************************
*                        MMPM PERFMON                                           *
********************************************************************************/
/** @addtogroup mmpm_constants_macros
@{ */
/** @name MMPM performance monitor parameters
@{ */
/** Measure the type read burst. */
#define READ_BURSTS_MMPM        0
/** Measure the type write burst. */
#define WRITE_BURSTS_MMPM       1
/** Measure the type read transfers. */
#define READ_TRANSFERS_MMPM     3
/** Measure the type write transfers. */
#define WRITE_TRANSFERS_MMPM    4
/** Three columns reserved for time stamp sec, ns, and latency fields. */
#define NR_PERFMON2_PARAM       3
/** Maximum number of clocks to measure. */
#define NR_REC_CLOCK            10
/** Maximum number of ports to measure. */
#define NR_PORTS                7
/** Total size of the line to write to the log file. */
#define NR_RECORDED_VALUES2     (NR_PERFMON2_PARAM + NR_REC_CLOCK + NR_PORTS)
/** Maximum filename size, including path. */
#define MAX_PATH_LENGTH         64
/** @} */ /* end_name_group MMPM performance monitor parameters */
/** @} */ /* end_addtogroup mmpm_constants_macros */

/** @addtogroup mmpm_datatypes
@{ */
/** @cond apps_only */
/**
  MMPM performance monitor information.
*/
typedef struct {
    uint32                      masterMeasureArray[NR_PORTS];
    /**< List of ports to measure. The first port in the list is used as the 
         trigger point. */
    uint32                      measurementConfig[NR_PORTS];
    /**< Type of measurement: read = 3, write = 4, read burst = 0, and 
         write burst = 1. */
    uint32                      latencyMasterPort;
    /**< Master port on which to measure the latency. */
    uint32                      holdoffTime;
    /**< Time to wait before taking the measurement. */
    uint32                      triggerMode;
    /**< Oneshot or continuous.  Oneshot only fills the ulog buffer once and 
         stops. Continuous runs forever until another measurement is started. */
    void                        *pDataMsg;
    /**< For future expansion of the API. */
    char                        pFilename[MAX_PATH_LENGTH];
    /**< Log filename. */
    uint32                      axiClockFreq;
    /**< Specified frequency at which FABRIC will be running during the 
         performance measurement. */
    uint32                      clockInfo[NR_REC_CLOCK];
    /**< Array that contains the clock IDs of all the clocks to be measured. */
    /* clock id values are defined by MmpmClkIdType enums of mmpm2_platformclocks.h. */
    uint32                      isClockFreqCalc[NR_REC_CLOCK];
    /**< Array that contains the parameter to check if the user wants to 
         calculate the clock or get the clock frequency using a clock 
         measurement circuit. @if OEM_only @newpagetable @endif */
} MmpmInfoPerfmonType;

/**
  PMIC GPIO status.
*/
typedef struct {
    uint32                      gpioModeSelect;
    /**< Mode selection. */
    uint32                      gpioVoltageSource;
    /**< Voltage source. */
    uint32                      gpioModeOnOff;
    /**< Mode selection is enabled or disabled. */
    uint32                      gpioOutBufferConfig;
    /**< Output buffer configuration. */
    uint32                      gpioOutBufferDriveStrength;
    /**< Output buffer drive strength. */
    uint32                      gpioCurrentSourcePulls;
    /**< Current source pulls. */
    uint32                      gpioSourceConfig;
    /**< GPIO source configuration. */
    uint32                      gpioDtestBufferOnOff;
    /**< Dtest buffer configuration. */
    uint32                      gpioExtPinConfig;
    /**< OEM_only pin configuration. */
} MmpmPmicGpioStatusType;

/**
  Client gets the returned PMIC GPIO status. \n
  InfoId = MMPM_INFO_ID_PMIC_GPIO.
*/
typedef struct {
    uint32                      gpioId;  /**< PMIC GPIO to be configured. */
    MmpmPmicGpioStatusType      gpioSts; /**< GPIO status.
                                         @if OEM_only @newpagetable @endif */
} MmpmPmicGpioInfoType;

/** @endcond */
/** @} */ /* end_addtogroup mmpm_datatypes */


/** @addtogroup mmpm_constants_macros
@{ */
/** @name Bus statuses
@vertspace{-6} The client gets the corresponding bus status.
@{ */

/** Maximum number of active master/slave pairs. */
#define MAX_ACT_MASTER_SLAVE    16
/** Maximum number of clients for each master/slave pair. */
#define MAX_ACT_CLIENT          16
/** @} */ /* end_name_group Corresponding bus status */
/** @} */ /* end_addtogroup mmpm_constants_macros */

/** @addtogroup mmpm_datatypes
@{ */
/** @cond apps_only */
/**
  Bandwidth client.
*/
typedef struct {
    uint32                      clientId;
    /**< MMPM client ID. */
    char                        clientName[MAX_CLIENT_NAME];
    /**< MMPM client name. */
    char                        fabClientName[MAX_CLIENT_NAME];
    /**< FABRIC node client name. */
    uint32                      uIbBytePerSec;
    /**< FABRIC node client's total Ib, in bytes per second, requested on a 
         master/slave pair. */
    uint32                      uAbBytePerSec;
    /**< FABRIC node client's total Ab, in bytes per second, requested on a 
         master/slave pair. */
} MmpmBwClientType;

/**
  Master/slave information.
*/
typedef struct {
    uint32                      coreId;
    /**< Master information: core ID. */
    uint32                      instanceId;
    /**< Master information: instance ID. */
    uint32                      axiPort;
    /**< Master information: AXI port. */
    uint32                      slaveId;
    /**< Slave information: slave ID. */
    uint32                      uIbBytePerSec;
    /**< Bandwidth: total Ib, in bytes per second, requested from all FABRIC 
         node clients on this master/slave. */
    uint32                      uAbBytePerSec;
    /**< Bandwidth: total Ab, in bytes per second, requested from all FABRIC 
         node clients on this master/slave. */
    uint32                      numOfClients;
    /**< Number of bandwidth clients on the same master/slave. */
    MmpmBwClientType            client[MAX_ACT_CLIENT];
    /**< Bandwidth clients' array. @if OEM_only @newpagetable @endif */
} MmpmMasterSlaveType;

/**
  FABRIC status information.
*/
typedef struct {
    uint32                      mmFabClkFreq;
    /**< Multimedia Subsystem (MMSS) FABRIC clock frequency. */
    uint32                      appsFabClkFreq;
    /**< Apps FABRIC clock frequency. */
    uint32                      sysFabClkFreq;
    /**< System FABRIC clock frequency. */
    uint32                      lpassFabClkFreq;
    /**< LPASS FABRIC clock frequency. */
    uint32                      ebiClkFreq;
    /**< EBI memory clock frequency. */
    uint32                      mmImemClkFreq;
    /**< MMSS IMEM memory clock frequency. */
    uint32                      numOfMasterSlave;
    /**< Number of master/slave pairs. */
    MmpmMasterSlaveType         masterSlave[MAX_ACT_MASTER_SLAVE];
    /**< Active master/slave array. */
} MmpmFabStatusInfoType;

/** @endcond */

/**
  Information data structure.
*/
typedef union {
/** @cond apps_only */
    MmpmInfoClkType             *pInfoClk;
    /**< Information data structure for InfoId = MMPM_INFO_ID_CORE_CLK and 
         MMPM_INFO_ID_CORE_CLK_MAX_SVS, _MAX_NOMINAL, and _MAX_TURBO. */
/** @endcond */

    boolean                     bInfoPower;
    /**< TRUE if a core has support for GDHS; otherwise, FALSE. */

/** @cond apps_only */
    MmpmInfoPerfmonType         *pInfoPerfmon;
    /**< Information data structure for InfoId = MMPM_INFO_ID_PERFMON. This is 
         used to trigger a memory bandwidth measurement. */
/** @endcond */

    MmpmInfoClkFreqType         *pInfoClkFreqType;
    /**< Pointer to the information data structure for
         InfoId = MMPM_INFO_ID_CLK_FREQ. This is used to get the clock
         frequency or measure the clock frequency. */

/** @cond apps_only */
    MmpmPmicGpioInfoType        *pPmicGpioStatus;
    /**< PMIC GPIO status. */
    uint32                      infoSetLotLevel;
    /**< Sets the MMPM2 debug level; debug level range: 0 to 0xf. */
    MmpmFabStatusInfoType       *pFabStatus;
    /**< FABRIC status. */
/** @endcond */

    uint32                      mipsValue;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_MIPS_MAX.

         The aDSP uses this to get the maximum MIPS. */

    uint64                      bwValue;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_BW_MAX.

         The LPASS uses this to get the maximum bandwidth. */

    uint32                      aggregateClientClass;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_AGGREGATE_CLIENT_CLASS.

         The aggregate class of active clients is returned in this value.
         Its value is set by the bitwise-OR of values from #MmpmClientClassType
         corresponding to the active classes. */

    MmpmInfoMppsType            *pMppsInfo;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_MPPS. */

    MmpmInfoBwExtType           *pBwExtInfo;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_BW_EXT. */

    boolean                     dcvsState;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_DCVS_STATE.

         This value returns the current overall enable/disable state of the
         DCVS (dynamic current and voltage scaling) module. */


    void                        *pExtInfo;
    /**< Information data structure if MmpmInfoDataType
         infoId = #MMPM_INFO_ID_EXT_REQ.

         The LPASS uses this to get the Generic Extended Info. */

} MmpmInfoDataStructType;


/**
  MMPM information data structure definition.
*/
typedef struct {
    MmpmInfoIdType              infoId;
    /**< ID of the information type.

         @values
         - #MMPM_INFO_ID_CLK_FREQ
         - #MMPM_INFO_ID_CORE_CLK_MAX
         - #MMPM_INFO_ID_MIPS_MAX
         - #MMPM_INFO_ID_BW_MAX
         - #MMPM_INFO_ID_AGGREGATE_CLIENT_CLASS
         - #MMPM_INFO_ID_MPPS
         - #MMPM_INFO_ID_BW_EXT
         - #MMPM_INFO_ID_DCVS_STATE
         - #MMPM_INFO_ID_EXT_REQ
         @tablebulletend */

    MmpmCoreIdType              coreId;
    /**< ID of the hardware core.

         @values See #MmpmCoreIdType */

    MmpmCoreInstanceIdType      instanceId;
    /**< ID of the instance of the same hardware core, e.g., the first instance 
         of the two Graphics2D cores.

              @values See #MmpmCoreInstanceIdType */

    MmpmInfoDataStructType      info;
    /**< Information data structure that contains the output information.
         @if OEM_only @newpagetable @endif */
} MmpmInfoDataType;



/*   MMPM Parameter Configuration  */

/**
  Valid memory parameters.
*/
typedef enum{
    MMPM_PARAM_ID_NONE = 0,
    /**< Invalid parameter. */

/** @cond apps_only */
    MMPM_PARAM_ID_RESOURCE_LIMIT,
    /**< Sets the resource limits (minimum and maximum). This works globally. */
/** @endcond */

    MMPM_PARAM_ID_CLIENT_OCMEM_MAP,
    /**< Sets the client's on-chip memory allocation map. */
    MMPM_PARAM_ID_MEMORY_MAP,
    /**< Sets memory address mapping for the specified memory. */
    MMPM_PARAM_ID_CLIENT_CLASS,
    /**< Sets the client's use case class. */
    MMPM_PARAM_ID_L2_CACHE_LINE_LOCK,
    /**< Sets the client's L2 cache line locking parameters. */
    MMPM_PARAM_ID_DCVS_PARTICIPATION,
    /**< Sets the client's DCVS participation. */
    MMPM_PARAM_ID_ENUM_MAX,
    /**< Enumeration maximum. */
    MMPM_PARAM_ID_Force32bit = 0x7fffffff
    /**< Forces the enumeration to 32 bits. @newpage */
} MmpmParameterIdType;


/**
  Memory address mapping parameter.
*/
typedef struct
{
    MmpmMemIdType memory;   /**< Memory type identifier. */
    uint64  startAddress;   /**< Virtual address of the start of the memory
                                 range. */
    uint32  size;           /**< Size of the memory range in bytes. */
} MmpmMemoryMapType;

/**
  L2 cache line locking parameter.
  Line locking is enabled by setting the startAddress and size fields to
  non-zero values.  Setting either the startAddress or size field to zero
  unlocks the previously activated line locking.
*/
typedef struct
{
    void* startAddress;         /**< Start address of the memory region to be
                                     locked */
    uint32 size;                /**< Size (bytes) of the memory region to be
                                     locked. */
    // Throttling parameters; applicable only when enabling line locking.
    uint32 throttleBlockSize;   /**< Block size for throttling, in bytes;
                                     0 for no throttling.  The region to be
                                     locked will be divided into blocks of this
                                     size for throttling purposes. */
    uint32 throttlePauseUs;     /**< Pause to be applied between locking each
                                     block, in microseconds. */

} MmpmL2CacheLineLockParameterType;

// Client use case class
typedef enum
{
    MMPM_UNKNOWN_CLIENT_CLASS        = 0x00, /**< Unknown client class */
    MMPM_AUDIO_CLIENT_CLASS          = 0x01, /**< Audio client class */
    MMPM_VOICE_CLIENT_CLASS          = 0x02, /**< Voice client class */
    MMPM_COMPUTE_CLIENT_CLASS        = 0x04, /**< Compute client class */
    MMPM_STREAMING_1HVX_CLIENT_CLASS = 0x08, /**< Camera streaming with 1 HVX
                                                  client class */
    MMPM_STREAMING_2HVX_CLIENT_CLASS = 0x10, /**< Camera streaming with 2 HVX
                                                  client class */
    MMPM_MAX_CLIENT_CLASS,
} MmpmClientClassType;

// Client's DCVS adjustment types.
// This is applicable when a client has enabled its participation in DCVS.
typedef enum
{
    MMPM_DCVS_ADJUST_UP_DOWN,  /**< Allows for DCVS to adjust up and down. */
    MMPM_DCVS_ADJUST_ONLY_UP   /**< Allows for DCVS to adjust up only. */
} MmpmDcvsEnableOptionsType;

// Client's DCVS participation options
typedef struct
{
    boolean enable;                       /**< Set to true to enable client's
                                               participation in DCVS. */
    MmpmDcvsEnableOptionsType enableOpt;  /**< Client's adjustment options;
                                               applicable when participation
                                               is enabled. */
} MmpmDcvsParticipationType;

/**
  Valid configuration parameter.
*/
typedef struct{
    MmpmParameterIdType paramId;
    /**< Parameter ID.

         @values See #MmpmParameterIdType */

    void*               pParamConfig;
    /**< Pointer to a parameter-specific structure.

         - If paramId is #MMPM_PARAM_ID_CLIENT_OCMEM_MAP -- pParamConfig points
           to the #MmpmOcmemMapType structure.
         - If paramId is #MMPM_PARAM_ID_CLIENT_CLASS -- pParamConfig points to
           the #MmpmClientClassType type.
         - If paramId is #MMPM_PARAM_ID_L2_CACHE_LINE_LOCK -- pParamConfig
           points to the #MmpmL2CacheLineLockParameterType type.
         - If paramId is #MMPM_PARAM_ID_DCVS_PARTICIPATION -- pParamConfig points
           to the #MmpmDcvsParticipationType type.
         - If paramId is #MMPM_PARAM_ID_MEMORY_MAP -- pParamConfig points to
           the #MmpmMemoryMapType structure. @tablebulletend */
} MmpmParameterConfigType;

/**
  OCMEM region description.
*/
typedef struct{
    uint32 regionId;
    /**< Region ID. */
    uint32 numKeys;
    /**< Number of macros in the region used by the allocation. */
    uint32 *pKey;
    /**< Pointer to the array listing the allocated macros. */
} MmpmOcmemMapRegionDescType;

/**
  OCMEM mapping type.
*/
typedef struct{
    uint32 numRegions;
    /**< Number of regions in the allocation. */
    MmpmOcmemMapRegionDescType *pRegions;
    /**< Pointer to an array with all regions for the allocation.
         @if OEM_only @newpagetable @endif */
} MmpmOcmemMapType;
/** @} */ /* end_addtogroup mmpm_datatypes */

/*======================================================================
   FUNCTION: MMPM_Init
======================================================================*/
/** @ingroup mmpm_func_init
  Initializes all MMPM components and registers all MMPM nodes.

  @param[in] cmd_line String containing one of the following:
                      - Initialization command line parameters 
                      - NULL @tablebulletend

  @detdesc
  This function is to be called only once at system runtime. It is typically 
  called by the operating system during system bootup.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  This function has multiple dependencies, such as clock driver, node power
  architecture, bus driver, and sleep.
  @par
  All dependencies are handled by the initialization framework and are not
  apparent to customers using the ADSPPM API.

@callgraph
@callergraph
*/
uint32 MMPM_Init(char * cmd_line);

/*======================================================================
   FUNCTION: MMPM_Register_Ext
======================================================================*/
/** @ingroup mmpm_func_register_ext
  Registers a new client for a specified hardware block.

  @datatypes
  MmpmRegParamType

  @param[in] pRegParam Pointer to the registration parameter.

  @detdesc
  This function must be called before calling MMPM_Request_Ext(), 
  MMPM_Release_Ext(), and MMPM_SetParameter() because the returned client ID 
  from %MMPM_Register_Ext() is required as input to these function calls.
  @par
  The MMPM_GetInfo() call might not require registration with the ADSPPM.
  @par
  Whether a client ID is required depends on the type of information 
  requested.

  @return
  Unique client ID -- On success.
  @par
  0 -- On failure.

  @dependencies
  None.

  @callgraph
  @callergraph
*/
uint32          MMPM_Register_Ext(MmpmRegParamType  *pRegParam);

/*======================================================================
   FUNCTION: MMPM_Deregister_Ext
======================================================================*/
/** @ingroup mmpm_func_deregister_ext
  Deregisters access to the device.

  @param[in] clientId Registered client ID.

  @detdesc
  All use cases associated with the device are removed, and its requested 
  resources are released.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  None.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Deregister_Ext(uint32          clientId);

/*======================================================================
   FUNCTION: MMPM_Request
======================================================================*/
/** @ingroup mmpm_func_request
  Requests resources for a hardware core via a pre-registered client ID.

  @datatypes
  MmpmRscParamType

  @param[in] clientId      Registered client ID.
  @param[in] pMmpmRscParam Pointer to the resource parameter.

  @detdesc
  Resources include all those defined by #MmpmRscIdType, which is specified in
  %MmpmRscParamType.
  @par
  If multiple requests are from the same registered client ID, the MMPM
  performs an update, i.e., the latest request to the resource replaces the 
  previous requests.
  @par
  If multiple requests are from different registered client IDs and they are 
  all making requests to the same resource, the MMPM's behavior for subsequent 
  requests is:
  - ``max'' for MMPM_RSC_IDs of: @vertspace{-4}
      - VREG @vertspace{-3}
      - CORE_CLK -- Sets the frequency (for corresponding clock IDs)
  - ``min'' for MMPM_RSC_IDs of SLEEP_LATENCY @vertspace{-3}
  - ``aggregate'' for MMPM_RSC_IDs of MEM_BW and MIPS @vertspace{-3}
  - ``voting'' for MMPM_RSC_IDs of: @vertspace{-4}
      - POWER @vertspace{-3}
      - CORE_CLK -- Enables (for corresponding clock IDs) @vertspace{-3}
      - ACTIVE_STATE
  - ``reject'' for MMPM_RSC_IDs of: @vertspace{-4}
      - CORE_CLK -- Sets the source (for corresponding clock IDs) @vertspace{-3}
      - CORE_CLK_DOMAIN (for corresponding clock IDs) because the clock 
        is in use @vertspace{-3}

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).@vertspace{-4}

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Request(uint32             clientId,
                             MmpmRscParamType   *pMmpmRscParam);

/*======================================================================
   FUNCTION: MMPM_Release
======================================================================*/
/** @ingroup mmpm_func_release
  Releases resources for a hardware core via a pre-registered client ID.

  @datatypes
  MmpmRscParamType

  @param[in] clientId      Registered client ID.
  @param[in] pMmpmRscParam Pointer to the resource parameter.

  @detdesc
  Resources include all those defined by #MmpmRscIdType, which is specified in
  the %MmpmRscParamType structure.
  @par
  All resources under the same resource ID are released for the registered
  client.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Release(uint32             clientId,
                             MmpmRscParamType   *pMmpmRscParam);

/*======================================================================
   FUNCTION: MMPM_Pause
======================================================================*/
/** @ingroup mmpm_func_pause
  Gates the resources of a hardware core via a pre-registered client ID.

  @datatypes
  MmpmRscParamType

  @param[in] clientId      Registered client ID.
  @param[in] pMmpmRscParam Pointer to the resource parameter.

  @detdesc
  This function supports only core clock and voltage regulation resources.
  @par
  If multiple requests are from the same registered client ID, MMPM 
  performs an update, i.e., the latest request to the resource replaces 
  the previous ones.
  @par
  If multiple requests are from different registered client IDs, and they 
  are all making the same resource gate to the same hardware core instance 
  (same core ID + same core instance ID), MMPM's behavior is the first 
  ungate to ungate the resource and the last gate to gate the resource.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Pause(uint32               clientId,
                           MmpmRscParamType     *pMmpmRscParam);

/*======================================================================
   FUNCTION: MMPM_Resume
======================================================================*/
/** @ingroup mmpm_func_resume
  Ungates the resources of a hardware core via a pre-registered client ID.

  @datatypes
  MmpmRscParamType

  @param[in] clientId      Registered client ID.
  @param[in] pMmpmRscParam Pointer to the resource parameter.

  @detdesc
  This function supports only core clock and voltage regulation resources.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Resume(uint32              clientId,
                            MmpmRscParamType    *pMmpmRscParam);

/*======================================================================
   FUNCTION: MMPM_Request_Ext
======================================================================*/
/** @ingroup mmpm_func_request_ext
  Requests resources for a hardware core via a pre-registered client ID. 
  The function allows requests for several resources in a single call.

  @datatypes
  MmpmRscExtParamType

  @param[in] clientId     Registered client ID.
  @param[in] pRscExtParam Pointer to the resource parameter.

  @detdesc
  Resources are defined in #MmpmRscIdType, which is specified in the
  %MmpmRscExtParamType structure.
  @par
  If multiple requests are from the same registered client ID, MMPM performs 
  an update, i.e., the latest request to the resource replaces the 
  previous ones.
  @par
  If multiple requests are from different registered client IDs, and they are 
  all making requests to the same resource, MMPM's behavior for subsequent 
  requests is:
  - ``max'' for MMPM_RSC_IDs of:
      - VREG
      - CORE_CLK -- Sets the frequency (for corresponding clock IDs
  - ``min'' for MMPM_RSC_IDs of SLEEP_LATENCY
  - ``aggregate'' for MMPM_RSC_IDs of MEM_BW and MIPS
  - ``voting'' for MMPM_RSC_IDs of:
      - POWER
      - CORE_CLK -- Enables (for corresponding clock IDs)
      - ACTIVE_STATE
  - ``reject'' for MMPM_RSC_IDs of:
      - CORE_CLK -- Sets the source (for corresponding clock IDs)
      - CORE_CLK_DOMAIN (for corresponding clock IDs) because the clock 
        is in use
  @par
  This function also allows selection of an asynchronous (non-blocking) 
  execution. If an asynchronous execution is requested, the function 
  returns immediately after storing the request parameters. The requests 
  are then processed in the background and the callback function specified 
  by the client during registration is called when all requests in the 
  bundle are processed.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Request_Ext(uint32 clientId,
                                 MmpmRscExtParamType *pRscExtParam);

/*======================================================================
   FUNCTION: MMPM_Release_Ext
======================================================================*/
/** @ingroup mmpm_func_release_ext
  Releases resources for a hardware core via a pre-registered client ID.

  @datatypes
  MmpmRscExtParamType

  @param[in] clientId     Registered client ID.
  @param[in] pRscExtParam Pointer to the resource parameter.

  @detdesc
  Resources are defined by #MmpmRscIdType, which is specified in the
  %MmpmRscExtParamType structure.
  @par
  All resources under the same resource ID are released for the registered
  client.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Release_Ext(uint32 clientId,
                                 MmpmRscExtParamType *pRscExtParam);

/*======================================================================
   FUNCTION: MMPM_Pause_Ext
======================================================================*/
/** @ingroup mmpm_func_pause_ext
  Makes multiple pause calls within one call.

  @datatypes
  MmpmRscExtParamType

  @param[in] clientId     Registered client ID.
  @param[in] pRscExtParam Pointer to the resource parameter.

  @detdesc
  Multiple pause calls are executed, and the function call ends when all 
  pause calls complete execution.
  @par
  When each pause call is executed, its behavior is identical to that of
  MMPM_Pause().
  @par
  For the individual return status of each pause call, the client must parse 
  pStsArray in the pRscExtParam parameter.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Pause_Ext(uint32 clientId,
                               MmpmRscExtParamType *pRscExtParam);

/*======================================================================
   FUNCTION: MMPM_Resume_Ext
======================================================================*/
/** @ingroup mmpm_func_resume_ext
  Makes multiple resume calls within one call.

  @datatypes
  MmpmRscExtParamType

  @param[in] clientId     Registered client ID.
  @param[in] pRscExtParam Pointer to the resource parameter.

  @detdesc
  Multiple resume calls are executed, and the function call ends when all 
  resume calls complete execution.
  @par
  When each resume call is executed, its behavior is identical to that of
  MMPM_Resume().
  @par
  For the individual return status of each resume call, the client must parse 
  pStsArray in the pRscExtParam parameter.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_Resume_Ext(uint32 clientId,
                                MmpmRscExtParamType *pRscExtParam);

/*======================================================================
   FUNCTION: MMPM_GetInfo
======================================================================*/
/** @ingroup mmpm_func_get_info
  Retrieves MMPM resource information.

  @datatypes
  MmpmInfoDataType

  @param[in] pInfoData Pointer to the resource information.

  @detdesc
  This function does not require pre-registration.
  @par
  Based on the information ID specified in %MmpmInfoDataType, 
  the MMPM returns the requested information for the ADSPPM resources.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM must be initialized before calling this function.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_GetInfo(MmpmInfoDataType   *pInfoData);

/*======================================================================
   FUNCTION: MMPM_SetParameter
======================================================================*/
/** @ingroup mmpm_func_set_parameter
  Sets various client-specific and global parameters.

  @note1hang Currently, this function only supports setting the client OCMEM
             allocation memory map.

  @datatypes
  MmpmParameterConfigType

  @param[in] clientId     Client ID.
  @param[in] pParamConfig Pointer to the configuration parameter.

  @return
  #MMPM_STATUS_SUCCESS -- On success.
  @par
  Error code -- On failure (see #MmpmStatusType).

  @dependencies
  MMPM_Register_Ext() must have been called.

  @callgraph
  @callergraph
*/
MMPM_STATUS     MMPM_SetParameter(uint32 clientId, MmpmParameterConfigType *pParamConfig);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif /* MMPM_H */

