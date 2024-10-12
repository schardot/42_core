#include "../include/so_long.h"

void	exit_and_free_all(t_game *gm, t_map *mstr, t_maperr *merr)
{
	if (merr)
		free(merr);
	if (mstr)
		free(mstr);
	exit_and_free_gm(gm);
	exit(0);
}

void	exit_and_free_gm(t_game *gm)
{
	if (gm->wn)
		mlx_destroy_window(gm->cn, gm->wn);
	if (gm->map)
		ft_free_grid(gm->map);
	if (gm)
		free(gm);
	exit(0);
}