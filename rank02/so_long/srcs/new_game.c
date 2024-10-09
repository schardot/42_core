/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:28:27 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/09 15:28:27 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map.h"

int	main(int argc, char **argv)
{
	t_maperr	*merror;
	t_map		*mstruct;
	t_game		*gm;
	char		**map;

	if (argc != 2)
		return (1);
	gm = malloc(sizeof(t_game));
	if (!gm)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	init_map_structs(&mstruct, &merror);
	check_map(merror, mstruct, argv[1]);
	init_game_struct(gm, mstruct);
	render_game(gm->map, gm);
	mlx_key_hook(gm->wn, key_press, (void *)gm);
	mlx_loop_hook(gm->cn, main_loop, (void *)gm);
	mlx_hook(gm->wn, 17, 0, (void *)exit, 0);
	mlx_loop(gm->cn);
}

void	init_game_struct(t_game *gm, t_map *m)
{
	int		s;

	s = SIZE;
	gm->cn = mlx_init();
	if (!gm->cn)
	{
		perror("Error");
		exit_and_free(gm);
	}
	gm->wn = mlx_new_window(gm->cn, m->len * s, m->height * s, "so_long");
	if (!gm->wn)
		exit_and_free(gm);
	files_to_images(gm);
	gm->map = ft_grddup(m->map, m->height);
	free (m->map);
	gm->pl_x = m->pl_x;
	gm->pl_y = m->pl_y;
	gm->C_sum = m->count_C;
	gm->C_collected = 0;
	gm->move_count = 0;
	gm->put_exit = 0;
}

void	files_to_images(t_game *gm)
{
	int	s;

	s = SIZE;
	gm->wimg = mlx_xpm_file_to_image(gm->cn, "sp/w.xpm", &s, &s);
	gm->pimg = mlx_xpm_file_to_image(gm->cn, "sp/p.xpm", &s, &s);
	gm->cimg = mlx_xpm_file_to_image(gm->cn, "sp/c.xpm", &s, &s);
	gm->eimg = mlx_xpm_file_to_image(gm->cn, "sp/e.xpm", &s, &s);
	gm->timg = mlx_xpm_file_to_image(gm->cn, "sp/t.xpm", &s, &s);
	if (!gm->wimg || !gm->pimg || !gm->cimg || !gm->eimg || !gm->timg)
		exit_and_free(gm);
}

void	exit_and_free(t_game *g)
{
	if (g->C_collected == g->C_sum)
		ft_printf("Nice! You completed the game in %d moves\n", g->move_count);
	mlx_destroy_window(g->cn, g->wn);
	free(g->map);
	free(g);
	exit (0);
}
