/***********************************************************************
 * rfs_nodev.h
 *
 * RFS Nodev Operations.
 * Copyright (c) 2013-2014 Qualcomm Technologies, Inc.  All Rights Reserved.
 *
 * APIs to hook up stubs for RFS APIs when there is no underlying
 * Filesystem implementation.
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/core.qdsp6/1.0.c2/storage/rfs/src/rfs_nodev.h#1 $ $DateTime: 2020/02/10 01:57:30 $ $Author: pwbldsvc $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2014-12-03   dks   Move rfs init to a task
2013-11-14   dks   Create

===========================================================================*/

#include "rfs_ops.h"

#ifndef __RFS_NODEV_H__
#define __RFS_NODEV_H__

int rfs_nodev_init (struct rfs_ops_type *base_ops);

#endif /* not __RFS_NODEV_H__ */
