#ifndef GLINK_INTERNAL_H
#define GLINK_INTERNAL_H

/*===========================================================================

                    GLink Core Internal Header File


-----------------------------------------------------------------------------
Copyright (c) 2014-2015 QUALCOMM Technologies Incorporated
-----------------------------------------------------------------------------
===========================================================================*/


/*===========================================================================

                           EDIT HISTORY FOR FILE

$Header: //components/rel/rpm.bf/1.8/core/mproc/glink/core/inc/glink_internal.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
07/07/15   bc      Remove unnecessary variable in channel ctx
07/01/15   bc      Remove unnecessary header
06/10/15   bc      Add new utility apis
05/19/15   an      QoS support
05/18/15   bc      Remove unused function declarations
05/18/15   bc      update transport_q_cs to have cs per edge
05/10/15   bc      Remove unnecessary channel migration variables
04/14/15   bc      Seperated channel state variable
04/09/15   an      Memory optimizations
03/20/15   an      Disable logging for memory constrained environment
03/24/15   an      Tx packet scheduler
02/23/15   bc      Added tracer packet support
01/28/15   rs      Integrated TZ
01/28/14   db      Added lock in channel context structure to change channel
                   states automically 
12/29/14   bm      Add rx/tx_abort callback to channel ctx
12/09/14   db      Changes in function declarations to accomodate xport priority
11/12/14   an      Core refactoring for limited memory environment support
07/04/14   bm      Updated API to v0.6.5 GLink spec
04/07/14   bm      Initial version. 
===========================================================================*/


/*===========================================================================
                        INCLUDE FILES
===========================================================================*/
#include "smem_list.h"
#include "glink.h"
#include "glink_os_utils.h"
#include "glink_core_if.h"

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================
                        FEATURE DEFINITIONS
===========================================================================*/
#define GLINK_VERSION 0
#define GLINK_FEATURE_FLAGS 0
#define GLINK_NUM_HOSTS     9
#define GLINK_INVALID_CID   0

/*===========================================================================
                           MACRO DEFINITIONS
===========================================================================*/
#if OS_EVENT_LOG_LEVEL >= OS_EVENT_LOG_LEVEL_INFO
#define GLINK_LOG_EVENT(type, ch_name, xport, remote_ss, param) \
  glink_mem_log(__FUNCTION__, __LINE__, type, ch_name, xport, remote_ss, param);

#define GLINK_MEM_LOG_SIZE 128
#else
#define GLINK_LOG_EVENT(type, ch_name, xport, remote_ss, param)
#define GLINK_MEM_LOG_SIZE 1
#endif

/*===========================================================================
                           TYPE DEFINITIONS
===========================================================================*/
typedef enum {
  GLINK_EVENT_INIT,
  GLINK_EVENT_REGISTER_XPORT,
  GLINK_EVENT_CH_OPEN,
  GLINK_EVENT_CH_CLOSE,
  GLINK_EVENT_CH_TX,
  GLINK_EVENT_CH_Q_RX_INTENT,
  GLINK_EVENT_CH_RX_DONE,
  GLINK_EVENT_LINK_UP,
  GLINK_EVENT_RX_CMD_VER,
  GLINK_EVENT_RM_CH_OPEN,
  GLINK_EVENT_CH_OPEN_ACK,
  GLINK_EVENT_CH_CLOSE_ACK,
  GLINK_EVENT_CH_REMOTE_CLOSE,
  GLINK_EVENT_CH_STATE_TRANS,
  GLINK_EVENT_CH_INTENT_PUT,
  GLINK_EVENT_CH_RX_DATA,
  GLINK_EVENT_CH_RX_DATA_FRAG,
  GLINK_EVENT_CH_GET_PKT_CTX,
  GLINK_EVENT_CH_PUT_PKT_CTX,
  GLINK_EVENT_CH_TX_DONE,
  GLINK_EVENT_CH_SIG_SET,
  GLINK_EVENT_CH_SIG_L_GET,
  GLINK_EVENT_CH_SIG_R_GET,
  GLINK_EVENT_CH_NO_MIGRATION,
  GLINK_EVENT_CH_MIGRATION_IN_PROGRESS,
  GLINK_EVENT_XPORT_INTERNAL,
  GLINK_EVENT_TRACER_PKT_FAILURE,
  GLINK_EVENT_TXV_INVALID_BUFFER,
  GLINK_EVENT_CH_QOS_REG,
  GLINK_EVENT_CH_QOS_CANCEL,
  GLINK_EVENT_CH_QOS_START,
  GLINK_EVENT_CH_QOS_STOP,
  GLINK_EVENT_INVALID_REMOTE_SS
}glink_log_event_type;

