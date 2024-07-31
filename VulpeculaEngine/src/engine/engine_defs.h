#ifndef ENGINE_DEFS
#define ENGINE_DEFS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sys/types.h>

#include "../darray/darray.h"
#include "../keyboard/keyboard.h"
#include "../mouse/mouse.h"
#include "../texture/texture_defs.h"
#include "../camera/camera_defs.h"
#include "SDL_render.h"

typedef struct SEngineApp {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int signal;
  SArray *objectPool;
  SArray *uiPool;
  SLoadedTexturesPool *loadedTextures;
  size_t framesCount;
  double framesDelta;
  SKeyboard* keyboard;
  SCamera* camera;
  SMouse* mouse;
  void (*tickFunction)(struct SEngineApp* engineApp);
  SDL_Texture* testNoise;
} SEngineApp;

#endif /* ENGINE_DEFS */
