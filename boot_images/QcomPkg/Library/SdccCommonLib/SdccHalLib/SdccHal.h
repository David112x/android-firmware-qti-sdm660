#ifndef __HALSDCC_H__
#define __HALSDCC_H__

/** @file HALsdcc.h
   
  Public interface declaration for the SDCC HAL 
  
  Copyright (c) 2014 - 2016, Qualcomm Technologies, Inc.
  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential
   
**/

/*=============================================================================
                              EDIT HISTORY

when         who     what, where, why
----------   ---     --------------------------------------------------- 
2016-08-04   sb      Remove legacy mode 
2016-01-18   eo      Reduced sdcc code size
2015-11-19   jt      Added HAL_sdcc_HandlePowerInterrupts()
2015-07-15   bn      Added SDHCi Flow Control
2015-03-30   bn      Fixed sSDHCADMADescriptor for 64-bit mode
2015-03-09   bn      Fixed Caps1's Bits[24:31] being overwritten
2015-02-27   rm      Added HAL_sdhci_DLLClockEnable
2015-01-26   rm      Integraged HS200/HS400 support for eMMC from UEFI 3.0
2014-09-24   bn      Added HAL_sdhci_SetCapabilities()
2014-06-18   bn      Initial version. Branched from 8994 UEFI
 
=============================================================================*/


//offsets for SDHC registers
#define HAL_SDHCI_REG_0_2_OFFSET                           (0x00000000)
#define HAL_SDHCI_REG_4_6_OFFSET                           (0x00000004)
#define HAL_SDHCI_REG_8_A_OFFSET                           (0x00000008)
#define HAL_SDHCI_REG_C_E_OFFSET                           (0x0000000c)
#define HAL_SDHCI_REG_10_12_OFFSET                         (0x00000010)
#define HAL_SDHCI_REG_14_16_OFFSET                         (0x00000014)
#define HAL_SDHCI_REG_18_1A_OFFSET                         (0x00000018)
#define HAL_SDHCI_REG_1C_1E_OFFSET                         (0x0000001c)
#define HAL_SDHCI_REG_20_22_OFFSET                         (0x00000020)
#define HAL_SDHCI_REG_24_26_OFFSET                         (0x00000024)
#define HAL_SDHCI_REG_28_2A_OFFSET                         (0x00000028)
#define HAL_SDHCI_REG_28_OFFSET                            (0x00000028)
#define HAL_SDHCI_REG_29_OFFSET                            (0x00000029)
#define HAL_SDHCI_REG_2C_2E_OFFSET                         (0x0000002c)
#define HAL_SDHCI_REG_2C_OFFSET                            (0x0000002c)
#define HAL_SDHCI_REG_2E_OFFSET                            (0x0000002e)
#define HAL_SDHCI_REG_2F_OFFSET                            (0x0000002f)
#define HAL_SDHCI_REG_30_32_OFFSET                         (0x00000030)
#define HAL_SDHCI_REG_34_36_OFFSET                         (0x00000034)
#define HAL_SDHCI_REG_38_3A_OFFSET                         (0x00000038)
#define HAL_SDHCI_REG_3C_3E_OFFSET                         (0x0000003c)
#define HAL_SDHCI_REG_3E_OFFSET                            (0x0000003E)
#define HAL_SDHCI_REG_40_42_OFFSET                         (0x00000040)
#define HAL_SDHCI_REG_44_46_OFFSET                         (0x00000044)
#define HAL_SDHCI_REG_48_4A_OFFSET                         (0x00000048)
#define HAL_SDHCI_REG_50_52_OFFSET                         (0x00000050)
#define HAL_SDHCI_REG_54_56_OFFSET                         (0x00000054)
#define HAL_SDHCI_REG_58_5A_OFFSET                         (0x00000058)
#define HAL_SDHCI_REG_5C_5E_OFFSET                         (0x0000005c)
#define HAL_SDHCI_REG_60_62_OFFSET                         (0x00000060)
#define HAL_SDHCI_REG_64_66_OFFSET                         (0x00000064)
#define HAL_SDHCI_REG_68_6A_OFFSET                         (0x00000068)
#define HAL_SDHCI_REG_6C_6E_OFFSET                         (0x0000006c)
#define HAL_SDHCI_REG_E0_E2_OFFSET                         (0x000000e0)
#define HAL_SDHCI_REG_FC_FE_OFFSET                         (0x000000fc)
#define HAL_SDHCI_REG_DLL_CONFIG_OFFSET                    (0x00000200)
#define HAL_SDHCI_REG_DLL_TEST_CTL_OFFSET                  (0x00000204)
#define HAL_SDHCI_REG_DLL_STATUS_OFFSET                    (0x00000208)
#define HAL_SDHCI_VENDOR_SPECIFIC_FUNC_OFFSET              (0x0000020c)
#define HAL_SDHCI_VENDOR_SPECIFIC_ADMA_ERR_OFFSET0_OFFSET  (0x00000214)

//BitMasks for Present State Registers
#define HAL_SDHCI_PRESENT_STATE_CMD_LINE_SIGNAL_LEVEL_BMSK          0x1000000
#define HAL_SDHCI_PRESENT_STATE_DAT_3_0_LINE_SIGNAL_LEVEL_BMSK      0xF00000
#define HAL_SDHCI_PRESENT_STATE_WR_PROTECT_SWITCH_PIN_LEVEL_BMSK    0x80000
#define HAL_SDHCI_PRESENT_STATE_CARD_DETECT_PIN_LEVEL_BMSK          0x40000
#define HAL_SDHCI_PRESENT_STATE_CARD_STATE_STABLE_BMSK              0x20000
#define HAL_SDHCI_PRESENT_STATE_CARD_INSERTED_BMSK                  0x10000
#define HAL_SDHCI_PRESENT_STATE_BUF_RD_EN_BMSK                      0x800
#define HAL_SDHCI_PRESENT_STATE_BUF_WR_EN_BMSK                      0x400
#define HAL_SDHCI_PRESENT_STATE_RD_TRANS_ACT_BMSK                   0x200
#define HAL_SDHCI_PRESENT_STATE_WR_TRANS_ACT_BMSK                   0x100
#define HAL_SDHCI_PRESENT_STATE_RETUNING_REQ_BMSK                   0x8
#define HAL_SDHCI_PRESENT_STATE_DAT_LINE_ACT_BMSK                   0x4
#define HAL_SDHCI_PRESENT_STATE_CMD_INHIBIT_DAT_BMSK                0x2
#define HAL_SDHCI_PRESENT_STATE_CMD_INHIBIT_CMD_BMSK                0x1


#define HAL_SDHCI_INTERRUPT_MSK_ALL 0x7FF003F
#define HAL_SDHCI_INTERRUPT_ERROR_MSK_ALL 0x7FF0000

