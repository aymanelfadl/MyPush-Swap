#include "push_swap.h"

t_stack_b    *new_node_b(int value)
{
    t_stack_b    *node;

    node = (t_stack_b *)malloc(sizeof(t_stack_b));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void    add_front_b(t_stack_b **stack, t_stack_b *new_node)
{
    if (!stack || !new_node)
        return ;
    new_node->next = *stack;
    *stack = new_node;
}

void    add_back_b(t_stack_b **stack, t_stack_b *new_node)
{
    t_stack_b    *current;

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

int    stack_size_b(t_stack_b *stack)
{
    int        size;
    t_stack_b    *current;

    size = 0;
    current = stack;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}
void    free_stack_b(t_stack_b *stack)
{
    t_stack_b    *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}