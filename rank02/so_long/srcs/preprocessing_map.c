#include "../include/map.h"

char	**check_map(t_maperr *merror, t_map *mstruct, char *file)
{
	initial_map_check(merror, mstruct, file);
	check_map_errors(merror, mstruct);
	mstruct->map = map_to_grid(merror, mstruct, file);
	get_player_xy(mstruct);
	check_valid_path(mstruct->map, mstruct->pl_y, mstruct->pl_x, mstruct->count_C);
	return (mstruct->map);
}

void	initial_map_check(t_maperr *merror, t_map *mstruct, char *file)
{
	int		fd;

	if(!ft_strnstr(file, ".ber\0", ft_strlen(file)))
		merror->notber = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		merror->cantopen = 1;
	check_map_errors(merror, mstruct);
	mstruct->line = "a";
	while (fd > 0 && mstruct->line)
	{
		mstruct->line = get_next_line(fd);
		check_line(merror, mstruct, mstruct->line);
	}
	close(fd);
}

void	check_line(t_maperr *merror, t_map *mstruct, char *line)
{
	if (ft_strlen(line) != mstruct->len)
	{
		if (mstruct->len == 0)
			mstruct->len = ft_strlen(line);
		else
			merror->linelen = 1;
	}
	check_map_errors(merror, mstruct);
	while (*line)
	{
		check_char(*line, mstruct, merror);
		check_map_errors(merror, mstruct);
		if (*line == 'P')
			mstruct->pl_y = mstruct->height;
		line ++;
	}
	check_count_char(mstruct, merror);
	mstruct->height++;
}

void	check_char(char line, t_map *mstruct, t_maperr *merror)
{
	if (line == '1')
		mstruct->count_1 ++;
	else if (line == '0')
		mstruct->count_0 ++;
	else if (line == 'E')
		mstruct->count_E++;
	else if (line == 'P')
		mstruct->count_P++;
	else if (line == 'C')
		mstruct->count_C++;
	else if (line != '\n')
		merror->count_inv = 1;
}

void	check_count_char(t_map *mstruct, t_maperr *merror)
{
	if (mstruct->count_E != 1)
		ft_putstr_fd("There is more than one exit, please check map.", 2);
	else if (mstruct->count_P != 1)
		ft_putstr_fd("There is more than one player, please check map.", 2);
	else if (mstruct->count_C < 1)
		ft_putstr_fd("There needs to be at least one collectible, please check map.", 2);
	else
		return ;
	exit (1);
}

void	init_map_structs(t_map *mstruct, t_maperr *merror)
{
	merror->linelen = 0;
	merror->count_inv = 0;
	merror->cantallocate = 0;
	merror-> cantopen = 0;
	merror->notber = 0;
	merror->borderinv = 0;
	mstruct->len = 0;
	mstruct->height = 0;
	mstruct->count_1 = 0;
	mstruct->count_0 = 0;
	mstruct->count_E = 0;
	mstruct->count_P = 0;
	mstruct->count_C = 0;
	mstruct->map = NULL;
	mstruct->line = NULL;
	mstruct->pl_x = 0;
	mstruct->pl_y = 0;
}

void    check_map_errors(t_maperr *m, t_map *mp)
{
	if (m->notber == 1)
		ft_putstr_fd("Error: check map extension\n", 2);
	else if (m->cantopen == 1)
		perror("Error: Could not open the file.\n");
	else if (m->linelen == 1)
	{
		ft_putstr_fd("Error: all lines should have the same length\n", 2);
		free (mp->line);
	}
	else if (m->count_inv == 1)
	{
		ft_putstr_fd("Error: map contains invalid character\n", 2);
		free(mp->line);
	}
	else if (m->cantallocate == 1)
		perror("Error: Memory allocation failed.\n");
	else if (m->borderinv == 1)
	{
		ft_putstr_fd("Error: borders are invalid\n", 2);
		free(mp->map);
	}
	if (m->notber || m->cantopen || m->cantallocate || m->linelen || m->borderinv || m->count_inv)
		exit(EXIT_FAILURE);
}

char	**map_to_grid(t_maperr *merror, t_map *mstruct, char *file)
{
	char	**map;
	int		m;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		merror->cantopen = 1;
	check_map_errors(merror, mstruct);
	mstruct->line = file;
	map = (char **)malloc(sizeof(char *) * (mstruct->height));
	if (!map)
		merror->cantallocate = 1;
	check_map_errors(merror, mstruct);
	m = 0;
	while (mstruct->line)
	{
		mstruct->line = get_next_line(fd);
		map[m] = ft_strdup(mstruct->line);
		m++;
		free(mstruct->line);
	}
	close(fd);
	check_borders(merror, mstruct);
	return (map);
}

void	check_borders(t_maperr *merror, t_map *mstruct)
{
	char	*first;
	char	*last;
	int		i;
	int		len;

	i = 0;
	len = mstruct->len;
	first = mstruct->map[0];
	last = mstruct->map[mstruct->height - 1];
	while (i < len)
	{
		if (first[i] != '1' || last[i] != '1')
			merror->borderinv = 1;
		i ++;
	}
	i = 1;
	while (i < mstruct->height - 1)
	{
		if (mstruct->map[i][0] != '1' || mstruct->map[i][len - 1] != '1')
			merror->borderinv = 1;
		i ++;
	}
	check_map_errors(merror, mstruct);
}
void	get_player_xy(t_map *m)
{
	int	h;
	int	w;

	h = 0;
	while (m->map[h])
	{
		w = 0;
		while (m->map[h][w])
		{
			if (m->map[h][w] == 'P')
			{
				m->pl_y = h;
				m->pl_x = w;
			}
			w ++;
		}
		h ++;
	}
}
int	check_valid_path(char **map, int h, int w, int count_C)
{
	static int	coin = 0;
	int			found_exit;

	if (check_neighbour(map, h, w))
	{
		if (map[h][w] == 'C')
			coin ++;
		map[h][w] = 'V';
		found_exit = check_valid_path(map, h - 1, w, count_C) || check_valid_path(map, h, w + 1, count_C) ||
				check_valid_path(map, h + 1, w, count_C) || check_valid_path(map, h, w - 1, count_C);
		if (map[h][w] == 'E' && coin == count_C)
			return (1);
		return (found_exit);
	}
	return (0);
}

int	check_neighbour(char **map, int h, int w)
{
	if (h > 0 && ft_strchr("0C", map[h - 1][w]))
		return (1);
	if (map[h + 1] && ft_strchr("0C", map[h + 1][w]))
		return (1);
	if (map[h][w + 1] && ft_strchr("0C", map[h][w + 1]))
		return (1);
	if (map[h][w - 1] && ft_strchr("0C", map[h][w - 1]))
		return (1);
	return (0);
}