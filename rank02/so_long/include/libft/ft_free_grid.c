#include "libft.h"

void    ft_free_grid(char **grid)
{
    int i;

    if (!grid)
        return ;
    i = 0;
    while (grid[i])
    {
        free (grid[i]);
        i ++;
    }
    free (grid);
    grid = NULL;
}