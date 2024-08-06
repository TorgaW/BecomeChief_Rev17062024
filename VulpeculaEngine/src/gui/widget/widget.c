
#include "widget.h"
#include "SDL_rect.h"
#include "darray/darray.h"
#include "gui/style/style.h"
#include "memory/memory.h"

SUIWidget* ui_create_widget(int hitTest, EUIWidgetType type, SVec2i position, SVec2i maxSize, SUIWidget* parent)
{
	SUIWidget* widget = engine_malloc(sizeof(SUIWidget), ENGINE_MALLOC_AUTO);
	widget->isHitTestable = hitTest;
	widget->type = type;
	widget->size.x = 0;
	widget->size.y = 0;
	widget->maxSize = maxSize;
	widget->parent = parent;
	widget->children = array_create(2, sizeof(SUIWidget*));
	widget->color.r = 255u;
	widget->color.g = 255u;
	widget->color.b = 255u;
	widget->color.a = 255u;
	widget->_renderRectangle.w = 0;
	widget->_renderRectangle.h = 0;
	widget->_renderRectangle.x = position.x;
	widget->_renderRectangle.y = position.y;
	widget->position = position;
	widget->style = engine_malloc(sizeof(SStyle), ENGINE_MALLOC_AUTO);
	widget->style->display = STYLE_DISPLAY_BLOCK;
	widget->style->alignment = STYLE_DISPLAY_ALIGNMENT_LEFT_UP;
	widget->style->gap = 0;
	widget->style->padding = 0;

	if(parent)
	{
		array_push_back(&widget, parent->children);
	}

	return widget;
}