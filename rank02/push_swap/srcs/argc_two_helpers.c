/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_two_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:36:39 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/25 10:36:40 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	argumentcount(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	argctwo(char ***arguments)
{
	int	ac;

	*arguments = ft_split(**arguments, ' ');
	if (!*arguments)
	{
		ft_printf("Error: Could not split arguments.\n");
		exit(1);
	}
	ac = argumentcount(*arguments);
	return (ac);
}

void	free_arguments(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
