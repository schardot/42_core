#include "../include/minilibx_opengl_20191021/mlx.h"
#include "../include/so_long.h"
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int ft_update(gamedata *g);

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
    img = mlx_xpm_file_to_image(connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/gold.xpm", &size, &size);
    if (img == NULL)
    {
        printf("Failed to load image\n");
        return (1);
    }

    gamedata *g;
    g = (gamedata *)malloc(1 * sizeof(gamedata));
    g->connection = connection;
    g->window = window;
    g->img = img;

   mlx_loop_hook(connection, ft_update, (void *)g);
    if (!window)
        exit(1);
    mlx_loop(connection);
}

int ft_update(gamedata *g)
{
    mlx_put_image_to_window(g->connection, g->window, g->img, 200, 200);
    return (0);
}

int put_file_to_image(gamedata *data)
{
    //tem q initializar data?
    int size = 32;
    data->coinimage = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/gold.xpm", &size, &size);
}