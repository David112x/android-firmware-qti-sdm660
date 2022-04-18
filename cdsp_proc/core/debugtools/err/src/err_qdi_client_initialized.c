/*=============================================================================

                err_qdi_client_initialized.c

GENERAL DESCRIPTION
      ERR QDI Client Process Code that goes to island image, if island mode is
      enabled , otherwise goes into main image

EXTERNAL FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS
   None.

Copyright (c) 2015 - 2016 by Qualcomm Technologies, Inc.  All Rights Reserved.

=============================================================================*/

/*=============================================================================

                        EDIT HISTORY FOR MODULE

 This section contains comments describing changes made to the module.
 Notice that changes are listed in reverse chronological order.


$Header: //components/rel/core.qdsp6/1.0.c2/debugtools/err/src/err_qdi_client_initialized.c#1 $ 
$DateTime: 2020/02/10 01:57:30 $ $Author: pwbldsvc $

when       who     what, where, why
--------   ---     ------------------------------------------------------------
08/28/15   din     Adapted from err_qdi_client.c
=============================================================================*/
#include "com_dtypes.h"

boolean err_qdi_client_initialized = FALSE;

/*===========================================================================

FUNCTION    ERR_QDI_CLIENT_IS_INITIALIZED

DESCRIPTION
  Initialize the err client qdi service.

DEPENDENCIES
  None.

RETURN VALUE
  TRUE/FALSE
  
SIDE EFFECTS
  None

===========================================================================*/
boolean err_qdi_client_is_initialized(void) 
{
 
   return err_qdi_client_initialized;

}  /* err_qdi_client_is_initialized */


