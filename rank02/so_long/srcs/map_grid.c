/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:17:11 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/09 15:17:14 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

char	**map_to_grid(t_maperr *merror, t_map *gm, char *file)
{
	char	**map;
	int		m;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		merror->open = 1;
	gm->line = file;
	map = (char **)malloc(sizeof(char *) * (gm->height));
	if (!map)
		merror->alloc = 1;
	check_map_errors(merror, gm);
	m = 0;
	while (gm->line)
	{
		gm->line = get_next_line(fd);
		if (gm->line)
		{
			map[m] = ft_strdup(gm->line);
			m++;
			free(gm->line);
		}
	}
	close(fd);
	return (map);
}

void	check_borders(t_maperr *merror, t_map *gm)
{
	char	*first;
	char	*last;
	int		i;

	i = 0;
	first = ft_strdup(gm->map[0]);
	last = ft_strdup(gm->map[gm->height - 1]);
	while (i < gm->len - 1)
	{
		if (!ft_strchr("1\n", first[i]) || !ft_strchr("1\n", last[i]))
			merror->border = 1;
		i++;
	}
	i = 1;
	while (i < gm->height - 1)
	{
		if (!ft_strchr("1\n", gm->map[i][0]) || \
		!ft_strchr("1\n", gm->map[i][gm->len - 2]))
			merror->border = 1;
		i ++;
	}
	free(first);
	free(last);
	check_map_errors(merror, gm);
}

void	get_player_xy(t_map *m)
{
	int	h;
	int	w;

	h = 0;
	if (!m)
		exit(1);
	while (m->map[h])
	{
		w = 0;
		while (m->map[h][w])
		{
			if (m->map[h][w] == 'P')
			{
				m->pl_y = h;
				m->pl_x = w;
				return ;
			}
			w++;
		}
		h++;
	}
}

int	check_path(char **map, int h, int w, int C_sum)
{
	static int	coin = 0;
	static int	found_exit = 0;
	static int	valid = 0;

	if (h < 0 || w < 0 || !map[h] || ft_strchr("V1\0", map[h][w]))
		return (0);
	if (map[h][w] == 'C')
		coin++;
	if (map[h][w] == 'E')
		found_exit = 1;
	map[h][w] = 'V';
	if (check_neighbour(map, h, w))
	{
		return (check_path(map, h - 1, w, C_sum) || \
			check_path(map, h, w + 1, C_sum) || \
			check_path(map, h + 1, w, C_sum) || \
			check_path(map, h, w - 1, C_sum));
	}
	if (found_exit && coin == C_sum)
		valid = 1;
	return (valid);
}

int	check_neighbour(char **map, int h, int w)
{
	if (h > 0 && ft_strchr("E0C", map[h - 1][w]))
		return (1);
	if (map[h + 1] && ft_strchr("E0C", map[h + 1][w]))
		return (1);
	if (map[h][w + 1] && ft_strchr("E0C", map[h][w + 1]))
		return (1);
	if (map[h][w - 1] && ft_strchr("E0C", map[h][w - 1]))
		return (1);
	return (0);
}
