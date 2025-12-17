/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:46:16 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:26:50 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	*copy_by_word(size_t *dest, const size_t *src, size_t n)
{
	while (n >= sizeof(size_t))
	{
		*dest++ = *src++;
		n -= sizeof(size_t);
	}
	return (dest);
}

static void	*copy_by_byte(char *dest, const char *src, size_t n)
{
	while (n--)
		*dest++ = *src++;
	return (dest);
}

static size_t	min_value(size_t x, size_t y)
{
	return (y ^ ((x ^ y) & ((size_t)(-1) * (x < y))));
}

static void	*shift_pointer(const void *p, size_t offset)
{
	return ((char *)p + offset);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_cpy;
	size_t	word_copy_offset;
	size_t	align_offset;

	if (!dest && !src)
		return (NULL);
	dest_cpy = dest;
	align_offset = min_value(n, (size_t)dest & (sizeof(size_t) - 1));
	copy_by_byte(dest, src, align_offset);
	n -= align_offset;
	dest = shift_pointer(dest, align_offset);
	src = shift_pointer(src, align_offset);
	copy_by_word(dest, src, n);
	word_copy_offset = n & ~(sizeof(size_t) - 1);
	n -= word_copy_offset;
	dest = shift_pointer(dest, word_copy_offset);
	src = shift_pointer(src, word_copy_offset);
	copy_by_byte(dest, src, n);
	return (dest_cpy);
}
