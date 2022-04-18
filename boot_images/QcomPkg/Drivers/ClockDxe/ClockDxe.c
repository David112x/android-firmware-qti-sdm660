/** @file ClockDxe.c

  This file implements clock EFI protocol interface.

  Copyright (c) 2010-2011,2014-2015 Qualcomm Technologies, Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 10/18/14   jb      Added DAL initialization
 05/01/14   asmitp  Renamed header file DALSYSProtocol.h to EFIDALSYSProtocol.h
 12/23/10   vs      Created.

=============================================================================*/


/*=========================================================================
      Include Files
==========================================================================*/

#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Protocol/EFIDALSYSProtocol.h>
#include <Protocol/EFIClock.h>
#include "DALDeviceId.h"
#include "DDIClock.h"


/*=========================================================================
      Type Definitions
==========================================================================*/


/*=========================================================================
      Function Prototypes
==========================================================================*/

EFI_STATUS EFI_GetClockID(IN EFI_CLOCK_PROTOCOL *This,
                          IN CONST CHAR8 *ClockName, OUT UINTN *ClockId);
EFI_STATUS EFI_EnableClock(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId);
EFI_STATUS EFI_DisableClock(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId);
EFI_STATUS EFI_IsClockEnabled(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                              OUT BOOLEAN *IsEnabled);
EFI_STATUS EFI_IsClockOn(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                         OUT BOOLEAN *IsOn);
EFI_STATUS EFI_SetClockFreqHz(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                              IN UINT32 FreqHz,
                              IN EFI_CLOCK_FREQUENCY_TYPE  Match,
                              OUT UINT32 *ResultFreqHz);
EFI_STATUS EFI_GetClockFreqHz(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                              OUT UINT32 *FreqHz);
EFI_STATUS EFI_CalcClockFreqHz(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                               OUT UINT32 *FreqHz);
EFI_STATUS EFI_SelectExternalSource(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                                    IN UINT32 FreqHz, IN UINT32 Source,
                                    IN UINT32 Divider, IN UINT32 VAL_M,
                                    IN UINT32 VAL_N, IN UINT32 VAL_2D);
EFI_STATUS EFI_SetExternalSourceDiv(IN EFI_CLOCK_PROTOCOL *This,
                                    IN CONST CHAR8 *ClockName, IN UINT32 Divider);
EFI_STATUS EFI_GetClockPowerDomainID(IN EFI_CLOCK_PROTOCOL *This,
                                     IN CONST CHAR8 *ClockPowerDomainName,
                                     OUT UINTN *ClockPowerDomainId);
EFI_STATUS EFI_EnableClockPowerDomain(IN EFI_CLOCK_PROTOCOL *This,
                                      IN UINTN ClockPowerDomainId);
EFI_STATUS EFI_DisableClockPowerDomain(IN EFI_CLOCK_PROTOCOL *This,
                                       IN UINTN ClockPowerDomainId);
EFI_STATUS EFI_EnterLowPowerMode(IN EFI_CLOCK_PROTOCOL *This);
EFI_STATUS EFI_ExitLowPowerMode(IN EFI_CLOCK_PROTOCOL *This);
EFI_STATUS EFI_SetClockDivider(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                               IN UINT32 Divider);
EFI_STATUS EFI_ResetClock(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                          IN EFI_CLOCK_RESET_TYPE eReset);

EFI_STATUS EFI_GetCpuFreqHz(IN EFI_CLOCK_PROTOCOL *This, OUT UINT32 *FreqHz);

/*=========================================================================
      Data Declarations
==========================================================================*/

// Clock Public Protocol
static EFI_CLOCK_PROTOCOL ClockProtocol =
{
   EFI_CLOCK_PROTOCOL_VERSION,
   EFI_GetClockID,
   EFI_EnableClock,
   EFI_DisableClock,
   EFI_IsClockEnabled,
   EFI_IsClockOn,
   EFI_SetClockFreqHz,
   EFI_GetClockFreqHz,
   EFI_CalcClockFreqHz,
   EFI_SelectExternalSource,
   EFI_GetClockPowerDomainID,
   EFI_EnableClockPowerDomain,
   EFI_DisableClockPowerDomain,
   EFI_EnterLowPowerMode,
   EFI_ExitLowPowerMode,
   EFI_SetClockDivider,
   EFI_ResetClock,
   EFI_GetCpuFreqHz,
   EFI_SetExternalSourceDiv
};

static DalDeviceHandle *hClock = NULL;

DALProps gDALModStringDeviceInfoList = {NULL, 0 ,0 , NULL};

