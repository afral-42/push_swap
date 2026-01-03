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
		while (rotations_count < b->size && b->top->data > a->top->data)
		{
			rotate_b(b, &ops_count);
			rotations_count++;
		}
		push_b(b, a, &ops_count);
		while (rotations_count)
		{
			reverse_rotate_b(b, &ops_count);
			rotations_count--;
		}
	}
	transfer_stack(a, b, &ops_count, &push_a);
	free_stack(b);
	return (ops_count);
}
