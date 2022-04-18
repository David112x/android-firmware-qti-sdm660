/*===========================================================================

            GLink SSR Configuration Structures

=============================================================================

  @file
    glink_ssr_devcfg_<proc>.c

    Contains structures to be used in Glink SSR configuration.

  Copyright (c) 2016 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Qualcomm Technologies, Inc. Confidential and Proprietary.
===========================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE


when       who     what, where, why
--------   ---     ----------------------------------------------------------
05/13/15   db      Initial version
===========================================================================*/

/*===========================================================================
                        INCLUDE FILES
===========================================================================*/
#include "DALStdDef.h"
#include "glink_ssr_config.h"

/*===========================================================================
                           MACRO DEFINITIONS
===========================================================================*/


/*===========================================================================
                        DATA DECLARATIONS
===========================================================================*/
const glink_ssr_config_type glink_ssr_devcfg_config = 
{
  "dsps",              /* Local host name  */
  "apss",              /* Master host name */
  "glink_ssr",         /* SSR channel name */
  "SMEM"               /* Transport name   */
};

