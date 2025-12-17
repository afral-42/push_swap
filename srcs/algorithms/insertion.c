/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:56:21 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/17 09:10:43 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "stack.h"

void	insertion(t_stack *a)
{
	int		rotations_count;

	rotations_count = 0;
	while (a->size)
	{
		while (rotations_count < b->size && b->top->data > a->top->data)
		{
			rotate_b(b);
			rotations_count++;
		}
		push_b(b, a);
		while (rotations_count)
		{
			reverse_rotate_b(b);
			rotations_count--;
		}
	}
	while (b->size)
		push_a(a, b);
}
