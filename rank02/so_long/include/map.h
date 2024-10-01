#ifndef MAP_H
#define MAP_H

//Struct used to store information on the map, used later to open window and transform file to a 2d array (grid)
typedef struct v_list
{
	int		len;
	int		height;
	int		count_1;
	int		count_0;
	int		count_E;
	int		count_P;
	int		count_C;
	char	**map;
	char	*line;
	int		pl_y;
	int		pl_x;
} t_map;

//Struct used to store error information while reading the file and dealing with the error properly in its very own function.
typedef struct s_list
{
	int	linelen;
	int	count_inv;
	int	cantallocate;
	int	cantopen;
	int	notber;
	int	borderinv;
} t_maperr;

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include "../include/libft/libft.h"
# include "../include/so_long.h"

/*
1. init_map_structs(t_map *mstruct, t_maperr *merror)
   |   --> Initializes the fields in `t_map` and `t_maperr` to zero or `NULL` values.
   |
   └─> check_map(t_maperr *merror, t_map *mstruct, char *file)
		|   --> Main map checker function, responsible for orchestrating all the map checks.
		|
		├──> initial_map_check(t_maperr *merror, t_map *mstruct, char *file)
		|    |   --> Opens the map file and performs initial checks, such as line length consistency.
		|    |
		|    └─> check_line(t_maperr *merror, t_map *mstruct, char *line)
		|         |   --> Ensures that each line has the same length and calls `check_char` for each character.
		|         |
		|         └─> check_char(char line, t_map *mstruct, t_maperr *merror)
		|             |   --> Validates each character in the line and updates counters for '10EPC'.
		|
		├──> check_map_errors(t_maperr *merror)
		|    |   --> After the initial checks, verifies if any errors were flagged in `merror`.
		|
		└──> map_to_grid(t_maperr *merror, t_map *mstruct, char *file)
			 |   --> Converts the valid map file into a 2D grid (array of strings) for further processing.
			 |
			 └─> check_borders(t_maperr *merror, t_map *mstruct)
			     |   --> Validates if all the borders of the map are made of walls.
*/

void	init_map_structs(t_map *mstruct, t_maperr *merror);
char	**check_map(t_maperr *merror, t_map *mstruct, char *file);
void	initial_map_check(t_maperr *merror, t_map *mstruct, char *file);
void	check_line(t_maperr *merror, t_map *mstruct, char *line);
void	check_char(char line, t_map *mstruct, t_maperr *merror);
void	check_map_errors(t_maperr *merror, t_map *mstruct);
char	**map_to_grid(t_maperr *merror, t_map *mstruct, char *file);
void	check_borders(t_maperr *merror, t_map *mstruct);

#endif