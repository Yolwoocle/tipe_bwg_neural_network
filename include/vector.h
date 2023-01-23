#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} vec2;

vec2 vadd(vec2 *u, vec2 *v);
vec2 vsub(vec2 *u, vec2 *v);
vec2 vneg(vec2 *u);
vec2 vscale(vec2 *u, double a);

#endif