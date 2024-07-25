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
    }
}

int check_argv(int argc, char *argv)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (ft_isdigit(argv[i]) == 1 || ft_strchr(argv, argv[i]))
        {
            ft_printf("Error\n");
            return (false);
        }
        i ++;
    }
    return (true);
}

int array_to_list(int argc, char **argv, node **a)
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
    //tenho que free node_aux?
    return (true);
}
