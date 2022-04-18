/*! \file  pmic_sbl_gen_driver.c
 *  
 *  \brief  File Contains the PMIC Set Mode validation Implementation
 *  \details Set Mode implementation is responsible for setting  
 *  all mode settings such as Register values, memory values, etc.
    Validation implementation here confirms all the register values written as expected 
    and PBS RAM version is also correct.
 *  
 *  
 *  &copy; Copyright 2013-2015 QUALCOMM Technologies Incorporated, All Rights Reserved
 */

/*===========================================================================

                        EDIT HISTORY FOR MODULE


when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
09/13/16   aab     Updated logging text to match the rest of SBL logging
07/08/16   pbarot  Adding pm_read_sbl_version() to read PDM SBL version flashed, also added mask read
03/23/16   pbarot  Adding condition check on lastwrite and correcting print for violation log
10/22/15   al      KW fix
09/08/15   pbarot  Update test based on CLogic implementation
08/18/15   pbarot  Updated PBS RAM version validation
06/23/15   pbarot  Creation, Moved Settings validation test code to this file
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_sbl_boot.h"                /* Needed for pm_clk_busy_wait and sbi_mini initialization */
#include "pm_config_sbl.h"              /* Contains the type definitions and static register tables */
#include "pm_config_sbl_test.h"         /* Contains the type definitions and static register tables */
#include "pm_target_information.h"
#include "CoreVerify.h"
#include "pm_version.h"
#include "pm_pbs_driver.h"
#include "pm_log_utils.h"

/* Global Variables */
// static uint8 max_pmic_index; /* For settings validation test */
static uint16 total_settings=0;

/* function prototypes */
static pm_err_flag_type pm_settings_validation_flag(uint8 *flag, boolean reset); /* For settings validation test */
static pm_err_flag_type pm_run_settings_validation();
static pm_err_flag_type pm_read_sbl_version();

/* Read and log SBL version which was flashed */
pm_err_flag_type 
pm_read_sbl_version()
{
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;
   uint8 read_data;
   
   err_flag |= pm_comm_read_byte(0, PM_SBL_TEST_REVID_SBL_ID_0, &read_data, 1);
   pm_log_message("REVID_SBL_ID_0:0x%X",read_data); 
   
   err_flag |= pm_comm_read_byte(0, PM_SBL_TEST_REVID_SBL_ID_1, &read_data, 1);
   pm_log_message("REVID_SBL_ID_1:0x%X",read_data); 
   
   return err_flag;
}

