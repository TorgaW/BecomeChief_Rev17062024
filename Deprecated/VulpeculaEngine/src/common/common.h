#ifndef COMMON
#define COMMON

#include "../memory/memory.h"
#include <stdint.h>
#include <sys/types.h>

#define alloc_struct(type, strategy) engine_malloc(sizeof(type), strategy);

// size_t get_cache_line_size();

#endif /* COMMON */
