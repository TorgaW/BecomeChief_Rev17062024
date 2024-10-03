#include "memory.h"
#include <stdlib.h>

void* engine_malloc(size_t num, int strategy)
{
	void* t = NULL;
	switch (strategy) {
		case ENGINE_MALLOC_DEFAULT:
		case ENGINE_MALLOC_AUTO:{
			t = malloc(num);
		} break;
	}
	return t;
}