// Bit Masks for Interrupt Status Registers
#define HAL_SDHCI_ERR_INT_STS_VENDOR_SPECIFIC_BMSK         0xF0000000
#define HAL_SDHCI_ERR_INT_STS_TUNING_ERR_BMSK               0x4000000
#define HAL_SDHCI_ERR_INT_STS_ADMA_ERR_BMSK                 0x2000000
#define HAL_SDHCI_ERR_INT_STS_AUTO_CMD_ERR_BMSK             0x1000000
#define HAL_SDHCI_ERR_INT_STS_CURRENT_LIMIT_ERR_BMSK         0x800000
#define HAL_SDHCI_ERR_INT_STS_DATA_END_BIT_ERR_BMSK          0x400000
#define HAL_SDHCI_ERR_INT_STS_DATA_CRC_ERR_BMSK              0x200000
#define HAL_SDHCI_ERR_INT_STS_DATA_TIMEOUT_ERR_BMSK          0x100000
#define HAL_SDHCI_ERR_INT_STS_CMD_INDX_ERR_BMSK               0x80000
#define HAL_SDHCI_ERR_INT_STS_CMD_END_BIT_ERR_BMSK            0x40000
#define HAL_SDHCI_ERR_INT_STS_CMD_CRC_ERR_BMSK                0x20000
#define HAL_SDHCI_ERR_INT_STS_CMD_TIMEOUT_ERR_BMSK            0x10000
#define HAL_SDHCI_NORMAL_INT_STS_ERR_INT_BMSK                  0x8000
#define HAL_SDHCI_NORMAL_INT_STS_RETUNING_EVENT_BMSK           0x1000
#define HAL_SDHCI_NORMAL_INT_STS_INT_C_BMSK                     0x800
#define HAL_SDHCI_NORMAL_INT_STS_INT_B_BMSK                     0x400
#define HAL_SDHCI_NORMAL_INT_STS_INT_A_BMSK                     0x200
#define HAL_SDHCI_NORMAL_INT_STS_CARD_INT_BMSK                  0x100
#define HAL_SDHCI_NORMAL_INT_STS_CARD_REMOVAL_BMSK               0x80
#define HAL_SDHCI_NORMAL_INT_STS_CARD_INSERTION_BMSK             0x40
#define HAL_SDHCI_NORMAL_INT_STS_BUF_RD_READY_BMSK               0x20
#define HAL_SDHCI_NORMAL_INT_STS_BUF_WR_READY_BMSK               0x10
#define HAL_SDHCI_NORMAL_INT_STS_DMA_INT_BMSK                     0x8
#define HAL_SDHCI_NORMAL_INT_STS_BLK_GAP_EVENT_BMSK               0x4
#define HAL_SDHCI_NORMAL_INT_STS_TRANS_COMPLETE_BMSK              0x2
#define HAL_SDHCI_NORMAL_INT_STS_CMD_COMPLETE_BMSK                0x1

/* Bit Masks for Interrupt Status Registers */
#define SDHCI_STATUS_VENDOR_SPECIFIC_BMSK      0xF0000000
#define SDHCI_STATUS_TUNING_ERR_BMSK           0x4000000
#define SDHCI_STATUS_ADMA_ERR_BMSK             0x2000000
#define SDHCI_STATUS_AUTO_CMD_ERR_BMSK         0x1000000
#define SDHCI_STATUS_CURRENT_LIMIT_ERR_BMSK    0x800000
#define SDHCI_STATUS_DATA_END_BIT_ERR_BMSK     0x400000
#define SDHCI_STATUS_DATA_CRC_ERR_BMSK         0x200000
#define SDHCI_STATUS_DATA_TIMEOUT_ERR_BMSK     0x100000
#define SDHCI_STATUS_CMD_INDX_ERR_BMSK         0x80000
#define SDHCI_STATUS_CMD_END_BIT_ERR_BMSK      0x40000
#define SDHCI_STATUS_CMD_CRC_ERR_BMSK          0x20000
#define SDHCI_STATUS_CMD_TIMEOUT_ERR_BMSK      0x10000
#define SDHCI_STATUS_ERR_INT_BMSK              0x8000
#define SDHCI_STATUS_RETUNING_EVENT_BMSK       0x1000
#define SDHCI_STATUS_INT_C_BMSK                0x800
#define SDHCI_STATUS_INT_B_BMSK                0x400
#define SDHCI_STATUS_INT_A_BMSK                0x200
#define SDHCI_STATUS_CARD_INT_BMSK             0x100
#define SDHCI_STATUS_CARD_REMOVAL_BMSK         0x80
#define SDHCI_STATUS_CARD_INSERTION_BMSK       0x40
#define SDHCI_STATUS_BUF_RD_READY_BMSK         0x20
#define SDHCI_STATUS_BUF_WR_READY_BMSK         0x10
#define SDHCI_STATUS_DMA_INT_BMSK              0x8
#define SDHCI_STATUS_BLK_GAP_EVENT_BMSK        0x4
#define SDHCI_STATUS_TRANS_COMPLETE_BMSK       0x2
#define SDHCI_STATUS_CMD_COMPLETE_BMSK         0x1


/** Status Clear Flags for individual states*/
enum HAL_sdcc_ApiStatus {
  HAL_SDCC_API_STATUS_SUCCESS,       /**< Success. */
  HAL_SDCC_API_STATUS_FAIL           /**< Failure */
};

/** Status Check Flags.
 *
 * Each Status Check can test for a specific feature in the Status
 * word.  The Enum name for these status indications are made common
 * to all MSMs, and the specific bit or bits being checked is coded
 * only in the HAL.
 *
 * Note that this is an enumerated list, and not a bitfield or value
 * selection.  These can not be or'ed together or combined.
 */
enum HAL_sdcc_StatusCheck {
  HAL_SDCC_STATUS_CMD_CRC_FAIL     , /**< Cmd resp received, CRC failed */
  HAL_SDCC_STATUS_CMD_TIMEOUT      , /**< Command response timeout */
  HAL_SDCC_STATUS_DATA_TIMEOUT     , /**< Data timeout */
  HAL_SDCC_STATUS_TX_UNDERRUN      , /**< Transmit Underrun */
  HAL_SDCC_STATUS_RX_OVERRUN       , /**< Receive overrun */
  HAL_SDCC_STATUS_CMD_RESPONSE_END , /**< Cmd resp received (CRC passed) */
  HAL_SDCC_STATUS_CMD_SENT         , /**< Cmd sent -no response required */
  HAL_SDCC_STATUS_START_BIT_ERR    , /**< Start Bit Error */
  HAL_SDCC_STATUS_TXFIFO_FULL      , /**< Transmit FIFO full */
  HAL_SDCC_STATUS_RXFIFO_HALF_FULL , /**< Receive FIFO half full */
  HAL_SDCC_STATUS_TXFIFO_HALF_FULL , /**< Transmit FIFO half full */
  HAL_SDCC_STATUS_RXDATA_AVLBL     , /**< Data available in receive FIFO */
  HAL_SDCC_STATUS_SDIO_INTR        , /**< SDIO int indicator for wake-up */
  HAL_SDCC_STATUS_PROG_DONE        , /**< Programming done */
  HAL_SDCC_STATUS_SDIO_INTR_OPER   , /**< SDIO int indicator for normal op */
  HAL_SDCC_STATUS_READ_ERROR       , /**< Error during Read operation */
  HAL_SDCC_STATUS_WRITE_ERROR      , /**< Error during Write operation */
  HAL_SDCC_STATUS_DMA_ERROR        , /**< Error during DMA operation */
  HAL_SDCC_STATUS_DATA_ERROR       , /**< Error during Data access */
  HAL_SDCC_STATUS_DATA_READY       , /**< Data Ready operation */
  HAL_SDCC_STATUS_DATA_END         , /**< Data transfer complete */
  HAL_SDCC_STATUS_TXACTIVE         , /**< Data transmission is progress */
  HAL_SDCC_STATUS_ANY_STATIC
  /**< Any and all status flags that are static (sticky).  These will
   * not reset without clearing. */
};

/* Number of items in the save/restore storage array */
#define SDCC_SAVE_RESTORE_ARRAY_SIZE         3


