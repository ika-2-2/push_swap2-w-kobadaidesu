#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	n;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sign);
}

void	error_check(char **args)
{
	char	**current;
	char	**compare;
	long	n;
	long	m;

	if (!args || !args[0])
		error_exit();
	current = args;
	while (*current)
	{
		if (!is_valid_number(*current))
			error_exit();
		n = ft_atol(*current);
		if (n > INT_MAX || n < INT_MIN)
			error_exit();
		compare = current + 1;
		while (*compare)
		{
			m = ft_atol(*compare);
			if (n == m)
				error_exit();
			compare++;
		}
		current++;
	}
}
