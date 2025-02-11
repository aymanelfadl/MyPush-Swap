#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    int mid;
    int pushed;
    int size;

    size = stack_size(*stack_a);
    mid = size / 2;
    pushed = 0;
    while (pushed < mid && size > 3)
    {
        if ((*stack_a)->index < mid)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a, 1);
        size = stack_size(*stack_a); 
    }
    while (size > 3)
    {
        pb(stack_a, stack_b);
        size = stack_size(*stack_a);
    }
}


void	sort_three(t_stack **stack_a)
{
	int	max;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	max = get_max_index(*stack_a);
	if ((*stack_a)->index == max)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index == max)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*stack_a);
	lowest_pos = get_lowest_position(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack_a, 1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a, 1);
			lowest_pos--;
		}
	}
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_size(*stack_a) == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a, 1);
        return;
    }
    if (stack_size(*stack_a) == 3)
    {
        sort_three(stack_a);
        return;
    }
    push_to_stack_b(stack_a, stack_b);
    sort_three(stack_a);
    while (*stack_b)
    {
        set_target_position(stack_a, stack_b);
        set_cost(stack_a, stack_b);
        shortest_path(stack_a, stack_b);
    }
    if (!is_sorted(*stack_a))
        shift_stack(stack_a);
}

