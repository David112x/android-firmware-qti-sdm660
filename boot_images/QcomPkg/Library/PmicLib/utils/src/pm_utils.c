/*! \file
*  
*  \brief  pm_utils.c ----This file contains the implementation of pm_malloc()
*  \details This file contains the implementation of pm_malloc()
*  
*  &copy; Copyright 2012, 2015-2017 QUALCOMM Technologies Incorporated, All Rights Reserved
*/

/*===========================================================================

EDIT HISTORY FOR MODULE

This document is created by a code generator, therefore this section will
not contain comments describing changes made to the module.


when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
05/03/17   czq     Added PSHOLD drop API.
08/12/16   aab     Added pm_sbl_get_adc_batt_id_pd_res_ohms() 
08/03/16   akm     Moved pm_clk_busy_wait to framework/src pm_busy_wait
05/26/16   al      Fix for API to return idx 
09/25/15   al      Removing the redundant check
05/01/14   aab     Added pm_clk_busy_wait()
03/20/14   aab     Added pm_boot_adc_get_mv() 
06/11/13   hs      Adding settling time for regulators.
06/20/12   hs      Created

===========================================================================*/

/*===========================================================================

INCLUDE FILES 

===========================================================================*/
#include "pm_utils.h"
#include "DALSys.h"
#include "CoreVerify.h"
#include "busywait.h"

#include <Library/IoLib.h>  
#include <Library/PcdLib.h> 


/*===========================================================================

                        GLOBALS and TYPE DEFINITIONS 

===========================================================================*/
#define FG_SRAM_RESET_WAIT_TIME     10000
	
static uint32 pmic_malloc_total_size = 0;


/*===========================================================================

                        FUNCTION DEFINITIONS 

===========================================================================*/
void pm_malloc(uint32 dwSize, void **ppMem)
{
    DALResult dalResult = DAL_SUCCESS;

    dalResult = DALSYS_Malloc(dwSize, ppMem);
    CORE_VERIFY(dalResult == DAL_SUCCESS );
    CORE_VERIFY_PTR(*ppMem);

    DALSYS_memset(*ppMem, 0, dwSize);

    pmic_malloc_total_size += dwSize;
}

uint64 pm_convert_time_to_timetick(uint64 time_us)
{
    return (time_us*19200000)/1000000;
}

uint64 pm_convert_timetick_to_time(uint64 time_tick)
{

    return (time_tick*1000000)/19200000;
}

uint32 pm_memory_allocated(void)
{
  return pmic_malloc_total_size;
}





uint8
pm_utils_get_upper_idx(uint32 data_value, uint32 *data_list, uint8 list_count)
{
  uint8 idx = 0;

  if (data_list == NULL || list_count==0)
  {
    CORE_VERIFY(0);
  }

  for (idx = 0; idx < list_count-1; idx++)
  {
    if (data_value <= data_list[idx]) 
      break;
  }
 
  return idx;
} 
void 
pm_utils_drop_pshold(void) 
{
   uint32      ps_hold_shft = 0;  
   uint32      PSHoldAddress = 0;

   /* This register controls the PSHOLD value.*/  
   PSHoldAddress = PcdGet32 (PcdPsHoldAddress);       
   MmioWrite32( PSHoldAddress, 0 << ps_hold_shft );     
       
   for(;;) /* Till device reset */  
   {  
     pm_busy_wait(FG_SRAM_RESET_WAIT_TIME); /* 10 ms*/  
   }  
   /* If reset, it should never get here, if we do loop ! */  
   /* CpuDeadLoop(); */  
} 

