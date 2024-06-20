#include "game_boot.h"
#include "../game_tick/game_tick.h"

#include "texture/texture.h"
#include "sprite/sprite.h"
#include "engine/engine.h"
#include "darray/darray.h"

#include <sys/types.h>

void game_boot() {
  SEngineApp engineApp = init_vulpecula_engine();
  engine_load_resources(&engineApp);

  engineApp.tickFunction = &game_tick;
  
  STexture *texture = get_texture(ENGINE_DEFAULT_TEX_0_128, &engineApp);
  SSprite sprite = {.x = 0, .y = 0, .texture = texture};
  array_push_back(&sprite, engineApp.objectPool);
  loop_vulpecula_engine(&engineApp);
}
