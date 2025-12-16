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

void	test_double_swap(void)
{
	t_stack	*a;
	t_stack	*b;

	a = generate_stack(3);
	b = generate_stack(3);
	double_swap(a, b);
	assert(a->size == 3);
	assert(a->top->data == 2);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 3);
	free_stack(a);
	assert(b->size == 3);
	assert(b->top->data == 2);
	assert(b->top->next->data == 1);
	assert(b->top->next->next->data == 3);
	free_stack(b);
}

void	test_rotate(void)
{
	t_stack	*a;
	
	a = generate_stack(0);
	rotate(a);
	free_stack(a);
	a = generate_stack(1);
	rotate(a);
	assert(a->size == 1);
	assert(a->top->data == 1);
	free_stack(a);
	a = generate_stack(2);
	rotate(a);
	assert(a->size == 2);
	assert(a->top->data == 2);
	assert(a->top->next->data == 1);
	free_stack(a);
	a = generate_stack(3);
	rotate(a);
	assert(a->size == 3);
	assert(a->top->data == 2);
	assert(a->top->next->data == 3);
	assert(a->top->next->next->data == 1);
	free_stack(a);
	a = generate_stack(4);
	rotate(a);
	assert(a->size == 4);
	assert(a->top->data == 2);
	assert(a->top->next->data == 3);
	assert(a->top->next->next->data == 4);
	assert(a->top->next->next->next->data == 1);
	free_stack(a);
}

void	test_reverse_rotate(void)
{
	t_stack	*a;
	
	a = generate_stack(0);
	reverse_rotate(a);
	free_stack(a);
	a = generate_stack(1);
	reverse_rotate(a);
	assert(a->size == 1);
	assert(a->top->data == 1);
	free_stack(a);
	a = generate_stack(2);
	reverse_rotate(a);
	assert(a->size == 2);
	assert(a->top->data == 2);
	assert(a->top->next->data == 1);
	free_stack(a);
	a = generate_stack(3);
	reverse_rotate(a);
	assert(a->size == 3);
	assert(a->top->data == 3);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 2);
	free_stack(a);
	a = generate_stack(4);
	reverse_rotate(a);
	assert(a->size == 4);
	assert(a->top->data == 4);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 2);
	assert(a->top->next->next->next->data == 3);
	free_stack(a);
}

void	test_push(void)
{
	t_stack	*a;
	t_stack	*b;

	a = generate_stack(3);
	b = generate_stack(0);
	push(b, a);
	assert(a->size == 2);
	assert(a->top->data == 2);
	assert(b->size == 1);
	assert(b->top->data == 1);
	push(b, a);
	assert(a->size == 1);
	assert(a->top->data == 3);
	assert(b->size == 2);
	assert(b->top->data == 2);
	assert(b->top->next->data == 1);
	push(b, a);
	assert(a->size == 0);
	assert(b->size == 3);
	assert(b->top->data == 3);
	assert(b->top->next->data == 2);
	assert(b->top->next->next->data == 1);
	free_stack(a);
	free_stack(b);
}

int	main(void)
{
	test_swap();
	test_double_swap();
	test_rotate();
	test_reverse_rotate();
	test_push();
}
