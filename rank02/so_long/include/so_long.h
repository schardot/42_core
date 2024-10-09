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
#define UP 125
#define RIGHT 124
#define DOWN 126
#define A 0
#define W 1
#define S 13
#define D 2
#define SIZE 96
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
void init_game_struct(t_game **gm, t_gerr **er, t_map *m);

#endif