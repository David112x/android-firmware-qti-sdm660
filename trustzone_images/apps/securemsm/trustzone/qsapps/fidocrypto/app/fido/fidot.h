/*
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
*/

#pragma once

/** Definitions from the FIDO UAF Authenticator Commands document
 */

/** Table 4.1.1: UAF Authenticator Command TAGs (0x3400-0x34FF, 0x3600-0x36FF). \n
*/
typedef enum {
  TAG_UAFV1_GETINFO_CMD             = 0x3401, /**< Tag for GetInfo command. */
  TAG_UAFV1_GETINFO_CMD_RESP        = 0x3601, /**< Tag for GetInfo command response. */
  TAG_UAFV1_REGISTER_CMD            = 0x3402, /**< Tag for Register command. */
  TAG_UAFV1_REGISTER_CMD_RESP       = 0x3602, /**< Tag for Register command response. */
  TAG_UAFV1_SIGN_CMD                = 0x3403, /**< Tag for Sign command. */
  TAG_UAFV1_SIGN_CMD_RESP           = 0x3603, /**< Tag for Sign command response. */
  TAG_UAFV1_DEREGISTER_CMD          = 0x3404, /**< Tag for Deregister command. */
  TAG_UAFV1_DEREGISTER_CMD_RESP     = 0x3604, /**< Tag for Deregister command response. */
  TAG_UAFV1_OPEN_SETTINGS_CMD       = 0x3406, /**< Tag for OpenSettings command. */
  TAG_UAFV1_OPEN_SETTINGS_CMD_RESP  = 0x3606, /**< Tag for OpenSettings command response. */
} UAF_AUTH_CMD_TAG;

/** Table 4.2.1: Non-command TAGs (0x2800-0x28FF, 0x3800-0x38FF). \n
*/
typedef enum {
  TAG_KEYHANDLE               = 0x2801, /**< Represents KeyHandle. */
  TAG_USERNAME_AND_KEYHANDLE  = 0x3802, /**< Represents an associate Username and KeyHandle. */
  TAG_USERVERIFY_TOKEN        = 0x2803, /**< Represents a User Verification Token. */
  TAG_APPID                   = 0x2804, /**< A full AppID as a UINT8[] encoding of a UTF8 string. */
  TAG_KEYHANDLE_ACCESS_TOKEN  = 0x2805, /**< Represents a KeyHandle Access Token. */
  TAG_USERNAME                = 0x2806, /**< A Username as a UINT8[] encoding of a UTF8 string. */
  TAG_ATTESTATION_TYPE        = 0x2807, /**< Represents an attestation type. */
  TAG_STATUS_CODE             = 0x2808, /**< Represents a status Code. */
  TAG_AUTHENTICATOR_METADATA  = 0x2809, /**< Represents a more detailed set of authenticator information. */
  TAG_ASSERTION_SCHEME        = 0x280A, /**< A UINT8[] containing the UTF8-encoded Assertion Scheme "UAFV1TLV" */
  TAG_TC_DISPLAY_PNG_CHARACHTERISTICS = 0x280B, /**< If an authenticator contains a PNG-capable transaction
                                                    confirmation display that is not implemented by a higher-level
                                                    layer, this tag is describing this display. */
  TAG_TC_DISPLAY_CONTENT_TYPE = 0x280C, /**< A UINT8[] containing the UTF8-encoded transaction display content type. */
  TAG_AUTHENTICATOR_INDEX     = 0x280D, /**< Authenticator index. */
  TAG_API_VERSION             = 0x280E, /**< API Version. */
  TAG_AUTHENTICATOR_ASSERTION = 0x280F, /**< Assertion generated by the Authenticator. */
  TAG_TRANSACTION_CONTENT     = 0x2810, /**< Transaction content sent to authenticator. */
  TAG_AUTHENTICATOR_INFO      = 0x3811, /**< Detailed information about Authenticator's capabilities. */
  TAG_SUPPORTED_EXTENSION_ID  = 0x2812, /**< Extension ID supported by the Authenticator. */
} UAF_AUTH_NON_CMD_TAG;

/** 4.3.1 Tags used in the UAF protocol (0x2E00-0x2EFF, 0x3E00-0x3EFF)
 */
