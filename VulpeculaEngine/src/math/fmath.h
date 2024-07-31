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

typedef struct SVec2f {
	float x, y;
} SVec2f;

typedef struct SVec3f {
	float x, y, z;
} SVec3f;

typedef struct SVec2i {
	int x, y;
} SVec2i;

typedef struct SVec3i {
	int x, y, z;
} SVec3i;

typedef struct SVec4i {
	int x, y, z, w;
} SVec4i;

typedef struct SColorRGBA {
	uint8_t r, g, b, a;
} SColorRGBA;

#endif /* FMATH */
