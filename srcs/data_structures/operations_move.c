/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@students.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 10:13:14 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/27 11:02:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	move_a(t_stack *a, size_t end, int *ops_counter)
{
	ssize_t	delta;
	size_t	start;
	ssize_t	i;

	start = a->position;
	delta = end - start;
	if (delta > 0 && (size_t)delta > a->size / 2)
		delta -= a->size;
	else if (delta < 0 && (size_t)(-delta) > a->size / 2)
		delta += a->size;
	i = 0;
	if (delta > 0)
	{
		while (i++ < delta)
			rotate_a(a, ops_counter);
	}
	else if (delta < 0)
	{
		while (i-- > delta)
			reverse_rotate_a(a, ops_counter);
	}
}

void	move_b(t_stack *b, size_t end, int *ops_counter)
{
	ssize_t	delta;
	size_t	start;
	ssize_t	i;

	start = b->position;
	delta = end - start;
	if (delta > 0 && (size_t)delta > b->size / 2)
		delta -= b->size;
	else if (delta < 0 && (size_t)(-delta) > b->size / 2)
		delta += b->size;
	i = 0;
	if (delta > 0)
	{
		while (i++ < delta)
			rotate_b(b, ops_counter);
	}
	else if (delta < 0)
	{
		while (i-- > delta)
			reverse_rotate_b(b, ops_counter);
	}
}
