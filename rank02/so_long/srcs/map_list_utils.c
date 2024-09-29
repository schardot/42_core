#include "../include/minilibx-linux/mlx.h"
#include "../include/so_long.h"
#include "../include/libft/libft.h"
#include "../include/libft/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

t_map *t_map_new(char letter)
{
    t_map *m;

    m = (t_amp *)malloc(size_of(t_map));
    if (!m)
    {
        ft_printf("Couldn't make t_map_new");
        return (NULL);
    }
    m->hei = -1;
    m->wid = -1;
    m->n_e = -1;
    m->n_0 = -1;
    m->n_1 = -1;
    m->n_p = -1;
    m->n_c = -1;
    return (m);
}

void t_mapadd_back(t_map **lst, t_map *new)
{
    t_map *last;

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

t_map *t_maplast(t_map *lst)
{
    t_map *aux;

    if (!lst)
        return (NULL);
    aux = lst;
    while (aux->next)
        aux = aux->next;
    return (aux);
}

t_map **t_map_init()
{
    t_map *head;

    head = m_list_new('1');
    m_listadd_back(&head, m_list_new('0'));
    m_listadd_back(&head, m_list_new('E'));
    m_listadd_back(&head, m_list_new('P'));
    m_listadd_back(&head, m_list_new('C'));
    return (&head);
}

void t_map_free(map_node *head)
{
    t_map *current;
    t_map *next_node;

    current = head;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