typedef struct _glink_channel_intents_type {

  /* Link for a channel in Tx queue */
  struct _glink_channel_intents_type* next;

  /* Pointer to channel context */
  glink_channel_ctx_type        *ch_ctx;

  /* Critical section to protest access to intent queues */
  os_cs_type                    intent_q_cs;

  /* Event that glink_tx waits on and blocks until remote rx_intents
  * are available */
  os_event_type                 rm_intent_avail_evt;

  /* Size of requested intent that this channel wait on */
  size_t                        rm_intent_req_size;

  /* Linked list of remote Rx intents. Data can be transmitted only when
  * remote intents are available */
  smem_list_type                remote_intent_q;

  /* Linked list of remote Rx intents which local GLink core has used to
  * transmit data, and are pending Tx complete */
  smem_list_type                remote_intent_pending_tx_q;

  /* Linked list of local Rx intents. Data can be received only when
  * local intents are available */
  smem_list_type                local_intent_q;

  /* Linked list of remote Rx intents held by the clients */
  smem_list_type                local_intent_client_q;

  /* Read intent being gathered */
  glink_rx_intent_type          *cur_read_intent;

  /* Linked list of Tx packets in the order they where submitted by 
   * the channel owner */
  smem_list_type                tx_pkt_q;

} glink_channel_intents_type;


typedef struct _glink_channel_qos_type {
  /* qos request count */
  uint32                        qos_req_count;

  /* qos request packet size */
  size_t                        qos_pkt_size;

  /* qos request latency */
  uint32                        qos_latency_us;

  /* qos request rate */
  uint32                        qos_rate;

  /* qos priority */
  uint32                        qos_tokens;

  /* qos transport context */
  void                          *qos_transport_ctx;

  /* qos start time for priority balancing */
  os_timetick_type              qos_start_priority_time;

} glink_channel_qos_type;


struct glink_channel_ctx {
  /* Link needed for use with list APIs.  Must be at the head of the struct */
  smem_list_link_type                 link;
  
  /* Channel name */
  char                                name[GLINK_CH_NAME_LEN];

  /* Local channel ID */
  uint32                              lcid;

  /* Remote Channel ID */
  uint32                              rcid;

  /* Local Channel state */
  glink_local_state_type              local_state;
  
  /* Remote channel state */
  glink_remote_state_type             remote_state;

  /* Critical section to protect channel states */
  os_cs_type                          ch_state_cs;
  
  /* Channel local control signal state */
  uint32                              local_sigs;

  /* Channel remote control signal state */
  uint32                              remote_sigs;

  /* Critical section to protect tx operations */
  os_cs_type                          tx_cs;
  
  /* channel intent collection */
  glink_channel_intents_type          *pintents;

  /* Critical section to protest access to QoS context */
  os_cs_type                          qos_cs;

  /* qos priority */
  uint32                              qos_priority;

  /* channel QoS context */
  glink_channel_qos_type              *qosctx;
  
  /* Interface pointer with with this channel is registered */
  glink_transport_if_type             *if_ptr; 

  /** Private data for client to maintain context. This data is passed back
   * to client in the notification callbacks */
  const void                          *priv;

  /** Data receive notification callback */
  glink_rx_notification_cb            notify_rx;

  /** Tracer Packet data receive notification callback */
  glink_rx_tracer_pkt_notification_cb notify_rx_tracer_pkt;
  
  /** Vector receive notification callback */
  glink_rxv_notification_cb           notify_rxv;

  /** Data transmit notification callback */
  glink_tx_notification_cb            notify_tx_done;

  /** GLink channel state notification callback */
  glink_state_notification_cb         notify_state;

  /** Intent request from the remote side */
  glink_notify_rx_intent_req_cb       notify_rx_intent_req;
  
