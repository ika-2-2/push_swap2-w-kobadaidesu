#include "push_swap.h"

void	op_pa(t_context *ctx)
{
	if (!ctx->stack_b)
		return ;
	pa(&ctx->stack_a, &ctx->stack_b);
	count_operation(ctx, OP_PA);
}

void	op_pb(t_context *ctx)
{
	if (!ctx->stack_a)
		return ;
	pb(&ctx->stack_a, &ctx->stack_b);
	count_operation(ctx, OP_PB);
}
