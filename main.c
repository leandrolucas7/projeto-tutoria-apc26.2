#include <stdio.h>
#include "lib/definitions.h"
#include "lib/lib.c"
#include "lib/fonts/basic.h"

#define WIDTH 82
#define HEIGHT 27

int main(void)
{
    Canvas *canvas = create_canvas(13, 13);
    Drawing A = basic['A'];
    Drawing B = basic['B'];
    draw_on_canvas(&A, canvas, 1, 1);
    draw_on_canvas(&B, canvas, 7, 1);
    draw_on_canvas(&B, canvas, 1, 7);
    draw_on_canvas(&A, canvas, 7, 7);
    render_canvas(canvas);

    free_canvas(canvas);
    canvas = NULL;
}
