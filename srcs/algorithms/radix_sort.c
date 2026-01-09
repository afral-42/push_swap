/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:33:36 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/09 15:30:04 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"
#include "list.h"


void	split_by_bit(t_stack *a, t_stack *b, unsigned short bit, t_ops_counter *ops)
{
	size_t	i;
	size_t	stack_size;
	
	i = 0;
	stack_size = a->size;
	while (i < stack_size)
	{
		if ((a->top->data >> bit) & 1)
			rotate_a(a, ops);
		else
			push_b(b, a, ops);
		i++;
	}
}

void	operate_radix_sort(t_stack *a, t_stack *b, t_ops_counter *ops)
{
	unsigned short	bit;

	bit = 0;
	while (bit < 32)
	{
		if (!compute_disorder(a))
			break;
		split_by_bit(a, b, bit, ops);
		transfer_stack(a, b, ops, &push_a);
		bit++;
	}
}

t_ops_counter	*radix_sort(t_stack *a)
{
	t_ops_counter	*ops;
	t_stack			*b;

	ops = new_ops_counter();
	if (!ops)
		return (NULL);
	b = init_stack();
	if (!b)
	{
		free(ops);
		return (NULL);
	}
	if (compress_stack(a) == -1)
	{
		free(ops);
		free_stack(b);
		return (NULL);
	}
	operate_radix_sort(a, b, ops);
	free_stack(b);
	return (ops);
}
