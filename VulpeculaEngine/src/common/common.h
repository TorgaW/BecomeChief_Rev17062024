#ifndef COMMON
#define COMMON

#include "../memory/memory.h"

#define alloc_struct(type, strategy) engine_malloc(sizeof(type), strategy);

#endif /* COMMON */
