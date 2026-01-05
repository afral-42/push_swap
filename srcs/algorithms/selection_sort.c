/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:58:57 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/05 14:31:25 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"
#include "algorithms.h"
#include "operations.h"
#include <stdio.h>

int	find_min(t_stack *a)
{
    t_list  *node;
	size_t	index;
    size_t  i;
	int		min;

    node = a->top;
	min = node->data;
	i = 0;
	index = 0;
    while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			index = i;
		}
		node = node->next;
		i++;
	}
	return (index);
}

int selection_sort(t_stack *a)
{
    t_stack *b;
	size_t	i;
	size_t	min_index;
	int		count;

	count = 0;
    b = init_stack();
    if (!b)
	{
        return (-1);
	}
	while (a->top)
	{
		min_index = find_min(a);
		i = 0;
		while (i < min_index)
		{
			count += rotate_a(a);
			i++;
		}
		count += push_b(b, a);
		// if (push_b(b, a) == -1)
		// 	return (abort_sort_function(b));
	}
	count += transfer_stack(a, b, &push_a);
	// if (transfer_stack(a, b, &push_a) == -1)
	// 	return (abort_sort_function(b));
	return (count);
}
