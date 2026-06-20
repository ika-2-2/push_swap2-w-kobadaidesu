#include "push_swap.h"

static void	print_bench_header(t_context *ctx)
{
	bench_putstr_err("[bench] disorder:  ");
	bench_print_percent(ctx->disorder);
	bench_putstr_err("[bench] strategy:  ");
	bench_putstr_err(strategy_name(ctx->strategy));
	if (ctx->strategy == STRATEGY_ADAPTIVE)
	{
		bench_putstr_err(" (");
		bench_putstr_err(strategy_name(ctx->active_strategy));
		bench_putstr_err(")");
	}
	bench_putstr_err(" / ");
	bench_putstr_err(strategy_complexity(ctx->active_strategy));
	bench_putstr_err("\n");
	bench_putstr_err("[bench] total_ops:  ");
	bench_putnbr_err(ctx->bench.total);
	write(2, "\n", 1);
}

static void	print_swap_push_counts(t_context *ctx)
{
	bench_putstr_err("[bench] ");
	bench_print_op_count(ctx, OP_SA, "sa");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_SB, "sb");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_SS, "ss");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_PA, "pa");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_PB, "pb");
	write(2, "\n", 1);
}

static void	print_rotate_counts(t_context *ctx)
{
	bench_putstr_err("[bench] ");
	bench_print_op_count(ctx, OP_RA, "ra");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_RB, "rb");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_RR, "rr");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_RRA, "rra");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_RRB, "rrb");
	bench_putstr_err(" ");
	bench_print_op_count(ctx, OP_RRR, "rrr");
	write(2, "\n", 1);
}

void	print_bench(t_context *ctx)
{
	print_bench_header(ctx);
	print_swap_push_counts(ctx);
	print_rotate_counts(ctx);
}
