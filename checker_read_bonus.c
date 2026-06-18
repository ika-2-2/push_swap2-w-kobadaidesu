/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/16 15:45:00 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "push_swap.h"

static int	checker_execute_swap_push(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 1);
	else
		return (0);
	return (1);
}

static int	checker_execute_rotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}

static int	checker_execute_line(char *line, t_stack **a, t_stack **b)
{
	if (checker_execute_swap_push(line, a, b))
		return (1);
	return (checker_execute_rotate(line, a, b));
}

static int	has_line_break(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

int	checker_read_ops(t_context *ctx)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!has_line_break(line)
			|| !checker_execute_line(line, &ctx->stack_a, &ctx->stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}
