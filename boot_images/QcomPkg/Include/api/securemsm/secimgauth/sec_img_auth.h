#ifndef SEC_IMG_AUTH_H
#define SEC_IMG_AUTH_H

/**
@file sec_img_auth.h
@brief Secure Image Authentication 
*/

/*===========================================================================
   Copyright (c) 2012-2015 by QUALCOMM Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE


when       who      what, where, why
--------   ---      ------------------------------------
10/29/15   plc      Added struct sec_img_auth_ftbl_type
15/08/14   mm       Adapted for 64 bit 
10/26/13   mm       Adapted for Boot ROM 
02/20/12   vg       Ported from TZ PIL.

===========================================================================*/

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <comdef.h>
#include "MIprogressive.h"
#include "MIheader.h"
#include "secboot.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/* The first 0x100 values are reserved for secure boot failures. Please refer secboot.h */
typedef enum sec_img_auth_error_type
{
  SEC_IMG_AUTH_SUCCESS = 0x0,
  SEC_IMG_AUTH_FAILURE = 0x101,
  SEC_IMG_AUTH_INVALID_ARG = 0x102,
  SEC_IMG_AUTH_OUT_OF_RANGE = 0x103,
  SEC_IMG_ELF_HEADERS_INVALID_DIGEST = 0x104,
  SEC_IMG_AUTH_SEGMENT_INVALID_DIGEST = 0x105,
  SEC_IMG_AUTH_NO_MEMORY = 0x106,
  SEC_IMG_AUTH_INVALID_DIGEST_LEN = 0x107,
  SEC_IMG_AUTH_GET_SW_VERSION_FAILED = 0x108,
  SEC_IMG_AUTH_GET_SW_ID_FAILED = 0x109,
  SEC_IMG_AUTH_GET_CODE_SEGMENT_FAILED = 0x10A,
  SEC_IMG_AUTH_INCORRECT_HASH_LEN = 0x10B,
  SEC_IMG_AUTH_INCORRECT_HASH_TOTAL_LEN = 0x10C,
  SEC_IMG_AUTH_CORRUPTED_IMAGE = 0x10D,
  SEC_IMG_AUTH_MI_BOOT_INVALID = 0x10E,
  SEC_IMG_AUTH_INVALID_ELF = 0x10F,
  SEC_IMG_AUTH_STATE_INVALID = 0x110,
  SEC_IMG_AUTH_MI_BOOT_INVALID_SIZE = 0x111,
  SEC_IMG_AUTH_ELF_INCORRECT_MAGIC = 0x112,
  SEC_IMG_AUTH_ELF_INVALID_CLASS = 0x113,
  SEC_IMG_AUTH_INVALID_VERSION = 0x114,
  SEC_IMG_AUTH_ELF_INVALID_EHSIZE = 0x115,
  SEC_IMG_AUTH_ELF_INVALID_PHENTSIZE = 0x116,
  SEC_IMG_AUTH_PROG_TBL_INVALID_SIZE = 0x117,
  SEC_IMG_AUTH_HASH_SEG_INVALID_SIZE = 0x118,
  SEC_IMG_AUTH_ELF_HDR_INVALID_SIZE = 0x119,
  SEC_IMG_AUTH_NOT_INITIALIZED = 0x11A,
  SEC_IMG_AUTH_ELF_INVALID_NUM_SEGMENTS = 0x11B,
  SEC_IMG_AUTH_INVALID_IMG_ID = 0x11C,
  SEC_IMG_AUTH_VALIDATE_IMAGE_AREA_INVALID_SEGMENT = 0x11D,
  SEC_IMG_AUTH_VALIDATE_IMAGE_AREA_INTEGER_OVERFLOW = 0x11E,
  SEC_IMG_AUTH_MI_BOOT_INVALID_CERT_CHAIN_SIZE = 0x11F,
  SEC_IMG_AUTH_HASH_SEG_TOTAL_INVALID_SIZE = 0x120,
  SEC_IMG_AUTH_SIG_INVALID_SIZE = 0x121,
  SEC_IMG_AUTH_MIHDR_NOT_ALIGNED = 0x122,
  SEC_IMG_AUTH_VALIDATE_IMAGE_AREA_INVALID_ENTRY= 0x123,
  SEC_IMG_AUTH_CERT_INVALID_SIZE = 0x124,
  SEC_IMG_AUTH_HASH_SEG_ARRAY_INVALID_SIZE = 0x125,
  SEC_IMG_AUTH_INCORRECT_HASH_TABLE_SEGMENTS_COUNT = 0x126,
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_SIZE =0x127,
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_MAGIC = 0x128,
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_VERSION = 0x129,
  SEC_IMG_AUTH_ENCRYPTION_INVALID_SIZE = 0x12A,
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_SOURCE_ID = 0x12B,
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_KEY_LADDER_LEN = 0x12C,
  SEC_IMG_AUTH_INVALID_ENCRYPTION_KEY_ID = 0x12D,
  SEC_IMG_AUTH_INVALID_IMAGE_ID = 0x12E,
  SEC_IMG_AUTH_INVALID_ENC_PRARM_SIZE = 0x12F,
  SEC_IMG_AUTH_INTEGER_OVERFLOW = 0x12E,
  SEC_IMG_AUTH_IMAGE_NOT_SUPPORTED = 0x130,
  SEC_IMG_AUTH_HW_FAILURE = 0x131,
  SEC_IMG_AUTH_SECDBG_INIT_FAILURE = 0x132,

  SEC_IMG_AUTH_MAX                    = 0x7FFFFFFF /**< Force to 32 bits */
}sec_img_auth_error_type;

