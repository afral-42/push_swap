/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:29:51 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:37:09 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"
#include "libft.h"

static t_specifiers	parse_specifiers(const char *s, va_list vargs)
{
	t_specifiers	specifiers;

	specifiers = new_specifiers();
	getflags(s, specifiers.flags);
	s = skip_flags(s);
	specifiers.width = getint(s);
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		s++;
		set_precision(&specifiers, getint(s));
		while (ft_isdigit(*s))
			s++;
	}
	if (specifiers.width < 0 || specifiers.precision < 0)
		return (specifiers);
	specifiers.type = gettype(*s);
	if (specifiers.type == UNDEFINED || specifiers.type == PCT)
		return (specifiers);
	if (*s == 'X')
		specifiers.to_upper = 1;
	specifiers.arg = getarg(specifiers.type, vargs);
	return (specifiers);
}

static ssize_t	out_formatted(t_specifiers specifiers)
{
	ssize_t	l;
	ssize_t	l_tot;

	l = 0;
	l_tot = 0;
	l = left_pad(specifiers);
	if (l < 0)
		return (-1);
	l_tot += l;
	l = prefix(specifiers);
	if (l < 0)
		return (-1);
	l_tot += l;
	l = format_value(specifiers);
	if (l < 0)
		return (-1);
	l_tot += l;
	l = right_pad(specifiers);
	if (l < 0)
		return (-1);
	l_tot += l;
	return (l_tot);
}

ssize_t	parse_unformatted(const char *s)
{
	const char	*p;
	ssize_t		l;

	l = 0;
	p = s;
	while (*p && *p != '%')
		p++;
	l = out(s, p - s);
	return (l);
}

ssize_t	parse_formatted(const char *s, va_list vargs)
{
	t_specifiers	specifiers;

	if (!(*s) || *s != '%')
		return (0);
	s++;
	specifiers = parse_specifiers(s, vargs);
	s = skip_flags(s);
	s = skip_width_and_precision(s);
	if (specifiers.type == UNDEFINED)
		return (-1);
	if (specifiers.type == PCT)
		return (out("%", 1));
	return (out_formatted(specifiers));
}
