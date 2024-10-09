/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:18:56 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/09 15:19:06 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

char	**check_map(t_maperr *merror, t_map *gm, char *file)
{
	char	**map_copy;

	initial_map_check(merror, gm, file);
	check_map_errors(merror, gm);
	gm->map = (char **)malloc(gm->height * sizeof(char *));
	gm->map = map_to_grid(merror, gm, file);
	check_borders(merror, gm);
	get_player_xy(gm);
	map_copy = ft_grddup(gm->map, gm->height);
	if (!check_valid_path(map_copy, gm->pl_y, gm->pl_x, gm->count_C))
	{
		ft_printf("There's no valid path\n");
		exit (1);
	}
	gm->len --;
	return (gm->map);
}

void	init_map_structs(t_map **gm, t_maperr **merror)
{
	*gm = (t_map *)malloc(sizeof(t_map));
	*merror = (t_maperr *)malloc(sizeof(t_maperr));
	if (!(*gm) || !(*merror))
	{
		perror("Error allocating memory for map structures");
		exit(EXIT_FAILURE);
	}
	(*merror)->linelen = 0;
	(*merror)->chars = 0;
	(*merror)->alloc = 0;
	(*merror)->open = 0;
	(*merror)->notber = 0;
	(*merror)->border = 0;
	(*gm)->len = 0;
	(*gm)->height = 0;
	(*gm)->count_1 = 0;
	(*gm)->count_0 = 0;
	(*gm)->count_E = 0;
	(*gm)->count_P = 0;
	(*gm)->count_C = 0;
	(*gm)->map = NULL;
	(*gm)->line = NULL;
	(*gm)->pl_x = 0;
	(*gm)->pl_y = 0;
}

void	check_map_errors(t_maperr *m, t_map *mp)
{
	if (m->notber == 1)
		ft_putstr_fd("Error: check map extension\n", 2);
	else if (m->open == 1)
		perror("Error");
	else if (m->linelen == 1)
	{
		ft_putstr_fd("Error: all lines should have the same length\n", 2);
		free (mp->line);
	}
	else if (m->chars == 1)
	{
		ft_putstr_fd("Error: map contains invalid character\n", 2);
		free(mp->line);
	}
	else if (m->alloc == 1)
		perror("Error");
	else if (m->border == 1)
	{
		ft_putstr_fd("Error: borders are invalid\n", 2);
		free(mp->map);
	}
	if (m->notber || m->open || m->alloc || m->linelen || m->border || m->chars)
		exit (EXIT_FAILURE);
}
