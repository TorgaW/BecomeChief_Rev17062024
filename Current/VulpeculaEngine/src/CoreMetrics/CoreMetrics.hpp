#ifndef ENGINE_CORE_METRICS
#define ENGINE_CORE_METRICS

#include <SDL2/SDL.h>
#include <cstddef>

#define ENGINE_SIGNAL_INITIALIZED 0
#define ENGINE_SIGNAL_RUNNING 1
#define ENGINE_SIGNAL_EXIT 2

struct EngineAppGraphics {
  SDL_Renderer *renderer;
  SDL_Window *window;
};

struct EngineAppMetrics {
  size_t framesCount;
  double framesDelta;
  double framesPerSecond;
  int engine_signal;
};

#endif /* ENGINE_CORE_METRICS */
