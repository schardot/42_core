#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    long biggest_number;
    long smallest_number;

    a = NULL;
    b = NULL;
    biggest_number = LONG_MIN;
    if (argc < 2)
        return (0);
    prep_check_argv(argc, argv, &biggest_number, &smallest_number);
    prep_array_to_list(argc, argv, &a);
    if (check_sort(a) == true)
    {
        //ft_lstclear(&a, free);
        return (0);
    }
    if (ft_lstsize(a) < 6)
    {
        small_list(&a, &b, ft_lstsize(a));
        return (0);
    }
    ft_radix_sort_signed(&a, &b, digits_amount(biggest_number), smallest_number);
    //ft_lstclear(a, free);
    return (0);
}


void ft_radix_sort(t_list **a, t_list **b, int size, int max_bits)
{
    int mask;
    int counter;
    int pushed;

    mask = 1;
    while (mask < (1 << max_bits))
    {
        counter = 0;
        pushed = 0;
        while (counter < size)
        {
            if (((long)(*a)->content & mask) == 0) // If the current bit is 0
            {
                push(a, b, 'b');
                pushed++;
            }
            else // If the current bit is 1
                rotate(a, 'a');
            counter++;
        }
        while (pushed > 0)
        {
            push(b, a, 'a');
            pushed --;
        }
        mask <<= 1;
    }
}

void ft_radix_sort_signed(t_list **a, t_list **b, int max_bits, long smallest_number)
{
    int size;

    size = ft_lstsize(*a);
    if (smallest_number < 0)
    {
        while (*a)
        {
            if ((long)(*a)->content < 0)
                push(a, b, 'b');
            else
                rotate(a, 'a');
        }
        ft_radix_sort(b, a, ft_lstsize(*b), max_bits);
        ft_reverse_list(b);
        ft_radix_sort(a, b, ft_lstsize(*a), max_bits);
        while (*b)
            push (b, a, 'a');
    }
    else
        ft_radix_sort(a, b, size, max_bits);
}

void ft_reverse_list(t_list **list)
{
    t_list *prev = NULL;
    t_list *current = *list;
    t_list *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
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

