/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:18:42 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/12 14:45:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

void	initial_file_check(t_maperr *merr, t_map *mstr, t_game *gm, char *file)
{
	int	fd;

	check_extension(gm, mstr, merr, file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		merr->open = 1;
	check_map_errors(merr, mstr, gm);
	mstr->line = "a";
	while (fd > 0 && mstr->line)
	{
		mstr->line = get_next_line(fd);
		if (mstr->line)
		{
			check_line(merr, mstr, gm, mstr->line);
			free (mstr->line);
			mstr->line = "a";
		}
	}
	if (check_count_chars(mstr, merr))
		exit_and_free_all(gm, mstr, merr);
	close(fd);
}

void	check_extension(t_game *gm, t_map *mstr, t_maperr *merr, char *file)
{
	char *aux;

	aux = ft_strnstr(file, ".ber\0", ft_strlen(file));
	if (!aux)
	{
		ft_putstr_fd("Error: check map extension\n", 2);
		exit_and_free_all(gm, mstr, merr);
	}
}

void	check_line(t_maperr *merr, t_map *mstr, t_game *gm, char *line)
{
	if (ft_strlen(line) != mstr->len)
	{
		if (line[ft_strlen(line) - 1] == '1' && line[ft_strlen(line)] == '\0')
		{
			if ((ft_strlen(line)) != mstr->len - 1)
				merr->linelen = 1;
		}
		else if (mstr->len == 0)
			mstr->len = ft_strlen(line);
		else
			merr->linelen = 1;
	}
	check_map_errors(merr, mstr, gm);
	while (*line)
	{
		check_char(*line, mstr, merr);
		check_map_errors(merr, mstr, gm);
		line++;
	}
	mstr->height++;
	line = "a";
}

void	check_char(char line, t_map *mstr, t_maperr *merr)
{
	if (line == '1')
		mstr->count_1++;
	else if (line == '0')
		mstr->count_0++;
	else if (line == 'E')
		mstr->count_E++;
	else if (line == 'P')
		mstr->count_P++;
	else if (line == 'C')
		mstr->count_C++;
	else if (line != '\n')
		merr->chars = 1;
}

int	check_count_chars(t_map *mstr, t_maperr *merr)
{
	if (mstr->count_E > 1)
		ft_putstr_fd("There is more than one exit, please check map.\n", 2);
	else if (mstr->count_E < 1)
		ft_putstr_fd("The game needs at least one exit\n", 2);
	else if (mstr->count_P > 1)
		ft_putstr_fd("There is more than one player, please check map.\n", 2);
	else if (mstr->count_P < 1)
		ft_putstr_fd("The game needs at least one player\n", 2);
	else if (mstr->count_C < 1)
		ft_putstr_fd("There needs to be at least one collectible\n", 2);
	else
		return (0);
	return (1);
}
