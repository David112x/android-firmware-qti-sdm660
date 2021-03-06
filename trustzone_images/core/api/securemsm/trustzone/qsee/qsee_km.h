#ifndef QSEE_KM_H
#define QSEE_KM_H

/**
@file qsee_km.h
@brief Provide Secure Key Manager API wrappers
*/

/*===========================================================================
   Copyright (c) 2015 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

  $Header:
  $DateTime:
  $Author:

when       who      what, where, why
--------   ---      ------------------------------------
01/28/15   amen     Initial version.

===========================================================================*/

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <stdint.h>

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/* Bitmask flags to give tz_km_cmd_service */
#define KM_KC_FLAG     0x1   // flag to indicate keycontroller operation
#define KM_MAX_FLAG    0x2

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/

/**
 * \ingroup cri_cm_cmn_intf
 * \brief CM command interface values
 */
typedef enum km_cm_cmdid
{
    KM_CM_READ_DEVICE_INFO            = 0,  /**< Read CM device information. */
    KM_CM_READ_STATUS_INFO            = 1,  /**< Read CM status information. */
    KM_CM_READ_ERROR_SEQ             = 2,  /**< Read CM sequence error information. */
    KM_CM_READ_ERROR_INIT            = 3,  /**< Read CM initialization error information. */
    KM_CM_READ_ERROR_OTPCMD          = 4,  /**< Read CM OTP segment tag execution error information. */
    KM_CM_READ_ERROR_TRNG            = 5,  /**< Read CM TRNG error information. */
    KM_CM_READ_FEATURE               = 6,  /**< Read a feature value from feature space. */
    KM_CM_READ_OTP                   = 7,  /**< Read an OTP value from the OTP. */
    KM_CM_WRITE_FEATURE              = 8,  /**< Write a feature value to feature space. */
    KM_CM_EXECUTE_RSB                = 9,  /**< Execute an RSB transaction request. */
    KM_CM_EXECUTE_RSB_KEY_EXCH       = 10, /**< Execute an RSB key exchange transaction request. */
    KM_CM_EXECUTE_RSB_DSB            = 11, /**< Execute an RSB/DSB transaction request. */
    KM_CM_EXECUTE_OTPCMD             = 12, /**< Execute OTP command segments at the specified tag level request. */
    KM_CM_EXECUTE_TRNG_SAMPLE        = 13, /**< Execute a sample TRNG request. */
    KM_CM_MAX_COMMANDS               = 14  /**< Maximum number of interface commands. */
} km_cm_cmdid;


/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/

/**
 * @brief  This function will initialize a key manager context
 *
 * @param [out]hdl         Context is initialized and returned in hdl
 *
 * @return 0 on success, negative on failure
 */
int qsee_km_init(void **hdl);

/**
 * @brief Only if Crypto Manager(CM) is not busy, then only will
 *        open cm session return a success.
 *
 * @param [in]hdl  hdl generated by qsee_km_init
 *
 * @return 0 on success, negative on failure
 *
 */
int qsee_km_open_cm_session(void *hdl);

/**
 * @brief  This function passes the data blob to be unwrapped by 
 *         the CM hardware, the api will work, only if open cm
 *         session passed
 *
 * @param [in]hdl         hdl generated by calling qsee_km_init
 * @param [in]cmd_hdl_id  cmd id for operation to be performed 
 *                        by CM, km_cm_cmdid type
 * @param [in]flag        To indicate suboperation, eg Key 
 *                        Controller
 * @param [in/out]buffer  Data command to feed to CM, also reads
 *                        back information as required by
 *                        command
 * @param [in]buff_len    length of buffer in bytes
 *
 * @return 0 on success, negative on failure
 *
 */
int qsee_km_cmd_service(void         *hdl,
                        km_cm_cmdid  cmd_hdl_id,
                        uint32_t       flag,
                        uint8_t        *buffer, uint32  buff_len);

/**
 * @brief  If during qsee_km_cmd_service, sub operation was Key 
 *         controller, then HW has a key. This key can be
 *         requested by initiating client by calling the
 *         following api.
 *
 * @param [in] hdl          hdl as received by qsee_km_init
 * @param [out] keyptr      User allocated buffer, key is 
 *                          written to this
 * @param [in] keysz        Length of the keyptr buffer
 *
 * @return 0 on success, negative on failure
 *
 */
int qsee_km_getkey(void   *hdl, 
                   uint32_t *keyptr, uint32_t keysz);

/**
 * @brief Once application completes usage of CM core, it can 
 *        relieve its usage by calling following api
 *
 * @param [in] hdl      hdl as received by qsee_km_init
 *
 * @return 0 on success, negative on failure
 *
 */
int qsee_km_close_cm_session(void *hdl);

/**
 * @brief  Once application doesnt need this service anymore, 
 *         it can free the context. 
 *
 * @param [in] hdl       hdl as received by qsee_km_init
 *
 * @return 0 on success, negative on failure
 */
int qsee_km_deinit(void *hdl);

#endif /*QSEE_KM_H*/

