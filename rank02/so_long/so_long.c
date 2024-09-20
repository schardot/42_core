#include "include/minilibx_opengl_20191021/mlx.h"
#include "include/so_long.h"
#include "include/libft/libft.h"
#include "include/libft/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct s_list
{
    void *connection;
    void *window;
    void *img;
} estrutura;

int ft_update(estrutura *g);

int main(int argc, char **argv)
{
    void    *connection;
    void    *window;
    void    *img;
    //arguments_check(argc, argv);
    connection = mlx_init();
    if (!connection)
        exit(1);
    window = mlx_new_window(connection, 800, 500, "window"); //tem q vincular esse tamanho com o tamanho do mapa

    int size;
    size = 200;
    img = mlx_xpm_file_to_image(connection, "/Users/nataliaschardosim/42_core/rank02/so_long/Tiny Adventure Pack/Char_idle_down.xpm", &size, &size);
    if (img == NULL)
    {
        printf("Failed to load image\n");
        return (1);
    }

    estrutura *g;
    g = (estrutura *)malloc(1 * sizeof(estrutura));
    g->connection = connection;
    g->window = window;
    g->img = img;

   mlx_loop_hook(connection, ft_update, (void *)g);
    if (!window)
        exit(1);
    mlx_loop(connection);
}

int ft_update(estrutura *g)
{
    mlx_put_image_to_window(g->connection, g->window, g->img, 200, 200);
}

char    **ber_to_grid(int fd) //it will create and populate a grid with information of the map. it will then check is all the characters a valid. it doesnt check if theres a valid path.
{
    int height = 0;
    int width;
    char *line;
    char **map;
    int m = 0;

    line = get_next_line(fd); //got first line;
    map = (char **)malloc(sizeof(char *) * (height + 2)); //if i dont initialize line here, it'll never go inside the loop
    map[m] = ft_strdup(line);
    m ++;
    height ++;
    while (line)
    {
        line = get_next_line(fd);
        map = ft_realloc(map, height + 2);
        map[m] = ft_strdup(line);
        m++;
        height++;
    }
    check_map(map);
    return (map);
}

void check_map(char **map)
{
    1. check if all the borders are 1 (walls)

    int w;
    int h;

    //for now i declared variables so i can count E, P and C but im sure theres a more efficient way to do it.
    int E;
    int P;
    int C;
    E = 0;
    P = 0;
    C = 0;

    w = 0;
    h = 0;
    while(map[h])
    {
        while (map[h][w])
        {
            if ((h == 0 || h == ultima linha) && map[h][w] != 1)
            {
                ft_printf("Map borders are invalid, check the extremities up or down");
                exit (1);
            }
            else if (first or last letter of the line are not 1)
            {
                ft_printf("Map borders are invalid, check the extremities left or right");
                exit (1);
            }
            if (map[h][w] == 'E')
                E ++;
            else if (map[h][w] == 'P')
                P ++;
            else if (map[h][w] == 'C')
                C ++;
            else if (map[h][w] != '1' && map[h][w] != '0')
            {
                ft_printf("Invalid character");
                exit(1);
            }
            w++;
        }
        h ++;
    }
    if (E > 1 || P > 1 || C < 1)
    {
        ft_printf("Too many exits, players or to little coins.");
        exit(1);
    }
}