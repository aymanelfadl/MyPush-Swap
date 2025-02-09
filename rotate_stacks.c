#include "push_swap.h"

void ra(t_stack_a **stack_a, int print)
{
    t_stack_a *first;

    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    first->next = NULL;
    add_back_a(stack_a, first);
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack_b **stack_b, int print)
{
    t_stack_b *first;

    if (!*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    *stack_b = (*stack_b)->next;
    first->next = NULL;
    add_back_b(stack_b, first);
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack_a **stack_a, t_stack_b **stack_b)
{
    if (*stack_a && (*stack_a)->next)
        ra(stack_a, 0);
    if (*stack_b && (*stack_b)->next)
        rb(stack_b, 0);
    write(1, "rr\n", 3);
}