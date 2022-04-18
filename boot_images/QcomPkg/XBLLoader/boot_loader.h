#ifndef BOOT_LOADER_H
#define BOOT_LOADER_H

/*=============================================================================

                              Boot Loader

GENERAL DESCRIPTION
  This module performs binary image and AMSS loading.

Copyright 2010-2015 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
=============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ----------------------------------------------------------
04/29/16   kpa     Pass auth enable flag to boot_load_elf_image
07/15/15   ck      Added boot_elf_load_deinit
07/01/15   as      Removed boot_elf_get_filtered_segment_start
02/25/15   kpa     Add config entry whitelist parameter to boot_populate_sbl_info
01/05/14   kpa     remove boot_load_header_and_image
10/27/14   kedara  Added SAFE 1.0
10/09/14   kedara  Added boot_elf_get_filtered_segment_start
09/24/14   kedara  Added boot_set_elf_and_prog_header
08/08/14   ck      Updated sahara function prototypes for 64 bit support
06/13/14   ck      Added boot_elf_segment_in_whitelist
06/13/14   ck      Whitelist region pointer now passed to boot_load_elf_image
03/05/14   ck      Updated boot_elf_verify_image_header parameter list
12/09/13   jz      64bit elf loading support
10/24/13   ck      Removed boot_rpm_cookie_sync, boot_init_rpm_entry_address,
                   and boot_notify_bl_jump_to_rpm
10/21/13   dhaval  declare api to explicitly hash ehdr+phdr
07/29/13   aus     Support for loading ELF SDI image
02/19/13   kedara  Added boot_get_elf_header, sbl_sahara_get_elf_header,
                   boot_get_program_header, sbl_sahara_get_program_header.
11/28/12   dh      Add boot_rpm_cookie_sync
11/08/12   kedara  Updated boot_elf_set_auth_and_ssa_enable
09/21/12   jz      Updated boot_load_elf_image
06/15/12   kedara  Added boot_elf_set_is_ssa_enabled.
06/14/12   kedara  Added support to read FOTA partition and check for 
                   recovery mode cookie
09/01/11   dh      Removed unused functions
08/24/11   aus     Added support for sahara secure boot
06/27/11   aus     Added flashless boot support
04/29/11   dh      Add boot_load_image_header to support loading image header
03/18/11   dxiang  Add new function boot_load_elf_image() for ELF image loading 
02/22/11   dxiang  Add new function boot_load_ssd_partition() for modem encryption 
01/28/11   dxiang  Add new function boot_init_rpm_entry_addr()
08/04/10   aus     Clean-up secboot 3.0
07/22/10   aus     Initial revision.
============================================================================*/

/*===========================================================================

                           INCLUDE FILES
						   
===========================================================================*/
#include "MIheader.h"
#include "boot_sbl_shared.h"
#include "boot_comdef.h"
#include "boot_clobber_prot.h"
#include "boot_extern_sec_img_interface.h"

/*=============================================================================

                              DEFINITIONS

=============================================================================*/
/* Cookie that defines FOTA recovery mode */
#define FOTA_RECOVERY_COOKIE 0x64645343

/*===========================================================================

                      PUBLIC FUNCTION DECLARATIONS

===========================================================================*/

/*===========================================================================
**  Function :  boot_auth_load_elf_info
** ==========================================================================
*/
/*!
* 
* @brief
*   This function loads elf image info
*
* @par Dependencies
*   None 
* 
* @retval
*   SEC_IMG_AUTH_SUCCESS - If ELF images is verified successfully
*   ERROR VALUES - In case of failure.
* 
*/
uint32 boot_populate_sbl_info 
(
  sec_img_auth_elf_info_type *sbl_elf_info,
  sec_img_auth_whitelist_area_param_t *sbl_white_list_param,
  whitelist_region_type * config_entry_whitelist_table
);

/*===========================================================================
**  Function :  boot_load_image_header
** ==========================================================================
*/
/*!
* 
* @brief
*   This function loads the specified image header from
*   the boot device to a given ram location. 
* 
* @param[in]  image_id   Image ID of the image header to be loaded
* @param[out] header_ptr Pointer to location to load the image header to
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
void boot_load_image_header
(
  image_type image_id,
  mi_boot_image_header_type *header_ptr 
);


/*===========================================================================

**  Function :  boot_load_header_and_image_with_cookie

** ==========================================================================
*/
/*!
* 
* @brief
*   This function loads in the specified image and image header with cookie
*   from the boot device to RAM.  The header_ptr parameter is optional, if
*   not NULL it will be filled in with the image header data.
* 
* @param[in]  image_id   Image ID of the image to be loaded
* @param[out] header_ptr Pointer to the image header that is read from the image
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
void boot_load_header_and_image_with_cookie
(
  image_type image_id,
  mi_boot_header_cookie_type *header_ptr      /* image header with cookie */
);


/*===========================================================================
**  Function :  boot_check_fota_partition
** ==========================================================================
*/
/*!
* 
* @brief
*   This function opens FOTA partition and checks if we need to boot into  
*   recovery mode
*
* @param[in] uint8 * - Partition ID for FOTA
*
* @par Dependencies
*   None
* 
* @retval
*   boolean - TRUE - recovery mode
*             FALSE - normal mode
* 
* @par Side Effects
*   None
* 
*/
boolean boot_check_fota_partition ( uint8 * img_partition_id );

