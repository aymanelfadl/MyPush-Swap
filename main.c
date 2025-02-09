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
int main()
{
    
}