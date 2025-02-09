#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_stack *temp = stack;
    while (temp)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[])
{
    int i;
    char **args;

    i = 1;
    if (argc == 1)
        return 0;
    while (i < argc)
    {
        args = ft_split((const char *)argv[i], ' ');
        
    }
}




// int main(void)
// {
//     t_stack *stack_a = NULL;
//     t_stack *stack_b = NULL;

//     add_back(&stack_a, new_node(1));
//     add_back(&stack_a, new_node(2));
//     add_back(&stack_a, new_node(3));
//     add_back(&stack_a, new_node(4));

//     add_back(&stack_b, new_node(1));
//     add_back(&stack_b, new_node(2));
//     add_back(&stack_b, new_node(3));
//     add_back(&stack_b, new_node(4));

//     printf("Before {A}:\n");
//     print_stack(stack_a);
    
//     sa(&stack_a, 1);

//     printf("After {A}:\n");
//     print_stack(stack_a);
    
//     free_stack(stack_b);
//     free_stack(stack_a);

//     return 0;
// }
