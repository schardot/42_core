#include "push_swap.h"

void update_stack(node **a, node **b)
{
    int size_a;
    int size_b;

    size_a = list_size(*a);
    size_b = list_size(*b);
    update_index(a, size_a);
    update_target(*a, b);
    update_index(b, size_b);
    update_cost(b, size_a, size_b);
    if (b && *b)
        update_cheapest(b);
}

void update_target(node *stack_a, node **stack_b)
{
    node *b;
    node *a;
    long biggest;

    biggest = biggest_node(stack_a);
    b = *stack_b;
    while (b)
    {
        a = stack_a;
        while (a)
        {
            if (!(b)->target)
                (b)->target = a;
            if (((b)->content > biggest))
            {
                if (a->content < b->target->content)
                    (b)->target = (a);
            }
            else if ((a)->content > (b)->content)
            {
                if ((a)->content < (b)->target->content || (b)->target->content < (b)->content)
                    (b)->target = (a);
            }
            a = (a)->next;
        }
       b = (b)->next;
    }
}

void update_index(node **list, int size)
{
    int i;
    node *stack;
    stack = *list;

    i = 0;
    while (stack)
    {
        (stack)->index = i;
        if (i <= size/2)
            (stack)->first_half = true;
        else if (i <= size / 2 && size % 2 != 0)
            (stack)->first_half = true;
        else
            (stack)->first_half = false;
        stack = (stack)->next;
        i++;
    }
}

void update_cost(node **stack, int target_stack_size, int stack_size)
{
    int cost;
    node *b;

    b = *stack;
    while (b)
    {
        cost = 0;
        if (b->first_half)
            cost = b->index;
        else
            cost = stack_size - b->index;
        if (b->target->first_half)
            cost += b->target->index;
        else
            cost += target_stack_size - b->target->index;
        b->cost = cost;
        b = b->next;
    }
}

void update_cheapest(node **stack)
{
    long cheapest_cost;
    node *cheapest_node;
    node *b;

    b = *stack;
    if (!b)
        return;
    cheapest_cost = LONG_MAX;
    while (b)
    {
        if (b->cost < cheapest_cost)
        {
            cheapest_node = b;
            cheapest_cost = b->cost;
        }
        b = b->next;
    }
    cheapest_node->cheapest = true;
}

long biggest_node(node *stack)
{
    long i;

    i = LONG_MIN;
    while (stack)
    {
        if (stack->content > i)
            i = stack->content;
        stack = stack->next;
    }
    return (i);
}