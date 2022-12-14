#include "utils.h"

bool fequal(float a, float b)
{
    return fabsf(a - b) < EPSILON;
}

