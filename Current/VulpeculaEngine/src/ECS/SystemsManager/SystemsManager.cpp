#include "SystemsManager.hpp"
#include <algorithm>
#include <vector>

ECSSystemsManager::ECSSystemsManager(){};

ECSSystemsManager::~ECSSystemsManager(){};

void ECSSystemsManager::RemoveSystem(int system_id) {
  ecs_systems_container.erase(
      std::remove_if(ecs_systems_container.begin(), ecs_systems_container.end(),
                     [&system_id](ECSSystem *sys) { return sys->GetECSSystemId() == system_id; }));
}