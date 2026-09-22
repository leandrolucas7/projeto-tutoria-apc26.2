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
    unsigned end_cycle; 
    unsigned short cycles_per_scene; // 3: the scene changes every 3 "cycles" (fps)
    unsigned short scene_tracker;
    unsigned short layer; // bigger number, "closer to the camera" (overlaps other Sequences)
    unsigned short repetitions;
    Sequence *sequence;
} SequenceInstance;


typedef struct {
    unsigned count;
    unsigned capacity;
    unsigned total_cycles; // total_cycles/fps = duration in seconds
    unsigned short fps;
    unsigned short repetitions;
    SequenceInstance **instances;
} Animation;

#endif
