#include <stdio.h>
#include "lib/definitions.h"
#include "lib/lib.c"
#include "lib/fonts/basic.h"
#include "lib/sprites/boy_scout.h"

int main(void)
{
    Canvas *canvas = create_canvas(62, 35);
    Drawing A = basic['A'];
    Drawing B = basic['B'];
    Drawing boy = Boy;

    Scene *AB = create_scene();
    insert_Drawing(&A, 25, 15, AB);
    insert_Drawing(&B, 31, 15, AB);

    Scene *A_AB_B = create_scene();
    insert_Drawing(&A, 3, 15, A_AB_B);
    insert_Drawing(&A, 25, 15, A_AB_B);
    insert_Drawing(&B, 31, 15, A_AB_B);
    insert_Drawing(&B, 54, 15, A_AB_B);

    Scene *BA = create_scene();
    insert_Drawing(&B, 25, 15, BA);
    insert_Drawing(&A, 31, 15, BA);

    Scene *B_BA_A = create_scene();
    insert_Drawing(&B, 3, 15, B_BA_A);
    insert_Drawing(&B, 25, 15, B_BA_A);
    insert_Drawing(&A, 31, 15, B_BA_A);
    insert_Drawing(&A, 54, 15, B_BA_A);

    Sequence *seq1 = create_sequence();
    insert_Scene(AB, seq1);
    insert_Scene(A_AB_B, seq1);
    insert_Scene(BA, seq1);
    insert_Scene(B_BA_A, seq1);

    //Sequence *seq2 = create_sequence();
    //insert_Scene(AB, seq2);

    Animation *animation = create_animation(20, 2);
    insert_Sequence(seq1, 0, 39, 10, 0, 2, animation);

    run_animation(animation, canvas);

    // free scenes 
    // free sequences
    //free_animation(animation);
    //free_scene(scene);
    free_canvas(canvas);
    canvas = NULL;
}
