#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bench
{
	int total;
	int count[OP_COUNT];
}	t_bench

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				error_exit(void);
long				ft_atol(char *str);
void				error_check(char **args);
t_stack				*init_stack(char **args);

#endif
