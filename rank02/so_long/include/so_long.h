#ifndef SO_LONG_H
# define SO_LONG_H

//#include "../include/minilibx-linux/mlx.h"
#include "../include/minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../include/libft/libft.h"
#include "../include/map.h"
#include <string.h>

#define ESC 53
#define LEFT 123
#define UP 126
#define RIGHT 124
#define DOWN 125
#define A 0
#define W 13
#define S 1
#define D 2
#define SIZE 94

typedef struct y_list
{
	void    *cn;
	void    *wn;
	void    *wimg;
	void    *pimg;
	void    *cimg;
	void    *eimg;
	void    *timg;
	char	**map;
	int		pl_x;
	int		pl_y;
	int		old_y;
	int		old_x;
	int		count_C;
	int		coins_collected;
	int		move_count;
	int		put_exit;
} t_game;

typedef struct a_list
{
	int	cnct; //no connection
	int	win; //no window
	int img;
} t_gerr;

int		key_press(int key, t_game *gm);
void	check_next_move(char *next, t_game *gm);
char	*check_next_obj(t_game *gm, int key);
int		main_loop(t_game *gm);
void	render_game(char **map, t_game *gm);
void	check_put_exit(t_game *g);
void	init_game_struct(t_game **gm, t_gerr **er, t_map *m);

#endif