#include "qmi_client.h"
#include "sns_usmr.h"
#include "sns_usmr_priv.h"

/*===========================================================================
  FUNCTION  qmi_client_send_msg_async
===========================================================================*/
/*!
@brief
  Sends an asynchronous QMI service message on the specified connection.
  The callback functi is expected to encode the message before sending it
  through this function.

@param[in]   user_handle        Handle used by the infrastructure to
@param[in]   msg_id             Message ID
@param[in]   req_c_struct       Pointer to the request
@param[in]   req_c_struct_len   Length of the request
@param[in]   resp_c_struct      Pointer to where the response will be stored
@param[in]   resp_c_struct_len  Length of the response buffer
@param[in]   resp_cb            Callback function to handle the response
@param[in]   resp_cb_data       Cablback user-data
@param[out]  txn_handle         Handle used to identify the transaction


@return
  QMI_NO_ERR and sets the transaction handle if function is successful,
  error code otherwise.
  QMI_SERVICE_ERR if server cannot be reached

@note

  - Dependencies
    - User must maintain the validity of the resp_c_struct throughout the
      lifetime of the txn_handle (Till the response is received or the
      transaction is cancelled).

  - Side Effects
*/
/*=========================================================================*/

qmi_client_error_type
qmi_client_send_msg_async
(
 qmi_client_type                 user_handle,
 unsigned int                    msg_id,
 void                            *req_c_struct,
 unsigned int                    req_c_struct_len,
 void                            *resp_c_struct,
 unsigned int                    resp_c_struct_len,
 qmi_client_recv_msg_async_cb    resp_cb,
 void                            *resp_cb_data,
 qmi_txn_handle                  *txn_handle
)
{
  // Offline Playback Stub
  return QMI_INTERNAL_ERR;
}

/*===========================================================================
  FUNCTION  qmi_client_release_async
===========================================================================*/
/*!
@brief
  Releases the connection to a service and return immediately without blocking.
  the provided callback is called when the connection is fully released and
  it is safe for the caller to release any associated resources.

@param[in]   user_handle        Handle used by the infrastructure to
@param[in]   release_cb         Callback to call when the connection is
                                fully released.
@param[in]   release_cb_data    Cookie to be provided with the callback.

@return
  QMI_NO_ERR if function is successful, error code otherwise.

@note

  - Dependencies
    - None

  - Side Effects
   - None
*/
/*=========================================================================*/
qmi_client_error_type
qmi_client_release_async
(
 qmi_client_type       user_handle,
 qmi_client_release_cb release_cb,
 void                  *release_cb_data
)
{
  // Offline Playback Stub
  return QMI_INTERNAL_ERR;
}

/*===========================================================================
  FUNCTION  qmi_client_message_decode
===========================================================================*/
/*!
@brief
  Decodes the body (TLV's) of a QMI message body from the wire format to the
  C structure.

@param[in]  user_handle   opaque  handle
                          object accessor function from service header file.
@param[in]  message_type  The type of message: request, response, or indication.
@param[in]  message_id    Message ID from IDL.
@param[in]  p_src         Pointer to beginning of first TLV in message.
@param[in]  src_len       Length of p_src buffer in bytes.
@param[out] p_dst         Pointer to C structure for decoded data
@param[in]  dst_len       Length (size) of p_dst C structure in bytes.

@retval    QMI_NO_ERR     Success
@retval    QMI_IDL_...    Error, see error codes defined in qmi.h
*/
/*=========================================================================*/
qmi_client_error_type
qmi_client_message_decode
(
 qmi_client_type                         user_handle,
 qmi_idl_type_of_message_type            req_resp_ind,
 unsigned int                            message_id,
 const void                              *p_src,
 unsigned int                            src_len,
 void                                    *p_dst,
 unsigned int                            dst_len
)
{
  // Offline Playback Stub
  return QMI_INTERNAL_ERR;
}