/**  \mainpage SD Card Controller Functional Overview
 *
 * The SD Card Controller driver module consists of four main
 * components:
 *
 * - SDCC hardware abstraction layer (HAL_sdcc)
 * 
 * - SDCC device driver common to all OSs (drivers/sdcc)
 *
 * - The SD Bus implementation for SD Memory and SDIO, for AMSS
 *
 * - Board Support Packages (BSP) for Qualcomm platforms
 * 
 * The SDCC driver and SD stack provide a high-level interface for
 * clients such as Hotplug and WLAN to interact with the SDCC
 * controllers to perform common functions or transfer bulk data.
 * 
 * The BSP for SDCC works with the SDCC driver to define board-level
 * behavior for the SDCC driver.  These platform-specific routines are
 * determined by the specific connections and mappings between the
 * MSM, SD slots, power sources, etc that are unique to that hardware
 * design (Surf, FFA, OEM board.)
 * 
 * The SDCC HAL provides hardware abstraction of the MSM's SD
 * controller to the SDCC driver layer.  The HAL provides a standard
 * API to the SDCC driver, independent of the underlying MSM ASIC
 * hardware.  All hardware access is performed in the HAL.  The HAL is
 * specific to a particular MSM ASIC, and common across all board
 * designs and platforms.
 * 
 * Parameters and data passed to the SDCC HAL are represented in
 * MSM-agnostic values, and must not communicate hardware-specific
 * register values.
 * 
 */

/**
 * @defgroup sdcc SD Card Controller
 *
 * The SDCC software provides block-data transfer and control methods
 * for the MSM SD/MMC Card Controller.
 */

/**
 * @defgroup sdcc_hal Hardware Abstraction Layer (HAL)
 * @ingroup sdcc
 * 
 * The Hardware Abstraction Layer serves to present a common calling
 * interface for all MSM designs that implement an SD Controller
 * block.  The specific attributes of the hardware, such as register
 * addresses, register names, and status bits are all contained within
 * the HAL, and referenced by generic terms between the driver and
 * HAL.
 */

/*@{*/
/**
 * @section error_handling HAL Error Handling
 *
 * No SDCC HAL API call returns an error status.  That is, all
 * functions are assumed to succeed.  Any indication of failure must
 * be detected through additional calls or values passed by reference.
 */

/**
 * @section return_values HAL Return Values
 *
 * Since no success/error status is returned to the caller, most
 * functions have a "void" return type and no return value.
 */

/**
 * @section side_effects HAL "Side Effects"
 *
 * All SDCC HAL functions have "side effects" because they interact
 * with hardware.  That is, there are no "pure functional" HAL calls.
 * The documented purpose of each API call is one and the same with
 * the side-effect.  For this reason, no specific Side Effect, or lack
 * thereof, is stated in the documentation for each function.
 */

/**
 * @section nControllerId SD Controller ID
 *
 * Most SDCC HAL functions take a \c nControllerId parameter as the first
 * argument.  This value represents the physical SD Controller block
 * in the MSM.  These are often referred to as "slot number" or "drive
 * number (driveno)".  Each \c nControllerId refers to a unique hardware
 * block in the MSM, responsible for one SD bus interface.
 *
 * The first controller in an MSM is number "0" and controllers are
 * numbered through N-1, where N is the number of supported
 * controllers in the MSM ASIC.  While the type is UINT32, the range
 * of values is usually small -- from 0 to 3 on most 7k targets.
 *
 * @note
 *
 * This value is ASSUMED to be valid by all HAL API calls!  Because
 * these calls are not a public API, and the upper code must already
 * validate the controller number, the HAL will never perform a range
 * or validation check on the controller ID.  The burden is on the
 * Driver layer to call HAL only with valid controller values.  Use of
 * values that are not present in hardware or supported by the HAL
 * will likely result in system failure.  Values must never be passed
 * from user/client code to the HAL without careful inspection.
 */

/*@}*/

/**
 * @defgroup sdcc_hal_bus SDCC Bus Configuration HAL
 * @ingroup sdcc_hal
 *
 * SDCC Bus Configuration HAL
 */
/*@{*/

/** Clock Select for in-coming data and command latch */
enum HAL_sdcc_ClockEdge {
  HAL_SDCC_CLOCK_EDGE_FALLING  = 0, /**< Latch on falling edge of MCIClock */
  HAL_SDCC_CLOCK_EDGE_RISING   = 1, /**< Latch on rising edge of MCIClock */
  HAL_SDCC_CLOCK_EDGE_FEEDBACK = 2, /**< Latch using feedback clock */
  HAL_SDCC_CLOCK_EDGE_LOOPBACK = 3, /**< Latch in loopback mode */
  HAL_SDCC_CLOCK_EDGE_DDR      = 3, /**< Latch in DDR mode */
  HAL_SDCC_CLOCK_UHS_MCLK      = 4, /* UHS mode mclk frequency used*/
  HAL_SDCC_CLOCK_UHS_MCLK_2    = 5,	/* UHS mode mclk/2 frequency used */
  HAL_SDCC_CLOCK_DDR200        = 6  /* mclk DDR200 mode*/
};

/**
 * Disables / Enables Flow Control for SDHCi interface
 *
 * Flow control should be enabled during initialization to avoid
 * aborting in cases where the processor is unable to keep up with the
 * data flow on SD Bus.
 *   
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nFlowControlEnable
 *   TRUE to enable flow control, FALSE to disable.
 */
void
HAL_sdhci_FlowControl (const UINT32 nControllerId,
                       BOOLEAN nFlowControlEnable);


/** Clock Select Bus Width configuration   */
enum HAL_sdcc_BusWidth {
  HAL_SDCC_BUS_WIDTH_1_BIT = 0, /**< 1 bit bus */
  HAL_SDCC_BUS_WIDTH_4_BIT = 1, /**< 4 bit bus */
  HAL_SDCC_BUS_WIDTH_8_BIT = 2  /**< 8 bit bus (MMC only) */
};

/**
 * Check for 8-bit bus width support.
 *
 * This API provides with the information if the underlying controller core
 * supports the 8 bit wide bus support. Some older versions of SDCC
 * controllers can not support 8-bit bus width, this function will make the
 * driver aware of the support to 8-bit interface and the driver can set and
 * configure appropriate bus width.
 *   
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @returns TRUE if the controller supports 8-bit bus, FALSE otherwise.
 */
BOOLEAN
HAL_sdcc_Supports8BitBus (const UINT32 nControllerId);
/*@}*/

/**
 * @defgroup sdcc_hal_power SDCC Power Control HAL
 * @ingroup sdcc_hal
 *
 * SDCC Power Control HAL
 */
/*@{*/

/**
 * Power control for the Controller Core has three states.  The
 * Power-Up state is used in the transition between Power-Off and
 * Power-On.  This phase is used during the ramp up of VDD from 0 to
 * the required voltage.
 *
 * Power on sequence, starting from VDD Off:
 * 1) VDD ON
 * 2) Issue HAL_SDCC_POWER_UP cmd,
 * 3) delay as needed,
 * 4) Issue HAL_SDCC_POWER_ON cmd.
 */
enum HAL_sdcc_PowerState {
  HAL_SDCC_POWER_OFF = 0,
  HAL_SDCC_POWER_UP  = 1,
  HAL_SDCC_POWER_ON  = 2
};

/**
 * Set the "power save" mode.
 *
 * Disable or Enable the Power Save mode [PWRSAVE of MCI_CLK].  When
 * enabled, the MCI clock will be present (output) only when the clock
 * is enabled and the bus is active.
 *
 * When disabled, (FALSE) the MCI Clock will be always active and
 * driven anytime the Clock is Enabled, even when there is no bus
 * activity.
 *
 * The driver should enable the power save mode to save current
 * when communication is idle.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nPwrSave
 *   True to enable PWRSAVE and mute the clock during idle.
 */
void
HAL_sdhci_PowerSave (const UINT32 nControllerId, BOOLEAN bEnable);

/**
 * Set or Clear DLL_RST, DLL_PDN bits of DLL_CONFIG register
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 * @set_clr
 *   flag indicating set/clear
 */
void 
HAL_sdhci_DllRstPdn(const UINT32 nController, BOOLEAN set_clr);

/**
 * Set or Clear CDR_EN of DLL_CONFIG register
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 * @bEnable
 *   flag indicating disable/enable CDR
 */
