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

