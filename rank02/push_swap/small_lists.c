#include "push_swap.h"
#include "libft/libft.h"

void small_list(t_list **a, t_list **b, int size, int smallest, int biggest)
{
    if (size == 2 && !check_sort(*a))
        swap(a, 'a');
    else if (size == 3 && !check_sort(*a))
        size_three_list(a);
    else if (size == 4 && !check_sort(*a))
        size_four_list(a, b);
    else if (size == 5 && !check_sort(*a))
        size_five_list(a, b, smallest, biggest);
}

void size_three_list(t_list **a)
{
    while (!check_sort(*a))
    {
        if ((long)(*a)->content > (long)(*a)->next->content)
            swap(a, 'a');
        else
            reverse(a, 'a');
    }
}

void size_four_list(t_list **a, t_list **b)
{
    while (ft_lstsize(*a) > 2)
    {
        if ((long)(*a)->content > (long)(*a)->next->content)
            swap(a, 'a');
        else
            push(a, b, 'b');
    }
    if ((long)(*a)->content < (long)(*a)->next->content)
        swap(a, 'a');
    while (*b)
        push(b, a, 'a');
    reverse(a, 'a');
}

void size_five_list(t_list **a, t_list **b, int first, int last)
{
    while (ft_lstsize(*a) > 2)
    {
        if (*b && (*b)->next && (long)(*b)->content < (long)(*b)->next->content)
            swap(b, 'b');
        if ((long)(*a)->content == first || (long)(*a)->content == last)
            rotate(a, 'a');
        else if ((long)(*a)->content > (long)(*a)->next->content)
            swap(a, 'a');
        else
            push(a, b, 'b');
    }
    if ((long)(*b)->content < (long)(*b)->next->content)
        swap(b, 'b');
    push(b, a, 'a');
    push(b, a, 'a');
    push(b, a, 'a');
    reverse(a, 'a');
}

