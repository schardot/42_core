/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:58:10 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/12 18:58:12 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

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
			printf("Error\n");
			exit(false);
		}
		str++;
	}
	return (true);
}

bool	prep_check_argv(int argc, char **argv, long *biggest, long *smallest)
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
			printf("Error\n");
			exit (false);
		}
		if (num > *biggest)
			*biggest = num;
		if (num < *smallest)
			*smallest = num;
		i++;
	}
	return (true);
}

bool	prep_array_to_list(int argc, char **argv, t_node **a)
{
	int		i;
	t_node	*node_aux;

	i = 1;
	*a = lst_new((long)ft_atoi(argv[i]));
	if (!*a)
		exit(false);
	i++;
	while (i < argc)
	{
		node_aux = lst_new((long)ft_atoi(argv[i]));
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
	i = 2;
	found_itself = false;
	while (i < argc)
	{
		len_i = ft_strlen(args[i]);
		if (len_cur == len_i && ft_strncmp(args[i], cur, len_cur) == 0)
		{
			if (found_itself == true)
			{
				printf("Error duplicate\n");
				exit(false);
			}
			found_itself = true;
		}
		i ++;
	}
	return (true);
}

bool	check_sort(t_node *a)
{
	t_node	*aux;

	if (!a)
		return (true);
	aux = a;
	while (aux->next)
	{
		if ((long)aux->value > (long)aux->next->value)
			return (false);
		aux = aux->next;
	}
	return (true);
}
