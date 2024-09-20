/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:58:10 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/19 17:37:00 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

bool	is_valid_number(char *arg)
{
	char	*str;

	str = arg;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf("Error\n");
			exit(false);
		}
		str++;
	}
	return (true);
}

bool	prep_check_argv(int argc, char **argv)
{
	int		i;
	long	num;
	char	*itoa_r;

	i = 1;
	while (i < argc)
	{
		is_valid_number(argv[i]);
		num = ft_atoi(argv[i]);
		itoa_r = ft_itoa(num);
		duplicates_check(argv, argc, argv[i]);
		if (ft_strncmp(itoa_r, argv[i], ft_strlen(argv[i]) != 0))
		{
			ft_printf("Error\n");
			exit (false);
		}
		i++;
	}
	return (true);
}

bool	prep_array_to_list(int argc, char **argv, t_node **a)
{
	int		i;
	char	**arguments;
	t_node	*node_aux;

	i = 1;
	arguments = argv;
	
	//-----------------ALTERANDO AQUI
	if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if (!arguments)
		{
			ft_printf("Error");
			exit (1);
		}
		argc = argumentcount(arguments);
		i = 0;
	}
	//-----------------------------------------
	prep_check_argv(argc, arguments);
	*a = lst_new((long)ft_atoi(arguments[i]));
	if (!*a)
		exit(false);
	i++;
	while (i < argc)
	{
		node_aux = lst_new((long)ft_atoi(arguments[i]));
		if (!node_aux)
		{
			lst_clear(a, free);
			return (false);
		}
		lst_add_back(a, node_aux);
		i++;
	}
	return (true);
}

bool	duplicates_check(char **args, int argc, char *cur)
{
	int		i;
	int		len_cur;
	int		len_i;
	bool	found_itself;

	len_cur = ft_strlen(cur);
	i = 1;
	found_itself = false;
	while (i < argc)
	{
		len_i = argumentcount(&args[i]);
		if (len_cur == len_i && ft_strncmp(args[i], cur, len_cur) == 0)
		{
			if (found_itself == true)
			{
				ft_printf("Error\n");
				exit(false);
			}
			found_itself = true;
		}
		i ++;
	}
	return (true);
}

int	argumentcount(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
		i++;
	return (i);
}