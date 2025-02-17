#include "push_swap.h"

int has_value(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

static int is_valide_number(char *value)
{
    int i;
    
    i = 0;
    if (!value || !*value)
        return (0);
    if (value[i] == '-' || value[i] == '+')
        i++;
    if (!value[i])
        return (0);
    while (value[i] != '\0')
    {
        if (!ft_isdigit(value[i]))
            return (0);
        i++;
    }
    return (1);
}

static void create_value(char **values, t_stack **stack_a)
{
    int i;
    long value;

    i = -1;
    if (!values)
        return;
    while (values[++i] != NULL)
    {
        if (is_valide_number(values[i]))
        {
            value = my_atoi(values[i]);
            if (value > INT_MAX || value < INT_MIN)
                error_cleanup(values, *stack_a);
            if (!has_value(*stack_a, (int)value))
                add_back(stack_a, new_node((int)value));
            else
                error_cleanup(values, *stack_a);
        }
        else
            error_cleanup(values, *stack_a);
    }
    i = 0;
    while (values[i])
        free(values[i++]);
    free(values);
}

void args_parser(int argc, char *argv[], t_stack **stack_a)
{
    char **values;
    int i;

    i = 0;
    while (i < argc)
    {
        values = ft_split(argv[i], ' ');
        if (!values)
        {
            free(values);
            error_cleanup(NULL, *stack_a);
        }
        create_value(values, stack_a);
        i++;
    }
}