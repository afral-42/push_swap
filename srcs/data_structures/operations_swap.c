/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:08:04 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/17 09:18:31 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	swap_a(t_stack *a)
{
	swap_a(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
