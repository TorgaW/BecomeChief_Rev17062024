#ifndef ENGINE_INPUT_SYSTEM_FACADE
#define ENGINE_INPUT_SYSTEM_FACADE

#include <SDL2/SDL.h>

class InputSystemFacade {
public:
  InputSystemFacade();
  InputSystemFacade(InputSystemFacade &&) = default;
  InputSystemFacade(const InputSystemFacade &) = default;
  InputSystemFacade &operator=(InputSystemFacade &&) = default;
  InputSystemFacade &operator=(const InputSystemFacade &) = default;
  ~InputSystemFacade();

  static inline unsigned char keyboard_keys[SDL_NUM_SCANCODES]{};
};

#endif /* ENGINE_INPUT_SYSTEM_FACADE */
