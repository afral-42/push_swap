/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:43:36 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/13 10:45:49 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "stack.h"
#include "list.h"
#include "operations.h"
#include "parsing.h"

void	trivial_merge(t_stack *a, size_t size, t_ops_counter *ops_count)
{
	if (size == 1)
		rotate_a(a, ops_count);
	else if (size == 2)
	{
		if (a->top->data > a->top->next->data)
			swap_a(a, ops_count);
		rotate_a(a, ops_count);
		rotate_a(a, ops_count);
	}
}

void	merge(t_stack *a, t_stack *b, size_t size, t_ops_counter *ops_count)
{
	size_t	i;
	size_t	rotation_count;

	i = 0;
	while (i < size - size / 2)
	{
		reverse_rotate_a(a, ops_count);
		push_b(b, a, ops_count);
		i++;
	}
	rotation_count = 0;
	while (i < size && b->top->data < lstget(a->top, a->size - 1))
	{
		rotation_count++;
		reverse_rotate_a(a, ops_count);
		i++;
	}
	while (i--)
	{
		if ((b->size && a->top->data > b->top->data) || rotation_count == 0)
			push_a(a, b, ops_count);
		else
			rotation_count--;
		rotate_a(a, ops_count);
	}
}

void	merge_sort_procedure(t_stack *a, t_stack *b, size_t size,
	t_ops_counter *ops_count)
{
	size_t	mid;

	if (size > 2)
	{
		mid = size / 2;
		merge_sort_procedure(a, b, mid, ops_count);
		merge_sort_procedure(a, b, size - mid, ops_count);
		merge(a, b, size, ops_count);
	}
	else
		trivial_merge(a, size, ops_count);
}

void	merge_sort(t_stack *a, t_ops_counter *ops_count)
{
	t_stack	*b;

	b = init_stack();
	if (!b)
		return ;
	merge_sort_procedure(a, b, a->size, ops_count);
	free_stack(b);
}
