#ifndef FMATH
#define FMATH

#include <stdint.h>

#define FMATH_PI 3.14159265358979323846

double fm_clamp(double d, double min, double max);
float fm_clamp_f(float d, float min, float max);

int64_t fm_floor(double x);
int32_t fm_floor_f(float x);

double fm_lerp(double x, double y, double t);
float fm_lerp_f(float x, float y, float t);

#endif /* FMATH */
