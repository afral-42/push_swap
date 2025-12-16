/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_pad_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:28:26 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:28:32 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"
#include "libft.h"
#include "limits.h"

ssize_t	left_pad(t_specifiers specifiers)
{
	int		nbr_size;
	int		pad_size;
	ssize_t	l;

	if (specifiers.flags['-']
		|| (specifiers.flags['0'] && !specifiers.precision_set))
		return (0);
	nbr_size = get_arg_size(specifiers) + get_prefix_size(specifiers);
	if (specifiers.width <= nbr_size)
		return (0);
	pad_size = specifiers.width - nbr_size;
	l = 0;
	while (pad_size--)
	{
		l += out(" ", 1);
		if (l < 0)
			return (-1);
	}
	return (l);
}
