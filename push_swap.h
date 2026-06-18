#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

typedef struct s_bench
{
	int	flag;
	int	total;
	int	count[OP_COUNT];
}	t_bench;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_context
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_bench		bench;
	t_strategy	strategy;
	double		disorder;
}	t_context;

void				error_exit(void);
long				ft_atol(char *str);
void				error_check(char **args);
void				init_context(t_context *ctx);
char				**skip_options(char **argv, t_context *ctx);
char				**get_number_args(char **argv);
void				free_number_args(char **args, char **argv);
double				calc_disorder(t_stack *a);
t_stack				*init_stack(char **args);
void				coordinate_compress(t_stack *stack);
void				sort_by_strategy(t_context *ctx);
void				sort_simple(t_context *ctx);
void				sort_small(t_context *ctx);
void				sort_selection(t_context *ctx);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
size_t				find_min_pos(t_stack *stack);
void				move_min_to_top(t_context *ctx);
const char			*strategy_name(t_strategy strategy);
const char			*strategy_complexity(t_strategy strategy);
void				print_bench(t_context *ctx);
void				bench_putstr_err(const char *str);
void				bench_putnbr_err(int n);
void				bench_print_percent(double value);
void				bench_print_op_count(t_context *ctx, t_operation op,
						const char *name);
void				count_operation(t_context *ctx, t_operation op);
void				op_sa(t_context *ctx);
void				op_sb(t_context *ctx);
void				op_ss(t_context *ctx);
void				op_pa(t_context *ctx);
void				op_pb(t_context *ctx);
void				op_ra(t_context *ctx);
void				op_rb(t_context *ctx);
void				op_rr(t_context *ctx);
void				op_rra(t_context *ctx);
void				op_rrb(t_context *ctx);
void				op_rrr(t_context *ctx);

void				sa(t_stack **stack_a, int flg);
void				sb(t_stack **stack_b, int flg);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, int flg);
void				rb(t_stack **stack_b, int flg);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a, int flg);
void				rrb(t_stack **stack_b, int flg);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif
