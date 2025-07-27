#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vec2.h"

#define EPS 1e-9

static int approx_eq(double a, double b) {
    return fabs(a - b) < EPS;
}

static int vec2_approx_eq(vec2(double) a, vec2(double) b) {
    return approx_eq(creal(a), creal(b)) && approx_eq(cimag(a), cimag(b));
}

int main() {
    // Construction
    vec2(double) v1 = vec2_new(3.0, 4.0);
    assert(approx_eq(vec2_x(v1), 3.0));
    assert(approx_eq(vec2_y(v1), 4.0));

    // Magnitude
    assert(approx_eq(vec2_magnitude(v1), 5.0));

    // Unit vector
    vec2(double) u = vec2_unit(v1);
    assert(approx_eq(vec2_magnitude(u), 1.0));
    assert(approx_eq(vec2_x(u), 3.0 / 5.0));
    assert(approx_eq(vec2_y(u), 4.0 / 5.0));

    // Angle (in radians)
    assert(approx_eq(vec2_angle(vec2_new(1.0, 0.0)), 0.0));
    assert(approx_eq(vec2_angle(vec2_new(0.0, 1.0)), M_PI / 2));

    // Dot product
    vec2(double) v2 = vec2_new(1.0, 0.0);
    assert(approx_eq(vec2_dot(v1, v2), 3.0));

    // Cross product (2D scalar)
    assert(approx_eq(vec2_cross(v1, v2), 4.0));

    // Projection: project v1 onto v2
    vec2(double) proj = vec2_proj(v1, v2);
    assert(vec2_approx_eq(proj, vec2_new(3.0, 0.0)));

    // Reflection: reflect v2 across y-axis normal (0,1)
    vec2(double) normal = vec2_new(0.0, 1.0);
    vec2(double) refl = vec2_reflect(v2, normal);
    assert(vec2_approx_eq(refl, vec2_new(1.0, 0.0)));  // reflection over y-axis keeps x same

    // Reflection: reflect v1 across x-axis normal (1,0)
    normal = vec2_new(1.0, 0.0);
    refl = vec2_reflect(v1, normal);
    assert(vec2_approx_eq(refl, vec2_new(3.0, -4.0)));

    // Constants test
    vec2(double) zero = vec2_zero(double);
    assert(vec2_approx_eq(zero, vec2_new(0.0, 0.0)));

    vec2(double) up = vec2_up(double);
    assert(vec2_approx_eq(up, vec2_new(0.0, 1.0)));

    vec2(double) right = vec2_right(double);
    assert(vec2_approx_eq(right, vec2_new(1.0, 0.0)));

    printf("All vec2 tests passed!\n");
    return 0;
}
