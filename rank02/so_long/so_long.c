#include "include/minilibx_opengl_20191021/mlx.h"
#include "include/so_long.h"
#include <stdlib.h>
#include <stdio.h>

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
    window = mlx_new_window(connection, 800, 500, "window");

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

// int arguments_check(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         ft_printf("Argc must be 2");
//         return (1);
//     }
//     if (argc == 2)
//         check_map(*argv);

// }

// int check_map(char *file)
// {
//     int fd;

//     fd = open(file, O_RDONLY);
//     if (fd == -1)
//         perror("Error opening file");
//     //use get_next_line to check map
// }