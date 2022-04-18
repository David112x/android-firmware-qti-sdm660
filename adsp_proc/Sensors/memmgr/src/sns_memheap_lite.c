/* =========================================================================

DESCRIPTION
  Implementation of a simple sub-allocator to manage memory allocations
  and deallocations using a Next Fit strategy.

 Copyright (c) 1997-2016 Qualcomm Technologies, Inc.  All Rights Reserved.
 Qualcomm Technologies Proprietary and Confidential.
============================================================================ */

#ifdef SNS_USES_ISLAND

/* ------------------------------------------------------------------------
** Includes
** ------------------------------------------------------------------------ */
#include <stdio.h>
#include <string.h>
#include "sns_memheap_lite.h"
#include "sns_common.h"
#include "sns_memmgr.h"

/* ------------------------------------------------------------------------
** Defines
** ------------------------------------------------------------------------ */
#define OVERFLOW_CHECK(elt_count, elt_size) (!(elt_count >= (1U<<10) || elt_size >= (1U<<22)) || ((((uint64)elt_count * (uint64)elt_size) >> 32) == 0))

#define BOUNDARY_CHECK(theBlock, heap_ptr) ((theBlock >= ((sns_mem_heap_type*)heap_ptr)->first_block) && (theBlock < (((sns_mem_heap_type*)heap_ptr)->first_block + heap_ptr->total_bytes)))

#define FRD_OFFSET_CHECK(block, heap_ptr) ((((sns_mem_block_header_type *)block)->forw_offset + (char *)block) <= ((((char*)((sns_mem_heap_type*)heap_ptr)->first_block) + ((sns_mem_heap_type*)heap_ptr)->total_bytes)))

//#define MEMHEAP_VERIFY_HEADER(block, heap_ptr) (((mem_block_header_type *)block)->header_guard == ((mem_heap_type*)heap_ptr)->block_header_guard ? TRUE : FALSE)

/* XOR based Guard byte calculations and restore */
#define INTEGRITY_CHECK_ON_USED_HEADER(magic_num_used, block) \
            (block[0]^block[1]^block[2]^block[3]^magic_num_used)

#define INTEGRITY_CHECK_ON_FREE_HEADER(magic_num_free, block) \
            (block[0]^block[1]^block[2]^block[3]^magic_num_free)

#define ADD_GUARD_BYTES_TO_USED_HEADER(magic_num_used, block) \
            (block[0] = block[1]^block[2]^block[3]^magic_num_used)

#define ADD_GUARD_BYTES_TO_FREE_HEADER(magic_num_free, block) \
            (block[0] = block[1]^block[2]^block[3]^magic_num_free)

#define HEAP_ALIGN 3

STATIC sns_mem_block_header_type *mem_find_free_block(
   sns_mem_heap_type *heap_ptr,
     /*  The heap to search for a free block
     */
   unsigned long  size_needed
     /*  The minimum size in bytes of the block needed (this size
         INCLUDES the size of the memory block header itself)
     */
);

SNS_MEMMGR_UIMAGE_DATA STATIC qurt_mutex_t sns_uheap_lock;

/* NOTUSED */
#define NOTUSED(i) if(i){}
#define MEMHEAP_MIN_BLOCK_SIZE 4

static int mem_init_block_header(sns_mem_block_header_type *, unsigned long, sns_mem_heap_type *hep_ptr);

#ifdef SNS_FEATURE_MEM_DEBUG
#ifndef MEM_HEAP_CALLER_ADDRESS_LEVEL
#define MEM_HEAP_CALLER_ADDRESS_LEVEL 1
#endif
#if defined(QDSP6)
 #define  MEM_HEAP_CALLER_ADDRESS(level) ((void *)__builtin_return_address(level));
#else
 #define MEM_HEAP_CALLER_ADDRESS(level) ((void *) __return_address())
#endif
#endif

