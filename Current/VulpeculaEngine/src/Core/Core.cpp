#include "Core.hpp"
#include "SDL_render.h"
#include "Systems/Input/InputSystem.hpp"
#include "Systems/Rendering/Eraser/RenderingEraserSystem.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

EngineApp::EngineApp() {}

EngineApp::~EngineApp() {}

bool EngineApp::Init() {
  int rendererFlags, windowFlags;
  rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
  windowFlags = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Couldn't initialize SDL: " << SDL_GetError() << "\n";
    return false;
  }

  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) <= 0) {
    std::cout << "Couldn't initialize SDL_Image: " << IMG_GetError() << "\n";
    return false;
  }

  graphics.window = SDL_CreateWindow("Become Chief Rev17062024", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, windowFlags);

  if (!graphics.window) {
    std::cout << "Failed to open window: " << SDL_GetError() << "\n";
    return false;
  }

  graphics.renderer = SDL_CreateRenderer(graphics.window, -1, rendererFlags);

  if (!graphics.renderer) {
    std::cout << "Failed to init renderer: " << SDL_GetError() << "\n";
    return false;
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

  InputSystem *inputSystem = new InputSystem();
  ecs_systems_manager.AddSystem(inputSystem);

  RenderingEraserSystem *renderingErasingSystem = new RenderingEraserSystem();
  ecs_systems_manager.AddSystem(renderingErasingSystem);

  return true;
}

void EngineApp::StartEngineLoop() {
  metrics.engine_signal = ENGINE_SIGNAL_RUNNING;
  Loop();
}

void EngineApp::Loop() {
  uint64_t tNow = SDL_GetPerformanceCounter();
  uint64_t tLast = 0;
  while (metrics.engine_signal == ENGINE_SIGNAL_RUNNING) {
    tLast = tNow;
    tNow = SDL_GetPerformanceCounter();
    metrics.framesDelta = (double)((tNow - tLast) * 1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;
    metrics.framesPerSecond = 1 / metrics.framesDelta;
    ecs_systems_manager.InvokeAllEnabled(&graphics, &metrics);
    SDL_RenderPresent(graphics.renderer);
  }
}