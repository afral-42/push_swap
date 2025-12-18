/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:02:01 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/18 15:38:20 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

int	push_a(t_stack *a, t_stack *b)
{
	if (push(a, pop(b)) < 0)
		return (-1);
	if (ft_printf("pa\n") < 0)
		return (-1);
	return (1);
}

int	push_b(t_stack *b, t_stack *a)
{
	if (push(b, pop(a)) < 0)
		return (-1);
	if (ft_printf("pb\n") < 0)
		return (-1);
	return (1);
}
