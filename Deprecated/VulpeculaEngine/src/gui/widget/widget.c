
#include "widget.h"
#include "SDL_rect.h"
#include "darray/darray.h"
#include "gui/style/style.h"
#include "math/fmath.h"
#include "memory/memory.h"

SUIWidget *ui_create_widget(int hitTest, EUIWidgetType type, SStyle *style,
                            SUIWidget *parent) {
  SVec2i zVec2i = fmath_zero_vec2i();
  SUIWidget *widget = engine_malloc(sizeof(SUIWidget), ENGINE_MALLOC_AUTO);
  widget->isHitTestable = hitTest;
  widget->visible = 1;
  widget->type = type;
  widget->size = zVec2i;
  widget->position = zVec2i;
  widget->maxSize = zVec2i;
  widget->minSize = zVec2i;
  widget->_renderRectangle.h = 0;
  widget->_renderRectangle.w = 0;
  widget->_renderRectangle.x = 0;
  widget->_renderRectangle.y = 0;
  widget->parent = parent;
  widget->children = array_create(2, sizeof(SUIWidget *));
  widget->color.r = 255u;
  widget->color.g = 255u;
  widget->color.b = 255u;
  widget->color.a = 255u;
  widget->style = style;

  if (parent) {
    array_push_back(&widget, parent->children);
  }

  return widget;
}

void ui_set_widget_style(SUIWidget *src, SStyle *style) {}