/**
 * @file:  cpr_image_target_init.h
 * @brief:
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * QUALCOMM Proprietary and Confidential.
 *
 * $DateTime: 2016/11/03 00:13:13 $
 * $Header: //components/rel/rpm.bf/1.8/core/power/cpr/image/rpm/target/660/cpr_image_target_init.h#1 $
 * $Change: 11690628 $
 */
#ifndef CPR_IMAGE_TARGET_INIT_H
#define CPR_IMAGE_TARGET_INIT_H

//******************************************************************************
// Default Enablement Structures
//******************************************************************************
struct cpr_cfg_funcs;

typedef enum
{
    CPR_INIT_NONE, /* used to disable CPR */
    CPR_INIT_SMEM,
    CPR_INIT_OPEN_LOOP,
    CPR_INIT_SW_CLOSED_LOOP,

    CPR_INIT_FUNCS_COUNT
} cpr_init_funcs_id;

struct cpr_cfg_funcs* cpr_image_target_get_init_func(cpr_init_funcs_id func_id);

#endif

