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
} game_node;

typedef struct s_list
{
	char letter;
	int	count;
	s_list	*next;
	s_list	*prev;
}	map_node;

int ft_update(gamedata *g);
gamedata *init_data(gamedata *data);
void put_file_to_image(gamedata *data);
char **start_map(char *filename);
char **ber_to_grid(int fd);
void check_map(char **map);
void grid_to_img(char **map, gamedata *d);

#endif