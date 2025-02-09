#include "push_swap.h"

t_stack    *new_node(int value)
{
    t_stack    *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void    add_front(t_stack **stack, t_stack *new_node)
{
    if (!stack || !new_node)
        return ;
    new_node->next = *stack;
    *stack = new_node;
}

void    add_back(t_stack **stack, t_stack *new_node)
{
    t_stack    *current;

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

void    free_stack(t_stack *stack)
{
    t_stack    *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int    stack_size(t_stack *stack)
{
    int        size;
    t_stack    *current;

    size = 0;
    current = stack;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}
