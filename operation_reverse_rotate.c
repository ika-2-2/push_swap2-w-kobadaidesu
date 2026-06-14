#include "push_swap.h"

static int	can_rotate(t_stack *stack)
{
	return (stack && stack->next != stack);
}

void	op_rra(t_context *ctx)
{
	if (!can_rotate(ctx->stack_a))
		return ;
	rra(&ctx->stack_a, 0);
	count_operation(ctx, OP_RRA);
}

void	op_rrb(t_context *ctx)
{
	if (!can_rotate(ctx->stack_b))
		return ;
	rrb(&ctx->stack_b, 0);
	count_operation(ctx, OP_RRB);
}

void	op_rrr(t_context *ctx)
{
	if (!can_rotate(ctx->stack_a) && !can_rotate(ctx->stack_b))
		return ;
	rrr(&ctx->stack_a, &ctx->stack_b);
	count_operation(ctx, OP_RRR);
}
