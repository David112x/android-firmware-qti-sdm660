/**
 * @file:  cpr_measurements.c
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * QUALCOMM Proprietary and Confidential.
 *
 * $DateTime: 2016/11/30 21:09:27 $
 * $Header: //components/rel/rpm.bf/1.8/core/power/cpr/common/src/cpr_measurements.c#2 $
 * $Change: 11885425 $
 */
#include "cpr_measurements.h"
#include "cpr_logs.h"
#include "cpr_rail.h"
#include "cpr_image.h"
#include "cpr_utils.h"
#include "string.h"

#define NUM_AGING_RUNS  10
#define MAX_AGING_RETRY 2

// This is for debugging purpose
static volatile int32 cpr_aging_delta_results[NUM_AGING_RUNS];


void cpr_measurements_settle(cpr_rail* rail, cpr_voltage_mode mode)
{
    boolean changed;
    cpr_results rslts;
    uint32 railIdx = rail->railIdx;
    uint32 modeIdx = cpr_utils_get_mode_idx(rail, mode);
    cpr_domain_info info = {CPR_DOMAIN_TYPE_MODE_BASED, {mode}};

    cpr_mode_settings* modeSettings = &cpr_info.railStates[railIdx].modeSettings[modeIdx];

    cpr_utils_set_active_mode_setting(rail->id, modeSettings, NULL);

    // we want to settle in the middle of our down and up thresholds.
    const cpr_hal_thread_cfg *tCfg   = rail->hal.thread->cfg;
    const int settle_steps_threshold = tCfg->dnThresh - ((tCfg->dnThresh + tCfg->upThresh) / 2);
    CPR_ASSERT(settle_steps_threshold >= 0);   //For now, only support configs where dn_threshold >= up_threshold.

    if(cpr_image_set_rail_mode( rail->id, &info ))
    {
        cpr_image_enable_measurements(rail, CPR_MEASUREMENT_TYPE_SETTLE);

        // make sure to disable CPR before configuring target quotients
        cpr_hal_disable_rail( &rail->hal );
        cpr_hal_set_targets( &rail->hal, mode, 0, modeSettings->targets, modeSettings->targetsCount );
        cpr_hal_start_poll( &rail->hal );

        do {
            cpr_image_wait(1000); // need at least 1 msec before reading result based on observation
            CPR_ASSERT( cpr_hal_get_results( &rail->hal, &rslts, RESULTS_TIMEOUT_20MS ) );
            changed = cpr_rail_process_results( rail, &rslts );
            cpr_hal_clear_interrupts( &rail->hal );
        }
        while(rslts.down && (rslts.steps > settle_steps_threshold) && changed);

        cpr_hal_stop_poll( &rail->hal );

        cpr_image_disable_measurements(rail, CPR_MEASUREMENT_TYPE_SETTLE);
    }
    else
    {
        CPR_LOG_WARNING(" Failed to settle on mode %d", mode);
    }

    // Restore original mode
    cpr_mode_settings* prevModeSettings = cpr_utils_get_previous_mode_setting(rail->id);

    info.u.mode = prevModeSettings == NULL ? CPR_VOLTAGE_MODE_OFF : prevModeSettings->mode;
    cpr_image_set_rail_mode( rail->id, &info );

    cpr_utils_set_active_mode_setting(rail->id, prevModeSettings, NULL);

    CPR_STATIC_LOG_RAIL_INFO(&cpr_info.railStates[railIdx]);
}

__attribute__((section("cpr_dram_reclaim_pool")))
void cpr_measurements_thermal_update(cpr_thermal_region region)
{
    CPR_IMAGE_LOCK_CORE();

    for(int i = 0; i < cpr_utils_get_num_rails(); i++)
    {
        cpr_rail_state* railState = &cpr_info.railStates[i];
        cpr_rail* rail = cpr_utils_get_rail( railState->id );

        if(!cpr_utils_is_closed_loop_mode(railState->id)) {
            continue;
        }

        CPR_LOG_INFO( "Thermal adjustment on %s. Region: %u", rail->name, region );

        railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_THERMAL] = rail->enablement->thermalAdjustment[region];
        cpr_rail_calculate_target_quotients( rail, railState );

        if(railState->activeMode != NULL) {
            cpr_rail_enable( rail, railState->activeMode, railState->activeMode->activeSubMode, true );
        }

        CPR_STATIC_LOG_RAIL_INFO(railState);
    }

    CPR_IMAGE_UNLOCK_CORE();
}

