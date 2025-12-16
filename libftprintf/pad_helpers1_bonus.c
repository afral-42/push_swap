/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_helpers1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:30:35 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:30:40 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf_utils_bonus.h"
#include "libft.h"

int	get_zero_pad(t_specifiers specifiers)
{
	int	arg_size;
	int	prefix_size;

	arg_size = get_arg_size(specifiers);
	prefix_size = get_prefix_size(specifiers);
	if (specifiers.width > arg_size + prefix_size)
		return (specifiers.width - prefix_size);
	return (1);
}

int	get_str_size(char *s, int precision, int precision_set)
{
	size_t	l;

	if (!s)
		l = sizeof "(null)" - 1;
	else
		l = ft_strlen(s);
	if (!precision_set)
		return (l);
	if ((size_t)precision > l)
		return (l);
	if (l > INT_MAX)
		return (INT_MAX);
	if (!s && precision < (int)(sizeof "(null)" - 1))
		return (0);
	return (precision);
}

int	get_arg_size(t_specifiers specifiers)
{
	if (specifiers.type == INT)
		return (get_int_size(specifiers.arg.i, specifiers.precision,
				specifiers.precision_set));
	if (specifiers.type == UINT)
		return (get_uint_size(specifiers.arg.ui, specifiers.precision,
				specifiers.precision_set));
	if (specifiers.type == HEX)
		return (get_hex_size(specifiers.arg.ui, specifiers.precision,
				specifiers.precision_set));
	if (specifiers.type == CHAR)
		return (1);
	if (specifiers.type == STR)
		return (get_str_size(specifiers.arg.s, specifiers.precision,
				specifiers.precision_set));
	if (specifiers.type == PTR)
		return (get_ptr_size(specifiers.arg.p));
	return (0);
}
