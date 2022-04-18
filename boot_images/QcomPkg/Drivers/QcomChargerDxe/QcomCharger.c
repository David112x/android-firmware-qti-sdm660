/** @file QcomCharger.c

  Implements the QUALCOMM Charger protocol

  Copyright (c) 2016,  Qualcomm Technologies Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


when         who     what, where, why
--------     ---     -----------------------------------------------------------
11/21/16     ra      Checking return status for ChargerLib_GetBatteryStatus
11/09/16     cs      modified charger present API also to detect DCIn. 
09/13/16     sm      Marked EFI_QcomChargerGetMaxUsbCurrent() as Unsupported
09/19/16     sv      Updated to support SDM660.
06/23/16     va      Adding Action Info for taking Action
06/23/16     va      Adding support for Charger Fg Peripheral dumps
06/14/16     va      Adding File log support to Charger App
06/03/16     va      Update for early sign of life during profile load
06/01/16     sm      Added wrapper APIs for battery presence and battery voltage.
05/24/16     sm      Enabled ChargerPlatform_Init() API call
05/09/16     sm      Added changes to install protocol from QcomChargerInitialize()
04/21/16     sm      Added API call for Watchdog
03/21/16     va      Adding DeInit Api 
03/15/16     sm      Added changes for bring up to only enter and exit the DXE 
                     no platform initialization performed. 
02/10/16     sm      Initial draft

=============================================================================*/
#include <Uefi.h>

/**
  EFI interfaces
 */
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

/**
  Charger PROTOCOL interface
 */
#include <Protocol/EFIQcomCharger.h>

/**
  EFI interfaces
 */
 #include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/QcomLib.h>
#include <api/systemdrivers/pmic/pm_uefi.h>

/**
  Protocol Dependencies
*/
#include <Protocol/EFIPlatformInfo.h>
#include <Protocol/EFIPmicVersion.h>
#include <Library/QcomTargetLib.h>

/**
  ADC Dependencies
 */
#include <Protocol/EFIAdc.h>

/**
  Ext HW Dependencies
*/

#include "QcomChargerPlatform.h"

#include <api/systemdrivers/charger/ChargerLibCommon.h>

EFI_QCOM_CHARGER_PROTOCOL QcomChargerProtocolImplementation;

/*===========================================================================*/
/*                  FUNCTIONS PROTOTYPES                                     */
/*===========================================================================*/
/**
EFI_QcomChargerInit()

@brief
Initializes charger module
*/
EFI_STATUS QcomChargerInitialize(IN EFI_HANDLE         ImageHandle,
                             IN EFI_SYSTEM_TABLE   *SystemTable)
{
  EFI_STATUS Status = EFI_SUCCESS;

  /* Required Initialization */
  Status = ChargerPlatform_Init();
  if(EFI_SUCCESS == Status)
  {
    Status = gBS->InstallMultipleProtocolInterfaces( &ImageHandle,
                                                      &gQcomChargerProtocolGuid,
                                                      &QcomChargerProtocolImplementation,
                                                      NULL );
  }

  return Status;
}

/**
EFI_QcomChargerEnableCharging()

@brief
Enables charging
*/
EFI_STATUS
EFIAPI 
EFI_QcomChargerEnableCharging
(
  IN BOOLEAN Enable
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  QCOM_CHARGER_PLATFORM_CFGDATA_TYPE CfgData;

  ChargerPlatform_GetConfigData(&CfgData);

  Status = ChargerLib_ChargerEnable(Enable);

  return Status;
}

/**
EFI_QcomChargerSetMaxUsbCurrent()

@brief
Set maximum USB current
*/
EFI_STATUS
EFIAPI 
EFI_QcomChargerSetMaxUsbCurrent
(
  IN UINT32 MaxCurrent
)
{
  EFI_STATUS Status = EFI_SUCCESS;

  Status = ChargerLib_SetMaxUsbCurrent(MaxCurrent);

  return Status;
}

/**
EFI_QcomChargerGetMaxUsbCurrent()

@brief
Gets maximum USB current from config file
*/
EFI_STATUS
EFIAPI 
EFI_QcomChargerGetMaxUsbCurrent
(
  OUT UINT32 *pMaxCurrent
)
{
  return EFI_UNSUPPORTED;
}

