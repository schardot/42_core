#include "../include/so_long.h"
#include "../include/map.h"

int	key_press(int key, t_game *gm)
{
	char	*next;

	next = check_next_obj(gm, key);
	if (!next)
		return (0);
	check_next_move(next, gm);
	render_game(gm->map, gm);
	return (0);
}

void	check_next_move(char *next, t_game *g)
{
	static int	coin = 0;
	static int	put_exit = 0;
	static int	move = 0;

	if (!next || !g || !g->map)
		return ;
	if (*next == 'C' || *next == '0' || *next == 'E')
	{
		if (put_exit)
		{
			g->map[g->pl_y][g->pl_x] = 'E';
			put_exit = 0;
		}
		if (*next == 'E')
		{
			if (coin == g->count_C)
				mlx_destroy_window(g->cn, g->wn); // tem que acabar o jogo direito!
			else
				put_exit = 1;
		}
		if (*next == 'C')
			coin++;
		*next = 'P';
		g->map[g->pl_y][g->pl_x] = '0';
		move++;
		ft_printf("Number of movements: %d\n", move);
	}
}

char	*check_next_obj(t_game *gm, int key)
{
	if (key == RIGHT || key == D)
		return (&gm->map[gm->pl_y][gm->pl_x + 1]);
	else if (key == LEFT || key == A)
		return (&gm->map[gm->pl_y][gm->pl_x - 1]);
	else if (key == UP || key == W)
		return (&gm->map[gm->pl_y + 1][gm->pl_x]);
	else if (key == DOWN || key == S)
		return (&gm->map[gm->pl_y - 1][gm->pl_x]);
	else if (key == ESC)
	{
		mlx_destroy_window(gm->cn, gm->wn);
		exit(0);
	}
	return (NULL);
}