void 
HAL_sdhci_CdrEnable (const UINT32 nController, BOOLEAN bEnable); 

/**
 * Set DLL_EN bit of DLL_CONFIG register
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 */
void 
HAL_sdhci_DllEnable (const UINT32 nController);

/**
 * Set CK_OUT_EN bit of DLL_CONFIG register
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 */

void 
HAL_sdhci_DllCkOutEnable (const UINT32 nController);

/**
 * Poll for CK_OUT_EN bit to be set/clear in DLL_CONFIG reg
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 * @set_clr
 *   flag indicating set/clear
 */
int 
HAL_sdhci_DllPollCkOutEn(const UINT32 nController, BOOLEAN bEnable);

/**
 * Wait until DLL_LOCK bit to be set in DLL_CONFIG reg
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 */

int 
HAL_sdhci_DllPollStatusLock(const UINT32 nController);

/**
 * Set the phase in DLL_CONFIG reg
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 */
int 
HAL_sdhci_ConfigCmDllPhase(const UINT32 nController, INT8 phase);

/**
 * Set the mclk_freq in DLL_CONFIG reg
 *
 * @param nController
 *   SD controller number, as described in \ref nController.
 */
void 
HAL_sdhci_DllMclkSet (const UINT32 nController, UINT32 mclk_freq);

/**
 * @defgroup sdcc_hal_cmd SDCC Command and Data 
 * @ingroup sdcc_hal
 * 
 * SDCC Command and Data Transfer
 */

/** Write or Read direction for data transfer */
enum HAL_sdcc_Dir {
  HAL_SDCC_DIR_WRITE = 0,  /**< controller to card */
  HAL_SDCC_DIR_READ  = 1   /**< card to controller */
};

/** MCI_CMD Configuration structure */
struct HAL_sdcc_SdCmd {
   UINT16   dat_cmd;     /**< indicates that this is a Command with Data */
   UINT16   prog_ena;    /**< PROG_DONE status bit will be asserted when busy
                              is de-asserted */
   UINT16   enable;      /**< If set enables CPSM. */
   UINT16   interrupt;   /**< disables cmd timer and waits for int request. */
   UINT16   longrsp;     /**< receives a 136-bit long response. */
   UINT16   response;    /**< waits for a response. */
   UINT16   cmd_index;   /**< Command index. */
   UINT32   cmd_arg;     /**< Cmd Argument*/
};

/*@}*/

/**
 * @defgroup sdcc_hal_int SDCC Interrupt Control
 * @ingroup sdcc_hal
 * 
 * SDCC Interrupt Control
 */

/*@{*/

/** Cause codes for Interrupt registers */
enum HAL_sdcc_IntSource {
  HAL_SDCC_INT_SOURCE_SDIO          = 0,        /**< SDIO Interrupt */
  HAL_SDCC_INT_SOURCE_PROG          = 1,        /**< Program Done   */
  HAL_SDCC_INT_SOURCE_DATA_TIMEOUT  = 2,        /**< Data Timeout   */
  HAL_SDCC_INT_SOURCE_SDIO_AND_PROG = 3,        /**< SDIO and PROG  */
  HAL_SDCC_INT_SOURCE_DATA_END      = 4,        /**< Data End       */
};


/**
 * Initialize the SD controller base registers.
 * Register Address is virtualized for WM6 Driver, as it runs in
 * user space.
 * 
 */
void 
HAL_sdcc_InitializeRegisters(void);

/*@}*/

/**
 * @defgroup sdcc_hal_mandatory Mandatory HAL Interface
 * @ingroup sdcc_hal
 *
 *
 * HAL Mandatory (Common) API functions.
 * 
 * The HAL specification mandates certain common API calls to be
 * provided by all modules.
 */
/*@{*/

/** Structure used for initializing HWIO base address */
typedef struct HAL_sdcc_BaseAddress
{
  UINT32 periphSSBase;           /**< Peripheral Subsystem Base Address */
  UINT32 periphSSBasePhys;       /**< Peripheral Subsystem Base Physical Address */
  UINT32 periphTlmmBase;         /**< TLMM Base Address */
  UINT32 periphTlmmBasePhys;     /**< TLMM Base Physical Address */
  UINT32 sdc1sdcc5topBase;       /**< SDC1_SDCC5_TOP Base Address */
  UINT32 sdc1sdcc5topBasePhys;   /**< SDC1_SDCC5_TOP Base Physical Address */ 
  UINT32 sdc2sdcc5topBase;       /**< SDC2_SDCC5_TOP Base Address */
  UINT32 sdc2sdcc5topBasePhys;   /**< SDC2_SDCC5_TOP Base Physical Address */ 
} HAL_sdcc_BaseAddressType;

/**
 * Initialize the SD controller core to a known initial state.
 *
 * @param base_addr
 *   Pointer to structure with all required HWIO base addresses initialized .
 *
 * @returns
 *   HAL_SDCC_API_STATUS_SUCCESS for Success
 *   HAL_SDCC_API_STATUS_FAIL for failure
 */
UINT32 HAL_sdcc_SetBaseAddress(HAL_sdcc_BaseAddressType *base_addr);

enum HAL_sdhci_mode {
  HAL_SDHCI_QCT_MODE = 0,
  HAL_SDHCI_SDHC_MODE = 1
};

/**
 * Handle the power interrupts according to the SWI.
 * See the MCI PWRCTR Status/Clear/Control registers in the SWI for details.
 * When there's a bus power event (bus power on/off), the corresponding
 * PWRCTL status bit is set. Software needs to clear the status bits and sets 
 * the corresponding "success" bit in the PWRCLT_CLT register to indiate 
 * the power events have been handled successfully.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 */
void HAL_sdhci_HandlePowerInterrupts (UINT32 nControllerId);

/**
 * Reg Offset: 0x00. 32-bit register 
 * Used with Auto CMD23 feature. it sets the 32-bit block count value to the
 * argument of the CMD23 while executing Auto CMD23
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nArg2
 *   32-bit value to be set to the Argument 2 register
 */
void HAL_sdhci_SetArg2 (const UINT32 nControllerId, UINT32 nArg2);

/**
 * Reg Offset: 0x04. 16-bit register
 * Configures number of bytes in a data block
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nBlockSize
 *   Indicates the transfer block size
 */
void HAL_sdhci_SetBlockSize (const UINT32 nControllerId, UINT16 nBlockSize);

/**
 * Reg Offset: 0x06. 16-bit register
 * Configures the number of blocks in the transfer
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nBlockCount
 *   Indicates the number of blocks in the transfer
 */
void HAL_sdhci_SetBlockCount (const UINT32 nControllerId, UINT16 nBlockCount);

/**
 * Reg Offset: 0x08. 32-bit register
 * Sets the SD Argument
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nArg
 *   Arguments for SD/eMMC commands
 */
void HAL_sdhci_SetCmdArg (const UINT32 nControllerId, UINT32 nArg);


struct HAL_sdhci_TransMode {
   UINT8    multiblock;
   UINT8    direction;
   UINT8    autocmd_en;
   UINT8    blk_count_en;
   UINT8    dma_en;
};

#define SDCHI_MULTI_BLK_SHIFT         0x5
#define SDHCI_DATA_TRANSFER_DIR_SHIFT 0x4
#define SDHCI_AUTO_CMD_ENABLE_SHIFT   0x2
#define SDHCI_BLK_COUNT_ENABLE_SHIFT  0x1

/**
 * Reg Offset: 0x0C. 16-bit register
 * Controls the operation of data transfer. The Host Driver must set the 
 * Transfer Mode Register before issuing a command which transfers data. 
 * Writes to this reigster are ignored when the DAT Command Inhibit bit 
 * in the Present State register is set.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param arg
 *   Arguments for SD/eMMC commands
 */