  /** New intent arrival from the remote side */
  glink_notify_rx_intent_cb           notify_rx_intent;

  /** Control signal change notification - Invoked when remote side
   *  alters its control signals */  
  glink_notify_rx_sigs_cb             notify_rx_sigs;
  
  /** rx_intent abort notification. This callback would be invoked for
  *  every rx_intent that is queued with GLink core at the time the
  *  remote side or local side decides to close the port. Optional */
  glink_notify_rx_abort_cb            notify_rx_abort;

  /** tx abort notification. This callback would be invoked if client
  *   had queued a tx buffer with glink and it had not been transmitted i.e.
  *   tx_done callback has not been called for this buffer and remote side
  *   or local side closed the port. Optional */
  glink_notify_tx_abort_cb            notify_tx_abort;

  /* save glink open config options */
  uint32                              ch_open_options;
};


typedef struct _glink_mem_log_entry_type {
  const char *func;
  uint32 line;
  glink_log_event_type type; 
  const char *msg;
  const char *xport;
  const char *remote_ss;
  uint32 param;
} glink_mem_log_entry_type;

/* Structure to store link notification callbacks */
typedef struct {
  /* Link needed for use with list APIs.  Must be at the head of the struct */
  smem_list_link_type       link;
  
  const char*               xport;         /* NULL = any transport */
  const char*               remote_ss;     /* NULL = any subsystem */
  glink_link_state_notif_cb link_notifier; /* Notification callback */
  void                      *priv;         /* Notification priv ptr */
} glink_link_notif_data_type;


/* Function pointer used to iterate glink registered transports
 * glink_client_cond_fn is used to find specifc transport client wants
 * glink_client_ex_fn will execute client's operation on specific/all transports
 * depends on client's choice */
typedef boolean (*glink_client_cond_fn)
(
  glink_transport_if_type *if_ptr,
  void                    *cond1,   /* First condition to compare */
  uint32                   cond2,   /* Second condition to compare */
  void                   **out      /* Client private return value */
);

typedef void (*glink_client_ex_fn)
(
  glink_transport_if_type *if_ptr,
  void                    *param1,   /* First parameter */
  uint32                   param2,   /* Second parameter */
  void                   **out      /* Client private return value */
);

/*===========================================================================
                              GLOBAL DATA DECLARATIONS
===========================================================================*/
extern const char *glink_hosts_supported[GLINK_NUM_HOSTS];

/*===========================================================================
                    LOCAL FUNCTION DEFINITIONS
===========================================================================*/
/*===========================================================================
                    EXTERNAL FUNCTION DEFINITIONS
===========================================================================*/
/*===========================================================================
FUNCTION      glink_link_up

DESCRIPTION   Indicates that transport is now ready to start negotiation 
              using the v0 configuration

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge
                         
RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_link_up
(
  glink_transport_if_type *if_ptr
);

/*===========================================================================
FUNCTION      glink_rx_cmd_version

DESCRIPTION   Receive transport version for remote-initiated version 
              negotiation

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge

            version   Remote Version

            features  Remote Features

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_version
(
  glink_transport_if_type *if_ptr,
  uint32                  version,
  uint32                  features
);

/*===========================================================================
FUNCTION      glink_rx_cmd_version_ack

DESCRIPTION   Receive ACK to previous glink_transport_if::tx_cmd_version 
              command

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge

            version   Remote Version

            features  Remote Features

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_version_ack
(
  glink_transport_if_type *if_ptr,
  uint32                  version,
  uint32                  features
);

/*===========================================================================
FUNCTION      glink_rx_cmd_ch_remote_open

DESCRIPTION   Receive remote channel open request; Calls 
              glink_transport_if:: tx_cmd_ch_remote_open_ack as a result

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge

            rcid      Remote Channel ID

            *name     String name for logical channel

            prio      requested xport priority from remote side

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_ch_remote_open
(
  glink_transport_if_type *if_ptr,
  uint32                  rcid,
  const char              *name,
  glink_xport_priority    prio  
);

/*===========================================================================
FUNCTION      glink_rx_cmd_ch_open_ack

DESCRIPTION   This function is invoked by the transport in response to 
              glink_transport_if:: tx_cmd_ch_open

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge

            lcid      Local Channel ID
   
            prio      Negotiated xport priority obtained from remote side
                      after negotiation happened on remote side

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_ch_open_ack
(
  glink_transport_if_type *if_ptr,
  uint32                  lcid,
  glink_xport_priority    prio
);

/*===========================================================================
FUNCTION      glink_rx_cmd_ch_close_ack

DESCRIPTION   This function is invoked by the transport in response to 
              glink_transport_if_type:: tx_cmd_ch_close

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge

            lcid      Local Channel ID

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_ch_close_ack
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  lcid     /* Local channel ID */
);

