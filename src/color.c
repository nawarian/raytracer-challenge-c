#include "color.h"
#include "tuple.h"

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

