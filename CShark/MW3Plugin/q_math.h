#ifndef Q_MATH_H
#define Q_MATH_H

#define PITCH       0   // up / down
#define YAW         1   // left / right
#define ROLL        2   // fall over

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec5_t[5];

float* VectorAdd(float* veca, float* vecb);
float* VectorScale(float* in, float scale);
void AngleVectors(const float angles[3], float forward[3], float right[3], float up[3]);

#endif