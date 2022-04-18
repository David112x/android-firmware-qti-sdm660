#ifndef UMEMHEAP_H
#define UMEMHEAP_H
/**
  @file umemheap_lite.h
  @brief A simple sub-allocator to manage memory allocations and deallocations
  using a Next Fit strategy. 

*/
/*===========================================================================
NOTE: The @brief description and any detailed descriptions above do not appear 
      in the PDF. 

      The Utility_Services_API_mainpage.dox file contains all file/group 
      descriptions that are in the output PDF generated using Doxygen and 
      Latex. To edit or update any of the file/group text in the PDF, edit 
      the Utility_Services_API_mainpage.dox file or contact Tech Pubs.

      The above description for this file is part of the "utils_memory" 
      group description in the Utility_Services_API_mainpage.dox file. 
===========================================================================*/
/*===========================================================================
 Note that these routines are FULLY re-entrant.  Furthermore, while
  performing memory allocation/deallocation calls on one heap, the routines
  may be interrupted to perform memory allocation/deallocation calls on
  different heaps without blocking or corruption.  However, should an
  interrupting task attempt to perform memory allocation/deallocation
  on the same heap that had a critical section interrupted, it will block
  allowing the first call to finish.  All this is accomplished by giving
  each heap its own semaphore.

FEATURE_MEMHEAP_MT
Activates multi threading support for the heap

  Usage Notes - Avoiding Fragmentation
 
1. If all bytes in the heap are freed, the heap is guaranteed to be returned
 to the same state as after a call to mem_init_heap, except that the
 values of maxUsed & maxRequest are not reset.  The order in which blocks
 are freed is irrelevant so long as they ALL are freed.
 
2. After n consecutive malloc/calloc calls, in a heap with non-fragmented
 free space (and no intervening realloc calls that return a new pointer),
 calling free in the reverse order on the n blocks guarantees that the heap
 will be returned to the exact same state as before the n alloc calls.
 

===========================================================================*/
/*
Copyright (c) 1997-2014 Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Confidential and Proprietary. 
*/
/*===========================================================================

                                 Edit History

$PVCSPath: O:/src/asw/COMMON/vcs/memheap.h_v   1.1   07 Mar 2002 18:48:56   rajeevg  $
$Header: //components/rel/core.qdsp6/1.0.c2/api/services/umemheap_lite.h#1 $ $DateTime: 2020/02/10 01:57:30 $ $Author: pwbldsvc $

when       who     what, where, why
--------   ---     --------------------------------------------------------
04/04/14   mg      first release

===========================================================================*/
/** @addtogroup utils_memory
@{ */

/* ------------------------------------------------------------------------
** Includes
** ------------------------------------------------------------------------ */
#include "comdef.h"


/* ------------------------------------------------------------------------
** Defines
** ------------------------------------------------------------------------ */




/** @cond 
*/


/* ------------------------------------------------------------------------
** Types
** ------------------------------------------------------------------------ */

/* Doxygen comments for this struct are in typedef struct mem_heap_struct */
struct mem_heap_struct;


/* Each heap can have its own function that is used to lock the heap and
** free the heap.  mem_lock_fnc_type and mem_free_fnc_type are the types
** of these functions.
*/
/**
  Provides an abstraction so each function can have its own function to 
  lock the heap.

  @param[in] ptr Pointer to what is to be locked.

  @return
  None.

  @dependencies
  None.
*/
typedef void (*mem_lock_fnc_type)( void * ptr);

/**
  Provides an abstraction so each function can have its own function to 
  free the heap.

  @param[in] ptr Pointer to what is to be freed.

  @return
  None.

  @dependencies
  None.
*/
typedef void (*mem_free_fnc_type)( void * ptr);

/** @brief Header for each memory block allocated. The header describes the 
  properties of the block allocated to the client. Note that the size of this 
  structure must be a multiple of the largest alignment size required by the 
  host CPU.
*/
typedef struct mem_block_header_struct {
  uint16        header_guard;

  unsigned char extra;        /**< Extra bytes at the end of a block. */
  char          free_flag:4;  /**< Flag to indicate if this memory block 
                                   is free. */
  char          last_flag:4;/**< Flag to indicate if this is the last block 
                                   in the allocated section. */
  unsigned long forw_offset; /**< Forward offset. The value of the offset 
                                   includes the size of the header and the 
                                   allocated block. */

} mem_block_header_type;



#ifndef MEMHEAP_CRIT_SECT_SIZE
   #define MEMHEAP_CRIT_SECT_SIZE 64
#endif

