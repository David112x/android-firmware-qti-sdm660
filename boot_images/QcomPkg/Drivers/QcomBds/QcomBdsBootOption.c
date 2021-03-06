/** @file
*
*  Copyright (c) 2014-2016 Qualcomm Technologies, Inc.  All Rights Reserved.
*  Portions Copyright (c) 2011-2013, ARM Limited. All rights  Reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 06/22/16   bh      Updated retail check
 03/09/16   vk      Remove ArmPlatformPkg dependency
 04/23/15   bh      Fix KW errors
 02/04/15   bh      Fix BootOrder issue
 12/12/14   bh      Drain serial port and enable synchornous IO in BDS
 12/11/14   bh      Fix KW errors
 12/01/14   bh      Fixed #if to #ifdefs
 11/06/14   bh      Removed FDT stuff
 10/24/14   bh      Initial branch from ArmPkg with edits

=============================================================================*/

#include "QcomBdsInternal.h"
#include <Library/QcomTargetLib.h>
#include <Library/QcomLib.h>
#include <Library/FuseControlLib.h>
#include "Library/SerialPortShLib.h"

extern EFI_HANDLE mImageHandle;

EFI_STATUS
BootOptionStart (
  IN BDS_LOAD_OPTION *BootOption
  )
{
  EFI_STATUS                            Status;
  UINT16                                LoadOptionIndexSize;
  // Set BootCurrent variable
  LoadOptionIndexSize = sizeof(UINT16);
  gRT->SetVariable (L"BootCurrent", &gEfiGlobalVariableGuid,
            EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
            LoadOptionIndexSize, &(BootOption->LoadOptionIndex));
  
  if (RETAIL)
  {
    SerialPortDrain();
    EnableSynchronousSerialPortIO ();
  }

  Status = BdsStartEfiApplication (mImageHandle, BootOption->FilePathList, BootOption->OptionalDataSize, BootOption->OptionalData);

  // Clear BootCurrent variable
  LoadOptionIndexSize = sizeof(UINT16);
  gRT->SetVariable (L"BootCurrent", &gEfiGlobalVariableGuid,
            EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
            0, NULL);
  return Status;
}

