#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

/* CANVAS */
void initialize_canvas(Canvas *canvas)
{
    for (unsigned i = 0; i < canvas->height + 2; i++)
    {
        char c1 = '#';
        char c2 = ' ';
        if (i == 0 || i == canvas->height + 1)
        {
            c2 = c1;
        }

        canvas->area[i][0] = c1;
        for (unsigned j = 1; j <= canvas->width; j++)
            canvas->area[i][j] = c2;
        canvas->area[i][canvas->width + 1] = c1;
    }
}


Canvas *create_canvas(unsigned width, unsigned height)
{
    Canvas *canvas = malloc(sizeof(Canvas));
    char **area = malloc((height + 2) * sizeof(char*));
    for (int i = 0; i < height + 2; i++)
    {
        area[i] = malloc(width + 2);
    }
    
    canvas->width = width;
    canvas->height = height;
    canvas->area = area;
    initialize_canvas(canvas);
    
    return canvas;
}


void free_canvas(Canvas *canvas)
{
    for (int i = 0; i < canvas->height + 2; i++)
    {
        free(canvas->area[i]);
    }

    free(canvas->area);
    canvas->area = NULL;
    free(canvas);
}


void draw_on_canvas(Drawing *drawing, Canvas *canvas, unsigned x, unsigned y, unsigned whitespaces)
{
    // Only check if the starting coordinate is inside the canvas 
        // The user must check if the whole image fits
    if (x > canvas->width || y > canvas->height)
        return;

    int row = 0;
    for (int i = 0; i < drawing->height; i++)
    {
        for (int j = 0; j < drawing->width; j++)
        {
            char c = drawing->data[j+row];
            if (!whitespaces && c == ' ')
                continue;
            canvas->area[i+y+1][j+x+1] = c;
        }
        row += drawing->width;
    }
}


void clear_canvas(Canvas *canvas) 
{
    initialize_canvas(canvas);
}


void render_canvas(Canvas *canvas)
{
    for (unsigned i = 0; i < canvas->height+2; i++)
    {
        for (int j = 0; j < canvas->width+2; j++)
            printf("%c", canvas->area[i][j]);

        printf("\n");
    }
}


/* Scenes */
Scene *create_scene()
{
    unsigned initial_size = 5;
    Scene *scene = malloc(sizeof(Scene));
    SceneObject **objects = malloc(initial_size * sizeof(SceneObject*));

    scene->count = 0;
    scene->capacity = initial_size;
    scene->objects = objects;
    return scene;
}


void free_scene(Scene *scene)
{
    free(scene->objects);
    free(scene);
}


void insert_SceneObject(SceneObject *object, Scene *scene)
{
    if (scene->count >= scene->capacity)
    {
        unsigned new_cap = scene->capacity * 2;
        SceneObject **temp = realloc(scene->objects, new_cap * sizeof(SceneObject*));

        // Not checking if realloc failed!!
        scene->objects = temp;
        scene->capacity = new_cap;
    }

    unsigned left = 0;
    unsigned right = scene->count;
    while (right > left)
    {
        unsigned mid = left + (right - left) / 2;
        if (object->z >= scene->objects[mid]->z)
            left = mid + 1;
        else 
            right = mid;
    }

    for (unsigned i = scene->count; i > left; i--)
        scene->objects[i] = scene->objects[i-1];
    scene->objects[left] = object;
    scene->count++;
}


void draw_scene(Scene *scene, Canvas *canvas)
{
    for (int i = 0; i < scene->count; i++)
        draw_on_canvas(scene->objects[i]->drawing, canvas, scene->objects[i]->x, scene->objects[i]->y, scene->objects[i]->whitespaces);
}


/* SEQUENCES */
Sequence *create_sequence()
{
    unsigned initial_size = 5;
    Sequence *sequence = malloc(sizeof(Sequence));
    Scene **scenes = malloc(initial_size * sizeof(Scene*));

    sequence->count = 0;
    sequence->capacity = initial_size;
    sequence->scenes = scenes;
    return sequence;
}


void free_sequence(Sequence *sequence)
{
    free(sequence->scenes);
    free(sequence);
}


void insert_Scene(Scene *scene, Sequence *sequence)
{
    if (sequence->count >= sequence->capacity)
    {
        unsigned new_cap = sequence->capacity * 2;
        Scene **temp = realloc(sequence->scenes , new_cap * sizeof(Scene*));

        // Not checking if realloc failed!!
        sequence->scenes = temp;
        sequence->capacity = new_cap;
    }

    sequence->scenes[sequence->count++] = scene;
}


/* ANIMATIONS */
Animation *create_animation()
{
    unsigned initial_size = 5;
    Animation *animation = malloc(sizeof(Animation));
    SequenceInstance **instances = malloc(initial_size * sizeof(SequenceInstance*));

    animation->count = 0;
    animation->capacity = initial_size;
    animation->instances = instances;
    return animation;
}


void free_animation(Animation *animation)
{
    free(animation->instances);
    free(animation);
}


void insert_SequenceInstance(SequenceInstance *instance, Animation *animation)
{
    if (animation->count >= animation->capacity)
    {
        unsigned new_cap = animation->capacity * 2;
        SequenceInstance **temp = realloc(animation->instances, new_cap * sizeof(SequenceInstance*));

        // Not checking if realloc failed!!
        animation->instances = temp;
        animation->capacity = new_cap;
    }

    unsigned left = 0;
    unsigned right = animation->count;
    while (right > left)
    {
        unsigned mid = left + (right - left) / 2;
        if (instance->layer >= animation->instances[mid]->layer)
            left = mid + 1;
        else 
            right = mid;
    }

    for (unsigned i = animation->count; i > left; i--)
        animation->instances[i] = animation->instances[i-1];
    animation->instances[left] = instance;
    animation->count++;
}


void run_animation(Animation animation)
{
    // Implemente the logic
}
