/** vi: tw=128 ts=3 sw=3 et :
@file rcinit_init.c
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
Copyright (c) 2015 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
===============================================================================*/
/*=============================================================================
Edit History
$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/rcinit/src/rcinit_init.c#1 $
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
#include "stdint.h"
#include "stringl/stringl.h"

#include "DALSysTypes.h"
#include "DALPropDef.h"

#include "rcinit_dal.h"
#include "rcinit_internal.h"

#include "rcecb.h"
#include "rcesn.h"
#include "rcevt.h"

/////////////////////////////////////////////////////////////////////
// Localized Type Declarations
/////////////////////////////////////////////////////////////////////

#define dwMaxNumEvents        2
#define RCINIT_WORKER         "rcinit_worker"

#define BASE_ALIGN_8BYTE      0x00000007
#define BASE_ALIGN_16BYTE     0x0000000f
#define BASE_ALIGN_32BYTE     0x0000001f
#define BASE_ALIGN_1KBYTE     0x000003ff
#define BASE_ALIGN_4KBYTE     0x00000fff

#define stack_base_alignment  BASE_ALIGN_8BYTE
#define stack_base_pad(n)     (((unsigned long)(n)+stack_base_alignment)&~stack_base_alignment)

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
extern const tracer_event_id_t rcinit_swe_event_init[RCINIT_GROUP_MAX];          // internal
#endif

/////////////////////////////////////////////////////////////////////
// Localized Storage
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// Init Function Support
/////////////////////////////////////////////////////////////////////

/*===========================================================================

 FUNCTION worker

 DESCRIPTION
 internal shell functions

 DEPENDENCIES
 none

 RETURN VALUE
 operation success

 SIDE EFFECTS
 shuts down by registration to system monitor
 ===========================================================================*/
static DALResult rcinit_worker(DALSYSEventHandle hUnused, void* tid)
{
   const rcinit_info_t** rcinit_group_p = rcinit_internal.worker_argv;

   while (RCINIT_NULL != *rcinit_group_p)
   {
      const rcinit_info_t* rcinit_p = *rcinit_group_p;

      if (IS_INITFN(rcinit_p))
      {
         // STALLING HERE?

         // BLOCKING HERE OCCURS ONLY WHEN THE INITFN IS USING KERNEL BLOCKING
         // MECHANISMS. CHECK WITH THE TECH AREA OWNING THE CALLBACK.

         rcinit_internal.initfn_curr = (void (*)(void))(rcinit_p->entry);

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
         tracer_event_simple_vargs(RCINIT_SWE_INIT_FUNC_RN, 2, rcinit_internal.group_curr, rcinit_internal.initfn_curr);
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
         MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "function enter group %x func_hash %x func_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

         // Initialization functions are triggered for execution at this point. They
         // are considered callbacks, and executed within the context of the 'rcinit_worker'
         // task. The 'rcinit_worker' task by itself does not supply any heap management, so
         // heap allocations tracked to 'rcinit_worker' context are actually performed by
         // other tech area supplied callbacks.

         // TODO: save current nhlos context name. set nhlos context name to rcinit_p->name. supply better runtime
         // tracking instruments based on context name. This might require a temporary context be established and
         // reclaimed.

         rcinit_internal.initfn_curr();

         // TODO: restore nhlos context name.

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
         tracer_event_simple_vargs(RCINIT_SWE_INIT_FUNC_XT, 2, rcinit_internal.group_curr, rcinit_internal.initfn_curr);
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
         MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "function exit group %x func_hash %x func_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

         rcinit_internal.initfn_curr = (void (*)(void))RCINIT_NULL;
      }

      rcinit_group_p++;
   }

   if (DAL_SUCCESS != DALSYS_EventCtrl(rcinit_internal.hEventWorkLoopAck, DALSYS_EVENT_CTRL_TRIGGER))
   {
      ERR_FATAL("worker ack", 0, 0, 0);
   }

   if (hUnused) {;}
   if (tid) {;}

   return DAL_SUCCESS;
}