/*==============================================================================

                     GLOBAL VARIABLES FOR THIS MODULE

==============================================================================*/
extern DALREG_DriverInfo DALClock_DriverInfo;

static DALREG_DriverInfo * DALDriverInfoArr[1] = { &DALClock_DriverInfo };

static DALSYSConfig DALSYSModConfig =
   {
      {0, NULL},              // string device info
      {1, DALDriverInfoArr}   // numeric driver info
   };

/*=========================================================================
      Functions
==========================================================================*/


/**
  Looks-up a clock id given a clock name.

  This function takes the name of a clock, and will return a handle that
  can be used for making requests on that clock.  This function will generally
  need to be the first to be invoked prior to using any other clock APIs.
  The string name of the clock can be found in the clock chapter of the
  chip HLD.  For example, "cc_uart2_clk".

  @param  This      [in]        The EFI_CLOCK_PROTOCOL instance.
  @param  ClockName [in]        String name of the clock.
  @param  ClockId   [out]       Pointer to fill in with the clock id.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_GetClockID(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  CONST CHAR8        *ClockName,
   OUT UINTN              *ClockId)
{
  DALResult eResult;

  if (ClockId == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_GetClockId(hClock,  ClockName,  (ClockIdType *)ClockId);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}

/**
  Set a clock external source Divider given a clock name.

  This function takes the name of a clock, and will Set a clock external source Divider
  associated to that clock.
  The string name of the clock can be found in the clock chapter of the
  chip HLD.  For example, "cc_uart2_clk".

  @param  This      [in]        The EFI_CLOCK_PROTOCOL instance.
  @param  ClockName [in]        String name of the clock.
  @param  nDivider  [in]        The divider to be set.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS EFI_SetExternalSourceDiv(
	IN EFI_CLOCK_PROTOCOL *This,
    IN CONST CHAR8 *ClockName,
    IN UINT32 nDivider)
{
  DALResult eResult;

  if (ClockName == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_SetExternalSourceDiv(hClock,  ClockName,  nDivider);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Enables a clock.

  This function will enable the given clock.  It does not reference count
  recursive calls, but does do tracking between multiple clients.

  @param  This    [in]          The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId [in]          Clock to enable.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_EnableClock(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockId)
{
  DALResult eResult;
  eResult = DalClock_EnableClock(hClock,  (ClockIdType)ClockId);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Disables a clock.

  This function will remove the client's vote to enable the given clock.
  There is no support for reference counting recursive calls, however the
  driver will not disable the clock if a different client has made an
  "enable" request.

  @param  This    [in]          The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId [in]          Clock to disable.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_DisableClock(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockId)
{
  DALResult eResult;
  eResult = DalClock_DisableClock(hClock,  (ClockIdType)ClockId);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Check the enabled state of a clock.

  This function checks if the given clock is enabled or disabled.  Note
  that this is not necessarily equivalent to the clock being active.  A
  clock may be disabled by the local processor, but enabled by another one.
  Or if the hardware is misconfigured the clock may be enabled, but not
  actively toggling.

  @param  This      [in]        The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId   [in]        Clock to check.
  @param  IsEnabled [out]       Return 1 if clock is enabled, 0 otherwise.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_IsClockEnabled(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT BOOLEAN            *IsEnabled)
{

  if (IsEnabled == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  *IsEnabled = (BOOLEAN)DalClock_IsClockEnabled(hClock,  (ClockIdType)ClockId);

  return EFI_SUCCESS;
}


/**
  Check if a clock is on or not.

  This function checks if the given clock is on or not.  "On"
  means the clock is not just enabled, but is actually toggling.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  IsOn     [out]        Return 1 if clock is ON, 0 otherwise.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_IsClockOn(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT BOOLEAN            *IsOn)
{

  if (IsOn == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  *IsOn = (BOOLEAN)DalClock_IsClockOn(hClock,  (ClockIdType)ClockId);

  return EFI_SUCCESS;
}


/**
  Sets the frequency of a clock.

  This function will request a frequency change for the given clock.  The
  driver will select the exact frequency based on the matching argument,
  which allows requesting a minimum or approximate frequency for
  example. There is no support for concurrent requests - the
  last request will be serviced and override any other minimum
  frequency requests.

  @param  This         [in]     The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId      [in]     Clock to set frequency of.
  @param  Freq         [in]     Clock frequency
  @param  Match        [in]     Type of match request:
                                0 - Frequency is a minimum allowed
                                1 - Frequency is a maximum allowed
                                2 - Closest match
                                3 - Exact match only
  @param  ResultFreq   [out]    The programmed clock frequency,
                                can be NULL if resulting
                                frequency does not need to be
                                checked.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_SetClockFreqHz(
   IN  EFI_CLOCK_PROTOCOL        *This,
   IN  UINTN                     ClockId,
   IN  UINT32                    Freq,
   IN  EFI_CLOCK_FREQUENCY_TYPE  Match,
   OUT UINT32                   *ResultFreq)
{

  DALResult eResult;

  if (ResultFreq == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_SetClockFrequency(hClock,
                                       (ClockIdType)ClockId,
                                       (uint32)Freq,
                                       (ClockFrequencyType)Match,
                                       (uint32 *)ResultFreq);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Get the frequency of a clock.

  This function retrieves the current frequency of a clock in Hertz.  This
  is independent of if the clock is running or not.  Note only clocks
  controlled on the local processor can have the frequency retrieved.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  FreqHz   [out]        Pointer to uint32 to fill
                                in with the frequency. A value
                                of zero indicates the frequency
                                could not be determined.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_GetClockFreqHz(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT UINT32             *FreqHz)
{

  DALResult eResult;

  if (FreqHz == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_GetClockFrequency(hClock,
                                       (ClockIdType)ClockId,
                                       (uint32 *)FreqHz);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Calculate the frequency of a clock.

  This function calculates the current frequency of a clock in Hertz using
  hardware counting circuits.  This functionality depends on this hardware
  support being present, as well as available on the current processor.  It
  also requires that the clock be enabled, which must be possible from
  the current environment.
  The frequency calculation is accurrate to within a few KHz.
  The calculation takes a long time (at least a few milliseconds) and
  is intended only for testing purposes, not any real modes of operation.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  FreqHz   [out]        Pointer to uint32 to fill
                                in with the frequency. A value
                                of zero indicates the frequency
                                could not be determined.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_CalcClockFreqHz(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT UINT32             *FreqHz)
{

  DALResult eResult;

  if (FreqHz == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_CalcClockFrequency(hClock,
                                       (ClockIdType)ClockId,
                                       (uint32 *)FreqHz);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Select an external source for a clock.

  This function will select an external source for a clock, and configure
  the clock generator dividers.  This is only necessary for clock domains
  that can be derived from a source outside of the clock block such that
  EFI_SetClockFreqHz cannot be used.
  Note that the caller must specify a non-zero value for the source clock's
  frequency if the caller expects the clock driver to provide voltage scaling
  support.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  FreqHz   [in]         Source frequency in Hz. The value '0' indicates that
                                voltage scaling is not expected for this source.
  @param  Source   [in]         Source to use.  Pass the following values:
                                0 - to select the first (or only) external source.
                                1 - to select the second external source.
                                2 - etc.
  @param  Divider  [in]         The integer divider to use.
  @param  VAL_M    [in]         The "M" value for any M/N counter (0 to bypass).
                                Not all clock domains have M/N counters,and these values
                                will be ignored.
  @param  VAL_N    [in]         The "N" value for any M/N counter.
  @param  VAL_2D   [in]         Twice the "D" value for any M/N counter.
                                The raw value is doubled to allow for
                                half-integer duty cycles.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
*/

