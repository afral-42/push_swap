/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:00:02 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/24 16:01:14 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdint.h>
#include "ft_vprintf.h"
#include "ft_printf_utils.h"
#include "libft.h"

int	ft_vprintf(const char *s, va_list vargs)
{
	ssize_t		l;
	size_t		l_tot;

	l = 0;
	l_tot = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		l = parse_unformatted(s);
		if (l < 0)
			return (l);
		l_tot += l;
		s += l;
		l = parse_formatted(s, vargs);
		if (l < 0)
			return (l);
		l_tot += l;
		if (*s)
			s++;
		if (*s)
			s++;
	}
	return (l_tot);
}
