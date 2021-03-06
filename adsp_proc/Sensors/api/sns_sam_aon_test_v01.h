#ifndef SNS_SAM_AON_TEST_SVC_SERVICE_01_H
#define SNS_SAM_AON_TEST_SVC_SERVICE_01_H
/**
  @file sns_sam_aon_test_v01.h

  @brief This is the public header file which defines the SNS_SAM_AON_TEST_SVC service Data structures.

  This header file defines the types and structures that were defined in
  SNS_SAM_AON_TEST_SVC. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were
  defined in the IDL as messages contain mandatory elements, optional
  elements, a combination of mandatory and optional elements (mandatory
  always come before optionals in the structure), or nothing (null message)

  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to.

  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:

  uint32_t test_opaque_len;
  uint8_t test_opaque[16];

  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set
  by the decode routine and should be checked so that the correct number of
  elements in the array will be accessed.

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2017 Qualcomm Technologies, Inc.  
  All Rights Reserved. 
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  $Header: //components/rel/ssc.slpi/2.2/api/sns_sam_aon_test_v01.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Tue Jan 24 2017 (Spin 0)
   From IDL File: sns_sam_aon_test_v01.idl */

/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_consts Constant values defined in the IDL */
/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_enums Enumerated types used in QMI messages */
/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_messages Structures sent as QMI messages */
/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_accessor Accessor for QMI service object */
/** @defgroup SNS_SAM_AON_TEST_SVC_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "sns_sam_common_v01.h"
#include "sns_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define SNS_SAM_AON_TEST_SVC_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define SNS_SAM_AON_TEST_SVC_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define SNS_SAM_AON_TEST_SVC_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define SNS_SAM_AON_TEST_SVC_V01_MAX_MESSAGE_ID 0x0024
/**
    @}
  */


/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_consts
    @{
  */
#define SNS_SAM_AON_TEST_SUID_V01 0x85ffcac15e564789

/**  Max number of items in a data report indication */
#define SNS_SAM_DATA_MAX_AON_TEST_LEN_V01 3
/**
    @}
  */

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_messages
    @{
  */
/** Request Message; This command enables SNS_SAM_AON_TEST algorithm. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}sns_sam_aon_test_enable_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_messages
    @{
  */
/** Response Message; This command enables SNS_SAM_AON_TEST algorithm. */
typedef struct {

  /* Mandatory */
  sns_common_resp_s_v01 resp;

  /* Mandatory */
  uint8_t instance_id;
  /**<  
    Instance ID is assigned by SAM.
    The client shall use this instance ID for future messages associated with
    this algorithm instance.
  */
}sns_sam_aon_test_enable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_messages
    @{
  */
/** Request Message; This command disables a SNS_SAM_AON_TEST algorithm. */
typedef struct {

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance id identifies the algorithm instance.  */
}sns_sam_aon_test_disable_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_messages
    @{
  */
/** Response Message; This command disables a SNS_SAM_AON_TEST algorithm. */
typedef struct {

  /* Mandatory */
  sns_common_resp_s_v01 resp;

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance id identifies the algorithm instance.  */
}sns_sam_aon_test_disable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_messages
    @{
  */
/** Indication Message; Report containing SNS_SAM_AON_TEST algorithm output */
typedef struct {

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance id identifies the algorithm instance.  */

  /* Mandatory */
  uint32_t timestamp;
  /**<   Timestamp of input used to generate the algorithm output  */

  /* Mandatory */
  uint32_t data_len;  /**< Must be set to # of elements in data */
  int32_t data[SNS_SAM_DATA_MAX_AON_TEST_LEN_V01];
  /**<   Feature output data  */
}sns_sam_aon_test_report_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_messages
    @{
  */
/** Indication Message; Asynchronous error indication for SNS_SAM_AON_TEST algorithm. */
typedef struct {

  /* Mandatory */
  uint8_t error;
  /**<   Sensor1 error code.  */

  /* Mandatory */
  uint8_t instance_id;
  /**<   Instance id identifies the algorithm instance.  */
}sns_sam_aon_test_error_ind_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 
//#define REMOVE_SNS_SAM_AON_TEST_CANCEL_V01 
//#define REMOVE_SNS_SAM_AON_TEST_DISABLE_V01 
//#define REMOVE_SNS_SAM_AON_TEST_ENABLE_V01 
//#define REMOVE_SNS_SAM_AON_TEST_ERROR_V01 
//#define REMOVE_SNS_SAM_AON_TEST_REPORT_V01 
//#define REMOVE_SNS_SAM_AON_TEST_VERSION_V01 
//#define REMOVE_SNS_SAM_GET_ALGO_ATTRIBUTES_V01 

/*Service Message Definition*/
/** @addtogroup SNS_SAM_AON_TEST_SVC_qmi_msg_ids
    @{
  */
#define SNS_SAM_AON_TEST_CANCEL_REQ_V01 0x0000
#define SNS_SAM_AON_TEST_CANCEL_RESP_V01 0x0000
#define SNS_SAM_AON_TEST_VERSION_REQ_V01 0x0001
#define SNS_SAM_AON_TEST_VERSION_RESP_V01 0x0001
#define SNS_SAM_AON_TEST_ENABLE_REQ_V01 0x0002
#define SNS_SAM_AON_TEST_ENABLE_RESP_V01 0x0002
#define SNS_SAM_AON_TEST_DISABLE_REQ_V01 0x0003
#define SNS_SAM_AON_TEST_DISABLE_RESP_V01 0x0003
#define SNS_SAM_AON_TEST_REPORT_IND_V01 0x0005
#define SNS_SAM_AON_TEST_ERROR_IND_V01 0x0006
#define SNS_SAM_AON_TEST_GET_ATTRIBUTES_REQ_V01 0x0024
#define SNS_SAM_AON_TEST_GET_ATTRIBUTES_RESP_V01 0x0024
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro SNS_SAM_AON_TEST_SVC_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type SNS_SAM_AON_TEST_SVC_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define SNS_SAM_AON_TEST_SVC_get_service_object_v01( ) \
          SNS_SAM_AON_TEST_SVC_get_service_object_internal_v01( \
            SNS_SAM_AON_TEST_SVC_V01_IDL_MAJOR_VERS, SNS_SAM_AON_TEST_SVC_V01_IDL_MINOR_VERS, \
            SNS_SAM_AON_TEST_SVC_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

