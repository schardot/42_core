#include "../include/so_long.h"
#include "../include/map.h"

int	main(int argc, char **argv)
{
	t_maperr	*merror;
	t_map		*mstruct;
	t_game		*gm;
	t_gerr		*gerr;
	char		**map;

	gm = malloc(sizeof(t_game));
	gerr = malloc(sizeof(t_gerr));
	if (!gm || !gerr)
	{
		perror("Error allocating memory for map structures");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
		return (1);
	init_map_structs(&mstruct, &merror);
	check_map(merror, mstruct, argv[1]);
	// gm->map = mstruct->map;
	init_game_struct(&gm, &gerr, mstruct);
	render_game(gm->map, gm);
	mlx_key_hook(gm->wn, key_press, (void *)gm);
	mlx_loop_hook(gm->cn, main_loop, (void *)gm);
	mlx_hook(gm->wn, 17, 0, (void *)exit, 0);
	mlx_loop(gm->cn);
}

int	main_loop(t_game *gm)
{
	if (!gm || !gm->map)
		exit (1);
	render_game(gm->map, gm);
	return (0);
}

void	render_pos(char **map, t_game *gm, int w, int h)
{
	int	w_size;
	int	h_size;

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

void	render_game(char **map, t_game *gm)
{
	int	h;
	int	w;

	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w] && map[h][w] != '\n')
		{
			render_pos(map, gm, w, h);
			w++;
		}
		h++;
	}
}

void	init_game_struct(t_game **gamestruct, t_gerr **er, t_map *m)
{
	t_game	*gm;
	int		s;

	s = SIZE;
	gm = *gamestruct;
	gm->cn = mlx_init();
	if (!gm->cn)
	{
		(*er)->cnct = 1;
		perror("Error");
		return ;
	}
	gm->wn = mlx_new_window(gm->cn, m->len * s, m->height * s, "so_long");
	if (!gm->wn)
		(*er)->win = 1;
	gm->wimg = mlx_xpm_file_to_image(gm->cn, "sp/w.xpm", &s, &s);
	gm->pimg = mlx_xpm_file_to_image(gm->cn, "sp/p.xpm", &s, &s);
	gm->cimg = mlx_xpm_file_to_image(gm->cn, "sp/c.xpm", &s, &s);
	gm->eimg = mlx_xpm_file_to_image(gm->cn, "sp/e.xpm", &s, &s);
	gm->timg = mlx_xpm_file_to_image(gm->cn, "sp/t.xpm", &s, &s);
	if (!gm->wimg || !gm->pimg || !gm->cimg || !gm->eimg || !gm->timg)
		(*er)->img = 1;
	gm->pl_x = m->pl_x;
	gm->pl_y = m->pl_y;
	gm->count_C = m->count_C;
	gm->coins_collected = 0;
	gm->move_count = 0;
	gm->put_exit = 0;
	gm->map = m->map;
}
