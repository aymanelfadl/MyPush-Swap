#include "push_swap.h"

int	abs_v(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	set_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > stack_size(tmp_b) / 2)
			tmp_b->cost_b = -(stack_size(tmp_b) - tmp_b->position);
		tmp_b->cost_a = tmp_b->target_position;
		if (tmp_b->target_position > stack_size(tmp_a) / 2)
			tmp_b->cost_a = -(stack_size(tmp_a) - tmp_b->target_position);
		tmp_b = tmp_b->next;
	}
}
void	rotate_stacks(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
    	(*cost_b)++;
	}
    while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	apply_op(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    rotate_stacks(a, b, &cost_a, &cost_b);
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
	pa(a, b);
}

void	shortest_path(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		shortest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	shortest = abs_v(tmp->cost_a) + abs_v(tmp->cost_b);
	cost_a = tmp->cost_a;
	cost_b = tmp->cost_b;
	tmp = tmp->next;
	while (tmp)
	{
		int current_cost = abs_v(tmp->cost_a) + abs_v(tmp->cost_b);
		if (current_cost < shortest)
		{
			shortest = current_cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	apply_op(a, b, cost_a, cost_b);
}


