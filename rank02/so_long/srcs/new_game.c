/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:28:27 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/12 14:48:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map.h"

int	main(int argc, char **argv)
{
	t_maperr	*merr;
	t_map		*mstr;
	t_game		*gm;

	if (argc != 2)
		return (1);
	allocate_structs(&gm, &mstr, &merr);
	check_map(merr, mstr, gm, argv[1]);
	init_game_struct(gm, mstr, merr);
	render_game(gm->map, gm);
	free(mstr);
	free(merr);
	mlx_key_hook(gm->wn, key_press, (void *)gm);
	mlx_loop_hook(gm->cn, main_loop, (void *)gm);
	mlx_hook(gm->wn, 17, 0, (void *)exit, 0);
	mlx_loop(gm->cn);
}

void	allocate_structs(t_game **gm, t_map **mstr, t_maperr **merr)
{
	*gm = malloc(sizeof(t_game));
	if (!*gm)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	*mstr = malloc(sizeof(t_map));
	if (!*mstr)
	{
		perror("Error");
		free(gm);
		exit(EXIT_FAILURE);
	}
	*merr = malloc(sizeof(t_maperr));
	if (!*merr)
	{
		perror("Error");
		free (*gm);
		free (*mstr);
		exit (EXIT_FAILURE);
	}
	init_map_structs(*mstr, *merr);
	(*gm)->map = NULL;
	(*gm)->wn = NULL;
}

void	init_game_struct(t_game *gm, t_map *mstr, t_maperr *merr)
{
	int		s;

	s = SIZE;
	gm->cn = mlx_init();
	if (!gm->cn)
	{
		perror("Error");
		exit_and_free_all(gm, mstr, merr);
	}
	gm->wn = mlx_new_window(gm->cn, mstr->len * s, mstr->height * s, "so_long");
	if (!gm->wn)
		exit_and_free_all(gm, mstr, merr);
	files_to_images(gm, mstr, merr);
	gm->C_sum = mstr->count_C;
	gm->C_collected = 0;
	gm->move_count = 0;
	gm->put_exit = 0;
	gm->height = mstr->height;
	gm->len = mstr->len;
}

void	files_to_images(t_game *gm, t_map *mstr, t_maperr *merr)
{
	int	s;

	s = SIZE;
	gm->wimg = mlx_xpm_file_to_image(gm->cn, "sp/w.xpm", &s, &s);
	gm->pimg = mlx_xpm_file_to_image(gm->cn, "sp/p.xpm", &s, &s);
	gm->cimg = mlx_xpm_file_to_image(gm->cn, "sp/c.xpm", &s, &s);
	gm->eimg = mlx_xpm_file_to_image(gm->cn, "sp/e.xpm", &s, &s);
	gm->timg = mlx_xpm_file_to_image(gm->cn, "sp/t.xpm", &s, &s);
	if (!gm->wimg || !gm->pimg || !gm->cimg || !gm->eimg || !gm->timg)
		exit_and_free_all(gm, mstr, merr);
}