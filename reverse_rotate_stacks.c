#include "push_swap.h"

void rra(t_stack **stack_a, int print)
{
    t_stack    *current;
    t_stack    *previous;

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
void   rrb(t_stack **stack_b, int print)
{
    t_stack    *current;
    t_stack    *previous;

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
void   rrr(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a && (*stack_a)->next)
        rra(stack_a, 0);
    if (*stack_b && (*stack_b)->next)
        rrb(stack_b, 0);
    write(1, "rrr\n", 3);
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

//     // rra(&stack_a, 1);
//     // rrb(&stack_b, 1);
//     rrr(&stack_a, &stack_b);

//     printf("After:\n");
//     printf("stack A:");
//     print_stack(stack_a);
//     printf("stack B:");
//     print_stack(stack_b);


//     free_stack(stack_a);
//     free_stack(stack_b);
// }