#include "noise.h"
#include <memory/memory.h>

void alloc_noise(SNoise* noise, uint32_t sizeX, uint32_t sizeY)
{
	noise->data = engine_malloc(sizeX*sizeY*sizeof(float), ENGINE_MALLOC_AUTO);
	noise->capacity = sizeX*sizeY;
	noise->size = 0u;
}