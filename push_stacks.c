/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:45:32 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:45:34 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!stack_b || !(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	add_front(stack_a, tmp);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	add_front(stack_b, tmp);
	if (print)
		write(1, "pb\n", 3);
}
