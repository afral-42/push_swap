/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:56:21 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 15:07:32 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"

static int	rotate_b_and_insert_a(t_stack *a, t_stack *b)
{
	size_t	rotations_count;

	rotations_count = 0;
	while (rotations_count < b->size && b->top->data > a->top->data)
	{
		if (rotate_b(b) < 0)
			return (-1);
		rotations_count++;
	}
	if (push_b(b, a) < 0)
		return (-1);
	return (rotations_count);
}

static int	reorder_b(t_stack *b, size_t rotations_count)
{
	while (rotations_count)
	{
		if (reverse_rotate_b(b) < 0)
			return (-1);
		rotations_count--;
	}
	return (0);
}

int	insertion_sort(t_stack *a)
{
	size_t	rotations_count;
	int		ops_count;
	t_stack	*b;

	b = init_stack();
	if (!b)
		return (-1);
	rotations_count = 0;
	ops_count = 0;
	while (a->size)
	{
		rotations_count = rotate_b_and_insert_a(a, b);
		if (rotations_count < 0)
			return (abort_sort_function(b));
		if (reorder_b(b, rotations_count) < 0)
			return (abort_sort_function(b));
		ops_count += (2 * rotations_count + 1);
	}
	if (transfer_stack(a, b, &push_a) < 0)
		return (abort_sort_function(b));
	ops_count += a->size;
	free_stack(b);
	return (ops_count);
}
