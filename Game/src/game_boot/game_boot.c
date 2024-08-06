#include "game_boot.h"
#include "../game_tick/game_tick.h"

#include "SDL_pixels.h"
#include "SDL_render.h"
#include "benchmark/time_benchmark.h"
#include "common/common.h"
#include "darray/darray.h"
#include "engine/engine.h"
#include "gui/layout/layout.h"
#include "gui/style/style.h"
#include "gui/widget/widget.h"
#include "math/fmath.h"
#include "math/frandom.h"
#include "math/noise/noise.h"
#include "math/noise/perlin/perlin.h"
#include "memory/memory.h"
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

  SUILayout *layout0 = ui_create_layout(0);
  array_push_back(&layout0, engineApp.uiPool);

  SStyle *wStyle = alloc_struct(SStyle, ENGINE_MALLOC_AUTO);
  wStyle->display = STYLE_DISPLAY_BLOCK;
  wStyle->alignment = STYLE_DISPLAY_ALIGNMENT_MIDDLE_CEN;
  wStyle->padding = 10;
  SUIWidget *widget0 = ui_create_widget(0, WIDGET_TYPE_ROOT, wStyle, NULL);
  widget0->color.r = 255u;
  widget0->color.g = 0u;
  widget0->color.b = 0u;
  SUIWidget *widget1 = ui_create_widget(0, WIDGET_TYPE_CONTAINER, wStyle, widget0);
  widget1->color.r = 0u;
  widget1->color.g = 255u;
  widget1->color.b = 0u;
  widget1->size.x = 700;
  widget1->size.y = 600;
  SUIWidget *widget2 = ui_create_widget(0, WIDGET_TYPE_CONTAINER, wStyle, widget1);
  widget2->color.r = 0u;
  widget2->color.g = 0u;
  widget2->color.b = 255u;
  widget2->size.x = 200;
  widget2->size.y = 300;
  SUIWidget *widget3 = ui_create_widget(0, WIDGET_TYPE_CONTAINER, wStyle, widget2);
  widget3->color.r = 255u;
  widget3->color.g = 255u;
  widget3->color.b = 0u;
  widget3->size.x = 100;
  widget3->size.y = 100;
  // SUIWidget* widget4 = ui_create_widget(0, WIDGET_TYPE_CONTAINER, w_pos,
  // w_max_size, widget0); widget4->color.r = 255u; widget4->color.g = 255u;
  // widget4->color.b = 255u;

  array_push_back(&widget0, layout0->widgets);
  layout0->_changed = 1;

  loop_vulpecula_engine(&engineApp);
}
