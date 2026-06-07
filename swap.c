/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:22:50 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 19:14:19 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックaの一番上と二番目を入れ替える
// flgはssの呼び出しかどうか判断
void	sa(t_stack **stack_a, int flg)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	first = *stack_a;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->next;
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
	*stack_a = second;
	if (flg == 0)
		write(1, "sa\n", 3);
}

// スタックbの一番上と二番目を入れ替える
// flgはssの呼び出しかどうか判断
void	sb(t_stack **stack_b, int flg)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	first = *stack_b;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->next;
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
	*stack_b = second;
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
