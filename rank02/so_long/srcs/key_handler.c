/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:19:17 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/11 14:52:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map.h"

int	key_press(int key, t_game *gm)
{
	char	*next;

	next = check_next_obj(gm, key);
	if (!next)
	{
		ft_free_grid(gm->map);
		mlx_destroy_window(gm->cn, gm->wn);
		exit(1);
	}
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
				ft_printf("Nice! You completed the game in %d moves\n", gm->move_count);
				ft_free_grid(gm->map);
				mlx_destroy_window(gm->cn, gm->wn);
				exit (0);
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
	{
		ft_free_grid(gm->map);
		mlx_destroy_window(gm->cn, gm->wn);
		exit(1);
	}
	return (NULL);
}
