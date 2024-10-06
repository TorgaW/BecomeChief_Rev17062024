#ifndef ENGINE_INPUT_SYSTEM
#define ENGINE_INPUT_SYSTEM

#include "CoreMetrics/CoreMetrics.hpp"
#include "ECS/System/System.hpp"

class InputSystem : public ECSSystem {
public:
  InputSystem();
  InputSystem(InputSystem &&) = default;
  InputSystem(const InputSystem &) = default;
  InputSystem &operator=(InputSystem &&) = default;
  InputSystem &operator=(const InputSystem &) = default;
  ~InputSystem();

private:
  static void ReadInput(EngineAppGraphics *graphics, EngineAppMetrics *metrics);
};

#endif /* ENGINE_INPUT_SYSTEM */
