#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	t_stack	*current;
	size_t	size;

	if (!stack)
		return (0);
	size = 1;
	current = stack->next;
	while (current && current != stack)
	{
		size++;
		current = current->next;
	}
	return (size);
}

double	calc_disorder(t_stack *stack)
{
	t_stack	*left;
	t_stack	*right;
	int		size;
	int		rest;
	int		mistakes;
	int		pairs;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	pairs = size * (size - 1) / 2;
	mistakes = 0;
	left = stack;
	while (--size)
	{
		rest = size;
		right = left->next;
		while (rest--)
		{
			if (left->index > right->index)
				mistakes++;
			right = right->next;
		}
		left = left->next;
	}
	return ((double)mistakes / (double)pairs);
}
