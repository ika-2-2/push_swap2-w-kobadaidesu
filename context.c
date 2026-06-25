/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:44:06 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/18 23:44:07 by dakobaya         ###   ########.fr       */
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
	ctx->active_strategy = STRATEGY_ADAPTIVE;
	ctx->disorder = 0.0;
}

static t_strategy	select_adaptive_strategy(double disorder)
{
	if (disorder < 0.2)
		return (STRATEGY_SIMPLE);
	if (disorder < 0.5)
		return (STRATEGY_MEDIUM);
	return (STRATEGY_COMPLEX);
}

static t_strategy	select_strategy(t_context *ctx)
{
	if (ctx->strategy == STRATEGY_ADAPTIVE)
		return (select_adaptive_strategy(ctx->disorder));
	return (ctx->strategy);
}

void	sort_by_strategy(t_context *ctx)
{
	size_t	size;

	ctx->active_strategy = select_strategy(ctx);
	if (stack_is_sorted(ctx->stack_a))
		return ;
	size = stack_size(ctx->stack_a);
	if (size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	if (ctx->active_strategy == STRATEGY_SIMPLE)
	{
		sort_simple(ctx);
	}
	else if (ctx->active_strategy == STRATEGY_MEDIUM)
	{
		sort_medium(ctx);
	}
	else if (ctx->active_strategy == STRATEGY_COMPLEX)
	{
		sort_complex(ctx);
	}
}