typedef enum {
  TAG_UAFV1_REG_ASSERTION         = 0x3E01, /**< Authenticator response to Register command. */
  TAG_UAFV1_AUTH_ASSERTION        = 0x3E02, /**< Authenticator response to Sign command. */
  TAG_UAFV1_KRD                   = 0x3E03, /**< Key Registration Data. */
  TAG_UAFV1_SIGNED_DATA           = 0x3E04, /**< Data signed by authenticator with the UAuth.priv key. */
  TAG_ATTESTATION_CERT            = 0x2E05, /**< Each entry contains a single X.509 DER-encoded [ITU-X690-2008]
                                                 certificate. Multiple occurrences are allowed and form the attestation
                                                 certificate chain. Multiple occurrences must be ordered.
                                                 The attestation certificate itself MUST occur first. Each subsequent
                                                 occurrence (if exists) MUST be the issuing certificate of the previous
                                                 occurrence. */
  TAG_SIGNATURE                   = 0x2E06, /**< A cryptographic signature. */
  TAG_ATTESTATION_BASIC_FULL      = 0x3E07, /**< Full Basic Attestation. */
  TAG_ATTESTATION_BASIC_SURROGATE = 0x3E08, /**< Surrogate Basic Attestation. */
  TAG_KEYID                       = 0x2E09, /**< Represents a KeyID. */
  TAG_FINAL_CHALLENGE             = 0x2E0A, /**< Represents a Final Challenge. */
  TAG_AAID                        = 0x2E0B, /**< Represents an Authenticator Attestation ID. */
  TAG_PUB_KEY                     = 0x2E0C, /**< Represents a Public Key. */
  TAG_COUNTERS                    = 0x2E0D, /**< Represents a use counters for the authenticator. */
  TAG_ASSERTION_INFO              = 0x2E0E, /**< Represents assertion information necessary for message processing. */
  TAG_AUTHENTICATOR_NONCE         = 0x2E0F, /**< Represents a nonce value generated by the authenticator. */
  TAG_TRANSACTION_CONTENT_HASH    = 0x2E10, /**< Represents a hash of transaction content. */
  TAG_EXTENSION_CRITICAL          = 0x3E11, /**< This is a composite tag indicating that the content is a critical
                                                 extension. If the recipient does not understand the contents of this tag,
                                                 it MUST abort processing of the entire message.
                                                 This tag can be appended to any command and response. */
  TAG_EXTENSION                   = 0x3E12, /**< This is a composite tag indicating that the content is an extension.
                                                 This tag can be appended to any command and response. */
  TAG_EXTENSION_ID                = 0x2E13, /**< Represents extension ID. Content of this tag is a UINT8[] encoding of a UTF-8 string. */
  TAG_EXTENSION_DATA              = 0x2E14, /**< Represents extension data. Content of this tag is a UINT8[] byte array. */
} UAF_TAG;

/** Table 4.4.1: UAF Authenticator Status Codes (0x00-0xFF)\n
//~ */
typedef enum {
  UAF_CMD_STATUS_OK                   = 0x00, /**< Success */
  UAF_CMD_STATUS_ERR_UNKNOWN          = 0x01, /**< A generic error */
  UAF_CMD_STATUS_ACCESS_DENIED        = 0x02, /**< Access to command is denied */
  UAF_CMD_STATUS_USER_NOT_ENROLLED    = 0x03, /**< User is not enrolled */
  UAF_CMD_STATUS_CANNOT_RENDER_TRANSACTION_CONTENT  = 0x04, /**< Transaction content cannot be rendered */
  UAF_CMD_STATUS_USER_CANCELLED       = 0x05, /**< User has cancelled the operation */
  UAF_CMD_STATUS_CMD_NOT_SUPPORTED    = 0x06, /**< Command not supported */
  UAF_CMD_STATUS_ATTESTATION_NOT_SUPPORTED          = 0x07, /**< Required attestation not supported */
} UAF_CMD_STATUS_CODE;

/** Maximum lengths as specified by the standard. \n
*/
#define UAFV1_FINAL_CHALLENGE_MAX_LEN 32
#define UAFV1_KH_ACCESS_TOKEN_MAX_LEN 32
#define UAFV1_USERNAME_MAX_LEN        128
#define UAFV1_APPID_MAX_LEN           512

/** Maximum length for Register and Sign responses. \n
*/
#define QC_REG_CMD_RESP_MAX_LEN        (65535 + 4)
#define QC_SIGN_CMD_RESP_MAX_LEN       (65535 + 4)

/** Maximum lengths in Authentication. \n
*/
#define QC_AAID_MAX_LEN                   10
#define QC_CONTENT_TYPE_MAX_LEN           32
#define QC_MAX_PNG_CHARACTERISTICS        32
#define QC_ASSERTION_SCHEME_MAX_LEN       9
#define QC_MAX_ATTESTATION_TYPES          32
#define QC_MAX_SUPPORTED_EXTENSIONS       32
#define QC_SUPPORTED_EXTENSION_ID_MAX_LEN 32

/** Earliest Authenticator API Version supported in our
    implementation.
*/
#define QC_AUTH_API_VERSION 0x01

/** PNG Characteristics. \n
*/
#define QC_DISPLAY_PNG_BIT_DEPTH          8
#define QC_DISPLAY_PNG_COMPRESSION_METHOD 0
#define QC_DISPLAY_PNG_FILTER             0
#define QC_DISPLAY_PNG_INTERLACE          0

