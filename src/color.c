#include <math.h>
#include "color.h"
#include "tuple.h"
#include "utils.h"

#include <stdio.h>

int _float_to_uint8(float value)
{
    if (value < 0.0f) {
        return 0;
    } else if (value >= 1.0f) {
        return 255;
    }

    int intval = (int) lround(255.0 * value);

    if (intval > 255) {
        return 255;
    } else if (intval < 0) {
        return 0;
    }

    return intval;
}

void color_to_rgb(color_t color, unsigned char dst[3])
{
    dst[0] = _float_to_uint8(color.x);
    dst[1] = _float_to_uint8(color.y);
    dst[2] = _float_to_uint8(color.z);
}

color_t color(float red, float green, float blue)
{
    return (color_t) {
        red,
        green,
        blue
    };
}

color_t color_sum(color_t a, color_t b)
{
    return (color_t) tuple_sum(a, b);
}

color_t color_sub(color_t a, color_t b)
{
    return (color_t) tuple_sub(a, b);
}

color_t color_mul(color_t color, float multiplier)
{
    return (color_t) tuple_mul(color, multiplier);
}

color_t color_product(color_t a, color_t b)
{
    return (color_t) {
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    };
}

