#include <stdio.h>
#include "lib/definitions.h"
#include "lib/lib.c"
#include "lib/fonts/basic.h"

#define WIDTH 82
#define HEIGHT 27

int main(void)
{
    Canvas *canvas = create_canvas(10, 10);
    Drawing A = basic['A'];
    Drawing B = basic['B'];
    FrameObject A1 = {
        .x = 1,
        .y = 1,
        .z = 0,
        .whitespaces = 0,
        .drawing = &A
    };
    FrameObject A2 = {
        .x = 1,
        .y = 5,
        .z = 1,
        .whitespaces = 0,
        .drawing = &A
    };
    FrameObject B1 = {
        .x = 3,
        .y = 3,
        .z = 2,
        .whitespaces = 0,
        .drawing = &B
    };

    Frame *frame = create_frame();
    insert_FrameObject(&B1, frame);
    insert_FrameObject(&A1, frame);
    insert_FrameObject(&A2, frame);
    draw_frame(frame, canvas);
    render_canvas(canvas);

    free_frame(frame);
    free_canvas(canvas);
    canvas = NULL;
}
