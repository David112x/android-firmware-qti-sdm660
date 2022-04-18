#ifndef GLINK_TRANSPORT_IF_H
#define GLINK_TRANSPORT_IF_H

/**
 * @file glink_transport_if.h
 *
 * Public API for the GLink Core to transport interface
 */
/*=============================================================================
     Copyright (c) 2014 QUALCOMM Technologies Incorporated.
     All rights reserved.
     Qualcomm Confidential and Proprietary
=============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE


when       who     what, where, why
--------   ---     ----------------------------------------------------------
02/10/15   an      Add wait_link_down to transport interface.
12/09/14   db      Function definition changes to accomodate xport priority
                   Added xport priority enum
03/22/14   bm      Initial release of GLink Core to transport interface.
===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================
                        INCLUDE FILES
===========================================================================*/

#include "comdef.h"

/*===========================================================================
                      MACRO DECLARATIONS
===========================================================================*/
/* GLink transport capability bit definitions */
/* Whether transport supports signalling */
#define GLINK_CAPABILITY_SIG_SUPPORT 0x00000001
/* Intentless mode of operation */
#define GLINK_CAPABILITY_INTENTLESS  0x00000002

/*===========================================================================
                      TYPE DECLARATIONS
===========================================================================*/
/* forward declaration */
struct glink_transport_if;
typedef struct glink_transport_if   glink_transport_if_type;

struct glink_core_xport_ctx;
typedef struct glink_core_xport_ctx glink_core_xport_ctx_type;

struct glink_core_if;
typedef struct glink_core_if        glink_core_if_type;

struct glink_rx_intent;
typedef struct glink_rx_intent      glink_rx_intent_type;

/* Priority of transports registered with glink */
typedef enum {
  GLINK_XPORT_SMEM = 100,
  GLINK_XPORT_RPM = 100,
  GLINK_XPORT_SMD = 200,
  GLINK_XPORT_CP_ENGINE = 300,
  GLINK_MIN_PRIORITY = GLINK_XPORT_CP_ENGINE,
  GLINK_INVALID_PRIORITY
} glink_xport_priority;	

/** Glink core -> Xport pkt type definition */
typedef struct {
  void       *data;      /* Pointer to the data buffer to be transmitted */
  const void *pkt_priv;  /* Per packet private data */
  uint32     iid;        /* Remote intent ID being used to transmit data */
  size_t     size;       /* Size of data buffer */
  size_t     size_remaining; /* Size left to transmit */
  void       *iovec;      /* Pointer to the data buffer to be transmitted */
  glink_buffer_provider_fn vprovider; /* Buffer provider for virtual space */
  glink_buffer_provider_fn pprovider; /* Buffer provider for physical space */
}glink_core_tx_pkt_type;
  
/** Transmit a version command for local negotiation. The transport would call
 *  glink_transport_if_type::rx_cmd_version_ack callback as a result */
typedef void (*tx_cmd_version_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  version, /* Version */
  uint32                  features /* Features */
);

/** Transmit a version ack for remote nogotiation */
typedef void (*tx_cmd_version_ack_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  version, /* Version */
  uint32                  features /* Features */
);

/** Signals the negotiation is complete and transport can now do version
 *  specific initialization. Return uint32 transport capabilities bit field */
typedef uint32 (*set_version_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  version, /* Version */
  uint32                  features /* Features */
);

/** Sends OPEN command to transport for transport to do whatever it deems 
 *  necessary to open a GLink logical channel.
 *  GLink Core expects glink_transport_if_type::rx_cmd_ch_open_ack to be called
 *  as a result of channel opening. */
typedef glink_err_type (*tx_cmd_ch_open_fn)
(
  glink_transport_if_type *if_ptr,/* Pointer to the interface instance */
  uint32                  lcid,   /* Local channel ID */
  const char              *name,  /* String name for the logical channel */
  glink_xport_priority    prio  
);

/** Sends CLOSE command to transport for transport to do whatever it deems 
 *  necessary to close the specified GLink logical channel.
 *  GLink Core expects glink_transport_if_type::rx_cmd_ch_close_ack to be 
 *  called as a result of channel closing. */
