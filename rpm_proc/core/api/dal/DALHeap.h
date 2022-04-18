#ifndef _DAL_HEAP
#define _DAL_HEAP

#include "DALSys.h"

#define DAL_HEAP_NODE_SIZE    8 /*bytes*/

typedef struct _HeapNode HeapNode;
typedef struct _DALHeap DALHeap;
struct _DALHeap
{
   HeapNode * pFreeNode;
   DALSYSSyncHandle hHeapLock;
   char HeapLockMem[DALSYS_SYNC_OBJ_SIZE_BYTES];  
};

int DALHeap_Init(DALHeap * pHeap, void * pHeapMem, unsigned int iHeapSize);
void * DALHeap_Malloc(DALHeap * pHeap, unsigned int iReqSize);
void DALHeap_Free(DALHeap * pHeap, void * pMem);

#endif //_DAL_HEAP

