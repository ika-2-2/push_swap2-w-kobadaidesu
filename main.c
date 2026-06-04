#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	error_check(char **args)
{
	int		i;
	int		j;
	long	n;
	long	m;

	// split でmalloc が失敗してreturn NULl　check
	if (!args || !args[0])
		error_exit();
	i = 0;
	while (args[i])
	{
		//数字はんてい
		if (!is_valid_number(args[i]))
			error_exit();
		// atoiじゃなくてatolなのはINTMINのはんていをするため
		// long min long max の対応もしたほうがいいかも
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_exit();
		j = i + 1;
		//重複チェック
		while (args[j])
		{
			m = ft_atol(args[j]);
			if (n == m)
				error_exit();
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**args;

	if (argc < 2)
		return (0);
	//入力するときに"2 3 1" だったとき
	if (ft_strchr(argv[1], ' '))
		args = ft_split(argv[1], ' ');
	//入力するときに2 3 1　だったとき
	else
		args = &argv[1];
	// error handling
	error_check(args);
	// スタックに数字をいれていく
	init_stack(args);
	// TODO: 座標圧縮
	coordinate_comp();
	return (0);
}
