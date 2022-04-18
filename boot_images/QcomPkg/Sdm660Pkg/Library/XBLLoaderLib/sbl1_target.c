/*=============================================================================

                               SBL1 Target

GENERAL DESCRIPTION
  Target-specific initialization and interface implementation.
  
Copyright 2011, 2014, 2015 by QUALCOMM Technologies Inc.  All Rights Reserved.
=============================================================================*/


/*=============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/1.4/QcomPkg/Sdm660Pkg/Library/XBLLoaderLib/sbl1_target.c#2 $

when       who      what, where, why
--------   ---      ------------------------------------------------------------
05/11/17   bd       PMIC WDG support in DLOAD mode for minidump case
11/17/15   plc      Mark RAMDUMP region as non-cacheable for now
10/22/15   plc      Replaced tlb invalidate with generic EL-agnostic call
10/13/15   plc      Sync to 8996 tip make dload buffers non-cacheable
08/26/15   plc      Re-enable download mode and sync to 8996 tip
08/07/15   plc      Disable download mode for Sdm660 for now
07/01/15   as       Added seg_elf_entry_point for images
02/07/15   kpa      Update Xbl Ramdump image attributes.
01/09/15   kpa      Update Xbl Ramdump image loading logic.
12/09/14   kpa      Update mmu attribute to MMU_PAGETABLE_INNER_WBWARA_OUTER_NONCACHE
08/05/14   ck       Added logic to load XBLRamDump segments and transfer execution
07/14/14   ck       Moved boot_dload_transition_enter_sahara to XBLRamDump
10/31/11   dh       Add sbl1_dload_entry.
09/29/11   dh       Initial revision
=============================================================================*/


/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "boot_comdef.h"
#include "boot_dload.h"
#include "boot_cache_mmu.h"
#include "boot_mc.h"
#include "boot_sbl_shared.h"
#include "boot_clobber_prot.h"
#include "boot_config.h"
#include "boot_page_table_armv8.h"
#include "boot_sbl_if.h"
#include "boot_hash_buffer.h"
#include "boot_flash_dev_if.h"
#include "boot_loader.h"
#include "boot_extern_pmic_interface.h"

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/
extern boot_procedure_func_type sbl1_pre_dload_procs[];

/* Shared data between SBL */
extern struct bl_shared_data_type bl_shared_data;

extern uint8 sbl1_partition_id[];


/* Whitelist region and Configuration table entry used by sbl1_dload_entry to
   load XBLRamDump image.  Placed here so it is in RW region and not stack. */
whitelist_region_type xbl_ramdump_table[] =
    {XBL_RAMDUMP_WHITELIST_REGION_TABLE};

/*==========================================================================
                     PRE/POST PROCEDURE DEFINITIONS 
===========================================================================*/
/* Initialize the elf header for ramdump image loading */ 
static void xbl_ramdump_configure_header(bl_shared_data_type *bl_shared_data )
{
  boot_elf_ziinit_structures(NULL);
  boot_set_elf_and_prog_header(
      bl_shared_data->sbl_shared_data->pbl_shared_data->elf_meta_info.elf_hdr,
      bl_shared_data->sbl_shared_data->pbl_shared_data->elf_meta_info.prog_hdr
    );
  boot_set_hash_segment_buffer(
      (void *)bl_shared_data->sbl_shared_data->pbl_shared_data->elf_meta_info.hash_seg_hdr
  );

  /* Configure the target image using custom partition ID information */ 
  boot_flash_configure_target_image(sbl1_partition_id);
}
    
/*==========================================================================
          FUNCTIONS TO EXECUTE BEFORE XBL RAMDUMP IMAGE LOADING
===========================================================================*/
boot_procedure_func_type load_xbl_ramdump_pre_procs[] = 
{
  /* Initialize the elf header for ramdump image loading */
  xbl_ramdump_configure_header,

  /*----------------------------------------------------------------------
   Last entry in the table.
  ----------------------------------------------------------------------*/
  NULL 
};    
    
/*==========================================================================
                 DEFINE XBL RAMDUMP BOOT CONFIG TABLE
===========================================================================*/    
boot_configuration_table_entry xbl_ramdump_config_entry =
  { SBL1_IMG,                                   /* host_img_id */
    CONFIG_IMG_QC,                              /* host_img_type */
    GEN_IMG,                                    /* target_img_id */
    CONFIG_IMG_ELF_SEG,                         /* target_img_type */
    SECBOOT_SBL1_SW_TYPE,                       /* target_img_sec_type */
    TRUE,                                       /* load */
    TRUE,                                       /* auth */
    FALSE,                                      /* exec */
    FALSE,                                      /* jump */
    NULL,                                       /* exec_function */
    NULL,                                       /* jump-function */
    load_xbl_ramdump_pre_procs,                 /* pre_procs */
    NULL,                                       /* post_procs */
    NULL,                                       /* load_cancel */
    sbl1_partition_id,                          /* target_img_partition_id */
    (uint8 *)"XBLRamDump Image Loaded, Delta",  /* target_img_str */
    xbl_ramdump_table,                          /* whitelist_table */
    FALSE,                                      /* boot_ssa_enabled */
    FALSE,                                      /* enable_rollback */
    FALSE,                                      /* enable_xpu */
    0x0,                                        /* xpu_proc_id */
    0x0,                                        /* sbl_qsee_interface_index */
    SCL_RAMDUMP_CODE_BASE                       /* seg_elf_entry_point */
  };


