/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:22:32 by nleite-s          #+#    #+#             */
/*   Updated: 2024/10/02 09:22:33 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*instructions;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	preprocessing(argc, argv, &a);
	if (a)
	{
		instructions = get_next_line(0);
		while (instructions != NULL)
		{
			try_instructions(&a, &b, instructions);
			free(instructions);
			instructions = get_next_line(0);
		}
		if (check_sort(a) && b == NULL)
			free_all(&a, &b, instructions, 0);
	}
	ft_printf("KO\n");
}

void	try_instructions(t_node **a, t_node **b, char *instructions)
{
	if (ft_strncmp(instructions, "sa\n", 3) == 0)
		swap(a, '-');
	else if (ft_strncmp(instructions, "sb\n", 3) == 0)
		swap(b, '-');
	else if (ft_strncmp(instructions, "pa\n", 3) == 0)
		push(b, a, '-');
	else if (ft_strncmp(instructions, "pb\n", 3) == 0)
		push(a, b, '-');
	else if (ft_strncmp(instructions, "ra\n", 3) == 0)
		rotate(a, '-');
	else if (ft_strncmp(instructions, "rb\n", 3) == 0)
		rotate(b, '-');
	else if (ft_strncmp(instructions, "rra\n", 4) == 0)
		reverse(a, '-');
	else if (ft_strncmp(instructions, "rrb\n", 4) == 0)
		reverse(b, '-');
	else if (ft_strncmp(instructions, "rrr\n", 4) == 0)
		move_both_stacks(a, b, 'e', true);
	else if (ft_strncmp(instructions, "rr\n", 3) == 0)
		move_both_stacks(a, b, 'o', true);
	else
		free_all(a, b, instructions, 1);
}

void	free_all(t_node **a, t_node **b, char *instructions, int error)
{
	if (a)
		lst_clear(a, &free);
	if (b)
		lst_clear(b, &free);
	if (instructions)
		free(instructions);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (error == 0)
	{
		ft_printf("OK\n");
		exit(1);
	}
}
