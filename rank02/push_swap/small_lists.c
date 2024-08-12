#include "push_swap.h"
#include "libft/libft.h"

void small_list(node **a, node **b, int size, int smallest, int biggest)
{
    if (size == 2 && !check_sort(*a))
        swap(a, 'a');
    else if (size == 3 && !check_sort(*a))
        size_three_list(a);
    else if (size == 5 && !check_sort(*a))
        size_five_list(a, b, smallest, biggest);
}

void size_three_list(node **a)
{
    while (!check_sort(*a))
    {
        if ((*a)->content > (*a)->next->content)
            swap(a, 'a');
        else
            reverse(a, 'a');
    }
}

void size_five_list(node **a, node **b, int first, int last)
{
    while (list_size(*a) > 2)
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

