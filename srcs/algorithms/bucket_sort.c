/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:44:40 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/03 12:04:03 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "stack.h"
#include "operations.h"


void	fill_bucket(t_stack *a, t_stack *b, int limit, t_ops_counter *ops_count)
{
	size_t	size;
	size_t	rotations_count;
	size_t	bucket_size;

	size = a->size;
	bucket_size = 0;
	rotations_count = 0;
	while (size)
	{
		if (a->top->data <= limit)
		{
			while (rotations_count++ < bucket_size && b->top->data > a->top->data)
				rotate_b(b, ops_count);
			push_b(b, a, ops_count);
			bucket_size++;
			while (--rotations_count)
				reverse_rotate_b(b, ops_count);
		}
		else
			rotate_a(a, ops_count);
		size--;
	}
}

void	bucket_sort_procedure(t_stack *a, t_stack *b, t_ops_counter *ops_counter)
{
	int	buckets_qty;
	int	limit;
	int	min;
	int	max;

	max = lstget_max(a->top);
	min = lstget_min(a->top);
	buckets_qty = ft_sqrt(max - min);
	limit = min + (max - min) / buckets_qty;
	while (limit < max + (max - min) / buckets_qty)
	{
		fill_bucket(a, b, limit, ops_counter);
		limit += (max - min) / buckets_qty;
	}
	while (b->size)
		push_a(a, b, ops_counter);
}

t_ops_counter	*bucket_sort(t_stack *a)
{
	t_stack			*b;
	t_ops_counter	*ops_counter;

	ops_counter = new_ops_counter();
	if (!ops_counter)
		return (NULL);
	b = init_stack();
	if (!b)
		return (NULL);
	bucket_sort_procedure(a, b, ops_counter);
	free_stack(b);
	return (ops_counter);
}
