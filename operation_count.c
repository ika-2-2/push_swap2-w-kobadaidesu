/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:50:19 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/23 15:50:20 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_operation(t_context *ctx, t_operation op)
{
	if (!ctx->bench.flag)
		return ;
	ctx->bench.total++;
	ctx->bench.count[op]++;
}
