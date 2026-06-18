/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ika_eater <ika_eater@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:56:05 by ika_eater         #+#    #+#             */
/*   Updated: 2026/06/18 22:17:35 by ika_eater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_check(t_stack **stack_a, t_stack **stack_b, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*stack_a)->index >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 0);
		i++;
	}
	while (*stack_b)
        pa(stack_a, stack_b);
}

static int	stack_size(t_stack **stack_a)
{
	t_stack	*a;
	int		size;

	if (!stack_a || !*stack_a)
		return (0);
	a = (*stack_a)->next;
	size = 0;
	while (a != *stack_a)
	{
		size++;
		a = a->next;
	}
	return (size + 1);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bit;
	int	size;
    int max_index;

    size = stack_size(stack_a);
    bit = 0;
    max_index = size - 1;
    while ((max_index >> bit) != 0)
    {
        radix_check(stack_a, stack_b, size, bit);
        bit++;
    }
}