typedef enum {
  PNG_COLOR_TYPE_GREYSCALE       = 0x00,
  PNG_COLOR_TYPE_TRUECOLOR       = 0x02,
  PNG_COLOR_TYPE_INDEXED_COLOR   = 0x03,
  PNG_COLOR_TYPE_GREYSCALE_ALPHA = 0x04,
  PNG_COLOR_TYPE_TRUECOLOR_ALPHA = 0x06,
} QC_PNG_COLOR_TYPE;

/** Definitions from the FIDO UAF Registry of Predefined Values
 */
/** 3.1 User Verification Methods
 */
typedef enum {
  USER_VERIFY_PRESENCE    = 0x01,
  USER_VERIFY_FINGERPRINT = 0x02,
  USER_VERIFY_PASSCODE    = 0x04,
  USER_VERIFY_VOICEPRINT  = 0x08,
  USER_VERIFY_FACEPRINT   = 0x10,
  USER_VERIFY_LOCATION    = 0x20,
  USER_VERIFY_EYEPRINT    = 0x40,
  USER_VERIFY_PATTERN     = 0x80,
  USER_VERIFY_HANDPRINT   = 0x100,
  USER_VERIFY_NONE        = 0x200,
  USER_VERIFY_ALL         = 0x400,
} UAF_AUTH_USER_VERIFICATION_TYPE;

/** 3.2 Key Protection Types
 */
typedef enum {
  KEY_PROTECTION_SOFTWARE       = 0x01,
  KEY_PROTECTION_HARDWARE       = 0x02,
  KEY_PROTECTION_TEE            = 0x04,
  KEY_PROTECTION_SECURE_ELEMENT = 0x08,
  KEY_PROTECTION_REMOTE_HANDLE  = 0x10,
} UAF_AUTH_KEY_PROTECTION_TYPE;

/** 3.3 Matcher protection types
 */
typedef enum {
  MATCHER_PROTECTION_SOFTWARE = 0x01,
  MATCHER_PROTECTION_TEE      = 0x02,
  MATCHER_PROTECTION_ON_CHIP  = 0x04,
} UAF_AUTH_MATCHER_PROTECTION_TYPE;

/** 3.4 Authenticator Attachment Hints
 */
typedef enum {
  ATTACHMENT_HINT_INTERNAL    = 0x01,
  ATTACHMENT_HINT_EXTERNAL    = 0x02,
  ATTACHMENT_HINT_WIRED       = 0x04,
  ATTACHMENT_HINT_WIRELESS    = 0x08,
  ATTACHMENT_HINT_NFC         = 0x10,
  ATTACHMENT_HINT_BLUETOOTH   = 0x20,
  ATTACHMENT_HINT_NETWORK     = 0x40,
  ATTACHMENT_HINT_READY       = 0x80,
  ATTACHMENT_HINT_WIFI_DIRECT = 0x100,
} UAF_AUTH_ATTACHMENT_HINT;

/** 3.5 Transaction Confirmation Display Types
 */
typedef enum {
  TRANSACTION_CONFIRMATION_DISPLAY_ANY                  = 0x01,
  TRANSACTION_CONFIRMATION_DISPLAY_PRIVILEGED_SOFTWARE  = 0x02,
  TRANSACTION_CONFIRMATION_DISPLAY_TEE                  = 0x04,
  TRANSACTION_CONFIRMATION_DISPLAY_HARDWARE             = 0x08,
  TRANSACTION_CONFIRMATION_DISPLAY_REMOTE               = 0x10,
} UAF_AUTH_TRANSACTION_CONFIRMATION_DISPLAY_TYPE;

/** 3.6.1 Authentication Algorithms
 */
typedef enum {
  UAF_ALG_SIGN_SECP256R1_ECDSA_SHA256_RAW = 0x01,
  UAF_ALG_SIGN_SECP256R1_ECDSA_SHA256_DER = 0x02,
  UAF_ALG_SIGN_RSASSA_PSS_SHA256_RAW      = 0x03,
  UAF_ALG_SIGN_RSASSA_PSS_SHA256_DER      = 0x04,
  UAF_ALG_SIGN_SECP256K1_ECDSA_SHA256_RAW = 0x05,
  UAF_ALG_SIGN_SECP256K1_ECDSA_SHA256_DER = 0x06,
} UAF_ALG;

/** 3.6.2 Public Key Representation Formats
 */
typedef enum {
  UAF_ALG_KEY_ECC_X962_RAW      = 0x100,
  UAF_ALG_KEY_ECC_X962_DER      = 0x101,
  UAF_ALG_KEY_RSA_2048_PSS_RAW  = 0x102,
  UAF_ALG_KEY_RSA_2048_PSS_DER  = 0x103,
} UAF_ALG_KEY;

/** 3.7 Assertion Schemes
 */
#define UAF_TLV_SCHEME "UAFV1TLV"
