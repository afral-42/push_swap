/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:56:21 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/17 10:34:34 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	insertion_sort(t_stack *a)
{
	size_t	rotations_count;
	t_stack	*b;

	b = init_stack();
	rotations_count = 0;
	while (a->size)
	{
		while (rotations_count < b->size && b->top->data > a->top->data)
		{
			rotate_b(b);
			rotations_count++;
		}
		push_b(b, a);
		while (rotations_count)
		{
			reverse_rotate_b(b);
			rotations_count--;
		}
	}
	while (b->size)
		push_a(a, b);
	free_stack(b);
}