void HAL_sdhci_SetTransferMode (const UINT32 nControllerId, 
                                const struct HAL_sdhci_TransMode *hal_mode);

struct HAL_sdhci_Cmd {
   UINT8   cmd_idx;
   UINT8   cmd_type;
   UINT8   data_present;
   UINT8   idx_check;
   UINT8   crc_check;
   UINT8   resp_type;
};

#define SDHCI_CMD_INDEX_SHIFT             0x8
#define SDHCI_CMD_TYPE_SHIFT              0x6
#define SDHCI_CMD_DATA_PRESENT_SEL_SHIFT  0x5
#define SDHCI_CMD_IDX_CHK_SHIFT           0x4
#define SDHCI_CMD_IDX_CRC_CHK_SHIFT       0x3

/**
 * Reg Offset: 0x0E. 16-bit register
 * Controls the SD/eMMC command generation.
 * Software should check the CMD and DAT Inhibit bits in 
 * the Present State register before issuing the command 
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param hal_cmd
 *   Contains the command index as well as other command attributes
 */
void HAL_sdhci_SetCommand (const UINT32 nControllerId, 
                           const struct HAL_sdhci_Cmd *hal_cmd);

/**
 * Reg Offset: 0x10-0x1F. 48-bit register
 * Reads the response from the memory card
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param resp
 *   [output] The response from the card is stored in this buffer
 *
 * @param_resp bLongResp
 *   Indicates to read a short or long response
 */
void HAL_sdhci_GetResponse (const UINT32 nControllerId, 
                            UINT32 *resp, BOOLEAN bLongResp);

/**
 * Reg Offset: 0x20. 32-bit register
 * Reads the data from the internal buffer. Used to read the data from
 * the memory device in FIFO mode
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 */
UINT32 HAL_sdhci_ReadDataBufPort (const UINT32 nControllerId);

/**
 * Reg Offset: 0x20. 32-bit register
 * Writes the data to the internal buffer. Used to write the data to 
 * the memory device in FIFO mode
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param nVal
 *   32-bit value to be written to the internal buffer which will 
 *   be sent to the memory device
 */
void HAL_sdhci_WriteDataBufPort (const UINT32 nControllerId, UINT32 nVal);

//BitMasks for Present State Registers
#define HAL_SDHCI_PRESENT_STATE_CMD_LINE_SIGNAL_LEVEL_BMSK          0x1000000
#define HAL_SDHCI_PRESENT_STATE_DAT_3_0_LINE_SIGNAL_LEVEL_BMSK      0xF00000
#define HAL_SDHCI_PRESENT_STATE_WR_PROTECT_SWITCH_PIN_LEVEL_BMSK    0x80000
#define HAL_SDHCI_PRESENT_STATE_CARD_DETECT_PIN_LEVEL_BMSK          0x40000
#define HAL_SDHCI_PRESENT_STATE_CARD_STATE_STABLE_BMSK              0x20000
#define HAL_SDHCI_PRESENT_STATE_CARD_INSERTED_BMSK                  0x10000
#define HAL_SDHCI_PRESENT_STATE_BUF_RD_EN_BMSK                      0x800
#define HAL_SDHCI_PRESENT_STATE_BUF_WR_EN_BMSK                      0x400
#define HAL_SDHCI_PRESENT_STATE_RD_TRANS_ACT_BMSK                   0x200
#define HAL_SDHCI_PRESENT_STATE_WR_TRANS_ACT_BMSK                   0x100
#define HAL_SDHCI_PRESENT_STATE_RETUNING_REQ_BMSK                   0x8
#define HAL_SDHCI_PRESENT_STATE_DAT_LINE_ACT_BMSK                   0x4
#define HAL_SDHCI_PRESENT_STATE_CMD_INHIBIT_DAT_BMSK                0x2
#define HAL_SDHCI_PRESENT_STATE_CMD_INHIBIT_CMD_BMSK                0x1

/**
 * Reg Offset: 0x24. 32-bit register
 * Reads the Present State register which gives the status of the host controller
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @return
 *   32-bit Present State register
 */
UINT32 HAL_sdhci_GetPresentState  (const UINT32 nControllerId);

#define SDHCI_DATA_TRANS_WIDTH_BMSK          0x2
#define SDHCI_EXT_DATA_TRANS_WIDTH_BMSK      0x20
#define SDHCI_DATA_TRANS_WIDTH_1_BIT_BMSK    0x0
#define SDHCI_DATA_TRANS_WIDTH_4_BIT_BMSK    0x2
#define SDHCI_DATA_TRANS_WIDTH_8_BIT_BMSK    0x20

/**
 * Reg Offset: 0x28. 8-bit register
 * Sets the Bus Width to 1, 4 or 8-bit bus width
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param BusWidth
 */
void HAL_sdhci_SetBusWidth (const UINT32 nControllerId, 
                            enum HAL_sdcc_BusWidth BusWidth);

#define SDHCI_32_BIT_ADMA2_ENABLE_BMSK  0x10
#define SDHCI_64_BIT_ADMA2_ENABLE_BMSK  0x18
#define SDHCI_DMA_SEL_BMSK              0x18

/**
 * Reg Offset: 0x28. 8-bit register
 * Enables 32-bit ADMA2 mode
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param bEnable
 *   Set to TRUE to enable AMDA2 mode. FALSE to enable SDMA mode
 */
void HAL_sdhci_ADMAEnable (const UINT32 nControllerId, BOOLEAN bEnable);


typedef enum HAL_sdhci_BusVolSelect_t {
  HAL_SDHCI_SD_BUS_VOLTAGE_33_BMSK = 0xE,
  HAL_SDHCI_SD_BUS_VOLTAGE_30_BMSK = 0xC,
  HAL_SDHCI_SD_BUS_VOLTAGE_18_BMSK = 0xA
}HAL_sdhci_BusVolSelect;

#define SDHCI_BUS_PWR_BMSK      0x1  /* Bit0 */
#define SDHCI_BUS_VOL_SEL_BMSK  0xE  /* Bits[1:3] */

/**
 * Reg Offset: 0x29. 8-bit register
 * Selects the bus voltage level for the memory device. 
 * The supported voltage levels info can be retrieved from the card's 
 * capabilities register 
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param cVoltage
 *   bus voltage level to be used
 */
void HAL_sdhci_VoltageSelect (UINT32 nControllerId, 
	                     HAL_sdhci_BusVolSelect cVoltage);

/**
 * Reg Offset: 0x29. 8-bit register
 * Turns the bus power on or off
 * Software should set the voltage level before turn on the power
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param bOn
 *   TRUE to turn on the bus power. FALSE to turn it off
 */
void HAL_sdhci_SetPower (UINT32 nControllerId, BOOLEAN bOn);

/**
 * Reg Offset: 0x29. 8-bit register
 * Reads the current bus power state.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @return
 *   8-bit value of the Power Control Register (offset 0x29)
 */
UINT8 HAL_sdhci_GetPowerState (UINT32 nControllerId);

/* Reg Offset: 2A. 8-bit Register
 * Block Gap Ctrl - Not implemented
 */

/* Reg Offset: 2B. 8-bit Register
 * Wake Up Control - Not implemented
 */

#define SDHCI_SDCLK_FREQ_SEL_SHFT       0x8
#define SDHCI_SDCLK_FREQ_SEL_MSB_SHFT   0x6
#define SDHCI_GEN_SEL_BMSK              0x20
#define SDHCI_GEN_SEL_SHFT              0x5
#define SDHCI_SDCLK_EN_BMSK             0x4 /* Bit2*/  
#define SDHCI_SDCLK_EN_SHFT             0x2
#define SDHCI_INTERNAL_CLK_STABLE_BMSK  0x2 /* Bit1 */
#define SDHCI_INTERNAL_CLK_STABLE_SHFT  0x1
#define SDHCI_INTERNAL_CLK_EN_BMSK      0x1 /* Bit0 */
#define SDHCI_INTERNAL_CLK_EN_SHFT      0x0

