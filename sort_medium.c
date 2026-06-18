/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:22:05 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/18 23:22:06 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	root;

	root = 1;
	while (root <= n / root)
		root++;
	return (root - 1);
}

static int	get_chunk_size(int size)
{
	if (size <= 50)
		return (8);
	if (size <= 100)
		return (12);
	if (size <= 500)
		return (30);
	return (int_sqrt(size));
}

static void	push_chunks_to_b(t_context *ctx, int chunk_size)
{
	int	min;
	int	max;
	int	pos;
	int	pushed;

	min = 0;
	max = chunk_size - 1;
	while (ctx->stack_a)
	{
		pos = find_pos_in_range(ctx->stack_a, min, max);
		if (pos < 0)
		{
			min += chunk_size;
			max += chunk_size;
		}
		else
		{
			move_a_pos_to_top(ctx, pos);
			pushed = ctx->stack_a->index;
			op_pb(ctx);
			if (pushed < min + (chunk_size / 2))
				op_rb(ctx);
		}
	}
}

static void	push_back_to_a(t_context *ctx)
{
	int	pos;

	while (ctx->stack_b)
	{
		pos = find_max_pos(ctx->stack_b);
		move_b_pos_to_top(ctx, pos);
		op_pa(ctx);
	}
}

void	sort_medium(t_context *ctx)
{
	int	size;
	int	chunk_size;

	size = (int)stack_size(ctx->stack_a);
	chunk_size = get_chunk_size(size);
	push_chunks_to_b(ctx, chunk_size);
	push_back_to_a(ctx);
}
