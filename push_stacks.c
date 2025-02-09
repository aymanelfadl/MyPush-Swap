#include "push_swap.h"

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack    *tmp;
    
    if (!stack_b || !(*stack_b))
        return ;
    tmp = *stack_b;  
    *stack_b = (*stack_b)->next;  
    add_front(stack_a, tmp);
    write(1, "pa\n", 3);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack    *tmp;
    
    if (!stack_a || !(*stack_a))
        return ;
    tmp = *stack_a;  
    *stack_a = (*stack_a)->next;  
    add_front(stack_b, tmp);
    write(1, "pb\n", 3);
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

//     pa(&stack_a , &stack_b);
//     pa(&stack_a , &stack_b);
//     pa(&stack_a , &stack_b);
//     pa(&stack_a , &stack_b);
//     pa(&stack_a , &stack_b);
//     pa(&stack_a , &stack_b);
//     pa(&stack_a , &stack_b);

//     pb(&stack_a , &stack_b);
//     pb(&stack_a , &stack_b);
//     pb(&stack_a , &stack_b);
//     pb(&stack_a , &stack_b);
//     pb(&stack_a , &stack_b);
//     pb(&stack_a , &stack_b);
//     pb(&stack_a , &stack_b);


//     printf("After:\n");
//     printf("stack A:");
//     print_stack(stack_a);
//     printf("stack B:");
//     print_stack(stack_b);


//     free_stack(stack_a);
//     free_stack(stack_b);
// }