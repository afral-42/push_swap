/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:56:21 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 16:59:55 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"

t_list	*lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t	get_min_index(t_list *lst)
{
	int		min;
	size_t	i;
	size_t	min_index;

	min = lst->data;
	min_index = 0;
	i = 1;
	lst = lst->next;
	while (lst)
	{
		if (lst->data < min)
		{
			min = lst->data;
			min_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (min_index);
}

size_t	get_insertion_index(t_stack *stack, int value)
{
	size_t	i;
	t_list	*node;

	if (value > stack->top->data)
	{
		node = stack->top;
		i = 0;
		while (value > node->data)
		{
			i++;
			if (!node->next || node->next->data < node->data)
				break;
			node = node->next;
		}
		return (i % stack->size);
	}
	node = lstlast(stack->top);
	i = stack->size;
	while (value < node->data)
	{
		i--;
		if (!node->prev || node->prev->data > node->data)
			break;
		node = node->prev;
	}
	return (i % stack->size);
}

void	put_value_on_top_of_a(t_stack *a, size_t index, t_ops_counter *ops_count)
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

t_ops_counter	*insertion_sort(t_stack *a)
{
	t_stack			*b;
	t_ops_counter	*ops_count;
	size_t			insertion_index;
	size_t			min_index;

	b = init_stack();
	if (!b)
		return (NULL);
	ops_count = new_ops_counter();
	if (!ops_count)
	{
		free_stack(b);
		return (NULL);
	}
	transfer_stack(b, a, ops_count, &push_b);
	push_a(a, b, ops_count);
	while (b->size)
	{
		insertion_index = get_insertion_index(a, b->top->data);
		put_value_on_top_of_a(a, insertion_index, ops_count);
		push_a(a, b, ops_count);
	}
	min_index = get_min_index(a->top);
	put_value_on_top_of_a(a, min_index, ops_count);
	free_stack(b);
	return (ops_count);
}
