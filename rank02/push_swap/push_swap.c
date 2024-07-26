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
        if (num > INT_MAX || num < INT_MIN || ft_strchr(argv, argv[i]))
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

int sort_list(node **a, node **b)
{
    int first;
    int last;
    bool sorted;

    first = (*a)->content;
    last = (*a)->content;
    sorted = false;
    while (sorted == false)
    {
        if (*b && (*b)->content < (*a)->content)
            push(b, a);
        if ((*a)->content < (*a)->next->content)
            rotate(a);
        else if ((*a)->content > (*a)->next->content)
            push(a, b);
        if ((*a)->content == first && (*b)->content == last)
            push(a, b);
        if (!*b)
            sorted = check_sort(a);
    }
}
bool    check_sort(node **a)
{
    while ((*a)->next)
    {
        if ((*a)->content > (*a)->next->content)
            return (false);
    }
    return (true);
}