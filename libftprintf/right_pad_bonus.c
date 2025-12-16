/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_pad_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:29:00 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:29:01 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

ssize_t	right_pad(t_specifiers specifiers)
{
	int	arg_size;
	int	prefix_size;
	int	pad_size;
	int	l;
	int	l_tot;

	if (!specifiers.flags['-'])
		return (0);
	arg_size = get_arg_size(specifiers);
	prefix_size = get_prefix_size(specifiers);
	if (specifiers.width <= arg_size + prefix_size)
		return (0);
	pad_size = specifiers.width - arg_size - prefix_size;
	l = 0;
	l_tot = 0;
	while (pad_size--)
	{
		l = out(" ", 1);
		if (l < 0)
			return (-1);
		l_tot += l;
	}
	return (l_tot);
}
