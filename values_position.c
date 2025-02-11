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

int find_target_index(t_stack **stack_a, int b_index)
{
    t_stack *temp;
    int target_index;

    temp = *stack_a;
    if (!temp)
        return (0);
    target_index = temp->index;
    while (temp)
    {
        if (temp->index > b_index && temp->index < target_index)
            target_index = temp->index;
        temp = temp->next;
    }
    if (target_index == (*stack_a)->index)
    {
        temp = *stack_a;
        target_index = temp->index;
        while (temp)
        {
            if (temp->index < target_index)
                target_index = temp->index;
            temp = temp->next;
        }
    }
    return (target_index);
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


int get_position_by_index(t_stack **stack, int index)
{
    t_stack *temp;

    temp = *stack;
    while (temp)
    {
        if (temp->index == index)
            return (temp->position);
        temp = temp->next;
    }
    return (0);
}

void set_target_position(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_b;
    t_stack *current_a;
    t_stack *target;
    int closest_bigger;

    current_b = *stack_b;
    while (current_b)
    {
        closest_bigger = INT_MAX;
        current_a = *stack_a;
        target = NULL;
        
        while (current_a)
        {
            if (current_a->index > current_b->index && 
                current_a->index < closest_bigger)
            {
                closest_bigger = current_a->index;
                target = current_a;
            }
            current_a = current_a->next;
        }
        
        if (!target)
        {
            current_a = *stack_a;
            closest_bigger = INT_MAX;
            while (current_a)
            {
                if (current_a->index < closest_bigger)
                {
                    closest_bigger = current_a->index;
                    target = current_a;
                }
                current_a = current_a->next;
            }
        }
        
        current_b->target_position = target->position;
        current_b = current_b->next;
    }
}