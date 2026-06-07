/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:22:50 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 21:39:51 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 入れ替える関数
static void swap_node(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *last;
	
	first = *stack;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	if (second->next == second->prev)
	{
		first->next = second;
		second->prev = first;
	}
	else
	{
		second->prev = last;
		last->next = second;
	}
	*stack = second;
}

// スタックaの一番上と二番目を入れ替える
// flgはssの呼び出しかどうか判断
void	sa(t_stack **stack_a, int flg)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	swap_node(stack_a);
	if (flg == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int flg)
{
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	swap_node(stack_b);
	if (flg == 0)
		write(1, "sb\n", 3);
}

// aとbどっちもswap実行
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
    write(1, "ss\n", 3);
}
