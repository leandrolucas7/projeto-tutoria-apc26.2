#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct {
    unsigned width;
    unsigned height;
    char **area;
} Canvas;

typedef struct {
    unsigned width;
    unsigned height;
    const char *data;
} Drawing;

#endif
