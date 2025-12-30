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

int	rotate_a(t_stack *a, int *counter)
{
	rotate(a);
	(*counter)++;
	if (ft_printf("ra\n") < 0)
		return (-1);
	return (1);
}

int	rotate_b(t_stack *b, int *counter)
{
	rotate(b);
	(*counter)++;
	if (ft_printf("rb\n") < 0)
		return (-1);
	return (1);
}

int	rotate_both(t_stack *a, t_stack *b, int *counter)
{
	rotate(a);
	rotate(b);
	(*counter)++;
	if (ft_printf("rr\n") < 0)
		return (-1);
	return (1);
}
