/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:22:37 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/12 19:22:39 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_stack(t_node **a, t_node **b)
{
	int	size_a;
	int	size_b;

	size_a = list_size(*a);
	size_b = list_size(*b);
	update_index(a, size_a);
	update_target(*a, b, biggest_node(*a));
	update_index(b, size_b);
	update_cost(b, size_a, size_b);
	if (b && *b)
		update_cheapest(b);
}

void	update_target(t_node *stack_a, t_node **stack_b, long biggest)
{
	t_node	*b;
	t_node	*a;

	b = *stack_b;
	while (b)
	{
		a = stack_a;
		while (a)
		{
			if (!(b)->target)
				(b)->target = a;
			if (((b)->value > biggest))
			{
				if (a->value < b->target->value)
					(b)->target = (a);
			}
			else if ((a)->value > (b)->value)
			{
				if (a->value < b->target->value || b->target->value < b->value)
					(b)->target = (a);
			}
			a = (a)->next;
		}
		b = (b)->next;
	}
}

void	update_index(t_node **list, int size)
{
	int		i;
	t_node	*stack;

	stack = *list;
	i = 0;
	while (stack)
	{
		(stack)->index = i;
		if (i <= size / 2)
			(stack)->first_half = true;
		else if (i <= size / 2 && size % 2 != 0)
			(stack)->first_half = true;
		else
			(stack)->first_half = false;
		stack = (stack)->next;
		i++;
	}
}

void	update_cost(t_node **stack, int target_stack_size, int stack_size)
{
	int		cost;
	t_node	*b;

	b = *stack;
	while (b)
	{
		cost = 0;
		if (b->first_half)
			cost = b->index;
		else
			cost = stack_size - b->index;
		if (b->target->first_half)
			cost += b->target->index;
		else
			cost += target_stack_size - b->target->index;
		b->cost = cost;
		b = b->next;
	}
}

void	update_cheapest(t_node **stack)
{
	long	cheapest_cost;
	t_node	*cheapest_node;
	t_node	*b;

	b = *stack;
	if (!b)
		return ;
	cheapest_cost = LONG_MAX;
	while (b)
	{
		if (b->cost < cheapest_cost)
		{
			cheapest_node = b;
			cheapest_cost = b->cost;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}
