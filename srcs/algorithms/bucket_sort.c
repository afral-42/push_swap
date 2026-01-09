/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:50:11 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/09 14:00:44 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"
#include "parsing.h"

size_t	find_max_index(t_stack *b, int *maximum)
{
	t_list	*node;
	size_t	index;
	size_t	i;
	int		max;

	node = b->top;
	max = node->data;
	i = 0;
	index = 0;
	while (node)
	{
		if (node->data > max)
		{
			max = node->data;
			index = i;
		}
		node = node->next;
		i++;
	}
	*maximum = max;
	return (index);
}

int	fill_buckets(t_stack *a, t_stack *b, t_buckets buckets,
				t_ops_counter *ops)
{
	size_t	rotations_count;
	size_t	stack_size;
	size_t	bucket_index;
	int		min;
	int		count;

	count = 0;
	min = lstget_min(a->top);
	bucket_index = 0;
	while (bucket_index < buckets.number)
	{
		rotations_count = 0;
		stack_size = a->size;
		while (rotations_count < stack_size)
		{
			if (a->top->data <= (int)(min + (bucket_index + 1) * buckets.size))
				count += push_b(b, a, ops);
			else
				count += rotate_a(a, ops);
			rotations_count++;
		}
		bucket_index++;
	}
	return (count);
}

int	empty_buckets(t_stack *a, t_stack *b, t_ops_counter *ops)
{
	size_t	max_index;
	int		max;
	int		(*action[2])(t_stack *, t_ops_counter *);
	int		count;

	count = 0;
	action[0] = &reverse_rotate_b;
	action[1] = &rotate_b;
	while (b->top)
	{
		max_index = find_max_index(b, &max);
		while (b->top->data != max)
			action[max_index <= b->size / 2](b, ops);
		push_a(a, b, ops);
	}
	return (count);
}

t_ops_counter	*bucket_sort(t_stack *a)
{
	t_stack			*b;
	t_buckets		buckets;
	t_ops_counter	*ops;	

	ops = new_ops_counter();
	if (!ops)
		return (NULL);
	b = init_stack();
	if (!b)
	{
		free(ops);
		return (NULL);
	}
	buckets.number = ft_sqrt(a->size);
	buckets.size = (lstget_max(a->top) - lstget_min(a->top) + 1)
		/ buckets.number + 1;
	fill_buckets(a, b, buckets, ops);
	empty_buckets(a, b, ops);
	free_stack(b);
	return (ops);
}
