#include "push_swap.h"

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


void push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    int mid;
    int pushed;

    if (!stack_a || !*stack_a)
        return;

    if (stack_size(*stack_a) <= 3)
        return;

    mid = stack_size(*stack_a) / 2;
    pushed = 0;
    while (pushed < mid && stack_size(*stack_a) > 3)
    {
        if ((*stack_a)->index <= mid)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a, 1);
    }
    while (stack_size(*stack_a) > 3)
        pb(stack_a, stack_b);
}