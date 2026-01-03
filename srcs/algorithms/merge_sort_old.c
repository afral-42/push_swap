/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:09:40 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/02 16:10:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"
#include "algorithms.h"

void	merge_b_in_a(t_stack *a, t_stack *b, size_t size, int *ops_count)
{
	size_t	i;
	size_t	rotations_count;
	
	if (b->size < size)
		size = b->size;
	transfer_b_to_a_sorted(b, a, size, ops_count);
	i = 0;
	rotations_count = 0;
	while (i < size)
	{
		while (rotations_count < size && b->size && b->top->data > a->top->data)
		{
			rotate_a(a, ops_count);
			rotations_count++;
		}
		if (b->size)
		{
			push_a(a, b, ops_count);
			rotate_a(a, ops_count);
		}
		i++;
	}
	while (rotations_count++ < size)
		rotate_a(a, ops_count);
}
void	merge_a_in_b(t_stack *b, t_stack *a, size_t size, int *ops_count)
{
	size_t	i;
	size_t	rotations_count;
	
	if (a->size < size)
		size = a->size;
	transfer_a_to_b_sorted(a, b, size, ops_count);
	i = 0;
	rotations_count = 0;
	while (i < size)
	{
		while (rotations_count < size && a->size && a->top->data > b->top->data)
		{
			rotate_b(b, ops_count);
			rotations_count++;
		}
		if (a->size)
		{
			push_b(b, a, ops_count);
			rotate_b(b, ops_count);
		}
		i++;
	}
	while (rotations_count++ < size)
		rotate_b(b, ops_count);
}

int	merge_sort_old(t_stack *a)
{
	t_stack	*b;
	size_t	size;
	size_t	ops;
	int		ops_count;
	int		counter;
	size_t	max_size;

	max_size = a->size;
	counter = 0;
	b = init_stack();
	ops_count = 0;
	size = 1;
	while (size < max_size)
	{
		ops = max_size / (2 * size);
		if(max_size % (2 * size) != 0)
			ops++;
		if (counter % 2 == 0)
		{
			while(ops > 0)
			{
				merge_a_in_b(b, a, size, &ops_count);
				ops--;
			}
		}
		else
		{
			while (ops > 0)
			{
				merge_b_in_a(a, b, size, &ops_count);
				ops--;
			}
		}
		size *= 2;
		counter++;
	}
	if (counter % 2 != 0)
		transfer_b_to_a_sorted(b, a, b->size, &ops_count);
	return (ops_count);
}
