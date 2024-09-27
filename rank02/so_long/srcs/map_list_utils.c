#include "../include/minilibx-linux/mlx.h"
#include "../include/so_long.h"
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

map_node *m_list_new(char letter)
{
    map_node *m;

    m = (map_node *)malloc(size_of(map_node));
    if (!m)
    {
        ft_printf("Couldn't make m_list_new");
        return (NULL);
    }
    m->letter = letter;
    m->count = 0;
    m->next = NULL;
    m->prev = NULL;
    return (m);
}

void m_listadd_back(map_node **lst, map_node *new)
{
    map_node *last;

    if (!new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);
    last->next = new;
    new->prev = last;
}

map_node *m_listlast(map_node *lst)
{
    map_node *aux;

    if (!lst)
        return (NULL);
    aux = lst;
    while (aux->next)
        aux = aux->next;
    return (aux);
}

map_node **m_list_init()
{
    map_node *head;

    head = m_list_new('1');
    m_listadd_back(&head, m_list_new('0'));
    m_listadd_back(&head, m_list_new('E'));
    m_listadd_back(&head, m_list_new('P'));
    m_listadd_back(&head, m_list_new('C'));
    return (&head);
}

void m_list_free(map_node *head)
{
    map_node *current;
    map_node *next_node;

    current = head;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}