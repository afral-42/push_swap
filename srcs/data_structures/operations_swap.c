/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:08:04 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 14:42:52 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

int	swap_a(t_stack *a)
{
	swap(a);
	if (ft_printf("sa\n") < 0)
		return (-1);
	return (1);
}

int	swap_b(t_stack *b)
{
	swap(b);
	if (ft_printf("sb\n") < 0)
		return (-1);
	return (1);
}

int	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (ft_printf("ss\n") < 0)
		return (-1);
	return (1);
}
