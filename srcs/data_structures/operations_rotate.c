/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:04:26 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/15 18:33:38 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

void	rotate_a(t_stack *a, t_ops_counter *counter)
{
	rotate(a);
	counter->ra++;
	if (counter->print_flag)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *b, t_ops_counter *counter)
{
	rotate(b);
	counter->rb++;
	if (counter->print_flag)
		ft_printf("rb\n");
}

void	rotate_both(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	rotate(a);
	rotate(b);
	counter->rr++;
	if (counter->print_flag)
		ft_printf("rr\n");
}
