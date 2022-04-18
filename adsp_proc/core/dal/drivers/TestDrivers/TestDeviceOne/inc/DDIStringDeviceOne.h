/*=============================================================================	
   Copyright (c) 2008 Qualcomm Technologies Incorporated.	
   All Rights Reserved.
	$Header: //components/rel/core.qdsp6/1.0.c2/dal/drivers/TestDrivers/TestDeviceOne/inc/DDIStringDeviceOne.h#1 $
=============================================================================*/
#ifndef __DALISTRINGDEVICEONE_H__
#define __DALISTRINGDEVICEONE_H__

#include "DalDevice.h"

#define DALSTRINGDEVICE_INTERFACE_VERSION DALINTERFACE_VERSION(1,0)


typedef struct DalStringDevice DalStringDevice;
struct DalStringDevice
{
   struct DalDevice DalDevice;
   DALResult (*ReadTest)(DalDeviceHandle * _h, void * dest_buffer, uint32  blen);
   DALResult (*WriteTest)(DalDeviceHandle * _h, void * src_buffer, uint32  blen);
};

typedef struct DalStringDeviceHandle DalStringDeviceHandle; 
struct DalStringDeviceHandle 
{
   uint32 dwDalHandleId;
   const DalStringDevice * pVtbl;
   void * pClientCtxt;
};

#define DAL_StringDeviceDeviceAttach(DevId,hDalDevice)\
        DAL_DeviceAttachEx(NULL,DevId,DALSTRINGDEVICE_INTERFACE_VERSION,hDalDevice)

static __inline DALResult
DalStringDevice_ReadTest(DalDeviceHandle * _h, void * dest_buffer, uint32  blen)
{
   return ((DalStringDeviceHandle *)_h)->pVtbl->ReadTest( _h, dest_buffer, blen);
}


static __inline DALResult
DalStringDevice_WriteTest(DalDeviceHandle * _h, void * src_buffer, uint32  blen)
{
   return ((DalStringDeviceHandle *)_h)->pVtbl->WriteTest( _h, src_buffer, blen);
}


#endif
