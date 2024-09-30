#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef struct v_list
{
	void    *connection;
	void    *window;
	void    *img;
	void    *wallimage;
	void    *playerimage;
	void    *coinimage;
	void    *exitimage;
	void    *tileimage;
} t_game;

int ft_update(t_game *g);
t_game *init_data(t_game *data);
void put_file_to_image(t_game *data);
char **start_map(char *filename);
char **ber_to_grid(int fd);
void check_map(char **map);
void grid_to_img(char **map, t_game *d);

#endif