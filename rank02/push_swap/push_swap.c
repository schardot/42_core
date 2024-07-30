#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    long biggest_number;

    a = NULL;
    b = NULL;
    biggest_number = LONG_MIN;
    if (argc < 2)
        return (0);
    prep_check_argv(argc, argv, &biggest_number);
    prep_array_to_list(argc, argv, &a);
    if (check_sort(a) == true)
    {
        ft_lstclear(&a, free);
        return (0);
    }
    ft_radix_sort(&a, &b, ft_lstsize(a), digits_amount(biggest_number));
    //ft_lstclear(a, free);
    return (0);
}


void ft_radix_sort(t_list **a, t_list **b, int size, int amountdigits)
{
    int mask;
    int counter;

    mask = 0;
    counter = 0;
    while (mask <= amountdigits)
    {
        mask++;
        while (counter < size)
        {
            if ((long)(*a)->content & mask)
                rotate(a, 'a');
            else
                push(a, b, 'b');
            counter++;
        }
        while (*b)
            push(b, a, 'a');
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