/* mem_block used by sbl1_dload_entry to change XBLRamDump MMU region to
   executable before jumping into image.  Placed here so it is in RW region
   and not stack. */
struct mem_block xbl_ramdump_mem_block =
  { SCL_RAMDUMP_CODE_BASE,
    SCL_RAMDUMP_CODE_BASE,
    SCL_RAMDUMP_CODE_SIZE >> 10,
    MMU_L3_SECTION_MAPPING,
    MMU_PAGETABLE_MEM_READ_ONLY,
    MMU_PAGETABLE_MEM_NON_CACHEABLE,
    MMU_PAGETABLE_EXECUTABLE_REGION, };


/*===========================================================================

**  Function :  sbl_dload_entry

** ==========================================================================
*/
/*!
* 
* @brief
*   This function pointer is defined in each SBL* Bootloader to handle SBL-specific
*   requirements to enter a download routine. It is initialized to 
*   boot_dload_transition_pbl_forced_dload by default.
*  
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void (*sbl_dload_entry)(void) = boot_dload_transition_pbl_forced_dload; 


/*===========================================================================

**  Function :  sbl_dload_target_entry

** ==========================================================================
*/
/*!
* 
* @brief
*   This function is defined in each SBL Bootloader to handle SBL-specific
*   requirements to enter a download routine
*  
* @par Dependencies
*   None
*   
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void sbl1_dload_entry ()
{
  static uint32 dload_entry_count = 0;
  boot_boolean result = FALSE;
  uint32 dload_flag =0x0;

  dload_flag = boot_dload_read_saved_cookie() & (SBL_MINIDUMP_MODE_BIT_MASK | SBL_DLOAD_MODE_BIT_MASK);
  if(dload_flag == SBL_MINIDUMP_MODE_BIT_MASK)
  {
    /* Enable PMIC WDG timer only for Minidump case, since full-dumps to eMMC/SDCard/QPST will not complete within PMIC WDG expiry */
    boot_pm_pon_wdog_cfg(PMIC_DEVICE_INDEX, DLOAD_PMIC_WDG_S1_VALUE, DLOAD_PMIC_WDG_S1_VALUE, PM_PON_RESET_CFG_HARD_RESET);
    boot_pm_pon_wdog_enable(PMIC_DEVICE_INDEX, PM_ON);
  }  

  dload_entry_count++; 

  /* Only execute the pre-dload procedures the first time we try to enter
   * dload in case there is an error within these procedures. */
  if( dload_entry_count == 1 && &bl_shared_data != NULL )
  {
    /* Entering dload routine for the first time */
    boot_do_procedures( &bl_shared_data, sbl1_pre_dload_procs );
  }

  
  /* Attempt to load and execute the XBLRamDump image.  If there is an error
     loading or executing the image then execution will ultimately return here
     with dload_entry_count > 1.  If that is the case then transfer execution
     to PBL Emergency Download Mode. */
  if (dload_entry_count > 1)
  {
    boot_dload_transition_pbl_forced_dload();
  }


  /* Use the boot_configuration_table_entry for the XBLRamDump image. */
  boot_config_process_entry(&bl_shared_data,
                            &xbl_ramdump_config_entry);

  /* XBLRamDump image has been loaded.  Change MMU permissions to allow
     allow execution before jumping into image.  Entry point is always
     the beginning of XBLRamDump's code memory region as ELF entry point value
     is occupied with XBLLoader. 
   */
  result =
    boot_mmu_page_table_map_single_mem_block(
     (uint64 *)bl_shared_data.sbl_shared_data->mmu_l1_pagetable_base,
      &xbl_ramdump_mem_block);

  BL_VERIFY(result,
            BL_ERR_MMU_PGTBL_MAPPING_FAIL|BL_ERROR_GROUP_BOOT);

  /* The Ramdump data region is already marked cacheable, non-exec via ramdump
     default mapping. Explicitly ensure dload buffers are uncached.
  */
  xbl_ramdump_mem_block.p_base = SCL_RAMDUMP_DLOAD_BUFFERS_BASE;
  xbl_ramdump_mem_block.v_base = SCL_RAMDUMP_DLOAD_BUFFERS_BASE;
  xbl_ramdump_mem_block.size_in_kbytes = SCL_RAMDUMP_DLOAD_BUFFERS_SIZE >> 10;
  xbl_ramdump_mem_block.access = MMU_PAGETABLE_MEM_READ_WRITE;
  xbl_ramdump_mem_block.executable = MMU_PAGETABLE_NON_EXECUTABLE_REGION;
  xbl_ramdump_mem_block.cachetype = MMU_PAGETABLE_MEM_NON_CACHEABLE;
            
  result =
    boot_mmu_page_table_map_single_mem_block(
     (uint64 *)bl_shared_data.sbl_shared_data->mmu_l1_pagetable_base,
      &xbl_ramdump_mem_block);

  BL_VERIFY(result,
            BL_ERR_MMU_PGTBL_MAPPING_FAIL|BL_ERROR_GROUP_BOOT);           

  mmu_invalidate_tlb();

  /* "Exit" XBLLoader and enter XBLRamDump. */
 ((void (*)())(uintnt)(SCL_RAMDUMP_CODE_BASE))(); 

 
}/* sbl_dload_entry() */
