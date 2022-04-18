/** @file

  Tests for QcomBaseLib

  Copyright (c) 2010-2011, Qualcomm Technologies Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 07/13/15   al      Changing TPL_NOTIFY to TPL_CALLBACK
 06/27/12   pbi     Updated for timetick changes
 07/30/11   sy      Adding TestInterface Library
 03/10/11   EBR     Created test for Timer and Stall

=============================================================================*/

#include <Uefi.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/TestInterface.h>


/**
  The user Entry Point for Application. The user code starts with this function
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
QcomBaseLibTestMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINTN EventIndex;
  EFI_STATUS  Status;
  UINT64 starting_uS;
  UINT64 ending_uS;
  UINT64 microseconds_taken;
  UINT64 deviation;
  EFI_EVENT TimerEvent;

  //
  // Create the timer event to implement a timer
  //
  TEST_START("QcomBaseLibTest");
  Status = gBS->CreateEvent (
                  EVT_TIMER,
                  TPL_CALLBACK,
                  NULL,
                  NULL,
                  &TimerEvent
                  );
  if(EFI_ERROR (Status)) {
  	goto ExitHandler;
  }

  // Set timer for 100ms
  AsciiPrint("Registering Timer Event: 100 ms relative timer\n");
  gBS->SetTimer(TimerEvent, TimerRelative, 1000000);
  starting_uS = GetTimerCountus();
  AsciiPrint("Waiting for 100 ms\n");
  gBS->WaitForEvent(1, &TimerEvent, &EventIndex);
  ending_uS = GetTimerCountus();
  AsciiPrint("100 ms timer event signaled\n");
  microseconds_taken = ending_uS - starting_uS;
  deviation = microseconds_taken - 100000;
  AsciiPrint("Deviation from 100 ms was (in usec): %d\n", (UINT32)deviation);


  // Test Stall
  AsciiPrint("Stalling for 100 ms\n");
  starting_uS = GetTimerCountus();
  gBS->Stall(100000);
  ending_uS = GetTimerCountus();
  microseconds_taken = ending_uS - starting_uS;
  deviation = microseconds_taken - 100000;
  AsciiPrint("Deviation from 100 ms was (in usec): %d\n", (UINT32)deviation);


  // Log Message
  LogMsg("Waiting for 100ms");
  gBS->Stall(100000);
  LogMsg("Done");


  // Fall through
ExitHandler:
  TestStatus("QcomBaseLibTest",Status);
  TEST_STOP("QcomBaseLibTest");
  return Status;
}
