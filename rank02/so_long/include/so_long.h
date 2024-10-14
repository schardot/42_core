/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:27:37 by nleite-s          #+#    #+#             */
/*   Updated: 2024/10/14 11:27:38 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
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
#define A 97
#define W 119
#define S 115
#define D 100
#define SIZE 94

typedef struct s_game
{
	void	*cn;		    // Connection to the MiniLibX graphical system
	void	*wn;		    // Window reference in MiniLibX
	void	*wimg;		 // Image representing walls in the game
	void	*pimg;		 // Image representing the player character
	void	*cimg;		 // Image representing collectibles
	void	*eimg;		 // Image representing the exit
	void	*timg;		 // Temporary image for intermediate rendering
	char	**map;		 // 2D array storing the game map
	int	height;		 // Height of the map in tiles
	int	len;		    // Length of the map in tiles
	int	pl_x;		    // Player's X coordinate in the map
	int	pl_y;		    // Player's Y coordinate in the map
	int	C_sum;		 // Total number of collectibles in the game
	int	C_collected; // Number of collected collectibles
	int	move_count;	 // Total number of moves made by the player
	int	put_exit;	 // Flag to indicate if the exit can be shown

} t_game;

int	key_press(int key, t_game *gm);
void	check_next_move(char *next, t_game *gm);
char  *check_next_obj(t_game *gm, int key);
int   main_loop(t_game *gm);
void	render_game(char **map, t_game *gm);
void	render_pos(char **map, t_game *gm, int w, int h);
void	check_put_exit(t_game *g);
void  init_game_struct(t_game *gm, t_map *mstr, t_maperr *merr);
void  files_to_images(t_game *gm, t_map *mstr, t_maperr *merr);
void  exit_and_free_all(t_game *gm, t_map *mstr, t_maperr *merr);
void  render_pos(char **map, t_game *gm, int w, int h);
void  allocate_structs(t_game **gm, t_map **mstr, t_maperr **merr);
int   exit_and_free_gm(t_game *gm);

#endif