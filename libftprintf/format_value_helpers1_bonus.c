/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_value_helpers1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:27:45 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:27:46 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"
#include "libft.h"

ssize_t	format_str(t_specifiers specifiers)
{
	size_t	size;
	size_t	l_str;

	if (!(specifiers.arg.s))
		l_str = 6;
	else
		l_str = ft_strlen(specifiers.arg.s);
	if (!specifiers.precision_set || (size_t)specifiers.precision > l_str)
		size = l_str;
	else
		size = specifiers.precision;
	if (!specifiers.arg.s && size < 6)
		return (0);
	else if (!specifiers.arg.s)
		return (out("(null)", size));
	else
		return (out(specifiers.arg.s, size));
}

ssize_t	format_chr(t_specifiers specifiers)
{
	return (out(&(specifiers.arg.c), 1));
}
