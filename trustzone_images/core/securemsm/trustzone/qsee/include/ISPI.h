#ifndef __ISPI_H
#define __ISPI_H

// AUTOGENERATED FILE: DO NOT EDIT

#include <stdint.h>
#include "object.h"

// Copyright (c) 2015-16 Qualcomm Technologies, Inc.  All Rights Reserved.

// Qualcomm Technologies Proprietary and Confidential.

//----------------------------------------------------------

//  Corresponds to qsee_spi_config_t.

//----------------------------------------------------------

/** @brief Structure that is used for SPI configuration. */

typedef struct {
  int32_t clkPolarity;
  int32_t clkAlwaysOn;
  int32_t csPolarity;
  int32_t csMode;
  int32_t shiftMode;
  int32_t bitsPerWord;
  int32_t maxFreq;
  int32_t hsMode;
  int32_t loopBack;
  int32_t slaveIndex;
  int32_t deassertionTime;
} ISPI_Config;

#define ISPI_CLK_POLARITY_INVALID INT32_C(0)
#define ISPI_CLK_POLARITY_IDLE_LOW INT32_C(1)
#define ISPI_CLK_POLARITY_IDLE_HIGH INT32_C(2)
#define ISPI_CLK_MODE_INVALID INT32_C(0)
#define ISPI_CLK_MODE_NORMAL INT32_C(1)
#define ISPI_CLK_MODE_ALWAYS_ON INT32_C(2)
#define ISPI_CS_POLARITY_INVALID INT32_C(0)
#define ISPI_CS_POLARITY_ACTIVE_LOW INT32_C(1)
#define ISPI_CS_POLARITY_ACTIVE_HIGH INT32_C(2)
#define ISPI_CS_MODE_INVALID INT32_C(0)
#define ISPI_CS_MODE_DEASSERT INT32_C(1)
#define ISPI_CS_MODE_KEEP_ASSERTED INT32_C(2)
#define ISPI_SHIFT_MODE_INVALID INT32_C(0)
#define ISPI_SHIFT_MODE_INPUT_FIRST INT32_C(1)
#define ISPI_SHIFT_MODE_OUTPUT_FIRST INT32_C(2)

#define ISPI_OP_close 0
#define ISPI_OP_open 1
#define ISPI_OP_read 2
#define ISPI_OP_write 3
#define ISPI_OP_writeFullDuplex 4

static inline int32_t
ISPI_release(Object self)
{
  return Object_invoke(self, Object_OP_release, 0, 0);
}

static inline int32_t
ISPI_retain(Object self)
{
  return Object_invoke(self, Object_OP_retain, 0, 0);
}

static inline int32_t
ISPI_close(Object self, int32_t deviceId_val)
{
  ObjectArg a[1];
  a[0].b = (ObjectBuf) { &deviceId_val, sizeof(int32_t) };

  return Object_invoke(self, ISPI_OP_close, a, ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t
ISPI_open(Object self, int32_t deviceId_val)
{
  ObjectArg a[1];
  a[0].b = (ObjectBuf) { &deviceId_val, sizeof(int32_t) };

  return Object_invoke(self, ISPI_OP_open, a, ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t
ISPI_read(Object self, int32_t deviceId_val, const ISPI_Config *config_ptr, void *data_ptr, size_t data_len, size_t *data_lenout)
{
  ObjectArg a[3];
  a[0].b = (ObjectBuf) { &deviceId_val, sizeof(int32_t) };
  a[1].bi = (ObjectBufIn) { config_ptr, sizeof(ISPI_Config) };
  a[2].b = (ObjectBuf) { data_ptr, data_len * 1 };

  int32_t result = Object_invoke(self, ISPI_OP_read, a, ObjectCounts_pack(2, 1, 0, 0));

  *data_lenout = a[2].b.size / 1;

  return result;
}

static inline int32_t
ISPI_write(Object self, int32_t deviceId_val, const ISPI_Config *config_ptr, const void *data_ptr, size_t data_len, uint64_t *bytesWritten_ptr)
{
  ObjectArg a[4];
  a[0].b = (ObjectBuf) { &deviceId_val, sizeof(int32_t) };
  a[1].bi = (ObjectBufIn) { config_ptr, sizeof(ISPI_Config) };
  a[2].bi = (ObjectBufIn) { data_ptr, data_len * 1 };
  a[3].b = (ObjectBuf) { bytesWritten_ptr, sizeof(uint64_t) };

  return Object_invoke(self, ISPI_OP_write, a, ObjectCounts_pack(3, 1, 0, 0));
}

static inline int32_t
ISPI_writeFullDuplex(Object self, int32_t deviceId_val, const ISPI_Config *config_ptr, const void *data_ptr, size_t data_len, uint64_t *bytesWritten_ptr, void *returnedData_ptr, size_t returnedData_len, size_t *returnedData_lenout)
{
  ObjectArg a[5];
  a[0].b = (ObjectBuf) { &deviceId_val, sizeof(int32_t) };
  a[1].bi = (ObjectBufIn) { config_ptr, sizeof(ISPI_Config) };
  a[2].bi = (ObjectBufIn) { data_ptr, data_len * 1 };
  a[3].b = (ObjectBuf) { bytesWritten_ptr, sizeof(uint64_t) };
  a[4].b = (ObjectBuf) { returnedData_ptr, returnedData_len * 1 };

  int32_t result = Object_invoke(self, ISPI_OP_writeFullDuplex, a, ObjectCounts_pack(3, 2, 0, 0));

  *returnedData_lenout = a[4].b.size / 1;

  return result;
}


#endif /* __ISPI_H */
