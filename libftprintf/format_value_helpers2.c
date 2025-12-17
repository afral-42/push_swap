/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:54:19 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:44:02 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

ssize_t	format_hex(t_specifiers specifiers)
{
	if (specifiers.to_upper)
		return (ft_putnbr_base(specifiers.arg.ui, 1, "0123456789ABCDEF"));
	return (ft_putnbr_base(specifiers.arg.ui, 1, "0123456789abcdef"));
}

ssize_t	format_uint(t_specifiers specifiers)
{
	return (ft_putnbr_base(specifiers.arg.ui, 1, "0123456789"));
}

ssize_t	format_int(t_specifiers specifiers)
{
	unsigned int	n;

	if (specifiers.arg.i < 0)
		n = (unsigned int)(-specifiers.arg.i);
	else
		n = (unsigned int)specifiers.arg.i;
	return (ft_putnbr_base(n, 1, "0123456789"));
}

ssize_t	format_ptr(t_specifiers specifiers)
{
	if (specifiers.arg.p == 0)
		return (out("(nil)", 5));
	return (ft_putnbr_base(specifiers.arg.p, 1, "0123456789abcdef"));
}
