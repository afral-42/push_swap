#include "stack.h"
#include "tests.h"

void	test_swap_nodes(void)
{
	t_stack	*a;
	t_stack	*b;

	a = generate_stack(5);
	b = init_stack();
	swap_nodes(a, b, 0, 1);
	assert(a->size == 5);
	assert(b->size == 0);
	assert(lstget(a->top, 0) == 2);
	assert(lstget(a->top, 1) == 1);
	swap_nodes(a, b, 2, 4);
	assert(a->size == 5);
	assert(b->size == 0);
	assert(lstget(a->top, 0) == 2);
	assert(lstget(a->top, 1) == 1);
	assert(lstget(a->top, 2) == 5);
	assert(lstget(a->top, 3) == 4);
	assert(lstget(a->top, 4) == 3);
	swap_nodes(a, b, 3, 4);
	assert(a->size == 5);
	assert(b->size == 0);
	assert(lstget(a->top, 0) == 2);
	assert(lstget(a->top, 1) == 1);
	assert(lstget(a->top, 2) == 5);
	assert(lstget(a->top, 3) == 3);
	assert(lstget(a->top, 4) == 4);
	swap_nodes(a, b, 1, 4);
	assert(a->size == 5);
	assert(b->size == 0);
	assert(lstget(a->top, 0) == 2);
	assert(lstget(a->top, 1) == 4);
	assert(lstget(a->top, 2) == 5);
	assert(lstget(a->top, 3) == 3);
	assert(lstget(a->top, 4) == 1);
	swap_nodes(a, b, 0, 4);
	assert(a->size == 5);
	assert(b->size == 0);
	assert(lstget(a->top, 0) == 1);
	assert(lstget(a->top, 1) == 4);
	assert(lstget(a->top, 2) == 5);
	assert(lstget(a->top, 3) == 3);
	assert(lstget(a->top, 4) == 2);
	swap_nodes(a, b, 1, 2);
	assert(a->size == 5);
	assert(b->size == 0);
	assert(lstget(a->top, 0) == 1);
	assert(lstget(a->top, 1) == 5);
	assert(lstget(a->top, 2) == 4);
	assert(lstget(a->top, 3) == 3);
	assert(lstget(a->top, 4) == 2);
	free_stack(a);
	free_stack(b);
}

int	main(void)
{
	test_swap_nodes();
}