/*===========================================================================
FUNCTION      glink_rx_cmd_ch_remote_close

DESCRIPTION   Remote channel close request; will result in sending 
              glink_transport_if_type:: tx_cmd_ch_remote_close_ack

ARGUMENTS   *if_ptr   Pointer to interface instance; must be unique
                      for each edge

            rcid      Remote Channel ID

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_ch_remote_close
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  rcid     /* Remote channel ID */
);

/*===========================================================================
FUNCTION      glink_rx_put_pkt_ctx

DESCRIPTION   Transport invokes this call to receive a packet fragment (must 
              have previously received an rx_cmd_rx_data packet)

ARGUMENTS   *if_ptr      Pointer to interface instance; must be unique
                         for each edge

            rcid         Remote Channel ID

            *intent_ptr  Pointer to the intent fragment

            complete     True if pkt is complete 

RETURN VALUE  None

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_put_pkt_ctx
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  rcid,    /* Remote channel ID */
  glink_rx_intent_type    *intent_ptr, /* Fragment ptr */
  boolean                 complete     /* True if pkt is complete */
);

/*===========================================================================
FUNCTION      glink_rx_cmd_remote_sigs

DESCRIPTION   Transport invokes this call to inform GLink of remote side
              changing its control signals

ARGUMENTS   *if_ptr      Pointer to interface instance; must be unique
                         for each edge

            rcid         Remote Channel ID

            remote_sigs  Remote signal state.

RETURN VALUE  None.

SIDE EFFECTS  None
===========================================================================*/
void glink_rx_cmd_remote_sigs
(
  glink_transport_if_type *if_ptr,    /* Pointer to the interface instance */
  uint32                  rcid,       /* Remote channel ID */
  uint32                  remote_sigs /* Remote control signals */
);

/*===========================================================================
  FUNCTION      glinki_add_ch_to_xport
===========================================================================*/
/** 
 * Add remote/local channel context to xport open channel queue
 *
 * @param[in]    if_ptr            Pointer to xport if on which channel is to
 *                                 be opened
 * @param[in]    ch_ctx            channel context
 * @param[out]   allocated_ch_ctx  Pointer to channel context pointer
 * @param[in]    local_open        flag to determine if channel is opened 
 *                                 locally or remotely
 * @param[in]    prio              negotiated xport priority 
 *                                 (used to send priority via remote_open_ack to 
 *                                  remote side)
 *
 * @return       pointer to glink_transport_if_type struct
 *
 * @sideeffects  NONE
 */
/*=========================================================================*/
glink_err_type glinki_add_ch_to_xport
(
  glink_transport_if_type  *if_ptr,
  glink_channel_ctx_type   *ch_ctx,
  glink_channel_ctx_type  **allocated_ch_ctx,
  unsigned int              local_open,
  glink_xport_priority      prio
);

void glink_mem_log
(
  const char *func, 
  uint32 line,
  glink_log_event_type type, 
  const char *msg, 
  const char *xport, 
  const char *remote_ss, 
  uint32 param
);

/*===========================================================================
FUNCTION      glink_core_setup
===========================================================================*/
/**

  Initializes internal core functions based on the transport capabilities.

  @param[in]  if_ptr   The Pointer to the interface instance.

  @return     None.

  @sideeffects  None.
*/
/*=========================================================================*/
void glink_core_setup(glink_transport_if_type *if_ptr);

/*===========================================================================
FUNCTION      glink_core_get_default_interface
===========================================================================*/
/**

  Provides default core interface.

  @return     Pointer to the default core interface.

  @sideeffects  None.
*/
/*=========================================================================*/
glink_core_if_type* glink_core_get_default_interface(void);

