/**@file DbiDumpLib.c

  Copyright (c) 2016, Qualcomm Technologies Inc. All rights reserved.<BR>

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 
 --------   ---     -----------------------------------------------------------
 06/13/16   vk      Initial version
=============================================================================*/

#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/ArmLib.h>
#include <Library/IoLib.h>
#include <Protocol/DebugSupport.h>

#include <Include/UefiInfoBlk.h>
#include <Library/SerialPortShLib.h>
#include <Library/UefiCfgLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/DbiDumpLib.h>
#include <Library/CookieLib.h>
#include <Library/WatchdogLib.h>

EFI_STATUS
SetupDBIDumpTable (UINT64 MemoryBase)
{
  EFI_STATUS Status = EFI_SUCCESS;
  UINTN WriteAddr;
  UINT32 WriteValue;
  UINT32 i;
  UINTN NumCores = 0;
  UINT32 SharedIMEMBaseAddr = 0;

  DUMP_TABLE_TYPE *DbiDumpTable = (DUMP_TABLE_TYPE*)(MemoryBase + DBI_DUMP_TABLE_OFFSET);
  DUMP_TABLE_TYPE *AppDumpTable = (DUMP_TABLE_TYPE*)(MemoryBase + DBI_DUMP_TABLE_OFFSET + sizeof(DUMP_TABLE_TYPE));
  DUMP_DATA_TYPE_TABLE *DumpDataTypeTable = (DUMP_DATA_TYPE_TABLE*)(MemoryBase + DBI_DUMP_TABLE_OFFSET + 2*sizeof(DUMP_TABLE_TYPE));
  
  Status = GetConfigValue("NumCpus", (UINT32*)&NumCores);
  if (Status != EFI_SUCCESS)
  {
      DEBUG(( EFI_D_ERROR, "Could not NumCpus uefiplat.cfg Defaulting to 8 cores , Status = (0x%x)\r\n", Status));
      NumCores = 0x08;
  }
  /* Fill out the top level DbiDumpTable version and entries*/
  DbiDumpTable->Version    =    0x1;
  DbiDumpTable->NumEntries =    0x1;

  /* Fill out the second level APP dump table */
  AppDumpTable->Version     =    0x1;
  AppDumpTable->NumEntries  =   NumCores + 1;

  DbiDumpTable->Entries[0].id         = MSM_DUMP_CLIENT_APPS;
  DbiDumpTable->Entries[0].type       = MSM_DUMP_TYPE_TABLE;
  DbiDumpTable->Entries[0].start_addr = (UINT64)AppDumpTable; 
  
  DEBUG ((EFI_D_INFO, "NumCores : %d \n", NumCores));
  
  for (i=0; i < NumCores ; i++)
  {
    DumpDataTypeTable->DumpDataType[i].header.version = 0x0;
    DumpDataTypeTable->DumpDataType[i].header.magic   = 0x0;
    DumpDataTypeTable->DumpDataType[i].start_addr     = MemoryBase + CPU_REG_DUMP_START_OFFSET + i * SDI_DUMP_CORE_AP_REG_SIZE;
    DumpDataTypeTable->DumpDataType[i].len            = SDI_DUMP_CORE_AP_REG_SIZE;
    AppDumpTable->Entries[i].id                       = MSM_CPU_REGS_DUMP + i;
    AppDumpTable->Entries[i].type                     = MSM_DUMP_TYPE_DATA;
    AppDumpTable->Entries[i].start_addr               = (UINT64)(&DumpDataTypeTable->DumpDataType[i]); 
  }

  DumpDataTypeTable->DumpDataType[NumCores].header.version = 0x0;
  DumpDataTypeTable->DumpDataType[NumCores].header.magic   = 0x0;
  DumpDataTypeTable->DumpDataType[NumCores].start_addr     = MemoryBase + CPU_REG_DUMP_END_OFFSET;
  DumpDataTypeTable->DumpDataType[NumCores].len            = SDI_DUMP_ETB_DUMP_SIZE;
  AppDumpTable->Entries[NumCores].id                       = MSM_ETB_DUMP;
  AppDumpTable->Entries[NumCores].type                     = MSM_DUMP_TYPE_DATA;
  AppDumpTable->Entries[NumCores].start_addr               = (UINT64)(&DumpDataTypeTable->DumpDataType[NumCores]);
  
  DumpDataTypeTable->DumpDataType[NumCores + 1].header.version = 0x0;
  DumpDataTypeTable->DumpDataType[NumCores + 1].header.magic   = 0x0;
  DumpDataTypeTable->DumpDataType[NumCores + 1].start_addr     = MemoryBase + CPU_REG_DUMP_END_CHECK_OFFSET;
  DumpDataTypeTable->DumpDataType[NumCores + 1].len            = SDI_DUMP_CORE_AP_REG_SIZE;
  AppDumpTable->Entries[NumCores + 1].id                       = CPU_REG_DUMP_END_CHECK;
  AppDumpTable->Entries[NumCores + 1].type                     = 0x0;
  AppDumpTable->Entries[NumCores + 1].start_addr               = (UINT64)(&DumpDataTypeTable->DumpDataType[NumCores + 1]);

  /* Set the IMEM Cookie with the address to the DbiDumpTable */
  Status = GetConfigValue ("SharedIMEMBaseAddr", (UINT32 *)&SharedIMEMBaseAddr); 
  if ((Status != EFI_SUCCESS) || (SharedIMEMBaseAddr == 0))
  {
    return EFI_UNSUPPORTED;
  }

  /* TODO: Fix this when Shared IMEM table is fixed to support 64-bit addressing */
  WriteAddr = (UINTN) SharedIMEMBaseAddr + DBI_SHARED_IMEM_COOKIE_OFFSET;
  //ASSERT((UINTN) DbiDumpTable < 0xFFFFFFFF);
  WriteValue = ((UINTN)DbiDumpTable & 0xFFFFFFFF);
  MmioWrite32(WriteAddr, WriteValue);

  return EFI_SUCCESS;
}

EFI_STATUS
InitDbiDump(VOID)
{
   EFI_STATUS Status;
   UINT64 DBIDumpDDRBase;
   
   /* Find the address of the DbiDumpTable base */
   Status = GetConfigValue64 ("DBIDumpDDRBase", &DBIDumpDDRBase); 
   if (Status != EFI_SUCCESS ) 
   {
      DEBUG((EFI_D_ERROR, "ERROR: Failed to get valid DBIDumpDDRBase from cfg file\n"));
      return Status;
   }
   
   Status = SetupDBIDumpTable(DBIDumpDDRBase);
   if (Status != EFI_SUCCESS ) 
     DEBUG((EFI_D_ERROR, "ERROR: Failed to set SBI table\n"));

   Status = SetDLOADCookie();
   if (Status != EFI_SUCCESS ) 
     DEBUG((EFI_D_ERROR, "ERROR: Failed to set DLOAD cookie\n"));

   return Status;
}

EFI_STATUS
SaveUefiContext (EFI_SYSTEM_CONTEXT SystemContext)
{
  UefiInfoBlkType* UefiInfoBlkPtr;
  
  UefiInfoBlkPtr = GetInfoBlkPtr();
  if (UefiInfoBlkPtr == NULL) {
    DEBUG((EFI_D_ERROR, "ERROR: Failed to get UefiInfoBlk!\n"));
    return EFI_DEVICE_ERROR;
  }

  UefiInfoBlkPtr->CrashContext = SystemContext;
  return EFI_SUCCESS;
}

