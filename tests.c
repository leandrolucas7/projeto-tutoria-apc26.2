#include <stdio.h>
#include "lib/lib.c"
#include "lib/sprites/boy_scout.h"
#include "lib/timer.c"

#define WIDTH 82
#define HEIGHT 27

int main(void)
{
    Canvas *canvas = create_canvas(50, 50);
    //Drawing A = basic['A'];
    Drawing A = Boy;
    SceneObject A1 = {
        .x = 1,
        .y = 1,
        .z = 0,
        .whitespaces = 0,
        .drawing = &A
    };

    Scene *scene = create_scene();
    insert_SceneObject(&A1, scene);
    draw_scene(scene, canvas);
    render_canvas(canvas);

    free_scene(scene);
    free_canvas(canvas);
    canvas = NULL;


    unsigned t = 4000000000;
    wait_ns(t);
    printf("After waiting\n");
}
