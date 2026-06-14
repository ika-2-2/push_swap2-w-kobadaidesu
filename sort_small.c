#include "push_swap.h"

static void	sort_two(t_context *ctx)
{
	t_stack	*a;

	a = ctx->stack_a;
	if (a->index > a->next->index)
		op_sa(ctx);
}

static void	sort_three(t_context *ctx)
{
	int	top;
	int	mid;
	int	bot;

	top = ctx->stack_a->index;
	mid = ctx->stack_a->next->index;
	bot = ctx->stack_a->prev->index;
	if (top > mid && mid < bot && top < bot)
		op_sa(ctx);
	else if (top > mid && mid > bot)
	{
		op_sa(ctx);
		op_rra(ctx);
	}
	else if (top > mid && mid < bot && top > bot)
		op_ra(ctx);
	else if (top < mid && mid > bot && top < bot)
	{
		op_sa(ctx);
		op_ra(ctx);
	}
	else if (top < mid && mid > bot && top > bot)
		op_rra(ctx);
}

static void	sort_five(t_context *ctx)
{
	size_t	size;
	size_t	pushed;

	size = stack_size(ctx->stack_a);
	pushed = 0;
	while (size > 3)
	{
		move_min_to_top(ctx);
		op_pb(ctx);
		pushed++;
		size--;
	}
	sort_three(ctx);
	while (pushed > 0)
	{
		op_pa(ctx);
		pushed--;
	}
}

void	sort_small(t_context *ctx)
{
	size_t	size;

	size = stack_size(ctx->stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(ctx);
	else if (size == 3)
		sort_three(ctx);
	else if (size <= 5)
		sort_five(ctx);
}
