#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct s_stack
{
    int                value;
    int                index;
    int                position;
    int                target_position;
    int                cost_a;
    int                cost_b;
    struct s_stack   *next;
}    t_stack;


// stacks utils 
t_stack			*new_node(int value);
void			add_front(t_stack **stack, t_stack *new_node);
void			add_back(t_stack **stack, t_stack *new_node);
void			free_stack(t_stack *stack);
int				stack_size(t_stack *stack);


// operations 
void    		pa(t_stack **stack_a, t_stack **stack_b);
void	    	pb(t_stack **stack_a, t_stack **stack_b);

void 			sa(t_stack **stack_a, int print);
void 			sb(t_stack **stack_b, int print);
void 			ss(t_stack **stack_a, t_stack **stack_b);

void 			rb(t_stack **stack_b, int print);
void 			ra(t_stack **stack_a, int print);
void 			rr(t_stack **stack_a, t_stack **stack_b);

void 			rra(t_stack **stack_a, int print);
void   			rrb(t_stack **stack_b, int print);
void   			rrr(t_stack **stack_a, t_stack **stack_b);


// parsing functions: 
void    args_parser(int  argc, char *argv[], t_stack **stack_a);
long    my_atoi(const char *str);
void    error_cleanup(char **values, t_stack *stack_a);

// sorting functions:
void    set_index(t_stack **stack);
void    push_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
int	    get_max_index(t_stack *stack);
void    set_target_position(t_stack **stack_a, t_stack **stack_b);
void    set_cost(t_stack **a, t_stack **b);
void	shortest_path(t_stack **a, t_stack **b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
int	    get_lowest_position(t_stack **stack);
int	    abs_v(int n);
t_stack *get_smallest_bigger_node(t_stack *stack, int inde);
void set_position(t_stack **stack);


#endif