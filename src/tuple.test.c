#include <assert.h>
#include <stdbool.h>

#include "tuple.h"
#include "utils.h"

void test_tuple_with_w_1_is_a_point(void)
{
    tuple_t a = tuple(4.3, -4.2, 3.1, 1.0);

    assert(fequal(a.x, 4.3));
    assert(fequal(a.y, -4.2));
    assert(fequal(a.z, 3.1));
    assert(fequal(a.w, 1.0));
    assert(is_point(a) == true);
    assert(is_vector(a) == false);
}

void test_tuple_with_w_0_is_a_vector(void)
{
    tuple_t a = tuple(4.3, -4.2, 3.1, 0.0);

    assert(fequal(a.x, 4.3));
    assert(fequal(a.y, -4.2));
    assert(fequal(a.z, 3.1));
    assert(fequal(a.w, 0.0));
    assert(is_point(a) == false);
    assert(is_vector(a) == true);
}

int main(void)
{
    test_tuple_with_w_1_is_a_point();
    test_tuple_with_w_0_is_a_vector();
}

