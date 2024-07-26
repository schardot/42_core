#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    long first;
    long last;

    a = NULL;
    b = NULL;
    first = LONG_MAX;
    last = LONG_MIN;
    if (argc < 2)
        return (0);
    if (!prep_check_argv(argc, argv, &first, &last))
        return (1);
    if (!prep_array_to_list(argc, argv, &a))
        return (1);
    sort_list(&a, &b, first, last);
    ft_lstclear((t_list **)&a, free);
    ft_lstclear((t_list **)&b, free);
    return (0);
}

bool prep_check_argv(int argc, char **argv, long *first, long *last)
{
    int i;
    long num;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (!*first && !*last)
        {
            *first = num;
            *last = num;
        }
        if (num < *first)
            *first = num;
        if (num > *last)
            *last = num;
        if (num > INT_MAX || num < INT_MIN || !ft_isdigit(argv[i][0]))
        {
            printf("Error\n"); //put my own implementation later
            return (false);
        }
        i ++;
    }
    return (true);
}

bool prep_array_to_list(int argc, char **argv, t_list **a)
{
    int i;
    t_list *node_aux;

    i = 2;
    *a = ft_lstnew((void *)(long)ft_atoi(argv[1]));
    if (!*a)
        return (false);
    while (i < argc)
    {
        node_aux = ft_lstnew((void *)(long)ft_atoi(argv[i]));
        if (!node_aux)
        {
            ft_lstclear(a, free);
            return (false);
        }
        ft_lstadd_back(a, node_aux);
        i ++;
    }
    return (true);
}

void sort_list(t_list **a, t_list **b, long first, long last)
{
    bool sorted;

    sorted = false;
    while (sorted == false)
    {
        if (*a && *b && (long)(*a)->content == first && (long)(*b)->content == last)
        {
            push(b, a, 'b');
            reverse(a, 'a');
        }
        else if (*b && (long)(*b)->content < (long)(*a)->content)
            push(b, a, 'b');
        else if ((long)(*a)->content < (long)(*a)->next->content)
            rotate(a, 'a');
        else if ((long)(*a)->content == last && (long)(*a)->next->content == first)
            reverse(a, 'a');
        else if ((long)(*a)->content > (long)(*a)->next->content)
        {
            push(a, b, 'a');
            rotate(a, 'a');
        }
        if (!*b)
            sorted = check_sort(a);
    }
}
bool    check_sort(t_list **a)
{
    t_list *aux;

    if (!a || !*a)
        return (true);
    aux = *a;
    while (aux->next)
    {
        if (*(int *)aux->content > *(int *)aux->next->content)
            return (false);
        aux = aux->next;
    }
    return (true);
}