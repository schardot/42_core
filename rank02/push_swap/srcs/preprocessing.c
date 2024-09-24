/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:58:10 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/24 16:26:52 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

bool	is_valid_number(char *arg)
{
	char	*str;

	str = arg;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf("Error\n");
			exit(false);
		}
		str++;
	}
	return (true);
}

bool check_argv(int argc, char **argv)
{
    int i;
    long num;
    char *itoa_r;

    i = 1;
    while (i < argc)
    {
        is_valid_number(argv[i]);
        num = ft_atoi(argv[i]);
        itoa_r = ft_itoa(num);
        duplicates_check(argv, argc, argv[i]);
        if (ft_strncmp(itoa_r, argv[i], ft_strlen(argv[i])) != 0) // Correct comparison
        {
            ft_printf("Error\n");
            exit(false);
        }
        i++;
    }
    return true;
}

void preprocessing(int argc, char **argv, t_node **a)
{
    char **arguments;
    int ac;

    ac = argc;
    arguments = argv;
    if (argc == 2)
        ac = argctwo(arguments[1]);
    check_argv(argc, arguments);
    create_populate_stack(a, ac, arguments);
}

void    create_populate_stack(t_node **a, int ac, char **arguments)
{
    int i;
    t_node *node_aux;

    *a = lst_new((long)ft_atoi(arguments[1]));
    if (!*a)
    {
        free_arguments(arguments);
        exit (1);
    }
    i = 2;
    while (i < ac)
    {
        node_aux = lst_new((long)ft_atoi(arguments[i]));
        if (!node_aux)
        {
            lst_clear(a, free);
            free_arguments(arguments);
            return ;
        }
        lst_add_back(a, node_aux);
        i++;
    }
    free_arguments(arguments);
}

bool	duplicates_check(char **args, int argc, char *cur)
{
	int		i;
	int		len_cur;
	int		len_i;
	bool	found_itself;

	len_cur = ft_strlen(cur);
	i = 1;
	found_itself = false;
	while (i < argc)
	{
		len_i = ft_strlen(args[i]);
		if (len_cur == len_i && ft_strncmp(args[i], cur, len_cur) == 0)
		{
			if (found_itself == true)
			{
				ft_printf("Error\n");
				exit(false);
			}
			found_itself = true;
		}
		i ++;
	}
	return (true);
}

int argumentcount(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
		i++;
	return (i);
}

int    argctwo(char *arguments)
{
    int ac;

    arguments = ft_split(arguments, ' ');
    if (!arguments)
    {
        ft_printf("Error: Could not split arguments.\n");
        exit (1);
    }
    ac = argumentcount(arguments);
    return (ac);
}

void    free_arguments(char **arguments)
{
    int i;

    i = 0;
    while(arguments[i])
    {
        free (arguments[i]);
        i ++;
    }
    free(arguments);
}