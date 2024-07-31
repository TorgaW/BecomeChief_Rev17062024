#include "game_boot.h"
#include "../game_tick/game_tick.h"

#include "SDL_pixels.h"
#include "SDL_render.h"
#include "benchmark/time_benchmark.h"
#include "darray/darray.h"
#include "engine/engine.h"
#include "gui/layout/layout.h"
#include "gui/widget/widget.h"
#include "math/fmath.h"
#include "math/frandom.h"
#include "math/noise/noise.h"
#include "math/noise/perlin/perlin.h"
#include "sprite/sprite.h"
#include "texture/texture.h"
#include <SDL2/SDL.h>

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

void game_boot() {
  SEngineApp engineApp = init_vulpecula_engine();
  engine_load_resources(&engineApp);

  engineApp.tickFunction = &game_tick;

  SUILayout* layout0 = ui_create_layout(0);
  array_push_back(&layout0, engineApp.uiPool);

  SUILayout* layout1 = ui_create_layout(0);
  array_push_back(&layout1, engineApp.uiPool);

  SVec2f w_pos = {.x = 0, .y = 0};
  SVec2f w_max_size = {.x = 0, .y = 0};
  SUIWidget* widget0 = ui_create_widget(0, WIDGET_TYPE_CONTAINER, w_pos, w_max_size, NULL);
  widget0->color.r = 255u;
  widget0->color.g = 0u;
  widget0->color.b = 0u;

  array_push_back(widget0, layout0->widgets);

  widget0->color.r = 0u;
  widget0->color.g = 255u;

  array_push_back(widget0, layout1->widgets);

  free(widget0);

  loop_vulpecula_engine(&engineApp);
}
