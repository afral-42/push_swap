/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:54:35 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 15:39:22 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

int	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	if (ft_printf("rra\n") < 0)
		return (-1);
	return (1);
}

int	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	if (ft_printf("rrb\n") < 0)
		return (-1);
	return (1);
}

int	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (ft_printf("rrr\n") < 0)
		return (-1);
	return (1);
}
