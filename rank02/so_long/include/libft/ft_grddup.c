#include "libft.h"

char    **ft_grddup(char **grid, int height)
{
    int     i;
    char    **newgrid;

    newgrid = (char **)malloc((height + 1) * sizeof(char *));
    if (!newgrid)
        return (NULL);
    i = 0;
    while (i < height)
    {
        newgrid[i] = ft_strdup(grid[i]);
        i ++;
    }
    newgrid[i] = NULL;
    return (newgrid);
}
