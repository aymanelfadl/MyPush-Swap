/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:46:46 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:46:48 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	t_stack	*current;
	t_stack	*previous;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	current = *stack_a;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	add_front(stack_a, current);
	previous->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*current;
	t_stack	*previous;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	current = *stack_b;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	add_front(stack_b, current);
	previous->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		rra(stack_a, 0);
	if (*stack_b && (*stack_b)->next)
		rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
