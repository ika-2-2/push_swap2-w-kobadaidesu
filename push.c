/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:35:34 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 18:53:39 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*push_node;
	t_stack	*a_last;
	t_stack	*b_last;

	if (!stack_b || !*stack_b)
		return ;
	push_node = *stack_b;
	if (push_node->next == push_node)
		*stack_b = NULL;
	else
	{
		b_last = push_node->prev;
		*stack_b = push_node->next;
		(*stack_b)->prev = b_last;
		b_last->next = *stack_b;
	}
	if (!*stack_a)
	{
		*stack_a = push_node;
		push_node->next = push_node;
		push_node->prev = push_node;
	}
	else
	{
		a_last = (*stack_a)->prev;
		push_node->next = *stack_a;
		push_node->prev = a_last;
		(*stack_a)->prev = push_node;
		a_last->next = push_node;
		*stack_a = push_node;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*push_node;
	t_stack	*a_last;
	t_stack	*b_last;

	if (!stack_a || !*stack_a)
		return ;
	push_node = *stack_a;
	if (push_node->next == push_node)
		*stack_a = NULL;
	else
	{
		a_last = push_node->prev;
		*stack_a = push_node->next;
		(*stack_a)->prev = a_last;
		a_last->next = *stack_a;
	}
	if (!*stack_b)
	{
		*stack_b = push_node;
		push_node->next = push_node;
		push_node->prev = push_node;
	}
	else
	{
		b_last = (*stack_b)->prev;
		push_node->next = *stack_b;
		push_node->prev = b_last;
		(*stack_b)->prev = push_node;
		b_last->next = push_node;
		*stack_b = push_node;
	}
	write(1, "pb\n", 3);
}
