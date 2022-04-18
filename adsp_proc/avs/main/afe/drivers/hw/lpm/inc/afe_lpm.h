/*========================================================================
hwd_devcfg.h

This file contains the implementation of avtimer server.

Copyright (c) 2013,2017 Qualcomm Technologies, Inc. (QTI).  All Rights Reserved.
Qualcomm Technologies, Inc. (QTI) Proprietary.  Export of this technology or software is regulated
by the U.S. Government, Diversion contrary to U.S. law prohibited.
*//*====================================================================== */

#ifndef AFE_LPM_H
#define AFE_LPM_H

#include "AFEInternal.h"

#ifdef __cplusplus
#include <new>
extern "C" {
#endif //__cplusplus

#include "qurt_elite_types.h"

#define AFE_SSR_DUMP_LPM_MEM
#undef AFE_SSR_DUMP_LPM_MEM

ADSPResult lpm_init(void);
ADSPResult lpm_deinit(void);

/* Used to map lpm memory for the client.
 * Will only create the memory region if being called
 * for the first time in a use case
 */
ADSPResult afe_lpm_client_register(void);

/* Used to unmap lpm memory for the client.
 * Will only destroy the memory region if being called
 * for the last time in a use case
 */
ADSPResult afe_lpm_client_deregister(void);

/* Returns the Cached status of LPM memory,
 * TRUE: Cached
 * False: Un-cached
 */
bool_t lpm_is_it_cached(void);

/**
  @brief Function which allocates LPM resources to remote
         client(HLOS).

  @param[in] ptr, pointer to APR packet

  @return  ADSP_EOK on success, an error code on error

*/
ADSPResult afe_request_lpm_resources_by_remote_client_handler(void *ptr);

/**
  @brief Function which releases LPM resources allocated to remote
         client(HLOS).

  @param[in] ptr, pointer to APR packet

  @return  ADSP_EOK on success, an error code on error

*/
ADSPResult afe_release_lpm_resources_by_remote_client_handler(void *ptr);

/*==========================================================================
  Globals
========================================================================== */
extern aud_stat_afe_svc_t *afe_svc_global_ptr;

#ifdef AFE_SSR_DUMP_LPM_MEM
ADSPResult afe_ssr_lpm_dump(void *dump_ptr,  uint64_t lpm_virt_addr, size_t size);
#endif

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // #ifndef AFE_LPM_H
