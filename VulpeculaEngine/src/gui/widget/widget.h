#ifndef WIDGET
#define WIDGET

#include "SDL_rect.h"
#include "darray/darray.h"
#include "math/fmath.h"

typedef enum EUIWidgetType 
{
	WIDGET_TYPE_CONTAINER,
	WIDGET_TYPE_IMAGE,
	WIDGET_TYPE_TEXT,
	WIDGET_TYPE_BUTTON,
	WIDGET_TYPE_CANVAS
} EUIWidgetType;

typedef struct SUIWidget {
	int isHitTestable;
	EUIWidgetType type;
	SVec2f maxSize; //x - max width, y - max height; 0,0 means infinite
	struct SUIWidget* parent;
	SArray* children;
	SColorRGBA color;
	SDL_Rect _renderRectangle;
} SUIWidget;

SUIWidget* ui_create_widget(int hitTest, EUIWidgetType type, SVec2f position, SVec2f maxSize, SUIWidget* parent);

#endif /* WIDGET */
