#include "push_swap.h"

void ra(t_stack **stack_a, int print)
{
    t_stack *first;

    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    first->next = NULL;
    add_back(stack_a, first);
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack **stack_b, int print)
{
    t_stack *first;

    if (!*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    *stack_b = (*stack_b)->next;
    first->next = NULL;
    add_back(stack_b, first);
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a && (*stack_a)->next)
        ra(stack_a, 0);
    if (*stack_b && (*stack_b)->next)
        rb(stack_b, 0);
    write(1, "rr\n", 3);
}

// void print_stack(t_stack *stack)
// {
//     t_stack *temp = stack;
//     while (temp)
//     {
//         printf("%d -> ", temp->value);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// int main ()
// {
//     t_stack *stack_a = new_node(1);

//     add_back(&stack_a, new_node(2));
//     add_back(&stack_a, new_node(3));
//     add_back(&stack_a, new_node(4));

//     t_stack *stack_b = new_node(10);

//     add_back(&stack_b, new_node(20));
//     add_back(&stack_b, new_node(30));
//     add_back(&stack_b, new_node(40));
    
//     printf("befor:\n");
//     printf("stack A: ");
//     print_stack(stack_a);
//     printf("stack B: ");
//     print_stack(stack_b);

//     // ra(&stack_a, 1);
//     // rb(&stack_b, 1);
//     rr(&stack_a, &stack_b);

//     printf("After:\n");
//     printf("stack A:");
//     print_stack(stack_a);
//     printf("stack B:");
//     print_stack(stack_b);


//     free_stack(stack_a);
//     free_stack(stack_b);
// }