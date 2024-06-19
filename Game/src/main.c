#include "../../VulpeculaEngine/src/darray/darray.h"
#include "../../VulpeculaEngine/src/engine/engine.h"
#include "../../VulpeculaEngine/src/memory/memory.h"
#include "../../VulpeculaEngine/src/sprite/sprite.h"
#include "../../VulpeculaEngine/src/texture/texture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void ticker(SEngineApp *engineApp) {
  SDL_Rect target = {.x = 0, .y = 0, .h = 128, .w = 128};
  SSprite *current = array_get_at(engineApp->objectPool, SSprite, 0);
  // printf("%s\n", current->texture->name);
  SDL_RenderSetScale(engineApp->renderer, engineApp->camera->zoom,
                     engineApp->camera->zoom);
  int cx = 0;
  int cy = 0;
  for (int i = -100; i < 100; i++) {
    for (int j = -100; j < 100; j++) {
      cx = i*128;
      cy = j*128;
      if(cx < engineApp->camera->x-2000 || cx > engineApp->camera->x+2000) continue;
      if(cy < engineApp->camera->y-2000 || cy > engineApp->camera->y+2000) continue;
      target.x = cx - engineApp->camera->x +
                 (double)DEFAULT_WINDOW_WIDTH / 2.0 / engineApp->camera->zoom;
      target.y = cy - engineApp->camera->y +
                 (double)DEFAULT_WINDOW_HEIGHT / 2.0 / engineApp->camera->zoom;
      // printf("x: %d, y: %d\n", i*128, j*128);
      SDL_RenderCopy(engineApp->renderer, current->texture->sdlTexture, NULL, &target);
    }
  }
}

int main(int argc, char *argv[]) {
  SEngineApp engineApp = init_vulpecula_engine();
  engine_load_resources(&engineApp);
  engineApp.tickFunction = &ticker;
  STexture *texture = get_texture(ENGINE_DEFAULT_TEX_0_128, &engineApp);
  SSprite sprite = {.x = 0, .y = 0, .texture = texture};
  array_push_back(&sprite, engineApp.objectPool);
  loop_vulpecula_engine(&engineApp);
  return 0;
}