#include "push_swap.h"
#include "libft/libft.h"

int swap(node *stack)
{
    int swap_helper;

    swap_helper = stack->content;
    stack->content = stack->next->content;
    stack->next->content = swap_helper;
    return (true);
}

int push(node **from, node **to)
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
    return (true);
}

bool rotate(node **stack) //shift up by one
{
    node    *last;
    node    *first;

    if (!stack || !*stack || !(*stack)->next) // no rotation needed if the stack is empty or has only one element
        return (false);
    first = *stack;
    last = ft_lstlast(*stack);
    *stack = (*stack)->next,
    last->next = first;
    first->next = NULL;
    return (true);
}

bool reverse(node **stack) // shift down by one
{
    node    *last;
    node    *seclast;

    if (!stack || !*stack || !(*stack)->next) // no rotation needed if the stack is empty or has only one element
        return (false);
    last = ft_lstlast(*stack);
    seclast = *stack;
    while (seclast->next != last)
        seclast = seclast->next;
    seclast->next = NULL;
    last->next = *stack;
    *stack = last;
    return (true);
}