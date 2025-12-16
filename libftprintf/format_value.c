/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:29:21 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 16:49:06 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

ssize_t	format_value(t_specifiers specifiers)
{
	if (specifiers.type == INT)
		return (format_int(specifiers));
	else if (specifiers.type == UINT)
		return (format_uint(specifiers));
	else if (specifiers.type == HEX)
		return (format_hex(specifiers));
	else if (specifiers.type == PTR)
		return (format_ptr(specifiers));
	else if (specifiers.type == STR)
		return (format_str(specifiers));
	else if (specifiers.type == CHAR)
		return (format_chr(specifiers));
	return (-1);
}
