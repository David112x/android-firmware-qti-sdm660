/**
 * @file:  cpr_hal.c
 *
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * QUALCOMM Proprietary and Confidential.
 *
 * $DateTime: 2016/08/19 05:58:45 $
 * $Header: //components/rel/boot.xf/1.4/QcomPkg/Library/CPRLib/common/hal/v3/src/cpr_hal.c#2 $
 * $Change: 11185940 $
 *
 */
#include "cpr_hal.h"
#include "cpr_logs.h"
#include "cpr_data.h"
#include "cpr_image.h"

//******************************************************************************
// Macros / Definitions / Constants
//******************************************************************************

#define ROSC_COUNT 16
#define HAL_CPR_TIMER_DEFAULT_INTERVAL  (5 * 19200)   //5ms * 19.2MHz
#define CPR_DEFAULT_GCNT 19     //We always use 19 since we always run the CPR Ref Clk at 19.2MHz
#define CPR_AGING_ROSC_COUNT 2 //gcnt0 and gcnt1

static uint8 sensor_thread_id;

//******************************************************************************
// Local Helper Functions
//******************************************************************************

__attribute__((noinline))
static void updateBitMask32(uint32 readAddr, uint32 writeAddr, const uint8* bitList, uint32 count, boolean set)
{
    uint32 reg_cur = 0xffffffff; /* 0 is valid value. Use 0xffffffff as invalid value */
    uint32 reg_val = 0;

    for(int i=0; i < count; i++)
    {
        /*
         * Compute the register to write to and bit position
         */
        uint32 reg_new = (bitList[i] / 32);
        uint32 bit     = (bitList[i] % 32);
        uint32 bmask   = (1 << bit);

        /*
         * Write the value to the register before moving to new register
         */
        if(reg_cur != 0xffffffff && reg_new != reg_cur )
        {
            CPR_HWIO_OUT( writeAddr + (sizeof(uint32) * reg_cur), reg_val );
        }

        /*
         * Read the register value if not read yet
         */
        if(reg_cur == 0xffffffff || reg_new != reg_cur )
        {
            reg_val = CPR_HWIO_IN( readAddr + (sizeof(uint32) * reg_new) );
            reg_cur = reg_new;
        }

        /* Mask Sensor */
        if(set) {
            reg_val |= bmask;
        }
        else /* Unmask sensor */ {
            reg_val &= ~bmask;
        }
    }

    /*
     * Write the value to the register
     */
    if(reg_cur != 0xffffffff)
    {
        CPR_HWIO_OUT( writeAddr + (sizeof(uint32) * reg_cur), reg_val );
    }
}

static void updateBitMaskAll32(uint32 readAddr, uint32 writeAddr, uint32 count, boolean set)
{
    uint32 val = (set) ? 0xFFFFFFFF : 0x0;

    for(uint32 i=0, reg=0 ; i < count; i+=32, reg++)
    {
        CPR_HWIO_OUT( writeAddr + (sizeof(uint32) * reg), val );
    }
}

static void cpr_hal_bypass_sensors(cpr_hal_handle* hdl, const uint8* sensors, uint16 count, boolean bypass)
{
    const uintptr_t base = hdl->controller->base;

    updateBitMask32( HWIO_CPR_SENSOR_BYPASS_READn_ADDR( base, 0 ),
                     HWIO_CPR_SENSOR_BYPASS_WRITEn_ADDR( base, 0 ),
                     sensors,
                     count,
                     bypass );
}

#define cpr_hal_bypass_sensor(hdl, sensor, bypass)      cpr_hal_bypass_sensors(hdl, &(sensor), 1, bypass)
#define cpr_hal_add_sensors(hdl, sensors, count)        cpr_hal_bypass_sensors(hdl, sensors, count, false)
#define cpr_hal_add_sensor(hdl, sensor)                 cpr_hal_bypass_sensor(hdl, sensor, false)
#define cpr_hal_remove_sensors(hdl, sensors, count)     cpr_hal_bypass_sensors(hdl, sensors, count, true)
#define cpr_hal_remove_sensor(hdl, sensor)              cpr_hal_bypass_sensor(hdl, sensor, true)

