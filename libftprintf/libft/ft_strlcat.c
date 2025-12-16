/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:46:26 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/12 14:12:31 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	l_cpy;

	l_src = ft_strlen(src);
	if (dst)
		l_dst = ft_strlen(dst);
	else
		l_dst = 0;
	if (size <= l_dst)
		return (l_src + size);
	dst += l_dst;
	size -= l_dst;
	if (size <= l_src)
		l_cpy = size - 1;
	else
		l_cpy = l_src;
	ft_memcpy(dst, src, l_cpy);
	dst[l_cpy] = '\0';
	return (l_dst + l_src);
}
