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

void	rotate_a(t_stack *a, t_ops_counter *counter)
{
	rotate(a);
	counter->ra++;
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b, t_ops_counter *counter)
{
	rotate(b);
	counter->rb++;
	ft_printf("rb\n");
}

void	rotate_both(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	rotate(a);
	rotate(b);
	counter->rr++;
	ft_printf("rr\n");
}
