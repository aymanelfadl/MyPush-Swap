#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_a
{
    int                value;
    struct s_stack_a    *next;
}    t_stack_a;

typedef struct s_stack_b
{
    int                value;
    struct s_stack_b    *next;
}    t_stack_b;

t_stack_a    *new_node_a(int value);
t_stack_b    *new_node_b(int value);
void        add_back_a(t_stack_a **stack, t_stack_a *new_node);
void        add_back_b(t_stack_b **stack, t_stack_b *new_node);
void        add_front_a(t_stack_a **stack, t_stack_a *new_node);
void        add_front_b(t_stack_b **stack, t_stack_b *new_node);

void        free_stack_a(t_stack_a *stack);
void        free_stack_b(t_stack_b *stack);
int         stack_size_a(t_stack_a *stack);
int         stack_size_b(t_stack_b *stack);
void        print_stack_a(t_stack_a *stack);
void        print_stack_b(t_stack_b *stack);

void        sa(t_stack_a **stack_a);
void        sb(t_stack_b **stack_b);
void        ss(t_stack_a **stack_a, t_stack_b **stack_b);
void        pa(t_stack_a **stack_a, t_stack_b **stack_b);
void        pb(t_stack_a **stack_a, t_stack_b **stack_b);
void        ra(t_stack_a **stack_a);
void        rb(t_stack_b **stack_b);
void        rr(t_stack_a **stack_a, t_stack_b **stack_b);
void        rra(t_stack_a **stack_a);
void        rrb(t_stack_b **stack_b);
void        rrr(t_stack_a **stack_a, t_stack_b **stack_b);



#endif