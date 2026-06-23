/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:50:43 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/23 15:50:44 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_selection(t_context *ctx)
{
	while (stack_size(ctx->stack_a) > 5)
	{
		move_min_to_top(ctx);
		op_pb(ctx);
	}
	sort_small(ctx);
	while (ctx->stack_b)
		op_pa(ctx);
}
