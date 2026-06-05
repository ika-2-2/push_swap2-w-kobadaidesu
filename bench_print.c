#include "push_swap.h"

static void	putstr_err(const char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

static void	putnbr_err(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		putnbr_err(nb / 10);
	c = (nb % 10) + '0';
	write(2, &c, 1);
}

static void	print_percent(double value)
{
	int	scaled;

	scaled = (int)(value * 10000.0 + 0.5);
	putnbr_err(scaled / 100);
	write(2, ".", 1);
	if (scaled % 100 < 10)
		write(2, "0", 1);
	putnbr_err(scaled % 100);
	write(2, "%\n", 2);
}

void	print_bench(t_config *config)
{
	putstr_err("[bench] disorder: ");
	print_percent(config->disorder);
	putstr_err("[bench] strategy: ");
	putstr_err(strategy_name(config->strategy));
	putstr_err(" (");
	putstr_err(strategy_complexity(config->strategy));
	putstr_err(")\n");
	putstr_err("[bench] total: ");
	putnbr_err(config->bench.total);
	write(2, "\n", 1);
	/*
		操作のカウントはまた捜査の関数を書いてから考える
	*/
}
