#include <stdio.h>
#include "lib/lib.c"
#include "lib/sprites/hat_girl.h"
#include "lib/sprites/boy.h"
#include "lib/sprites/props.h"

int main(void)
{
    Canvas *canvas = create_canvas(180, 70);
    Animation * animation = create_animation(10, 2);
    Sequence *sequence = create_sequence();
    Scene **scenes = malloc(sizeof(Scene*) * HatGirl.walk_r_count);

    unsigned x = 2;
    unsigned x_inc = 3;
    unsigned y = 39;
    for (int i = 0; i < HatGirl.walk_r_count; i++)
    {
        scenes[i] = create_scene();
        insert_Drawing(&HatGirl.walk_r[i], x, y, scenes[i]);
        insert_Drawing(&Boy.walk_r[i], x+35, y, scenes[i]);
        insert_Drawing(&Sun, 130, 1, scenes[i]);
        insert_Drawing(&Cloud, 10, 3, scenes[i]);
        insert_Drawing(&Cloud, 60, 3, scenes[i]);
        insert_Drawing(&House, 87, 28, scenes[i]);
        insert_Scene(scenes[i], sequence);
        x += x_inc;
    }

    insert_Sequence(sequence, 0, 23, 0, 2, animation);
    run_animation(animation, canvas);

}
