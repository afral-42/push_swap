#include "tests.h"

void	test_swap(void)
{
	t_stack	*stack;

	stack = generate_stack(0);
	swap(stack);
	free_stack(stack);
	stack = generate_stack(1);
	swap(stack);
	assert(stack->size == 1);
	assert(stack->top->data == 1);
	free_stack(stack);
	stack = generate_stack(2);
	swap(stack);
	assert(stack->size == 2);
	assert(stack->top->data == 2);
	assert(stack->top->next->data == 1);
	free_stack(stack);
	stack = generate_stack(3);
	swap(stack);
	assert(stack->size == 3);
	assert(stack->top->data == 2);
	assert(stack->top->next->data == 1);
	assert(stack->top->next->next->data == 3);
	free_stack(stack);
}

int	main(void)
{
	test_swap();
}
