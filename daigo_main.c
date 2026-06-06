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
	if (ctx.bench.flag)
		print_bench(&ctx);
	free_number_args(args, argv);
	return (0);
}
