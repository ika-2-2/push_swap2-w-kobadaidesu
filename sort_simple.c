/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:44:26 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/18 23:44:26 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_min_pos(t_stack *stack)
{
	int		min_index;
	size_t	min_pos;
	size_t	pos;
	size_t	size;

	min_index = stack->index;
	min_pos = 0;
	pos = 0;
	size = stack_size(stack);
	while (pos < size)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	move_a_pos_to_top(t_context *ctx, int pos)
{
	int	size;

	size = (int)stack_size(ctx->stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			op_ra(ctx);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			op_rra(ctx);
	}
}

void	move_min_to_top(t_context *ctx)
{
	move_a_pos_to_top(ctx, (int)find_min_pos(ctx->stack_a));
}

void	sort_simple(t_context *ctx)
{
	if (stack_size(ctx->stack_a) <= 5)
		sort_small(ctx);
	else
		sort_selection(ctx);
}
