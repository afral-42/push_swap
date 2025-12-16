/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_value_helpers2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:27:57 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:27:58 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

static int	get_precision(t_specifiers specifiers)
{
	if (specifiers.flags['0'] && !specifiers.precision_set
		&& !specifiers.flags['-'])
		return (get_zero_pad(specifiers));
	else
		return (specifiers.precision);
}

ssize_t	format_hex(t_specifiers specifiers)
{
	int	precision;

	if (specifiers.arg.ui == 0 && specifiers.precision_set
		&& specifiers.precision == 0)
		return (0);
	precision = get_precision(specifiers);
	if (specifiers.to_upper)
		return (ft_putnbr_base(specifiers.arg.ui, precision,
				"0123456789ABCDEF"));
	return (ft_putnbr_base(specifiers.arg.ui, precision,
			"0123456789abcdef"));
}

ssize_t	format_uint(t_specifiers specifiers)
{
	int	precision;

	if (specifiers.arg.ui == 0 && specifiers.precision_set
		&& specifiers.precision == 0)
		return (0);
	precision = get_precision(specifiers);
	return (ft_putnbr_base(specifiers.arg.ui, precision, "0123456789"));
}

ssize_t	format_int(t_specifiers specifiers)
{
	int				precision;
	unsigned int	n;

	if (specifiers.arg.i == 0 && specifiers.precision_set
		&& specifiers.precision == 0)
		return (0);
	precision = get_precision(specifiers);
	if (specifiers.arg.i < 0)
		n = (unsigned int)(-specifiers.arg.i);
	else
		n = (unsigned int)specifiers.arg.i;
	return (ft_putnbr_base(n, precision, "0123456789"));
}

ssize_t	format_ptr(t_specifiers specifiers)
{
	if (specifiers.arg.p == 0)
		return (out("(nil)", 5));
	return (ft_putnbr_base(specifiers.arg.p, 1, "0123456789abcdef"));
}