/*===========================================================================
FUNCTION mem_heap_get_random_num
DESCRIPTION

===========================================================================*/
int sns_mem_heap_get_random_num(void*  random_ptr, int random_len)
{
  if(random_len == 4)
  {
    uint32 *ran_num = (uint32 *)random_ptr;
    *ran_num = 0xabcddcba;
  }
  else if(random_len == 2)
  {
    uint16 *ran_num = (uint16 *)random_ptr;
    *ran_num = 0xabcd;
  }

  return SNS_MEMHEAP_SUCCESS;
}

/*===========================================================================
FUNCTION MEM_GET_NEXT_BLOCK

DESCRIPTION
  Return the next block header in the heap for the block following the
  given one.  If the given block is the last block in the heap, return
  the first block in the heap.  Never returns NULL.

  Returns a pointer the the memory block header of the block following the given
  block (or the first block of the heap if the given block was the last
  block of the heap).

===========================================================================*/
SNS_MEMMGR_UIMAGE_CODE static sns_mem_block_header_type *mem_get_next_block
(
   const sns_mem_heap_type         *heap_ptr,
     /*  The heap the given block belongs to -- may NOT be NULL!
     */
   const sns_mem_block_header_type *block_ptr
     /*  The block in the heap for which to return the following heap
         block
     */
)
{
   uint16 *pblk = NULL;
   sns_mem_block_header_type *nextBlkPtr = NULL;
   SNS_ASSERT(block_ptr != NULL);
   SNS_ASSERT(heap_ptr != NULL); //this may be redundent since , it a static function re-visit this for possible optimisation
   SNS_ASSERT(block_ptr->forw_offset != 0);
   SNS_ASSERT(FRD_OFFSET_CHECK(block_ptr, heap_ptr));
   SNS_ASSERT(!((block_ptr->forw_offset)%kMinChunkSizeLite));

   nextBlkPtr =  block_ptr->last_flag  ? heap_ptr->first_block
           : (sns_mem_block_header_type *) ((char *) block_ptr + block_ptr->forw_offset);
   pblk = (uint16*)nextBlkPtr;
   if(nextBlkPtr->free_flag == kBlockFreeLite){
      SNS_ASSERT(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk));
   }
   else{
      SNS_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk));
   }
   return nextBlkPtr;
} /* END mem_get_next_block */