static void cpr_hal_mask_sensors(cpr_hal_handle* hdl, const uint8* sensors, uint16 count, boolean mask)
{
    const uintptr_t base = hdl->controller->base;

    updateBitMask32( HWIO_CPR_SENSOR_MASK_READn_ADDR( base, 0 ),
                     HWIO_CPR_SENSOR_MASK_WRITEn_ADDR( base, 0 ),
                     sensors,
                     count,
                     mask );
}

#define cpr_hal_mask_sensor(hdl, sensor, mask)          cpr_hal_mask_sensors(hdl, &(sensor), 1, mask)
#define cpr_hal_enable_sensors(hdl, sensors, count)     cpr_hal_mask_sensors(hdl, sensors, count, false)
#define cpr_hal_enable_sensor(hdl, sensor)              cpr_hal_mask_sensor(hdl, sensor, false)
#define cpr_hal_disable_sensors(hdl, sensors, count)    cpr_hal_mask_sensors(hdl, sensors, count, true)
#define cpr_hal_disable_sensor(hdl, sensor)             cpr_hal_mask_sensor(hdl, sensor, true)

static void cpr_hal_mask_all_sensors(cpr_hal_handle* hdl, uint16 sensorsTotal, boolean mask)
{
    const uintptr_t base = hdl->controller->base;

    updateBitMaskAll32( HWIO_CPR_SENSOR_MASK_READn_ADDR( base, 0 ),
                        HWIO_CPR_SENSOR_MASK_WRITEn_ADDR( base, 0 ),
                        sensorsTotal,
                        mask );
}

#define cpr_hal_disable_all_sensors(hdl, sensorsTotal)    cpr_hal_mask_all_sensors(hdl, sensorsTotal, true)

/*
 * Set the number of clk cycles to count between activating cont_ack signal.
 * The purpose of the timer is to allow a PMIC transaction to settle with a new Vdd level,
 * before kicking off a next measurement.
 */
static void cpr_hal_set_timer_auto_cont_interval(cpr_hal_handle* hdl, uint32 interval)
{
    CPR_HWIO_OUT( HWIO_CPR_TIMER_AUTO_CONT_ADDR( hdl->controller->base ), interval );
}

/*
 * Set number of times to perform back-to-back measurement in the VDD_MAX/MIN count mode
 * - forced to 1 for AGE_PAGE mode
 * - forced to number of non-bypassed sensors for STAGGERED mode
 * - S/W can program value 1 into this CSR in order to mimic Rev2 legacy ALL_AT_ONCE mode
 */
static void cpr_hal_set_count_repeat(cpr_hal_handle* hdl, uint32 count)
{
    CPR_HWIO_OUT_FIELD( HWIO_CPR_FSM_CTL_ADDR( hdl->controller->base ), HWIO_CPR_FSM_CTL_COUNT_REPEAT, count );
}

static void cpr_hal_enable_controller(cpr_hal_handle* hdl, boolean enable)
{
    cpr_hal_controller *controller = hdl->controller;

    CPR_HWIO_OUT_FIELD( HWIO_CPR_FSM_CTL_ADDR( controller->base ), HWIO_CPR_FSM_CTL_LOOP_EN, enable );

    controller->enabled = CPR_HWIO_IN_FIELD(HWIO_CPR_FSM_CTL_ADDR( controller->base ), HWIO_CPR_FSM_CTL_LOOP_EN);

    CPR_LOG_TRACE("--- cpr_hal_enable_controller (LOOP_EN:%u) ---", controller->enabled);
}

static void cpr_hal_enable_thread(cpr_hal_handle* hdl, boolean enable)
{
    cpr_hal_controller *controller = hdl->controller;
    cpr_hal_thread     *thread     = hdl->thread;

    CPR_HWIO_OUT_FIELD( HWIO_CPR_MASK_THREAD_t_ADDR( controller->base, thread->id ), HWIO_CPR_MASK_THREAD_t_DISABLE_THREAD, !enable );

    thread->enabled = !CPR_HWIO_IN_FIELD( HWIO_CPR_MASK_THREAD_t_ADDR( controller->base, thread->id ), HWIO_CPR_MASK_THREAD_t_DISABLE_THREAD );

    CPR_LOG_TRACE("--- cpr_hal_enable_thread (enable:%d) (thread:%d) ---", thread->enabled, thread->id);
}

static boolean cpr_hal_check_all_threads_disabled(cpr_hal_handle* hdl)
{
    cpr_hal_controller *controller = hdl->controller;

    for(int i = 0; i < controller->threadsCount; i++)
    {
        if(controller->threads[i]->enabled)
        {
            return false;
        }
    }

    return true;
}

