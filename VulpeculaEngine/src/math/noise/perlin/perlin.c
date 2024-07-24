#include "perlin.h"
#include "math/fmath.h"
#include "math/frandom.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

float _perlin_quintic_interpolation(float x) {
  return x * x * x * (x * (x * 6 - 15) + 10);
}

// float _perlin_random_gradient(SMathRandomState *randomState, float dx,
//                               float dy) {
//   // gen random value
//   float rgx = (float)random_range(randomState, 0, 10000000);
//   // randomly decide sign
//   float srgx = random(randomState) % 2 == 0 ? -1.0f : 1.0f;
//   // gradient value for X
//   float gX = (rgx * srgx) / 10000000.0f;

//   // gen random value
//   float rgy = (float)random_range(randomState, 0, 10000000);
//   // randomly decide sign
//   float srgy = random(randomState) % 2 == 0 ? -1.0f : 1.0f;
//   // gradient value for Y
//   float gY = (rgy * srgy) / 10000000.0f;

//   // return dot product
//   // printf("dot: %f\n", (dx * gX + dy * gY));
//   // float dot = dx * gX + dy * gY;
//   return dx * gX + dy * gY;
// }

// float _perlin_random_gradient(SMathRandomState *randomState, float dx,
//                               float dy) {
//   float theta =
//       ((float)random_range(randomState, 0, 10000000) * (2.0f * FMATH_PI)) /
//       10000000.0f;
//   float gx = cosf(theta);
//   float gy = sinf(theta);
//   return dx * gx + dy * gy;
// }

float _perlin_random_gradient(float dx,
                              float dy, float ix, float iy, SNoise* noise) {
  const uint32_t w = 8 * sizeof(uint32_t);
  const uint32_t s = w / 2;
  uint32_t a = ix, b = iy;
  a *= noise->perlin_random_values[0];
  b ^= a << s | a >> (w - s);
  b *= noise->perlin_random_values[1];
  a ^= b << s | b >> (w - s);
  a *= noise->perlin_random_values[2];

  // in [0, 2*Pi]
  float r = a * (3.14159265 / ~(~0u >> 1));

  return dx * cosf(r) + dy * sinf(r);
}

float calc_perlin_2d(float x, float y, SNoise* noise) {

  // see https://github.com/Auburn/FastNoiseLite/tree/master/C

  int32_t x0 = fm_floor_f(x), y0 = fm_floor_f(y);
  // printf("inY: %d\n",y0);
  float xd0 = (float)(x - x0), yd0 = (float)(y - y0);
  float xd1 = xd0 - 1, yd1 = yd0 - 1;

  float xi = _perlin_quintic_interpolation(xd0);
  float yi = _perlin_quintic_interpolation(yd0);
  // printf("xi: %f; yi: %f;\n", xi, yi);

  float xf = fm_lerp_f(_perlin_random_gradient(xd0, yd0, x0, y0, noise),
                       _perlin_random_gradient(xd1, yd0, x0+1, y0, noise), xi);

  // printf("xf: %f\n", xf);
  float yf = fm_lerp_f(_perlin_random_gradient(xd0, yd1, x0, y0+1, noise),
                       _perlin_random_gradient(xd1, yd1, x0+1, y0+1, noise), xi);
  // printf("yi: %f\n", yi);
  return fm_lerp_f(xf, yf, yi);
  // return (float)random_range(randomState, 0, 10000000) / 10000000.0f;
}

float calc_perlin_fbm_2d(float x, float y, SNoise* noise)
{
  
}
