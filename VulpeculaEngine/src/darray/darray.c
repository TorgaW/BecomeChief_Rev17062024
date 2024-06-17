#include "darray.h"
#include "../memory/memory.h"
#include <string.h>
#include <stdlib.h>

SArray *array_create(size_t capacity, size_t dataTypeSize) {
  SArray *t = engine_malloc(sizeof(SArray), ENGINE_MALLOC_AUTO);
  t->capacity = capacity;
  t->size = 0;
  t->dataTypeSize = dataTypeSize;
  t->data = engine_malloc(dataTypeSize * capacity, ENGINE_MALLOC_AUTO);
  return t;
}

void array_push_back(void *data, SArray *array) {
  if (array->capacity <= array->size) {
    _array_realloc_data(array);
  }
  memcpy(array->data + array->size, data, array->dataTypeSize);
  array->size++;
}

void array_push_back_mul(void *data, size_t dataCount, SArray *array) 
{
  while (array->capacity <= (array->size + dataCount)) {
    _array_realloc_data(array);
  }
  memcpy(array->data + array->size, data, array->dataTypeSize * dataCount);
  array->size += dataCount;
}

bool _array_realloc_data(SArray *array) {
  array->data = realloc(array->data, array->capacity * array->dataTypeSize * 2);
  array->capacity *= 2;
  return true;
}