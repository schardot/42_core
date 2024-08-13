/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:20:22 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/12 19:20:24 by nataliaschard    ###   ########.fr       */
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
		return (0);
	prep_check_argv(argc, argv);
	prep_array_to_list(argc, argv, &a);
	if (list_size(a) == 3)
		size_three_list(&a);
	if (check_sort(a) == true)
		return (0);
	sort(&a, &b);
	return (0);
}
