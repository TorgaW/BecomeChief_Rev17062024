#ifndef SIMPLEX
#define SIMPLEX

#include <stdint.h>
#include "math/frandom.h"

float _perlin_quintic_interpolation(float x);
float _perlin_random_gradient(SMathRandomState *randomState, float dx, float dy);

float calc_perlin_2d(float x, float y, SMathRandomState *randomState);

#endif /* SIMPLEX */