void rcinit_dal_loop_worker_create(void)
{
   if (DAL_SUCCESS != DALSYS_EventCreate(DALSYS_EVENT_ATTR_WORKLOOP_EVENT, &rcinit_internal.hEventWorkLoop, NULL))
   {
      ERR_FATAL("worker event creation", 0, 0, 0);
   }
   if (DAL_SUCCESS != DALSYS_EventCreate(DALSYS_EVENT_ATTR_NORMAL, &rcinit_internal.hEventWorkLoopAck, NULL))
   {
      ERR_FATAL("worker create event initfn", 0, 0, 0);
   }
   if (DAL_SUCCESS != DALSYS_RegisterWorkLoopEx(RCINIT_WORKER, rcinit_lookup_stksz(RCINIT_WORKER), rcinit_lookup_prio(RCINIT_WORKER), dwMaxNumEvents, &rcinit_internal.hWorkLoop, NULL))
   {
      ERR_FATAL("worker work loop registration", 0, 0, 0);
   }
   if (DAL_SUCCESS != DALSYS_AddEventToWorkLoop(rcinit_internal.hWorkLoop, rcinit_worker, RCINIT_NULL, rcinit_internal.hEventWorkLoop, NULL))
   {
      ERR_FATAL("worker work loop event addition", 0, 0, 0);
   }
}

/*===========================================================================

 FUNCTION rcinit_handshake_init

 DESCRIPTION
 *required* task handshake to rcinit; all tasks managed by the framework *must*
 *call this api or they will block startup. this is by design.

 DEPENDENCIES
 none

 RETURN VALUE
 operation success

 SIDE EFFECTS
 none
 ===========================================================================*/
void rcinit_handshake_init(void)                                                 // preferred API
{
   rcinit_info_t* rcinit_p = (rcinit_info_t*)rcinit_internal_tls_get_specific(rcinit_internal.tls_key);

   if (RCINIT_NULL == rcinit_p)
   {
      unsigned long task_hash;
      char task_name[RCINIT_NAME_MAX];

      task_hash = rcinit_internal_task_name(task_name, sizeof(task_name));

#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
      MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_ERROR, "TASK NOT IN RCINIT FRAMEWORK MAY NOT HANDSHAKE group %x task_hash %x task_name %s", rcinit_internal.group_curr, task_hash, task_name);
#endif
   }

   else
   {
      // edge case group 0, initfn starting a task, must call rcinit_handshake

      if (RCINIT_GROUP_0 == rcinit_internal.group_curr &&                           // processing group 0 (only)
          rcinit_process_group_init_fn == rcinit_internal.process_state)            // processing initfns (only)
      {
         rcinit_internal_hs_list_hs(rcinit_internal.hs_init, rcinit_internal.group_curr, rcinit_p->name);

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
         tracer_event_simple_vargs(RCINIT_SWE_INIT_TASK_HS, 2, rcinit_internal.group_curr, rcinit_p->hash); // HS accepted
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
         MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "handshake group %x task_hash %x task_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

         if (DAL_SUCCESS != DALSYS_EventCtrl(rcinit_internal.hEventInitFnSpawn, DALSYS_EVENT_CTRL_TRIGGER))
         {
            ERR_FATAL("worker event initfn trigger", 0, 0, 0);
         }
      }

      // all other use case collect and wait for the defineack

      else
      {
         RCEVT_THRESHOLD count = rcevt_getcount_handle(rcinit_internal.defineack) + 1;

         rcinit_internal_hs_list_hs(rcinit_internal.hs_init, rcinit_internal.group_curr, rcinit_p->name);

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
         tracer_event_simple_vargs(RCINIT_SWE_INIT_TASK_HS, 2, rcinit_internal.group_curr, rcinit_p->hash); // HS accepted
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
         MSG_SPRINTF_3(MSG_SSID_TMS, MSG_LEGACY_HIGH, "handshake group %x task_hash %x task_name %s", rcinit_internal.group_curr, rcinit_p->hash, rcinit_p->name);
#endif

         if (rcevt_signal_handle(rcinit_internal.define)) {;}

         if (rcevt_wait_count_handle(rcinit_internal.defineack, count)) {;}
      }
   }
}

void rcinit_handshake_startup(void)
{
   rcinit_handshake_init();                                                      // use preferred API
}

/*===========================================================================

 FUNCTION rcinit_initfn_spawn_task

 DESCRIPTION
 required wrapper for an init function to spawn a task (very specialized edge
 case found during sequence group 0, this should be the exception)

 DEPENDENCIES
 Requires existing RCINIT task database information where the task entry
 point is NULL. The static data is preallocated, and this call binds the
 entry point to the context and starts it. Edge case; only allowed from
 Group 0 initfn processing. all other use cases are not supported and
 are considered a bug.

 RETURN VALUE
 none

 SIDE EFFECTS
 task must call rcinit_handshake_startup(); else startup process will block
 as designed

 ===========================================================================*/
