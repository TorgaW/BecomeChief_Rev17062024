#include "fmath.h"

double fm_clamp(double d, double min, double max) {
  const double t = d < min ? min : d;
  return t > max ? max : t;
}

float fm_clamp_f(float d, float min, float max) {
  const float t = d < min ? min : d;
  return t > max ? max : t;
}

int64_t fm_floor(double x) { return (int64_t)x - (x < (int64_t)x); }

int32_t fm_floor_f(float x) { return (int32_t)x - (x < (int32_t)x); }

double fm_lerp(double x, double y, double t) { return x + t * (y - x); }
float fm_lerp_f(float x, float y, float t) { return x + t * (y - x); }