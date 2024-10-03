#ifndef PERLIN
#define PERLIN

#include <stdint.h>
#include "math/noise/noise.h"

float _perlin_quintic_interpolation(float x);
float _perlin_random_gradient(float dx, float dy, float ix, float iy, SNoise* noise);

float calc_perlin_2d(float x, float y, SNoise* noise);

typedef struct SPerlinFBMParams {

    float gain;
    //synonym for 'lacunarity' word
    float lake;
    float amplitude;
    float frequency;

} SPerlinFBMParams;

typedef struct SPerlinDomainWarpingParams {

    float vx0, vy0, vx1, vy1, vx2, vy2, vx3, vy3;
    float p;

} SPerlinDomainWarpingParams;

void init_perlin_fbm_params(SPerlinFBMParams* src);

void init_perlin_domain_warping_params(SPerlinDomainWarpingParams* src);

float calc_perlin_fbm_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SNoise* noise);
float calc_perlin_fbm_ridged_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SNoise* noise);

float calc_perlin_dwfbm_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SPerlinDomainWarpingParams* dwParams, SNoise* noise);

float calc_perlin_dwfbm_ridged_2d(float x, float y, uint8_t octaves, SPerlinFBMParams* params, SPerlinDomainWarpingParams* dwParams, SNoise* noise);

#endif /* PERLIN */
