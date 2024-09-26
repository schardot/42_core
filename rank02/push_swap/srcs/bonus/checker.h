/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:49:16 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/26 11:49:17 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../include/push_swap.h"

void	try_instructions(t_node **a, t_node **b, char *instructions);
void	free_all(t_node **a, t_node **b, char *instructions, int error);

#endif
