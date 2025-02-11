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
void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	do_reverse_rotate_both(t_stack **a, t_stack **b, int *cost_a,
		int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	apply_op(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
		do_reverse_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
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
void shortest_path(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs_v(tmp->cost_a) + abs_v(tmp->cost_b) < abs_v(cheapest))
		{
			cheapest = abs_v(tmp->cost_b) + abs_v(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
    apply_op(a, b, cost_a, cost_b);
}


