#include "push_swap.h"

t_stack_a    *new_node_a(int value)
{
    t_stack_a    *node;

    node = (t_stack_a *)malloc(sizeof(t_stack_a));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void    add_front_a(t_stack_a **stack, t_stack_a *new_node)
{
    if (!stack || !new_node)
        return ;
    new_node->next = *stack;
    *stack = new_node;
}

void    add_back_a(t_stack_a **stack, t_stack_a *new_node)
{
    t_stack_a    *current;

    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;
}



void    free_stack_a(t_stack_a *stack)
{
    t_stack_a    *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}



int    stack_size_a(t_stack_a *stack)
{
    int        size;
    t_stack_a    *current;

    size = 0;
    current = stack;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}
