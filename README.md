# vec2.c

Hacky 2D vector library that abuses macros & `complex`.

# Usage

```c
#include "vec2.h"

int main(void) {
  vec2(int) v2i = vec2_new(34, 35);
  vec2(float) v2f = vec2_new(34.0, 35.0);
  vec2(float) total = v2i + v2f;
  vec2(float) dot = vec2_dot(total, total * 2);

  printf("[%f, %f]", vec2_x(dot), vec2_y(dot));
}
```

# Installation

Just copy `vec2.h` into your include folder.
