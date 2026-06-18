/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:00:00 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_context(t_context *ctx)
{
	int	*count;
	int	*end;

	ctx->stack_a = NULL;
	ctx->stack_b = NULL;
	ctx->bench.flag = 0;
	ctx->bench.total = 0;
	count = ctx->bench.count;
	end = ctx->bench.count + OP_COUNT;
	while (count < end)
	{
		*count = 0;
		count++;
	}
	ctx->strategy = STRATEGY_ADAPTIVE;
	ctx->disorder = 0.0;
}

void	sort_by_strategy(t_context *ctx)
{
	if (ctx->strategy == STRATEGY_SIMPLE)
	{
		sort_simple(ctx);
	}
	else if (ctx->strategy == STRATEGY_MEDIUM)
	{
		sort_medium(ctx);
	}
	else if (ctx->strategy == STRATEGY_COMPLEX)
	{
		return ;
	}
	else
	{
		return ;
	}
}
