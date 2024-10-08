/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:46:04 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/27 16:42:14 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(char *arg)
{
	char	*str;

	if (!arg)
		return (1);
	str = arg;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		str++;
	}
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int		i;
	long	num;
	char	*itoa_r;

	i = 0;
	while (i < argc)
	{
		if (is_valid_number(argv[i]) == 1)
			return (1);
		if (duplicates_check(argv, argc, argv[i]) == 1)
			return (1);
		num = ft_atoi(argv[i]);
		itoa_r = ft_itoa(num);
		if (ft_strncmp(itoa_r, argv[i], ft_strlen(argv[i])) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			free(itoa_r);
			return (1);
		}
		free(itoa_r);
		i++;
	}
	return (0);
}

void	preprocessing(int argc, char **argv, t_node **a)
{
	char	**arguments;
	int		ac;
	int		stack_status;
	int		should_free;

	should_free = 0;
	stack_status = 0;
	ac = argc - 1;
	arguments = argv;
	arguments ++;
	if (argc == 2)
	{
		ac = argctwo(&arguments);
		should_free = 1;
	}
	if (check_argv(ac, arguments) == 0)
		stack_status = create_populate_stack(a, ac, arguments);
	if (should_free == 1)
		free_arguments(arguments);
	if (stack_status == 1)
		exit (1);
}

int	create_populate_stack(t_node **a, int ac, char **arguments)
{
	int		i;
	t_node	*node_aux;

	*a = lst_new((long)ft_atoi(arguments[0]));
	if (!*a)
		return (1);
	i = 1;
	while (i < ac)
	{
		node_aux = lst_new((long)ft_atoi(arguments[i]));
		if (!node_aux)
		{
			lst_clear(a, free);
			return (1);
		}
		lst_add_back(a, node_aux);
		i++;
	}
	return (0);
}

int	duplicates_check(char **args, int argc, char *cur)
{
	int		i;
	int		len_cur;
	int		len_i;
	bool	found_itself;

	len_cur = ft_strlen(cur);
	i = 0;
	found_itself = false;
	while (i < argc)
	{
		len_i = ft_strlen(args[i]);
		if (len_cur == len_i && ft_strncmp(args[i], cur, len_cur) == 0)
		{
			if (found_itself == true)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			found_itself = true;
		}
		i ++;
	}
	return (0);
}
