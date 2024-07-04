#include "game_tick.h"

#include "darray/darray.h"
#include "engine/engine.h"
#include "sprite/sprite.h"

#include "math/frandom.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void game_tick(SEngineApp *engineApp) {
  SDL_Rect target = {.x = 0, .y = 0, .h = 128, .w = 128};
  SSprite *current = array_get_at(engineApp->objectPool, SSprite, 0);
  // printf("%s\n", current->texture->name);
  SDL_RenderSetScale(engineApp->renderer, engineApp->camera->zoom,
                     engineApp->camera->zoom);
  int cx = 0;
  int cy = 0;
  // for (int i = -3000; i < 3000; i++) {
  //   for (int j = -3000; j < 3000; j++) {
  //     cx = i * 128;
  //     cy = j * 128;
  //     if (cx < engineApp->camera->x - ((double)DEFAULT_WINDOW_WIDTH*2+128) || cx > engineApp->camera->x + ((double)DEFAULT_WINDOW_WIDTH*2+128))
  //       continue;
  //     if (cy < engineApp->camera->y - ((double)DEFAULT_WINDOW_HEIGHT*2+128) || cy > engineApp->camera->y + ((double)DEFAULT_WINDOW_HEIGHT*2+128))
  //       continue;
  //     target.x = cx - engineApp->camera->x +
  //                (double)DEFAULT_WINDOW_WIDTH / 2.0 / engineApp->camera->zoom;
  //     target.y = cy - engineApp->camera->y +
  //                (double)DEFAULT_WINDOW_HEIGHT / 2.0 / engineApp->camera->zoom;
  //     // printf("x: %d, y: %d\n", i*128, j*128);
  //     SDL_RenderCopy(engineApp->renderer, current->texture->sdlTexture, NULL,
  //                    &target);
  //   }
  // }
}