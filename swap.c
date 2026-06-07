/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:22:50 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/07 17:51:21 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
    t_stack *last;

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
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
    t_stack *last;

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
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
