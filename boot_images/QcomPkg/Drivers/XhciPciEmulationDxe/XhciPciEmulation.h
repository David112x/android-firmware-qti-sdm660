/** @file

Copyright (c) 2010 - 2012 Qualcomm Technologies, Inc.	All Rights Reserved.
Portions Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
/*=============================================================================
                              EDIT HISTORY


 when       who      what, where, why
 --------   ---      ---------------------------------------------------------
 04/30/14   amitg   Updates Assert with USB Assert Macro
=============================================================================*/

#ifndef _XHCI_PCI_ROOT_BRIDGE_H_
#define _XHCI_PCI_ROOT_BRIDGE_H_

#include <PiDxe.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PciLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DmaLib.h>

#include <Protocol/EmbeddedExternalDevice.h>
#include <Protocol/DevicePath.h>
#include <Protocol/PciIo.h>
#include <Protocol/PciRootBridgeIo.h>
#include <Protocol/PciHostBridgeResourceAllocation.h>

#include <IndustryStandard/Pci23.h>
#include <IndustryStandard/Pci22.h>
#include <IndustryStandard/Acpi.h>

#include "UsbError.h"

#define QUALCOMM_VENDOR_ID                   0x5143
#define QUALCOMM_XHCI_DEVICE_ID              0x0102

#define EFI_RESOURCE_NONEXISTENT  0xFFFFFFFFFFFFFFFFULL
#define EFI_RESOURCE_LESS         0xFFFFFFFFFFFFFFFEULL
#define EFI_RESOURCE_SATISFIED    0x0000000000000000ULL

#define _DBG(EfiD, Expression, ...)	DEBUG((EfiD, Expression, ##__VA_ARGS__))
#define DBG(Efid, str, ...) \
  _DBG (Efid, "%a: " str "\n", __FUNCTION__, ##__VA_ARGS__);

typedef struct {
  ACPI_HID_DEVICE_PATH      AcpiDevicePath;
  EFI_DEVICE_PATH_PROTOCOL  EndDevicePath;
} EFI_PCI_ROOT_BRIDGE_DEVICE_PATH;


#define ACPI_CONFIG_IO    0
#define ACPI_CONFIG_MMIO  1
#define ACPI_CONFIG_BUS   2

typedef struct {
  EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR Desc[3];
  EFI_ACPI_END_TAG_DESCRIPTOR       EndDesc;
} ACPI_CONFIG_INFO;


#define PCI_ROOT_BRIDGE_SIGNATURE     SIGNATURE_32 ('u', 's', 'b', 'X')

typedef struct {
  UINT32                                            Signature;
  EFI_HANDLE                                        Handle;
  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL                   Io;
  EFI_PCI_ROOT_BRIDGE_DEVICE_PATH                   DevicePath;
  
  UINT8   StartBus;
  UINT8   EndBus;
  UINT16  Type;
  UINT32  MemoryStart;
  UINT32  MemorySize;
  UINTN   IoOffset;
  UINT32  IoStart;
  UINT32  IoSize;
  UINT64  PciAttributes;  

  ACPI_CONFIG_INFO  *Config;

} PCI_ROOT_BRIDGE;


#define INSTANCE_FROM_PCI_ROOT_BRIDGE_IO_THIS(a)    CR (a, PCI_ROOT_BRIDGE, Io, PCI_ROOT_BRIDGE_SIGNATURE)


typedef union {
  UINT8   volatile  *buf;
  UINT8   volatile  *ui8;
  UINT16  volatile  *ui16;
  UINT32  volatile  *ui32;
  UINT64  volatile  *ui64;
  UINTN   volatile  ui;
} PTR;



/**
  Test to see if this driver supports ControllerHandle. Any
  ControllerHandle that has UsbConfig protocol installed will
  be supported if protocol instance supports XHCI.

  @param  This                 Protocol instance pointer.
  @param  Controller           Handle of device to test.
  @param  RemainingDevicePath  Not used.

  @return EFI_SUCCESS          This driver supports this device.
  @return EFI_UNSUPPORTED      This driver does not support this device.

**/
EFI_STATUS
EFIAPI
XhcPciEmulationDriverBindingSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL *This,
  IN EFI_HANDLE                  Controller,
  IN EFI_DEVICE_PATH_PROTOCOL    *RemainingDevicePath
  );

  