static boolean cpr_hal_is_aging_result_valid(cpr_hal_handle* hdl)
{
    /*
     * 1 - QUOT_MIN/MAX, SEL_MIN/MAX & SENSOR_MIN/MAX contain AGE readouts.
     * 0 - They contain data for regular CPR ROs.
     *
     * PAGE_IS_AGE has same timing as BUSY and is only valid when BUSY=0,
     * which is until 'cont=1' arrives.
     */
    return CPR_HWIO_IN_FIELD( HWIO_CPR_FSM_STA_ADDR( hdl->controller->base ), HWIO_CPR_FSM_STA_PAGE_IS_AGE );
}

/*
 * Turns on/off the specified Ring Oscilator
 */
static void cpr_hal_enable_ro(cpr_hal_handle *hdl, uint32 ro, boolean enable)
{
    cpr_hal_controller *controller = hdl->controller;
    uint32 gcntOffset = (HWIO_CPR_GCNT1_ADDR( 0 ) - HWIO_CPR_GCNT0_ADDR( 0 )) * ro;

    if(enable)
    {
        CPR_HWIO_OUT_FIELD( HWIO_CPR_GCNT0_ADDR( controller->base ) + gcntOffset, HWIO_CPR_GCNT0_GCNT0, CPR_DEFAULT_GCNT );
        controller->roMask &= ~(1 << ro);
    }
    else
    {
        CPR_HWIO_OUT_FIELD( HWIO_CPR_GCNT0_ADDR( controller->base ) + gcntOffset, HWIO_CPR_GCNT0_GCNT0, 0 );
        controller->roMask |= (1 << ro);
    }
}

/*
 * ANDs ro mask for all threads.
 * If bit is 1, all threads are masking the RO, and the RO needs to be disabled.
 * If bit is 0, some threads are using the RO, and the RO needs to be enabled.
 */
static uint16 cpr_hal_aggregate_thread_ro_masks(cpr_hal_handle *hdl)
{
    uint16 mask = 0xffff;

    for(int i = 0; i < hdl->controller->threadsCount; i++)
    {
        mask &= hdl->controller->threads[i]->roMask4Thread;
    }

    return mask;
}

/*
 * Disables RO if no thread need it.
 * Enables RO if a thread needs it.
 */
static void cpr_hal_update_ro_enablements(cpr_hal_handle *hdl)
{
    uint16 ro_mask_new  = cpr_hal_aggregate_thread_ro_masks(hdl); /* get new RO enablements */
    uint16 ro_mask_diff = hdl->controller->roMask ^ ro_mask_new;  /* XOR with current RO enablements to get
                                                                     what ROs need to be updated */
    for(int ro = 0; ro < ROSC_COUNT; ro++)
    {
        uint16 ro_bit = 1 << ro;

        if((ro_mask_diff & ro_bit) == 0)
        {
            // No update
            continue;
        }

        // If bit is 0, enable the RO, else disable the RO.
        cpr_hal_enable_ro(hdl, ro, ((ro_mask_new & ro_bit) == 0) );
    }
}

/*
 * Update the RO mask for the thread, and update RO enablements.
 * NOTE: Does not turn on/off the Ring Oscillator
 */
static void cpr_hal_set_ro_mask(cpr_hal_handle *hdl, uint16 roMask)
{
    cpr_hal_thread *thread = hdl->thread;

    // Update RO mask field for the thread
    CPR_HWIO_OUT_FIELD( HWIO_CPR_MASK_THREAD_t_ADDR( hdl->controller->base, thread->id ),
                        HWIO_CPR_MASK_THREAD_t_RO_MASK4THREAD,
                        roMask );

    thread->roMask4Thread = roMask;
}

static void cpr_hal_set_target_quotient(cpr_hal_handle *hdl, uint32 ro, uint32 quotient)
{
    uint32 targetOffset = (HWIO_CPR_TARGET1_t_m_ADDR( 0, 0, 0 ) - HWIO_CPR_TARGET0_t_m_ADDR( 0, 0, 0 )) * ro;

    CPR_LOG_TRACE( " Setting RO %u to %u", ro, quotient );

    CPR_HWIO_OUT_FIELD( HWIO_CPR_TARGET0_t_m_ADDR( hdl->controller->base, hdl->thread->id, 0 ) + targetOffset,
                        HWIO_CPR_TARGET0_t_m_TARGET0,
                        quotient );
}

