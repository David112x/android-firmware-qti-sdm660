#ifndef BARE_METAL_INFO_H
#define BARE_METAL_INFO_H

/*! \file bare_metal_info.h
 *
 * \brief   <Brief Comment Block/>
 * \details <Detailed Comment Block/>
 * \n &copy; Copyright 2012 Qualcomm Technologies Incorporated, All Rights Reserved
 */

/*===================================================================
			        EDIT HISTORY FOR MODULE
 This section contains comments describing changes made to this file.
 Notice that changes are listed in reverse chronological order.

$Header: //components/rel/rpm.bf/1.8/core/pmic/pm/pmic_devices/common/src/bare_metal_info.h#1 $ 
$Author: pwbldsvc $ 

when		who		what, where, why
--------	---		------------------------------------------------

====================================================================*/
/*===================================================================
                        INCLUDE FILES
====================================================================*/
#include "pm_qc_pmic.h"   
#include "DALSys.h"    


/*===================================================================
                        DEFINITIONS
====================================================================*/
   


// TODO: Get rid of this. Localize it to the PmicDevice
#define PM_MAX_REGS     0xFFFF

/******************************************************************************
Lint notes:  Lint complains about this macro with error 506: 
  Constant value Boolean  -- A Boolean, i.e., a quantity
  found in a context that requires a Boolean such as an argument
  to && or || or an if() or while() clause or ! was found to be
  a constant and hence will evaluate the same way each time.
******************************************************************************/
#define PM_SHIFT_FROM_MASK(x) (/*lint -save -e506 */ \
                               (x & 0x01) ? 0 : \
                               (x & 0x02) ? 1 : \
                               (x & 0x04) ? 2 : \
                               (x & 0x08) ? 3 : \
                               (x & 0x10) ? 4 : \
                               (x & 0x20) ? 5 : \
                               (x & 0x40) ? 6 : \
                               (x & 0x80) ? 7 : 0 \
                               /* lint -restore */)

#define PM_BIT(X) (1 << X)


typedef unsigned short pm_register_address_type ; 
typedef unsigned char  pm_register_data_type ;
typedef unsigned char  pm_register_mask_type ;
typedef unsigned short pm_register_16_bit_data_type ; 
typedef unsigned short pm_register_16_bit_mask_type ; 


typedef struct RegisterInfoType
{
    pm_register_address_type    addr ;
    pm_register_mask_type       mask;
    pm_register_data_type       data;
} RegisterInfoType ;
#endif // BARE_METAL_INFO_H
