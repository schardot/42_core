#include "push_swap.h"
#include "libft/libft.h"

int push_swap(int argc, char **argv)
{
    node  *a;
    node  *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (push_swap(?));
        //If no parameters are specified, the program must not display anything and give the prompt back.
    if (!check_argv(argc, argv))
        return (false);
    else
    {
        if (!array_to_list(argc, argv, &a))
            return (false);
        sort_list()
    }
}

int prep_check_argv(int argc, char *argv)
{
    int i;
    int num;

    i = 0;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (num > INT_MAX || num < INT_MIN || ft_strchr(argv, argv[i])) // ft_digit is not going to work, come back here later
        {
            ft_printf("Error\n");
            return (false);
        }
        i ++;
    }
    return (true);
}

int prep_array_to_list(int argc, char **argv, node **a)
{
    int i;
    node *node_aux;

    i = 1;
    *a = ft_lstnew(ft_atoi(argv[0]));
    if (!*a)
        return (false);
    while (i < argc - 1)
    {
        node_aux = ft_lstnew(ft_atoi(argv[i]));
            if(!node_aux)
            {
                ft_lstclear(a, free);
                return (false);
            }
        ft_lstadd_back(a, node_aux);
        i ++;
    }
    return (true);
}

int sort_list()
{
    //at this point:
    // 1. checked for errors
    // 2. transformed from array to linked list
    // 3. stack a is full
    // 4. stack b is empty
    // NOW ===
    // already wrote functions for the operations push swap rotate and reverse
    // its time to figure out how i want to do the sorting in the most efficient way
    // each time i do a move, print which move was it!
}