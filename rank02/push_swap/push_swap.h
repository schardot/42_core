#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

int main(int argc, char **argv);
bool prep_check_argv(int argc, char **argv, long *first, long *last);
bool prep_array_to_list(int argc, char **argv, t_list **a);
void swap(t_list *stack, char c);
void push(t_list **from, t_list **to, char c);
bool rotate(t_list **stack, char c);
bool reverse(t_list **stack, char c);
void sort_list(t_list **a, t_list **b, long first, long last);
bool check_sort(t_list **a);

#endif