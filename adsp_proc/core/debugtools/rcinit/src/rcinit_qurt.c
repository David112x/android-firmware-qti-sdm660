/** vi: tw=128 ts=3 sw=3 et :
@file rcinit_qurt.c
@brief This file contains the API for the Run Control Framework, API 2.1
*/
/*=============================================================================
NOTE: The @brief description above does not appear in the PDF.
The tms_mainpage.dox file contains the group/module descriptions that
are displayed in the output PDF generated using Doxygen and LaTeX. To
edit or update any of the group/module text in the PDF, edit the
tms_mainpage.dox file or contact Tech Pubs.
===============================================================================*/
/*=============================================================================
Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
===============================================================================*/
/*=============================================================================
Edit History
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/rcinit/src/rcinit_qurt.c#1 $
$DateTime: 2020/02/10 01:57:30 $
$Change: 22511909 $
$Author: pwbldsvc $
===============================================================================*/

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
#include "tracer.h"
#include "rcinit_tracer_swe.h"
#endif

#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
#include "msg.h"
#endif

#include "err.h"
#include "stringl/stringl.h"

#include "rcinit_qurt.h"
#include "rcinit_internal.h"

qurt_thread_t rcinit_lookup_qurttask_info(RCINIT_INFO info)
{
   rcinit_info_t* rcinit_p = (rcinit_info_t*)info;

   if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle && RCINIT_TASK_QURTTASK == rcinit_p->type)
   {
      return(qurt_thread_t)(rcinit_p->handle->tid_p);
   }

   return RCINIT_ZERO;
}

qurt_thread_t rcinit_lookup_qurttask(RCINIT_NAME name)
{
   RCINIT_INFO info = rcinit_lookup(name);

   if (RCINIT_NULL != info)
   {
      return rcinit_lookup_qurttask_info(info);
   }

   return RCINIT_ZERO;
}

static void TASK_ENTRY(void* argv)
{
   const rcinit_info_t* rcinit_p = (const rcinit_info_t*)argv;

   if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle)
   {
      void (*entry)(void*) = (void (*)(void*))rcinit_p->handle->entry;

      rcinit_internal_tls_set_specific(rcinit_internal.tls_key, (void*)rcinit_p);

      if (RCINIT_NULL != entry && RCINIT_ENTRY_NONE != entry)
      {
         unsigned long restart = 0;

         rcinit_internal_hs_list_add(rcinit_internal.hs_init, rcinit_internal.group_curr, rcinit_p->name);

         do
         {
            RCXH_TRY
            {
#if defined(RCINIT_TRACER_SWEVT)
               tracer_event_simple_vargs(RCINIT_SWE_INIT_TASK_RN, 2, rcinit_internal.group_curr, rcinit_p->hash);
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
               MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "task begins group %x task_hash %x task_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

               entry((void*)restart);

               restart = 0;
            }

            RCXH_CATCH(RCXH_RCINIT_TASK_RESTART)
            {
#if defined(RCINIT_TRACER_SWEVT) && defined(RCINIT_SWE_INIT_TASK_RS)
               tracer_event_simple_vargs(RCINIT_SWE_INIT_TASK_RS, 2, rcinit_internal.group_curr, rcinit_p->hash);
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
               MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "task exception restart group %x task_hash %x task_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

               restart++;
            }

            RCXH_CATCH(RCXH_RCINIT_TASK_END)
            {
#if defined(RCINIT_TRACER_SWEVT) && defined(RCINIT_SWE_INIT_TASK_E)
               tracer_event_simple_vargs(RCINIT_SWE_INIT_TASK_E, 2, rcinit_internal.group_curr, rcinit_p->hash);
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
               MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "task exception end group %x task_hash %x task_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

               restart = 0;
            }

            RCXH_ENDTRY;

         } while (0 < restart);

#if defined(RCINIT_TRACER_SWEVT)
         tracer_event_simple_vargs(RCINIT_SWE_INIT_TASK_XT, 2, rcinit_internal.group_curr, rcinit_p->hash);
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
         MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "task exit group %x task_hash %x task_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif
      }
   }

   else
   {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
      MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "task exit group %x no context", rcinit_internal.group_curr, 0, 0);
#endif
   }
}

void rcinit_internal_start_qurttask(const rcinit_info_t* rcinit_p, void* entry)
{
   if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle)
   {
      qurt_thread_attr_t qurt_attr;

      if (RCINIT_NULL != rcinit_p->handle->stack)
      {
         secure_memset(rcinit_p->handle->stack, RCINIT_STACK_INIT, rcinit_p->stksz);
      }

      qurt_thread_attr_init(&qurt_attr);
      qurt_thread_attr_set_name(&qurt_attr, (char*)rcinit_p->name);
      qurt_thread_attr_set_stack_size(&qurt_attr, rcinit_p->stksz);
      qurt_thread_attr_set_stack_addr(&qurt_attr, rcinit_p->handle->stack);
      qurt_thread_attr_set_priority(&qurt_attr, RCINIT_MAP_PRIO_QURT(rcinit_p->prio)); // qurt priority is 0 = high, invert to match 0 = low
      qurt_thread_attr_set_affinity(&qurt_attr, rcinit_p->cpu_affinity);

      rcinit_p->handle->entry = (rcinit_entry_p)entry;

      qurt_thread_create((qurt_thread_t*)(&(rcinit_p->handle->tid_p)), &qurt_attr, TASK_ENTRY, (void*)rcinit_p);
   }
}
