/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:19:17 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/09 15:19:19 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map.h"

int	key_press(int key, t_game *gm)
{
	char	*next;

	next = check_next_obj(gm, key);
	if (!next)
		exit_and_free(gm);
	check_next_move(next, gm);
	render_game(gm->map, gm);
	return (0);
}

void	check_next_move(char *next, t_game *g)
{
	if (!next || !g || !g->map)
		return ;
	if (*next == 'C' || *next == '0' || *next == 'E')
	{
		if (*next == 'C')
			g->C_collected ++;
		if (g->put_exit)
			check_put_exit(g);
		else
			g->map[g->pl_y][g->pl_x] = '0';
		g->move_count ++;
		ft_printf("Number of movements: %d\n", g->move_count);
		if (*next == 'E')
		{
			if (g->C_collected == g->C_sum)
				exit_and_free(g);
			else
				g->put_exit = 1;
		}
		*next = 'P';
	}
}

void	check_put_exit(t_game *g)
{
	if (g->put_exit)
	{
		g->map[g->pl_y][g->pl_x] = 'E';
		g->put_exit = 0;
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
		exit_and_free(gm);
	return (NULL);
}
