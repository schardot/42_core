#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct node{
    int content;
    struct node *next;
} node;

int push_swap(int argc, char **argv);
int check_argv(int argc, char *argv);
int array_to_list(int argc, char **argv, node **a);
int swap(node *stack);
int push(node **from, node **to);
bool rotate(node **stack);
bool reverse(node **stack);
