/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:04:05 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/13 14:04:06 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;
    t_list *aux;

    aux = lst;
    i = 0;
    if (!lst)
        return (0);
    while (aux)
    {
        i++;
        aux = aux->next;
    }
    return (i);
}
