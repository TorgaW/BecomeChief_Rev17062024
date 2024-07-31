#ifndef LAYOUT
#define LAYOUT

#include "darray/darray.h"

typedef struct SUILayout {
	SArray* widgets;
	int zOrder;
} SUILayout;

SUILayout* ui_create_layout(int zOrder);

#endif /* LAYOUT */