/*===========================================================================
FUNCTION      glink_core_setup_full_xport
===========================================================================*/
/**

  Initializes internal core functions for the full-featured transport.

  @param[in]  if_ptr   The Pointer to the interface instance.

  @return     None.

  @sideeffects  None.
*/
/*=========================================================================*/
void glink_core_setup_full_xport(glink_transport_if_type *if_ptr);

/*===========================================================================
FUNCTION      glink_core_setup_intentless_xport
===========================================================================*/
/**

  Initializes internal core functions for the intentless transport.

  @param[in]  if_ptr   The Pointer to the interface instance.

  @return     None.

  @sideeffects  None.
*/
/*=========================================================================*/
void glink_core_setup_intentless_xport(glink_transport_if_type *if_ptr);

/*===========================================================================
  FUNCTION      glink_core_setup_intent_xport
===========================================================================*/
/**

  Initializes internal core functions based on the transport capabilities.

  @param[in]  if_ptr   The Pointer to the interface instance.

  @return     None.

  @sideeffects  None.
*/
/*=========================================================================*/
void glink_core_setup_intent_xport(glink_transport_if_type *if_ptr);

/*===========================================================================
  FUNCTION      glink_core_qos_get_priority
===========================================================================*/
/**

  Calculates pinitial priority for QoS request.

  @param[in]  if_ptr   The Pointer to the interface instance.
  @param[in]  req_rate The requested rate.

  @return     Priority.

  @sideeffects  None.
*/
/*=========================================================================*/
uint32 glink_core_qos_get_priority(glink_transport_if_type *if_ptr, uint32 req_rate);

/*===========================================================================
  FUNCTION      glinki_channel_fully_opened
===========================================================================*/
/** 
 * Check whether this channel is fully opened or not (local & remote)
 * This also checks transport status
 *
 * @param[in]  handle        glink channel handle
 *
 * @return     TRUE,  if channel is fully opened
 *             FASLE, otherwise
 *
 * @sideeffects  NONE
 */
/*=========================================================================*/
boolean glinki_channel_fully_opened
(
  glink_handle_type          handle
);

/*===========================================================================
  FUNCTION      glink_core_qos_cancel
===========================================================================*/
/**

  Releases QoS resources.

  @param[in]  open_ch_ctx  Pointer to the channel context.

  @return     None.

  @sideeffects  None.
*/
/*=========================================================================*/
void glink_core_qos_cancel(glink_channel_ctx_type *open_ch_ctx);

/*===========================================================================
  FUNCTION      glinki_register_link_notif_data
===========================================================================*/
/** 
 * Register link notification data
 *
 * @param[in]  link_notif_data  parameter for link notif data
 * 
 * @return       NONE
 * 
 * @sideeffects  NONE
 */
/*=========================================================================*/
void glinki_register_link_notif_data
(
  glink_link_notif_data_type *link_notif_data
);

/*===========================================================================
  FUNCTION      glinki_deregister_link_notif_data
===========================================================================*/
/** 
 * Deregister link notification data
 *
 * @param[in]  link_notif_data  parameter for link notif data
 * 
 * @return       NONE
 * 
 * @sideeffects  NONE
 */
/*=========================================================================*/
void glinki_deregister_link_notif_data
(
  glink_link_notif_data_type *link_notif_data
);

/*===========================================================================
  FUNCTION      glinki_scan_xports_and_notify
===========================================================================*/
/** 
 * Scan xports and notify link up state event
 *
 * @param[in]  link_notif_data  parameter for link notif data
 * 
 * @return       NONE
 * 
 * @sideeffects  NONE
 */
/*=========================================================================*/
void glinki_scan_xports_and_notify
(
  glink_link_notif_data_type *link_notif_data
);

/*===========================================================================
  FUNCTION      glinki_scan_notif_list_and_notify
===========================================================================*/
/** 
 * Scan registered link notification list and notify of xport link state change
 *
 * @param[in]  if_ptr  pointer to xport interface
 * @param[in]  state   link state to notify
 * 
 * @return       NONE
 * 
 * @sideeffects  NONE
 */
/*=========================================================================*/
void glinki_scan_notif_list_and_notify
(
  glink_transport_if_type *if_ptr,
  glink_link_state_type state
);

