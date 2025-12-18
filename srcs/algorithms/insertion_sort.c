/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:56:21 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 15:02:37 by arebilla         ###   ########.fr       */
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
	rotations_count = 0;
	ops_count = 0;
	while (a->size)
	{
		while (rotations_count < b->size && b->top->data > a->top->data)
		{
			if (rotate_b(b) < 0)
				return (abort_sort_function(b));
			ops_count++;
			rotations_count++;
		}
		if (push_b(b, a) < 0)
			return (abort_sort_function(b));
		ops_count++;
		while (rotations_count)
		{
			if (reverse_rotate_b(b) < 0)
				return (abort_sort_function(b));
			ops_count++;
			rotations_count--;
		}
	}
	while (b->size && push_a(a, b) >= 0)
		ops_count++;
	if (b->size)
		return (abort_sort_function(b));
	free_stack(b);
	return (ops_count);
}
