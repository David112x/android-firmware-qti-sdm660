#ifndef __IHMAC_H
#define __IHMAC_H

// AUTOGENERATED FILE: DO NOT EDIT

#include <stdint.h>
#include "object.h"

// Copyright (c) 2015 Qualcomm Technologies, Inc.  All Rights Reserved.

// Qualcomm Technologies Proprietary and Confidential.

#define IHmac_PARAM_KEY INT32_C(1)
#define IHmac_PARAM_INVALID INT32_C(-1)
#define IHmac_SIZE_SHA1 INT32_C(20)
#define IHmac_SIZE_SHA256 INT32_C(32)
#define IHmac_SIZE_INVALID INT32_C(-1)
#define IHmac_DIGEST_SIZE_SHA1 INT32_C(20)
#define IHmac_DIGEST_SIZE_SHA256 INT32_C(32)

#define IHmac_OP_update 0
#define IHmac_OP_final 1
#define IHmac_OP_setParamAsData 2

static inline int32_t
IHmac_release(Object self)
{
  return Object_invoke(self, Object_OP_release, 0, 0);
}

static inline int32_t
IHmac_retain(Object self)
{
  return Object_invoke(self, Object_OP_retain, 0, 0);
}

static inline int32_t
IHmac_update(Object self, const void *msg_ptr, size_t msg_len)
{
  ObjectArg a[1];
  a[0].bi = (ObjectBufIn) { msg_ptr, msg_len * 1 };

  return Object_invoke(self, IHmac_OP_update, a, ObjectCounts_pack(1, 0, 0, 0));
}

static inline int32_t
IHmac_final(Object self, void *digest_ptr, size_t digest_len, size_t *digest_lenout)
{
  ObjectArg a[1];
  a[0].b = (ObjectBuf) { digest_ptr, digest_len * 1 };

  int32_t result = Object_invoke(self, IHmac_OP_final, a, ObjectCounts_pack(0, 1, 0, 0));

  *digest_lenout = a[0].b.size / 1;

  return result;
}

static inline int32_t
IHmac_setParamAsData(Object self, int32_t paramID_val, const void *param_ptr, size_t param_len)
{
  ObjectArg a[2];
  a[0].b = (ObjectBuf) { &paramID_val, sizeof(int32_t) };
  a[1].bi = (ObjectBufIn) { param_ptr, param_len * 1 };

  return Object_invoke(self, IHmac_OP_setParamAsData, a, ObjectCounts_pack(2, 0, 0, 0));
}


#endif /* __IHMAC_H */
