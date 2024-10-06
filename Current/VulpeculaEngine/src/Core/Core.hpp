#ifndef ENGINE_CORE
#define ENGINE_CORE

#include <SDL2/SDL.h>

#include <cstddef>
#include <functional>

#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080

#define ENGINE_SIGNAL_INITIALIZED 0
#define ENGINE_SIGNAL_LOOPING 1
#define ENGINE_SIGNAL_EXIT 2

struct EngineAppGraphics {
  SDL_Renderer *renderer;
  SDL_Window *window;
};

struct EngineAppMetrics {
  size_t framesCount;
  double framesDelta;
  double framesPerSecond;
};

class EngineApp {
public:
  EngineApp();
  EngineApp(EngineApp &&) = default;
  EngineApp(const EngineApp &) = default;
  EngineApp &operator=(EngineApp &&) = default;
  EngineApp &operator=(const EngineApp &) = default;
  ~EngineApp();

  // inits engine before start working
  bool Init();
  // starts engine loop with custom function
  void StartEngineLoop(std::function<void(EngineAppGraphics *)> updateFunc);

  // getter for 'graphics' variable
  inline EngineAppGraphics *GetGraphics() { return &this->graphics; };

  // getter for 'metrics' variable
  inline EngineAppMetrics *GetMetrics() { return &this->metrics; };

private:
  // graphics struct reference
  EngineAppGraphics graphics{nullptr, nullptr};
  // engine metrics
  EngineAppMetrics metrics{0, 0, 0};

  // ref to custom update function
  std::function<void(EngineAppGraphics *)> side_updater;

  // current engine signal
  int engine_signal = -1;

  // main loop function
  void Loop();
};

#endif /* ENGINE_CORE */
