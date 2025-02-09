#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_a
{
    int	value;
    int	size;
    struct s_stack_a	*next;

}	t_stack_a;

typedef struct s_stack_b
{
    int	value;
    int	size;
    struct s_stack_b	*next;

}	t_stack_b;


#endif