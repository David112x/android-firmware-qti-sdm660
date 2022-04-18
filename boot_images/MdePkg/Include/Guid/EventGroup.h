/** @file
  GUIDs for gBS->CreateEventEx Event Groups. Defined in UEFI spec 2.0 and PI 1.2.1.

Copyright (c) 2011 - 2016 Qualcomm Technologies, Inc. All rights reserved.
Portions Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under 
the terms and conditions of the BSD License that accompanies this distribution.  
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.                                          
    
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

**/

#ifndef __EVENT_GROUP_GUID__
#define __EVENT_GROUP_GUID__

                                             
#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES \
  { 0x27abf055, 0xb1b8, 0x4c26, { 0x80, 0x48, 0x74, 0x8f, 0x37, 0xba, 0xa2, 0xdf } }

extern EFI_GUID gEfiEventExitBootServicesGuid;

#if defined(QCOM_EDK2_PATCH)
#define EFI_EVENT_GROUP_EXIT_BOOT_SUCCESS_SERVICES \
  { 0xc1e2200d, 0xef9d, 0x448b, { 0xb6, 0x46, 0xcd, 0x6e, 0x5d, 0x27, 0x83, 0xe9 } }

extern EFI_GUID gEfiEventExitBootServicesSuccessGuid;
#endif

#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE \
  { 0x13fa7698, 0xc831, 0x49c7, { 0x87, 0xea, 0x8f, 0x43, 0xfc, 0xc2, 0x51, 0x96 } }

extern EFI_GUID gEfiEventVirtualAddressChangeGuid;


#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE \
  { 0x78bee926, 0x692f, 0x48fd, { 0x9e, 0xdb, 0x1, 0x42, 0x2e, 0xf0, 0xd7, 0xab } }

extern EFI_GUID gEfiEventMemoryMapChangeGuid;


#define EFI_EVENT_GROUP_READY_TO_BOOT \
  { 0x7ce88fb3, 0x4bd7, 0x4679, { 0x87, 0xa8, 0xa8, 0xd8, 0xde, 0xe5, 0x0d, 0x2b } }

extern EFI_GUID gEfiEventReadyToBootGuid;

#define EFI_EVENT_GROUP_DXE_DISPATCH_GUID \
  { 0x7081e22f, 0xcac6, 0x4053, { 0x94, 0x68, 0x67, 0x57, 0x82, 0xcf, 0x88, 0xe5 }}

extern EFI_GUID gEfiEventDxeDispatchGuid;

#define EFI_END_OF_DXE_EVENT_GROUP_GUID \
  { 0x2ce967a, 0xdd7e, 0x4ffc, { 0x9e, 0xe7, 0x81, 0xc, 0xf0, 0x47, 0x8, 0x80 } }

extern EFI_GUID gEfiEndOfDxeEventGroupGuid;

#if defined(QCOM_EDK2_PATCH)
#define EFI_EVENT_FBPT_OS_LOADER_LOAD_IMAGE_START \
  { 0x4EDD6DFF, 0x8943, 0xDFA0, { 0x45, 0xAC, 0xF1, 0x3A, 0xA2, 0x95, 0x40, 0x70 } }

extern EFI_GUID gEfiEventFBPTOsLoaderLoadImageStartGuid;

#define EFI_EVENT_FBPT_OS_LOADER_START_IMAGE_START \
  { 0xC25022B6, 0x220B, 0x49E0, { 0xF6, 0xCC, 0xDF, 0x3A, 0x9D, 0x95, 0x5D, 0xAA } }

extern EFI_GUID gEfiEventFBPTOsLoaderStartImageStartGuid;

#define EFI_EVENT_FBPT_EXIT_BOOT_SERVICES_ENTRY \
  { 0x4F3B99A9, 0xAD43, 0xE290, { 0xAB, 0xC1, 0xDF, 0x3A, 0x39, 0x5F, 0xFF, 0x80 } }

extern EFI_GUID gEfiEventFBPTExitBootServicesEntryGuid;

#define EFI_EVENT_FBPT_EXIT_BOOT_SERVICES_EXIT \
  { 0x71E387BC, 0xB10F, 0x4019, { 0xC4, 0x9A, 0x41, 0x0D, 0xA6, 0x95, 0xCF, 0xF7 } }

extern EFI_GUID gEfiEventFBPTExitBootServicesExitGuid;
#endif // defined(QCOM_EDK2_PATCH)

#endif
