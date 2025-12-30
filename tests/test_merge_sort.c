#include "tests.h"

void	test_merge_a_in_b(void)
{
	t_stack	*a;
	t_stack	*b;
	int		numbers[8] = {2, 3, 6, 9, 1, 5, 7, 8 };

	a = generate_custom_stack(numbers, 8);
	b = init_stack();
	merge_a_in_b(b, a, 4);
	assert(a->size == 0);
	assert(b->size == 8);
	check_list_integrity(b->top);
	assert(lstcheck_duplicate(b->top) == 0);
	assert(compute_disorder(b) == 0);
}

int	main(void)
{
	test_merge_a_in_b();
}
