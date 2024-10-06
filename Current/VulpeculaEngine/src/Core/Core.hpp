#ifndef CORE
#define CORE

#include "../CoreMetrics/CoreMetrics.hpp"
#include "ECS/SystemsManager/SystemsManager.hpp"
#include <SDL2/SDL.h>

#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080

class EngineApp {
public:
  EngineApp();
  EngineApp(EngineApp &&) = default;
  EngineApp(const EngineApp &) = default;
  EngineApp &operator=(EngineApp &&) = default;
  EngineApp &operator=(const EngineApp &) = default;
  ~EngineApp();

  // inits engine before start working
  static bool Init();
  // starts engine loop with custom function
  static void StartEngineLoop();

  // getter for 'graphics' variable
  static inline EngineAppGraphics *GetGraphics() { return &graphics; };

  // getter for 'metrics' variable
  static inline EngineAppMetrics *GetMetrics() { return &metrics; };

  static inline ECSSystemsManager ecs_systems_manager;

private:
  // graphics struct reference
  static inline EngineAppGraphics graphics{nullptr, nullptr};
  // engine metrics
  static inline EngineAppMetrics metrics{0, 0, 0};

  // main loop function
  static void Loop();
};

#endif /* CORE */