static void cpr_hal_disable_interrupts(cpr_hal_handle* hdl)
{
    CPR_HWIO_OUT( HWIO_CPR_IRQ_EN_t_ADDR( hdl->controller->base, hdl->thread->id ), 0 );
}

static void cpr_hal_init_thread(cpr_hal_handle* hdl, cpr_hal_thread *thread, boolean configureHW)
{
    const uintptr_t base = hdl->controller->base;

    if(thread == NULL || thread->init)
    {
        return;
    }

    thread->init = true;

    /*
     * Configure HW. This is one time initialization and never changed at runtime.
     */
    if(configureHW)
    {
        const cpr_hal_thread_cfg *tcfg = thread->cfg;

        /*
         * Specify which sensor belongs to which thread
         */
        for(int i = 0; i < tcfg->sensorsCount; i++) {
            CPR_HWIO_OUT( HWIO_CPR_SENSOR_THREAD_n_ADDR( base, tcfg->sensors[i] ), thread->id );
        }

        uint32 thresholds = CPR_HWIO_SET_FIELD_VALUE( tcfg->upThresh, HWIO_CPR_THRESHOLD_t_UP_THRESHOLD ) |
                            CPR_HWIO_SET_FIELD_VALUE( tcfg->dnThresh, HWIO_CPR_THRESHOLD_t_DN_THRESHOLD ) |
                            CPR_HWIO_SET_FIELD_VALUE( tcfg->consecUp, HWIO_CPR_THRESHOLD_t_CONSECUTIVE_UP ) |
                            CPR_HWIO_SET_FIELD_VALUE( tcfg->consecDn, HWIO_CPR_THRESHOLD_t_CONSECUTIVE_DN );

        CPR_HWIO_OUT( HWIO_CPR_THRESHOLD_t_ADDR( base, thread->id ), thresholds );
    }

    // disable the thread and mask all 16 ROs for the thread.
    CPR_HWIO_OUT( HWIO_CPR_MASK_THREAD_t_ADDR( base, thread->id ), ~0 );

    thread->enabled       = false;
    thread->roMask4Thread = 0xffff;
}

static void cpr_hal_read_temp_sensor_data(cpr_hal_handle* hdl);

static void cpr_hal_enable_aging_ro(cpr_hal_handle* hdl, boolean enable)
{
    // Enable/disable RO 0 and 1 for aging measurement
    for(int i = 0; i < CPR_AGING_ROSC_COUNT; i++)
    {
        cpr_hal_enable_ro(hdl, i, enable);
    }

    // Update RO mask for the thread
    cpr_hal_set_ro_mask(hdl, hdl->controller->roMask);
}

//******************************************************************************
// Public API Functions
//******************************************************************************

/*
 * Initialize CPR controller and all threads in the controller.
 */
