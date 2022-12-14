#ifndef _color_h_
#define _color_h_

#include "tuple.h"

typedef tuple_t color_t;

color_t color(float red, float green, float blue);
color_t color_sum(color_t a, color_t b);
color_t color_sub(color_t a, color_t b);
color_t color_mul(color_t color, float multiplier);
color_t color_product(color_t a, color_t b);

#endif

