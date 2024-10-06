#include "RenderingEraserSystem.hpp"
#include "ECS/SystemsDictionary/SystemsDictionary.hpp"
#include "SDL_render.h"

#include <iostream>

RenderingEraserSystem::RenderingEraserSystem() {
  ecs_system_id = EngineSystemsIDs::ENGINE_SYSTEM_RENDERING_ERASER;
  ecs_system_enabled = true;
  ecs_system_invoke_handler = &RenderingEraserSystem::EraseWindow;
};

RenderingEraserSystem::~RenderingEraserSystem(){};

void RenderingEraserSystem::EraseWindow(EngineAppGraphics *graphics, EngineAppMetrics *metrics) {
  SDL_SetRenderDrawColor(graphics->renderer, 0, 0, 0, 255);
  SDL_RenderClear(graphics->renderer);
  std::cout << metrics->framesPerSecond << "\n";
}