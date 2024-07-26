#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct node{
    int content;
    struct node *next;
} node;

int push_swap(int argc, char **argv);
int prep_check_argv(int argc, char *argv);
int prep_array_to_list(int argc, char **argv, node **a);
int swap(node *stack, char c);
int push(node **from, node **to, char c);
bool rotate(node **stack, char c);
bool reverse(node **stack, char c);
int sort_list(node **a, node **b);
bool check_sort(node **a);
