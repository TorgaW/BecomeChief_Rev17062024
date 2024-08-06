#ifndef STYLE
#define STYLE

// typedef enum SStyleFlexDirection {
//   FLEX_DIRECTION_ROW,
//   FLEX_DIRECTION_COLUMN
// } SStyleFlexDirection;

// typedef enum SStyleFlexJustify {
//   FLEX_JUSTIFY_START,
//   FLEX_JUSTIFY_END,
//   FLEX_JUSTIFY_CENTER
// } SStyleFlexJustify;

// typedef enum SStyleFlexAlign {
//   FLEX_ALIGN_START,
//   FLEX_ALIGN_END,
//   FLEX_ALIGN_CENTER
// } SStyleFlexAlign;

//only 'display: block' supported for now
typedef enum SStyleDisplay
{
  STYLE_DISPLAY_BLOCK,
  // STYLE_DISPLAY_FLEX
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
  //type of an alignment
  SStyleDisplay display;
  SStyleDisplayAlignment alignment;
  //does element fill all free space
  int fillWidth;
  //does element fill all free space
  int fillHeight;

  // int gap;
  
  //padding for children elements
  int padding;
} SStyle;

#endif /* STYLE */
