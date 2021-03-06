
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

              Diag Interface

GENERAL DESCRIPTION
   Contains main implementation of Diagnostic Log Services.

EXTERNALIZED FUNCTIONS
   log_set_code
   log_set_length
   log_set_timestamp
   log_submit
   log_free
   log_get_length
   log_get_code
   log_status
   log_alloc
   log_commit
   log_shorten

INITIALIZATION AND SEQUENCING REQUIREMENTS


Copyright (c) 2007-2012, 2014, 2017-2018 Qualcomm Technologies Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary

                              Edit History

$Header: //components/rel/core.qdsp6/1.0.c2/services/diag/LSM/qurt/src/Diag_LSM_Log.c#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
03/21/18   gn      Tagging the data with dynamic diag IDs
27/01/17   nk      Fixed issue with log_submit api
11/14/14   jtm/vk  Multi-PD Optimizations 
07/06/14   ph      Added support for Diag over STM
11/27/13   ph      Updated MSG 1.0 API references to MSG.2.0.
07/05/12   sg      Changes to bringup Diag MultiPD
10/19/10   mad     Fixed log_shorten
04/09/10   sg      Merging DCM rtos and wm files
09/23/09   sg      Mainlined when MSM5000_IRAM_FWD is not defined
07/07/09   mad     Removed unwanted headers: queue.h,diagpkti.h, diagi.h,
                   diagpkt.h,assert.h,qw.h,log_codes.h,diagtune.h,string.h
01/27/09   mad     modified log_submit() to allocate memory only if log mask is
                   enabled.
09/30/08   mad     Changes to take out Component services, and use
                   filesystem calls to access windiag driver.
09/04/08   mad     Fixed bug in log_free(): to free the correct pointer
05/01/08   JV      Added support to update the copy of log_mask in this process
                   during initialization and also on mask change
02/11/08   JV      Changed the comparison of IDiagPkt_Send()'s return value from
                   AEE_FAILURE to AEE_SUCCESS
01/16/08   JV      Created stubs for log_on_demand_register and log_on_demand_unregister
                   as we do not have function pointer support for Diag 1.5A
11/20/07   JV      Created

===========================================================================*/


/* ==========================================================================
   Include Files
========================================================================== */
#include "diagdiag_v.h"           /* For diag_log_rsp_type */
#include "log.h"
#include "msg.h"                  /* For MSG_LOW */
#include "diagstub.h"             /* For ts_get */
#include "Diag_LSM_Log_i.h"       /* For LSM log init and deinit */
#include "Diag_LSMi.h"            /* For declaration of windiag driver HANDLE etc */
#include "diagbuf_mpd.h"          /* For mpd functions */
#include "diaglogi.h"             /* For Diag log_header_type and functions */
#include "diag_shared_i.h"        /* For definition diag datatypes. */
#include "log_arrays_i.h"         /* For log_last_item_tbl */
#include "Diag_LSM_Qdi_wrapper.h" /* For LSM QDI wrapper functions */
#include "Diag_LSM_stm.h"         /* For diag stm macros and functions */
#include "diagbuf_v.h"            /* For diagbuf_header_type */
#include <stringl/stringl.h>      /* For memscpy */

/* The content of this table are computed in diag_lsm_log_init().  'uint16' is used
 * instead of 'int' to reduce data bus cycles to access an element of this
 * array.  The last entry is the offset to the byte following the array.  It
 * is used for range checking. */
static uint16 log_mask_offset_tbl[LOG_EQUIP_ID_LAST+1];

/* 'log_mask' is the mask of bits used to represent the configuration of all
* log codes. '1' denotes the code being enabled, '0' denotes 
* disabled. 
*/

static byte log_mask[LOG_MASK_SIZE];

void *log_commit_last = NULL; /* Many writers, 1 reader (DIAG) */

/* Internal function declarations */
static boolean log_status_mask(log_code_type code);
static boolean log_search_mask(unsigned int id, unsigned int item);
static boolean log_mask_enabled(const byte *xx_mask_ptr, unsigned int xx_id,
                                unsigned int xx_item);

