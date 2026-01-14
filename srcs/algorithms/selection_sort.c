/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:58:57 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/13 10:42:42 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"
#include "algorithms.h"
#include "operations.h"
#include <stdio.h>

int	find_min(t_stack *a)
{
	t_list	*node;
	size_t	index;
	size_t	i;
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

void	selection_sort(t_stack *a, t_ops_counter *ops)
{
	t_stack	*b;
	size_t	i;
	size_t	min_index;

	b = init_stack();
	if (!b)
		return ;
	while (a->top)
	{
		min_index = find_min(a);
		i = 0;
		while (i < min_index)
		{
			rotate_a(a, ops);
			i++;
		}
		push_b(b, a, ops);
	}
	transfer_stack(a, b, ops, &push_a);
}
