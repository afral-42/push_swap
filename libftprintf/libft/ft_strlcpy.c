/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:24:42 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/12 14:12:23 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l_src;
	size_t	l_cpy;

	if (!size)
		return (ft_strlen(src));
	l_src = ft_strlen(src);
	if (size <= l_src)
		l_cpy = size - 1;
	else
		l_cpy = l_src;
	ft_memcpy(dst, src, l_cpy);
	dst[l_cpy] = '\0';
	return (l_src);
}
