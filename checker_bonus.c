/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/16 15:44:55 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker_error(char **args, char **argv, t_context *ctx)
{
	stack_clear(&ctx->stack_a);
	stack_clear(&ctx->stack_b);
	free_number_args(args, argv);
	write(2, "Error\n", 6);
	return (1);
}

static int	checker_result(t_context *ctx)
{
	int	ok;

	ok = (stack_is_sorted(ctx->stack_a) && !ctx->stack_b);
	if (ok)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_clear(&ctx->stack_a);
	stack_clear(&ctx->stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_context	ctx;
	char		**args;

	if (argc < 2)
		return (0);
	ctx.stack_a = NULL;
	ctx.stack_b = NULL;
	args = get_number_args(argv + 1);
	if (has_arg_error(args))
		return (checker_error(args, argv + 1, &ctx));
	ctx.stack_a = init_stack(args);
	coordinate_compress(ctx.stack_a);
	if (!checker_read_ops(&ctx))
		return (checker_error(args, argv + 1, &ctx));
	free_number_args(args, argv + 1);
	return (checker_result(&ctx));
}
