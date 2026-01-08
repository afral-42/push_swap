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

size_t	get_insertion_index_from_top(t_stack *stack, int value)
{
	t_list	*node;
	size_t	i;

	node = stack->top;
	i = 0;
	while (value > node->data)
	{
		i++;
		if (!node->next || node->next->data < node->data)
			break ;
		node = node->next;
	}
	return (i % stack->size);
}

size_t	get_insertion_index_from_bottom(t_stack *stack, int value)
{
	t_list	*node;
	size_t	i;

	node = lstlast(stack->top);
	i = stack->size;
	while (value < node->data)
	{
		i--;
		if (!node->prev || node->prev->data > node->data)
			break ;
		node = node->prev;
	}
	return (i % stack->size);
}

size_t	get_insertion_index(t_stack *stack, int value)
{
	if (value > stack->top->data)
		return (get_insertion_index_from_top(stack, value));
	else
		return (get_insertion_index_from_bottom(stack, value));
}
