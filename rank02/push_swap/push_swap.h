#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

bool prep_check_argv(int argc, char **argv, long *biggest_number, long *smallest_number);
bool prep_array_to_list(int argc, char **argv, t_list **a);
void swap(t_list **stack, char c);
void push(t_list **from, t_list **to, char c);
bool rotate(t_list **stack, char c);
bool reverse(t_list **stack, char c);
bool check_sort(t_list *a);
void small_list(t_list **a, t_list **b, int size);
void size_three_list(t_list **a);
void size_four_list(t_list **a, t_list **b);
void size_five_list(t_list **a, t_list **b);
int digits_amount(int num);
void ft_radix_sort(t_list **a, t_list **b, int size, int amountdigits);
bool is_valid_number(char *arg);
bool duplicates_check(char **argv, int argc, char *current);
void ft_radix_sort_signed(t_list **a, t_list **b, int max_bits, long smallest_number);
void ft_reverse_list(t_list **list);

#endif