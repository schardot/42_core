#include "../include/so_long.h"
#include "../include/map.h"

int main(int argc, char **argv)
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
	gm->map = mstruct->map;
	//free(mstruct->map);
	/*
	 **  hook funct are called as follow :
	 **
	 **   expose_hook(void *param);
	 **   key_hook(int keycode, void *param);
	 **   mouse_hook(int button, int x,int y, void *param);
	 **   loop_hook(void *param);
	 **
	 */
	init_game_struct(&gm, &gerr, mstruct);
	//mlx_expose_hook(gm->win, main_loop, (void *)gm);
	render_game(gm->map, gm);
	mlx_key_hook(gm->win, key_press, (void *)gm);
	mlx_loop_hook(gm->cnct, main_loop, (void *)gm);
	mlx_hook(gm->win, 17, 0, (void *)exit, 0);
	mlx_loop(gm->cnct);
}
int	key_press(int key, t_game *gm)
{
	char	*next;

	next = check_next_obj(gm, key);
	check_next_move(next, gm);
	render_game(gm->map, gm);
	return (0);
}

void	check_next_move(char *next, t_game *g)
{
	static int	coin = 0;
	static int	put_exit = 0;


	if (*next == 'C')
	{
		coin ++;
		*next = 'P';
		if (put_exit)
			g->map[g->pl_y][g->pl_x] = 'E';
		else
			g->map[g->pl_y][g->pl_x] = '0';
	}
	else if (*next == '0')
	{
		*next = 'P';
		if (put_exit)
			g->map[g->pl_y][g->pl_x] = 'E';
		else
			g->map[g->pl_y][g->pl_x] = '0';
	}
	else if (*next == 'E')
	{
		if (coin == g->count_C)
			mlx_destroy_window(g->cnct, g->win);
		else
		{
			*next = 'P';
			g->map[g->pl_y][g->pl_x] = '0';
			put_exit = 1;
		}
	}
}

char	*check_next_obj(t_game *gm, int key)
{
	if (key == RIGHT)
		return (&gm->map[gm->pl_y][gm->pl_x + 1]);
	else if (key == LEFT)
		return (&gm->map[gm->pl_y][gm->pl_x - 1]);
	else if (key == UP)
		return (&gm->map[gm->pl_y + 1][gm->pl_x]);
	else if (key == DOWN)
		return (&gm->map[gm->pl_y - 1][gm->pl_x]);
	else if (key == ESC)
		mlx_destroy_window(gm->cnct, gm->win);
	return (NULL);
}

int main_loop(t_game *gm)
{
	render_game(gm->map, gm);
	return (0);
}

void	render_game(char **map, t_game *gm)
{
	void	*img;
	int		h;
	int		w;

	if (!map || !gm)
		return;
	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w] && map[h][w] != '\n')
		{
			if (map[h][w] == '1')
				mlx_put_image_to_window(gm->cnct, gm->win, gm->wallimg, w * gm->size, h * gm->size);
			//img = gm->wallimg;
			else if (map[h][w] == '0')
				mlx_put_image_to_window(gm->cnct, gm->win, gm->tileimg, w * gm->size, h * gm->size);
			//img = gm->tileimg;
			else if (map[h][w] == 'C')
				mlx_put_image_to_window(gm->cnct, gm->win, gm->coinimg, w * gm->size, h * gm->size);
			// img = gm->coinimg;
			else if (map[h][w] == 'E')
				mlx_put_image_to_window(gm->cnct, gm->win, gm->exitimg, w * gm->size, h * gm->size);
			//	img = gm->exitimg;
			else if (map[h][w] == 'P')
			{
				mlx_put_image_to_window(gm->cnct, gm->win, gm->playerimg, w * gm->size, h * gm->size);
				// img = gm->playerimg;
				gm->pl_x = w;
				gm->pl_y = h;
			}
			// mlx_put_image_to_window(gm->cnct, gm->win, img, w * gm->size, h * gm->size);
			w ++;
		}
		h ++;
	}
}

void	init_game_struct(t_game **gm, t_gerr **er, t_map *m)
{
	(*gm)->size = 96;
	(*gm)->cnct = mlx_init();
	if (!(*gm)->cnct)
	{
		(*er)->cnct = 1;
		ft_putstr_fd("Error: Failed to initialize connection to graphical environment\n", 2);
		return;
	}
	(*gm)->win = mlx_new_window((*gm)->cnct, m->len * (*gm)->size, m->height * (*gm)->size, "so_long, farewell, auf wiedersehen goodbye!");
	if (!(*gm)->win)
		(*er)->win = 1;

	(*gm)->wallimg = NULL;
	(*gm)->playerimg = NULL;
	(*gm)->coinimg = NULL;
	(*gm)->exitimg = NULL;
	(*gm)->tileimg = NULL;
	(*gm)->wallimg = mlx_xpm_file_to_image((*gm)->cnct, "sprites/wall.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->playerimg = mlx_xpm_file_to_image((*gm)->cnct, "sprites/player.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->coinimg = mlx_xpm_file_to_image((*gm)->cnct, "sprites/collectible.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->exitimg = mlx_xpm_file_to_image((*gm)->cnct, "sprites/exit.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->tileimg = mlx_xpm_file_to_image((*gm)->cnct, "sprites/tile.xpm", &(*gm)->size, &(*gm)->size);
	if (!(*gm)->wallimg || !(*gm)->playerimg || !(*gm)->coinimg || !(*gm)->exitimg || !(*gm)->tileimg)
	{
		(*er)->img = 1;
		ft_printf("nao tem imagem");
	}
	(*gm)->pl_x = m->pl_x;
	(*gm)->pl_y = m->pl_y;
	(*gm)->count_C = m->count_C;
	// (*gm)->map = (char **)malloc(m->height * sizeof(char *));
	// if (!(*gm)->map)
	// {
	// 	ft_putstr_fd("Error: Couldnt alloc map\n", 2);
	// 	return ;
	// }
}
