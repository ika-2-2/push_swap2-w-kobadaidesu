/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 00:00:00 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by kasuzuki         ###   ########.fr       */
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
