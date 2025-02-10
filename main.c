#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    
    if (argc < 2)
        return (1);
        
    stack_a = NULL;
    args_parser(argc - 1, &argv[1], &stack_a); 
    
    t_stack *temp = stack_a;
    while (temp)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }

    free_stack(stack_a);

    return (0);
}