EFI_STATUS
BuildBootOptionListFromBootOrder (
  IN OUT LIST_ENTRY *BootOptionList
  )
{
  EFI_STATUS                    Status;
  UINTN                         Index;
  UINT16*                       BootOrder;
  UINTN                         BootOrderSize;
  BDS_LOAD_OPTION*              BdsLoadOption;
  BDS_LOAD_OPTION_ENTRY*        BdsLoadOptionEntry;

  InitializeListHead (BootOptionList);

  // Get the Boot Option Order from the environment variable
  Status = GetGlobalEnvironmentVariable (L"BootOrder", NULL, &BootOrderSize, (VOID**)&BootOrder);
  if (EFI_ERROR(Status) || (BootOrder == NULL) ) {
    return Status;
  }

  for (Index = 0; Index < BootOrderSize / sizeof (UINT16); Index++) {
    Status = BootOptionFromLoadOptionIndex (BootOrder[Index], &BdsLoadOption);
    if (!EFI_ERROR(Status)) {
      BdsLoadOptionEntry = (BDS_LOAD_OPTION_ENTRY*)AllocatePool(sizeof(BDS_LOAD_OPTION_ENTRY));
      if (BdsLoadOptionEntry == NULL)
        return EFI_OUT_OF_RESOURCES;
      BdsLoadOptionEntry->BdsLoadOption = BdsLoadOption;
      InsertTailList (BootOptionList,&BdsLoadOptionEntry->Link);
    }
  }

  FreePool (BootOrder);

  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
BootOptionSetFields (
  IN BDS_LOAD_OPTION*           BootOption,
  IN UINT32                     Attributes,
  IN CHAR16*                    BootDescription,
  IN EFI_DEVICE_PATH_PROTOCOL*  DevicePath,
  IN ARM_BDS_LOADER_TYPE        BootType,
  IN ARM_BDS_LOADER_ARGUMENTS*  BootArguments
  )
{
  EFI_QC_LOAD_OPTION               EfiLoadOption;
  UINTN                         EfiLoadOptionSize;
  UINTN                         BootDescriptionSize;
  UINTN                         BootOptionalDataSize;
  UINT16                        FilePathListLength;
  UINT8*                        EfiLoadOptionPtr;

  // If we are overwriting an existent Boot Option then we have to free previously allocated memory
  if (BootOption->LoadOption) {
    FreePool(BootOption->LoadOption);
  }

  BootDescriptionSize = StrSize (BootDescription);
  BootOptionalDataSize = 0;
 
  // Compute the size of the FilePath list
  FilePathListLength = GetUnalignedDevicePathSize (DevicePath);

  // Allocate the memory for the EFI Load Option
  EfiLoadOptionSize = sizeof(UINT32) + sizeof(UINT16) + BootDescriptionSize + FilePathListLength + BootOptionalDataSize;
  EfiLoadOption = (EFI_QC_LOAD_OPTION)AllocatePool(EfiLoadOptionSize);
  if (EfiLoadOption == NULL)
    return EFI_OUT_OF_RESOURCES;
  EfiLoadOptionPtr = EfiLoadOption;

  //
  // Populate the EFI Load Option and BDS Boot Option structures
  //

  // Attributes fields
  BootOption->Attributes = Attributes;
  *(UINT32*)EfiLoadOptionPtr = Attributes;
  EfiLoadOptionPtr += sizeof(UINT32);

  // FilePath List fields
  BootOption->FilePathListLength = FilePathListLength;
  *(UINT16*)EfiLoadOptionPtr = FilePathListLength;
  EfiLoadOptionPtr += sizeof(UINT16);

  // Boot description fields
  BootOption->Description = (CHAR16*)EfiLoadOptionPtr;
  CopyMem (EfiLoadOptionPtr, BootDescription, BootDescriptionSize);
  EfiLoadOptionPtr += BootDescriptionSize;

  // File path fields
  BootOption->FilePathList = (EFI_DEVICE_PATH_PROTOCOL*)EfiLoadOptionPtr;
  CopyMem (EfiLoadOptionPtr, DevicePath, FilePathListLength);
  EfiLoadOptionPtr += FilePathListLength;

  // Optional Data fields, Do unaligned writes
  BootOption->OptionalData = NULL;

  BootOption->OptionalDataSize = 0;

  // If this function is called at the creation of the Boot Device entry (not at the update) the
  // BootOption->LoadOptionSize must be zero then we get a new BootIndex for this entry
  if (BootOption->LoadOptionSize == 0) {
    BootOption->LoadOptionIndex = BootOptionAllocateBootIndex ();
  }

  // Fill the EFI Load option fields
  BootOption->LoadOption = EfiLoadOption;
  BootOption->LoadOptionSize = EfiLoadOptionSize;

  return EFI_SUCCESS;
}

EFI_STATUS
BootOptionCreate (
  IN  UINT32                    Attributes,
  IN  CHAR16*                   BootDescription,
  IN  EFI_DEVICE_PATH_PROTOCOL* DevicePath,
  IN  ARM_BDS_LOADER_TYPE       BootType,
  IN  ARM_BDS_LOADER_ARGUMENTS* BootArguments,
  OUT BDS_LOAD_OPTION**         BdsLoadOption
  )
{
  BDS_LOAD_OPTION_ENTRY*        BootOptionEntry;
  BDS_LOAD_OPTION*              BootOption;
  EFI_STATUS                    Status;
  //Following variables excluded when we do not want to add to BootOrder variable
#ifdef ENABLE_ENUMERATED_BOOTORDER_SAVING 
  CHAR16                        BootVariableName[9];
  UINT16*                       BootOrder;
  UINTN                         BootOrderSize;
#endif
  //
  // Allocate and fill the memory for the BDS Load Option structure
  //
  BootOptionEntry = (BDS_LOAD_OPTION_ENTRY*)AllocatePool (sizeof (BDS_LOAD_OPTION_ENTRY));
  if (BootOptionEntry == NULL)
    return EFI_OUT_OF_RESOURCES;
  InitializeListHead (&BootOptionEntry->Link);
  BootOptionEntry->BdsLoadOption = (BDS_LOAD_OPTION*)AllocateZeroPool (sizeof(BDS_LOAD_OPTION));
  if (BootOptionEntry->BdsLoadOption == NULL)
    return EFI_OUT_OF_RESOURCES;
  BootOption = BootOptionEntry->BdsLoadOption;
  Status = BootOptionSetFields (BootOption, Attributes, BootDescription, DevicePath, BootType, BootArguments);
  if (EFI_ERROR(Status))
    return Status;
  //
  // Set the related environment variables
  //
  //The following is excluded because we don't want to add to BootOrder persistent variable
#ifdef ENABLE_ENUMERATED_BOOTORDER_SAVING
  // Create Boot#### environment variable
  UnicodeSPrint (BootVariableName, 9 * sizeof(CHAR16), L"Boot%04X", BootOption->LoadOptionIndex);
  Status = gRT->SetVariable (
      BootVariableName,
      &gEfiGlobalVariableGuid,
      EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
      BootOption->LoadOptionSize,
      BootOption->LoadOption
      );

  // Add the new Boot Index to the list
  Status = GetGlobalEnvironmentVariable (L"BootOrder", NULL, &BootOrderSize, (VOID**)&BootOrder);
  if (!EFI_ERROR(Status)) {
    BootOrder = ReallocatePool (BootOrderSize, BootOrderSize + sizeof(UINT16), BootOrder);
    // Add the new index at the end
    BootOrder[BootOrderSize / sizeof(UINT16)] = BootOption->LoadOptionIndex;
    BootOrderSize += sizeof(UINT16);
  } else {
    // BootOrder does not exist. Create it
    BootOrderSize = sizeof(UINT16);
    BootOrder = &(BootOption->LoadOptionIndex);
  }

  // Update (or Create) the BootOrder environment variable
  Status = gRT->SetVariable (
      L"BootOrder",
      &gEfiGlobalVariableGuid,
      EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
      BootOrderSize,
      BootOrder
      );

  // We only free it if the UEFI Variable 'BootOrder' was already existing
  if (BootOrderSize > sizeof(UINT16)) {
    FreePool (BootOrder);
  }
#endif
  *BdsLoadOption = BootOption;
  return Status;
}

EFI_STATUS
BootOptionUpdate (
  IN  BDS_LOAD_OPTION*          BdsLoadOption,
  IN  UINT32                    Attributes,
  IN  CHAR16*                   BootDescription,
  IN  EFI_DEVICE_PATH_PROTOCOL* DevicePath,
  IN  ARM_BDS_LOADER_TYPE       BootType,
  IN  ARM_BDS_LOADER_ARGUMENTS* BootArguments
  )
{
  EFI_STATUS      Status;
  CHAR16          BootVariableName[9];

  // Update the BDS Load Option structure
  BootOptionSetFields (BdsLoadOption, Attributes, BootDescription, DevicePath, BootType, BootArguments);

  // Update the related environment variables
  UnicodeSPrint (BootVariableName, 9 * sizeof(CHAR16), L"Boot%04X", BdsLoadOption->LoadOptionIndex);

  Status = gRT->SetVariable (
      BootVariableName,
      &gEfiGlobalVariableGuid,
      EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
      BdsLoadOption->LoadOptionSize,
      BdsLoadOption->LoadOption
      );

  return Status;
}

EFI_STATUS
BootOptionDelete (
  IN  BDS_LOAD_OPTION *BootOption
  )
{
  UINTN         Index;
  UINTN         BootOrderSize;
  UINT16*       BootOrder;
  UINTN         BootOrderCount;
  EFI_STATUS    Status;

  // Remove the entry from the BootOrder environment variable
  Status = GetGlobalEnvironmentVariable (L"BootOrder", NULL, &BootOrderSize, (VOID**)&BootOrder);
  if (!EFI_ERROR(Status) && (BootOrder != NULL) ) {
    BootOrderCount = BootOrderSize / sizeof(UINT16);

    // Find the index of the removed entry
    for (Index = 0; Index < BootOrderCount; Index++) {
      if (BootOrder[Index] == BootOption->LoadOptionIndex) {
        // If it the last entry we do not need to rearrange the BootOrder list
        if (Index + 1 != BootOrderCount) {
          CopyMem (
            &BootOrder[Index],
            &BootOrder[Index + 1],
            (BootOrderCount - (Index + 1)) * sizeof(UINT16)
            );
        }
        break;
      }
    }

    // Update the BootOrder environment variable
    Status = gRT->SetVariable (
        L"BootOrder",
        &gEfiGlobalVariableGuid,
        EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
        BootOrderSize - sizeof(UINT16),
        BootOrder
        );
  }

  FreePool (BootOrder);

  return EFI_SUCCESS;
}
