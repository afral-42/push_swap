#include "algorithms.h"
#include "stack.h"
#include "tests.h"


int	main(void)
{
	int	numbers[] = { 6, 8, 2, 4 };
	int	numbers2[] = { 2, 4, 6, 8 };
	t_stack	*s;

	s = generate_custom_stack(numbers, 4);
	assert(get_insertion_index(s, 5) == 0);
	assert(get_insertion_index(s, 7) == 1);
	assert(get_insertion_index(s, 9) == 2);
	assert(get_insertion_index(s, 1) == 2);
	assert(get_insertion_index(s, 3) == 3);
	free_stack(s);
	s = generate_custom_stack(numbers2, 4);
	assert(get_insertion_index(s, 1) == 0);
	assert(get_insertion_index(s, 3) == 1);
	assert(get_insertion_index(s, 5) == 2);
	assert(get_insertion_index(s, 7) == 3);
	assert(get_insertion_index(s, 9) == 0);
	free_stack(s);
}
