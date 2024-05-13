/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:21:50 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/13 13:21:52 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *head;

    head = (t_list *)malloc(sizeof(t_list));
    if (head == NULL)
        return (NULL);
    
    head->content = (void *)content;
    head->next = NULL;
    return (head);
}