/*===========================================================================
FUNCTION MEM_INIT_HEAP

DESCRIPTION
  Initializes the heap_ptr object and sets up inMemoryChunk for use with the
  heap_ptr object.  inMemoryChunk may be aligned on any boundary.  Beginning
  bytes will be skipped until a paragraph boundary is reached.  Do NOT pass
  in NULL pointers.  infail_fnc_ptr may be NULL in which case no function will
  be called if mem_malloc or mem_calloc is about to fail.  If infail_fnc_ptr
  is provided, it will be called once and then the allocation will be
  attempted again.  See description of my_allocator_failed_proc for details.
  There is no protection for initializing a heap more than once.  If a heap
  is re-initialized, all pointers previously allocated from the heap are
  immediately invalidated and their contents possibly destroyed.  If that's
  the desired behavior, a heap may be initialized more than once.
===========================================================================*/
/*lint -sem(mem_init_heap,1p,2p,2P>=3n) */
int sns_mem_init_heap(
   sns_mem_heap_type                 *heap_ptr,
      /* Statically allocated heap structure
      */
   mem_magic_number_struct       *mem_magic_number,
     /* Base pointer for magic number array,index*/
   void                          *heap_mem_ptr,
      /* Pointer to contiguous block of memory used for this heap
      */
   unsigned long                  heap_mem_size
      /* The size in bytes of the memory pointed to by heap_mem_ptr
      */
)
{
  char *memory_end_ptr;
    /* 1 beyond computed end of memory passed in to use as heap.
    */
  char *memory_start_ptr;
    /* The computed beginning of the memory passed in to use as heap.  This
       computed value guarantees the heap actually starts on a paragraph
       boundary.
    */
  unsigned long chunks;
    /* How many whole blocks of size kMinChunkSizeLite fit in the area of
       memory starting at memory_start_ptr and ending at (memory_end_ptr-1)
    */
  uint16 * pblk = NULL;

  SNS_ASSERT(NULL != heap_ptr);

  SNS_ASSERT(NULL != mem_magic_number);

  SNS_ASSERT(NULL != mem_magic_number->magic_num);

  SNS_ASSERT(NULL != mem_magic_number->magic_num_index_array);

  SNS_ASSERT(mem_magic_number->magic_num_index < SNS_MAX_HEAP_INIT); /* support at the most 30 heaps*/

  if( (heap_ptr->magic_num) &&
      (heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index])){
  	/* heap is already initialized so just return */
  	return SNS_MEMHEAP_SUCCESS;
  }

  memset(heap_ptr, 0, sizeof(sns_mem_heap_type));

  SNS_ASSERT(NULL != heap_mem_ptr);
  SNS_ASSERT(NULL != heap_mem_size);
  SNS_ASSERT(heap_mem_size >= (2*kMinChunkSizeLite-1));

  memory_start_ptr = (char *)heap_mem_ptr;
  memory_end_ptr   = memory_start_ptr + heap_mem_size;

  //use the memory required for memheap_crit_sect from the heap getting initialized */
 while( (((unsigned long)memory_start_ptr) & 0x000FUL) )
  {
     ++memory_start_ptr;
  }

  /* Initilize the heap mutex */
  qurt_rmutex_init(&sns_uheap_lock);

  /* Advance to the nearest paragraph boundary. This while loop should work
  ** regardless of how many bits are required for address pointers near or
  ** far, etc.
  **
  ** Turn off lint "size incompatibility" warning because cast from pointer
  ** to unsigned long will lose bits, but we don't care because we're only
  ** interested in the least significant bits and we never cast back into a
  ** pointer, so the warning can be safely ignored
  */
  /*lint --e(507)*/
  /*while( (((unsigned long)memory_start_ptr) & 0x000FUL) )
  {
     ++memory_start_ptr;
  }*/

  chunks = (unsigned long) ((memory_end_ptr - memory_start_ptr) / kMinChunkSizeLite);

  heap_ptr->first_block            = (sns_mem_block_header_type *) memory_start_ptr;
  heap_ptr->next_block             = heap_ptr->first_block;


  sns_mem_heap_get_random_num((&(mem_magic_number->magic_num[mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index]])), 4);
  heap_ptr->magic_num = mem_magic_number->magic_num[mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index]];
  heap_ptr->magic_num_index = mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index];
  sns_mem_heap_get_random_num(&(heap_ptr->magic_num_free), 2);
  sns_mem_heap_get_random_num(&(heap_ptr->magic_num_used), 2);
  mem_magic_number->magic_num_index++;
  mem_init_block_header(heap_ptr->first_block, chunks * kMinChunkSizeLite, heap_ptr);
  heap_ptr->first_block->last_flag = (char) kLastBlockLite;
  heap_ptr->total_blocks           = 1;
  heap_ptr->max_used               = 0;
  heap_ptr->max_request            = 0;
  heap_ptr->used_bytes             = 0;
  heap_ptr->total_bytes            = chunks * kMinChunkSizeLite;
  pblk = (uint16*)(heap_ptr->first_block);
  ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
  return SNS_MEMHEAP_SUCCESS;
} /* END mem_init_heap */