typedef glink_err_type (*tx_cmd_ch_close_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                     lcid  /* Local channel ID */
);

/** Sends the remote open ACK command in response to receiving
 *  glink_core_if_type::rx_cmd_ch_remote_open */
typedef void (*tx_cmd_ch_remote_open_ack_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  rcid,    /* Remote channel ID */
  glink_xport_priority    prio
);

/** Sends the remote close ACK command in response to receiving
 *  glink_core_if_type::rx_cmd_ch_remote_close */
typedef void (*tx_cmd_ch_remote_close_ack_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  rcid     /* Remote channel ID */
);

/** Allocates a receive buffer for the local rx intent */
typedef glink_err_type (*allocate_rx_intent_fn)
(
  glink_transport_if_type *if_ptr,    /* Pointer to the interface instance */
  size_t                  size,       /* Size of Rx intent */
  glink_rx_intent_type    *intent_ptr /* Intent ptr */
);

/** Deallocates a receive buffer for the local rx intent */
typedef glink_err_type (*deallocate_rx_intent_fn)
(
  glink_transport_if_type *if_ptr,    /* Pointer to the interface instance */
  glink_rx_intent_type    *intent_ptr /* Intent ptr */
); 

/** Send receive intent ID for a given channel */
typedef glink_err_type (*tx_cmd_local_rx_intent_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  lcid,    /* Local channel ID */
  size_t                  size,    /* Size of Rx intent */
  uint32                  liid     /* Local indent ID */
); 

/** Send receive done command for an intent for the specified channel */
typedef void(*tx_cmd_local_rx_done_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  lcid,    /* Local channel ID */
  uint32                  liid,    /* Local indent ID */
  boolean                 reuse    /* Reuse indent */
);

/** Send a data packet to the transport to be transmitted over the specified
 *  channel */
typedef glink_err_type (*tx_fn)
(
  glink_transport_if_type *if_ptr, /* Pointer to the interface instance */
  uint32                  lcid,    /* Local channel ID */
  glink_core_tx_pkt_type  *pctx    /* Packet to be transmitted */
);

/** Send a intent request to the remote side to have it queue more rx intents
 *  to unblock this end's tx operation */
typedef glink_err_type (*tx_cmd_rx_intent_req_fn)
(
  glink_transport_if_type *if_ptr,   /* Pointer to the interface instance */
  uint32                  lcid,      /* Local channel ID */
  size_t                  size       /* Size of the requested intent */
);

/** Send the ACK back for the rx intent request send by the other side, 
 *  specifynig whether the request was granted ot not */
typedef glink_err_type (*tx_cmd_remote_rx_intent_req_ack_fn)
(
  glink_transport_if_type *if_ptr,   /* Pointer to the interface instance */
  uint32                  lcid,      /* Local channel ID */
  boolean                 granted    /* Whether of not the intent request was
                                        granted */
);

/** Sets the local channel signals as per the specified 32-bit mask. 
 *  Transport may also send the 32-bit value as-is to the remote side. */
typedef glink_err_type (*tx_cmd_set_sigs_fn)
(
  glink_transport_if_type *if_ptr,   /* Pointer to the interface instance */
  uint32                  lcid,      /* Local channel ID */
  uint32                  sigs       /* Whether of not the intent request was
                                        granted */
);

/** Lets the XAL know of SSR on that edge. */
typedef glink_err_type (*ssr_fn)
(
  glink_transport_if_type *if_ptr   /* Pointer to the interface instance */
);

/** Trigger a poll for any rx data / signals on transport. */
typedef glink_err_type (*poll_fn)
(
  glink_transport_if_type *if_ptr   /* Pointer to the interface instance */
);

/** Mask/Unmask rx interrupt associated with transport. */
typedef glink_err_type (*mask_rx_irq_fn)
(
  glink_transport_if_type *if_ptr,  /* Pointer to the interface instance */
  boolean                 mask      /* TRUE-mask, FALSE=unmask */
);

/** Wait for the link to go down. */
typedef boolean (*wait_link_down_fn)
(
  glink_transport_if_type *if_ptr   /* Pointer to the interface instance */
);


/**
 * Data Structure for GLink Core to call into transport API
 *
 * This structure is used by the GLink core to operate transport
 * This set of function pointers to to be filled in by the transport
 * abstraction layer.
 */
struct glink_transport_if {
  /* Link needed for use with list APIs.  Must be at the head of the struct */
  smem_list_link_type                link;
  
  /** Transmit a version command for local negotiation. The transport would 
   * call glink_transport_if_type::rx_cmd_version_ack callback as a result */
  tx_cmd_version_fn                  tx_cmd_version;

  /** Transmit a version ack for remote nogotiation */
  tx_cmd_version_ack_fn              tx_cmd_version_ack;

  /** Signals the negotiation is complete and transport can now do version
   *  specific initialization */
  set_version_fn                     set_version;


  /** Sends OPEN command to transport for transport to do whatever it deems 
   *  necessary to open a GLink logical channel.
   *  GLink Core expects glink_transport_if_type::rx_cmd_ch_open_ack to be 
   *  called as a result of channel opening. */
  tx_cmd_ch_open_fn                  tx_cmd_ch_open;


  /** Sends CLOSE command to transport for transport to do whatever it deems 
   *  necessary to close the specified GLink logical channel.
   *  GLink Core expects glink_transport_if_type::rx_cmd_ch_close_ack to be 
   *  called as a result of channel closing. */
  tx_cmd_ch_close_fn                 tx_cmd_ch_close;


  /** Sends the remote open ACK command in response to receiving
   *  glink_core_if_type::rx_cmd_ch_remote_open */
  tx_cmd_ch_remote_open_ack_fn       tx_cmd_ch_remote_open_ack;

  /** Sends the remote close ACK command in response to receiving
   *  glink_core_if_type::rx_cmd_ch_remote_close */
  tx_cmd_ch_remote_close_ack_fn      tx_cmd_ch_remote_close_ack;

  /** Allocates a receive vector buffer for the local rx intent */
  allocate_rx_intent_fn               allocate_rx_intent;

  /** Deallocates a receive vector buffer for the local rx intent */
  deallocate_rx_intent_fn             deallocate_rx_intent;

  /** Send receive intent ID for a given channel */
  tx_cmd_local_rx_intent_fn          tx_cmd_local_rx_intent;


  /** Send receive done command for an intent for the specified channel */
  tx_cmd_local_rx_done_fn            tx_cmd_local_rx_done;


  /** Send a data packet to the transport to be transmitted over the specified
   *  channel */
  tx_fn                              tx;

   /** Send request to the remote to queue more rx intents */
  tx_cmd_rx_intent_req_fn            tx_cmd_rx_intent_req;

  /** Send ACK to the remote side's request to queue more rx intents */
  tx_cmd_remote_rx_intent_req_ack_fn tx_cmd_remote_rx_intent_req_ack;

  /** Sets the local channel signals as per the specified 32-bit mask. 
   *  Transport may also send the 32-bit value as-is to the remote side. */
  tx_cmd_set_sigs_fn                 tx_cmd_set_sigs;

  /** Lets the XAL know of SSR on that edge. */
  ssr_fn                             ssr;

  /** Trigger a poll for any rx data / signals on transport. */
  poll_fn                            poll;

  /** Mask/Unmask rx interrupt associated with transport */
  mask_rx_irq_fn                     mask_rx_irq;

  /** Wait for the link to go down. */
  wait_link_down_fn                  wait_link_down;

  /** Transport specific data pointer that transport may choose fill in
   * with some data */
  glink_core_xport_ctx_type          *glink_core_priv;

  /** GLINK core interface pointer associated with this transport interface */
  glink_core_if_type                 *glink_core_if_ptr;

  /* glink transport priority */
  glink_xport_priority                glink_priority;  
};

#endif //GLINK_TRANSPORT_IF_H

