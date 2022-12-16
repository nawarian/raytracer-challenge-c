#include <assert.h>
#include "tuple.h"
#include "color.h"
#include "utils.h"

/**
 * Scenario: Colors are (red, green, blue) tuples
 *
 * Given c ← color(-0.5, 0.4, 1.7)
 * Then c.red = -0.5
 *   And c.green = 0.4
 *   And c.blue = 1.7
 */
void test_colors_are_red_green_blue_tuples(void)
{
    color_t c = color(-0.5, 0.4, 1.7);

    assert(fequal(c.x, -0.5));
    assert(fequal(c.y, 0.4));
    assert(fequal(c.z, 1.7));
}

/**
 * Scenario: Adding colors
 *
 * Given c1 ← color(0.9, 0.6, 0.75)
 *   And c2 ← color(0.7, 0.1, 0.25)
 *  Then c1 + c2 = color(1.6, 0.7, 1.0)
 */
void test_adding_colors(void)
{
    color_t c1 = color(0.9, 0.6, 0.75);
    color_t c2 = color(0.7, 0.1, 0.25);

    assert(tuple_equals(color_sum(c1, c2), color(1.6, 0.7, 1.0)));
}

/**
 * Scenario: Subtracting colors
 *
 * Given c1 ← color(0.9, 0.6, 0.75)
 *   And c2 ← color(0.7, 0.1, 0.25)
 *  Then c1 - c2 = color(0.2, 0.5, 0.5)
 */
void test_subtracting_colors(void)
{
    color_t c1 = color(0.9, 0.6, 0.75);
    color_t c2 = color(0.7, 0.1, 0.25);

    assert(tuple_equals(color_sub(c1, c2), color(0.2, 0.5, 0.5)));
}

/**
 * Scenario: Multiplying a color by a scalar
 *
 * Given c ← color(0.2, 0.3, 0.4)
 * Then c * 2 = color(0.4, 0.6, 0.8)
 */
void test_multiplying_color_by_scalar(void)
{
    color_t c = color(0.2, 0.3, 0.4);

    assert(tuple_equals(color_mul(c, 2), color(0.4, 0.6, 0.8)));
}

/**
 * Scenario: Multiplying colors
 *
 * Given c1 ← color(1, 0.2, 0.4)
 *   And c2 ← color(0.9, 1, 0.1)
 *  Then c1 * c2 = color(0.9, 0.2, 0.04)
 */
void test_multiplying_colors(void)
{
    color_t c1 = color(1, 0.2, 0.4);
    color_t c2 = color(0.9, 1, 0.1);

    assert(tuple_equals(color_product(c1, c2), color(0.9, 0.2, 0.04)));
}

int main(void)
{
    test_colors_are_red_green_blue_tuples();
    test_adding_colors();
    test_subtracting_colors();
    test_multiplying_color_by_scalar();
    test_multiplying_colors();

    return 0;
}

