/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:20:22 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/24 14:42:30 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	preprocessing(argc, argv, &a);
	if (list_size(a) == 3)
		size_three_list(&a);
	if (check_sort(a) == true)
	{
		lst_clear(&a, &free);
		return (0);
	}
	sort(&a, &b);
	lst_clear(&a, &free);
	lst_clear(&b, &free);
	return (0);
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