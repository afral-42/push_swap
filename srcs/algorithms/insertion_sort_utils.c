/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:27:11 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/08 11:31:34 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "stack.h"
#include "list.h"

size_t	get_insertion_index(t_stack *stack, int value, size_t lower_limit, size_t upper_limit)
{
	t_list	*node;
	size_t	i;
	size_t	size;

	node = stack->top;
	size = lower_limit + stack->size - (upper_limit % stack->size);
	i = 0;
	while (i++ < lower_limit)
		node = node->next;

	i = lower_limit;
	while (size && node && value > node->data)
	{
		node = node->next;
		i++;
		size--;
	}
	if (node)
		return (i);
	i = 0;
	node = stack->top;
	while (size && i < upper_limit && value > node->data)
	{
		node = node->next;
		i++;
		size--;
	}
	return (i);
}
