/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:44:21 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/26 18:44:23 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit (1);
	preprocessing(argc, argv, &a);
	if (a && list_size(a) == 3)
		size_three_list(&a);
	if (a && check_sort(a) == true)
	{
		lst_clear(&a, &free);
		return (0);
	}
	else if (a)
		sort(&a, &b);
	lst_clear(&a, &free);
	lst_clear(&b, &free);
	return (0);
}
