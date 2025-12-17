/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:02:01 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/17 09:18:57 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	push_a(t_stack *a, t_stack *b)
{
	push(a, pop(b));
	ft_printf("pa\n");
}

void	push_b(t_stack *b, t_stack *a)
{
	push(b, pop(a));
	ft_printf("pb\n");
}
