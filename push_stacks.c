#include "push_swap.h"

void    pa(t_stack_a **stack_a, t_stack_b **stack_b)
{
    t_stack_b    *tmp_b;
    t_stack_a    *new;

    if (!stack_b || !(*stack_b))
        return ;
    new = new_node_a((*stack_b)->value);
    if (!new)
        return ;
    add_front_a(stack_a, new);
    tmp_b = *stack_b;
    *stack_b = (*stack_b)->next;
    free(tmp_b);
    write(1, "pa\n", 3);
}

void    pb(t_stack_a **stack_a, t_stack_b **stack_b)
{
    t_stack_a    *tmp_a;
    t_stack_b    *new;

    if (!stack_a || !(*stack_a))
        return ;
    new = new_node_b((*stack_a)->value);
    if (!new)
        return ;
    add_front_b(stack_b, new);
    tmp_a = *stack_a;
    *stack_a = (*stack_a)->next;
    free(tmp_a);
    write(1, "pb\n", 3);
}