#include "push_swap.h"

int list_size(node *stack)
{
    int i;

    i = 1;
    while (stack->next)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

node    *lst_new(long content)
{
    node    *head;
    head = (node *)malloc(sizeof(node));
    if (!head)
        return (NULL);
    head->content = content;
    head->index = INT_MIN;
    head->cost = INT_MIN;
    head->first_half = NULL;
    head->cheapest = NULL;
    head->target = NULL;
    head->next = NULL;
    head->prev = NULL;
    return (head);
}

void    lst_clear(node **lst, void (*del)(void *))
{
    node *aux;

    if (!del || !lst || !*lst)
        return;
    while (lst && *lst)
    {
        aux = (*lst)->next;
        del((void *)(*lst)->content);
        free (*lst);
        *lst = aux;
    }
}

void    lst_add_back(node **lst, node *new)
{
    node *last;

    if (!new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    last = lst_last(*lst);
    last->next = new;
    new->prev = last;
}

node    *lst_last(node *lst)
{
    node *aux;

    if (!lst)
        return (NULL);
    aux = lst;
    while (aux->next)
        aux = aux->next;
    return (aux);
}