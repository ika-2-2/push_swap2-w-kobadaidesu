#include "push_swap.h"

void	init_config(t_config *config)
{
	int	*count;
	int	*end;

	config->stack_a = NULL;
	config->stack_b = NULL;
	config->bench.flag = 0;
	config->bench.total = 0;
	count = config->bench.count;
	end = config->bench.count + OP_COUNT;
	while (count < end)
	{
		*count = 0;
		count++;
	}
	config->strategy = STRATEGY_ADAPTIVE;
	config->disorder = 0.0;
}

void	sort_by_strategy(t_config *config)
{
	if (config->strategy == STRATEGY_SIMPLE)
	{
		/*
			sort_simple(config);
		*/
	}
	else if (config->strategy == STRATEGY_MEDIUM)
	{
		/*
			sort_medium(config);
		*/
	}
	else if (config->strategy == STRATEGY_COMPLEX)
	{
		/*
			sort_complex(config);
		*/
	}
	else
	{
		/*
			sort_adaptive(config);
		*/
	}
}
