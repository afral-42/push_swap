/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:29:10 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:29:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

int	get_prefix_size(t_specifiers specifiers)
{
	if (specifiers.type == PTR && specifiers.arg.p != 0)
		return (2);
	if (specifiers.type == HEX && specifiers.arg.ui != 0
		&& specifiers.flags['#'])
		return (2);
	if (specifiers.type == INT
		&& (specifiers.arg.i < 0 || specifiers.flags[' ']
			|| specifiers.flags['+']))
		return (1);
	return (0);
}

ssize_t	prefix(t_specifiers specifiers)
{
	if (specifiers.type == PTR && specifiers.arg.p != 0)
		return (out("0x", 2));
	if (specifiers.type == HEX && specifiers.arg.ui != 0
		&& specifiers.flags['#'])
	{
		if (specifiers.to_upper)
			return (out("0X", 2));
		return (out("0x", 2));
	}
	if (specifiers.type == INT)
	{
		if (specifiers.arg.i < 0)
			return (out("-", 1));
		if (specifiers.flags[' '])
			return (out(" ", 1));
		if (specifiers.flags['+'])
			return (out("+", 1));
	}
	return (0);
}
