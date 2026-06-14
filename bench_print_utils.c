#include "push_swap.h"

void	bench_putstr_err(const char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	bench_putnbr_err(int n)
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
		bench_putnbr_err(nb / 10);
	c = (nb % 10) + '0';
	write(2, &c, 1);
}

void	bench_print_percent(double value)
{
	int	scaled;

	scaled = (int)(value * 10000.0 + 0.5);
	bench_putnbr_err(scaled / 100);
	write(2, ".", 1);
	if (scaled % 100 < 10)
		write(2, "0", 1);
	bench_putnbr_err(scaled % 100);
	write(2, "%\n", 2);
}

void	bench_print_op_count(t_context *ctx, t_operation op, const char *name)
{
	int	n;
	int	digits;

	n = ctx->bench.count[op];
	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	bench_putstr_err(name);
	bench_putstr_err(": ");
	while (digits++ < 4)
		write(2, " ", 1);
	bench_putnbr_err(ctx->bench.count[op]);
}