EFI_STATUS
EFI_SelectExternalSource(
    IN EFI_CLOCK_PROTOCOL *This,
    IN UINTN              ClockId,
    IN UINT32             FreqHz,
    IN UINT32             Source,
    IN UINT32             Divider,
    IN UINT32             VAL_M,
    IN UINT32             VAL_N,
    IN UINT32             VAL_2D)
{
  DALResult eResult;

  eResult = DalClock_SelectExternalSource(hClock,
                                          (ClockIdType)ClockId,
                                          (uint32) FreqHz,
                                          (uint32) Source,
                                          (uint32) Divider,
                                          (uint32) VAL_M,
                                          (uint32) VAL_N,
                                          (uint32) VAL_2D);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Looks up a Power Domain ID for a specified power domain name.

  This function takes the name of a power domain and returns a handle that
  can be used for making requests on that power domain. Usually, this function
  must be the first to be invoked prior to using any other power domain functions.
  The string name of the clock can be found in the software frequency
  plan, e.g., VDD_GRP.

  @param[in]  This                   Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]  ClockPowerDomainName   String name of the power domain.
  @param[out] ClockPowerDomainId     Pointer where to fill in the power domain ID.

  @return EFI_SUCCESS                The function completed successfully.
  @return EFI_PROTOCOL_ERROR         The function had a protocol error.
**/

