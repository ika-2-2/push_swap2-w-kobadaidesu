/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:22:56 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 19:19:05 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 順番をローテート(繰り上げ)
void	ra(t_stack **stack_a, int flg)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	if (flg == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int flg)
{
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	if (flg == 0)
		write(1, "rb\n", 3);
}

// 両方
void	rr(t_stack **stack_a, t_stack **stack_b, int flg)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (flg == 0)
		write(1, "rr\n", 3);
}
