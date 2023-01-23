#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main() {
    vec2 u = {-2., 3.};
    vec2 v = {2., 3.};
    v = vadd(&u, &v);

    printf("vec2(%f %f)\n", v.x, v.y);

    return 0;
}