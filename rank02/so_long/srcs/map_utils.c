#include "../include/minilibx-linux/mlx.h"
#include "../include/so_long.h"
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

char **ber_to_grid(int fd) // it will create and populate a grid with information of the map. it will then check is all the characters a valid. it doesnt check if theres a valid path.
{
    int     height = 0;
    int     width;
    char    *line;
    char    **map;
    int     m = 0;

    line = get_next_line(fd);
    map = (char **)malloc(sizeof(char *) * (height + 2));
    map[m] = ft_strdup(line);
    m++;
    height++;
    while (line)
    {
        line = get_next_line(fd);
        map = ft_grdrealloc(map, height + 2);
        map[m] = ft_strdup(line);
        m++;
        height++;
    }
    //check_map(map);
    return (map);
}

// void check_map(char **map)
// {
//     1. check if all the borders are 1(walls)

//         int w;
//     int h;

//     // for now i declared variables so i can count E, P and C but im sure theres a more efficient way to do it.
//     int E;
//     int P;
//     int C;
//     E = 0;
//     P = 0;
//     C = 0;

//     w = 0;
//     h = 0;
//     while (map[h])
//     {
//         while (map[h][w])
//         {
//             if ((h == 0 || h == ultima linha) && map[h][w] != 1)
//             {
//                 printf("Map borders are invalid, check the extremities up or down");
//                 exit(1);
//             }
//             else if (first or last letter of the line are not 1)
//             {
//                 printf("Map borders are invalid, check the extremities left or right");
//                 exit(1);
//             }
//             if (map[h][w] == 'E')
//                 E++;
//             else if (map[h][w] == 'P')
//                 P++;
//             else if (map[h][w] == 'C')
//                 C++;
//             else if (map[h][w] != '1' && map[h][w] != '0')
//             {
//                 ft_printf("Invalid character");
//                 exit(1);
//             }
//             w++;
//         }
//         h++;
//     }
//     if (E > 1 || P > 1 || C < 1)
//     {
//         ft_printf("Too many exits, players or too little coins.");
//         exit(1);
//     }
// }

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