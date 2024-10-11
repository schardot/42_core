#include "libft.h"

char    **ft_grddup(char **grid, int height)
{
    int     i;
    char    **newgrid;

    if (height <= 0 || !grid)
        return (NULL);
    newgrid = (char **)malloc((height + 1) * sizeof(char *));
    if (!newgrid)
        return (NULL);
    i = 0;
    while (i < height)
    {
        newgrid[i] = ft_strdup(grid[i]);
        if (!newgrid[i])
        {
            ft_free_grid(newgrid);
            return (NULL);
        }
        i ++;
    }
    newgrid[i] = NULL;
    return (newgrid);
}
