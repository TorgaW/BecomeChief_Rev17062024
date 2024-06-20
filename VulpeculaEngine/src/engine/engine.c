#include "engine.h"

#include "../camera/camera.h"
#include "../common/common.h"
#include "../sprite/sprite.h"
#include "../texture/texture.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
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

  app.framesCount = 0;

  app.keyboard = alloc_struct(SKeyboard, ENGINE_MALLOC_AUTO);
  memset(app.keyboard->keys, 0, SDL_NUM_SCANCODES);

  app.camera = alloc_struct(SCamera, ENGINE_MALLOC_AUTO);
  memset(app.camera, 0, sizeof(SCamera));
  app.camera->zoom = 1.0;

  app.mouse = alloc_struct(SMouse, ENGINE_MALLOC_AUTO);
  memset(app.mouse, 0, sizeof(SMouse));

  //nearest filter
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

  return app;
}

void _read_input(SEngineApp *engineApp) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT: {
      engineApp->signal = ENGINE_SIGNAL_EXIT;
    } break;
    case SDL_KEYDOWN: {
      engineApp->keyboard->keys[event.key.keysym.scancode] = 1;
    } break;
    case SDL_KEYUP: {
      engineApp->keyboard->keys[event.key.keysym.scancode] = 0;
    } break;
    case SDL_WINDOWEVENT_FOCUS_LOST: {
      memset(engineApp->keyboard->keys, 0, SDL_NUM_SCANCODES);
    } break;
    case SDL_MOUSEBUTTONDOWN: {
      switch (event.button.button) {
      case SDL_BUTTON_LEFT: {
        engineApp->mouse->buttons[0] = 1;
      } break;
      case SDL_BUTTON_RIGHT: {
        engineApp->mouse->buttons[1] = 1;
      } break;
      }
    } break;
    case SDL_MOUSEBUTTONUP: {
      switch (event.button.button) {
      case SDL_BUTTON_LEFT: {
        engineApp->mouse->buttons[0] = 0;
      } break;
      case SDL_BUTTON_RIGHT: {
        engineApp->mouse->buttons[1] = 0;
      } break;
      }
    } break;
    case SDL_MOUSEWHEEL: {
      engineApp->mouse->wheel = event.wheel.y;
    } break;
    default:
      break;
    }
  }
}

void loop_vulpecula_engine(SEngineApp *engineApp) {

  engineApp->signal = ENGINE_SIGNAL_RUNNING;

  uint64_t tNow = SDL_GetPerformanceCounter();
  uint64_t tLast = 0;

  while (engineApp->signal != ENGINE_SIGNAL_EXIT) {

    tLast = tNow;
    tNow = SDL_GetPerformanceCounter();
    engineApp->framesDelta = (double)((tNow - tLast) * 1000 /
                                      (double)SDL_GetPerformanceFrequency()) *
                             0.001;
    printf("%f ms; %.4f fps;\n", engineApp->framesDelta * 1000.0, 1000.0 / (engineApp->framesDelta * 1000.0));
    _read_input(engineApp);
    camera_movement(engineApp);
    SDL_RenderClear(engineApp->renderer);

    engineApp->tickFunction(engineApp);

    SDL_RenderPresent(engineApp->renderer);
    engineApp->framesCount++;
    engineApp->mouse->wheel = 0;
  }
  free_vulpecula_engine(engineApp);
}

void free_vulpecula_engine(SEngineApp *engineApp) {
  SDL_DestroyRenderer(engineApp->renderer);
  SDL_DestroyWindow(engineApp->window);
  IMG_Quit();
  array_free(engineApp->objectPool);
}

void engine_load_resources(SEngineApp *engineApp) {
  // load default placeholder 128x128. id = 1
  load_texture("VulpeculaEngine/resources/placeholders/default128_0.png",
               "DefaultTex128", engineApp);
}