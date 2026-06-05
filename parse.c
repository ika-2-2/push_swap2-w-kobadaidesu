#include "push_swap.h"

static int	parse_strategy(char *arg, t_strategy *strategy)
{
	if (ft_strcmp(arg, "--simple") == 0)
		*strategy = STRATEGY_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		*strategy = STRATEGY_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		*strategy = STRATEGY_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		*strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

char	**skip_options(char **argv, t_config *config)
{
	while (*argv)
	{
		if (ft_strcmp(*argv, "--bench") == 0)
			config->bench.flag = 1;
		else if (!parse_strategy(*argv, &config->strategy))
			break ;
		argv++;
	}
	return (argv);
}

char	**get_number_args(char **argv)
{
	if (!*argv)
		error_exit();
	if (ft_strchr(*argv, ' '))
	{
		if (*(argv + 1))
			error_exit();
		return (ft_split(*argv, ' '));
	}
	return (argv);
}

void	free_number_args(char **args, char **argv)
{
	char	**current;

	if (args == argv)
		return ;
	current = args;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(args);
}
