#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

long my_atoi(const char *str)
{
    int     i;
    long    sum;
    int     si;

    si = 1;
    sum = 0;
    i = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            si *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        sum = sum * 10 + (str[i] - '0');
        if (sum > INT_MAX || sum < INT_MIN)
            return ((long)INT_MAX + 1);
        i++;
    }
    return (sum * si);
}

void error_cleanup(char **values, t_stack *stack_a)
{
    int i;

    write(2, "Error\n", 6);
    if (values)
    {
        i = 0;
        while (values[i])
            free(values[i++]);
        free(values);
    }
    if (stack_a)
        free_stack(stack_a);
    exit(EXIT_FAILURE);
}