void cpr_hal_init_controller(cpr_hal_handle* hdl, boolean configureHW)
{
    if(hdl == NULL || hdl->controller == NULL || hdl->controller->init)
    {
        return;
    }

    cpr_hal_controller           *controller = hdl->controller;
    const cpr_hal_controller_cfg *cCfg       = controller->cfg;

    controller->init = true;

    CPR_LOG_TRACE( "Initializing controller @ 0x%x", (uint32)controller->base );

    /*
     * Configure HW. This is one time initialization and never changed at runtime.
     */
    if(configureHW)
    {
        const uintptr_t base = controller->base;

        // Enable the clocks
        if(cCfg->ahbClk != NULL) {
            cpr_image_enable_clock(cCfg->ahbClk);
        }

        if(cCfg->refClk != NULL) {
            cpr_image_enable_clock(cCfg->refClk);
        }

        // TODO - needed?
        //CPR_HWIO_OUT_FIELD(HWIO_CPR_BIST_CHAIN_CHECK0_ADDR(hdl->hw_base_address), HWIO_CPR_BIST_CHAIN_CHECK0_SCLK_CNT_EXPECTED, 32*6);

        cpr_hal_set_timer_auto_cont_interval(hdl, HAL_CPR_TIMER_DEFAULT_INTERVAL);
        CPR_HWIO_OUT_FIELD( HWIO_CPR_FSM_CTL_ADDR( base ), HWIO_CPR_FSM_CTL_IDLE_CLOCKS, 0x1f );

        CPR_HWIO_OUT_FIELD( HWIO_CPR_STEP_QUOT_INIT_ADDR( base ), HWIO_CPR_STEP_QUOT_INIT_STEP_QUOT_INIT_MAX, cCfg->stepQuotMax );
        CPR_HWIO_OUT_FIELD( HWIO_CPR_STEP_QUOT_INIT_ADDR( base ), HWIO_CPR_STEP_QUOT_INIT_STEP_QUOT_INIT_MIN, cCfg->stepQuotMin );
        CPR_HWIO_OUT_FIELD( HWIO_CPR_TIMER_CLAMP_ADDR( base ), HWIO_CPR_TIMER_CLAMP_CLAMP_TIMER_INTERVAL, 1u );

        cpr_hal_set_count_mode(hdl, CPR_HAL_COUNT_MODE_ALL_AT_ONCE_MIN);

        cpr_hal_set_count_repeat(hdl, 1);

        cpr_hal_bypass_sensors( hdl, cCfg->bypassSensors, cCfg->bypassSensorsCount, true );
        cpr_hal_disable_sensors( hdl, cCfg->disableSensors, cCfg->disableSensorsCount );
    }

    /*
     * Disable all ROs
     */
    for(int i = 0; i < ROSC_COUNT; i++)
    {
        cpr_hal_enable_ro(hdl, i, false);
    }

    cpr_hal_enable_controller( hdl, false );

    /*
     * Initialize all threads in the controller
     */
    for(int i = 0; i < controller->threadsCount; i++)
    {
        cpr_hal_init_thread(hdl, controller->threads[i], configureHW);
    }
}

void cpr_hal_clear_interrupts(cpr_hal_handle* hdl)
{
    CPR_HWIO_OUT( HWIO_CPR_IRQ_CLEAR_t_ADDR( hdl->controller->base, hdl->thread->id ), ~0 );
}

void cpr_hal_ack_result(cpr_hal_handle* hdl, boolean ack)
{
    /*
     * set VDD_CHANGED_ONE_STEP bit (bit 0) of CPR_CONT_CMD_t register
     *
     * A write of any data value to this address will send a pulse to cpr_master.cont_ack.
     * The meaning of the cont_ack signal is to indicate that the cpr_master should continue
     * with a next measurement iteration, and that the recommendation of the prior iteration was taken.
     *
     * Tell the controller that the VDD has been changed by
     * exactly one PMIC step compared to the previous measurement.
     * This CSR is per thread
     */
    CPR_HWIO_OUT( HWIO_CPR_CONT_CMD_t_ADDR( hdl->controller->base, hdl->thread->id ), ack );
}

void cpr_hal_set_count_mode(cpr_hal_handle* hdl, cpr_hal_count_mode count_mode)
{
    /*
     * NOTE: Provided BUSY=0, COUNT_MODE can change when LOOP_EN=1.
     * When set to ALL_AT_ONCE_AGE, 'gcnt[0]' is for AGE_MAX; 'gcnt[1]' for AGE_MIN RO and
     * controller will automatically force 0 onto 'gcnt[2..15]' to so skip all other RO slots.
     */
    CPR_HWIO_OUT_FIELD( HWIO_CPR_FSM_CTL_ADDR( hdl->controller->base ), HWIO_CPR_FSM_CTL_COUNT_MODE, count_mode);
}

static void cpr_hal_read_results( cpr_hal_handle* hdl, cpr_results* rslts)
{
    const uintptr_t base = hdl->controller->base;
    const uint32    tid  = hdl->thread->id;

    uint32 status = CPR_HWIO_IN( HWIO_CPR_RESULT0_t_ADDR( base, tid ) );

    rslts->busy  = !!CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT0_t_BUSY );
    rslts->up    = !!CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT0_t_STEP_UP );
    rslts->down  = !!CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT0_t_STEP_DN );
    rslts->steps = CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT0_t_ERROR_STEPS );

    status = CPR_HWIO_IN( HWIO_CPR_RESULT1_t_ADDR( base, tid ) );

    rslts->quotMax = CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT1_t_QUOT_MAX );
    rslts->quotMin = CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT1_t_QUOT_MIN );
    rslts->selMax  = CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT1_t_SEL_MAX );
    rslts->selMin  = CPR_HWIO_GET_FIELD_VALUE( status, HWIO_CPR_RESULT1_t_SEL_MIN );

    cpr_hal_read_temp_sensor_data(hdl);
}

