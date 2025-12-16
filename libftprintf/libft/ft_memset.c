/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:50:34 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:27:02 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	pointer_is_aligned(unsigned char *p)
{
	const size_t	align_mask = sizeof(size_t) - 1;

	return (((size_t)p & align_mask) == 0);
}

static size_t	expand_byte(unsigned char c)
{
	return ((size_t)(-1) / 0xff * c);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			*w;
	size_t			word;

	p = (unsigned char *)s;
	while (n && !pointer_is_aligned(p))
	{
		*p++ = (unsigned char)c;
		n--;
	}
	word = expand_byte((unsigned char)c);
	w = (size_t *)p;
	while (n >= sizeof(size_t))
	{
		*w++ = word;
		n -= sizeof(size_t);
	}
	p = (unsigned char *)w;
	while (n)
	{
		*p++ = (unsigned char)c;
		n--;
	}
	return (s);
}
