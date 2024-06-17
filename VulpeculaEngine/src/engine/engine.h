#ifndef ENGINE
#define ENGINE

#include "engine_defs.h"

#define DEFAULT_WINDOW_WIDTH 1200
#define DEFAULT_WINDOW_HEIGHT 720

#define ENGINE_SIGNAL_IDLE 0
#define ENGINE_SIGNAL_RUNNING 1
#define ENGINE_SIGNAL_EXIT 2

SEngineApp init_vulpecula_engine();

void loop_vulpecula_engine(SEngineApp *engineApp);

void _read_input(SEngineApp *engineApp);

void free_vulpecula_engine(SEngineApp *engineApp);

#endif /* ENGINE */
