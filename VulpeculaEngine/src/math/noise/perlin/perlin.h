#ifndef PERLIN
#define PERLIN

#include <stdint.h>
#include "math/frandom.h"
#include "math/noise/noise.h"

float _perlin_quintic_interpolation(float x);
float _perlin_random_gradient(float dx, float dy, float ix, float iy, SNoise* noise);

float calc_perlin_2d(float x, float y, SNoise* noise);

float calc_perlin_fbm_2d(float x, float y, SNoise* noise);

#endif /* PERLIN */
