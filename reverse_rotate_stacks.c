#include "push_swap.h"

void rra(t_stack_a **stack_a, int print)
{
    t_stack_a    *current;
    t_stack_a    *previous;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    current = *stack_a;
    while (current->next)
    {
        previous = current;
        current = current->next;
    }
    add_front_a(stack_a, current);
    previous->next = NULL;
    if (print)
        write(1, "rra\n", 4);
}
void   rrb(t_stack_b **stack_b, int print)
{
    t_stack_b    *current;
    t_stack_b    *previous;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    current = *stack_b;
    while (current->next)
    {
        previous = current;
        current = current->next;
    }
    add_front_b(stack_b, current);
    previous->next = NULL;
    if (print)
        write(1, "rrb\n", 4);
}
void   rrr(t_stack_a **stack_a, t_stack_b **stack_b)
{
    if (*stack_a && (*stack_a)->next)
        rra(stack_a, 0);
    if (*stack_b && (*stack_b)->next)
        rrb(stack_b, 0);
    write(1, "rr\n", 3);
}