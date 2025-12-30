/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:50:55 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 17:39:58 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"

int	abort_sort_function(t_stack *b)
{
	free_stack(b);
	return (-1);
}

int	transfer_stack(t_stack *dest, t_stack *src, int *ops_count,
				int (*push_fct)(t_stack *, t_stack *, int *))
{
	while (src->size)
	{
		if (push_fct(dest, src, ops_count) < 0)
			return (-1);
	}
	return (dest->size);
}

int	transfer_a_to_b_sorted(t_stack *a, t_stack *b, size_t size, int *ops_count)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		rotate_a(a, ops_count);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		push_b(b, a, ops_count);
		reverse_rotate_a(a, ops_count);
		i++;
	}
	push_b(b, a, ops_count);
	return (3 * (size - 1) + 1);
}

int	transfer_b_to_a_sorted(t_stack *b, t_stack *a, size_t size, int *ops_count)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		rotate_b(b, ops_count);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		push_a(a, b, ops_count);
		reverse_rotate_b(b, ops_count);
		i++;
	}
	push_a(a, b, ops_count);
	return (3 * (size - 1) + 1);
}
