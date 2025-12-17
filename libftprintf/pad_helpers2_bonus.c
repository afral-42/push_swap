/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_helpers2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:30:21 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:30:22 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

static int	get_nbr_size(unsigned long n, int precision, int base_len)
{
	int	l;

	l = 1;
	while (n / base_len)
	{
		l++;
		n /= base_len;
	}
	if (precision > l)
		return (precision);
	return (l);
}

int	get_int_size(int n, int precision, int precision_set)
{
	if (n == 0 && precision_set && precision == 0)
		return (0);
	if (n < 0)
		return (get_nbr_size((unsigned int)(-n), precision, 10));
	return (get_nbr_size(n, precision, 10));
}

int	get_uint_size(unsigned int n, int precision, int precision_set)
{
	if (n == 0 && precision_set && precision == 0)
		return (0);
	return (get_nbr_size(n, precision, 10));
}

int	get_hex_size(unsigned int n, int precision, int precision_set)
{
	if (n == 0 && precision_set && precision == 0)
		return (0);
	return (get_nbr_size(n, precision, 16));
}

int	get_ptr_size(uintptr_t p)
{
	if (!p)
		return (sizeof "(nil)" - 1);
	return (get_nbr_size(p, 1, 16));
}
