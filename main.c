#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_stack *temp = stack;
    while (temp)
    {
        printf("value: %d -> ", temp->value);
        printf("index: %d -> ", temp->index);
        printf("\n");
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    
    if (argc == 1)
        return 0;
    args_parser(argc - 1, &argv[1], &stack_a);
    set_index(&stack_a);
    push_to_stack_b(&stack_a, &stack_b);
    sort_three(&stack_a);
    printf("stack_a:\n");
    print_stack(stack_a);
    printf("stack_b:\n");
    print_stack(stack_b);

    
}
