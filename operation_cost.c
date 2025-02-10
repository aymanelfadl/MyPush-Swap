#include "push_swap.h"

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