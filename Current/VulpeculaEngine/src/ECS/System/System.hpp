#ifndef ENGINE_ECS_SYSTEM
#define ENGINE_ECS_SYSTEM

#include "../../CoreMetrics/CoreMetrics.hpp"
#include <functional>
class ECSSystem {
public:
  ECSSystem();
  ECSSystem(ECSSystem &&) = default;
  ECSSystem(const ECSSystem &) = default;
  ECSSystem &operator=(ECSSystem &&) = default;
  ECSSystem &operator=(const ECSSystem &) = default;
  ~ECSSystem();

protected:
  std::function<void(EngineAppGraphics *, EngineAppMetrics *)> ecs_system_invoke_handler;
  int ecs_system_id;
  bool ecs_system_enabled = true;

public:
  inline int GetECSSystemId() { return ecs_system_id; };

  inline bool GetECSSystemIsEnabled() { return ecs_system_enabled; };

  inline void SetECSSystemIsEnabled(bool enabled) { ecs_system_enabled = enabled; };

  inline void Invoke(EngineAppGraphics *graphics, EngineAppMetrics *metrics) {
    ecs_system_invoke_handler(graphics, metrics);
  };

  inline void SetupInvokeHandler(std::function<void(EngineAppGraphics *, EngineAppMetrics *)> func) {
    ecs_system_invoke_handler = func;
  };
};

#endif /* ENGINE_ECS_SYSTEM */
