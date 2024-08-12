#include "push_swap.h"
#include "libft/libft.h"

void swap(node **stack, char c)
{
    long swap_helper;

    if (list_size(*stack) < 2)
        return ;
    if (stack && (*stack)->next)
    {
        swap_helper = (*stack)->content;
        (*stack)->content = (*stack)->next->content;
        (*stack)->next->content = swap_helper;
        if (c == 'a' || c == 'b')
            printf("s%c\n", c);
    }
}

void push(node **from, node **to, char c)
{
    node *aux;

    if (!from || !*from)
        return ;
    if (!*to)
    {
        *to = *from;
        (*from) = (*from)->next;
        (*to)->next = NULL;
        (*from)->prev = NULL;
    }
    else
    {
        aux = *to;
        *to = *from;
        if ((*from)->next)
        {
            *from = (*from)->next;
            (*to)->next->prev = NULL;
        }
        else
            *from = NULL;
        (*to)->next = aux;
        (*to)->next->prev = (*to);
    }
    printf("p%c\n", c);
}

bool rotate(node **stack, char c)
{
    node    *last;
    node    *first;

    if (!stack || !*stack || !(*stack)->next)
        return (false);
    first = *stack;
    last = lst_last(*stack);
    *stack = (*stack)->next;
    last->next = first;
    first->next = NULL;
    first->prev = last;
    (*stack)->prev = NULL;
    printf("r");
    if (c == 'a' || c == 'b')
        printf("%c\n", c);
    return (true);
}

bool move_both_stacks(node **a, node **b, char  operation)
{
    if (operation == 'o')
    {
        if (rotate(a, 'x') && rotate(b, 'x'))
        {
            printf("\n");
            return (true);
        }
    }
    else if (operation == 'e')
    {
        if (reverse(a, 'x') && reverse(b, 'x'))
        {
            printf("rrr\n");
            return (true);
        }
    }
    return (false);
}
bool reverse(node **stack, char c)
{
    node    *last;
    node    *seclast;

    if (!stack || !*stack || !(*stack)->next)
        return (false);
    last = lst_last(*stack);
    seclast = *stack;
    while (seclast->next != last)
        seclast = seclast->next;
    seclast->next = NULL;
    last->next = *stack;
    *stack = last;
    (*stack)->next->prev = (*stack);
    (*stack)->prev = NULL;
    if (c == 'a' || c == 'b')
        printf("rr%c\n", c);
    return (true);
}
