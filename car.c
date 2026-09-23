#include <stdio.h>
#include "lib/lib.c"
#include "lib/sprites/props.h"

int main(void)
{
    Canvas *canvas = create_canvas(180, 30);
    Animation *animation = create_animation(15, 1);
    Sequence *sequence = create_sequence();

    const unsigned scene_count = 27;
    Scene **scenes = malloc(sizeof(Scene *) * scene_count);

    unsigned x = 0;
    unsigned x_inc = 7;
    unsigned y = 5;

    for (unsigned i = 0; i < scene_count; i++)
    {
        scenes[i] = create_scene();

        insert_Drawing(&ClassicCar, x, y, scenes[i]);
        insert_Scene(scenes[i], sequence);

        x += x_inc;
    }

    insert_Sequence(
        sequence,
        0,
        scene_count - 1,
        0,                  // layer
        3,                  // repeat
        animation
    );

    run_animation(animation, canvas);

    return 0;
}
