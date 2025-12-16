/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:10:15 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 12:34:41 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_nbr_len(unsigned int n)
{
	size_t		len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static unsigned int	abs_int(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int)n);
}

char	*ft_itoa(int n)
{
	unsigned int	abs_n;
	char			*n_str;
	char			*p_n_str;
	size_t			l_n_str;

	if (!n)
		return (ft_strdup("0"));
	abs_n = abs_int(n);
	l_n_str = get_nbr_len(abs_n);
	if (n < 0)
		l_n_str++;
	n_str = malloc(l_n_str + 1);
	if (!n_str)
		return (NULL);
	if (n < 0)
		*n_str = '-';
	p_n_str = n_str + l_n_str;
	*p_n_str-- = '\0';
	while (abs_n)
	{
		*p_n_str-- = abs_n % 10 + '0';
		abs_n /= 10;
	}
	return (n_str);
}
