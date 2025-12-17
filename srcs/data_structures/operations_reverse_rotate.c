/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:54:35 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/17 09:54:36 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra");
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb");
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr");
}