/**
 * Reg Offset: 0x2C. 16-bit register
 * Set the SD Clock frequency using 10-bit divider
 * The base frequency and the divider are used to set the SD clock.
 * The base frequency is retrieved from the Capabilities register
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @nDivider
 *   10-bit divider of the Power Control Register (offset 0x29)
 */
void HAL_sdhci_SetClock_10Bits_Mode (UINT32 nControllerId, 
                                                   UINT32 nDivider);

/**
 * Reg Offset: 0x2C. 16-bit register
 * Enables or stops the SD Clock. Software must stop the SD Clock before
 * making any change to the Clock Frequency Select
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param bEnable
 *   TRUE to enable or FALSE to disable SD Clock
 */
void HAL_sdhci_EnableSDClk (UINT32 nControllerId, BOOLEAN bEnable);

/**
 * Reg Offset: 0x2C. 16-bit register
 * Checks if the internal clock is stable. Software must check the internal 
 * clock stable before enabling the SD Clock
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @return
 *   TRUE indicates the internal clock is stable. FALSE otherwise
 */
BOOLEAN HAL_sdhci_IsClkStable (UINT32 nControllerId);

/**
 * Reg Offset: 0x2E. 8-bit register
 * Sets the timeout counter for DAT line timeout. Timeout clock frequency 
 * will be generated by dividing the base clock TMCLK value by this value
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param nTimeoutCounterValue
 *   8-bit value for the DAT line timeout counter
 */
void HAL_sdhci_SetTimeout (const UINT32 nControllerId, 
                           UINT8 nTimeoutCounterValue);

enum HAL_sdhci_reset {
  HAL_SDHCI_RESET_ALL = 0x1,     /* Bit0 */
  HAL_SDHCI_RESET_CMD = 0x2,     /* Bit1 */
  HAL_SDHCI_RESET_DAT = 0x4,     /* Bit2 */ 
  HAL_SDHCI_RESET_CMD_DAT = 0x6  /* Bit[1:2] */
};

/**
 * Reg Offset: 0x2F. 8-bit register
 * Issues software resets for CMD line, DAT line, or all software reset
 * Set to 1 to initiate a reset. Software must wait for the bit to be cleared
 * indicating the reset has completed.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param ResetType
 *   indicates which reset to perform
 */
void HAL_sdhci_SoftwareReset (const UINT32 nControllerId, 
                              enum HAL_sdhci_reset ResetType);

#define HAL_SDHCI_INTERRUPT_MSK_ALL 0x7FF003F
#define HAL_SDHCI_INTERRUPT_ERROR_MSK_ALL 0x7FF0000

/* Bit Masks for Interrupt Status Registers */
#define SDHCI_STATUS_VENDOR_SPECIFIC_BMSK      0xF0000000
#define SDHCI_STATUS_TUNING_ERR_BMSK           0x4000000
#define SDHCI_STATUS_ADMA_ERR_BMSK             0x2000000
#define SDHCI_STATUS_AUTO_CMD_ERR_BMSK         0x1000000
#define SDHCI_STATUS_CURRENT_LIMIT_ERR_BMSK    0x800000
#define SDHCI_STATUS_DATA_END_BIT_ERR_BMSK     0x400000
#define SDHCI_STATUS_DATA_CRC_ERR_BMSK         0x200000
#define SDHCI_STATUS_DATA_TIMEOUT_ERR_BMSK     0x100000
#define SDHCI_STATUS_CMD_INDX_ERR_BMSK         0x80000
#define SDHCI_STATUS_CMD_END_BIT_ERR_BMSK      0x40000
#define SDHCI_STATUS_CMD_CRC_ERR_BMSK          0x20000
#define SDHCI_STATUS_CMD_TIMEOUT_ERR_BMSK      0x10000
#define SDHCI_STATUS_ERR_INT_BMSK              0x8000
#define SDHCI_STATUS_RETUNING_EVENT_BMSK       0x1000
#define SDHCI_STATUS_INT_C_BMSK                0x800
#define SDHCI_STATUS_INT_B_BMSK                0x400
#define SDHCI_STATUS_INT_A_BMSK                0x200
#define SDHCI_STATUS_CARD_INT_BMSK             0x100
#define SDHCI_STATUS_CARD_REMOVAL_BMSK         0x80
#define SDHCI_STATUS_CARD_INSERTION_BMSK       0x40
#define SDHCI_STATUS_BUF_RD_READY_BMSK         0x20
#define SDHCI_STATUS_BUF_WR_READY_BMSK         0x10
#define SDHCI_STATUS_DMA_INT_BMSK              0x8
#define SDHCI_STATUS_BLK_GAP_EVENT_BMSK        0x4
#define SDHCI_STATUS_TRANS_COMPLETE_BMSK       0x2
#define SDHCI_STATUS_CMD_COMPLETE_BMSK         0x1

/**
 * Reg Offset: 0x30-0x32. This API accesses to two 16-bit registers.
 * Read the Normal Interrupt Status Register and 
 * the Error Interrupt Status Register
 * These status bits are enabled by the Interrupt Status Enable Registers.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @returns
 * 32-bit value: 
 * Bits[0-15]: Reg 0x30. Normal Interrupt Status Register
 * Bits[16-31]: Reg 0x32. Error Interrupt Status Register
 */
UINT32 HAL_sdhci_GetInterruptStatus (const UINT32 nControllerId);

/**
 * Reg Offset: 0x30-0x32. This API accesses to two 16-bit registers.
 * Clears the Normal Interrupt Status Register and 
 * the Error Interrupt Status Register
 * Writing a 1 clears the bit. Writing 0 keeps the bit unchanged.
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nMask
 *   Bit-wise mask of the bits to be cleared
 */
void HAL_sdhci_ResetInterruptStatus (const UINT32 nControllerId, UINT32 nMask);

/**
 * Reg Offset: 0x34-0x36. This API accesses to two 16-bit registers.
 * Enables or Disables the status of the events described in 
 * the Interrupt Status Registers. 
 * Writing a 1 to the Interrupt Status Enable bits indicates that when 
 * the events occur the corresponding interrupt status bit is set 
 * (Note that the interrupt is not triggered unless 
 * the corresponding Interrupt Signal Enable bit is set.)
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param mask
 *   Bit-wise mask of the status to be enabled/disabled
 * 
 * @param bEnable
 *   Indicates the operation to be carried out.
 *   If set to 1, enable the status bits that are indicated in the nMask param
 *   If clear to 0, disable the status bits that are indicated in the nMask param.
 */
void HAL_sdhci_InterruptStatusEnable (const UINT32 nControllerId, 
                                      UINT32 nMask, BOOLEAN bEnable);

/**
 * Reg Offset: 0x38 - 0x3A. This API accesses to two 16-bit registers.
 * Enables/Disables the Normal Interrupt Signal (0x38) and the Error 
 * Interrupt Signal (0x3A). Writing a 1 to the bits in the Interrupt Signal Enable
 * indicates that if the corresponding Interrupt Status Enable bit is set, 
 * the interrupt would be triggered to the system
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param nMask
 *   Bit-wise mask of the interrupt signal to be enabled or disabled
 * 
 * @param bEnable
 *   Indicates the operation to be carried out.
 *   If set to 1, enable the bit-wise nMask param as the interrupt triggered events
 *   If clear to 0, disable the bit-wise nMask param as the interrupt triggered events
 */
void HAL_sdhci_InterruptSignalEnable (const UINT32 nControllerId, 
                                      UINT32 nMask, UINT8 bEnable);

#define SDHCI_UHS_MODE_SEL_BMSK   0x7

