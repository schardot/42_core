#include "../include/minilibx-linux/mlx.h"
#include "../include/so_long.h"
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


void grid_to_img(char **map, gamedata *d)
{
    int w;
    int h;
    int size;

    size = 32;
    h = 0;
    while (map[h])
    {
        w = 0;
        while (map[h][w])
        {
            if (map[h][w] == '1')
                mlx_put_image_to_window(d->connection, d->window, d->wallimage, size, size);
            else if (map[h][w] == '0')
                mlx_put_image_to_window(d->connection, d->window, d->tileimage, size, size);
            else if (map[h][w] == 'P')
                mlx_put_image_to_window(d->connection, d->window, d->playerimage, size, size);
            else if (map[h][w] == 'C')
                mlx_put_image_to_window(d->connection, d->window, d->coinimage, size, size);
            else if (map[h][w] == 'E')
                mlx_put_image_to_window(d->connection, d->window, d->exitimage, size, size);
            w ++;
        }
        h ++;
    }
}