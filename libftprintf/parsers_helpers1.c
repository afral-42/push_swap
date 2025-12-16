/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_helpers1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:53:24 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:38:49 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
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

ssize_t	out(const char *s, size_t l)
{
	return (write(1, s, l));
}