boolean cpr_hal_get_results(cpr_hal_handle* hdl, cpr_results* rslts, uint32 timeout)
{
    boolean ret = true;

    do {
        cpr_hal_read_results( hdl, rslts );

        if(timeout == 0) {
            break;
        }
        else {
            timeout--;
        }

        if(rslts->busy) {
            cpr_image_wait(3); // 3 usec is recommended by HW team
        }
    } while(rslts->busy);

    if(!rslts->busy) {
        CPR_LOG_TRACE( " Results - (up: %d) (dn: %d) (steps: %d) (QuotMin:%d) (QuotMax:%d) (SelMin:%d) (SelMax:%d)",
                      rslts->up, rslts->down, rslts->steps,
                      rslts->quotMin, rslts->quotMax, rslts->selMin, rslts->selMax);
    }
    else {
        CPR_LOG_ERROR( "Timeout waiting for results" );
        ret = false;
    }

    return ret;
}

void cpr_hal_set_targets(cpr_hal_handle* hdl, cpr_voltage_mode mode, uint32 freq, cpr_quotient* tgts, uint32 count)
{
    uint16 ro_mask = 0xffff; /* default is masking all ROs */

    for(int i = 0; i < count; i++)
    {
        if (tgts[i].quotient != 0)
        {
            cpr_hal_set_target_quotient(hdl, tgts[i].ro, tgts[i].quotient);

            // Unmask RO
            ro_mask &= ~(1 << tgts[i].ro);
        }
    }

    cpr_hal_set_ro_mask(hdl, ro_mask);

    cpr_hal_update_ro_enablements(hdl);
}

void cpr_hal_start_poll(cpr_hal_handle* hdl)
{
    CPR_LOG_TRACE("Start polling");

    cpr_hal_enable_rail( hdl, true, true, false, true );
}

void cpr_hal_stop_poll(cpr_hal_handle* hdl)
{
    cpr_hal_disable_rail( hdl );

    CPR_LOG_TRACE("Stopped polling");
}

void cpr_hal_enable_up_interrupt(cpr_hal_handle* hdl, boolean enable)
{
    CPR_HWIO_OUT_FIELD( HWIO_CPR_IRQ_EN_t_ADDR( hdl->controller->base, hdl->thread->id ),
                        HWIO_CPR_IRQ_EN_t_UP_FLAG_EN,
                        enable );
}

void cpr_hal_enable_down_interrupt(cpr_hal_handle* hdl, boolean enable)
{
    CPR_HWIO_OUT_FIELD( HWIO_CPR_IRQ_EN_t_ADDR( hdl->controller->base, hdl->thread->id ),
                        HWIO_CPR_IRQ_EN_t_DOWN_FLAG_EN,
                        enable );
}

void cpr_hal_enable_mid_interrupt(cpr_hal_handle* hdl, boolean enable)
{
    CPR_HWIO_OUT_FIELD( HWIO_CPR_IRQ_EN_t_ADDR( hdl->controller->base, hdl->thread->id ),
                        HWIO_CPR_IRQ_EN_t_MID_FLAG_EN,
                        enable );
}

/*
 * To re-enable CPR after setting parameters for new mode
 * - Enable Thread by simply writing into related CSR bit  - or set loop_en=1
 */
void cpr_hal_enable_rail(cpr_hal_handle* hdl, boolean up, boolean down, boolean mid, boolean swControl)
{
    if(swControl)
    {
        cpr_hal_enable_up_interrupt(hdl, up);
        cpr_hal_enable_down_interrupt(hdl, down);
        cpr_hal_enable_mid_interrupt(hdl, mid);

        cpr_hal_enable_thread(hdl, true);

        if(!hdl->controller->enabled)
        {
            cpr_hal_enable_controller(hdl, true);
        }
    }
    else if(hdl->controller->type == CPR_CONTROLLER_TYPE_HW_CL_CAPABLE)
    {
#if defined HWIO_APCS_APCC_CPR_SW_MODE_ADDR
        CPR_HWIO_OUT_FIELD( HWIO_APCS_APCC_CPR_SW_MODE_ADDR( hdl->controller->base ), HWIO_APCS_APCC_CPR_SW_MODE_CPR_SW_MODE, swControl );
#endif
        cpr_hal_enable_controller( hdl, true );
    }
}

