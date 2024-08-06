#ifndef STYLE
#define STYLE

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

typedef enum SStyleDisplay
{
  STYLE_DISPLAY_BLOCK,
  STYLE_DISPLAY_FLEX
} SStyleDisplay;

//alignment for children
typedef enum SStyleDisplayAlignment
{
  STYLE_DISPLAY_ALIGNMENT_LEFT_UP,
  STYLE_DISPLAY_ALIGNMENT_MIDDLE_UP,
  STYLE_DISPLAY_ALIGNMENT_RIGHT_UP,
  STYLE_DISPLAY_ALIGNMENT_LEFT_CEN,
  STYLE_DISPLAY_ALIGNMENT_MIDDLE_CEN,
  STYLE_DISPLAY_ALIGNMENT_RIGHT_CEN,
  STYLE_DISPLAY_ALIGNMENT_LEFT_DWN,
  STYLE_DISPLAY_ALIGNMENT_MIDDLE_DWN,
  STYLE_DISPLAY_ALIGNMENT_RIGHT_DWN
} SStyleDisplayAlignment;

typedef struct SStyle {
  SStyleDisplay display;
  SStyleDisplayAlignment alignment;
  SStyleFlexDirection flexDirection;
  SStyleFlexJustify flexJustify;
  SStyleFlexAlign flexAlign;
  int gap;
  int padding;
} SStyle;

#endif /* STYLE */
