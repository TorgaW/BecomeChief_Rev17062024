#ifndef SYSTEMSMANAGER
#define SYSTEMSMANAGER

#include "../System/System.hpp"
#include <vector>

class ECSSystemsManager {
public:
  ECSSystemsManager();
  ECSSystemsManager(ECSSystemsManager &&) = default;
  ECSSystemsManager(const ECSSystemsManager &) = default;
  ECSSystemsManager &operator=(ECSSystemsManager &&) = default;
  ECSSystemsManager &operator=(const ECSSystemsManager &) = default;
  ~ECSSystemsManager();

private:
  std::vector<ECSSystem *> ecs_systems_container;

public:
  inline void AddSystem(ECSSystem *system) { ecs_systems_container.push_back(system); };

  void RemoveSystem(int system_id);

  inline void InvokeAllEnabled(EngineAppGraphics *graphics, EngineAppMetrics *metrics) {
    for (auto sys : ecs_systems_container) {
      if (sys->GetECSSystemIsEnabled()) {
        sys->Invoke(graphics, metrics);
      }
    }
  };

  inline void InvokeAll(EngineAppGraphics *graphics, EngineAppMetrics *metrics) {
    for (auto sys : ecs_systems_container) {
      sys->Invoke(graphics, metrics);
    }
  };
};

#endif /* SYSTEMSMANAGER */
