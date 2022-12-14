#include <stdbool.h>
#include <math.h>
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

tuple_t tuple_mul(tuple_t tuple, float multiplier)
{
    return (tuple_t) {
        tuple.x * multiplier,
        tuple.y * multiplier,
        tuple.z * multiplier,
        tuple.w * multiplier
    };
}

tuple_t tuple_div(tuple_t tuple, float factor)
{
    return (tuple_t) {
        tuple.x / factor,
        tuple.y / factor,
        tuple.z / factor,
        tuple.w / factor
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

float vector_magnitude(tuple_t vector)
{
    return sqrt(
        powf(vector.x, 2)
        + powf(vector.y, 2)
        + powf(vector.z, 2)
        + powf(vector.w, 2)
    );
}

tuple_t vector_normalize(tuple_t vector)
{
    float magnitude = vector_magnitude(vector);

    return (tuple_t) {
        vector.x / magnitude,
        vector.y / magnitude,
        vector.z / magnitude,
        vector.w / magnitude
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
