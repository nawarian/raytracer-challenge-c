#ifndef _canvas_h_
#define _canvas_h_

#include "color.h"

typedef struct {
    int width;
    int height;
    color_t *pixels;
} canvas_t;

canvas_t canvas(int width, int height);
void canvas_destroy(canvas_t canvas);
void canvas_write(canvas_t canvas, int x, int y, color_t color);
color_t canvas_pixel_at(canvas_t canvas, int x, int y);
unsigned char *canvas_to_ppm(canvas_t canvas);

#endif

