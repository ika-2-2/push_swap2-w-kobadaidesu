/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ika_eater <ika_eater@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:56:05 by ika_eater         #+#    #+#             */
/*   Updated: 2026/06/16 00:07:15 by ika_eater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_check(t_stack **stack_a, t_stack **stack_b, int size, int bit)
{
    int i;

    i = 0;
    while(i < size)
    {
        if((((*stack_a)->index >> bit) & 1) == 0)
            pb(stack_a, stack_b);
        else
            ra(stack_a, 0);
        i++;
    }
}

int stack_size(t_stack **stack_a)
{
    t_stack *a;
    int size;
    
    a = *stack_a;
    size = 0;
    while(size != a->index)
    {
        size = a->index;
        a = a->next;
    }
    return (size);
}

int radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int bit;
    int size;

    
}
