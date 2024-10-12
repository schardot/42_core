#ifndef MAP_H
# define MAP_H

// Struct used to store information on the map, used later to open window and transform file to a 2D array (grid)
typedef struct s_map
{
	int len;	  // Length of a line in the map
	int height;	  // Number of lines in the map
	int count_1;  // Count of walls
	int count_0;  // Count of empty spaces
	int count_E;  // Count of exits
	int count_P;  // Count of players
	int count_C;  // Count of collectibles
	char *line;	  // Current line being read
	int	pc_coin;  // Coin count used for path checking
	int pc_exit;  // Flag for exit found used for path checking
	int pc_valid; // Flag for valid used for path checking
} t_map;

// Struct used to store error information while reading the file and dealing with errors properly in its very own function.
typedef struct s_maperr
{
	int linelen; // Flag for inconsistent line lengths
	int chars;	 // Flag for invalid characters in the map
	int alloc;	 // Flag for memory allocation failures
	int open;	 // Flag for failed file opening
	int notber;	 // Flag for incorrect file extension
	int border;	 // Flag for invalid borders
} t_maperr;

# include <fcntl.h>					// For open()
# include <stddef.h>				// For NULL
# include <stdio.h>					// For perror() and printf()
# include <unistd.h>				// For close() and read()
# include "../include/libft/libft.h"
# include "../include/libft/get_next_line/get_next_line.h"
# include "../include/so_long.h"

typedef struct s_game t_game;

/*
1. init_map_structs(t_map *mstr, t_maperr *merr)
   |   --> Initializes the fields in `t_map` and `t_maperr` to zero or `NULL` values.
   |
   └─> check_map(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
		|   --> Main map checker function, responsible for orchestrating all the map checks.
		|
		├──> initial_map_check(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
		|    |   --> Opens the map file and performs initial checks, such as line length consistency.
		|    |
		|    └─> check_line(t_maperr *merr, t_map *mstr, t_game *gm, char *line)
		|         |   --> Ensures that each line has the same length and calls `check_char` for each character.
		|         |
		|         └─> check_char(char line, t_map *mstr, t_maperr *merr)
		|             |   --> Validates each character in the line and updates counters for '10EPC'.
		|
		├──> check_map_errors(t_maperr *merr, t_map *mstr, t_game *gm)
		|    |   --> After the initial checks, verifies if any errors were flagged in `merr`.
		|
		├──> map_to_grid(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
		|    |   --> Converts the valid map file into a 2D grid (array of strings) for further processing.
		|
		├──> check_borders(t_maperr *merr, t_map *mstr, t_game *gm)
		|    |   --> Validates if all the borders of the map are made of walls.
		|
		├──> get_player_xy(t_game *gm)
		|    |   --> Retrieves the coordinates of the player in the map.
		|
		├──> check_valid_path(char **map, int h, int w, t_map *mstr)
		|    |   --> Checks if there is a valid path from the player to the exit while collecting all collectibles.
			 |
			 └──> check_neighbour(char **map, int h, int w)
				  |   --> Checks the neighboring cells of a given cell to determine if movement is possible.
*/

// Function prototypes:
void	init_map_structs(t_map *mstr, t_maperr *merr);
void	check_map(t_maperr *merr, t_map *mstr, t_game *gm, char *file);
void	initial_file_check(t_maperr *merr, t_map *mstr, t_game *gm, char *file);
void	check_line(t_maperr *merr, t_map *mstr, t_game *gm, char *line);
void	check_char(char line, t_map *mstr, t_maperr *merr);
void	check_map_errors(t_maperr *merr, t_map *mstr, t_game *gm);
void	map_to_grid(t_maperr *merr, t_map *mstr, t_game *gm, char *file);
void	check_borders(t_maperr *merr, t_map *mstr, t_game *gm);
void	get_player_xy(t_game *gm);
int		check_path(char **map, int h, int w, t_map *m);
int		check_neighbour(char **map, int h, int w);
int		check_count_chars(t_map *mstr, t_maperr *merr);
void	write_map_from_file(t_game *gm, t_map *mstr, int fd);
void	check_extension(t_game *gm, t_map *mstr, t_maperr *merr, char *file);

#endif
