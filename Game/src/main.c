#include "game_boot/game_boot.h"
#include "math/noise/noise.h"
#include "math/noise/simplex/perlin.h"

#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  SNoise noise = {.noiseType = NOISE_SIMPLEX};
  alloc_noise(&noise, 128, 128);
  game_boot();
  return 0;
}