void rcinit_initfn_spawn_task(RCINIT_INFO info_p, void* entry)
{
   boolean started = FALSE;
   rcinit_info_t* rcinit_p = (rcinit_info_t*)info_p;

   if (RCINIT_NULL != rcinit_p &&
       RCINIT_GROUP_0 == rcinit_lookup_group(rcinit_p->name) &&                  // must be in group 0 (only)
       RCINIT_GROUP_0 == rcinit_internal.group_curr &&                           // processing group 0 (only)
       rcinit_process_group_init_fn == rcinit_internal.process_state &&          // processing initfns (only)
       RCINIT_NULL == rcinit_p->entry &&                                         // must not have an entry (specialized)
       RCINIT_NULL != entry)                                                     // must have an entry point argument
   {
      // DAL Event Objects Are Protected on Context Allowed to Wait (Create/Wait/Destroy)
      if (DAL_SUCCESS != DALSYS_EventCreate(DALSYS_EVENT_ATTR_NORMAL, &rcinit_internal.hEventInitFnSpawn, NULL))
      {
         ERR_FATAL("initfnspawn event", 0, 0, 0);
      }

      if (RCINIT_NULL != rcinit_p->handle && RCINIT_ENTRY_NONE != rcinit_p->handle->entry)
      {
         if (RCINIT_TASK_DALTASK == rcinit_p->type)
         {
            rcinit_internal_start_daltask(rcinit_p, entry);                      // launches task and fills in overhead

            started = TRUE;
         }

         else if (RCINIT_TASK_POSIX == rcinit_p->type)
         {
            if (RCINIT_STACK_NULL == rcinit_p->handle->stack)
            {
               rcinit_p->handle->stack = (rcinit_stack_p)stack_base_pad(rcinit_internal_malloc(stack_base_pad(rcinit_p->stksz)));
            }

            rcinit_internal_start_posix(rcinit_p, entry);                        // launches task and fills in overhead

            started = TRUE;
         }

         else if (RCINIT_TASK_QURTTASK == rcinit_p->type)
         {
            if (RCINIT_STACK_NULL == rcinit_p->handle->stack)
            {
               rcinit_p->handle->stack = (rcinit_stack_p)stack_base_pad(rcinit_internal_malloc(stack_base_pad(rcinit_p->stksz)));
            }

            rcinit_internal_start_qurttask(rcinit_p, entry);                     // launches task and fills in overhead

            started = TRUE;
         }

         else if (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type)
         {
            if (RCINIT_STACK_NULL == rcinit_p->handle->stack)
            {
               rcinit_p->handle->stack = (rcinit_stack_p)stack_base_pad(rcinit_internal_malloc(stack_base_pad(rcinit_p->stksz)));
            }

            rcinit_internal_start_rextask(rcinit_p, entry);                      // launches task and fills in overhead

            started = TRUE;
         }
      }

      // STALLING HERE?

      // BLOCKING HERE OCCURS UNTIL THE SINGLE TASK STARTED PERFORMS ITS HANDSHAKE.
      // THIS IS THE NORMAL MECHANISM. CHECK WITH THE TECH AREA OWNING THE CONTEXT
      // WHEN BLOCKING DURATION BECOMES EXCESSIVE WAITING FOR THE HANDSHAKE.

      if (TRUE == started)
      {
         // DAL Event Objects Are Protected on Context Allowed to Wait (Create/Wait/Destroy)
         if (DAL_SUCCESS != DALSYS_EventWait(rcinit_internal.hEventInitFnSpawn))
         {
            ERR_FATAL("initfnspawn event", 0, 0, 0);
         }
      }
      // DAL Event Objects Are Protected on Context Allowed to Wait (Create/Wait/Destroy)
      if (DAL_SUCCESS != DALSYS_DestroyObject(rcinit_internal.hEventInitFnSpawn))
      {
         ERR_FATAL("initfnspawn event", 0, 0, 0);
      }
   }
   else
   {
      ERR_FATAL("client does not meet requirements", 0, 0, 0);
   }
}

/*===========================================================================

 FUNCTION rcinit_internal_process_groups

 DESCRIPTION
 init function processing
 task define and start signaling

 DEPENDENCIES
 none

 RETURN VALUE
 none

 SIDE EFFECTS
 none

 ===========================================================================*/
