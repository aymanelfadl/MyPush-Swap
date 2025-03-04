/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:44:55 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:44:57 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		printf("value: %d -> ", temp->value);
		printf("index: %d -> ", temp->index);
		printf("position: %d -> ", temp->position);
		printf("target_position: %d -> ", temp->target_position);
		printf("cost_a: %d -> ", temp->cost_a);
		printf("cost_b: %d -> ", temp->cost_b);
		printf("\n");
		temp = temp->next;
	}
	printf("NULL\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	args_parser(argc - 1, &argv[1], &stack_a);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	set_index(&stack_a);
	set_index(&stack_b);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