/*===========================================================================
FUNCTION MEM_DEINIT_HEAP

DESCRIPTION
  De-Initializes the heap_ptr object only if the heap is in reset state.
  User is responsible for freeing all the allocated pointers before  calling
  into this function.
===========================================================================*/
int sns_mem_deinit_heap(
   sns_mem_heap_type                 *heap_ptr,
      /* Statically allocated heap structure
      */
   mem_magic_number_struct       *mem_magic_number
)
{
  SNS_ASSERT(NULL != mem_magic_number);

  SNS_ASSERT(NULL != mem_magic_number->magic_num);

  SNS_ASSERT(NULL != mem_magic_number->magic_num_index_array);
  // return the magic number
  mem_magic_number->magic_num_index--;
  if(mem_magic_number->magic_num_index < SNS_MAX_HEAP_INIT)
  {
	  mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index]=heap_ptr->magic_num_index;
  }
 /* De-initialize heap only if all the allocated blocks are freed */
 if(heap_ptr->used_bytes == 0)
 {
   qurt_rmutex_destroy(&sns_uheap_lock);
   memset(heap_ptr, 0, sizeof(sns_mem_heap_type));
 }
 else
 {
	SNS_ASSERT(heap_ptr->used_bytes == 0);
 }
 return SNS_MEMHEAP_SUCCESS;
}

/*===========================================================================
FUNCTION MEM_INIT_BLOCK_HEADER

DESCRIPTION
  Initializes a memory block header to control a block of memory in the
  heap.  The header may still need to some of its fields adjusted after
  this call if it will be a used block or the last block in the heap.
===========================================================================*/
SNS_MEMMGR_UIMAGE_CODE int mem_init_block_header(
   sns_mem_block_header_type *block_ptr,
     /* Memory header block to be initialized
     */
   unsigned long          size,
     /* The size of the block of memory controlled by this
        memory header block INCLUDING the size of the
        header block itself
     */
     sns_mem_heap_type *heap_ptr
)
{
  char *p_temp;
  SNS_ASSERT(NULL != block_ptr);
  p_temp = ((char*)block_ptr);
  memset(p_temp, 0 , sizeof(sns_mem_block_header_type));
  block_ptr->free_flag   = (char) kBlockFreeLite;
  block_ptr->forw_offset = size;

  return SNS_MEMHEAP_SUCCESS;
} /* END mem_init_block_header */

