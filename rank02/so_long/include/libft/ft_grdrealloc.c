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
    // Initialize all pointers to NULL to handle partial failures
    for (h = 0; h < size; h++)
        newgrid[h] = NULL;

    if (ptr)
    {
        h = 0;
        while (h < size && ptr[h])
        {
            newgrid[h] = ft_strdup(ptr[h]);
            if (!newgrid[h]) // If `ft_strdup` fails, free everything and return NULL
            {
                while (h > 0)  // Free any successfully copied strings
                {
                    h--;
                    free(newgrid[h]);
                }
                free(newgrid);
                free(ptr);
                return (NULL);
            }
            h++;
        }
        free(ptr);  // Free the old array after copying
    }
    return (newgrid);
}

static char **populate_newgrid(char **newgrid, char *ptr)
{
	
}