/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:26:03 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:25:47 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;
	char			c;

	if (n < 0)
	{
		abs_n = -n;
		write(fd, "-", 1);
	}
	else
		abs_n = n;
	if (abs_n / 10)
		ft_putnbr_fd(abs_n / 10, fd);
	c = abs_n % 10 + '0';
	write(fd, &c, 1);
}
