/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:50:55 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 14:31:46 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	abort_sort_function(t_stack *b)
{
	free_stack(b);
	return (-1);
}

int	transfer_stack(t_stack *dest, t_stack *src,
				int (*push_fct)(t_stack *, t_stack *))
{
	while (src->size)
	{
		if (push_fct(dest, src) < 0)
			return (-1);
	}
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
