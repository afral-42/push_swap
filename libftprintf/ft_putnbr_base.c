/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:56:05 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 18:06:29 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft.h"

static ssize_t	ft_put_zero_padding(int precision, int size, char *base)
{
	ssize_t	l;
	ssize_t	l_tot;
	char	c;

	l = 0;
	l_tot = 0;
	while (precision-- > size)
	{
		c = base[0];
		l = write(1, &c, 1);
		if (l < 0)
			return (-1);
		l_tot += l;
	}
	return (l_tot);
}

static ssize_t	ft_put_digits(unsigned long n, unsigned long divisor,
						char *base, size_t radix)
{
	char	c;
	ssize_t	l;
	ssize_t	l_tot;

	l = 0;
	l_tot = 0;
	while (divisor)
	{
		c = base[n / divisor];
		n = n % divisor;
		divisor /= radix;
		l = write(1, &c, 1);
		if (l < 0)
			return (-1);
		l_tot += l;
	}
	return (l_tot);
}

ssize_t	ft_putnbr_base(unsigned long n, int precision, char *base)
{
	size_t			radix;
	unsigned long	divisor;
	ssize_t			l;
	ssize_t			l_tot;
	int				size;

	radix = ft_strlen(base);
	divisor = 1;
	size = 1;
	l = 0;
	l_tot = 0;
	while (n / divisor > radix - 1)
	{
		divisor *= radix;
		size++;
	}
	l = ft_put_zero_padding(precision, size, base);
	if (l < 0)
		return (-1);
	l_tot += l;
	l_tot = ft_put_digits(n, divisor, base, radix);
	if (l < 0)
		return (-1);
	l_tot += l;
	return (l_tot);
}
