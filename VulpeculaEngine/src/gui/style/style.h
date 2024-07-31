#ifndef STYLE
#define STYLE

#include "math/fmath.h"
typedef enum SStyleFlexDirection {
  FLEX_DIRECTION_ROW,
  FLEX_DIRECTION_COLUMN
} SStyleFlexDirection;

typedef enum SStyleFlexJustify {
  FLEX_JUSTIFY_START,
  FLEX_JUSTIFY_END,
  FLEX_JUSTIFY_CENTER
} SStyleFlexJustify;

typedef enum SStyleFlexAlign {
  FLEX_ALIGN_START,
  FLEX_ALIGN_END,
  FLEX_ALIGN_CENTER
} SStyleFlexAlign;

typedef struct SStyle {
  SStyleFlexDirection flexDirection;
  SStyleFlexJustify flexJustify;
  SStyleFlexAlign flexAlign;
  int gap;
  SVec4i padding;
} SStyle;

#endif /* STYLE */