/**
 * Reg Offset: 0x3E. 16-bit register
 * Change UHS Mode 
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * @param mode
 *   UHS mode selected
 */
void HAL_sdhci_SetUHSMode(UINT32 nControllerId, UINT16 mode);

struct HAL_sdhci_Capabilities {
   UINT32 HAL_sdhci_Reg_40_42;
   UINT32 HAL_sdhci_Reg_44_46;
};

// Bit Masks for Capabilities Registers
#define HAL_SDHCI_CAPS_SLOT_TYPE_BMSK                0xc0000000
#define HAL_SDHCI_CAPS_ASYNC_INT_SUPPORT_BMSK        0x20000000
#define HAL_SDHCI_CAPS_SYS_BUS_SUPPORT_64_BIT_BMSK   0x10000000
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_1_8V_BMSK     0x4000000
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_0V_BMSK     0x2000000
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_3V_BMSK     0x1000000
#define HAL_SDHCI_CAPS_SUSPEND_RESUME_SUPPORT_BMSK   0x800000
#define HAL_SDHCI_CAPS_SDMA_SUPPORT_BMSK             0x400000
#define HAL_SDHCI_CAPS_HS_SUPPORT_BMSK               0x200000
#define HAL_SDHCI_CAPS_ADMA2_SUPPORT_BMSK            0x80000
#define HAL_SDHCI_CAPS_SUPPORT_8_BIT_BMSK            0x40000
#define HAL_SDHCI_CAPS_MAX_BLK_LENGTH_BMSK           0x30000
#define HAL_SDHCI_CAPS_BASE_SDCLK_FREQ_BMSK          0xff00
#define HAL_SDHCI_CAPS_TIMEOUT_CLK_UNIT_BMSK         0x80
#define HAL_SDHCI_CAPS_TIMEOUT_CLK_FREQ_BMSK         0x3f
#define HAL_SDHCI_CAPS_CLK_MULTIPLIER_BMSK           0xff0000
#define HAL_SDHCI_CAPS_RETUNING_MODE_BMSK            0xc000
#define HAL_SDHCI_CAPS_USE_TUNING_FOR_SDR50_BMSK     0x2000
#define HAL_SDHCI_CAPS_TIMER_CNT_FOR_RETUNING_BMSK   0xf00
#define HAL_SDHCI_CAPS_DRIVER_TYPE_D_SUPPORT_BMSK    0x40
#define HAL_SDHCI_CAPS_DRIVER_TYPE_C_SUPPORT_BMSK    0x20
#define HAL_SDHCI_CAPS_DRIVER_TYPE_A_SUPPORT_BMSK    0x10
#define HAL_SDHCI_CAPS_DDR_50_SUPPORT_BMSK           0x4
#define HAL_SDHCI_CAPS_SDR_104_SUPPORT_BMSK          0x2
#define HAL_SDHCI_CAPS_SDR_50_SUPPORT_BMSK           0x1

/* Caps1 are Bits[0:23] only. Bits[24:31] contains HC_SPEC_VERSION_NUM */
#define HAL_SDHCI_CAPS1_BMSK                         0xFFFFFF

/* Capabilities1 Bit Shift */
#define HAL_SDHCI_CAPS_DDR_50_SUPPORT_SHFT            2
#define HAL_SDHCI_CAPS_SDR_104_SUPPORT_SHFT           1
#define HAL_SDHCI_CAPS_SDR_50_SUPPORT_SHFT            0

/* Capabilities0 Bit Shift */
#define HAL_SDHCI_CAPS_SLOT_TYPE_SHFT                30
#define HAL_SDHCI_CAPS_ASYNC_INT_SUPPORT_SHFT        29
#define HAL_SDHCI_CAPS_SYS_BUS_SUPPORT_64_BIT_SHFT   28
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_1_8V_SHFT     26
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_0V_SHFT     25
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_3V_SHFT     24
#define HAL_SDHCI_CAPS_SUSPEND_RESUME_SUPPORT_SHFT   23   
#define HAL_SDHCI_CAPS_SDMA_SUPPORT_SHFT             22
#define HAL_SDHCI_CAPS_HS_SUPPORT_SHFT               21
#define HAL_SDHCI_CAPS_ADMA2_SUPPORT_SHFT            19
#define HAL_SDHCI_CAPS_SUPPORT_8_BIT_SHFT            18
#define HAL_SDHCI_CAPS_MAX_BLK_LENGTH_SHFT           16
#define HAL_SDHCI_CAPS_BASE_SDCLK_FREQ_SHFT           8
#define HAL_SDHCI_CAPS_TIMEOUT_CLK_UNIT_SHFT          7

/**
 * Reg Offset: 0x40. 64-bit register
 * Retrieves the Capabilities. The capabilities provides information 
 * specific to host controller implemenations
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param Capabilities
 *   Host controller capabilities
 */
void HAL_sdhci_GetCapabilities (const UINT32 nControllerId, 
                                struct HAL_sdhci_Capabilities *Capabilities);

#define ADMA_FLAGS_DESC_VALID      0x00000001
#define ADMA_FLAGS_DESC_END        0x00000002
#define ADMA_FLAGS_DESC_INT        0x00000004
#define ADMA_FLAGS_OPERATION_NOP   0x00000000
#define ADMA_FLAGS_OPERATION_TRAN  0x00000020
#define ADMA_FLAGS_OPERATION_LINK  0x00000030
#define MAX_DESCRIPTOR_SIZE        (64*1024)

typedef struct __attribute__((__packed__))
{
   UINT16      nADMAFlags;
   UINT16      nDataSize;
   UINTN       nDataAddress;
} sSDHCADMADescriptor;

/**
 * Reg Offset: 0x58. 32-bit register
 * Sets the descriptor table address for the 32-bit Address ADMA
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param nAddress
 *   Specifies the address of the descriptor table for 32-bit ADMA
 *
 */
void HAL_sdhci_SetADMASystemAddress (const UINT32 nControllerId, 
                                     UINT32 nAddress);

/**
 * Reg Offset: 0x5C. 32-bit register
 * Sets the descriptor table address for the 64-bit Address ADMA
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 *
 * @param nAddress
 *   Specifies the address of the descriptor table for 64-bit ADMA 
 *
 */
void HAL_sdhci_SetADMASystemAddress64bit (const UINT32 nControllerId, 
                                          UINT32 nAddress);

#define HC_REG_DLL_CONFIG_PDN_BMSK  0x20000000
#define HC_REG_DLL_CONFIG_RST_BMSK  0x40000000

/**
 * Register SDCC_HC_REG_DLL_CONFIG
 * Disables the DLL clock
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 */
void 
HAL_sdhci_DisableDLLClock (const UINT32 nControllerId);

#define HC_REG_DLL_CONFIG_TRACK_SEL_BMSK   0x1

/**
 * Register SDCC_HC_REG_DLL_CONFIG 
 * Enable CMD line tracking
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 */
void 
HAL_sdhci_EnableCmdLineTracking (const UINT32 nControllerId);


