/*===========================================================================

                     SMP2P DEVICE CONFIGURATION

        This file provides the device configuration for SMP2P

  ---------------------------------------------------------------------------
  Copyright (c) 2016 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
  ---------------------------------------------------------------------------
===========================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

$Header:

when       who     what, where, why
--------   ---     ----------------------------------------------------------
===========================================================================*/

/*===========================================================================
                          INCLUDE FILES
===========================================================================*/

#include "DALStdDef.h"
#include "DDIIPCInt.h"
#include "smem_type.h"
#include "smp2p_internal.h"

/*===========================================================================
                    CONSTANT / MACRO DECLARATIONS
===========================================================================*/

/*===========================================================================
                      GLOBAL DATA DEFINATION
===========================================================================*/
/** Local processor info */
const smp2p_proc_info_type smp2p_devcfg_proc_info = 
{ 
  /** This host name */
  "adsp",
  
  /** This host SMEM ID */
  SMEM_ADSP,
  
  /** Feature flags supported */
  SMP2P_FFLAGS_SSR_HANDSHAKE,
  
  /** Max number of entries */
  16
};

/** Interrupt info for connected subsystems */
const smp2p_interrupt_info_type smp2p_devcfg_interrupt_info[] = 
{
  /** APPS */
  {
    /* destination */
    SMEM_APPS,
    
    /* destination host type */
    DALIPCINT_PROC_ACPU,
    
    /* outgoing interrupt register */
    DALIPCINT_GP_2,
    
    /* interrupt bits in irq_out register */
    0,
    
    /* incoming interrupt register */
    33,
  },
  
  /** MODEM */
  {
    /* destination */
    SMEM_MODEM,
    
    /* destination host type */
    DALIPCINT_PROC_MDSPSW,
    
    /* outgoing interrupt register */
    DALIPCINT_GP_2,
    
    /* interrupt bits in irq_out register */
    0,
    
    /* incoming interrupt register */
    9,
  },

  /** SSC */
  {
    /* destination */
    SMEM_SSC,
    
    /* destination host type */
    DALIPCINT_PROC_SPS,
    
    /* outgoing interrupt register */
    DALIPCINT_GP_2,
    
    /* interrupt bits in irq_out register */
    0,
    
    /* incoming interrupt register */
    119,
  },
  
  /** END */
  {
    /* destination */
    SMEM_INVALID_HOST,
    
    /* destination host type */
    DALIPCINT_PROC_NULL,
    
    /* outgoing interrupt register */
    DALIPCINT_INT_32BITS,
    
    /* interrupt bits in irq_out register */
    0,
    
    /* incoming interrupt register */
    0,
  },
};
