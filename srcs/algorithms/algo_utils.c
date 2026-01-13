/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:50:55 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/13 10:43:22 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "stack.h"
#include "operations.h"

int	transfer_stack(t_stack *dest, t_stack *src, t_ops_counter *ops_count,
				void (*push_fct)(t_stack *, t_stack *, t_ops_counter *))
{
	while (src->size)
		push_fct(dest, src, ops_count);
	return (dest->size);
}

size_t	ft_sqrt(size_t nb)
{
	size_t	sqrt;

	sqrt = 1;
	while (sqrt * sqrt <= nb)
		sqrt++;
	return (sqrt - 1);
}
