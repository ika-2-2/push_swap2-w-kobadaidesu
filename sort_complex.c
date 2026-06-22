/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ika_eater <ika_eater@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:56:05 by ika_eater         #+#    #+#             */
/*   Updated: 2026/06/18 22:21:58 by ika_eater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bit(t_context *ctx, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((ctx->stack_a->index >> bit) & 1) == 0)
			op_pb(ctx);
		else
			op_ra(ctx);
		i++;
	}
	while (ctx->stack_b)
		op_pa(ctx);
}

void	sort_complex(t_context *ctx)
{
	int	bit;
	int	size;
	int	max_index;

	size = (int)stack_size(ctx->stack_a);
	if (size <= 1)
		return ;
	bit = 0;
	max_index = size - 1;
	while ((max_index >> bit) != 0)
	{
		sort_bit(ctx, size, bit);
		bit++;
	}
}
