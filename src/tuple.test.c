#include <assert.h>
#include <stdbool.h>

#include "tuple.h"
#include "utils.h"

/**
 * Scenario: A tuple with w=1.0 is a point
 *
 * Given a ← tuple(4.3, -4.2, 3.1, 1.0)
 * Then a.x = 4.3
 *   And a.y = -4.2
 *   And a.z = 3.1
 *   And a.w = 1.0
 *   And a is a point
 *   And a is not a vector
 */
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

/**
 * Scenario: A tuple with w=0 is a vector
 *
 * Given a ← tuple(4.3, -4.2, 3.1, 0.0)
 * Then a.x = 4.3
 *   And a.y = -4.2
 *   And a.z = 3.1
 *   And a.w = 0.0
 *   And a is not a point
 *   And a is a vector
 */
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

/**
 * Scenario: point() creates tuples with w=1
 *
 * Given p ← point(4, -4, 3)
 * Then p = tuple(4, -4, 3, 1)
 */
void test_point_creates_tuples_with_w_1(void)
{
    tuple_t p = point(4, -4, 3);

    assert(tuple_equals(p, tuple(4, -4, 3, 1)));
}

/**
 * Scenario: vector() creates tuples with w=0
 *
 * Given v ← vector(4, -4, 3)
 * Then v = tuple(4, -4, 3, 0)
 */
void test_vector_creates_tuples_with_w_0(void)
{
    tuple_t v = vector(4, -4, 3);

    assert(tuple_equals(v, tuple(4, -4, 3, 0)));
}

/**
 * Scenario: Adding two tuples
 *
 * Given a1 ← tuple(3, -2, 5, 1)
 *   And a2 ← tuple(-2, 3, 1, 0)
 * Then a1 + a2 = tuple(1, 1, 6, 1)
 */
void test_adding_two_tuples(void)
{
    tuple_t a1 = tuple(3, -2, 5, 1);
    tuple_t a2 = tuple(-2, 3, 1, 0);

    assert(tuple_equals(tuple_sum(a1, a2), tuple(1, 1, 6, 1)));
}

/**
 * Scenario: Subtracting two points
 *
 * Given p1 ← point(3, 2, 1)
 *   And p2 ← point(5, 6, 7)
 * Then p1 - p2 = vector(-2, -4, -6)
 */
void test_subtracting_two_points(void)
{
    tuple_t p1 = point(3, 2, 1);
    tuple_t p2 = point(5, 6, 7);

    assert(tuple_equals(tuple_sub(p1, p2), vector(-2, -4, -6)));
}

/**
 * Scenario: Subtracting a vector from a point
 *
 * Given p ← point(3, 2, 1)
 *   And v ← vector(5, 6, 7)
 * Then p - v = point(-2, -4, -6)
 */
void test_subtracting_vector_from_point(void)
{
    tuple_t p = point(3, 2, 1);
    tuple_t v = vector(5, 6, 7);

    assert(tuple_equals(tuple_sub(p, v), point(-2, -4, -6)));
}

/**
 * Scenario: Subtracting two vectors
 *
 * Given v1 ← vector(3, 2, 1)
 *   And v2 ← vector(5, 6, 7)
 * Then v1 - v2 = vector(-2, -4, -6)
 */
void test_subtracting_two_vectors(void)
{
    tuple_t v1 = vector(3, 2, 1);
    tuple_t v2 = vector(5, 6, 7);

    assert(tuple_equals(tuple_sub(v1, v2), vector(-2, -4 , -6)));
}

/**
 * Scenario: Subtracting a vector from the zero vector
 *
 * Given zero ← vector(0, 0, 0)
 *   And v ← vector(1, -2, 3)
 * Then zero - v = vector(-1, 2, -3)
 */
void test_subtracting_vector_from_zero_vector(void)
{
    tuple_t zero = vector(0, 0, 0);
    tuple_t v = vector(1, -2, 3);

    assert(tuple_equals(tuple_sub(zero, v), vector(-1, 2, -3)));
}

/**
 * Scenario: Negating a tuple
 *
 * Given a ← tuple(1, -2, 3, -4)
 * Then -a = tuple(-1, 2, -3, 4)
 */
void test_negating_tuple(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    assert(tuple_equals(tuple_negate(a), tuple(-1, 2, -3, 4)));
}

/**
 * Scenario: Multiplying a tuple by a scalar
 *
 * Given a ← tuple(1, -2, 3, -4)
 * Then a * 3.5 = tuple(3.5, -7, 10.5, -14)
 */
void test_multiplying_tuple_by_scalar(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    assert(tuple_equals(tuple_mul(a, 3.5), tuple(3.5, -7, 10.5, -14)));
}

/**
 * Scenario: Multiplying a tuple by a fraction
 *
 * Given a ← tuple(1, -2, 3, -4)
 * Then a * 0.5 = tuple(0.5, -1, 1.5, -2)
 */
void test_multiplying_tuple_by_fraction(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    assert(tuple_equals(tuple_mul(a, 0.5), tuple(0.5, -1, 1.5, -2)));
}

/**
 * Scenario: Dividing a tuple by a scalar
 *
 * Given a ← tuple(1, -2, 3, -4)
 * Then a / 2 = tuple(0.5, -1, 1.5, -2)
 */
void test_dividing_tuple_by_scalar(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    assert(tuple_equals(tuple_div(a, 2), tuple(0.5, -1, 1.5, -2)));
}

int main(void)
{
    test_tuple_with_w_1_is_a_point();
    test_tuple_with_w_0_is_a_vector();
    test_point_creates_tuples_with_w_1();
    test_vector_creates_tuples_with_w_0();
    test_adding_two_tuples();
    test_subtracting_two_points();
    test_subtracting_vector_from_point();
    test_subtracting_two_vectors();
    test_subtracting_vector_from_zero_vector();
    test_negating_tuple();
    test_multiplying_tuple_by_scalar();
    test_multiplying_tuple_by_fraction();
    test_dividing_tuple_by_scalar();
}

