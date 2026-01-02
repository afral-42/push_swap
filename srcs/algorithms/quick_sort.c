/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:12:12 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/30 16:11:57 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "stack.h"
#include "list.h"
#include "operations.h"

size_t	partition_a(t_stack *a, t_stack *b, size_t r, int *ops_count)
{
	int		pivot_data;
	size_t	pivot_index;
	size_t	i;

	pivot_data = lstget(a->top, r - 1);
	i = 0;
	while (i++ < r)
	{
		if (a->top->data <= pivot_data)
			push_b(b, a, ops_count);
		else
			rotate_a(a, ops_count);
	}
	i = 0;
	while (i++ < r - b->size)
		reverse_rotate_a(a, ops_count);
	i = 0;
	pivot_index = b->size;
	while (i++ < pivot_index)
		push_a(a, b, ops_count);
	return (pivot_index);
}

void	quick_sort_procedure(t_stack *a, t_stack *b, size_t r, int *ops_count)
{
	size_t	pivot_index;

	if (!r)
		return ;
	pivot_index = partition_a(a, b, r, ops_count);
	quick_sort_procedure(a, b, pivot_index - 1, ops_count);
	rotate_a(a, ops_count);
	quick_sort_procedure(a, b, r - pivot_index, ops_count);
}

int	quick_sort(t_stack *a)
{
	int		ops_count;
	t_stack	*b;

	ops_count = 0;
	b = init_stack();
	if (!b)
		return (0);
	quick_sort_procedure(a, b, a->size, &ops_count);
	free_stack(b);
	return (ops_count);
}