typedef struct mem_heap_struct {
  uint32                         magic_num;
  mem_block_header_type         *first_block;   
  /**< First block in the heap. */
  mem_block_header_type         *next_block;    
  /**< Next free block in the heap. */
  unsigned long                  total_blocks;  
  /**< Total blocks in the heap. */
  unsigned long                  total_bytes;   
  /**< Total bytes available in the heap. */
  unsigned long                  used_bytes;    
  /**< Amount of bytes in use in the heap. */
  unsigned long                  max_used;      
  /**< Maximum amount that has been used in the heap. */
  unsigned long                  max_request;     
  /**< Pointer to the failed function. */
  mem_lock_fnc_type              lock_fnc_ptr;
  mem_free_fnc_type              free_fnc_ptr;
  uint8 memheap_crit_sect[MEMHEAP_CRIT_SECT_SIZE];
   /**< this is random number used in XOR(guard_bytes) 
    calculation of free memory block  */
  uint16 magic_num_free;
/**< this is random number used in XOR(guard_bytes) 
    calculation of used memory block  */
  uint16 magic_num_used;	
  uint16 magic_num_index; 

} mem_heap_type;



/* ------------------------------------------------------------------------
** Functions
** ------------------------------------------------------------------------ */

#ifdef __cplusplus
   extern "C"
   {
#endif


/**
  Initializes the I/O heap object and sets up heap_mem_ptr for use with 
  the I/O heap object. 
 
  The heap_mem_ptr parameter may be aligned on any boundary. Beginning bytes 
  are skipped until a paragraph boundary is reached. NULL pointers must not 
  be passed in for heap_mem_ptr. The fail_fnc_ptr parameter may be NULL; 
  in which case, no function is called if mem_malloc() or mem_calloc() 
  is about to fail. If fail_fnc_ptr is provided, it is called once and the 
  allocation is attempted again. See mem_allocator_failed_proc_type() 
  for details.
  
  There is no protection for initializing a heap more than once. If a heap
  is reinitialized, all pointers previously allocated from the heap are
  immediately invalidated and their contents possibly destroyed. If this is 
  the desired behavior, a heap may be initialized more than once.
 
  @param[in] heap_ptr         Pointer to the statically allocated heap 
                              structure.
  @param[in,out] heap_mem_ptr Pointer to the contiguous block of memory used 
                              for this heap.
  @param[in] heap_mem_size    Size in bytes of the memory pointed to by 
                              heap_mem_ptr.
  @param[in] fail_fnc_ptr     Function to call when allocation fails; can be 
                              NULL.
 
  @return
  None.

  @dependencies
  None.
*/
/*lint -sem(mem_init_heap,1p,2p,2P>=3n) */
void umem_init_heap(
   mem_heap_type                 *heap_ptr,  
   void                          *heap_mem_ptr,
   unsigned long                  heap_mem_size   
);

/**
  Deinitializes the heap_ptr object only if the heap is in the Reset state.
  Users are responsible for freeing all allocated pointers before calling 
  this function.
  
  @param[in] heap_ptr  Pointer to the heap structure to be deinitialized.
  
  @return
  None.
  
  @dependencies
  None.
*/
void umem_deinit_heap(
   mem_heap_type                 *heap_ptr 
);





/**
  Allocates a block of size bytes from the heap. If heap_ptr is NULL
  or size is 0, the NULL pointer is silently returned.

  @param[in] heap_ptr    Pointer to the heap from which to allocate.
  @param[in] size        Number of bytes to allocate.  

  @return
  Returns a pointer to the newly allocated block, or NULL if the block
  could not be allocated.
 
  @dependencies
  heap_ptr must not be NULL. \n
  size must not be 0.
*/
/*lint -sem(mem_malloc,1p,2n>=0&&(@p==0||@P==2n)) */

void* umem_malloc(
  mem_heap_type *heap_ptr, 
  unsigned int         size
);




/**
  Deallocates the ptr block of memory. If ptr or heap_ptr is NULL, or
  ptr is outside the range of memory managed by heap_ptr, the function
  call does nothing and is guaranteed to be harmless. This function will
  ASSERT if it can detect an attempt to free an already freed block. 
  However, detection is not always possible.

  @param[in] heap_ptr    Pointer to the heap from which to allocate.
  @param[in] ptr         Pointer to the memory to be freed.
  @param[in] file_name   Name of the file from which mem_free() was called 
                         (only used in Debug mode).
  @param[in] line_number Line number corresponding to the mem_free() call 
                         (only used in Debug mode).

  @return
  None.

  @dependencies
  None.
*/
/*lint -sem(mem_free,1p) */
void umem_free(
  mem_heap_type *heap_ptr,
  void          *ptr
);




/* ------------------------------------------------------------------------
** 
** Memory Heap Debug and Test Routines
**
** ------------------------------------------------------------------------ */



/** @cond
*/
/* Anonymous enum used for keeping tracking of memory. */
enum {
  kBlockFree = 1,/* needed some sapce for checksum in block header so reduced it to 1*/
  kBlockUsed = 0,
  kLastBlock = 1,/* needed some sapce for checksum in block header so reduced it to 1*/
  kMinChunkSize = 16
};
/** @endcond */






#ifdef __cplusplus
   }
#endif

/** @} */ /* end_addtogroup utils_services */
#endif /* MEMHEAP_H */
