#ifndef ENGINE_DEFS
#define ENGINE_DEFS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../darray/darray.h"
#include "../texture/texture_defs.h"

typedef struct SEngineApp {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int signal;
  SArray *objectPool;
  SLoadedTexturesPool *loadedTextures;
//   int poolCount;
//   SMemPool* objectPools[0xFF+1]; //256 object pools
} SEngineApp;

#endif /* ENGINE_DEFS */
