#include <stdbool.h>
#include "tuple.h"
#include "utils.h"

tuple_t tuple(float x, float y, float z, float w)
{
    return (tuple_t) { x, y, z, w };
}

bool is_point(tuple_t tuple)
{
    return fequal(tuple.w, 1);
}

bool is_vector(tuple_t tuple)
{
    return fequal(tuple.w, 0);
}
