/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/30 16:31:23 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	ctx;
	char		**args;

	if (argc < 2)
		return (0);
	init_context(&ctx);
	argv = skip_options(argv + 1, &ctx);
	args = get_number_args(argv);
	error_check(args);
	ctx.stack_a = init_stack(args);
	coordinate_compress(ctx.stack_a);
	ctx.disorder = calc_disorder(ctx.stack_a);
	sort_by_strategy(&ctx);
	if (ctx.bench.total_count_flg)
	{
		ft_putnbr_fd(ctx.bench.total, 1);
		write(1, "\n", 1);
	}
	else if (ctx.bench.flag)
		print_bench(&ctx);
	stack_clear(&ctx.stack_a);
	stack_clear(&ctx.stack_b);
	free_number_args(args, argv);
	return (0);
}
