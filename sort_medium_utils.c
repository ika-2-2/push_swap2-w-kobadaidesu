/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:22:14 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/18 23:22:15 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_in_range(t_stack *stack, int min, int max)
{
	int		pos;
	int		size;
	t_stack	*current;

	if (!stack)
		return (-1);
	pos = 0;
	size = (int)stack_size(stack);
	current = stack;
	while (pos < size)
	{
		if (current->index >= min && current->index <= max)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

int	find_max_pos(t_stack *stack)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_stack	*current;

	pos = 0;
	max_pos = 0;
	max_index = stack->index;
	current = stack;
	while (pos < (int)stack_size(stack))
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	move_a_pos_to_top(t_context *ctx, int pos)
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

void	move_b_pos_to_top(t_context *ctx, int pos)
{
	int	size;

	size = (int)stack_size(ctx->stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			op_rb(ctx);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			op_rrb(ctx);
	}
}
