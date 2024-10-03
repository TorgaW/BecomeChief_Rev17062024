#ifndef LAYOUT
#define LAYOUT

#include "darray/darray.h"

typedef struct SUILayout {
	SArray* widgets;
	int zOrder;
	int _changed;
} SUILayout;

SUILayout* ui_create_layout(int zOrder);

#endif /* LAYOUT */
