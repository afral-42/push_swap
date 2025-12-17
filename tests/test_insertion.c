#include "tests.h"

void	test_with_already_sorted_stack(void)
{
	t_stack	*stack;

	stack = generate_stack(0);
	assert(stack_is_sorted(stack));
	insertion_sort(stack);
	assert(stack_is_sorted(stack));
	stack = generate_stack(1);
	assert(stack_is_sorted(stack));
	insertion_sort(stack);
	assert(stack_is_sorted(stack));
}
