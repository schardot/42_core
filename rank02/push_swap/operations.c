#include "push_swap.h"
#include "libft/libft.h"

int swap(node *stack, char c)
{
    int swap_helper;

    swap_helper = stack->content;
    stack->content = stack->next->content;
    stack->next->content = swap_helper;
    write(1, 's', 1);
    write(1, &c, 1);
    return (true);
}

int push(node **from, node **to, char c)
{
    node    *aux;
    if (!*from)
        return ; //nothing to move, stack is empty
    if (!*to)
    {
        *to = *from;
        (*from) = (*from)->next;
        (*to)->next = NULL;
    }
    else
    {
        aux = *to;
        *to = *from;
        (*from) = (*from)->next;
        (*to)->next = aux;
    }
    write(1, 'p', 1);
    write(1, &c, 1);
    return (true);
}

bool rotate(node **stack, char c)
{
    node    *last;
    node    *first;

    if (!stack || !*stack || !(*stack)->next)
        return (false);
    first = *stack;
    last = ft_lstlast(*stack);
    *stack = (*stack)->next,
    last->next = first;
    first->next = NULL;
    write(1, 'r', 1);
    write(1, &c, 1);
    return (true);
}

bool reverse(node **stack, char c)
{
    node    *last;
    node    *seclast;

    if (!stack || !*stack || !(*stack)->next)
        return (false);
    last = ft_lstlast(*stack);
    seclast = *stack;
    while (seclast->next != last)
        seclast = seclast->next;
    seclast->next = NULL;
    last->next = *stack;
    *stack = last;
    write(1, 'rr', 2);
    write(1, &c, 1);
    return (true);
}