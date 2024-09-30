#include "../include/map.h"

int	main(int argc, char **argv)
{
	t_maperr	*merror;
	t_map		*mstruct;
	char		**map;

	init_map_structs(mstruct, merror);
	map = check_map(merror, mstruct, argv[1]);
	continuar(map);
}

char	**check_map(t_maperr *merror, t_map *mstruct, char *file)
{
	initial_map_check(merror, mstruct, file);
	check_map_errors(merror);
	mstruct->map = map_to_grid(merror, mstruct, file);
}

void	initial_map_check(t_maperr *merror, t_map *mstruct, char *file)
{
	int		fd;
	char	*line;

	if(!ft_strnstr(file, ".ber\0", ft_strlen(file)))
		merror->notber = 1; //*****
	fd = open(file, O_RDONLY);
	if (fd < 0)
		merror->cantopen = 1; //*** */
	//check_error
	line = "a";
	while (fd > 0 && line)
	{
		line = get_next_line(fd);
		check_line(merror, mstruct, line);
	}
	close(fd);
}

void	check_line(t_maperr *merror, t_map *mstruct, char *line)
{
	if (ft_strlen(line) != mstruct->len)
	{
		if (mstruct->len == 0)
			mstruct->len = ft_strlen(line);
		else
			merror->linelen = 1;
	}
	while (*line)
	{
		check_char(*line, mstruct, merror);
		line ++;
	}
	free (line);
	mstruct->height++;
}

void	check_char(char line, t_map *mstruct, t_maperr *merror)
{
	if (line == '1')
		mstruct->count_1 ++;
	else if (line == '0')
		mstruct->count_0 ++;
	else if (line == 'E')
		mstruct->count_E++;
	else if (line == 'P')
		mstruct->count_P++;
	else if (line == 'C')
		mstruct->count_C++;
	else if (line != '\n')
		merror->count_inv ++;
}

void	init_map_structs(t_map *mstruct, t_maperr *merror)
{
	merror->linelen = 0;
	merror->count_inv = 0;
	merror->cantallocate = 0;
	merror-> cantopen = 0;
	merror->notber = 0;
	merror->borderinv = 0;
	mstruct->len = 0;
	mstruct->height = 0;
	mstruct->count_1 = 0;
	mstruct->count_0 = 0;
	mstruct->count_E = 0;
	mstruct->count_P = 0;
	mstruct->count_C = 0;
	mstruct->map = NULL;
}

void    check_map_errors(t_maperr *m)
{
	if (m->notber == 1)
		ft_putstr_fd("Error: check map extension", 2);
	if (m->cantopen == 1)
		ft_putstr_fd("Error: can't open file", 2);
	if (m->linelen == 1)
		ft_putstr_fd("Error: all lines should have the same length", 2); //freeline
	if (m->count_inv == 1)
		ft_putstr_fd("Error: map contains invalid character", 2); //free line
	if (m->cantallocate == 1)
		ft_putstr_fd("Error: can't allocate map", 2);
	if (m->borderinv == 1)
		ft_putstr_fd("Error: borders are invalid", 2); //free map
}

char	**map_to_grid(t_maperr *merror, t_map *mstruct, char *file)
{
	char	**map;
	char	*line;
	int		m;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		merror->cantopen = 1;
	line = file;
	map = (char **)malloc(sizeof(char *) * (mstruct->height));
	if (!map)
		merror->cantallocate = 1;
	m = 0;
	while (line)
	{
		line = get_next_line(fd);
		map[m] = ft_strdup(line);
		m++;
	}
	close(fd);
	check_borders(merror, mstruct);
	return (map);
}

void	check_borders(t_maperr *merror, t_map *mstruct)
{
	char	*first;
	char	*last;
	int		i;
	int		len;

	i = 0;
	len = mstruct->len;
	first = mstruct->map[0];
	last = mstruct->map[mstruct->height - 1];
	while (*first & *last)
	{
		if (*first != '1' || *last != '1') // If any character is not '1', return 0 (false)
			merror->borderinv = 1;
		first ++;
		last ++;
	}
	while(mstruct->map[i])
	{
		if (mstruct->map[i][0] != '1' || mstruct->map[i][len - 1])
			merror->borderinv = 1;
		i ++;
	}
}
