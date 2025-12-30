#include "stack.h"
#include "operations.h"
#include <stddef.h>

size_t parent(size_t i)
{
	return ((i - 1) / 2);
}

size_t left(size_t i)
{
	return (2 * i + 1);
}

size_t right(size_t i)
{
	return (2 * i + 2);
}

void	swap_nodes(t_stack *a, t_stack *b, size_t n, size_t m, int *ops_count)
{
	move_a(a, n, ops_count);
	push_b(b, a, ops_count);
	move_a(a, m, ops_count);
	push_a(a, b, ops_count);
	rotate_a(a, ops_count);
	push_b(b, a, ops_count);
	move_a(a, n, ops_count);
	push_a(a, b, ops_count);
}

void	max_heapify(t_stack *a, t_stack *b, size_t i, size_t size, int *ops_count)
{
	size_t	l;
	size_t	r;
	size_t	max;

	l = left(i);
	r = right(i);
	if (l < size && lstget(a->top, l) > lstget(a->top, i))
		max = l;
	else
		max = i;
	if (r < size && lstget(a->top, r) > lstget(a->top, max))
		max = r;
	if (max != i)
	{
		swap_nodes(a, b, i, max, ops_count);
		max_heapify(a, b, max, size, ops_count);
	}
}

void	build_max_heap(t_stack *a, t_stack *b, int *ops_count)
{
	size_t	i;
	size_t	first_leave;

	first_leave = a->size / 2;
	i = 0;
	while (i < first_leave)
	{
		max_heapify(a, b, first_leave - i - 1, a->size, ops_count);
		i++;
	}
}

int	heap_sort(t_stack *a)
{
	t_stack	*b;
	size_t	size;
	 size_t	i;
	int		ops_count;

	b = init_stack();
	ops_count = 0;
	build_max_heap(a, b, &ops_count);
	size = a->size;
	i = 0;
	while(i < a->size - 1)
	{
		swap_nodes(a, b, 0, a->size - i - 1, &ops_count);
		size--;
		max_heapify(a, b, 0, size, &ops_count);
		i++;
	}
	free_stack(b);
	return (ops_count);
}
