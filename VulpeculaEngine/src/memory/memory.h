#ifndef MEMORY
#define MEMORY

#include "malloc.h"
#include <sys/types.h>

#define ENGINE_MALLOC_DEFAULT 0
#define ENGINE_MALLOC_AUTO 1

typedef struct SMemPool
{

} SMemPool;

void* engine_malloc(size_t num, int strategy);

// void engine_free(size_t num, int strategy);

#endif /* MEMORY */