void cpr_hal_disable_rail(cpr_hal_handle* hdl)
{
    cpr_hal_disable_interrupts(hdl);
    cpr_hal_clear_interrupts(hdl);

    /*
     * Disable this rail
     *
     * From HPG:
     *
     * 1. One controller, one rail, one thread 
     *  In this case (like CX, GFX) each rail has its own controller and the controller only has one thread.
     *  We can use LOOP_EN for mode switching which is: disable cpr (LOOP_EN=0), reconfigure the mode,
     *  enable CPR (LOOP_EN=1). SW only needs to tell controller the new mode since the targets are already
     *  programmed in controller. We have per mode target registers in CPR3 controller.
     *
     * 2. One controller , one rail, two threads (APPS CPR)
     *  In this case (like HMSS in Istari) the threads are aggregated in HW and SW receives only one interrupt.
     *  In this case SW can use the LOOP_EN approach described in 1.
     *
     * 3. One controller, multi rail, multi thread
     *  In this case (like MX, DDR) SW needs to follow the THREAD disable approach and use the thread disable
     *  CSR for disabling a thread/rail on which mode switch is happening.
     */
    if(hdl->controller->threadsCount > 1)
    {
        cpr_hal_enable_thread( hdl, false );

        if(cpr_hal_check_all_threads_disabled(hdl))
        {
            cpr_hal_enable_controller(hdl, false);
        }
    }
    else
    {
        cpr_hal_enable_controller( hdl, false );
    }
}

/*
 * Configure CPR controller to read the QUOTs of AGE_Max RO and AGE_Min RO.
 * After configured, gcnt[0] is for AGE_Max RO, gcnt[1] is for AGE_Min RO.
 * Controller will force zero value to the rest and skip all other ROs measurement.
 */
void cpr_hal_enable_aging(cpr_hal_handle* hdl, const cpr_aging_cfg* aging_cfg)
{
    cpr_hal_controller *controller = hdl->controller;

    // Set cont mode to VDD_MIN(0) and count_repeat=0
    cpr_hal_set_count_mode(hdl, CPR_HAL_COUNT_MODE_ALL_AT_ONCE_MIN);
    cpr_hal_set_count_repeat(hdl, 0);

    // Set all timer intervals to 0
    cpr_hal_set_timer_auto_cont_interval(hdl, 0);

    // step_quot_init_max/min are already configured in cpr_hal_init_controller().

    // Program gcnt 0 and 1 to 19
    cpr_hal_enable_aging_ro(hdl, true);

    // Mask all the sensors except the sensor which has selected to be aging sensor.
    cpr_hal_disable_all_sensors(hdl, controller->cfg->sensorsTotal);
    cpr_hal_enable_sensor(hdl, aging_cfg->sensorID);

    // Bypass the sensors
    // Not in the de-aging flow pseudo code but according to the "SoC specific HPG" section,
    //     "we should bypass collapsible sensors to avoid CPR measurement being reset by power ON/OFF of collapsible blocks"
    //     "Note that, SW should mask all the sensors except AGE sensor ID and that is besides these bypass settings."
    cpr_hal_remove_sensors(hdl, aging_cfg->bypassSensorIDs, aging_cfg->bypassSensorIDsCount);

    // If CPR controller support more than 1 thread, write 0 to CPR_SENSOR_THREAD_N where N is AGE_SENSOR_ID
    if(controller->threadsCount > 1) {
        sensor_thread_id = CPR_HWIO_IN( HWIO_CPR_SENSOR_THREAD_n_ADDR( controller->base, aging_cfg->sensorID ) );
        CPR_HWIO_OUT( HWIO_CPR_SENSOR_THREAD_n_ADDR( controller->base, aging_cfg->sensorID ), 0 );
    }

    /*
     * Enable up/mid/down interrupts for polling and enable CPR controller.
     *
     * For aging algorithm in CPR3 we have to enable all UP/DOWN/MID interrupts
     * to avoid auto_cont mode of cpr controller.
     * Note that if one of this interrupt is disabled, CPR goes to auto mode if that event happens.
     */
    cpr_hal_enable_rail( hdl, true, true, true, true );
}

