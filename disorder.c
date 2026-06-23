/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:50:05 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/23 15:50:06 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	t_stack	*current;
	size_t	size;

	if (!stack)
		return (0);
	size = 1;
	current = stack->next;
	while (current && current != stack)
	{
		size++;
		current = current->next;
	}
	return (size);
}

static int	count_mistakes_from(t_stack *left, int rest)
{
	t_stack	*right;
	int		mistakes;

	right = left->next;
	mistakes = 0;
	while (rest--)
	{
		if (left->index > right->index)
			mistakes++;
		right = right->next;
	}
	return (mistakes);
}

double	calc_disorder(t_stack *stack)
{
	t_stack	*left;
	int		size;
	int		rest;
	int		mistakes;
	int		pairs;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	pairs = size * (size - 1) / 2;
	mistakes = 0;
	left = stack;
	rest = size - 1;
	while (rest > 0)
	{
		mistakes += count_mistakes_from(left, rest);
		left = left->next;
		rest--;
	}
	return ((double)mistakes / (double)pairs);
}