/*===========================================================================
FUNCTION MEM_MALLOC

DESCRIPTION
  Allocates a block of size bytes from the heap.  If heap_ptr is NULL
  or size is 0, the NULL pointer will be silently returned.

  Returns a pointer to the newly allocated block, or NULL if the block
  could not be allocated.
===========================================================================*/
/*lint -sem(mem_malloc,1p,2n>=0&&(@p==0||@P==2n)) */
SNS_MEMMGR_UIMAGE_CODE inline void* sns_mem_malloc(
  sns_mem_heap_type *heap_ptr,
     /* Heap from which to allocate
     */
  mem_magic_number_struct       *mem_magic_number,
  unsigned int         size,
     /* Number of bytes to allocate
     */
  unsigned int         calldepth
     /* The number of calls above which the first mem_malloc()
        call was made. (only used in Debug mode). Upper bound to 4*/
)
{

  unsigned long chunks;
    /* the computed minimum size of the memory block in chunks needed
       to satisfy the request */

  unsigned long actualSize;
    /* the computed minimum size of the memory block in bytes needed
       to satisfy the request */

  unsigned char bonusBytes;
    /* the computed number of unused bytes at the end of the allocated
       memory block.  Will always be < kMinChunkSizeLite */

  sns_mem_block_header_type *freeBlock = NULL;
    /* the free block found of size >= actualSize */

  void *answer = NULL;
    /* the address of memory to be returned to the caller */

  uint16 * pblk = NULL;
  uint32 blockHeaderSize=sizeof(sns_mem_block_header_type);

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

  SNS_ASSERT(heap_ptr != NULL);

  SNS_ASSERT(NULL != mem_magic_number);

  SNS_ASSERT(NULL != mem_magic_number->magic_num);

  SNS_ASSERT(NULL != mem_magic_number->magic_num_index_array);

  if (!size) return NULL;

  /* quick check if requested size of memory is available */
  if( (unsigned long) size > heap_ptr->total_bytes ) return NULL;

  /* chunks overflow check : check max memory that can be malloc'd at a time */
  if( (0xFFFFFFFF - ( kMinChunkSizeLite + sizeof(sns_mem_block_header_type)) )
  	    < ((unsigned long) size)) return NULL;

  chunks = ((unsigned long) size + blockHeaderSize
            + kMinChunkSizeLite - 1) / kMinChunkSizeLite;
  actualSize = chunks * kMinChunkSizeLite;
  bonusBytes = (unsigned char)
                (actualSize - size - blockHeaderSize);

    qurt_rmutex_lock(&sns_uheap_lock);

    SNS_ASSERT(heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index]);
    freeBlock = mem_find_free_block(heap_ptr, actualSize);
    if (freeBlock)
    {
      pblk = (uint16*)freeBlock;
      SNS_ASSERT(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk));

      /* split the block (if necessary) and return the new block */
      SNS_ASSERT(freeBlock->forw_offset > 0);
      // frd offset and actual size are chunk aligned
      if (freeBlock->forw_offset >= (actualSize + blockHeaderSize + kMinChunkSizeLite))
      {
        /* must split into two free blocks */
        sns_mem_block_header_type *newBlock = (sns_mem_block_header_type *)
                                          ((char *) freeBlock + actualSize);
        mem_init_block_header(newBlock, freeBlock->forw_offset - actualSize, heap_ptr);
        newBlock->last_flag = freeBlock->last_flag;
        freeBlock->forw_offset = actualSize;
        freeBlock->last_flag = 0;

        ++heap_ptr->total_blocks;
         pblk = (uint16*)newBlock;
        ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
      }
      else
      {
        // A preexisting block is larger than actualSize but not large enough to
        // be split into two blocks. We must count the additional bytes as our
        // bonus blocks because when we free this block, we make the assumption
        // requested size = forward offset - headerSize - extra bytes
        bonusBytes += freeBlock->forw_offset - actualSize;
      }

      /* mark the block as used and return it */
      freeBlock->free_flag = kBlockUsedLite;
      freeBlock->extra = bonusBytes;
      /*  set up next block to search for
          next allocation request */
      heap_ptr->next_block = mem_get_next_block(heap_ptr, freeBlock);
      heap_ptr->used_bytes += size;
      SNS_ASSERT(heap_ptr->total_bytes >= heap_ptr->used_bytes);
      if (heap_ptr->used_bytes > heap_ptr->max_used) {
        heap_ptr->max_used = heap_ptr->used_bytes;
      }
      if (size > heap_ptr->max_request) {
        heap_ptr->max_request = size;
      }
	  pblk = (uint16*)freeBlock;
      ADD_GUARD_BYTES_TO_USED_HEADER(heap_ptr->magic_num_used, pblk);
      answer = (char *) freeBlock + blockHeaderSize;
    }

#ifdef SNS_FEATURE_MEM_DEBUG
    if(answer != NULL)
    {
      SNS_ASSERT( freeBlock != NULL );
      switch(MEM_HEAP_CALLER_ADDRESS_LEVEL + calldepth)
      {
         case 1:
            freeBlock->caller_ptr=MEM_HEAP_CALLER_ADDRESS(1);
            break;
         case 2:
            freeBlock->caller_ptr=MEM_HEAP_CALLER_ADDRESS(2);
            break;
         case 3:
            freeBlock->caller_ptr=MEM_HEAP_CALLER_ADDRESS(3);
            break;
         case 4:
            freeBlock->caller_ptr=MEM_HEAP_CALLER_ADDRESS(4);
            break;
         default:
            freeBlock->caller_ptr=MEM_HEAP_CALLER_ADDRESS(1);
            break;
      }
    }
#endif

    qurt_rmutex_unlock(&sns_uheap_lock);

  return answer;
} /* END mem_malloc */

