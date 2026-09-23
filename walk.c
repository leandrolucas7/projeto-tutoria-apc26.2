#include <stdio.h>
#include "lib/lib.c"
#include "lib/sprites/farmer.h"

int main(void)
{
    Canvas *canvas = create_canvas(80, 40);
    Animation * animation = create_animation(10, 2);
    Sequence *sequence = create_sequence();
    Scene **scenes = malloc(sizeof(Scene*) * FarmGirl.walk_r_count);

    unsigned x = 2;
    unsigned x_inc = 3;
    unsigned y = 9;
    for (int i = 0; i < FarmGirl.walk_r_count; i++)
    {
        scenes[i] = create_scene();
        insert_Drawing(&FarmGirl.walk_r[i], x, y, scenes[i]);
        insert_Scene(scenes[i], sequence);
        x += x_inc;
    }

    insert_Sequence(sequence, 0, 23, 4, 0, 2, animation);
    run_animation(animation, canvas);

}
