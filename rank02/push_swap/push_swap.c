#include "push_swap.h"
#include "libft/libft.h"

int push_swap(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (NULL);
        //If no parameters are specified, the program must not display anything and give the prompt back.
    if (!check_argv(argc, argv))
        return (false);
    else
    {
        array_to_list(argc, argv, &a);
    }
}

int check_argv(int argc, char *argv)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (ft_isdigit(argv[i]) == 1 || ft_strchr(argv, argv[i]))
        {
            ft_printf("Error\n");
            return (false);
        }
        i ++;
    }
    return (true);
}

int array_to_list(int argc, char **argv, t_list **a)
{
    int i;
    t_list *node_aux;

    i = 1;
    a = ft_lstnew(argv[0]);
    while (i < argc - 1)
    {
        node_aux = ft_lstnew(argv[i]);
            if(!node_aux)
                return (NULL);
        ft_lstadd_back(a, node_aux);
        i ++;
    }
    return (i); //que vai ser quandos nodes tem na lista. nao sei se preciso
}
int swap(t_list *stack)
{
    int swap_helper;

    swap_helper = stack->content;
    stack->content = stack->next->content;
    stack->next->content = swap_helper;
}

int push(t_list **from, t_list **to)
{
    if (!to)
    {
        to = ft_lstnew(from->content);
        ft_lstdelone(from->next, free)
    }
}

int rotate()

int reverse()