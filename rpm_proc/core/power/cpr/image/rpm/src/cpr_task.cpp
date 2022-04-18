/*===========================================================================
                              rbcpr_task.cpp

SERVICES:

DESCRIPTION:

INITIALIZATION AND SEQUENCING REQUIREMENTS:
  Description...

Copyright (c) 2012 Qualcomm Technologies, Incorporated.  All Rights Reserved.
QUALCOMM Proprietary.  Export of this technology or software is regulated
by the U.S. Government. Diversion contrary to U.S. law prohibited.
===========================================================================*/


//===========================================================================
//                     Includes and Variable Definitions
//===========================================================================

//---------------------------------------------------------------------------
// Include Files
//---------------------------------------------------------------------------
#include "cpr_task.h"
#include "CoreVerify.h"
#include "time_service.h"
#include "cortex-m3.h"
#include "swevent.h"

extern "C"
{
	#include "rpmserver.h"
}

//---------------------------------------------------------------------------
// Constant / Define Declarations
//--------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Type Declarations
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Global Constant Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Local Object Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Static Variable Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Forward Declarations
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// External References
//---------------------------------------------------------------------------
extern "C" void cpr_handler(cpr_closed_loop_rail_t);

//===========================================================================
//                             Macro Definitions
//===========================================================================

//===========================================================================
//                           Function Definitions
//===========================================================================
RBCPRTask::RBCPRTask (cpr_image_isr func, void* ctx, uint32_t client_interrupt_id, uint8_t priority)
    : Task (priority),
      state_ (IDLE), interrupt_id(client_interrupt_id), myfunc(func), myctx(ctx)
{
}

RBCPRTask::~RBCPRTask ()
{
}

uint64_t RBCPRTask::get_length() const
{
  return 30;
}

uint64_t RBCPRTask::get_length_given(uint32_t systemStateIn, uint32_t &systemStateOut)
{
  systemStateOut = 0;
  return get_length ();
}

void RBCPRTask::reestimate()
{
}

bool RBCPRTask::hasImmediateWork() const
{
  return (state_ != IDLE);
}

void RBCPRTask::execute_until(volatile bool &preempt, uint64_t stop_time)
{
  if (preempt)
  {
    return;
  }

  if (state_ == ACTIVE)
  {
    uint64_t start = time_service_now();

    if ((start + get_length ()) > stop_time)
    {
      return;
    }

    myfunc(myctx);
  }
  
  #if DAL_CONFIG_TARGET_ID==0x660 || DAL_CONFIG_TARGET_ID==0x405
  cpr_rail *rail = (cpr_rail  *)(myctx);
  if (rail->id == CPR_RAIL_LPI_CX)
  {
	rpm_spm_enable_lpass_shtdwn_interrupt();
  }
  #endif /* DAL_CONFIG_TARGET_ID==0x660 || DAL_CONFIG_TARGET_ID==0x405 */
  
  state_ = IDLE;
  interrupt_enable_no_clear(interrupt_id);
  }

void RBCPRTask::enqueue ()
{
  CPR_ASSERT (state_ == IDLE);
  state_ = ACTIVE;

  interrupt_disable(interrupt_id);

  schedule_me(IGNORE_DEADLINE);
}

extern "C" void RBCPRTaskISR(void* task)
{
  RBCPRTask *the_task = (RBCPRTask*)task;
  CPR_ASSERT (the_task != NULL);
  the_task->enqueue ();
}

extern "C" void* RBCPRTaskInit(cpr_image_isr func, void* ctx, uint32_t client_interrupt_id)
{
  return (void*) new RBCPRTask(func, ctx, client_interrupt_id);
}