/**
  Starting the PCI emulation Driver.

  @param  This                 Protocol instance pointer.
  @param  Controller           Handle of device to test.
  @param  RemainingDevicePath  Not used.

  @return EFI_SUCCESS          supports this device.
  @return EFI_UNSUPPORTED      do not support this device.
  @return EFI_DEVICE_ERROR     cannot be started due to device Error.
  @return EFI_OUT_OF_RESOURCES cannot allocate resources.

**/
EFI_STATUS
EFIAPI
XhcPciEmulationDriverBindingStart (
  IN EFI_DRIVER_BINDING_PROTOCOL *This,
  IN EFI_HANDLE                  Controller,
  IN EFI_DEVICE_PATH_PROTOCOL    *RemainingDevicePath
  );

/**
  Stop this driver on ControllerHandle. Support stoping any child handles
  created by this driver.

  @param  This                 Protocol instance pointer.
  @param  Controller           Handle of device to stop driver on.
  @param  NumberOfChildren     Number of Children in the ChildHandleBuffer.
  @param  ChildHandleBuffer    List of handles for the children we need to stop.

  @return EFI_SUCCESS          Success.
  @return EFI_DEVICE_ERROR     Fail.

**/
EFI_STATUS
EFIAPI
XhcPciEmulationDriverBindingStop (
  IN EFI_DRIVER_BINDING_PROTOCOL *This,
  IN EFI_HANDLE                  Controller,
  IN UINTN                       NumberOfChildren,
  IN EFI_HANDLE                  *ChildHandleBuffer
  );


EFI_STATUS
EFIAPI
PciRootBridgeIoPollMem ( 
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                                 Address,
  IN  UINT64                                 Mask,
  IN  UINT64                                 Value,
  IN  UINT64                                 Delay,
  OUT UINT64                                 *Result
  );
  
EFI_STATUS
EFIAPI
PciRootBridgeIoPollIo ( 
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN  UINT64                                 Address,
  IN  UINT64                                 Mask,
  IN  UINT64                                 Value,
  IN  UINT64                                 Delay,
  OUT UINT64                                 *Result
  );
  
EFI_STATUS
EFIAPI
PciRootBridgeIoMemRead (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                                 Address,
  IN     UINTN                                  Count,
  IN OUT VOID                                   *Buffer
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoMemWrite (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                                 Address,
  IN     UINTN                                  Count,
  IN OUT VOID                                   *Buffer
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoIoRead (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                                 UserAddress,
  IN     UINTN                                  Count,
  IN OUT VOID                                   *UserBuffer
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoIoWrite (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                                 UserAddress,
  IN     UINTN                                  Count,
  IN OUT VOID                                   *UserBuffer
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoCopyMem (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN UINT64                                 DestAddress,
  IN UINT64                                 SrcAddress,
  IN UINTN                                  Count
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoPciRead (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                                 Address,
  IN     UINTN                                  Count,
  IN OUT VOID                                   *Buffer
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoPciWrite (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL        *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                                 Address,
  IN     UINTN                                  Count,
  IN OUT VOID                                   *Buffer
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoMap (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL            *This,
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION  Operation,
  IN     VOID                                       *HostAddress,
  IN OUT UINTN                                      *NumberOfBytes,
  OUT    EFI_PHYSICAL_ADDRESS                       *DeviceAddress,
  OUT    VOID                                       **Mapping
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoUnmap (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
  IN VOID                             *Mapping
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoAllocateBuffer (
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
  IN  EFI_ALLOCATE_TYPE                Type,
  IN  EFI_MEMORY_TYPE                  MemoryType,
  IN  UINTN                            Pages,
  OUT VOID                             **HostAddress,
  IN  UINT64                           Attributes
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoFreeBuffer (
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
  IN  UINTN                            Pages,
  OUT VOID                             *HostAddress
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoFlush (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoGetAttributes (
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
  OUT UINT64                           *Supported,
  OUT UINT64                           *Attributes
  );

EFI_STATUS
EFIAPI
PciRootBridgeIoSetAttributes (
  IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
  IN     UINT64                           Attributes,
  IN OUT UINT64                           *ResourceBase,
  IN OUT UINT64                           *ResourceLength 
  ); 

EFI_STATUS
EFIAPI
PciRootBridgeIoConfiguration (
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
  OUT VOID                             **Resources
  );

//
// Private Function Prototypes
//
EFI_STATUS
EFIAPI
PciRootBridgeIoMemRW (
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH  Width,
  IN  UINTN                                  Count,
  IN  BOOLEAN                                InStrideFlag,
  IN  PTR                                    In,
  IN  BOOLEAN                                OutStrideFlag,
  OUT PTR                                    Out
  );

BOOLEAN
PciIoMemAddressValid (
  IN EFI_PCI_IO_PROTOCOL  *This,
  IN UINT64               Address
  );

#endif

