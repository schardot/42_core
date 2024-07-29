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
    if (check_sort(a) == true)
        return (0);
    sort_list(&a, &b, first, last);
    //ft_lstclear(a, free);
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

    if (ft_lstsize(*a) < 6)
    {
        small_list(a, b, first, last);
        return ;
    }
    sorted = false;
    while (sorted == false)
    {
        while (ft_lstsize(*a) > 2)
        {
            if ((long)(*a)->content == first || (long)(*a)->content == last)
                rotate(a, 'a');
            else
                push(a, b, 'b');
        }
        if ((long)(*a)->content == first)
            rotate(a, 'a');
        while(*b)
        {
            if (!(*b)->next)
                push(b, a, 'a');
            else if (*b && (long)(*b)->content < (long)(*b)->next->content)
                swap(b, 'b');
            else if (*b && (long)(*b)->content < (long)(*a)->content && (*b)->content > ft_lstlast(*a)->content)
                push(b, a, 'a');
            else
                rotate(a, 'a');
        }
        reverse(a, 'a');
        sorted = check_sort(*a);
    }
    return ;
}

bool    check_sort(t_list *a)
{
    t_list *aux;

    if (!a)
        return (true);
    aux = a;
    while (aux->next)
    {
        if ((long)aux->content > (long)aux->next->content)
            return (false);
        aux = aux->next;
    }
    return (true);
}
