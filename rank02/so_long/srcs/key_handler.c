/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:38 by nleite-s          #+#    #+#             */
/*   Updated: 2024/10/14 11:26:39 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/so_long.h"
#include "../include/map.h"

int	key_press(int key, t_game *gm)
{
	char	*next;

	next = check_next_obj(gm, key);
	if (!next)
		exit_and_free_gm(gm);
	check_next_move(next, gm);
	render_game(gm->map, gm);
	return (0);
}

void	check_next_move(char *next, t_game *gm)
{
	if (!next || !gm || !gm->map)
		return ;
	if (*next == 'C' || *next == '0' || *next == 'E')
	{
		if (*next == 'C')
			gm->C_collected ++;
		if (gm->put_exit)
			check_put_exit(gm);
		else
			gm->map[gm->pl_y][gm->pl_x] = '0';
		gm->move_count ++;
		ft_printf("Number of movements: %d\n", gm->move_count);
		if (*next == 'E')
		{
			if (gm->C_collected == gm->C_sum)
			{
				ft_printf("Nice! Game completed in %d moves\n", gm->move_count);
				exit_and_free_gm(gm);
			}
			else
				gm->put_exit = 1;
		}
		*next = 'P';
	}
}

void	check_put_exit(t_game *gm)
{
	if (gm->put_exit)
	{
		gm->map[gm->pl_y][gm->pl_x] = 'E';
		gm->put_exit = 0;
	}
}

char	*check_next_obj(t_game *gm, int key)
{
	if (key == RIGHT || key == D)
		return (&gm->map[gm->pl_y][gm->pl_x + 1]);
	else if (key == LEFT || key == A)
		return (&gm->map[gm->pl_y][gm->pl_x - 1]);
	else if (key == UP || key == W)
		return (&gm->map[gm->pl_y - 1][gm->pl_x]);
	else if (key == DOWN || key == S)
		return (&gm->map[gm->pl_y + 1][gm->pl_x]);
	else if (key == ESC)
		exit_and_free_gm(gm);
	return ("a");
}
