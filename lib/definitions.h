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


typedef struct {
    unsigned x;
    unsigned y;
    int z; // Used to indicate the proximity/distance to the screen and order of "painting" of the drawings (- -> +)
    unsigned whitespaces;
    Drawing *drawing;
} FrameObject;


typedef struct {
    unsigned count;
    unsigned capacity;
    FrameObject **objects;
}Frame;

#endif
