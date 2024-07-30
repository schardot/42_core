#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    long first;
    long last;

    a = NULL;
    b = NULL;
    first = LONG_MAX;
    last = LONG_MIN;
    if (argc < 2)
        return (0);
    prep_check_argv(argc, argv, &first, &last);
    prep_array_to_list(argc, argv, &a);
    if (check_sort(a) == true)
    {
        ft_lstclear(&a, free);
        return (0);
    }
    sort_list(&a, &b, last);
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
        if (num > INT_MAX || num < INT_MIN || !ft_isdigit(argv[i][0] && argv[i][0] != '-'))
        {
            printf("Error\n"); //put my own implementation later
            exit (false);
        }
        i ++;
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
        exit (false);
    i ++;
    while (i < argc)
    {
        node_aux = ft_lstnew((void *)(long)ft_atoi(argv[i]));
        if (!node_aux)
        {
            ft_lstclear(a, free);
            exit (false);
        }
        ft_lstadd_back(a, node_aux);
        i ++;
    }
    return (true);
}

void    sort_list(t_list **a, t_list **b, long last)
{
    int max_digits;
    int i;
    int j;

    i = 0;
    max_digits = digits_amount(last);
    while (i < max_digits)
    {
        j = 0;
        while (j < ft_lstsize(*a))
        {
            if (((long)(*a)->content >> i) && 1)
                rotate(a, 'a');
            else
                push(a, b, 'b');
            j++;
        }
        while (*b)
            push(b, a, 'a');
        i++;
    }
}

bool check_sort(t_list *a)
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

int digits_amount(int num)
{
    int i;

    i = 0;
    while (num >> i)
        i++;
    return (i);
}
