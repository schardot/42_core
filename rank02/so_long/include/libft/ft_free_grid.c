void    ft_free_grid(char **grid)
{
    int i;

    if (!grid)
        exit (1);
    i = 0;
    while (grid[i])
    {
        free (grid[i]);
        i ++;
    }
}