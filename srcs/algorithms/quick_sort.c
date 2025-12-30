/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:12:12 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/30 16:11:57 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	j = 0;
	while (j++ < r)
	{
		if (a->top->data <= pivot_data)
			push_b(b, a, ops_count);
		else
			rotate_a(a, ops_count);
	}
	j = 0;
	while (j++ < r - b->size)
		reverse_rotate_a(a, ops_count);
	j = 0;
	left_partition_size = b->size - 1;
	while (j++ < left_partition_size + 1)
		push_a(a, b, ops_count);
	return (left_partition_size + 1);
}

void	quick_sort_procedure(t_stack *a, t_stack *b, size_t r, int *ops_count)
{
	size_t	q;

	if (r > 0)
	{
		q = partition_a(a, b, r, ops_count);
		quick_sort_procedure(a, b, q - 1, ops_count);
		rotate_a(a, ops_count);
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
	free_stack(b);
	return (ops_count);
}
