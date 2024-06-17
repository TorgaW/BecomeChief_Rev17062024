#include "engine.h"

#include "../sprite/sprite.h"
#include "../texture/texture.h"
#include <stdio.h>
#include <sys/types.h>

SEngineApp init_vulpecula_engine() {
  int rendererFlags, windowFlags;
  rendererFlags = SDL_RENDERER_ACCELERATED;
  windowFlags = 0;

  SEngineApp app;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) <= 0) {
    printf("Couldn't initialize SDL_Image: %s\n", IMG_GetError());
    exit(1);
  }

  app.window =
      SDL_CreateWindow("Become Chief Rev17062024", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, DEFAULT_WINDOW_WIDTH,
                       DEFAULT_WINDOW_HEIGHT, windowFlags);

  if (!app.window) {
    printf("Failed to open %d x %d window: %s\n", DEFAULT_WINDOW_WIDTH,
           DEFAULT_WINDOW_HEIGHT, SDL_GetError());
    exit(1);
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

  if (!app.renderer) {
    printf("Failed to create renderer: %s\n", SDL_GetError());
    exit(1);
  }

  app.signal = ENGINE_SIGNAL_IDLE;

  app.objectPool = array_create(256, sizeof(SSprite));
  app.loadedTextures = init_loaded_textures_pool();

  return app;
}

void _read_input(SEngineApp *engineApp) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT: {
      engineApp->signal = ENGINE_SIGNAL_EXIT;
    } break;
    default:
      break;
    }
  }
}

void loop_vulpecula_engine(SEngineApp *engineApp) {
  engineApp->signal = ENGINE_SIGNAL_RUNNING;
  size_t i = 0;
  SDL_Rect target = {.x = 0, .y = 0, .h = 128, .w = 128};
  while (engineApp->signal != ENGINE_SIGNAL_EXIT) {
    _read_input(engineApp);
    SDL_RenderClear(engineApp->renderer);
    i = 0;
	SSprite* current = NULL;
    for (; i < engineApp->objectPool->size; i++) {
	  current = array_get_at(engineApp->objectPool, SSprite, i);
	  target.x = current->x;
	  target.y = current->y;
      SDL_RenderCopy(
          engineApp->renderer,
          current->texture->sdlTexture,
          NULL, &target);
    }
    SDL_RenderPresent(engineApp->renderer);
  }
  free_vulpecula_engine(engineApp);
}

void free_vulpecula_engine(SEngineApp *engineApp) {
  SDL_DestroyRenderer(engineApp->renderer);
  SDL_DestroyWindow(engineApp->window);
  IMG_Quit();
  array_free(engineApp->objectPool);
}