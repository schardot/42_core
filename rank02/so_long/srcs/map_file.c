#include "../include/map.h"

void	initial_map_check(t_maperr *merror, t_map *gm, char *file)
{
	int	fd;

	if (!ft_strnstr(file, ".ber\0", ft_strlen(file)))
		merror->notber = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		merror->open = 1;
	check_map_errors(merror, gm);
	gm->line = "a";
	while (fd > 0 && gm->line)
	{
		gm->line = get_next_line(fd);
		if (gm->line)
			check_line(merror, gm, gm->line);
	}
	check_count_char(gm, merror);
	close(fd);
}

void	check_line(t_maperr *merror, t_map *gm, char *line)
{
	if (ft_strlen(line) != gm->len)
	{
		if (line[ft_strlen(line) - 1] == '1' && line[ft_strlen(line)] == '\0')
		{
			if ((ft_strlen(line)) != gm->len - 1)
				merror->linelen = 1;
		}
		else if (gm->len == 0)
			gm->len = ft_strlen(line);
		else
			merror->linelen = 1;
	}
	check_map_errors(merror, gm);
	while (*line)
	{
		check_char(*line, gm, merror);
		check_map_errors(merror, gm);
		if (*line == 'P')
			gm->pl_y = gm->height;
		line++;
	}
	gm->height++;
}

void	check_char(char line, t_map *gm, t_maperr *merror)
{
	if (line == '1')
		gm->count_1++;
	else if (line == '0')
		gm->count_0++;
	else if (line == 'E')
		gm->count_E++;
	else if (line == 'P')
		gm->count_P++;
	else if (line == 'C')
		gm->count_C++;
	else if (line != '\n')
		merror->chars = 1;
}

void	check_count_char(t_map *gm, t_maperr *merror)
{
	if (gm->count_E > 1)
		ft_putstr_fd("There is more than one exit, please check map.\n", 2);
	else if (gm->count_E < 1)
		ft_putstr_fd("The game needs at least one exit\n", 2);
	else if (gm->count_P > 1)
		ft_putstr_fd("There is more than one player, please check map.\n", 2);
	else if (gm->count_P < 1)
		ft_putstr_fd("The game needs at least one player\n", 2);
	else if (gm->count_C < 1)
		ft_putstr_fd("There needs to be at least one collectible\n", 2);
	else
		return;
	exit(1);
}
