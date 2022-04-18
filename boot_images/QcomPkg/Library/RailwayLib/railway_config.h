/*===========================================================================

  railway_config.h - data related to platform-specific customization

  Copyright (c) 2012 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ===========================================================================*/

#ifndef RAILWAY_CONFIG_H
#define RAILWAY_CONFIG_H

#include "railway.h"
#include "railway_internal.h"

typedef void (*railway_static_cb_type)(uint32);

typedef enum
{
    RAILWAY_RAIL_TYPE_MX = 0,  // Shall be >= logical rails
    RAILWAY_RAIL_TYPE_LOGIC,   // Shall be <= Mx rail
    RAILWAY_RAIL_TYPE_EBI,     // Shall be == Mx rail if votes > rentention
    RAILWAY_RAIL_TYPE_WLAN,
                               // Otherwise, shall be in retention voltage
    RAILWAY_RAIL_TYPES_COUNT,
} railway_rail_type_t;

typedef struct
{
    const char        *vreg_name;

    enum
    {
    RAILWAY_SMPS_TYPE,
    RAILWAY_LDO_TYPE,
    }                 pmic_rail_type;

    uint8             pmic_chip_id;
    uint8             pmic_peripheral_index;

    railway_corner    initial_corner; // Which corner to vote for out of the box (no votes received yet).
    uint32            default_retention_uv; // default retention voltage in microvolt
} railway_rail_config_t;

typedef struct
{
    int                    num_rails;
    railway_rail_config_t *rails;
} railway_config_data_t;

extern const railway_config_data_t * const RAILWAY_CONFIG_DATA;

#endif // RPM_CONFIG_H
