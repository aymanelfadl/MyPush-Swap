/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:40:51 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/18 17:41:04 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "getNextLine/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// stacks utils
t_stack				*new_node(int value);
void				add_front(t_stack **stack, t_stack *new_node);
void				add_back(t_stack **stack, t_stack *new_node);
void				free_stack(t_stack *stack);
int					stack_size(t_stack *stack);
void				print_stack(t_stack *stack);

// operations
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				rb(t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);

// parsing functions:
void				args_parser(int argc, char *argv[], t_stack **stack_a);
long				my_atoi(const char *str);
void				error_cleanup(char **values, t_stack *stack_a);

// sorting functions:
void				set_index(t_stack **stack);
int					get_max_index(t_stack *stack);
int					is_sorted(t_stack *stack);
void				set_target_position(t_stack **stack_a, t_stack **stack_b);
void				set_cost(t_stack **a, t_stack **b);
void				shortest_path(t_stack **a, t_stack **b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					get_lowest_position(t_stack **stack);
t_stack				*get_smallest_bigger_node(t_stack *stack, int inde);

#endif
