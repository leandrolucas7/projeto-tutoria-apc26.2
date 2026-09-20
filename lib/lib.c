#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

/* CANVAS */
void initialize_canvas(Canvas *canvas)
{
    for (int i = 0; i < canvas->height + 2; i++)
    {
        char c1 = '#';
        char c2 = ' ';
        if (i == 0 || i == canvas->height + 1)
        {
            c2 = c1;
        }

        canvas->area[i][0] = c1;
        for (int j = 1; j <= canvas->width; j++)
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
    for (int i = 0; i < canvas->height+2; i++)
    {
        for (int j = 0; j < canvas->width+2; j++)
            printf("%c", canvas->area[i][j]);

        printf("\n");
    }
}


/* FRAMES */

Frame *create_frame()
{
    unsigned initial_size = 5;
    Frame *frame = malloc(sizeof(Frame));
    FrameObject **objects = malloc(initial_size * sizeof(FrameObject*));

    frame->count = 0;
    frame->capacity = initial_size;
    frame->objects = objects;
    return frame;
}


void free_frame(Frame *frame)
{
    free(frame->objects);
    free(frame);
}


void insert_FrameObject(FrameObject *object, Frame *frame)
{
    if (frame->count >= frame->capacity)
    {
        unsigned new_cap = frame->capacity * 2;
        FrameObject **temp = realloc(frame->objects, new_cap * sizeof(FrameObject*));

        // Not checking if realloc failed!!
        frame->objects = temp;
        frame->capacity = new_cap;
    }

    unsigned left = 0;
    unsigned right = frame->count;
    while (right > left)
    {
        unsigned mid = left + (right - left) / 2;
        if (object->z >= frame->objects[mid]->z)
            left = mid + 1;
        else 
            right = mid;
    }

    for (unsigned i = frame->count; i > left; i--)
        frame->objects[i] = frame->objects[i-1];
    frame->objects[left] = object;
    frame->count++;
}


void draw_frame(Frame *frame, Canvas *canvas)
{
    for (int i = 0; i < frame->count; i++)
        draw_on_canvas(frame->objects[i]->drawing, canvas, frame->objects[i]->x, frame->objects[i]->y, frame->objects[i]->whitespaces);
}
