/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:54:35 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/05 23:54:21 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	coordinate_compress(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	if (!stack)
		return ;
	current = stack;
	while (1)
	{
		index = 0;
		compare = stack;
		while (1)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
			if (compare == stack)
				break ;
		}
		current->index = index;
		current = current->next;
		if (current == stack)
			break ;
	}
}
