#include "push_swap.h"

static int	can_rotate(t_stack *stack)
{
	return (stack && stack->next != stack);
}

void	op_ra(t_context *ctx)
{
	if (!can_rotate(ctx->stack_a))
		return ;
	ra(&ctx->stack_a, 0);
	count_operation(ctx, OP_RA);
}

void	op_rb(t_context *ctx)
{
	if (!can_rotate(ctx->stack_b))
		return ;
	rb(&ctx->stack_b, 0);
	count_operation(ctx, OP_RB);
}

void	op_rr(t_context *ctx)
{
	if (!can_rotate(ctx->stack_a) && !can_rotate(ctx->stack_b))
		return ;
	rr(&ctx->stack_a, &ctx->stack_b);
	count_operation(ctx, OP_RR);
}
