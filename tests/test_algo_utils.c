#include "tests.h"

void	test_transfer_stack(void)
{
	t_stack	*a;
	t_stack	*b;

	a = generate_stack(1);
	b = init_stack();
	transfer_stack(b, a, &push_b);
	assert(a->size == 0);
	assert(b->size == 1);
	assert(b->top->data = 1);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
	a = generate_stack(2);
	b = init_stack();
	transfer_stack(b, a, &push_b);
	assert(a->size == 0);
	assert(b->size == 2);
	assert(b->top->data = 2);
	assert(b->top->next->data = 1);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
	a = generate_stack(3);
	b = init_stack();
	transfer_stack(b, a, &push_b);
	assert(a->size == 0);
	assert(b->size == 3);
	assert(b->top->data = 3);
	assert(b->top->next->data = 2);
	assert(b->top->next->next->data = 1);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
}

void	test_transfer_stack_a_to_b_sorted(void)
{
	t_stack	*a;
	t_stack	*b;

	a = generate_stack(1);
	b = init_stack();
	transfer_a_to_b_sorted(a, b, 1);
	assert(a->size == 0);
	assert(b->size == 1);
	assert(b->top->data = 1);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
	a = generate_stack(2);
	b = init_stack();
	transfer_a_to_b_sorted(a, b, 2);
	assert(a->size == 0);
	assert(b->size == 2);
	assert(b->top->data = 1);
	assert(b->top->next->data = 2);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
	a = generate_stack(3);
	b = init_stack();
	transfer_a_to_b_sorted(a, b, 3);
	assert(a->size == 0);
	assert(b->size == 3);
	assert(b->top->data = 1);
	assert(b->top->next->data = 2);
	assert(b->top->next->next->data = 3);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
	a = generate_stack(3);
	b = init_stack();
	transfer_a_to_b_sorted(a, b, 2);
	assert(a->size == 1);
	assert(a->top->data = 3);
	assert(b->size == 2);
	assert(b->top->data = 1);
	assert(b->top->next->data = 2);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	free_stack(a);
	free_stack(b);
}

int	main(void)
{
	test_transfer_stack();
	test_transfer_stack_a_to_b_sorted();
}
