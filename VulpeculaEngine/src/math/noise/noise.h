#ifndef NOISE
#define NOISE

#include <stdint.h>
#include <sys/types.h>
#define NOISE_SIMPLEX 0

typedef struct SNoise {
	int noiseType;
	size_t size;
	size_t capacity;
	float* data;
} SNoise;

void alloc_noise(SNoise* noise, uint32_t sizeX, uint32_t sizeY);

#endif /* NOISE */
