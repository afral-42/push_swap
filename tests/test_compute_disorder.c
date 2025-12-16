#include "tests.h"

void	test_disorder_min(void)
{
	t_stack	*stack;

	stack = generate_stack(0);
	assert(compute_disorder(stack) == 0);
	free_stack(stack);
	stack = generate_stack(1);
	assert(compute_disorder(stack) == 0);
	free_stack(stack);
	stack = generate_stack(2);
	assert(compute_disorder(stack) == 0);
	free_stack(stack);
	stack = generate_stack(3);
	assert(compute_disorder(stack) == 0);
	free_stack(stack);
	stack = generate_stack(10);
	assert(compute_disorder(stack) == 0);
	free_stack(stack);
}

void	test_disorder_max(void)
{
	t_stack	*stack;
	t_stack	*stack_cpy;

	stack = generate_stack(2);
	swap(stack);
	assert(compute_disorder(stack) == 1.0);
	free_stack(stack);
	stack = generate_stack(3);
	stack_cpy = generate_stack(0);
	while (stack->size)
		push(stack_cpy, stack);
	assert(compute_disorder(stack_cpy) == 1.0);
	free_stack(stack);
	free_stack(stack_cpy);
	stack = generate_stack(10);
	stack_cpy = generate_stack(0);
	while (stack->size)
		push(stack_cpy, stack);
	assert(compute_disorder(stack_cpy) == 1.0);
	free_stack(stack);
	free_stack(stack_cpy);
}

void	test_disorder_intermediate(void)
{
	t_stack	*stack;

	stack = generate_stack(4);
	swap(stack);
	assert(compute_disorder(stack) == (double)1 / 6);
	free_stack(stack);
	stack = generate_stack(5);
	rotate(stack);
	assert(compute_disorder(stack) == (double)4 / 10);
	rotate(stack);
	assert(compute_disorder(stack) == (double)6 / 10);
	rotate(stack);
	assert(compute_disorder(stack) == (double)6 / 10);
	rotate(stack);
	assert(compute_disorder(stack) == (double)4 / 10);
	free_stack(stack);
	stack = generate_stack(5);
	reverse_rotate(stack);
	assert(compute_disorder(stack) == (double)4 / 10);
	reverse_rotate(stack);
	assert(compute_disorder(stack) == (double)6 / 10);
	reverse_rotate(stack);
	assert(compute_disorder(stack) == (double)6 / 10);
	reverse_rotate(stack);
	assert(compute_disorder(stack) == (double)4 / 10);
	free_stack(stack);
}

int	main()
{
	test_disorder_min();
	test_disorder_max();
	test_disorder_intermediate();
}
