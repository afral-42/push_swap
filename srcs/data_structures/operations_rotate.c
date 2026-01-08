/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:04:26 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 12:16:57 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

int	rotate_a(t_stack *a, t_ops_counter *counter)
{
	rotate(a);
	counter->ra++;
	if (ft_printf("ra\n") < 0)
		return (-1);
	return (1);
}

int	rotate_b(t_stack *b, t_ops_counter *counter)
{
	rotate(b);
	counter->rb++;
	if (ft_printf("rb\n") < 0)
		return (-1);
	return (1);
}

int	rotate_both(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	rotate(a);
	rotate(b);
	counter->rr++;
	if (ft_printf("rr\n") < 0)
		return (-1);
	return (1);
}
