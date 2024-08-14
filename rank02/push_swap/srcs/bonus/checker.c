/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:29:30 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/14 11:29:32 by nataliaschard    ###   ########.fr       */
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
	prep_check_argv(argc, argv);
	prep_array_to_list(argc, argv, &a);
	instructions = get_next_line(0);
	while (instructions != NULL)
	{
		try_instructions(&a, &b, instructions);
		free(instructions);
		instructions = get_next_line(0);
	}
	if (check_sort(a) && b == NULL)
	{
		ft_printf("OK\n");
		return (0);
	}
	ft_printf("KO\n");
	return (1);
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
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
