#ifndef RENDERINGERASERSYSTEM
#define RENDERINGERASERSYSTEM

#include "CoreMetrics/CoreMetrics.hpp"
#include "ECS/System/System.hpp"

class RenderingEraserSystem : public ECSSystem {
public:
  RenderingEraserSystem();
  RenderingEraserSystem(RenderingEraserSystem &&) = default;
  RenderingEraserSystem(const RenderingEraserSystem &) = default;
  RenderingEraserSystem &operator=(RenderingEraserSystem &&) = default;
  RenderingEraserSystem &operator=(const RenderingEraserSystem &) = default;
  ~RenderingEraserSystem();

private:
  static void EraseWindow(EngineAppGraphics *graphics, EngineAppMetrics *metrics);
};

#endif /* RENDERINGERASERSYSTEM */
