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

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	long	biggest_number;
	long	smallest_number;

	a = NULL;
	b = NULL;
	biggest_number = LONG_MIN;
	smallest_number = LONG_MAX;
	if (argc < 2)
		return (0);
	prep_check_argv(argc, argv, &biggest_number, &smallest_number);
	prep_array_to_list(argc, argv, &a);
	if (check_sort(a) == true)
	{
		return (0);
	}
	sort(&a, &b);
	return (0);
}

void	sort(t_node **a, t_node **b)
{
	t_node	*cur;
	bool	sorted;

	sorted = false;
	while (list_size(*a) > 3)
		push(a, b, 'b');
	size_three_list(a);
	while (!sorted || !b)
	{
		while (!*b && !sorted)
		{
			rotate(a, 'a');
			sorted = check_sort(*a);
		}
		if (sorted)
			return ;
		update_stack(a, b);
		cur = (*b);
		while (cur->next && !cur->cheapest)
			cur = cur->next;
		move_until_first(a, b, cur);
		push(b, a, 'a');
		if (check_sort(*a) && !*b)
			sorted = true;
	}
}

void	move_until_first(t_node **a, t_node **b, t_node *cur)
{
	bool	c_half;
	bool	t_half;

	while ((cur->index > 0 || cur->target->index > 0))
	{
		c_half = cur->first_half;
		t_half = cur->target->first_half;
		if (cur->index > 0 && cur->target->index > 0 && c_half == t_half)
		{
			if (c_half && t_half)
				move_both_stacks(a, b, 'o');
			else if (!c_half && !t_half)
				move_both_stacks(a, b, 'e');
		}
		else if (cur->index > 0 && c_half)
			rotate(b, 'b');
		else if (cur->index > 0 && !c_half)
			reverse(b, 'b');
		else if (cur->target->index > 0 && t_half)
			rotate(a, 'a');
		else if (cur->target->index > 0 && !t_half)
			reverse(a, 'a');
		update_index(a, list_size(*a));
		update_index(b, list_size(*b));
	}
}

void	size_three_list(t_node **a)
{
	while (!check_sort(*a))
	{
		if ((*a)->value > (*a)->next->value)
			swap(a, 'a');
		else
			reverse(a, 'a');
	}
}

long	biggest_node(t_node *stack)
{
	long	i;

	i = LONG_MIN;
	while (stack)
	{
		if (stack->value > i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}
