#include "../include/minilibx-linux/mlx.h"
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
    gamedata *data;
    char **grid;

    //antes de inicializar struct, arg check
    grid = start_map(argv[1]);
    data = init_data(data);
}

int ft_update(gamedata *g)
{
    mlx_put_image_to_window(g->connection, g->window, g->img, 100, 100);
    return (0);
}
gamedata *init_data(gamedata *data)
{
    data = (gamedata *)malloc(1 * sizeof(gamedata));
    data->connection = mlx_init();
    if (!data->connection)
    {
        printf("In init_data.c: Can't establish connection");
        exit(1);
    }
    data->window = mlx_new_window(data->connection, 800, 500, "so_long, farewell, auf wiedersehen goodbye!"); // tem q vincular esse tamanho com o tamanho do mapa
    if (!data->window)
    {
        printf("In init_data.c: Can't open window");
        exit(1);
    }
    put_file_to_image(data);
    mlx_loop_hook(data->connection, ft_update, (void *)data);
    mlx_loop(data->connection);
    return (data);
}
void put_file_to_image(gamedata *data)
{
    //tem q initializar data?
    int size = 32;
    data->coinimage = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/collectible.xpm", &size, &size);
    data->exitimage = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/exit.xpm", &size, &size);
    data->wallimage = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/wall.xpm", &size, &size);
    data->playerimage = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/exit.xpm", &size, &size);
    data->tileimage = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/tile.xpm", &size, &size);
}
char **start_map(char *filename)
{
    int fd;
    char **grid;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("In start_map.c: Error opening the file.");
        exit (1);
    }
    return (ber_to_grid(fd));
}