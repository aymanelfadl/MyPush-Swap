#include "push_swap.h"

void set_position(t_stack **stack)
{
    t_stack *temp;
    int i;

    temp = *stack;
    i = 0;
    while (temp)
    {
        temp->position = i;
        temp = temp->next;
        i++;
    }
}

int find_target_index(t_stack **stack_a, int b_index)
{
    t_stack *temp;
    int target_index;

    temp = *stack_a;
    if (!temp)
        return (0);
    target_index = temp->index;
    while (temp)
    {
        if (temp->index > b_index && temp->index < target_index)
            target_index = temp->index;
        temp = temp->next;
    }
    if (target_index == (*stack_a)->index)
    {
        temp = *stack_a;
        target_index = temp->index;
        while (temp)
        {
            if (temp->index < target_index)
                target_index = temp->index;
            temp = temp->next;
        }
    }
    return (target_index);
}

int get_position_by_index(t_stack **stack, int index)
{
    t_stack *temp;

    temp = *stack;
    while (temp)
    {
        if (temp->index == index)
            return (temp->position);
        temp = temp->next;
    }
    return (0);
}

void set_target_position(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    int target_index;

    tmp_b = *stack_b;
    set_position(stack_a);
    set_position(stack_b);
    target_index = 0;
    while (tmp_b)
    {
        target_index = find_target_index(stack_a, tmp_b->index);
        tmp_b->target_position = target_index;
        tmp_b = tmp_b->next;
    }
}