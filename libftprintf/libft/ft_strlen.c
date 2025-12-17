/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:37:26 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 14:05:43 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	pointer_is_aligned(const char *p)
{
	const size_t	align_mask = sizeof(size_t) - 1;

	return (((size_t)p & align_mask) == 0);
}

static int	has_zero_byte(size_t	w)
{
	const size_t	l = (size_t)(-1) / 0xff;
	const size_t	h = 0x80 * l;

	return ((h & (w - l) & ~w) != 0);
}

size_t	ft_strlen(const char *s)
{
	const char		*p;
	const size_t	*w;

	p = s;
	while (*p && !(pointer_is_aligned(p)))
		p++;
	w = (size_t *)p;
	while (!has_zero_byte(*w))
		w++;
	p = (char *)w;
	while (*p)
		p++;
	return (p - s);
}
