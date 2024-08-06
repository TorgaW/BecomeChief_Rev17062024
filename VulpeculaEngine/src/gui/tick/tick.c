#include "tick.h"
#include "SDL_video.h"
#include "darray/darray.h"
#include "gui/style/style.h"
#include "gui/widget/widget.h"
#include <stdio.h>

// current style support state:
// only 'display: block'
void ui_tick(SEngineApp *engineApp, SUILayout *target) {

  SUIWidget *currentWidget = NULL;
  for (int i = 0; i < target->widgets->size; i++) {
    currentWidget = *array_get_at(target->widgets, SUIWidget *, i);
    _dfs_widgets(currentWidget, engineApp);
  }
}

void _dfs_widgets(SUIWidget *root, SEngineApp *engineApp) {
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < root->children->size; i++) {
    _dfs_widgets(*array_get_at(root->children, SUIWidget *, i), engineApp);
  }

  int wWidth, wHeight;
  SDL_GetWindowSizeInPixels(engineApp->window, &wWidth, &wHeight);

  if (root->style->display == STYLE_DISPLAY_BLOCK) {

    switch (root->type) {
    case WIDGET_TYPE_CONTAINER: {
      root->_renderRectangle.w = root->size.x;
      root->_renderRectangle.h = root->size.y;

      switch (root->parent->style->alignment) {

      case STYLE_DISPLAY_ALIGNMENT_LEFT_UP: {
        root->_renderRectangle.x = root->parent->_renderRectangle.x +
                                   root->position.x +
                                   root->parent->style->padding;
        root->_renderRectangle.y = root->parent->_renderRectangle.y +
                                   root->position.y +
                                   root->parent->style->padding;
      } break;
      case STYLE_DISPLAY_ALIGNMENT_MIDDLE_UP: {
        root->_renderRectangle.x = root->parent->_renderRectangle.x +
                                   root->parent->style->padding +
                                   root->position.x +
                                   (root->parent->_renderRectangle.w - root->parent->style->padding*2) / 2 -
                                   root->size.x / 2;
        root->_renderRectangle.y = root->parent->_renderRectangle.y +
                                   root->position.y +
                                   root->parent->style->padding;
      } break;
      case STYLE_DISPLAY_ALIGNMENT_RIGHT_UP: {
        root->_renderRectangle.x = root->parent->_renderRectangle.x +
                                   root->parent->style->padding +
                                   root->position.x +
                                   (root->parent->_renderRectangle.w - root->parent->style->padding*2) -
                                   root->size.x;
        root->_renderRectangle.y = root->parent->_renderRectangle.y +
                                   root->position.y +
                                   root->parent->style->padding;
      } break;
      case STYLE_DISPLAY_ALIGNMENT_LEFT_CEN: {

      } break;
      case STYLE_DISPLAY_ALIGNMENT_MIDDLE_CEN: {

      } break;
      case STYLE_DISPLAY_ALIGNMENT_RIGHT_CEN: {

      } break;
      case STYLE_DISPLAY_ALIGNMENT_LEFT_DWN: {

      } break;
      case STYLE_DISPLAY_ALIGNMENT_MIDDLE_DWN: {

      } break;
      case STYLE_DISPLAY_ALIGNMENT_RIGHT_DWN: {

      } break;
      }

      //
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