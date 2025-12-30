#include "operations.h"
#include "tests.h"

void	test_swap(void)
{
	t_stack	*stack;

	stack = generate_stack(0);
	swap(stack);
	free_stack(stack);
	stack = generate_stack(1);
	swap(stack);
	check_list_integrity(stack->top);
	assert(stack->size == 1);
	assert(stack->top->data == 1);
	free_stack(stack);
	stack = generate_stack(2);
	swap(stack);
	check_list_integrity(stack->top);
	assert(stack->size == 2);
	assert(stack->top->data == 2);
	assert(stack->top->next->data == 1);
	free_stack(stack);
	stack = generate_stack(3);
	swap(stack);
	check_list_integrity(stack->top);
	assert(stack->size == 3);
	assert(stack->top->data == 2);
	assert(stack->top->next->data == 1);
	assert(stack->top->next->next->data == 3);
	free_stack(stack);
}

void	test_swap_both(void)
{
	t_stack	*a;
	t_stack	*b;
	int		ops_counter;

	ops_counter = 0;
	a = generate_stack(3);
	b = generate_stack(3);
	swap_both(a, b, &ops_counter);
	check_list_integrity(a->top);
	assert(a->size == 3);
	assert(a->top->data == 2);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 3);
	free_stack(a);
	check_list_integrity(b->top);
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
	check_list_integrity(a->top);
	assert(a->size == 1);
	assert(a->top->data == 1);
	free_stack(a);
	a = generate_stack(2);
	rotate(a);
	check_list_integrity(a->top);
	assert(a->size == 2);
	assert(a->top->data == 2);
	assert(a->top->next->data == 1);
	free_stack(a);
	a = generate_stack(3);
	rotate(a);
	check_list_integrity(a->top);
	assert(a->size == 3);
	assert(a->top->data == 2);
	assert(a->top->next->data == 3);
	assert(a->top->next->next->data == 1);
	free_stack(a);
	a = generate_stack(4);
	rotate(a);
	check_list_integrity(a->top);
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
	check_list_integrity(a->top);
	assert(a->size == 1);
	assert(a->top->data == 1);
	free_stack(a);
	a = generate_stack(2);
	reverse_rotate(a);
	check_list_integrity(a->top);
	assert(a->size == 2);
	assert(a->top->data == 2);
	assert(a->top->next->data == 1);
	free_stack(a);
	a = generate_stack(3);
	reverse_rotate(a);
	check_list_integrity(a->top);
	assert(a->size == 3);
	assert(a->top->data == 3);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 2);
	free_stack(a);
	a = generate_stack(4);
	reverse_rotate(a);
	check_list_integrity(a->top);
	assert(a->size == 4);
	assert(a->top->data == 4);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 2);
	assert(a->top->next->next->next->data == 3);
	free_stack(a);
}

void	test_rotate_both(void)
{
	t_stack	*a;
	t_stack	*b;
	int		ops_counter;

	a = generate_stack(4);
	b = generate_stack(4);
	rotate_both(a, b, &ops_counter);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	assert(a->size == 4);
	assert(a->top->data == 2);
	assert(a->top->next->data == 3);
	assert(a->top->next->next->data == 4);
	assert(a->top->next->next->next->data == 1);
	assert(b->size == 4);
	assert(b->top->data == 2);
	assert(b->top->next->data == 3);
	assert(b->top->next->next->data == 4);
	assert(b->top->next->next->next->data == 1);
	free_stack(a);
	free_stack(b);
}

void	test_reverse_rotate_both(void)
{
	t_stack	*a;
	t_stack	*b;
	int		ops_counter;

	ops_counter = 0;
	a = generate_stack(4);
	b = generate_stack(4);
	reverse_rotate_both(a, b, &ops_counter);
	check_list_integrity(a->top);
	check_list_integrity(b->top);
	assert(a->size == 4);
	assert(a->top->data == 4);
	assert(a->top->next->data == 1);
	assert(a->top->next->next->data == 2);
	assert(a->top->next->next->next->data == 3);
	assert(b->size == 4);
	assert(b->top->data == 4);
	assert(b->top->next->data == 1);
	assert(b->top->next->next->data == 2);
	assert(b->top->next->next->next->data == 3);
	free_stack(a);
	free_stack(b);
}

void	test_move_a()
{
	t_stack	*a;
	int		ops_counter;

	ops_counter = 0;
	a = generate_stack(5);
	move_a(a, 1, &ops_counter); 
	assert(a->position == 1);
	assert(a->top->data == 2);
	assert(ops_counter = 1);
	move_a(a, 4, &ops_counter);
	assert(a->position == 4);
	assert(a->top->data == 5);
	assert(ops_counter = 3);
	move_a(a, 2, &ops_counter);
	assert(a->position == 2);
	assert(a->top->data == 3);
	assert(ops_counter = 5);
	move_a(a, 3, &ops_counter);
	assert(a->position == 3);
	assert(a->top->data == 4);
	assert(ops_counter = 6);
	move_a(a, 0, &ops_counter);
	assert(a->position == 0);
	assert(a->top->data == 1);
	assert(ops_counter = 8);
}

int	main(void)
{
	test_swap();
	test_swap_both();
	test_rotate();
	test_reverse_rotate();
	test_rotate_both();
	test_reverse_rotate_both();
	test_move_a();
}
