#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

bool is_valid_number(char *arg)
{
    char *str;

    str = arg;
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
        {
            printf("Error\n");
            exit(false);
        }
        str++;
    }
    return (true);
}

bool prep_check_argv(int argc, char **argv, long *biggest_number)
{
    int i;
    long num;
    char **copy;

    i = 1;
    while (i < argc)
    {
        is_valid_number(argv[i]);
        num = ft_atoi(argv[i]);
        copy = argv;
        while (*copy)
        {
            if (!duplicates_check(argv + i + 1, argv[i]) || num > INT_MAX || num < INT_MIN)
            {
                printf("Error\n");
                exit (false);
            }
            copy ++;
        }
        if (num > *biggest_number)
            *biggest_number = num;
        i++;
    }
    return (true);
}

bool prep_array_to_list(int argc, char **argv, t_list **a)
{
    int i;
    t_list *node_aux;

    i = 1;
    *a = ft_lstnew((void *)(long)ft_atoi(argv[i]));
    if (!*a)
        exit(false);
    i++;
    while (i < argc)
    {
        node_aux = ft_lstnew((void *)(long)ft_atoi(argv[i]));
        if (!node_aux)
        {
            ft_lstclear(a, free);
            exit(false);
        }
        ft_lstadd_back(a, node_aux);
        i++;
    }
    return (true);
}

bool duplicates_check(char **argv, char *current)
{
    char **copy_argv;

    copy_argv = argv;
    while (*copy_argv)
    {
        if (*copy_argv != current && ft_strncmp(*copy_argv, current, ft_strlen(*copy_argv)) == 0)
        {
            printf("Error\n");
            exit (false);
        }
        copy_argv ++;
    }
    return (true);
}
int digits_amount(int num)
{
    int i;

    i = 0;
    while (num >> i)
        i++;
    return (i);
}