#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "canvas.h"
#include "color.h"

#define _get_pixel_index(canvas, x, y) (canvas.width * y) + x

/**
 * Creates a new instance of `canvas_t` with `width * height` pixels.
 * The caller is responsible for freeing the canvas' memory by calling `canvas_destroy()`.
 */
canvas_t canvas(int width, int height)
{
    color_t *pixels = calloc(width * height, sizeof(color_t));

    return (canvas_t) {
        width,
        height,
        pixels
    };
}

/**
 * Frees the memory held by `canvas.pixels`.
 */
void canvas_destroy(canvas_t canvas)
{
    free(canvas.pixels);
}

color_t canvas_pixel_at(canvas_t canvas, int x, int y)
{
    int index = _get_pixel_index(canvas, x, y);

    return canvas.pixels[index];
}

void canvas_write(canvas_t canvas, int x, int y, color_t color)
{
    int index = _get_pixel_index(canvas, x, y);

    canvas.pixels[index] = color;
}

// helper macro to simplify canvas_to_ppm()
#define _write_pixel(color_idx) { \
    color_size = sprintf((char *) buff, "%d", color_tuple[color_idx]); \
    /* line limit reached? */ \
    if (row_cursor + color_size > 70) { \
        row_cursor = 0; \
        ppm[ppm_cursor - 1] = '\n'; \
    } \
    memcpy(ppm + ppm_cursor, buff, color_size); \
    ppm_cursor += color_size; \
    ppm[ppm_cursor++] = ' '; \
    row_cursor += color_size + 1; \
}
/**
 * Converts the `canvas_t` object to a binary stream.
 * The caller is responsible for freeing the result's memory.
 */
unsigned char *canvas_to_ppm(canvas_t canvas)
{
    int ppm_size = canvas.height * 70 + canvas.height;

    unsigned char *ppm = calloc(ppm_size, sizeof(unsigned char));

    // Write header
    int ppm_cursor = sprintf((char *) ppm, "P3\n%d %d\n255\n", canvas.width, canvas.height);

    // Write color map
    color_t pixel;
    int color_size;
    int row_cursor;
    unsigned char buff[4];
    unsigned char color_tuple[3];
    for (int row = 0; row < canvas.height; ++row) {
        row_cursor = 0;
        for (int col = 0; col < canvas.width; ++col) {
            pixel = canvas_pixel_at(canvas, col, row);
            color_to_rgb(pixel, color_tuple);

            _write_pixel(0); // red
            _write_pixel(1); // green
            _write_pixel(2); // blue
        }

        ppm[ppm_cursor - 1] = '\n';
    }

    return ppm;
}