pm_err_flag_type 
pm_run_settings_validation()
{
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;
   pm_err_flag_type err_flag_chip_rev = PM_ERR_FLAG__SUCCESS;
   pm_sbl_seq_type *rc = NULL;  //reg config data ptr
   boolean valid_sid = FALSE;
   uint32 rev_id_read;
   boolean valid_config_flag = TRUE;
   pm_sbl_seq_type *rc_copy = NULL;  
   pm_sbl_seq_type *last_write = NULL; 
   uint8 read_data;
   uint16 offset;
   uint64 pmic_elf_start_addr;
   
   pm_psi_get_base_address(&pmic_elf_start_addr);
   //PSI: Get PDM data pointer from pmic elf image
   pm_sbl_pdm_config_type  *pm_sbl_pdm_config_ds   = (pm_sbl_pdm_config_type*)(pmic_elf_start_addr);
   CORE_VERIFY_PTR(pm_sbl_pdm_config_ds);
   CORE_VERIFY_PTR(pm_sbl_pdm_config_ds->pdm_data);
   pm_sbl_seq_type         *sbl_reg_config_ds      = pm_sbl_pdm_config_ds->pdm_data->pm_sbl_seq; 
   pm_sbl_cond_seq_type    *sbl_cond_config_ds     = pm_sbl_pdm_config_ds->pdm_data->pm_sbl_cond_seq;
   pm_pbs_ram_data_type    *pbs_ram_config_ds      = pm_sbl_pdm_config_ds->pdm_data->pm_pbs_ram_seq;
   pm_sbl_config_info_type *sbl_config_info_ds     = pm_sbl_pdm_config_ds->pm_psi_info; 
   
   if ((sbl_reg_config_ds == NULL)||(sbl_cond_config_ds == NULL)|| (pbs_ram_config_ds == NULL))
   {
      return PM_ERR_FLAG__INVALID_POINTER;
   }
   
   if(sbl_config_info_ds->signature != PSI_SIGNATURE) 
   { 
      CORE_VERIFY(0); //Error fatal if the pmic image signature doesn't match 
   } 
    
   for(rc = sbl_reg_config_ds; (rc->reg_operation != PM_SBL_OPERATION_INVALID); rc++)  
   {
      if (rc->reg_operation != PM_SBL_DELAY ) 
      {
         err_flag_chip_rev |= pm_resolve_chip_revision(rc->sid, &valid_sid, &rev_id_read);
         if (valid_sid == FALSE)
         {
            continue;  //This current configuation does not apply to this SID (PMIC does not exist)
         }
      }    

      if ( (rc->cond_start_index == 0) && (rc->cond_end_index == 0) ) 
      {
         valid_config_flag = TRUE; //Normal configuration
      }
      else
      {
         valid_config_flag = TRUE;
         err_flag |= pm_sbl_validate_cond_config(sbl_config_info_ds, sbl_cond_config_ds, rc->cond_start_index, rc->cond_end_index, &valid_config_flag); //check conditional config
      }
     
      // if( pm_sbl_validate_reg_config(rc->rev_id, rev_id_read, rc->reg_operation, rc->rev_id_operation)== TRUE )
      if( valid_config_flag == TRUE )
      { 
         switch(rc->reg_operation)  
         {
            case PM_SBL_WRITE:  
            {
               last_write = rc;
               for(rc_copy = rc; (rc_copy->reg_operation != PM_SBL_OPERATION_INVALID); rc_copy++)
               {
                  if (rc_copy->sid == rc->sid && rc_copy->address == rc->address)
                  {
                     // First check if this write is meeting conditional logic
                     if ( (rc_copy->cond_start_index == 0) && (rc_copy->cond_end_index == 0) ) 
                     {
                        valid_config_flag = TRUE; //Normal configuration
                     }
                     else
                     {
                        err_flag |= pm_sbl_validate_cond_config(sbl_config_info_ds, sbl_cond_config_ds, rc_copy->cond_start_index, rc_copy->cond_end_index, &valid_config_flag); //check conditional config
                     }
                     
                     if( valid_config_flag == TRUE )
                     { 
                        last_write = rc_copy; // getting pointer to last write of same register that we are on at current stage
                     }
                  }
                  else
                  {
                     continue;
                  }
               }
               // pm_log_message("READ_DATA: sid:%d,add:0x%X,offset:0x%X,data:0x%X,lastwrite_data:0x%X",rc->sid, rc->address, rc->offset, rc->data, last_write->data);
               offset = rc->address & 0x00FF;
               if ( (offset != PM_SBL_TEST_OFFSET_SEC_ACCESS) && (offset != PM_SBL_TEST_OFFSET_INT_EN) ) // not covering entries with with selected offset of SEC_ACCESS and INT_EN
               { 
                  // err_flag |= pm_comm_read_byte(rc->sid, rc->address, &read_data, 1); //address data at original location is being changed in sbl write function so not adding offset in base address
                  err_flag |= pm_comm_read_byte_mask(rc->sid, rc->address, rc->mask, &read_data, 1); //address data at original location is being changed in sbl write function so not adding offset in base address

                  if (read_data == last_write->data) // comparing current read data from register and comparing it to last write data from structure 
                  {
                     pm_log_message("PASS:%d,0x%X,set:0x%X,get:0x%X",rc->sid, rc->address, last_write->data, read_data); // remove to save some memory 
                  }
                  else
                  {
                     pm_log_message("VIOLATION:%d,0x%X,set:0x%X,get:0x%X",rc->sid, rc->address, last_write->data, read_data);
                  }
                  total_settings++;
               }   
            }
               break;
            case PM_SBL_PBS_RAM:
            {
               // max_pmic_index = rc->data; // reading data section for PM_SBL_PBS_RAM gives particular pmic its intended for and last pmic index stored will give idea on max pmics available.                  
               // max_pmic_index = (rc->sid /2); // changing logic to determine max pmic index due to pmk sbl is seperately generated and rc->data is 0 for pmk reg cfg.
               pm_log_message("PBS:%d:0x%X,0x%X",(rc->sid/2), (((&pbs_ram_config_ds[rc->data*PBS_RAM_DATA_SIZE])+(rc->address-1))->word2), (((&pbs_ram_config_ds[rc->data*PBS_RAM_DATA_SIZE])+(rc->address-1))->word1));            
            }
               break;
            case PM_SBL_DELAY: 
            case PM_SBL_NOP:
               break;
            default:
               err_flag |= PM_ERR_FLAG__SBL_CONFIG_REG_OPERATION_NOT_SUPPORTED;
               break;
         }
      }
   }
    
   return err_flag;
}


