#include "push_swap.h"

int abs_v(int n)
{
    if (n < 0)
        return (n * -1);
    return (n);
}

void set_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    int size_a;
    int size_b;

    tmp_b = *stack_b;
    size_a = stack_size(*stack_a);
    size_b = stack_size(*stack_b);
    while (tmp_b)
    {
        if (tmp_b->position > size_b / 2)
            tmp_b->cost_b = -(size_b - tmp_b->position);
        else
            tmp_b->cost_b = tmp_b->position;

        if (tmp_b->target_position > size_a / 2)
            tmp_b->cost_a = -(size_a - tmp_b->target_position);
        else
            tmp_b->cost_a = tmp_b->target_position;
			
        tmp_b = tmp_b->next;
    }
}

void rotate_stack(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(stack_a, stack_b);
        (*cost_a)++;
        (*cost_b)++;
    }
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(stack_a, stack_b);
        (*cost_a)--;
        (*cost_b)--;
    }
}

void apply_op(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    rotate_stack(a, b, &cost_a, &cost_b);
    
    while (cost_b < 0)
    {
        rrb(b, 1);
        cost_b++;
    }
    while (cost_b > 0)
    {
        rb(b, 1);
        cost_b--;
    }
    while (cost_a < 0)
    {
        rra(a, 1);
        cost_a++;
    }
    while (cost_a > 0)
    {
        ra(a, 1);
        cost_a--;
    }
    pa(a, b, 1);
}


void shortest_path(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int shortest_path;
    int cost_a;
    int cost_b;
    int total_cost;

    tmp = *b;
    shortest_path = INT_MAX;
    cost_a = 0;
    cost_b = 0;
    while (tmp)
    {
        total_cost = abs_v(tmp->cost_a) + abs_v(tmp->cost_b);
        if (total_cost < shortest_path)
        {
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
            shortest_path = total_cost;
        }
        tmp = tmp->next;
    }
    apply_op(a, b, cost_a, cost_b);
}
