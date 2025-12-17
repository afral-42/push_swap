/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_helpers2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:29:23 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:29:24 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"
#include "libft.h"

static int	is_flag(char c)
{
	if (c && ft_strchr(FLAGS, c))
		return (1);
	return (0);
}

void	getflags(const char *s, int flags[127])
{
	while (is_flag(*s))
	{
		flags[(int)*s]++;
		(s)++;
	}
}

const char	*skip_flags(const char *s)
{
	while (is_flag(*s))
		s++;
	return (s);
}

const char	*skip_width_and_precision(const char *s)
{
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (s);
}

const char	*skip_specifiers(const char *s)
{
	if (*s)
		s++;
	s = skip_flags(s);
	s = skip_width_and_precision(s);
	if (*s)
		s++;
	return (s);
}
