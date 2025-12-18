/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:04:26 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 14:59:22 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

int	rotate_a(t_stack *a)
{
	rotate(a);
	if (ft_printf("ra\n") < 0)
		return (-1);
	return (1);
}

int	rotate_b(t_stack *b)
{
	rotate(b);
	if (ft_printf("rb\n") < 0)
		return (-1);
	return (1);
}

int	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	if (ft_printf("rr\n") < 0)
		return (-1);
	return (1);
}
