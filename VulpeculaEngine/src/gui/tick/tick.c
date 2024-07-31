#include "tick.h"
#include "darray/darray.h"
#include "gui/widget/widget.h"
#include <stdio.h>

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

  switch (root->type) {
  case WIDGET_TYPE_CONTAINER: {
    if (root->children->size == 0) {
      root->_contentSize.x = root->minSize.x;
      root->_contentSize.y = root->minSize.y;
    }
  } break;
  case WIDGET_TYPE_IMAGE:
  case WIDGET_TYPE_TEXT:
  case WIDGET_TYPE_BUTTON:
  case WIDGET_TYPE_INPUT_TEXT:
  case WIDGET_TYPE_INPUT_SELECT:
  case WIDGET_TYPE_VERT_SCROLL:
    break;
  case WIDGET_TYPE_ROOT: {
    int windowWidth, windowHeight;
    SDL_GetWindowSizeInPixels(engineApp->window, &windowWidth, &windowHeight);
    root->_renderRectangle.w = windowWidth;
    root->_renderRectangle.h = windowHeight;
    SUIWidget *current = NULL;
	int gap = 100;
	int padding = 100;
    for (int i = 0; i < root->children->size; i++) {
      // only for flex row
      current = *array_get_at(root->children, SUIWidget *, i);
      current->_renderRectangle.w = ((windowWidth - padding*2 - gap * (root->children->size - 1)) / root->children->size);
      current->_renderRectangle.x =
          (i * ((windowWidth - 100) / root->children->size) + padding);
      current->_renderRectangle.y = padding;
      current->_renderRectangle.h = windowHeight - padding*2;
    }
  } break;
  }
  SDL_SetRenderDrawColor(engineApp->renderer, root->color.r, root->color.g,
                         root->color.b, root->color.a);
  SDL_RenderDrawRect(engineApp->renderer, &root->_renderRectangle);
}