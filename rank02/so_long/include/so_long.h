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

typedef struct s_game
{
	void	*cn;		 // Connection to the MiniLibX graphical system
	void	*wn;		 // Window reference in MiniLibX
	void	*wimg;		 // Image representing walls in the game
	void	*pimg;		 // Image representing the player character
	void	*cimg;		 // Image representing collectibles
	void	*eimg;		 // Image representing the exit
	void	*timg;		 // Temporary image for intermediate rendering
	char	**map;		 // 2D array storing the game map
	int		height;		 // Height of the map in tiles
	int		len;		 // Length of the map in tiles
	int		pl_x;		 // Player's X coordinate in the map
	int		pl_y;		 // Player's Y coordinate in the map
	int		C_sum;		 // Total number of collectibles in the game
	int		C_collected; // Number of collected collectibles
	int		move_count;	 // Total number of moves made by the player
	int		put_exit;	 // Flag to indicate if the exit can be shown
} t_game;

/*
1. main(int argc, char **argv)
   |   --> Entry point of the program, responsible for initializing the game, setting up the map, and starting the game loop.
   |
   ├──> malloc() for t_game, t_map, t_maperr
   |    |   --> Allocates memory for game state, map state, and error handling.
   |
   ├──> check_map(merr, mstr, gm, argv[1])
   |    |   --> Reads the map file, checks for errors, and converts the map to a grid.
   |    |
   |    └─> init_map_structs(mstr, merr)
   |         |   --> Initializes the map structure (`t_map`) and error structure (`t_maperr`).
   |         |
   |         └─> initial_map_check(merr, mstr, argv[1])
   |             |   --> Performs the initial checks on the map (file validity, line consistency).
   |             |
   |             └─> check_line(merr, mstr, line)
   |                 |   --> Validates each line's length and checks its characters.
   |                 |
   |                 └─> check_char(char line, t_map *mstr, t_maperr *merr)
   |                     |   --> Checks if each character is valid ('1', '0', 'E', 'P', 'C').
   |
   ├──> init_game_struct(gm, mstr)
   |    |   --> Initializes the game structure and links it with the map structure.
   |    |
   |    ├──> mlx_init()
   |    |    |   --> Initializes the MiniLibX connection (sets up graphics environment).
   |    |
   |    ├──> mlx_new_window()
   |    |    |   --> Creates the game window with the specified size (map length * tile size).
   |    |
   |    ├──> files_to_images(gm)
   |    |    |   --> Loads image files (XPM) for walls, player, collectibles, and exit.
   |    |
   |    └──> Initialize game state variables (C_sum, C_collected, move_count, etc.).
   |
   ├──> render_game(gm->map, gm)
   |    |   --> Renders the initial game map and places the player on the map.
   |    |
   |    └─> render_pos(gm->map, gm, w, h)
   |         |   --> Renders a specific position (tile) on the map based on the grid coordinates.
   |
   ├──> mlx_key_hook(gm->wn, key_press, (void *)gm)
   |	| -- > Sets up key press events(e.g., movement, exit) with the `key_press()` function.
   |	|
   |    └─> key_press(int key, t_game *gm)
   |	| -- > Handles key presses, updates player movement, and checks if the move is valid.
   |	|
   |    ├──> check_next_obj(gm, key)
   |		| -- > Determines the object on the next tile based on the direction of movement.
   |		|
   |		└─> check_next_move(next, gm)
   |		| -- > Moves the player to the next tile and updates the game state.
   |
   ├──> mlx_loop_hook(gm->cn, main_loop, (void *)gm)
   |	| -- > Sets up the main game loop with the `main_loop()` function.
   |	|
   |    └─> main_loop(t_game *gm)
   |		| -- > Continuously updates the game state and checks if any key events occurred.
   |
   ├──> mlx_hook(gm->wn, 17, 0, (void *)exit, 0)
   |	| -- > Adds a hook to capture window close events(like the window "X" button).
   |
   └──> mlx_loop(gm->cn)
   		| -- > Starts the MiniLibX main loop, rendering frames and handling events(such as key presses).
*/

int		key_press(int key, t_game *gm);
void	check_next_move(char *next, t_game *gm);
char	*check_next_obj(t_game *gm, int key);
int		main_loop(t_game *gm);
void	render_game(char **map, t_game *gm);
void	render_pos(char **map, t_game *gm, int w, int h);
void	check_put_exit(t_game *g);
void	init_game_struct(t_game *gm, t_map *m);
void	files_to_images(t_game *gm);
void	exit_and_free(t_game *g);
void	render_pos(char **map, t_game *gm, int w, int h);

#endif