/*===========================================================================

  Copyright (c) 2012-2013,2016 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

===========================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include "thermal.h"
#include "sensors-tsens.h"
#include "sensors-adc.h"
#include "sensors-bcl.h"
#include "sensors-gen.h"
#include "sensors-qmi.h"
#include "sensors-thermal.h"
#include "sensors.h"
#include "sensors_manager_internal.h"

struct alias_map_t {
	char *sensor_name;
	char *alias;
};

static struct alias_map_t alias_map_8974[] = {
	{"tsens_tz_sensor5", "cpu0" },
	{"tsens_tz_sensor6", "cpu1" },
	{"tsens_tz_sensor7", "cpu2" },
	{"tsens_tz_sensor8", "cpu3" },
	{"tsens_tz_sensor3", "pop_mem" },
};

static struct alias_map_t alias_map_8x62[] = {
	{"tsens_tz_sensor5", "cpu0" },
	{"tsens_tz_sensor6", "cpu1" },
	{"tsens_tz_sensor7", "cpu2" },
	{"tsens_tz_sensor8", "cpu3" },
	{"tsens_tz_sensor2", "pop_mem" },
};

static struct sensor_info tsens_sensors[] = {
	{
		.name = "tsens_tz_sensor0",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 0,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor1",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 1,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor2",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 2,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor3",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 3,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor4",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 4,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor5",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 5,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor6",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 6,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor7",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 7,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor8",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 8,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor9",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 9,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "tsens_tz_sensor10",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = tsens_sensor_interrupt_wait,
		.update_thresholds = tsens_sensor_update_thresholds,
		.tzn = 10,
		.data = NULL,
		.interrupt_enable = 1,
	},
	{
		.name = "pa_therm0",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = NULL,
		.update_thresholds = NULL,
		.tzn = 13,
		.data = NULL,
		.interrupt_enable = 0,
	},
	{
		.name = "pa_therm1",
		.setup = tsens_sensors_setup,
		.shutdown = tsens_sensors_shutdown,
		.get_temperature = tsens_sensor_get_temperature,
		.interrupt_wait = NULL,
		.update_thresholds = NULL,
		.tzn = 14,
		.data = NULL,
		.interrupt_enable = 0,
	},
};

static struct sensor_info gen_sensors_8974[] = {
	{
		.name = "pm8941_tz",
		.setup = gen_sensors_setup,
		.shutdown = gen_sensors_shutdown,
		.get_temperature = gen_sensor_get_temperature,
		.interrupt_wait = NULL,
		.update_thresholds = NULL,
		.tzn = 0,
		.data = NULL,
		.interrupt_enable = 0,
		.scaling_factor = 1000,
	},
	{
		.name = "pm8841_tz",
		.setup = thermal_sensor_setup,
		.shutdown = thermal_sensor_shutdown,
		.get_temperature = thermal_sensor_get_temperature,
		.interrupt_wait = thermal_sensor_interrupt_wait,
		.update_thresholds = NULL,
		.tzn = 11,
		.data = NULL,
		.interrupt_enable = 1,
		.scaling_factor = 1000,
	},
};

static struct sensor_info gen_sensors_8974_pro_ac[] = {
	{
		.name = "pm8941_tz",
		.setup = gen_sensors_setup,
		.shutdown = gen_sensors_shutdown,
		.get_temperature = gen_sensor_get_temperature,
		.interrupt_wait = NULL,
		.update_thresholds = NULL,
		.tzn = 0,
		.data = NULL,
		.interrupt_enable = 0,
	},
	{
		.name = "pma8084_tz",
		.setup = thermal_sensor_setup,
		.shutdown = thermal_sensor_shutdown,
		.get_temperature = thermal_sensor_get_temperature,
		.interrupt_wait = thermal_sensor_interrupt_wait,
		.update_thresholds = NULL,
		.tzn = 11,
		.data = NULL,
		.interrupt_enable = 1,
		.scaling_factor = 1000,
	},
};

static struct sensor_info gen_sensors_8x62[] = {
	{
		.name = "pma8084_tz",
		.setup = gen_sensors_setup,
		.shutdown = gen_sensors_shutdown,
		.get_temperature = gen_sensor_get_temperature,
		.interrupt_wait = NULL,
		.update_thresholds = NULL,
		.tzn = 0,
		.data = NULL,
		.interrupt_enable = 0,
	},
};

static struct sensor_info bcl_sensors[] = {
	{
		.name = "bcl",
		.setup = bcl_setup,
		.shutdown = bcl_shutdown,
		.get_temperature = bcl_get_iavail,
		.interrupt_wait = bcl_interrupt_wait,
		.update_thresholds = bcl_update_thresholds,
		.tzn = 0,
		.data = NULL,
		.interrupt_enable = 1,
	}
};

static char *find_alias(const char * sensor_name)
{
	char               *ret_val = NULL;
	static uint8_t      init;
	static struct alias_map_t *arr;
	static uint8_t      arr_len;

	if (init == 0) {
		switch (therm_get_msm_id()) {
			case THERM_MSM_8974:
			case THERM_MSM_8974PRO_AA:
			case THERM_MSM_8974PRO_AB:
			case THERM_MSM_8974PRO_AC:
				arr = alias_map_8974;
				arr_len = ARRAY_SIZE(alias_map_8974);
				break;
			case THERM_MSM_8x62:
				arr = alias_map_8x62;
				arr_len = ARRAY_SIZE(alias_map_8x62);
				break;
			default:
				msg("%s: Uknown B-family device", __func__);
				break;
		}
		init = 1;
	}

	if (arr != NULL) {
		uint8_t idx;
		for (idx = 0; idx < arr_len; idx++) {
			if (strncmp(sensor_name, arr[idx].sensor_name,
				    MAX_SENSOR_NAME_LEN) == 0) {
				ret_val = arr[idx].alias;
				break;
			}
		}
	}
	return ret_val;
}

static void generic_wait(struct sensors_mgr_sensor_info *sensor_mgr)
{
	struct sensor_info *sensor = (struct sensor_info *)sensor_mgr->data;
	sensor->interrupt_wait(sensor);
}

static int generic_read(struct sensors_mgr_sensor_info *sensor_mgr)
{
	struct sensor_info *sensor = (struct sensor_info *)sensor_mgr->data;
	return sensor->get_temperature(sensor);
}

static void generic_update_thresholds(struct sensors_mgr_sensor_info *sensor_mgr)
{
	struct sensor_info *sensor = (struct sensor_info *)sensor_mgr->data;
	sensor->update_thresholds(sensor,
				 &sensor_mgr->active_thresh.thresh);
}

static void generic_shutdown(struct sensors_mgr_sensor_info *sensor_mgr)
{
	struct sensor_info *sensor = (struct sensor_info *)sensor_mgr->data;
	sensor->shutdown(sensor);

	free(sensor_mgr);
}

static int add_tgt_sensor(struct sensor_info *sensor)
{
	int ret_val = 0;
	struct sensors_mgr_sensor_info *sensor_mgr = NULL;

	if (!sensor->scaling_factor)
		sensor->scaling_factor = DEFAULT_SENSOR_SCALING_FACTOR;

	pthread_mutex_init(&(sensor->read_mtx), NULL);

	sensor_mgr = malloc(sizeof(struct sensors_mgr_sensor_info));
	if (sensor_mgr == NULL) {
		msg("%s: malloc failed.\n", __func__);
		ret_val = -(ENOMEM);
		goto error_handler;
	}
	memset(sensor_mgr, 0, sizeof(struct sensors_mgr_sensor_info));

	sensor_mgr->name = sensor->name;
	sensor_mgr->alias = find_alias(sensor->name);

	if (sensor->setup(sensor) == 0) {
		ret_val = -(EFAULT);
		goto error_handler;
	}

	sensor_mgr->data = (void*) sensor;
	sensor->sensor_mgr = sensor_mgr;

	sensor_mgr->get_temperature = generic_read;
	sensor_mgr->shutdown = generic_shutdown;

	if (sensor->interrupt_wait)
		sensor_mgr->wait = generic_wait;
	if (sensor->update_thresholds)
		sensor_mgr->update_thresholds = generic_update_thresholds;

	sensors_manager_add_sensor(sensor_mgr);

error_handler:
	if (ret_val) {
		if (sensor_mgr)
			free(sensor_mgr);
	}
	return ret_val;
}

int add_tgt_sensors_set(struct sensor_info *sensor_arr, int arr_size)
{
	int idx = 0;
	int ret_val = 0;

	for (idx = 0; idx < arr_size; idx++) {
		if (add_tgt_sensor(&sensor_arr[idx]) != 0) {
			msg("%s: Error adding %s\n", __func__,
			    sensor_arr[idx].name);
			ret_val = -(EFAULT);
			break;
		}
	}

	return ret_val;
}
static int min_mode;
int sensors_init(int minimum_mode)
{
	int ret_val = 0;
	min_mode = minimum_mode;

	if (!min_mode)
		modem_ts_qmi_init();

	if (add_tgt_sensors_set(tsens_sensors,
			   ARRAY_SIZE(tsens_sensors)) != 0) {
		msg("%s: Error adding TSENS TS\n", __func__);
		ret_val = -(EFAULT);
	}

	/* GEN */
	switch (therm_get_msm_id()) {
		case THERM_MSM_8x62:
			if (add_tgt_sensors_set(gen_sensors_8x62,
					   ARRAY_SIZE(gen_sensors_8x62)) != 0) {
				msg("%s: Error adding GEN TS\n", __func__);
				ret_val = -(EFAULT);
			}
			break;
		case THERM_MSM_8974PRO_AC:
			if (add_tgt_sensors_set(gen_sensors_8974_pro_ac,
					   ARRAY_SIZE(gen_sensors_8974_pro_ac)) != 0) {
				msg("%s: Error adding GEN TS\n", __func__);
				ret_val = -(EFAULT);
			}
			break;
		case THERM_MSM_8974:
		case THERM_MSM_8974PRO_AA:
		case THERM_MSM_8974PRO_AB:
		default:
			if (add_tgt_sensors_set(gen_sensors_8974,
					   ARRAY_SIZE(gen_sensors_8974)) != 0) {
				msg("%s: Error adding GEN TS\n", __func__);
				ret_val = -(EFAULT);
			}
			break;
	}

	/* BCL */
	if (add_tgt_sensors_set(bcl_sensors,
			   ARRAY_SIZE(bcl_sensors)) != 0) {
		msg("%s: Error adding BCL TS\n", __func__);
		ret_val = -(EFAULT);
	}

	return ret_val;
}

void sensors_release(void)
{
	if (!min_mode)
		modem_qmi_ts_comm_release();
}
