#include "noise.h"
#include "math/frandom.h"
#include <memory/memory.h>

void alloc_noise(SNoise* noise, uint32_t sizeX, uint32_t sizeY)
{
	noise->data = engine_malloc(sizeX*sizeY*sizeof(float), ENGINE_MALLOC_AUTO);
	noise->capacity = sizeX*sizeY;
	noise->size = 0u;
}

void gen_perlin_random_values(SNoise* noise, SMathRandomState* randomState)
{
	noise->perlin_random_values[0] = random_range(randomState, 5, 0xFFFFFFFA);
	noise->perlin_random_values[1] = random_range(randomState, 5, 0xFFFFFFFA);
	noise->perlin_random_values[2] = random_range(randomState, 5, 0xFFFFFFFA);
}