#define HAL_SDHCI_CAPS_BASE_SDCLK_FREQ_200MHZ         0x0000C800 /* Bit[8:15] inclusive. Caps0 */
#define HAL_SDHCI_CAPS_SUPPORT_8_BIT_ENABLE           0x00040000 /* Bit18. Caps0 */
#define HAL_SDHCI_CAPS_ADMA2_SUPPORT_ENABLE           0x00080000 /* Bit19. Caps0*/
#define HAL_SDHCI_CAPS_HS_SUPPORT_ENABLE              0x00200000 /* Bit21. Caps0 */
#define HAL_SDHCI_CAPS_SDR_50_SUPPORT_ENABLE          0x00000001 /* Bit0. Caps1 */
#define HAL_SDHCI_CAPS_SDR_104_SUPPORT_ENABLE         0x00000002 /* Bit1. Caps1 */
#define HAL_SDHCI_CAPS_DDR_50_SUPPORT_ENABLE          0x00000004 /* Bit2. Caps1 */
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_1_8V_ENABLE    0x04000000 /* Bit26. Caps0 */
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_0V_ENABLE    0x02000000 /* Bit25. Caps0 */
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_3V_ENABLE    0x01000000 /* Bit24. Caps0 */
#define HAL_SDHCI_CAPS_SYS_BUS_SUPPORT_64_BIT_ENABLE  0x10000000 /* Bit28. Caps0 */
#define HAL_SDHCI_CAPS_SLOT_TYPE_EMBEDDED_SLOT        0x40000000 /* Bit[30:31]. Caps0 */
#define HAL_SDHCI_CAPS_SLOT_TYPE_SD_SLOT              0x00000000 /* Bit[30:31]. Caps0 */

#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_1_8V_DISABLE   0x00000000
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_0V_DISABLE   0x00000000
#define HAL_SDHCI_CAPS_VOLTAGE_SUPPORT_3_3V_DISABLE   0x00000000
#define HAL_SDHCI_CAPS_SUPPORT_8_BIT_DISABLE          0x00000000
#define HAL_SDHCI_CAPS_SYS_BUS_SUPPORT_64_BIT_DISABLE 0x00000000 

/**
 * Reg Offset: 0x11C and 0x120.
 * Set the SDHCi Capabitilities. 
 * Each SDCC controller supports a specific set of features.
 * Setting the bits in the HC_VENDOR_SPECIFIC_CAPABILITIES0 and 
 * HC_VENDOR_SPECIFIC_CAPABILITIES1 to indicate the features that are supported
 * in this SDCC controller.
 * Note that the setting of the obove mentioned registers will be reflected in the read-only bits of
 * the Capbilities registers (register offset 0x40-0x46)
 * 
 */
void HAL_sdhci_SetCapabilities (const UINT32 nControllerId);

/* Capabilities */
typedef enum
{
   HAL_CAPABILITIES_SLOT_TYPE,
   HAL_CAPABILITIES_ASYNC_INT_SUPPORT,
   HAL_CAPABILITIES_SYS_BUS_SUPPORT_64_BIT,
   HAL_CAPABILITIES_VOLTAGE_SUPPORT_1_8V,
   HAL_CAPABILITIES_VOLTAGE_SUPPORT_3_0V,
   HAL_CAPABILITIES_VOLTAGE_SUPPORT_3_3V,
   HAL_CAPABILITIES_SUSPEND_RESUME_SUPPORT,
   HAL_CAPABILITIES_SDMA_SUPPORT,
   HAL_CAPABILITIES_HS_SUPPORT,
   HAL_CAPABILITIES_ADMA2_SUPPORT,
   HAL_CAPABILITIES_SUPPORT_8_BIT,
   HAL_CAPABILITIES_MAX_BLK_LENGTH,
   HAL_CAPABILITIES_BASE_SDCLK_FREQ,
   HAL_CAPABILITIES_TIMEOUT_CLK_UNIT,
   HAL_CAPABILITIES_TIMEOUT_CLK_FREQ,
   HAL_CAPABILITIES_CLK_MULTIPLIER,        
   HAL_CAPABILITIES_RETUNING_MODE,         
   HAL_CAPABILITIES_USE_TUNING_FOR_SDR50,  
   HAL_CAPABILITIES_TIMER_CNT_FOR_RETUNING,
   HAL_CAPABILITIES_DRIVER_TYPE_D_SUPPORT, 
   HAL_CAPABILITIES_DRIVER_TYPE_C_SUPPORT, 
   HAL_CAPABILITIES_DRIVER_TYPE_A_SUPPORT, 
   HAL_CAPABILITIES_DDR_50_SUPPORT,        
   HAL_CAPABILITIES_SDR_104_SUPPORT,       
   HAL_CAPABILITIES_SDR_50_SUPPORT   
} HAL_capabilties_type;

/**
 * Overwrite the SDHC Capability0 Register
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param Capabilities
 *   The capability 0 to overwrite - see SDHCi spec
 *
 * @param value
 *   New capability value
 */
void HAL_sdcc_OverwriteCaps0 (const UINT32 nController, 
                              HAL_capabilties_type Capabilities, UINT32 nValue);

/**
 * Overwrite the SDHC Capability1 Register
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId .
 * 
 * @param Capabilities
 *   The capability 1 to overwrite - see SDHCi spec
 *
 * @param value
 *   New capability value
 */
void HAL_sdcc_OverwriteCaps1 (const UINT32 nController, 
                              HAL_capabilties_type Capabilities, UINT32 nValue);

/**
 * Register SDCC_HC_VENDOR_SPECIFIC_FUNC 
 * Change Select In  
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId
 * @param select_in
 *   Select In Value
 */
void HAL_sdhci_HCSelectIn (const UINT32 nControllerId, UINT32 select_in);

/**
 * Register SDCC_HC_VENDOR_SPECIFIC_FUNC 
 * Disable Select In
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId
 */
void HAL_sdhci_HCSelectInDisable (const UINT32 nControllerId);

/**
 * Register SDCC_HC_VENDOR_SPECIFIC_FUNC 
 * Change SDC4 MCLK Select value
 *
 * @param nControllerId
 *   SD controller number, as described in \ref nControllerId
 * @param mclk_sel_value 
 *   MCLK Select value  
 */
void HAL_sdhci_Sdc4MclkSelect (const UINT32 nControllerId, UINT32 mclk_sel_value);

/**
 * Register SDCC_HC_REG_DLL_CONFIG_2 
 * Enables/disables DDR Calibration  
 *
 * @param nController
 *   SD controller number, as described in \ref nController .
 *  
 * @param calib_en
 *   DDR calibration is finished or not
 *
 */
void HAL_sdhci_CalibrateDDR (const UINT32 nController, BOOLEAN calib_en);

/**
 * Register SDCC_HC_VENDOR_SPECIFIC_FUNC3 
 * Enable/disable PWRSAVE DLL
 *
 * @param nController
 *   SD controller number, as described in \ref nController .
 *  
 * @param pwr_save
 *   Enable/disable PWRSAVE DLL
 *   
 */
void HAL_sdhci_PowerSaveDll (const UINT32 nController, BOOLEAN pwr_save);

/**
 * Register SDCC_HC_REG_DLL_STATUS 
 * Makes sure DDR_DLL_LOCK_JDR is set 
 *
 * @param nController
 *   SD controller number, as described in \ref nController .
 *
 * @return
 *   TRUE indicates DDR_DLL_LOCK_JDR is set. FALSE otherwise
 */
BOOLEAN HAL_sdhci_DDRDllLock (const UINT32 nController);

/**
 * Register SDCC_HC_REG_DDR_CONFIG 
 * Configuration of ddr_config input of DLL
 *
 * @param nController
 *   SD controller number, as described in \ref nController .
 *
 */
void HAL_sdhci_ConfigDDR (const UINT32 nController);

/**
 * Register SDCC_HC_REG_DLL_CONFIG
 * Clear DLL_RST bit
 *
 * @param nController
 *   SD controller number, as described in \ref nController .
 *  
 */
void HAL_sdhci_ClearDLLRST (const UINT32 nController); 

/**
 * Register SDCC_HC_REG_DLL_CONFIG_2 
 * Enables/disables DLL clock
 *
 * @param nController
 *   SD controller number, as described in \ref nController .
 *  
 * @param bEnable
 *   Enable or disable DLL clock
 *
 */
void
HAL_sdhci_DLLClockEnable (const UINT32 nController, BOOLEAN bEnable);                              
/*@}*/

#endif /* __HALSDCC_H__ */
