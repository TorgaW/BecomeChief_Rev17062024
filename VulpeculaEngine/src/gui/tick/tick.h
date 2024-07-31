#ifndef TICK
#define TICK

/**
 * @brief Contains all sorts of tick functions for GUI
 * 
 */
#include "engine/engine_defs.h"
#include "gui/layout/layout.h"
#include "gui/widget/widget.h"


void ui_tick(SEngineApp* engineApp, SUILayout* target);

void _dfs_widgets(SUIWidget* root, SEngineApp *engineApp);


#endif /* TICK */
