#include "tick.h"
#include "SDL_video.h"
#include "darray/darray.h"
#include "gui/style/style.h"
#include "gui/widget/widget.h"
#include <stdio.h>

// current style support state:
// only 'display: block'
void ui_tick(SEngineApp *engineApp, SUILayout *target) {
  if (target->_changed == 0)
    return;

  SUIWidget *currentWidget = NULL;
  for (int i = 0; i < target->widgets->size; i++) {
    currentWidget = *array_get_at(target->widgets, SUIWidget *, i);
    _dfs_widgets(currentWidget, engineApp);
  }

  target->_changed = 0;
}

void _dfs_widgets(SUIWidget *root, SEngineApp *engineApp) {
  if (root == NULL) {
    return;
  }
  
  int wWidth, wHeight;
  SDL_GetWindowSizeInPixels(engineApp->window, &wWidth, &wHeight);
  if (root->style->display == STYLE_DISPLAY_BLOCK) {

    switch (root->type) {
    case WIDGET_TYPE_CONTAINER: {
      root->_renderRectangle.w = root->size.x;
      root->_renderRectangle.h = root->size.y;

      _block_align_container(root);

    } break;
    case WIDGET_TYPE_IMAGE: {

    } break;
    case WIDGET_TYPE_TEXT: {

    } break;
    case WIDGET_TYPE_BUTTON: {

    } break;
    case WIDGET_TYPE_INPUT_TEXT: {

    } break;
    case WIDGET_TYPE_INPUT_SELECT: {

    } break;
    case WIDGET_TYPE_VERT_SCROLL: {

    } break;
    case WIDGET_TYPE_ROOT: {
      root->_renderRectangle.w = wWidth;
      root->_renderRectangle.h = wHeight;
      root->_renderRectangle.x = 0;
      root->_renderRectangle.y = 0;
    } break;
    }
  }

  for (int i = 0; i < root->children->size; i++) {
    _dfs_widgets(*array_get_at(root->children, SUIWidget *, i), engineApp);
  }
}

void _block_align_container(SUIWidget *src) {

  switch (src->parent->style->alignment) {

  case STYLE_DISPLAY_ALIGNMENT_LEFT_UP: {
    src->_renderRectangle.x = src->parent->_renderRectangle.x +
                              src->position.x + src->parent->style->padding;
    src->_renderRectangle.y = src->parent->_renderRectangle.y +
                              src->position.y + src->parent->style->padding;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_MIDDLE_UP: {
    src->_renderRectangle.x =
        src->parent->_renderRectangle.x + src->parent->style->padding +
        src->position.x +
        (src->parent->_renderRectangle.w - src->parent->style->padding * 2) /
            2 -
        src->size.x / 2;
    src->_renderRectangle.y = src->parent->_renderRectangle.y +
                              src->position.y + src->parent->style->padding;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_RIGHT_UP: {
    src->_renderRectangle.x =
        src->parent->_renderRectangle.x + src->parent->style->padding +
        src->position.x +
        (src->parent->_renderRectangle.w - src->parent->style->padding * 2) -
        src->size.x;
    src->_renderRectangle.y = src->parent->_renderRectangle.y +
                              src->position.y + src->parent->style->padding;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_LEFT_CEN: {
    src->_renderRectangle.x = src->parent->_renderRectangle.x +
                              src->position.x + src->parent->style->padding;
    src->_renderRectangle.y =
        src->parent->_renderRectangle.y + src->position.y +
        src->parent->style->padding +
        (src->parent->_renderRectangle.h - src->parent->style->padding * 2) /
            2 -
        src->size.y / 2;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_MIDDLE_CEN: {
    src->_renderRectangle.x =
        src->parent->_renderRectangle.x + src->parent->style->padding +
        src->position.x +
        (src->parent->_renderRectangle.w - src->parent->style->padding * 2) /
            2 -
        src->size.x / 2;
    src->_renderRectangle.y =
        src->parent->_renderRectangle.y + src->position.y +
        src->parent->style->padding +
        (src->parent->_renderRectangle.h - src->parent->style->padding * 2) /
            2 -
        src->size.y / 2;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_RIGHT_CEN: {
    src->_renderRectangle.x =
        src->parent->_renderRectangle.x + src->parent->style->padding +
        src->position.x +
        (src->parent->_renderRectangle.w - src->parent->style->padding * 2) -
        src->size.x;
    src->_renderRectangle.y =
        src->parent->_renderRectangle.y + src->position.y +
        src->parent->style->padding +
        (src->parent->_renderRectangle.h - src->parent->style->padding * 2) /
            2 -
        src->size.y / 2;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_LEFT_DWN: {
    src->_renderRectangle.x = src->parent->_renderRectangle.x +
                              src->position.x + src->parent->style->padding;
    src->_renderRectangle.y =
        src->parent->_renderRectangle.y + src->parent->style->padding +
        src->position.y +
        (src->parent->_renderRectangle.h - src->parent->style->padding * 2) -
        src->size.y;

  } break;
  case STYLE_DISPLAY_ALIGNMENT_MIDDLE_DWN: {
    src->_renderRectangle.x =
        src->parent->_renderRectangle.x + src->parent->style->padding +
        src->position.x +
        (src->parent->_renderRectangle.w - src->parent->style->padding * 2) /
            2 -
        src->size.x / 2;
    src->_renderRectangle.y =
        src->parent->_renderRectangle.y + src->parent->style->padding +
        src->position.y +
        (src->parent->_renderRectangle.h - src->parent->style->padding * 2) -
        src->size.y;
  } break;
  case STYLE_DISPLAY_ALIGNMENT_RIGHT_DWN: {
    src->_renderRectangle.x =
        src->parent->_renderRectangle.x + src->parent->style->padding +
        src->position.x +
        (src->parent->_renderRectangle.w - src->parent->style->padding * 2) -
        src->size.x;
    src->_renderRectangle.y =
        src->parent->_renderRectangle.y + src->parent->style->padding +
        src->position.y +
        (src->parent->_renderRectangle.h - src->parent->style->padding * 2) -
        src->size.y;
  } break;
  }
}

// RENDERING

void ui_render(SEngineApp *engineApp, SUILayout *target) {
  SUIWidget *currentWidget = NULL;
  for (int i = 0; i < target->widgets->size; i++) {
    currentWidget = *array_get_at(target->widgets, SUIWidget *, i);
    _dfs_widgets_render(currentWidget, engineApp);
  }
}

void _dfs_widgets_render(SUIWidget *root, SEngineApp *engineApp) {
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < root->children->size; i++) {
    _dfs_widgets_render(*array_get_at(root->children, SUIWidget *, i),
                        engineApp);
  }

  SDL_SetRenderDrawColor(engineApp->renderer, root->color.r, root->color.g,
                         root->color.b, root->color.a);
  SDL_RenderDrawRect(engineApp->renderer, &root->_renderRectangle);
}