/*===========================================================================
  FUNCTION  qmi_client_get_service_instance
===========================================================================*/
/*!
@brief
   Retrieves a service with a specific instance ID capable of handling the
   service object

@return
   QMI_NO_ERR if function is successful, error code otherwise.

@param[in]      service_obj         Service object
@param[in]      instance_id         Instance ID of the service
                                    Use QMI_CLIENT_INSTANCE_ANY to mention
                                    no preference.
@param[out]     service_info        Service information

@note

  - Dependencies
    - None

  - Side Effects
   - service_info may be written
*/
/*=========================================================================*/
qmi_client_error_type
qmi_client_get_service_instance
(
 qmi_idl_service_object_type service_obj,
 qmi_service_instance instance_id,
 qmi_service_info *service_info
)
{
  // Offline Playback Stub
//  return QMI_INTERNAL_ERR;
  return (smr_find_service(service_obj, instance_id) >= 0) ? QMI_NO_ERR : QMI_SERVICE_ERR;
}

/*===========================================================================
  FUNCTION  qmi_client_register_error_cb
===========================================================================*/
/*!
@brief
  Register an service error callback with the user handle (Valid operation
  for connected client handles returned by qmi_client_init only).

@param[in]  user_handle   opaque handle returned by qmi_client_init
@param[in]  err_cb        Pointer to callback function
@param[in]  err_cb_data   User-data

@retval  QMI_NO_ERR       Success
         QMI_SERVICE_ERR  Server has gone down and the callback is invoked
         QMI_CLIENT_TRANSPORT_ERR Non-recoverable error in the transport
         QMI_INTERNAL_ERR Invalid input parameters
*/
/*=========================================================================*/
qmi_client_error_type qmi_client_register_error_cb
(
 qmi_client_type user_handle,
 qmi_client_error_cb err_cb,
 void *err_cb_data
)
{
  // Offline Playback Stub
  return QMI_INTERNAL_ERR;
}

/*===========================================================================
  FUNCTION  qmi_client_init_instance
===========================================================================*/
/*!
@brief
  Helper blocking function to lookup and initialize a connection with a
  service with a specific instance ID.

@param[in]   service_obj        Service object
@param[in]   instance_id        Instance ID of the service.
                                Use QMI_CLIENT_INSTANCE_ANY if there is
                                no preference on the instance ID.
@param[in]   ind_cb             Indication callback function
@param[in]   ind_cb_data        Indication callback user-data
@param[in]   os_params          OS-specific parameters. It can be a pointer
                                to event object, or signal mask and TCB
@param[in]   timeout            Time-out in milliseconds. 0 = no timeout
@param[out]  user_handle        Handle used by the infrastructure to
                                identify different clients.

@retval  QMI_NO_ERR       Success
         QMI_INTERNAL_ERR Invalid input parameters
         QMI_TIMEOUT_ERR  No service of the required instance_id was found
                          in the time provided by timeout.

@notes
 1. This function internally calls qmi_client_get_service_list() and
    qmi_client_init() and may also create a notifier client in case
    the service is not already up.

 2. If a service of the required instance ID is not found, the function may
    block for a time longer than 'timeout' before returning QMI_TIMEOUT_ERR.

 3. If the client does not know the instance ID but still does not want
    to connect with the first instance of the service (QMI_CLIENT_INSTANCE_ANY)
    then it should use qmi_client_get_service_list() and qmi_client_init()
    with the notifier client instead of this helper.

*/
/*=========================================================================*/
qmi_client_error_type qmi_client_init_instance
(
 qmi_idl_service_object_type service_obj,
 qmi_service_instance        instance_id,
 qmi_client_ind_cb           ind_cb,
 void                        *ind_cb_data,
 qmi_client_os_params        *os_params,
 uint32_t                    timeout,
 qmi_client_type             *user_handle
)
{
  // Offline Playback Stub
  return QMI_INTERNAL_ERR;
}
