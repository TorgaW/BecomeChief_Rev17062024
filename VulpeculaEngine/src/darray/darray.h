#ifndef DARRAY
#define DARRAY

#include <sys/types.h>

typedef struct SArray
{
	size_t capacity;
	size_t size;
	size_t dataTypeSize;
	void* data;
} SArray;

SArray* array_create(size_t capacity, size_t dataTypeSize);

void array_push_back(void* data, SArray* array);
void array_push_back_mul(void* data, size_t dataSize, SArray* array);

int _array_realloc_data(SArray* array);

#endif /* DARRAY */
