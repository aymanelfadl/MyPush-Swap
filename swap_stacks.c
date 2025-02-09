#include "push_swap.h"

void sa(t_stack **stack_a, int print)
{
    t_stack *first;
    t_stack *second;

    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    second = (*stack_a)->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    if (print)
        write(1, "sa\n", 3);
}

void sb(t_stack **stack_b, int print)
{
    t_stack *first;
    t_stack *second;

    if (!*stack_b || !(*stack_b)->next)
        return;

    first = *stack_b;
    second = (*stack_b)->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;

    if (print)
        write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    int print_a;
    int print_b;

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
    if (print_a || print_b)
        write(1, "ss\n", 3);
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

//     sa(&stack_a, 1);
//     ss(&stack_a, &stack_b);
//     printf("After:\n");
//     printf("stack A:");
//     print_stack(stack_a);
//     printf("stack B:");
//     print_stack(stack_b);


//     free_stack(stack_a);
//     free_stack(stack_b);
// }