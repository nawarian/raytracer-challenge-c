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

void test_point_creates_tuples_with_w_1(void)
{
    tuple_t p = point(4, -4, 3);

    assert(tuple_equals(p, tuple(4, -4, 3, 1)));
}

void test_vector_creates_tuples_with_w_0(void)
{
    tuple_t v = vector(4, -4, 3);

    assert(tuple_equals(v, tuple(4, -4, 3, 0)));
}

void test_adding_two_tuples(void)
{
    tuple_t a1 = tuple(3, -2, 5, 1);
    tuple_t a2 = tuple(-2, 3, 1, 0);

    assert(tuple_equals(tuple_sum(a1, a2), tuple(1, 1, 6, 1)));
}

int main(void)
{
    test_tuple_with_w_1_is_a_point();
    test_tuple_with_w_0_is_a_vector();
    test_point_creates_tuples_with_w_1();
    test_vector_creates_tuples_with_w_0();
    test_adding_two_tuples();
}

