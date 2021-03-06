#ifndef _TRACER_EVENT_TBL_H
#define _TRACER_EVENT_TBL_H

#include "tracer_event_ids.h"

#define EVENT_SUBSYSTEM rpm

typedef struct _tracer_event_item {
	tracer_event_id_t evt_id;
	char * evt_str;
}tracer_event_item;

tracer_event_item tracer_event_tbl[] = {
	{TRACER_EVENT_RESERVE_0,""},
	{DDR_EVENT_FIRST=1,"ddr first event placeholder"},
	{DDR_EVENT_BIMC_SR_ENTRY_IDLE,"ddr enter self refresh idle: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_SR_ENTRY_ASAP,"ddr enter self refresh asap: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_SR_EXIT,"ddr exit self refresh: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_DPD_ENTRY,"ddr deep power down entry: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_DPD_EXIT,"ddr deep power down exit: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_PASR_UPDATE,"ddr partial array self refresh update: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_PWR_COLLAPSE_ENTRY,"ddr bimc power collapse entry: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_PWR_COLLAPSE_EXIT,"ddr bimc power collapse exit: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_PRE_CLK_SWITCH,"ddr bimc pre clock switch: %x,%x,%x,%x"},
	{DDR_EVENT_BIMC_POST_CLK_SWITCH,"ddr bimc post clock switch: %x,%x,%x,%x"},
	{DDR_EVENT_DDR_DRIVER_ERROR_FATAL,"ddr error fatal: %x,%x,%x,%x"},
	{DDR_EVENT_LAST=63,"ddr last event placeholder"},
	{QDSS_TS_FREQ_CHANGE=690,"QDSS timestamp counter new frequency %d at qtimer %llu"},
	{QDSS_INIT_COMPLETE,"QDSS Initialization complete"},
	{QDSS_RESERVED=699,"Reserved last qdss msg"},
	{PMIC_EVENT_FIRST=512,"PMIC first event placeholder"},
	{PMIC_DRV_PWR_SW_EN,"pmic_index = %d periph_type = %d periph_index = %d enable = %d"},
	{PMIC_DRV_PWR_PIN_CTRL,"pmic_index = %d periph_type = %d periph_index = %d pin = %d"},
	{PMIC_DRV_PWR_PIN_CTRL_MODE,"pmic_index = %d periph_type = %d periph_index = %d pin = %d"},
	{PMIC_DRV_PWR_VOLT_LVL,"pmic_index = %d periph_type = %d periph_index = %d volt = %d"},
	{PMIC_DRV_PWR_PIN_VOLT_LVL,"pmic_index = %d periph_type = %d periph_index = %d volt = %d"},
	{PMIC_DRV_PWR_MODE,"pmic_index = %d periph_type = %d periph_index = %d mode = %d"},
	{PMIC_DRV_PWR_PULL_DOWN_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_PWR_SW_EN_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_PWR_PIN_CTRL_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_PWR_VOLT_LVL_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_PWR_PIN_VOLT_LVL_ERROR,"pmic_index = %d periph_type = %d periph_index = %d"},
	{PMIC_DRV_PWR_MODE_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_PWR_IRQ_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_SMPS_ILIM_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_SMPS_QM_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_SMPS_SWITCH_FREQ_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_SMPS_PHASE_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_SMPS_SS_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_SMPS_VSTEP_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_CLK_SW_EN,"pmic_index = %d periph_type = %d periph_index = %d enable = %d"},
	{PMIC_DRV_CLK_PIN_CTRL,"pmic_index = %d periph_type = %d periph_index = %d pin = %d"},
	{PMIC_DRV_CLK_SW_EN_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_DRV_CLK_PIN_CTRL_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_RPM_VREG_SETTLING_ERROR,"pmic_index = %d periph_type = %d periph_index = %d"},
	{PMIC_RPM_STEPPER_SETTLING_ERROR,"pmic_index = %d periph_type = %d periph_index = %d"},
	{PMIC_DRV_SMPS_OCP_ERROR,"pmic_index = %d periph_type = %d periph_index = %d error = %d"},
	{PMIC_RPM_SETTLING_TIME,"periph_info = %d estimated = %d actual = %d"},
	{PMIC_EVENT_LAST=639,"PMIC last event placeholder"},
	{SPMI_EVENT_FIRST=79,"placeholder first spmi swevent"},
	{SPMI_EVENT_FATAL_ERROR=80,"spmi_fatal_error: (result %d) (file %x) (line %d)"},
	{SPMI_EVENT_ERROR,"spmi_error: (result %x) (file %x) (line %d)"},
	{SPMI_EVENT_WARNING,"spmi_warning: (file %x) (line %d)"},
	{SPMI_EVENT_LAST=100,"placeholder last spmi swevent"},
	{CPR_EVT_INIT=670,"cpr_init (chip_version 0x%x) (foundry 0x%x) (cpr_rev 0x%x)"},
	{CPR_EVT_RAIL_INIT=671,"cpr_rail_init (rail_mode 0x%0.8x) (global_ceiling_uv %d) (global_floor_uv %d)"},
	{CPR_EVT_RAIL_INIT_OPEN_LOOP=672,"cpr_rail_init_open_loop (rail_mode 0x%0.8x) (ceiling_uv %d) (floor_uv %d)"},
	{CPR_EVT_RAIL_INIT_SMEM=673,"cpr_rail_init_smem (rail_mode 0x%0.8x) (ceiling_uv %d) (floor_uv %d) (total_margin_mv %d)"},
	{CPR_EVT_RAIL_ENABLE=674,"cpr_rail_enable (rail_mode 0x%0.8x) (current_uv %d) (up_down_counts 0x%0.8x)"},
	{CPR_EVT_RAIL_ISR=675,"cpr_rail_isr (rail_mode 0x%0.8x) (recommendation_uv %d) (up_down_ints 0x%0.8x)"},
	{CPR_EVT_HAL_SET_TEMP_BANDS=676,"cpr_hal_set_temp_bands (controller 0x%0.8x) (mode %d) (temp_bands 0x%0.8x) (temp_sensor_data 0x%0.8x)"},
	{CPR_EVT_RAIL_DISABLE_MODE=677,"cpr_rail_disable_mode (rail_mode 0x%0.8x) (use_openloop_mode %d) (use_closedloop_mode %d)"},
	{CPR_EVT_LAST=689,"NULL"},
	{MISC_GFX_PHASE=710,"misc_gfx_phase: (phase: %d) (corner: %d) (IDDQ: %d) (temp level: %d)"},
	{MISC_CX_SINGLEPHASE,"misc_cx_singlephase: (corner: %d) (IDDQ: %d) (VPU: %d) (temp level: %d)"},
	{MISC_CX_DUALPHASE,"misc_cx_dualphase: (corner: %d) (IDDQ: %d) (VPU: %d) (temp level: %d)"},
	{MISC_NPA_DUMP_REQUEST,"misc_npa_dump: (trigger_time: 0x%0.8x%0.8x)"},
	{MISC_NPA_DUMP_COMPLETE,"misc_npa_dump_complete"},
	{MISC_CX_LIMIT_CHANGE=728,"misc_cx_limiter_change: (old limit: %d) (new limit: %d)"},
	{MISC_CX_LIMIT_EXCEED=729,"misc_cx_limiter_exceed: (corner: %d) (limit: %d)"},
	{MISC_LAST=730,"misc_unused"},
	{RAILWAY_CHANGE_VOLTAGE=650,"railway_change_voltage: (rail %d) (new microvolts %d) (old microvolts %d) (new corner/old corner 0x%0.8x)"},
	{RAILWAY_LAST=669,"rpm_ocmem_update_bank_setting: (old_vote: %d) (new_vote: %d) (active_votes: %d) (retention_votes: %d)"},
	{RPM_BOOT_STARTED=192,"rpm boot started (free_heap_space: %d)"},
	{RPM_BOOT_FINISHED,"rpm boot finished (free_heap_space: %d)"},
	{RPM_BRINGUP_REQ,"rpm_bringup_req: (master: %plugin[1]<RPM>) (core %d) (is_soft_transition %d)"},
	{RPM_BRINGUP_ACK,"rpm_bringup_ack: (master: %plugin[1]<RPM>) (core %d) (is_soft_transition %d)"},
	{RPM_SHUTDOWN_REQ,"rpm_shutdown_req: (maste: %plugin[1]<RPM>) (core %d) (is_soft_transition %d)"},
	{RPM_SHUTDOWN_ACK,"rpm_shutdown_ack: (master: %plugin[1]<RPM>) (core %d) (is_soft_transition %d)"},
	{RPM_TRANSITION_QUEUED,"rpm_transition_queued: (master: %plugin[1]<RPM>) (status %d) (deadline: 0x%x)"},
	{RPM_MASTER_SET_TRANSITION,"rpm_master_set_transition: (master: %plugin[1]<RPM>) (fromSet %d) (toSet: %d) (cacheHit: %d)"},
	{RPM_MASTER_SET_TRANSITION_COMPLETE,"rpm_set_transition_complete: (master: %plugin[1]<RPM>.) (deadline: 0x%x) (exceeded %d)"},
	{RPM_HASH_MISMATCH,"rpm_hash_mismatch: (next_task %d) (pre_state %d) (next_state %d) (system_hash %d)"},
	{RPM_CPU_FAST_EXTERNAL_VOTE,"rpm_svs (mode: RPM_CPU_FAST) (reason: external vote)"},
	{RPM_CPU_FAST_IMMINENT_PROCESSING,"rpm_svs (mode: RPM_CPU_FAST) (reason: imminent processing)"},
	{RPM_CPU_FAST_SCHEDULE_IS_FULL,"rpm_svs (mode: RPM_CPU_FAST) (reason: schedule is full)"},
	{RPM_CPU_SLOW_IDLE,"rpm_svs (mode: RPM_CPU_SLOW) (reason: idle)"},
	{RPM_CPU_FAST_SPEEDUP,"rpm_svs (mode: RPM_CPU_FAST) (reason: speedup) (old_duration: %x) (new_duration: %x) (switch_time: %x)"},
	{RPM_CPU_SLOW_NO_SPEEDUP,"rpm_svs (mode: RPM_CPU_SLOW) (reason: no speedup) (old_duration: 0x%x) (new_duration: 0x%x) (switch_time: 0x%x)"},
	{RPM_MESSAGE_RECEIVED,"rpm_message_received (master: %plugin[1]<RPM>) (message id: %d) (set: %d)"},
	{RPM_PROCESS_REQUEST,"rpm_process_request (master: %plugin[1]<RPM>) (Resource Name: %plugin[*]<resource>)"},
	{RPM_SEND_RESPONSE,"rpm_send_message_response (master: %plugin[1]<RPM>) (service: 0x%x)"},
	{RPM_ERR_FATAL,"rpm_err_fatal (lr: 0x%0.8x) (ipsr: 0x%0.8x)"},
	{RPM_XLATE_REQUEST,"rpm_xlate_request (Resource Name: %plugin[*]<resource>)"},
	{RPM_APPLY_REQUEST,"rpm_apply_request (Resource Name: %plugin[*]<resource>) (bypassed: %d)"},
	{RPM_ESTIMATE_CACHE_HIT,"rpm_estimate_cache_hit (estimate: %d)"},
	{RPM_ESTIMATE_CACHE_MISMATCH,"rpm_estimate_cache_mismatch (expected_result: %d) (expected_duration: %d) (actual_result: %d) (actual_duration: %d)"},
	{RPM_MASTER_SET_TRANSITION_BYPASS,"rpm_transition_bypass (master: %plugin[1]<RPM>) (wake_time: 0x%0.8x)"},
	{RPM_RESOURCE_SETTLING,"rpm_resource_settling (master: %plugin[1]<RPM>) (resource type: %plugin[1]<resource>) (resource id: %d) (msg id: %d)"},
	{RPM_RESOURCE_SETTLING_TIME,"rpm_resource_settling_time (deadline: 0x%0.8x%0.8x)"},
	{RPM_RESOURCE_SETTLING_COMPLETE,"rpm_resource_settling_complete (master: %plugin[1]<RPM) (resource type: %plugin[1]<resource>) (resource id: %d) (msg id: %d)"},
	{RPM_RESOURCE_SETTLING_SPIN,"rpm_resource_settling_spin"},
	{RPM_SETTLING_MESSAGE_REQUEUED,"rpm_settling_message_reenqueued (master: %plugin[1]<RPM>), (message id: %d)"},
	{RPM_SETTLING_TRANSITION_REQUEUED,"rpm_transition_settling_requeued: (master %plugin[1]<RPM>) (status %d) (deadline: 0x%0.8x%0.8x)"},
	{RPM_TRANSITION_POSTPONED,"rpm_transition_postponed: (master %plugin[1]<RPM>)"},
	{RPM_CPR_SENSOR_DISABLED,"rpm_cpr_sensor_disabled (rail: %d) (disabled: %d)"},
	{RPM_OUT_OF_HEAP,"rpm_out_of_heap"},
	{RPM_COMMAND_RECEIVED,"rpm_command_received (master: %plugin[1]<RPM>)"},
	{RPM_HEAP_CHECK,"rpm_heap_check (free_heap_space: %d)"},
	{RPM_MASTER_STATES,"rpm_master_states (master_state_bmsk: %d)"},
	{RPM_NAS_START,"rpm_nas_start "},
	{RPM_RAM_LOG_DISABLE,"rpm_ram_log_disable (num_logs_bef_stop: %d)"},
	{RPM_RAM_LOG_DISABLED,"rpm_ram_log_disabled"},
	{RPM_RAM_LOG_ENABLED,"rpm_ram_log_enabled"},
	{RPM_TZ_HALT_INT_RECEIVED,"rpm_abort_interrupt_received (TZ HALT) ... aborting"},
	{RPM_NON_SECURE_WD_BITE_INT_RECEIVED,"rpm_abort_interrupt_received (APPS NON SECURE WD BITE) ... aborting"},
	{RPM_ENQUEUE_SCHEDULED_TASK,"rpm_enqueue_common_task (task_id: %d) "},
	{RPM_EXECUTE_SCHEDULED_TASK,"rpm_execute_common_task (task_id: %d) "},
	{RPM_COMPLETE_SCHEDULED_TASK,"rpm_complete_common_task (task_id: %d) "},
	{RPM_PREEMPT_SCHEDULED_TASK,"rpm_preempt_common_task (task_id: %d)"},
	{RPM_CLEAR_APCS_QGICDR_COMPLETE,"rpm_clear_acps_qgicdr_complete"},
	{RPM_DCC_CRC_ERR_INT_RECEIVED,"rpm_dcc_crc_err_int_received"},
	{RPM_MASTER_SET_TRANSITION_CACHE_STATUS,"rpm_transition_cache_status: (startState: %d)(actionHash: %d)"},
	{RPM_ESTIMATE_CACHE_OBSERVE,"rpm_estimate_cache_observe: (startState: %d)(actionHash: %d)(resultState: %d)(estimate: %d)"},
	{RPM_SOFT_TRIGGER_BRINGUP,"rpm_soft_trigger_bringup, (pending: %d)(mpm_index: %d)"},
	{GCC_RESET,"gcc_reset ... aborting (reset_reason: %d)"},
	{RPM_BOOT_INIT_FCN_STARTED,"rpm_boot_init_fcn_started (init_fcn_id: %d) (free_heap_space: %d)"},
	{RPM_BOOT_INIT_FCN_FINISHED,"rpm_boot_init_fcn_finished (init_fcn_id: %d) (free_heap_space: %d)"},
	{RPM_APPS_HANG_STATUS,"rpm_apps_hang_status (Core: 0x%x) (Gladiator: 0x%x) (GIC: 0x%x) (WDOG: 0x%x)"},
	{RPM_RESET_CHIP,"rpm_reset_chip"},
	{RPM_LOG_REGISTER,"rpm_log_register (PhysAddress: 0x%0.8x) (Value: 0x%0.8x)"},
	{RPM_RECLAIM_POOL,"rpm_reclaim_pool (Base: 0x%0.8x) (Limit: 0x%0.8x) (free_heap_space: %d)"},
	{RPM_CCI_SPM_E3_ENTRY_WORKAROUND_STARTED,"rpm_cci_spm_e3_entry_workaround_started"},
	{RPM_CCI_SPM_E3_EXIT_WORKAROUND_STARTED,"rpm_cci_spm_e3_exit_workaround_started"},
	{RPM_CCI_SPM_E3_WORKAROUND_FINISHED,"rpm_cci_spm_e3_workaround_finished"},
	{RPM_GIC_DISABLE,"rpm_gic_disable (saved_gicd_ctlr: 0x%x)"},
	{RPM_GIC_ENABLE,"rpm_gic_enable"},
	{RPM_LAST=319,"rpm error fatal2"},
	{SLEEP_DEEP_SLEEP_ENTER=320,"deep sleep enter. (sleep mode: %d) (count: %d)"},
	{SLEEP_DEEP_SLEEP_EXIT,"deep sleep exit (sleep mode: %d)"},
	{SLEEP_NO_DEEP_SLEEP,"bail early from deep sleep. (sleep mode: %d) (reason: %d)"},
	{SLEEP_RPM_HALT_ENTER,"rpm halt enter"},
	{SLEEP_RPM_HALT_EXIT,"rpm halt exit"},
	{SLEEP_MPM_INTS,"pending mpm interrupts at wakeup: (interrupt_status_1 %d), (interrupt_status_2 %d), (timestamp: 0x%0.8x%0.8x)"},
	{SLEEP_DEEP_SLEEP_ENTER_COMPLETE,"deep sleep enter complete (sleep mode: %d), (duration: 0x%0.8x)"},
	{SLEEP_DEEP_SLEEP_EXIT_COMPLETE,"deep sleep exit complete (sleep mode: %d)"},
	{SLEEP_MPM_WAKEUP_TIME,"mpm programmed wake up time (wakeup time: 0x%0.8x%0.8x)"},
	{SLEEP_MPM_WAKEUP_TIME_ACTUAL,"mpm actual wake up time (wakeup time: 0x%0.8x%0.8x)"},
	{SLEEP_CPR_SVS2_PROCESS,"cpr_svs2_process"},
	{SLEEP_MPM_VOLTAGE,"mpm_voltages: (mx_off: %d) (mx_on: %d) (cx_off: %d) (cx_on: %d)"},
	{SLEEP_MPM_RO_DIV,"mpm_ro_divider: (mx: %d) (ro_div: 0x%x)"},
	{SLEEP_WLAN_FREEZE_IO_WORKAROUND,"wlan mpm config: (old_reg: 0x%0.8x) (new_reg: 0x%0.8x)"},
	{SLEEP_EVENT_LAST=383,"sleep last event placeholder"},
	{SYSTEM_DB_ADD_WRITE=700,"adding sysdb write op: (command id: 0x%x) (addr: 0x%x) (num: %d) (data: 0x%x)"},
	{SYSTEM_DB_ADD_READ,"adding sysdb read op: (command id: 0x%x) (addr: 0x%x) (num: %d)"},
	{SYSTEM_DB_FLUSH_QUEUE,"flushing the sysdb op queue."},
	{SYSTEM_DB_STATE_HANDLER,"entering the sysdb state handler: (state: 0x%x)"},
	{SYSTEM_DB_WRITE,"sysdb write: (command id: 0x%x) (addr: 0x%x) (val: 0x%x) (mask: 0x%x)"},
	{SYSTEM_DB_READ,"sysdb read: (command id: 0x%x) (addr: 0x%x) (val: 0x%x)"},
	{SYSTEM_DB_CLK_STATUS,"Clock Name: %plugin[1]<clock>.  Actual State = %d (On/OFF).  Reference Count = %d.  Frequency = %dHz"},
	{SYSTEM_DB_CLK_PWR_DOMAIN,"Clock power domain name: %s.  Enable = %d  Reference Count = %d"},
	{SYSTEM_DB_EVENT_LAST=709,"SYSTEM_DB last event placeholder"},
	{CLOCK_EVENT_FIRST=384,"Clock first event placeholder"},
	{CLOCK_EVENT_INIT,"Clock Initialize"},
	{CLOCK_EVENT_STATUS,"Clock Name: %plugin[1]<clock>.  Requested state = %d (enable/disable), actual state (reference count) = %d"},
	{CLOCK_EVENT_FREQ,"Clock Name: %plugin[1]<clock>.  Frequency = %d"},
	{CLOCK_EVENT_PLL_STATUS,"Clock PLL %d.	 Status = %d"},
	{CLOCK_EVENT_POWER_COLLAPSE,"Clock Power Collapse: %plugin[3]<clock>."},
	{CLOCK_EVENT_POWER_RESTORE,"Clock Power Restore:  %plugin[3]<clock>."},
	{CLOCK_EVENT_BIMC_COLLAPSE,"Clock BIMC Collapse:  %plugin[2]<clock>."},
	{CLOCK_EVENT_BIMC_RESTORE,"Clock BIMC Restore:   %plugin[2]<clock>."},
	{CLOCK_EVENT_CX,"Clock CX voltage = %d"},
	{CLOCK_EVENT_GFX,"Clock GFX voltage = %d"},
	{CLOCK_EVENT_EBI,"Clock VDDA_EBI voltage = %d"},
	{CLOCK_EVENT_LAST=511,"Clock last event placeholder"},
	{BUS_EVENT_INIT_DONE=64,"icb_init_cb: complete"},
	{BUS_EVENT_SLAVE_XLATE,"icb_slaves_translate_cb: (%plugin[1]<busslave>) (bandwidth %x %x)"},
	{BUS_EVENT_SLAVE_APPLY,"icb_slaves_apply_cb: (%plugin[1]<busslave>) (bandwidth %x %x)"},
	{BUS_EVENT_MASTER_XLATE,"icb_masters_translate_cb: (%plugin[1]<busmaster>) (bandwidth %x %x)"},
	{BUS_EVENT_MASTER_APPLY,"icb_masters_apply_cb: (%plugin[1]<busmaster>) (bandwidth %x %x)"},
	{BUS_EVENT_SPDM_XLATE,"icb_spdm_req_translate_cb: (request %d)"},
	{BUS_EVENT_SPDM_APPLY,"icb_spdm_req_apply_cb: (request %d)"},
	{BUS_EVENT_SPDM_STATE,"request_spdm_clock: (request %d)"},
	{BUS_EVENT_MASTER_LATENCY_XLATE,"icb_master_latency_translate_cb: (%plugin[1]<busmaster>) (latency %d)"},
	{BUS_EVENT_MASTER_LATENCY_APPLY,"icb_master_latency_apply_cb: (%plugin[1]<busmaster>) (latency %d)"},
	{BUS_EVENT_ICB_LAST=78,"placeholder last icb swevent"},
	{TRACER_EVENT_ID_MAX,""}
};

#endif // _TRACER_EVENT_TBL_H
