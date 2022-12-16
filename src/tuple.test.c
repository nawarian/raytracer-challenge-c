#include <assert.h>
#include <stdbool.h>
#include <math.h>

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

/**
 * Scenario: Computing the magnitude of vector(1, 0, 0)
 *
 * Given v ← vector(1, 0, 0)
 * Then magnitude(v) = 1
 */
void test_computing_magnitude_vector_1_0_0(void)
{
    tuple_t v = vector(1, 0, 0);

    assert(fequal(vector_magnitude(v), 1));
}

/**
 * Scenario: Computing the magnitude of vector(0, 1, 0)
 *
 * Given v ← vector(0, 1, 0)
 * Then magnitude(v) = 1
 */
void test_computing_magnitude_vector_0_1_0(void)
{
    tuple_t v = vector(0, 1, 0);

    assert(fequal(vector_magnitude(v), 1));
}

/**
 * Scenario: Computing the magnitude of vector(0, 0, 1)
 *
 * Given v ← vector(0, 0, 1)
 * Then magnitude(v) = 1
 */
void test_computing_magnitude_vector_0_0_1(void)
{
    tuple_t v = vector(0, 0, 1);

    assert(fequal(vector_magnitude(v), 1));
}

/**
 * Scenario: Computing the magnitude of vector(1, 2, 3)
 *
 * Given v ← vector(1, 2, 3)
 * Then magnitude(v) = √14
 */
void test_computing_magnitude_vector_1_2_3(void)
{
    tuple_t v = vector(1, 2, 3);

    assert(fequal(vector_magnitude(v), sqrt(14)));
}

/**
 * Scenario: Computing the magnitude of vector(-1, -2, -3)
 *
 * Given v ← vector(-1, -2, -3)
 * Then magnitude(v) = √14
 */
void test_computing_magnitude_vector_n1_n2_n3(void)
{
    tuple_t v = vector(-1, -2, -3);

    assert(fequal(vector_magnitude(v), sqrt(14)));
}

/**
 * Scenario: Normalizing vector(4, 0, 0) gives (1, 0, 0)
 *
 * Given v ← vector(4, 0, 0)
 * Then normalize(v) = vector(1, 0, 0)
 */
void test_normalizing_vector_4_0_0_gives_1_0_0(void)
{
    tuple_t v = vector(4, 0, 0);

    assert(tuple_equals(vector_normalize(v), vector(1, 0, 0)));
}

/**
 * Scenario: Normalizing vector(1, 2, 3)
 *
 * Given v ← vector(1, 2, 3) # vector(1/√14, 2/√14, 3/√14)
 *  Then normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)
 */
void test_normalizing_vector_1_2_3(void)
{
    tuple_t v = vector(1, 2, 3);

    assert(tuple_equals(vector_normalize(v), vector(0.26726, 0.53452, 0.80178)));
}

/**
 * Scenario: The magnitude of a normalized vector
 *
 * Given v ← vector(1, 2, 3)
 * When norm ← normalize(v)
 * Then magnitude(norm) = 1
 */
void test_magnitude_of_normalized_vector(void)
{
    tuple_t v = vector(1, 2, 3);
    tuple_t norm = vector_normalize(v);

    assert(fequal(vector_magnitude(norm), 1));
}

/**
 * Scenario: The dot product of two tuples
 *
 * Given a ← vector(1, 2, 3)
 *   And b ← vector(2, 3, 4)
 * Then dot(a, b) = 20
 */
void test_dot_product_of_two_tuples(void)
{
    tuple_t a = vector(1, 2, 3);
    tuple_t b = vector(2, 3, 4);

    assert(fequal(vector_dot(a, b), 20));
}

/**
 * Scenario: The cross product of two vectors
 *
 * Given a ← vector(1, 2, 3)
 *   And b ← vector(2, 3, 4)
 * Then cross(a, b) = vector(-1, 2, -1)
 *   And cross(b, a) = vector(1, -2, 1)
 */
void test_cross_product_of_two_vectors(void)
{
    tuple_t a = vector(1, 2, 3);
    tuple_t b = vector(2, 3, 4);

    assert(tuple_equals(vector_cross(a, b), vector(-1, 2, -1)));
    assert(tuple_equals(vector_cross(b, a), vector(1, -2, 1)));
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
    test_computing_magnitude_vector_1_0_0();
    test_computing_magnitude_vector_0_1_0();
    test_computing_magnitude_vector_0_0_1();
    test_computing_magnitude_vector_1_2_3();
    test_computing_magnitude_vector_n1_n2_n3();
    test_normalizing_vector_4_0_0_gives_1_0_0();
    test_normalizing_vector_1_2_3();
    test_magnitude_of_normalized_vector();
    test_dot_product_of_two_tuples();
    test_cross_product_of_two_vectors();

    return 0;
}

