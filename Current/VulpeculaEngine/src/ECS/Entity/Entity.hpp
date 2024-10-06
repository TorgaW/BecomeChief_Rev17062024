#ifndef ENGINE_ECS_ENTITY
#define ENGINE_ECS_ENTITY

#include "../Component/Component.hpp"
#include <algorithm>
#include <vector>

class ECSEntity {
public:
  ECSEntity();
  ECSEntity(ECSEntity &&) = default;
  ECSEntity(const ECSEntity &) = default;
  ECSEntity &operator=(ECSEntity &&) = default;
  ECSEntity &operator=(const ECSEntity &) = default;
  ~ECSEntity();

protected:
  int ecs_entity_id;
  std::vector<ECSComponent *> ecs_components;

public:
  inline int GetECSEntityId() { return ecs_entity_id; };

  inline std::vector<ECSComponent *> GetComponents() { return ecs_components; };

  inline void AddComponent(ECSComponent *comp) { ecs_components.push_back(comp); };

  void RemoveComponentById(int compId);

  template <class T> T *GetComponent(int id) {
    auto found = std::find_if(ecs_components.begin(), ecs_components.end(), [&id](ECSComponent *comp) {
      return comp->GetECSComponentId() == id && comp->GetECSComponentIsEnabled();
    });
    if (found == ecs_components.end()) {
      return nullptr;
    }
    return *found;
  };
};
#endif /* ENGINE_ECS_ENTITY */
