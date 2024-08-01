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

bool prep_check_argv(int argc, char **argv, long *biggest_number, long *smallest_number)
{
    int i;
    long num;
    char *itoa_r;
    //char **copy;

    i = 1;
    while (i < argc)
    {
        is_valid_number(argv[i]);
        num = ft_atoi(argv[i]);
        itoa_r = ft_itoa(num);
        if (ft_strncmp(itoa_r, argv[i], ft_strlen(argv[i]) != 0))
        {
            printf("Out of bounds for int\n");
            exit(false);
        }
        //copy = argv;
        // while (*copy)
        // {
            if (!duplicates_check(argv, argc, argv[i]))
            {
                printf("Error\n");
                exit (false);
            }
            //copy ++;
       // }
        if (num > *biggest_number)
            *biggest_number = num;
        if (num < *smallest_number)
            *smallest_number = num;
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

bool duplicates_check(char **args, int argc, char *current)
{
    int i;
    int len_current;
    int len_i;
    bool found_itself;

    len_current = ft_strlen(current);
    i = 2;
    found_itself = false;
    while (i < argc)
    {
        len_i = ft_strlen(args[i]);
        if (len_current == len_i && ft_strncmp(args[i], current, len_current) == 0)
        {
            if (found_itself == true)
            {
                printf("Error duplicate\n");
                exit(false);
            }
            found_itself = true;
        }
        i ++;
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