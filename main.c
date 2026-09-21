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
    SceneObject A1 = {
        .x = 1,
        .y = 1,
        .z = 0,
        .whitespaces = 0,
        .drawing = &A
    };
    SceneObject A2 = {
        .x = 1,
        .y = 5,
        .z = 1,
        .whitespaces = 0,
        .drawing = &A
    };
    SceneObject B1 = {
        .x = 3,
        .y = 3,
        .z = 2,
        .whitespaces = 0,
        .drawing = &B
    };

    Scene *scene = create_scene();
    insert_SceneObject(&B1, scene);
    insert_SceneObject(&A1, scene);
    insert_SceneObject(&A2, scene);
    draw_scene(scene, canvas);
    render_canvas(canvas);

    free_scene(scene);
    free_canvas(canvas);
    canvas = NULL;
}