/* External Function Implementations */
/*===========================================================================

FUNCTION LOG_ALLOC

DESCRIPTION
  This function allocates a buffer of size 'length' for logging data.  The
  specified length is the length of the entire log, including the log
  header.  This operation is inteneded only for logs that do not require
  data accumulation.

  !!! The header is filled in automatically by this routine.
 
PARAMETERS 
  log_code_type code   - log code
  unsigned int length  - size of log to alloc
 
DEPENDENCIES:
   Diag log service must be initialized.
   log_commit() or log_free() must be called ASAP after this call.

RETURN VALUE
  A pointer to the allocated buffer is returned on success.
  If the log code is disabled or there is not enough space, NULL is returned.

SIDE EFFECTS
  Since this allocation is made from a shared resource pool, log_commit()
  or log_free() must be called as soon as possible and in a timely fashion.

  If you need to log accumulated data, store the accumulated data in your
  own memory space and use log_submit() to log the data.
===========================================================================*/
PACKED void* log_alloc(
   log_code_type code,
   unsigned int length
   )
{
   diag_log_rsp_type *plog_pkt_ptr; /* Pointer to packet being created */
   log_header_type *phdr_ptr = NULL;
   void *return_ptr = NULL;
#ifdef FEATURE_DIAG_STM
   boolean stm_enabled = diag_stm_enabled; /* Store global for persistent behavior */
#endif

   if (diag_qdi_handle < DIAG_FD_MIN_VALUE)
   {
      return (NULL);
   }
   if (length <= sizeof(log_header_type))
   {
      MSG_1(MSG_SSID_DIAG, MSG_LEGACY_ERROR, "Alloc invalid length %d", length);
   }
   else if (log_status(code))
   {
#ifdef FEATURE_DIAG_STM
      /* Check is STM enabled */
      if (stm_enabled)
      {
         plog_pkt_ptr = (diag_log_rsp_type *)diag_stm_log_alloc(length + LOG_DIAGPKT_OFFSET);
      }
      else
      /* For any other case, we allocate from diagbuf as the packet is needed by something other than just STM */
#endif
      {
         plog_pkt_ptr = (diag_log_rsp_type *)diagbuf_mpd_alloc(0, FPOS(diag_log_rsp_type, log) + length, 0, DIAGBUF_ALLOC_REQUEST_LOG);
      }

      if (plog_pkt_ptr != NULL)
      {
         /* Fill in top of packet. i.e. diag_log_rsp_type*/
         plog_pkt_ptr->cmd_code = DIAG_LOG_F;
         plog_pkt_ptr->more = 0;
         plog_pkt_ptr->len = (uint16)length;

         /* Fill in log header*/
         phdr_ptr = (log_header_type *)&(plog_pkt_ptr->log);
         phdr_ptr->len = (uint16)length;
         phdr_ptr->code = code;
         time_get(phdr_ptr->ts);

         return_ptr = (void *)&(plog_pkt_ptr->log);
      }
      else
      {
#ifdef VINDBG
         printf("\n dropped log 0X%x", code);
#endif
         /* Dropped a log. */
         MSG_1(MSG_SSID_DIAG, MSG_LEGACY_LOW, "Dropped log 0x%x", code);
      }

   } /* if valid and enabled */

   return (return_ptr);

} /* log_alloc */


/*===========================================================================

FUNCTION LOG_SHORTEN

DESCRIPTION
  This function shortens the length of a previously allocated logging buffer in
  legacy code. This is used when the size of the record is not known at allocation
  time.Now that diagbuf is not used in the LSM layer and we just use memory from
  a pre-allocated pool, calling log_shorten, does not free the excess memory, it just
  updates the length field.
 
PARAMETERS 
  void *ptr           - pointer to the log pkt
  unsigned int length - length of the log pkt
DEPENDENCIES:
   Diag log service must be initialized.
   This must be called prior to log_commit().

RETURN VALUE
  None.

===========================================================================*/
void log_shorten(
   PACKED void *ptr,
   unsigned int length
   )
{
   byte *pdiag_pkt = (byte *)ptr; /* use byte* for pointer arithmetic */
   diag_log_rsp_type *pdiag_log;

   if (ptr)
   {
      pdiag_pkt -= LOG_DIAGPKT_OFFSET;
      pdiag_log = (diag_log_rsp_type *)pdiag_pkt;

      if (length < pdiag_log->len)
      {
         diagbuf_header_type *pkt_hdr;
         pkt_hdr = ((diagbuf_header_type *)pdiag_pkt - 1);
         if (pkt_hdr->status != DIAGBUF_STM_BUFFER_S)
         {
            // Do not call diagbuf_mpd_shorten if allocated from STM heap
            diagbuf_mpd_shorten((void *)pdiag_log, length + LOG_DIAGPKT_OFFSET);
         }

         /* Set the log packet length to the new length */
         pdiag_log->len = (uint16)length;

         /* log_set_length takes the log itself, not the log packet */
         log_set_length(ptr, length);
      }
   }
} /* log_shorten */

