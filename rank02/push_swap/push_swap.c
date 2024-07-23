#include "push_swap.h"
#include "libft/libft.h"

int push_swap(int argc, char **argv)
{
    t_list  *a;

    a = NULL;
    //implementar error handling pra argc e argv
    if (is_stack_sorted(argc, argv))
        its already sorted, check later what to return;
    else
    {
        array_to_list(argc, argv, &a);
    }
}

int is_stack_sorted(int argc, char *argv)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (argv[i + 1] < argv[i])
            return (false);
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
