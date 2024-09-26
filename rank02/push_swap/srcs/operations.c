/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:45:55 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/26 18:45:56 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **stack, char c)
{
	long	swap_helper;

	if (list_size(*stack) < 2)
		return ;
	if (stack && (*stack)->next)
	{
		swap_helper = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = swap_helper;
		if (c == 'a' || c == 'b')
			ft_printf("s%c\n", c);
	}
}

void	push(t_node **from, t_node **to, char c)
{
	t_node	*aux;

	if (!from || !*from)
		return ;
	aux = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	aux->next = *to;
	if (*to)
		(*to)->prev = aux;
	*to = aux;
	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
}

bool	rotate(t_node **stack, char c)
{
	t_node	*last;
	t_node	*first;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	first = *stack;
	last = lst_last(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	(*stack)->prev = NULL;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	return (true);
}

bool	move_both_stacks(t_node **a, t_node **b, char operation, bool checker)
{
	if (operation == 'o')
	{
		if (rotate(a, 'x') && rotate(b, 'x'))
		{
			if (!checker)
				ft_printf("rr\n");
			return (true);
		}
	}
	else if (operation == 'e')
	{
		if (reverse(a, 'x') && reverse(b, 'x'))
		{
			if (!checker)
				ft_printf("rrr\n");
			return (true);
		}
	}
	return (false);
}

bool	reverse(t_node **stack, char c)
{
	t_node	*last;
	t_node	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	(*stack)->next->prev = *stack;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	return (true);
}
