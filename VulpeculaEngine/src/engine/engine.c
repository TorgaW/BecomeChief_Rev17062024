#include "engine.h"

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
    printf("Couldn't initialize SDL_Image: %s\n", SDL_GetError());
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
  while (engineApp->signal != ENGINE_SIGNAL_EXIT) {
    _read_input(engineApp);
  }
  free_vulpecula_engine(engineApp);
}

void free_vulpecula_engine(SEngineApp *engineApp) {
  SDL_DestroyRenderer(engineApp->renderer);
  SDL_DestroyWindow(engineApp->window);
  IMG_Quit();
}