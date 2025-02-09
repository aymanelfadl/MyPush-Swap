#include "push_swap.h"

void print_stack_a(t_stack_a *stack)
{
    t_stack_a *temp = stack;
    while (temp)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void print_stack_b(t_stack_b *stack)
{
    t_stack_b *temp = stack;
    while (temp)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(void)
{
    t_stack_a *stack_a = NULL;
    t_stack_b *stack_b = NULL;

    add_back_a(&stack_a, new_node_a(1));
    add_back_a(&stack_a, new_node_a(2));
    add_back_a(&stack_a, new_node_a(3));
    add_back_a(&stack_a, new_node_a(4));

    printf("Before {A}:\n");
    print_stack_a(stack_a);
    
    sa(&stack_a, 1);

    printf("After {A}:\n");
    print_stack_a(stack_a);
    
    free_stack_b(stack_b);
    free_stack_a(stack_a);

    return 0;
}
