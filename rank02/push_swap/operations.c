#include "push_swap.h"
#include "libft/libft.h"

void swap(t_list **stack, char c)
{
    long swap_helper;

    if (ft_lstsize(*stack) < 2)
        return ;
    if (stack && (*stack)->next)
    {
        swap_helper = (long)(*stack)->content;
        (*stack)->content = (*stack)->next->content;
        (*stack)->next->content = (void *)swap_helper;
        write(1, "s", 1);
        if (c == 'a' || c == 'b')
        {
            write(1, &c, 1);
            write(1, "\n", 1);
        }
    }
}

void swap_swap(t_list **a, t_list **b)
{
    swap(a, 's');
    swap(b, 's');
    write(1, "\n", 1);
}
void push(t_list **from, t_list **to, char c)
{
    t_list *aux;

    if (!from || !*from)
        return ;
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
        *from = (*from)->next;
        (*to)->next = aux;
    }
    write(1, "p", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}

bool rotate(t_list **stack, char c)
{
    t_list    *last;
    t_list    *first;

    if (!stack || !*stack || !(*stack)->next)
        return (false);
    first = *stack;
    last = ft_lstlast(*stack);
    *stack = (*stack)->next,
    last->next = first;
    first->next = NULL;
    write(1, "r", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
    return (true);
}

bool reverse(t_list **stack, char c)
{
    t_list    *last;
    t_list    *seclast;

    if (!stack || !*stack || !(*stack)->next)
        return (false);
    last = ft_lstlast(*stack);
    seclast = *stack;
    while (seclast->next != last)
        seclast = seclast->next;
    seclast->next = NULL;
    last->next = *stack;
    *stack = last;
    write(1, "rr", 2);
    write(1, &c, 1);
    write(1, "\n", 1);
    return (true);
}