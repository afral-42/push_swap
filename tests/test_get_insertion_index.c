#include "algorithms.h"
#include "stack.h"
#include "tests.h"


int	main(void)
{
	int	numbers[] = { 6, 8, 2, 4 };
	int	numbers2[] = { 2, 4, 6, 8 };
	int numbers3[] = { 2, 6, 10, 4, 8 };
	t_stack	*s;

	s = generate_custom_stack(numbers, 4);
	assert(get_insertion_index(s, 5, 2, 2) == 0);
	assert(get_insertion_index(s, 7, 2, 2) == 1);
	assert(get_insertion_index(s, 9, 2, 2) == 2);
	assert(get_insertion_index(s, 1, 2, 2) == 2);
	assert(get_insertion_index(s, 3, 2, 2) == 3);
	assert(get_insertion_index(s, 3, 0, 1) == 0);
	free_stack(s);
	s = generate_custom_stack(numbers2, 4);
	assert(get_insertion_index(s, 1, 0, 4) == 0);
	assert(get_insertion_index(s, 3, 0, 4) == 1);
	assert(get_insertion_index(s, 5, 0, 4) == 2);
	assert(get_insertion_index(s, 7, 0, 4) == 3);
	assert(get_insertion_index(s, 9, 0, 4) == 0);
	free_stack(s);
	s = generate_custom_stack(numbers3, 4);
	assert(get_insertion_index(s, 7, 0, 2) == 2);
	free_stack(s);
}
