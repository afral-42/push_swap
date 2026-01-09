/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:06:21 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/08 19:06:25 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"
#include "stack.h"

static void	put_value_on_top_of_a(t_stack *a, size_t index,
								t_ops_counter *ops_count)
{
	if (index < a->size / 2 + 1)
	{
		while (index--)
			rotate_a(a, ops_count);
	}
	else
	{
		while (index++ < a->size)
			reverse_rotate_a(a, ops_count);
	}
}

void	insertion_sort_procedure(t_stack *a, t_stack *b,
											t_ops_counter *ops_count)
{
	size_t	insertion_index;
	size_t	min_index;

	while (a->top->next)
		push_b(b, a, ops_count);
	while (b->size)
	{
		min_index = get_min_index(a->top);
		insertion_index = get_insertion_index(a, b->top->data, min_index, min_index);
		put_value_on_top_of_a(a, insertion_index, ops_count);
		push_a(a, b, ops_count);
	}
	min_index = get_min_index(a->top);
	put_value_on_top_of_a(a, min_index, ops_count);
}

t_ops_counter	*insertion_sort(t_stack *a)
{
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
	if (!a->top)
	{
		free_stack(b);
		return (ops_count);
	}
	insertion_sort_procedure(a, b, ops_count);
	free_stack(b);
	return (ops_count);
}
