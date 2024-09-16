#include "minilibx/mlx.h"
#include <stdlib.h>

int main()
{
    void    *connection;
    void    *window;

    connection = mlx_init();
    if (!connection)
        exit(1);
    window = mlx_new_window(connection, 500, 500, window);
    if (!window)
        exit(1);
    mlx_loop(connection);
}