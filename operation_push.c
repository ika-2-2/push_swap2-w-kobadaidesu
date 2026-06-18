/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/16 15:45:45 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_context *ctx)
{
	if (!ctx->stack_b)
		return ;
	pa(&ctx->stack_a, &ctx->stack_b, 0);
	count_operation(ctx, OP_PA);
}

void	op_pb(t_context *ctx)
{
	if (!ctx->stack_a)
		return ;
	pb(&ctx->stack_a, &ctx->stack_b, 0);
	count_operation(ctx, OP_PB);
}
