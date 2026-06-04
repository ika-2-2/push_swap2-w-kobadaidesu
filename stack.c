/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:58:41 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/04 17:23:15 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 新しいスタック作成
t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// 最後尾にノードを作る
void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_list	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (!last->next)
		last = last->next;
	new->prev = last;
}

// TODO: malloc失敗したときに全freeする関数

t_stack *init_stack(char **args)
{
    
}