/*===========================================================================
FUNCTION MEM_FREE

DESCRIPTION
  Deallocates the ptr block of memory.  If ptr is NULL, heap_ptr is NULL or
  ptr is outside the range of memory managed by heap_ptr, then this function
  call does nothing (and is guaranteed to be harmless).  This function will
  ASSERT if it can detect an attempt to free an already freed block.  (This
  is not always reliable though, so it might not catch it.)
===========================================================================*/
/*lint -sem(mem_free,1p) */
SNS_MEMMGR_UIMAGE_CODE int sns_mem_free(
  sns_mem_heap_type *heap_ptr,
     /* Heap in which to free memory
     */
  mem_magic_number_struct       *mem_magic_number,
  void          *ptr
     /* Memory to free
     */
)
{
  sns_mem_block_header_type *theBlock;
    /* The computed address of the memory header block in the heap that
       controls the memory referenced by ptr */
  uint32          sizeBlockHeader=sizeof(sns_mem_block_header_type);

  uint16 *pblk = NULL;

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

  SNS_ASSERT(heap_ptr != NULL);

  SNS_ASSERT(NULL != mem_magic_number);

  SNS_ASSERT(NULL != mem_magic_number->magic_num);

  SNS_ASSERT(NULL != mem_magic_number->magic_num_index_array);
  /*commented out the below assert since NULL free occurances are found and once
   corrsponding fixes are in its need to be uncomment*/
  SNS_ASSERT(heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index]);

  /*commented out the below assert since NULL free occurances are found and once
   corrsponding fixes are in its need to be uncomment*/
  if(ptr == NULL)
  {
     //MEMHEAP_ERROR(" NULL ptr occurenaces in mem_free()",0,0,0);
    //SNS_ASSERT(0);

    return SNS_MEMHEAP_SUCCESS;
  }

  /* free the passed in block */

  SNS_ASSERT(NULL != heap_ptr->first_block);
  qurt_rmutex_lock(&sns_uheap_lock);
  theBlock = (sns_mem_block_header_type *)
                          ((char *) ptr - sizeBlockHeader);

  //check for block alignment to kMinChunkSizeLite
  SNS_ASSERT((((uint32)theBlock)%kMinChunkSizeLite) == 0);

  /* boundry check for the ptr passed to free */
  SNS_ASSERT(BOUNDARY_CHECK(theBlock, heap_ptr));

  /* Try to detect corruption. */
  SNS_ASSERT(!theBlock->free_flag);  /* Attempt to detect multiple
                                            frees of same block */
  /* Make sure forw_offset is reasonable */
  SNS_ASSERT(theBlock->forw_offset >= sizeBlockHeader);
  /* Make sure extra is reasonable */
  SNS_ASSERT(theBlock->extra <= (( 2 * kMinChunkSizeLite) + sizeBlockHeader));

  /* Make sure forw_offset is not spiling over the heap boundry */
  SNS_ASSERT(FRD_OFFSET_CHECK(theBlock, heap_ptr));

 //check for heap canary
  pblk = (uint16*)(theBlock);
  SNS_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk));

  if (!theBlock->free_flag) /* Be intelligent about not munging the heap if
                              a multiple free of the same block is detected */
  {
    SNS_ASSERT((theBlock->forw_offset - sizeBlockHeader
                                  - theBlock->extra) <= heap_ptr->used_bytes);
    heap_ptr->used_bytes -= theBlock->forw_offset - sizeBlockHeader
                                  - theBlock->extra;
    SNS_ASSERT(heap_ptr->total_bytes >= heap_ptr->used_bytes);

    theBlock->free_flag = (char) kBlockFreeLite;
    /* now backup the next pointer if applicable */
    //next_block = mem_get_next_block(heap_ptr, theBlock);

    if (theBlock < heap_ptr->next_block) {
      /* Backup now to lessen possible fragmentation */
      heap_ptr->next_block = theBlock;
    }
	  pblk = (uint16*)theBlock;
    ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);

    /* reset heap to initial state if everything is now freed */
    if (!heap_ptr->used_bytes) {

      /* reset heap now, but retain statistics */
      heap_ptr->next_block = heap_ptr->first_block;
      mem_init_block_header(heap_ptr->first_block, heap_ptr->total_bytes, heap_ptr);
      heap_ptr->first_block->last_flag = (char) kLastBlockLite;
      heap_ptr->total_blocks = 1;
	   pblk = (uint16*)(heap_ptr->first_block);
      ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
    }
	}
     qurt_rmutex_unlock(&sns_uheap_lock);
     return SNS_MEMHEAP_SUCCESS;
} /* END mem_free */

