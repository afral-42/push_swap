/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:08:04 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/15 18:34:17 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

void	swap_a(t_stack *a, t_ops_counter *counter)
{
	swap(a);
	counter->sa++;
	if (counter->print_flag)
		ft_printf("sa\n");
}

void	swap_b(t_stack *b, t_ops_counter *counter)
{
	swap(b);
	counter->sb++;
	if (counter->print_flag)
		ft_printf("sb\n");
}

void	swap_both(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	swap(a);
	swap(b);
	counter->ss++;
	if (counter->print_flag)
		ft_printf("ss\n");
}
