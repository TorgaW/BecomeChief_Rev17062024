#include "../../VulpeculaEngine/src/darray/darray.h"
#include "../../VulpeculaEngine/src/engine/engine.h"
#include "../../VulpeculaEngine/src/memory/memory.h"
#include "../../VulpeculaEngine/src/sprite/sprite.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  SArray *array = array_create(1, sizeof(int));
  int *example = malloc(sizeof(int) * 10);
  for (size_t i = 0; i < 10; i++) {
    example[i] = i;
  }
  array_push_back_mul(example, 10, array);
  for (size_t i = 0; i < 10; i++) {
    printf("value: %d, capacity: %zu\n", *((int *)array->data + i),
           array->size);
  }
  SEngineApp engineApp = init_vulpecula_engine();
  loop_vulpecula_engine(&engineApp);
  free(example);
  return 0;
}