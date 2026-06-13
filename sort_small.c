#include "push_swap.h"

static void	sort_two(t_context *ctx)
{
	t_stack	*a;

	a = ctx->stack_a;
	if (a->index > a->next->index)
		sa(&ctx->stack_a, 0);
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
		sa(&ctx->stack_a, 0);
	else if (top > mid && mid > bot)
	{
		sa(&ctx->stack_a, 0);
		rra(&ctx->stack_a, 0);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(&ctx->stack_a, 0);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(&ctx->stack_a, 0);
		ra(&ctx->stack_a, 0);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(&ctx->stack_a, 0);
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
		pb(&ctx->stack_a, &ctx->stack_b);
		pushed++;
		size--;
	}
	sort_three(ctx);
	while (pushed > 0)
	{
		pa(&ctx->stack_a, &ctx->stack_b);
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