void rcinit_internal_process_groups(void)
{
   const rcinit_info_t* rcinit_p;

   rcinit_info_p rcinit_info_rcinit_p = rcinit_lookup("rcinit");

   if (RCINIT_NULL == rcinit_info_rcinit_p)
   {
      ERR_FATAL("rcinit task info not available", 0, 0, 0);
   }

   rcinit_internal.policy_base = rcinit_internal_groups[rcinit_internal.policy_curr]; // initialize before a transition

   ////////////////////////////////////////
   // Process Groups
   ////////////////////////////////////////

   while (rcinit_internal.group_curr < RCINIT_GROUP_MAX)
   {
      unsigned long resource_size;

#if !defined(RCINIT_EXCLUDE_TRACER_SWEVT)
      tracer_event_simple(rcinit_swe_event_init[rcinit_internal.group_curr]);    // software event
#endif
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
      MSG_SPRINTF_1(MSG_SSID_TMS, MSG_LEGACY_HIGH, "initialization begins group %x", rcinit_internal.group_curr);
#endif

      ////////////////////////////////////////
      // Policy Filter Application
      ////////////////////////////////////////

      rcinit_internal.process_state = rcinit_process_group_policy_fn;

      rcinit_internal.group_base = rcinit_internal.policy_base[rcinit_internal.group_curr]; // initialize before a transition

      for (rcinit_internal.group_curr_idx = RCINIT_GROUP_0; RCINIT_NULL != rcinit_internal.group_base[rcinit_internal.group_curr_idx]; rcinit_internal.group_curr_idx++)
      {
         rcinit_p = rcinit_internal.group_base[rcinit_internal.group_curr_idx];

         if (RCINIT_NULL != rcinit_p && RCINIT_NULL == rcinit_p->handle &&
             RCINIT_STKSZ_ZERO == rcinit_p->stksz &&
             RCINIT_TASK_POLICYFN == rcinit_p->type &&
             RCINIT_NULL != rcinit_p->entry)
         {
            static boolean policy_oneshot = FALSE;

            if (FALSE == policy_oneshot)
            {
               RCINIT_NAME(*policyfn)(const RCINIT_NAME[]);
               RCINIT_NAME policy_name;
               RCINIT_POLICY policy;

               policyfn = (RCINIT_NAME(*)(const RCINIT_NAME[]))rcinit_p->entry;
               policy_name = policyfn(rcinit_internal_policy_list);
               policy = rcinit_lookup_policy(policy_name);

               if (RCINIT_POLICY_NONE != policy)
               {
                  policy_oneshot = TRUE;                                         // only one policy transition is allowed

                  rcinit_internal.policy_curr = policy;

                  rcinit_internal.policy_base = rcinit_internal_groups[rcinit_internal.policy_curr];
               }
            }

            break;
         }
      }

      rcinit_internal.group_base = rcinit_internal.policy_base[rcinit_internal.group_curr]; // after transition

      ////////////////////////////////////////
      // Static Resource Sizing
      ////////////////////////////////////////

      rcinit_internal.process_state = rcinit_process_group_sizing;

      resource_size = 0;                                                         // initial group resource allocation (scale is rcinit_stack_t)

      for (rcinit_internal.group_curr_idx = RCINIT_GROUP_0; RCINIT_NULL != rcinit_internal.group_base[rcinit_internal.group_curr_idx]; rcinit_internal.group_curr_idx++)
      {
         rcinit_p = rcinit_internal.group_base[rcinit_internal.group_curr_idx];

         if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle &&       // must have a context handle
             RCINIT_STKSZ_ZERO != rcinit_p->stksz &&                             // must have a stack size
             RCINIT_STACK_NULL == rcinit_p->handle->stack &&                     // must not have an static stack
             RCINIT_NULL != rcinit_p->entry &&                                   // must have an entry
             rcinit_info_rcinit_p != rcinit_p)                                   // must not be rcinit, rcinit is the bootstrap
         {
            if (RCINIT_TASK_DALTASK == rcinit_p->type)
            {
               // NO STACK ALLOCATIONS; DAL WORKLOOPS INTERNALLY MANAGED
            }

            else if (RCINIT_TASK_POSIX == rcinit_p->type)
            {
               resource_size += rcinit_p->stksz;                                 // tech area specified
               resource_size += sizeof(_rcxh_scope_t);                           // handlers overhead
               resource_size = stack_base_pad(resource_size);                    // pad alignment
            }

            else if (RCINIT_TASK_QURTTASK == rcinit_p->type)
            {
               resource_size += rcinit_p->stksz;                                 // tech area specified
               resource_size += sizeof(_rcxh_scope_t);                           // handlers overhead
               resource_size = stack_base_pad(resource_size);                    // pad alignment
            }

            else if (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type)
            {
               resource_size += rcinit_p->stksz;                                 // tech area specified
               resource_size += sizeof(_rcxh_scope_t);                           // handlers overhead
               resource_size = stack_base_pad(resource_size);                    // pad alignment
            }
         }
      }

      ////////////////////////////////////////
      // Static Resource Allocation
      ////////////////////////////////////////

      // One chunck per group to aviod excessive heap fragmentation. We cannot know what
      // the group configuration is until the policy function has been run, so it is not
      // possible to perform an allocation any larger than group based granularity. Less
      // fragmentation comes with a larger allocation.

      // The stack resource allocation is performed as heap is marked as NO EXECUTE space
      // with all products. We are not allowed to supply stacks in areas that potentially
      // will be in EXECUTE capable areas. Stack smashing by buffer overflow should not be
      // able to leave executable code in the stack.

      rcinit_internal.process_state = rcinit_process_group_allocation;

      if (0 != resource_size)                                                    // do not allocate a zero size resource
      {
         resource_size = stack_base_pad(resource_size);                          // pad alignment

         // TODO: save current nhlos context name. set nhlos context name to "STACKS_GROUPx". supply better runtime
         // tracking instruments based on context name. This might require a temporary context be established and
         // reclaimed.

         rcinit_internal.allocs[rcinit_internal.group_curr] = (unsigned char*)rcinit_internal_malloc(resource_size);

         // TODO: restore nhlos context name.

         if (RCINIT_NULL == rcinit_internal.allocs[rcinit_internal.group_curr])
         {
            ERR_FATAL("static resource allocation failure", 0, 0, 0);
         }

         // set for location of next allocation
         rcinit_internal.stacks[rcinit_internal.group_curr] = (rcinit_stack_p)stack_base_pad(rcinit_internal.allocs[rcinit_internal.group_curr]);

         rcinit_internal.stacks_size += resource_size; // measured in KB
      }

      ////////////////////////////////////////
      // Static Resource Assignments
      ////////////////////////////////////////

      // Stack resource allocations are handed out to the tasks; the pointer math is performed bother
      // over rcinit_stack_t sizes and unsigned char* so that at the end, an warning check can be computed
      // and insure that everything matches. Diagnostic instrumets output issues with computed sizes when
      // they are not matching.

      // The small pad location between stacks, when available, is initialized to a known canary. If
      // the small pad location between stacks, when available, has the canary overwritten, then that
      // will indicate a stack overflow from the higher address into the lower address. Triage via
      // Trace32 to identify this specific condition.

      rcinit_internal.process_state = rcinit_process_group_assignment;

      if (0 != resource_size)                                                    // do not allocate a zero size resource
      {
         for (rcinit_internal.group_curr_idx = RCINIT_GROUP_0; RCINIT_NULL != rcinit_internal.group_base[rcinit_internal.group_curr_idx]; rcinit_internal.group_curr_idx++)
         {
            rcinit_p = rcinit_internal.group_base[rcinit_internal.group_curr_idx];

            if (RCINIT_NULL != rcinit_p && RCINIT_NULL != rcinit_p->handle &&    // must have a context handle
                RCINIT_STKSZ_ZERO != rcinit_p->stksz &&                          // must have a stack size
                RCINIT_STACK_NULL == rcinit_p->handle->stack &&                  // must not have an static stack
                RCINIT_NULL != rcinit_p->entry &&                                // must have an entry
                rcinit_info_rcinit_p != rcinit_p)                                // must not be rcinit, rcinit is the bootstrap
            {
               if (RCINIT_TASK_DALTASK == rcinit_p->type)                        // check and handout previously computed allocation
               {
                  // NO STACK ALLOCATIONS; DAL WORKLOOPS INTERNALLY MANAGED
               }

               else if (RCINIT_TASK_POSIX == rcinit_p->type)                     // check and handout previously computed allocation
               {
                  rcinit_p->handle->stack = rcinit_internal.stacks[rcinit_internal.group_curr];

                  rcinit_internal.stacks[rcinit_internal.group_curr] += (rcinit_p->stksz / sizeof(rcinit_stack_t));
                  rcinit_internal.stacks[rcinit_internal.group_curr] += (sizeof(_rcxh_scope_t) / sizeof(rcinit_stack_t));

                  // set for location of next allocation

                  rcinit_internal.stacks[rcinit_internal.group_curr] = (rcinit_stack_p)stack_base_pad(rcinit_internal.stacks[rcinit_internal.group_curr]);

                  if ((unsigned char*)rcinit_internal.stacks[rcinit_internal.group_curr] > rcinit_internal.allocs[rcinit_internal.group_curr] + resource_size)
                  {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
                     MSG_SPRINTF_2(MSG_SSID_TMS, MSG_LEGACY_ERROR, "stack pad check in group %x with posix %s", rcinit_internal.group_curr, rcinit_p->name);
#endif
                  }
               }

               else if (RCINIT_TASK_QURTTASK == rcinit_p->type)                  // check and handout previously computed allocation
               {
                  rcinit_p->handle->stack = rcinit_internal.stacks[rcinit_internal.group_curr];

                  rcinit_internal.stacks[rcinit_internal.group_curr] += (rcinit_p->stksz / sizeof(rcinit_stack_t));
                  rcinit_internal.stacks[rcinit_internal.group_curr] += (sizeof(_rcxh_scope_t) / sizeof(rcinit_stack_t));

                  // set for location of next allocation

                  rcinit_internal.stacks[rcinit_internal.group_curr] = (rcinit_stack_p)stack_base_pad(rcinit_internal.stacks[rcinit_internal.group_curr]);

                  if ((unsigned char*)rcinit_internal.stacks[rcinit_internal.group_curr] > rcinit_internal.allocs[rcinit_internal.group_curr] + resource_size)
                  {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
                     MSG_SPRINTF_2(MSG_SSID_TMS, MSG_LEGACY_ERROR, "stack pad check in group %x with qurt %s", rcinit_internal.group_curr, rcinit_p->name);
#endif
                  }
               }

               else if (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type) // check and handout previously computed allocation
               {
                  rcinit_p->handle->stack = rcinit_internal.stacks[rcinit_internal.group_curr];

                  rcinit_internal.stacks[rcinit_internal.group_curr] += (rcinit_p->stksz / sizeof(rcinit_stack_t));
                  rcinit_internal.stacks[rcinit_internal.group_curr] += (sizeof(_rcxh_scope_t) / sizeof(rcinit_stack_t));

                  // set for location of next allocation

                  rcinit_internal.stacks[rcinit_internal.group_curr] = (rcinit_stack_p)stack_base_pad(rcinit_internal.stacks[rcinit_internal.group_curr]);

                  if ((unsigned char*)rcinit_internal.stacks[rcinit_internal.group_curr] > rcinit_internal.allocs[rcinit_internal.group_curr] + resource_size)
                  {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
                     MSG_SPRINTF_2(MSG_SSID_TMS, MSG_LEGACY_ERROR, "stack pad check in group %x with qurt %s", rcinit_internal.group_curr, rcinit_p->name);
#endif
                  }
               }
            }
         }
      }

      ////////////////////////////////////////
      // Function Process
      ////////////////////////////////////////

      // Initialization functions are triggered for execution at this point. They
      // are considered callbacks, and executed within the context of the 'rcinit_worker'
      // task. The 'rcinit_worker' task by itself does not supply any heap management, so
      // heap allocations tracked to 'rcinit_worker' context are actually performed by
      // other tech area supplied callbacks.

      rcinit_internal.process_state = rcinit_process_group_init_fn;

      for (rcinit_internal.group_curr_idx = RCINIT_GROUP_0; RCINIT_NULL != rcinit_internal.group_base[rcinit_internal.group_curr_idx]; rcinit_internal.group_curr_idx++)
      {
         rcinit_p = rcinit_internal.group_base[rcinit_internal.group_curr_idx];

         if (IS_INITFN(rcinit_p))
         {
            rcinit_internal.worker_argv = rcinit_internal.group_base;

            if (DAL_SUCCESS != DALSYS_EventCtrl(rcinit_internal.hEventWorkLoop, DALSYS_EVENT_CTRL_TRIGGER) ||
                DAL_SUCCESS != DALSYS_EventWait(rcinit_internal.hEventWorkLoopAck) ||
                DAL_SUCCESS != DALSYS_EventCtrl(rcinit_internal.hEventWorkLoopAck, DALSYS_EVENT_CTRL_RESET))
            {
               ERR_FATAL("rcinit_worker trigger", 0, 0, 0);
            }

            break;
         }
      }

      ////////////////////////////////////////
      // Task Process
      ////////////////////////////////////////

      // Tasks are now logically concurrently started. It is required for the task to
      // call the rcinit_handshake_startup function to indicate it is ready to block at
      // the logical barrier for all other tasks performing concurrent initialization.

      // It is highly discouraged for a task context to perform any type of blocking
      // during the initialization portion. Blocking calls can occur following the
      // required call to rcinit_handshake_startup. Any other use is not encouraged,
      // and ultimately could lead to race conditions or other latent bugs based on
      // startup timing that is not so deterministic.

      rcinit_internal.process_state = rcinit_process_group_init_task;

      rcinit_internal.def.curr = 0;                                              // currently defined
      rcinit_internal.def.prev = rcevt_getcount_handle(rcinit_internal.define);  // previously defined

      for (rcinit_internal.group_curr_idx = RCINIT_GROUP_0; RCINIT_NULL != rcinit_internal.group_base[rcinit_internal.group_curr_idx]; rcinit_internal.group_curr_idx++)
      {
         rcinit_p = rcinit_internal.group_base[rcinit_internal.group_curr_idx];

         if (IS_TASK(rcinit_p))
         {
            if (RCINIT_ENTRY_NONE != rcinit_p->handle->entry)
            {
               if (RCINIT_TASK_DALTASK == rcinit_p->type)
               {
                  // NO STACK ALLOCATIONS; DAL WORKLOOPS INTERNALLY MANAGED

                  rcinit_internal_start_daltask(rcinit_p, rcinit_p->entry);      // launches task and fills in overhead

                  rcinit_internal.def.curr++;
               }

               else if (RCINIT_TASK_POSIX == rcinit_p->type)
               {
                  if (RCINIT_STACK_NULL == rcinit_p->handle->stack)
                  {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
                     MSG_SPRINTF_2(MSG_SSID_TMS, MSG_LEGACY_ERROR, "stack checks in group %x with posix %s", rcinit_internal.group_curr, rcinit_p->name);
#endif
                  }

                  else
                  {
                     rcinit_internal_start_posix(rcinit_p, rcinit_p->entry);     // launches task and fills in overhead

                     rcinit_internal.def.curr++;
                  }
               }

               else if (RCINIT_TASK_QURTTASK == rcinit_p->type)
               {
                  if (RCINIT_STACK_NULL == rcinit_p->handle->stack)
                  {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
                     MSG_SPRINTF_2(MSG_SSID_TMS, MSG_LEGACY_ERROR, "stack checks in group %x with qurt %s", rcinit_internal.group_curr, rcinit_p->name);
#endif
                  }

                  else
                  {
                     rcinit_internal_start_qurttask(rcinit_p, rcinit_p->entry);  // launches task and fills in overhead

                     rcinit_internal.def.curr++;
                  }
               }

               else if (RCINIT_TASK_REXTASK == rcinit_p->type || RCINIT_TASK_LEGACY == rcinit_p->type)
               {
                  if (RCINIT_STACK_NULL == rcinit_p->handle->stack)
                  {
#if !defined(RCINIT_EXCLUDE_MSG_SWEVT)
                     MSG_SPRINTF_2(MSG_SSID_TMS, MSG_LEGACY_ERROR, "stack checks in group %x with rex %s", rcinit_internal.group_curr, rcinit_p->name);
#endif
                  }

                  else
                  {
                     rcinit_internal_start_rextask(rcinit_p, rcinit_p->entry);   // launches task and fills in overhead

                     rcinit_internal.def.curr++;
                  }
               }
            }
         }
      }

      if (0 != rcinit_internal.def.curr)                                         // only wait when tasks were started
      {
         rcinit_internal.process_state = rcinit_process_group_init_blocking;

         // async signal arrival order; wait for all to complete that were started

         // STALLING HERE?

         // BLOCKING HERE OCCURS UNTIL ALL THE TASKS STARTED PERFORM THEIR HANDSHAKES.
         // THIS IS THE NORMAL MECHANISM. CHECK WITH THE TECH AREA OWNING A SPECIFIC
         // CONTEXT WHEN BLOCKING DURATION BECOMES EXCESSIVE WAITING FOR THE HANDSHAKE.
         // TASKS ARE LOGICALLY STARTED IN PARALLEL, AND ALLOWED TO BE SCHEDULED AND
         // RUN CONCURRENTLY.

         if (rcevt_wait_count_handle(rcinit_internal.define, rcinit_internal.def.prev + rcinit_internal.def.curr)) {;} // wait for all defined tasks handshake; this group

         // TASKS BLOCKING ON THIS HANDLE ARE WAITING CORRECTLY; ANY TASK BLOCKING
         // ELSEWHERE IS NOT PERFORMING STARTUP CORRECTLY.

         rcinit_internal.process_state = rcinit_process_group_run;

         if (rcevt_signal_handle(rcinit_internal.defineack)) {;}                         // issue start signal to all defined tasks; this group
      }

      else
      {
         // No blocking required, no tasks started
      }

      rcinit_internal.def.curr = 0;                                              // reset instruments
      rcinit_internal.def.prev = 0;                                              // reset instruments

      rcinit_internal.group_curr++;
   }

   ////////////////////////////////////////
   // Group Processing Complete
   ////////////////////////////////////////

   rcinit_internal.group_curr = RCINIT_GROUP_NONE;                               // current group
   rcinit_internal.process_state = rcinit_process_none;
}

/*===========================================================================

 FUNCTION rcinit_init

 DESCRIPTION
 prepare internal data storage setup

 DEPENDENCIES
 none

 RETURN VALUE
 none

 SIDE EFFECTS
 none

 ===========================================================================*/
void rcinit_init(void)
{
   rcinit_internal.policy_curr = rcinit_lookup_policy(RCINIT_POLICY_NAME_DEFAULT);

   if (RCINIT_POLICY_NONE != rcinit_internal.policy_curr)
   {
      int group;

      rcinit_internal_devcfg_check_load();                                       // load devcfg configs first, potentially allows a runtime override later

      if (rcecb_init()) {;}                                                      // rcevt events service

      if (rcesn_init()) {;}                                                      // rcevt events service

      if (rcevt_init()) {;}                                                      // rcevt events service

      rcinit_internal_hs_list_init();

      rcxh_init();

      // internal events

      for (group = 0; group < RCINIT_GROUP_MAX; group++)
      {
         // rcinit_internal.rcevt_handle.init_event[group] = (rce_nde_p)rcevt_create_name(rcinit_init_rcevt[group]);
         rcinit_internal.rcevt_handle.term_event[group] = (rce_nde_p)rcevt_create_name(rcinit_term_rcevt[group]);
      }

      rcinit_internal.define = (rce_nde_p)rcevt_create_name(RCINIT_RCEVT_DEFINE); // handle to define event, internal, ok to observe
      rcinit_internal.defineack = (rce_nde_p)rcevt_create_name(RCINIT_RCEVT_DEFINEACK); // handle to defineack event, internal, ok to observe

      if (RCINIT_NULL == rcinit_internal.define ||                               // must have rcevt allocated
          RCINIT_NULL == rcinit_internal.defineack)                              // must have rcevt allocated
      {
         ERR_FATAL("initialization", 0, 0, 0);
      }

      rcinit_internal.policy_base = rcinit_internal_groups[rcinit_internal.policy_curr];

      rcinit_internal.group_curr = RCINIT_GROUP_0;

      rcinit_internal.group_base = rcinit_internal.policy_base[rcinit_internal.group_curr];

      rcinit_internal_tls_create_key(&rcinit_internal.tls_key, RCINIT_NULL);

      rcinit_dal_loop_worker_create();                                           // internal worker thread

      rcinit_internal_process_groups();                                          // sequence groups
   }

   else
   {
      ERR_FATAL("default policy not available", 0, 0, 0);
   }
}

// DALCFG Image Payload May Contain Specific Initialization

void rcinit_internal_devcfg_check_load(void)
{
   DALSYSPropertyVar propValue;
   DALSYS_PROPERTY_HANDLE_DECLARE(pHandle);

   if (DAL_SUCCESS == DALSYS_GetDALPropertyHandleStr("tms_rcinit", pHandle))
   {
      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_err_fatal_enable", 0, &propValue))
      {
         rcinit_term_err_fatal_set(propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_latency_enable", 0, &propValue))
      {
         rcinit_term_latency_enable_set(propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout", 0, &propValue))
      {
         rcinit_term_timeout_set(propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_0", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_0, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_1", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_1, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_2", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_2, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_3", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_3, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_4", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_4, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_5", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_5, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_6", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_6, propValue.Val.dwVal);
      }

      if (DAL_SUCCESS == DALSYS_GetPropertyValue(pHandle, "rcinit_term_timeout_group_7", 0, &propValue))
      {
         rcinit_term_timeout_group_set(RCINIT_GROUP_7, propValue.Val.dwVal);
      }
   }
}
