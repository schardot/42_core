#include "libft.h"

char **ft_grdrealloc(char **ptr, size_t size)
{
    char **newgrid;
    size_t h;

    newgrid = (char **)malloc(size * sizeof(char *));
    if (!newgrid)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr)
    {
        h = 0;
        while (h < size && ptr[h])
        {
            newgrid[h] = ft_strdup(ptr[h]);
            h ++;
        }
        free(ptr);
    }
    return (newgrid);
}