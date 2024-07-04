#ifndef FMATH
#define FMATH

#include <stdint.h>
double fm_clamp(double d, double min, double max);
float fm_clamp_f(float d, float min, float max);

int64_t fm_floor(double x);
int32_t fm_floor_f(float x);

#endif /* FMATH */
