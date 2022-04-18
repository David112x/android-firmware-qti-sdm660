/** @file UefiCfgLib.h
   
  Copyright (c) 2012-2015 Qualcomm Technologies, Inc.  All Rights Reserved.
   
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 04/18/14   vk      Move to MemRegionInfo.h
 10/18/14   jb      Add allocate only declaration
 05/22/14   vk      Revert type change
 05/19/14   vk      GetConfigValue64 support
 10/18/13   vk      Update MemRegionInfo struct members
 06/11/13   niting  Added func to get config value from an input table
 01/15/12   vk      Initial Version

=============================================================================*/
#ifndef __UEFI_CFG_LIB__H__
#define __UEFI_CFG_LIB__H__

#include <Uefi.h>
#include <Pi/PiBootMode.h>
#include <Pi/PiHob.h>
#include <MemRegionInfo.h>
#include <Library/ArmLib.h>

/* Name for the UefiCfg Shared Library Interface */
#define UEFI_CFG_LIB_NAME "UEFI Config Lib"

/* Corresponds to version 1.1
 * MSB 16 bits Major version
 * LSB 16 bits Minor version
 * See note about the versioning and the way Loader works in LOAD_LIB comments
 * In short, if major version is same the lib should be "strictly compatible"
 * with all the previous versions */
#define UEFI_CFG_LIB_VERSION  0x00010002


typedef struct 
{
  CHAR8* Key;
  CHAR8* Value;
} ConfigPair;

/* Typedefs for UefiCfg Shared Library Interface */
typedef EFI_STATUS (*GET_MEM_INFO_BY_NAME) (CHAR8* RegionName, MemRegionInfo* MemRegions);
typedef EFI_STATUS (*GET_CONFIG_STRING) (CHAR8* Key, CHAR8* Value, UINTN* ValBuffSize);
typedef EFI_STATUS (*GET_CONFIG_VAL) (CHAR8* Key, UINT32* Value);
typedef EFI_STATUS (*GET_CONFIG_VAL64) (CHAR8* Key, UINT64* Value);

/* UefiCfg Shared Library Interface */
typedef struct
{
  UINT32                LibVersion; 
  GET_MEM_INFO_BY_NAME  GetMemInfoByName;
  GET_CONFIG_STRING     GetCfgInfoString; 
  GET_CONFIG_VAL        GetCfgInfoVal; 
  GET_CONFIG_VAL64      GetCfgInfoVal64; 
}UefiCfgLibType;

/* Loader function that helps getting the UefiCfgLib interface */
INTN LoadUefiCfgLib (IN  UefiCfgLibType* UefiCfgLibIntfPtr OPTIONAL,
                     IN  UINT32          LibVersion    OPTIONAL);


/**
  Get Memory Region information structure created by parsing the
  platform config file

  @param  RegionName             Pointer to ASCII region name in configuration file
  @param  MemRegionInfo          Pointer to MemRegionInfo, allocated by caller,
                                 returns copy in same struct, cannot be NULL

  @retval EFI_SUCCESS            Successfully retrieved the entry
  @retval EFI_NOT_FOUND          Unable to find specified entry in table
  @retval EFI_NOT_READY          Error: Config SharedLib is not initialized
  @retval EFI_INVALID_PARAMETER  RegionName or MemoryRegion is NULL
**/
EFI_STATUS
EFIAPI
GetMemRegionInfoByName (IN CHAR8* RegionName, IN OUT MemRegionInfo* MemoryRegion);

/**
  Get config string  created by parsing the platform config file

  @param  Key                    Pointer to ASCII parameter to search for in config file
  @param  Value                  On input pointer to buffer used to return value
  @param  ValBuffSize            On input pointer to size of input buffer in bytes
                                 On output size of Value including NULL in bytes

  @retval EFI_SUCCESS            Successfully retrieved the entry
  @retval EFI_NOT_FOUND          Unable to find specified entry in config table
  @retval EFI_NOT_READY          Error: Config SharedLib is not initialized
  @retval EFI_INVALID_PARAMETER  Key or Value is NULL
  @retval EFI_BUFFER_TOO_SMALL   Found the entry, but buffer passed in is too
                                 small to return it, BuffSz will return required size
**/
EFI_STATUS
GetConfigString (IN CHAR8* Key, IN OUT CHAR8* Value, IN OUT UINTN* ValBuffSize);

/**
  Get config value created by parsing the platform config file

  @param  Key                    Pointer to ASCII parameter to search for in config file
  @param  Value                  On input pointer to buffer used to return value

  @retval EFI_SUCCESS            Successfully retrieved the entry
  @retval EFI_NOT_FOUND          Unable to find specified entry in config table
  @retval EFI_NOT_READY          Error: Config SharedLib is not initialized
  @retval EFI_INVALID_PARAMETER  Key or Value is NULL
**/
EFI_STATUS
GetConfigValue (IN CHAR8* Key, IN OUT UINT32* Value);

/**
  Get config value created by parsing the platform config file

  @param  Key                    Pointer to ASCII parameter to search for in config file
  @param  Value                  On input pointer to buffer used to return value

  @retval EFI_SUCCESS            Successfully retrieved the entry
  @retval EFI_NOT_FOUND          Unable to find specified entry in config table
  @retval EFI_NOT_READY          Error: Config SharedLib is not initialized
  @retval EFI_INVALID_PARAMETER  Key or Value is NULL
**/
EFI_STATUS
GetConfigValue64 (IN CHAR8* Key, IN OUT UINT64* Value);

/**
  Get config value from a preparsed config table

  @param  Key                    Pointer to ASCII parameter to search for in config file
  @param  Value                  On input pointer to buffer used to return value 
  @param  ConfigTblPtr           Pointer to the config table. 
  @param  ConfigCnt              Number of items in the config table. 

  @retval EFI_SUCCESS            Successfully retrieved the entry
  @retval EFI_NOT_FOUND          Unable to find specified entry in config table
  @retval EFI_NOT_READY          Error: Config SharedLib is not initialized
  @retval EFI_INVALID_PARAMETER  Key or Value is NULL
**/
EFI_STATUS
GetConfigValFromTable (IN CHAR8* Key, IN OUT UINT32* Value,
                         ConfigPair* ConfigTblPtr, UINTN ConfigCnt);

#endif /* __UEFI_CFG_LIB__H__ */
