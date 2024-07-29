#include "game_boot.h"
#include "../game_tick/game_tick.h"

#include "SDL_pixels.h"
#include "SDL_render.h"
#include "benchmark/time_benchmark.h"
#include "darray/darray.h"
#include "engine/engine.h"
#include "math/fmath.h"
#include "math/frandom.h"
#include "math/noise/noise.h"
#include "math/noise/perlin/perlin.h"
#include "sprite/sprite.h"
#include "texture/texture.h"
#include <SDL2/SDL.h>

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

void game_boot() {
  SEngineApp engineApp = init_vulpecula_engine();
  engine_load_resources(&engineApp);

  engineApp.tickFunction = &game_tick;

  SNoise noise = {.noiseType = NOISE_PERLIN};
  alloc_noise(&noise, 512, 512);
  SMathRandomState rState = {.seed = 0xFFFF};
  gen_perlin_random_values(&noise, &rState);
  SPerlinFBMParams fbmParams;
  init_perlin_fbm_params(&fbmParams);
  fbmParams.lake = 1.5f;
  SPerlinDomainWarpingParams dwParams;
  init_perlin_domain_warping_params(&dwParams);
  dwParams.p = 1.2f;

  BC_START_BENCHMARK
  int w = 512, h = 512;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      noise.data[i * h + j] = fm_clamp_f(
          calc_perlin_dwfbm_2d((j) * 0.05f + 0.05f, (i) * 0.05f + 0.05f, 7,
                               &fbmParams, &dwParams, &noise),
          0.0f, 0.9999f);
    }
  }
  BC_STOP_BENCHMARK
  BC_PRINT_RESULTS_BENCHMARK

  SDL_Texture *noiseTexture =
      SDL_CreateTexture(engineApp.renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STREAMING, w, h);
  SDL_SetTextureScaleMode(noiseTexture, SDL_ScaleModeNearest);
  uint32_t pixels[w * h];
  // int pitch = 0;
  SDL_PixelFormat *formatPix = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

  for (int i = 0; i < w * h; i++) {
    pixels[i] = SDL_MapRGBA(formatPix, (uint8_t)(255 * noise.data[i]),
                            (uint8_t)(256 * noise.data[i]),
                            (uint8_t)(256 * noise.data[i]), 255);
    // printf("uvalue: %u\n nvalue: %f", (uint8_t)(noise.data[i]*255),
    // noise.data[i]);
  }

  SDL_UpdateTexture(noiseTexture, NULL, pixels, sizeof(uint32_t) * w);
  // SDL_LockTexture(noiseTexture, NULL, (void**)&pixels, &pitch);
  // printf("%d\n", pitch);
  // int c = 0;
  // int t = 0;
  // for (int i = 0; i < 16 * 16; i++) {
  //   if(c==1)
  //   {
  //     pixels[i] = 255;
  //     c = 0;
  //     t++;
  //   }
  //   else
  //   {
  //     pixels[i] = (uint8_t)(noise.data[t] * 255.0f);
  //     c++;
  //   }
  // }
  // SDL_UnlockTexture(noiseTexture);
  engineApp.testNoise = noiseTexture;

  STexture *texture = get_texture(ENGINE_DEFAULT_TEX_0_128, &engineApp);
  SSprite sprite = {.x = 0, .y = 0, .texture = texture};
  array_push_back(&sprite, engineApp.objectPool);
  loop_vulpecula_engine(&engineApp);
}
