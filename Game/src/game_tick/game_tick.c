#include "game_tick.h"

#include "SDL_render.h"
#include "darray/darray.h"
#include "engine/engine.h"
#include "sprite/sprite.h"

#include "math/frandom.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

void game_tick(SEngineApp *engineApp) {
  SDL_Rect target = {.x = 0, .y = 0, .h = 1024, .w = 1024};
  SSprite *current = array_get_at(engineApp->objectPool, SSprite, 0);
  // SDL_ScaleMode mode;
  // SDL_GetTextureScaleMode(engineApp->testNoise, &mode);
  // printf("mode: %u", mode);
  // printf("%s\n", current->texture->name);
  SDL_RenderSetScale(engineApp->renderer, engineApp->camera->zoom,
                     engineApp->camera->zoom);
  int cx = 0;
  int cy = 0;
  // for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      // cx = i * 16;
      // cy = j * 16;
      if (cx < engineApp->camera->x - ((float)DEFAULT_WINDOW_WIDTH*2+1024) || cx > engineApp->camera->x + ((float)DEFAULT_WINDOW_WIDTH*2+1024))
        continue;
      if (cy < engineApp->camera->y - ((float)DEFAULT_WINDOW_HEIGHT*2+1024) || cy > engineApp->camera->y + ((float)DEFAULT_WINDOW_HEIGHT*2+1024))
        continue;
      target.x = cx - engineApp->camera->x +
                 (float)DEFAULT_WINDOW_WIDTH / 2.0 / engineApp->camera->zoom;
      target.y = cy - engineApp->camera->y +
                 (float)DEFAULT_WINDOW_HEIGHT / 2.0 / engineApp->camera->zoom;
      // printf("x: %d, y: %d\n", i*128, j*128);
      SDL_RenderCopy(engineApp->renderer, engineApp->testNoise, NULL,
                     &target);
    }
  // }
}