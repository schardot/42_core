/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_two_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:45:09 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/26 11:45:10 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	argumentcount(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	argctwo(char ***arguments)
{
	int	ac;

	*arguments = ft_split(**arguments, ' ');
	if (!*arguments)
	{
		ft_printf("Error: Could not split arguments.\n");
		exit(1);
	}
	ac = argumentcount(*arguments);
	return (ac);
}

void	free_arguments(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
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
