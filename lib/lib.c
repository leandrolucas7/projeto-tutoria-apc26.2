#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

void fill_borders(Canvas *canvas)
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
    fill_borders(canvas);
    
    return canvas;
}


void draw_on_canvas(Drawing *drawing, Canvas *canvas, unsigned x, unsigned y)
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
            canvas->area[i+y+1][j+x+1] = drawing->data[j+row];
        }
        row += drawing->width;
    }
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

/*int main(void)
{

       
    int idx = 0;
    for(int i = 0; i < basic['A'].height; i++)
    {
        for (int j =0; j < basic['A'].width; j++)
            printf("%c", basic['A'].data[idx++]);
        printf("\n");
    }

    printf("\n");

}*/

