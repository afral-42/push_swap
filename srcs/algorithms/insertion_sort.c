/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:56:21 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 16:59:55 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"

t_ops_counter	*insertion_sort(t_stack *a)
{
	size_t			rotations_count;
	t_stack			*b;
	t_ops_counter	*ops_count;

	b = init_stack();
	if (!b)
		return (NULL);
	ops_count = new_ops_counter();
	if (!ops_count)
	{
		free_stack(b);
		return (NULL);
	}
	rotations_count = 0;
	while (a->size)
	{
		while (rotations_count < b->size && b->top->data > a->top->data)
		{
			rotate_b(b, ops_count);
			rotations_count++;
		}
		push_b(b, a, ops_count);
		while (rotations_count)
		{
			reverse_rotate_b(b, ops_count);
			rotations_count--;
		}
	}
	transfer_stack(a, b, ops_count, &push_a);
	free_stack(b);
	return (ops_count);
}
