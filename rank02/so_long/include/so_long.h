#ifndef SO_LONG_H
# define SO_LONG_H

#include "../include/minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../include/libft/libft.h"
#include "../include/map.h"
#include <string.h>

#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

typedef struct y_list
{
	void    *cnct;
	void    *win;
	void    *wallimg;
	void    *playerimg;
	void    *coinimg;
	void    *exitimg;
	void    *tileimg;
	int		size;
	char	**map;
	int		pl_x;
	int		pl_y;
	int		count_C;
} t_game;

typedef struct a_list
{
	int	cnct; //no connection
	int	win; //no window
	int img;
} t_gerr;

int key_press(int key, t_game *gm);
void check_next_move(char *next, t_game *gm);
char *check_next_obj(t_game *gm, int key);
int main_loop(t_game *gm);
void render_game(char **map, t_game *gm);
void init_game_struct(t_game *gm, t_gerr *er, t_map *m);

#endif