/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:54:35 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 12:18:12 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

void	reverse_rotate_a(t_stack *a, t_ops_counter *counter)
{
	reverse_rotate(a);
	counter->rra++;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *b, t_ops_counter *counter)
{
	reverse_rotate(b);
	counter->rrb++;
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_ops_counter *counter)
{
	reverse_rotate(a);
	reverse_rotate(b);
	counter->rrr++;
	ft_printf("rrr\n");
}
