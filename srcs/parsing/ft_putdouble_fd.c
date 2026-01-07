/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:41:15 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/07 13:45:42 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(double n, size_t precision, int fd)
{
	int	multiplicator;

	ft_putnbr_fd((int)n, fd);
	if (!precision)
		return ;
	ft_putchar_fd('.', fd);
	multiplicator = 10;
	while (precision--)
	{
		ft_putchar_fd('0' + (int)(n * multiplicator) % 10, fd);
		multiplicator *= 10;
	}
}