/**
EFI_QcomChargerGetChargingStatus()

@brief
Initializes charger module
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerGetChargingAction
(
  EFI_QCOM_CHARGER_ACTION_TYPE  *pChargingAction,
  EFI_QCOM_CHARGER_ACTION_INFO  *pChargerActionInfo
)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if(NULL == pChargingAction)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status = ChargerPlatform_GetChargingAction((QCOM_CHARGER_PLATFORM_ACTION_TYPE *)pChargingAction, (QCOM_CHARGER_PLATFORM_ACTION_INFO* )pChargerActionInfo);

  return Status;
}


/**
EFI_QcomChargerTakeAction()

@brief
Initializes charger module
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerTakeAction
(
  EFI_QCOM_CHARGER_ACTION_TYPE ChargingAction,
  CONST EFI_QCOM_CHARGER_ACTION_INFO *pChargerActionInfo
)
{
  EFI_STATUS Status = EFI_SUCCESS;

  Status = ChargerPlatform_TakeAction((QCOM_CHARGER_PLATFORM_ACTION_TYPE)ChargingAction, (QCOM_CHARGER_PLATFORM_ACTION_INFO *)pChargerActionInfo);

  return Status;
}

EFI_STATUS
EFIAPI 
EFI_QcomChargerDisplayImage
(
  IN EFI_QCOM_CHARGER_DISP_IMAGE_TYPE ImageType,
  IN BOOLEAN ClearScreen
)
{
  EFI_STATUS Status = EFI_SUCCESS;

  Status = ChargerLibEvent_DispBattSymbol((CHARGERLIB_EVENT_DISP_IMAGE_TYPE)ImageType, ClearScreen); 

  return Status;
}


EFI_STATUS
EFIAPI 
EFI_QcomChargerDeInitialize
(
  EFI_QCOM_CHARGER_ACTION_TYPE ChargingAction
)
{
  EFI_STATUS Status = EFI_SUCCESS;

  Status = ChargerLib_Exit(PM_DEVICE_0);

  return Status;
}



/**
EFI_QcomChargerGetBatteryPresence ()

@brief
Get battery presence status
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerGetBatteryPresence
(
  OUT BOOLEAN  *pBatteryPresent
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  
  if(NULL == pBatteryPresent)
  {
    return EFI_INVALID_PARAMETER;
  }
  
  Status = ChargerLib_GetBatteryPresence(pBatteryPresent);

  return Status;
}

/**
EFI_QcomChargerGetBatteryVoltage ()

@brief
Returns battery voltage
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerGetBatteryVoltage
(
  OUT UINT32  *pBatteryVoltage
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_PM_FG_BATT_STATUS_INFO BatteryStatus = {0};
  
  if(NULL == pBatteryVoltage)
  {
    return EFI_INVALID_PARAMETER;
  }
  *pBatteryVoltage = 0;

  Status = ChargerLib_GetBatteryStatus((chargerlib_batt_status_info*)&BatteryStatus);
  
  if(EFI_SUCCESS == Status)
  {
  *pBatteryVoltage = BatteryStatus.BatteryVoltage;
  }

  return Status;
}

/**
EFI_QcomChargerGetFileLogInfo ()

@brief
Returns Charger Log File handle information 
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerGetFileLogInfo
(
  OUT EFI_QCOM_CHARGER_LOG_INFO *pFileLogInfo
)
{
  EFI_STATUS                     Status = EFI_SUCCESS;
  QCOM_CHARGER_PLATFORM_LOG_INFO Info   = {0};

  if(NULL == pFileLogInfo)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status = ChargerPlatformFile_GetLogInfo(&Info);
  if(Status == EFI_SUCCESS)
  {
    pFileLogInfo->gChargerLogHandle            = Info.gChargerLogHandle;
    pFileLogInfo->bPrintChargerAppDbgMsg       = Info.bPrintChargerAppDbgMsg;
    pFileLogInfo->bPrintChargerAppDbgMsgToFile = Info.bPrintChargerAppDbgMsgToFile;
  }
  else
  {
    /* DEBUG */
    CHARGER_FILE_UART_DEBUG(( EFI_D_WARN, "QcomChargerDxe:: %a Error = %r \r\n",__FUNCTION__, Status));
  }

  return Status;
}

/**
EFI_QcomChargerDumpPeripheral ()

@brief
Debug Prints Charger Fg Peripheral  
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerDumpPeripheral( )
{
  EFI_STATUS Status = EFI_SUCCESS;
  Status = ChargerLib_DumpChargerPeripheral();
  return Status;
}

/**
EFI_QcomChargerIsDcInValid ()

@brief
get if dcin is valid or not
*/
EFI_STATUS
EFIAPI
EFI_QcomChargerIsDcInValid(BOOLEAN* pIsDcInValid)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if (!pIsDcInValid)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status = ChargeLib_IsDcinValid(pIsDcInValid);

  return Status;
}


/**
  PMIC FG UEFI Protocol implementation
 */
EFI_QCOM_CHARGER_PROTOCOL QcomChargerProtocolImplementation =
{
  QCOM_CHARGER_REVISION,
  EFI_QcomChargerEnableCharging,
  EFI_QcomChargerGetMaxUsbCurrent,
  EFI_QcomChargerSetMaxUsbCurrent,
  EFI_QcomChargerGetChargingAction,
  EFI_QcomChargerTakeAction,
  EFI_QcomChargerDisplayImage,
  EFI_QcomChargerGetBatteryPresence,
  EFI_QcomChargerGetBatteryVoltage,
  EFI_QcomChargerDeInitialize,
  EFI_QcomChargerGetFileLogInfo,
  EFI_QcomChargerDumpPeripheral,
  EFI_QcomChargerIsDcInValid,
};
