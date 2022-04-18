/** vi: tw=128 ts=3 sw=3 et :
@file rcinit_rex.c
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
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/rcinit/src/rcinit_rex.c#1 $
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

#include "rcinit_rex.h"
#include "rcinit_internal.h"

rex_tcb_type* rcinit_lookup_rextask_info(RCINIT_INFO info)
{
   rcinit_info_t* rcinit_p = (rcinit_info_t*)info;

   if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle &&
       (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type))
   {
      return(rex_tcb_type*)rcinit_p->handle->tid_p;
   }

   return RCINIT_NULL;
}

rex_tcb_type* rcinit_lookup_rextask(RCINIT_NAME name)
{
   RCINIT_INFO info = rcinit_lookup(name);

   if (RCINIT_NULL != info)
   {
      return rcinit_lookup_rextask_info(info);
   }

   return RCINIT_NULL;
}

RCINIT_GROUP rcinit_lookup_group_rextask(rex_tcb_type* tid)
{
   RCINIT_GROUP rc = RCINIT_GROUP_0;
   const rcinit_info_t*** rcinit_sequence_group;

   rcinit_sequence_group = rcinit_internal_groups[rcinit_internal.policy_curr];

   while (RCINIT_NULL != *rcinit_sequence_group)
   {
      const rcinit_info_t** rcinit_group = *rcinit_sequence_group;

      while (RCINIT_NULL != *rcinit_group)
      {
         const rcinit_info_t* rcinit_p = *rcinit_group;

         if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle &&       // must have a context handle
             (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type) &&
             (rex_tcb_type*)rcinit_p->handle->tid_p == tid)                      // tcb pointer associates with group
         {
            return rc;
         }

         rcinit_group++;                                                         // next; this group
      }

      rc++;                                                                      // processing next group

      rcinit_sequence_group++;                                                   // next; sequence group
   }

   return RCINIT_GROUP_NONE;                                                     // no task context in framework processing
}

RCINIT_INFO rcinit_lookup_info_rextask(rex_tcb_type* tid)
{
   RCINIT_INFO rc = RCINIT_NULL;
   const rcinit_info_t*** rcinit_sequence_group;

   rcinit_sequence_group = rcinit_internal_groups[rcinit_internal.policy_curr];

   while (RCINIT_NULL != *rcinit_sequence_group)
   {
      const rcinit_info_t** rcinit_group = *rcinit_sequence_group;

      while (RCINIT_NULL != *rcinit_group)
      {
         const rcinit_info_t* rcinit_p = *rcinit_group;

         if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle &&       // must have a context handle
             (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type) &&
             (rex_tcb_type*)rcinit_p->handle->tid_p == tid)                      // tcb pointer associates with group
         {
            return(RCINIT_INFO)rcinit_p;
         }

         rcinit_group++;                                                         // next; this group
      }

      rcinit_sequence_group++;                                                   // next; sequence group
   }

   return rc;                                                                    // no task context in framework processing
}

static void TASK_ENTRY(unsigned long argv)
{
   const rcinit_info_t* rcinit_p = (const rcinit_info_t*)argv;

   if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle)
   {
      void (*entry)(unsigned long) = (void (*)(unsigned long))rcinit_p->handle->entry;

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

               entry(restart);

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

void rcinit_internal_start_rextask(const rcinit_info_t* rcinit_p, void* entry)
{
   if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle)
   {
      if (RCINIT_NULL == rcinit_p->handle->tid_p)
      {
         if (NULL == (rcinit_p->handle->tid_p = (rcinit_tid_p)rcinit_internal_malloc(sizeof(rex_tcb_type))))
         {
            ERR_FATAL("rextask context creation", 0, 0, 0);
         }
      }

      secure_memset(rcinit_p->handle->tid_p, 0, sizeof(rex_tcb_type));           // rex api requires tcb to be zero

      if (RCINIT_NULL != rcinit_p->handle->stack)
      {
         secure_memset(rcinit_p->handle->stack, 0, rcinit_p->stksz);             // rex trace32 extensions requires stack to be zero
      }

      rcinit_p->handle->entry = (rcinit_entry_p)entry;

      RCINIT_MAP_REX_DEF_TASK(rcinit_p->cpu_affinity, rcinit_p->handle->tid_p,
                              (unsigned char*)rcinit_p->handle->stack, rcinit_p->stksz,
                              RCINIT_MAP_PRIO_REX(rcinit_p->prio), TASK_ENTRY, (unsigned long)rcinit_p, (char*)rcinit_p->name,
                              FALSE, -1);
   }
}