/*===========================================================================
  FUNCTION      glinki_xport_linkup
===========================================================================*/
/** 
 * Check whether this transport is in linkup state or not
 *
 * @param[in]    if_ptr     transport interface pointer
 * 
 * @return       TRUE   if this xport is in link up state
 *               FALSE  otherwise
 * 
 * @sideeffects  NONE
 */
/*=========================================================================*/
boolean glinki_xport_linkup
(
  glink_transport_if_type *if_ptr
);

/*===========================================================================
  FUNCTION      glinki_xports_for_each
===========================================================================*/
/** 
 * Scan all the transports in given edge and perform client's function for each
 * transport
 *
 * @param[in]    remote_ss    name of remote subsystem, NULL string not accepted
 * @param[in]    client_ex_fn client function to perform when desired xport is 
 *                            found
 * @param[in]    cond1        first condition to use in client_ex_fn
 * @param[in]    cond2        second condition to use in client_ex_fn
 * @param[out]   out          value to return in case client wants
 *
 * @return       None.
 *
 * @sideeffects  None.
 */
/*=========================================================================*/
void glinki_xports_for_each
(
  const char         *remote_ss,
  glink_client_ex_fn  client_ex_fn,
  void               *param1,
  uint32              param2,
  void              **out
);

/*===========================================================================
  FUNCTION      glinki_xports_find
===========================================================================*/
/** 
 * Scan all the transports in given edge and finds transport that satisfy
 * client's condition
 *
 * @param[in]    remote_ss      name of remote subsystem, NULL string not accepted
 * @param[in]    client_cond_fn client function to check if this transport is 
 *                              what client is looking for
 * @param[in]    cond1          first condition to use in client_ex_fn
 * @param[in]    cond2          second condition to use in client_ex_fn
 * @param[out]   out            value to return in case client wants
 *
 * @return       pointer to glink_transport_if_type struct
 *               NULL if there isn't any xport matches client's search condition
 *
 * @sideeffects  None.
 */
/*=========================================================================*/
glink_transport_if_type *glinki_xports_find
(
  const char           *remote_ss,
  glink_client_cond_fn  client_cond_fn,
  void                 *cond1,
  uint32                cond2,
  void                **out
);

/*===========================================================================
  FUNCTION      glinki_find_ch_ctx_by_lcid
===========================================================================*/
/** 
 * Find channel context by lcid
 *
 * @param[in]    xport_ctx  Pointer to transport private context
 * @param[in]    lcid       local channel ID
 *
 * @return       pointer to glink channel context
 *
 * @sideeffects  This function needs to be protected by channel_q_cs
 *               Caller is responsible grab/release mutex when calling this
 */
/*=========================================================================*/
glink_channel_ctx_type *glinki_find_ch_ctx_by_lcid
(
  glink_core_xport_ctx_type *xport_ctx,
  uint32                     lcid
);

/*===========================================================================
  FUNCTION      glinki_find_ch_ctx_by_rcid
===========================================================================*/
/** 
 * Find channel context by rcid
 *
 * @param[in]    xport_ctx  Pointer to transport private context
 * @param[in]    rcid       remote channel ID
 *
 * @return       pointer to glink channel context
 *
 * @sideeffects  This function needs to be protected by channel_q_cs
 *               Caller is responsible grab/release mutex when calling this
 */
/*=========================================================================*/
glink_channel_ctx_type *glinki_find_ch_ctx_by_rcid
(
  glink_core_xport_ctx_type *xport_ctx,
  uint32                     rcid
);

/*===========================================================================
  FUNCTION      glinki_find_ch_ctx_by_name
===========================================================================*/
/** 
 * Find channel context by channel name, called by local/remote open function
 * This function will also indicate (valid_open_call) if this open call would
 * be valid or not
 *
 * @param[in]    xport_ctx        Pointer to transport private context
 * @param[in]    ch_name          channel name
 * @param[in]    local_open       flag to indicate this is local open call
 * @param[out]   valid_open_call  tell whether this open call would be valid
 *                                or not
 *
 * @return       pointer to glink channel context
 *               NULL if channel doesn't exist
 *
 * @sideeffects  This function needs to be protected by channel_q_cs
 *               Caller is responsible grab/release mutex when calling this
 */
