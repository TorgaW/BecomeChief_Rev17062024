#include "../../VulpeculaEngine/src/darray/darray.h"
#include "../../VulpeculaEngine/src/engine/engine.h"
#include "../../VulpeculaEngine/src/memory/memory.h"
#include "../../VulpeculaEngine/src/sprite/sprite.h"
#include "../../VulpeculaEngine/src/texture/texture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  SEngineApp engineApp = init_vulpecula_engine();
  STexture *texture = load_texture(
      "VulpeculaEngine/resources/placeholders/default128.png", &engineApp);
  SSprite sprite = {.x = 0, .y = 0, .texture = texture};
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      sprite.x = i * 128;
      sprite.y = j * 128;
      array_push_back(&sprite, engineApp.objectPool);
    }
  }
  loop_vulpecula_engine(&engineApp);
  return 0;
}