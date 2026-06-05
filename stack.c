/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasuzuki <kasuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:58:41 by kasuzuki          #+#    #+#             */
/*   Updated: 2026/06/04 20:12:21 by kasuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 新しいスタック作成
static t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// 最後尾にノードを作る
static void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		new->next = new;
		new->prev = new;
		*stack = new;
		return ;
	}
	last = (*stack)->prev;
	last->next = new;
	new->prev = last;
	new->next = *stack;
	(*stack)->prev = new;
}


// malloc失敗したときに全freeする関数
static void	all_free(t_stack **stack_a)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*nextone;

	if (!stack_a || !*stack_a)
		return ;
	start = *stack_a;
	current = start->next;
	while (current != start)
	{
		nextone = current->next;
		free(current);
		current = nextone;
	}
	free(start);
	*stack_a = NULL;
}

t_stack	*init_stack(char **args)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i])
	{
		new_node = stack_new((int)ft_atol(args[i]));
		if (!new_node)
		{
			all_free(&stack_a);
			error_exit();
		}
		stack_add_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}
