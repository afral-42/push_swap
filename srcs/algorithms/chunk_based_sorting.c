/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:33:17 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 17:12:15 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "algorithms.h"
#include <stddef.h>

void	build_sorted_chunk(t_stack *a, t_stack *b, size_t chunk_size, t_ops_counter *ops_counter)
{
	size_t	i;
	size_t	rotations_count;

	rotations_count = 0;
	i = 0;
	while (i < chunk_size && a->size)
	{
		while (rotations_count < i && b->top->data > a->top->data)
		{
			rotate_b(b, ops_counter);
			rotations_count++;
		}
		push_b(b, a, ops_counter);
		while (rotations_count)
		{
			reverse_rotate_b(b, ops_counter);
			rotations_count--;
		}
		i++;
	}
}

void	merge_chunks(t_stack *a, t_stack *b, size_t chunk_size, t_ops_counter *counter)
{
	size_t	i;
	size_t	rotation_count;

	i = 0;
	while (i < chunk_size)
	{
		push_b(b, a, counter);
		if (i > 0)
			rotate_b(b, counter);
		i++;
	}
	rotation_count = chunk_size;
	if (a->size < chunk_size)
		rotation_count = a->size;
	else
		rotation_count = chunk_size;
	i = b->size + rotation_count;
	while (i)
	{
		if ((b->top && a->top->data > b->top->data) || rotation_count == 0)
			push_a(a, b, counter);
		else
			rotation_count--;
		rotate_a(a, counter);
		i--;
	}
}
#include "parsing.h"
void	chunk_based_sort_procedure(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	size_t	chunk_size;
	size_t	merge_chunk_size;
	size_t	merge_count;
	size_t	i;
	
	chunk_size = ft_sqrt(a->size);
	while (a->size)
		build_sorted_chunk(a, b, chunk_size, counter);
	transfer_stack(a, b, counter, &push_a);
	merge_chunk_size = chunk_size;
	while (merge_chunk_size < a->size)
	{
		merge_count = 0;
		while (merge_count <= a->size / (2 * merge_chunk_size))
		{
			merge_count++;
			if (a->size > merge_count * 2 * merge_chunk_size)
				merge_chunks(a, b, merge_chunk_size, counter);
			else 
			{
				i = 0;
				while (i < a->size - (merge_count - 1) * 2 * merge_chunk_size)
				{
					rotate_a(a, counter);
					i++;
				}
			}
			print_list(a->top);
		}
		merge_chunk_size *= 2;
	}
}

t_ops_counter	*chunk_based_sort(t_stack *a)
{
	t_ops_counter	*counter;
	t_stack			*b;

	counter = new_ops_counter();
	if (!counter)
		return (NULL);
	b = init_stack();
	if (!b)
	{
		free(counter);
		return (NULL);
	}
	chunk_based_sort_procedure(a, b, counter);
	free_stack(b);
	return (counter);
}
