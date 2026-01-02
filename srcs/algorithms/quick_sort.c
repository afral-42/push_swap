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

int	skip_if_no_right_partion(t_stack *a, int pivot_data, size_t size)
{
	t_list	*node;

	node = a->top;
	while (size--)
	{
		if (node->data > pivot_data)
			return (0);
		node = node->next;
	}
	return (1);
}

size_t	partition_a(t_stack *a, t_stack *b, size_t size, int *ops_count)
{
	int		pivot_data;
	size_t	left_partition_size;
	size_t	i;

	pivot_data = lstget(a->top, size - 1);
	if (skip_if_no_right_partion(a, pivot_data, size))
		return (size - 1);
	i = 0;
	while (i++ < size)
	{
		if (a->top->data <= pivot_data)
			push_b(b, a, ops_count);
		else
			rotate_a(a, ops_count);
	}
	left_partition_size = b->size - 1;
	while (size-- > b->size)
		reverse_rotate_a(a, ops_count);
	while (b->size)
		push_a(a, b, ops_count);
	return (left_partition_size);
}

void	quick_sort_procedure(t_stack *a, t_stack *b, size_t size, int *ops_count)
{
	size_t	left_partition_size;

	if (!size)
		return ;
	left_partition_size = partition_a(a, b, size, ops_count);
	quick_sort_procedure(a, b, left_partition_size, ops_count);
	rotate_a(a, ops_count);
	quick_sort_procedure(a, b, size - left_partition_size - 1, ops_count);
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
