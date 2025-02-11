#include "push_swap.h"

void set_position(t_stack **stack)
{
    t_stack *temp;
    int i;

    temp = *stack;
    i = 0;
    while (temp)
    {
        temp->position = i;
        temp = temp->next;
        i++;
    }
}

int	get_lowest_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_position;

	tmp = *stack;
	lowest_index = tmp->index;
	set_position(stack);
	lowest_position = tmp->position;
    tmp = tmp->next;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_position);
}

int	find_target_position(t_stack **a, int stack_b_idx)
{
	t_stack	*tmp_a;
    int    target_idx;
    int    target_pos;

    target_idx = INT_MAX;
    target_pos = 0;
	tmp_a = *a;
	while (tmp_a)
	{
        if (get_smallest_bigger_node(*a, stack_b_idx)->index)
        {
            target_idx = get_smallest_bigger_node(*a, stack_b_idx)->index;
            target_pos = get_smallest_bigger_node(*a, stack_b_idx)->position;
        }
        tmp_a = tmp_a->next;
    }
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	set_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	set_position(a);
	set_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = find_target_position(a, tmp_b->index);
		tmp_b->target_position = target_pos;
		tmp_b = tmp_b->next;
	}
}
