#ifndef ENGINE
#define ENGINE

#include "engine_defs.h"

#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080

#define ENGINE_SIGNAL_IDLE 0
#define ENGINE_SIGNAL_RUNNING 1
#define ENGINE_SIGNAL_EXIT 2

#define ENGINE_DEFAULT_TEX_0_128 1
#define ENGINE_DEFAULT_TEX_0_128_NAME "DefaultTex128"

SEngineApp init_vulpecula_engine();

void engine_load_resources(SEngineApp *engineApp);

void loop_vulpecula_engine(SEngineApp *engineApp);

void _read_input(SEngineApp *engineApp);

void free_vulpecula_engine(SEngineApp *engineApp);

#endif /* ENGINE */
