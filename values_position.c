/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:47:43 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:47:45 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

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
	t_stack	*target_node;
	int		target_pos;

	target_node = get_smallest_bigger_node(*a, stack_b_idx);
	if (target_node)
		return (target_node->position);
	target_pos = get_lowest_position(a);
	return (target_pos);
}

void	set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	set_position(stack_a);
	set_position(stack_b);
	while (tmp_b)
	{
		tmp_b->target_position = find_target_position(stack_a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}
