/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:28:19 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:28:21 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdint.h>
#include "ft_printf_utils_bonus.h"
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
		s = skip_specifiers(s);
	}
	return (l_tot);
}
