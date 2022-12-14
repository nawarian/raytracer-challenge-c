#include <stdbool.h>
#include "tuple.h"
#include "utils.h"

tuple_t tuple(float x, float y, float z, float w)
{
    return (tuple_t) { x, y, z, w };
}

tuple_t point(float x, float y, float z)
{
    return tuple(x, y, z, 1.0);
}

tuple_t vector(float x, float y, float z)
{
    return tuple(x, y, z, 0.0);
}

bool tuple_equals(tuple_t a, tuple_t b)
{
    return fequal(a.x, b.x)
        && fequal(a.y, b.y)
        && fequal(a.z, b.z)
        && fequal(a.w, b.w);
}

tuple_t tuple_sum(tuple_t a, tuple_t b)
{
    return (tuple_t) {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}

tuple_t tuple_sub(tuple_t a, tuple_t b)
{
    return (tuple_t) {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}

tuple_t tuple_mul(tuple_t a, float multiplier)
{
    return (tuple_t) {
        a.x * multiplier,
        a.y * multiplier,
        a.z * multiplier,
        a.w * multiplier
    };
}

tuple_t tuple_negate(tuple_t tuple)
{
    return (tuple_t) {
        -tuple.x,
        -tuple.y,
        -tuple.z,
        -tuple.w
    };
}

bool is_point(tuple_t tuple)
{
    return fequal(tuple.w, 1);
}

bool is_vector(tuple_t tuple)
{
    return fequal(tuple.w, 0);
}
