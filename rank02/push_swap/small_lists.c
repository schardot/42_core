#include "push_swap.h"
#include "libft/libft.h"

void small_list(t_list **a, t_list **b, int size)
{
    if (size == 2 && !check_sort(*a))
        swap(a, 'a');
    else if (size == 3 && !check_sort(*a))
        size_three_list(a);
    else if (size == 4 && !check_sort(*a))
        size_four_list(a, b);
    else if (size == 5 && !check_sort(*a))
        size_five_list(a, b);
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
    {
        push(b, a, 'a');
        // if (*b && !(*b)->next)
        //     push(b, a, 'a');
        // else if (*b && (long)(*b)->content < (long)(*b)->next->content)
        //     swap(b, 'b');
        // else if (*b && (long)(*b)->content < (long)(*a)->content)
        //     push(b, a, 'a');
    }
    reverse(a, 'a');
}

void size_five_list(t_list **a, t_list **b)
{
    while (ft_lstsize(*a) > 3)
    {
        if ((long)(*a)->content > (long)(*a)->next->content)
            swap(a, 'a');
        else
            push(a, b, 'b');
    }
    size_three_list(a);
    if ((long)(*b)->content < (long)(*b)->next->content)
        swap(b, 'b');
    push(b, a, 'a');
    push(b, a, 'a');
}

