#ifndef _tuple_h_
#define _tuple_h_

#include <stdbool.h>

typedef struct {
    float x;
    float y;
    float z;
    float w;
} tuple_t;

tuple_t tuple(float x, float y, float z, float w);
tuple_t point(float x, float y, float z);
tuple_t vector(float x, float y, float z);

bool tuple_equals(tuple_t a, tuple_t b);
bool is_point(tuple_t tuple);
bool is_vector(tuple_t tuple);

#endif

