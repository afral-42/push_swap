/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:08:04 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 12:19:36 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

void	swap_a(t_stack *a, t_ops_counter *counter)
{
	swap(a);
	counter->sa++;
	ft_printf("sa\n");
}

void	swap_b(t_stack *b, t_ops_counter *counter)
{
	swap(b);
	counter->sb++;
	ft_printf("sb\n");
}

void	swap_both(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	swap(a);
	swap(b);
	counter->ss++;
	ft_printf("ss\n");
}
