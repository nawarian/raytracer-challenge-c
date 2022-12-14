#include <stdlib.h>

#include "canvas.h"

canvas_t canvas(int width, int height)
{
    color_t *pixels = calloc(width * height, sizeof(color_t));

    return (canvas_t) {
        width,
        height,
        pixels
    };
}

void canvas_destroy(canvas_t canvas)
{
    free(canvas.pixels);
}

