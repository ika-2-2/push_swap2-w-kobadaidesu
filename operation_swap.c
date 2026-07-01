/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/30 16:30:08 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_swap(t_stack *stack)
{
	return (stack && stack->next != stack);
}

void	op_sa(t_context *ctx)
{
	if (!can_swap(ctx->stack_a))
		return ;
	sa(&ctx->stack_a, ctx->bench.total_count_flg);
	count_operation(ctx, OP_SA);
}

void	op_sb(t_context *ctx)
{
	if (!can_swap(ctx->stack_b))
		return ;
	sb(&ctx->stack_b, ctx->bench.total_count_flg);
	count_operation(ctx, OP_SB);
}

void	op_ss(t_context *ctx)
{
	if (!can_swap(ctx->stack_a) && !can_swap(ctx->stack_b))
		return ;
	ss(&ctx->stack_a, &ctx->stack_b, ctx->bench.total_count_flg);
	count_operation(ctx, OP_SS);
}