/*=========================================================================*/
glink_channel_ctx_type *glinki_find_ch_ctx_by_name
(
  glink_core_xport_ctx_type *xport_ctx,
  const char                *ch_name,
  boolean                    local_open,
  boolean                   *valid_open_call
);

/*===========================================================================
  FUNCTION      glinki_find_remote_host
===========================================================================*/
/** 
 * return remote subsystem ID based on remote subsystem name
 *
 * @param[in]    remote_ss  remote subsystem name
 *
 * @return       remote subsystem ID
 *
 * @sideeffects  None.
 */
/*=========================================================================*/
uint32 glinki_find_remote_host
(
  const char *remote_ss
);

/*===========================================================================
  FUNCTION      glink_get_best_xport
===========================================================================*/
/** 
 * This function gives best available transport for give edge
 *
 * @param[in]    remote_ss  Name of remote subsystem
 * 
 * @return       pointer to glink_transport_if_type
 *
 * @sideeffects  NONE
 */
/*=========================================================================*/
glink_transport_if_type *glinki_find_best_xport
(
  const char *remote_ss
);

/*===========================================================================
  FUNCTION      glinki_find_requested_xport
===========================================================================*/
/** 
 * Find requested or best transport depending on client's request
 *
 * @param[in]    xport_name         name of transport
 * @param[in]    remote_ss          remote subsystem name
 * @param[in]    open_ch_option     option client gave when called glink_open
 * @param[out]   suggested_priority best xport priority glink suggests
 *
 * @return       pointer to glink_transport_if_type struct
 *
 * @sideeffects  NONE
 */
/*=========================================================================*/
glink_transport_if_type *glinki_find_requested_xport
(
  const char           *xport_name,
  const char           *remote_ss,
  uint32                open_ch_option,
  glink_xport_priority *suggested_priority
);

/*===========================================================================
  FUNCTION      glinki_find_xport_by_priority
===========================================================================*/
/** 
 * This function returns glink_transport_if pointer based on transport priority
 *
 * @param[in]    prio        glink xport prio
 * @param[in]    remote_ss   remote subsytem name
 *
 * @return       pointer to glink_transport_if_type struct
 *
 * @sideeffects  NONE
 */
/*=========================================================================*/
glink_transport_if_type *glinki_find_xport_by_priority
(
  glink_xport_priority  prio,
  const char           *remote_ss
);

/*===========================================================================
  FUNCTION      glinki_enqueue_item
===========================================================================*/
/** 
 *  Enqueue item to smem list in protected context
 * 
 * @param[in]    smem_list  smem list to enqueue
 * @param[in]    item       item to enqueue
 * @param[in]    cs         mutex to protect the list
 *
 * @return       None.
 *
 * @sideeffects  None.
 */
/*=========================================================================*/
void glinki_enqueue_item
(
  smem_list_type *smem_list_ptr,
  void           *item,
  os_cs_type     *cs
);

/*===========================================================================
  FUNCTION      glinki_dequeue_item
===========================================================================*/
/** 
 *  Dequeue item from smem list in protected context
 * 
 * @param[in]    smem_list  smem list to dequeue from 
 * @param[in]    item       item to dequeue
 * @param[in]    cs         mutex to protect the list
 *
 * @return       None.
 *
 * @sideeffects  None.
 */
/*=========================================================================*/
void glinki_dequeue_item
(
  smem_list_type *smem_list_ptr,
  void           *item,
  os_cs_type     *cs
);

#ifdef FEATURE_TRACER_PACKET
/*===========================================================================
FUNCTION      glink_tracer_packet_log_pctx_pkt
===========================================================================*/
/** 
 * Log tracer packet event. Tracer packet is included in glink_core_tx_pkt
 * and needs to use vprovider to extract it
 * 
 * @param[in]  pctx     pointer to glink_core_tx_pkt_type
 * @param[in]  event_id event_id
 * 
 * @return         None
 *
 * @sideeffects    None
 */
/*=========================================================================*/
void glink_tracer_packet_log_pctx_pkt
(
  glink_core_tx_pkt_type  *pctx,
  uint32                   event_id
);
#endif

#endif /* GLINK_INTERNAL_H */
