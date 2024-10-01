#include "../include/so_long.h"
#include "../include/map.h"

int main(int argc, char **argv)
{
	t_maperr	*merror;
	t_map		*mstruct;
	t_game		*gm;
	char		**map;

	init_map_structs(mstruct, merror);
	gm->map = check_map(merror, mstruct, argv[1]);
	// Initialize game structure, window, images, etc.
	init_game_struct(gm, merror, mstruct);

	// Set up the loop hook
	mlx_loop_hook(gm.cnct, main_loop, &gm);

	// Register the key press event handler
	mlx_key_hook(gm.win, key_press, &gm);

	// Start the main event loop
	mlx_loop(gm.cnct);
	newgame(map);
}
int	key_press(int key, t_game *gm)
{
	static int	coin = 0;
	if(check_valid_move())
	{
		gm->map[pl_y][pl_x] = '0';
		if (key == RIGHT)
			gm->map[pl_y][pl_x + 1] = 'P';
		else if (key == LEFT)
			gm->map[pl_y][pl_x - 1] = 'P';
		else if (key == UP)
			gm->map[pl_y + 1][pl_x] = 'P';
		else if (key == DOWN)
			gm->map[pl_y - 1][pl_x] = 'P';
		else if (key == ESC)
			fechar janela;
	}
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
				img = gm->wallimage;
			else if (map[h][w] == '0')
				img = gm->tileimage;
			else if (map[h][w] == 'C')
				img = gm->coinimage;
			else if (map[h][w] == 'E')
				img = gm->exitimage;
			else
			{
				img = gm->playerimage;
				gm->pl_x = w;
				gm->pl_y = h;
			}
			mlx_put_image_to_window(gm->cnct, gm->win, img, w * gm->size, h * gm->size);
		}
	}
}


void init_game_struct(t_game *gm, t_gerr er, t_map m)
{
	int	size;

	size = 32;
	gm->cnct = mlx_init();
	if (!gm->cnct)
		er->cnct = 1;
	gm->win = mlx_new_window(gm->cnct, m->len, m->height, "so_long, farewell, auf wiedersehen goodbye!");
	if (!gm->win)
		er->win = 1;
	gm->wallimg = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/wall.xpm", &size, &size);
	gm->playimg = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/player.xpm", &size, &size);
	gm->coinimg = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/collectible.xpm", &size, &size);
	gm->exitimg = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/exit.xpm", &size, &size);
	gm->tileimg = mlx_xpm_file_to_image(data->connection, "/Users/nataliaschardosim/42_core/rank02/so_long/sprites/tile.xpm", &size, &size);
	if (!gm->wallimg || !gm->playimg || !gm->coinimg || !gm->exitimg || !gm->tileimg)
		er->image = 1;
	gm->size = 32;
}
