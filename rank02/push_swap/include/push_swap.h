/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:57:49 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/25 10:28:01 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct node
{
	long		value;
	int			index;
	int			cost;
	bool		first_half;
	bool		cheapest;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}	t_node;

void	preprocessing(int argc, char **argv, t_node **a);
int		create_populate_stack(t_node **a, int ac, char **arguments);
bool	is_valid_number(char *arg);
int		argumentcount(char **argv);
void	free_arguments(char **arguments);
int		argctwo(char ***arguments);
void	check_argv(int argc, char **argv);
void	duplicates_check(char **args, int argc, char *current);
bool	check_sort(t_node *a);
void	sort(t_node **a, t_node **b);
void	finish_sorting(t_node **a, bool *sorted);
void	size_three_list(t_node **a);
void	update_stack(t_node **a, t_node **b);
void	update_target(t_node *a, t_node **b, t_node *biggest);
void	update_index(t_node **stack, int size);
void	update_cost(t_node **stack, int target_stack_size, int stack_size);
void	update_cheapest(t_node **stack);
void	swap(t_node **stack, char c);
void	push(t_node **from, t_node **to, char c);
bool	rotate(t_node **stack, char c);
bool	reverse(t_node **stack, char c);
void	move_until_first(t_node **a, t_node **b, t_node *cur);
bool	move_both_stacks(t_node **a, t_node **b, char operation, bool checker);
int		list_size(t_node *stack);
t_node	*lst_new(long value);
void	lst_clear(t_node **lst, void (*del)(void *));
void	lst_add_back(t_node **lst, t_node *new);
t_node	*lst_last(t_node *lst);
t_node	*biggest_node(t_node *stack);

#endif
