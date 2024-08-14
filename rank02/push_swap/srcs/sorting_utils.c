/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:28:28 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/14 11:28:31 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		if (!*b && !sorted)
			finish_sorting(a, &sorted);
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

void	finish_sorting(t_node **a, bool *sorted)
{
	while (*sorted == false)
	{
		if (biggest_node(*a)->first_half)
			rotate(a, 'a');
		else if (biggest_node(*a)->first_half == false)
			reverse(a, 'a');
		update_index(a, list_size(*a));
		*sorted = check_sort(*a);
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
				move_both_stacks(a, b, 'o', false);
			else if (!c_half && !t_half)
				move_both_stacks(a, b, 'e', false);
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

t_node	*biggest_node(t_node *stack)
{
	long	biggest_value;
	t_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_value = LONG_MIN;
	while (stack)
	{
		if (stack->value > biggest_value)
		{
			biggest_node = stack;
			biggest_value = stack->value;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
