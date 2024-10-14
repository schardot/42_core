/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:22 by nleite-s          #+#    #+#             */
/*   Updated: 2024/10/14 11:26:23 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/so_long.h"
#include "../include/map.h"

void	exit_and_free_all(t_game *gm, t_map *mstr, t_maperr *merr)
{
	if (merr)
		free(merr);
	if (mstr)
		free(mstr);
	exit_and_free_gm(gm);
	exit(0);
}

int	exit_and_free_gm(t_game *gm)
{
	if (gm->wn)
	{
		mlx_destroy_image(gm->cn, gm->wimg);
		mlx_destroy_image(gm->cn, gm->eimg);
		mlx_destroy_image(gm->cn, gm->pimg);
		mlx_destroy_image(gm->cn, gm->timg);
		mlx_destroy_image(gm->cn, gm->cimg);
		mlx_clear_window(gm->cn, gm->wn);
		mlx_destroy_window(gm->cn, gm->wn);
		mlx_destroy_display(gm->cn);
		free(gm->cn);
	}
	if (gm->map)
		ft_free_grid(gm->map);
	if (gm)
		free (gm);
	exit (0);
	return (0);
}
