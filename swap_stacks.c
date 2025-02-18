/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:47:30 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:47:33 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	int	print_a;
	int	print_b;

	print_a = 0;
	print_b = 0;
	if (*stack_a && (*stack_a)->next)
	{
		sa(stack_a, 0);
		print_a = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		sb(stack_b, 0);
		print_b = 1;
	}
	if (print && (print_a || print_b))
		write(1, "ss\n", 3);
}