pm_err_flag_type 
pm_sbl_config_test()
{   
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;
   uint8 flag;
   
   err_flag |= pm_settings_validation_flag(&flag, 0); // to verify if flag register bit is set to run this test function
   if(flag)
   {     
      pm_log_message("PM_SET_VAL:Start");
      err_flag |= pm_run_settings_validation(); // Run through settings validation
      err_flag |= pm_read_sbl_version(); // Read and log SBL version which was flashed  
      pm_log_message("PM_SET_VAL:End:%d",total_settings);
   }
   else
   {
      pm_log_message("SET_VAL:Skip");
   }    
   return err_flag;
}

pm_err_flag_type pm_pbs_ram_version_validation_test(void)
{
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;
   pm_pbs_info_type pbs_info_ptr;
   uint8 pmic_device_index=0;
   uint8 flag;
   // char str[PM_SBL_TEST_MAX_STR_LENGTH]; made it global
   
   err_flag |= pm_settings_validation_flag(&flag, 1); // to verify if flag register bit is set to run this test function
   if(flag){
      /* go through all available PMIC and print out PBS RAM version for each */
      for (pmic_device_index = 0; pmic_device_index < PM_MAX_NUM_PMICS; pmic_device_index++)
      {
         if (pm_get_pmic_model(pmic_device_index) != PMIC_IS_INVALID && pm_get_pmic_model(pmic_device_index) != PMIC_IS_UNKNOWN)
         {
            err_flag |= pm_get_pbs_info(pmic_device_index, &pbs_info_ptr);
            pm_log_message("PBS_GET:%d:0x%X",pmic_device_index, pbs_info_ptr.ram_version);
         }
         else
         {
            continue;
         }
      }
   }
   return err_flag;
}

pm_err_flag_type pm_settings_validation_flag(uint8 *flag, boolean reset)
{
   pm_settings_test_flag_reg_info_type* flag_reg_ptr=NULL;
   pm_err_flag_type err_flag = PM_ERR_FLAG__SUCCESS;
   // uint8 sid = 0;  // removed to save some memory 
   // uint8 mask=0x01; // removed to save some memory
   *flag=0x00; 

   // handle to structure where test flag register is stored 
   flag_reg_ptr = (pm_settings_test_flag_reg_info_type*)pm_target_information_get_common_info(PM_PROP_SETTINGS_TEST_FLAG_REG);

   CORE_VERIFY_PTR(flag_reg_ptr);

   if (flag_reg_ptr)
   { 
      err_flag |= pm_comm_read_byte_mask(0, flag_reg_ptr->flag_register, 0x01, flag, 1); // read bit 0 of register retrived to decide  whether test needs to be triggered or not
   }
   if (reset) 
   {
      err_flag |= pm_comm_write_byte_mask(0, flag_reg_ptr->flag_register, 0x01, 0x00, 1); // reset flag for validation test
   }    
   return err_flag;
}
