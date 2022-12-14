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

#endif

