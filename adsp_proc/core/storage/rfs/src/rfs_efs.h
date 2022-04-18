/***********************************************************************
 * rfs_efs.h
 *
 * RFS wrapper for EFS
 * Copyright (c) 2013-2014 Qualcomm Technologies, Inc.  All Rights Reserved.
 *
 * APIs to hook up EFS Filesystem under RFS API layer.
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/core.qdsp6/1.0.c2/storage/rfs/src/rfs_efs.h#1 $ $DateTime: 2020/02/10 01:57:30 $ $Author: pwbldsvc $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2014-12-03   dks   Move rfs init to a task
2013-11-14   dks   Create

===========================================================================*/

#ifndef __RFS_EFS_H__
#define __RFS_EFS_H__

#include "rfs_ops.h"

#ifdef FEATURE_RFS_USE_EFS

int rfs_efs_init (struct rfs_ops_type *base_ops);

#endif

#endif /* not __RFS_EFS_H__ */
