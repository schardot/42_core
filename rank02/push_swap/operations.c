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
        if (c == 'a' || c == 'b')
            ft_printf("s%c\n", c);
    }
}

void swap_swap(t_list **a, t_list **b)
{
    swap(a, 's');
    swap(b, 's');
    ft_printf("\n");
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
    ft_printf("P%c\n", c);
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
    ft_printf("r%c\n", c);
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
    ft_printf("rr%c\n", c);
    return (true);
}