/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:18:56 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/12 14:47:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

void	check_map(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
{
	char	**map_copy;

	initial_file_check(merr, mstr, gm, file);
	check_map_errors(merr, mstr, gm);
	map_to_grid(merr, mstr, gm, file);
	check_borders(merr, mstr, gm);
	get_player_xy(gm);
	map_copy = ft_grddup(gm->map, mstr->height);
	if (!check_path(map_copy, gm->pl_y, gm->pl_x, mstr))
	{
		ft_printf("There's no valid path\n");
		ft_free_grid(map_copy);
		exit_and_free_all(gm, mstr, merr);
		exit (1);
	}
	ft_free_grid(map_copy);
	mstr->len--;
}

void	init_map_structs(t_map *mstr, t_maperr *merr)
{
	merr->linelen = 0;
	merr->chars = 0;
	merr->alloc = 0;
	merr->open = 0;
	merr->notber = 0;
	merr->border = 0;
	mstr->len = 0;
	mstr->height = 0;
	mstr->count_1 = 0;
	mstr->count_0 = 0;
	mstr->count_E = 0;
	mstr->count_P = 0;
	mstr->count_C = 0;
	mstr->line = NULL;
	mstr->pc_coin = 0;
	mstr->pc_exit = 0;
	mstr->pc_valid = 0;
}

void	check_map_errors(t_maperr *merr, t_map *mstr, t_game *gm)
{
	if (merr->open == 1)
		perror("Error");
	else if (merr->linelen == 1)
	{
		ft_putstr_fd("Error: all lines should have the same length\n", 2);
		free (mstr->line);
	}
	else if (merr->chars == 1)
	{
		ft_putstr_fd("Error: map contains invalid character\n", 2);
		free(mstr->line);
	}
	else if (merr->alloc == 1)
		perror("Error");
	else if (merr->border == 1)
		ft_putstr_fd("Error: borders are invalid\n", 2);
	if (merr->notber || merr->open || merr->alloc || \
	merr->linelen || merr->border || merr->chars)
		exit_and_free_all(gm, mstr, merr);
}

int check_path(char **map, int h, int w, t_map *mstr)
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
