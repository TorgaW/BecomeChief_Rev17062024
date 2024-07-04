#include "perlin.h"
#include "math/fmath.h"
#include <stdint.h>

float _perlin_quintic_interpolation(float x)
{
	return x * x * x * (x * (x * 6 - 15) + 10);
}

float calc_perlin_2d(float x, float y) {
  int32_t x0 = fm_floor_f(x), y0 = fm_floor_f(y);
  float xd0 = (float)(x - x0), yd0 = (float)(y - y0);
  float xd1 = xd0 - 1, yd1 = yd0 - 1;

  float xi = _perlin_quintic_interpolation(xd0);
  float yi = _perlin_quintic_interpolation(yd0);

  //TODO
  //see https://github.com/Auburn/FastNoiseLite/tree/master/C
  //continue to copy his code from function '_fnlSinglePerlin2D'
  return 0.0f;
}