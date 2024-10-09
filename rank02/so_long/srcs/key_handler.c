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
	if (!next || !g || !g->map)
		return ;
	if (*next == 'C' || *next == '0' || *next == 'E')
	{
		if (*next == 'C')
			g->coins_collected ++;
		if (g->put_exit)
			check_put_exit(g);
		else
			g->map[g->pl_y][g->pl_x] = '0';
		g->move_count ++;
		ft_printf("Number of movements: %d\n", g->move_count);
		if (*next == 'E')
		{
			if (g->coins_collected == g->count_C)
			{
				ft_printf("Congratulations! You completed the game in %d moves.\n", g->move_count);
				mlx_destroy_window(g->cn, g->wn); // Exit the game gracefully
				exit(0);						  // Ensure the program ends cleanly
			}
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
	{
		mlx_destroy_window(gm->cn, gm->wn);
		exit(0);
	}
	return (NULL);
}