/*===========================================================================

FUNCTION LOG_COMMIT

DESCRIPTION
  This function commits a log buffer allocated by log_alloc().  Calling this
  function tells the logging service that the user is finished with the
  allocated buffer.
 
PARAMETERS 
  void *ptr - pointer to log pkt to commit.
 
DEPENDENCIES:
   Diag log service must be initialized.
   'ptr' must point to the address that was returned by a prior call to
  log_alloc().

RETURN VALUE
  None.

SIDE EFFECTS
  Since this allocation is made from a shared resource pool, this must be
  called as soon as possible after a log_alloc call.  This operation is not
  intended for logs that take considerable amounts of time ( > 0.01 sec ).
===========================================================================*/
void log_commit(PACKED void *ptr)
{
   if (ptr)
   {
      void *diagpkt_ptr;
      /* Set pointer to begining of diag pkt, not the log */
      diagpkt_ptr = ((byte *)ptr - LOG_DIAGPKT_OFFSET);

#ifdef FEATURE_DIAG_STM
      boolean stm_enabled = diag_stm_enabled; /* Store global for persistent behavior */
      diagbuf_header_type *pkt_hdr = ((diagbuf_header_type *)diagpkt_ptr - 1);

      if (stm_enabled)
      {
         log_header_type *phdr_ptr = NULL;

         /* Set pointer to beginning of diag pkt, not the log */
         phdr_ptr = (log_header_type *)ptr;
         diag_stm_write_pkt(diagpkt_ptr, LOG_DIAGPKT_OFFSET + phdr_ptr->len);
         if (pkt_hdr->status == DIAGBUF_STM_BUFFER_S)
         {
            diag_stm_log_free((void *)diagpkt_ptr);
         }
      }
      else
#endif /* FEATURE_DIAG_STM */
      {
         log_commit_last = (void *)ptr;
         diagbuf_mpd_commit(diagpkt_ptr);
      }
   }
   return;
} /* log_commit */

/*===========================================================================

FUNCTION LOG_FREE

DESCRIPTION
  This function frees the buffer in pre-allocated memory.

DEPENDENCIES:
  Diag log service must be initialized.

RETURN VALUE

SIDE EFFECTS
  None.
===========================================================================*/
void log_free(PACKED void *ptr)
{
   if (ptr)
   {
      byte *pkt_ptr = (byte *)ptr;
#ifdef FEATURE_DIAG_STM
      diagbuf_header_type *pkt_hdr;    /* Store the header in local variable     */
#endif

      pkt_ptr -= LOG_DIAGPKT_OFFSET;
#ifdef FEATURE_DIAG_STM

      //Check status to see if this is an STM only buffer. If so, use STM free function instead
      pkt_hdr = ((diagbuf_header_type *)pkt_ptr - 1);

      if (pkt_hdr->status == DIAGBUF_STM_BUFFER_S)
      {
         diag_stm_log_free(pkt_ptr);
      }
      else
#endif
      {
         diagbuf_mpd_shorten(pkt_ptr, 0);
         diagbuf_mpd_commit(pkt_ptr);
      }
   } 
} /* log_free */

