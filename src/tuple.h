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
bool is_point(tuple_t tuple);
bool is_vector(tuple_t tuple);

#endif

