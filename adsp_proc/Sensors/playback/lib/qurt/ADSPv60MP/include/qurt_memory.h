#ifndef QURT_MEMORY_H
#define QURT_MEMORY_H
/**
  @file qurt_memory.h
  @brief  Prototypes of Kernel memory API functions      

 EXTERNALIZED FUNCTIONS
  none

 INITIALIZATION AND SEQUENCING REQUIREMENTS
  none

 Copyright (c) 2013  by Qualcomm Technologies, Inc.  All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
 ======================================================================*/


#include <qurt_error.h>
#include <qurt_types.h>
//#include <qurt_util_macros.h>

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup memory_management_types
@{ */

extern qurt_mem_pool_t qurt_mem_default_pool;

/** @} */ /* end_addtogroup memory_management_types */
/*=====================================================================
 Functions
======================================================================*/

/**@ingroup func_qurt_mem_cache_clean
  Performs a cache clean operation on the data stored in the specified memory area.

  @note1hang The flush all operation can be performed only on the data cache.

  @datatypes
  #qurt_addr_t \n
  #qurt_size_t \n
  #qurt_mem_cache_op_t \n
  #qurt_mem_cache_type_t

  @param[in] addr      Address of data to be flushed.
  @param[in]  size     Size (in bytes) of data to be flushed.
  @param[in] opcode    Type of cache clean operation: \n QURT_MEM_CACHE_FLUSH,\n QURT_MEM_CACHE_INVALIDATE,\n 
                       QURT_MEM_CACHE_FLUSH_INVALIDATE,\n QURT_MEM_CACHE_FLUSH_ALL.\n
                       @note1 QURT_MEM_CACHE_FLUSH_ALL is valid only when the type is QURT_MEM_DCACHE
  @param type          Cache type: QURT_MEM_ICACHE, QURT_MEM_DCACHE.
 
  @return
  QURT_EOK -- Cache operation performed successfully.\n
  QURT_EVAL -- Invalid cache type.\n
  QURT_EALIGN -- Aligning data or address failed.\n
  
  @dependencies
  None.
*/
int qurt_mem_cache_clean(qurt_addr_t addr, qurt_size_t size, qurt_mem_cache_op_t opcode, qurt_mem_cache_type_t type);

/**@ingroup func_qurt_mem_l2cache_line_lock 
  Performs an L2 cache line locking operation. This function locks selective lines in the L2 cache memory.

  @note1hang The line lock operation can be performed only on the 32-byte aligned size and address.

  @datatypes
  #qurt_addr_t \n
  #qurt_size_t 
 
  @param[in] addr   Address of the L2 cache memory line to be locked; the address must be 32-byte aligned.
  @param[in] size   Size (in bytes) of L2 cache memory to be line locked. Size must be a multiple of 32 bytes.
 
  @return
  QURT_EOK -- Success.\n
  QURT_EALIGN -- Aligning data or address failure.\n

  @dependencies
  None.
*/
int qurt_mem_l2cache_line_lock (qurt_addr_t addr, qurt_size_t size);

/**@ingroup func_qurt_mem_l2cache_line_unlock 
  Performs an L2 cache line unlocking operation. This function unlocks selective lines in the L2 cache memory.

  @note1hang The line unlock operation can be performed only on a 32-byte aligned size and address.

  @datatypes
  #qurt_addr_t \n
  #qurt_size_t 
 
  @param[in] addr   Address of the L2 cache memory line to be locked; the address must be 32-byte aligned.
  @param[in] size   Size (in bytes) of the L2 cache memory to be line ulocked; size must be a multiple of 32 bytes.
 
  @return
  QURT_EOK -- Success. \n
  QURT_EALIGN -- Aligning data or address failure. \n
  QURT_EFAILED -- Operation failed, cannot find the matching tag.

  @dependencies
  None.
*/
int qurt_mem_l2cache_line_unlock(qurt_addr_t addr, qurt_size_t size);

/**@ingroup func_qurt_mem_region_attr_init
  @xreflabel{sec:qurt_mem_region_attr_init} 
  Initializes the specified memory region attribute structure with default attribute values: \n
  - Mapping -- QURT_MEM_MAPPING_VIRTUAL \n
  - Cache mode -- QURT_MEM_CACHE_WRITEBACK \n
  - Physical address -- -1 \n
  - Virtual address -- -1 \n
  - Memory type -- QURT_MEM_REGION_LOCAL \n
  - Size -- -1 

    @note1hang The memory physical address attribute must be explicitly set by calling the
             qmmem_attr_set_physaddr() function. The size and pool attributes are set directly 
			 as parameters in the memory region create operation.

  @datatypes
  #qurt_mem_region_attr_t

  @param[in,out] attr  Pointer to the destination structure for the memory region attributes.

  @return
  None.

  @dependencies
  None.
 */
void qurt_mem_region_attr_init(qurt_mem_region_attr_t *attr);

/**@ingroup func_qurt_mem_pool_attach 
  Initializes a memory pool object to be attached to a pool predefined in the system
  configuration file.

  Memory pool objects are used to assign memory regions to physical memory in different
  Hexagon memory units. They are specified in memory region create operations
  (Section @xref{sec:mem_region_create}).

  @note1hang QuRT predefines the memory pool object qurt_mem_default_pool
             (Section @xref{dox:mem_management}) for allocation memory regions in SMI memory. The pool attach
             operation is necessary only when allocating memory regions in nonstandard
             memory units such as TCM.
 
  @datatypes
  #qurt_mem_pool_t

  @param[in] name   Pointer to the memory pool name. 
  @param[out] pool  Pointer to the memory pool object.

  @return
  QURT_EOK -- Attach operation successful.

  @dependencies
  None.
*/
int qurt_mem_pool_attach(char *name, qurt_mem_pool_t *pool);

/**@ingroup func_qurt_mem_pool_create
   Dynamically creates a new memory pool object.

   The pool is assigned a single memory region with the specified base address and size.

   The base address and size values passed to this function must be aligned to 4K byte
   boundaries, and must be expressed as the actual base address and size values divided by 4K.

   For example, the function call: 
         @code
         qurt_mem_pool_create ("TCM_PHYSPOOL", 0xd8020, 0x20, &pool)
		 @endcode
   ... is equivalent to the following static pool definition in the QuRT system configuration file:
        @code
       <physical_pool name="TCM_PHYSPOOL">
            <region base="0xd8020000" size="0x20000" />
       </physical_pool>
	   @endcode

   For more information on the system configuration file refer to @xhyperref{Q2,[Q2]}.

   @note1hang Dynamically created pools are not identical to static pools. In particular, 
   qurt_mem_pool_attr_get() is not valid with dynamically created pools.

   @note1hang Dynamic pool creation permanently consumes system resources, and cannot be undone.

  @datatypes
  #qurt_mem_pool_t

  @param[in] name           Pointer to the memory pool name. 
  @param[in] base           Base address of the memory region (divided by 4K).
  @param[in] size           Size (in bytes) of the memory region (divided by 4K).
  @param[out] pool          Pointer to the memory pool object.

  @return
  QURT_EOK -- Success.

  @dependencies
  None.
*/
int qurt_mem_pool_create(char *name, unsigned base, unsigned size, qurt_mem_pool_t *pool);

/**@ingroup func_qurt_mem_pool_add_pages
  Add a physical address range to an existing memory pool object.
  Only allowed to be called with root privileges (guest-OS mode).

  @datatypes
  #qurt_mem_pool_t

  @param[in] pool           The memory pool handle.
  @param[in] first_pageno   First page number of the range (address >> 12)
  @param[in] size_in_pages  Number of pages in the range (size >> 12)

  @return
  QURT_EOK -- The pages were successfully added.

  @dependencies
  None.
*/
int qurt_mem_pool_add_pages(qurt_mem_pool_t pool,
                            unsigned first_pageno,
                            unsigned size_in_pages);

/**@ingroup func_qurt_mem_pool_remove_pages
  Remove a physical address range from an existing memory pool object.
  Only allowed to be called with root privileges (guest-OS mode).
  In the future, this will support more mechanisms (through flags)
  for dealing with the situation where part of the area to be removed
  is currently in use.  For now, if any part of the area to be removed
  is in use, the API will return an error without changing the state.

  @datatypes
  #qurt_mem_pool_t

  @param[in] pool           The memory pool handle.
  @param[in] first_pageno   First page number of the range (address >> 12)
  @param[in] size_in_pages  Number of pages in the range (size >> 12)
  @param[in] flags          Flags controlling how to handle portions of the
                            range which are either not in the pool or which
                            are currently in use.  More flags will be added
                            in the future.  Pass 0 for default behavior.

                            Flags defined include:

                            QURT_POOL_REMOVE_ALL_OR_NONE -- only proceed
                              with the API if the entire range specified
                              is contained in the pool's free space with
                              no holes.  (Default behavior is that holes
                              in the range which are not part of the pool
                              are silently skipped.)
  @param[in] callback       A callback function to be called when the
                            removal is complete.  Only called if the
                            operation is completed; if the API returns
                            an error, the function is not called. A
                            value of 0 can be passed to skip the callback.
  @param[in] arg            The argument to be passed to the callback
                            function when the operation is complete.

  @return
  QURT_EOK -- The pages were successfully removed.

  @dependencies
  None.
*/
int qurt_mem_pool_remove_pages(qurt_mem_pool_t pool,
                               unsigned first_pageno,
                               unsigned size_in_pages,
                               unsigned flags,
                               void (*callback)(void *),
                               void *arg);

#define QURT_POOL_REMOVE_ALL_OR_NONE            1

/**@ingroup func_qurt_mem_pool_attr_get  
   Gets the memory pool attributes. \n
   Retrieves pool configurations based on the pool handle, and fills in
   the attribute structure with configuration values.   

   @datatypes
   #qurt_mem_pool_t \n
   #qurt_mem_pool_attr_t

   @param[in]  pool   Pool handle obtained from pool_attach.
   @param[out] attr   Pointer to the memory region attribute structure. 

   @return   
   0 -- Success. \n
   QURT_EINVALID -- Corrupt handle; pool handle is invalid.
*/
int qurt_mem_pool_attr_get (qurt_mem_pool_t pool, qurt_mem_pool_attr_t *attr);

/**@ingroup func_qurt_mem_pool_attr_get_size
  Gets the size of the specified memory pool range.

  @datatypes
  #qurt_mem_pool_attr_t \n
  #qurt_size_t
 
  @param[in] attr      Pointer to the memory pool attribute structure.
  @param[in]  range_id   Memory pool range key.
  @param[out] size     Pointe to the destination variable for the range size.

  @return 
  0 -- Success. \n
  QURT_EINVALID -- Range is invalid.

  @dependencies
  None.
*/
static inline int qurt_mem_pool_attr_get_size (qurt_mem_pool_attr_t *attr, int range_id, qurt_size_t *size){
    if ((range_id >= MAX_POOL_RANGES) || (range_id < 0)){
        (*size) = 0;
        return QURT_EINVALID;
    }
    else {
        (*size) = attr->ranges[range_id].size; 
    }
    return QURT_EOK;
}

/**@ingroup func_qurt_mem_pool_attr_get_addr
   Gets the start address of the specified memory pool range.
 
  @datatypes
  #qurt_mem_pool_attr_t \n
  #qurt_addr_t
  
  @param[in] attr        Pointer to the memory pool attribute structure.
  @param[in]  range_id   Memory pool range key.
  @param[out] addr       Pointer to the destination variable for range start address.

  @return 
  0 -- Success. \n
  QURT_EINVALID -- Range is invalid.

  @dependencies
  None.
*/
static inline int qurt_mem_pool_attr_get_addr (qurt_mem_pool_attr_t *attr, int range_id, qurt_addr_t *addr){
    if ((range_id >= MAX_POOL_RANGES) || (range_id < 0)){
        (*addr) = 0;
        return QURT_EINVALID;
    }
    else {
        (*addr) = (attr->ranges[range_id].start)<<12;
   }
   return QURT_EOK;
}



/**@ingroup func_qurt_mem_region_create
  @xreflabel{sec:mem_region_create}
  Creates a memory region with the specified attributes.

  The memory region attribute structure is initialized by the application with
  qurt_mem_region_attr_init() and qurt_mem_region_attr_setattribute().

  If the virtual address attribute is set to its default value 
  (Section @xref{sec:qurt_mem_region_attr_init}), the memory region's virtual address is 
  automatically assigned any available virtual address value.

  If the memory mapping attribute is set to virtual mapping, the memory region's physical
  address is also automatically assigned.\n

  @note1hang The physical address attribute is explicitly set in the attribute structure only
             for memory regions with physical-contiguous-mapped mapping.

  Memory regions are always assigned to memory pools. The pool value specifies the memory pool
  that the memory region is assigned to.

  @note1hang If attr is specified as NULL, the memory region is created with default
             attribute values (Section @xref{sec:qurt_mem_region_attr_init}).
             QuRT predefines the memory pool object qurt_mem_default_pool
             (Section @xref{dox:mem_management}) which allocates memory regions in SMI memory.

  @datatypes
  #qurt_mem_region_t \n
  #qurt_size_t \n
  #qurt_mem_pool_t \n
  qurt_mem_region_attr_t

  @param[out] region Pointer to the memory region object.
  @param[in]  size   Memory region size (in bytes). If size is not an integral multiple of 4K,
                     it is rounded up to a 4K boundary.
  @param[in]  pool   Memory pool of the region.
  @param[in]  attr   Pointer to the memory region attribute structure.

  @return
  QURT_EOK -- Memory region successfully created.\n
  QURT_EMEM -- Not enough memory to create region.

  @dependencies
  None.
*/
int qurt_mem_region_create(qurt_mem_region_t *region, qurt_size_t size, qurt_mem_pool_t pool, qurt_mem_region_attr_t *attr);

/**@ingroup func_qurt_mem_region_delete
  Deletes the specified memory region.

  If the memory region was created by the caller application, it is removed and its
  assigned memory reclaimed by the system.

  If the memory region was created by a different application (and shared with the caller
  application), then only the local memory mapping to the region is removed; the memory
  itself is not reclaimed by the system.

  @datatypes
  #qurt_mem_region_t

  @param[in] region Memory region object.

  @returns
  QURT_EOK -- Region successfully deleted.

  @dependencies
  None.
*/
int qurt_mem_region_delete(qurt_mem_region_t region);


/**@ingroup func_qurt_mem_region_attr_get
  @xreflabel{sec:mem_region_attr_get}
  Gets the memory attributes of the specified message region.
  After a memory region is created, its attributes cannot be changed.

  @datatypes
  #qurt_mem_region_t \n
  #qurt_mem_region_attr_t

  @param[in] region     Memory region object.
  @param[out] attr      Pointer to the destination structure for memory region attributes.

  @return
  QURT_EOK -- Operation successfully performed. \n
  Error code -- Failure.

  @dependencies
  None.
*/
int qurt_mem_region_attr_get(qurt_mem_region_t region, qurt_mem_region_attr_t *attr);


/**@ingroup func_qurt_mem_region_attr_set_type
  Sets the memory type in the specified memory region attribute structure.

  The type indicates whether the memory region is local to an application or shared between
  applications. 
  For more information, see @xhyperref{Q3,[Q3]}. 
 
  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_mem_region_type_t

  @param[in,out] attr  Pointer to memory region attribute structure.
  @param[in]     type  Memory type. Values: \n
                       - QURT_MEM_REGION_LOCAL \n
                       - QURT_MEM_REGION_SHARED @tablebulletend
  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_set_type(qurt_mem_region_attr_t *attr, qurt_mem_region_type_t type){
    attr->type = type;
}

/**@ingroup func_qurt_mem_region_attr_get_size
  Gets the memory region size from the specified memory region attribute structure.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_size_t

  @param[in]  attr  Pointer to the memory region attribute structure.
  @param[out] size  Pointer to the destination variable for memory region size.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_size(qurt_mem_region_attr_t *attr, qurt_size_t *size){
    (*size) = attr->size;
}

/**@ingroup func_qurt_mem_region_attr_get_type
  Gets the memory type from the specified memory region attribute structure.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_mem_region_type_t

  @param[in] attr  Pointer to the memory region attribute structure.
  @param[out] type  Pointer to the destination variable for the memory type.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_type(qurt_mem_region_attr_t *attr, qurt_mem_region_type_t *type){
    (*type) = attr->type;
}

/**@ingroup func_qurt_mem_region_attr_set_physaddr
  Sets the memory region 32-bit physical address in the specified memory attribute structure.

  @note1hang The physical address attribute is explicitly set only for memory regions with
             physical-contiguous-mapped mapping. Otherwise it is automatically set by
             QuRT when the memory region is created.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_paddr_t

  @param[in,out] attr  Pointer to the memory region attribute structure.
  @param[in] addr  Memory region physical address.

  @return      
  None.
 */
static inline void qurt_mem_region_attr_set_physaddr(qurt_mem_region_attr_t *attr, qurt_paddr_t addr){
    attr->ppn = (unsigned)(((unsigned)(addr))>>12);
}

/**@ingroup func_qurt_mem_region_attr_get_physaddr
  Gets the memory region physical address from the specified memory region attribute structure.
  
  @datatypes
  #qurt_mem_region_attr_t
  
  @param[in]  attr  Pointer to the memory region attribute structure.
  @param[out] addr  Pointer to the destination variable for memory region physical address.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_physaddr(qurt_mem_region_attr_t *attr, unsigned int *addr){
    (*addr) = (unsigned)(((unsigned) (attr->ppn))<<12);
}

/**@ingroup func_qurt_mem_region_attr_set_virtaddr
  Sets the memory region virtual address in the specified memory attribute structure.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_addr_t
  
  @param[in,out] attr  Pointer to the memory region attribute structure.
  @param[in]     addr  Memory region virtual address.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_set_virtaddr(qurt_mem_region_attr_t *attr, qurt_addr_t addr){
    attr->virtaddr = addr;
}

/**@ingroup func_qurt_mem_region_attr_get_virtaddr
  Gets the memory region virtual address from the specified memory region attribute structure.

  @datatypes
  #qurt_mem_region_attr_t \n

  @param[in]   attr   Pointer to the memory region attribute structure.
  @param[out]  addr   Pointer to the destination variable for the memory region virtual address.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_virtaddr(qurt_mem_region_attr_t *attr, unsigned int *addr){
    (*addr) = (unsigned int)(attr->virtaddr);
}

/**@ingroup func_qurt_mem_region_attr_set_mapping
  Sets the memory mapping in the specified memory region attribute structure.

  The mapping value indicates how the memory region is mapped in virtual memory:\n  
  - QURT_MEM_MAPPING_VIRTUAL -- The region virtual address space is mapped to
     noncontiguous areas of physical memory. This makes the most efficient use of
     virtual memory, and works for most memory use cases.\n
  - QURT_MEM_MAPPING_PHYS_CONTIGUOUS -- The region virtual address space must
     be mapped to a contiguous area of physical memory. This is necessary when the
     memory region is accessed by external devices which bypass Hexagon
     virtual memory addressing.\n
  - QURT_MEM_MAPPING_IDEMPOTENT -- The region virtual address space is mapped
     to the identical area of physical memory. \n 
  - QURT_MEM_MAPPING_NONE -- No address mapping is performed. \n
  - QURT_MEM_MAPPING_VIRTUAL_FIXED_ADDR -- Equivalent to QURT_MEM_
     MAPPING_VIRTUAL except that the virtual address space is mapped to the
     specified virtual memory address. The mapping can be performed to contiguous
     or non-contiguous address ranges.
  - QURT_MEM_MAPPING_VIRTUAL_FIXED -- The region virtual address space is
     mapped either to the specified area of physical memory or (if no area is specified)
     to any available physical memory. This mapping is used to create regions from
     virtual space that was reserved by calling qurt_mem_region_create with
     mapping QURT_MEM_MEM_MAPPING_NONE. Remapping a virtual range is not
     permitted without first deleting the memory region. When such a region is
     deleted, its corresponding virtual memory addressing remains intact. \n
   

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_mem_mapping_t
  
  @param[in,out] attr     Pointer to the memory region attribute structure.
  @param[in] mapping  Mapping. Values: \n
                      QURT_MEM_MAPPING_VIRTUAL, \n
                      QURT_MEM_MAPPING_PHYS_CONTIGUOUS, \n
                      QURT_MEM_MAPPING_IDEMPOTENT, \n
                      QURT_MEM_MAPPING_VIRTUAL_FIXED, \n
                      QURT_MEM_MAPPING_NONE, \n
                      QURT_MEM_MAPPING_VIRTUAL_FIXED_ADDR.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_set_mapping(qurt_mem_region_attr_t *attr, qurt_mem_mapping_t mapping){
    attr->mapping_type = mapping;
}

/**@ingroup func_qurt_mem_region_attr_get_mapping
  Gets the memory mapping from the specified memory region attribute structure.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_mem_mapping_t

  @param[in]  attr     Pointer to the memory region attribute structure.
  @param[out] mapping  Pointer to the destination variable for memory mapping.

  @return 
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_mapping(qurt_mem_region_attr_t *attr, qurt_mem_mapping_t *mapping){
    (*mapping) = attr->mapping_type;
}

/**@ingroup func_qurt_mem_region_attr_set_cache_mode
  Sets the cache operation mode in the specified memory region attribute structure.

  For more information on the cache, see @xhyperref{Q3,[Q3]}.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_mem_cache_mode_t
  
  @param[in,out] attr  Pointer to the memory region attribute structure.
  @param[in] mode      Cache mode. Values:  \n
                    QURT_MEM_CACHE_WRITEBACK, \n
                    QURT_MEM_CACHE_WRITETHROUGH,\n
                    QURT_MEM_CACHE_WRITEBACK_ NONL2CACHEABLE,\n
                    QURT_MEM_CACHE_WRITETHROUGH_ NONL2CACHEABLE,\n
                    QURT_MEM_CACHE_WRITEBACK_L2CACHEABLE,\n
                    QURT_MEM_CACHE_WRITETHROUGH_ L2CACHEABLE,\n
                    QURT_MEM_CACHE_NONE.
  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_set_cache_mode(qurt_mem_region_attr_t *attr, qurt_mem_cache_mode_t mode){
    QURT_PGATTR_C_SET(attr->pga, (unsigned)mode);
}

/**@ingroup func_qurt_mem_region_attr_get_cache_mode
  Gets the cache operation mode from the specified memory region attribute structure.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_mem_cache_mode_t

  @param[in]  attr  Pointer to the memory region attribute structure.
  @param[out] mode  Pointer to the destination variable for cache mode.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_cache_mode(qurt_mem_region_attr_t *attr, qurt_mem_cache_mode_t *mode){
    (*mode) = (qurt_mem_cache_mode_t)QURT_PGATTR_C_GET(attr->pga);
}

/**@ingroup func_qurt_mem_region_attr_set_bus_attr
  Sets the (A1, A0) bus attribute bits in the specified memory region attribute structure.

  For more information on the bus attribute bits, see @xhyperref{Q3,[Q3]}.

  @datatypes
  #qurt_mem_region_attr_t

  @param[in,out] attr  Pointer to the memory region attribute structure.
  @param[in] abits     The (A1, A0) bits to be used with the memory region, expressed as a 2-bit binary number.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_set_bus_attr(qurt_mem_region_attr_t *attr, unsigned abits){
    QURT_PGATTR_A_SET(attr->pga, abits);
}

/**@ingroup func_qurt_mem_region_attr_get_bus_attr
  Gets the (A1, A0) bus attribute bits from the specified memory region attribute structure.

  @datatypes
  #qurt_mem_region_attr_t 

  @param[in]  attr  Pointer to the memory region attribute structure.
  @param[out] pbits Pointer to an unsigned integer which is filled in with
                    the (A1, A0) bits from the memory region attribute structure, expressed as a 2-bit binary number.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_bus_attr(qurt_mem_region_attr_t *attr, unsigned *pbits){
    (*pbits) = QURT_PGATTR_A_GET(attr->pga);
}

void qurt_mem_region_attr_set_owner(qurt_mem_region_attr_t *attr, int handle);
void qurt_mem_region_attr_get_owner(qurt_mem_region_attr_t *attr, int *p_handle);
void qurt_mem_region_attr_set_perms(qurt_mem_region_attr_t *attr, unsigned perms);
void qurt_mem_region_attr_get_perms(qurt_mem_region_attr_t *attr, unsigned *p_perms);

/**@ingroup func_qurt_mem_map_static_query
  Determines if a memory page is statically mapped.
  Pages are specified by the following attributes: physical address, page size, cache mode,
  and memory permissions: \n
  - If the specified page is statically mapped, vaddr returns the page's virtual
     address. \n
  - If the page is not statically mapped (or if it does not exist as specified), vaddr
     returns -1 as the virtual address value.\n
  QuRT memory maps are defined in the system configuration file.
 
  @datatypes
  #qurt_addr_t \n
  #qurt_mem_cache_mode_t \n
  #qurt_perm_t
  
  @param[out]  vaddr             Virtual address corresponding to paddr.
  @param[in]   paddr             Physical address.  
  @param[in]   page_size         Size of the mapped memory page.
  @param[in]   cache_attribs     Cache mode (writeback, etc.).
  @param[in]   perm              Access permissions.

  @return
  QURT_EOK -- Specified page is statically mapped, virtual address is returned in vaddr. \n
  QURT_EMEM -- Specified page is not statically mapped, -1 is returned in vaddr. \n
  QURT_EVAL -- Specified page does not exist.

  @dependencies
  None.
 */
int qurt_mem_map_static_query(qurt_addr_t *vaddr, qurt_addr_t paddr, unsigned int page_size, qurt_mem_cache_mode_t cache_attribs, qurt_perm_t perm);


/**@ingroup func_qurt_mem_region_query
  Queries a memory region. \n
  This function determines whether a dynamically-created memory region (Section @xref{sec:mem_region_create}) exists for the
  specified virtual or physical address.  
  Once a memory region has been determined to exist, its attributes can be
  accessed (Section @xref{sec:mem_region_attr_get}).

  @note1hang This function returns QURT_EFATAL if QURT_EINVALID is passed to both
             vaddr and paddr (or to neither). 

  @datatypes
  #qurt_mem_region_t \n
  #qurt_paddr_t 
   
  @param[out] region_handle    Pointer to the memory region object (if it exists).
  @param[in]  vaddr            Virtual address to query; if vaddr is specified, paddr must be set to
                               the value QURT_EINVALID.
  @param[in]  paddr            Physical address to query; if paddr is specified, vaddr must be set to
                               the value QURT_EINVALID.

  @return 
  QURT_EOK -- Query successfully performed. \n
  QURT_EMEM -- Region not found for the specified address. \n
  QURT_EFATAL -- Invalid input parameters.

  @dependencies
  None.
 */
int qurt_mem_region_query(qurt_mem_region_t *region_handle, qurt_addr_t vaddr, qurt_paddr_t paddr);


/**@ingroup func_qurt_mapping_create
  Creates a new memory mapping in the page table.

  @datatypes
  #qurt_addr_t \n
  #qurt_size_t \n
  #qurt_mem_cache_mode_t \n
  #qurt_perm_t
 
  @param vaddr			Virtual address.
  @param paddr			Physical address.
  @param size			Size (4K-aligned) of the mapped memory page.
  @param cache_attribs		Cache mode (writeback, etc.).
  @param perm			Access permissions.

  @return			
  QURT_EOK -- Mapping created. \n
  QURT_EMEM -- Failed to create mapping. 	

  @dependencies
  None.
*/
int qurt_mapping_create(qurt_addr_t vaddr, qurt_addr_t paddr, qurt_size_t size,
                         qurt_mem_cache_mode_t cache_attribs, qurt_perm_t perm);

/**@ingroup func_qurt_mapping_remove
  Deletes the specified memory mapping from the page table.
 
  @datatypes
  #qurt_addr_t \n
  #qurt_size_t

  @param[in] vaddr			Virtual address.
  @param[in] paddr			Physical address.
  @param[in] size			Size of the mapped memory page (4K-aligned).

  @return 			
  QURT_EOK -- Mapping created successfully.

  @dependencies
  None.
  		
 */ 		
int qurt_mapping_remove(qurt_addr_t vaddr, qurt_addr_t paddr, qurt_size_t size);

/**@ingroup func_qurt_lookup_physaddr
  Translates a virtual memory address to the physical memory address it is mapped to.

  @datatypes
  #qurt_addr_t
  #qurt_paddr_t

  @param[in] vaddr   Virtual address.

  @return
  Nonzero -- Physical address the virtual address is mapped to.\n
  0 -- Virtual address not mapped.

  @dependencies
  None.
*/
qurt_paddr_t qurt_lookup_physaddr (qurt_addr_t vaddr);

/**@ingroup func_qurt_mem_region_attr_set_physaddr_64
  Sets the memory region 64-bit physical address in the specified memory attribute structure.

  @note1hang The physical address attribute is explicitly set only for memory regions with
             physically contiguous mapping. Otherwise it is automatically set by
             QuRT when the memory region is created.

  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_paddr_64_t

  @param[in,out] attr  Pointer to the memory region attribute structure.
  @param[in] addr_64   Memory region 64-bit physical address.

  @return      
  None.
 */
static inline void qurt_mem_region_attr_set_physaddr_64(qurt_mem_region_attr_t *attr, qurt_paddr_64_t addr_64){
    attr->ppn = (unsigned)(((unsigned long long)(addr_64))>>12);
}

/**@ingroup func_qurt_mem_region_attr_get_physaddr_64
  Gets the memory region 64-bit physical address from the specified memory region attribute structure.
  
  @datatypes
  #qurt_mem_region_attr_t \n
  #qurt_paddr_64_t  
  
  @param[in]  attr     Pointer to the memory region attribute structure.
  @param[out] addr_64  Pointer to the destination variable for the memory region 64-bit physical address.

  @return
  None.

  @dependencies
  None.
 */
static inline void qurt_mem_region_attr_get_physaddr_64(qurt_mem_region_attr_t *attr, qurt_paddr_64_t *addr_64){
    (*addr_64) = (unsigned long long)(((unsigned long long)(attr->ppn))<<12);
}

/**@ingroup func_qurt_mem_map_static_query_64
  Determines if a memory page is statically mapped.
  Pages are specified by the following attributes: 64-bit physical address, page size, cache mode,
  and memory permissions. \n
  If the specified page is statically mapped, vaddr returns the page's virtual
     address. 
  If the page is not statically mapped (or if it does not exist as specified), vaddr
     returns -1 as the virtual address value.\n
  QuRT memory maps are defined in the system configuration file.
 
  @datatypes
  #qurt_addr_t \n
  #qurt_paddr_64_t \n
  #qurt_mem_cache_mode_t \n
  #qurt_perm_t
  
  @param[out]  vaddr             Virtual address corresponding to paddr.
  @param[in]   paddr_64          64-bit physical address.  
  @param[in]   page_size         Size of the mapped memory page.
  @param[in]   cache_attribs     Cache mode (writeback, etc.).
  @param[in]   perm              Access permissions.

  @return
  QURT_EOK -- Specified page is statically mapped, virtual address is returned in vaddr. \n
  QURT_EMEM -- Specified page is not statically mapped, -1 is returned in vaddr. \n
  QURT_EVAL -- Specified page does not exist.

  @dependencies
  None.
 */
int qurt_mem_map_static_query_64(qurt_addr_t *vaddr, qurt_paddr_64_t paddr_64, unsigned int page_size, qurt_mem_cache_mode_t cache_attribs, qurt_perm_t perm);

/**@ingroup func_qurt_mem_region_query_64
  Determines if a dynamically created memory region (Section @xref{sec:mem_region_create}) exists for the
  specified virtual or physical address. Once a memory region has been determined to exist, its attributes can be
  accessed (Section @xref{sec:mem_region_attr_get}).

  @note1hang This function returns QURT_EFATAL if QURT_EINVALID is passed to both
             vaddr and paddr (or to neither).   

  @datatypes
  #qurt_mem_region_t \n
  #qurt_addr_t \n
  #qurt_paddr_64_t 
 
  @param[out] region_handle    Pointer to the memory region object (if it exists).
  @param[in]  vaddr            Virtual address to query; if vaddr is specified, paddr must be set to
                               the value QURT_EINVALID.
  @param[in]  paddr_64         64-bit physical address to query; if paddr is specified, vaddr must be set to
                               the value QURT_EINVALID.

  @return 
  QURT_EOK -- Success. \n
  QURT_EMEM -- Region not found for the specified address. \n
  QURT_EFATAL -- Invalid input parameters.

  @dependencies
  None.
 */
int qurt_mem_region_query_64(qurt_mem_region_t *region_handle, qurt_addr_t vaddr, qurt_paddr_64_t paddr_64);

/**@ingroup func_qurt_mapping_create_64
  Creates a new memory mapping in the page table.

  @datatypes
  #qurt_addr_t \n
  #qurt_paddr_64_t \n
  #qurt_size_t \n
  #qurt_mem_cache_mode_t \n
  #qurt_perm_t
 
  @param[in] vaddr	        Virtual address.
  @param[in] paddr_64		64-bit physical address.
  @param[in] size			Size (4K-aligned) of the mapped memory page.
  @param[in] cache_attribs  Cache mode (writeback, etc.).
  @param[in] perm			Access permissions.

  @return			
  QURT_EOK -- Success. \n
  QURT_EMEM -- Failure.	

  @dependencies
  None.
*/
int qurt_mapping_create_64(qurt_addr_t vaddr, qurt_paddr_64_t paddr_64, qurt_size_t size,
                         qurt_mem_cache_mode_t cache_attribs, qurt_perm_t perm);

/**@ingroup func_qurt_mapping_remove_64
  Deletes the specified memory mapping from the page table.
 
  @datatypes
  #qurt_addr_t \n
  #qurt_paddr_64_t \n  
  #qurt_size_t
 
  @param[in] vaddr    Virtual address.
  @param[in] paddr_64 64-bit physical address.
  @param[in] size     Size of the mapped memory page (4K-aligned).

  @return 			
  QURT_EOK -- Success.

  @dependencies
  None.
  		
 */ 		
int qurt_mapping_remove_64(qurt_addr_t vaddr, qurt_paddr_64_t paddr_64, qurt_size_t size);

/**@ingroup func_qurt_lookup_physaddr_64
  Translates a virtual memory address to the 64-bit physical memory address it is mapped to.

  @datatypes
  #qurt_paddr_64_t \n
  #qurt_addr_t

  @param[in] vaddr   Virtual address.

  @return
  Nonzero -- 64-bit physical address the virtual address is mapped to. \n
  0 -- Virtual address has not been mapped.

  @dependencies
  None.
*/
qurt_paddr_64_t qurt_lookup_physaddr_64 (qurt_addr_t vaddr);
   
/**@ingroup func_qurt_mapping_reclaim
  Deallocates all QuRT resources associated with the specified virtual
  memory area, making it available for user memory management:\n
  - The associated physical memory areas are freed and added to the
    specified physical pool.\n
  - The associated TLB entries are deleted and made available for TLB
    management.\n
  - The virtual memory area itself is not freed -- it is left in
    place as allocated but unmapped virtual memory. Any access to this
    memory area generates an exception.\n
  The virtual memory area must be statically allocated.
  If no pool is specified, the freed physical memory is not added to any pool.

  @note1hang The virtual memory area is currently restricted to being
         filled with locked TLB entries that are contiguous
         within the memory area, and contained by it.

  @datatypes
  #qurt_addr_t \n
  #qurt_size_t \n
  #qurt_mem_pool_t

  @param[in] vaddr   Virtual address of the memory area to be freed.
  @param[in] vsize   Size (in bytes) of the memory area to be freed.
  @param[in] pool    Handle to the physical pool where freed physical memory is added.
                     If set to 0, freed physical memory is not added to any pool.

  @return
  0 -- Success. \n
  Nonzero -- Failure indicating a partial success, or that the request was malformed. The expected behvaior is that
       QuRT logs messages related to the failure, and callers are free to ignore the return value.

  @dependencies
  None.
*/
int qurt_mapping_reclaim(qurt_addr_t vaddr, qurt_size_t vsize, qurt_mem_pool_t pool);


/**@ingroup qurt_mem_configure_cache_partition
  Configure Hexagon cache partition at system level
  This API can only be called with the QurtOS privilege. The partition size of 7/8 is only applicable 
  to L2 cache.
  
  Note: Hexagon V60 core doesn't support L1 cache partition anymore.

  @param[in] 
  cache type       cache type for partition configuration.
                      HEXAGON_L1_I_CACHE
                      HEXAGON_L1_D_CACHE
                      HEXAGON_L2_CACHE

  partition_size   cache partition size
                      FULL_SIZE
                      HALF_SIZE
                      THREE_QUARTER_SIZE
                      SEVEN_EIGHTHS_SIZE

  @return 			
       QURT_EOK     // success
       QURT_EVAL    // error

  @dependencies
  None.
  		
 */ 		
int qurt_mem_configure_cache_partition(qurt_cache_type_t cache_type, qurt_cache_partition_size_t partition_size);


/**@ingroup func_qurt_l2fetch_disable
  Disables L2FETCH activities on all hardware threads.
 
  @return 			
  None

  @dependencies
  None.  		
 */ 		
void qurt_l2fetch_disable(void);

/**@ingroup func_qurt_mem_syncht
  This is a heavy-weight synchronization operation. This instruction ensures that all previous memory 
  transactions (cached and uncached load/store, mem_locked, etc.) from the thread have completed 
  and are globally observable before continuing past this instruction.

  @note1hang Wrapper of Hexagon instruction SYNCHT.
 
  @return 			
  None

  @dependencies
  None.  		
 */ 
static inline void qurt_mem_syncht(void){
    __asm__  __volatile__ (" SYNCHT \n");    
}

/**@ingroup func_qurt_mem_barrier
  This instruction provides synchronization for a thread. It establishes a memory barrier to ensure 
  proper ordering between accesses before the barrier instruction and accesses after the barrier 
  instruction. All accesses before the barrier will be globally observable before any memory access 
  occurring after the barrier may be observed. 

  @note1hang Wrapper of Hexagon instruction BARRIER.
 
  @return 			
  None

  @dependencies
  None.  		
 */ 
static inline void qurt_mem_barrier(void){
    __asm__  __volatile__ (" BARRIER \n");    
}
    
#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif /* QURT_MEMORY_H */
