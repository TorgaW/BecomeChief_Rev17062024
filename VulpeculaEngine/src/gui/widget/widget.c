
#include "widget.h"
#include "SDL_rect.h"
#include "darray/darray.h"
#include "memory/memory.h"

SUIWidget* ui_create_widget(int hitTest, EUIWidgetType type, SVec2f position, SVec2f maxSize, SUIWidget* parent)
{
	SUIWidget* widget = engine_malloc(sizeof(SUIWidget), ENGINE_MALLOC_AUTO);
	widget->isHitTestable = hitTest;
	widget->type = type;
	widget->maxSize = maxSize;
	widget->parent = NULL;
	widget->children = NULL;
	widget->color.r = 255u;
	widget->color.g = 255u;
	widget->color.b = 255u;
	widget->color.a = 255u;
	widget->_renderRectangle.w = 0;
	widget->_renderRectangle.h = 0;
	widget->_renderRectangle.x = position.x;
	widget->_renderRectangle.y = position.y;
	return widget;
}