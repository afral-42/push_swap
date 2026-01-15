/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:02:01 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/15 18:31:37 by abounoua         ###   ########lyon.fr   */
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
	if (counter->print_flag)
		ft_printf("pa\n");
}

void	push_b(t_stack *b, t_stack *a, t_ops_counter *counter)
{
	lst_move_head(&(b->top), &(a->top));
	counter->pb++;
	a->size--;
	b->size++;
	if (counter->print_flag)
		ft_printf("pb\n");
}
