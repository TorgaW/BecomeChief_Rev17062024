#include "perlin.h"
#include "math/fmath.h"
#include <math.h>
#include <stdint.h>

float _perlin_quintic_interpolation(float x) {
  return x * x * x * (x * (x * 6 - 15) + 10);
}

float _perlin_random_gradient(float dx, float dy, float ix, float iy,
                              SNoise *noise) {
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

float calc_perlin_2d(float x, float y, SNoise *noise) {

  // see https://github.com/Auburn/FastNoiseLite/tree/master/C

  int32_t x0 = fm_floor_f(x), y0 = fm_floor_f(y);
  // printf("inY: %d\n",y0);
  float xd0 = (float)(x - x0), yd0 = (float)(y - y0);
  float xd1 = xd0 - 1, yd1 = yd0 - 1;

  float xi = _perlin_quintic_interpolation(xd0);
  float yi = _perlin_quintic_interpolation(yd0);
  // printf("xi: %f; yi: %f;\n", xi, yi);

  float xf =
      fm_lerp_f(_perlin_random_gradient(xd0, yd0, x0, y0, noise),
                _perlin_random_gradient(xd1, yd0, x0 + 1, y0, noise), xi);

  // printf("xf: %f\n", xf);
  float yf =
      fm_lerp_f(_perlin_random_gradient(xd0, yd1, x0, y0 + 1, noise),
                _perlin_random_gradient(xd1, yd1, x0 + 1, y0 + 1, noise), xi);
  // printf("yi: %f\n", yi);
  return fm_lerp_f(xf, yf, yi);
  // return (float)random_range(randomState, 0, 10000000) / 10000000.0f;
}


void init_perlin_fbm_params(SPerlinFBMParams* src)
{
  src->amplitude = 0.5f;
  src->frequency = 1.0f;
  src->gain = 0.5f;
  src->lake = 2.0f;
}

void init_perlin_domain_warping_params(SPerlinDomainWarpingParams* src)
{
  src->vx0 = 0.5f;
  src->vy0 = 1.8;
  src->vx1 = 4.1f;
  src->vy1 = 1.4f;
  src->vx2 = 3.3f;
  src->vy2 = 5.5f;
  src->vx3 = 1.9f;
  src->vy3 = 9.1f;
  src->p = 3.0f;
}

float calc_perlin_fbm_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SNoise *noise) {
  
  //source: https://thebookofshaders.com/13/
  
  float v = 0.0f;
  float amp = params->amplitude;
  float freq = params->frequency;
  float gain = params->gain;
  float lake = params->lake;
  for (uint8_t i = 0; i < octaves; i++) {
    v += amp * calc_perlin_2d(freq * x, freq * y, noise);
    freq *= lake;
    amp *= gain;
  }
  return v;
}

float calc_perlin_fbm_ridged_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SNoise* noise)
{
    float v = 0.0f;
  float amp = params->amplitude;
  float freq = params->frequency;
  float gain = params->gain;
  float lake = params->lake;
  for (uint8_t i = 0; i < octaves; i++) {
    v += amp * fabsf(calc_perlin_2d(freq * x, freq * y, noise));
    freq *= lake;
    amp *= gain;
  }
  return v;
}

float calc_perlin_dwfbm_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SPerlinDomainWarpingParams* dwParams, SNoise* noise)
{
  float ax = calc_perlin_fbm_2d(x + dwParams->vx0, y + dwParams->vy0, octaves, params, noise);
  float ay = calc_perlin_fbm_2d(x + dwParams->vx1, y + dwParams->vy1, octaves, params, noise);
  float bx = calc_perlin_fbm_2d(x + dwParams->vx2 + ax * dwParams->p, y + dwParams->vy2 + ay * dwParams->p, octaves, params, noise);
  float by = calc_perlin_fbm_2d(x + dwParams->vx3 + ax * dwParams->p, y + dwParams->vy3 + ay * dwParams->p, octaves, params, noise);
  return calc_perlin_fbm_2d(x + dwParams->p * bx, y + dwParams->p * by, octaves, params, noise);
}

float calc_perlin_dwfbm_ridged_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SPerlinDomainWarpingParams* dwParams, SNoise* noise)
{
  float ax = calc_perlin_fbm_ridged_2d(x + dwParams->vx0, y + dwParams->vy0, octaves, params, noise);
  float ay = calc_perlin_fbm_ridged_2d(x + dwParams->vx1, y + dwParams->vy1, octaves, params, noise);
  float bx = calc_perlin_fbm_ridged_2d(x + dwParams->vx2 + ax * dwParams->p, y + dwParams->vy2 + ay * dwParams->p, octaves, params, noise);
  float by = calc_perlin_fbm_ridged_2d(x + dwParams->vx3 + ax * dwParams->p, y + dwParams->vy3 + ay * dwParams->p, octaves, params, noise);
  return calc_perlin_fbm_ridged_2d(x + dwParams->p * bx, y + dwParams->p * by, octaves, params, noise);
}
