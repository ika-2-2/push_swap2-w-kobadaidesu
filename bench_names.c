#include "push_swap.h"

const char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("complex");
	return ("adaptive");
}

const char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n sqrt n)");
	if (strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("adaptive");
}
