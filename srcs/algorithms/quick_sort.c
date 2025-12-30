#include "algorithms.h"
#include "stack.h"
#include "list.h"
#include "operations.h"

size_t	partition_a(t_stack *a, t_stack *b, size_t r, int *ops_count)
{
	int		pivot_data;
	size_t	left_partition_size;
	size_t	j;

	pivot_data = lstget(a->top, r - 1);
	left_partition_size = 0;
	j = 0;
	while (j++ < r - 1)
	{
		if (a->top->data <= pivot_data)
		{
			push_b(b, a, ops_count);
			left_partition_size++;
		}
		else
			rotate_a(a, ops_count);
	}
	j = 0;
	while (j++ < left_partition_size)
		push_a(a, b, ops_count);
	return (left_partition_size + 1);
}

void	quick_sort_procedure(t_stack *a, t_stack *b, size_t r, int *ops_count)
{
	size_t	q;
	// size_t	i;

	if (r > 0)
	{
		q = partition_a(a, b, r, ops_count);
		// transfer_b_to_a_sorted(b, a, r, ops_count);
		quick_sort_procedure(a, b, q - 1, ops_count);
		if (a->size)
		{
			push_b(b, a, ops_count);
			rotate_b(b, ops_count);
		}
		quick_sort_procedure(a, b, r - q, ops_count);
	}
}

int	quick_sort(t_stack *a)
{
	int		ops_count;
	t_stack	*b;

	ops_count = 0;
	b = init_stack();
	if (!b)
		return (0);
	quick_sort_procedure(a, b, a->size, &ops_count);
	transfer_b_to_a_sorted(b, a, b->size, &ops_count);
	free_stack(b);
	return (ops_count);
}
