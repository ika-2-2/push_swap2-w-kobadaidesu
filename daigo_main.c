#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	char		**args;

	if (argc < 2)
		return (0);
	init_config(&config);
	argv = skip_options(argv + 1, &config);
	args = get_number_args(argv);
	error_check(args);
	config.stack_a = init_stack(args);
	coordinate_compress(config.stack_a);
	config.disorder = calc_disorder(config.stack_a);
	sort_by_strategy(&config);
	if (config.bench.flag)
		print_bench(&config);
	free_number_args(args, argv);
	return (0);
}
