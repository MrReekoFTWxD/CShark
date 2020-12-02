#include <math.h>
#include <fastmath.h>

#include "Memory.h"
#include "q_math.h"

float* VectorAdd(float* veca, float* vecb)
{
	float* out = (float*)Malloc(0xC);
	out[0] = veca[0] + vecb[0];
	out[1] = veca[1] + vecb[1];
	out[2] = veca[2] + vecb[2];
	return out;
}

float* VectorScale(float* in, float scale) {
	float* out = (float*)Malloc(0xC);
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
	return out;
}

void AngleVectors(const float angles[3], float forward[3], float right[3], float up[3]) {
	float   angle;
	static float    sr, sp, sy, cr, cp, cy;
	// static to help MS compiler fp bugs
 
	angle = angles[YAW] * (M_PI*2 / 360);
	sy = sinf(angle);
	cy = cosf(angle);
	angle = angles[PITCH] * (M_PI*2 / 360);
	sp = sinf(angle);
	cp = cosf(angle);
	angle = angles[ROLL] * (M_PI*2 / 360);
	sr = sinf(angle);
	cr = cosf(angle);
 
	if (forward)
	{
		forward[0] = cp*cy;
		forward[1] = cp*sy;
		forward[2] = -sp;
	}
	if (right)
	{
		right[0] = (-1*sr*sp*cy+-1*cr*-sy);
		right[1] = (-1*sr*sp*sy+-1*cr*cy);
		right[2] = -1*sr*cp;
	}
	if (up)
	{
		up[0] = (cr*sp*cy+-sr*-sy);
		up[1] = (cr*sp*sy+-sr*cy);
		up[2] = cr*cp;
	}
}