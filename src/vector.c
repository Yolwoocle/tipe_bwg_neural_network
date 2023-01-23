#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

vec2 vadd(vec2 *u, vec2 *v) {
    vec2 res = {
        .x = u->x + v->x, 
        .y = u->y + v->y, 
    };
    return res;
}

vec2 vsub(vec2 *u, vec2 *v) {
    vec2 res = {
        .x = u->x - v->x, 
        .y = u->y - v->y, 
    };
    return res;
}

vec2 vneg(vec2 *u) {
    vec2 res = {
        .x = -u->x, 
        .y = -u->y, 
    };
    return res;
}

vec2 vscale(vec2 *u, double a) {
    vec2 res = {
        .x = u->x * a,
        .y = u->y * a,
    };
    return res;
}