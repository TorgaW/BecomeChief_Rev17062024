#include "InputSystem.hpp"
#include "CoreMetrics/CoreMetrics.hpp"
#include "ECS/SystemsDictionary/SystemsDictionary.hpp"
#include "SDL_events.h"
#include "Systems/Input/Facade/InputSystemFacade.hpp"
#include <functional>

InputSystem::InputSystem() {
  ecs_system_id = EngineSystemsIDs::ENGINE_SYSTEM_INPUT;
  ecs_system_enabled = true;
  ecs_system_invoke_handler = InputSystem::ReadInput;
};

InputSystem::~InputSystem(){};

void InputSystem::ReadInput(EngineAppGraphics *graphics, EngineAppMetrics *metrics) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT: {
      metrics->engine_signal = ENGINE_SIGNAL_EXIT; // exit signal
    } break;
    case SDL_KEYDOWN: {
      InputSystemFacade::keyboard_keys[event.key.keysym.scancode] = 1;
    } break;
    case SDL_KEYUP: {
      InputSystemFacade::keyboard_keys[event.key.keysym.scancode] = 0;
    } break;
    // case SDL_MOUSEBUTTONDOWN: {
    //   switch (event.button.button) {
    //   case SDL_BUTTON_LEFT: {
    //     engineApp->mouse->buttons[0] = 1;
    //   } break;
    //   case SDL_BUTTON_RIGHT: {
    //     engineApp->mouse->buttons[1] = 1;
    //   } break;
    //   }
    // } break;
    // case SDL_MOUSEBUTTONUP: {
    //   switch (event.button.button) {
    //   case SDL_BUTTON_LEFT: {
    //     engineApp->mouse->buttons[0] = 0;
    //   } break;
    //   case SDL_BUTTON_RIGHT: {
    //     engineApp->mouse->buttons[1] = 0;
    //   } break;
    //   }
    // } break;
    // case SDL_MOUSEWHEEL: {
    //   engineApp->mouse->wheel = event.wheel.y;
    // } break;
    default:
      break;
    }
  }
}