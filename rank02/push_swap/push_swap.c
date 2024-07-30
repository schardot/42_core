#include "push_swap.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    long first;
    long last;

    a = NULL;
    b = NULL;
    first = LONG_MAX;
    last = LONG_MIN;
    if (argc < 2)
        return (0);
    if (!prep_check_argv(argc, argv, &first, &last))
        return (1);
    if (!prep_array_to_list(argc, argv, &a))
        return (1);
    if (check_sort(a) == true)
    {
        ft_lstclear(&a, free);
        return (0);
    }
    sort_list(&a, &b, last);
    //ft_lstclear(a, free);
    return (0);
}

bool prep_check_argv(int argc, char **argv, long *first, long *last)
{
    int i;
    long num;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (!*first && !*last)
        {
            *first = num;
            *last = num;
        }
        if (num < *first)
            *first = num;
        if (num > *last)
            *last = num;
        if (num > INT_MAX || num < INT_MIN || !ft_isdigit(argv[i][0] && argv[i][0] != '-'))
        {
            printf("Error\n"); //put my own implementation later
            return (false);
        }
        i ++;
    }
    return (true);
}

bool prep_array_to_list(int argc, char **argv, t_list **a)
{
    int i;
    t_list *node_aux;

    i = 1;
    *a = ft_lstnew((void *)(long)ft_atoi(argv[i]));
    if (!*a)
        return (false);
    i ++;
    while (i < argc)
    {
        node_aux = ft_lstnew((void *)(long)ft_atoi(argv[i]));
        if (!node_aux)
        {
            ft_lstclear(a, free);
            return (false);
        }
        ft_lstadd_back(a, node_aux);
        i ++;
    }
    return (true);
}

void    sort_list(t_list **a, t_list **b, long last)
{
    int max_digits;
    int i;
    int j;

    i = 0;
    max_digits = digits_amount(last);
    while (i < max_digits)
    {
        j = 0;
        while (j < ft_lstsize(*a))
        {
            if (((long)(*a)->content >> i) && 1)
                rotate(a, 'a');
            else
                push(a, b, 'b');
            j++;
        }
        while (*b)
            push(b, a, 'a');
        i++;
    }
}

bool check_sort(t_list *a)
{
    t_list *aux;

    if (!a)
        return (true);
    aux = a;
    while (aux->next)
    {
        if ((long)aux->content > (long)aux->next->content)
            return (false);
        aux = aux->next;
    }
    return (true);
}

int digits_amount(int num)
{
    int i;

    i = 0;
    while (num >> i)
        i++;
    return (i);
}

void swap(t_list **stack, char c)
{
    long swap_helper;

    if (ft_lstsize(*stack) < 2)
        return;
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
        return;
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
    t_list *last;
    t_list *first;

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
    t_list *last;
    t_list *seclast;

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

// static int ft_isspace(int c);

// int ft_atoi(const char *nptr)
// {
//     int r;
//     int sign;

//     sign = 1;
//     r = 0;
//     while (ft_isspace(*nptr))
//         nptr++;
//     if (*nptr == '-' || *nptr == '+')
//     {
//         if (*nptr == '-')
//             sign = -1;
//         nptr++;
//     }
//     while (*nptr != '\0' && ft_isdigit(*nptr))
//     {
//         r = (r * 10) + (*nptr - '0');
//         nptr++;
//     }
//     r *= sign;
//     return (r);
// }

// static int ft_isspace(int c)
// {
//     if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')
//         return (1);
//     else if (c == '\v')
//         return (1);
//     else
//         return (0);
// }

// int ft_isdigit(int c)
// {
//     return (c >= '0' && c <= '9');
// }

// void ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list *last;

//     if (!new)
//         return;
//     if (!*lst)
//     {
//         *lst = new;
//         return;
//     }
//     last = ft_lstlast(*lst);
//     last->next = new;
// }

// void ft_lstclear(t_list **lst, void (*del)(void *))
// {
//     t_list *aux;

//     if (!del || !lst || !*lst)
//         return;
//     while (lst && *lst)
//     {
//         aux = (*lst)->next;
//         ft_lstdelone(*lst, del);
//         *lst = aux;
//     }
// }

// t_list *ft_lstlast(t_list *lst)
// {
//     t_list *aux;

//     if (!lst)
//         return (NULL);
//     aux = lst;
//     while (aux->next)
//         aux = aux->next;
//     return (aux);
// }

// t_list *ft_lstnew(void *content)
// {
//     t_list *head;

//     head = (t_list *)malloc(sizeof(t_list));
//     if (head == NULL)
//         return (NULL);
//     head->content = (void *)content;
//     head->next = NULL;
//     return (head);
// }

// void ft_lstdelone(t_list *lst, void (*del)(void
//                                                *))
// {
//     if (!lst)
//         return;
//     if (del)
//         del(lst->content);
//     free(lst);
// }

// int ft_lstsize(t_list *lst)
// {
//     int i;
//     t_list *aux;

//     aux = lst;
//     i = 0;
//     if (!lst)
//         return (0);
//     while (aux)
//     {
//         i++;
//         aux = aux->next;
//     }
//     return (i);
// }
