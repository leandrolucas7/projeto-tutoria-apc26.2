#include <stdio.h>
#include "lib/definitions.h"
#include "lib/lib.c"
#include "lib/fonts/basic.h"
#include "lib/sprites/boy_scout.h"

int main(void)
{
    Canvas *canvas = create_canvas(100, 20);
    Drawing A = basic['A'];
    Drawing B = basic['B'];
    Drawing boy = Boy;

    SceneObject A1 = {
        .x = 4,
        .y = 4,
        .z = 0,
        .whitespaces = 0,
        .drawing = &A
    };
    SceneObject B1 = {
        .x = 90,
        .y = 4,
        .z = 0,
        .whitespaces = 0,
        .drawing = &B
    };
    Scene *A_B = create_scene();
    insert_SceneObject(&A1, A_B);
    insert_SceneObject(&B1, A_B);

    SceneObject A2 = {
        .x = 90,
        .y = 4,
        .z = 0,
        .whitespaces = 0,
        .drawing = &A
    };
    SceneObject B2 = {
        .x = 4,
        .y = 4,
        .z = 0,
        .whitespaces = 0,
        .drawing = &B
    };
    Scene *B_A = create_scene();
    insert_SceneObject(&A2, B_A);
    insert_SceneObject(&B2, B_A);

    SceneObject A3 = {
        .x = 43,
        .y = 4,
        .z = 0,
        .whitespaces = 0,
        .drawing = &A
    };
    SceneObject B3 = {
        .x = 51,
        .y = 4,
        .z = 0,
        .whitespaces = 0,
        .drawing = &B
    };
    Scene *AB = create_scene();
    insert_SceneObject(&A3, AB);
    insert_SceneObject(&B3, AB);

    Sequence *seq1 = create_sequence();
    insert_Scene(A_B, seq1);
    insert_Scene(B_A, seq1);

    Sequence *seq2 = create_sequence();
    insert_Scene(AB, seq2);

    Animation *animation = create_animation(20, 2);
    insert_Sequence(seq1, 0, 39, 20, 0, 1, animation);
    insert_Sequence(seq2, 39, 48, 10, 0, 1, animation);
    insert_Sequence(seq1, 48, 87, 20, 0, 1, animation);

    run_animation(animation, canvas);

    // free scenes 
    // free sequences
    //free_animation(animation);
    //free_scene(scene);
    free_canvas(canvas);
    canvas = NULL;
}
