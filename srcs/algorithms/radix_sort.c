/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:27:04 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/30 17:39:04 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include <stddef.h>

int	skip_digit(t_stack *a, int mask)
{
	size_t	zero_count;
	t_list	*node;
	
	zero_count = 0;
	node = a->top;
	while (node)
	{
		if ((node->data & mask) == 0)
			zero_count++;
		node = node->next;
	}
	return (zero_count == 1 || zero_count == a->size);
}


void	radix_sort_procedure(t_stack *a, t_stack *b, int *ops_count)
{
	size_t	i;
	size_t	j;
	int		digit;

	i = 0;
	while (i < sizeof(a->top->data) * 8)
	{
		if (!skip_digit(a, 1 << i))
		{
			j = 0;
			while (j++ < a->size + b->size)
			{
				digit = a->top->data & (1 << i);
				if (digit == 0 || (digit != 0 && i == 31))
					push_b(b, a, ops_count);
				else
					rotate_a(a, ops_count);
			}
			while (b->top)
				push_a(a, b, ops_count);
		}
		i++;
	}
}

int	radix_sort(t_stack *a)
{
	t_stack	*b;
	int		ops_count;

	b = init_stack();
	if (!b)
		return (0);
	ops_count = 0;
	radix_sort_procedure(a, b, &ops_count);
	free_stack(b);
	return (ops_count);
}