typedef struct sec_img_auth_elf_info_type
{
  void *elf_hdr;       /**< Pointer to the elf header */
  void *prog_hdr;      /**< Pointer to the start of the program header; */
  uint8*      hash_seg_hdr;   /**< Pointer to the hash segment header*/
} sec_img_auth_elf_info_type;


/**
 * Structure for holding whitelist
 */
typedef struct sec_img_auth_whitelist_area_s
{
  uint64 start; /**< Start address of the memory area. Start is inclusive. */
  uint64 end;   /**< End address of the memory area. End is exclusive.*/
} sec_img_auth_whitelist_area_t;

/**
 * Strucuture for passing the whitelist and the count
*/
typedef struct sec_img_auth_whitelist_area_param_s
{
  uint32 count;
  sec_img_auth_whitelist_area_t *area;
}sec_img_auth_whitelist_area_param_t;

/* State of Secure Image Authentication */
typedef enum
{
  SEC_IMG_AUTH_STATE_INIT = 1,
  SEC_IMG_AUTH_STATE_ELF_AND_PROG_HDRS_HASH_MATCH,
  SEC_IMG_AUTH_STATE_COMPLETE_SEGMENTS_HASH_MATCH
}sec_img_auth_state_et;

/* Structure the state of the secure image auth 
  * Holds verified information in case of success
  * Holds error information in case of error 
  */
typedef struct sec_img_auth_verified_info_t
{
  uint32 version_id; /* the version of this structure. */
  uint32 ph_segment; /* Segment that caused the hash failure. */
  sec_img_auth_state_et state; /* State of the Secure Image Authentication. */
  secboot_verified_info_type v_info; /* Secure Boot verified information. */
  secboot_verified_info_type qc_v_info;
  sec_img_auth_error_type oem_auth_status;
  sec_img_auth_error_type qc_auth_status;
}sec_img_auth_verified_info_s;


/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/
 
/**
 * @brief Authenticates hash table segment against its signature.
 *
 * @param[in] sec_img_id  Secure Image Identifier 
 * @param[in] elf_hdr     Pointer to the ELF header 
 * @param[in] whitelist_area Pointer to the whitelist area 
 * @param[out] v_info Pointer to the verified info 
 *
 * @return 0 on success,  else failure.
 */
sec_img_auth_error_type sec_img_auth_verify_metadata(uint32 sec_img_id, 
                                 const sec_img_auth_elf_info_type *sec_img_data,
                                 sec_img_auth_whitelist_area_param_t *whitelist_area,
                                 sec_img_auth_verified_info_s *v_info);

/**
 * @brief Validates ELF segments against hash table 
 *
 * @param[in] sec_img_id  Secure Image Identifier 
 * @param[out] v_info Pointer to the verified info 
 * @return 0 on success,  else failure
 */
sec_img_auth_error_type sec_img_auth_hash_elf_segments(uint32 sec_img_id,
                                      sec_img_auth_verified_info_s *v_info);

/**
 * @brief Elf header parser, to check for the correct format.
 *
 * @param[in] elf_hdr   Pointer to the ELF header.
 *
 * @result \c TRUE if the header is in correct format, \c FALSE otherwise.
 */

sec_img_auth_error_type sec_img_auth_validate_elf(const void* elf_hdr);

/**
 * @brief Check for loadable, non paged segments
 *
 * @param[in] ELF object class format 
 * @param[in] Program hdr entry for the segment
 *
 * @result \c TRUE if the segment is valid, \c FALSE otherwise.
 */
boolean sec_img_auth_is_valid_segment(uint32 format, const void * entry);

/**
 * @brief Check if the image auth is enabled or not
 *
 * @param[in] code_seg - code segment
 *
 * @param[in, out] is_auth_enabled - the flag for the image auth to be enabled or not
 *
 * @return 0 on success, negative on failure
 */
sec_img_auth_error_type sec_img_auth_is_auth_enabled(uint32 code_seg, uint32* is_auth_enabled);

/**
 * @brief SecImgAuth Function table
 */
typedef struct sec_img_auth_ftbl_type
{
  uint32 version_id;  /*define ftbl version */
  sec_img_auth_error_type (*sec_img_auth_init)
                       (void* s_img_handle);
  sec_img_auth_error_type (*sec_img_auth_verify_metadata)
                       (void *s_img_handle,
                        void *v_info);
  sec_img_auth_error_type (*sec_img_auth_hash_elf_segments)
                       (void *s_img_handle,
                        void *v_info);
  sec_img_auth_error_type (*sec_img_auth_validate_elf)
                       (const void* elf_hdr);
  uint32 (*sec_img_auth_is_valid_segment)
                       (uint32 format, const void * entry);
  sec_img_auth_error_type (*sec_img_auth_get_elf_format)
                       (const  void * elf_hdr,
                        uint32 *elf_format);
}sec_img_auth_ftbl_type;

/**
 * @brief initialize sec img auth lib variables
 *
 * @param[in] pbl_verified_info - the verified information from pbl
 *
 * @return 0 on success, negative on failure
 */
sec_img_auth_error_type sec_img_auth_init(secboot_verified_info_type *pbl_verified_info);

/**
 * @brief de-initialize sec img auth lib variables
 *
 * @return 0 on success, negative on failure
 */
sec_img_auth_error_type sec_img_auth_deinit(void);

void sec_img_auth_re_enable_debug(secboot_verified_info_type v_info);
#endif
