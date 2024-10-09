#ifndef MAP_H
#define MAP_H

// Struct used to store information on the map, used later to open window and transform file to a 2D array (grid)
typedef struct v_list
{
	int len;	 // Length of a line in the map
	int height;	 // Number of lines in the map
	int count_1; // Count of walls
	int count_0; // Count of empty spaces
	int count_E; // Count of exits
	int count_P; // Count of players
	int count_C; // Count of collectibles
	char **map;	 // 2D array representing the map
	char *line;	 // Current line being read
	int pl_y;	 // Player's y-coordinate
	int pl_x;	 // Player's x-coordinate
} t_map;

// Struct used to store error information while reading the file and dealing with errors properly in its very own function.
typedef struct x_list
{
	int linelen;	  // Flag for inconsistent line lengths
	int chars;	  // Flag for invalid characters in the map
	int alloc; // Flag for memory allocation failures
	int open;	  // Flag for failed file opening
	int notber;		  // Flag for incorrect file extension
	int border;	  // Flag for invalid borders
} t_maperr;

#include <fcntl.h>					// For open()
#include <stddef.h>					// For NULL
#include <stdio.h>					// For perror() and printf()
#include <unistd.h>					// For close() and read()
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include "../include/so_long.h"

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
		├──> check_map_errors(t_maperr *merror, t_map *mstruct)
		|    |   --> After the initial checks, verifies if any errors were flagged in `merror`.
		|
		├──> map_to_grid(t_maperr *merror, t_map *mstruct, char *file)
		|    |   --> Converts the valid map file into a 2D grid (array of strings) for further processing.
		|
		├──> check_borders(t_maperr *merror, t_map *mstruct)
		|    |   --> Validates if all the borders of the map are made of walls.
		|
		├──> get_player_xy(t_map *mstruct)
		|    |   --> Retrieves the coordinates of the player in the map.
		|
		├──> check_valid_path(char **map, int h, int w, int count_C)
		|    |   --> Checks if there is a valid path from the player to the exit while collecting all collectibles.
		     |
			 └──> check_neighbour(char **map, int h, int w)
			      |   --> Checks the neighboring cells of a given cell to determine if movement is possible.
*/

// Function prototypes
void init_map_structs(t_map **mstruct, t_maperr **merror);
char **check_map(t_maperr *merror, t_map *mstruct, char *file);
void initial_map_check(t_maperr *merror, t_map *mstruct, char *file);
void check_line(t_maperr *merror, t_map *mstruct, char *line);
void check_char(char line, t_map *mstruct, t_maperr *merror);
void check_map_errors(t_maperr *merror, t_map *mstruct);
char **map_to_grid(t_maperr *merror, t_map *mstruct, char *file);
void check_borders(t_maperr *merror, t_map *mstruct);
void get_player_xy(t_map *mstruct);							  // Added to retrieve player coordinates
int check_valid_path(char **map, int h, int w, int count_C); // Added to validate path to exit
int check_neighbour(char **map, int h, int w);				  // Added to check neighboring cells for valid moves
void check_count_char(t_map *mstruct, t_maperr *merror);

#endif
