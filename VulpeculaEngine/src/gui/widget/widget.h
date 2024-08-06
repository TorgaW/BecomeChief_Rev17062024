#ifndef WIDGET
#define WIDGET

#include "SDL_rect.h"
#include "darray/darray.h"
#include "gui/style/style.h"
#include "math/fmath.h"

typedef enum EUIWidgetType 
{
	WIDGET_TYPE_CONTAINER,
	WIDGET_TYPE_IMAGE,
	WIDGET_TYPE_TEXT,
	WIDGET_TYPE_BUTTON,
	WIDGET_TYPE_INPUT_TEXT,
	WIDGET_TYPE_INPUT_SELECT,
	WIDGET_TYPE_VERT_SCROLL,
	WIDGET_TYPE_ROOT
} EUIWidgetType;

typedef struct SUIWidget {
	int isHitTestable;
	EUIWidgetType type;
	SVec2i size;
	SVec2i position;
	SVec2i maxSize; //x - max width, y - max height; 0,0 means infinite
	SVec2i minSize; //x - min width, y - min height
	struct SUIWidget* parent;
	SArray* children;
	SColorRGBA color;
	SDL_Rect _renderRectangle;
	SVec2i _contentSize;
	SStyle* style;
} SUIWidget;

SUIWidget* ui_create_widget(int hitTest, EUIWidgetType type, SVec2i position, SVec2i maxSize, SUIWidget* parent);

#endif /* WIDGET */