void cpr_hal_disable_aging(cpr_hal_handle* hdl, const cpr_aging_cfg* aging_cfg)
{
    // Disable up/mid/down interrupts, clear interrupts, and disable CPR controller
    cpr_hal_disable_rail(hdl);

    // If CPR controller support more than 1 thread, restore thread ID for aging sensor
    if(hdl->controller->threadsCount > 1) {
        CPR_HWIO_OUT( HWIO_CPR_SENSOR_THREAD_n_ADDR( hdl->controller->base, aging_cfg->sensorID ), sensor_thread_id );
    }

    // Unbypass sensors
    cpr_hal_add_sensors(hdl, aging_cfg->bypassSensorIDs, aging_cfg->bypassSensorIDsCount);

    // Unmask all the sensors except the sensor which has selected to be aging sensor.
    cpr_hal_disable_sensor(hdl, aging_cfg->sensorID);
    cpr_hal_enable_sensors(hdl, hdl->thread->cfg->sensors, hdl->thread->cfg->sensorsCount);

    // Reset gcnt 0 and 1
    cpr_hal_enable_aging_ro(hdl, false);

    cpr_hal_set_timer_auto_cont_interval(hdl, HAL_CPR_TIMER_DEFAULT_INTERVAL);

    cpr_hal_set_count_repeat(hdl, 1);
    cpr_hal_set_count_mode(hdl, CPR_HAL_COUNT_MODE_ALL_AT_ONCE_MIN);
}

boolean cpr_hal_get_aging_delta(cpr_hal_handle* hdl, int32 *aging_delta, uint32 *retry_count)
{
    cpr_results rslts;
    boolean ret = true;

    cpr_image_wait(10); // 10usec is from HPG

    // wait for busy to be low
    if(!cpr_hal_get_results( hdl, &rslts, RESULTS_TIMEOUT_5MS ))
    {
        /*
         * If busy remains high more than 5ms, set loop_en to low and start from beginning for 2nd time.
         * If in 2nd time , busy remain low as well, exit the algorithm and set age compensation
         * to MAX_COMPENSATION provided in Age spreadsheet
         */
        *retry_count += 1;
        return false;
    }

    // set age_page mode
    cpr_hal_set_count_mode(hdl, CPR_HAL_COUNT_MODE_ALL_AT_ONCE_AGE);

    // send CONT_NACK
    cpr_hal_ack_result(hdl, false);

    cpr_image_wait(10); // 10 usec is from HPG

    if(!cpr_hal_get_results(hdl, &rslts, RESULTS_TIMEOUT_5MS ))
    {
        /*
         * If busy remains high more than 5ms, set loop_en to low and start from beginning for 2nd time.
         * If in 2nd time , busy remain low as well, exit the algorithm and set age compensation
         * to MAX_COMPENSATION provided in Age spreadsheet
         */
        *retry_count += 1;
        return false;
    }

    // check for valid aging data
    if(cpr_hal_is_aging_result_valid(hdl))
    {
        // ALWAYS CALCULATE DELTA= RO#1 - RO#0
        *aging_delta = (rslts.selMax == 1) ? (rslts.quotMax - rslts.quotMin) : (rslts.quotMin - rslts.quotMax);

        CPR_LOG_INFO("Aging Delta: %d", *aging_delta);
    }
    else
    {
        /*
         * Do not increment error count.
         * HPG does not define what to do when PAGE_IS_AGE was not set for multiple trials.
         */
        CPR_LOG_ERROR("PAGE_IS_AGE is not set");
        ret = false;
    }

    return ret;
}

#ifdef V3_HAL_VERSION

void cpr_hal_enable_temp_margin_adj(cpr_hal_handle* hdl, const cpr_voltage_plan* vp, boolean enable )
{
  // Stubbed function
}

void cpr_hal_init_temp_margin_adj(cpr_hal_handle* hdl, uint8 modeIndex, const cpr_voltage_plan* vp)
{
  // Stubbed function
}

void cpr_hal_set_temp_margin(cpr_hal_handle* hdl, uint8 modeIndex, const cpr_voltage_plan* vp)
{
  // Stubbed function
}

void cpr_hal_read_temp_sensor_data(cpr_hal_handle* hdl)
{
  // Stubbed function
}
#endif
