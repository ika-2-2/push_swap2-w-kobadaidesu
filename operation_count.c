#include "push_swap.h"

void	count_operation(t_context *ctx, t_operation op)
{
	if (!ctx->bench.flag)
		return ;
	ctx->bench.total++;
	ctx->bench.count[op]++;
}
