#include "perlin.h"
#include "math/fmath.h"
#include "math/frandom.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

float _perlin_quintic_interpolation(float x) {
  return x * x * x * (x * (x * 6 - 15) + 10);
}

float _perlin_random_gradient(SMathRandomState *randomState, float dx,
                              float dy) {
  // gen random value
  float rgx = (float)random_range(randomState, 0, 10000000);
  // randomly decide sign
  float srgx = random(randomState) % 2 == 0 ? -1.0f : 1.0f;
  // gradient value for X
  float gX = (rgx * srgx) / 10000000.0f;

  // gen random value
  float rgy = (float)random_range(randomState, 0, 10000000);
  // randomly decide sign
  float srgy = random(randomState) % 2 == 0 ? -1.0f : 1.0f;
  // gradient value for Y
  float gY = (rgx * srgx) / 10000000.0f;

  // return dot product
  // printf("dot: %f\n", (dx * gX + dy * gY));
  float dot = dx * gX + dy * gY;
  return dot;
}

float calc_perlin_2d(float x, float y, SMathRandomState *randomState) {

  // see https://github.com/Auburn/FastNoiseLite/tree/master/C

  int32_t x0 = fm_floor_f(x), y0 = fm_floor_f(y);
  // printf("inY: %d\n",y0);
  float xd0 = (float)(x - x0), yd0 = (float)(y - y0);
  float xd1 = xd0 + 1, yd1 = yd0 + 1;

  float xi = _perlin_quintic_interpolation(xd0);
  float yi = _perlin_quintic_interpolation(yd0);

  float xf = fm_lerp_f(_perlin_random_gradient(randomState, xd0, yd0),
                       _perlin_random_gradient(randomState, xd1, yd0), xi);
  
  // printf("xf: %f\n", xf);
  float yf = fm_lerp_f(_perlin_random_gradient(randomState, xd0, yd1),
                       _perlin_random_gradient(randomState, xd1, yd1), xi);
  // printf("yi: %f\n", yi);
  return fm_lerp_f(xf, yf, yi);
}