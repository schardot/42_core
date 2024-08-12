#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct node
{
    long content;
    int index;
    int cost;
    bool first_half;
    bool cheapest; //entender melhor como usar
    struct node *target;
    struct node *next;
    struct node *prev;
} node;

bool is_valid_number(char *arg);
bool prep_check_argv(int argc, char **argv, long *biggest_number, long *smallest_number);
bool prep_array_to_list(int argc, char **argv, node **a);
bool duplicates_check(char **args, int argc, char *current);
bool check_sort(node *a);
void sort(node **a, node **b);
void update_stack(node **a, node **b);
void update_target(node *a, node **b);
void update_index(node **stack, int size);
void update_cost(node **stack, int target_stack_size, int stack_size);
void update_cheapest(node **stack);
void swap(node **stack, char c);
void push(node **from, node **to, char c);
bool rotate(node **stack, char c);
void move_until_first(node **a, node **b, node *cur);
bool move_both_stacks(node **a, node **b, char operation);
bool reverse(node **stack, char c);
int list_size(node *stack);
node    *lst_new(long content);
void    lst_clear(node **lst, void (*del)(void *));
void lst_add_back(node **lst, node *new);
node    *lst_last(node *lst);
void small_list(node **a, node **b, int size, int smallest, int biggest);
void size_three_list(node **a);
void size_five_list(node **a, node **b, int first, int last);
long biggest_node(node *stack);

#endif