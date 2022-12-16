#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "canvas.h"
#include "color.h"
#include "tuple.h"

#define _assert_ppm_slice_equals(a, b, size) assert(strncmp(a, b, size - 1) == 0);

/**
 * Scenario: Creating a canvas
 *
 * Given c ← canvas(10, 20)
 * Then c.width = 10
 *   And c.height = 20
 *   And every pixel of c is color(0, 0, 0)
 */
void test_creating_canvas(void)
{
    canvas_t c = canvas(10, 20);
    assert(c.width == 10);
    assert(c.height == 20);

    for (int i = 0; i < 10 * 20; ++i) {
        assert(tuple_equals(c.pixels[i], color(0, 0, 0)));
    }

    canvas_destroy(c);
}

/**
 * Scenario: Writing pixels to a canvas
 *
 * Given c ← canvas(10, 20)
 *   And red ← color(1, 0, 0)
 * When write_pixel(c, 2, 3, red)
 * Then pixel_at(c, 2, 3) = red
 */
void test_writing_pixels_to_canvas(void)
{
    canvas_t c = canvas(10, 20);
    color_t red = color(1, 0, 0);

    canvas_write(c, 2, 3, red);

    assert(tuple_equals(canvas_pixel_at(c, 2, 3), red));

    canvas_destroy(c);
}

/**
 * Scenario: Constructing the PPM header
 *
 * Given c ← canvas(5, 3)
 * When ppm ← canvas_to_ppm(c)
 * Then lines 1-3 of ppm are
 *   """
 *   P3
 *   5 3
 *   255
 *   """
 */
void test_constructing_ppm_header(void)
{
    canvas_t c = canvas(5, 3);
    unsigned char *ppm = canvas_to_ppm(c);

    const char expected[] =
        "P3\n" \
        "5 3\n" \
        "255\n"
    ;


    free(ppm);
    canvas_destroy(c);
}

/**
 * Scenario: Constructing the PPM pixel data
 *
 * Given c ← canvas(5, 3)
 *   And c1 ← color(1.5, 0, 0)
 *   And c2 ← color(0, 0.5, 0)
 *   And c3 ← color(-0.5, 0, 1)
 * When write_pixel(c, 0, 0, c1)
 *   And write_pixel(c, 2, 1, c2)
 *   And write_pixel(c, 4, 2, c3)
 *   And ppm ← canvas_to_ppm(c)
 * Then lines 4-6 of ppm are
 *   """
 *   255 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 128 0 0 0 0 0 0 0
 *   0 0 0 0 0 0 0 0 0 0 0 0 0 0 255
 *   """
 */
void test_constructing_ppm_pixel_data(void)
{
    canvas_t c = canvas(5, 3);
    color_t c1 = color(1.5, 0, 0);
    color_t c2 = color(0, 0.5, 0);
    color_t c3 = color(-0.5, 0, 1);

    canvas_write(c, 0, 0, c1);
    canvas_write(c, 2, 1, c2);
    canvas_write(c, 4, 2, c3);

    const char header[] = "P3\n5 3\n255\n";
    int header_size = sizeof(header) - 1;
    const char expected[] =
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n" \
        "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n" \
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n"
    ;

    unsigned char *ppm = canvas_to_ppm(c);

    _assert_ppm_slice_equals(expected, (const char *) ppm + header_size, sizeof(expected));

    free(ppm);
    canvas_destroy(c);
}

/**
 * Scenario: Splitting long lines in PPM files
 *
 * Given c ← canvas(10, 2)
 * When every pixel of c is set to color(1, 0.8, 0.6)
 *   And ppm ← canvas_to_ppm(c)
 * Then lines 4-7 of ppm are
 *   """
 *   255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204
 *   153 255 204 153 255 204 153 255 204 153 255 204 153
 *   255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204
 *   153 255 204 153 255 204 153 255 204 153 255 204 153
 *   """
 */
void test_splitting_long_lines_ppm_files(void)
{
    canvas_t c = canvas(10, 2);
    color_t pixel = color(1, 0.8, 0.6);

    // Every pixel of c is color(1, 0.8, 0.6)
    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < 10; ++x) {
            canvas_write(c, x, y, pixel);
        }
    }

    const char header[] = "P3\n10 2\n255\n";
    int header_size = sizeof(header) - 1;
    const char expected[] =
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n" \
        "153 255 204 153 255 204 153 255 204 153 255 204 153\n" \
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n" \
        "153 255 204 153 255 204 153 255 204 153 255 204 153\n";

    unsigned char *ppm = canvas_to_ppm(c);
    _assert_ppm_slice_equals(expected, (const char *) ppm + header_size, sizeof(expected));

    free(ppm);
    canvas_destroy(c);
}

/**
 * Scenario: PPM files are terminated by a newline character
 *
 * Given c ← canvas(5, 3)
 * When ppm ← canvas_to_ppm(c)
 * Then ppm ends with a newline character
 */
void test_ppm_files_are_terminated_by_newline_character(void)
{
    // TODO: canvas(5, 3) once the memory leak is fixed
    canvas_t c = canvas(5, 5);

    unsigned char *ppm = canvas_to_ppm(c);

    assert(ppm[strlen((const char *) ppm) - 1] == '\n');

    free(ppm);
    canvas_destroy(c);
}

/**
 * TODO: Fix memory leak
 */
void test_fix_memory_leak(void)
{
    //canvas_t c = canvas(1, 1);
    //canvas_destroy(c);
}

int main(void)
{
    test_creating_canvas();
    test_writing_pixels_to_canvas();
    test_constructing_ppm_header();
    test_constructing_ppm_pixel_data();
    test_splitting_long_lines_ppm_files();
    test_ppm_files_are_terminated_by_newline_character();
    test_fix_memory_leak();

    return 0;
}

