/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:35:34 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 21:56:01 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 送る側のスタックから先頭を切り離して返す関数
static t_stack *pop_node(t_stack **from_stack)
{
	t_stack *pop_target;
	t_stack *last;
	
	pop_target = *from_stack;
	if (pop_target->next == pop_target)
		*from_stack = NULL;
	else
	{
		last = pop_target->prev;
		*from_stack = pop_target->next;
		(*from_stack)->prev = last;
		last->next = *from_stack;
	}
	return (pop_target);
}

// 受け取るスタックの戦闘に切り離したノードを挿入する関数
static void push_node(t_stack **to_stack, t_stack *node)
{
	t_stack *last;
	if (!*to_stack)
	{
		*to_stack = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last = (*to_stack)->prev;
		node->next = *to_stack;
		node->prev = last;
		(*to_stack)->prev = node;
		last->next = node;
		*to_stack = node;
	}
}

// bの一番上をaの一番上に移動
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node;

	if (!stack_b || !*stack_b)
		return ;
	node = pop_node(stack_b);
	push_node(stack_a, node);
	write(1, "pa\n", 3);
}

// aの一番上をbの一番上に移動
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node;

	if (!stack_a || !*stack_a)
		return ;
	node = pop_node(stack_a);
	push_node(stack_b, node);
	write(1, "pb\n", 3);
}
