#include "push_swap.h"
#include <stdio.h>

static int	is_sorted(t_stack *stack)
{
	t_stack	*cur;

	if (!stack)
		return (1);
	cur = stack;
	while (cur->next != stack)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack(argv + 1);
	coordinate_compress(stack_a);
	stack_b = NULL;
	fprintf(stderr, "before: ");
	print_stack(stack_a);
	radix_sort(&stack_a, &stack_b);
	fprintf(stderr, "after:  ");
	print_stack(stack_a);
	if (is_sorted(stack_a))
		fprintf(stderr, "SORTED\n");
	else
		fprintf(stderr, "NOT SORTED\n");
	return (0);
}
