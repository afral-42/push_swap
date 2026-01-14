#include "tests.h"

int	main(void)
{
	test_sorting_with_already_sorted_stack(&merge_sort);
	test_sorting_with_maximum_disorder_stack(&merge_sort);
	test_sorting_with_average_disorder_stack(&merge_sort);
}
