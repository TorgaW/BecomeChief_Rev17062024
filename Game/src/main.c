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
  engine_load_resources(&engineApp);
  STexture *texture = get_texture_by_name(ENGINE_DEFAULT_TEX_128_NAME, &engineApp);
  SSprite sprite = {.x = 0, .y = 0, .texture = texture};
  for (int i = -2000; i < 2000; i++) {
    for (int j = -2000; j < 2000; j++) {
      sprite.x = i * 128;
      sprite.y = j * 128;
      array_push_back(&sprite, engineApp.objectPool);
    }
  }
  loop_vulpecula_engine(&engineApp);
  return 0;
}