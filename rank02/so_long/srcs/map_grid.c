/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:17:11 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/10 16:55:20 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

void	map_to_grid(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
{
	int		m;
	int		fd;

	gm->map = (char **)malloc((mstr->height + 1) * sizeof(char *));
	if (!gm->map)
		return;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		merr->open = 1;
	mstr->line = file;
	check_map_errors(merr, mstr, gm);
	m = 0;
	while (mstr->line)
	{
		mstr->line = get_next_line(fd);
		if (mstr->line)
		{
			gm->map[m] = ft_strdup(mstr->line);
			m++;
			free(mstr->line);
		}
	}
	close(fd);
	gm->map[m] = NULL;
}

void	check_borders(t_maperr *merr, t_map *mstr, t_game *gm)
{
	char	*first;
	char	*last;
	int		i;

	i = 0;
	first = ft_strdup(gm->map[0]);
	last = ft_strdup(gm->map[mstr->height - 1]);
	while (i < mstr->len - 1)
	{
		if (!ft_strchr("1\n", first[i]) || !ft_strchr("1\n", last[i]))
			merr->border = 1;
		i++;
	}
	i = 1;
	while (i < mstr->height - 1)
	{
		if (!ft_strchr("1\n", gm->map[i][0]) || \
		!ft_strchr("1\n", gm->map[i][mstr->len - 2]))
			merr->border = 1;
		i ++;
	}
	free(first);
	free(last);
	check_map_errors(merr, mstr, gm);
}

void	get_player_xy(t_game *gm)
{
	int	h;
	int	w;

	h = 0;
	if (!gm)
		exit(1);
	while (gm->map[h])
	{
		w = 0;
		while (gm->map[h][w])
		{
			if (gm->map[h][w] == 'P')
			{
				gm->pl_y = h;
				gm->pl_x = w;
				return ;
			}
			w++;
		}
		h++;
	}
}

int	check_path(char **map, int h, int w, t_map *mstr)
{
	if (h < 0 || w < 0 || !map[h] || ft_strchr("V1\0", map[h][w]))
		return (0);
	if (map[h][w] == 'C')
		mstr->pc_coin++;
	if (map[h][w] == 'E')
		mstr->pc_exit = 1;
	map[h][w] = 'V';
	if (check_neighbour(map, h, w))
	{
		return (check_path(map, h - 1, w, mstr) ||
				check_path(map, h, w + 1, mstr) ||
				check_path(map, h + 1, w, mstr) ||
				check_path(map, h, w - 1, mstr));
	}
	if (mstr->pc_exit && mstr->pc_coin == mstr->count_C)
		mstr->pc_valid = 1;
	return (mstr->pc_valid);
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
