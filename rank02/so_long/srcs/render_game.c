/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:26:30 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/11 14:01:23 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map.h"

int	main_loop(t_game *gm)
{
	if (!gm || !gm->map)
		exit(1);
	render_game(gm->map, gm);
	return (0);
}

void	render_game(char **map, t_game *gm)
{
	int	h;
	int	w;

	h = 0;
	while (h < gm->height)
	{
		w = 0;
		while (w < gm->len)
		{
			render_pos(map, gm, w, h);
			w ++;
		}
		h ++;
	}
}

void	render_pos(char **map, t_game *gm, int w, int h)
{
	int	w_size;
	int	h_size;

	if (h >= gm->height || w >= gm->len)
		return ;
	w_size = w * SIZE;
	h_size = h * (SIZE);
	if (map[h][w] == '1')
		mlx_put_image_to_window(gm->cn, gm->wn, gm->wimg, w_size, h_size);
	else if (map[h][w] == '0')
		mlx_put_image_to_window(gm->cn, gm->wn, gm->timg, w_size, h_size);
	else if (map[h][w] == 'C')
		mlx_put_image_to_window(gm->cn, gm->wn, gm->cimg, w_size, h_size);
	else if (map[h][w] == 'E')
		mlx_put_image_to_window(gm->cn, gm->wn, gm->eimg, w_size, h_size);
	else if (map[h][w] == 'P')
	{
		mlx_put_image_to_window(gm->cn, gm->wn, gm->pimg, w_size, h_size);
		gm->pl_x = w;
		gm->pl_y = h;
	}
}
