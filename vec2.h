#ifndef __VEC2_H__
#define __VEC2_H__

#include <complex.h>
#include <math.h>

#define _VX vec2_x(v)
#define _VY vec2_y(v)

// type
#define vec2(T) T complex

// basic
#define vec2_new(x, y) ((x) + (y)*I)
#define vec2_x(v) (creal(v))
#define vec2_y(v) (cimag(v))

// geometric
#define vec2_magnitude(v) (sqrt(_VX * _VX + _VY * _VY))
#define vec2_unit(v) (v / vec2_magnitude(v))
#define vec2_angle(v) (atan2(_VY, _VX))

// stuff
#define vec2_dot(v1, v2) vec2_x((v1)*conj(v2))
#define vec2_cross(v1, v2) (vec2_y((v1)*conj(v2)))
#define vec2_proj(v, onto)                                                     \
  ((vec2(typeof(v)))((vec2_dot(v, onto) / vec2_dot(onto, onto)) * (onto)))
#define vec2_reflect(v, normal) ((v)-2 * vec2_dot(v, normal) * (normal))
#define vec2_lerp(v1, v2, t) ((1 - (t)) * (v1) + (t) * (v2))

// constants
#define vec2_zero(T) vec2_new(T(0), T(0))
#define vec2_one(T) vec2_new(T(1), T(1))
#define vec2_up(T) vec2_new(T(0), T(1))
#define vec2_down(T) vec2_new(T(0), T(-1))
#define vec2_right(T) vec2_new(T(1), T(0))
#define vec2_left(T) vec2_new(T(-1), T(0))

#undef _VX
#undef _VY

#endif
