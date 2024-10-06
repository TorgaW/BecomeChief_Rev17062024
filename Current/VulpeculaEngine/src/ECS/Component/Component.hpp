#ifndef ENGINE_ECS_COMPONENT
#define ENGINE_ECS_COMPONENT

class ECSComponent {
public:
  ECSComponent();
  ECSComponent(ECSComponent &&) = default;
  ECSComponent(const ECSComponent &) = default;
  ECSComponent &operator=(ECSComponent &&) = default;
  ECSComponent &operator=(const ECSComponent &) = default;
  ~ECSComponent();

protected:
  int ecs_comp_id;
  bool ecs_comp_enabled = true;

public:
  inline int GetECSComponentId() { return ecs_comp_id; };

  inline bool GetECSComponentIsEnabled() { return ecs_comp_enabled; };

  inline void SetECSComponentIsEnabled(bool enabled) { ecs_comp_enabled = enabled; };
};

#endif /* ENGINE_ECS_COMPONENT */
