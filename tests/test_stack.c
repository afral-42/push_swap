#include "tests.h"

void	test_init_stack(void)
{
	t_stack	*stack;

	stack = init_stack();
	assert(stack->top == NULL);
	assert(stack->size == 0);
	free_stack(stack);
}

void	test_push_st(void)
{
	t_stack	*stack;

	push_st(NULL, 1);
	stack = init_stack();
	push_st(stack, 3);
	assert(stack->size == 1);
	assert(stack->top->data == 3);
	push_st(stack, 2);
	assert(stack->size == 2);
	assert(stack->top->data == 2);
	push_st(stack, 1);
	assert(stack->size == 3);
	assert(stack->top->data == 1);
	free_stack(stack);
}

void	test_pop_st(void)
{
	int		data;
	t_stack	*stack;

	stack = generate_stack(3);
	assert(stack->size == 3);
	assert(stack->top->data == 1);
	data = pop_st(stack);
	assert(data == 1);
	assert(stack->size == 2);
	assert(stack->top->data == 2);
	data = pop_st(stack);
	assert(data == 2);
	assert(stack->size == 1);
	assert(stack->top->data == 3);
	data = pop_st(stack);
	assert(data == 3);
	assert(stack->size == 0);
	assert(stack->top == NULL);
	free_stack(stack);
}

int	main(void)
{
	test_init_stack();
	test_push_st();
	test_pop_st();
}
