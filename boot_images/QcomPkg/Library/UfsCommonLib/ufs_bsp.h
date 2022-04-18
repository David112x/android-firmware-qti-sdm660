#ifndef UFS_BSP_H
#define UFS_BSP_H
 /**********************************************************************
 * ufs_bsp.h
 *
 * UFS driver BSP.
 *
 * Copyright (c) 2008-2016, 2018
 * Qualcomm Technologies Incorporated.
 * All Rights Reserved.
 * Qualcomm Confidential and Proprietary
 *
 **********************************************************************

                             Edit History

$Header: //components/rel/boot.xf/1.4/QcomPkg/Library/UfsCommonLib/ufs_bsp.h#3 $
$DateTime: 2018/10/16 09:22:30 $ $Author: pwbldsvc $

when         who     what, where, why
----------   ---     --------------------------------------------------------------  
2018-10-12   sb      Add reset api support
2016-08-18   jt      Add DAL config  
2015-06-15   rh      Disable the PHY from decoding the LCC sequence
2013-06-20   rh      Initial version.
-----------------------------------------------------------------------------*/

#include "hwio_ufs_v1.h"
#include "ufs_osal.h"

#define UFS_CLOCK_MODE_OFF    0
#define UFS_CLOCK_MODE_ON     1

#define FLUSH                 1
#define INVAL                 2
#define CLEAN                 4

#define SUCCESS               1
#define FAIL                  0

#define MPHY_INIT_BUSY_WAIT   0x00000001

// Data structure used to initialize the UFS phy
struct ufs_mphy_init_item {
   uint32_t reg;
   uint8_t  val;
};

/* Cock busy wait function, unit in uS*/
void ufs_bsp_busy_wait(uint32_t us);

/* Configuration of all clock sources */
void ufs_bsp_clk_set (uint8_t hostid, uint32_t mode);

void ufs_bsp_reset (uint8_t hostid); 
void ufs_bsp_device_reset (uint8_t hostid);

void ufs_bsp_enable_symbol_clk (void);

/* Get the data structure for the UFS PHY init table */
uint32_t ufs_bsp_get_mphy_init_item_table (struct ufs_mphy_init_item **itm);
uint32_t ufs_bsp_get_mphy_init_rate_b_item_table (struct ufs_mphy_init_item **itm);
uint32_t ufs_bsp_mphy_start (uint8_t hostid);
void ufs_bsp_post_link_init (uint8_t hostid);


/* Cache management wrapper */
void ufs_bsp_cache_op (void *addr, uint32_t len, uint32_t op);

/* Basic memory barrier function */
void ufs_bsp_memory_barrier (void);

/* Functions to manage transfer descriptor buffer */
void *ufs_bsp_allocate_xfer_buf (size_t size);
void  ufs_bsp_free_xfer_buf (void *pmem);

/* Map register into accessable memory region */
uintptr_t ufs_bsp_get_reg_baseaddress (uint8_t hostid);

/* Settings on each platform */
struct ufs_bsp_config_item {
   uint8_t     skip_gear_sw;
   uint8_t     slow_xfer;
   uint8_t     skip_link_start;
   uint8_t     core_skip; 
};

/* DAL config settings */
struct ufs_dal_config_item {
   uint8_t     enable_hs;
   uint8_t     gear;
   uint8_t     num_lanes;
};

void ufs_bsp_get_platform_config (struct ufs_bsp_config_item *itm);
boolean ufs_bsp_get_dal_config(struct ufs_dal_config_item *itm); 

#endif /* #ifndef UFS_BSP_H */

