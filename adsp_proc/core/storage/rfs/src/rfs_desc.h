/***********************************************************************
 * rfs_desc.h
 *
 * File descriptor management for rfs
 *
 * Copyright (c) 2014 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 * File descriptor management for rfs
 *
 ***********************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/core.qdsp6/1.0.c2/storage/rfs/src/rfs_desc.h#1 $ $DateTime: 2020/02/10 01:57:30 $ $Author: pwbldsvc $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2014-10-15   dks   Create

===========================================================================*/

#ifndef __RFS_DESC_H__
#define __RFS_DESC_H__

#include "rfs_config_i.h"

void rfs_desc_init (void);

int rfs_desc_allocate_fd (const char *path, int oflag);

int rfs_desc_free_fd (int fd);

int rfs_desc_lookup_fd (int fd, char *fname, uint32 fname_len,
                        int *oflag, uint32 *offset);

int rfs_desc_update_offset (int fd, uint32 offset);

#endif /* not __RFS_DESC_H__ */