static boolean cpr_measurements_get_aging_delta(cpr_rail* rail, const cpr_aging_cfg* aging_cfg, int32 *avg_aging_delta)
{
    int32   sum            = 0;
    uint32  retry_count    = 0;
    int32   num_valid_runs = 0;
    boolean ret            = true;

    cpr_image_enable_measurements(rail, CPR_MEASUREMENT_TYPE_AGING);

    /*
     * HPG recommends to do at least 10 times measurement and get average of delta.
     */
    for(int i = 0; i < NUM_AGING_RUNS && retry_count < MAX_AGING_RETRY; i++)
    {
        int32 aging_delta = 0;

        cpr_hal_enable_aging(&rail->hal, aging_cfg);

        if(cpr_hal_get_aging_delta(&rail->hal, &aging_delta, &retry_count))
        {
            cpr_aging_delta_results[i] = aging_delta; /* for debug */

            sum += aging_delta;
            num_valid_runs++;
        }
        else
        {
            cpr_aging_delta_results[i] = 0xDEADDEAD; /* for debug */
        }

        cpr_hal_disable_aging(&rail->hal, aging_cfg);
    }

    cpr_image_disable_measurements(rail, CPR_MEASUREMENT_TYPE_AGING);

    if(retry_count < MAX_AGING_RETRY && num_valid_runs > 0)
    {
        /*
         * TODO: Need to refine how to get average aging delta.
         *
         * Noticed that there were outliners due to SEL_MAX value but
         * HPG does not specify how to remove outliners.
         * For now, we simply calculate average by sum / # of runs.
         */

        /* Rounding fraction */
        int32 rounding = (sum >= 0) ? (num_valid_runs/2) : -(num_valid_runs/2);

        *avg_aging_delta = (sum + rounding) / num_valid_runs;

        CPR_LOG_INFO("Avg. Aging Delta: %d (Sum: %d) (Runs: %d/%d) (Retry: %d)",
                     *avg_aging_delta, sum, num_valid_runs, NUM_AGING_RUNS, retry_count);
    }
    else
    {
        CPR_LOG_WARNING("Failed to get aging delta (Runs: %d/%d) (Retry: %d/%d)",
                        num_valid_runs, NUM_AGING_RUNS, retry_count, MAX_AGING_RETRY);
        ret = false;
    }

    return ret;
}

static int32 cpr_measurements_calculate_aging_margin(const cpr_aging_cfg* aging_cfg, int32 max_aging_delta)
{
    // check aging_ro_kv_x100 is not 0
    CORE_VERIFY(aging_cfg->kv);

    // ( max_age_delta * 100 / aging_kv_ro_x100 )
    int32 aging_margin_uv = (max_aging_delta * 100) / aging_cfg->kv;

    // The aging_cfg->scalingFactor is x10 value of the Derate Scaling Factor in Voltage Plan.
    // Need to divide it by 10. Aging margin is represented in uv
    aging_margin_uv = (((aging_margin_uv * aging_cfg->scalingFactor) / 10) * 1000);

    // limit to aging_margin_limit
    return MIN(aging_cfg->marginLimit, aging_margin_uv);
}

void cpr_measurements_aging(cpr_rail* rail)
{
    const cpr_versioned_voltage_plan* vvp = cpr_utils_get_versioned_voltage_plan(rail->id);
    cpr_rail_state* railState = cpr_utils_get_rail_state( rail->id );
    const cpr_aging_cfg* agingCfg;
    int32 initial_delta;
    int32 current_delta;

    //return early if aging is not supported
    if(!vvp || !vvp->agingCfg || (cpr_info.cprRev < vvp->agingCfg->cprRevMinToRun))
    {
        CPR_LOG_WARNING("Aging not supported for %s rail", rail->name);

        railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_AGING] = 0;
        return;
    }

    agingCfg = vvp->agingCfg;

    /*
     * Read initial aging delta from fuse.  Delta could be negative.
     */
    initial_delta = cpr_utils_decode_fuse_value(&agingCfg->fuse, agingCfg->fusePackingFactor, true);
    railState->decodedFuseAging = initial_delta;

    CPR_LOG_INFO("Initial aging delta: %d (PackingFactor: %d)", initial_delta, agingCfg->fusePackingFactor);

    /*
     * CR 1088051:
     * The fuse value 0 is valid now and cannot be used to check if PTE has enabled fuse on the part.
     * cprRevMinToRun field was added to aging config to determine if de-aging should run.
     */
#if 0
    //check to see if PTE has enabled fuse on this part, if not, disable aging
    if(initial_delta == 0)
    {
        CPR_LOG_WARNING("Aging fuse not programmed");

        railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_AGING] = 0;
        return;
    }
#endif

    /*
     * Set voltage mode to specified mode for aging.
     * The ceiling voltage of the mode must be set to global ceiling (SS voltage)
     * and not open loop.
     */
    cpr_domain_info info = {CPR_DOMAIN_TYPE_MODE_BASED, {agingCfg->modeToRun}};

    CPR_LOG_INFO("Aging init: set %s rail mode to %u", rail->name, agingCfg->modeToRun);

    if(!cpr_image_set_rail_mode( rail->id, &info ))
    {
        CPR_LOG_FATAL(" Failed to set %s rail mode to %u", rail->name, agingCfg->modeToRun);
        return;
    }

    /*
     * Find the delta between AGE_MAX and AGE_MIN and compare with FUSED_SKEW
     */
    if(cpr_measurements_get_aging_delta(rail, agingCfg, &current_delta))
    {
        int32 max_age_delta = current_delta - initial_delta;

        /*
         * Find the amount of adjustment in Voltage domain based on
         * the current_delta and AGE_RO_KV
         */
        if(max_age_delta > 0)
        {
            /*
             * calculate margin adjustment
             */
            railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_AGING] = cpr_measurements_calculate_aging_margin(agingCfg, max_age_delta);
        }
        else
        {
            // no AGE adjustment needed
            railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_AGING] = 0;
        }
    }
    else
    {
        /*
         * Failed to get aging delta.
         * Set the aging compensation to max.
         */
        railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_AGING] = agingCfg->marginLimit;
    }

    CPR_LOG_INFO("Aging margin: %d", railState->marginAdjustments[CPR_MARGIN_ADJUSTMENT_AGING]);

    /*
     * reset voltage mode
     */
    info.u.mode = CPR_VOLTAGE_MODE_OFF;

    CPR_LOG_INFO("Aging cleanup: set %s rail mode to %u", rail->name, info.u.mode);

    cpr_image_set_rail_mode( rail->id, &info );

    CPR_STATIC_LOG_RAIL_INFO(railState);
}