/*===========================================================================
**  Function :  boot_load_ssd_partition
** ==========================================================================
*/
/*!
* 
* @brief
*   This function loads the Secure Software Download encryption keys into a 
*   pre-determined location in memory to be used by TrustZone. This function 
*   will read SCL_SSD_PARTITION_SIZE bytes from the the SSD partition, and move
*   the contents into memory at SCL_SSD_PARTITION_BASE. If either of these 
*   definitions do not exist, the function does nothing. 
*
* @param[in] bl_shared_data Pointer to the shared data 
*
* @par Dependencies
*   SCL_SSD_PARTITION_SIZE and SCL_SSD_PARTITION_BASE must be defined.
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
void boot_load_ssd_partition( bl_shared_data_type *bl_shared_data );

/*===========================================================================
**  Function :  boot_load_elf_image
** ==========================================================================
*/
/*!
* 
* @brief
*   This function will load an ELF formatted image from the requested 
*   partition_id. The QC header located at the beginning of the hash segment
*   will also be loaded into the location pointed to by header_ptr
*
* @param[in] 
*  elf_segment_whitelist - Pointer to the whitelist table specifying segment
*                          regions to load.  NULL means all segments are loaded.
*
*  image_id              - ID of the image to be loaded
*
* @par Dependencies
*   BOOT_FEATURE_LOAD_ELF must be defined 
* 
* @retval
*   None
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
void boot_load_elf_image( 
  whitelist_region_type * elf_segment_whitelist,
  uint32 image_id,
  boot_boolean auth
);
#else
static inline
void boot_load_elf_image(
  whitelist_region_type * elf_segment_whitelist,
  uint32 image_id,
  boot_boolean auth
)
{}
#endif

/*===========================================================================
**  Function :  boot_elf_verify_elf_hdr
** ==========================================================================
*/
/*!
* 
* @brief
*   This function verifies hash of elf_hdr with an expected
*   hash value. If ehdr+phdr hash verification fails then this function  
*   doesn't return and enters boot_error_handler if hash check fails.
*   
*
* @par Dependencies
*   first hash in the hash table always represents hash of ehdr+phdr 
* 
* @retval
*   None
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
void boot_elf_verify_elf_hdr
(
  void
);
#else
static inline void boot_elf_verify_elf_hdr
(
  void
){}
#endif


/*===========================================================================
**  Function :  boot_elf_verify_image_header
** ==========================================================================
*/
/*!
* 
* @brief
*   This function validates the elf header in the partition 
*
* @param[in] partition_id - Pointer to the partition ID information
* @param[int] header_ptr  - Pointer to the QC header buffer that must be cleared
*
* @par Dependencies
*   None 
* 
* @retval
*   Boolean TRUE is valid header, FALSE otherwise
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
boolean boot_elf_verify_image_header
(   
 uint8 * partition_id,
 mi_boot_image_header_type * header_ptr
);
#else
static inline boolean boot_elf_verify_image_header
(  
 uint8 * partition_id,
 mi_boot_image_header_type * header_ptr
)
{ return FALSE; }
#endif

/*===========================================================================
**  Function :  boot_elf_load_init_hash_segment
** ==========================================================================
*/
/*!
* 
* @brief
*   This function initializes all global variables within the module which are
*   necessary to perform ELF loading. This function will also load the 
*   hash data segment into memory, read in the QC header, and assign 
*   hash_segment_start to point to the start of the hash entries. 
*
* @param[in] partition_id - Pointer to the partition ID information
* @param[out] header_ptr - Pointer to the QC header that is read from the image
*
* @par Dependencies
*   None 
* 
* @retval
*   None
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
void boot_elf_load_init_hash_segment
(
 uint8 * partition_id, 
 mi_boot_image_header_type *header_ptr
);
#else
static inline void boot_elf_load_init_hash_segment
(
 uint8 * partition_id, 
 mi_boot_image_header_type *header_ptr
){}
#endif


/*===========================================================================
**  Function :  boot_elf_ziinit_structures
** ==========================================================================
*/
/*!
* 
* @brief
*   This function zero-initializes all global variables within the module which
*   are necessary to perform ELF loading.  
*
* @param[out] header_ptr - Pointer to the QC header that is read from the image
*
* @par Dependencies
*   None 
* 
* @retval
*   None
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
void boot_elf_ziinit_structures(mi_boot_image_header_type *header_ptr);
#else
static inline void boot_elf_ziinit_structures(mi_boot_image_header_type *header_ptr)
{}
#endif


/*===========================================================================
**  Function :  boot_elf_load_deinit
** ==========================================================================
*/
/*!
* 
* @brief
*   This function deinitializes the necessary variables when ELF loading is 
*   complete. The flash translation interface is closed, and reset to NULL
*   so that it may be re-used again by the module for a new target image. 
*
* @par Dependencies
*   None 
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
void boot_elf_load_deinit(void);
#else
static inline void boot_elf_load_deinit()
{}
#endif


/*===========================================================================
**  Function :  boot_get_elf_entry_address
** ==========================================================================
*/
/*!
* 
* @brief
*   This function returns the value of the elf header entry pointer. 
*
* @par Dependencies
*   None 
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
uint64 boot_get_elf_entry_address
( void );
#else
static inline uint64 boot_get_elf_entry_address
( void )
{
  return 0x0;
}
#endif

/*===========================================================================
**  Function :  boot_set_elf_and_prog_header
** ==========================================================================
*/
/*!
* 
* @brief
*  This function sets the global elf header and program header variables 
*  with provided data. 
*
* @param[in]
*   elf_hdr_ptr - Pointer to elf header
*
* @param[in]
*   prog_hdr_ptr - Pointer to Program header
*
* @par Dependencies
*   Elf header global struct is assumed to be zero initialized before
*  invoking the api. 
* 
* @retval
*   Boolean TRUE if success, FALSE otherwise
*/
#ifdef FEATURE_BOOT_LOAD_ELF
boolean boot_set_elf_and_prog_header(
  void *elf_hdr_ptr,
  void *prog_hdr_ptr
);
#else
static inline boolean boot_set_elf_and_prog_header( 
  void *elf_hdr_ptr,
  void *prog_hdr_ptr
)
{
  return TRUE;
}
#endif

