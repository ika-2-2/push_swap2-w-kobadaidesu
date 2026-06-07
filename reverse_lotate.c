/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_lotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:23:01 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 19:18:53 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 順番をローテート(繰り下げ)
void	rra(t_stack **stack_a, int flg)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	if (flg == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int flg)
{
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	if (flg == 0)
		write(1, "rrb\n", 4);
}

// どっちも
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}
