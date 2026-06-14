#include "push_swap.h"

void	sort_selection(t_context *ctx)
{
	while (stack_size(ctx->stack_a) > 5)
	{
		move_min_to_top(ctx);
		op_pb(ctx);
	}
	sort_small(ctx);
	while (ctx->stack_b)
		op_pa(ctx);
}
