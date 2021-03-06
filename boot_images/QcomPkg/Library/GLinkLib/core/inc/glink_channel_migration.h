#ifndef GLINK_CHANNEL_MIGRATION_H
#define GLINK_CHANNEL_MIGRATION_H

/*===========================================================================

                    GLink channel migration Header File


-----------------------------------------------------------------------------
Copyright (c) 2014 QUALCOMM Technologies Incorporated
-----------------------------------------------------------------------------
===========================================================================*/


/*===========================================================================

                           EDIT HISTORY FOR FILE


when       who     what, where, why
--------   ---     ----------------------------------------------------------
11/14/14   db      Initial version. 
===========================================================================*/


/*===========================================================================

                        INCLUDE FILES

===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================
                        FEATURE DEFINITIONS
===========================================================================*/

/** 
 * This function returns glink_transport_if pointer based on 
 *  XPORT priority
 *
 * @param[in]    prio       glink xport prio
 * @param[in]   remote_ss   remote subsytem name
 *
 * @return       pointer to glink_transport_if_type struct
 *
 * @sideeffects  NONE
 */
glink_transport_if_type *glinki_get_xport_from_prio
(
  glink_xport_priority prio,
  const char *remote_ss 
);

/** 
 * This function negotiated xport priorities and gives best
 *  available priority
 *
 * @param[in]    requested_best_prio priority requested by remote subsytem
 * @param[in]    current_best_prio   priority requested by channel on local 
                                     side
 *
 * @return       Negotiated xport priority
 *
 * @sideeffects  NONE
 */
glink_xport_priority glinki_negotiate_ch_migration
(
  glink_xport_priority requested_prio,
  glink_xport_priority current_prio 
);

/** 
 * This function searches channel with given name on all available
 * xports and returns channel context and xport on which channel is
 * present. These return values are used to negotiate xport priorities
 * and to decide if channel needs to be migrated from given xport
 * to negotiated xport
 *
 * @param[in]    if_ptr              transport on which channel is opened
 * @param[in]    name                name of the channel
 * @param[in]    is_local_channel    flag to notify this function if channel to
 *	                                 be searched will have state REMOTE_OPEN
 *                                   or LOCAL_OPEN
 * @param[out]   present_ch_ctx      channel context to be returned
 * @param[out]   present_if_ptr      xport pointer on which channel is open
 *
 * @return       TRUE  -  if channel found
 *               FALSE -  if channel is not found
 *
 * @sideeffects  NONE
 */
boolean glinki_local_channel_exists
(
  glink_transport_if_type *if_ptr,
  glink_transport_if_type **present_if_ptr,  
  const char               *name,
  glink_channel_ctx_type  **present_ch_ctx,
  boolean                 is_local_channel  
);

/** 
 * This function sets flag for channel context to represent
 * that channel is tagged for deletion. This is to cover corner 
 * case where local side might close the channel but channel 
 * context still sticks around and might be found again for
 * xport negotiation.
 *
 * @param[in]    if_ptr  transport on which channel is opened
 * @param[in]    name    name of the channel
 * @param[in]    prio    priority of negotiated xport. all channels on
 *	                     xports other than xport with this prio will be 
 *		                 tagged for deletion
 *
 * @return       NONE
 *
 * @sideeffects  NONE
 */
void glinki_tag_ch_for_deletion
(
  glink_transport_if_type *if_ptr,
  const char              *name,
  glink_xport_priority    prio  
);

#endif /* GLINK_CHANNEL_MIGRATION_H */
