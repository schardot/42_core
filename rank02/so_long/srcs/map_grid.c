/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:17:11 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/12 14:47:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

void	map_to_grid(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
{
	int		fd;

	gm->map = malloc((mstr->height + 1) * sizeof(char *));
	if (!gm->map)
		merr->alloc = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		merr->open = 1;
	mstr->line = file;
	write_map_from_file(gm, mstr, fd);
	check_map_errors(merr, mstr, gm);
	close(fd);
}

void	write_map_from_file(t_game *gm, t_map *mstr, int fd)
{
	int	m;

	m = 0;
	while (mstr->line)
	{
		mstr->line = get_next_line(fd);
		if (mstr->line)
		{
			gm->map[m] = ft_strdup(mstr->line);
			if (!gm->map[m])
			{
				ft_free_grid(gm->map);
				close(fd);
				return;
			}
			m++;
			free(mstr->line);
		}
	}
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
