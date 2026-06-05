/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:54:35 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/05 23:33:20 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 座標圧縮
int *coordinate_comp(t_stack *stack_a)
{
    t_stack *current_a;
    t_stack *current_b;
    int cnt;
    
    current_a = stack_a;
    while(current_a)
    {
        cnt = 0;
        current_b = stack_a;
        while(current_b)
        {
            if(current_a->value > current_b->value)
                cnt++;
            current_b = current_b->next;
        }
        current_a->index = cnt;
        current_a = current_a->next;
    }
}
