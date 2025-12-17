/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:57:05 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 08:40:31 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_vprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	vargs;
	int		len;

	va_start(vargs, s);
	len = ft_vprintf(s, vargs);
	va_end(vargs);
	return (len);
}
