#include "push_swap.h"

int main(int argc, char **argv)
{
    node *a;
    node *b;
    long biggest_number;
    long smallest_number;

    a = NULL;
    b = NULL;
    biggest_number = LONG_MIN;
    smallest_number = LONG_MAX;
    if (argc < 2)
        return (0);
    prep_check_argv(argc, argv, &biggest_number, &smallest_number);
    prep_array_to_list(argc, argv, &a);
    if (check_sort(a) == true)
    {
        // ft_lstclear(&a, free);
        return (0);
    }
    if (list_size(a) < 6)
    {
        small_list(&a, &b, list_size(a), smallest_number, biggest_number);
        return (0);
    }
    sort(&a, &b);
    return (0);
}

void sort(node **a, node **b)
{
    node* cur;
    bool sorted;

    sorted = false;
    while (list_size(*a) > 3)
        push(a, b, 'b');
    size_three_list(a);
    while (!sorted || !b)
    {
        while (!*b && !sorted)
        {
            rotate(a, 'a');
            sorted = check_sort(*a);
        }
        if (sorted)
            return ;
        update_stack(a, b);
        cur = (*b);
        while (cur->next && !cur->cheapest)
            cur = cur->next;
        move_until_first(a, b, cur);
        push(b, a, 'a');
        if (check_sort(*a) && !*b)
            sorted = true;
    }
}

void move_until_first(node **a, node **b, node *cur)
{
    // while (cur->index > 0 && cur->target->index > 0) // if they are both not first
    // {
    //     if (cur->first_half && cur->target->first_half) // if they are both first half
    //         move_both_stacks(a, b, 'o');
    //     else if (!cur->first_half && !cur->target->first_half) // if they are both NOT first half
    //         move_both_stacks(a, b, 'e');
    //     update_index(a, list_size(*a));
    //     update_index(b, list_size(*b));
    // }
    bool c_half;
    bool t_half;

    while ((cur->index > 0 || cur->target->index > 0))
    {
        c_half = cur->first_half;
        t_half = cur->target->first_half;
        if (cur->index > 0 && cur->target->index > 0 && c_half == t_half)
        {
            if (cur->first_half && cur->target->first_half) // if they are both first half
                move_both_stacks(a, b, 'o');
            else if (!cur->first_half && !cur->target->first_half) // if they are both NOT first half
                move_both_stacks(a, b, 'e');
        }
        else if (cur->index > 0 && cur->first_half)
            rotate(b, 'b');
        else if (cur->index > 0 && !cur->first_half)
            reverse(b, 'b');
        else if (cur->target->index > 0 && cur->target->first_half)
            rotate(a, 'a');
        else if (cur->target->index > 0 && !cur->target->first_half)
            reverse(a, 'a');
        update_index(a, list_size(*a));
        update_index(b, list_size(*b));
    }
}
