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
} SceneObject;


typedef struct {
    unsigned count;
    unsigned capacity;
    SceneObject **objects;
} Scene;


typedef struct {
    unsigned count;
    unsigned capacity;
    Scene **scenes;
}Sequence;


typedef struct {
    unsigned start_cycle;
    unsigned end_cycle; // not included: [start, end) => duration = end - start
    unsigned cycles_per_scene; // 3: the scene changes every 3 "cycles" (fps)
    unsigned layer; // bigger number, "closer to the camera" (overlaps other Sequences)
    Sequence *sequence;
} SequenceInstance;


typedef struct {
    unsigned count;
    unsigned capacity;
    unsigned fps;
    unsigned total_cycles; // total_cycles/fps = duration in seconds
    SequenceInstance **instances;
} Animation;

#endif
