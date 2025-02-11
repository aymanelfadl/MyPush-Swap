#include "push_swap.h"

static int *stack_to_array(t_stack *stack)
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

static void sort_array(int *array, int size)
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

int	get_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

t_stack *get_smallest_bigger_node(t_stack *stack, int index)
{
    t_stack *smallest_bigger_node;

    smallest_bigger_node = NULL;
    while (stack)
    {
        if (stack->index > index && (!smallest_bigger_node || stack->index < smallest_bigger_node->index))
            smallest_bigger_node = stack;
        stack = stack->next;
    }
    return smallest_bigger_node;
}