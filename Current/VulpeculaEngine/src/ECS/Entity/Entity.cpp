#include "Entity.hpp"
#include <algorithm>

void ECSEntity::RemoveComponentById(int compId) {
  auto foundComponent = this->GetComponent<ECSComponent>(compId);
  if (foundComponent != nullptr) {
    ecs_components.erase(std::remove_if(ecs_components.begin(), ecs_components.end(),
                                        [&compId](ECSComponent *comp) { return comp->GetECSComponentId() == compId; }));
  }
};

ECSEntity::ECSEntity(){};
ECSEntity::~ECSEntity(){};