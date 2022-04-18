#ifndef _SPIDEVICETRANSFER_H
#define _SPIDEVICETRANSFER_H
/*
===========================================================================

FILE:   SpiDeviceTransfer.h

DESCRIPTION:

===========================================================================

        Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/buses/spi/src/device/inc/SpiDeviceTransfer.h#1 $

When     Who    What, where, why
-------- ---    -----------------------------------------------------------
12/10/12 ag     Created.
===========================================================================
        Copyright c 2011-2013 Qualcomm Technologies Incorporated.
            All Rights Reserved.
            Qualcomm Proprietary/GTDR

===========================================================================
*/
#include "SpiDevice.h"

typedef enum SpiTransferDataType {
   SPIDEVICE_TRANSFER_SINGLE_BUFF_DATA,
   SPIDEVICE_TRANSFER_LINKED_BUFF_DATA,
}SpiTransferDataType;

typedef enum SpiDeviceTransferDataResult {
   SPIDEVICE_TRANSFER_GET_DATA_SUCCESS,
   SPIDEVICE_TRANSFER_GET_DATA_PARTIAL,
   SPIDEVICE_TRANSFER_GET_DATA_NONE,
   SPIDEVICE_TRANSFER_GET_DATA_DONE,
   SPIDEVICE_TRANSFER_SET_DATA_SUCCESS,
   SPIDEVICE_TRANSFER_SET_DATA_PARTIAL,
   SPIDEVICE_TRANSFER_SET_DATA_NONE,
   SPIDEVICE_TRANSFER_SET_DATA_DONE,
   SPIDEVICE_TRANSFER_BUFF_AVAILABLE,
   SPIDEVICE_TRANSFER_BUFF_LAST,
   SPIDEVICE_TRANSFER_BUFF_NONE,
}SpiDeviceTransferDataResult;

typedef struct SpiDeviceSingleBuffData SpiDeviceSingleBuffData;
struct SpiDeviceSingleBuffData
{
   uint8 *curReadPtr;
   uint8 *curReadPtrPhys;
   uint32 uReadAvail;
   uint8 *curWritePtr;
   uint8 *curWritePtrPhys;
   uint32 uWriteAvail;
};

typedef struct SpiDeviceLinkedBuffData SpiDeviceLinkedBuffData;
struct SpiDeviceLinkedBuffData
{
   SpiBufferType *curReadVector;
   uint8 *curReadPtr;
   uint8 *curReadPtrPhys;
   uint32 uCurReadAvail;
   uint32 uReadVectorAvail;
   SpiBufferType *curWriteVector;
   uint8 *curWritePtr;
   uint8 *curWritePtrPhys;
   uint32 uCurWriteAvail;
   uint32 uWriteVectorAvail;
};

typedef enum spi_direction {
   SPI_IN,
   SPI_OUT,
   SPI_BI_DIRECTIONAL
}spi_direction_t;

typedef struct SpiDeviceTransferType SpiDeviceTransferType;
struct SpiDeviceTransferType
{
   SpiTransferDataType eDataType;
   uint32 uTotalReadLen;
   uint32 uTotalWriteLen;
   spi_direction_t direction;
   /* flag set to TRUE when the output transfer is complete by HW*/
   boolean bWriteTransferDone;
   /* flag set to TRUE when ALL data from user buffer is read*/
   boolean bWriteBufferEmpty;
   /* flag set to TRUE when the input transfer is complete by HW and data
    * written to the input buffer */
   boolean bReadTransferDone;
   /* flag set to TRUE when input data buffer is Full*/
   boolean bReadBufferFull;
   /* the status/result of the transaction */
   int32 transferResult;
   SpiDeviceSingleBuffData sData;
   /*Meant for block and Fifo operations*/
   SpiDeviceTransferDataResult(*getNextWord)(SpiDeviceTransferType *transfer, uint32 *buf);
   SpiDeviceTransferDataResult(*setNextWord)(SpiDeviceTransferType *transfer, uint32 *buf);
   SpiDeviceTransferDataResult(*getNextByte)(SpiDeviceTransferType *transfer, uint8 *buf);
   SpiDeviceTransferDataResult(*setNextByte)(SpiDeviceTransferType *transfer, uint8 *buf);
};

void
SpiDeviceLinkedBufferTransferInit
(
   SpiDeviceTransferType *transfer,
   SpiBufferType *readVector,
   uint32 uNumReadVecs,
   SpiBufferType *writeVector,
   uint32 uNumWriteVecs
   );

void
SpiDeviceSingleBufferTransferInit
(
   SpiDeviceTransferType *transfer,
   uint8 *readBuf,
   uint8 *readBufPhys,
   uint32 uTotalReadLen,
   uint8 *writeBuf,
   uint8 *writeBufPhys,
   uint32 uTotalWriteLen
   );
#endif
