#ifndef __IHDMISTATUS_H
#define __IHDMISTATUS_H

// AUTOGENERATED FILE: DO NOT EDIT

#include <stdint.h>
#include "object.h"

// Copyright (c) 2015 Qualcomm Technologies, Inc.  All Rights Reserved.

// Qualcomm Technologies Proprietary and Confidential.

#define IHdmiStatus_OP_hdmiStatusRead 0

static inline int32_t
IHdmiStatus_release(Object self)
{
  return Object_invoke(self, Object_OP_release, 0, 0);
}

static inline int32_t
IHdmiStatus_retain(Object self)
{
  return Object_invoke(self, Object_OP_retain, 0, 0);
}

static inline int32_t
IHdmiStatus_hdmiStatusRead(Object self, uint32_t *hdmiEnable_ptr, uint32_t *hdmiSense_ptr, uint32_t *hdcpAuth_ptr)
{
  ObjectArg a[1];
  struct {
    uint32_t m_hdmiEnable;
    uint32_t m_hdmiSense;
    uint32_t m_hdcpAuth;
  } o;
  a[0].b = (ObjectBuf) { &o, 12 };

  int32_t result = Object_invoke(self, IHdmiStatus_OP_hdmiStatusRead, a, ObjectCounts_pack(0, 1, 0, 0));

  *hdmiEnable_ptr = o.m_hdmiEnable;
  *hdmiSense_ptr = o.m_hdmiSense;
  *hdcpAuth_ptr = o.m_hdcpAuth;

  return result;
}


#endif /* __IHDMISTATUS_H */