EFI_STATUS
EFI_GetClockPowerDomainID(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  CONST CHAR8        *ClockPowerDomainName,
   OUT UINTN              *ClockPowerDomainId)
{
  DALResult eResult;

  if (ClockPowerDomainId == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_GetPowerDomainId(hClock, ClockPowerDomainName, (ClockPowerDomainIdType *)ClockPowerDomainId);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Enables a specified power domain.

  @param  This               [in]    The EFI_CLOCK_PROTOCOL instance.
  @param  ClockPowerDomainId [in]    Power Domain to enable.

  @return EFI_SUCCESS                The function completed successfully.
  @return EFI_PROTOCOL_ERROR         The function had a protocol error.
**/

EFI_STATUS
EFI_EnableClockPowerDomain(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockPowerDomainId)
{
  DALResult eResult;
  eResult = DalClock_EnablePowerDomain(hClock,  (ClockPowerDomainIdType)ClockPowerDomainId);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Disables a power domain.

  @param  This               [in]    The EFI_CLOCK_PROTOCOL instance.
  @param  ClockPowerDomainId [in]    Power Domain to disable.

  @return EFI_SUCCESS                The function completed successfully.
  @return EFI_PROTOCOL_ERROR         The function had a protocol error.
**/

EFI_STATUS
EFI_DisableClockPowerDomain(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockPowerDomainId)
{
  DALResult eResult;
  eResult = DalClock_DisablePowerDomain(hClock,  (ClockPowerDomainIdType)ClockPowerDomainId);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Enter the low power mode.

  This function is used to enter a low power state that facilitates
  rapid battery charging.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
*/

EFI_STATUS
EFI_EnterLowPowerMode(
    IN EFI_CLOCK_PROTOCOL *This)
{
  DALResult eResult;

  eResult = DalClock_EnterLowPowerMode(hClock);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Exit the low power mode.

  This function restores the state of the SoC to the state it was in before
  it entered a low power state that facilitates rapid battery charging.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
*/

EFI_STATUS
EFI_ExitLowPowerMode(
    IN EFI_CLOCK_PROTOCOL *This)
{
  DALResult eResult;

  eResult = DalClock_ExitLowPowerMode(hClock);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Sets the divider for a clock.

  This function programs the divider for a specified clock. This
  functionality only applies to a small subset of clocks that have
  independent dividers off the main domain.

  @param  This         [in]     The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId      [in]     Clock to set divider of.
  @param  Divider      [in]     Clock divider.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_SetClockDivider(
   IN  EFI_CLOCK_PROTOCOL        *This,
   IN  UINTN                     ClockId,
   IN  UINT32                    Divider)
{

  DALResult eResult;

  eResult = DalClock_SetClockDivider(hClock,
                                     (ClockIdType)ClockId,
                                     (uint32)Divider);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  Resets a specified clock's hardware.

  This function allows resetting the hardware in a specified clock domain. The
  resetting is destructive to the hardware and requires reconfiguration
  after the reset is deasserted.

  @param  This    [in]          The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId [in]          Clock to reset.
  @param  eReset  [in]          Type of reset: assert, deassert, or pulse.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_ResetClock(
   IN EFI_CLOCK_PROTOCOL   *This,
   IN UINTN                 ClockId,
   IN EFI_CLOCK_RESET_TYPE  eReset)
{
  DALResult eResult;
  eResult = DalClock_ResetClock(hClock, (ClockIdType)ClockId, (ClockResetType)eReset);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}

/**
  Get the frequency of a current CPU clock.

  This function retrieves the current running frequency of a CPU clock in Hertz.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  FreqHz   [out]        Pointer to uint32 to fill
                                in with the frequency. A value
                                of zero indicates the frequency
                                could not be determined.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_GetCpuFreqHz(
   IN  EFI_CLOCK_PROTOCOL *This,
   OUT UINT32             *FreqHz)
{

  DALResult eResult;

  if (FreqHz == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalClock_GetCpuFrequency(hClock,
                                    (uint32 *)FreqHz);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}

/**
  Clock DXE driver entry point.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/

EFI_STATUS
EFIAPI
ClockDxeEntryPoint (
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  EFI_HANDLE  handle = NULL;
  EFI_STATUS  status;
  DALResult   eResult;

  // Init DALSys
  DALSYS_InitMod(&DALSYSModConfig);

  //Attach to the clock DAL
  eResult = DAL_DeviceAttach(DALDEVICEID_CLOCK, &hClock);
  if(eResult == DAL_SUCCESS)
  {
    // Publish the DALSYS Protocol
    status = gBS->InstallMultipleProtocolInterfaces(
                    &handle,
                    &gEfiClockProtocolGuid,
                    (void **)&ClockProtocol, NULL );
  }
  else
  {
    DALSYS_DeInitMod();
    status = EFI_PROTOCOL_ERROR;
  }

  return status;
}

