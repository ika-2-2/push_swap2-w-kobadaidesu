#include "push_swap.h"

void	sort_simple(t_context *ctx)
{
	if (stack_size(ctx->stack_a) <= 5)
		sort_small(ctx);
}