/*===========================================================================

FUNCTION LOG_SUBMIT

DESCRIPTION
  This function is called to log an accumlated log entry. If logging is
  enabled for the entry by the external device, then this function essentially
  does the folliwng:
  log = log_alloc ();
  memscpy (log, length, ptr, log->len);
  log_commit (log);

PARAMETERS
  void *ptr - pointer to log pkt
 
DEPENDENCIES
   Diag log service must be initialized.

RETURN VALUE
  Boolean indicating success.

SIDE EFFECTS
  None.
===========================================================================*/
boolean log_submit( PACKED void *ptr )
{
   boolean bReturnVal = FALSE;
   diag_log_rsp_type *plog_pkt_ptr = NULL;

#ifdef FEATURE_DIAG_STM
   boolean stm_enabled = diag_stm_enabled; /* Store global for persistent behavior */
#endif

   /* The header is common to all logs, and is always at the beginning of the
          * packet. */
   log_header_type *plog_ptr = (log_header_type *)ptr;
   if (plog_ptr && (diag_qdi_handle >= DIAG_FD_MIN_VALUE))
   {
      /* Local vars to avoid use of misaligned variables */
      log_code_type code = plog_ptr->code;
      unsigned int length = plog_ptr->len;
      if ((length > sizeof(log_header_type)) && log_status(code))
      {
#ifdef FEATURE_DIAG_STM
         /* Check is STM enabled and that DIAG_STREAM_STM is the *only* stream */
         if (stm_enabled)
         {
            /* In this use case, we detect if *only* STM is enabled (i.e. no listeners) and then allocate
            as an STM only packet.*/
            plog_pkt_ptr = (diag_log_rsp_type *)diag_stm_log_alloc(length + LOG_DIAGPKT_OFFSET);
         }
         else
         /* For any other case, we allocate from diagbuf as the packet is needed by something other than just STM */
#endif
         {
            plog_pkt_ptr = (diag_log_rsp_type *)diagbuf_mpd_alloc(0, FPOS(diag_log_rsp_type, log) + length, 0, DIAGBUF_ALLOC_REQUEST_LOG);
         }
         if (plog_pkt_ptr != NULL)
         {
            plog_pkt_ptr->cmd_code = DIAG_LOG_F;
            plog_pkt_ptr->more = 0;
            plog_pkt_ptr->len = (uint16)length;
            memscpy(&plog_pkt_ptr->log, length, (void *)ptr, length);

            log_commit(&plog_pkt_ptr->log); //log_commit() takes care of STM as well.
            bReturnVal = TRUE;
         } /* if (plog_pkt_ptr != NULL) */
         else
         {
            /* Dropped a log */
            MSG_1(MSG_SSID_DIAG, MSG_LEGACY_LOW, "Dropped log 0x%x", code);
         }
      } /* if ((length > sizeof(log_header_type)) && log_status (code)) */
   } /* if (plog_ptr && ghWinDiag) */
   return (bReturnVal);
} /* log_submit */

/*===========================================================================

FUNCTION LOG_SET_LENGTH

DESCRIPTION
  This function sets the length field in the given log record.
  
  !!! Use with caution.  It is possible to corrupt a log record using this
  command.  It is intended for use only with accumulated log records, not
  buffers returned by log_alloc().

DEPENDENCIES
  Diag log service must be initialized.
   
RETURN VALUE
  None.

SIDE EFFECTS
  None.
===========================================================================*/
void log_set_length( PACKED void *ptr, unsigned int length )
{
   if (ptr)
   {
      /* All log packets are required to start with 'log_header_type'. */
      ((log_header_type *)ptr)->len = (uint16)length;
   }
} /* log_set_length */

/*===========================================================================

FUNCTION LOG_SET_CODE

DESCRIPTION
  This function sets the logging code in the given log record.

DEPENDENCIES
  Diag log service must be initialized.


RETURN VALUE
  None.

SIDE EFFECTS
  None.
===========================================================================*/
void log_set_code(PACKED void *ptr, log_code_type code)
{
   if (ptr)
   {
      /* All log packets are required to start with 'log_header_type'. */
      ((log_header_type *)ptr)->code = code;
   }

} /* log_set_code */

/*===========================================================================

FUNCTION LOG_SET_TIMESTAMP

DESCRIPTION
  This function captures the system time and stores it in the given log record.

DEPENDENCIES
   Diag log service must be initialized.

RETURN VALUE
  None.

SIDE EFFECTS
  None.
===========================================================================*/
void log_set_timestamp(PACKED void *plog_hdr_ptr)
{
   if (plog_hdr_ptr)
   {
      time_get(((log_header_type *)plog_hdr_ptr)->ts);
   }
} /* log_set_timestamp */

/*===========================================================================

FUNCTION LOG_GET_LENGTH

DESCRIPTION
  This function returns the length field in the given log record.

DEPENDENCIES
   Diag log service must be initialized.

RETURN VALUE
  An unsigned int, the length

SIDE EFFECTS
  None.
===========================================================================*/
unsigned int log_get_length(PACKED void *ptr)
{
   unsigned int length = 0;
   if (ptr)
   {
      log_header_type *plog = (log_header_type *)ptr;

      if (plog)
      {
         length = plog->len;
      }
   }
   return (length);
}

/*===========================================================================

FUNCTION LOG_GET_CODE

DESCRIPTION
  This function returns the log code field in the given log record.

DEPENDENCIES
   Diag log service must be initialized.

RETURN VALUE
  log_code_type, the code

SIDE EFFECTS
  None.
===========================================================================*/
log_code_type log_get_code(PACKED void *ptr)
{
   log_code_type code = 0;
   if (ptr)
   {
      log_header_type *plog = (log_header_type *)ptr;

      if (plog)
      {
         code = (log_code_type)plog->code;
      }
   }
   return (code);
}

