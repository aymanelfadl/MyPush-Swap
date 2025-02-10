#include "push_swap.h"

int *stack_to_array(t_stack *stack)
{
    int *array;
    int i;

    i = 0;
    array = malloc(sizeof(int) * stack_size(stack));
    if (!array)
        return (NULL);
    while (stack)
    {
        array[i] = stack->value;
        stack = stack->next;
        i++;
    }
    return array;
}

void sort_array(int *array, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void set_index(t_stack **stack)
{
    t_stack *temp;
    int i;
    int *sorted_array;

    sorted_array = stack_to_array(*stack);
    sort_array(sorted_array, stack_size(*stack));
    temp = *stack;
    while (temp)
    {
        i = 0;
        while (temp->value != sorted_array[i])
            i++;
        temp->index = i;
        temp = temp->next;
    }
    free(sorted_array);
}