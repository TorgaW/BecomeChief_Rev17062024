#ifndef NOISE
#define NOISE

#include "math/frandom.h"
#include <stdint.h>
#include <sys/types.h>
#define NOISE_PERLIN 0

typedef struct SNoise {
	int noiseType;
	size_t size;
	size_t capacity;
	float* data;
	uint32_t perlin_random_values[3];
} SNoise;

void alloc_noise(SNoise* noise, uint32_t sizeX, uint32_t sizeY);

void gen_perlin_random_values(SNoise* noise, SMathRandomState* randomState);

#endif /* NOISE */
