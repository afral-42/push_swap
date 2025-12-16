/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_helpers1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:29:34 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:29:34 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils_bonus.h"
#include "libft.h"

t_arg	getarg(t_type type, va_list	vargs)
{
	t_arg	arg;

	if (type == INT)
		arg.i = va_arg(vargs, int);
	else if (type == UINT || type == HEX)
		arg.i = va_arg(vargs, unsigned int);
	else if (type == CHAR)
		arg.c = va_arg(vargs, int);
	else if (type == STR)
		arg.s = va_arg(vargs, char *);
	else if (type == PTR)
		arg.p = va_arg(vargs, uintptr_t);
	else
		arg.i = 0;
	return (arg);
}

t_type	gettype(const char c)
{
	if (c == 'i' || c == 'd')
		return (INT);
	if (c == 'u')
		return (UINT);
	if (c == 'x' || c == 'X')
		return (HEX);
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STR);
	if (c == 'p')
		return (PTR);
	if (c == '%')
		return (PCT);
	return (UNDEFINED);
}

int	getint(const char *s)
{
	int	n;

	n = 0;
	while (ft_isdigit(*s))
	{
		if (10 * n + *s - '0' < n)
			return (-1);
		n = 10 * n + *s - '0';
		s++;
	}
	return (n);
}

ssize_t	out(const char *s, size_t l)
{
	return (write(1, s, l));
}
