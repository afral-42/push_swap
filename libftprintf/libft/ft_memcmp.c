/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:52:16 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:39:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	pointer_is_aligned(const unsigned char *p)
{
	const size_t	align_mask = sizeof(size_t) - 1;

	return (((size_t)p & align_mask) == 0);
}

static size_t	move_by_word(const size_t *w1, const size_t *w2, size_t n)
{
	size_t	i;

	i = 0;
	while (n >= sizeof(size_t) && *w1 == *w2)
	{
		w1++;
		w2++;
		n -= sizeof(size_t);
		i++;
	}
	return (i);
}

static size_t	move_by_char(const unsigned char *p1,
								const unsigned char *p2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && *p1 == *p2)
	{
		p1++;
		p2++;
		n--;
		i++;
	}
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	const size_t		*w1;
	const size_t		*w2;
	size_t				mov;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n && !pointer_is_aligned(p1) && *p1 == *p2)
	{
		p1++;
		p2++;
		n--;
	}
	w1 = (const size_t *)p1;
	w2 = (const size_t *)p2;
	mov = move_by_word(w1, w2, n);
	n -= mov * sizeof(size_t);
	p1 = (const unsigned char *)(w1 + mov);
	p2 = (const unsigned char *)(w2 + mov);
	mov = move_by_char(p1, p2, n);
	n -= mov;
	if (n)
		return (*(p1 + mov) - *(p2 + mov));
	return (0);
}
