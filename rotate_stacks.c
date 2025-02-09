#include "push_swap.h"

void ra(t_stack_a **stack_a)
{
    if (!*stack_a || !(*stack_a)->next)
        return ;
    add_back_a(stack_a, *stack_a);
    stack_a = &(*stack_a)->next;
    write(1, "ra\n", 3);
}
void rb(t_stack_b **stack_b)
{
    if (!*stack_b || !(*stack_b)->next)
        return ;
    add_back_b(stack_b, *stack_b);
    stack_b = &(*stack_b)->next;
    write(1, "rb\n", 3);
}

void rr(t_stack_a **stack_a, t_stack_b **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
