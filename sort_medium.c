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

static int	get_chunk_size(int size)
{
	int	root;

	root = 1;
	while (root <= size / root)
	{
		if (root * root >= size)
			return (root * 2);
		root++;
	}
	return (root * 2);
}

static int	is_in_range(int index, int min, int max)
{
	return (index >= min && index <= max);
}

static void	push_chunk_to_b(t_context *ctx, int min, int max)
{
	int	checked;
	int	size;

	checked = 0;
	size = (int)stack_size(ctx->stack_a);
	while (checked < size)
	{
		if (is_in_range(ctx->stack_a->index, min, max))
			op_pb(ctx);
		else
			op_ra(ctx);
		checked++;
	}
}

static void	push_chunk_back_to_a(t_context *ctx)
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
	int	min;
	int	max;

	size = (int)stack_size(ctx->stack_a);
	if (size <= 1)
		return ;
	chunk_size = get_chunk_size(size);
	max = size - 1;
	while (max >= 0)
	{
		min = max - chunk_size + 1;
		if (min < 0)
			min = 0;
		push_chunk_to_b(ctx, min, max);
		push_chunk_back_to_a(ctx);
		max = min - 1;
	}
}
