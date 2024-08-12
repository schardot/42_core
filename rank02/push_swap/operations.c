/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:20:32 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/12 19:20:34 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
			printf("s%c\n", c);
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
	printf("p%c\n", c);
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
	printf("r");
	if (c == 'a' || c == 'b')
		printf("%c\n", c);
	return (true);
}

bool	move_both_stacks(t_node **a, t_node **b, char operation)
{
	if (operation == 'o')
	{
		if (rotate(a, 'x') && rotate(b, 'x'))
		{
			printf("\n");
			return (true);
		}
	}
	else if (operation == 'e')
	{
		if (reverse(a, 'x') && reverse(b, 'x'))
		{
			printf("rrr\n");
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
		printf("rr%c\n", c);
	return (true);
}
