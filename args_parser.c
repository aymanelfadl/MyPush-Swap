#include "push_swap.h"

int is_valide_number(char *value)
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

void create_value(char **values, t_stack **stack_a)
{
    int i;
    
    i = -1;
    if (!values)
        return;
    while (values[++i] != NULL)
    {
        if (is_valide_number(values[i]))
            add_back(stack_a, new_node(ft_atoi((const char *)values[i])));
        else
        {
            write(2, "Error\n", 6);
            while (values[i])
                free(values[i++]);
            free(values);
			free_stack(*stack_a);
            exit(EXIT_FAILURE);
        }
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
            write(2, "Error\n", 6);
            exit(1);
        }
        create_value(values, stack_a);
        i++;
    }
}