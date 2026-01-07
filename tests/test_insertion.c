#include "tests.h"

void	test_bucket_sort(void)
{
	test_sorting_with_already_sorted_stack(&bucket_sort);
	test_sorting_with_maximum_disorder_stack(&bucket_sort);
	test_sorting_with_average_disorder_stack(&bucket_sort);
}

void	test_radix_sort(void)
{
	test_sorting_with_already_sorted_stack(&radix_sort);
	test_sorting_with_maximum_disorder_stack(&radix_sort);
	test_sorting_with_average_disorder_stack(&radix_sort);
}

void	test_quick_sort(void)
{
	test_sorting_with_already_sorted_stack(&quick_sort);
	test_sorting_with_maximum_disorder_stack(&quick_sort);
	test_sorting_with_average_disorder_stack(&quick_sort);
}

void	test_merge_sort(void)
{
	test_sorting_with_already_sorted_stack(&merge_sort);
	test_sorting_with_maximum_disorder_stack(&merge_sort);
	test_sorting_with_average_disorder_stack(&merge_sort);
}

void	test_insertion_sort(void)
{
	test_sorting_with_already_sorted_stack(&insertion_sort);
	test_sorting_with_maximum_disorder_stack(&insertion_sort);
	test_sorting_with_average_disorder_stack(&insertion_sort);
}

int	main(void)
{
	test_insertion_sort();
	test_merge_sort();
	test_quick_sort();
	test_radix_sort();
	test_bucket_sort();
}