/*===========================================================================
FUNCTION MEM_FIND_FREE_BLOCK

DESCRIPTION
  Find a free block of at least inSizeNeeded total bytes.  Collapse
  adjacent free blocks along the way.

  Returns a pointer to a memory block header describing a free block
  of at least inSizeNeeded total bytes.  Returns NULL if no such free
  block exists or can be created by collapsing adjacent free blocks.
===========================================================================*/
SNS_MEMMGR_UIMAGE_CODE sns_mem_block_header_type *mem_find_free_block(
   sns_mem_heap_type *heap_ptr,
     /*  The heap to search for a free block
     */
   unsigned long  size_needed
     /*  The minimum size in bytes of the block needed (this size
         INCLUDES the size of the memory block header itself)
     */
)
{
  long searchBlocks;
    /* The maximum number of blocks to search.  After searching this
       many, we've been through the heap once and the allocation fails
       if we couldn't find/create a satisfactory free block */

  sns_mem_block_header_type *followingBlock;
    /* a loop variable used to walk through the blocks of the heap */
  uint16 *pblk = NULL;

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

  SNS_ASSERT(NULL != heap_ptr);
  SNS_ASSERT(NULL != heap_ptr->first_block);
  /* sanity check for the  heap_ptr->next_block  */
  if((heap_ptr->next_block)->free_flag == kBlockFreeLite){
      pblk = (uint16*)(heap_ptr->next_block);
      SNS_ASSERT(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk));
   }
   else{
      pblk = (uint16*)(heap_ptr->next_block);
      SNS_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk));
   }

  searchBlocks = (long) heap_ptr->total_blocks;

  followingBlock = mem_get_next_block(heap_ptr, heap_ptr->next_block);

  for (; searchBlocks > 0; --searchBlocks, heap_ptr->next_block=followingBlock,
                  followingBlock=mem_get_next_block(heap_ptr, heap_ptr->next_block))
  {
    SNS_ASSERT(heap_ptr->next_block->forw_offset > 0);
    SNS_ASSERT(followingBlock->forw_offset > 0);

    if (heap_ptr->next_block->free_flag)
    {
      while (heap_ptr->next_block->forw_offset < size_needed
             && followingBlock->free_flag && followingBlock > heap_ptr->next_block)
      {
        /* collapse adjacent free blocks into one if it
         * will allow us to satisfy a request
         */

        heap_ptr->next_block->forw_offset += followingBlock->forw_offset;
        heap_ptr->next_block->last_flag = followingBlock->last_flag;
        pblk = (uint16*) (heap_ptr->next_block);
        ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);

        --heap_ptr->total_blocks;
        --searchBlocks; /* don't search more than we need */
		//memset the following block header information to 0 for safe unlinking
		{
             uint32 *temp = (uint32*)followingBlock; /*did it like this for optimization purpose*/
             temp[0] = NULL;
             temp[1] = NULL;
        }
        followingBlock = mem_get_next_block(heap_ptr, heap_ptr->next_block);

      }
      if (heap_ptr->next_block->forw_offset >= size_needed) {
        return heap_ptr->next_block;
      }
    }
  }
  return SNS_MEMHEAP_FAILURE;       /* didn't find anything */
} /* END mem_find_free_block */

#endif /* SNS_USES_ISLAND */
