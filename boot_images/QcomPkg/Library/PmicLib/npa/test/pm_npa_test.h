#ifndef PM_NPA_TEST_H
#define PM_NPA_TEST_H
/*===========================================================================


                  P M    NPA   TEST H E A D E R    F I L E

DESCRIPTION
  This file contains prototype definitions to support interaction
  with the QUALCOMM Power Management ICs.

Copyright (c) 2014-2016 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
08/22/16   pb     Port latest changes to 8998
04/28/14   va     Created.(Expose protocol to call npa test init for tests run)
===========================================================================*/
/*===========================================================================

                        INCLUDE FILES

===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include <Library/QcomLib.h>
#include "CoreVerify.h"
//#include <../Include/Protocol/EFIPmicNpaTest.h>
#include <Library/npa_resource.h>
#include <Library/MemoryAllocationLib.h>
#include "pm_npa.h"

/*===========================================================================

                        TYPE DEFINITIONS

===========================================================================*/
#define strlcpy AsciiStrnCpy

/*===========================================================================

                        DEFINITIONS

===========================================================================*/

/*PAM RESOURCEINFO */
typedef struct PMIC_NPATEST_RESOURCEINFO{
  uint32 num_of_test_nodes;
  char   *rsrc_test_name;
  pm_npa_node_resource_info *node_rsrc_arr;
  //void   *node_rsrc_arr;
}PMIC_NPATEST_RESOURCEINFO;

/*===========================================================================

                        GENERIC FUNCTION PROTOTYPES

===========================================================================*/
void pm_npa_test_init (void);
EFI_STATUS pm_npa_get_resource_info(PMIC_NPATEST_RESOURCEINFO *PamResourceInfo);


#endif /* PM_NPA_TEST_H */
