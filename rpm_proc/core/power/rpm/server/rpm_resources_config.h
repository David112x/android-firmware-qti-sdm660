/*===========================================================================

  rpm_resources_config.h - configurations for resources

  Copyright (c) 2015 Qualcomm Technologies, Inc.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================*/

#ifndef RPM_RESOURCES_CONFIG_H
#define RPM_RESOURCES_CONFIG_H

#include <stdint.h>
#include "rpm.h"

typedef struct
{
    rpm_resource_type type;
    unsigned          id;
    unsigned          hashed:1;
    unsigned          reserved:7;
} rpm_resource_config_t;

extern const rpm_resource_config_t * const RESOURCE_CONFIG_DATA;


typedef struct
{
    rpm_resource_type type;
    uint32_t          id;
} rpm_bimc_resource_config_t;

extern const rpm_bimc_resource_config_t * const BIMC_RESOURCE_CONFIG_DATA;

#endif // RPM_RESOURCES_CONFIG_H

