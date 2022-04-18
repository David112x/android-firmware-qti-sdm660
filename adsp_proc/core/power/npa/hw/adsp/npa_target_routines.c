/*============================================================================
@file npa_target_routines.c

NPA target initialization for MSM8974 ADSP Kernel PD

Copyright (c) 2010 - 2017 QUALCOMM Technologies, Incorporated.
All Rights Reserved.
QUALCOMM Proprietary/GTDR

$Header: //components/rel/core.qdsp6/1.0.c2/power/npa/hw/adsp/npa_target_routines.c#1 $
============================================================================*/
#include "npa_internal.h"
#include "npa_remote_resource.h"

/* RPM available callback, defined in npa_remote_rpm_protocol.c */
extern void npa_rpm_available_cb( void*, unsigned int, void*, unsigned int );

#ifdef NPA_USES_QDI
/* NPA/QDI init routine, defined in npa_remote_qdi_drv.c */
extern void npa_qdi_init(void);

/* NOTE: It doesn't matter if undefined resources are entered in this list
   as NPA uses resource_available to only publish available resources */
static const char *npa_qdi_pd1_resources[] = 
{ 
  "/core/cpu/latency",
  "/core/cpu/latency/usec",
  "/core/cpu/wakeup",
  "/core/cpu/vdd",
  "/rail/vdd_dig",
  "/core/cpu/l2cache",
  "/core/uSleep",
  "/sleep/max_duration/usec",
  "/pmic/client/sensor_dsp_proxy",
  "/clk/pnoc",
  "/pmic/client/rail_cx",
  "/vdd/cx",
  "/clk/cpu",
  "/clk/snoc",
  "/clk/bimc",
  "/pmic/client/sensor_vdd",
  "/pmic/client/sensor_vdd_2",
  "/pmic/client/sensor_vddio",
  "/pmic/client/sensor_vddio_2",
  "/clk/qdss",
  "/vdd/lpicx"
};
#endif /* NPA_USES_QDI */

void npa_target_init( void )
{
  npa_resource_available_cb( "/init/rpm", npa_rpm_available_cb,  NULL ); 

#ifdef NPA_USES_QDI
  npa_qdi_init();
  
  /* Publish some resources to ALL PD's */
  npa_remote_publish_resources( NPA_ALL_PDS, 
                                sizeof(npa_qdi_pd1_resources)/sizeof(char *),
                                npa_qdi_pd1_resources );
#endif
}

#ifdef NPA_SCHEDULED_REQUESTS_SUPPORTED
#include "rcinit.h"

/* Create the NPA Scheduler Thread */
void npa_scheduler_init_rctask( void )
{
  RCINIT_INFO handle = rcinit_lookup("npaScheduler");

  if (RCINIT_NULL != handle)
  {
    rcinit_initfn_spawn_task(handle, npaScheduler_task);
  }
}
#endif /* NPA_SCHEDULED_REQUESTS_SUPPORTED */