/*===========================================================================
**  Function :  boot_get_elf_eident_class
** ==========================================================================
*/
/*!
* 
* @brief
*   This function returns the value of the elf e_ident class value.
*   1 = 32 bit elf, 2 = 64 bit elf according to ELF spec.
*
* @par Dependencies
*   None 
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
uint32 boot_get_elf_eident_class
( void );
#else
static inline uint32 boot_get_elf_eident_class
( void )
{
  return 0x0;
}
#endif

/*===========================================================================
**  Function :  boot_get_elf_header
** ==========================================================================
*/
/*!
* 
* @brief
*   This function returns the address of elf header. 
*
* @par Dependencies
*   None 
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
uint64 boot_get_elf_header
( void );
#else
static inline uint64 boot_get_elf_header
( void )
{
  return 0x0;
}
#endif

/*===========================================================================
**  Function :  boot_get_program_header
** ==========================================================================
*/
/*!
* 
* @brief
*   This function returns the address of elf header. 
*
* @par Dependencies
*   None 
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
uint64 boot_get_program_header
( void );
#else
static inline uint64 boot_get_program_header
( void )
{
  return 0x0;
}
#endif

/* ============================================================================
**  Function : sbl_sahara_entry
** ============================================================================
*/
/*!
*   @brief
*   This function provides an entry into the Sahara protocol from SBL1.
*   This function performs any initialization required and jumps into the
*   protocol to transfer images directly to memory.
*   
*   @details
*   This function provides an entry into the Sahara protocol from PBL.
*   This function performs any initialization required and jumps into the
*   protocol to transfer images directly to memory.
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval  None
*   
*   @sa None
*/
#ifdef FEATURE_SAHARA_BOOT
void sbl_sahara_entry ( 
   mi_boot_image_header_type *header_ptr,
   uint32 image_id,
   uint32 image_type,
   uint32 sec_image_type,
   boot_boolean auth_flag,   
   boot_boolean jump_flag,   
   bl_shared_data_type * bl_shared_data   
);
#else
static inline void sbl_sahara_entry ( 
   mi_boot_image_header_type *header_ptr,
   uint32 image_id,
   uint32 image_type,
   uint32 sec_image_type,   
   boot_boolean auth_flag,   
   boot_boolean jump_flag,      
   bl_shared_data_type * bl_shared_data   
){}
#endif

/* ============================================================================
**  Function : sbl_sahara_get_elf_header
** ============================================================================
*/
/*!
*   @brief
*   This function returns elf header base address.
*   
*   @details
*   This function returns elf header base address for the last loaded elf image
*   
*   @param none
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval  None
*   
*   @sa None
*/
#ifdef FEATURE_SAHARA_BOOT
uint64 sbl_sahara_get_elf_header( void );
#else
static inline uint64 sbl_sahara_get_elf_header( void )
{
  return 0x0;
}
#endif

/* ============================================================================
**  Function : sbl_sahara_get_program_header
** ============================================================================
*/
/*!
*   @brief
*   This function returns program header buffer base address.
*   
*   @details
*   This function returns program header buffer base address
*   for the last loaded elf image.
*   
*   @param none
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval  None
*   
*   @sa None
*/
#ifdef FEATURE_SAHARA_BOOT
uint64 sbl_sahara_get_program_header( void );
#else
static inline uint64 sbl_sahara_get_program_header( void )
{
  return 0x0;
}
#endif


/*===========================================================================
**  Function :  boot_elf_set_auth_and_ssa_enable
** ==========================================================================
*/
/*!
* 
* @brief
*   This function will set/reset Flag to Turn on/Turn off authentication and
*   Subsystem image loading mode for elf images.
*
* @param[in] 
*  boolean auth_from_cfg_table   - TRUE if config table entry for the image
*                                  enables authentication else FALSE.
*  boolean ssa_value             - TRUE if Subsystem image loading mode to be
*                                  turned on else FALSE
*
* @param[out] 
*  None
*
* @par Dependencies
*  None
* 
* @retval
*   None
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
void boot_elf_set_auth_and_ssa_enable
( 
  boolean auth_from_cfg_table,
  boolean ssa_value
);
#else
static inline void boot_elf_set_auth_and_ssa_enable
( 
  boolean auth_from_cfg_table,
  boolean ssa_value
){}
#endif


/*===========================================================================
**  Function :  boot_elf_segment_in_whitelist
** ==========================================================================
*/
/*!
* 
* @brief
*   This function will set/reset Flag to Turn on/Turn off authentication and
*   Subsystem image loading mode for elf images.
*
* @param[in] 
*  boolean auth_from_cfg_table   - TRUE if config table entry for the image
*                                  enables authentication else FALSE.
*  boolean ssa_value             - TRUE if Subsystem image loading mode to be
*                                  turned on else FALSE
*
* @param[out] 
*  None
*
* @par Dependencies
*  None
* 
* @retval
*   None
* 
*/
#ifdef FEATURE_BOOT_LOAD_ELF
boolean
boot_elf_segment_in_whitelist(void * phdr_entry_ptr,
                              whitelist_region_type * elf_segment_whitelist);
#else
static inline boolean
boot_elf_segment_in_whitelist(void * phdr_entry_ptr,
                              whitelist_region_type * elf_segment_whitelist)
{
  return FALSE;
}
#endif

#endif /* BOOT_LOADER_H */

