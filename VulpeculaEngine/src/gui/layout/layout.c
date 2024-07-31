#include "layout.h"
#include "darray/darray.h"
#include "gui/widget/widget.h"
#include "memory/memory.h"

SUILayout* ui_create_layout(int zOrder)
{
	SUILayout* layout = engine_malloc(sizeof(SUILayout), ENGINE_MALLOC_AUTO);
	layout->widgets = array_create(32, sizeof(SUIWidget));
	layout->zOrder = zOrder;
	return layout;
}