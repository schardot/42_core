#ifndef SO_LONG_H
# define SO_LONG_H

#include "../include/minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include "../include/map.h"
#include <string.h>

#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

typedef struct v_list
{
	void    *cnct;
	void    *win;
	void    *wallimage;
	void    *playerimage;
	void    *coinimage;
	void    *exitimage;
	void    *tileimage;
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
	int image;
} t_gerr;

int ft_update(t_game *g);
t_game *init_data(t_game *data);
void put_file_to_image(t_game *data);
void grid_to_img(char **map, t_game *d);

#endif