/*===========================================================================

FUNCTION LOG_STATUS

DESCRIPTION
  This function returns whether a particular code is enabled for logging.

DEPENDENCIES
   Diag log service must be initialized.

RETURN VALUE
  boolean indicating if enabled

SIDE EFFECTS
  None.
===========================================================================*/
boolean log_status(log_code_type code)
{
   boolean status = FALSE;

   status = log_status_mask(code);

   return (status);
} /* log_status */

/*===========================================================================

FUNCTION DIAG_LSM_LOG_INIT

DESCRIPTION
 Initializes the log service

RETURN VALUE
 boolean indicating success

SIDE EFFECTS
 None.
===========================================================================*/
boolean Diag_LSM_Log_Init(void)
{
   boolean status = TRUE;
   int i = 0;

   log_mask_offset_tbl[0] = 0;

   for (i = 0; i < LOG_EQUIP_ID_LAST; i++)
   {
      log_mask_offset_tbl[i + 1] = 1 + log_mask_offset_tbl[i] +
         LOG_MASK_ARRAY_INDEX(log_last_item_tbl[i]);
   }
   return (status);
} /* Diag_LSM_Log_Init */

/*===========================================================================

FUNCTION    Diag_LSM_Log_DeInit

DESCRIPTION
  De-Initialize the Diag Log service.

DEPENDENCIES


RETURN VALUE
   boolean indicating success


SIDE EFFECTS


===========================================================================*/
boolean Diag_LSM_Log_DeInit(void)
{
   return (TRUE);
}     /* Diag_LSM_Log_DeInit */

/*===========================================================================

FUNCTION    log_update_mask

DESCRIPTION
  Update the log mask.

DEPENDENCIES
  None.

RETURN VALUE
  None

SIDE EFFECTS
  None

===========================================================================*/
boolean log_update_mask(void)
{
   boolean status = TRUE;
   if (diag_qdi_handle >= DIAG_FD_MIN_VALUE)
   {
      dword maskLen_Recvd = 0;

      if (!(diag_lsm_ioctl(DIAG_IOCTL_GETLOGMASK, NULL, 0, log_mask, sizeof(log_mask), &maskLen_Recvd)) || maskLen_Recvd != LOG_MASK_SIZE)
      {
         status = FALSE;
      }
   }
   else
   {
      status = FALSE;
   }
   return (status);
} /* log_update_mask */

/*===========================================================================

FUNCTION LOG_STATUS_MASK

DESCRIPTION
  This routine is a wrapper for log_search_mask().  It is used to look up
  the given code in the log mask.

RETURN VALUE
  A boolean indicating if the specified log is enabled.

===========================================================================*/
static boolean
log_status_mask(log_code_type code)
{
   unsigned int id, item;
   boolean status = FALSE;

   id = LOG_GET_EQUIP_ID(code);
   item = LOG_GET_ITEM_NUM(code);

   status = log_search_mask(id, item);
   return (status);
}

/*===========================================================================

FUNCTION LOG_SEARCH_MASK

DESCRIPTION
  This function returns a boolean indicating TRUE if the given ID and 'item'
  denotes a valid and enabled log code.

===========================================================================*/
static boolean log_search_mask(
   unsigned int id,
   unsigned int item
   )
{
   boolean return_val = FALSE;

   /* if valid code val */
   if (log_mask_enabled(log_mask, id, item))
   {
      return_val = TRUE;
   }
   return (return_val);
} /* log_search_mask */


/*===========================================================================

FUNCTION LOG_MASK_ENABLED

DESCRIPTION
  This function returns a boolean indicating if the specified code is enabled.

  The equipment ID and item code are passed in to avoid duplicating the
  calculation within this call.  It has to be done for most routines that call
  this anyways.

===========================================================================*/
static boolean log_mask_enabled(
   const byte *mask_ptr,
   unsigned int id,
   unsigned int item
   )
{
   unsigned int offset, index, mask;
   boolean enabled = FALSE;

   if (id <= LOG_EQUIP_ID_LAST && item <= log_last_item_tbl[id])
   {
      offset = log_mask_offset_tbl[id];
      index = LOG_MASK_ARRAY_INDEX(item);

      mask = LOG_MASK_BIT_MASK(item);


      if (mask_ptr[offset + index] & mask)
      {
         enabled = TRUE;
      }
   }
   else
   {
      /*Nothing */
   }
   return (enabled);
} /* log_mask_enabled */


