/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:58:36 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/24 14:50:52 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	list_size(t_node *stack)
{
	int	i;

	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_node	*lst_new(long value)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->value = value;
	head->index = INT_MIN;
	head->cost = INT_MIN;
	head->first_half = NULL;
	head->cheapest = NULL;
	head->target = NULL;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	lst_clear(t_node **lst, void (*del)(void *))
{
	t_node	*aux;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		//del((void *)(*lst)->value);
		free (*lst);
		*lst = aux;
	}
	//free (lst);
	*lst = NULL;
}

void	lst_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = lst_last(*lst);
	last->next = new;
	new->prev = last;
}

t_node	*lst_last(t_node *lst)
{
	t_node	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux->next)
		aux = aux->next;
	return (aux);
}
