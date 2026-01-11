/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:02:01 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 12:15:06 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"
#include "ft_printf.h"

void	push_a(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	lst_move_head(&(a->top), &(b->top));
	counter->pa++;
	a->size++;
	b->size--;
	ft_printf("pa\n");
}

void	push_b(t_stack *b, t_stack *a, t_ops_counter *counter)
{
	lst_move_head(&(b->top), &(a->top));
	counter->pb++;
	a->size--;
	b->size++;
	ft_printf("pb\n");
}
