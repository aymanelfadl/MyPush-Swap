/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:44:10 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:44:13 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack **A, t_stack **B, char *op)
{
	free(op);
	free_stack(*A);
	free_stack(*B);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_moves(t_stack **A, t_stack **B, char *op)
{
	if (!ft_strncmp(op, "pa\n", 3))
		pa(A, B, 0);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(A, B, 0);
	else if (!ft_strncmp(op, "sa\n", 3))
		sa(A, 0);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(B, 0);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(A, B);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(A, 0);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(B, 0);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(A, B);
	else if (!ft_strncmp(op, "rra\n", 3))
		rra(A, 0);
	else if (!ft_strncmp(op, "rrb\n", 3))
		rrb(B, 0);
	else if (!ft_strncmp(op, "rrr\n", 3))
		rrr(A, B);
	else
		print_error(A, B, op);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operations;

	stack_a = NULL;
	stack_b = NULL;
	args_parser(argc - 1, &argv[1], &stack_a);
	operations = get_next_line(0);
	while (operations)
	{
		check_moves(&stack_a, &stack_b, operations);
		free(operations);
		operations = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
