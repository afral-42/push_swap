/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:22:03 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 18:07:43 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	pointer_is_aligned(const unsigned char *p)
{
	const size_t	align_mask = sizeof(size_t) - 1;

	return (((size_t)p & align_mask) == 0);
}

static int	has_byte(const size_t	w, unsigned char b)
{
	const size_t	l = (size_t)(-1) / 0xff;
	const size_t	h = 0x80 * l;
	const size_t	mask = b * l;

	return ((h & ((w ^ mask) - l) & ~(w ^ mask)) != 0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	const size_t		*w;

	p = (unsigned char *)s;
	while (n && !(pointer_is_aligned(p)) && *p != (unsigned char)c)
	{
		p++;
		n--;
	}
	w = (const size_t *)p;
	while (n > sizeof(size_t) && !(has_byte(*w, (unsigned char)c)))
	{
		w++;
		n -= sizeof(size_t);
	}
	p = (const unsigned char *)w;
	while (n && *p != (unsigned char)c)
	{
		p++;
		n--;
	}
	if (!n)
		return (NULL);
	return ((void *)p);
}
