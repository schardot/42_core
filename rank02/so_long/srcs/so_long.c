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
    check_extension(filename);
    check_file(filename);
}
void    check_extension(filename)
{
    char    *extension;

    extension = ft_substr(filename, ft_strlen(filename) - 4, 4);
    if (ft_strncmp(extension, ".ber", 5) != 0)
    {
        ft_printf("Error, the map is not .ber");
        free (extension);
        exit (1);
    }
    free (extension);
}

int check_file(char *filename)
{
    int fd;
    char *line;
    int linelen;
    int auxlen;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("In start_map, line 78, couldnt open file");
        exit (1);
    }
    linelen = 0;
    line = "a";
    while (line)
    {
        line = get_next_line(fd);
        check_chars(line);
        auxlen = ft_strlen(line);
        if (linelen > 0 && auxlen != linelen)
        {
            ft_printf("All the lines must have the same length");
            free (line);
            exit (1);
        }
        linelen = auxlen;
        free (line);
    }
    close(fd);
    return (linelen);
}
    // -------------------

    // -------------------- III) funcao que vai ler uma linha e checar as unicas letras permitidas
void    check_chars(char *line, int linelen)
{
    int i;
    map_aux *m_list;

    init_m_list(m_list);
    i = 0;
    if (line[0] != '1' || line[linelen - 1] != 1)
    {
        ft_printf("Borders are not all 1").
        free (line);
        exit (1);
    }
    while(line[i])
    {
        if (!ft_strchr("10PCE", line[i]))
        {
            ft_printf("Found and invalid character");
            free (line);
            exit (1);
        }
        i ++;
    }
}
    // ---------------------

    // --------------------- IV) criar o mapa
char    **create_map()
{
    char **map;
    int m;
    int fd;

    m = 0;
    map = (char **)malloc(height * sizeof(char *));
    if (!map)
    {
        ft_printf("Couldn't allocate map");
        exit (1);
    }
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("In creating the map, second read. Couldnt open file");
        exit(1);
    }
    while (map[m])
    {
        map[m] = get_next_line(fd);
        m ++;
    }
    return (map);
}

    // --------------------

    // -------------------- V) ver se tem path valido e ver se a primeira e ultima linha sao '1'
    nao quero fazer isso agora
    // -------------------

void    init_m_list(map_aux *m_list)
{
    char *chars = "01EPC"
    int i;
    m_list = (map_aux *)malloc(5 * sizeof(map_aux));
    if (!m_list)
    {
        ft_printf("Couldnt create m_list");
        exit (1); ///nao da certo pq tem outras coisas pra free
    }
    i = 0;
    while (i < 5)
    {
        m_list->letter = chars[i];
        count
    }
}