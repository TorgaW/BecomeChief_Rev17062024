#ifndef DARRAY
#define DARRAY

#include "../defs/defs.h"
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
void array_push_back_mul(void* data, size_t dataCount, SArray* array);

#define array_get_at(array, type, index) (((type*)array->data) + index)

void array_free(SArray* array);

bool _array_realloc_data(SArray* array);

#endif /* DARRAY */
