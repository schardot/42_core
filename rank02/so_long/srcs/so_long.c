#include "../include/so_long.h"
#include "../include/map.h"

int main(int argc, char **argv)
{
	t_maperr	*merror;
	t_map		*mstruct;
	t_game		*gm;
	t_gerr		*gerr;
	char		**map;

	if (argc != 2)
		return (1);
	init_map_structs(&mstruct, &merror);
	gm->map = check_map(merror, mstruct, argv[1]);
	// Initialize game structure, window, images, etc.
	init_game_struct(&gm, &gerr, mstruct);

	// Set up the loop hook
	mlx_loop_hook(gm->cnct, main_loop, &gm);

	// Register the key press event handler
	mlx_key_hook(gm->win, key_press, &gm);

	// Start the main event loop
	mlx_loop(gm->cnct);
}
int	key_press(int key, t_game *gm)
{
	char	*next;

	next = check_next_obj(gm, key);
	check_next_move(next, gm);
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

	h = -1;
	while (map[++h])
	{
		w = -1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
				img = gm->wallimg;
			else if (map[h][w] == '0')
				img = gm->tileimg;
			else if (map[h][w] == 'C')
				img = gm->coinimg;
			else if (map[h][w] == 'E')
				img = gm->exitimg;
			else
			{
				img = gm->playerimg;
				gm->pl_x = w;
				gm->pl_y = h;
			}
			mlx_put_image_to_window(gm->cnct, gm->win, img, w * gm->size, h * gm->size);
		}
	}
}


void init_game_struct(t_game **gm, t_gerr **er, t_map *m)
{
	*gm = malloc(sizeof(t_game));
	*er = malloc(sizeof(t_gerr));
	if (!(*gm) || !(*er))
	{
		perror("Error allocating memory for map structures");
		exit(EXIT_FAILURE);
	}
	(*gm)->size = 32;
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
	(*gm)->wallimg = mlx_xpm_file_to_image((*gm)->cnct, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/wall.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->playerimg = mlx_xpm_file_to_image((*gm)->cnct, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/player.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->coinimg = mlx_xpm_file_to_image((*gm)->cnct, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/collectible.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->exitimg = mlx_xpm_file_to_image((*gm)->cnct, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/exit.xpm", &(*gm)->size, &(*gm)->size);
	(*gm)->tileimg = mlx_xpm_file_to_image((*gm)->cnct, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/tile.xpm", &(*gm)->size, &(*gm)->size);
	if (!(*gm)->wallimg || !(*gm)->playerimg || !(*gm)->coinimg || !(*gm)->exitimg || !(*gm)->tileimg)
		(*er)->img = 1;
	(*gm)->pl_x = m->pl_x;
	(*gm)->pl_y = m->pl_y;
	(*gm)->count_C = m->count_C;
}
